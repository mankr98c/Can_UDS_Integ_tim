/*
Micron flash
 Author:  Shekhar
 Company: Pupilmesh pvt ltd
 Ver. 1.0
*/

// header file inclusion
#ifndef _micron_nand_flash_h
#define _micron_nand_flash_h

#include "stm32h7xx_hal.h" // include header for your stm micro-contoler
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "main.h"

// private deifnes
#define Nand_Flash_DEBUG   		1		 		// change to 0/1 to disable/enable debug
#define FLASH_WIDTH             8               // Flash data width
#define FLASH_SIZE_BYTES        0x40000000      // Flash size in bytes (2gb in hex)
#define NUM_BLOCKS              2048            // Total number of blocks in the device
#define NUM_PAGES_PER_BLOCK     64              // Number of pages per block
#define PAGE_SIZE               2176            // Page size in bytes
#define PAGE_DATA_SIZE          2048            // Page data size in bytes
#define PAGE_SPARE_SIZE         128             // Page spare size in bytes
#define NAND_ID_MANUFACTURER    0x2C
#define NAND_ID_DEVICE          0x24

#define ROW_ADDRESS_BLOCK_BITS   11
#define ROW_ADDRESS_PAGE_BITS    6
#define ROW_ADDRESS_BITS         24
#define COL_ADDRESS_BITS         12
#define DUMMY_Byte				 00

/* physical address macros; Input address must be of type NAND_Addr */
#define ADDRESS_2_BLOCK(Address)    ((uint16_t) (Address >> 17))   // divide by 131072 (2^17 bytes per block)
#define ADDRESS_2_PLANE(Address)    (ADDRESS_2_BLOCK(Address) & 1) // get the last bit of the block number
#define ADDRESS_2_PAGE(Address)     ((uint16_t) ((Address >> 11) & 0x3F))
#define ADDRESS_2_COL(Address)      ((uint32_t) (Address & 0x07FF)) // take last 11 bits of address

/* bit macros */
#define CHECK_OIP(status_reg)      (status_reg & SPI_NAND_OIP) // returns 1 if OIP bit is 1 and device is busy

typedef struct {
        uint16_t plane       : 1;                       // 1 bit to specify plane number
        uint16_t block       : ROW_ADDRESS_BLOCK_BITS;  // block number
        uint16_t page        : ROW_ADDRESS_PAGE_BITS;   // page number
        uint32_t rowAddr     : ROW_ADDRESS_BITS;        // block/page address
        uint32_t colAddr     : COL_ADDRESS_BITS;        // starting address within a page for writes
   } PhysicalAddrs;


// Enumerations
typedef enum {
        SPI_NAND_RESET                  = 0xFF,
        SPI_NAND_GET_FEATURES           = 0x0F,
        SPI_NAND_SET_FEATURES           = 0x1F,
        SPI_NAND_READ_ID                = 0x9F,
        SPI_NAND_PAGE_READ              = 0x13,
        SPI_NAND_READ_PAGE_CACHE_RANDOM = 0x30,
        SPI_NAND_READ_PAGE_CACHE_LAST   = 0x3F,
        SPI_NAND_READ_CACHE_X1          = 0x03,
        SPI_NAND_READ_CACHE_X2          = 0x3B, // dual wire I/O
        SPI_NAND_READ_CACHE_X4          = 0x6B, // quad wire I/O
        SPI_NAND_READ_CACHE_DUAL_IO     = 0xBB,
        SPI_NAND_READ_CACHE_QUAD_IO     = 0xEB,
        SPI_NAND_WRITE_ENABLE           = 0x06, // sets WEL bit in Status Register to 1
        SPI_NAND_WRITE_DISABLE          = 0x04, // clears WEL bit
        SPI_NAND_BLOCK_ERASE            = 0xD8,
        SPI_NAND_PROGRAM_EXEC           = 0x10,
        SPI_NAND_PROGRAM_LOAD_X1        = 0x02,
        SPI_NAND_PROGRAM_LOAD_X4        = 0x32,
        SPI_NAND_PROGRAM_LOAD_RANDOM_X1 = 0x84,
        SPI_NAND_PROGRAM_LOAD_RANDOM_X4 = 0x34,
        SPI_NAND_PERMANENT_BLK_LOCK     = 0x2C     // permanently protect a group of blocks
    } CommandCodes;

typedef enum {
		SPI_NAND_BLKLOCK_REG_ADDR = 0xA0,
        SPI_NAND_CFG_REG_ADDR     = 0xB0,
		SPI_NAND_STATUS_REG_ADDR  = 0xC0,
		SPI_NAND_DIE_SEL_REG_ADDR = 0xD0,
	} RegisterAddr;

typedef enum {
		SPI_NAND_BRWD   = (1 << 7), // block register write disable
		SPI_NAND_BP     = (1 << 6) | (1 << 5) | (1 << 4) | (1 << 3),
		SPI_NAND_TB     = (1 << 2),
		SPI_NAND_WP_D   = (1 << 1), // Write protect#/hold# disable
	} BlockLockRegBits;

typedef enum {
		SPI_NAND_CFG    = (1 << 7) | (1 << 6) | (1 << 1),
		SPI_NAND_LOT_EN = (1 << 5),
		SPI_NAND_ECC_EN = (1 << 4),
	} ConfigRegBits;


typedef enum {
		SPI_NAND_CRBSY = (1 << 7), // Cache Read Busy
		SPI_NAND_ECC   = (1 << 6) | (1 << 5) | (1 << 4),  // ECC bits
		SPI_NAND_PF    = (1 << 3), // program fail
		SPI_NAND_EF    = (1 << 2), // erase fail
		SPI_NAND_WEL   = (1 << 1), // write enable latch
		SPI_NAND_OIP   = (1 << 0), // operation in progress
	} StatusRegBits;

typedef enum {
		SPI_NAND_DS0    = (1 << 6),
	} DieSelRegBits;

typedef enum {
		ReadFromCache,
		ReadFromCacheX2,
		ReadFromCacheX4,
		ReadFromCacheDualIO,
		ReadFromCacheQuadIO,
	} PageReadMode;

// Low level functions
uint16_t micron_nand_flash_ReadID(void); // read identification registers
void csLow(void); // cs pin low to w/r
void csHigh(void); // cs pin high no comm.
void clear_buffs_nand(); // flush all buffers and temps

//   List of APIs
void micron_nand_flash_Init(void);
void micron_nand_flash_reset(void);
void micron_nand_flash_until_ready(void);
void micron_nand_flash_check_busy(void);
void micron_nand_flash_write_enable_disable(uint8_t en_dis);
void micron_nand_flash_get_feature(RegisterAddr reg_addr, uint8_t reg);
void micron_nand_flash_set_feature(RegisterAddr reg_addr, uint8_t reg);
void micron_nand_flash_block_erase(PhysicalAddrs *addr);
void micron_nand_flash_page_read(PhysicalAddrs *addr, uint16_t length,uint8_t buffer[length-1] );
void micron_nand_flash_page_program(PhysicalAddrs *addr, uint16_t length,uint8_t buffer[length-1] );

#endif

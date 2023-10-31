/*******************************************************************************
**
** -----------------------------------------------------------------------------
** File Name    : ISOUDS_RdCfg.h
**
** Description  : Include file component for ISOUDS_RdCfg.c
**
** -----------------------------------------------------------------------------
**
*******************************************************************************/

/* To avoid multi-inclusions */
#ifndef ISOUDS_RDCFG_H
#define ISOUDS_RDCFG_H

/************************************* Inclusion files ************************/
#include "ISOUDS_WrDaByID_Cfg.h"
#include "ISOUDS_Server_Cfg.h"
#include "ISOUDS_RdDaByID_HAL.h"

/************************** Declaration of global symbol and constants ********/
/* Number of Periodic Read DID's */

#define ISOUDS_MAX_NO_OF_IDS_ALLOWED	(5)

/* DID Read Configuration Table size */
#define     ISOUDS_RDCONFTABSIZE     (15U)

#define		ISOUDS_RDBID_MAX_SA_LEVEL	1U

/* READ DID's */

/*ECU Status Message DID and LEN*/
#define		ISOUDS_ECU_STATUS_MSG							0xEF01U
#define		ISOUDS_ECU_STATUS_MSG_LEN						6U

/*SYMC Part Number DID and LEN*/
#define		ISOUDS_SYMC_PART_NUM							0xF187U
#define		ISOUDS_SYMC_PART_NUM_LEN						10U

/*SYMC Software version DID and LEN*/
#define		ISOUDS_SYMC_SOFTWARE_VER						0xF189U
#define		ISOUDS_SYMC_SOFTWARE_VER_LEN					2U

/*System supplier code DID and LEN*/
#define		ISOUDS_SYSTEM_SUPP_CODE							0xF18AU
#define		ISOUDS_SYSTEM_SUPP_CODE_LEN						5U

/*ECU Manufacturing Date DID and LEN*/
#define		ISOUDS_ECU_MANUFACT_DATE						0xF18BU
#define		ISOUDS_ECU_MANUFACT_DATE_LEN					3U

/*ECU Serial Number DID and LEN*/
#define		ISOUDS_ECU_SERIAL_NUM							0xF18CU
#define		ISOUDS_ECU_SERIAL_NUM_LEN						30U

/*VIN Data DID and LEN*/
#define		ISOUDS_VEH_ID_NUM_DATA							0xF190U
#define		ISOUDS_VEH_ID_NUM_DATA_LEN						17U

/*Repair Shop-Code or Tester Serial Number DID and LEN*/
#define		ISOUDS_TESTER_SER_NO							0xF198U
#define		ISOUDS_TESTER_SER_NO_LEN						8U

/*Programming Date DID and LEN*/
#define		ISOUDS_PROGRAMMING_DATE							0xF199U
#define		ISOUDS_PROGRAMMING_DATE_LEN						3U

/*Diagnostic Information DID and LEN*/
#define		ISOUDS_DIAGNOSTIC_INFO							0xF1A0U
#define		ISOUDS_DIAGNOSTIC_INFO_LEN						2U

/*Programming Identification Information DID and LEN*/
#define		ISOUDS_PROGRAM_IDENT_INFO						0xF1A1U
#define		ISOUDS_PROGRAM_IDENT_INFO_LEN					14U

/*Programming Identification Information DID and LEN*/
#define		ISOUDS_HARDWARE_VER     						0xF1A2U
#define		ISOUDS_HARDWARE_VER_LEN					        2U

/*Programming Identification Information DID and LEN*/
#define		ISOUDS_CAN_DB_VER       						0xF1A3U
#define		ISOUDS_CAN_DB_VER_LEN					        4U

/*ECU Information DID and LEN*/
#define		ISOUDS_ECU_INFO								    0x12B0U
#define		ISOUDS_ECU_INFO_LEN							    16U

/*ECU QR Code DID and LEN*/
#define		ISOUDS_QR_CODE		    						0x12B1U
#define		ISOUDS_QR_CODE_LEN 							    21U

/* DIDs Data Bytes*/
/*ECU Status Message DID Data Bytes*/

/* Supply voltage level */
#define		ISOUDS_ECUSTATMSG_SUPPLYVTGLEV_LEN				1U
#define		ISOUDS_ECUSTATMSG_SUPPLYVTGLEV_POS				0U

/*CMX Version of CAN-1*/
#define		ISOUDS_ECUSTATMSG_CMXVERCAN1_LEN				2U
#define		ISOUDS_ECUSTATMSG_CMXVERCAN1_POS				1U

/*CAN Transmit error counter of CAN-1*/
#define		ISOUDS_ECUSTATMSG_TRANSMERRCNTRCAN1_LEN			1U
#define		ISOUDS_ECUSTATMSG_TRANSMERRCNTRCAN1_POS			3U

/*CAN Receive error counter of CAN-1*/
#define		ISOUDS_ECUSTATMSG_RECEIVEERRCNTRCAN1_LEN		1U
#define		ISOUDS_ECUSTATMSG_RECEIVEERRCNTRCAN1_POS		4U

/*CAN BusOff Counter of CAN-1*/
#define		ISOUDS_ECUSTATMSG_CANBUSOFFCNTRCAN1_LEN			1U
#define		ISOUDS_ECUSTATMSG_CANBUSOFFCNTRCAN1_POS			5U

/* Programming Identification Information Data Bytes */
/*Flash document version number Length */
#define		ISOUDS_PROGIDINFO_FLSHDOCVERNUM_LEN				1U
#define		ISOUDS_PROGIDINFO_FLSHDOCVERNUM_POS				0U

/*Status Flag Length */
#define		ISOUDS_PROGIDINFO_STATFLAG_LEN					1U
#define		ISOUDS_PROGIDINFO_STATFLAG_POS					1U

/*Support Flag Length */
#define		ISOUDS_PROGIDINFO_SUPPFLAG_LEN					1U
#define		ISOUDS_PROGIDINFO_SUPPFLAG_POS					2U

/*Security Class Length */
#define		ISOUDS_PROGIDINFO_SECCLASS_LEN					1U
#define		ISOUDS_PROGIDINFO_SECCLASS_POS					3U

/*Number of code blocks Length */
#define		ISOUDS_PROGIDINFO_NUMOFCODEBLKS_LEN				1U
#define		ISOUDS_PROGIDINFO_NUMOFCODEBLKS_POS				4U

/*Reprogramming Attempt Counter Length */
#define		ISOUDS_PROGIDINFO_REPROGATTMCNT_LEN				2U
#define		ISOUDS_PROGIDINFO_REPROGATTMCNT_POS				5U

/*Max number of Attempt Counter Length */
#define		ISOUDS_PROGIDINFO_MAXNUMATTMCNT_LEN				2U
#define		ISOUDS_PROGIDINFO_MAXNUMATTMCNT_POS				7U

/*Number of data blocks Length */
#define		ISOUDS_PROGIDINFO_NUMOFDATABLKS_LEN				1U
#define		ISOUDS_PROGIDINFO_NUMOFDATABLKS_POS				9U

/*Reprogramming Attempt Counter Length */
#define		ISOUDS_PROGIDINFO_REPROGATTMCNTDA_LEN			2U
#define		ISOUDS_PROGIDINFO_REPROGATTMCNTDA_POS			10U

/*Max number of Attempt Counter Length */
#define		ISOUDS_PROGIDINFO_MAXNUMATTMCNTDA_LEN			2U
#define		ISOUDS_PROGIDINFO_MAXNUMATTMCNTDA_POS			12U


/* Eeprom DataId for DID */
/* Vehicle Identification Number DID*/
#define EEPROM_DID_VehIDNum_ID             		0x0003

/* Tester Serial Number DID*/
#define EEPROM_DID_TestSerialNum_ID             0x0004

/* Programming Date. DID*/
#define EEPROM_DID_ProgramDate_ID             	0x0005

/* Programming attempt count */
#define EEPROM_DID_PRGM_ATMPT_CNT				0x0006

/* SYMC Part number */
#define EEPROM_DID_PART_NUMBER   				0x0100

/* SYMC SW Version */
#define EEPROM_DID_SW_VERSION   				0x0101

/* ECU Info */
#define EEPROM_DID_ECU_INFO        				0x0102

/* QR Code */
#define EEPROM_DID_QR_CODE         				0x0103

/* Hardware Version */
#define EEPROM_DID_HW_Version				    0x0104

/********************************* Declaration of global macros ***************/

/********************************* Declaration of global types ****************/
typedef struct
{
    uint16_t rdDid;                           /* Data Identifier */
    uint8_t  rdDidLen;                        /* DID length - no. of bytes */
    uint8_t *rdDidAddr;                       /* address of the DID */
    uint8_t (*rdDid_funPtr) (uint8_t buffer[], uint16_t len);/* Function pointer to callback
												function */
    uint8_t  rdDidSess;                       /* session in which the DID is
												supported */
    uint8_t  secured;                       /* Secured */
    uint8_t NoSecAccssSup;
    ISOUDS_SASuppLevel SecAccssLevl[ISOUDS_RDBID_MAX_SA_LEVEL];
}ISOUDS_RdDidType;

/****************************** External links of global variables ************/

/****************************** External links of global constants ************/
extern const ISOUDS_RdDidType ISOUDS_RdConfTab[ISOUDS_RDCONFTABSIZE];
extern uint16_t  locDID[ISOUDS_MAX_NO_OF_IDS_ALLOWED];
/*******************************************************************************
**                                      FUNCTIONS                              *
*******************************************************************************/

/********************************** Function definitions **********************/
/***************************************************************************************************
** Function                 : ISOUDS_Get_RDCONFTABSIZE

** Description              : Return the Number of Subfunctions configured for Read DID

** Paramete           		: None

** Return value             : retVal : Number of DIDs Supported

** Remarks                  : None
***************************************************************************************************/
extern uint16_t ISOUDS_Get_RDCONFTABSIZE(void);

/***************************************************************************************************
** Function                 : ISOUDS_Get_MAXNoOfDIDAllowd
** Description              : Return the Max Number of DID Allowed for Read DID
** Paramete           		: None
** Return value             : retVal : Number of MAX nnumber Supported
** Remarks                  : None
***************************************************************************************************/
extern uint16_t ISOUDS_Get_MAXNoOfDIDAllowd(void);

#endif  /* ISOUDS_RDCFG_H */

/*******************************************************************************
**
** -----------------------------------------------------------------------------
** File Name    : ISOUDS_RdDaByPdID_HAL.h
**
** Description  : Include file of component ISOUDS_RdDaByPdID_HAL.c
**
** -----------------------------------------------------------------------------
**
*******************************************************************************/

/* To avoid multi-inclusions */
#ifndef ISOUDS_RDDABYPDID_HAL_H
#define ISOUDS_RDDABYPDID_HAL_H

/************************************* Inclusion files ************************/
#include "ISOUDS_Server.h"
#include "ISOUDS_RdDaByPdIDCfg.h"
#include "ISOUDS_RdDaByPdID.h"
/************************** Declaration of global symbol and constants ********/

/********************************* Declaration of global macros ***************/
/* READ DID's */

/* Read Periodic Call back function for Identifier 0x00 */
#define 	READ_PERIODIC_DID_DATA_ID_0             Get_PeriodicDataF200
/* Identifier 0x00 */
#define     ISOUDS_RDPD_ID_0                         (uint16_t)0x00
/* Identifier 0x00 Read Data length */
#define 	ISOUDS_RDPDID0_DATA_LEN                  (uint8_t)1


/* Read Periodic Call back function for Identifier 0x01 */
#define		READ_PERIODIC_DID_DATA_ID_1             Get_PeriodicDataF201
/* Identifier 0x01 */
#define     ISOUDS_RDPD_ID_1                         (uint16_t)0x01
/* Identifier 0x01 Read Data length */
#define 	ISOUDS_RDPDID1_DATA_LEN                  (uint8_t)2

/* Identifier 0x02 */
/* Read Periodic Call back function for Identifier 0x02 */
#define		READ_PERIODIC_DID_DATA_ID_2             Get_PeriodicDataF202
#define     ISOUDS_RDPD_ID_2                         (uint16_t)0x02
/* Identifier 0x02 Read Data length */
#define 	ISOUDS_RDPDID2_DATA_LEN                  (uint8_t)3

/* Read Periodic Call back function for Identifier 0x03 */
#define		READ_PERIODIC_DID_DATA_ID_3             Get_PeriodicDataF203
/* Identifier 0x03 */
#define     ISOUDS_RDPD_ID_3                         (uint16_t)0x03
/* Identifier 0x03 Read Data length */
#define 	ISOUDS_RDPDID3_DATA_LEN                  (uint8_t)4


/* Read Periodic Call back function for Identifier 0x04 */
#define		READ_PERIODIC_DID_DATA_ID_4             Get_PeriodicDataF204
/* Identifier 0x04 */
#define     ISOUDS_RDPD_ID_4                         (uint16_t)0x04
/* Identifier 0x04 Read Data length */
#define 	ISOUDS_RDPDID4_DATA_LEN                  (uint8_t)5
/********************************* Declaration of global types ****************/

/****************************** External links of global variables ************/

/****************************** External links of global constants ************/

/*******************************************************************************
**                                      FUNCTIONS                              *
*******************************************************************************/

/********************************** Function definitions **********************/
extern uint8_t READ_PERIODIC_DID_DATA_ID_0(uint8_t buffer[], uint16_t len);
extern uint8_t READ_PERIODIC_DID_DATA_ID_1(uint8_t buffer[], uint16_t len);
extern uint8_t READ_PERIODIC_DID_DATA_ID_2(uint8_t buffer[], uint16_t len);
extern uint8_t READ_PERIODIC_DID_DATA_ID_3(uint8_t buffer[], uint16_t len);
extern uint8_t READ_PERIODIC_DID_DATA_ID_4(uint8_t buffer[], uint16_t len);

#endif  /* ISOUDS_RDDABYPDID_HAL_H */

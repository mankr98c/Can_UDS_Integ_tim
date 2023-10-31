/*******************************************************************************
** Copyright (c) 2018 Embitel
**
** This software is the property of Embitel .
** It can not be used or duplicated without Embitel authorization .
**
** -----------------------------------------------------------------------------
** File Name   : ISOUDS_WrCfg.h
** Module Name : UDS
** -----------------------------------------------------------------------------
**
** Description : Include file of component ISOUDS_WrCfg.c
**
** -----------------------------------------------------------------------------
**
** Documentation reference :
**
********************************************************************************
** R E V I S I O N H I S T O R Y
********************************************************************************
** V01.00
** - Baseline for UDS module
**
*******************************************************************************/

/* To avoid multi-inclusions */
#ifndef ISOUDS_WRCFG_H
#define ISOUDS_WRCFG_H

/************************************* Inclusion files ************************/
#include "ISOUDS_Server.h"

/************************** Declaration of global symbol and constants ********/
/* DID Write Configuration Table size */
#define ISOUDS_WRCONFTABSIZE            	(4U)
#define ISOUDS_WrDid_MaxSAlevel            	(2)

/* DID */
/*SYMC Part Number DID and LEN*/
#define		ISOUDS_WDID_SYMC_PART_NUM						    0xF187U
#define		ISOUDS_WDID_SYMC_PART_NUM_LEN					    10U

#define		ISOUDS_WDID_VEH_IDEN_NO								0xF190U
#define		ISOUDS_WDID_VEH_IDEN_NO_LEN							17U

#define		ISOUDS_WDID_ECU_INFO								0x12B0U
#define		ISOUDS_WDID_ECU_INFO_LEN							17U

#define		ISOUDS_WDID_QR_CODE		    						0x12B1U
#define		ISOUDS_WDID_QR_CODE_LEN 							22U

/* delete the below macros after integrating with application */
#define ISOUDS_WRITE_SUCC  (uint8_t)0
#define ISOUDS_WRITE_FAIL  (uint8_t)1
/********************************* Declaration f global macros ***************/

/********************************* Declaration of global types ****************/
typedef struct
{
    uint16_t wrDid;								/* Data Identifier */
    uint8_t  wrDidLen;							/* DID length - no. of bytes */
    uint8_t (*wrDid_funPtr) ( uint8_t  DestBuff[], uint8_t  len);	/* Function pointer to
													    callback function */
	uint8_t  wrDidSess;                       	/* session in which the DID is supported */
    uint8_t  secured;							/* Secured */
    uint8_t NoSecAccssSup;
    ISOUDS_SASuppLevel SecAccssLevl[ISOUDS_WrDid_MaxSAlevel];                      		/* Secured */
}ISOUDS_WrDidType;

/********************** External links of global variables ********************/

/********************** External links of global constants ********************/
extern const ISOUDS_WrDidType ISOUDS_WrConfTab[ISOUDS_WRCONFTABSIZE];

/*******************************************************************************
**                                FUNCTIONS 	                               *
*******************************************************************************/

/************************** Function definitions ******************************/
/***************************************************************************************************
** Function                 : ISOUDS_Get_WRCONFTABSIZE

** Description              : Return the Number of DIDs configured for Write DID

** Paramete           		: None

** Return value             : retVal : Number of DIDs Supported

** Remarks                  : None
***************************************************************************************************/
extern uint16_t ISOUDS_Get_WRCONFTABSIZE(void);
#endif  /* _ISOUDS_WRCFG_H_ */

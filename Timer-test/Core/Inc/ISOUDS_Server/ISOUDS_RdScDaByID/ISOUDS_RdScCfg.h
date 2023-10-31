/*******************************************************************************
** Copyright (c)
**
** This software is the property of Embitel .
** It can not be used or duplicated without Embitel authorization .
**
** -----------------------------------------------------------------------------
** File Name   : ISOUDS_RdScCfg.h
** Module Name : UDS
** -----------------------------------------------------------------------------
**
** Description :
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
#ifndef ISOUDS_RDSCCFG_H
#define ISOUDS_RDSCCFG_H

/************************************* Inclusion files ********************************************/
#include <stdint.h>
#include "ISOUDS_Server.h"

/************************** Declaration of global symbol and constants ****************************/
/* Read Scaling Data Configuration Table size */
#define     ISOUDS_RDSCCONFTABSIZE      1U

#define		ISOUDS_RdScDBIDMaxSAlevel	1U

/* NULL function pointer */
#define     ISOUDS_RDSCFUNCNULLPTR      ((uint8_t (*) (uint8_t srcBuff[], uint16_t len))0U)

/* DID Defines */
#define     ISOUDS_DUMMYSCID            (uint16_t)0xF190

/********************************* Declaration of global macros ***********************************/

/********************************* Declaration of global types ************************************/
typedef struct
{
    uint16_t rdScid;                              /* Scaling Data Identifier */
    uint16_t  rdScidLen;                           /* length - no. of bytes */
    uint8_t (*rdScid_funPtr) (uint8_t * RdScId_DataPtr, uint16_t RdScId_DataLen);   /* Function pointer to callback function */
	uint8_t SecAccssSup;
	uint8_t NoSecAccssSup;
    ISOUDS_SASuppLevel SecAccssLevl[ISOUDS_RdScDBIDMaxSAlevel];
}ISOUDS_RdScDidType;

/****************************** External links of global variables ********************************/

/****************************** External links of global constants ********************************/
extern const ISOUDS_RdScDidType ISOUDS_RdScConfTab[ISOUDS_RDSCCONFTABSIZE];

/***************************************************************************************************
**                                      FUNCTIONS                                                 **
***************************************************************************************************/

/********************************** Function definitions ******************************************/

/***************************************************************************************************
** Function                 : ISOUDS_Get_RDSCCONFTABSIZE

** Description              : Return the Number of Subfunctions configured for Read Scalind Data by ID

** Paramete           		: None

** Return value             : retVal : Number of DIDs Supported

** Remarks                  : None
***************************************************************************************************/
extern uint16_t ISOUDS_Get_RDSCCONFTABSIZE(void);

#endif  /* ISOUDS_RDSCCFG_H */

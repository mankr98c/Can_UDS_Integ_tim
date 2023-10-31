/*******************************************************************************
**
** -----------------------------------------------------------------------------
** File Name    : ISOUDS_DyDfDaIDCfg.h
**
** Description  : Include file component for ISOUDS_DyDfDaIDCfg.c
**
** -----------------------------------------------------------------------------
**
*******************************************************************************/

/* To avoid multi-inclusions */
#ifndef ISOUDS_DYDFDAIDCFG_H
#define ISOUDS_DYDFDAIDCFG_H

/************************************* Inclusion files ************************/
#include "string.h"
#include "ISOUDS_WrDaByID_Cfg.h"
#include "ISOUDS_Server_Cfg.h"

/************************** Declaration of global symbol and constants ********/
/* DID Read Configuration Table size */
#define     ISOUDS_DYDDCONFTABSIZE     (uint8_t)2
#define     ISOUDS_DYDBUFFSIZE     	   (uint8_t)100

#define		ISOUDS_DYDD_MAX_SA_LEVEL	1U

/* NULL function pointer */
#define     ISOUDS_DYFUNCNULLPTR     ((uint8_t (*) (uint8_t srcBuff[], uint16_t len))0)

/********************************* Declaration of global macros ***************/

/********************************* Declaration of global types ****************/
typedef struct
{
    uint16_t DyDid;                           /* Data Identifier */
    uint8_t  DyDidLen;                        /* DID length - no. of bytes */
	uint8_t  Buff[ISOUDS_DYDBUFFSIZE];
    uint8_t  DyDidSess;                       /* session in which the DID is 											supported */
    uint8_t  secured;                       /* Secured */
	uint8_t NoSecAccssSup;
    ISOUDS_SASuppLevel SecAccssLevl[ISOUDS_DYDD_MAX_SA_LEVEL];
}ISOUDS_DyDidType;

/****************************** External links of global variables ************/
extern ISOUDS_DyDidType ISOUDS_DyDDConfTab[ISOUDS_DYDDCONFTABSIZE];


/****************************** External links of global constants ************/

/***************************************************************************************************
** Function                 : ISOUDS_Get_DYDDCONFTABSIZE

** Description              : Return the Number of Subfunctions configured for Dynamically Define DID

** Paramete           		: None

** Return value             : retVal : Number of subfunctions

** Remarks                  : None
***************************************************************************************************/
extern uint16_t ISOUDS_Get_DYDDCONFTABSIZE(void);
#endif

/***************************************************************************************************
** Copyright (c) 2018 EMBITEL
**
** This software is the property of EMBITEL.
** It can not be used or duplicated without EMBITEL authorization.
**
** -------------------------------------------------------------------------------------------------
** File Name    : ISOUDS_RdMemByAddr_Cfg.h
** Module Name  : ISOUDS_RdMemByAddr_Cfg
** -------------------------------------------------------------------------------------------------
**
** Description : Include file of component ISOUDS_RdMemByAddr_Cfg.c
** This file must exclusively contain informations needed to
** use this component.
**
** -------------------------------------------------------------------------------------------------
**
** Documentation reference :
**
****************************************************************************************************
** R E V I S I O N H I S T O R Y
****************************************************************************************************
** V01.00 23/05/2019
** - Baseline Created
**
***************************************************************************************************/

/* To avoid multi-inclusions */
#ifndef ISOUDS_RDMEMBYADD_CFG_H
#define ISOUDS_RDMEMBYADD_CFG_H

/************************************* Inclusion files ********************************************/
#include "ISOUDS_RdMemByAddr_HAL.h"
/************************** Declaration of global symbol and constants ****************************/
/* DID Read Configuration Table size */

/********************************* Declaration of global macros ***********************************/

#define	ISOUDS_RdMemByAddMaxentries		(1U)
#define ISOUDS_RdMemByAddMaxSAlevel		(1U)
/********************************* Declaration of global types ************************************/
typedef struct
{
    uint8_t	MemAddLength;					/* Memory Address Length */
    uint8_t	MemSizeLength;					/* Memory size Length */
    uint32_t	MemStartAddress;				/* Start address of the configured memory  */
	uint32_t	MemMaxsize;						/* Maximum size of memory from MemStartAddress */
    uint8_t	SuptdSession;                   /* session in which the Memory Read is supported */
    uint8_t	secured;                      	/* Secured */
    uint8_t NoSecAccssSup;
    ISOUDS_SASuppLevel	secLev[ISOUDS_RdMemByAddMaxSAlevel];                      	/* Secured */
    uint8_t (*rdMemByAddr_funPtr) (uint32_t RdAddress, uint32_t RdLength, const uint8_t *RespBuff);/* Function pointer to callback*/
}ISOUDS_RdMemByAddType;


/****************************** External links of global variables ********************************/

/****************************** External links of global constants ********************************/
extern const ISOUDS_RdMemByAddType ISOUDS_RdMemByAddConfTab[ISOUDS_RdMemByAddMaxentries];

/***************************************************************************************************
**                                      FUNCTIONS                                                 **
***************************************************************************************************/

/********************************** Function Declaration ******************************************/

/***************************************************************************************************
** Function                 : ISOUDS_Get_RdDTCMaxSubFun

** Description              : Return the Number of entries configured for Read Memory by address

** Paramete           		: None

** Return value             : retVal : Number of Entries Supported

** Remarks                  : None
***************************************************************************************************/
extern uint16_t ISOUDS_Get_RdMemByAddMaxentries(void);

#endif  /* ISOUDS_RDMEMBYADD_CFG_H */

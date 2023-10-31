/***************************************************************************************************
** Copyright (c) 2018 EMBITEL
**
** This software is the property of EMBITEL.
** It can not be used or duplicated without EMBITEL authorization.
**
** -------------------------------------------------------------------------------------------------
** File Name    : ISOUDS_WrtMemByAddr_Cfg.h
** Module Name  : ISOUDS_WrtMemByAddr_Cfg
** -------------------------------------------------------------------------------------------------
**
** Description : Include file of component ISOUDS_WrtMemByAddr_Cfg.c
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
** V01.00 27/05/2019
** - Baseline Created
**
***************************************************************************************************/

/* To avoid multi-inclusions */
#ifndef ISOUDS_WRTMEMBYADD_CFG_H
#define ISOUDS_WRTMEMBYADD_CFG_H

/************************************* Inclusion files ********************************************/
#include <stdint.h>

/************************** Declaration of global symbol and constants ****************************/
/* DID Read Configuration Table size */

/********************************* Declaration of global macros ***********************************/

#define	ISOUDS_WrtMemByAddMaxentries		(1U)
#define ISOUDS_WrtMemByAddMaxSAlevel		(1U)
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
    ISOUDS_SASuppLevel	secLev[ISOUDS_WrtMemByAddMaxSAlevel];                      	/* Secured */
    uint8_t (*WrtMemByAddr_funPtr) (uint32_t RdAddress, uint32_t RdLength, uint8_t *RespBuff);/* Function pointer to callback*/
}ISOUDS_WrtMemByAddType;


/****************************** External links of global variables ********************************/

/****************************** External links of global constants ********************************/
extern const ISOUDS_WrtMemByAddType ISOUDS_WrtMemByAddConfTab[ISOUDS_WrtMemByAddMaxentries];

/***************************************************************************************************
**                                      FUNCTIONS                                                 **
***************************************************************************************************/

/********************************** Function Declaration ******************************************/

/***************************************************************************************************
** Function                 : ISOUDS_Get_WrtMemByAddMaxentries

** Description              : Return the Number of Entries configured for Write Memory By Address

** Paramete           		: None

** Return value             : retVal : Number of Entries Supported

** Remarks                  : None
***************************************************************************************************/
extern uint16_t ISOUDS_Get_WrtMemByAddMaxentries(void);
#endif  /* ISOUDS_WRTMEMBYADD_CFG_H */

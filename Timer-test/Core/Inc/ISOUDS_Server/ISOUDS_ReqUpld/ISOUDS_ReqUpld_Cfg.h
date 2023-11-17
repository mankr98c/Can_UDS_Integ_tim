/***************************************************************************************************
** Copyright (c) 2018 EMBITEL
**
** This software is the property of EMBITEL.
** It can not be used or duplicated without EMBITEL authorization.
**
** -------------------------------------------------------------------------------------------------
** File Name    : ISOUDS_ReqUpld_Cfg.h
** Module Name  : ISOUDS_ReqUpld_Cfg
** -------------------------------------------------------------------------------------------------
**
** Description : Include file of component ISOUDS_ReqDwnld_Cfg.c
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
#ifndef ISOUDS_REQUPLD_CFG_H
#define ISOUDS_REQUPLD_CFG_H

/************************************* Inclusion files ********************************************/
#include "ISOUDS_ReqUpld_HAL.h"
/************************** Declaration of global symbol and constants ****************************/
/* DID Read Configuration Table size */

/********************************* Declaration of global macros ***********************************/

#define	ISOUDS_ReqUpldMaxentries		(17U)
#define ISOUDS_ReqUpldMaxSAlevel		(1U)

#define ISOUDS_UPLOAD_BLKLENFRMTID	(uint8_t)0x20U			/* Block lengthFormatIdentifier */
#define ISOUDS_UPLOAD_BLOCK_LENGTH	(uint8_t)0x0100U		/* maxNumberOfBlockLength */
//#define   ISOUDS_UPLOAD_DAFRMTID				(uint8_t)(0x00)
//#define   ISOUDS_UPLOAD_ADDRLENFRMTID			(uint8_t)(0x11)

/* Address of memory blocks */
#define     FLASH_UPLOAD_START_ADDR     0x0000C000UL
#define     FLASH_UPLOAD_END_ADDR       0x0006FFFFUL
/********************************* Declaration of global types ****************/

typedef struct
{
    uint8_t	MemAddLength;					/* Memory Address Length */  /*0x23 7-4[memory size],0-3[memory adress] Memory adress memory size*/
    uint8_t	MemSizeLength;					/* Memory size Length */ /*0x23 0x44 0x12 0x34 0x56 0x78 0x11 0x22 0x33 0x44 */
    uint8_t Compressn_Type;					/* Compression Type */
    uint8_t Encyrptn_Type;					/* Emcryption Type */
    uint8_t	SuptdSession;                   /* session in which the Memory Read is supported */
    uint8_t	SecAccssSup;                      	/* Secured */
    uint8_t NoSecAccssSup;
    ISOUDS_SASuppLevel SecAccssLevl[ISOUDS_ReqUpldMaxSAlevel];
	uint8_t (*rdMemByAddr_funPtr) (unsigned long RdAddress, unsigned long RdLength, uint8_t *RespBuff);/* Function pointer to callback*/
}ISOUDS_ReqUpldType;


/****************************** External links of global variables ********************************/

/****************************** External links of global constants ********************************/
extern const ISOUDS_ReqUpldType ISOUDS_ReqUpldConfTab[ISOUDS_ReqUpldMaxentries];

/***************************************************************************************************
**                                      FUNCTIONS                                                 **
***************************************************************************************************/

/********************************** Function Declaration ******************************************/

#endif  /* ISOUDS_REQUPLD_CFG_H */

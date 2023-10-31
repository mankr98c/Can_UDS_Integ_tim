/***************************************************************************************************
** Copyright (c) 2018 EMBITEL
**
** This software is the property of EMBITEL.
** It can not be used or duplicated without EMBITEL authorization.
**
** -------------------------------------------------------------------------------------------------
** File Name    : ISOUDS_ReqDwnld_Cfg.h
** Module Name  : ISOUDS_ReqDwnld_Cfg
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
#ifndef ISOUDS_REQDNLD_CFG_H
#define ISOUDS_REQDNLD_CFG_H

/************************************* Inclusion files ********************************************/
#include "ISOUDS_ReqDwnld_HAL.h"
/************************** Declaration of global symbol and constants ****************************/
/* DID Read Configuration Table size */

/********************************* Declaration of global macros ***********************************/
#define ISOUDS_ReqDwnldMaxentries  17U

#define ISOUDS_ReqDwnldMaxSAlevel		(1U)

#define ISOUDS_DOWNLOAD_BLKLENFRMTID	(uint8_t)0x20U			/* Block lengthFormatIdentifier */
#define ISOUDS_DOWNLOAD_BLOCK_LENGTH	(uint16_t)0x0100U		/* maxNumberOfBlockLength */

/* Address of memory blocks */
#define     FLASH_DOWNLOAD_START_ADDR     0x0000C000UL
#define     FLASH_DOWNLOAD_END_ADDR       0x0006FFFFUL
/********************************* Declaration of global types ****************/


typedef struct
{
    uint8_t	MemAddLength;					/* Memory Address Length */  /*0x23 7-4[memory size],0-3[memory adress] Memory adress memory size*/
    uint8_t	MemSizeLength;					/* Memory size Length */ /*0x23 0x44 0x12 0x34 0x56 0x78 0x11 0x22 0x33 0x44 */
	uint8_t 	Compressn_Type;					/* Compression Type */
	uint8_t 	Encyrptn_Type;					/* Emcryption Type */
    uint8_t	SuptdSession;                   /* session in which the Memory Read is supported */
    uint8_t	SecAccssSup;                      	/* Secured */
     uint8_t NoSecAccssSup;
    ISOUDS_SASuppLevel SecAccssLevl[ISOUDS_ReqDwnldMaxSAlevel];
	uint8_t (*rdMemByAddr_funPtr) (unsigned long RdAddress, unsigned long RdLength, uint8_t *RespBuff);/* Function pointer to callback*/
}ISOUDS_ReqDwnldType;


/****************************** External links of global variables ********************************/

/****************************** External links of global constants ********************************/
extern const ISOUDS_ReqDwnldType ISOUDS_ReqDwnldConfTab[ISOUDS_ReqDwnldMaxentries];

/***************************************************************************************************
**                                      FUNCTIONS                                                 **
***************************************************************************************************/

/********************************** Function Declaration ******************************************/

#endif  /* ISOUDS_RDMEMBYADD_CFG_H */

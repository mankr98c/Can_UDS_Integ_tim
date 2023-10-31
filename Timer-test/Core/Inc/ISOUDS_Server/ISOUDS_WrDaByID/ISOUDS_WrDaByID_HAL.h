/*******************************************************************************
** Copyright (c) 2018 Embitel
**
** This software is the property of Embitel .
** It can not be used or duplicated without Embitel authorization .
**
** -----------------------------------------------------------------------------
** File Name   : ISOUDS_WrDaByID_HAL.h
** Module Name : UDS
** -----------------------------------------------------------------------------
**
** Description : Include file of component ISOUDS_WrDaByID.c
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
#ifndef ISOUDS_WRDABYID_HAL_H
#define ISOUDS_WRDABYID_HAL_H

/****************************** Inclusion files *******************************/
#include <ISOUDS_WrDaByID_Cfg.h>

/******************* Declaration of global symbol and constants ***************/

/************************ Declaration of global macros ************************/

/************************* Declaration of global types ************************/

/*********************** External links of global variables *******************/

/************************ External links of global constants ******************/

/*******************************************************************************
**                                 FUNCTIONS                                   *
*******************************************************************************/

/**************************** Function definitions ****************************/
extern uint8_t HAL_WriteStatus(void);
extern uint8_t  ISOUDS_Write_SYMC_PartNoCbk(uint8_t  DestBuff[], uint8_t  len);
extern uint8_t  ISOUDS_Write_VehIdenNoCbk(uint8_t  DestBuff[], uint8_t  len);
extern uint8_t  ISOUDS_Write_EcuInfoCbk(uint8_t  DestBuff[], uint8_t  len);
extern uint8_t  ISOUDS_Write_QRCodeCbk(uint8_t  DestBuff[], uint8_t  len);

#endif  /* _ISOUDS_WRDABYID_HAL_H_ */

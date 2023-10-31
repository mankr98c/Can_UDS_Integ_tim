/*******************************************************************************
** Copyright (c) 2018 Embitel
**
** This software is the property of Embitel .
** It can not be used or duplicated without Embitel authorization .
**
** -----------------------------------------------------------------------------
** File Name   : ISOUDS_RtnCtrl_HAL.h
** Module Name : UDS
** -----------------------------------------------------------------------------
**
** Description : Include file of component ISOUDS_RtnCtrl.c
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
#ifndef ISOUDS_RTNCTRL_HAL_H
#define ISOUDS_RTNCTRL_HAL_H

/************************************* Inclusion files ************************/

/************************** Declaration of global symbol and constants ********/

/********************************* Declaration of global macros ***************/
#define ISOUDS_ERASESUCCESS						0x00
#define ISOUDS_ERASEFAILURE						0x01
/********************************* Declaration of global types ****************/

/****************************** External links of global variables ************/

/****************************** External links of global constants ************/

/*******************************************************************************
**                                      FUNCTIONS                              *
*******************************************************************************/

/********************************** Function definitions **********************/
extern uint8_t HAL_RtnCntrlPreCondCheck(void);
															
extern uint8_t HAL_RtnCheckMemory(ISOUDS_ConfType *ISOUDSConfPtr, uint16_t RtnCntrlID, uint8_t RtnType, \
															uint8_t *Data, uint16_t *RespLenth);

extern uint8_t HAL_RtnEraseMemory(ISOUDS_ConfType *ISOUDSConfPtr, uint16_t RtnCntrlID, uint8_t RtnType, \
															uint8_t *Data, uint16_t *RespLenth);

extern uint8_t HAL_RtnChecProgDependencies(ISOUDS_ConfType *ISOUDSConfPtr, uint16_t RtnCntrlID, uint8_t RtnType, \
															uint8_t *Data, uint16_t *RespLenth);

#endif  /* _ISOUDS_RTNCTRL_HAL_H_ */

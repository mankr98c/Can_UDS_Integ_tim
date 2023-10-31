/*******************************************************************************
** Copyright (c) 2018 Embitel
**
** This software is the property of Embitel .
** It can not be used or duplicated without Embitel authorization .
**
** -----------------------------------------------------------------------------
** File Name   : ISOUDS_IOCtrlByID_HAL.h
** Module Name : UDS
** -----------------------------------------------------------------------------
**
** Description : Include file of component ISOUDS_IOCtrlByID.c
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
#ifndef ISOUDS_IOCTRLBYID_HAL_H
#define ISOUDS_IOCTRLBYID_HAL_H

/************************************* Inclusion files ************************/

/************************** Declaration of global symbol and constants ********/

/********************************* Declaration of global macros ***************/

/********************************* Declaration of global types ****************/

/****************************** External links of global variables ************/

/****************************** External links of global constants ************/

/*******************************************************************************
**                                      FUNCTIONS                              *
*******************************************************************************/

/********************************** Function definitions **********************/
extern uint8_t HAL_IOCntrlPreCondCheck(void);
extern uint8_t HAL_IOctrlTestRtn(uint16_t IOCntrlID, uint8_t IOCntrlParam, uint8_t *Data, uint16_t *RespLenth);
extern uint8_t HAL_IOctrlFrtHeatPwr(uint16_t IOCntrlID, uint8_t IOCntrlParam, uint8_t *Data, uint16_t *RespLenth);
extern uint8_t HAL_IOctrlRearHeatPwr(uint16_t IOCntrlID, uint8_t IOCntrlParam, uint8_t *Data, uint16_t *RespLenth);
extern uint8_t HAL_IOctrlFrtVentPwr(uint16_t IOCntrlID, uint8_t IOCntrlParam, uint8_t *Data, uint16_t *RespLenth);

#endif  /* ISOUDS_IOCTRLBYID_HAL_H */

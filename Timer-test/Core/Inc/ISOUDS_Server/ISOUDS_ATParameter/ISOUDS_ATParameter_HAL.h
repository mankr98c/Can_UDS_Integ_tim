/***************************************************************************************************
** Copyright (c) 2018 EMBITEL
**
** This software is the property of EMBITEL .
** It can not be used or duplicated without EMBITEL authorization .
**
** -------------------------------------------------------------------------------------------------
** File Name   : ISOUDS_ATParameter_HAL.h
** Module Name : UDS
** -------------------------------------------------------------------------------------------------
**
** Description : Access Timing Parameter Service
**
** -------------------------------------------------------------------------------------------------
**
** Documentation reference :
**
****************************************************************************************************
** R E V I S I O N H I S T O R Y
****************************************************************************************************
** V01.00
** - Baseline for UDS module
**
***************************************************************************************************/

/* To avoid multi-inclusions */
#ifndef ISOUDS_ATPARAMETER_HAL_H
#define ISOUDS_ATPARAMETER_HAL_H

/************************************* Inclusion files ********************************************/
#include "ISOUDS_Server.h"
#include "ISOUDS_ATParameter_Cfg.h"

/************************** Declaration of global symbol and constants ****************************/

/********************************* Declaration of global macros ***********************************/

/********************************* Declaration of global types ************************************/

/****************************** External CANks of global variables ********************************/

/****************************** External CANks of global constants ********************************/

/***************************************************************************************************
**                                      FUNCTIONS                              					   *
***************************************************************************************************/

/********************************** Function definitions ******************************************/

extern uint8_t HAL_AccessTimParamPreCondCheck(void);
extern uint8_t HAL_readExtendedTimingParameterSet_Cbk(uint8_t *Data,uint16_t *RespByes);
extern uint8_t HAL_setTimingParametersToDefaultValues_cbk(uint8_t *Data,uint16_t *RespByes);
extern uint8_t HAL_readCurrentlyActiveTimingParameters_Cbk(uint8_t *Data,uint16_t *RespByes);
extern uint8_t HAL_setTimingParametersToGivenValues_Cbk(uint8_t *Data,uint16_t *RespByes);

#endif  /* _ISOUDS_ATPARAMETER_HAL_H_ */

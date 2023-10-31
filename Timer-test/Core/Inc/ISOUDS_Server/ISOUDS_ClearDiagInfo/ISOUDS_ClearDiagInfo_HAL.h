/*******************************************************************************
** Copyright (c) 2018 Embitel
**
** This software is the property of Embitel .
** It can not be used or duplicated without Embitel authorization .
**
** -----------------------------------------------------------------------------
** File Name   : ISOUDS_ClearDiagInfo_HAL.h
** Module Name : UDS
** -----------------------------------------------------------------------------
**
** Description : This service Clears DTCs
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
#ifndef ISOUDS_CLRDTC_HAL_H
#define ISOUDS_CLRDTC_HAL_H

/************************************* Inclusion files ************************/
#include "ISOUDS_Server.h"

/************************** Declaration of global symbol and constants ********/

/********************************* Declaration of global macros ***************/

/********************************* Declaration of global types ****************/

/****************************** External CANks of global variables ************/

/****************************** External CANks of global constants ************/

/*******************************************************************************
**                                      FUNCTIONS                              *
*******************************************************************************/

/********************************** Function definitions **********************/
extern uint8_t HAL_ClearDTCInfoPreCondCheck(void);
extern uint8_t HAL_CLearDTCInfoReq(uint32_t DTCNumber, uint8_t MemorySelection);
extern uint8_t HAL_CLearDTCInfoReqStat(void);
#endif  /* ISOUDS_CLRDTC_HAL_H */

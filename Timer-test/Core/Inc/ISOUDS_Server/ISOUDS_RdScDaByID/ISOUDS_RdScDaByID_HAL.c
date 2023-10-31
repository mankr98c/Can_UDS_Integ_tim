/*******************************************************************************
** Copyright (c)
**
** This software is the property of Embitel .
** It can not be used or duplicated without Embitel authorization .
**
** -----------------------------------------------------------------------------
** File Name   : ISOUDS_RdScDaByID_HAL.c
** Module Name : UDS
** -----------------------------------------------------------------------------
**
** Description :
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

/**************************************** Inclusion files *****************************************/
#include "ISOUDS_RdScCfg.h"
#include "ISOUDS_RdScDaByID_HAL.h"
#include "ISOUDS_Server.h"

#if (ISOUDS_APP_CONFIG == ISOUDS_SERVER)
/********************************* Declaration of local macros ************************************/

/********************************* Declaration of local types *************************************/

/******************************* Declaration of local variables ***********************************/

/******************************* Declaration of local constants ***********************************/

/****************************** Declaration of exported variables *********************************/

/****************************** Declaration of exported constants *********************************/

/***************************************************************************************************/
/******************************** Function definitions ********************************************/

uint8_t  ISOUDS_RdScIdDummyFunc(uint8_t * DataPtr, uint16_t DataLen)
{
	uint8_t RespVal = ISOUDS_POSRES;

	uint8_t LoopIdx;

	for(LoopIdx = 0U; LoopIdx < DataLen; LoopIdx++)
	{
		DataPtr[LoopIdx] = LoopIdx;
	}

	return RespVal;
}

#endif

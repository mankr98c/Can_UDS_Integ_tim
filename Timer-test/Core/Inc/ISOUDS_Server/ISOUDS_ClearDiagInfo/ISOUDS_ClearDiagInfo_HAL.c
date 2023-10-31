/*******************************************************************************
** Copyright (c) 2018 Embitel
**
** This software is the property of Embitel .
** It can not be used or duplicated without Embitel authorization .
**
** -----------------------------------------------------------------------------
** File Name   : ISOUDS_ClearDiagInfo_HAL.c
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

/**************************************** Inclusion files *********************/
#include "ISOUDS_Server_Cfg.h"
#include "ISOUDS_ClearDiagInfo_HAL.h"
#include "Fcm.h"

#if (ISOUDS_APP_CONFIG == ISOUDS_SERVER)
/********************** Declaration of local symbol and constants *************/

/********************************* Declaration of local macros ****************/

/********************************* Declaration of local types *****************/

/******************************* Declaration of local variables ***************/

/******************************* Declaration of local constants ***************/

/****************************** Declaration of exported variables *************/

/****************************** Declaration of exported constants *************/

/*******************************************************************************
**                                      FUNCTIONS                              *
*******************************************************************************/

/**************************** Internal functions declarations *****************/

/******************************** Function definitions ************************/

/*******************************************************************************
** Function                 : HAL_ClearDTCInfoPreCondCheck

** Description              : API to check preconditions of Clear DTC info service

** Parameter                : None

** Return value             : ISOUDS_TRUE or  ISOUDS_FALSE
*******************************************************************************/
uint8_t HAL_ClearDTCInfoPreCondCheck(void)
{
	uint8_t RetVal;
	/*Verify the preconditions and return ISOUDS_TRUE of ISOUDS_FALSE*/
	RetVal = ISOUDS_TRUE;
	return RetVal;
}

/*******************************************************************************
** Function                 : HAL_CLearDTCInfoReq

** Description              : API to check req of Clear DTC info service

** Parameter                : DTCNumber

** Return value             : ISOUDS_POSRES or other ISOUDS macros. refer ISOUDS_Server.h file
*******************************************************************************/
uint8_t HAL_CLearDTCInfoReq(uint32_t DTCNumber, uint8_t MemorySelection)
{

	uint8_t RespVal;
	(void)MemorySelection;
	/* User Specific Code */

	if (ISOUDS_CLRDIAG_INFO_MASK_VAL == DTCNumber)
	{
		//setWdtEn(PAL_HIGH);
		(void)FCM_ClearAllDTCInfo();
		//setWdtEn(PAL_LOW);
	    /* User specific implementation */
		RespVal = ISOUDS_POSRES;
	}
	else
	{
		/* Clear the Requested DTC */
		RespVal = FCM_ClearRequestdDTCInfo(DTCNumber, MemorySelection);

		if(FCM_TRUE == RespVal)
		{
			/* User specific implementation */
			RespVal = ISOUDS_POSRES;
		}
		else
		{
			/* User specific implementation */
			RespVal = ISOUDS_ROOR;
		}

	}
	
	return RespVal;
}

/*******************************************************************************
** Function                 : HAL_CLearDTCInfoReq

** Description              : API to check req of Clear DTC info service

** Parameter                : None

** Return value             : ISOUDS_POSRES or other ISOUDS macros. refer ISOUDS_Server.h file
*******************************************************************************/
uint8_t HAL_CLearDTCInfoReqStat(void)
{
	uint8_t RespVal;
    /* User specific implementation */
	RespVal = ISOUDS_POSRES;
	return RespVal;
}

#endif

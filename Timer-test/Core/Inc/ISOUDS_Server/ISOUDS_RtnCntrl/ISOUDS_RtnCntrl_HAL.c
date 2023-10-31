/*******************************************************************************
** Copyright (c) 2018 Embitel
**
** This software is the property of Embitel .
** It can not be used or duplicated without Embitel authorization .
**
** -----------------------------------------------------------------------------
** File Name   : ISOUDS_RtnCtrl_HAL.c
** Module Name : UDS
** -----------------------------------------------------------------------------
**
** Description : Routine Control service
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
#include "ISOUDS_Server.h"
#include "ISOUDS_RtnCntrl.h"
#include "ISOUDS_RtnCntrl_Cfg.h"
#include "ISOUDS_RtnCntrl_HAL.h"

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
** Function                 : HAL_RtnCntrlPreCondCheck
**
** Description              : Checks the pre conditions for Routine Control
**
** Parameters 				: None
**
**
** Return value             : ISOUDS_TRUE or ISOUDS_FALSE
*******************************************************************************/
uint8_t HAL_RtnCntrlPreCondCheck(void)
{
	uint8_t RetVal;
	/*User specific implementation*/
	RetVal = ISOUDS_TRUE;
	return RetVal;
}

/**************************************************************************************************
** Function                 : HAL_RtnCheckMemory
**
** Description              : API for Check Memory Routine control ID
**
** Parameters 				: RtnCntrlID : Routine Control ID
**            				: RtnType : Routine Type
**							: Data Pointer: Point to Node Identification Number if required
**							: RespLenth : Response lenth
** Return value             : ISOUDS_POSRES or update based on the condition.
**                            Please refer ISOUDS_Server.h file for macros
***************************************************************************************************/
uint8_t HAL_RtnCheckMemory(ISOUDS_ConfType *ISOUDSConfPtr, uint16_t RtnCntrlID, uint8_t RtnType, \
															uint8_t *Data, uint16_t *RespLenth)
{
	uint8_t RespVal = ISOUDS_CNC;
	
	if((ISOUDSConfPtr != NULL_PTR) && (Data != NULL_PTR) && (RespLenth != NULL_PTR))
	{
		(void)RtnType;
		(void)RtnCntrlID;
		
		if ((ISOUDS_TRUE == ISOUDS_Get_VehicleSpeed_Check()) && (ISOUDS_TRUE == ISOUDS_Get_EngineSpeed_Check()) \
															 && (ISOUDS_TRUE == ISOUDS_Get_Gear_Status_Check()))
		{
			
			
			Data[ISOUDS_ZERO] = ISOUDS_TWO;
			*RespLenth += ISOUDS_ONE;
			RespVal = ISOUDS_POSRES;
			
		}
		else
		{
			Data[ISOUDS_ZERO] = ISOUDS_FIVE;
			*RespLenth += ISOUDS_ONE;
			RespVal = ISOUDS_POSRES;
			
		}

	}
	else
	{
		/* Do Nothing */
	}
	return RespVal;
}



/**************************************************************************************************
** Function                 : HAL_RtnCheckMemory
**
** Description              : API for Erase Memory Routine control ID
**
** Parameters 				: RtnCntrlID : Routine Control ID
**            				: RtnType : Routine Type
**							: Data Pointer: Point to Node Identification Number if required
**							: RespLenth : Response lenth
** Return value             : ISOUDS_POSRES or update based on the condition.
**                            Please refer ISOUDS_Server.h file for macros
***************************************************************************************************/
uint8_t HAL_RtnEraseMemory(ISOUDS_ConfType *ISOUDSConfPtr, uint16_t RtnCntrlID, uint8_t RtnType, \
															uint8_t *Data, uint16_t *RespLenth)
{
	uint8_t RespVal = ISOUDS_CNC;

	if((ISOUDSConfPtr != NULL_PTR) && (Data != NULL_PTR) && (RespLenth != NULL_PTR))
	{
		(void)RtnType;
		(void)RtnCntrlID;

		if ((ISOUDS_TRUE == ISOUDS_Get_VehicleSpeed_Check()) && (ISOUDS_TRUE == ISOUDS_Get_EngineSpeed_Check()) \
															 && (ISOUDS_TRUE == ISOUDS_Get_Gear_Status_Check()))
		{


			Data[ISOUDS_ZERO] = ISOUDS_TWO;
			*RespLenth += ISOUDS_ONE;
			RespVal = ISOUDS_POSRES;

		}
		else
		{
			Data[ISOUDS_ZERO] = ISOUDS_FIVE;
			*RespLenth += ISOUDS_ONE;
			RespVal = ISOUDS_POSRES;

		}

	}
	else
	{
		/* Do Nothing */
	}
	return RespVal;
}


/**************************************************************************************************
** Function                 : HAL_RtnCheckMemory
**
** Description              : API for Erase Memory Routine control ID
**
** Parameters 				: RtnCntrlID : Routine Control ID
**            				: RtnType : Routine Type
**							: Data Pointer: Point to Node Identification Number if required
**							: RespLenth : Response lenth
** Return value             : ISOUDS_POSRES or update based on the condition.
**                            Please refer ISOUDS_Server.h file for macros
***************************************************************************************************/
uint8_t HAL_RtnChecProgDependencies(ISOUDS_ConfType *ISOUDSConfPtr, uint16_t RtnCntrlID, uint8_t RtnType, \
															uint8_t *Data, uint16_t *RespLenth)
{
	uint8_t RespVal = ISOUDS_CNC;

	if((ISOUDSConfPtr != NULL_PTR) && (Data != NULL_PTR) && (RespLenth != NULL_PTR))
	{
		(void)RtnType;
		(void)RtnCntrlID;

		if ((ISOUDS_TRUE == ISOUDS_Get_VehicleSpeed_Check()) && (ISOUDS_TRUE == ISOUDS_Get_EngineSpeed_Check()) \
															 && (ISOUDS_TRUE == ISOUDS_Get_Gear_Status_Check()))
		{


			Data[ISOUDS_ZERO] = ISOUDS_TWO;
			*RespLenth += ISOUDS_ONE;
			RespVal = ISOUDS_POSRES;

		}
		else
		{
			Data[ISOUDS_ZERO] = ISOUDS_FIVE;
			*RespLenth += ISOUDS_ONE;
			RespVal = ISOUDS_POSRES;

		}

	}
	else
	{
		/* Do Nothing */
	}
	return RespVal;
}

#endif

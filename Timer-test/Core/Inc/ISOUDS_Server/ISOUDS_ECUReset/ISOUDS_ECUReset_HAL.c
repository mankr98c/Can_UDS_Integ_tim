/***************************************************************************************************
**
** -------------------------------------------------------------------------------------------------
** File Name    : ISOUDS_ECUReset_HAL.c
**
** Description  : ECU Reset
**
** -------------------------------------------------------------------------------------------------
**
***************************************************************************************************/

/**************************************** Inclusion files *****************************************/
#include "ISOUDS_Server.h"
#include "ISOUDS_Server_Cfg.h"
#include "ISOUDS_ECUReset_HAL.h"

#if (ISOUDS_APP_CONFIG == ISOUDS_SERVER)
/********************** Declaration of local symbol and constants *********************************/

/********************************* Declaration of local macros ************************************/

/********************************* Declaration of local types *************************************/

/******************************* Declaration of local variables ***********************************/

/******************************* Declaration of local constants ***********************************/

/****************************** Declaration of exported variables *********************************/

/****************************** Declaration of exported constants *********************************/

/***************************************************************************************************
**                                      FUNCTIONS                                                 **
***************************************************************************************************/

/**************************** Internal functions declarations *************************************/

/******************************** Function definitions ********************************************/

/***************************************************************************************************
** Function                 : HAL_HardReset_Cond

** Description              : API to check hardrset conditions

** Parameter                : None

** Return value             : ISOUDS_TRUE or ISOUDS_FALSE
***************************************************************************************************/
uint8_t HAL_HardReset_Cond(void)
{
	uint8_t CondMeet;
	
	/*User specific implementation*/
	if ((ISOUDS_TRUE == ISOUDS_Get_VehicleSpeed_Check()) && (ISOUDS_TRUE == ISOUDS_Get_EngineSpeed_Check()) && \
																	(ISOUDS_TRUE == ISOUDS_Get_Gear_Status_Check()))
	{
		CondMeet = ISOUDS_TRUE;
	}
	else
	{
		CondMeet = ISOUDS_FALSE;
	}
	
	return CondMeet;
}

/***************************************************************************************************
** Function                 : HAL_KeyOffOnReset_Cond

** Description              : API to check KeyOffOnReset conditions

** Parameter                : None

** Return value             : ISOUDS_TRUE or ISOUDS_FALSE
***************************************************************************************************/
uint8_t HAL_KeyOffOnReset_Cond(void)
{
	uint8_t CondMeet;
	/*User specific implementation*/
	if ((ISOUDS_TRUE == ISOUDS_Get_VehicleSpeed_Check()) && (ISOUDS_TRUE == ISOUDS_Get_EngineSpeed_Check()) && \
																	(ISOUDS_TRUE == ISOUDS_Get_Gear_Status_Check()))
	{
		CondMeet = ISOUDS_TRUE;
	}
	else
	{
		CondMeet = ISOUDS_FALSE;
	}
	return CondMeet;

}

/***************************************************************************************************
** Function                 : HAL_SoftReset_Cond

** Description              : API to check SoftReset conditions

** Parameter                : None

** Return value             : ISOUDS_TRUE or ISOUDS_FALSE
***************************************************************************************************/
uint8_t HAL_SoftReset_Cond(void)
{
	uint8_t CondMeet;
	/*User specific implementation*/
	if ((ISOUDS_TRUE == ISOUDS_Get_VehicleSpeed_Check()) && (ISOUDS_TRUE == ISOUDS_Get_EngineSpeed_Check()) && \
																	(ISOUDS_TRUE == ISOUDS_Get_Gear_Status_Check()))
	{
		CondMeet = ISOUDS_TRUE;
	}
	else
	{
		CondMeet = ISOUDS_FALSE;
	}
	return CondMeet;
}

/***************************************************************************************************
** Function                 : HAL_EnablRpdPwrSD_Cond

** Description              : API to check EnablRpdPwrSD conditions

** Parameter                : None

** Return value             : ISOUDS_TRUE or ISOUDS_FALSE
***************************************************************************************************/
uint8_t HAL_EnablRpdPwrSD_Cond(void)
{
	uint8_t CondMeet;
	/*User specific implementation*/
	if ((ISOUDS_TRUE == ISOUDS_Get_VehicleSpeed_Check()) && (ISOUDS_TRUE == ISOUDS_Get_EngineSpeed_Check())\
																&& (ISOUDS_TRUE == ISOUDS_Get_Gear_Status_Check()))
	{
		CondMeet = ISOUDS_TRUE;
	}
	else
	{
		CondMeet = ISOUDS_FALSE;
	}
	return CondMeet;
}

/***************************************************************************************************
** Function                 : HAL_HardReset_Proc

** Description              : API to process HardReset

** Parameter                : None

** Return value             : UDS response codes. Refer ISOUDS_Server.h for macro's
***************************************************************************************************/
uint8_t HAL_HardReset_Proc(void)
{
	uint8_t RespVal;
	/*User specific implementation*/
	RespVal = ISOUDS_POSRES;
	return RespVal;
}

/***************************************************************************************************
** Function                 : HAL_KeyOffOnReset_Proc

** Description              : API to process KeyOffOnReset

** Parameter                : None

** Return value             : UDS response codes. Refer ISOUDS_Server.h for macro's
***************************************************************************************************/
uint8_t HAL_KeyOffOnReset_Proc(void)
{
	uint8_t RespVal;
	/*User specific implementation*/
	RespVal = ISOUDS_POSRES;
	return RespVal;
}

/***************************************************************************************************
** Function                 : HAL_SoftReset_Proc

** Description              : API to process SoftReset

** Parameter                : None

** Return value             : UDS response codes. Refer ISOUDS_Server.h for macro's
***************************************************************************************************/
uint8_t HAL_SoftReset_Proc(void)
{
	uint8_t RespVal;
	/*User specific implementation*/
	RespVal = ISOUDS_POSRES;
	return RespVal;
}

/***************************************************************************************************
** Function                 : HAL_EnablRpdPwrSD_Proc

** Description              : API to process EnablRpdPwrSD

** Parameter                : None

** Return value             : UDS response codes. Refer ISOUDS_Server.h for macro's
***************************************************************************************************/
uint8_t HAL_EnablRpdPwrSD_Proc(void)
{
	uint8_t RespVal;
	/*User specific implementation*/
	RespVal = ISOUDS_POSRES;
	return RespVal;
}

#endif

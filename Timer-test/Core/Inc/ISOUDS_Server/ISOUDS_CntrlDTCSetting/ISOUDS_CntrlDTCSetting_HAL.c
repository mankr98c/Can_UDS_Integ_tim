/*******************************************************************************
**
** -----------------------------------------------------------------------------
** File Name    : ISOUDS_CntrlDTCSetting_HAL.c
**
** Description  : Control DTC Setting Service
**
** -----------------------------------------------------------------------------
**
*******************************************************************************/

/**************************************** Inclusion files *********************/
#include "ISOUDS_Server_Cfg.h"
#include "ISOUDS_CntrlDTCSetting.h"
#include "ISOUDS_CntrlDTCSetting_Cfg.h"
#include "ISOUDS_CntrlDTCSetting_HAL.h"
#include "Fcm.h"

#if (SYMC_SECURITY == 1)
#include "fsymc_security.h"
#endif

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
** Function                 : HAL_CntrlDTCSetngPreCondCheck

** Description              : API to check Control DTC Setting preconditions

** Parameter                : None

** Return value             : ISOUDS_TRUE or ISOUDS_FALSE
*******************************************************************************/
uint8_t HAL_CntrlDTCSetngPreCondCheck(void)
{
	uint8_t RetVal;
	/* User specific implementation*/
	if ((ISOUDS_TRUE == ISOUDS_Get_VehicleSpeed_Check()) && (ISOUDS_TRUE == ISOUDS_Get_EngineSpeed_Check()) && (ISOUDS_TRUE == ISOUDS_Get_Gear_Status_Check()))
	{
		RetVal = ISOUDS_TRUE;
	}
	else
	{
		RetVal = ISOUDS_FALSE;
	}
    return RetVal;
}

/*******************************************************************************
** Function                 : HAL_CntrDTCSet_ON_Cbk

** Description              : API to make control dtc on

** Parameter                : None

** Return value             : ISOUDS response. refer ISOUDS_Server.h file for response codes
*******************************************************************************/
uint8_t HAL_CntrDTCSet_ON_Cbk(uint8_t DTCSettingType, const uint8_t *Data, uint16_t DataLen)
{
	uint8_t RespVal;
	(void) DTCSettingType;
	(void) Data;

    /* User specific implementation*/

	FCM_UpdateCntrolDTCSetting(FCM_DTC_SETTING_ON);
	
	RespVal = ISOUDS_POSRES;

    return RespVal;
}

/*******************************************************************************
** Function                 : HAL_CntrDTCSet_OFF_Cbk

** Description              : API to make control dtc off

** Parameter                : None

** Return value             : ISOUDS response. refer ISOUDS_Server.h file for response codes
*******************************************************************************/
uint8_t HAL_CntrDTCSet_OFF_Cbk(uint8_t DTCSettingType, const uint8_t *Data, uint16_t DataLen)
{
	uint8_t RespVal;
	(void) DTCSettingType;
	(void) Data;
	
#if (SYMC_SECURITY == 1)
	SYMC_UpdateSeed();
#endif

    /* User specific implementation*/
	FCM_UpdateCntrolDTCSetting(FCM_DTC_SETTING_OFF);
	RespVal = ISOUDS_POSRES;
	
    return RespVal;
}

#endif

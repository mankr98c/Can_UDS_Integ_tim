/*******************************************************************************
**
** -----------------------------------------------------------------------------
** File Name    : ISOUDS_CntrlDTCSetting_Cfg.c
**
** Description  : Communication Control Service Configuration
**
** -----------------------------------------------------------------------------
**
*******************************************************************************/

/**************************************** Inclusion files *********************/
#include "ISOUDS_Server_Cfg.h"
#include "ISOUDS_CntrlDTCSetting.h"
#include "ISOUDS_CntrlDTCSetting_Cfg.h"
#include "ISOUDS_CntrlDTCSetting_HAL.h"

#if (ISOUDS_APP_CONFIG == ISOUDS_SERVER)
/********************** Declaration of local symbol and constants *************/

/********************************* Declaration of local macros ****************/

/********************************* Declaration of local types *****************/

static uint8_t ISOUDS_CntrDTCSet_ON_Cbk(uint8_t DTCSettingType,const uint8_t *Data, uint16_t DataLen);
static uint8_t ISOUDS_CntrDTCSet_OFF_Cbk(uint8_t DTCSettingType,const uint8_t *Data, uint16_t DataLen);


/******************************* Declaration of local variables ***************/

ISOUDS_CntrlDTCSetCfg_t ISOUDS_CntrlDTCSetCfgTbl[ISOUDS_CntrlDTCSetMaxSubFun] =	{
																					{
																						ISOUDS_DTC_SETNG_ON,
																						EXTENDED_SESS,
																						ISOUDS_FALSE,
																						1,
	 																					{UnlockedL1},
																						&ISOUDS_CntrDTCSet_ON_Cbk
																					},
																					{
																						ISOUDS_DTC_SETNG_OFF,
																						EXTENDED_SESS,
																						ISOUDS_FALSE,
																						2,
	 																					{UnlockedL1},
																						&ISOUDS_CntrDTCSet_OFF_Cbk
																					}
																				};

/******************************* Declaration of local constants ***************/

/****************************** Declaration of exported variables *************/

/****************************** Declaration of exported constants *************/

/*******************************************************************************
**                                      FUNCTIONS                              *
*******************************************************************************/

/******************************** Function definitions ************************/

/***************************************************************************************************
** Function                 : ISOUDS_Get_CntrlDTCSetMaxSubFun

** Description              : Return the Number of Subfunctions configured for the Control DTC settings

** Paramete           		: None

** Return value             : retVal : Number of subfunctions

** Remarks                  : None
***************************************************************************************************/
uint8_t ISOUDS_Get_CntrlDTCSetMaxSubFun(void)
{
	return ISOUDS_CntrlDTCSetMaxSubFun;
}

/*******************************************************************************
** Function                 : ISOUDS_CntrlDTCSetngPreCondCheck
**
** Description              : Checks the pre conditions for Control DTC setting
**
** Parameters 				: None
**
**
** Return value             : RetVal : Pre condition validity
*******************************************************************************/
uint8_t ISOUDS_CntrlDTCSetngPreCondCheck(void)
{
	uint8_t RetVal = ISOUDS_TRUE;

	

	/* Add Code to check the Pre-conditions and update RetVal accordingly */
	RetVal = HAL_CntrlDTCSetngPreCondCheck();

	return RetVal;
}

/**************************** Internal Function definitions *******************/
/*******************************************************************************
** Function                 : ISOUDS_CntrDTCSet_ON_Cbk
**
** Description              : Control DTC settings ON
**
** Parameters 				: DTCSettingType : DTC setting Tydpe
**            				: CommType : Communication Type
**							: Data Pointer: Point to Node Identification Number if required
** Return value             : None
*******************************************************************************/
static uint8_t ISOUDS_CntrDTCSet_ON_Cbk(uint8_t DTCSettingType,const uint8_t *Data, uint16_t DataLen)
{
	uint8_t RespVal = ISOUDS_POSRES;

	

	/* Manual code start */

	/* Perform Operation and strore the Response code into RespVal */
	RespVal = HAL_CntrDTCSet_ON_Cbk(DTCSettingType, Data, DataLen);
	/* Manual Code End */

	return RespVal;
}
/*******************************************************************************
** Function                 : ISOUDS_CntrDTCSet_OFF_Cbk
**
** Description              : Control DTC settings ON
**
** Parameters 				: DTCSettingType : DTC setting Type
**            				: CommType : Communication Type
**							: Data Pointer: Point to Node Identification Number if required
** Return value             : None
*******************************************************************************/
static uint8_t ISOUDS_CntrDTCSet_OFF_Cbk(uint8_t DTCSettingType,const uint8_t *Data, uint16_t DataLen)
{
	uint8_t RespVal = ISOUDS_POSRES;

	

	/* Manual code start */

	/* Perform Operation and strore the Response code into RespVal */
	RespVal = HAL_CntrDTCSet_OFF_Cbk(DTCSettingType, Data, DataLen);

	/* Manual Code End */

	return RespVal;
}

#endif

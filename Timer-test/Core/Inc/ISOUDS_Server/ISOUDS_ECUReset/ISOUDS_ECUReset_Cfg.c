/***************************************************************************************************
**
** -------------------------------------------------------------------------------------------------
** File Name    : ISOUDS_ECUReset.c
**
** Description  : ECU Reset
**
** -------------------------------------------------------------------------------------------------
**
***************************************************************************************************/

/**************************************** Inclusion files *****************************************/
#include "ISOUDS_Server.h"
#include "ISOUDS_Server_Cfg.h"
#include "ISOUDS_ECUReset_Cfg.h"
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
static uint8_t ISOUDS_HardReset_Cbk(void);
static uint8_t ISOUDS_SoftReset_Cbk(void);
static uint8_t ISOUDS_KeyOffOnReset_Cbk(void);






const ISOUDS_EcuRstCfg_t ISOUDS_ECURSTCfgTbl[ISOUDS_ECURSTMaxSubFun] =	{
																			{
																				ISOUDS_HARDRESET,
																				(PROGRAMMING_SESS | EXTENDED_SESS),
																				ISOUDS_FALSE,
																				1,
																				{UnlockedL2},
																				&ISOUDS_HardReset_Cbk
																			},
																			{
																				ISUODS_KEYOFFON,
																				(PROGRAMMING_SESS | EXTENDED_SESS),
																				ISOUDS_FALSE,
																				1,
																				{UnlockedL2},
																				&ISOUDS_KeyOffOnReset_Cbk
																			},
																			{
																				ISOUDS_SOFTRESET,
																				(PROGRAMMING_SESS | EXTENDED_SESS),
																				ISOUDS_FALSE,
																				1,
																				{UnlockedL1},
																				&ISOUDS_SoftReset_Cbk
																			}
																		};

/******************************** Function definitions ********************************************/

/**************************** Internal Function definitions ***************************************/
/***************************************************************************************************
** Function                 : ISOUDS_Get_ECURSTMaxSubFun

** Description              : Return the Number of Subfunctions configured for ECU Reset

** Paramete           		: None

** Return value             : retVal : Number of subfunctions Supported

** Remarks                  : None
***************************************************************************************************/
uint8_t ISOUDS_Get_ECURSTMaxSubFun(void)
{
	return ISOUDS_ECURSTMaxSubFun;
}

/***************************************************************************************************
** Function                 : ISOUDS_HardReset_Cbk

** Description              : Handels the HardReset Request

** Paramete           		: None

** Return value             : retVal : Response code

** Remarks                  : None
***************************************************************************************************/
static uint8_t ISOUDS_HardReset_Cbk(void)
{
	uint8_t RespVal = ISOUDS_POSRES;
	uint8_t CondMeet;

	/* API need to be defined to check the conditions */
	CondMeet = HAL_HardReset_Cond();

	if (ISOUDS_TRUE == CondMeet)
	{
		/* Switch session as per request */
		ISOUDS_ReqECUReset();

		/* reset the required parameters during programming session transition */

		/* Reset request Accepted */
		RespVal = HAL_HardReset_Proc();
	}
	else
	{
		RespVal = ISOUDS_CNC;
	}

	return RespVal;
}


/***************************************************************************************************
** Function                 : ISOUDS_KeyOffOnReset_Cbk

** Description              : Handels the KeyOffOnReset Request

** Paramete           		: None

** Return value             : retVal : Response code

** Remarks                  : None
***************************************************************************************************/
static uint8_t ISOUDS_KeyOffOnReset_Cbk(void)
{
	uint8_t RespVal = ISOUDS_POSRES;
	uint8_t CondMeet;

	/* API need to be defined to check the conditions */
	CondMeet = HAL_KeyOffOnReset_Cond();

	if (ISOUDS_TRUE == CondMeet)
	{
		/* reset the required parameters during programming session transition */

		/* Reset request Accepted */
		RespVal = HAL_KeyOffOnReset_Proc();
	}
	else
	{
		RespVal = ISOUDS_CNC;
	}

	return RespVal;
}


/***************************************************************************************************
** Function                 : ISOUDS_SoftReset_Cbk

** Description              : Handels the SoftReset Request

** Paramete           		: None

** Return value             : retVal : Response code

** Remarks                  : None
***************************************************************************************************/
static uint8_t ISOUDS_SoftReset_Cbk(void)
{
	uint8_t RespVal = ISOUDS_POSRES;
	uint8_t CondMeet;

	/* API need to be defined to check the conditions */
	CondMeet = HAL_SoftReset_Cond();

	if (ISOUDS_TRUE == CondMeet)
	{
		/* Switch session as per request */
		ISOUDS_ReqECUReset();

		/* reset the required parameters during programming session transition */

		/* Reset request Accepted */
		RespVal = HAL_SoftReset_Proc();
	}
	else
	{
		RespVal = ISOUDS_CNC;
	}

	return RespVal;
}


#endif

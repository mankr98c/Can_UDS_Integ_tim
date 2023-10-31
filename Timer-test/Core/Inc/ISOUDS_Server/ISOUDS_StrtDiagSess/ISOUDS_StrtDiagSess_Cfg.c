/***************************************************************************************************
**
** -------------------------------------------------------------------------------------------------
** File Name    : ISOUDS_StrtDiagSess.c
**
** Description  : Start Diagnostic session
**
** -------------------------------------------------------------------------------------------------
**
***************************************************************************************************/

/**************************************** Inclusion files *****************************************/
#include "ISOUDS_Server_Cfg.h"
#include "ISOUDS_StrtDiagSess.h"
#include "ISOUDS_StrtDiagSess_Cfg.h"
#include "ISOUDS_StrtDiagSess_HAL.h"

#if (ISOUDS_APP_CONFIG == ISOUDS_SERVER)
/********************** Declaration of local symbol and constants *********************************/

/********************************* Declaration of local macros ************************************/

/********************************* Declaration of local types *************************************/

/******************************* Declaration of local variables ***********************************/

/******************************* Declaration of local constants ***********************************/
static uint8_t ISOUDS_StrDiagSessDefault_Cbk( ISOUDS_ConfType *ISOUDSConfPtr);
static uint8_t ISOUDS_StrDiagSessExtended_Cbk( ISOUDS_ConfType *ISOUDSConfPtr);
static uint8_t ISOUDS_StrDiagSessProgramming_Cbk( ISOUDS_ConfType *ISOUDSConfPtr);
static uint8_t ISOUDS_StrDiagSessSafety_Cbk (ISOUDS_ConfType *ISOUDSConfPtr);

const ISOUDS_SessSubfunMap ISOUDS_SessSubfunMap_Tbl[ISOUDS_StrtDiagSessCfgMaxSubFun] = {
																							{(uint8_t)ISOUDS_DEFAULT, 		1U},
																							{(uint8_t)ISOUDS_PROGRAMMING, 	2U},
																							{(uint8_t)ISOUDS_EXTENDED, 		3U},
																							{(uint8_t)ISOUDS_SAFETY, 		4U},
																						};

/****************************** Declaration of exported variables *********************************/
ISOUDS_StrtDiagSessCfg_t ISOUDS_StrtDiagSessCfg_Tbl[ISOUDS_StrtDiagSessCfgMaxSubFun] =	{
																							{
																								(uint8_t)ISOUDS_DEFAULT,
																								(DEFAULT_SESS|EXTENDED_SESS ),
																								ISOUDS_FALSE,
																								1,
																								{UnlockedL1},
																								&ISOUDS_StrDiagSessDefault_Cbk
																							},
																							{
																								(uint8_t)ISOUDS_PROGRAMMING,
																								(DEFAULT_SESS|PROGRAMMING_SESS),
																								ISOUDS_FALSE,
																								1,
																								{UnlockedL1},
																								&ISOUDS_StrDiagSessProgramming_Cbk
																							},
																							{
																								(uint8_t)ISOUDS_EXTENDED,
																								(DEFAULT_SESS |EXTENDED_SESS|PROGRAMMING_SESS |SAFETY_SESS ),
																								ISOUDS_FALSE,
																								1,
																								{UnlockedL1},
																								&ISOUDS_StrDiagSessExtended_Cbk
																							},
																							{
																								(uint8_t)ISOUDS_SAFETY,
																								(DEFAULT_SESS|SAFETY_SESS),
																								ISOUDS_FALSE,
																								1,
																								{UnlockedL1},
																								&ISOUDS_StrDiagSessSafety_Cbk
																							}
																							
																						};
/****************************** Declaration of exported constants *********************************/

/***************************************************************************************************
**                                      FUNCTIONS                                                 **
***************************************************************************************************/

/******************************** Function definitions ********************************************/
/***************************************************************************************************
** Function                 : ISOUDS_Get_StrtDiagSessCfgMaxSub

** Description              : Return the Number of Subfunction configured for the Start Diagnostic Session

** Paramete           		: None

** Return value             : retVal : Number of Subfunctions

** Remarks                  : None
***************************************************************************************************/
uint8_t ISOUDS_Get_StrtDiagSessCfgMaxSub(void)
{
	return ISOUDS_StrtDiagSessCfgMaxSubFun;
}
/**************************** Internal functions declarations *************************************/
/***************************************************************************************************
** Function                 : ISOUDS_StrDiagSessDefault_Cbk

** Description              : Check for conditions and switch to default session

** Parameter                : None

** Return value             :  RespVal -> Returns the response for the service request

** Remarks                  : None
***************************************************************************************************/
static uint8_t ISOUDS_StrDiagSessDefault_Cbk (ISOUDS_ConfType *ISOUDSConfPtr)
{
	uint8_t RespVal = ISOUDS_POSRES;

	if (NULL_PTR != ISOUDSConfPtr)
	{
		if (ISOUDSConfPtr->srvSt == (uint8_t)ISOUDS_RXMSG)
		{
			/* Manual code start */

			/* Initial Routine request handler */
			/* Perform Operation and strore the Response code into RespVal */
			RespVal = HAL_StrDiagSessDefault_Cbk();

			/* Manual Code End */
		}
		else
		{

			/* Manual code start */

			/* Pending response handler */

			/* Perform Operation and strore the Response code into RespVal */
			RespVal = HAL_StrDiagSessDefault_Cbk();

			/* Manual Code End */
		}
	}
	else
	{
		/* do nothing */
	}
	
	return RespVal;
}

/***************************************************************************************************
** Function                 : ISOUDS_StrDiagSessExtended_Cbk

** Description              : Check for conditions and switch to extended session

** Parameter                : None

** Return value             :  RespVal -> Returns the response for the service request

** Remarks                  : None
***************************************************************************************************/
static uint8_t ISOUDS_StrDiagSessExtended_Cbk (ISOUDS_ConfType *ISOUDSConfPtr)
{
	uint8_t RespVal = ISOUDS_POSRES;

	if (NULL_PTR != ISOUDSConfPtr)
	{
		if (ISOUDSConfPtr->srvSt == (uint8_t)ISOUDS_RXMSG)
		{
			/* Manual code start */
			/* Initial Routine request handler */
			/* Perform Operation and strore the Response code into RespVal */
			RespVal = HAL_StrDiagSessExtended_Cbk();

			/* Manual Code End */
		}
		else
		{

			/* Manual code start */

			/* Pending response handler */

			/* Perform Operation and strore the Response code into RespVal */
			RespVal = HAL_StrDiagSessExtended_Cbk();

			/* Manual Code End */
		}
	}
	else
	{
		/* do nothing */
	}

	return RespVal;
}

/***************************************************************************************************
** Function                 : ISOUDS_StrDiagSessProgramming_Cbk

** Description              : Check for conditions and switch to Programming session

** Parameter                : None

** Return value             : RespVal -> Returns the response for the service request

** Remarks                  : None
***************************************************************************************************/
static uint8_t ISOUDS_StrDiagSessProgramming_Cbk (ISOUDS_ConfType *ISOUDSConfPtr)
{
	uint8_t RespVal = ISOUDS_POSRES;

	if (NULL_PTR != ISOUDSConfPtr)
	{
		if (ISOUDSConfPtr->srvSt == (uint8_t)ISOUDS_RXMSG)
		{
			/* Manual code start */

			/* Initial Routine request handler */
			/* Perform Operation and strore the Response code into RespVal */
			RespVal = HAL_StrDiagSessProgramming_Cbk();

			/* Manual Code End */
		}
		else
		{

			/* Manual code start */

			/* Pending response handler */

			/* Perform Operation and strore the Response code into RespVal */
			RespVal = HAL_StrDiagSessProgramming_Cbk();

			/* Manual Code End */
		}
	}
	else
	{
		/* do nothing */
	}

	return RespVal;
}


/***************************************************************************************************
** Function                 : ISOUDS_StrDiagSessSafety_Cbk

** Description              : Check for conditions and switch to extended session

** Parameter                : None

** Return value             :  RespVal -> Returns the response for the service request

** Remarks                  : None
***************************************************************************************************/
static uint8_t ISOUDS_StrDiagSessSafety_Cbk (ISOUDS_ConfType *ISOUDSConfPtr)
{
	uint8_t RespVal = ISOUDS_POSRES;

	if (NULL_PTR != ISOUDSConfPtr)
	{
		if (ISOUDSConfPtr->srvSt == (uint8_t)ISOUDS_RXMSG)
		{
			/* Manual code start */
			/* Initial Routine request handler */
			/* Perform Operation and strore the Response code into RespVal */
			RespVal = HAL_StrDiagSessSafety_Cbk();

			/* Manual Code End */
		}
		else
		{

			/* Manual code start */

			/* Pending response handler */

			/* Perform Operation and strore the Response code into RespVal */
			RespVal = HAL_StrDiagSessSafety_Cbk();

			/* Manual Code End */
		}
	}
	else
	{
		/* do nothing */
	}

	return RespVal;
}

#endif

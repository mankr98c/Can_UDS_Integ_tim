/*******************************************************************************
**
** -----------------------------------------------------------------------------
** File Name    : ISOUDS_ClearDiagInfo_Cfg.c
**
** Description  : Clear Diagnostic info Service Configuration
**
** -----------------------------------------------------------------------------
**
*******************************************************************************/

/**************************************** Inclusion files *********************/
#include "ISOUDS_Server_Cfg.h"
#include "ISOUDS_CntrlDTCSetting_Cfg.h"
#include "ISOUDS_ClearDiagInfo_HAL.h"

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

/******************************** Function definitions ************************/

/*******************************************************************************
** Function                 : ISOUDS_CntrlDTCSetngPreCondCheck
**
** Description              : Checks the pre conditions for Clear DTC information
**
** Parameters 				: None
**
**
** Return value             : RetVal : Pre condition validity
*******************************************************************************/
uint8_t ISOUDS_ClearDTCInfoPreCondCheck(void)
{
	uint8_t RetVal = ISOUDS_TRUE;

	/* Add Code to check the Pre-conditions and update RetVal accordingly */
    RetVal = HAL_ClearDTCInfoPreCondCheck();
	return RetVal;
}

/*******************************************************************************
** Function                 : ISOUDS_CLearDTCInfoReq
**
** Description              : Clear DTC Info Request
**
** Parameters 				: DTCNumber : DTC number to be cleared
**
** Return value             : Response Value
*******************************************************************************/
uint8_t ISOUDS_CLearDTCInfoReq(uint32_t DTCNumber, uint8_t MemorySelection)
{
	uint8_t RespVal = ISOUDS_POSRES;

	

	/* Manual code start */

	/* Perform Operation and strore the Response code into RespVal */
	RespVal = HAL_CLearDTCInfoReq(DTCNumber, MemorySelection);

	/* Manual Code End */

	return RespVal;
}

/*******************************************************************************
** Function                 : ISOUDS_CLearDTCInfoReqStat
**
** Description              : Clear DTC Info Request status
**
** Parameters 				: DTCNumber : DTC number to be cleared
**
** Return value             : Response Value
*******************************************************************************/
uint8_t ISOUDS_CLearDTCInfoReqStat(void)
{
	uint8_t RespVal = ISOUDS_POSRES;

	

	/* Manual code start */

	/* Perform Operation and strore the Response code into RespVal */
	RespVal = HAL_CLearDTCInfoReqStat();

	/* Manual Code End */

	return RespVal;
}

/**************************** Internal Function definitions *******************/

#endif

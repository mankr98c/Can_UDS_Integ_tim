/*******************************************************************************
**
** -----------------------------------------------------------------------------
** File Name    : ISOUDS_CommCntrl_HAL.c
**
** Description  : Communication Control Service
**
** -----------------------------------------------------------------------------
**
*******************************************************************************/

/**************************************** Inclusion files *********************/
#include "ISOUDS_Server_Cfg.h"
#include "ISOUDS_CommCntrl.h"
#include "ISOUDS_CommCntrlCfg.h"
#include "ISOUDS_CommCntrl_HAL.h"

/********************** Declaration of local symbol and constants *************/

/********************************* Declaration of local macros ****************/

/********************************* Declaration of local types *****************/

/******************************* Declaration of local variables ***************/

/******************************* Declaration of local constants ***************/

/****************************** Declaration of exported variables *************/

/****************************** Declaration of exported constants *************/

/****************************** Declaration of Internal Functions *************/

/*******************************************************************************
**                                      FUNCTIONS                              *
*******************************************************************************/

/******************************** Function definitions ************************/

/*******************************************************************************
** Function                 : HAL_CommCntlPreCondCheck
**
** Description              : API to check comm control preconditions
**
** Parameters 				: None
**
** Return value             : ISOUDS_TRUE or FALSE
*******************************************************************************/
uint8_t HAL_CommCntlPreCondCheck(void)
{
	uint8_t RetVal;
	/* User specific implementation */
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
** Function                 : HAL_EnblRxTx
**
** Description              : API to to enable rx and tx
**
** Parameters 				: ControlType : Communication Control Type
**            				: CommType : Communication Type
**							: Data Pointer: Point to Node Identification Number if required
**
** Return value             : Postive or negative response coded based on the condition.
**                            Refer ISOUDS_Server.h file
*******************************************************************************/
uint8_t HAL_EnblRxTx(uint8_t ControlType, uint8_t CommType, const uint8_t *Data)
{
	uint8_t RespVal;
    /* User specific code */
	(void)ControlType;
	(void)CommType;
	(void)Data;
	RespVal = ISOUDS_POSRES;
	return RespVal;

}

/*******************************************************************************
** Function                 : HAL_EnblRxDisableTx
**
** Description              : API to to enable rx and Disable tx
**
** Parameters 				: ControlType : Communication Control Type
**            				: CommType : Communication Type
**							: Data Pointer: Point to Node Identification Number if required
**
** Return value             : Postive or negative response coded based on the condition.
**                            Refer ISOUDS_Server.h file
*******************************************************************************/
uint8_t HAL_EnblRxDisableTx(uint8_t ControlType, uint8_t CommType, const uint8_t *Data)
{
	uint8_t RespVal;
    /* User specific code */
	(void)ControlType;
	(void)CommType;
	(void)Data;
	RespVal = ISOUDS_POSRES;
	return RespVal;
}

/*******************************************************************************
** Function                 : HAL_DisablRxTx
**
** Description              : API to to Disable rx and Enable tx
**
** Parameters 				: ControlType : Communication Control Type
**            				: CommType : Communication Type
**							: Data Pointer: Point to Node Identification Number if required
**
** Return value             : Postive or negative response coded based on the condition.
**                            Refer ISOUDS_Server.h file
*******************************************************************************/
uint8_t HAL_DisbleRxEnblTx(uint8_t ControlType, uint8_t CommType, const uint8_t *Data)
{
	uint8_t RespVal;
    /* User specific code */
	(void)ControlType;
	(void)CommType;
	(void)Data;
	RespVal = ISOUDS_POSRES;
	return RespVal;
}



/*******************************************************************************
** Function                 : HAL_DisablRxTx
**
** Description              : API to to Disable rx and tx
**
** Parameters 				: ControlType : Communication Control Type
**            				: CommType : Communication Type
**							: Data Pointer: Point to Node Identification Number if required
**
** Return value             : Postive or negative response coded based on the condition.
**                            Refer ISOUDS_Server.h file
*******************************************************************************/
uint8_t HAL_DisablRxTx(uint8_t ControlType, uint8_t CommType, const uint8_t *Data)
{
	uint8_t RespVal;
    /* User specific code */
	(void)ControlType;
	(void)CommType;
	(void)Data;
	RespVal = ISOUDS_POSRES;
	return RespVal;
}


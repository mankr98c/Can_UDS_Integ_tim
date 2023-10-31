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
#include "ISOUDS_Server.h"
#include "ISOUDS_LinkCntrl.h"
#include "ISOUDS_LinkCntrlCfg.h"
#include "ISOUDS_LinkCntrl_HAL.h"

#if (ISOUDS_APP_CONFIG == ISOUDS_SERVER)
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
** Function                 : ISOUDS_LinkCntlPreCondCheck
**
** Description              : Checks the pre conditions for Link control
**
** Parameters 				: None
**
**
** Return value             : ISOUDS_TRUE or ISOUDS_FALSE
*******************************************************************************/
uint8_t HAL_LinkCntlPreCondCheck(void)
{
	uint8_t RetVal;
	/* User specific implementation */
	RetVal = ISOUDS_TRUE;

	return RetVal;
}

/*******************************************************************************
** Function                 : HAL_LinkCntrl_VMTWFP
**
** Description              : API for verifyModeTransitionWithFixedParameter
**
** Parameters 				: ControlType : Link Control Type
**							: Data Pointer: Point to Node Identification Number if required
** Return value             : Based on the condition return the response
**                            Please refer ISOUDS_Server.h for UDS macros.
*******************************************************************************/
uint8_t HAL_LinkCntrl_VMTWFP(uint8_t ControlType, uint8_t *Data)
{
	uint8_t RespVal;

	(void)ControlType;
	(void)Data;
    /* User specific implementation */
	RespVal = ISOUDS_POSRES;

	return RespVal;
}

/*******************************************************************************
** Function                 : HAL_LinkCntrl_VMTWSP
**
** Description              : API for verifyModeTransitionWithSpecificParameter
**
** Parameters 				: ControlType : Link Control Type
**							: Data Pointer: Point to Node Identification Number if required
** Return value             : Based on the condition return the response
**                            Please refer ISOUDS_Server.h for UDS macros.
*******************************************************************************/
uint8_t HAL_LinkCntrl_VMTWSP(uint8_t ControlType, uint8_t *Data)
{
	uint8_t RespVal;

	(void)ControlType;
	(void)Data;
    /* User specific implementation */
	RespVal = ISOUDS_POSRES;
	return RespVal;
}


/*******************************************************************************
** Function                 : HAL_LinkCntrl_TM
**
** Description              : API for Transition mode
**
** Parameters 				: ControlType : Link Control Type
**							: Data Pointer: Point to Node Identification Number if required
** Return value             : Based on the condition return the response
**                            Please refer ISOUDS_Server.h for UDS macros.
*******************************************************************************/
uint8_t HAL_LinkCntrl_TM(uint8_t ControlType, uint8_t *Data)
{
	uint8_t RespVal;

	(void)ControlType;
	(void)Data;

    /* User specific implementation */
	RespVal = ISOUDS_POSRES;
	return RespVal;
}

#endif

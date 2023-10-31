/*******************************************************************************
**
** -----------------------------------------------------------------------------
** File Name    : ISOUDS_CommCntrl.c
**
** Description  : Communication Control Service
**
** -----------------------------------------------------------------------------
**
*******************************************************************************/

/**************************************** Inclusion files *********************/
#include "ISOUDS_Server.h"
#include "ISOUDS_Server_Cfg.h"
#include "ISOUDS_LinkCntrl.h"
#include "ISOUDS_LinkCntrlCfg.h"
#include "ISOUDS_LinkCntrl_HAL.h"

#if (ISOUDS_APP_CONFIG == ISOUDS_SERVER)
/********************** Declaration of local symbol and constants *************/

/********************************* Declaration of local macros ****************/

/********************************* Declaration of local types *****************/

static uint8_t ISOUDS_LinkCntrl_VMTWFP(uint8_t ControlType, uint8_t *Data);
static uint8_t ISOUDS_LinkCntrl_VMTWSP(uint8_t ControlType, uint8_t *Data);
static uint8_t ISOUDS_LinkCntrl_TM(uint8_t ControlType, uint8_t *Data);
static uint8_t ISOUDS_LinkCntrl_TransModeID;
static uint32_t ISOUDS_LinkCntrl_linkRecord;
static uint8_t ISOUDS_RxLinkCntrltype;
/******************************* Declaration of local variables ***************/

ISOUDS_LinkCntCfg_t ISOUDS_LinkContCfgTbl[ISOUDS_LinkContMaxSubFun] =	{
																		{
																			VMTWFP,
																			EXTENDED_SESS,
																			ISOUDS_TRUE,
																			1,
																			{UnlockedL1},
																			&ISOUDS_LinkCntrl_VMTWFP
																		},
																		{
																			VMTWSP,
																			EXTENDED_SESS,
																			ISOUDS_TRUE,
																			1,
																			{UnlockedL1},
																			&ISOUDS_LinkCntrl_VMTWSP
																		},
																		{
																			TM,
																			EXTENDED_SESS,
																			ISOUDS_TRUE,
																			1,
																			{UnlockedL1},
																			&ISOUDS_LinkCntrl_TM
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
** Function                 : ISOUDS_Get_LinkContMaxSubFun

** Description              : Return the Number of Subfunction configured for Link control

** Paramete           		: None

** Return value             : retVal : Number of Link control Subfunctions Supported

** Remarks                  : None
***************************************************************************************************/
uint8_t ISOUDS_Get_LinkContMaxSubFun(void)
{
	return ISOUDS_LinkContMaxSubFun;
}

/*******************************************************************************
** Function                 : ISOUDS_LinkCntlPreCondCheck
**
** Description              : Checks the pre conditions for Link control
**
** Parameters 				: None
**
**
** Return value             : RetVal : Pre condition validity
*******************************************************************************/
uint8_t ISOUDS_LinkCntlPreCondCheck(void)
{
	uint8_t RetVal = ISOUDS_TRUE;

	

	/* Add Code to check the Pre-conditions and update RetVal accordingly */
	RetVal = HAL_LinkCntlPreCondCheck();

	return RetVal;
}

/**************************** Internal Function definitions *******************/
/*******************************************************************************
** Function                 : ISOUDS_LinkCntrl_VMTWFP
**
** Description              : API for verifyModeTransitionWithFixedParameter
**
** Parameters 				: ControlType : Link Control Type
**							: Data Pointer: Point to Node Identification Number if required
** Return value             : None
*******************************************************************************/
static uint8_t ISOUDS_LinkCntrl_VMTWFP(uint8_t ControlType, uint8_t *Data)
{
	uint8_t RespVal = ISOUDS_POSRES;

	/* Manual code start */

	/* Perform Operation and strore the Response code into RespVal */
	RespVal = HAL_LinkCntrl_VMTWFP(ControlType, Data);

	/* Manual Code End */

	if (ISOUDS_POSRES == RespVal)
	{
		ISOUDS_RxLinkCntrltype = ControlType;
		ISOUDS_LinkCntrl_TransModeID = Data[0];
	}
	else
	{
		/* Do nothing */
	}

	return RespVal;
}
/*******************************************************************************
** Function                 : ISOUDS_LinkCntrl_VMTWSP
**
** Description              : API for verifyModeTransitionWithSpecificParameter
**
** Parameters 				: ControlType : Link Control Type
**							: Data Pointer: Point to Node Identification Number if required
** Return value             : None
*******************************************************************************/
static uint8_t ISOUDS_LinkCntrl_VMTWSP(uint8_t ControlType, uint8_t *Data)
{
	uint8_t RespVal = ISOUDS_POSRES;

	/* Manual code start */

	/* Perform Operation and strore the Response code into RespVal */
	RespVal = HAL_LinkCntrl_VMTWSP(ControlType, Data);

	/* Manual Code End */
	if (ISOUDS_POSRES == RespVal)
	{
		ISOUDS_RxLinkCntrltype = ControlType;

		ISOUDS_LinkCntrl_linkRecord  = (uint32_t)(((uint32_t)Data[0] &
				(uint32_t)0xFFFFFFFFU) << 16);
		ISOUDS_LinkCntrl_linkRecord |= (uint32_t)((uint32_t)(((uint32_t)Data[1]
				& (uint32_t)0xFFFFFFFFU) << 8));
		ISOUDS_LinkCntrl_linkRecord |= (uint32_t)((uint32_t)(((uint32_t)Data[2]
				& (uint32_t)0xFFFFFFFFU)));
	}
	else
	{
		/* Do nothing */
	}
	return RespVal;
}
/*******************************************************************************
** Function                 : ISOUDS_LinkCntrl_VMTWSP
**
** Description              : API for Transition mode
**
** Parameters 				: ControlType : Link Control Type
**							: Data Pointer: Point to Node Identification Number if required
** Return value             : None
*******************************************************************************/
static uint8_t ISOUDS_LinkCntrl_TM(uint8_t ControlType, uint8_t *Data)
{
	uint8_t RespVal = ISOUDS_POSRES;

	

	/* Manual code start */

	/* Perform Operation and strore the Response code into RespVal */
	RespVal = HAL_LinkCntrl_TM(ControlType, Data);
	/* Manual Code End */

	if (ISOUDS_POSRES == RespVal)
	{
		if (VMTWFP == (ISOUDS_LinkContType_e)ISOUDS_RxLinkCntrltype)
		{
			/*Recomend to used the ISOUDS_LinkCntrl_TransModeID*/
		}
		else if (VMTWSP == (ISOUDS_LinkContType_e)ISOUDS_RxLinkCntrltype)
		{
			/*Recomend to used the ISOUDS_LinkCntrl_linkRecord*/
		}
		else
		{
			/* Do nothing */
		}
	}
	else
	{
		/* Do nothing */
	}

	return RespVal;
}

#endif

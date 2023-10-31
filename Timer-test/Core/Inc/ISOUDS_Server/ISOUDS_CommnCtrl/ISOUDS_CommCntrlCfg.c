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
#include "ISOUDS_Server_Cfg.h"
#include "ISOUDS_CommCntrl.h"
#include "ISOUDS_CommCntrlCfg.h"
#include "ISOUDS_CommCntrl_HAL.h"

/********************** Declaration of local symbol and constants *************/

/********************************* Declaration of local macros ****************/

/********************************* Declaration of local types *****************/

static uint8_t ISOUDS_EnblRxTx(uint8_t ControlType, uint8_t CommType, const uint8_t *Data);
static uint8_t ISOUDS_EnblRxDisableTx(uint8_t ControlType, uint8_t CommType, const uint8_t *Data);
static uint8_t ISOUDS_DisbleRxEnblTx(uint8_t ControlType, uint8_t CommType, const uint8_t *Data);
static uint8_t ISOUDS_DisablRxTx(uint8_t ControlType, uint8_t CommType, const uint8_t *Data);


/******************************* Declaration of local variables ***************/

ISOUDS_ComCntCfg_t ISOUDS_ComContCfgTbl[ISOUDS_ComContMaxSubFun] =	{
																		{
																			EnblRxTx,
																			EXTENDED_SESS,
																			ISOUDS_FALSE,
																			2,
																			{UnlockedL1},
																			&ISOUDS_EnblRxTx
																		},
																		{
																			EnblRxDisablTx,
																			EXTENDED_SESS,
																			ISOUDS_FALSE,
																			2,
																			{UnlockedL1},
																			&ISOUDS_EnblRxDisableTx
																		},
																		{
																			DisablRxEnblTx,
																			EXTENDED_SESS,
																			ISOUDS_FALSE,
																			2,
																			{UnlockedL1},
																			&ISOUDS_DisbleRxEnblTx
																		},
																		{
																			DisablRxTx,
																			EXTENDED_SESS,
																			ISOUDS_FALSE,
																			2,
																			{UnlockedL1},
																			&ISOUDS_DisablRxTx
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
** Function                 : ISOUDS_Get_ComContMaxSubFun

** Description              : Return the Number of Subfunctions configured for Communication control

** Paramete           		: None

** Return value             : retVal : Number of subfunctions

** Remarks                  : None
***************************************************************************************************/
uint8_t ISOUDS_Get_ComContMaxSubFun(void)
{
	return ISOUDS_ComContMaxSubFun;
}

/*******************************************************************************
** Function                 : ISOUDS_CommTypeSupp
**
** Description              : Checks Communication Validity
**
** Parameters 				: CommType  : Communication Type received
**
**
** Return value             : RetVal : Communication type validity
*******************************************************************************/
uint8_t ISOUDS_CommTypeSupp(uint8_t CommType)
{
	uint8_t RetVal = ISOUDS_TRUE;

	/* Check normal or Network management communication type */
	if (ISOUDS_ZERO == (CommType & ISOUDS_NWMCMANCM))
		/* Add more conditions according to requirement */
	{
		/* Neither Normal nor Network Management request */
		RetVal = ISOUDS_FALSE;
	}
	else
	{
		/* Do nothing */
	}

	return RetVal;
}

/*******************************************************************************
** Function                 : ISOUDS_CommCntlPreCondCheck
**
** Description              : Checks the pre conditions for Communication control
**
** Parameters 				: None
**
**
** Return value             : RetVal : Pre condition validity
*******************************************************************************/
uint8_t ISOUDS_CommCntlPreCondCheck(void)
{
	uint8_t RetVal = ISOUDS_TRUE;

	

	/* Add Code to check the Pre-conditions and update RetVal accordingly */
	RetVal = HAL_CommCntlPreCondCheck();

	return RetVal;
}

/**************************** Internal Function definitions *******************/
/*******************************************************************************
** Function                 : ISOUDS_EnblRxTx
**
** Description              : API to Enable the Rx & tX
**
** Parameters 				: ControlType : Communication Control Type
**            				: CommType : Communication Type
**							: Data Pointer: Point to Node Identification Number if required
** Return value             : None
*******************************************************************************/
static uint8_t ISOUDS_EnblRxTx(uint8_t ControlType, uint8_t CommType, const uint8_t *Data)
{
	uint8_t RespVal = ISOUDS_POSRES;

	

	/* Manual code start */

	/* Perform Operation and strore the Response code into RespVal */
	RespVal = HAL_EnblRxTx(ControlType,CommType, Data);

	/* Manual Code End */

	return RespVal;
}

/*******************************************************************************
** Function                 : ISOUDS_EnblRxDisableTx
**
** Description              : API to Enable the Rx & Disable tX
**
** Parameters 				: ControlType : Communication Control Type
**            				: CommType : Communication Type
**							: Data Pointer: Point to Node Identification Number if required
** Return value             : None
*******************************************************************************/
static uint8_t ISOUDS_EnblRxDisableTx(uint8_t ControlType, uint8_t CommType, const uint8_t *Data)
{
	uint8_t RespVal = ISOUDS_POSRES;



	/* Manual code start */

	/* Perform Operation and strore the Response code into RespVal */
	RespVal = HAL_EnblRxDisableTx(ControlType,CommType, Data);

	/* Manual Code End */

	return RespVal;
}

/*******************************************************************************
** Function                 : ISOUDS_DisbleRxEnblTx
**
** Description              : API to Disable Rx and Enable  tX
**
** Parameters 				: ControlType : Communication Control Type
**            				: CommType : Communication Type
**							: Data Pointer: Point to Node Identification Number if required
** Return value             : None
*******************************************************************************/
static uint8_t ISOUDS_DisbleRxEnblTx(uint8_t ControlType, uint8_t CommType, const uint8_t *Data)
{
	uint8_t RespVal = ISOUDS_POSRES;



	/* Manual code start */

	/* Perform Operation and strore the Response code into RespVal */
	RespVal = HAL_DisbleRxEnblTx(ControlType,CommType, Data);

	/* Manual Code End */

	return RespVal;
}

/*******************************************************************************
** Function                 : ISOUDS_DisablRxTx
**
** Description              : API to Enable the Rx
**
** Parameters 				: ControlType : Communication Control Type
**            				: CommType : Communication Type
**							: Data Pointer: Point to Node Identification Number if required
** Return value             : None
*******************************************************************************/
static uint8_t ISOUDS_DisablRxTx(uint8_t ControlType, uint8_t CommType, const uint8_t *Data)
{
	uint8_t RespVal = ISOUDS_POSRES;

	

	/* Manual code start */

	/* Perform Operation and strore the Response code into RespVal */
    RespVal = HAL_DisablRxTx(ControlType, CommType, Data);

	/* Manual Code End */

	return RespVal;
}

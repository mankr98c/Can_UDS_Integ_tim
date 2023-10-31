/*******************************************************************************
**
** -----------------------------------------------------------------------------
** File Name    : ISOUDS_ATParameterCfg.c
**
** Description  : Access timing parameters Configuration
**
** -----------------------------------------------------------------------------
**
*******************************************************************************/

/**************************************** Inclusion files *********************/
#include "ISOUDS_Server_Cfg.h"
#include "ISOUDS_ATParameter.h"
#include "ISOUDS_ATParameter_Cfg.h"
#include "ISOUDS_ATParameter_HAL.h"

#if (ISOUDS_APP_CONFIG == ISOUDS_SERVER)
/********************** Declaration of local symbol and constants *************/

/********************************* Declaration of local macros ****************/

/********************************* Declaration of local types *****************/

static uint8_t ISOUDS_readExtendedTimingParameterSet_Cbk(uint8_t timingParameterAccessType, uint8_t *Data, uint16_t *RespByes);
static uint8_t ISOUDS_setTimingParametersToDefaultValues_cbk(uint8_t timingParameterAccessType, uint8_t *Data, uint16_t *RespByes);
static uint8_t ISOUDS_readCurrentlyActiveTimingParameters_Cbk(uint8_t timingParameterAccessType, uint8_t *Data, uint16_t *RespByes);
static uint8_t ISOUDS_setTimingParametersToGivenValues_Cbk(uint8_t timingParameterAccessType, uint8_t *Data, uint16_t *RespByes);


/******************************* Declaration of local variables ***************/

ISOUDS_AccessTimParSubCfg_t ISOUDS_AccessTimParSubCfg[ISOUDS_AccTimPartMaxSubFun] =	{
																							{
																								readExtendedTimingParameterSet,
																								EXTENDED_SESS,
																								ISOUDS_TRUE,
																								1,
																								{UnlockedL1},
																								&ISOUDS_readExtendedTimingParameterSet_Cbk
																							},
																							{
																								setTimingParametersToDefaultValues,
																								EXTENDED_SESS,
																								ISOUDS_TRUE,
																								1,
																								{UnlockedL1},
																								&ISOUDS_setTimingParametersToDefaultValues_cbk
																							},
																							{
																								readCurrentlyActiveTimingParameters,
																								EXTENDED_SESS,
																								ISOUDS_TRUE,
																								1,
																								{UnlockedL1},
																								&ISOUDS_readCurrentlyActiveTimingParameters_Cbk
																							},
																							{
																								setTimingParametersToGivenValues,
																								EXTENDED_SESS,
																								ISOUDS_TRUE,
																								1,
																								{UnlockedL1},
																								&ISOUDS_setTimingParametersToGivenValues_Cbk
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
** Function                 : ISOUDS_Get_AccTimeParMaxSubFun

** Description              : Return the Number of Subfunctions configured for the AT Parameters

** Paramete           		: None

** Return value             : retVal : Number of subfunctions

** Remarks                  : None
***************************************************************************************************/
uint8_t ISOUDS_Get_AccTimeParMaxSubFun(void)
{
	return ISOUDS_AccTimPartMaxSubFun;
}

/*******************************************************************************
** Function                 : ISOUDS_AccessTimParamPreCondCheck
**
** Description              : Checks the pre conditions for Access Timing Params
**
** Parameters 				: None
**
**
** Return value             : RetVal : Pre condition validity
*******************************************************************************/
uint8_t ISOUDS_AccessTimParamPreCondCheck(void)
{
	uint8_t RetVal;

	/* Add Code to check the Pre-conditions and update RetVal accordingly */
	RetVal = HAL_AccessTimParamPreCondCheck();

	return RetVal;
}

/**************************** Internal Function definitions *******************/
/*******************************************************************************
** Function                 : ISOUDS_readExtendedTimingParameterSet_Cbk
**
** Description              : API to readExtendedTimingParameterSet
**
** Parameters 				: timingParameterAccessType : Communication Control Type
**							: Data Pointer: Point to Node Identification Number if required
**							: RespByes : Response byte too be sent
** Return value             : None
*******************************************************************************/
static uint8_t ISOUDS_readExtendedTimingParameterSet_Cbk(uint8_t timingParameterAccessType, uint8_t *Data, uint16_t *RespByes)
{
	uint8_t RespVal = ISOUDS_POSRES;
	uint8_t S2min = MSEC_4;
	(void)timingParameterAccessType;
	/* Manual code start */
	Data[0] = (uint8_t)ISOUDS_NRC78P2MINLIM;
	Data[1] = (uint8_t)(ISOUDS_NRC78P2MINLIM >> 8);
	Data[2] = (uint8_t)ISOUDS_NRC78P2MAXLIM;
	Data[3] = (uint8_t)(ISOUDS_NRC78P2MAXLIM >> 8);
	Data[4] = (uint8_t)S2min;

	*RespByes = 4;
	/* Perform Operation and strore the Response code into RespVal */
    RespVal = HAL_readExtendedTimingParameterSet_Cbk(&Data[5], RespByes);
	/* Manual Code End */

	return RespVal;
}
/*******************************************************************************
** Function                 : ISOUDS_setTimingParametersToDefaultValues_cbk
**
** Description              : API to setTimingParametersToDefaultValues
**
** Parameters 				: ControlType : Communication Control Type
**            				: CommType : Communication Type
**							: Data Pointer: Point to Node Identification Number if required
** Return value             : None
*******************************************************************************/
static uint8_t ISOUDS_setTimingParametersToDefaultValues_cbk(uint8_t timingParameterAccessType, uint8_t *Data, uint16_t *RespByes)
{
	uint8_t RespVal= ISOUDS_POSRES;
	uint32_t S2min = MSEC_4;
	uint32_t P2min = ISOUDS_NRC78P2MINLIM;
	uint32_t P2max = ISOUDS_NRC78P2MAXLIM;
	(void)timingParameterAccessType;
	/* Manual code start */
	if(((P2min > ISOUDS_P2MINRANGE_MIN)&&(P2max <= ISOUDS_P2MINRANGE_MAX)) &&
	  ((S2min > ISOUDS_S2MINRANGE_MIN)&&(S2min <= ISOUDS_S2MINRANGE_MAX)))
	{
		ISOUDS_iTmrP2Min = (uint32_t)P2min;
		ISOUDS_iTmrP2Max = (uint32_t)P2max;
		ISOUDS_iTmrSTmin = (uint32_t)S2min;
		RespVal = HAL_setTimingParametersToDefaultValues_cbk(Data, RespByes);
	}
	else
	{
		RespVal = ISOUDS_ROOR;
	}

	/* Manual Code End */

	return RespVal;
}
/*******************************************************************************
** Function                 : ISOUDS_readCurrentlyActiveTimingParameters_Cbk
**
** Description              : API to readCurrentlyActiveTimingParameters
**
** Parameters 				: ControlType : Communication Control Type
**            				: CommType : Communication Type
**							: Data Pointer: Point to Node Identification Number if required
** Return value             : None
*******************************************************************************/
static uint8_t ISOUDS_readCurrentlyActiveTimingParameters_Cbk(uint8_t timingParameterAccessType, uint8_t *Data, uint16_t *RespByes)
{
	uint8_t RespVal= ISOUDS_POSRES;
	(void)timingParameterAccessType;
	/* Manual code start */
	Data[0] = (uint8_t)ISOUDS_iTmrP2Min;
	Data[1] = (uint8_t)(ISOUDS_iTmrP2Min >> 8);
	Data[2] = (uint8_t)(ISOUDS_iTmrP2Min >> 16);
	Data[3] = (uint8_t)(ISOUDS_iTmrP2Min >> 24);
	Data[4] = (uint8_t)ISOUDS_iTmrP2Max;
	Data[5] = (uint8_t)(ISOUDS_iTmrP2Max >> 8);
	Data[6] = (uint8_t)(ISOUDS_iTmrP2Max >> 16);
	Data[7] = (uint8_t)(ISOUDS_iTmrP2Max >> 24);
	Data[8] = (uint8_t)ISOUDS_iTmrSTmin;

	*RespByes = 9;
	/* Perform Operation and strore the Response code into RespVal */
	RespVal = HAL_readCurrentlyActiveTimingParameters_Cbk(&Data[9], RespByes);

	/* Manual Code End */

	return RespVal;}
/*******************************************************************************
** Function                 : ISOUDS_setTimingParametersToGivenValues_Cbk
**
** Description              : API to setTimingParametersToGivenValues
**
** Parameters 				: ControlType : Communication Control Type
**            				: CommType : Communication Type
**							: Data Pointer: Point to Node Identification Number if required
** Return value             : None
*******************************************************************************/
static uint8_t ISOUDS_setTimingParametersToGivenValues_Cbk(uint8_t timingParameterAccessType, uint8_t *Data, uint16_t *RespByes)
{
	uint8_t RespVal = ISOUDS_POSRES;
	uint32_t S2min;
	uint32_t P2min;
	uint32_t P2max;

	(void)timingParameterAccessType;

	/* Manual code start */
	P2min =
		(uint32_t)(((uint32_t)Data[0] << 8) | (uint32_t)Data[1]);
	P2max =
		(uint32_t)(((uint32_t)Data[2] << 8) | (uint32_t)Data[3]);
	S2min = (uint32_t)Data[4];

	if(((P2min > ISOUDS_P2MINRANGE_MIN)&&(P2max <= ISOUDS_P2MINRANGE_MAX)) &&
	  ((S2min > ISOUDS_S2MINRANGE_MIN)&&(S2min <= ISOUDS_S2MINRANGE_MAX)))
	{
		ISOUDS_iTmrP2Min = (uint32_t)P2min;
		ISOUDS_iTmrP2Max = (uint32_t)P2max;
		ISOUDS_iTmrSTmin = (uint32_t)S2min;
		RespVal = HAL_setTimingParametersToGivenValues_Cbk(&Data[5], RespByes);
	}
	else
	{
		RespVal = ISOUDS_ROOR;
	}

	/* Manual Code End */

	return RespVal;
}

#endif


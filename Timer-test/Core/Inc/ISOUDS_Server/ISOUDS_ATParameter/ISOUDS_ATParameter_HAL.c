/***************************************************************************************************
** Copyright (c) 2018 EMBITEL
**
** This software is the property of EMBITEL .
** It can not be used or duplicated without EMBITEL authorization .
**
** -------------------------------------------------------------------------------------------------
** File Name   : ISOUDS_ATParameter_HAL.c
** Module Name : UDS
** -------------------------------------------------------------------------------------------------
**
** Description : Access Timing Parameter Service
**
** -------------------------------------------------------------------------------------------------
**
** Documentation reference :
**
****************************************************************************************************
** R E V I S I O N H I S T O R Y
****************************************************************************************************
** V01.00
** - Baseline for UDS module
**
***************************************************************************************************/

/**************************************** Inclusion files *****************************************/
#include "ISOUDS_Server_Cfg.h"
#include "ISOUDS_ATParameter.h"
#include "ISOUDS_ATParameter_Cfg.h"
#include "ISOUDS_ATParameter_HAL.h"

#if (ISOUDS_APP_CONFIG == ISOUDS_SERVER)
/********************** Declaration of local symbol and constants *********************************/


/********************************* Declaration of local macros ************************************/

/********************************* Declaration of local types *************************************/

/******************************* Declaration of local variables ***********************************/

/******************************* Declaration of local constants ***********************************/

/****************************** Declaration of exported variables *********************************/

/****************************** Declaration of exported constants *********************************/

/***************************************************************************************************
**                                      FUNCTIONS                             					   *
***************************************************************************************************/

/**************************** Internal functions declarations *************************************/

/******************************** Function definitions ********************************************/

/***************************************************************************************************
** Function                 : HAL_AccessTimParamPreCondCheck

** Description              : Check preconditions the Access Timing Parameter.

** Parameter                : None

** Return value             : ISOUDS_TRUE or ISOUDS_FALSE
***************************************************************************************************/
uint8_t HAL_AccessTimParamPreCondCheck(void)
{
	uint8_t RetVal;
	/*Verify the preconditions and return ISOUDS_TRUE of ISOUDS_FALSE*/
	RetVal = ISOUDS_TRUE;
	return RetVal;

}

/***************************************************************************************************
** Function                 : HAL_readExtendedTimingParameterSet_Cbk

** Description              : API to read extended timing parameter.

** Parameters 				: Data Pointer: Point to Node Identification Number if required
**							: RespByes : Response byte too be sent

** Return value             : ISOUDS response code. refer ISOUDS_Server.h
***************************************************************************************************/
uint8_t HAL_readExtendedTimingParameterSet_Cbk(uint8_t *Data,uint16_t *RespByes)
{

	uint8_t RespVal;

	RespVal = ISOUDS_POSRES;

	(void)Data;
	(void)RespByes;

	#if 0
	/* User code */
	/* Default value*/
	Data[0] = 0x00;
    /* By default one extra byte added to data pointer, so in the below variable it is
    Incremented by 1 */
	*RespByes += 1;
    #endif
	return RespVal;
}
/***************************************************************************************************
** Function                 : HAL_setTimingParametersToDefaultValues_cbk

** Description              : API to set timing parameters to default values.

** Parameters 				: Data Pointer: Point to Node Identification Number if required
**							: RespByes : Response byte too be sent

** Return value             : ISOUDS response code. refer ISOUDS_Server.h
***************************************************************************************************/
uint8_t HAL_setTimingParametersToDefaultValues_cbk(uint8_t *Data,uint16_t *RespByes)
{
    uint8_t RespVal;
	RespVal = ISOUDS_POSRES;

	(void)Data;
	(void)RespByes;

    #if 0
	/* User code */
	Data[0] = 0x00; /* Default value*/
    /* By default one extra byte added to data pointer, so in the below variable it is
    Incremented by 1 */
	*RespByes += 1;
    #endif
	return RespVal;
}

/***************************************************************************************************
** Function                 : HAL_setTimingParametersToDefaultValues_cbk

** Description              : API to read currently active timing parameters.

** Parameters 				: Data Pointer: Point to Node Identification Number if required
**							: RespByes : Response byte too be sent

** Return value             : ISOUDS response code. refer ISOUDS_Server.h
***************************************************************************************************/
uint8_t HAL_readCurrentlyActiveTimingParameters_Cbk(uint8_t *Data,uint16_t *RespByes)
{
    uint8_t RespVal;
	RespVal = ISOUDS_POSRES;

	(void)Data;
	(void)RespByes;

    #if 0
	/* User code */
	Data[0] = 0x00; /* Default value*/
    /* By default one extra byte added to data pointer, so in the below variable it is
    Incremented by 1 */
	*RespByes += 1;
    #endif
	return RespVal;
}
/***************************************************************************************************
** Function                 : HAL_setTimingParametersToGivenValues_Cbk

** Description              : API to set timing parameters to given values.

** Parameters 				: Data Pointer: Point to Node Identification Number if required
**							: RespByes : Response byte too be sent

** Return value             : ISOUDS response code. refer ISOUDS_Server.h
***************************************************************************************************/
uint8_t HAL_setTimingParametersToGivenValues_Cbk(uint8_t *Data,uint16_t *RespByes)
{
    uint8_t RespVal;
	RespVal = ISOUDS_POSRES;

	(void)Data;
	(void)RespByes;

    #if 0
	/* User code */
	Data[0] = 0x00; /* Default value*/
    /* By default one extra byte added to data pointer, so in the below variable it is
    Incremented by 1 */
	*RespByes += 1;
    #endif
	return RespVal;
}

#endif


/*******************************************************************************
** Copyright (c) 2018 Embitel
**
** This software is the property of Embitel .
** It can not be used or duplicated without Embitel authorization .
**
** -----------------------------------------------------------------------------
** File Name   : ISOUDS_IOCtrlByID_HAL.c
** Module Name : UDS
** -----------------------------------------------------------------------------
**
** Description : Input Output Control By Identifier Service
**
** -----------------------------------------------------------------------------
**
** Documentation reference :
**
********************************************************************************
** R E V I S I O N H I S T O R Y
********************************************************************************
** V01.00
** - Baseline for UDS module
**
*******************************************************************************/

/**************************************** Inclusion files *********************/
#include "ISOUDS_Server.h"
#include "ISOUDS_Server_Cfg.h"
#include "ISOUDS_IOCtrlByID_HAL.h"

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

/**************************** Internal functions declarations *****************/

/******************************** Function definitions ************************/

/*******************************************************************************
** Function                 : HAL_IOCntrlPreCondCheck

** Description              : API to check precondition of IO control

** Parameter                : None

** Return value             : ISOUDS_TRUE or ISOUDS_FALSE
*******************************************************************************/
uint8_t HAL_IOCntrlPreCondCheck(void)
{
	uint8_t RetVal;
	/*User specific code to return true or flase*/
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
** Function                 : HAL_IOctrlTestRtn
**
** Description              : API for IO Contol Test Routine
**
** Parameters 				: ControlType : Communication Control Type
**            				: CommType : Communication Type
**							: Data Pointer: Point to Node Identification Number if required
** Return value             : ISOUDS_POSRES based on the implemntation check status
**                            Refer ISOUDS_Server.h file UDS macro's.
*******************************************************************************/
uint8_t HAL_IOctrlTestRtn(uint16_t IOCntrlID, uint8_t IOCntrlParam, uint8_t *Data, uint16_t *RespLenth)
{
	uint8_t RespVal;
	(void)*RespLenth;
	(void)*Data;
	(void)IOCntrlParam;
	(void)IOCntrlID;
    /* User specific code */

	RespVal = ISOUDS_POSRES;
	return RespVal;
}

/*******************************************************************************
** Function                 : HAL_IOctrlFrtHeatPwr
**
** Description              : API for IO Contol Test Routine
**
** Parameters 				: ControlType : Communication Control Type
**            				: CommType : Communication Type
**							: Data Pointer: Point to Node Identification Number if required
** Return value             : ISOUDS_POSRES based on the implemntation check status
**                            Refer ISOUDS_Server.h file UDS macro's.
*******************************************************************************/
uint8_t HAL_IOctrlFrtHeatPwr(uint16_t IOCntrlID, uint8_t IOCntrlParam, uint8_t *Data, uint16_t *RespLenth)
{
	uint8_t RespVal;
	(void)*RespLenth;
	(void)*Data;
	(void)IOCntrlParam;
	(void)IOCntrlID;
    /* User specific code */

	RespVal = ISOUDS_POSRES;
	return RespVal;
}

/*******************************************************************************
** Function                 : HAL_IOctrlRearHeatPwr
**
** Description              : API for IO Contol Test Routine
**
** Parameters 				: ControlType : Communication Control Type
**            				: CommType : Communication Type
**							: Data Pointer: Point to Node Identification Number if required
** Return value             : ISOUDS_POSRES based on the implemntation check status
**                            Refer ISOUDS_Server.h file UDS macro's.
*******************************************************************************/
uint8_t HAL_IOctrlRearHeatPwr(uint16_t IOCntrlID, uint8_t IOCntrlParam, uint8_t *Data, uint16_t *RespLenth)
{
	uint8_t RespVal;
	(void)*RespLenth;
	(void)*Data;
	(void)IOCntrlParam;
	(void)IOCntrlID;
    /* User specific code */

	RespVal = ISOUDS_POSRES;
	return RespVal;
}

/*******************************************************************************
** Function                 : HAL_IOctrlFrtVentPwr
**
** Description              : API for IO Contol Test Routine
**
** Parameters 				: ControlType : Communication Control Type
**            				: CommType : Communication Type
**							: Data Pointer: Point to Node Identification Number if required
** Return value             : ISOUDS_POSRES based on the implemntation check status
**                            Refer ISOUDS_Server.h file UDS macro's.
*******************************************************************************/
uint8_t HAL_IOctrlFrtVentPwr(uint16_t IOCntrlID, uint8_t IOCntrlParam, uint8_t *Data, uint16_t *RespLenth)
{
	uint8_t RespVal;
	(void)*RespLenth;
	(void)*Data;
	(void)IOCntrlParam;
	(void)IOCntrlID;
    /* User specific code */
    #if 0
    Data = 0x00; /*default balue given*/
    *RespLenth += 0x01;
    #endif
	RespVal = ISOUDS_POSRES;
	return RespVal;
}

#endif

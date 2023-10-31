/*******************************************************************************
** Copyright (c)
**
** This software is the property of Embitel .
** It can not be used or duplicated without Embitel authorization .
**
** -----------------------------------------------------------------------------
** File Name   : ISOUDS_ReqUpld_HAL.c
** Module Name : UDS
** -----------------------------------------------------------------------------
**
** Description :
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

/**************************************** Inclusion files *****************************************/
#include "ISOUDS_Server.h"
#include "ISOUDS_ReqUpld.h"
#include "ISOUDS_ReqUpld_Cfg.h"
#include "ISOUDS_ReqUpld_HAL.h"

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

/******************************** Function definitions ********************************************/
/**************************************************************************************************
** Function                 : ISOUDS_ReqUpldReqCbk

** Description              : Reads the data record value from RdAddress till RdLength

** Parameter srcBuff        : data array

** Parameter len            : RdAddress - Read Address
							: RdLength 	- Read Lenth
							: RespBuff	- Repponse buffer
** Return value             : Positive or Negative Response value

** Remarks                  : None
***************************************************************************************************/
uint8_t  ISOUDS_ReqUpldReqCbk (unsigned long RdAddress, unsigned long RdLength, uint8_t *RespBuff)
{
    uint8_t retVal;
	(void) RdAddress;
	(void) RdLength;
	(void) *RespBuff;
    /*User specific code*/
    #if 0
    *RespBuff =  0x00;
    RdLength -= 0x01;
    #endif
    retVal = (uint8_t)ISOUDS_POSRES;
    return retVal;

}

#endif


/*******************************************************************************
** Copyright (c)
**
** This software is the property of Embitel .
** It can not be used or duplicated without Embitel authorization .
**
** -----------------------------------------------------------------------------
** File Name   : ISOUDS_RdScCfg.c
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
#include "ISOUDS_RdScCfg.h"
#include "ISOUDS_Server.h"
#include "ISOUDS_RdScDaByID_HAL.h"

#if (ISOUDS_APP_CONFIG == ISOUDS_SERVER)
/********************************* Declaration of local macros ************************************/

/********************************* Declaration of local types *************************************/

/******************************* Declaration of local variables ***********************************/

/******************************* Declaration of local constants ***********************************/

/****************************** Declaration of exported variables *********************************/

/****************************** Declaration of exported constants *********************************/
const ISOUDS_RdScDidType ISOUDS_RdScConfTab[ISOUDS_RDSCCONFTABSIZE] =
{
    {
        (uint16_t)ISOUDS_DUMMYSCID,
        (uint16_t)17,
        &ISOUDS_RdScIdDummyFunc,
        ISOUDS_TRUE,
		1,
		{UnlockedL1}
    },
};

/***************************************************************************************************
** Function                 : ISOUDS_Get_RDSCCONFTABSIZE

** Description              : Return the Number of Subfunctions configured for Read Scalind Data by ID

** Paramete           		: None

** Return value             : retVal : Number of DIDs Supported

** Remarks                  : None
***************************************************************************************************/
uint16_t ISOUDS_Get_RDSCCONFTABSIZE(void)
{
	return ISOUDS_RDSCCONFTABSIZE;
}

/***************************************************************************************************/

#endif

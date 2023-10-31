/***************************************************************************************************
** Copyright (c) 2018 EMBITEL
**
** This software is the property of EMBITEL.
** It can not be used or duplicated without EMBITEL authorization.
**
** -------------------------------------------------------------------------------------------------
** File Name    : ISOUDS_RdCfg.c
** Module Name  : ISOUDS_RdDaByID
** -------------------------------------------------------------------------------------------------
**
** Description : Values for types defined in CanSrv_RdCfg.h will reside in this file.
**
** -------------------------------------------------------------------------------------------------
**
** Documentation reference : EME-17ST013-12211.01(SWLLD CanSrv_RdDaByID)
**
****************************************************************************************************
** R E V I S I O N H I S T O R Y
****************************************************************************************************
** V01.00 16/07/2018
** - Baseline Created
**
***************************************************************************************************/

/**************************************** Inclusion files *****************************************/
#include "ISOUDS_Server.h"
#include "ISOUDS_Server_Cfg.h"
#include "ISOUDS_RdMemByAddr_Cfg.h"
#include "ISOUDS_RdMemByAddr_HAL.h"

#if (ISOUDS_APP_CONFIG == ISOUDS_SERVER)
/********************************* Declaration of local macros ************************************/

/********************************* Declaration of local types *************************************/

/******************************* Declaration of local variables ***********************************/

/******************************* Declaration of local constants ***********************************/

/****************************** Declaration of exported variables *********************************/


/****************************** Declaration of exported constants *********************************/

const ISOUDS_RdMemByAddType ISOUDS_RdMemByAddConfTab[ISOUDS_RdMemByAddMaxentries] =
{
	{
		4U,
		4U,
		0x00000000U,
		0xFDU,
		(uint8_t)(EXTENDED_SESS),
		ISOUDS_FALSE,
		1,
		{UnlockedL1},
		&ISOUDS_RdAddLengthReqCbk,
	}
};

/***************************************************************************************************
** Function                 : ISOUDS_Get_RdDTCMaxSubFun

** Description              : Return the Number of entries configured for Read Memory by address

** Paramete           		: None

** Return value             : retVal : Number of Entries Supported

** Remarks                  : None
***************************************************************************************************/
uint16_t ISOUDS_Get_RdMemByAddMaxentries(void)
{
	return ISOUDS_RdMemByAddMaxentries;
}

/****************************************************************************************************/

#endif

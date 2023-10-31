/*******************************************************************************
** Copyright (c) 2018 Embitel
**
** This software is the property of Embitel .
** It can not be used or duplicated without Embitel authorization .
**
** -----------------------------------------------------------------------------
** File Name   : ISOUDS_WrCfg.c
** Module Name : UDS
** -----------------------------------------------------------------------------
**
** Description : Write Data Identifier configuration
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
/*************************** Inclusion files **********************************/
#include "ISOUDS_Server_Cfg.h"
#include "ISOUDS_WrDaByID_Cfg.h"
#include "ISOUDS_WrDaByID_HAL.h"

#if (ISOUDS_APP_CONFIG == ISOUDS_SERVER)
/********************** Declaration of local symbol and constants *************/

/************************* Declaration of local macros ************************/

/************************* Declaration of local types *************************/

/*********************** Declaration of local variables ***********************/

/*********************** Declaration of local constants ***********************/

/********************** Declaration of exported variables *********************/

/********************** Declaration of exported constants *********************/
const ISOUDS_WrDidType ISOUDS_WrConfTab[ISOUDS_WRCONFTABSIZE] =
{
	{
		ISOUDS_WDID_SYMC_PART_NUM,
		ISOUDS_WDID_SYMC_PART_NUM_LEN,
		&ISOUDS_Write_SYMC_PartNoCbk,
		(EXTENDED_SESS),
		ISOUDS_TRUE,
		2,
	 	{UnlockedL1,UnlockedL2}
	},
	{
		ISOUDS_WDID_VEH_IDEN_NO,
		ISOUDS_WDID_VEH_IDEN_NO_LEN,
		&ISOUDS_Write_VehIdenNoCbk,
		(EXTENDED_SESS | PROGRAMMING_SESS),
		ISOUDS_TRUE,
		2,
	 	{UnlockedL1,UnlockedL2}
	},
	{
		ISOUDS_WDID_ECU_INFO,
		ISOUDS_WDID_ECU_INFO_LEN,
		&ISOUDS_Write_EcuInfoCbk,
		(EXTENDED_SESS),
		ISOUDS_TRUE,
		2,
	 	{UnlockedL1,UnlockedL2}
	},
	{
		ISOUDS_WDID_QR_CODE,
		ISOUDS_WDID_QR_CODE_LEN,
		&ISOUDS_Write_QRCodeCbk,
		(EXTENDED_SESS),
		ISOUDS_TRUE,
		2,
	 	{UnlockedL1,UnlockedL2}
	}
};


/*******************************************************************************
**                                  FUNCTIONS                                  *
*******************************************************************************/

/**************************** Internal functions declarations *****************/



/***************************************************************************************************
** Function                 : ISOUDS_Get_WRCONFTABSIZE

** Description              : Return the Number of DIDs configured for Write DID

** Paramete           		: None

** Return value             : retVal : Number of DIDs Supported

** Remarks                  : None
***************************************************************************************************/
uint16_t ISOUDS_Get_WRCONFTABSIZE(void)
{
	return ISOUDS_WRCONFTABSIZE;
}

#endif

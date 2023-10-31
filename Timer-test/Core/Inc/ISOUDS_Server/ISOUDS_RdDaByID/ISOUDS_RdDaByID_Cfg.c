/*******************************************************************************
**
** -----------------------------------------------------------------------------
** File Name    : ISOUDS_RdCfg.c
**
** Description  : Read Data Identifier configuration
**
** -----------------------------------------------------------------------------
**
*******************************************************************************/
/**************************************** Inclusion files *********************/
#include "ISOUDS_RdDaByID_Cfg.h"
#if (ISOUDS_APP_CONFIG == ISOUDS_SERVER)
/********************************* Declaration of local macros ****************/
/********************************* Declaration of local types *****************/
/******************************* Declaration of local variables ***************/

/******************************* Declaration of local constants ***************/
/****************************** Declaration of exported variables *************/
 uint16_t  locDID[ISOUDS_MAX_NO_OF_IDS_ALLOWED];
/****************************** Declaration of exported constants *************/
const ISOUDS_RdDidType ISOUDS_RdConfTab[ISOUDS_RDCONFTABSIZE] =
{
	{
			ISOUDS_ECU_STATUS_MSG,
			ISOUDS_ECU_STATUS_MSG_LEN,
			NULL_PTR,
			&RDBI_EcuStatusMsgCbk,
			(DEFAULT_SESS|PROGRAMMING_SESS|EXTENDED_SESS),
			ISOUDS_FALSE,
			 1,
			{UnlockedL1}
    },
    {
    		ISOUDS_SYMC_PART_NUM ,
			ISOUDS_SYMC_PART_NUM_LEN,
			NULL_PTR,
			&RDBI_SYMCPartNumCbk,
			(DEFAULT_SESS|PROGRAMMING_SESS|EXTENDED_SESS),
			ISOUDS_FALSE,
			 1,
			{UnlockedL1}
	},
	{
			ISOUDS_SYMC_SOFTWARE_VER,
			ISOUDS_SYMC_SOFTWARE_VER_LEN,
			NULL_PTR,
			&RDBI_SYMCSoftwareVerCbk,
			(DEFAULT_SESS|EXTENDED_SESS),
			ISOUDS_FALSE,
			 1,
			{UnlockedL1}
	},
	{
			ISOUDS_SYSTEM_SUPP_CODE	,
			ISOUDS_SYSTEM_SUPP_CODE_LEN,
			NULL_PTR,
			&RDBI_SystemSuppCodeCbk,
			(DEFAULT_SESS|PROGRAMMING_SESS|EXTENDED_SESS),
			ISOUDS_FALSE,
			 1,
			{UnlockedL1}
	},
	{
			ISOUDS_ECU_MANUFACT_DATE,
			ISOUDS_ECU_MANUFACT_DATE_LEN,
			NULL_PTR,
			&RDBI_ECUManufctDateCbk,
			(DEFAULT_SESS|EXTENDED_SESS),
			ISOUDS_FALSE,
			 1,
			{UnlockedL2}
	},
	{
			ISOUDS_ECU_SERIAL_NUM,
			ISOUDS_ECU_SERIAL_NUM_LEN,
			NULL_PTR,
			&RDBI_ECUSerialNUmCbk,
			(DEFAULT_SESS|EXTENDED_SESS),
			ISOUDS_FALSE,
			 1,
			{UnlockedL2}
	},
	{
			ISOUDS_VEH_ID_NUM_DATA,
			ISOUDS_VEH_ID_NUM_DATA_LEN,
			NULL_PTR,
			&RDBI_VehicleIDNumDataCbk,
			(DEFAULT_SESS|EXTENDED_SESS),
			ISOUDS_FALSE,
			 1,
			{UnlockedL1}
	},
	{
			ISOUDS_TESTER_SER_NO,
			ISOUDS_TESTER_SER_NO_LEN,
			NULL_PTR,
			&RDBI_TesterSerialNumCbk,
			(DEFAULT_SESS|EXTENDED_SESS),
			ISOUDS_FALSE,
			1,
			{UnlockedL1}
	},
	{
			ISOUDS_PROGRAMMING_DATE,
			ISOUDS_PROGRAMMING_DATE_LEN,
			NULL_PTR,
			&RDBI_ProgramDateCbk,
			(DEFAULT_SESS|EXTENDED_SESS),
			ISOUDS_FALSE,
			1,
			{UnlockedL1}
	},	
	{
			ISOUDS_DIAGNOSTIC_INFO,
			ISOUDS_DIAGNOSTIC_INFO_LEN,
			NULL_PTR,
			&RDBI_DiagnosticInfoCbk,
			(DEFAULT_SESS|PROGRAMMING_SESS|EXTENDED_SESS),
			ISOUDS_FALSE,
			1,
			{UnlockedL1}
	},
	{
			ISOUDS_PROGRAM_IDENT_INFO,
			ISOUDS_PROGRAM_IDENT_INFO_LEN,
			NULL_PTR,
			&RDBI_ProgramIdInfoCbk,
			(DEFAULT_SESS|PROGRAMMING_SESS|EXTENDED_SESS),
			ISOUDS_FALSE,
			1,
			{UnlockedL1}
	},
	{
			ISOUDS_HARDWARE_VER,
			ISOUDS_HARDWARE_VER_LEN,
			NULL_PTR,
			&RDBI_HardwareVerCbk,
			(DEFAULT_SESS|EXTENDED_SESS),
			ISOUDS_FALSE,
			1,
			{UnlockedL1}
	},
	{
			ISOUDS_CAN_DB_VER,
			ISOUDS_CAN_DB_VER_LEN,
			NULL_PTR,
			&RDBI_CANDBVerCbk,
			(DEFAULT_SESS|PROGRAMMING_SESS|EXTENDED_SESS),
			ISOUDS_FALSE,
			1,
			{UnlockedL1}
	},
	{
			ISOUDS_ECU_INFO,
			ISOUDS_ECU_INFO_LEN,
			NULL_PTR,
			&RDBI_ECUInfoCbk,
			(DEFAULT_SESS|EXTENDED_SESS),
			ISOUDS_FALSE,
			 1,
			{UnlockedL1}
	},
	{
			ISOUDS_QR_CODE,
			ISOUDS_QR_CODE_LEN,
			NULL_PTR,
			&RDBI_QRCodeCbk,
			(DEFAULT_SESS|EXTENDED_SESS),
			ISOUDS_FALSE,
			 1,
			{UnlockedL1}
	}
};
/***************************************************************************************************
** Function                 : ISOUDS_Get_RDCONFTABSIZE
** Description              : Return the Number of Subfunctions configured for Read DID
** Paramete           		: None
** Return value             : retVal : Number of DIDs Supported
** Remarks                  : None
***************************************************************************************************/
uint16_t ISOUDS_Get_RDCONFTABSIZE(void)
{
	return ISOUDS_RDCONFTABSIZE;
}

/***************************************************************************************************
** Function                 : ISOUDS_Get_MAXNoOfDIDAllowd
** Description              : Return the Max Number of DID Allowed for Read DID
** Paramete           		: None
** Return value             : retVal : Number of MAX nnumber Supported
** Remarks                  : None
***************************************************************************************************/
uint16_t ISOUDS_Get_MAXNoOfDIDAllowd(void)
{
	return ISOUDS_MAX_NO_OF_IDS_ALLOWED;
}

#endif

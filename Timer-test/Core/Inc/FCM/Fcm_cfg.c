/***************************************************************************************************
** Copyright (c) 2023 EMBITEL
**
** This software is the property of EMBITEL.
** It can not be used or duplicated without EMBITEL authorization.
**
** -------------------------------------------------------------------------------------------------
** File Name    : Fcm_cfg.c
** Module name  : configuration file of Fault Code Management
** -------------------------------------------------------------------------------------------------
** Description : Include file of component Fcm_cfg.c
**
** -------------------------------------------------------------------------------------------------
**
** Documentation reference : None
**
****************************************************************************************************
** R E V I S I O N  H I S T O R Y
****************************************************************************************************
** V01.00 
** - Baseline Created
**
***************************************************************************************************/

/**************************************** Inclusion files *****************************************/
#include "Fcm_cfg.h"
#include "Fcm.h"
#include "Fcm_HAL.h"
#include "stddef.h"
static uint16_t get_snapshot_by_DID(uint32_t did);

/* Variable to store the DTC configuration information */
/* Note: Update in this variable should reflect in the FCM_DTCInfo and vise versa */
const FCM_DTC_CfgType FCM_DtcCfg_Tabl[FCM_MAXNUM_DTCS] =
{
  	/* DTC num,       					OccurcThreshld, OccIncrmntVal,  AgingThrehlod,     AgingIncrmntVal, DTC_Group,  Permanent DTC*/ 
	{FCM_DTC_BPOSHIGHVTG                      ,  1U,   	FCM_ONE,    	FCM_AGINGTHRESHOLD,    FCM_ONE, BODY_DTC_GROUP,     FCM_FALSE},
	{FCM_DTC_BPOSLOWVTG                       ,  1U,   	FCM_ONE,    	FCM_AGINGTHRESHOLD,    FCM_ONE, BODY_DTC_GROUP,     FCM_FALSE},
	{FCM_DTC_C_CANBUSOFF                      ,  1U,   	FCM_ONE,    	FCM_AGINGTHRESHOLD,    FCM_ONE, BODY_DTC_GROUP, 	FCM_FALSE},
	{FCM_DTC_DRVRSEATHTRPOWLINSHRTCKT         ,  1U,   	FCM_ONE,    	FCM_AGINGTHRESHOLD,    FCM_ONE, BODY_DTC_GROUP, 	FCM_FALSE},
	{FCM_DTC_PASSSEATHTRPOWLINSHRTCKT         ,  1U,   	FCM_ONE,    	FCM_AGINGTHRESHOLD,    FCM_ONE, BODY_DTC_GROUP, 	FCM_FALSE},
	{FCM_DTC_2NDRWLHSEATHTRPOWLINSHRTCKT      ,  1U,   	FCM_ONE,    	FCM_AGINGTHRESHOLD,    FCM_ONE, BODY_DTC_GROUP, 	FCM_FALSE},
	{FCM_DTC_2NDRWRHSEATHTRPOWLINSHRTCKT      ,  1U,   	FCM_ONE,    	FCM_AGINGTHRESHOLD,    FCM_ONE, BODY_DTC_GROUP, 	FCM_FALSE},
	{FCM_DTC_DRVRSEATHTRPOWLINOPNCKT          ,  1U,   	FCM_ONE,    	FCM_AGINGTHRESHOLD,    FCM_ONE, BODY_DTC_GROUP, 	FCM_FALSE},
	{FCM_DTC_PASSSEATHTRPOWLINOPNCKT          ,  1U,   	FCM_ONE,    	FCM_AGINGTHRESHOLD,    FCM_ONE, BODY_DTC_GROUP, 	FCM_FALSE},
	{FCM_DTC_2NDRWLHSEATHTRPOWLINOPNCKT       ,  1U,   	FCM_ONE,    	FCM_AGINGTHRESHOLD,    FCM_ONE, BODY_DTC_GROUP, 	FCM_FALSE},
	{FCM_DTC_2NDRWRHSEATHTRPOWLINOPNCKT       ,  1U,   	FCM_ONE,    	FCM_AGINGTHRESHOLD,    FCM_ONE, BODY_DTC_GROUP, 	FCM_FALSE},
	{FCM_DTC_DRVRSEATHTRCNTRLLINSHRTCKT       ,  1U,   	FCM_ONE,    	FCM_AGINGTHRESHOLD,    FCM_ONE, BODY_DTC_GROUP, 	FCM_FALSE},
	{FCM_DTC_PASSSEATHTRCNTRLLINSHRTCKT       ,  1U,   	FCM_ONE,    	FCM_AGINGTHRESHOLD,    FCM_ONE, BODY_DTC_GROUP, 	FCM_FALSE},
	{FCM_DTC_2NDRWLHSEATHTRCNTRLLINSHRTCKT    ,  1U,   	FCM_ONE,    	FCM_AGINGTHRESHOLD,    FCM_ONE, BODY_DTC_GROUP, 	FCM_FALSE},
	{FCM_DTC_2NDRWRHSEATHTRCNTRLLINSHRTCKT    ,  1U,   	FCM_ONE,    	FCM_AGINGTHRESHOLD,    FCM_ONE, BODY_DTC_GROUP, 	FCM_FALSE},
	{FCM_DTC_DRVRSEATHTRCNTRLLINOPNCKT        ,  1U,   	FCM_ONE,    	FCM_AGINGTHRESHOLD,    FCM_ONE, BODY_DTC_GROUP, 	FCM_FALSE},
	{FCM_DTC_PASSSEATHTRCNTRLLINOPNCKT        ,  1U,   	FCM_ONE,    	FCM_AGINGTHRESHOLD,    FCM_ONE, BODY_DTC_GROUP, 	FCM_FALSE},
	{FCM_DTC_2NDRWLHSEATHTRCNTRLLINOPNCKT     ,  1U,   	FCM_ONE,    	FCM_AGINGTHRESHOLD,    FCM_ONE, BODY_DTC_GROUP, 	FCM_FALSE},
	{FCM_DTC_2NDRWRHSEATHTRCNTRLLINOPNCKT     ,  1U,   	FCM_ONE,    	FCM_AGINGTHRESHOLD,    FCM_ONE, BODY_DTC_GROUP, 	FCM_FALSE},
	{FCM_DTC_DRVRSEATVENTPOWLINSHRTCKT        ,  1U,   	FCM_ONE,    	FCM_AGINGTHRESHOLD,    FCM_ONE, BODY_DTC_GROUP, 	FCM_FALSE},
	{FCM_DTC_PASSSEATVENTPOWLINSHRTCKT        ,  1U,   	FCM_ONE,    	FCM_AGINGTHRESHOLD,    FCM_ONE, BODY_DTC_GROUP, 	FCM_FALSE},
	{FCM_DTC_DRVRSEATVENTPOWCNTRLLINOPNCKT    ,  1U,   	FCM_ONE,    	FCM_AGINGTHRESHOLD,    FCM_ONE, BODY_DTC_GROUP, 	FCM_FALSE},
	{FCM_DTC_PASSSEATVENTPOWCNTRLLINOPNCKT    ,  1U,   	FCM_ONE,    	FCM_AGINGTHRESHOLD,    FCM_ONE, BODY_DTC_GROUP, 	FCM_FALSE},
	{FCM_DTC_DRVRSEATVENTCNTRLLINSHRTCKT      ,  1U,   	FCM_ONE,    	FCM_AGINGTHRESHOLD,    FCM_ONE, BODY_DTC_GROUP, 	FCM_FALSE},
	{FCM_DTC_PASSSEATVENTCNTRLLINSHRTCKT      ,  1U,   	FCM_ONE,    	FCM_AGINGTHRESHOLD,    FCM_ONE, BODY_DTC_GROUP, 	FCM_FALSE},
	{FCM_DTC_DRVRSEATBCKHTROPNCKTDISCNCTN     ,  1U,   	FCM_ONE,    	FCM_AGINGTHRESHOLD,    FCM_ONE, BODY_DTC_GROUP, 	FCM_FALSE},
	{FCM_DTC_PASSSEATBCKHTROPNCKTDISCNCTN     ,  1U,   	FCM_ONE,    	FCM_AGINGTHRESHOLD,    FCM_ONE, BODY_DTC_GROUP, 	FCM_FALSE},
	{FCM_DTC_2NDRWLHSEATBCKHTROPNCKTDISCNCTN  ,  1U,   	FCM_ONE,    	FCM_AGINGTHRESHOLD,    FCM_ONE, BODY_DTC_GROUP, 	FCM_FALSE},
	{FCM_DTC_2NDRWRHSEATBCKHTROPNCKTDISCNCTN  ,  1U,   	FCM_ONE,    	FCM_AGINGTHRESHOLD,    FCM_ONE, BODY_DTC_GROUP, 	FCM_FALSE},
	{FCM_DTC_TRGTTEMPDRVRSEATHTRNOTREACHED    ,  1U,   	FCM_ONE,    	FCM_AGINGTHRESHOLD,    FCM_ONE, BODY_DTC_GROUP, 	FCM_FALSE},
	{FCM_DTC_TRGTTEMPPASSSEATHTRNOTREACHED    ,  1U,   	FCM_ONE,    	FCM_AGINGTHRESHOLD,    FCM_ONE, BODY_DTC_GROUP, 	FCM_FALSE},
	{FCM_DTC_TRGTTEMP2NDLHSEATHTRNOTREACHED   ,  1U,   	FCM_ONE,    	FCM_AGINGTHRESHOLD,    FCM_ONE, BODY_DTC_GROUP, 	FCM_FALSE},
	{FCM_DTC_TRGTTEMP2NDRHSEATHTRNOTREACHED   ,  1U,   	FCM_ONE,    	FCM_AGINGTHRESHOLD,    FCM_ONE, BODY_DTC_GROUP, 	FCM_FALSE}
};

const FCM_DTCSnapShotInfo FCM_DTCSnapshotDataVar[FCM_MAXNUM_DTCS] = 
{
	{ 
		FCM_ONE, 
		{
			{FCM_DID_F1B0, FCM_TWO, FCM_SEVEN, &get_snapshot_by_DID},
			{FCM_ZERO,FCM_ZERO,FCM_ZERO,NULL},
			{FCM_ZERO,FCM_ZERO,FCM_ZERO,NULL}
		}
	},
	{ 
		FCM_ONE, 
		{
			{FCM_DID_F1B0, FCM_TWO, FCM_EIGHT, &get_snapshot_by_DID},
			{FCM_ZERO,FCM_ZERO,FCM_ZERO,NULL},
			{FCM_ZERO,FCM_ZERO,FCM_ZERO,NULL}
		}
	},
	{ 
		FCM_ONE, 
		{
			{FCM_DID_F1B0, FCM_TWO, FCM_NINE, &get_snapshot_by_DID},
			{FCM_ZERO,FCM_ZERO,FCM_ZERO,NULL},
			{FCM_ZERO,FCM_ZERO,FCM_ZERO,NULL}
		}
	},
	{
		FCM_ONE, 
		{
		 {FCM_DID_F1B0, FCM_TWO, FCM_TEN, &get_snapshot_by_DID},
		 {FCM_ZERO,FCM_ZERO,FCM_ZERO,NULL},
		 {FCM_ZERO,FCM_ZERO,FCM_ZERO,NULL}
		}
	},
	{
		FCM_ONE, 
		{
		 {FCM_DID_F1B0, FCM_TWO, FCM_ELEVEN, &get_snapshot_by_DID},
		 {FCM_ZERO,FCM_ZERO,FCM_ZERO,NULL},
		 {FCM_ZERO,FCM_ZERO,FCM_ZERO,NULL}
		}
	},
	{
		FCM_ONE,
		{
		 {FCM_DID_F1B0, FCM_TWO, FCM_TWELVE, &get_snapshot_by_DID},
		 {FCM_ZERO,FCM_ZERO,FCM_ZERO,NULL},
		 {FCM_ZERO,FCM_ZERO,FCM_ZERO,NULL}
		}
	},
	{
		FCM_ONE, 
		{
		 {FCM_DID_F1B0, FCM_TWO, FCM_THIRTEEN, &get_snapshot_by_DID},
		 {FCM_ZERO,FCM_ZERO,FCM_ZERO,NULL},
		 {FCM_ZERO,FCM_ZERO,FCM_ZERO,NULL}
		}
	},
	{
		FCM_ONE, 
		{
		 {FCM_DID_F1B0, FCM_TWO, FCM_FOURTEEN, &get_snapshot_by_DID},
		 {FCM_ZERO,FCM_ZERO,FCM_ZERO,NULL},
		 {FCM_ZERO,FCM_ZERO,FCM_ZERO,NULL}
		}
	},
	{
		FCM_ONE, 
		{
		 {FCM_DID_F1B0, FCM_TWO, FCM_FIFTEEN, &get_snapshot_by_DID},
		 {FCM_ZERO,FCM_ZERO,FCM_ZERO,NULL},
		 {FCM_ZERO,FCM_ZERO,FCM_ZERO,NULL}
		}
	},
	{
		FCM_ONE, 
		{
		 {FCM_DID_F1B0, FCM_TWO, FCM_SIXTEEN, &get_snapshot_by_DID},
		 {FCM_ZERO,FCM_ZERO,FCM_ZERO,NULL},
		 {FCM_ZERO,FCM_ZERO,FCM_ZERO,NULL}
		}
	},
	{
		FCM_ONE, 
		{
		 {FCM_DID_F1B0, FCM_TWO, FCM_SEVENTEEN, &get_snapshot_by_DID},
		 {FCM_ZERO,FCM_ZERO,FCM_ZERO,NULL},
		 {FCM_ZERO,FCM_ZERO,FCM_ZERO,NULL}
		}
	},
	{
		FCM_TWO, 
		{
		 {FCM_DID_F1B0, FCM_TWO, FCM_EIGHTEEN, &get_snapshot_by_DID},
		 {FCM_DID_F1B5, FCM_TWO, FCM_NINETEEN, &get_snapshot_by_DID},
		 {FCM_ZERO,FCM_ZERO,FCM_ZERO,NULL}
		}
	},
	{
		FCM_TWO, 
		{
		 {FCM_DID_F1B0, FCM_TWO, FCM_TWENTY, &get_snapshot_by_DID},
		 {FCM_DID_F1B6, FCM_TWO, FCM_TWENTYONE, &get_snapshot_by_DID},
		 {FCM_ZERO,FCM_ZERO,FCM_ZERO,NULL}
		}
	},
	{
		FCM_TWO, 
		{
		 {FCM_DID_F1B0, FCM_TWO, FCM_TWENTYTWO, &get_snapshot_by_DID},
		 {FCM_DID_F1B7, FCM_TWO, FCM_TWENTYTHREE, &get_snapshot_by_DID},
		 {FCM_ZERO,FCM_ZERO,FCM_ZERO,NULL}
		}
	},
	{
		FCM_TWO, 
		{
		 {FCM_DID_F1B0, FCM_TWO, FCM_TWENTYFOUR, &get_snapshot_by_DID},
		 {FCM_DID_F1B8, FCM_TWO, FCM_TWENTYFIVE, &get_snapshot_by_DID},
		 {FCM_ZERO,FCM_ZERO,FCM_ZERO,NULL}
		}
	},
	{
		FCM_TWO, 
		{
		 {FCM_DID_F1B0, FCM_TWO, FCM_TWENTYSIX, &get_snapshot_by_DID},
		 {FCM_DID_F1B5, FCM_TWO, FCM_TWENTYSEVEN, &get_snapshot_by_DID},
		 {FCM_ZERO,FCM_ZERO,FCM_ZERO,NULL}
		}
	},
	{
		FCM_TWO, 
		{
		 {FCM_DID_F1B0, FCM_TWO, FCM_TWENTYEIGHT, &get_snapshot_by_DID},
		 {FCM_DID_F1B6, FCM_TWO, FCM_TWENTYNINE, &get_snapshot_by_DID},
		 {FCM_ZERO,FCM_ZERO,FCM_ZERO,NULL}
		}
	},
	{
		FCM_TWO, 
		{
		 {FCM_DID_F1B0, FCM_TWO, FCM_THIRTY, &get_snapshot_by_DID},
		 {FCM_DID_F1B7, FCM_TWO, FCM_THIRTYONE, &get_snapshot_by_DID},
		 {FCM_ZERO,FCM_ZERO,FCM_ZERO,NULL}
		}
	},
	{
		FCM_TWO, 
		{
		 {FCM_DID_F1B0, FCM_TWO, FCM_THIRTYTWO, &get_snapshot_by_DID},
		 {FCM_DID_F1B8, FCM_TWO, FCM_THIRTYTHREE, &get_snapshot_by_DID},
		 {FCM_ZERO,FCM_ZERO,FCM_ZERO,NULL}
		}
	},
	{
		FCM_ONE, 
		{
		 {FCM_DID_F1B0, FCM_TWO, FCM_THIRTYFOUR, &get_snapshot_by_DID},
		 {FCM_ZERO,FCM_ZERO,FCM_ZERO,NULL},
		 {FCM_ZERO,FCM_ZERO,FCM_ZERO,NULL}
		}
	},
	{
		FCM_ONE, 
		{
		 {FCM_DID_F1B0, FCM_TWO, FCM_THIRTYFIVE, &get_snapshot_by_DID},
		 {FCM_ZERO,FCM_ZERO,FCM_ZERO,NULL},
		 {FCM_ZERO,FCM_ZERO,FCM_ZERO,NULL}
		}
	},
	{
		FCM_ONE, 
		{
		 {FCM_DID_F1B0, FCM_TWO, FCM_THIRTYSIX, &get_snapshot_by_DID},
		 {FCM_ZERO,FCM_ZERO,FCM_ZERO,NULL},
		 {FCM_ZERO,FCM_ZERO,FCM_ZERO,NULL}
		}
	},
	{
		FCM_ONE, 
		{
		 {FCM_DID_F1B0, FCM_TWO, FCM_THIRTYSEVEN, &get_snapshot_by_DID},
		 {FCM_ZERO,FCM_ZERO,FCM_ZERO,NULL},
		 {FCM_ZERO,FCM_ZERO,FCM_ZERO,NULL}
		}
	},
	{
		FCM_THREE, 
		{
		 {FCM_DID_F1B0, FCM_TWO, FCM_THIRTYEIGHT, &get_snapshot_by_DID},
		 {FCM_DID_F1B9, FCM_TWO, FCM_THIRTYNINE, &get_snapshot_by_DID},
		 {FCM_DID_F1BA, FCM_TWO, FCM_FOURTY, &get_snapshot_by_DID}
		}
	},
	{
		FCM_THREE, 
		{
		 {FCM_DID_F1B0, FCM_TWO, FCM_FOURTYONE, &get_snapshot_by_DID},
		 {FCM_DID_F1BB, FCM_TWO, FCM_FOURTYTWO, &get_snapshot_by_DID},
		 {FCM_DID_F1BC, FCM_TWO, FCM_FOURTYTHREE, &get_snapshot_by_DID}
		}
	},
	{
		FCM_ONE, 
		{
		 {FCM_DID_F1B0, FCM_TWO, FCM_FOURTYFOUR, &get_snapshot_by_DID},
		 {FCM_ZERO,FCM_ZERO,FCM_ZERO,NULL},
		 {FCM_ZERO,FCM_ZERO,FCM_ZERO,NULL}
		}
	},
		{
		FCM_ONE,
		{
		 {FCM_DID_F1B0, FCM_TWO, FCM_FOURTYFIVE, &get_snapshot_by_DID},
		 {FCM_ZERO,FCM_ZERO,FCM_ZERO,NULL},
		 {FCM_ZERO,FCM_ZERO,FCM_ZERO,NULL}
		}
	},
	{
		FCM_ONE, 
		{
		 {FCM_DID_F1B0, FCM_TWO, FCM_FOURTYSIX, &get_snapshot_by_DID},
		 {FCM_ZERO,FCM_ZERO,FCM_ZERO,NULL},
		 {FCM_ZERO,FCM_ZERO,FCM_ZERO,NULL},
		}
	},
	{
		FCM_ONE, 
		{
		 {FCM_DID_F1B0, FCM_TWO, FCM_FOURTYSEVEN, &get_snapshot_by_DID},
		 {FCM_ZERO,FCM_ZERO,FCM_ZERO,NULL},
		 {FCM_ZERO,FCM_ZERO,FCM_ZERO,NULL},
		}
	},
	{
		FCM_TWO, 
		{
		 {FCM_DID_F1B0, FCM_TWO, FCM_FOURTYEIGHT, &get_snapshot_by_DID},
		 {FCM_DID_F1B5, FCM_TWO, FCM_FOURTYNINE, &get_snapshot_by_DID},
		 {FCM_ZERO,FCM_ZERO,FCM_ZERO,NULL},
		}
	},
	{
		FCM_TWO,
		{
		 {FCM_DID_F1B0, FCM_TWO, FCM_FIFTY, &get_snapshot_by_DID},
		 {FCM_DID_F1B6, FCM_TWO, FCM_FIFTYONE, &get_snapshot_by_DID},
		 {FCM_ZERO,FCM_ZERO,FCM_ZERO,NULL},
		}
	},
	{
		FCM_TWO, 
		{
		 {FCM_DID_F1B0, FCM_TWO, FCM_FIFTYTWO, &get_snapshot_by_DID},
		 {FCM_DID_F1B7, FCM_TWO, FCM_FIFTYTHREE, &get_snapshot_by_DID},
		 {FCM_ZERO,FCM_ZERO,FCM_ZERO,NULL}
		}
	},
	{
		FCM_TWO, 
		{
		 {FCM_DID_F1B0, FCM_TWO, FCM_FIFTYFOUR, &get_snapshot_by_DID},
		 {FCM_DID_F1B8, FCM_TWO, FCM_FIFTYFIVE, &get_snapshot_by_DID},
		 {FCM_ZERO,FCM_ZERO,FCM_ZERO,NULL}
		}
	}
	
};

/*----Start of Variables data should be copied to NVM------ */

/* Variable to store the DTC status information */
/* Note: Update in this variable should reflect in the FCM_DtcCfg_Tabl and vise versa */
FCM_DTC_StatusType FCM_DTCInfo[FCM_MAXNUM_DTCS] = 
{
/* Occurence Count,         Fault Status,                  Aging Count */
	{FCM_ZERO,             {FCM_DEFAULT_DTC_STATUS},        FCM_ZERO},
	{FCM_ZERO,             {FCM_DEFAULT_DTC_STATUS},        FCM_ZERO},
	{FCM_ZERO,             {FCM_DEFAULT_DTC_STATUS},        FCM_ZERO},
	{FCM_ZERO,             {FCM_DEFAULT_DTC_STATUS},        FCM_ZERO},
	{FCM_ZERO,             {FCM_DEFAULT_DTC_STATUS},        FCM_ZERO},
	{FCM_ZERO,             {FCM_DEFAULT_DTC_STATUS},        FCM_ZERO},
	{FCM_ZERO,             {FCM_DEFAULT_DTC_STATUS},        FCM_ZERO},
	{FCM_ZERO,             {FCM_DEFAULT_DTC_STATUS},        FCM_ZERO},
	{FCM_ZERO,             {FCM_DEFAULT_DTC_STATUS},        FCM_ZERO},
	{FCM_ZERO,             {FCM_DEFAULT_DTC_STATUS},        FCM_ZERO},
	{FCM_ZERO,             {FCM_DEFAULT_DTC_STATUS},        FCM_ZERO},
	{FCM_ZERO,             {FCM_DEFAULT_DTC_STATUS},        FCM_ZERO},
	{FCM_ZERO,             {FCM_DEFAULT_DTC_STATUS},        FCM_ZERO},
	{FCM_ZERO,             {FCM_DEFAULT_DTC_STATUS},        FCM_ZERO},
	{FCM_ZERO,             {FCM_DEFAULT_DTC_STATUS},        FCM_ZERO},
	{FCM_ZERO,             {FCM_DEFAULT_DTC_STATUS},        FCM_ZERO},
	{FCM_ZERO,             {FCM_DEFAULT_DTC_STATUS},        FCM_ZERO},
	{FCM_ZERO,             {FCM_DEFAULT_DTC_STATUS},        FCM_ZERO},
	{FCM_ZERO,             {FCM_DEFAULT_DTC_STATUS},        FCM_ZERO},
	{FCM_ZERO,             {FCM_DEFAULT_DTC_STATUS},        FCM_ZERO},
	{FCM_ZERO,             {FCM_DEFAULT_DTC_STATUS},        FCM_ZERO},
	{FCM_ZERO,             {FCM_DEFAULT_DTC_STATUS},        FCM_ZERO},
	{FCM_ZERO,             {FCM_DEFAULT_DTC_STATUS},        FCM_ZERO},
	{FCM_ZERO,             {FCM_DEFAULT_DTC_STATUS},        FCM_ZERO},
	{FCM_ZERO,             {FCM_DEFAULT_DTC_STATUS},        FCM_ZERO},
	{FCM_ZERO,             {FCM_DEFAULT_DTC_STATUS},        FCM_ZERO},
	{FCM_ZERO,             {FCM_DEFAULT_DTC_STATUS},        FCM_ZERO},
	{FCM_ZERO,             {FCM_DEFAULT_DTC_STATUS},        FCM_ZERO},
	{FCM_ZERO,             {FCM_DEFAULT_DTC_STATUS},        FCM_ZERO},
	{FCM_ZERO,             {FCM_DEFAULT_DTC_STATUS},        FCM_ZERO},
	{FCM_ZERO,             {FCM_DEFAULT_DTC_STATUS},        FCM_ZERO},
	{FCM_ZERO,             {FCM_DEFAULT_DTC_STATUS},        FCM_ZERO},
	{FCM_ZERO,             {FCM_DEFAULT_DTC_STATUS},        FCM_ZERO}

};


/* Stores DTC first failed DTC info */
uint8_t FCM_FirstFailedDTCInfoFlag = FCM_FALSE;
FCM_DTC_InfoType FCM_FirstFailedDTCInfo;

/* Stores DTC most recent Test Failed DTC info */
uint8_t FCM_MostRecentFailedDTCInfoFlag = FCM_FALSE;
FCM_DTC_InfoType FCM_MostRecentFailedDTCInfo;

/* Stores DTC first confirmed, DTC info */
uint8_t FCM_FirstCnfmdDTCInfoFlag = FCM_FALSE;
FCM_DTC_InfoType FCM_FirstCnfmdDTCInfo;

/* Stores DTC most recent confirmed DTC info */
uint8_t FCM_MostRecentCnfmdDTCInfoFlag = FCM_FALSE;
FCM_DTC_InfoType FCM_MostRecentCnfmdDTCInfo;

/*----End of Variables data to be copied to NVM---------*/

void FCM_Init_DTC_Info(void)
{
	uint16_t DTC_Index;
	uint8_t DTC_InfoReadStat;
	
	DTC_InfoReadStat = HAL_FCM_ReadDTCInfo(&FCM_DTCInfo[FCM_ZERO],sizeof(FCM_DTCInfo));
	/* Check if the DTC Read Failure */
	if (FCM_ZERO == DTC_InfoReadStat)
	{
		for (DTC_Index = FCM_ZERO; DTC_Index < FCM_MAXNUM_DTCS;DTC_Index++)
		{
			/* Clear the DTC status bits according to ISO 14229-1 2013 Specification */
			FCM_DTCInfo[DTC_Index].FaultStatus.Signal.testFailed   = FCM_FALSE;
			FCM_DTCInfo[DTC_Index].FaultStatus.Signal.testFailedThisOperationCycle   = FCM_FALSE;
			FCM_DTCInfo[DTC_Index].FaultStatus.Signal.pendingDTC   = FCM_FALSE;
			FCM_DTCInfo[DTC_Index].FaultStatus.Signal.confirmedDTC   = FCM_FALSE;
		#if (FCM_TST_NOT_CMPLTD_SNC_LST_CLR_STAT_SUPT == FCM_TRUE)
			FCM_DTCInfo[DTC_Index].FaultStatus.Signal.testNotCompletedSinceLastClear = FCM_TRUE;
		#else
			FCM_DTCInfo[DTC_Index].FaultStatus.Signal.testNotCompletedSinceLastClear = FCM_FALSE;
		#endif
			FCM_DTCInfo[DTC_Index].FaultStatus.Signal.testFailedSinceLastClear   = FCM_FALSE;

		#if (FCM_TST_NOT_CMPLTD_THIS_OPCYCLE_STAT_SUPT == FCM_TRUE)
			FCM_DTCInfo[DTC_Index].FaultStatus.Signal.testNotCompletedThisOperationCycle = FCM_TRUE;
		#else
			FCM_DTCInfo[DTC_Index].FaultStatus.Signal.testNotCompletedThisOperationCycle = FCM_FALSE;
		#endif
			FCM_DTCInfo[DTC_Index].FaultStatus.Signal.warningIndicatorRequested    = FCM_FALSE;

			FCM_DTCInfo[DTC_Index].AgingCount = FCM_ZERO;
			FCM_DTCInfo[DTC_Index].OccurenceCount = FCM_ZERO;
		}
		
		HAL_FCM_WriteDTCInfo(&FCM_DTCInfo[FCM_ZERO], sizeof(FCM_DTCInfo));

	}
	else
	{
		/* Do Nothing */
	}
	
	/* Initialization Flag set */
	FCM_FCM_DTC_InitStatus = FCM_TRUE;

	/* Stop the Operation Cycle */
	FCM_UpdateOperationCycle(BODY_DTC_GROUP,FCM_OPERATION_CYCLE_STOP);
	/* Start the Operation Cycle */
	FCM_UpdateOperationCycle(BODY_DTC_GROUP,FCM_OPERATION_CYCLE_START);
}

/***************************************************************************************************
** Function                 : FCM_FirstFailedDTCIndication

** Description              : This function indicates the First Failed DTC 

** Parameter                : DTC_Indx:	DTC number requested

** Return value             : None
***************************************************************************************************/
void FCM_FirstFailedDTCIndication(uint16_t FCM_DTC_Idx)
{

	
	(void)FCM_DTC_Idx;

}
/***************************************************************************************************
** Function                 : FCM_ConfirmedDTCIndication

** Description              : This function indicates the confirmed DTC 

** Parameter                : DTC_Indx:	DTC number requested

** Return value             : None
***************************************************************************************************/
void FCM_ConfirmedDTCIndication(uint16_t DTC_Indx)
{
	uint8_t FCM_Index;
	uint16_t FCM_DTCRecData;
	
	/* Check for maxmum index */
	if( DTC_Indx < FCM_MAXNUM_DTCS)
	{
		/* Check For CAN buss off DTC */
		if(FCM_DTC_C_CANBUSOFF == FCM_DtcCfg_Tabl[DTC_Indx].Fault_Id)
		{
			/* Run Loop for Supported Snapshat Data */
			for(FCM_Index = 0;FCM_Index < FCM_DTCSnapshotDataVar[DTC_Indx].FCM_DTCNumSnapshotSupp;FCM_Index++)
			{
				if(NULL != FCM_DTCSnapshotDataVar[DTC_Indx].FCM_DTCSnapshotDataSupp[FCM_Index].FCM_DTCFuncPtr)
				{
					/*Read from ADC Data */
					FCM_DTCRecData = (FCM_DTCSnapshotDataVar[DTC_Indx].FCM_DTCSnapshotDataSupp[FCM_Index].FCM_DTCFuncPtr)\
							(FCM_DTCSnapshotDataVar[DTC_Indx].FCM_DTCSnapshotDataSupp[FCM_Index].FCM_DTCSnapShotDataID);
					
					/* Write Data to EEPROM */
					//(void)writeEeprom(FCM_DTCSnapshotDataVar[DTC_Indx].FCM_DTCSnapshotDataSupp[FCM_Index].FCM_DTCEEPROMDataID\
								,FCM_DTCSnapshotDataVar[DTC_Indx].FCM_DTCSnapshotDataSupp[FCM_Index].FCM_DTCSnapshotLen\
								,(uint32_t)&FCM_DTCRecData);
				}
				else
				{
					/*Do Nothing */
				}
			}
		}
		else
		{
			/* Do Nothing */
		}
	}
	else
	{
		/* Do Nothing */
	}
	
}

/***************************************************************************************************
** Function                 : FCM_GetDTCSnpShotRecdByDTCnum

** Description              : This function copies the snapshot record data to data buffer

** Parameter                : FCM_DTC_Number:	DTC number requested
								FCM_DTC_Rec_Num:	REcord number requested
								Fcm_Snapshot_DataBuff:			Data buffer to store the data
								RespByts:			Responce bytes

** Return value             : DTC_Rec_Validity: Validiity of the request
***************************************************************************************************/
uint8_t FCM_GetDTCSnpShotRecdByDTCnum(uint32_t FCM_DTC_Number, uint8_t FCM_DTC_Rec_Num, uint8_t *Fcm_Snapshot_DataBuff, uint16_t *RespByts)
{
	
	uint8_t DTC_Rec_Validity = FCM_FALSE;
	uint16_t FCM_DTC_Ind;
	uint16_t BuffLen = FCM_ZERO;
	uint8_t *DataBuff = Fcm_Snapshot_DataBuff;
	
	FCM_DTC_Ind = FCM_FindDTCIndex(FCM_DTC_Number);
	
	if((NULL_PTR != DataBuff) && (NULL_PTR != RespByts))
	{
	
		if(FCM_DTC_Ind < FCM_MAXNUM_DTCS)
		{
			FCM_CopyDTCStatusByDTCNumber(FCM_DTC_Number, DataBuff);
				
			/* Increment the Response bytes by DTC Number + Status byte */
			RespByts[FCM_ZERO] +=  FCM_FOUR;

			/* Move the pointer to point after the DTC status data */
			if (FCM_DTC_Rec_Num == FCM_READ_SNAPSHOT_DATA_RECORD_1)
			{
				/* Copy the Record  number */
				DataBuff[FCM_FOUR] = FCM_READ_SNAPSHOT_DATA_RECORD_1;

				DataBuff[FCM_FIVE] = (uint8_t)FCM_DTCSnapshotDataVar[FCM_DTC_Ind].FCM_DTCNumSnapshotSupp;
				
				/* Update the Response Length */
				RespByts[FCM_ZERO] += FCM_TWO;
				
				/* Update the snapshot record here */
				HAL_FCM_Read_Snapst_Data(FCM_DTC_Ind, (&DataBuff[FCM_SIX]), &BuffLen);
				
				/* Update the Response Length */
				RespByts[FCM_ZERO] += (BuffLen);
				
				/* DTC record is valid */
				DTC_Rec_Validity = FCM_TRUE;
			}
			else if (FCM_DTC_Rec_Num == FCM_READ_ALL_SNAPSHOT_DATA_RECORDS)
			{	
				/* Copy the Record  number */
				DataBuff[FCM_FOUR] = FCM_READ_ALL_SNAPSHOT_DATA_RECORDS;

				DataBuff[FCM_FIVE] = (uint8_t)FCM_DTCSnapshotDataVar[FCM_DTC_Ind].FCM_DTCNumSnapshotSupp;
				
				/* Update the Response Length */
				RespByts[FCM_ZERO] += FCM_TWO;
				
				/* Update the snapshot record here */
				HAL_FCM_Read_Snapst_Data(FCM_DTC_Ind, (&DataBuff[FCM_SIX]), &BuffLen);
				
				/* Update the Response Length */
				RespByts[FCM_ZERO] += (BuffLen);
				
				/* DTC record is valid */
				DTC_Rec_Validity = FCM_TRUE;
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
	}
	else
	{
		
		/* Do nothing */
		
	}
	/* To be implemented */
	return DTC_Rec_Validity;
	
	
}


/***************************************************************************************************
** Function                 : FCM_ClearRequestdDTCInfo

** Description              : This function Initializes FCM parameters

** Parameter                : DTC_Number : DTC number whose status to be cleared

** Return value             : None
***************************************************************************************************/
uint8_t FCM_ClearRequestdDTCInfo (uint32_t DTC_Number, uint8_t DTC_MemorySelection)
{
    uint16_t    Indx;
    uint8_t RetVal = FCM_FALSE;

    (void)DTC_MemorySelection;

    if (FCM_TRUE == HAL_FCM_InitStatus())
    {
        /* Find the DTC Index */
        Indx = FCM_FindDTCIndex(DTC_Number);

        if (Indx < FCM_MAXNUM_DTCS)
        {
            /* Clear the DTC status bits according to ISO 14229-1 2013 Specification */
            FCM_DTCInfo[Indx].FaultStatus.Signal.testFailed = FCM_FALSE;
            FCM_DTCInfo[Indx].FaultStatus.Signal.testFailedThisOperationCycle  = FCM_FALSE;
            FCM_DTCInfo[Indx].FaultStatus.Signal.pendingDTC  = FCM_FALSE;
            FCM_DTCInfo[Indx].FaultStatus.Signal.confirmedDTC  = FCM_FALSE;
        #if (FCM_TST_NOT_CMPLTD_SNC_LST_CLR_STAT_SUPT == FCM_TRUE)
            FCM_DTCInfo[Indx].FaultStatus.Signal.testNotCompletedSinceLastClear  = FCM_TRUE;
        #else
            FCM_DTCInfo[Indx].FaultStatus.Signal.testNotCompletedSinceLastClear = FCM_FALSE;
        #endif
            FCM_DTCInfo[Indx].FaultStatus.Signal.testFailedSinceLastClear = FCM_FALSE;

        #if (FCM_TST_NOT_CMPLTD_THIS_OPCYCLE_STAT_SUPT == FCM_TRUE)
            FCM_DTCInfo[Indx].FaultStatus.Signal.testNotCompletedThisOperationCycle = FCM_TRUE;
        #else
            FCM_DTCInfo[Indx].FaultStatus.Signal.testNotCompletedThisOperationCycle = FCM_FALSE;
        #endif
            FCM_DTCInfo[Indx].FaultStatus.Signal.warningIndicatorRequested = FCM_FALSE;

            FCM_DTCInfo[Indx].AgingCount   = FCM_ZERO;
            FCM_DTCInfo[Indx].OccurenceCount  = FCM_ZERO;

			HAL_FCM_ClearReqDTCUpdate(Indx,FCM_DTCInfo);
			
            RetVal = FCM_TRUE;
        }
        else
        {
            RetVal = FCM_FALSE;
        }
    }
    else
    {
        /* Do nothing if FCM not init*/
    }

    return RetVal;
}

/***************************************************************************************************
** Function                 : FCM_GetDTCFaultDetCounter

** Description              : This function copies the Fault Detection counter record data to data buffer

** Parameter                : 	DataBuff:			Data buffer to store the data
								RespByts:			Responce bytes

** Return value             : None
***************************************************************************************************/
void FCM_GetDTCFaultDetCounter(uint8_t *DataBuff, uint16_t *RespByts)
{
	
	uint16_t DTC_Index;

	if((NULL_PTR != DataBuff) && (NULL_PTR != RespByts))
	{
		
		/* Loop till the all DTCs */
		for (DTC_Index = FCM_ZERO; DTC_Index < FCM_MAXNUM_DTCS; DTC_Index++)
		{
			/* Copy the DTC Number to buffer */
			DataBuff[DTC_Index * FCM_FOUR] = (uint8_t)(FCM_DtcCfg_Tabl[DTC_Index].Fault_Id >> FCM_SIXTEEN);

			DataBuff[(DTC_Index * FCM_FOUR) + FCM_ONE] = (uint8_t)((FCM_DtcCfg_Tabl[DTC_Index].Fault_Id >> FCM_EIGHT) & FCM_MASK);

			DataBuff[(DTC_Index * FCM_FOUR) + FCM_TWO] = (uint8_t)((FCM_DtcCfg_Tabl[DTC_Index].Fault_Id) & FCM_MASK);

			/*Copy the DTC status into buffer */
			DataBuff[(DTC_Index * FCM_FOUR) + FCM_THREE] = (FCM_DTCInfo[DTC_Index].OccurenceCount);
			
			RespByts[FCM_ZERO] += FCM_FOUR;

		}
	}
	else
	{
		/* Do nothing */
	}
		
}

/***************************************************************************************************
** Function                 : FCM_GetPermanentStatus

** Description              : This function copies the Permanent Status data to data buffer

** Parameter                :   DataBuff:           Data buffer to store the data
                                RespByts:           Responce bytes

** Return value             : None
***************************************************************************************************/
void FCM_GetPermanentStatus(uint8_t *DataBuff, uint16_t *RespByts)
{
    uint8_t DTC_Index;
    uint8_t Count = FCM_ZERO;

	if((NULL_PTR != DataBuff) && (NULL_PTR != RespByts))
	{
		/* Loop till the all DTCs */
		for (DTC_Index = FCM_ZERO; DTC_Index < FCM_MAXNUM_DTCS; DTC_Index++)
		{
			if(FCM_TRUE == FCM_DtcCfg_Tabl[DTC_Index].PermanentDTC)
			  {
				/* Copy the DTC Number to buffer */
				DataBuff[Count] = (uint8_t)(FCM_DtcCfg_Tabl[DTC_Index].Fault_Id >> FCM_SIXTEEN);
				Count++;
				DataBuff[Count] = (uint8_t)((FCM_DtcCfg_Tabl[DTC_Index].Fault_Id >> FCM_EIGHT) & FCM_MASK);
				Count++;
				DataBuff[Count] = (uint8_t)((FCM_DtcCfg_Tabl[DTC_Index].Fault_Id) & FCM_MASK);
				Count++;

				RespByts[FCM_ZERO] += FCM_THREE;
			  }
			else
			{
				/* Do nothing */
			}
		}
	}
	else
	{
		
		/* Do nothing */
	}
}
/***************************************************************************************************
** Function                 : FCM_CheckControlDTCCNCcndtns

** Description              : This function Checks the conditions for Processing the Control DTC request

** Parameter                : None:

** Return value             : fl_ReturnVal = 	FCM_TRUE; Conditions not correct
												FCM_FALSE; Conditions are correct
***************************************************************************************************/

uint8_t FCM_CheckControlDTCCNCcndtns(void)
{
	uint8_t fl_ReturnVal;
	
	/* Need to be modified by application engineer according to requirement */
	
	fl_ReturnVal = FCM_FALSE;
	
	
	return fl_ReturnVal;
}

/***************************************************************************************************
** Function                 : FCM_CheckControlDTCCNCcndtns

** Description              : This function verifies the optional record data of Control DTC request

** Parameter                : None:

** Return value             : fl_ReturnVal = 	FCM_TRUE; Request Out Of Range
												FCM_FALSE; Request accepted
***************************************************************************************************/

uint8_t FCM_CheckControlDTCROORcndtns(void)
{
	uint8_t fl_ReturnVal;
	
	/* Need to be modified by application engineer according to requirement */
	
	fl_ReturnVal = FCM_FALSE;
	
	
	return fl_ReturnVal;
}


/***************************************************************************************************
** Function                 : FCM_DTC_FailedIndition

** Description              : Failed DTC Indication

** Parameter                : DTC Index

** Return value             : None
***************************************************************************************************/
void FCM_DTC_FailedIndication(uint16_t DTC_Index)
{
	/* Variable Initialisation */
	uint16_t FCM_Index;
	uint16_t FCM_DTCRecData;
	/* Check for maximum index */
	if( DTC_Index < FCM_MAXNUM_DTCS)
	{
		/* Write in EEPROM */
		FCM_DTC_WriteDTCToEEPROM(DTC_Index,FCM_DTCInfo);
		/* Check For CAN buss off DTC */
		if(FCM_DTC_C_CANBUSOFF != FCM_DtcCfg_Tabl[DTC_Index].Fault_Id)
		{
			/* Run Loop for Supported Snapshat Data */
			for(FCM_Index = 0;FCM_Index < FCM_DTCSnapshotDataVar[DTC_Index].FCM_DTCNumSnapshotSupp;FCM_Index++)
			{
				if(NULL != FCM_DTCSnapshotDataVar[DTC_Index].FCM_DTCSnapshotDataSupp[FCM_Index].FCM_DTCFuncPtr)
				{
					/*Read from ADC Data */
					FCM_DTCRecData = (FCM_DTCSnapshotDataVar[DTC_Index].FCM_DTCSnapshotDataSupp[FCM_Index].FCM_DTCFuncPtr)\
							(FCM_DTCSnapshotDataVar[DTC_Index].FCM_DTCSnapshotDataSupp[FCM_Index].FCM_DTCSnapShotDataID);
					
					/* Write Data to EEPROM */
					//(void)writeEeprom(FCM_DTCSnapshotDataVar[DTC_Index].FCM_DTCSnapshotDataSupp[FCM_Index].FCM_DTCEEPROMDataID\
								,FCM_DTCSnapshotDataVar[DTC_Index].FCM_DTCSnapshotDataSupp[FCM_Index].FCM_DTCSnapshotLen\
								,(uint32_t)&FCM_DTCRecData);
				}
				else
				{
					/* Do Nothing */
				}
				
			}
			
		}
		else
		{
			/* Do Nothing */
		}
	}
	else
	{
		/* Do Nothing */
	}

}

void FCM_DTC_WriteDTCToEEPROM(uint16_t DTC_Index, FCM_DTC_StatusType *FCM_PtrToDTCInfo)
{
	/* Write in to EEPROM */
	//(void)writeEeprom((uint16_t)(FCM_EEPROM_STRTDTC_DATAID + DTC_Index),\
						(uint16_t)(sizeof(FCM_DTC_StatusType)),\
						(uint32_t)&FCM_PtrToDTCInfo[DTC_Index]);
}

static uint16_t get_snapshot_by_DID(uint32_t did)
{
	uint16_t gSnapshotList;
	/* Update snapshot list and return */
    return gSnapshotList;
}


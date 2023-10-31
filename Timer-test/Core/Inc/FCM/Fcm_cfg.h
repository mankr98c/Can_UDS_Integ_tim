/***************************************************************************************************
** Copyright (c) 2023 EMBITEL
**
** This software is the property of EMBITEL.
** It can not be used or duplicated without EMBITEL authorization.
**
** -------------------------------------------------------------------------------------------------
** File Name    : Fcm_cfg.h
** Module name  : Fault Code Management
** -------------------------------------------------------------------------------------------------
** Description : Include file of component Fcm_cfg.h
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
/* To avoid multiple inclusions */
#ifndef FCMCFG_H
#define FCMCFG_H
/**************************************** Inclusion files *****************************************/
#include <stdint.h>
/****************************** Declaration of Global Symbols *************************************/

#define 	NULL_PTR 				((void *)0)

#define FCM_FALSE									0U
#define FCM_TRUE									1U

#define FCM_ZERO									0U
#define FCM_ONE										1U
#define FCM_TWO										2U
#define FCM_THREE									3U
#define FCM_FOUR									4U
#define FCM_FIVE									5U
#define FCM_SIX										6U
#define FCM_SEVEN									7U
#define FCM_EIGHT									8U
#define FCM_NINE                                    9U
#define FCM_TEN                                     10U
#define FCM_ELEVEN                                  11U
#define FCM_TWELVE									12U
#define FCM_THIRTEEN								13U
#define FCM_FOURTEEN								14U
#define FCM_FIFTEEN									15U
#define FCM_SIXTEEN									16U
#define FCM_SEVENTEEN								17U
#define FCM_EIGHTEEN								18U
#define FCM_NINETEEN								19U
#define FCM_TWENTY									20U
#define FCM_TWENTYONE								21U
#define FCM_TWENTYTWO								22U
#define FCM_TWENTYTHREE								23U
#define FCM_TWENTYFOUR								24U
#define FCM_TWENTYFIVE								25U
#define FCM_TWENTYSIX								26U
#define FCM_TWENTYSEVEN								27U
#define FCM_TWENTYEIGHT								28U
#define FCM_TWENTYNINE								29U
#define FCM_THIRTY							    	30U
#define FCM_THIRTYONE						    	31U
#define FCM_THIRTYTWO						    	32U
#define FCM_THIRTYTHREE						    	33U
#define FCM_THIRTYFOUR						    	34U
#define FCM_THIRTYFIVE						    	35U
#define FCM_THIRTYSIX						    	36U
#define FCM_THIRTYSEVEN						    	37U
#define FCM_THIRTYEIGHT						    	38U
#define FCM_THIRTYNINE						    	39U
#define FCM_FOURTY									40U
#define FCM_FOURTYONE								41U
#define FCM_FOURTYTWO								42U
#define FCM_FOURTYTHREE								43U
#define FCM_FOURTYFOUR								44U
#define FCM_FOURTYFIVE								45U
#define FCM_FOURTYSIX								46U
#define FCM_FOURTYSEVEN								47U
#define FCM_FOURTYEIGHT								48U
#define FCM_FOURTYNINE								49U
#define FCM_FIFTY									50U
#define FCM_FIFTYONE								51U
#define FCM_FIFTYTWO								52U
#define FCM_FIFTYTHREE								53U
#define FCM_FIFTYFOUR								54U
#define FCM_FIFTYFIVE								55U
#define FCM_FIFTYSIX								56U
#define FCM_FIFTYSEVEN								57U
#define FCM_FIFTYEIGHT								58U
#define FCM_FIFTYNINE								59U
#define FCM_SIXTY									60U
#define FCM_SIXTYONE								61U
#define FCM_SIXTYTWO								62U
#define FCM_SIXTYTHREE								63U
#define FCM_SIXTYFOUR								64U
#define FCM_SIXTYFIVE								65U

#define FCM_MASK									0xFFU

#define FCM_AGINGTHRESHOLD  						40U


/* Number of supported DTCs */
#define FCM_MAXNUM_DTCS     						33U

#define FCM_EXTNDED_DATA_RECORD1_ID_1				0xFFF3U
#define FCM_EXTNDED_DATA_RECORD1_ID_2				0xFFF4U

#define EEPROM_FCM_DTCRAWStatus_DATAID				FCM_SIXTY
#define FCM_EEPROM_STRTDTC_DATAID						61U

/*#define  FCM_NETWRKGRPSUPP*/

/********************************* Declaration of macros ************************************/


/*Macros to configure supported DTC status bits */
#define FCM_TST_FAILED_STAT_SUPT					FCM_TRUE
#define FCM_TST_FAILED_THIS_OPCYCLE_STAT_SUPT		FCM_TRUE
#define FCM_PENDING_DTC_STAT_SUPT					FCM_TRUE
#define FCM_CONFIRMED_DTC_STAT_SUPT					FCM_TRUE
#define FCM_TST_NOT_CMPLTD_SNC_LST_CLR_STAT_SUPT	FCM_FALSE
#define FCM_TST_FAILED_SNC_LST_CLR_STAT_SUPT		FCM_TRUE
#define FCM_TST_NOT_CMPLTD_THIS_OPCYCLE_STAT_SUPT	FCM_TRUE
#define FCM_WARNING_INDICATOR_STAT_SUPT				FCM_FALSE

#if (FCM_PENDING_DTC_STAT_SUPT == FCM_TRUE)
	#if (FCM_TST_FAILED_THIS_OPCYCLE_STAT_SUPT == FCM_FALSE) || (FCM_TST_NOT_CMPLTD_THIS_OPCYCLE_STAT_SUPT == FCM_FALSE)
		#error "If Pending DTC is supported, then both test failed this operation cycle and Test not completed this operation cycle should also be supported"
	#endif
#endif

#if (FCM_WARNING_INDICATOR_STAT_SUPT == FCM_TRUE)
	#if (FCM_CONFIRMED_DTC_STAT_SUPT == FCM_FALSE)
		#error "Warning indicator is supported only if Confirmed DTC is supported"
	#endif
#endif

/* Macro for supported DTC status bits */
#define FCM_SUPPORTED_DTC_STATUS_BITS	((FCM_TST_FAILED_STAT_SUPT 			<< FCM_ZERO) 	|\
					(FCM_TST_FAILED_THIS_OPCYCLE_STAT_SUPT 		<< FCM_ONE)  	|\
					(FCM_PENDING_DTC_STAT_SUPT			<< FCM_TWO)  	|\
					(FCM_CONFIRMED_DTC_STAT_SUPT			<< FCM_THREE)	|\
					(FCM_TST_NOT_CMPLTD_SNC_LST_CLR_STAT_SUPT	<< FCM_FOUR)	|\
					(FCM_TST_FAILED_SNC_LST_CLR_STAT_SUPT		<< FCM_FIVE)	|\
					(FCM_TST_NOT_CMPLTD_THIS_OPCYCLE_STAT_SUPT	<< FCM_SIX)	|\
					(FCM_WARNING_INDICATOR_STAT_SUPT		<< FCM_SEVEN))

#define FCM_DTC_STAT_MSK                            (FCM_SUPPORTED_DTC_STATUS_BITS)

/* Macro for Default DTC status */
#define FCM_DEFAULT_DTC_STATUS		((FCM_TST_NOT_CMPLTD_SNC_LST_CLR_STAT_SUPT	<< FCM_FOUR)	|\
					(FCM_TST_NOT_CMPLTD_THIS_OPCYCLE_STAT_SUPT	<< FCM_SIX))

#define BODY_DTC_GROUP_START_INDEX						0U
#define BODY_DTC_GROUP_END_INDEX						(FCM_MAXNUM_DTCS)

#define POWERTRAIN_DTC_GROUP_START_INDEX				(BODY_DTC_GROUP_END_INDEX)
#define POWERTRAIN_DTC_GROUP_END_INDEX					((BODY_DTC_GROUP_END_INDEX) + 0U)

/* The DTC index is start of Network DTCs */
#define NETWORK_DTC_GROUP_START_INDEX					(POWERTRAIN_DTC_GROUP_END_INDEX)
#define NETWORK_DTC_GROUP_END_INDEX						(FCM_MAXNUM_DTCS)

#define DEFAULT_FIRST_FAILED_DTC						0x000000U
#define DEFAULT_FIRST_FAILED_DTC_STAT					0x00U


/* Macros for all the DTC supported */
#define FCM_DTC_BPOSHIGHVTG                             0x910000U
#define FCM_DTC_BPOSLOWVTG                              0x910100U
#define FCM_DTC_C_CANBUSOFF                             0x911000U
#define FCM_DTC_DRVRSEATHTRPOWLINSHRTCKT                0x912000U
#define FCM_DTC_PASSSEATHTRPOWLINSHRTCKT                0x912100U
#define FCM_DTC_2NDRWLHSEATHTRPOWLINSHRTCKT             0x912200U
#define FCM_DTC_2NDRWRHSEATHTRPOWLINSHRTCKT             0x912300U
#define FCM_DTC_DRVRSEATHTRPOWLINOPNCKT                 0x912400U
#define FCM_DTC_PASSSEATHTRPOWLINOPNCKT              	0x912500U
#define FCM_DTC_2NDRWLHSEATHTRPOWLINOPNCKT              0x912600U
#define FCM_DTC_2NDRWRHSEATHTRPOWLINOPNCKT      	    0x912700U
#define FCM_DTC_DRVRSEATHTRCNTRLLINSHRTCKT              0x913000U
#define FCM_DTC_PASSSEATHTRCNTRLLINSHRTCKT              0x913100U
#define FCM_DTC_2NDRWLHSEATHTRCNTRLLINSHRTCKT           0x913200U
#define FCM_DTC_2NDRWRHSEATHTRCNTRLLINSHRTCKT           0x913300U
#define FCM_DTC_DRVRSEATHTRCNTRLLINOPNCKT               0x913400U
#define FCM_DTC_PASSSEATHTRCNTRLLINOPNCKT               0x913500U
#define FCM_DTC_2NDRWLHSEATHTRCNTRLLINOPNCKT            0x913600U
#define FCM_DTC_2NDRWRHSEATHTRCNTRLLINOPNCKT            0x913700U
#define FCM_DTC_DRVRSEATVENTPOWLINSHRTCKT               0x914000U
#define FCM_DTC_PASSSEATVENTPOWLINSHRTCKT               0x914100U
#define FCM_DTC_DRVRSEATVENTPOWCNTRLLINOPNCKT           0x914200U
#define FCM_DTC_PASSSEATVENTPOWCNTRLLINOPNCKT           0x914300U
#define FCM_DTC_DRVRSEATVENTCNTRLLINSHRTCKT             0x915000U
#define FCM_DTC_PASSSEATVENTCNTRLLINSHRTCKT             0x915100U
#define FCM_DTC_DRVRSEATBCKHTROPNCKTDISCNCTN            0x916000U
#define FCM_DTC_PASSSEATBCKHTROPNCKTDISCNCTN            0x916100U
#define FCM_DTC_2NDRWLHSEATBCKHTROPNCKTDISCNCTN         0x916200U
#define FCM_DTC_2NDRWRHSEATBCKHTROPNCKTDISCNCTN         0x916300U
#define FCM_DTC_TRGTTEMPDRVRSEATHTRNOTREACHED           0x916400U
#define FCM_DTC_TRGTTEMPPASSSEATHTRNOTREACHED           0x916500U
#define FCM_DTC_TRGTTEMP2NDLHSEATHTRNOTREACHED          0x916600U
#define FCM_DTC_TRGTTEMP2NDRHSEATHTRNOTREACHED          0x916700U


/* Macros for all the Global DID supported */
#define FCM_DID_F1B0                                    0xF1B0U
#define FCM_DID_F1B1                                    0xF1B1U
#define FCM_DID_F1B2                                    0xF1B2U
#define FCM_DID_F1B3                                    0xF1B3U
#define FCM_DID_F1B4                                    0xF1B4U
#define FCM_DID_F1B5                                    0xF1B5U
#define FCM_DID_F1B6                                    0xF1B6U
#define FCM_DID_F1B7                                    0xF1B7U
#define FCM_DID_F1B8                                    0xF1B8U
#define FCM_DID_F1B9                                    0xF1B9U
#define FCM_DID_F1BA                                    0xF1BAU
#define FCM_DID_F1BB                                    0xF1BBU
#define FCM_DID_F1BC                                    0xF1BCU



/* Macros for DTC Snapshot data record number */
#define FCM_READ_SNAPSHOT_DATA_RECORD_1					0x01U

/* Macros for DTC Snapshot data record number */
#define FCM_READ_ALL_SNAPSHOT_DATA_RECORDS				0xFFU

/* Maximum Snapshot Data Supported */
#define FCM_DTC_MAXSNAPSUPP_PERDTC						3U

typedef enum
{
	BODY_DTC_GROUP,
	NETWORK_DTC_GROUP,
	POWR_TRN_DTC_GROUP,
	NUMBER_OF_DTC_GROUPS
}eFCM_GroupType;

typedef union
{
	uint8_t byte;
	struct
	{
		uint8_t warningIndicatorRequested:1;
		uint8_t testNotCompletedThisOperationCycle:1;
		uint8_t testFailedSinceLastClear:1;
		uint8_t testNotCompletedSinceLastClear:1;
		uint8_t confirmedDTC:1;
		uint8_t pendingDTC:1;
		uint8_t testFailedThisOperationCycle:1;
		uint8_t testFailed:1;	
	}Signal;
}FCM_DTC_FaultStatusType;

typedef struct
{
	uint32_t 			Fault_Id;
	uint8_t 			OccurenceCount;
	FCM_DTC_FaultStatusType	FaultStatus;
	uint8_t 			AgingCount;
}FCM_DTC_InfoType;

typedef struct
{
	uint8_t 			OccurenceCount;
	FCM_DTC_FaultStatusType	FaultStatus;
	uint8_t 			AgingCount;
}FCM_DTC_StatusType;

typedef struct
{
	uint32_t	Fault_Id;
	uint8_t		OccurenceThrehlod;		/* Trip Counter Threshold*/
	uint8_t		OccIncrmntVal;			/* Trip Counter Increment Value*/
	uint8_t		AgingThrehlod;
	uint8_t		AgingIncrmntVal;
	eFCM_GroupType		DTC_Group;
	uint8_t       PermanentDTC;
}FCM_DTC_CfgType;

typedef struct
{
	uint16_t FCM_DTCSnapShotDataID;
	uint16_t FCM_DTCSnapshotLen;
	uint16_t FCM_DTCEEPROMDataID;
	uint16_t (*FCM_DTCFuncPtr) (uint32_t DID);
}FCM_DTCSnapShotDataInfo;

typedef struct
{
	uint16_t FCM_DTCNumSnapshotSupp;
	FCM_DTCSnapShotDataInfo FCM_DTCSnapshotDataSupp[FCM_DTC_MAXSNAPSUPP_PERDTC];
}FCM_DTCSnapShotInfo;

extern const FCM_DTCSnapShotInfo FCM_DTCSnapshotDataVar[FCM_MAXNUM_DTCS];

extern const FCM_DTC_CfgType 	FCM_DtcCfg_Tabl[FCM_MAXNUM_DTCS];
extern FCM_DTC_StatusType 	FCM_DTCInfo[FCM_MAXNUM_DTCS];
extern uint8_t 		FCM_FirstFailedDTCInfoFlag;
extern FCM_DTC_InfoType	FCM_FirstFailedDTCInfo;
extern uint8_t FCM_MostRecentFailedDTCInfoFlag;
extern FCM_DTC_InfoType FCM_MostRecentFailedDTCInfo;
extern uint8_t 		FCM_FirstCnfmdDTCInfoFlag ;
extern FCM_DTC_InfoType	FCM_FirstCnfmdDTCInfo;
extern uint8_t		FCM_MostRecentCnfmdDTCInfoFlag;
extern FCM_DTC_InfoType	FCM_MostRecentCnfmdDTCInfo;
extern void FCM_Init_DTC_Info(void);
extern void FCM_ConfirmedDTCIndication(uint16_t DTC_Indx);
extern void FCM_FirstFailedDTCIndication(uint16_t FCM_DTC_Idx);
extern uint8_t FCM_GetDTCSnpShotRecdByDTCnum(uint32_t FCM_DTC_Number, uint8_t FCM_DTC_Rec_Num, uint8_t *Fcm_Snapshot_DataBuff, uint16_t *RespByts);
extern uint8_t FCM_ClearRequestdDTCInfo (uint32_t DTC_Number, uint8_t DTC_MemorySelection);
extern void  FCM_GetDTCFaultDetCounter(uint8_t *DataBuff, uint16_t *RespByts);
extern void FCM_GetPermanentStatus(uint8_t *DataBuff, uint16_t *RespByts);
extern uint8_t  FCM_CheckControlDTCCNCcndtns(void);
extern uint8_t  FCM_CheckControlDTCROORcndtns(void);

extern void FCM_DTC_FailedIndication(uint16_t DTC_Index);

extern void FCM_DTC_WriteDTCToEEPROM(uint16_t DTC_Index, FCM_DTC_StatusType *FCM_PtrToDTCInfo);
#endif /* FCMCFG_H */

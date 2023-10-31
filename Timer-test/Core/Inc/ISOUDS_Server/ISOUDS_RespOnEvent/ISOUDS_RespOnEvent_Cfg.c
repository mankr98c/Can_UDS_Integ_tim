/***************************************************************************************************
**
** -------------------------------------------------------------------------------------------------
** File Name    : ISOUDS_RespOnEvent_Cfg.c
**
** Description  : Response on event configuration
**
** -------------------------------------------------------------------------------------------------
**
***************************************************************************************************/

/**************************************** Inclusion files *****************************************/
#include "ISOUDS_Server.h"
#include "ISOUDS_Server_Cfg.h"
#include "ISOUDS_RespOnEvent.h"

#if (ISOUDS_APP_CONFIG == ISOUDS_SERVER)
/********************** Declaration of local symbol and constants *********************************/

/********************************* Declaration of local macros ************************************/

/********************************* Declaration of local types *************************************/

/******************************* Declaration of local variables ***********************************/
uint8_t ISOUDS_NoOfDTCsStoredPrevly;
uint32_t ISOUDS_TimerVal;
uint32_t ISOUDS_TimeOutVal;
ISOUDS_EventConf ISOUDS_EventConfig[ISOUDS_NUM_OF_EVNTS_SUP];
ISOUDS_EventConf ISOUDS_MostRcntEventReq;
uint8_t ISOUDS_RespOnEventDIDData[ISOUDS_RESPONEVENT_MAX_DID_LEN_SUPP];
uint16_t ISOUDS_RespOnEventDIDLen;

uint8_t ISOUDS_RespOnEventDIDLIVEDATA[ISOUDS_RESPONEVENT_MAX_DID_LEN_SUPP];
uint16_t ISOUDS_RespOnEventDIDLiveLen;

uint8_t ISOUDS_MostResentTestFaildDTCFlag;
uint8_t ISOUDS_MostResentConfirmedDTCFlag;

uint32_t ISOUDS_RespDIDonStatChng;
uint8_t ISOUDS_ResponStatChngFlag;

uint8_t ISOUDS_RespEventReqBuffer[ISOUDS_RESPONEVENT_MAX_REQ_LEN];
/******************************* Declaration of local constants ***********************************/

/****************************** Declaration of exported variables *********************************/

/****************************** Declaration of exported constants *********************************/

/***************************************************************************************************
**                                      FUNCTIONS                                                 **
***************************************************************************************************/

/**************************** Internal functions declarations *************************************/
static void ISOUDS_SchedOnDTCStatChng(void);
static void ISOUDS_SchedOnTimeIntrpt(void);
static void ISOUDS_SchedOnChngOfDID(void);
static void ISOUDS_SchedMstRsntDTCOnStatChng(void);
static void ISOUDS_SchedRepDTCInfoOnDTCStatChng(void);

/******************************** Function definitions ********************************************/
/***************************************************************************************************
** Function                 : ISOUDS_RespOnDtcStatChangeReq

** Description              : process the request

** Parameter EventRecd		: Event reocord daata

** Parameter RespVal 		: Response code

** Return value             : None
***************************************************************************************************/
uint8_t ISOUDS_RespOnDtcStatChangeReq(uint8_t EventRecd)
{
	uint8_t RespVal = ISOUDS_POSRES;

	(void)EventRecd;
	/* Read number of DTC with status mask */
	ISOUDS_NoOfDTCsStoredPrevly = ISOUDS_READ_NUM_OF_DTC_WITH_STAT_MASK(EventRecd);

	return RespVal;
}

/***************************************************************************************************
** Function                 : ISOUDS_RespOnChangeOfDataIDReq

** Description              : process the request

** Parameter EventRecd		: Pointer to Event record data

** Parameter RespVal 		: Response code

** Return value             : None
***************************************************************************************************/
uint8_t ISOUDS_RespOnChangeOfDataIDReq(uint16_t DID_NUM)
{
	uint8_t RespVal = ISOUDS_POSRES;

	uint8_t RetVal = 0u;

	(void)DID_NUM;

#if 0
	RetVal = ISOUDS_RdLookUp(DID_NUM);
#endif
	if(RetVal == ISOUDS_FALSE)
	{
		RespVal = ISOUDS_ROOR;
	}

	return RespVal;
}

/***************************************************************************************************
** Function                 : ISOUDS_RespOnCompOfValReq

** Description              : process the request

** Parameter EventRecd		: Pointer to Event record data

** Parameter RespVal 		: Response code

** Return value             : None
***************************************************************************************************/
uint8_t ISOUDS_RespOnCompOfValReq(uint8_t *EventRecd)
{
	uint8_t RespVal = ISOUDS_POSRES;

	(void)EventRecd;

	return RespVal;
}

/***************************************************************************************************
** Function                 : ISOUDS_reportMostRecentDtcOnStatusChangeReq

** Description              : Process the Most recent DTC on status change Req

** Parameter EventRecd		:  Event record data

** Parameter RespVal 		: Response code

** Return value             : None
***************************************************************************************************/
uint8_t ISOUDS_reportMostRecentDtcOnStatusChangeReq(uint8_t MostResntDTCFaildDTC)
{
	uint8_t RespVal = ISOUDS_POSRES;
	
	switch(MostResntDTCFaildDTC)
	{
		case REPORTMOSTRECENTTESTFAILEDDTC:
		{
			ISOUDS_MostResentTestFaildDTCFlag = ISOUDS_FALSE;
		}
		break;
		case REPORTMOSTRECENTCONFIRMEDDTC:
		{
			ISOUDS_MostResentConfirmedDTCFlag = ISOUDS_FALSE;
		}
		break;
		default:
		{
			RespVal = ISOUDS_ROOR;
		}
		break;
	}

	return RespVal;
}

/***************************************************************************************************
** Function                 : ISOUDS_MostResntTestFaildIndc

** Description              : Most resent Test failed DTC indication

** Parameter 				: None

** Parameter RetVal 		: None

** Return value             : None
***************************************************************************************************/
void ISOUDS_MostResntTestFaildIndc(void)
{
	ISOUDS_MostResentTestFaildDTCFlag = ISOUDS_TRUE;
}

/***************************************************************************************************
** Function                 : ISOUDS_MostResntConfirmedIndc

** Description              : Most resent Confirmed DTC indication

** Parameter 				: None

** Parameter RetVal 		: None

** Return value             : None
***************************************************************************************************/
void ISOUDS_MostResntConfirmedIndc(void)
{
	ISOUDS_MostResentConfirmedDTCFlag = ISOUDS_TRUE;
}

/***************************************************************************************************
** Function                 : ISOUDS_ReportDTCStatusChange

** Description              : Report DTC status Change

** Parameter 				: DTC : DTC number
							: Old_Status: Old DTC status
							: New_Status: New DTC status

** Parameter RetVal 		: None

** Return value             : None
***************************************************************************************************/
void ISOUDS_ReportDTCStatusChange(uint32_t DTC, uint8_t Old_Status, uint8_t New_Status)
{
	uint8_t status_Mask;
	
	if(EVENT_REG_ACTIV == ISOUDS_EventConfig[reportDTCRecordInformationOnDtcStatusChange].EventActStat)
	{
		status_Mask = ISOUDS_EventConfig[reportDTCRecordInformationOnDtcStatusChange].eventTypeRecord[0];
	
		if ((Old_Status & status_Mask) != (New_Status & status_Mask))
		{
			ISOUDS_RespDIDonStatChng = DTC;

			ISOUDS_ResponStatChngFlag = ISOUDS_TRUE;
		}
	}
	else
	{
		/* Do Nothing */
	}
}

/***************************************************************************************************
** Function                 : ISOUDS_GetOnDtcStatChangeEventStat

** Description              : Get the DTC status change Event status

** Parameter 				: None

** Parameter RetVal 		: TRUE : Event triggered
** 							: FALSE : Event Not triggered

** Return value             : None
***************************************************************************************************/
uint8_t ISOUDS_GetOnDtcStatChangeEventStat(void)
{
	uint8_t Read_NumOFDTCsWitStatMsk;
	uint8_t RetVal;

	RetVal = ISOUDS_FALSE;

	/* Get the Number of DTCs with the status mask */
	Read_NumOFDTCsWitStatMsk = ISOUDS_READ_NUM_OF_DTC_WITH_STAT_MASK(ISOUDS_EventConfig[OnDtcStatusChange].eventTypeRecord[0]);

	/* Check with the Previous data */
	if (ISOUDS_NoOfDTCsStoredPrevly != Read_NumOFDTCsWitStatMsk)
	{
		/* Event triggered */
		RetVal = ISOUDS_TRUE;
	}
	else
	{
		/* Do nothing */
	}

	return RetVal;
}

/***************************************************************************************************
** Function                 : ISOUDS_ClrOnDtcStatChangeEventStat

** Description              : Clear the DTC status change Event status

** Parameter 				: None

** Parameter RetVal 		: TRUE : Event triggered
** 							: FALSE : Event Not triggered

** Return value             : None
***************************************************************************************************/
uint8_t ISOUDS_ClrOnDtcStatChangeEventStat(void)
{
	uint8_t Read_NumOFDTCsWitStatMsk;
	uint8_t RetVal;

	RetVal = ISOUDS_FALSE;
	/* Get the Number of DTCs with the status mask */
	Read_NumOFDTCsWitStatMsk = ISOUDS_READ_NUM_OF_DTC_WITH_STAT_MASK(ISOUDS_EventConfig[OnDtcStatusChange].eventTypeRecord[0]);
	/* Check with the Previous data */
	if (ISOUDS_NoOfDTCsStoredPrevly != Read_NumOFDTCsWitStatMsk)
	{
		/* Clear */
		ISOUDS_NoOfDTCsStoredPrevly = Read_NumOFDTCsWitStatMsk;

		RetVal = ISOUDS_TRUE;
	}
	else
	{
		/* Do nothing */
	}

	return RetVal;
}

/***************************************************************************************************
** Function                 : ISOUDS_RespOnTimerInterptReq

** Description              : Registers response on event request

** Parameter 	EventReq	: Event record

** Parameter RespVal 		: Response

** Return value             : None
***************************************************************************************************/
uint8_t ISOUDS_RespOnTimerInterptReq(uint8_t EventReq)
{
	uint8_t RespVal = ISOUDS_POSRES;

	/* Event record */
	switch(EventReq)
	{
		/* Slow data  rate */
		case ISOUDS_SLOW_RATE_TIMER:
		{
			/* One second timeout */
			ISOUDS_TimeOutVal = ISOUDS_TIMOUT_VAL_1S;
		}
		break;
		/* Medium data rate */
		case ISOUDS_MEDM_RATE_TIMER:
		{
			/* 300msec timeout */
			ISOUDS_TimeOutVal = ISOUDS_TIMOUT_VAL_300mS;
		}
		break;
		/* Fast data rate */
		case ISOUDS_FAST_RATE_TIMER:
		{
			/* 25msec timeout */
			ISOUDS_TimeOutVal = ISOUDS_TIMOUT_VAL_25mS;
		}
		break;
		default:
		{
			RespVal = ISOUDS_ROOR;
		}
		break;
	}

	ISOUDS_TimerVal = 0;

	return RespVal;
}

/***************************************************************************************************
** Function                 : ISOUDS_GetOnTimerInterruptStat

** Description              : Get on timer interrupt status

** Parameter 				: None

** Parameter RetVal 		: TRUE : Event triggered
** 							: FALSE : Event Not triggered

** Return value             : None
***************************************************************************************************/
uint8_t ISOUDS_GetOnTimerInterruptStat(void)
{
	uint8_t RetVal = ISOUDS_FALSE;
	/* Timeout expired */
	if (ISOUDS_TimerVal >= ISOUDS_TimeOutVal)
	{
		RetVal = ISOUDS_TRUE;
	}

	return RetVal;
}

/***************************************************************************************************
** Function                 : ISOUDS_UpdtOnTmrIntrptTmrVal

** Description              : Updates the timer value

** Parameter 				: None

** Parameter 		 		: None

** Return value             : None
***************************************************************************************************/
static void ISOUDS_UpdtOnTmrIntrptTmrVal(void)
{
	/* Timeout value check */
	if (ISOUDS_TimerVal < ISOUDS_TimeOutVal)
	{
		/* Increment the timer value */
		ISOUDS_TimerVal += ISOUDS_SERVER_PERIOD_SCHED;
	}
}

/***************************************************************************************************
** Function                 : ISOUDS_ClrOnTimerInterruptStat

** Description              : CLears on timer interrupt status

** Parameter 				: None

** Parameter 		 		: None

** Return value             : None
***************************************************************************************************/
void ISOUDS_ClrOnTimerInterruptStat(void)
{
	/* Check if the timer value reached timeout */
	if (ISOUDS_TimerVal >= ISOUDS_TimeOutVal)
	{
		/* Clear the timer values */
		ISOUDS_TimerVal = 0;
	}


}

/***************************************************************************************************
** Function                 : ISOUDS_RespOnEvent_Sched

** Description              : Schedules the response on event

** Parameter 				: None

** Parameter 		 		: None

** Return value             : None
***************************************************************************************************/
void ISOUDS_RespOnEvent_Sched(void)
{
	uint8_t EvntIndx;
	uint8_t LoopIndx;

	uint16_t ReqLength;

	/* Run for all events */
	for (EvntIndx = 0 ; EvntIndx < ISOUDS_NUM_OF_EVNTS_SUP; EvntIndx++)
	{
		/* Check if the event active */
		if (EVENT_REG_ACTIV == ISOUDS_EventConfig[EvntIndx].EventActStat)
		{
			/* Switch event */
			switch(ISOUDS_EventConfig[EvntIndx].EventType)
			{
				/* On DTC status change */
				case ISOUDS_ONDTCSTATUSCHANGE:
				{
					ISOUDS_SchedOnDTCStatChng();
				}
				break;
				/* On timer interrupt */
				case ISOUDS_ONTIMERINTERRUPT:
				{
					ISOUDS_SchedOnTimeIntrpt();
				}
				break;
				/* On Change of DID data */
				case ISOUDS_ONCHANGEOFDATAIDENTIFIER:
				{
					ISOUDS_SchedOnChngOfDID();
				}
				break;
				/* On comparison of values */
				case ISOUDS_ONCOMPARISONOFVALUES:
				{

				}
				break;
				case ISOUDS_REPMOSTRSNTDTCONSTATCHNG:
				{
					ISOUDS_SchedMstRsntDTCOnStatChng();
				}
				break;
				case ISOUDS_REPDTCRECINFOONDTCSTTCHNG:
				{
					ISOUDS_SchedRepDTCInfoOnDTCStatChng();
				}
				break;
				default:
				{

				}
				break;
			}

			/* Check if it is infinite window or window time elapsed */
			if ((ISOUDS_INFINITE_WINDOW != ISOUDS_EventConfig[EvntIndx].EventWindowTime) && (ISOUDS_EventConfig[EvntIndx].EventTimeLapsed > ((uint32_t)ISOUDS_EventConfig[EvntIndx].EventWindowTime * ISOUDS_RESPON_EVNT_10S)))
			{
				/* Prepare the final response */
				ISOUDS_RespEventReqBuffer[0] = ISOUDS_SIDRESPONEVENT_POSRESP;
				ISOUDS_RespEventReqBuffer[1] = ISOUDS_EventConfig[EvntIndx].EventType;
				ISOUDS_RespEventReqBuffer[2] = 1;
				ISOUDS_RespEventReqBuffer[3] = ISOUDS_EventConfig[EvntIndx].EventWindowTime;

				for (LoopIndx = 0; LoopIndx < ISOUDS_EventConfig[EvntIndx].eventTypeRecordLen; LoopIndx++)
				{
					ISOUDS_RespEventReqBuffer[LoopIndx + 4] = ISOUDS_EventConfig[EvntIndx].eventTypeRecord[LoopIndx];
				}

				for (LoopIndx = 0; LoopIndx < (ISOUDS_EventConfig[EvntIndx].serviceToRespondToRecordLen + ISOUDS_EventConfig[EvntIndx].eventTypeRecordLen); LoopIndx++)
				{
					ISOUDS_RespEventReqBuffer[LoopIndx + 4 + ISOUDS_EventConfig[EvntIndx].eventTypeRecordLen] = ISOUDS_EventConfig[EvntIndx].serviceToRespondToRecord[LoopIndx];
				}

				ReqLength = (4U + (uint16_t)ISOUDS_EventConfig[EvntIndx].eventTypeRecordLen + ISOUDS_EventConfig[EvntIndx].serviceToRespondToRecordLen);

				ISOUDS_ServerSetRespCANid();
				/* Transmit the message */
				ISOUDS_ServerTxRequest (ReqLength, &ISOUDS_RespEventReqBuffer[0]);
				/* Inactivate the Event */
				ISOUDS_EventConfig[EvntIndx].EventActStat = EVENT_REG_INACTIV;
			}
			/* If  not infinite window */
			if (ISOUDS_INFINITE_WINDOW != ISOUDS_EventConfig[EvntIndx].EventWindowTime)
			{
				/* Increment the Time elapsed */
				ISOUDS_EventConfig[EvntIndx].EventTimeLapsed += ISOUDS_SERVER_PERIOD_SCHED;
			}
		}
	}
}

static void ISOUDS_SchedOnDTCStatChng(void)
{
	uint8_t EventStatus;

	/* Get on DTC status event status */
	EventStatus = ISOUDS_GetOnDtcStatChangeEventStat();
	/* EEvent triggered */
	if (ISOUDS_TRUE == EventStatus)
	{
		/* Get the UDS status */
		if (ISOUDS_IDLE == ISOUDS_GetUDSStat())
		{
			/* Send the request */
			ISOUDS_ServerMsgIndi(ISOUDS_EventConfig[OnDtcStatusChange].serviceToRespondToRecordLen, ISOUDS_EventConfig[OnDtcStatusChange].serviceToRespondToRecord, ISOUDS_PHYSICALREQ);
			/* CLear the event triggred */
			(void)ISOUDS_ClrOnDtcStatChangeEventStat();
		}
	}
}

static void ISOUDS_SchedOnTimeIntrpt(void)
{
	uint8_t EventStatus;

	ISOUDS_SchedOnTimeIntrpt();
	/* Get the event status */
	EventStatus = ISOUDS_GetOnTimerInterruptStat();
	/* Check if the event triggered */
	if (ISOUDS_TRUE == EventStatus)
	{
		/* Check the UDS status */
		if (ISOUDS_IDLE == ISOUDS_GetUDSStat())
		{
			/* Send the request	 */
			ISOUDS_ServerMsgIndi(ISOUDS_EventConfig[OnTimerInterrupt].serviceToRespondToRecordLen, ISOUDS_EventConfig[OnTimerInterrupt].serviceToRespondToRecord, ISOUDS_PHYSICALREQ);
			/* CLear the event */
			ISOUDS_ClrOnTimerInterruptStat();
		}
	}
	else
	{
		/* Update the evet interrupt */
		ISOUDS_UpdtOnTmrIntrptTmrVal();
	}
}

static void ISOUDS_SchedOnChngOfDID(void)
{
	uint8_t RetVal;
	uint8_t LoopIndx;

	uint16_t DID_NUM = 0u;

	DID_NUM = ((uint16_t)ISOUDS_EventConfig[OnChangeOfDataIdentifier].eventTypeRecord[0] << 8) | ISOUDS_EventConfig[OnChangeOfDataIdentifier].eventTypeRecord[1];
	ISOUDS_RespOnEventDIDLiveLen = 0u;

	RetVal = ISOUDS_RdDidData(DID_NUM,ISOUDS_RespOnEventDIDLIVEDATA,&ISOUDS_RespOnEventDIDLiveLen);

	if(ISOUDS_TRUE == RetVal)
	{
		for(LoopIndx = 0; LoopIndx < ISOUDS_RespOnEventDIDLiveLen;LoopIndx++ )
		{
			if(ISOUDS_RespOnEventDIDLIVEDATA[LoopIndx] != ISOUDS_RespOnEventDIDData[LoopIndx])
			{
				break;
			}

		}

		if(LoopIndx != ISOUDS_RespOnEventDIDLiveLen)
		{
			/* Check the UDS status */
			if (ISOUDS_IDLE == ISOUDS_GetUDSStat())
			{
				ISOUDS_ServerMsgIndi(ISOUDS_EventConfig[OnChangeOfDataIdentifier].serviceToRespondToRecordLen, ISOUDS_EventConfig[OnChangeOfDataIdentifier].serviceToRespondToRecord, ISOUDS_PHYSICALREQ);

				for(LoopIndx = 0; LoopIndx < ISOUDS_RespOnEventDIDLiveLen;LoopIndx++ )
				{
					 ISOUDS_RespOnEventDIDData[LoopIndx] = ISOUDS_RespOnEventDIDLIVEDATA[LoopIndx];

				}

			}
		}
	}
}

static void ISOUDS_SchedMstRsntDTCOnStatChng(void)
{
	switch(ISOUDS_EventConfig[reportMostRecentDtcOnStatusChange].eventTypeRecord[0])
	{
		case REPORTMOSTRECENTTESTFAILEDDTC:
		{
			if (ISOUDS_TRUE == ISOUDS_MostResentTestFaildDTCFlag)
			{
				/* Check the UDS status */
				if (ISOUDS_IDLE == ISOUDS_GetUDSStat())
				{
					/* Prepare the request */
					ISOUDS_RespEventReqBuffer[0] = 0x19;
					ISOUDS_RespEventReqBuffer[1] = 0x0D;

					/* Send the request	 */
					ISOUDS_ServerMsgIndi(2U, &ISOUDS_RespEventReqBuffer[0], ISOUDS_PHYSICALREQ);
					ISOUDS_MostResentTestFaildDTCFlag = ISOUDS_FALSE;
				}
			}
		}
		break;
		case REPORTMOSTRECENTCONFIRMEDDTC:
		{
			if (ISOUDS_TRUE == ISOUDS_MostResentConfirmedDTCFlag)
			{
				/* Check the UDS status */
				if (ISOUDS_IDLE == ISOUDS_GetUDSStat())
				{
					/* Prepare the request */
					ISOUDS_RespEventReqBuffer[0] = 0x19;
					ISOUDS_RespEventReqBuffer[1] = 0x0E;

					/* Send the request	 */
					ISOUDS_ServerMsgIndi(2U, &ISOUDS_RespEventReqBuffer[0], ISOUDS_PHYSICALREQ);

					ISOUDS_MostResentConfirmedDTCFlag = ISOUDS_FALSE;
				}
			}
		}
		break;
		default:
		{
			ISOUDS_EventConfig[reportMostRecentDtcOnStatusChange].EventActStat = EVENT_REG_ACTIV;
		}
		break;
	}
}

static void ISOUDS_SchedRepDTCInfoOnDTCStatChng(void)
{
	uint8_t LoopIndx;
	uint16_t ReqLength;

	if (ISOUDS_TRUE == ISOUDS_ResponStatChngFlag)
	{
		/* Check the UDS status */
		if (ISOUDS_IDLE == ISOUDS_GetUDSStat())
		{
			/* Prepare the request */
			ISOUDS_RespEventReqBuffer[0] = 0x19;

			for (LoopIndx = 0; LoopIndx < ISOUDS_EventConfig[reportDTCRecordInformationOnDtcStatusChange].serviceToRespondToRecordLen; LoopIndx++)
			{
				ISOUDS_RespEventReqBuffer[LoopIndx + 1] = ISOUDS_EventConfig[reportDTCRecordInformationOnDtcStatusChange].serviceToRespondToRecord[LoopIndx];
			}

			ReqLength = ISOUDS_EventConfig[reportDTCRecordInformationOnDtcStatusChange].serviceToRespondToRecordLen + 1;

			ISOUDS_RespEventReqBuffer[ReqLength] = (uint8_t)((ISOUDS_RespDIDonStatChng >> 16) & 0xFF);
			ReqLength++;
			ISOUDS_RespEventReqBuffer[ReqLength] = (uint8_t)((ISOUDS_RespDIDonStatChng >> 8) & 0xFF);
			ReqLength++;
			ISOUDS_RespEventReqBuffer[ReqLength] = (uint8_t)(ISOUDS_RespDIDonStatChng & 0xFF);
			ReqLength++;
			/* Send the request	 */
			ISOUDS_ServerMsgIndi(ReqLength, &ISOUDS_RespEventReqBuffer[0], ISOUDS_PHYSICALREQ);

			ISOUDS_ResponStatChngFlag = ISOUDS_FALSE;
		}
	}
}

#endif


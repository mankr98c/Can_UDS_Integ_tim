/***************************************************************************************************
**
** -------------------------------------------------------------------------------------------------
** File Name    : ISOUDS_RespOnEvent_Cfg.h
**
** Description  : Response on event configuration
**
** -------------------------------------------------------------------------------------------------
**
***************************************************************************************************/

/* To avoid multi-inclusions */
#ifndef ISOUDS_RESPONEVENT_CFG_H
#define ISOUDS_RESPONEVENT_CFG_H

/************************************* Inclusion files ********************************************/
#include "ISOUDS_Server.h"


/************************** Declaration of global symbol and constants ****************************/
#define	ISOUDS_EVENTTYPERECORD_LEN_MAX			0x0AU
#define	ISOUDS_SERVICETORESP_LEN_MAX			0x10U

#define ISOUDS_RESPONEVENT_ENABLE		TRUE

#define ISOUDS_NUM_OF_EVNTS_SUP					0x06U
/********************************* Declaration of global macros ***********************************/
/* Configure the respective FCM API here */
#define ISOUDS_READ_NUM_OF_DTC_WITH_STAT_MASK(StatMask)			0x01

#define ISOUDS_SLOW_RATE_TIMER			0x01U
#define ISOUDS_MEDM_RATE_TIMER			0x02U
#define ISOUDS_FAST_RATE_TIMER			0x03U

#define ISOUDS_TIMOUT_VAL_1S			1000U
#define ISOUDS_TIMOUT_VAL_300mS			300U
#define ISOUDS_TIMOUT_VAL_25mS			25U
#define ISOUDS_RESPON_EVNT_10S			10000U

#define ISOUDS_RESP_ONCOMPVAL_REC_LEN	10U
#define ISOUDS_RESPONEVENT_MAX_DID_LEN_SUPP  10U
#define ISOUDS_RESPONEVENT_MAX_REQ_LEN	50U

/********************************* Declaration of global types ************************************/
typedef enum
{
	OnDtcStatusChange,
	OnTimerInterrupt,
	OnChangeOfDataIdentifier,
	OnComparisonOfValues,
	reportMostRecentDtcOnStatusChange,
	reportDTCRecordInformationOnDtcStatusChange
}ISOUDS_EventTypeIndx_e;

typedef enum
{
	EVENT_EMPTY,
	EVENT_REG_INACTIV,
	EVENT_REG_ACTIV
}ISOUDS_EventActStat_e;

typedef struct
{
	uint32_t EventTimeLapsed;
	ISOUDS_EventActStat_e EventActStat;
	uint8_t EventType;
	uint8_t EventWindowTime;
	uint8_t eventTypeRecordLen;
	uint16_t serviceToRespondToRecordLen;
	uint8_t eventTypeRecord[ISOUDS_EVENTTYPERECORD_LEN_MAX];
	uint8_t serviceToRespondToRecord[ISOUDS_SERVICETORESP_LEN_MAX];
}ISOUDS_EventConf;

/****************************** External links of global variables ********************************/
extern ISOUDS_EventConf ISOUDS_EventConfig[ISOUDS_NUM_OF_EVNTS_SUP];
extern ISOUDS_EventConf ISOUDS_MostRcntEventReq;
extern uint8_t ISOUDS_RespOnEventDIDData[ISOUDS_RESPONEVENT_MAX_DID_LEN_SUPP];
extern uint16_t ISOUDS_RespOnEventDIDLen;
/****************************** External links of global constants ********************************/

/***************************************************************************************************
**                                      FUNCTIONS                                                 **
***************************************************************************************************/

/********************************** Function definitions ******************************************/
extern uint8_t ISOUDS_RespOnDtcStatChangeReq(uint8_t EventRecd);
extern uint8_t ISOUDS_RespOnTimerInterptReq(uint8_t EventReq);
extern uint8_t ISOUDS_GetOnDtcStatChangeEventStat(void);
extern uint8_t ISOUDS_ClrOnDtcStatChangeEventStat(void);
extern void ISOUDS_ClrOnTimerInterruptStat(void);
extern uint8_t ISOUDS_GetOnTimerInterruptStat(void);
extern uint8_t ISOUDS_RespOnChangeOfDataIDReq(uint16_t DID_NUM);
extern void ISOUDS_RespOnEvent_Sched(void);
extern uint8_t ISOUDS_reportMostRecentDtcOnStatusChangeReq(uint8_t MostResntDTCFaildDTC);
extern void ISOUDS_MostResntTestFaildIndc(void);
extern void ISOUDS_MostResntConfirmedIndc(void);
extern void ISOUDS_ReportDTCStatusChange(uint32_t DTC, uint8_t Old_Status, uint8_t New_Status);
extern uint8_t ISOUDS_RespOnCompOfValReq(uint8_t *EventRecd);
#endif  /* ISOUDS_ECURESET_H */

/*******************************************************************************
** Copyright (c) 2018 Embitel
**
** This software is the property of Embitel .
** It can not be used or duplicated without Embitel authorization .
**
** -----------------------------------------------------------------------------
** File Name   : ISOUDS_Server_Cfg.h
** Module Name : UDS
** -----------------------------------------------------------------------------
**
** Description : Configuration file of component UDS Server
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

/* To avoid multi-inclusions */
#ifndef ISOUDS_SERVER_CFG_H
#define ISOUDS_SERVER_CFG_H

#include "CanTp.h"
#include "ISOUDS_StrtDiagSess.h"
#include "ISOUDS_TstrPrsnt.h"
#include "ISOUDS_RtnCntrl.h"
#include "ISOUDS_SA.h"
#include "ISOUDS_WrDaByID.h"
#include "ISOUDS_CntrlDTCSetting.h"
#include "ISOUDS_CommCntrl.h"
#include "ISOUDS_RdDaByID.h"
#include "ISOUDS_ECUReset.h"
#include "ISOUDS_RdDTCInf.h"
#include "ISOUDS_ClearDiagInfo.h"
#include "ISOUDS_IOCtrlByID.h"
#include "ISOUDS_RdDaByPdID.h"
#include "ISOUDS_RdMemByAddr.h"
#include "ISOUDS_ReqDwnld.h"
#include "ISOUDS_TrnsfrDa.h"
#include "ISOUDS_TrnsfrExit.h"
#include "ISOUDS_WrtMemByAddr.h"
#include "ISOUDS_ATParameter.h"
#include "ISOUDS_Authentication.h"
#include "ISOUDS_DyDfDaID.h"
#include "ISOUDS_LinkCntrl.h"
#include "ISOUDS_RdScDaByID.h"
#include "ISOUDS_ReqFileTransfer.h"
#include "ISOUDS_ReqUpld.h"
#include "ISOUDS_RespOnEvent.h"
#include "ISOUDSSecurDtaTrans.h"
#include "ISOUDS_Comn.h"

/************************** Declaration of global symbol and constants ********/
/* The periodic scheduling interval of iso14229-1 */
#define     ISOUDS_SERVER_PERIOD_SCHED    (10U)

/* Timer Threshold before ECU is reset */
#define     ISOUDS_TMRTHRES        (50U)

/* Service distributor configuration table size */
#define     ISOUDS_TABSIZE         (18U)

/* Number of Logical Channels Supported per Physcial Channel */
#define 	ISOUDS_SRV_REQ_CONFIG_TAB		2U

/* UDS Buffer size */
#define     ISOUDS_SERVER_BUFFSIZE        (uint16_t)(4095U)
 /* Standard P2 limit = 50 ms */
#define     ISOUDS_STDP2LIM        (50U)
 /* Standard P2 limit = 150 ms for client*/
#define     ISOUDS_CLIENT_STDP2LIM (20U)
/* NRC 78 minimum limit = 4500 ms */
#define     ISOUDS_NRC78P2MINLIM   (0U)
/* NRC 78 maximum limit = 5000 ms */
#define     ISOUDS_NRC78P2MAXLIM   (2000U)
/* NRC 78 maximum limit = 5100 ms for client*/
#define     ISOUDS_CLIENT_NRC78P2MAXLIM (5000U)
/* Timer S3 limit = 5000 ms */
#define     ISOUDS_S3TMRLIM        (5000U)
/* Service Timeout */
#define     ISOUDS_SRVTIMEOUT      (500u)
/* Security Access Lock Count */
#define     ISOUDS_SA_LOCK_COUNT   (5000u)
/* ECU Reset Count */
#define     ISOUDS_RST_COUNT       (1000u)

/* Write Read address : User define */
#define     WRRD_ADDRESS           0x200020F1u


/* UDS Server CAN Id */
#define   ISOUDS_CAN_SERVER_RESP_ID				(uint32_t)0x739
#define   ISOUDS_CAN_SERVER_RESP_ID_TYPE		(ISOUDS_STANDARD_ID)
#define   ISOUDS_CAN_PERIODIC_MSG_RESP_ID		(uint32_t)0x18DAF24C
#define   ISOUDS_CAN_PERIODIC_MSG_RESP_ID_TYPE	(uint8_t)(ISOUDS_EXTENDED_ID)
#define	  ISOUDS_CAN_SERVER_PHY_REQ_ID			(uint32_t)0x731
#define	  ISOUDS_CAN_SERVER_PHY_REQ_ID_TYPE		(uint8_t)(ISOUDS_STANDARD_ID)
#define	  ISOUDS_CAN_SERVER_FNC_REQ_ID			(uint32_t)0x700
#define	  ISOUDS_CAN_SERVER_FNC_REQ_ID_TYPE		(uint8_t)(ISOUDS_STANDARD_ID)

#define ISOUDS_SECHD_TIME						(uint16_t)3U
#define ISOUDS_PROG_KEY_MSG_TIMER_OFF			(uint16_t)0xFFFFU
#define ISOUDS_PROG_KEY_MSG_TIMER				(uint16_t)5000U
#define ISOUDS_PROG_KEY_MSG_CYCLIC_TIMER		(uint16_t)10U

#define	ISOUDS_PROG_KEY_MSG_EXP_TIMER			( ISOUDS_PROG_KEY_MSG_TIMER / ISOUDS_SECHD_TIME)
#define	ISOUDS_PROG_KEY_MSG_EXP_CYCLIC_TIMER	( ISOUDS_PROG_KEY_MSG_CYCLIC_TIMER / ISOUDS_SECHD_TIME)



/********************************* Declaration of global macros ***************/

/********************************* Declaration of global types ****************/
typedef enum
{
	UDS_SERVER_PHYS = 0x00U,
	UDS_SERVER_FUNC = 0x01U,
	ISOUDS_SERV_MAX_CHANN
}ISOUDS_ServrType_t;

/********************************* Declaration of global types ************************************/
#define ISOUDS_SRV_MAX_SECLEV_SUPP		2U

typedef struct
{
	ISOUDS_AddrType Addressing;
    uint8_t SID;          /* Service id */
    void (*ISOUDS_FunPtr)(ISOUDS_ConfType *ISOUDSConfPtr, uint8_t dataBuff[]);/* Hold address of the
                                                                            UDS service funtion */
    uint8_t  srvSess;      /* Diagnostic session in which the service is supported */
    uint8_t  secured;                      	/* Secured */
	uint8_t	 NoSecAccssSup;		
    ISOUDS_SASuppLevel  secLev[ISOUDS_SRV_MAX_SECLEV_SUPP];                      	/* Secured */
	uint8_t AuthEnable;		/* Authentication enable or disabled */
}ISOUDS_iTabType;
/****************************** External CANks of global variables ********************************/

/****************************** External CANks of global constants ********************************/
extern const ISOUDS_iTabType ISOUDS_iTab[ISOUDS_TABSIZE];
/* UDS Buffer for data */
extern uint8_t ISOUDS_SrvBuff[ISOUDS_SERVER_BUFFSIZE];
/***************************************************************************************************
**                                      FUNCTIONS                                                 **
***************************************************************************************************/

/********************************** Function definitions ******************************************/

/****************************** External links of global variables ************/
/* UDS configuration */
extern ISOUDS_ConfType ISOUDS_ServrConf[ISOUDS_SERV_MAX_CHANN];
/* UDS Buffer for data */
extern uint8_t ISOUDS_SrvBuff[ISOUDS_SERVER_BUFFSIZE];
extern ISOUDS_DiagRxMsgId_st ISOUDS_ServerConfig_Tab[ISOUDS_SRV_REQ_CONFIG_TAB];
/****************************** External links of global constants ************/

/*******************************************************************************
**                                      FUNCTIONS                              *
*******************************************************************************/
/********************************** Function definitions **********************/
extern void DelayedSystemSoftwareResetIndication(void);
extern uint8_t ISOUDS_Get_Gear_Status_Check(void);
extern uint8_t ISOUDS_Get_EngineSpeed_Check(void);
extern uint8_t ISOUDS_Get_VehicleSpeed_Check(void);
extern uint8_t ISOUDS_Get_IgnitionStatus(void);
extern void ISOUDS_ServerSetReqCANid(void);
extern void ISOUDS_ServerSetRespCANid(void);
extern void ISOUDS_SrvSetPrdDatByIDCANid(void);
extern void ISOUDS_ServerTxRequest(uint16_t dataLen, const uint8_t *dataPtr);
extern uint8_t ISOUDS_Get_NoOfServConfgrd(void);
/***************************************************************************************************
** Function                 : ISOUDS_ReprogrammingReq_Indi

** Description              : Reprogramming Indication

** Parameter           		: None

** Return value             : None

** Remarks                  : None
***************************************************************************************************/
extern void ISOUDS_ReprogrammingReq_Indi(void);


/***************************************************************************************************
** Function                 : ISOUDS_GetServerPeriodSched

** Description              : Get Server Scheduler Period

** Paramete           		: None

** Return value             : Server Scheduler Period

** Remarks                  : None
***************************************************************************************************/
extern uint32_t ISOUDS_GetServerPeriodSched(void);

/***************************************************************************************************
** Function                 : ISOUDS_GetTimerThresh

** Description              : Get Timer Threshold 

** Paramete           		: None

** Return value             : Timer Threshold 

** Remarks                  : None
***************************************************************************************************/
extern uint32_t ISOUDS_GetTimerThresh(void);

/***************************************************************************************************
** Function                 : ISOUDS_GetServerBuffSize

** Description              : Get Server Buffer Size 

** Paramete           		: None

** Return value             : Buffer Size 

** Remarks                  : None
***************************************************************************************************/
extern uint32_t ISOUDS_GetServerBuffSize(void);

/***************************************************************************************************
** Function                 : ISOUDS_GetSTDP2Limit

** Description              : Get  Standard P2 Limit

** Paramete           		: None

** Return value             :  Standard P2 Limit

** Remarks                  : None
***************************************************************************************************/
extern uint32_t ISOUDS_GetSTDP2Limit(void);

/***************************************************************************************************
** Function                 : ISOUDS_GetNRC78P2MimLim

** Description              : Get  NRC 78 minimum limit

** Paramete           		: None

** Return value             :  NRC 78 minimum limit

** Remarks                  : None
***************************************************************************************************/
extern uint32_t ISOUDS_GetNRC78P2MimLim(void);

/***************************************************************************************************
** Function                 : ISOUDS_GetNRC78P2MaxLim

** Description              : Get  NRC 78 maximum limit

** Paramete           		: None

** Return value             :  NRC 78 maximum limit

** Remarks                  : None
***************************************************************************************************/
extern uint32_t ISOUDS_GetNRC78P2MaxLim(void);

/***************************************************************************************************
** Function                 : ISOUDS_GetS3TimerLim

** Description              : Get  Timer S3 limit

** Paramete           		: None

** Return value             :  Timer S3 limit

** Remarks                  : None
***************************************************************************************************/
extern uint32_t ISOUDS_GetS3TimerLim(void);

#endif  /* _ISOUDS_SERVER_CFG_H_ */

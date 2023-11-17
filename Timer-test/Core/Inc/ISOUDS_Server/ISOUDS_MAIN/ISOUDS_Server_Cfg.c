/*******************************************************************************
** Copyright (c) 2018 Embitel
**
** This software is the property of Embitel .
** It can not be used or duplicated without Embitel authorization .
**
** -----------------------------------------------------------------------------
** File Name   : ISOUDS_Server_Cfg.c
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

/************************************* Inclusion files ************************/
#include "ISOUDS_Server_Cfg.h"

#if (ISOUDS_APP_CONFIG == ISOUDS_SERVER)
/************************** Declaration of global symbol and constants ********/

/********************************* Declaration of global macros ***************/

/********************************* Declaration of global types ****************/

/****************************** External links of global variables ************/
uint8_t ISOUDS_SrvBuff[ISOUDS_SERVER_BUFFSIZE];
/****************************** External links of global constants ************/

/*******************************************************************************
**                                      FUNCTIONS                              *
*******************************************************************************/
ISOUDS_DiagRxMsgId_st ISOUDS_ServerConfig_Tab[ISOUDS_SRV_REQ_CONFIG_TAB] =
{

	{
		ISOUDS_CAN_SERVER_FNC_REQ_ID,
		ISOUDS_CAN_SERVER_RESP_ID,
		ISOUDS_CAN_SERVER_FNC_REQ_ID_TYPE,
		ISOUDS_CAN_SERVER_RESP_ID_TYPE
	},
	{
		ISOUDS_CAN_SERVER_PHY_REQ_ID,
		ISOUDS_CAN_SERVER_RESP_ID,
		ISOUDS_CAN_SERVER_PHY_REQ_ID_TYPE,
		ISOUDS_CAN_SERVER_RESP_ID_TYPE
	}
};

/* UDS table with service ids and related functions. */
const ISOUDS_iTabType ISOUDS_iTab[ISOUDS_TABSIZE] =
{
    {
		ISOUDS_SERVER_FUNCTIONAL_OR_PHYSICAL,
        (uint8_t)ISOUDS_SIDSTRTDIAGSESS,
        &ISOUDS_StrtDiagSess,
        (DEFAULT_SESS|PROGRAMMING_SESS|EXTENDED_SESS|SAFETY_SESS),
		ISOUDS_FALSE,
		1,
		{UnlockedL1,ISOUDS_ZERO},
		ISOUDS_FALSE
    },
    {
		ISOUDS_SERVER_FUNCTIONAL_OR_PHYSICAL,
        (uint8_t)ISOUDS_SIDTSTRPRSNT,
        &ISOUDS_TstrPrsnt,
		(DEFAULT_SESS|PROGRAMMING_SESS|EXTENDED_SESS|SAFETY_SESS),
		ISOUDS_FALSE,
		1,
		{UnlockedL1,ISOUDS_ZERO},
		ISOUDS_FALSE
    },
    {
		ISOUDS_SERVER_FUNCTIONAL_OR_PHYSICAL,
		(uint8_t)ISOUDS_SIDCLEARDIAGINFO,
		&ISOUDS_ClearDiagInfo,
		(EXTENDED_SESS),
		ISOUDS_FALSE,
		 1,
		{UnlockedL1,ISOUDS_ZERO},
		ISOUDS_FALSE
    },
    {
		ISOUDS_SERVER_FUNCTIONAL_OR_PHYSICAL,
		(uint8_t)ISOUDS_SIDCNTRLDTCSET,
		&ISOUDS_CntrlDTCSetting,
		(EXTENDED_SESS | PROGRAMMING_SESS),
		ISOUDS_FALSE,
		 1,
		{UnlockedL1,ISOUDS_ZERO},
		ISOUDS_FALSE
     },
     {
    	 ISOUDS_SERVER_FUNCTIONAL_OR_PHYSICAL,
         (uint8_t)ISOUDS_SIDCOMMCNTRL,
          &ISOUDS_CommCntrl,
     	  (EXTENDED_SESS | PROGRAMMING_SESS),
     	  ISOUDS_FALSE,
     	  1,
     	  {UnlockedL1,ISOUDS_ZERO},
     	  ISOUDS_FALSE
      },
      {
    	ISOUDS_SERVER_FUNCTIONAL_OR_PHYSICAL,
        (uint8_t)ISOUDS_SIDECURESET,
        &ISOUDS_ECUReset,
        (PROGRAMMING_SESS|EXTENDED_SESS),
     	ISOUDS_FALSE,
     	1,
     	{UnlockedL1,ISOUDS_ZERO},
     	ISOUDS_FALSE
       },
       {
		ISOUDS_SERVER_FUNCTIONAL_OR_PHYSICAL,
		(uint8_t)ISOUDS_SIDRDDABYID,
		&ISOUDS_RdDaByID,
		(DEFAULT_SESS|PROGRAMMING_SESS|EXTENDED_SESS|SAFETY_SESS),
		ISOUDS_FALSE,
		1,
		{UnlockedL1,ISOUDS_ZERO},
		ISOUDS_FALSE
      },
      {
        ISOUDS_PHYSICALREQ,
        (uint8_t)ISOUDS_SIDRDDTCINF,
         &ISOUDS_RdDTCInf,
      	(DEFAULT_SESS|EXTENDED_SESS),
      	ISOUDS_FALSE,
      	 1,
      	{UnlockedL1,ISOUDS_ZERO},
      	ISOUDS_FALSE
      },    
    {
    	ISOUDS_PHYSICALREQ,
        (uint8_t)ISOUDS_SIDRTNCNTRLID,
        &ISOUDS_RtnCntrl,
		(PROGRAMMING_SESS|EXTENDED_SESS|SAFETY_SESS),
		ISOUDS_TRUE,
		 1,
		{UnlockedL1,ISOUDS_ZERO},
		ISOUDS_FALSE
    },
    {
    	ISOUDS_PHYSICALREQ,
        (uint8_t)ISOUDS_SIDSA,
        &ISOUDS_SA,
		(PROGRAMMING_SESS|EXTENDED_SESS|SAFETY_SESS),
		ISOUDS_FALSE,
		 1,
		{UnlockedL2,ISOUDS_ZERO},
		ISOUDS_FALSE
    },
    {
    	ISOUDS_PHYSICALREQ,
        (uint8_t)ISOUDS_SIDWRDABYID,
        &ISOUDS_WrDaByID,
		(PROGRAMMING_SESS|EXTENDED_SESS|DEFAULT_SESS),
		ISOUDS_FALSE,
		 2,
		{UnlockedL2,UnlockedL4},
		ISOUDS_FALSE
    },
    {
    	ISOUDS_PHYSICALREQ,
        (uint8_t)ISOUDS_SIDIOCTRLBYID,
        &ISOUDS_IOCtrlByID,
		(EXTENDED_SESS),
		ISOUDS_FALSE,
		 1,
		{UnlockedL2,ISOUDS_ZERO},
		ISOUDS_FALSE
    },
    {
    	ISOUDS_PHYSICALREQ,
        (uint8_t)ISOUDS_SIDRDDABYPERIODIC,
        &ISOUDS_RdDaByPdID,
		(EXTENDED_SESS),
		ISOUDS_FALSE,
		 1,
		{UnlockedL2,ISOUDS_ZERO},
		ISOUDS_FALSE
    },
    {
    	ISOUDS_PHYSICALREQ,
        (uint8_t)ISOUDS_SIDRDMEMBYADDR,
        &ISOUDS_RdMemByAddr,
		(EXTENDED_SESS),
		ISOUDS_FALSE,
		 1,
		{UnlockedL2,ISOUDS_ZERO},
		ISOUDS_FALSE
    },
	{
    	ISOUDS_PHYSICALREQ,
        (uint8_t)ISOUDS_SIDREQUPLD,
        &ISOUDS_ReqUpld,
		(EXTENDED_SESS |PROGRAMMING_SESS ),
		ISOUDS_FALSE,
		 1,
		{UnlockedL1,ISOUDS_ZERO},
		ISOUDS_FALSE
    },

    {
    	ISOUDS_PHYSICALREQ,
        (uint8_t)ISOUDS_SIDREQDWNLD,
        &ISOUDS_ReqDwnld,
		(PROGRAMMING_SESS |EXTENDED_SESS),
		ISOUDS_TRUE,
		 1,
		{UnlockedL1,ISOUDS_ZERO},
		ISOUDS_FALSE
    },
    {
    	ISOUDS_PHYSICALREQ,
        (uint8_t)ISOUDS_SIDTRNSFRDTID,
        &ISOUDS_TrnsfrDa,
		(PROGRAMMING_SESS),
		ISOUDS_TRUE,
		 1,
		{UnlockedL4,ISOUDS_ZERO},
		ISOUDS_FALSE
    },
    {
    	ISOUDS_PHYSICALREQ,
        (uint8_t)ISOUDS_SIDTRNSFREXITDID,
        &ISOUDS_TrnsfrExit,
		(PROGRAMMING_SESS),
		ISOUDS_TRUE,
		 1,
		{UnlockedL4,ISOUDS_ZERO},
		ISOUDS_FALSE
    },
    {
    	ISOUDS_PHYSICALREQ,
        (uint8_t)ISOUDS_SIDWRTMEMBYADDR,
        &ISOUDS_WrtMemByAddr,
		(EXTENDED_SESS),
		ISOUDS_TRUE,
		 1,
		{UnlockedL2,ISOUDS_ZERO},
		ISOUDS_FALSE
    }
    /*,
	{
    	ISOUDS_PHYSICALREQ,
        (uint8_t)ISOUDS_SIDATPARAMETER,
        &ISOUDS_ATParameter,
		(EXTENDED_SESS),
		ISOUDS_FALSE,
		 1,
		{UnlockedL2},
		ISOUDS_FALSE
    },
	{
    	ISOUDS_PHYSICALREQ,
        (uint8_t)ISOUDS_SIDAUTHNTCTNID,
        &ISOUDS_Authnticatn,
		(EXTENDED_SESS),
		ISOUDS_FALSE,
		 1,
		{UnlockedL2},
		ISOUDS_FALSE
    },
	{
    	ISOUDS_PHYSICALREQ,
        (uint8_t)ISOUDS_SID_DDDID,
        &ISOUDS_DDDID,
		(EXTENDED_SESS),
		ISOUDS_FALSE,
		 1,
		{UnlockedL2},
		ISOUDS_FALSE
    },
	{
    	ISOUDS_PHYSICALREQ,
        (uint8_t)ISOUDS_SIDLINKCNTRLID,
        &ISOUDS_LinkCntrl,
		(EXTENDED_SESS),
		ISOUDS_FALSE,
		 1,
		{UnlockedL2},
		ISOUDS_FALSE
    },
	{
    	ISOUDS_PHYSICALREQ,
        (uint8_t)ISOUDS_SIDRDSCDABYID,
        &ISOUDS_RdScDaByID,
		(EXTENDED_SESS),
		ISOUDS_FALSE,
		 1,
		{UnlockedL2},
		ISOUDS_FALSE
    },
	{
    	ISOUDS_PHYSICALREQ,
        (uint8_t)ISOUDS_SIDREQFILETRNSFR,
        &ISOUDS_ReqFileTransfer,
		(EXTENDED_SESS),
		ISOUDS_FALSE,
		 1,
		{UnlockedL2},
		ISOUDS_FALSE
    },
	{
    	ISOUDS_PHYSICALREQ,
        (uint8_t)ISOUDS_SIDREQUPLD,
        &ISOUDS_ReqUpld,
		(EXTENDED_SESS),
		ISOUDS_FALSE,
		 1,
		{UnlockedL2},
		ISOUDS_FALSE
    },
	{
    	ISOUDS_PHYSICALREQ,
        (uint8_t)ISOUDS_SIDRESPONEVENT,
        &ISOUDS_RespOnEvent,
		(EXTENDED_SESS),
		ISOUDS_FALSE,
		 1,
		{UnlockedL2},
		ISOUDS_FALSE
    }*/

};
/*******************************************************************************
** Function                 : ISOUDS_ServerSetReqCANid

** Description              : To Recevie CAN ID

** Parameter                : CAN ID

** Return value             : None
*******************************************************************************/
void ISOUDS_ServerSetReqCANid(void)
{
	ISOTP_SetRxPhysReqID(ISOUDS_ServerConfig_Tab[ISOUDS_PHYSICALREQ - ISOUDS_ONE].RequestID, \
							ISOUDS_ServerConfig_Tab[ISOUDS_PHYSICALREQ - ISOUDS_ONE].RequestIDType);
							
	ISOTP_SetRxFuncReqID(ISOUDS_ServerConfig_Tab[ISOUDS_FUNCTIONALREQ - ISOUDS_ONE].RequestID, \
						  ISOUDS_ServerConfig_Tab[ISOUDS_FUNCTIONALREQ - ISOUDS_ONE].RequestIDType);
}

/*******************************************************************************
** Function                 : ISOUDS_ServerSetRespCANid

** Description              : To Send CAN ID

** Parameter                : CAN ID

** Return value             : None
*******************************************************************************/
void ISOUDS_ServerSetRespCANid(void)
{
	ISOTP_SetTxmesgMesgID(ISOUDS_ServerConfig_Tab[ISOUDS_PHYSICALREQ - ISOUDS_ONE].ResponseID, \
							ISOUDS_ServerConfig_Tab[ISOUDS_PHYSICALREQ - ISOUDS_ONE].ResponseIDType);
}

/*******************************************************************************
** Function                 : ISOUDS_SrvSetPrdDatByIDCANid

** Description              : To set send message Id for Periodic message Tx

** Parameter                : CAN ID

** Return value             : None
*******************************************************************************/
void ISOUDS_SrvSetPrdDatByIDCANid(void)
{
	/*ISOTP_SetTxmesgMesgID(ISOUDS_CAN_PERIODIC_MSG_RESP_ID, ISOUDS_CAN_PERIODIC_MSG_RESP_ID_TYPE);*/
}

/*******************************************************************************
** Function                 : ISOUDS_ServerTxRequest

** Description              : To Send CAN ID

** Parameter                : CAN ID

** Return value             : None
*******************************************************************************/
void ISOUDS_ServerTxRequest(uint16_t dataLen, const uint8_t *dataPtr)
{
	(void)ISOTP_TxRequest(dataLen, (uint8_t *)dataPtr);
}

/*******************************************************************************
** Function                 : DelayedSystemSoftwareResetIndication

** Description              : Delayed Reset Request index

** Parameter                : None

** Return value             : None
*******************************************************************************/
void DelayedSystemSoftwareResetIndication(void)
{
	/*ECU Reset*/
	/* Repro_Reset - ISOUDS_ZERO */

}
/***************************************************************************************************
** Function                 : ISOUDS_Get_IgnitionStatus

** Description              : Ignition status should ne checked and return true if ON

** Paramete           		: None

** Return value             : retVal : ISOUDS_TRUE/ISOUDS_FALSE

** Remarks                  : None
***************************************************************************************************/
uint8_t ISOUDS_Get_IgnitionStatus(void)
{
	return ISOUDS_TRUE;
}

/***************************************************************************************************
** Function                 : ISOUDS_Get_VehicleSpeed_Check

** Description              : Vehicle Speed should ne checked and return true if Vehicle Speed limit conditoons are met

** Paramete           		: None

** Return value             : retVal : ISOUDS_TRUE/ISOUDS_FALSE

** Remarks                  : None
***************************************************************************************************/
uint8_t ISOUDS_Get_VehicleSpeed_Check(void)
{
	return ISOUDS_TRUE;
}

/***************************************************************************************************
** Function                 : ISOUDS_Get_EngineSpeed_Check

** Description              : Engine Speed should ne checked and return true if Engine Speed limit conditoons are met

** Paramete           		: None

** Return value             : retVal : ISOUDS_TRUE/ISOUDS_FALSE

** Remarks                  : None
***************************************************************************************************/
uint8_t ISOUDS_Get_EngineSpeed_Check(void)
{
	return ISOUDS_TRUE;
}

/***************************************************************************************************
** Function                 : ISOUDS_Get_Gear_Status_Check

** Description              : Return the Gear status TRUE if Conditions from C1 from Secition 8 are met

** Paramete           		: None

** Return value             : retVal : ISOUDS_TRUE/ISOUDS_FALSE

** Remarks                  : None
***************************************************************************************************/
uint8_t ISOUDS_Get_Gear_Status_Check(void)
{
	return ISOUDS_TRUE;
}

/***************************************************************************************************
** Function                 : ISOUDS_Get_NoOfServConfgrd

** Description              : Return the Number of Services configured for the Server

** Paramete           		: None

** Return value             : retVal : ISOUDS_TRUE/ISOUDS_FALSE

** Remarks                  : None
***************************************************************************************************/
uint8_t ISOUDS_Get_NoOfServConfgrd(void)
{
	return ((uint8_t)ISOUDS_TABSIZE);
}

/***************************************************************************************************
** Function                 : ISOUDS_ReprogrammingReq_Indi

** Description              : Reprogramming Indication

** Parameter           		: None

** Return value             : None

** Remarks                  : None
***************************************************************************************************/
void ISOUDS_ReprogrammingReq_Indi(void)
{
    uint8_t data[6] = {ISOUDS_ZERO};
    uint16_t  p2aValue = ISOUDS_ZERO;

    /* Prepare the Programming session positive response */
    data[0] = 0x50;
    data[1] = 0x02;
    data[3] = (uint8_t)ISOUDS_STDP2LIM;
    data[2] = (uint8_t)(((uint16_t)ISOUDS_STDP2LIM) >> 8);

    /* Store the P2* value - resolution 10 ms/bit */
    p2aValue    = (uint16_t)(((uint32_t)ISOUDS_NRC78P2MAXLIM) / ((uint8_t)0x0A));
    data[5] = (uint8_t)(p2aValue & 0xFFu);
    data[4] = (uint8_t)((p2aValue >> 8)& 0xFFu);
    /* Transmit the programming session positive response */
    (void)ISOTP_TxRequest(sizeof(data), data);
    /* Change the UDS state to Programming session */
    ISOUDS_SetSessionStat(ISOUDS_PRGS);
    /* Restart the S3 timer */
    ISOUDS_ResetiS3Timer();

    ISOUDS_SA_ResetPwrONDly();
}

/***************************************************************************************************
** Function                 : ISOUDS_GetServerPeriodSched

** Description              : Get Server Scheduler Period

** Paramete           		: None

** Return value             : Server Scheduler Period

** Remarks                  : None
***************************************************************************************************/
uint32_t ISOUDS_GetServerPeriodSched(void)
{
	/* return Server Scheduler Period */
	return ISOUDS_SERVER_PERIOD_SCHED;
}

/***************************************************************************************************
** Function                 : ISOUDS_GetTimerThresh

** Description              : Get Timer Threshold 

** Paramete           		: None

** Return value             : Timer Threshold 

** Remarks                  : None
***************************************************************************************************/
uint32_t ISOUDS_GetTimerThresh(void)
{
	/* return Timer Threshold */
	return ISOUDS_TMRTHRES;
}

/***************************************************************************************************
** Function                 : ISOUDS_GetServerBuffSize

** Description              : Get Server Buffer Size 

** Paramete           		: None

** Return value             : Buffer Size 

** Remarks                  : None
***************************************************************************************************/
uint32_t ISOUDS_GetServerBuffSize(void)
{
	/* return Buffer Size */
	return ISOUDS_SERVER_BUFFSIZE;
}

/***************************************************************************************************
** Function                 : ISOUDS_GetSTDP2Limit

** Description              : Get  Standard P2 Limit

** Paramete           		: None

** Return value             :  Standard P2 Limit

** Remarks                  : None
***************************************************************************************************/
uint32_t ISOUDS_GetSTDP2Limit(void)
{
	/* return Standard P2 Limit */
	return ISOUDS_STDP2LIM;
}

/***************************************************************************************************
** Function                 : ISOUDS_GetNRC78P2MimLim

** Description              : Get  NRC 78 minimum limit

** Paramete           		: None

** Return value             :  NRC 78 minimum limit

** Remarks                  : None
***************************************************************************************************/
uint32_t ISOUDS_GetNRC78P2MimLim(void)
{
	/* return NRC 78 minimum limit */
	return ISOUDS_NRC78P2MINLIM;
}

/***************************************************************************************************
** Function                 : ISOUDS_GetNRC78P2MaxLim

** Description              : Get  NRC 78 maximum limit

** Paramete           		: None

** Return value             :  NRC 78 maximum limit

** Remarks                  : None
***************************************************************************************************/
uint32_t ISOUDS_GetNRC78P2MaxLim(void)
{
	/* return NRC 78 maximum limit */
	return ISOUDS_NRC78P2MAXLIM;
}

/***************************************************************************************************
** Function                 : ISOUDS_GetS3TimerLim

** Description              : Get  Timer S3 limit

** Paramete           		: None

** Return value             :  Timer S3 limit

** Remarks                  : None
***************************************************************************************************/
uint32_t ISOUDS_GetS3TimerLim(void)
{
	/* return Timer S3 limit */
	return ISOUDS_S3TMRLIM;
}

#endif

/*******************************************************************************
** Copyright (c) 2018 Embitel
**
** This software is the property of Embitel .
** It can not be used or duplicated without Embitel authorization .
**
** -----------------------------------------------------------------------------
** File Name   : ISOUDS_Server.h
** Module Name : UDS
** -----------------------------------------------------------------------------
**
** Description : Include file of component ISOUDS_Server.c
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
#ifndef ISOUDS_SERVER_H
#define ISOUDS_SERVER_H

/************************************* Inclusion files ************************/

#include <stdint.h>
#include "ISOUDS_Comn.h"
#include "ISOUDS_Server_Cfg.h"
#include "ISOUDS_StrtDiagSess_Cfg.h"
/************************** Declaration of global symbol and constants ********/


/********************************* Declaration of global types ****************/

/****************************** External links of global variables ************/
/* ECU Reset Request */
extern uint8_t ISOUDS_EcuRstReq;

/* UDS current session */
extern uint8_t ISOUDS_Sess;

/* Timer for Ecu Reset */
extern uint32_t ISOUDS_TmrECURst;


extern uint32_t ISOUDS_iTmrP2Min;
extern uint32_t ISOUDS_iTmrP2Max;
extern uint32_t ISOUDS_iTmrSTmin;


extern uint8_t ISOUDS_SrvChannel;
/****************************** External links of global constants ************/

/*******************************************************************************
**                                      FUNCTIONS                             **
*******************************************************************************/

/********************************** Function definitions **********************/
extern void ISOUDS_Server_Init (void);
extern void ISOUDS_Main_Server (void);
extern void ISOUDS_ServerMsgIndi (uint16_t nBytes, const uint8_t *tpBuff, ISOUDS_AddrType ReqType);
extern void ISOUDS_ServerTxCnfCbk (void);
extern void ISOUDS_ServerRst (void);
extern void ISOUDS_SrvMon (void);
extern void ISOUDS_ReqECUReset (void);

extern uint8_t ISOUDS_SetAccessParameters (uint32_t P2min, uint32_t P2max, uint32_t STmin);
extern void ISOUDS_ResetiS3Timer (void);
extern uint8_t ISOUDS_GetUDSStat(void);
extern uint8_t ISOUDS_DefaultsessionStatus (void);
extern void ISUDS_SessionChangeInd(void);
extern void ISOUDS_SetSessionStat(uint8_t TargetSession);
#endif  /* _ISOUDS_H_ */

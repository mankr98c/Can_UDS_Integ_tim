/***************************************************************************************************
** Copyright (c) 2023 EMBITEL
**
** This software is the property of EMBITEL.
** It can not be used or duplicated without EMBITEL authorization.
**
** -------------------------------------------------------------------------------------------------
** File Name    : Fcm.h
** Module name  : Fault Code Management
** -------------------------------------------------------------------------------------------------
** Description : Include file of component Fcm.h
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
#ifndef FCM_H
#define FCM_H

/**************************************** Inclusion files *****************************************/

#include "Fcm_cfg.h"
#include <stdint.h>
/********************************* Declaration of macros ************************************/

/****************************** Declaration of Global Symbols *************************************/
typedef enum{
	FCM_OPERATION_CYCLE_START,
	FCM_OPERATION_CYCLE_STOP
}eFCM_OperationCycleType;

typedef enum{
	FCM_TESTFAIL,
	FCM_TESTPASS
}eFCM_TestResultType;

typedef enum{
	FCM_DTC_SETTING_ON = 0x01U,
	FCM_DTC_SETTING_OFF
}eFCM_ControDTCType;



/****************************** Declaration of Global Types ***************************************/

/****************************** Declaration of exported variables *********************************/
/****************************** Declaration of exported constants *********************************/

/**************************** External functions declarations *************************************/
extern void FCM_Init(void);
extern uint8_t FCM_GetDTCStatusByDTCNmbr (uint32_t DTC_Num);
extern uint8_t FCM_FindDTCIndex(uint32_t FCM_DTC_Number);
extern uint16_t FCM_FindNmDTCIndex(uint32_t FCM_DTC_Number);
extern uint8_t FCM_GetDTCStatusByDTCIndex (uint8_t DTC_Index);
extern uint8_t FCM_GetHealedDTCStatusByDTCNumber (uint16_t DTC_Index);
extern void FCM_CopyDTCStatusByDTCNumber (uint32_t DTC_Number, uint8_t* data_ptr);
extern void FCM_NotifyTestResult (uint8_t FCM_DTC_Idx, eFCM_TestResultType FCM_FaultSt);
extern void FCM_UpdateOperationCycle(eFCM_GroupType DTC_GrpIndex, eFCM_OperationCycleType CycleStatus);
extern uint8_t FCM_ClearAllDTCInfo (void);
extern uint16_t FCM_ReportNoOfDTCByStatusMask (uint8_t FCM_DTC_StatusMask);
extern uint16_t FCM_ReportDTCByStatusMask (uint8_t FCM_DTC_StatusMask, uint8_t* data_ptr);
extern uint16_t FCM_ReportSupportedDTCs (uint8_t* data_ptr);
extern uint8_t FCM_ReportFirstFailedDTC (uint8_t* r, uint16_t *RespLen);
extern uint8_t FCM_ReportMostRecentFailedDTC (uint8_t* data_ptr, uint16_t *RespLen);
extern uint8_t FCM_ReportFirstCnfmdDTC (uint8_t* data_ptr, uint16_t *length);
extern uint8_t FCM_ReportMostRecentCnfmdDTC (uint8_t* data_ptr, uint16_t *RespLen);
extern void FCM_UpdateCntrolDTCSetting (eFCM_ControDTCType DTCControlStat);
extern uint8_t FCM_GetCnfrmdDTCStatusByDTCNumber (uint32_t DTC_Number);
extern uint16_t FCM_AppReportDTCByStatusMask (uint8_t FCM_DTC_StatusMask, uint8_t* data_ptr, const uint16_t* Index_prt);

#endif /* FCM_H */

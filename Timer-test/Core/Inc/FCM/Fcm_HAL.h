/***************************************************************************************************
** Copyright (c) 2023 EMBITEL
**
** This software is the property of EMBITEL.
** It can not be used or duplicated without EMBITEL authorization.
**
** -------------------------------------------------------------------------------------------------
** File Name    : Fcm_HAL.h
** Module name  : 
** -------------------------------------------------------------------------------------------------
** Description : Include file of component FcmHAL.c
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
#ifndef FCM_HAL_H
#define FCM_HAL_H
/**************************************** Inclusion files *****************************************/
#include "Fcm.h"
#include "Fcm_cfg.h"


/********************************* Declaration of macros ************************************/
#define IGNITION_OFF					 0x00u
#define IGNITION_ON						 0x01u

/****************************** Declaration of Global Symbols *************************************/
#define FCM_HAL_IGNITION_STAUS                  IGNITION_ON
/****************************** Declaration of Global Types ***************************************/

/****************************** Declaration of exported variables *********************************/
extern uint8_t PreviousIgnitionStatus;
extern uint8_t FCM_FCM_DTC_InitStatus;
/****************************** Declaration of exported constants *********************************/

/**************************** External functions declarations *************************************/

extern uint8_t HAL_FCM_InitStatus(void);
extern uint8_t HAL_FCM_ReadDTCInfo (FCM_DTC_StatusType * FCM_ReadDTCInfo, uint16_t Size);
extern void HAL_FCM_WriteDTCInfo(const FCM_DTC_StatusType *FCM_WriteDTCInfo,uint16_t Size);
extern void HAL_FCM_ClearReqDTCUpdate(uint16_t FCM_ReqDTCIndx,FCM_DTC_StatusType *FCM_ClearDTCInfo);
extern void HAL_FCM_DTC_StatusChange(uint8_t FCM_DTC_Idx);
extern void HAL_FCM_ClearAllDTC(FCM_DTC_StatusType *FCM_WriteDTCInfo);
extern void HAL_FCM_Read_Snapst_Data(uint16_t FCM_DTC_Ind, uint8_t *DataBuff, uint16_t *BuffLen);

#endif /* FCM_HAL_H */

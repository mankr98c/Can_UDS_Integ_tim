/***************************************************************************************************
** Copyright (c) 2018 EMBITEL
**
** This software is the property of EMBITEL.
** It can not be used or duplicated without EMBITEL authorization.
**
** -------------------------------------------------------------------------------------------------
** File Name    : ISOUDS_RdDaByID_HAL.h
** Module Name  : ISOUDS_RdDaByID
** -------------------------------------------------------------------------------------------------
**
** Description : Include file of component CanSrv_RdDaByID.c
** This file must exclusively contain informations needed to
** use this component.
**
** -------------------------------------------------------------------------------------------------
**
** Documentation reference : EME-17ST013-12211.01(SWLLD CanSrv_RdDaByID)
**
****************************************************************************************************
** R E V I S I O N H I S T O R Y
****************************************************************************************************
** V01.00 16/07/2018
** - Baseline Created
**
***************************************************************************************************/

/* To avoid multi-inclusions */
#ifndef ISOUDS_RDDABYID_HAL_H
#define ISOUDS_RDDABYID_HAL_H

/************************************* Inclusion files ********************************************/
#include "ISOUDS_Server_Cfg.h"
#include "ISOUDS_RdDaByID_Cfg.h"

/************************** Declaration of global symbol and constants ****************************/

/********************************* Declaration of global macros ***********************************/

/********************************* Declaration of global types ************************************/

/****************************** External links of global variables ********************************/

/****************************** External links of global constants ********************************/

/***************************************************************************************************
**                                      FUNCTIONS                                                 **
***************************************************************************************************/

/********************************** Function definitions ******************************************/
extern uint8_t ISOUDS_CheckPreConditions(void);
extern uint8_t ISOUDS_GetNVMReadStatus(void);

extern uint8_t RDBI_EcuStatusMsgCbk(uint8_t buffer[], uint16_t len);
extern uint8_t RDBI_SYMCPartNumCbk(uint8_t buffer[], uint16_t len);
extern uint8_t RDBI_SYMCSoftwareVerCbk(uint8_t buffer[], uint16_t len);
extern uint8_t RDBI_SystemSuppCodeCbk(uint8_t buffer[], uint16_t len);
extern uint8_t RDBI_ECUManufctDateCbk(uint8_t buffer[], uint16_t len);
extern uint8_t RDBI_ECUSerialNUmCbk(uint8_t buffer[], uint16_t len);
extern uint8_t RDBI_VehicleIDNumDataCbk(uint8_t buffer[], uint16_t len);
extern uint8_t RDBI_TesterSerialNumCbk(uint8_t buffer[], uint16_t len);
extern uint8_t RDBI_ProgramDateCbk(uint8_t buffer[], uint16_t len);
extern uint8_t RDBI_DiagnosticInfoCbk(uint8_t buffer[], uint16_t len);
extern uint8_t RDBI_ProgramIdInfoCbk(uint8_t buffer[], uint16_t len);
extern uint8_t RDBI_HardwareVerCbk(uint8_t buffer[], uint16_t len);
extern uint8_t RDBI_CANDBVerCbk(uint8_t buffer[], uint16_t len);
extern uint8_t RDBI_ECUInfoCbk(uint8_t buffer[], uint16_t len);
extern uint8_t RDBI_QRCodeCbk(uint8_t buffer[], uint16_t len);

#endif  /* ISOUDS_RDDABYID_HAL_H */

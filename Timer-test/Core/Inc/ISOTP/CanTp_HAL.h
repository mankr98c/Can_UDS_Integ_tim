/***************************************************************************************************
** Copyright (c) 2020 Embitel
**
** This software is the property of Embitel.
** It can not be used or duplicated without Embitel authorization.
**
** -------------------------------------------------------------------------------------------------
** File Name : ISOTP_HAL.h
** -------------------------------------------------------------------------------------------------
**
** Description : HAL header for ISOTP module.
**
** -------------------------------------------------------------------------------------------------
**
** Documentation reference :
**
****************************************************************************************************
** R E V I S I O N H I S T O R Y
****************************************************************************************************
** V01.00
** - First Version
**
**
***************************************************************************************************/
#ifndef ISOTP_HAL
#define ISOTP_HAL
/************************************* Inclusion files ********************************************/
#include "CanTp.h"
#include <stdint.h>

/*******************************************************************************
** Function                 : ISOTP_HAL_MsgIndi

** Description              : Indicates that a new request has been received

** Parameter isoTpConfPtr   : Pointer to TP configuration structure

** Return value             : None
*******************************************************************************/
extern void ISOTP_HAL_MsgIndi (ISOTP_CfgType *isoTpConfPtr);

/*******************************************************************************
** Function                 : ISOTP_HAL_FFIndi

** Description              : Indicates that the first frame of new request has
							  been received

** Parameter isoTpConfPtr   : Pointer to TP configuration structure

** Return value             : None
*******************************************************************************/
extern void ISOTP_HAL_FFIndi (const ISOTP_CfgType *isoTpConfPtr);

/*******************************************************************************
** Function                 : ISOTP_HAL_TxCnfCbk

** Description              : Confirmation of response sent

** Parameter                : isoTpConfPtr : Pointer to teh transmited frrame

** Return value             : None
*******************************************************************************/
extern void ISOTP_HAL_TxCnfCbk (const ISOTP_CfgType *isoTpConfPtr);

/***************************************************************************************************
** Function                 : ISOTP_HAL_Reset

** Description              : Callback after every reset of ISOTP, Includes successful transmission and timeout.\.

** Parameter rxData         : None

** Return value             : None

** Remarks                  : None
***************************************************************************************************/
extern void ISOTP_HAL_Reset (void);

/***************************************************************************************************
** Function                 : ISOTP_HAL_TimeoutInd

** Description              : Callback after Any TimeOut.\.

** Parameter rxData         : None

** Return value             : None

** Remarks                  : None
***************************************************************************************************/
extern void ISOTP_HAL_TimeoutInd (void);

/*******************************************************************************
** Function                 : ISOTP_HAL_CANMesgTxnReq_Stub

** Description              : Request Transmission Stub for CAN Interface

** Parameter                : MsgId : Message Identifer
** 							: DLC   : Data Length Code
** 							: dataBuff : Pointer to the data buffer

** Return value             : None
*******************************************************************************/
extern void ISOTP_HAL_CANMesgTxnReq_Stub(uint32_t MsgId, uint8_t MesgType, uint8_t DLC,const uint8_t *dataBuff);

#endif

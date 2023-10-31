/***************************************************************************************************
** Copyright (c) 2020 Embitel
**
** This software is the property of Embitel.
** It can not be used or duplicated without Embitel authorization.
**
** -------------------------------------------------------------------------------------------------
** File Name : ISOTP_HAL.c
** -------------------------------------------------------------------------------------------------
**
** Description : HAL sourece for ISOTP module.
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
/************************************* Inclusion files ********************************************/
#include "CanTp_HAL.h"
#include "ISOUDS_Server.h"
#include "ISOUDS_Server_Cfg.h"
#include <stdio.h>
#include "main.h"

extern FDCAN_HandleTypeDef hfdcan3;
extern UART_HandleTypeDef huart7;

extern FDCAN_TxHeaderTypeDef   TxHeader1;
#define debug_uart huart7
/*******************************************************************************
** Function                 : ISOTP_HAL_MsgIndi

** Description              : Indicates that a new request has been received

** Parameter isoTpConfPtr   : Pointer to TP configuration structure

** Return value             : None
*******************************************************************************/
void ISOTP_HAL_MsgIndi (ISOTP_CfgType *isoTpConfPtr)
{
	char buff[100]={0};
	ISOUDS_ServerMsgIndi(isoTpConfPtr->nBytes, isoTpConfPtr->tpBuff, (ISOUDS_AddrType)isoTpConfPtr->ReqType);
	sprintf(buff,"\r\n UDS received \r\n");
	  	HAL_UART_Transmit(&debug_uart, (uint8_t *) buff, sizeof(buff), 100);
	   	memset(buff,0,sizeof(buff));
}

/*******************************************************************************
** Function                 : ISOTP_HAL_FFIndi

** Description              : Indicates that the first frame of new request has
							  been received
a
** Parameter isoTpConfPtr   : Pointer to TP configuration structure

** Return value             : None
*******************************************************************************/
void ISOTP_HAL_FFIndi (const ISOTP_CfgType *isoTpConfPtr)
{
	(void)isoTpConfPtr;
}

/*******************************************************************************
** Function                 : ISOUDS_TxCnfCbk

** Description              : Confirmation of response sent

** Parameter                : None

** Return value             : None
*******************************************************************************/
void ISOTP_HAL_TxCnfCbk (const ISOTP_CfgType *isoTpConfPtr)
{
	(void)isoTpConfPtr;
	ISOUDS_ServerTxCnfCbk();
}

/***************************************************************************************************
** Function                 : ISOTP_HAL_Reset

** Description              : Callback after every reset of ISOTP, Includes successful transmission and timeout.\.

** Parameter rxData         : None

** Return value             : None

** Remarks                  : None
***************************************************************************************************/
void ISOTP_HAL_Reset (void)
{

}

/***************************************************************************************************
** Function                 : ISOTP_HAL_TimeoutInd

** Description              : Callback after Any TimeOut.\.

** Parameter rxData         : None

** Return value             : None

** Remarks                  : None
***************************************************************************************************/
void ISOTP_HAL_TimeoutInd (void)
{
	ISOUDS_ServerRst();
}

/*******************************************************************************
** Function                 : ISOTP_HAL_CANMesgTxnReq_Stub

** Description              : Request Transmission Stub for CAN Interface

** Parameter                : MsgId : Message Identifer
** 							: DLC   : Data Length Code
** 							: dataBuff : Pointer to the data buffer

** Return value             : None
*******************************************************************************/
void ISOTP_HAL_CANMesgTxnReq_Stub(uint32_t MsgId, uint8_t MesgType, uint8_t  DLC,const uint8_t *dataBuff)
{

	uint8_t Indx, data8[8];

	extern FDCAN_TxHeaderTypeDef   TxHeader1;
    (void)MesgType;



      TxHeader1.Identifier = MsgId;
      TxHeader1.IdType = MesgType;
      TxHeader1.TxFrameType = FDCAN_DATA_FRAME;
      TxHeader1.DataLength = FDCAN_DLC_BYTES_8;
      TxHeader1.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
      TxHeader1.BitRateSwitch = FDCAN_BRS_OFF;
      TxHeader1.FDFormat = FDCAN_CLASSIC_CAN;
      TxHeader1.TxEventFifoControl = FDCAN_NO_TX_EVENTS;
      TxHeader1.MessageMarker = 0;

      for(Indx = 0; Indx < DLC; Indx++)
          {
         data8[Indx] = dataBuff[Indx];
          }

   HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan3, &TxHeader1, data8);


}

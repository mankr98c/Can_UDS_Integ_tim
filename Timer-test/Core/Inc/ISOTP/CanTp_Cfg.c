/***************************************************************************************************
** Copyright (c) 2018 Embitel
**
** This software is the property of Embitel.
** It can not be used or duplicated without Embitel.
**
** -------------------------------------------------------------------------------------------------
** File Name    : ISOTP_Cfg.c
** Module name  : Can Transport layer configuration file.
** -------------------------------------------------------------------------------------------------
**
** Description  : Provides configuration of CAN TP layer.
**
** -------------------------------------------------------------------------------------------------
**
** Documentation reference : None
**
****************************************************************************************************
** R E V I S I O N H I S T O R Y
****************************************************************************************************
** V01.00
** - Baseline for CANTP module
**
***************************************************************************************************/

/**************************************** Inclusion files *****************************************/
#include "CanTp.h"
#include <stdint.h>

/********************** Declaration of local symbol and constants *********************************/
/****************************** Declaration of exported variables *********************************/
/****************************** Declaration of exported constants *********************************/
/********************************* Declaration of local macros ************************************/
/********************************* Declaration of local types *************************************/
/******************************* Declaration of local variables ***********************************/
/******************************* Declaration of local constants ***********************************/
uint32_t ISOTP_TxMesgID;
uint8_t ISOTP_TxMesgID_Type;
static uint32_t ISOTP_RxPhysReqID;
static uint32_t ISOTP_RxFuncReqID;
static uint8_t ISOTP_RxPhysReqID_Type;
static uint8_t ISOTP_RxFuncReqID_Type;

/* ISO15765 timeout configuration */
const ISOTP_TimeoutT ISOTP_iTimeOut[ISOTP_TIMEOUT_TAB] =
{
     /* Transmission timeout values */
    {
        (uint32_t)ISOTP_NAS_TIMEOUT_MS,       /* N_As timeout in ms */
        (uint32_t)ISOTP_NBS_TIMEOUT_MS,       /* N_Bs timeout in ms */
        (uint32_t)ISOTP_NCS_TIMEOUT_MS        /* N_Cs timeout in ms */
    },
    /* Reception timeout values */
    {
        (uint32_t)ISOTP_NAR_TIMEOUT_MS,       /* N_Ar timeout in ms */
        (uint32_t)ISOTP_NBR_TIMEOUT_MS,       /* N_Br timeout in ms */
        (uint32_t)ISOTP_NCR_TIMEOUT_MS        /* N_Cr timeout in ms */
    }
};

/***************************************************************************************************
** Function                 : ISOTP_CheckIfLogclChanRespMesg

** Description              : Check logical channel response message

** Parameter                : PhysChanId : Physical channel ID
							: MesgID : Message ID
							: Type : Request message type

** Return value             : RetVal : Success or fail

** Remarks                  : None
***************************************************************************************************/
ISOTP_ReqType ISOTP_CheckReqType(uint32_t MesgID, uint8_t MesgType)
{
	ISOTP_ReqType RetVal = ISOTP_PHYSICALREQ;

	if ((MesgID == ISOTP_RxPhysReqID) && (MesgType == ISOTP_RxPhysReqID_Type))
	{
		RetVal = ISOTP_PHYSICALREQ;
	}
	else if	((MesgID == ISOTP_RxFuncReqID) && (MesgType == ISOTP_RxFuncReqID_Type))
	{
		RetVal = ISOTP_FUNCTIONALREQ;
	}
	else
	{
		/* Do nothing */
	}

	return RetVal;
}

/***************************************************************************************************
** Function                 : ISOTP_CheckIfLogclChanRespMesg

** Description              : Check logical channel response message

** Parameter                : PhysChanId : Physical channel ID
							: MesgID : Message ID
							: Type : Request message type

** Return value             : RetVal : Success or fail

** Remarks                  : None
***************************************************************************************************/
uint8_t ISOTP_CheckRxMesgID(uint32_t MesgID, uint8_t MesgType)
{
	uint8_t RetVal = ISOTP_FALSE;

	if (((MesgID == ISOTP_RxPhysReqID) && (MesgType == ISOTP_RxPhysReqID_Type)) ||
		((MesgID == ISOTP_RxFuncReqID) && (MesgType == ISOTP_RxFuncReqID_Type)))
	{
		RetVal = ISOTP_TRUE;
	}

	return RetVal;
}

/***************************************************************************************************
** Function                 : ISOTP_CheckIfLogclChanReqMesg

** Description              : Check logical channel response message

** Parameter                : PhysChanId : Physical channel ID
							: MesgID : Message ID
							: Type : Request message type

** Return value             : RetVal : Success or fail

** Remarks                  : None
***************************************************************************************************/
uint8_t ISOTP_CheckTxMesgID(uint32_t MesgID, uint8_t MesgType)
{
	uint8_t RetVal = ISOTP_FALSE;

	if ((MesgID == ISOTP_TxMesgID) && (MesgType == ISOTP_TxMesgID_Type))
	{
		RetVal = ISOTP_TRUE;
	}

	return RetVal;
}

/***************************************************************************************************
** Function                 : ISOTP_CheckIfLogclChanRespMesg

** Description              : Check logical channel response message

** Parameter                : PhysChanId : Physical channel ID
							: MesgID : Message ID
							: Type : Request message type

** Return value             : RetVal : Success or fail

** Remarks                  : None
***************************************************************************************************/
void ISOTP_SetRxPhysReqID(uint32_t MesgID, uint8_t MesgType)
{
	ISOTP_RxPhysReqID = MesgID;
	ISOTP_RxPhysReqID_Type = MesgType;
}

/***************************************************************************************************
** Function                 : ISOTP_CheckIfLogclChanRespMesg

** Description              : Check logical channel response message

** Parameter                : PhysChanId : Physical channel ID
							: MesgID : Message ID
							: Type : Request message type

** Return value             : RetVal : Success or fail

** Remarks                  : None
***************************************************************************************************/
void ISOTP_SetRxFuncReqID(uint32_t MesgID, uint8_t MesgType)
{
	ISOTP_RxFuncReqID = MesgID;
	ISOTP_RxFuncReqID_Type = MesgType;
}

/***************************************************************************************************
** Function                 : ISOTP_CheckIfLogclChanReqMesg

** Description              : Check logical channel response message

** Parameter                : PhysChanId : Physical channel ID
							: MesgID : Message ID
							: Type : Request message type

** Return value             : RetVal : Success or fail

** Remarks                  : None
***************************************************************************************************/
void ISOTP_SetTxmesgMesgID(uint32_t MesgID, uint8_t MesgType)
{
	ISOTP_TxMesgID = MesgID;
	ISOTP_TxMesgID_Type = MesgType;
}

/***************************************************************************************************
** Function                 : ISOTP_GetSchedPeriod

** Description              : Get Scheduler Periodicity

** Parameter                : None

** Return value             : Scheduler Periodicity

** Remarks                  : None
***************************************************************************************************/
uint32_t ISOTP_GetSchedPeriod(void)
{
	/* return Periodicity */
	return ISOTP_PERIOD_SCHED;
}

/***************************************************************************************************
** Function                 : ISOTP_GetFCSTMIN

** Description              : Get Flow control minimum segmentation time 

** Parameter                : None

** Return value             : Flow control minimum segmentation time

** Remarks                  : None
***************************************************************************************************/
uint32_t ISOTP_GetFCSTMIN(void)
{
	/* return Flow control minimum segmentation time */
	return ISOTP_FCSTMIN;
}

/***************************************************************************************************
** Function                 : ISOTP_GetPADVal

** Description              : Get Padding data value

** Parameter                : None

** Return value             : Padding data value 

** Remarks                  : None
***************************************************************************************************/
uint8_t ISOTP_GetPADVal(void)
{
	/* return Padding data value */
	return ISOTP_PADDATA_VAL;
}

/***************************************************************************************************
** Function                 : ISOTP_GetFCBS

** Description              : Get Flow control block size 

** Parameter                : None

** Return value             : Flow control block size 

** Remarks                  : None
***************************************************************************************************/
uint8_t ISOTP_GetFCBS(void)
{
	/* return Flow control block size */
	return ISOTP_FCBS;
}

/***************************************************************************************************
** Function                 : ISOTP_GetFCBS

** Description              : Get iso15765 buffer size

** Parameter                : None

** Return value             : buffer size 

** Remarks                  : None
***************************************************************************************************/
uint32_t ISOTP_GetBUFFSIZE(void)
{
	/* return iso15765 buffer size */
	return ISOTP_BUFFSIZE;
}

/***************************************************************************************************
** Function                 : ISOTP_ST_PADDING

** Description              : Get Padding related values

** Parameter                : None

** Return value             : buffer size 

** Remarks                  : None
***************************************************************************************************/
uint8_t ISOTP_STPadding(void)
{
	/* return iso15765 buffer size */
	return ISOTP_ST_PADDING;
}




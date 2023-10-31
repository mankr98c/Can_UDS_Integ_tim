/*******************************************************************************
** Copyright (c) 2018 Embitel
**
** This software is the property of Embitel .
** It can not be used or duplicated without Embitel authorization .
**
** -----------------------------------------------------------------------------
** File Name   : ISOUDS_RdDTCInf_HAL.c
** Module Name : UDS
** -----------------------------------------------------------------------------
**
** Description : This service Reads DTC Information
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

/**************************************** Inclusion files *********************/
#include "ISOUDS_RdDTCInf.h"
#include "ISOUDS_RdDTCInf_HAL.h"
#include "Fcm.h"
#include "Fcm_cfg.h"

#if (ISOUDS_APP_CONFIG == ISOUDS_SERVER)
/************************** Declaration of local symbol and constants *********/

/********************************* Declaration of local macros ****************/

/********************************* Declaration of local types *****************/

/******************************* Declaration of local variables ***************/

/******************************* Declaration of local constants ***************/

/****************************** Declaration of exported variables *************/

/****************************** Declaration of exported constants *************/

/*******************************************************************************
**                                      FUNCTIONS                              *
*******************************************************************************/

/**************************** Internal functions declarations *****************/

/******************************** Function definitions ************************/

/*******************************************************************************
** Function                 : HAL_RdDTCPreCondCheck

** Description              : API to check preconditions

** Parameter                : None

** Return value             : ISOUDS_TRUE or ISOUDS_FALSE
*******************************************************************************/
uint8_t HAL_RdDTCPreCondCheck(void)
{
	uint8_t RetVal;
	/*User specific implementation*/
	RetVal = ISOUDS_TRUE;
	return RetVal;
}

/*******************************************************************************
** Function                 : HAL_RdTDCInf_reportNumberOfDTCByStatusMask
**
** Description              : API to reportNumberOfDTCByStatusMask
**
** Parameters 				: RespLen : Length of data copied
**            				: dataBuff : diagnostic Data Buffer
** Return value             : RespVal : Response Type. refer ISOUDS_Server.h file
*******************************************************************************/
uint8_t HAL_RdTDCInf_reportNumberOfDTCByStatusMask(uint8_t *RdDTCStatusAvailabilityMask, uint8_t *DTCFormatIdentifier,uint16_t *DTCCount)
{
	uint8_t RespVal;

	RespVal = ISOUDS_POSRES;
    /*User specific implementation*/

	*DTCCount = FCM_ReportNoOfDTCByStatusMask(*RdDTCStatusAvailabilityMask & FCM_SUPPORTED_DTC_STATUS_BITS);/*DTCCount*/
	*RdDTCStatusAvailabilityMask = FCM_SUPPORTED_DTC_STATUS_BITS;/*DTCStatusAvailabilityMask*/
	*DTCFormatIdentifier = 0x01;/*DTCFormatIdentifier*/

	return RespVal;

}

/*******************************************************************************
** Function                 : HAL_RdTDCInf_reportDTCByStatusMask
**
** Description              : API to reportDTCByStatusMask
**
** Parameters 				: RespLen : Length of data copied
**            				: dataBuff : diagnostic Data Buffer
** Return value             : RespVal : Response Type. refer ISOUDS_Server.h file
*******************************************************************************/
uint8_t HAL_RdTDCInf_reportDTCByStatusMask(uint8_t *RdDTCStatusAvailabilityMask, uint8_t *Data, uint16_t *RespLen)
{
	uint8_t RespVal;
	RespVal = ISOUDS_POSRES;
	
	/*User specific code*/
	*RespLen += FCM_ReportDTCByStatusMask(*RdDTCStatusAvailabilityMask & FCM_SUPPORTED_DTC_STATUS_BITS, Data);
	
	*RdDTCStatusAvailabilityMask = FCM_SUPPORTED_DTC_STATUS_BITS;

	return RespVal;
}

/*******************************************************************************
** Function                 : HAL_RdTDCInf_reportDTCSnapshotRecordByDTCNumber
**
** Description              : API to reportDTCSnapshotRecordByDTCNumber
**
** Parameters 				: RespLen : Length of data copied
**            				: dataBuff : diagnostic Data Buffer
** Return value             : RespVal : Response Type. refer ISOUDS_Server.h file
*******************************************************************************/
uint8_t HAL_RdTDCInf_reportDTCSnapshotRecordByDTCNumber(uint32_t *DTCMaskRecord,uint8_t *DTCSnapshotRecordNumber,uint8_t *StatMask, uint8_t *Data, uint16_t *Resplen)
{
	uint8_t RespVal = ISOUDS_POSRES;
	uint8_t RetVal;
	(void)StatMask;
	

	RetVal = FCM_GetDTCSnpShotRecdByDTCnum(*DTCMaskRecord, *DTCSnapshotRecordNumber, Data, Resplen);

	if (ISOUDS_TRUE == RetVal)
	{
		RespVal = ISOUDS_POSRES;
	}
	else
	{
		RespVal = ISOUDS_ROOR;
	}
	return RespVal;
}

/*******************************************************************************
** Function                 : HAL_RdTDCInf_reportSupportedDTC
**
** Description              : API to reportSupportedDTC
**
** Parameters 				: Rpt_SuppDTC_RespLen : Length of data copied
**            				: dataBuff : diagnostic Data Buffer
** Return value             : RespVal : Response Type. refer ISOUDS_Server.h file
*******************************************************************************/
uint8_t HAL_RdTDCInf_reportSupportedDTC(uint8_t * Data,uint16_t *Rpt_SuppDTC_RespLen)
{
	uint8_t RespVal;

	RespVal = ISOUDS_POSRES;
	
	Data[ISOUDS_ZERO] = FCM_SUPPORTED_DTC_STATUS_BITS;
	Rpt_SuppDTC_RespLen[ISOUDS_ZERO] += ISOUDS_ONE;
	Rpt_SuppDTC_RespLen[ISOUDS_ZERO] += FCM_ReportSupportedDTCs(&Data[ISOUDS_ONE]);
	
	return RespVal;
}


#endif

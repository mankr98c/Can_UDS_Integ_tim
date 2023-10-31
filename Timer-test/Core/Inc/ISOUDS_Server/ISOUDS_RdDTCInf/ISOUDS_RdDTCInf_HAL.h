/*******************************************************************************
** Copyright (c) 2018 Embitel
**
** This software is the property of Embitel.
** It can not be used or duplicated without Embitel authorization .
**
** -----------------------------------------------------------------------------
** File Name   : ISOUDS_RdDTCInf_HAL.h
** Module Name : UDS
** -----------------------------------------------------------------------------
**
** Description : Include component of ISOUDS_RdDTCInf.c
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
#ifndef ISOUDS_RDDTCINF_HAL_H
#define ISOUDS_RDDTCINF_HAL_H
/************************************* Inclusion files ************************/
#include "ISOUDS_Server_Cfg.h"
#include "ISOUDS_RdDTCInf_Cfg.h"
/************************** Declaration of global symbol and constants ********/

/********************************* Declaration of global macros ***************/
/********************************* Declaration of global types ****************/

/****************************** External links of global variables ************/

/****************************** External links of global constants ************/

/*******************************************************************************
**                                      FUNCTIONS                              *
*******************************************************************************/

/********************************** Function definitions **********************/
extern uint8_t HAL_RdDTCPreCondCheck(void);
extern uint8_t HAL_RdTDCInf_reportNumberOfDTCByStatusMask( uint8_t *RdDTCStatusAvailabilityMask, uint8_t *DTCFormatIdentifier,uint16_t *DTCCount);
extern uint8_t HAL_RdTDCInf_reportDTCByStatusMask(uint8_t *RdDTCStatusAvailabilityMask, uint8_t *Data, uint16_t *RespLen);
extern uint8_t HAL_RdTDCInf_reportDTCSnapshotRecordByDTCNumber(uint32_t *DTCMaskRecord,uint8_t *DTCSnapshotRecordNumber,uint8_t *StatMask, uint8_t *Data, uint16_t *Resplen);
extern uint8_t HAL_RdTDCInf_reportSupportedDTC(uint8_t * Data,uint16_t *Rpt_SuppDTC_RespLen);


#endif  /* ISOUDS_RDDTCINF_HAL_H */

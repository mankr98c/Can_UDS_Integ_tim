/*******************************************************************************
** Copyright (c) 2018 Embitel
**
** This software is the property of Embitel.
** It can not be used or duplicated without Embitel authorization .
**
** -----------------------------------------------------------------------------
** File Name   : ISOUDS_RdDTCInf.h
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
#ifndef ISOUDS_RDDTCINF_H
#define ISOUDS_RDDTCINF_H
/************************************* Inclusion files ************************/
#include "ISOUDS_Server.h"
#include "ISOUDS_RdDTCInf_Cfg.h"
/************************** Declaration of global symbol and constants ********/

/********************************* Declaration of global macros ***************/

/********************************* Declaration of global types ****************/
/* SID of Read Diagnostic Information session service */
#define     ISOUDS_SIDRDDTCINF      (0x19U)
#define		ISOUDS_RDDTCLEN			(0x01U)

/****************************** External links of global variables ************/

/****************************** External links of global constants ************/

/*******************************************************************************
**                                      FUNCTIONS                              *
*******************************************************************************/

/********************************** Function definitions **********************/
extern void ISOUDS_RdDTCInf (ISOUDS_ConfType *ISOUDSConfPtr, uint8_t dataBuff[]);

#endif  /* ISOUDS_RDDTCINF_H */

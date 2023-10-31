/***************************************************************************************************
** Copyright (c) 2018 Embitel
**
** This software is the property of Embitel.
** It can not be used or duplicated without Embitel authorization.
**
** -----------------------------------------------------------------------------
** File Name   : ISOUDS_ReqFileTransfer.h
** Module Name : UDS
** -----------------------------------------------------------------------------
**
** Description : Include file component for ISOUDS_ReqFileTransfer.c
**
** -----------------------------------------------------------------------------
**
** Documentation reference :
**
****************************************************************************************************
** R E V I S I O N H I S T O R Y
****************************************************************************************************
** V01.00
** - Baseline for UDS module
**
***************************************************************************************************/
/* To avoid multi-inclusions */
#ifndef ISOUDS_REQFILETRANSFER_H
#define ISOUDS_REQFILETRANSFER_H

/************************************* Inclusion files ********************************************/
#include "ISOUDS_Server.h"
#include "ISOUDS_SA.h"
#include "ISOUDS_ReqFileTransferCfg.h"
/************************** Declaration of global symbol and constants ****************************/

/********************************* Declaration of global macros ***********************************/

/********************************* Declaration of global types ************************************/
/* SID of Request File Transfer service */
#define ISOUDS_SIDREQFILETRNSFR		((uint8_t)0x38)
/* Response SID of Request File Transfer service */
#define ISOUDS_REQFILETRNSFR_RES	((uint8_t)0x78)
/* length (number of bytes) of the maxNumberOfBlockLength */
#define LENGTHFORMATIDENTIFIER	((uint8_t)0x02)

#define ADDFILE					((uint8_t)0x01)
#define DELETEFILE				((uint8_t)0x02)
#define REPLACEFILE     		((uint8_t)0x03)
#define READFILE        		((uint8_t)0x04)
#define READDIR         		((uint8_t)0x05)

#define CBK_RSP_SUCCESS						0U
#define CBK_RSP_PEND						1U
#define CBK_RSP_FAILURE						2U

/****************************** External links of global variables ********************************/

/****************************** External links of global constants ********************************/

/***************************************************************************************************
**                                      		FUNCTIONS              			                   *
***************************************************************************************************/

/********************************** Function definitions ******************************************/
extern void ISOUDS_ReqFileTransfer(ISOUDS_ConfType *ISOUDSConfPtr, uint8_t dataBuff[]);

#endif  /* _ISOUDS_REQFILETRANSFER_H_ */

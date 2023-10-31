/*******************************************************************************
** Copyright (c)
**
** This software is the property of Embitel .
** It can not be used or duplicated without Embitel authorization .
**
** -----------------------------------------------------------------------------
** File Name   : ISOUDS_RdMemByAddr.h
** Module Name : UDS
** -----------------------------------------------------------------------------
**
** Description :
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
#ifndef ISOUDS_RDMEMBYADDR_H
#define ISOUDS_RDMEMBYADDR_H

/************************************* Inclusion files ********************************************/
#include "ISOUDS_Server.h"

/************************** Declaration of global symbol and constants ****************************/

/********************************* Declaration of global macros ***********************************/

/********************************* Declaration of global types ************************************/
/* SID of Read Memory By Address service */
#define     ISOUDS_SIDRDMEMBYADDR        (0x23)

/****************************** External links of global variables ********************************/

/****************************** External links of global constants ********************************/

/***************************************************************************************************
**                                      FUNCTIONS                                                 **
***************************************************************************************************/

/********************************** Function definitions ******************************************/
extern void ISOUDS_RdMemByAddr (ISOUDS_ConfType *ISOUDSConfPtr, uint8_t dataBuff[]);

#endif  /* ISOUDS_RDMEMBYADDR_H */

/*******************************************************************************
** Copyright (c)
**
** This software is the property of Embitel .
** It can not be used or duplicated without Embitel authorization .
**
** -----------------------------------------------------------------------------
** File Name   : ISOUDS_ReqUpld.h
** Module Name : UDS
** -----------------------------------------------------------------------------
**
** Description : Include file of component ISOUDS_ReqDwnld.c
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
#ifndef ISOUDS_REQUPLD_H
#define ISOUDS_REQUPLD_H

/************************************* Inclusion files ********************************************/
#include "ISOUDS_ReqUpld_Cfg.h"
/************************** Declaration of global symbol and constants ****************************/

/********************************* Declaration of global macros ***********************************/

/********************************* Declaration of global types ************************************/
/* SID of Request Upload service */
#define     ISOUDS_SIDREQUPLD  (0x35)

/****************************** External links of global variables ********************************/

/****************************** External links of global constants ********************************/

/***************************************************************************************************
**                                      FUNCTIONS                                                 **
***************************************************************************************************/

/********************************** Function definitions ******************************************/
extern void ISOUDS_ReqUpld (ISOUDS_ConfType *ISOUDSConfPtr, uint8_t dataBuff[]);

#endif  /* ISOUDS_REQUPLD_H */

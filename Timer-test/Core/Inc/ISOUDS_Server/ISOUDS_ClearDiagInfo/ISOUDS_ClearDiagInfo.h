/*******************************************************************************
** Copyright (c) 2018 Embitel
**
** This software is the property of Embitel .
** It can not be used or duplicated without Embitel authorization .
**
** -----------------------------------------------------------------------------
** File Name   : ISOUDS_ClearDiagInfo.h
** Module Name : UDS
** -----------------------------------------------------------------------------
**
** Description : This service Clears DTCs
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
#ifndef ISOUDS_CLRDTC_H
#define ISOUDS_CLRDTC_H

/************************************* Inclusion files ************************/
#include "ISOUDS_Server_Cfg.h"
#include "ISOUDS_Server.h"
#include "ISOUDS_ClearDiagInfo_Cfg.h"

/************************** Declaration of global symbol and constants ********/

/********************************* Declaration of global macros ***************/

/********************************* Declaration of global types ****************/
/* SID of Start Clear Diagnostic information service */
#define     ISOUDS_SIDCLEARDIAGINFO      (0x14)
/****************************** External CANks of global variables ************/

/****************************** External CANks of global constants ************/

/*******************************************************************************
**                                      FUNCTIONS                              *
*******************************************************************************/

/********************************** Function definitions **********************/
extern void ISOUDS_ClearDiagInfo (ISOUDS_ConfType *ISOUDSConfPtr,uint8_t dataBuff[]);

#endif  /* ISOUDS_CLRDTC_H */

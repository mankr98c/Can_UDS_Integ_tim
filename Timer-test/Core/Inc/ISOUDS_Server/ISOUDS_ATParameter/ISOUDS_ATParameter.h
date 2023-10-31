/***************************************************************************************************
** Copyright (c) 2018 EMBITEL
**
** This software is the property of EMBITEL .
** It can not be used or duplicated without EMBITEL authorization .
**
** -------------------------------------------------------------------------------------------------
** File Name   : ISOUDS_AccessTimingParameter.h
** Module Name : UDS
** -------------------------------------------------------------------------------------------------
**
** Description : Access Timing Parameter Service
**
** -------------------------------------------------------------------------------------------------
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
#ifndef ISOUDS_ACCESSTIMINGPARAMETER_H
#define ISOUDS_ACCESSTIMINGPARAMETER_H

/************************************* Inclusion files ********************************************/
#include "ISOUDS_Server.h"

/************************** Declaration of global symbol and constants ****************************/
/* SID of Access Timing Parameter service */
#define     ISOUDS_SIDATPARAMETER        (0x83U)

/********************************* Declaration of global macros ***********************************/

/********************************* Declaration of global types ************************************/

/****************************** External CANks of global variables ********************************/

/****************************** External CANks of global constants ********************************/

/***************************************************************************************************
**                                      FUNCTIONS                              					   *
***************************************************************************************************/

/********************************** Function definitions ******************************************/
extern void ISOUDS_ATParameter (ISOUDS_ConfType *ISOUDSConfPtr, uint8_t dataBuff[]);

#define MSEC_4 	(uint8_t)4

#endif  /* _ISOUDS_ACCESSTIMINGPARAMETER_H_ */

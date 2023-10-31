/*******************************************************************************
** Copyright (c) 2018 Embitel
**
** This software is the property of Embitel .
** It can not be used or duplicated without Embitel authorization .
**
** -----------------------------------------------------------------------------
** File Name   : ISOUDS_WrDaByID.h
** Module Name : UDS
** -----------------------------------------------------------------------------
**
** Description : Include file of component ISOUDS_WrDaByID.c
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
#ifndef ISOUDS_WRDABYID_H
#define ISOUDS_WRDABYID_H

/****************************** Inclusion files *******************************/
#include <ISOUDS_WrDaByID_Cfg.h>

/******************* Declaration of global symbol and constants ***************/

/************************ Declaration of global macros ************************/

/************************* Declaration of global types ************************/
/* SID of Write Data By Identifier service */
#define     ISOUDS_SIDWRDABYID        (0x2EU)

/*********************** External links of global variables *******************/

/************************ External links of global constants ******************/

/*******************************************************************************
**                                 FUNCTIONS                                   *
*******************************************************************************/

/**************************** Function definitions ****************************/

/*******************************************************************************
** Function                 : ISOUDS_WrDaByID

** Description              : Sends response to Write Data by ID service request

** Parameter ISOUDSConfPtr : Pointer to service configuration structure

** Parameter dataBuff       : Pointer to service data buffer

** Return value             : None
*******************************************************************************/
extern void ISOUDS_WrDaByID (ISOUDS_ConfType *ISOUDSConfPtr, uint8_t dataBuff[]);

#endif  /* _ISOUDS_WRDABYID_H_ */

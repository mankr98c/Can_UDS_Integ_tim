/*******************************************************************************
** Copyright (c) 2018 Embitel
**
** This software is the property of Embitel .
** It can not be used or duplicated without Embitel authorization .
**
** -----------------------------------------------------------------------------
** File Name   : ISOUDS_IOCtrlByID.h
** Module Name : UDS
** -----------------------------------------------------------------------------
**
** Description : Include file of component ISOUDS_IOCtrlByID.c
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
#ifndef ISOUDS_IOCTRLBYID_H
#define ISOUDS_IOCTRLBYID_H

/************************************* Inclusion files ************************/

/************************** Declaration of global symbol and constants ********/

/********************************* Declaration of global macros ***************/

/********************************* Declaration of global types ****************/
/* SID of Input Output Control By Identifier service */
#define     ISOUDS_SIDIOCTRLBYID        (0x2FU)
/* Minimum Service length of IO Control By Identifier service */
#define	ISOUDS_IOSRVLEN     (0x05U)

/****************************** External links of global variables ************/

/****************************** External links of global constants ************/

/*******************************************************************************
**                                      FUNCTIONS                              *
*******************************************************************************/

/********************************** Function definitions **********************/
extern void ISOUDS_IOCtrlByID (ISOUDS_ConfType *ISOUDSConfPtr, \
															uint8_t dataBuff[]);

#endif  /* _ISOUDS_IOCTRLBYID_H_ */

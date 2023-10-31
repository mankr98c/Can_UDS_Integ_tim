/*******************************************************************************
** Copyright (c) 2018 Embitel
**
** This software is the property of Embitel .
** It can not be used or duplicated without Embitel authorization .
**
** -----------------------------------------------------------------------------
** File Name   : ISOUDS_RtnCtrl.h
** Module Name : UDS
** -----------------------------------------------------------------------------
**
** Description : Include file of component ISOUDS_RtnCtrl.c
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
#ifndef ISOUDS_RTNCTRL_H
#define ISOUDS_RTNCTRL_H

/************************************* Inclusion files ************************/

/************************** Declaration of global symbol and constants ********/

/********************************* Declaration of global macros ***************/

/********************************* Declaration of global types ****************/
/* SID of Input Output Control By Identifier service */
#define     ISOUDS_SIDRTNCNTRLID        (0x31U)
/* Minimum Service length of Routine Control service */
#define	ISOUDS_RTNCNTRLSERLEN     (0x04U)

/****************************** External links of global variables ************/

/* Diagnostic Device request to start routine execution successful */
/* Start Routine */
#define     ISOUDS_STARTROUTINE     ((uint8_t)1)
/* Stop Routine */
#define     ISOUDS_STOPROUTINE      ((uint8_t)2)
/* Req Results Routine */
#define     ISOUDS_REQRESROUTINE    ((uint8_t)3)




/****************************** External links of global constants ************/

/*******************************************************************************
**                                      FUNCTIONS                              *
*******************************************************************************/

/********************************** Function definitions **********************/
extern void ISOUDS_RtnCntrl (ISOUDS_ConfType *ISOUDSConfPtr, \
															uint8_t dataBuff[]);

#endif  /* _ISOUDS_RTNCTRL_H_ */

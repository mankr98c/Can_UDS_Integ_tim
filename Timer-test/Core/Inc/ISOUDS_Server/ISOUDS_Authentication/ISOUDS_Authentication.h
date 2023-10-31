/*******************************************************************************
** Copyright (c) 2020 Embitel
**
** This software is the property of Embitel .
** It can not be used or duplicated without Embitel authorization .
**
** -----------------------------------------------------------------------------
** File Name   : ISOUDS_Authentication.h
** Module Name : UDS
** -----------------------------------------------------------------------------
**
** Description : Include file of component ISOUDS_Authentication.c
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
#ifndef ISOUDS_AUTHNTCTN_H
#define ISOUDS_AUTHNTCTN_H

/************************************* Inclusion files ************************/
#include "ISOUDS_Server.h"
/************************** Declaration of global symbol and constants ********/

/********************************* Declaration of global macros ***************/

/********************************* Declaration of global types ****************/
/* SID of Authentication service */
#define ISOUDS_SIDAUTHNTCTNID  		(0x29U)
/* Minimum Service length of Authentication service */
#define	ISOUDS_AUTHNTCTNSERLEN     	(0x02U)

#define ISOUDS_DEAUTHENTICATED		(0x00U)
#define ISOUDS_AUTHENTICATED	   	(0x01U)



/****************************** External links of global variables ************/

/****************************** External links of global constants ************/

/*******************************************************************************
**                                      FUNCTIONS                              *
*******************************************************************************/

/********************************** Function definitions **********************/

/*******************************************************************************
** Function                 : ISOUDS_AUTHENInit

** Description              : Initialize the Authetication Service

** Parameter 				: None 

** Return value             : None
*******************************************************************************/
extern void ISOUDS_AUTHENInit(void);


/*******************************************************************************
** Function                 : ISOUDS_Authnticatn

** Description              : Sends response to Authentication service request

** Parameter ISOUDSConfPtr  : Pointer to service configuration structure

** Parameter dataBuff       : Data array

** Return value             : None
*******************************************************************************/
extern void ISOUDS_Authnticatn (ISOUDS_ConfType *ISOUDSConfPtr, \
															uint8_t dataBuff[]);
															
/*******************************************************************************
** Function                 : ISOUDS_AuthStateMachine

** Description              : State machine for Authentication

** Parameter ISOUDSConfPtr  : Pointer to service configuration structure

** Parameter dataBuff       : Data array

** Return value             : None
*******************************************************************************/
extern void ISOUDS_AuthStateMachine(ISOUDS_ConfType *ISOUDSConfPtr, uint8_t dataBuff[]);


/***************************************************************************************************
** Function                 : ISOUDS_AUTHENChkTimer

** Description              : Check Timers after Authentication

** Parameter ISOUDSConfPtr  : void

** Parameter dataBuff       : void

** Return value             : None
***************************************************************************************************/
extern void ISOUDS_AUTHENChkTimer (void);

/*******************************************************************************
** Function                 : ISOUDS_AUTHENReset

** Description              : Reset the Authetication Service

** Parameter 				: None 

** Return value             : None
*******************************************************************************/
extern void ISOUDS_AUTHENReset(void);

/*******************************************************************************
** Function                 : ISOUDS_GetAAUTHENTICATEStatus

** Description              :Get the Authentication Status

** Parameter 				: None

** Return value             : Status
*******************************************************************************/
extern uint8_t ISOUDS_GetAAUTHENTICATEStatus(void);

/*******************************************************************************
** Function                 : ISOUDS_RestrtAuthTime

** Description              :Restart the Authentication timer

** Parameter 				: None

** Return value             : None
*******************************************************************************/
extern void ISOUDS_RestrtAuthTime(void);

#endif  /* _ISOUDS_RTNCTRL_H_ */

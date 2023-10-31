/*******************************************************************************
**
** -----------------------------------------------------------------------------
** File Name    : ISOUDS_CommCntrl.h
**
** Description  : Include component of ISOUDS_CommCntrl.c
**
** -----------------------------------------------------------------------------
**
*******************************************************************************/

/* To avoid multi-inclusions */
#ifndef ISOUDS_COMMCNTRL_H
#define ISOUDS_COMMCNTRL_H

/************************************* Inclusion files ************************/
#include "ISOUDS_Server.h"

/************************** Declaration of global symbol and constants ********/
/* SID of Communication Control service */
#define     ISOUDS_SIDCOMMCNTRL			(0x28)

#define		ISOUDS_SUBFUN_MASK			(0x7F)

#define		ISOUDS_POSRESP_MASK			(0x80)

#define		ISOUDS_NCM           		(uint8_t)1  /* Network Comm Messages */
#define		ISOUDS_NWMCM         		(uint8_t)2  /* Netwrok Mgmt Comm Messages */
#define		ISOUDS_NWMCMANCM     		(uint8_t)3  /* Network comm and Mgmt Comm
													 messages */
#define   	ISOUDS_CMMCNTRLSERLEN    	(3)   /* Service Length */
#define   	ISOUDS_CMMCNTRLSERRSPLEN    (2)   /* Service Response Length */

/********************************* Declaration of global macros ***************/

/********************************* Declaration of global types ****************/

/****************************** External CANks of global variables ************/

/****************************** External CANks of global constants ************/

/*******************************************************************************
**                                      FUNCTIONS                              *
*******************************************************************************/

/********************************** Function definitions **********************/
/*******************************************************************************
** Function                 : ISOUDS_CommCntrl
**
** Description              : Communication Control
**
** Parameters 				: ISOUDSConfPtr  : Pointer to service configuration structure
**							  dataBuff       : Pointer to service data buffer
**
** Return value             : None
*******************************************************************************/
extern void ISOUDS_CommCntrl (ISOUDS_ConfType *ISOUDSConfPtr, uint8_t dataBuff[]);

/*******************************************************************************
** Function                 : ISOUDS_ComContInit
**
** Description              : Communication Control Initialization
**
** Parameters 				: None
**
** Return value             : None
*******************************************************************************/
extern void ISOUDS_ComContInit(void);

#endif  /* ISOUDS_COMMCNTRL_H */

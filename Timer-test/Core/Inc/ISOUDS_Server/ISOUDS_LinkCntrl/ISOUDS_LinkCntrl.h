/*******************************************************************************
**
** -----------------------------------------------------------------------------
** File Name    : ISOUDS_LinkCntrl.h
**
** Description  : Include component of ISOUDS_LinkCntrl.c
**
** -----------------------------------------------------------------------------
**
*******************************************************************************/

/* To avoid multi-inclusions */
#ifndef ISOUDS_LINKCNTRL_H
#define ISOUDS_LINKCNTRL_H

/************************************* Inclusion files ************************/
#include "ISOUDS_Server.h"

/************************** Declaration of global symbol and constants ********/

/********************************* Declaration of global macros ***************/
/* SID of Link Control service */
#define     ISOUDS_SIDLINKCNTRLID        (0x87U)

#define		ISOUDS_SUBFUN_MASK			(0x7F)

#define		ISOUDS_POSRESP_MASK			(0x80)

#define   	ISOUDS_LINKCNTRLSERLEN    	(3)   /* Service Length */
#define   	ISOUDS_LINKCNTRLSERRSPLEN    (2)   /* Service Response Length */

/********************************* Declaration of global types ****************/

/****************************** External CANks of global variables ************/

/****************************** External CANks of global constants ************/

/*******************************************************************************
**                                      FUNCTIONS                              *
*******************************************************************************/

/********************************** Function definitions **********************/
/*******************************************************************************
** Function                 : ISOUDS_LinkCntrl
**
** Description              : Link Control
**
** Parameters 				: ISOUDSConfPtr  : Pointer to service configuration structure
**							  dataBuff       : Pointer to service data buffer
**
** Return value             : None
*******************************************************************************/
extern void ISOUDS_LinkCntrl (ISOUDS_ConfType *ISOUDSConfPtr, uint8_t dataBuff[]);

/*******************************************************************************
** Function                 : ISOUDS_LinkCntrlInit
**
** Description              : Link Control Initialization
**
** Parameters 				: None
**
** Return value             : None
*******************************************************************************/
extern void ISOUDS_LinkCntrlInit (void);


#endif  /* ISOUDS_COMMCNTRL_H */

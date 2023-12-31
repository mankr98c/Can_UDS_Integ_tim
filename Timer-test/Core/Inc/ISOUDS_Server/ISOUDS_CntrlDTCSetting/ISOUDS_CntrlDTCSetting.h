/*******************************************************************************
**
** -----------------------------------------------------------------------------
** File Name    : ISOUDS_CntrlDTCSetting.h
**
** Description  : Include component of ISOUDS_CntrlDTCSetting.c
**
** -----------------------------------------------------------------------------
**
*******************************************************************************/

/* To avoid multi-inclusions */
#ifndef ISOUDS_CNTRLDTCSETTING_H
#define ISOUDS_CNTRLDTCSETTING_H

/************************************* Inclusion files ************************/
#include "ISOUDS_Server.h"

/************************** Declaration of global symbol and constants ********/
/* SID of Control DTC service */
#define     ISOUDS_SIDCNTRLDTCSET        (uint8_t)(0x85)

/********************************* Declaration of global macros ***************/

/********************************* Declaration of global types ****************/

/****************************** External CANks of global variables ************/

/****************************** External CANks of global constants ************/

/*******************************************************************************
**                                      FUNCTIONS                              *
*******************************************************************************/

/********************************** Function definitions **********************/
extern void ISOUDS_CntrlDTCSetting(ISOUDS_ConfType *ISOUDSConfPtr,
									uint8_t dataBuff[]);


#endif  /* ISOUDS_CNTRLDTCSETTING_H */

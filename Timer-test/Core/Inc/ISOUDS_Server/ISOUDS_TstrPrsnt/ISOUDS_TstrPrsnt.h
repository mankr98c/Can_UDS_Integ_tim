/*******************************************************************************
**
** -----------------------------------------------------------------------------
** File Name    : ISOUDS.c
**
** Description  : Include file of component ISOUDS_TstrPrsnt.c
**
** -----------------------------------------------------------------------------
**
*******************************************************************************/

/* To avoid multi-inclusions */
#ifndef ISOUDS_TSTRPRSNT_H
#define ISOUDS_TSTRPRSNT_H

/************************************* Inclusion files ************************/
#include "ISOUDS_Server.h"
/************************** Declaration of global symbol and constants ********/

/********************************* Declaration of global macros ***************/
#define ISOUDS_SIDTSTRPRSNT     0x3E

/********************************* Declaration of global types ****************/

/****************************** External links of global variables ************/
extern uint32_t ISOUDS_SessionTimeoutCntr;

/****************************** External links of global constants ************/

/*******************************************************************************
**                                      FUNCTIONS                              *
*******************************************************************************/

/********************************** Function definitions **********************/
extern void ISOUDS_TstrPrsnt(ISOUDS_ConfType *ISOUDSConfPtr, uint8_t dataBuff[]);
extern void ISOUDS_MonitorTstrPrsnt(void);
#endif  /* ISOUDS_TSTRPRSNT_H */

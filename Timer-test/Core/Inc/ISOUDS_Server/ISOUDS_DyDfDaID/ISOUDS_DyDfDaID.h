/*******************************************************************************
**
** -----------------------------------------------------------------------------
** File Name    : ISOUDS_DyDfDaID.h
**
** Description  : Include file component for ISOUDS_DDDID.c
**
** -----------------------------------------------------------------------------
**
*******************************************************************************/

/* To avoid multi-inclusions */
#ifndef ISOUDS_DYDFDAID_H
#define ISOUDS_DYDFDAID_H

/************************************* Inclusion files ************************/
#include "ISOUDS_Server.h"
#include "ISOUDS_Server_Cfg.h"
#include "ISOUDS_DyDfDaIDCfg.h"

/************************** Declaration of global symbol and constants ********/

/********************************* Declaration of global macros ***************/


/********************************* Declaration of global types ****************/
/* SID of Dynamically Define Data Identifier service */
#define     ISOUDS_SID_DDDID         (uint8_t)0x2C
#define 	ISOUDS_MEM_START_ADD     (uint32_t)0x00003000U
#define 	ISOUDS_MEM_END_ADD     	 (uint32_t)0x00003400U

/****************************** External links of global variables ************/
extern uint8_t ISOUDS_DyTabIdx_DDDID;
/****************************** External links of global constants ************/

/*******************************************************************************
**                                      FUNCTIONS                              *
*******************************************************************************/

/********************************** Function definitions **********************/
extern void ISOUDS_DDDID (ISOUDS_ConfType *ISOUDSConfPtr, uint8_t dataBuff[]);
extern uint8_t ISOUDS_DyLookUp (uint16_t recvDDDid);

#endif  /* ISOUDS_DYDFDAID_H */

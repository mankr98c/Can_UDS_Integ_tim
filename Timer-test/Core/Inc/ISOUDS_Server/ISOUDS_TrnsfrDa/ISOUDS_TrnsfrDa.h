/***************************************************************************************************
**
** -------------------------------------------------------------------------------------------------
** File Name    : ISOUDS_TrnsfrDa.h
**
** Description  : Include file of component ISOUDS_TrnsfrDa.c
**
** -------------------------------------------------------------------------------------------------
**
***************************************************************************************************/

/* To avoid multi-inclusions */
#ifndef ISOUDS_TRNSFRDA_H
#define ISOUDS_TRNSFRDA_H

/************************************* Inclusion files ********************************************/
#include "ISOUDS_Server.h"
#include "ISOUDS_Server_Cfg.h"

/************************** Declaration of global symbol and constants ****************************/
#define ISOUDS_TRIDLE       (uint8_t)0 /* Transfer Data service in Idle state */
#define ISOUDS_REQDW        (uint8_t)1 /* Transfer Data service in ReqDownload state */
#define ISOUDS_REQDWTD      (uint8_t)2 /* Transfer Data service is busy with ReqDownload state */
#define ISOUDS_REQTDFNSH    (uint8_t)3 /* Transfer Data service finish */
#define ISOUDS_REQUP        (uint8_t)4 /* Transfer Data service in Request Upload state */
#define ISOUDS_REQUPTD      (uint8_t)5 /* Transfer Data service is busy with Request upload state */
#define ISOUDS_REQTDUPFNSH  (uint8_t)6 /* Transfer Data service finish */

/********************************* Declaration of global macros ***********************************/

/********************************* Declaration of global types ************************************/
/* SID of Transfer Data service */
#define ISOUDS_SIDTRNSFRDTID    (0x36)

/****************************** External CANks of global variables ********************************/

/****************************** External CANks of global constants ********************************/

/***************************************************************************************************
**                                      FUNCTIONS                                                 **
***************************************************************************************************/

/********************************** Function definitions ******************************************/
extern void ISOUDS_TrnsfrDa (ISOUDS_ConfType *ISOUDSConfPtr, uint8_t dataBuff[]);
extern void ISOUDS_TrnsfrDaExit (void);
extern uint8_t ISOUDS_ReqTrnsfrDa (uint32_t addr, uint32_t size, uint8_t servreq);
extern uint8_t ISOUDS_ChkTrnsfrExit (void);

#endif  /* ISOUDS_TRNSFRDA_H */

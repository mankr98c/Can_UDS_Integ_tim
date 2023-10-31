/***************************************************************************************************
**
** -------------------------------------------------------------------------------------------------
** File Name    : ISOUDS_SA.h
**
** Description  : Include file of component ISOUDS_SA.c
**
** -------------------------------------------------------------------------------------------------
**
***************************************************************************************************/

/* To avoid multi-inclusions */
#ifndef ISOUDS_SA_H
#define ISOUDS_SA_H

/************************************* Inclusion files ********************************************/
#include "ISOUDS_Server.h"

/************************** Declaration of global symbol and constants ****************************/
/* SID of Security Access */
#define     ISOUDS_SIDSA                (0x27)

#define		ISOUDS_SA_SERV

/********************************* Declaration of global macros ***********************************/
/* ISOUDS_SAState machine states */
/* State A :- All levels locked,No Active Seed Send */
#define ISOUDS_SA_STATE_A            ((uint8_t)1)
/* State B :- All levels locked,Seed Send waiting for key */
#define ISOUDS_SA_STATE_B            ((uint8_t)2)
/* State C:- One level Unlocked ,No Active Seed */
#define ISOUDS_SA_STATE_C            ((uint8_t)3)
/* State D:- One level Unlocked, Seed Send for another level waiting for key */
#define ISOUDS_SA_STATE_D            ((uint8_t)4)

/* Security Access Service length */
#define     ISOUDS_SASERLEN             	(2)

#define     ISOUDS_SA_TRUE                   (1)
#define     ISOUDS_SA_FALSE                  (0)
/********************************* Declaration of global types ************************************/

/****************************** External links of global variables ********************************/

/****************************** External links of global constants ********************************/

/***************************************************************************************************
**                                      FUNCTIONS                                                 **
***************************************************************************************************/

/********************************** Function definitions ******************************************/
extern void ISOUDS_SAInit (void);
extern void ISOUDS_SA (ISOUDS_ConfType *ISOUDSConfPtr, uint8_t dataBuff[]);
extern uint8_t ISOUDS_GetSASt (void);
extern void ISOUDS_SAChkTimer (void);
extern void ISOUDS_SAReset (void);
extern uint8_t ISOUDS_GetSAStLevel (uint8_t SecAcssLevel);
extern uint32_t ISOUDS_GetSATimerSessionRunning (void);
extern uint32_t ISOUDS_GetSATimerWaitingForKeyRunning (void);
extern void ISOUDS_SA_ResetPwrONDly(void);
#endif  /* ISOUDS_SA_H */

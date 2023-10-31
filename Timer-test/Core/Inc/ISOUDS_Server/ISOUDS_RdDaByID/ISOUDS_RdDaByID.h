/*******************************************************************************
**
** -----------------------------------------------------------------------------
** File Name    : ISOUDS_RdDaByID.h
**
** Description  : Include file component for ISOUDS_RdDaByID.c
**
** -----------------------------------------------------------------------------
**
*******************************************************************************/

/* To avoid multi-inclusions */
#ifndef ISOUDS_RDDABYID_H
#define ISOUDS_RDDABYID_H

/************************************* Inclusion files ************************/
#include "ISOUDS_Server.h"
#include "ISOUDS_SA.h"
#include "ISOUDS_RdDaByID_Cfg.h"

/************************** Declaration of global symbol and constants ********/

/********************************* Declaration of global macros ***************/


/********************************* Declaration of global types ****************/
/* SID of Read Data By Identifier service */
#define     ISOUDS_SIDRDDABYID        (0x22)

/****************************** External links of global variables ************/
extern uint8_t ISOUDS_RdTabIdx_DDDID;
/****************************** External links of global constants ************/

/*******************************************************************************
**                                      FUNCTIONS                              *
*******************************************************************************/

/********************************** Function definitions **********************/
extern void ISOUDS_RdDaByID (ISOUDS_ConfType *ISOUDSConfPtr, uint8_t dataBuff[]);
extern uint8_t ISOUDS_RdArrData (uint8_t srcBuff[], uint8_t len);
extern uint8_t ISOUDS_RdLookUp_DDDID (uint16_t recvDDDid);
extern uint8_t ISOUDS_RdDidData_DDDID (uint16_t rdDid,uint8_t buffer[], uint16_t *buffPos);
extern uint8_t ISOUDS_RdDidData (uint16_t rdDid,uint8_t buffer[], uint16_t *buffPos);
extern uint8_t ISOUDS_RdLookUp (uint16_t recvDid);
#endif  /* ISOUDS_RDDABYID_H */

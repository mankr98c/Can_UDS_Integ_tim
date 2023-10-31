/*******************************************************************************
**
** -----------------------------------------------------------------------------
** File Name    : ISOUDS_RdDaByPdID.h
**
** Description  : Include file of component ISOUDS_RdDaByPdID.c
**
** -----------------------------------------------------------------------------
**
*******************************************************************************/

/* To avoid multi-inclusions */
#ifndef ISOUDS_RDDABYPDID_H
#define ISOUDS_RDDABYPDID_H

/************************************* Inclusion files ************************/
#include "ISOUDS_RdDaByPdIDCfg.h"
#include "ISOUDS_Server.h"
#include "ISOUDS_Server_Cfg.h"



/************************** Declaration of global symbol and constants ********/

/********************************* Declaration of global macros ***************/
/* SID of Read data By Periodic Identifier service */
#define     ISOUDS_SIDRDDABYPERIODIC        	(0x2A)

#define ISOUDS_PERIODICTRANSMIT_DEFAULT			(uint8_t)0x00
#define ISOUDS_PERIODICTRANSMIT_SLOWRATE		(uint8_t)0x01
#define ISOUDS_PERIODICTRANSMIT_MEDIUMRATE		(uint8_t)0x02
#define ISOUDS_PERIODICTRANSMIT_FASTRATE		(uint8_t)0x03
#define ISOUDS_PERIODICTRANSMIT_STOPSENDING		(uint8_t)0x04

/********************************* Declaration of global types ****************/
/* To save periodic DID time value */
typedef struct{
	uint16_t PDidTxCounter;
	uint16_t PDidTxCounterLimit;
	uint8_t  PeriodicDid;
	uint8_t  PdDidResSt;
}ISOUDS_PdDidCntrType;


/****************************** External links of global variables ************/

/****************************** External links of global constants ************/

/*******************************************************************************
**                                      FUNCTIONS                              *
*******************************************************************************/

/********************************** Function definitions **********************/
extern void ISOUDS_RdDataPeriodicDIDMainFunction (void);
extern void ISOUDS_RdDaByPdID(ISOUDS_ConfType *ISOUDSRdPdDidConfPtr, uint8_t dataBuff[]);

#endif  /* ISOUDS_RDDABYPDID_H */

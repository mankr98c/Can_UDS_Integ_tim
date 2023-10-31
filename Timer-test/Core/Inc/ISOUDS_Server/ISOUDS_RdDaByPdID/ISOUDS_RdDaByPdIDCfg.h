/*******************************************************************************
**
** -----------------------------------------------------------------------------
** File Name    : ISOUDS_RdDaByPdIDCfg.h
**
** Description  : Include file component for ISOUDS_RdDaByPdIDCfg.c
**
** -----------------------------------------------------------------------------
**
*******************************************************************************/

/* To avoid multi-inclusions */
#ifndef ISOUDS_RDDABYPDIDFCG_H
#define ISOUDS_RDDABYPDIDFCG_H

/************************************* Inclusion files ************************/
#include "ISOUDS_Server_Cfg.h"
#include "ISOUDS_RdDaByPdID.h"
#include "ISOUDS_Server.h"
/************************** Declaration of global symbol and constants ********/
/* Periodic Read DID Data Configuration Table size */
#define	ISOUDS_RDPDDIDDACONFTABSIZE		(uint8_t)5

#define ISOUDS_RdDaByPdIDMaxSAlevel		1U

#define		ISOUDS_PRDC_DT_MAX_BUF_SIZE				20U

#define ISOUDS_READ_PER_DATA_BY_ID_ENABLE		TRUE

/* Periodic DID time interval for slow, medium, fast rate in msec */
#define ISOUDS_TRANSMITDATAPERIODIC_SLOW	(uint16_t)1000
#define ISOUDS_TRANSMITDATAPERIODIC_MEDIUM	(uint16_t)100
#define ISOUDS_TRANSMITDATAPERIODIC_FAST	(uint16_t)10


/* NULL function pointer */
#define     ISOUDS_RDPDDIDFUNCNULLPTR     ((uint8_t (*) (uint8_t srcBuff[], uint16_t len))0)

/********************************* Declaration of global macros ***************/
/* Periodic did service length */
#define  RDPDID_SERV_LEN_ONE_BYTE		(uint16_t)1
#define  RDPDID_SERV_LEN_TWO_BYTE		(uint16_t)2
/********************************* Declaration of global types ****************/
typedef struct
{
	uint16_t rdPdDid;                             /* Periodic Data Identifier */
	uint8_t  rdPdDidLen;                          /* Periodic DID length - no. of bytes */
	uint8_t *rdPdDidAddr;                         /* Periodic DID address type of the DID */
	uint8_t (*rdPdDid_funPtr) (uint8_t buffer[], uint16_t len); /* Function pointer to callback function */
	uint8_t  rdPdDidSess;                         /* session in which the DID is supported */
	uint8_t  rdPdsecured;                       /* Read periodic DID Secured */
    uint8_t NoSecAccssSup;
    ISOUDS_SASuppLevel SecAccssLevl[ISOUDS_RdDaByPdIDMaxSAlevel];
}ISOUDS_RdPdDidType;


/****************************** External links of global variables ************/
#define  RDPDID_SRV_PARAM_TYPE		ISOUDS_ServrConf

#define  RDDABYPDID_TX_REQ_FUN		ISOTP_TxRequest

/****************************** External links of global constants ************/
extern const ISOUDS_RdPdDidType ISOUDS_RdPdDidDaConfTab[ISOUDS_RDPDDIDDACONFTABSIZE];

/*******************************************************************************
**                                      FUNCTIONS                              *
*******************************************************************************/

/********************************** Function definitions **********************/

/***************************************************************************************************
** Function                 : ISOUDS_Get_RDPDDIDDACONFTABSIZE

** Description              : Return the Number of Subfunctions configured for Read DID

** Paramete           		: None

** Return value             : retVal : Number of DIDs Supported

** Remarks                  : None
***************************************************************************************************/
extern uint16_t ISOUDS_Get_RDPDDIDDACONFTABSIZE(void);

#endif  /* ISOUDS_RDDABYPDIDFCG_H */

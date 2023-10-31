/*******************************************************************************
**
** -----------------------------------------------------------------------------
** File Name    : ISOUDSSecurDtaTrans.h
**
** Description  : Include file of component ISOUDSSecurDtaTrans.c
**
** -----------------------------------------------------------------------------
**
*******************************************************************************/

/* To avoid multi-inclusions */
#ifndef ISOUDS_SecureDtaTrans_H
#define ISOUDS_SecureDtaTrans_H

/************************************* Inclusion files ************************/
#include "ISOUDS_Server.h"
#include "ISOUDSSecurDtaTrans_Cfg.h"
/************************** Declaration of global symbol and constants ********/

/********************************* Declaration of global macros ***************/
#define ISOUDS_SIDSECURDTATRANS     	0x84U
#define ISOUDS_SRESIDSECURDTATRANS     	0xC4

#define ZERO							0U
#define ONE								1U
/********************************* Declaration of global types ****************/

/****************************** External links of global variables ************/

/****************************** External links of global constants ************/

/*******************************************************************************
**                                      FUNCTIONS                              *
*******************************************************************************/

/********************************** Function definitions **********************/

/*******************************************************************************
** Function                 : ISOUDS_SecurityLayerReq

** Description              : Request To Security layer

** Parameter isoTpConfPtr 	: Pointer to ISOTP configuration structure

** Return value             : None
*******************************************************************************/
extern void ISOUDS_SecurityLayerReq(uint16_t nBytes, uint8_t *tpBuff, ISOUDS_AddrType ReqType);

/*******************************************************************************
** Function                		: ISOUDS_SecurityLayerReqAPI

** Description              	: To Give Response as the Secure Data

** Parameter Length	 			: number of Bytes

** Parameter PtrToDestdataBuff  : Pointer to Data Buffer

** Return value            		 : None
*******************************************************************************/
extern void ISOUDS_SecurityLayerResp(uint16_t *Length,\
										uint8_t *PtrToDestdataBuff);

/*******************************************************************************
** Function                 : GetSecurityFlagStatus

** Description              : Get the Status of Security Flag

** Return value             : Status of Flag
*******************************************************************************/
uint8_t ISOUDS_GetSecurityFlagStatus(void);

/*******************************************************************************
** Function                 : SetSecurityFlag

** Description              : Set Security Flag

** Return value             : None
*******************************************************************************/
void ISOUDS_SetSecurityFlag(void);

/*******************************************************************************
** Function                 : ResetSecurityFlag

** Description              : Reset Security Flag

** Return value             : None
*******************************************************************************/
void ISOUDS_ResetSecurityFlag(void);
#endif  /* ISOUDS_TSTRPRSNT_H */

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
#ifndef ISOUDS_SecureDtaTrans_cfg_H
#define ISOUDS_SecureDtaTrans_cfg_H

/************************************* Inclusion files ************************/
#include "ISOUDS_Server.h"
/************************** Declaration of global symbol and constants ********/
#define ISOUDS_SECDATATRANS_ENABLE		TRUE
/********************************* Declaration of global macros ***************/
#define SecureData						0x55U

/********************************* Declaration of global types ****************/

/****************************** External links of global variables ************/

/****************************** External links of global constants ************/

/*******************************************************************************
**                                      FUNCTIONS                              *
*******************************************************************************/

/********************************** Function definitions **********************/

/*******************************************************************************
** Function                 	: SecureDtaTrans_Decode

** Description              	: Decode the Secured Data send by service
								request

** Parameter isoTpConfPtr 	: Pointer to ISOTP configuration structure

** Return value             : TRUE or FALSE
*******************************************************************************/
extern uint8_t ISOUDS_SecureDtaTrans_Decode(uint16_t nBytes, uint8_t *tpBuff);


#endif  /* ISOUDS_TSTRPRSNT_H */

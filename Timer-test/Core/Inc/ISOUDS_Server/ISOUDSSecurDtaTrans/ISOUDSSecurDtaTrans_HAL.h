/*******************************************************************************
**
** -----------------------------------------------------------------------------
** File Name    : ISOUDSSecurDtaTrans_HAL.h
**
** Description  : Include file of component ISOUDSSecurDtaTrans_HAL.c
**
** -----------------------------------------------------------------------------
**
*******************************************************************************/

/* To avoid multi-inclusions */
#ifndef ISOUDS_SecureDtaTrans_HAL_H
#define ISOUDS_SecureDtaTrans_HAL_H

/************************************* Inclusion files ************************/
#include "ISOUDS_Server.h"
#include "ISOUDSSecurDtaTrans_Cfg.h"
/************************** Declaration of global symbol and constants ********/

/********************************* Declaration of global macros ***************/

/********************************* Declaration of global types ****************/

/****************************** External links of global variables ************/

/****************************** External links of global constants ************/

/*******************************************************************************
**                                      FUNCTIONS                              *
*******************************************************************************/

/********************************** Function definitions **********************/
/*******************************************************************************
** Function                 : SecureDtaTrans_Encode

** Description              : Encode the Data

** Parameter Length	 			: number of Bytes

** Parameter PtrTodataBuff      : Pointer to Data Buffer

** Return value             : TRUE or FALSE
*******************************************************************************/
extern void ISOUDS_SecureDtaTrans_Encode(uint16_t Length,uint8_t *PtrTodataBuff);


#endif  /* ISOUDS_TSTRPRSNT_HAL_H */

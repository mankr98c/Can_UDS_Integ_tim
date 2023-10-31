/*******************************************************************************
**
** -----------------------------------------------------------------------------
** File Name    : ISOUDS_CntrlDTCSetting_HAL.h
**
** Description  : Include component of ISOUDS_CntrlDTCSetting.c
**
** -----------------------------------------------------------------------------
**
*******************************************************************************/

/* To avoid multi-inclusions */
#ifndef ISOUDS_CNTRLDTCSETTING_HAL_H
#define ISOUDS_CNTRLDTCSETTING_HAL_H

/************************************* Inclusion files ************************/
#include "ISOUDS_Server.h"

/************************** Declaration of global symbol and constants ********/

/********************************* Declaration of global macros ***************/

/********************************* Declaration of global types ****************/

/****************************** External CANks of global variables ************/

/****************************** External CANks of global constants ************/

/*******************************************************************************
**                                      FUNCTIONS                              *
*******************************************************************************/

/********************************** Function definitions **********************/
extern uint8_t HAL_CntrlDTCSetngPreCondCheck(void);
extern uint8_t HAL_CntrDTCSet_ON_Cbk(uint8_t DTCSettingType, const uint8_t *Data, uint16_t DataLen);
extern uint8_t HAL_CntrDTCSet_OFF_Cbk(uint8_t DTCSettingType, const uint8_t *Data, uint16_t DataLen);

#endif  /* ISOUDS_CNTRLDTCSETTING_HAL_H */

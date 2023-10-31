/*******************************************************************************
**
** -----------------------------------------------------------------------------
** File Name    : ISOUDS_CommCntrl_HAL.h
**
** Description  : Include component of ISOUDS_CommCntrl.c
**
** -----------------------------------------------------------------------------
**
*******************************************************************************/

/* To avoid multi-inclusions */
#ifndef ISOUDS_COMMCNTRL_HAL_H
#define ISOUDS_COMMCNTRL_HAL_H

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
extern uint8_t HAL_CommCntlPreCondCheck(void);
extern uint8_t HAL_EnblRxTx(uint8_t ControlType, uint8_t CommType, const uint8_t *Data);
extern uint8_t HAL_EnblRxDisableTx(uint8_t ControlType, uint8_t CommType, const uint8_t *Data);
extern uint8_t HAL_DisbleRxEnblTx(uint8_t ControlType, uint8_t CommType, const uint8_t *Data);
extern uint8_t HAL_DisablRxTx(uint8_t ControlType, uint8_t CommType, const uint8_t *Data);

#endif  /* ISOUDS_COMMCNTRL_HAL_H */

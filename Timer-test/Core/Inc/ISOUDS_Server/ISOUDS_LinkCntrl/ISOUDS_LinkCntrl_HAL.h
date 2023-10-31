/*******************************************************************************
**
** -----------------------------------------------------------------------------
** File Name    : ISOUDS_LinkCntrl_HAL.h
**
** Description  : Include component of ISOUDS_LinkCntrl.c
**
** -----------------------------------------------------------------------------
**
*******************************************************************************/

/* To avoid multi-inclusions */
#ifndef ISOUDS_LINKCNTRL_HAL_H
#define ISOUDS_LINKCNTRL_HAL_H

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
extern uint8_t HAL_LinkCntlPreCondCheck(void);
extern uint8_t HAL_LinkCntrl_VMTWFP(uint8_t ControlType, uint8_t *Data);
extern uint8_t HAL_LinkCntrl_VMTWSP(uint8_t ControlType, uint8_t *Data);
extern uint8_t HAL_LinkCntrl_TM(uint8_t ControlType, uint8_t *Data);


#endif  /* ISOUDS_COMMCNTRL_H */

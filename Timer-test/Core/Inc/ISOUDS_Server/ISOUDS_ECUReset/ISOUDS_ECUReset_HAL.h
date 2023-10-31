/***************************************************************************************************
**
** -------------------------------------------------------------------------------------------------
** File Name    : ISOUDS_ECUReset_HAL.h
**
** Description  : Include component of ISOUDS_ECUReset.c
**
** -------------------------------------------------------------------------------------------------
**
***************************************************************************************************/

/* To avoid multi-inclusions */
#ifndef ISOUDS_ECURESET_HAL_H
#define ISOUDS_ECURESET_HAL_H

/************************************* Inclusion files ********************************************/
#include "ISOUDS_Server_Cfg.h"


/************************** Declaration of global symbol and constants ****************************/

/********************************* Declaration of global macros ***********************************/

/********************************* Declaration of global types ************************************/

/****************************** External links of global variables ********************************/

/****************************** External links of global constants ********************************/

/***************************************************************************************************
**                                      FUNCTIONS                                                 **
***************************************************************************************************/

/********************************** Function definitions ******************************************/
extern uint8_t HAL_HardReset_Cond(void);
extern uint8_t HAL_KeyOffOnReset_Cond(void);
extern uint8_t HAL_SoftReset_Cond(void);
extern uint8_t HAL_EnablRpdPwrSD_Cond(void);
extern uint8_t HAL_HardReset_Proc(void);
extern uint8_t HAL_KeyOffOnReset_Proc(void);
extern uint8_t HAL_SoftReset_Proc(void);
extern uint8_t HAL_EnablRpdPwrSD_Proc(void);

#endif  /* ISOUDS_ECURESET_HAL_H */

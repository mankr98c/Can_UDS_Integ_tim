/***************************************************************************************************
**
** -------------------------------------------------------------------------------------------------
** File Name    : ISOUDS_StrtDiagSess_HAL.h
**
** Description  : Include file for component ISOUDS_StrtDiagSess.c
**
** -------------------------------------------------------------------------------------------------
**
***************************************************************************************************/

/* To avoid multi-inclusions */
#ifndef ISOUDS_STRTDIAGSESS_HAL_H
#define ISOUDS_STRTDIAGSESS_HAL_H

/************************************* Inclusion files ********************************************/
#include "ISOUDS_Server.h"

/************************** Declaration of global symbol and constants ****************************/

/********************************* Declaration of global macros ***********************************/

/********************************* Declaration of global types ************************************/

/****************************** External CANks of global variables ********************************/

/****************************** External CANks of global constants ********************************/

/***************************************************************************************************
**                                      FUNCTIONS                                                 **
***************************************************************************************************/

/********************************** Function definitions ******************************************/
extern uint8_t HAL_StrDiagSessDefault_Cbk(void);
extern uint8_t HAL_StrDiagSessExtended_Cbk(void);
extern uint8_t HAL_StrDiagSessProgramming_Cbk(void);
extern uint8_t HAL_StrDiagSessVehManuEOL_Cbk(void);
extern uint8_t HAL_StrDiagSessSafety_Cbk(void);

#endif  /* ISOUDS_STRTDIAGSESS_HAL_H */

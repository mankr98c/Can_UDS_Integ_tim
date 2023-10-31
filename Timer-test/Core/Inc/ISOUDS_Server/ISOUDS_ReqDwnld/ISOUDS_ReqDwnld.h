/***************************************************************************************************
**
** -------------------------------------------------------------------------------------------------
** File Name    : ISOUDS_ReqDwnld.h
**
** Description  : Include file of component ISOUDS_ReqDwnld.c
**
** -------------------------------------------------------------------------------------------------
**
***************************************************************************************************/

/* To avoid multi-inclusions */
#ifndef ISOUDS_REQDWNLD_H
#define ISOUDS_REQDWNLD_H

/************************************* Inclusion files ********************************************/
#include <stdint.h>
#include "ISOUDS_ReqDwnld_Cfg.h"
/************************** Declaration of global symbol and constants ****************************/

/********************************* Declaration of global macros ***********************************/

/********************************* Declaration of global types ************************************/
/* SID of Request download service */
#define     ISOUDS_SIDREQDWNLD  (0x34)


/****************************** External CANks of global variables ********************************/

/****************************** External CANks of global constants ********************************/

/***************************************************************************************************
**                                      FUNCTIONS                                                 **
***************************************************************************************************/

/********************************** Function definitions ******************************************/
extern void ISOUDS_ReqDwnld (ISOUDS_ConfType *ISOUDSConfPtr, uint8_t dataBuff[]);

#endif  /* ISOUDS_REQDWNLD_H */

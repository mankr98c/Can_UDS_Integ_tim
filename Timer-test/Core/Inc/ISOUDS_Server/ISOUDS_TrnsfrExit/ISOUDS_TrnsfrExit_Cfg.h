/***************************************************************************************************
**
** -------------------------------------------------------------------------------------------------
** File Name    : ISOUDS_TrnsfrExit.h
**
** Description  : Include file of component ISOUDS_TrnsfrExit.c
**
** -------------------------------------------------------------------------------------------------
**
***************************************************************************************************/

/* To avoid multi-inclusions */
#ifndef ISOUDS_TRNSFREXIT_CFG_H
#define ISOUDS_TRNSFREXIT_CFG_H

/************************************* Inclusion files ********************************************/
#include "ISOUDS_Server.h"

/************************** Declaration of global symbol and constants ****************************/

/********************************* Declaration of global macros ***********************************/
#define ISOUDS_TRANSFEREXT_INFO_SEC_SUPP	(ISOUDS_FALSE)
#define ISOUDS_TRANSFEREXT_INFO_SEC_LEVL	(0U)
/********************************* Declaration of global types ************************************/


/****************************** External CANks of global variables ********************************/

/****************************** External CANks of global constants ********************************/

/***************************************************************************************************
**                                      FUNCTIONS                                                 **
***************************************************************************************************/

/********************************** Function definitions ******************************************/
extern uint16_t ISOUDS_TrnsfrExitInd(const uint8_t *transferRequestParameterRecord, uint16_t RecordLength);

#endif  /* ISOUDS_TRNSFREXIT_CFG_H */

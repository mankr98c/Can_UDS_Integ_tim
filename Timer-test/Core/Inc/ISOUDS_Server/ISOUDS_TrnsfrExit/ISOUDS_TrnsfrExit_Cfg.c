/***************************************************************************************************
**
** -------------------------------------------------------------------------------------------------
** File Name    : ISOUDS_TrnsfrExit.c
**
** Description  : Data Transfer Exit Service
**
** -------------------------------------------------------------------------------------------------
**
***************************************************************************************************/

/**************************************** Inclusion files *****************************************/
#include "ISOUDS_TrnsfrExit_Cfg.h"
#include "ISOUDS_TrnsfrDa.h"

#if (ISOUDS_APP_CONFIG == ISOUDS_SERVER)
/********************** Declaration of local symbol and constants *********************************/

/********************************* Declaration of local macros ************************************/

/********************************* Declaration of local types *************************************/

/******************************* Declaration of local variables ***********************************/

/******************************* Declaration of local constants ***********************************/

/****************************** Declaration of exported variables *********************************/

/****************************** Declaration of exported constants *********************************/

/***************************************************************************************************
**                                      FUNCTIONS                                                 **
***************************************************************************************************/

/**************************** Internal functions declarations *************************************/

/******************************** Function definitions ********************************************/

/***************************************************************************************************
** Function                 : ISOUDS_TrnsfrExitInd

** Description              : Indication for Traansfer exit request

** Parameter 				: transferRequestParameterRecord: Parameter data record start address
							: RecordLength : Parametr record length

** Parameter dataBuff       : Data array

** Return value             : RespRecLength : Length of the response record stored in the bufffer 
												transferRequestParameterRecord
***************************************************************************************************/
uint16_t ISOUDS_TrnsfrExitInd(const uint8_t *transferRequestParameterRecord, uint16_t RecordLength)
{
	uint16_t RespRecLength = ISOUDS_ZERO;
	(void) *transferRequestParameterRecord;
	(void) RecordLength;
	/* Manual code start */

	/* Implement the Parameter record handling */

	/* Manual code end */
	
	return RespRecLength;
}

#endif

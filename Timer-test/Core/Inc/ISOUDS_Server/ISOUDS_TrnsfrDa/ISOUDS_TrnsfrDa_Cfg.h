/***************************************************************************************************
**
** -------------------------------------------------------------------------------------------------
** File Name    : ISOUDS_TrnsfrDa.h
**
** Description  : Include file of component ISOUDS_TrnsfrDa.c
**
** -------------------------------------------------------------------------------------------------
**
***************************************************************************************************/

/* To avoid multi-inclusions */
#ifndef ISOUDS_TRNSFRDA_CFG_H
#define ISOUDS_TRNSFRDA_CFG_H

/************************************* Inclusion files ********************************************/
#include "ISOUDS_Server.h"
#include "ISOUDS_Server_Cfg.h"

/************************** Declaration of global symbol and constants ****************************/

/********************************* Declaration of global macros ***********************************/
#define ISOUDS_TRANSFERDA_SEC_SUPP	(ISOUDS_FALSE)
#define ISOUDS_TRANSFERDA_SEC_LEVL	(0U)
/********************************* Declaration of global types ************************************/

/****************************** External CANks of global variables ********************************/

/****************************** External CANks of global constants ********************************/

/***************************************************************************************************
**                                      FUNCTIONS                                                 **
***************************************************************************************************/

/********************************** Function definitions ******************************************/
extern uint8_t ISOUDS_TransferDataDownloadReq (uint32_t ReqAddress, uint16_t ReqLength, const uint8_t *DownloadBuff);
extern uint8_t ISOUDS_GetTrnsfrReqstDwnldStat (void);
extern uint8_t ISOUDS_TranferDataUploadRequest (uint32_t ReqAddress, uint16_t ReqLength, const uint8_t *UploadBuff);
#endif  /* ISOUDS_TRNSFRDA_H */

/*******************************************************************************
** Copyright (c) 2018 Embitel
**
** This software is the property of Embitel .
** It can not be used or duplicated without Embitel authorization .
**
** -----------------------------------------------------------------------------
** File Name   : ISOUDS_ReqFileTransferCfg.h
** Module Name : UDS
** -----------------------------------------------------------------------------
**
** Description : Configuration header file for Request File Transfer Service
**
** -----------------------------------------------------------------------------
**
** Documentation reference :
**
********************************************************************************
** R E V I S I O N H I S T O R Y
********************************************************************************
** V01.00
** - Baseline for UDS module
**
*******************************************************************************/

/* To avoid multi-inclusions */
#ifndef ISOUDS_REQFILETRANSFERCFG_H
#define ISOUDS_REQFILETRANSFERCFG_H

/************************************* Inclusion files ************************/

/************************** Declaration of global symbol and constants ********/

#define DATA_BLOCK_LEN					256U

#define CBK_RSP_SUCCESS						0U
#define CBK_RSP_PEND						1U
#define CBK_RSP_FAILURE						2U

#define ISOUDS_REQ_FILETRNSFR_SEC_SUPP		ISOUDS_TRUE

#define ISOUDS_REQ_FILETRNSFR_SEC_LEVL		1U

/********************************* Declaration of global macros ***************/

/********************************* Declaration of global types ****************/

/****************************** External links of global variables ************/

/****************************** External links of global constants ************/

/*******************************************************************************
**                                      FUNCTIONS                              *
*******************************************************************************/
/********************************** External Function declaration *************/
extern uint8_t ISOUDS_ReqFTReadFile(uint16_t filePathNameLen, uint8_t *filePathName, uint8_t dataFormId);
extern uint8_t  ISOUDS_ReqFTAddFile(uint16_t filPathNameLen, uint8_t *filePathName, \
					uint8_t dataFormId, uint8_t fileSizeParaLength, \
					uint8_t *fileSizeUncomprsd, uint8_t *fileSizeCompred);
extern uint8_t ISOUDS_ReqFTDelFile(uint8_t *filePathName);
extern uint8_t ISOUDS_ReqFTReplaceFile(uint16_t filPathNameLen, uint8_t *filePathName, \
					uint8_t dataFormId, uint8_t fileSizeParaLength, \
					uint8_t *fileSizeUncomprsd, uint8_t *fileSizeCompred);
extern uint8_t ISOUDS_ReqFTReadDir(uint16_t filePathAndNameLen, uint8_t *filePathName);
extern uint8_t ISOUDS_GetReqFileAddStat(void);
extern void ISOUDS_ReqFileLen(uint8_t* l_FilePathAndName, uint16_t FilePathAndNameLen, uint8_t DataFrmt);
extern uint8_t ISOUDS_GetReqFileLenStat(uint32_t* FileLen);
#endif  /* _ISOUDS_REQFILETRANSFERCFG_H_ */

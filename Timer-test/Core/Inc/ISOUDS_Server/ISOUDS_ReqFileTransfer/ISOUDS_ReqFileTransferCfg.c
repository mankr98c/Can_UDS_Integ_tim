/*******************************************************************************
** Copyright (c) 2018 Embitel
**
** This software is the property of Embitel .
** It can not be used or duplicated without Embitel authorization .
**
** -----------------------------------------------------------------------------
** File Name   : ISOUDS_ReqFileTransferCfg.c
** Module Name : UDS
** -----------------------------------------------------------------------------
**
** Description : Configuration source file for Request File Transfer Service
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

/**************************************** Inclusion files *********************/
#include "ISOUDS_Server.h"
#include "ISOUDS_ReqFileTransferCfg.h"
#include "ISOUDS_TrnsfrDa.h"

#if (ISOUDS_APP_CONFIG == ISOUDS_SERVER)
/********************** Declaration of local symbol and constants *************/

/********************************* Declaration of local macros ****************/

/********************************* Declaration of local types *****************/

/******************************* Declaration of local variables ***************/

/******************************* Declaration of local constants ***************/

/****************************** Declaration of exported variables *************/

/****************************** Declaration of exported constants *************/

/*******************************************************************************
**                                      FUNCTIONS                              *
*******************************************************************************/

/**************************** Internal functions declarations *****************/

/******************************** Function definitions ************************/
uint8_t ISOUDS_ReqFTReadFile(uint16_t filePathNameLen, uint8_t *filePathName, uint8_t dataFormId)
{
	uint8_t RespVal = ISOUDS_POSRES;
	(void)dataFormId;
	(void)filePathNameLen;
	(void)filePathName;
	/* Manual code start */

	/* Perform Operation and store the Response code into RespVal */
	RespVal = ISOUDS_CNC;
	/* Manual Code End */

	return RespVal;
}

uint8_t ISOUDS_ReqFTAddFile(uint16_t filPathNameLen, uint8_t *filePathName, \
					uint8_t dataFormId, uint8_t fileSizeParaLength, \
					uint8_t *fileSizeUncomprsd, uint8_t *fileSizeCompred)
{
	uint8_t RespVal = ISOUDS_POSRES;
	(void)filPathNameLen;
	(void)filePathName;
	(void)dataFormId;
	(void)fileSizeParaLength;
	(void)fileSizeUncomprsd;
	(void)fileSizeCompred;

	/* Manual code start */
	
	/* Request for Upload Service */
	/* Call this after successfuly adding the file */
	uint32_t reqFilesize; /* woorksp only when fileSizeParaLength is 4 */
	reqFilesize = ((uint32_t)fileSizeUncomprsd[0] << 24) | ((uint32_t)fileSizeUncomprsd[1] << 16) | ((uint32_t)fileSizeUncomprsd[2] << 8) | fileSizeUncomprsd[3];
	
	RespVal = ISOUDS_ReqTrnsfrDa((uint32_t)NULL_PTR, reqFilesize, ISOUDS_REQDW);

	if (RespVal == ISOUDS_FALSE)
	{
		RespVal = ISOUDS_GPF;
	}
	else
	{

	        RespVal = ISOUDS_POSRES;

	}
	/* Manual Code End */

	return RespVal;
}

uint8_t ISOUDS_ReqFTDelFile(uint8_t *filePathName)
{
	uint8_t RespVal = ISOUDS_POSRES;
	(void)filePathName;
	/* Manual code start */

	/* Perform Operation and store the Response code into RespVal */
	//RespVal = ISOUDS_CNC;
	/* Manual Code End */

	return RespVal;
}

uint8_t ISOUDS_ReqFTReplaceFile(uint16_t filPathNameLen, uint8_t *filePathName, \
					uint8_t dataFormId, uint8_t fileSizeParaLength, \
					uint8_t *fileSizeUncomprsd, uint8_t *fileSizeCompred)
{
	uint8_t RespVal = ISOUDS_POSRES;
	(void)filPathNameLen;
	(void)filePathName;
	(void)dataFormId;
	(void)fileSizeParaLength;
	(void)fileSizeUncomprsd;
	(void)fileSizeCompred;


	/* Manual code start */

	/* Perform Operation and store the Response code into RespVal */
	RespVal = ISOUDS_CNC;
	/* Manual Code End */

	return RespVal;
}

uint8_t ISOUDS_ReqFTReadDir(uint16_t filePathAndNameLen, uint8_t *filePathName)
{
	uint8_t RespVal = ISOUDS_POSRES;

	(void)filePathAndNameLen;
	(void)filePathName;


	/* Manual code start */

	/* Perform Operation and store the Response code into RespVal */
	RespVal = ISOUDS_CNC;
	/* Manual Code End */

	return RespVal;
}

uint8_t ISOUDS_GetReqFileLenStat(uint32_t* FileLen)
{
/* Dummy Code Start */
	uint8_t RetVal;
	static uint8_t ReqFileLenCnt;

	ReqFileLenCnt++;

	if(ReqFileLenCnt >= 3U)
	{
		ReqFileLenCnt = 0U;

		*FileLen = DATA_BLOCK_LEN * 2U;

		RetVal = CBK_RSP_SUCCESS;
	}
	else
	{
		RetVal = CBK_RSP_PEND;
	}

	return RetVal;
	/* Dummy Code End */
}

void ISOUDS_ReqFileLen(uint8_t* l_FilePathAndName, uint16_t FilePathAndNameLen, uint8_t DataFrmt)
{
	(void)l_FilePathAndName;
	(void)FilePathAndNameLen;
	(void)DataFrmt;

}

uint8_t ISOUDS_GetReqFileAddStat(void)
{
	return CBK_RSP_SUCCESS;
}

#endif

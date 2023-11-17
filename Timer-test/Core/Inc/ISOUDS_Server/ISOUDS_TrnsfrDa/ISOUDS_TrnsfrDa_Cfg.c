/***************************************************************************************************
**
** -------------------------------------------------------------------------------------------------
** File Name    : ISOUDS_TrnsfrDa.c
**
** Description  : Transfer Data Service. This service is used to tranfer data between client and
**                server
**
** -------------------------------------------------------------------------------------------------
**
***************************************************************************************************/

/**************************************** Inclusion files *****************************************/
#include "ISOUDS_TrnsfrDa.h"
#include"ISOUDS_TrnsfrDa_Cfg.h"

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
** Function                 : ISOUDS_TransferDataDownloadReq

** Description              : Indication for request download packet

** Parameter 				: ReqAddress 	: Download address
							: ReqLength		: Donload Lengthe
							: DownloadBuff	: Download Data buffer

** Parameter 		        : flshresultstatus : Status of the request(ISOUDS_POSRES/ISOUDS_GPF ... etc.,)

** Return value             : None

** Remarks                  : None
***************************************************************************************************/
uint8_t ISOUDS_TransferDataDownloadReq (uint32_t ReqAddress, uint16_t ReqLength, const uint8_t *DownloadBuff)
{
    uint8_t flshresultstatus = ISOUDS_POSRES;
	(void) ReqAddress;
	(void) ReqLength;
	(void) *DownloadBuff;

	/* Manual code starts */

	/* Integrate Flash/NVM module to write the DownloadBuff to the Flash/NVM memory */

	/* Manual code ends */

	return flshresultstatus;
}

/***************************************************************************************************
** Function                 : ISOUDS_GetTrnsfrReqstDwnldStat

** Description              : Get Transfer data Download request status

** Parameter 				: None

** Return value             : flshresultstatus : Status of the download request(ISOUDS_POSRES/ISOUDS_GPF ... etc.,)

** Remarks                  : None
***************************************************************************************************/
uint8_t ISOUDS_GetTrnsfrReqstDwnldStat (void)
{
    uint8_t flshresultstatus = ISOUDS_POSRES;

	/* Manual code starts */

	/* Integrate Flash/NVM module to get the status of the write requested in ISOUDS_TransferDataDownloadReq() */

	/* Manual code ends */

	return flshresultstatus;
}

/***************************************************************************************************
** Function                 : ISOUDS_TransferDataDownloadReq

** Description              : Sends response to Transfer data service request

** Parameter 				: ReqAddress 	: Upload address
							: ReqLength		: Upload Lengthe
							: DownloadBuff	: Upload Data buffer

** Return value             : flshresultstatus : Status of the download request(ISOUDS_POSRES/ISOUDS_GPF ... etc.,)

** Remarks                  : None
***************************************************************************************************/
uint8_t ISOUDS_TranferDataUploadRequest (uint32_t ReqAddress, uint16_t ReqLength, const uint8_t *UploadBuff)
{
    uint8_t flshresultstatus = ISOUDS_POSRES;
	(void) ReqAddress;
	(void) ReqLength;
	(void) *UploadBuff;

	/* Manual code starts */
	void WriteDataToFlash(uint32_t flashAddress, const uint8_t *data, uint32_t dataSize);
//	ReqAddress = flashAddress;
	/* Integrate Flash/NVM module to read the Flash/NVM memory to UploadBuff */

	/* Manual code ends */

	return flshresultstatus;
}

#endif

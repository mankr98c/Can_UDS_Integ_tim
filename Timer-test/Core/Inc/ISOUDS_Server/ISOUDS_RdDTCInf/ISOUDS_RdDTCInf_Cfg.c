/*******************************************************************************
**
** -----------------------------------------------------------------------------
** File Name    : ISOUDS_CommCntrl.c
**
** Description  : Communication Control Service
**
** -----------------------------------------------------------------------------
**
*******************************************************************************/

/**************************************** Inclusion files *********************/
#include "ISOUDS_Server_Cfg.h"
#include "ISOUDS_RdDTCInf.h"
#include "ISOUDS_RdDTCInf_Cfg.h"
#include "ISOUDS_RdDTCInf_HAL.h"

#if (ISOUDS_APP_CONFIG == ISOUDS_SERVER)
/********************** Declaration of local symbol and constants *************/

/********************************* Declaration of local macros ****************/

/********************************* Declaration of local types *****************/
static uint8_t ISOUDS_RdTDCInf_reportDTCByStatusMask(uint8_t *Data, uint16_t *RespLen);
static uint8_t ISOUDS_RdTDCInf_reportNumberOfDTCByStatusMask(uint8_t *Data, uint16_t *RespLen);
static uint8_t ISOUDS_RdTDCInf_reportDTCSnpshotRecordByDTCNumber( uint8_t *Data, uint16_t *RespLen);
static uint8_t ISOUDS_RdTDCInf_reportSupportedDTC( uint8_t *Data, uint16_t *RespLen);
/******************************* Declaration of local variables ***************/

ISOUDS_RdDTCCfg_t ISOUDS_RdDTCCfg_Tbl[ISOUDS_RdDTCMaxSubFun] =	{
																	{
																		reportNumberOfDTCByStatusMask,	/* Subfunction */
																		3,								/* Message Length */
																		DEFAULT_SESS|EXTENDED_SESS,				/* Supported session */
																		ISOUDS_FALSE,					/* Security Support */
																		1,								/* Security Level */
																		&ISOUDS_RdTDCInf_reportNumberOfDTCByStatusMask/*Function pointer*/
																	},
																	{
																		reportDTCByStatusMask,
																		3,
																		DEFAULT_SESS|EXTENDED_SESS,
																		ISOUDS_FALSE,
																		2,
																		&ISOUDS_RdTDCInf_reportDTCByStatusMask/*Function pointer*/
																	},
																	{
																		reportDTCSnapshotRecordByDTCNumber,
																		6,
																		DEFAULT_SESS|EXTENDED_SESS,
																		ISOUDS_FALSE,
																		2,
																		&ISOUDS_RdTDCInf_reportDTCSnpshotRecordByDTCNumber/*Function pointer*/
																	},
																	{
																		reportSupportedDTC,
																		2,
																		DEFAULT_SESS|EXTENDED_SESS,
																		ISOUDS_FALSE,
																		2,
																		&ISOUDS_RdTDCInf_reportSupportedDTC/*Function pointer*/
																	}
																};

/******************************* Declaration of local constants ***************/

/****************************** Declaration of exported variables *************/

/****************************** Declaration of exported constants *************/

/*******************************************************************************
**                                      FUNCTIONS                              *
*******************************************************************************/

/******************************** Function definitions ************************/

/*******************************************************************************
** Function                 : ISOUDS_RdDTCPreCondCheck
**
** Description              : Checks the pre conditions for Read DTC
**
** Parameters 				: None
**
**
** Return value             : RetVal : Pre condition validity
*******************************************************************************/
uint8_t ISOUDS_RdDTCPreCondCheck(void)
{
	uint8_t RetVal = ISOUDS_TRUE;


	/* Add Code to check the Pre-conditions and update RetVal accordingly */
	RetVal = HAL_RdDTCPreCondCheck();

	return RetVal;
}

/**************************** Internal Function definitions *******************/
/*******************************************************************************
** Function                 : ISOUDS_RdTDCInf_reportNumberOfDTCByStatusMask
**
** Description              : API to reportNumberOfDTCByStatusMask
**
** Parameters 				: RespLen : Length of data copied
**            				: Data : diagnostic Data Buffer
** Return value             : RespVal : Response Type
*******************************************************************************/
static uint8_t ISOUDS_RdTDCInf_reportNumberOfDTCByStatusMask( uint8_t *Data, uint16_t *RespLen)
{
	uint8_t RespVal = ISOUDS_POSRES;

	uint8_t RdDTCStatusAvailabilityMask;
	uint8_t DTCFormatIdentifier;
	uint16_t DTCCount;

	if (NULL_PTR != Data)
	{
		/* Manual code start */
		/* Read DTC Status mask */
		RdDTCStatusAvailabilityMask = Data[0];

		/* Perform Operation and strore the Response code into RespVal */
		RespVal = HAL_RdTDCInf_reportNumberOfDTCByStatusMask (&RdDTCStatusAvailabilityMask, &DTCFormatIdentifier,
				&DTCCount);
		Data[0] = RdDTCStatusAvailabilityMask;
		Data[1] = DTCFormatIdentifier;
		#if(ISOUDS_BIG_ENDIAN == ISOUDS_ENDIAN_CONFIGURATION)
			Data[2] = (uint8_t)(DTCCount);
			Data[3] = (uint8_t)(DTCCount >> 8);
		#else
			Data[2] = (uint8_t)(DTCCount);
			Data[3] = (uint8_t)(DTCCount >> 8);
		#endif		
		*RespLen += 4U;
		/* Manual Code End */

		
	}
	else
	{
		/* do nothing */
		
	}
	
	/* Manual Code End */

	return RespVal;
}

/*******************************************************************************
** Function                 : ISOUDS_RdTDCInf_reportDTCByStatusMask
**
** Description              : API to reportNumberOfDTCByStatusMask
**
** Parameters 				: RespLen : Length of data copied
**            				: Data : diagnostic Data Buffer
** Return value             : RespVal : Response Type
*******************************************************************************/
static uint8_t ISOUDS_RdTDCInf_reportDTCByStatusMask( uint8_t *Data, uint16_t *RespLen)
{
	uint8_t RespVal = ISOUDS_POSRES;
	uint8_t RdDTCStatusAvailabilityMask;

	/* Manual code start */
	if (NULL_PTR != Data)
	{
		/* Read DTC Status mask */
		RdDTCStatusAvailabilityMask = Data[0];
		RespVal = HAL_RdTDCInf_reportDTCByStatusMask(&RdDTCStatusAvailabilityMask, &Data[1], RespLen);
		Data[0] = RdDTCStatusAvailabilityMask;
		*RespLen += 0x1U;
	}
	else
	{
		
		/* do nothing */
		
	}
	/* Manual Code End */

	return RespVal;
}

/*******************************************************************************
** Function                 : ISOUDS_RdTDCInf_reportDTCSnpshotRecordByDTCNumber
**
** Description              : API to reportDTCSnapshotRecordByDTCNumber
**
** Parameters 				: RespLen : Length of data copied
**            				: Data : diagnostic Data Buffer
** Return value             : RespVal : Response Type
*******************************************************************************/
static uint8_t ISOUDS_RdTDCInf_reportDTCSnpshotRecordByDTCNumber( uint8_t *Data, uint16_t *RespLen)
{
	uint8_t RespVal = ISOUDS_POSRES;
	uint32_t DTCMaskRecord;
	uint8_t DTCSnapshotRecordNumber;
	uint8_t StatMask =0;

	if (NULL_PTR != Data)
	{
		#if(ISOUDS_LITTLE_ENDIAN == ISOUDS_ENDIAN_CONFIGURATION)
			
			DTCMaskRecord = ((uint32_t)(((uint32_t)Data[0]) << 16) + ((uint32_t)Data[1] << 8) + (uint32_t)Data[2]);
		#else
			DTCMaskRecord = ((uint32_t)((uint32_t)Data[0]) + ((uint32_t)Data[1] << 8) + ((uint32_t)Data[2] << 16));
		#endif
		
		DTCSnapshotRecordNumber = Data[3];

		/* Manual code start */
		RespVal = HAL_RdTDCInf_reportDTCSnapshotRecordByDTCNumber(&DTCMaskRecord,&DTCSnapshotRecordNumber,&StatMask, &Data[0], RespLen);

		/* Manual Code End */

		
	}
	else
	{
		/* do nothing */
		
		
	}
	/* Manual Code End */

	return RespVal;
}
/*******************************************************************************
** Function                 : ISOUDS_RdTDCInf_reportSupportedDTC
**
** Description              : API to reportNumberOfDTCByStatusMask
**
** Parameters 				: RespLen : Length of data copied
**            				: Data : diagnostic Data Buffer
** Return value             : RespVal : Response Type
*******************************************************************************/
static uint8_t ISOUDS_RdTDCInf_reportSupportedDTC( uint8_t *Data, uint16_t *RespLen)
{
	uint8_t RespVal = ISOUDS_POSRES;

	/* Manual code start */
	RespVal = HAL_RdTDCInf_reportSupportedDTC( Data, RespLen);
	/* Manual Code End */

	return RespVal;
}

#endif

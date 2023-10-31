/***************************************************************************************************
** Copyright (c) 2023 EMBITEL
**
** This software is the property of EMBITEL.
** It can not be used or duplicated without EMBITEL authorization.
**
** -------------------------------------------------------------------------------------------------
** File Name    : Fcm_HAL.c
** Module name  : 
** -------------------------------------------------------------------------------------------------
** Description : Fault Code Management HAL file
**
** -------------------------------------------------------------------------------------------------
**
** Documentation reference : None
**
****************************************************************************************************
** R E V I S I O N  H I S T O R Y
****************************************************************************************************
** V01.00 
** - Baseline Created
**
***************************************************************************************************/
/**************************************** Inclusion files *****************************************/
#include "Fcm_HAL.h"
#include <string.h>
/********************** Declaration of local symbol and constants *********************************/
/********************************* Declaration of local macros ************************************/

/********************************* Declaration of local types *************************************/

/******************************* Declaration of local variables ***********************************/

/******************************* Declaration of local constants ***********************************/
static uint8_t FCM_DTC_RAWStatus = FCM_ZERO;
/****************************** Declaration of exported variables *********************************/
uint8_t PreviousIgnitionStatus = IGNITION_OFF;
/****************************** Declaration of exported constants *********************************/
uint8_t FCM_FCM_DTC_InitStatus;
/***************************************************************************************************
**                                      FUNCTIONS                                                 **
***************************************************************************************************/

/**************************** Internal functions declarations *************************************/

/******************************** Function definitions ********************************************/

/***************************************************************************************************
** Function                 : HAL_FCM_InitStatus

** Description              : Function to initialize FCM App status

** Parameter                : None

** Return value             : None
***************************************************************************************************/
uint8_t HAL_FCM_InitStatus(void)
{
	return FCM_FCM_DTC_InitStatus;
}
/***************************************************************************************************
** Function                 : HAL_FCM_ReadDTCInfo

** Description              : Function to Read the DTC Info from NVM

** Parameter                : FCM_ReadDTCInfo-> Data Pointer to Read the data
** 							: Size->Size of data to be read

** Return value             : None
***************************************************************************************************/

uint8_t HAL_FCM_ReadDTCInfo ( FCM_DTC_StatusType* FCM_ReadDTCInfo, uint16_t Size)
{
	/* Variable Declaration */
	uint32_t Retval =  FCM_ZERO;
	uint8_t FCM_Status = FCM_ZERO;
	uint16_t FCM_Index = FCM_ZERO;
#if 0
	/* Read From EEPROM */
	Retval  = readEeprom(EEPROM_FCM_DTCRAWStatus_DATAID,(uint32_t)&FCM_DTC_RAWStatus);

	(void)Size;
	/* Cehck if Read Success */
	if(EE_OK == Retval)
	{
		/* Check if Raw Status flag set */
		if(FCM_ONE == FCM_DTC_RAWStatus)
		{
			/* Run the loop for Read DTC */
			for(FCM_Index = FCM_ZERO;FCM_Index < FCM_MAXNUM_DTCS;FCM_Index++)
			{
				/* Read EEPROM */
				(void)readEeprom(((uint16_t)FCM_EEPROM_STRTDTC_DATAID + FCM_Index),\
								(uint32_t)&FCM_ReadDTCInfo[FCM_Index]);
			}
			
			/* Update the status */
			FCM_Status = FCM_ONE;
		}
		else
		{
			/* Do Nothing */
		}
	}
	else
	{
		/* Do Nothing */
	}
#endif
	/* Return Status */
	return FCM_Status;
}
/***************************************************************************************************
** Function                 : HAL_FCM_WriteDTCInfo

** Description              : Always return TRUE DTC structure memory is defined by FCM module itself

** Parameter                : FCM_WriteDTCInfo->Data Pointer to Write the data
** 							: Size ->Size of data to be written

** Return value             : None
***************************************************************************************************/
void HAL_FCM_WriteDTCInfo(const FCM_DTC_StatusType *FCM_WriteDTCInfo,uint16_t Size)
{
#if 0
	/* Variable Declaration */
	uint32_t Retval =  FCM_ZERO;
	uint16_t FCM_Index = FCM_ZERO;
	
	uint16_t FCM_EepromID;
	(void)Size;

	/* Update the Status */
	FCM_DTC_RAWStatus = FCM_ONE;
	/* Write in EEPROM */
	Retval  = writeEeprom(EEPROM_FCM_DTCRAWStatus_DATAID,FCM_ONE,(uint32_t)&FCM_DTC_RAWStatus);
	/* Check if Write Success */
	if(EE_OK == Retval)
	{
		/* Run the Loop to write All DTC */
		for(FCM_Index = FCM_ZERO;FCM_Index < FCM_MAXNUM_DTCS;FCM_Index++)
		{
			FCM_EepromID = ((uint16_t)FCM_EEPROM_STRTDTC_DATAID + FCM_Index);
			/* Write in to EEPROM */
			(void)writeEeprom(FCM_EepromID,(uint16_t)(sizeof(FCM_DTC_StatusType)),\
							(uint32_t)&FCM_WriteDTCInfo[FCM_Index]);
		}
	}
	else
	{
		/* Do Nothing */
	}
#endif
}

/***************************************************************************************************
** Function                 : HAL_FCM_Read_Snapst_Data

** Description              : To get the snapshot data record

** Parameter                : FCM_DTC_Ind:
**                            DataBuff:
**                            BuffLen:

** Return value             : None
***************************************************************************************************/
void HAL_FCM_Read_Snapst_Data(uint16_t FCM_DTC_Ind, uint8_t *DataBuff, uint16_t *BuffLen)
{
	uint16_t SnapshotDataIdx = FCM_ZERO;
	uint8_t Indx;
	uint8_t buff[3];
	
	for(Indx = FCM_ZERO; Indx < FCM_DTCSnapshotDataVar[FCM_DTC_Ind].FCM_DTCNumSnapshotSupp; Indx++)
	{
		DataBuff[SnapshotDataIdx] = (uint8_t)(FCM_DTCSnapshotDataVar[FCM_DTC_Ind].\
											 FCM_DTCSnapshotDataSupp[Indx].FCM_DTCSnapShotDataID >> FCM_EIGHT);
		DataBuff[SnapshotDataIdx + FCM_ONE] = (uint8_t)(FCM_DTCSnapshotDataVar[FCM_DTC_Ind].\
											FCM_DTCSnapshotDataSupp[Indx].FCM_DTCSnapShotDataID);
		
		//(void)readEeprom(FCM_DTCSnapshotDataVar[FCM_DTC_Ind].FCM_DTCSnapshotDataSupp[Indx].\
							FCM_DTCEEPROMDataID,(uint32_t)buff);
		memcpy(&DataBuff[SnapshotDataIdx + FCM_TWO], buff, FCM_DTCSnapshotDataVar[FCM_DTC_Ind].\
							FCM_DTCSnapshotDataSupp[Indx].FCM_DTCSnapshotLen);
	
		SnapshotDataIdx += (FCM_TWO + FCM_DTCSnapshotDataVar[FCM_DTC_Ind].\
							FCM_DTCSnapshotDataSupp[Indx].FCM_DTCSnapshotLen);
	}
	
	BuffLen[FCM_ZERO] = SnapshotDataIdx;
}


/***************************************************************************************************
** Function                 : HAL_FCM_ClearReqDTCUpdate

** Description              : To clear the requested DTC in NVM

** Parameter                : FCM_ClearDTCInfo pointer

** Return value             : None
***************************************************************************************************/
void HAL_FCM_ClearReqDTCUpdate(uint16_t FCM_ReqDTCIndx, FCM_DTC_StatusType *FCM_ClearDTCInfo)
{
	uint16_t FCM_Indx;
	uint16_t FCM_DTCRecData;
	
	uint16_t FCM_EEPROMID;

	/* Write the individual DTC status into NVM */
	if(FCM_ReqDTCIndx < FCM_MAXNUM_DTCS)
	{
		/* Intialize the Variable */
		FCM_DTCRecData = 0xFFFF;
		FCM_EEPROMID = ((uint16_t)FCM_EEPROM_STRTDTC_DATAID + FCM_ReqDTCIndx);
		/* Write EEPROM to Clear DTC */
		//(void)writeEeprom(FCM_EEPROMID,(uint16_t)(sizeof(FCM_DTC_StatusType))\
							,(uint32_t)&FCM_ClearDTCInfo[FCM_ReqDTCIndx]);
							
		for(FCM_Indx = FCM_ZERO;FCM_Indx < FCM_DTCSnapshotDataVar[FCM_ReqDTCIndx].FCM_DTCNumSnapshotSupp;FCM_Indx++)
		{
			/* Write Data to EEPROM */
			//(void)writeEeprom(FCM_DTCSnapshotDataVar[FCM_ReqDTCIndx].FCM_DTCSnapshotDataSupp[FCM_Indx].FCM_DTCEEPROMDataID\
							,FCM_DTCSnapshotDataVar[FCM_ReqDTCIndx].FCM_DTCSnapshotDataSupp[FCM_Indx].FCM_DTCSnapshotLen\
							,(uint32_t)&FCM_DTCRecData);
		}
	}
	else
	{
		/* Do Nothing */
	}
		
		
}
/***************************************************************************************************
** Function                 : HAL_FCM_DTC_StatusChange

** Description              : To update the DTC status change in NVM

** Parameter                : FCM_DTC_Idx

** Return value             : None
***************************************************************************************************/
void HAL_FCM_DTC_StatusChange(uint8_t FCM_DTC_Idx)
{
	/* Write the DTC data into NVM based on requirement */
	(void)FCM_DTC_Idx;
}
/***************************************************************************************************
** Function                 : HAL_FCM_ClearAllDTC

** Description              : To clear all DTC

** Parameter                : None

** Return value             : None
***************************************************************************************************/
void HAL_FCM_ClearAllDTC(FCM_DTC_StatusType *FCM_WriteDTCInfo)
{
	/* Variable Declaration */

	uint16_t FCM_Index = FCM_ZERO;
	uint16_t FCM_RecIndex = FCM_ZERO;
	uint16_t FCM_DTCRecData;
	
	/* Run the Loop to write All DTC */
	for(FCM_Index = FCM_ZERO;FCM_Index < FCM_MAXNUM_DTCS;FCM_Index++)
	{
		/* Intialize the Variable */
		FCM_DTCRecData = 0xFFFF;
		/* Write in to EEPROM */
		//(void)writeEeprom((uint16_t)(FCM_EEPROM_STRTDTC_DATAID + FCM_Index),\
				(uint16_t)(sizeof(FCM_DTC_StatusType)),(uint32_t)&FCM_WriteDTCInfo[FCM_Index]);

		for(FCM_RecIndex = FCM_ZERO;FCM_RecIndex < FCM_DTCSnapshotDataVar[FCM_Index].FCM_DTCNumSnapshotSupp;FCM_RecIndex++)
		{
			/* Write Data to EEPROM */
			//(void)writeEeprom(FCM_DTCSnapshotDataVar[FCM_Index].FCM_DTCSnapshotDataSupp[FCM_RecIndex].FCM_DTCEEPROMDataID\
							,FCM_DTCSnapshotDataVar[FCM_Index].FCM_DTCSnapshotDataSupp[FCM_RecIndex].FCM_DTCSnapshotLen\
							,(uint32_t)&FCM_DTCRecData);
		}
	}

}

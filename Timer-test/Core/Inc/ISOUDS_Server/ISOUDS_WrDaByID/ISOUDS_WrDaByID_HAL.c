/*******************************************************************************
** Copyright (c) 2018 Embitel
**
** This software is the property of Embitel .
** It can not be used or duplicated without Embitel authorization .
**
** -----------------------------------------------------------------------------
** File Name   : ISOUDS_WrDaByID_HAL.c
** Module Name : UDS
** -----------------------------------------------------------------------------
**
** Description : Write Data By Identifier Service
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
#include "ISOUDS_Server_Cfg.h"
#include "ISOUDS_WrDaByID.h"
#include "ISOUDS_WrDaByID_HAL.h"
#include  "stdbool.h"
#include "ISOUDS_RdDaByID_Cfg.h"
#include <string.h>

#if (ISOUDS_APP_CONFIG == ISOUDS_SERVER)
/********************** Declaration of local symbol and constants *************/
/************************ Declaration of local macros *************************/

/************************* Declaration of local types *************************/
/********************** Declaration of local variables ************************/

/************************ Declaration of local constants **********************/

/********************** Declaration of exported variables *********************/

/********************** Declaration of exported constants *********************/

/*******************************************************************************
**                                   FUNCTIONS                                 *
*******************************************************************************/

/**************************** Internal functions declarations *****************/

/************************** Function definitions ******************************/

/*******************************************************************************
** Function                 : HAL_WriteStatus

** Description              : Sends/pending response to Write Data by ID service request

** Parameter                : None

** Return value             : ISOUDS_WRITE_SUCC or ISOUDS_WRITE_FAIL
*******************************************************************************/
uint8_t HAL_WriteStatus(void)
{
	uint8_t WriteRetStat;
	/*User specific code*/
	/*Check the NVM status and return the status*/
	WriteRetStat = ISOUDS_WRITE_SUCC;
    return (WriteRetStat);
}

/**************************************************************************************************
** Function                 : ISOUDS_Write_SYMC_PartNoCbk

** Description              : Writes SYMC part number

** Parameter SrcBuff        : data array

** Parameter len            : Length - Number of Bytes to Write

** Return value             : Positive or Negative Response value

** Remarks                  : None
***************************************************************************************************/
uint8_t  ISOUDS_Write_SYMC_PartNoCbk(uint8_t  DestBuff[], uint8_t  len)
{
	//uint32_t retVal ;
	uint8_t RespVal ;
	(void)DestBuff;
	(void)len;

	/* update Negative Response */
	RespVal = ISOUDS_POSRES;

	/* update the retVal variable with respective response if required */

	return RespVal;
}

/**************************************************************************************************
** Function                 : ISOUDS_Write_VehIdenNoCbk

** Description              : Writes vehicle identification number

** Parameter SrcBuff        : data array

** Parameter len            : Length - Number of Bytes to Write

** Return value             : Positive or Negative Response value

** Remarks                  : None
***************************************************************************************************/
uint8_t  ISOUDS_Write_VehIdenNoCbk(uint8_t  DestBuff[], uint8_t  len)
{
	uint8_t RespVal = ISOUDS_POSRES;
	(void)len;
#if 0
	uint32_t retVal ;
	/* Write EPPROM */
	retVal = EE_OK; //writeEeprom(EEPROM_DID_VehIDNum_ID,ISOUDS_WDID_VEH_IDEN_NO_LEN,(uint32_t)DestBuff);
	/* Check Status */
	if(EE_OK == retVal)
	{
		/* update Positive Response */
		RespVal = ISOUDS_POSRES;
	}
	else
	{
		/* update Negative Response */
		RespVal = ISOUDS_GPF;
	}
#endif
	/* update the retVal variable with respective response if required */

	return RespVal;
}

/**************************************************************************************************
** Function                 : ISOUDS_Write_EcuInfoCbk

** Description              : Writes ECU Info

** Parameter SrcBuff        : data array

** Parameter len            : Length - Number of Bytes to Write

** Return value             : Positive or Negative Response value

** Remarks                  : None
***************************************************************************************************/
uint8_t  ISOUDS_Write_EcuInfoCbk(uint8_t  DestBuff[], uint8_t  len)
{

	uint8_t RespVal = ISOUDS_POSRES;
	(void)len;
#if 0
	uint32_t retVal ;
	if(DestBuff[0] == 0xBB)
	{

		/* 10bytes ASCII, WARMER & VENT FRT : 87310-42000, WARMER & VENT : 87320-42000 */
		const uint8_t warmerVentFrt_number[10] = "8731042000";
		const uint8_t warmerVent_number[10] = "8732042000";
		const uint8_t recovery_number[10] = "U100WARMER";
		uint16_t funcSpec = 0;

		if(memcmp(warmerVentFrt_number, &DestBuff[1], 10U) == 0U)
			funcSpec = FUNC_FRONT_WARMER|FUNC_FRONT_VENT;
		else if(memcmp(warmerVent_number, &DestBuff[1], 10U) == 0U)
			funcSpec = FUNC_FRONT_WARMER|FUNC_FRONT_VENT|FUNC_REAR_WARMER;
		else if(memcmp(recovery_number, &DestBuff[1], 10U) == 0U)
			funcSpec = 0xFF;

		if(funcSpec != 0)
		{
			setWdtEn(PAL_HIGH);
			/* Write EPPROM */
			retVal = writeEeprom(EEPROM_DID_ECU_INFO,ISOUDS_WDID_ECU_INFO_LEN - 1,(uint32_t)&DestBuff[1]);
			/* Check Status */
			if(EE_OK == retVal)
			{
				/* Write EPPROM */
				retVal = writeEeprom(EEPROM_DID_PART_NUMBER,ISOUDS_SYMC_PART_NUM_LEN,(uint32_t)&DestBuff[1]);

				if(EE_OK == retVal)
					retVal = writeEeprom(EEPROM_DID_HW_Version,ISOUDS_HARDWARE_VER_LEN,(uint32_t)&DestBuff[15]);

				/* Check Status */
				if(EE_OK == retVal)
				{
					if(funcSpec != 0xFF)
					{
						setFuncSpecification(funcSpec);
						setLockStatus(TRUE);
					}
					else
					{
						setLockStatus(FALSE);
					}

					/* update Positive Response */
					RespVal = ISOUDS_POSRES;
				}
			}
			setWdtEn(PAL_LOW);
		}
	}
#endif
	/* update the retVal variable with respective response if required */

	return RespVal;
}

/**************************************************************************************************
** Function                 : ISOUDS_Write_QRCodeCbk

** Description              : Writes QR Code

** Parameter SrcBuff        : data array

** Parameter len            : Length - Number of Bytes to Write

** Return value             : Positive or Negative Response value

** Remarks                  : None
***************************************************************************************************/
uint8_t  ISOUDS_Write_QRCodeCbk(uint8_t  DestBuff[], uint8_t  len)
{

	uint8_t RespVal = ISOUDS_GPF;
	(void)len;
#if 0
	uint32_t retVal ;
	if(DestBuff[0] == 0xBD)
	{
		/* Write EPPROM */
		retVal = writeEeprom(EEPROM_DID_QR_CODE,ISOUDS_WDID_QR_CODE_LEN - 1,(uint32_t)&DestBuff[1]);
		/* Check Status */
		if(EE_OK == retVal)
		{
			/* update Positive Response */
			RespVal = ISOUDS_POSRES;
		}
	}
#endif
	/* update the retVal variable with respective response if required */

	return RespVal;
}
#endif

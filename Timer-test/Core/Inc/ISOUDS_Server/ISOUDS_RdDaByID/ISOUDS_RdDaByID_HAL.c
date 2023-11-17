/***************************************************************************************************
** Copyright (c) 2018 EMBITEL
**
** This software is the property of EMBITEL.
** It can not be used or duplicated without EMBITEL authorization.
**
** -------------------------------------------------------------------------------------------------
** File Name    : ISOUDS_RdDaByID_HAL.c
** Module Name  : ISOUDS_RdDaByID
** -------------------------------------------------------------------------------------------------
**
** Description : Read Data by Identifier
**
** -------------------------------------------------------------------------------------------------
**
** Documentation reference : EME-17ST013-12211.01(SWLLD CanSrv_RdDaByID)
**
****************************************************************************************************
** R E V I S I O N H I S T O R Y
****************************************************************************************************
** V01.00 16/07/2018
** - Baseline Created
**
***************************************************************************************************/

/**************************************** Inclusion files *****************************************/
#include "ISOUDS_Server_Cfg.h"
#include "ISOUDS_RdDaByID.h"
#include "ISOUDS_RdDaByID_Cfg.h"
#include "ISOUDS_RdDaByID_HAL.h"

#if (SYMC_SECURITY == 1)
#include "fsymc_security.h"
#endif

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
static uint8_t ECUStatMSG_SupplyVtgLev(uint8_t buffer[], uint16_t len);
static uint8_t ECUStatMSG_CMXVerCAN1(uint8_t buffer[], uint16_t len);
static uint8_t ECUStatMSG_TransmErrCntrCAN1(uint8_t buffer[], uint16_t len);
static uint8_t ECUStatMSG_ReceiveErrCntrCAN1(uint8_t buffer[], uint16_t len);
static uint8_t ECUStatMSG_CANBUSOFFCntrCAN1(uint8_t buffer[], uint16_t len);
static uint8_t ProgIdInfo_FlashDocVerNum(uint8_t buffer[], uint16_t len);
static uint8_t ProgIdInfo_StatusFlag(uint8_t buffer[], uint16_t len);
static uint8_t ProgIdInfo_SupportFlag(uint8_t buffer[], uint16_t len);
static uint8_t ProgIdInfo_SecurityClass(uint8_t buffer[], uint16_t len);
static uint8_t ProgIdInfo_NumOfCodeBlkS(uint8_t buffer[], uint16_t len);
static uint8_t ProgIdInfo_ReProgAttmCNT(uint8_t buffer[], uint16_t len);
static uint8_t ProgIdInfo_MaxNumAttmCNT(uint8_t buffer[], uint16_t len);
static uint8_t ProgIdInfo_NumOfDataBlks(uint8_t buffer[], uint16_t len);
static uint8_t ProgIdInfo_ReProgAttmCntDa(uint8_t buffer[], uint16_t len);
static uint8_t ProgIdInfo_MaxNumAttmCntDa(uint8_t buffer[], uint16_t len);

/******************************** Function definitions ********************************************/
/*******************************************************************************
** Function         :ISOUDS_CheckPreConditions

** Description      : API to check the Preconditions

** Parameter        : None

** Return value     :read success (0) or failure (1)

** Remarks          :None
*******************************************************************************/
uint8_t ISOUDS_CheckPreConditions(void)
{
	uint8_t RespVal = ISOUDS_FALSE;

	/* Insert logic to check the pre conditions */

	return RespVal;
}

/*******************************************************************************
** Function         :RDBI_EcuStatusMsgCbk

** Description      :Read ECU Status Message.

** Parameter        :buffer and length of data

** Return value     :read success (0) or failure (1)

** Remarks          :None
*******************************************************************************/
uint8_t RDBI_EcuStatusMsgCbk(uint8_t buffer[], uint16_t len)
{
	uint8_t RespVal = ISOUDS_POSRES;
	uint8_t Status[ISOUDS_ECU_STATUS_MSG_LEN];

	uint16_t idx;

/*retrieve Supply voltage level*/
	(void)ECUStatMSG_SupplyVtgLev(&Status[ISOUDS_ECUSTATMSG_SUPPLYVTGLEV_POS],\
								ISOUDS_ECUSTATMSG_SUPPLYVTGLEV_LEN);
/*retrieve CMX Version of CAN-1*/
	(void)ECUStatMSG_CMXVerCAN1(&Status[ISOUDS_ECUSTATMSG_CMXVERCAN1_POS],\
								ISOUDS_ECUSTATMSG_CMXVERCAN1_LEN);
/*CAN Transmit error counter of CAN-1*/
	(void)ECUStatMSG_TransmErrCntrCAN1(&Status[ISOUDS_ECUSTATMSG_TRANSMERRCNTRCAN1_POS],\
								ISOUDS_ECUSTATMSG_TRANSMERRCNTRCAN1_LEN);
/*CAN Receive error counter of CAN-1*/
	(void)ECUStatMSG_ReceiveErrCntrCAN1(&Status[ISOUDS_ECUSTATMSG_RECEIVEERRCNTRCAN1_POS],\
								ISOUDS_ECUSTATMSG_RECEIVEERRCNTRCAN1_LEN);
/*CAN BusOff Counter of CAN-1*/
	(void)ECUStatMSG_CANBUSOFFCntrCAN1(&Status[ISOUDS_ECUSTATMSG_CANBUSOFFCNTRCAN1_POS],\
								ISOUDS_ECUSTATMSG_CANBUSOFFCNTRCAN1_LEN);

/* Copy data */
	for(idx = 0U; idx < len; idx++)
	{
		buffer[idx] = Status[idx];
	}
	/* End of Dummy Code */
	return RespVal;
}
/*******************************************************************************
** Function         :RDBI_SYMCPartNumCbk

** Description      :ReadSYMC Part Number.

** Parameter        :buffer and length of data

** Return value     :read success (0) or failure (1)

** Remarks          :None
*******************************************************************************/
uint8_t RDBI_SYMCPartNumCbk(uint8_t buffer[], uint16_t len)
{
	uint8_t RespVal = ISOUDS_POSRES;
	uint8_t	part_number[10] = "12";
		uint16_t idx;
	for(idx = 0U; idx < len; idx++)
			{
				buffer[idx] = part_number[idx];
			}
#if 0
	uint32_t StatusVal;
	/* 10bytes ASCII, WARMER & VENT FRT : 87310-42000, WARMER & VENT : 87320-42000 */
	uint8_t	part_number[10] = "";
	uint16_t idx;

#if (SYMC_SECURITY == 1)
	SYMC_UpdateSeed();
#endif

	StatusVal = readEeprom(EEPROM_DID_PART_NUMBER, (uint32_t)buffer);
	if(EE_OK != StatusVal)
	{
		/* Copy data */
		for(idx = 0U; idx < len; idx++)
		{
			buffer[idx] = part_number[idx];
		}
	}
#endif
	/* End of Dummy Code */
	return RespVal;
}
/*******************************************************************************
** Function         :RDBI_SYMCSoftwareVerCbk

** Description      :Read SYMC Software version.

** Parameter        :buffer and length of data

** Return value     :read success (0) or failure (1)

** Remarks          :None
*******************************************************************************/
uint8_t RDBI_SYMCSoftwareVerCbk(uint8_t buffer[], uint16_t len)
{
	uint8_t RespVal = ISOUDS_POSRES;
#if 0
	uint32_t StatusVal;
	/* before SOP: 00 ~ 99, after SOP: A0 ~ Z9 */
	uint8_t version[2] = "10";
	uint16_t idx;

#if (SYMC_SECURITY == 1)
	SYMC_UpdateSeed();
#endif

	StatusVal = readEeprom(EEPROM_DID_SW_VERSION, (uint32_t)buffer);
	if(EE_OK != StatusVal)
	{
		/* Copy data */
		for(idx = 0U; idx < len; idx++)
		{
			buffer[idx] = version[idx];
		}
		
		writeEeprom(EEPROM_DID_SW_VERSION,ISOUDS_SYMC_SOFTWARE_VER_LEN,(uint32_t)version);
	}
	else
	{
		if(memcmp(version, buffer, ISOUDS_SYMC_SOFTWARE_VER_LEN) != 0U)
			writeEeprom(EEPROM_DID_SW_VERSION,ISOUDS_SYMC_SOFTWARE_VER_LEN,(uint32_t)version);
	}
#endif
	/* End of Dummy Code */
	return RespVal;
}
/*******************************************************************************
** Function         :RDBI_SystemSuppCodeCbks

** Description      :Read System supplier code.

** Parameter        :buffer and length of data

** Return value     :read success (0) or failure (1)

** Remarks          :None
*******************************************************************************/
uint8_t RDBI_SystemSuppCodeCbk(uint8_t buffer[], uint16_t len)
{
	uint8_t RespVal = ISOUDS_POSRES;

	uint16_t idx;

	/* Copy data */
	for(idx = 0U; idx < len; idx++)
	{
		buffer[idx] = (uint8_t)idx;
	}


	/* End of Dummy Code */
	return RespVal;
}
/*******************************************************************************
** Function         :RDBI_ECUManufctDateCbk

** Description      :Read ECU Manufacturing Date.

** Parameter        :buffer and length of data

** Return value     :read success (0) or failure (1)

** Remarks          :None
*******************************************************************************/
uint8_t RDBI_ECUManufctDateCbk(uint8_t buffer[], uint16_t len)
{
	uint8_t RespVal = ISOUDS_POSRES;

	uint16_t idx;

	/* Copy data */
	for(idx = 0U; idx < len; idx++)
	{
		buffer[idx] = (uint8_t)idx;
	}


	/* End of Dummy Code */
	return RespVal;
}

/*******************************************************************************
** Function         :RDBI_ECUSerialNUmCbk

** Description      :ReadECU Serial Number.

** Parameter        :buffer and length of data

** Return value     :read success (0) or failure (1)

** Remarks          :None
*******************************************************************************/
uint8_t RDBI_ECUSerialNUmCbk(uint8_t buffer[], uint16_t len)
{
	uint8_t RespVal = ISOUDS_POSRES;

	uint16_t idx;

	/* Copy data */
	for(idx = 0U; idx < len; idx++)
	{
		buffer[idx] = (uint8_t)idx;
	}


	/* End of Dummy Code */
	return RespVal;
}

/*******************************************************************************
** Function         :RDBI_VehicleIDNumDataCbk

** Description      :Read VIN Data.

** Parameter        :buffer and length of data

** Return value     :read success (0) or failure (1)

** Remarks          :None
*******************************************************************************/
uint8_t RDBI_VehicleIDNumDataCbk(uint8_t buffer[], uint16_t len)
{
	uint8_t RespVal = ISOUDS_POSRES;
#if 0
	uint32_t StatusVal;

	(void)len;
	/* Read From EEPROM */
	StatusVal = readEeprom(EEPROM_DID_VehIDNum_ID,(uint32_t)buffer);
	/* Check the Status */
	if(EE_OK == StatusVal)
	{
		/* Update Response */
		RespVal = ISOUDS_POSRES;
	}
	else
	{
		/* Update negative Response */
		RespVal = ISOUDS_GPF;
	}
#endif
	/* End of Dummy Code */
	return RespVal;
}
/*******************************************************************************
** Function         :RDBI_TesterSerialNumCbk

** Description      :Read Repair Shop-Code or Tester Serial Number.

** Parameter        :buffer and length of data

** Return value     :read success (0) or failure (1)

** Remarks          :None
*******************************************************************************/
uint8_t RDBI_TesterSerialNumCbk(uint8_t buffer[], uint16_t len)
{
	uint8_t RespVal = ISOUDS_POSRES;
#if 0
	uint32_t StatusVal;
	(void)len;
	/* Read From EEPROM */
	StatusVal = readEeprom(EEPROM_DID_TestSerialNum_ID,(uint32_t)buffer);
	/* Check the Status */
	if(EE_OK == StatusVal)
	{
		/* Update Response */
		RespVal = ISOUDS_POSRES;
	}
	else
	{
		/* Update negative Response */
		RespVal = ISOUDS_GPF;
	}
#endif
	/* End of Dummy Code */
	return RespVal;
}
/*******************************************************************************
** Function         :RDBI_ProgramDateCbk

** Description      :Read Programming Date.

** Parameter        :buffer and length of data

** Return value     :read success (0) or failure (1)

** Remarks          :None
*******************************************************************************/
uint8_t RDBI_ProgramDateCbk(uint8_t buffer[], uint16_t len)
{
	uint8_t RespVal = ISOUDS_POSRES;
#if 0
	uint32_t StatusVal;
	(void)len;
	/* Read From EEPROM */
	StatusVal = readEeprom(EEPROM_DID_ProgramDate_ID,(uint32_t)buffer);
	/* Check the Status */
	if(EE_OK == StatusVal)
	{
		/* Update Response */
		RespVal = ISOUDS_POSRES;
	}
	else
	{
		/* Update negative Response */
		RespVal = ISOUDS_GPF;
	}
#endif
	/* End of Dummy Code */
	return RespVal;
}
/*******************************************************************************
** Function         :RDBI_DiagnosticInfoCbk

** Description      :Read Diagnostic Information.

** Parameter        :buffer and length of data

** Return value     :read success (0) or failure (1)

** Remarks          :None
*******************************************************************************/
uint8_t RDBI_DiagnosticInfoCbk(uint8_t buffer[], uint16_t len)
{
	uint8_t RespVal = ISOUDS_POSRES;

	uint16_t idx;

	/* Copy data */
	for(idx = 0U; idx < len; idx++)
	{
		buffer[idx] = (uint8_t)idx;
	}


	/* End of Dummy Code */
	return RespVal;
}
/*******************************************************************************
** Function         :RDBI_ProgramIdInfoCbk

** Description      :Read Programming Identification Information

** Parameter        :buffer and length of data

** Return value     :read success (0) or failure (1)

** Remarks          :None
*******************************************************************************/
uint8_t RDBI_ProgramIdInfoCbk(uint8_t buffer[], uint16_t len)
{
	uint8_t RespVal = ISOUDS_POSRES;
	uint8_t status[ISOUDS_PROGRAM_IDENT_INFO_LEN];
	uint16_t idx;

#if (SYMC_SECURITY == 1)
	SYMC_UpdateSeed();
#endif
	
/*retrieve Flash document version number Length*/
	(void)ProgIdInfo_FlashDocVerNum(&status[ISOUDS_PROGIDINFO_FLSHDOCVERNUM_POS],\
							ISOUDS_PROGIDINFO_FLSHDOCVERNUM_LEN);
/*retrieve Status Flag Length*/
	(void)ProgIdInfo_StatusFlag(&status[ISOUDS_PROGIDINFO_STATFLAG_POS],\
							ISOUDS_PROGIDINFO_STATFLAG_LEN);
/*retrieve Support Flag Length*/
	(void)ProgIdInfo_SupportFlag(&status[ISOUDS_PROGIDINFO_SUPPFLAG_POS],\
							ISOUDS_PROGIDINFO_SUPPFLAG_LEN);
/*retrieve Security Class Length*/
	(void)ProgIdInfo_SecurityClass(&status[ISOUDS_PROGIDINFO_SECCLASS_POS],\
							ISOUDS_PROGIDINFO_SECCLASS_LEN);
/*retrieve Number of code blocks Length*/
	(void)ProgIdInfo_NumOfCodeBlkS(&status[ISOUDS_PROGIDINFO_NUMOFCODEBLKS_POS],\
							ISOUDS_PROGIDINFO_NUMOFCODEBLKS_LEN);
/*retrieve Reprogramming Attempt Counter Length*/
	(void)ProgIdInfo_ReProgAttmCNT(&status[ISOUDS_PROGIDINFO_REPROGATTMCNT_POS],\
							ISOUDS_PROGIDINFO_REPROGATTMCNT_LEN);
/*retrieve Max number of Attempt Counter Length*/
	(void)ProgIdInfo_MaxNumAttmCNT(&status[ISOUDS_PROGIDINFO_MAXNUMATTMCNT_POS],\
							ISOUDS_PROGIDINFO_MAXNUMATTMCNT_LEN);
/*retrieve Number of data blocks Length*/
	(void)ProgIdInfo_NumOfDataBlks(&status[ISOUDS_PROGIDINFO_NUMOFDATABLKS_POS],\
							ISOUDS_PROGIDINFO_NUMOFDATABLKS_LEN);
/*retrieve Reprogramming Attempt Counter Length*/
	(void)ProgIdInfo_ReProgAttmCntDa(&status[ISOUDS_PROGIDINFO_REPROGATTMCNTDA_POS],\
							ISOUDS_PROGIDINFO_REPROGATTMCNTDA_LEN);
/*retrieve Max number of Attempt Counter Length */
	(void)ProgIdInfo_MaxNumAttmCntDa(&status[ISOUDS_PROGIDINFO_MAXNUMATTMCNTDA_POS],\
							ISOUDS_PROGIDINFO_MAXNUMATTMCNTDA_LEN);
/* Copu Data */
	for(idx = 0U; idx < len; idx++)
	{
		buffer[idx] = status[idx];
	}

	/* End of Dummy Code */
	return RespVal;
}
/*******************************************************************************
** Function         :RDBI_HardwareVerCbk

** Description      :Read Hardware version

** Parameter        :buffer and length of data

** Return value     :read success (0) or failure (1)

** Remarks          :None
*******************************************************************************/
uint8_t RDBI_HardwareVerCbk(uint8_t buffer[], uint16_t len)
{
	uint8_t RespVal = ISOUDS_POSRES;
#if 0
	uint32_t StatusVal;
	uint8_t	hw_ver[2] = "";
	uint16_t idx;

#if (SYMC_SECURITY == 1)
	SYMC_UpdateSeed();
#endif

	StatusVal = readEeprom(EEPROM_DID_HW_Version, (uint32_t)buffer);
	if(EE_OK != StatusVal)
	{
		/* Copy data */
		for(idx = 0U; idx < len; idx++)
		{
			buffer[idx] = hw_ver[idx];
		}
	}
#endif
	/* End of Dummy Code */
	return RespVal;
}
/*******************************************************************************
** Function         :RDBI_CANDBVerCbk

** Description      :Read Programming Identification Information

** Parameter        :buffer and length of data

** Return value     :read success (0) or failure (1)

** Remarks          :None
*******************************************************************************/
uint8_t RDBI_CANDBVerCbk(uint8_t buffer[], uint16_t len)
{
	uint8_t RespVal = ISOUDS_POSRES;
	uint8_t	can_db[] = "2.02";
	uint16_t idx;

#if (SYMC_SECURITY == 1)
	SYMC_UpdateSeed();
#endif

	/* Copy data */
	for(idx = 0U; idx < len; idx++)
	{
		buffer[idx] = can_db[idx];
	}

	/* End of Dummy Code */
	return RespVal;
}
/*******************************************************************************
** Function         :ECUStatMSG_SupplyVtgLev

** Description      :Read ECU Status Message DID Data Bytes -Supply voltage level

** Parameter        :buffer and length of data

** Return value     :read success (0) or failure (1)

** Remarks          :None
*******************************************************************************/
static uint8_t ECUStatMSG_SupplyVtgLev(uint8_t buffer[], uint16_t len)
{
	uint8_t RespVal = ISOUDS_POSRES;

	uint8_t idx;

	for(idx = 0U; idx < len; idx++)
	{
		buffer[idx] = idx;
	}

	/* End of Dummy Code */
	return RespVal;
}

/*******************************************************************************
** Function         :ECUStatMSG_CMXVerCAN1

** Description      :Read ECU Status Message DID Data Bytes -CMX Version of CAN-1

** Parameter        :buffer and length of data

** Return value     :read success (0) or failure (1)

** Remarks          :None
*******************************************************************************/
static uint8_t ECUStatMSG_CMXVerCAN1(uint8_t buffer[], uint16_t len)
{
	uint8_t RespVal = ISOUDS_POSRES;

	uint8_t idx;

	for(idx = 0U; idx < len; idx++)
	{
		buffer[idx] = idx;
	}

	/* End of Dummy Code */
	return RespVal;
}


/*******************************************************************************
** Function         :ECUStatMSG_TransmErrCntrCAN1

** Description      :Read ECU Status Message DID Data Bytes - CAN Transmit error counter of CAN-1

** Parameter        :buffer and length of data

** Return value     :read success (0) or failure (1)

** Remarks          :None
*******************************************************************************/
static uint8_t ECUStatMSG_TransmErrCntrCAN1(uint8_t buffer[], uint16_t len)
{
	uint8_t RespVal = ISOUDS_POSRES;

	uint8_t idx;

	for(idx = 0U; idx < len; idx++)
	{
		buffer[idx] = idx;
	}

	/* End of Dummy Code */
	return RespVal;
}

/*******************************************************************************
** Function         :ECUStatMSG_ReceiveErrCntrCAN1

** Description      :Read ECU Status Message DID Data Bytes - CAN Receive error counter of CAN-1

** Parameter        :buffer and length of data

** Return value     :read success (0) or failure (1)

** Remarks          :None
*******************************************************************************/
static uint8_t ECUStatMSG_ReceiveErrCntrCAN1(uint8_t buffer[], uint16_t len)
{
	uint8_t RespVal = ISOUDS_POSRES;

	uint8_t idx;

	for(idx = 0U; idx < len; idx++)
	{
		buffer[idx] = idx;
	}

	/* End of Dummy Code */
	return RespVal;
}


/*******************************************************************************
** Function         :ECUStatMSG_CANBUSOFFCntrCAN1

** Description      :Read ECU Status Message DID Data Bytes - CAN BusOff Counter of CAN-1

** Parameter        :buffer and length of data

** Return value     :read success (0) or failure (1)

** Remarks          :None
*******************************************************************************/
static uint8_t ECUStatMSG_CANBUSOFFCntrCAN1(uint8_t buffer[], uint16_t len)
{
	uint8_t RespVal = ISOUDS_POSRES;

	uint8_t idx;

	for(idx = 0U; idx < len; idx++)
	{
		buffer[idx] = idx;
	}

	/* End of Dummy Code */
	return RespVal;
}


/*******************************************************************************
** Function         :ProgIdInfo_FlashDocVerNum

** Description      :Read Programming Identification Information Data Bytes
** 												- Flash document version number

** Parameter        :buffer and length of data

** Return value     :read success (0) or failure (1)

** Remarks          :None
*******************************************************************************/
static uint8_t ProgIdInfo_FlashDocVerNum(uint8_t buffer[], uint16_t len)
{
	uint8_t RespVal = ISOUDS_POSRES;
	/* SES A 203-10 applied controller: $20 */
	uint8_t flash_doc_ver = 0x20;
	uint8_t idx;

	for(idx = 0U; idx < len; idx++)
	{
		buffer[idx] = flash_doc_ver;
	}

	/* End of Dummy Code */
	return RespVal;
}

/*******************************************************************************
** Function         :ProgIdInfo_StatusFlag

** Description      :Read Programming Identification Information Data Bytes
** 												- Status Flag

** Parameter        :buffer and length of data

** Return value     :read success (0) or failure (1)

** Remarks          :None
*******************************************************************************/
static uint8_t ProgIdInfo_StatusFlag(uint8_t buffer[], uint16_t len)
{
	uint8_t RespVal = ISOUDS_POSRES;

	uint8_t idx;

	for(idx = 0U; idx < len; idx++)
	{
		buffer[idx] = idx;
	}

	/* End of Dummy Code */
	return RespVal;
}

/*******************************************************************************
** Function         :ProgIdInfo_SupportFlag

** Description      :Read Programming Identification Information Data Bytes
** 												- Support Flag

** Parameter        :buffer and length of data

** Return value     :read success (0) or failure (1)

** Remarks          :None
*******************************************************************************/
static uint8_t ProgIdInfo_SupportFlag(uint8_t buffer[], uint16_t len)
{
	uint8_t RespVal = ISOUDS_POSRES;
	/* SES A 203-10 applied Signature Support: 1 (Feature supported) */
	uint8_t signature_support = 0x1;
	uint8_t idx;

	for(idx = 0U; idx < len; idx++)
	{
		buffer[idx] = signature_support;
	}

	/* End of Dummy Code */
	return RespVal;
}


/*******************************************************************************
** Function         :ProgIdInfo_SecurityClass

** Description      :Read Programming Identification Information Data Bytes
** 												- Security Class

** Parameter        :buffer and length of data

** Return value     :read success (0) or failure (1)

** Remarks          :None
*******************************************************************************/
static uint8_t ProgIdInfo_SecurityClass(uint8_t buffer[], uint16_t len)
{
	uint8_t RespVal = ISOUDS_POSRES;
	/* SES A 203-10 applied: $03 (Security Class CCC) */
	uint8_t security_class_ccc = 0x03;
	uint8_t idx;

	for(idx = 0U; idx < len; idx++)
	{
		buffer[idx] = security_class_ccc;
	}

	/* End of Dummy Code */
	return RespVal;
}

/*******************************************************************************
** Function         :ProgIdInfo_NumOfCodeBlkS

** Description      :Read Programming Identification Information Data Bytes
** 												- Number of code blocks

** Parameter        :buffer and length of data

** Return value     :read success (0) or failure (1)

** Remarks          :None
*******************************************************************************/
static uint8_t ProgIdInfo_NumOfCodeBlkS(uint8_t buffer[], uint16_t len)
{
	uint8_t RespVal = ISOUDS_POSRES;

	uint8_t idx;

	for(idx = 0U; idx < len; idx++)
	{
		buffer[idx] = idx;
	}

	/* End of Dummy Code */
	return RespVal;
}

/*******************************************************************************
** Function         :ProgIdInfo_ReProgAttmCNT

** Description      :Read Programming Identification Information Data Bytes
** 												- Reprogramming Attempt Counter

** Parameter        :buffer and length of data

** Return value     :read success (0) or failure (1)

** Remarks          :None
*******************************************************************************/
static uint8_t ProgIdInfo_ReProgAttmCNT(uint8_t buffer[], uint16_t len)
{
	uint8_t RespVal = ISOUDS_POSRES;

	uint8_t idx;

	for(idx = 0U; idx < len; idx++)
	{
		buffer[idx] = idx;
	}

	/* End of Dummy Code */
	return RespVal;
}

/*******************************************************************************
** Function         :ProgIdInfo_MaxNumAttmCNT

** Description      :Read Programming Identification Information Data Bytes
** 												- Max number of Attempt Counter

** Parameter        :buffer and length of data

** Return value     :read success (0) or failure (1)

** Remarks          :None
*******************************************************************************/
static uint8_t ProgIdInfo_MaxNumAttmCNT(uint8_t buffer[], uint16_t len)
{
	uint8_t RespVal = ISOUDS_POSRES;

	uint8_t idx;

	for(idx = 0U; idx < len; idx++)
	{
		buffer[idx] = idx;
	}

	/* End of Dummy Code */
	return RespVal;
}

/*******************************************************************************
** Function         :ProgIdInfo_NumOfDataBlks

** Description      :Read Programming Identification Information Data Bytes
** 												- Number of data blocks

** Parameter        :buffer and length of data

** Return value     :read success (0) or failure (1)

** Remarks          :None
*******************************************************************************/
static uint8_t ProgIdInfo_NumOfDataBlks(uint8_t buffer[], uint16_t len)
{
	uint8_t RespVal = ISOUDS_POSRES;

	uint8_t idx;

	for(idx = 0U; idx < len; idx++)
	{
		buffer[idx] = idx;
	}

	/* End of Dummy Code */
	return RespVal;
}

/*******************************************************************************
** Function         :ProgIdInfo_ReProgAttmCntDa

** Description      :Read Programming Identification Information Data Bytes
** 											- Reprogramming Attempt Counter Data Block

** Parameter        :buffer and length of data

** Return value     :read success (0) or failure (1)

** Remarks          :None
*******************************************************************************/
static uint8_t ProgIdInfo_ReProgAttmCntDa(uint8_t buffer[], uint16_t len)
{
	uint8_t RespVal = ISOUDS_POSRES;

	uint8_t idx;

	for(idx = 0U; idx < len; idx++)
	{
		buffer[idx] = idx;
	}

	/* End of Dummy Code */
	return RespVal;
}

/*******************************************************************************
** Function         :ProgIdInfo_MaxNumAttmCntDa

** Description      :Read Programming Identification Information Data Bytes
** 											- Max number of Attempt Counter

** Parameter        :buffer and length of data

** Return value     :read success (0) or failure (1)

** Remarks          :None
*******************************************************************************/
static uint8_t ProgIdInfo_MaxNumAttmCntDa(uint8_t buffer[], uint16_t len)
{
	uint8_t RespVal = ISOUDS_POSRES;

	uint8_t idx;

	for(idx = 0U; idx < len; idx++)
	{
		buffer[idx] = idx;
	}

	/* End of Dummy Code */
	return RespVal;
}

/*******************************************************************************
** Function         :RDBI_ECUInfoCbk

** Description      :Read ECU Information

** Parameter        :buffer and length of data

** Return value     :read success (0) or failure (1)

** Remarks          :None
*******************************************************************************/
uint8_t RDBI_ECUInfoCbk(uint8_t buffer[], uint16_t len)
{
	uint8_t RespVal = ISOUDS_POSRES;
#if 0
	uint32_t StatusVal;
	uint8_t	ecu_info[16] = "";
	uint16_t idx;

	StatusVal = readEeprom(EEPROM_DID_ECU_INFO, (uint32_t)buffer);
	if(EE_OK != StatusVal)
	{
		/* Copy data */
		for(idx = 0U; idx < len; idx++)
		{
			buffer[idx] = ecu_info[idx];
		}
	}
#endif
	/* End of Dummy Code */
	return RespVal;
}

/*******************************************************************************
** Function         :RDBI_QRCodeCbk

** Description      :Read QR Code

** Parameter        :buffer and length of data

** Return value     :read success (0) or failure (1)

** Remarks          :None
*******************************************************************************/
uint8_t RDBI_QRCodeCbk(uint8_t buffer[], uint16_t len)
{
	uint8_t RespVal = ISOUDS_POSRES;
#if 0
	uint32_t StatusVal;
	/* 10bytes ASCII, WARMER & VENT FRT : 87310-42000, WARMER & VENT : 87320-42000 */
	uint8_t	qr_code[21] = "";
	uint16_t idx;

	StatusVal = readEeprom(EEPROM_DID_QR_CODE, (uint32_t)buffer);
	if(EE_OK != StatusVal)
	{
		/* Copy data */
		for(idx = 0U; idx < len; idx++)
		{
			buffer[idx] = qr_code[idx];
		}
	}
#endif
	/* End of Dummy Code */
	return RespVal;
}

#endif

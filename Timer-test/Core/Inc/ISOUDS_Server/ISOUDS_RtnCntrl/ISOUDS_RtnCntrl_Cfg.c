/*******************************************************************************
**
** -----------------------------------------------------------------------------
** File Name    : ISOUDS_RtnCntrl.c
**
** Description  : Communication Control Service
**
** -----------------------------------------------------------------------------
**
*******************************************************************************/

/**************************************** Inclusion files *********************/
#include "ISOUDS_Server.h"
#include "ISOUDS_Server_Cfg.h"
#include "ISOUDS_RtnCntrl.h"
#include "ISOUDS_RtnCntrl_Cfg.h"
#include "ISOUDS_RtnCntrl_HAL.h"

#if (ISOUDS_APP_CONFIG == ISOUDS_SERVER)
/********************** Declaration of local symbol and constants *************/

/********************************* Declaration of local macros ****************/

/********************************* Declaration of local types *****************/

static uint8_t ISOUDS_RtnCheckMemory(ISOUDS_ConfType *ISOUDSConfPtr, \
		uint16_t RtnCntrlID, uint8_t RtnType, uint8_t *Data, uint16_t *RespLenth);

static uint8_t ISOUDS_RtnEraseMemory(ISOUDS_ConfType *ISOUDSConfPtr, \
		uint16_t RtnCntrlID, uint8_t RtnType, uint8_t *Data, uint16_t *RespLenth);

static uint8_t ISOUDS_RtnCheckProgDependcies(ISOUDS_ConfType *ISOUDSConfPtr, \
		uint16_t RtnCntrlID, uint8_t RtnType, uint8_t *Data, uint16_t *RespLenth);

/******************************* Declaration of local variables ***************/

ISOUDS_RtnCntrlCfg_t ISOUDS_RtnCntrlCfg_Tbl[ISOUDS_RtnContrlMaxSubFun] ={
																			{
																				ISOUDS_RTN_CHECK_MEM,
																				(PROGRAMMING_SESS|EXTENDED_SESS),
																				3,
																				{1},
																				12,
																				ISOUDS_TRUE,
																				1,
	 																			{UnlockedL1},
																				&ISOUDS_RtnCheckMemory
																			},
																			{
																				ISOUDS_RTN_ERASE_MEM,
																				(PROGRAMMING_SESS|EXTENDED_SESS),
																				3,
																				{1},
																				8,
																				ISOUDS_TRUE,
																				1,
	 																			{UnlockedL1},
																				&ISOUDS_RtnEraseMemory
																			},
																			{
																				ISOUDS_RTN_CHECKPROGDEP,
																				(PROGRAMMING_SESS|EXTENDED_SESS),
																				3,
																				{1},
																				8,
																				ISOUDS_TRUE,
																				1,
	 																			{UnlockedL1},
																				&ISOUDS_RtnCheckProgDependcies
																			}
																		};

/******************************* Declaration of local constants ***************/

/****************************** Declaration of exported variables *************/

/****************************** Declaration of exported constants *************/

/*******************************************************************************
**                                      FUNCTIONS                              *
*******************************************************************************/

/******************************** Function definitions ************************/

/***************************************************************************************************
** Function                 : ISOUDS_Get_RtnContrlMaxSubFun

** Description              : Return the Number of RID configured for Routine Control

** Paramete           		: None

** Return value             : retVal : Number of RIDs Supported

** Remarks                  : None
***************************************************************************************************/
uint16_t ISOUDS_Get_RtnContrlMaxSubFun(void)
{
	return ISOUDS_RtnContrlMaxSubFun;
}

/*******************************************************************************
** Function                 : ISOUDS_RtnControlTypeSuppChk
**
** Description              : Checks if the Routine type is supported or not
**
** Parameters 				: RoutineType  : Routine Type received
**							: RoutineIDIndex : Routine ID index
**
** Return value             : RetVal : Communication type validity
*******************************************************************************/
uint8_t ISOUDS_RtnControlTypeSuppChk(uint8_t RoutineType, uint16_t RoutineIDIndex)
{
	uint8_t Index;
	uint8_t RtnType_Found = ISOUDS_FALSE;

	for (Index = 0; (Index < ISOUDS_RtnCntrlCfg_Tbl[RoutineIDIndex].NumOfRtntypeSup) && (ISOUDS_FALSE == RtnType_Found); Index++)
	{
		if (RoutineType == ISOUDS_RtnCntrlCfg_Tbl[RoutineIDIndex].RtntypeSupp[Index])
		{
			RtnType_Found = ISOUDS_TRUE;
		}
		else
		{
			/* Do nothing */
		}
	}

	return RtnType_Found;
}

/*******************************************************************************
** Function                 : ISOUDS_RtnCntrlPreCondCheck
**
** Description              : Checks the pre conditions for Routine Control
**
** Parameters 				: None
**
**
** Return value             : RetVal : Pre condition validity
*******************************************************************************/
uint8_t ISOUDS_RtnCntrlPreCondCheck(void)
{
	uint8_t RetVal = ISOUDS_TRUE;

	/* Add Code to check the Pre-conditions and update RetVal accordingly */
	RetVal = HAL_RtnCntrlPreCondCheck();

	return RetVal;
}

/**************************** Internal Function definitions *******************/
/**************************************************************************************************
** Function                 : ISOUDS_RtnCheckMemory
**
** Description              : API for Check Memory Routine control ID
**
** Parameters 				: RtnCntrlID : Routine Control ID
**            				: RtnType : Routine Type
**							: Data Pointer: Point to Node Identification Number if required
**							: RespLenth : Response lenth
** Return value             : None
***************************************************************************************************/
static uint8_t ISOUDS_RtnCheckMemory(ISOUDS_ConfType *ISOUDSConfPtr, uint16_t RtnCntrlID, uint8_t RtnType, uint8_t *Data, uint16_t *RespLenth)
{
	uint8_t RespVal = ISOUDS_POSRES;

	/* Manual code start */

	/* Initial Routine request handler */
	/* Perform Operation and store the Response code into RespVal */
	RespVal = HAL_RtnCheckMemory(ISOUDSConfPtr, RtnCntrlID, RtnType, Data, RespLenth);

	/* Manual Code End */

	return RespVal;
}

/**************************************************************************************************
** Function                 : ISOUDS_RtnEraseMemory
**
** Description              : API for Erase Memory Routine control ID
**
** Parameters 				: RtnCntrlID : Routine Control ID
**            				: RtnType : Routine Type
**							: Data Pointer: Point to Node Identification Number if required
**							: RespLenth : Response lenth
** Return value             : None
***************************************************************************************************/
static uint8_t ISOUDS_RtnEraseMemory(ISOUDS_ConfType *ISOUDSConfPtr, uint16_t RtnCntrlID, uint8_t RtnType, uint8_t *Data, uint16_t *RespLenth)
{
	uint8_t RespVal = ISOUDS_POSRES;

	/* Manual code start */

	/* Initial Routine request handler */
	/* Perform Operation and store the Response code into RespVal */
	RespVal = HAL_RtnEraseMemory(ISOUDSConfPtr, RtnCntrlID, RtnType, Data, RespLenth);

	/* Manual Code End */

	return RespVal;
}

/**************************************************************************************************
** Function                 : ISOUDS_RtnCheckProgDependcies
**
** Description              : API for Check Programming Dependencies Routine control ID
**
** Parameters 				: RtnCntrlID : Routine Control ID
**            				: RtnType : Routine Type
**							: Data Pointer: Point to Node Identification Number if required
**							: RespLenth : Response lenth
** Return value             : None
***************************************************************************************************/
static uint8_t ISOUDS_RtnCheckProgDependcies(ISOUDS_ConfType *ISOUDSConfPtr, uint16_t RtnCntrlID, uint8_t RtnType, uint8_t *Data, uint16_t *RespLenth)
{
	uint8_t RespVal = ISOUDS_POSRES;

	/* Manual code start */

	/* Initial Routine request handler */
	/* Perform Operation and store the Response code into RespVal */
	RespVal = HAL_RtnChecProgDependencies(ISOUDSConfPtr, RtnCntrlID, RtnType, Data, RespLenth);

	/* Manual Code End */

	return RespVal;
}


#endif

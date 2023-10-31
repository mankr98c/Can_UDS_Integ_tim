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
#include "ISOUDS_Server.h"
#include "ISOUDS_IOCtrlByID.h"
#include "ISOUDS_IOCtrlByID_Cfg.h"
#include "ISOUDS_IOCtrlByID_HAL.h"

#if (ISOUDS_APP_CONFIG == ISOUDS_SERVER)
/********************** Declaration of local symbol and constants *************/

/********************************* Declaration of local macros ****************/

/********************************* Declaration of local types *****************/

static uint8_t ISOUDS_IOctrlTestRtn(uint16_t IOCntrlID, uint8_t IOCntrlParam, uint8_t *Data, uint16_t *RespLenth);
static uint8_t ISOUDS_IOctrlFrtHeatPwr(uint16_t IOCntrlID, uint8_t IOCntrlParam, uint8_t *Data, uint16_t *RespLenth);
static uint8_t ISOUDS_IOctrlRearHeatPwr(uint16_t IOCntrlID, uint8_t IOCntrlParam, uint8_t *Data, uint16_t *RespLenth);
static uint8_t ISOUDS_IOctrlFrtVentPwr(uint16_t IOCntrlID, uint8_t IOCntrlParam, uint8_t *Data, uint16_t *RespLenth);

/******************************* Declaration of local variables ***************/

ISOUDS_IOCntrlCfg_t ISOUDS_IOCntrlCfg_Tbl[ISOUDS_IOContrlMaxSubFun] =	{
																			{
																				ISOUDS_IOCTL_TESTRTN,
																				(EXTENDED_SESS),
																				4,
																				{0, 1, 2, 3},
																				5,
																				ISOUDS_FALSE,
																				1,
																				{UnlockedL2},
																				&ISOUDS_IOctrlTestRtn
																			},
																			{
																				ISOUDS_IOCTL_FRTHEATPWRCTRL,
																				(EXTENDED_SESS),
																				3,
																				{0, 1, 2},
																				5,
																				ISOUDS_FALSE,
																				1,
																				{UnlockedL1},
																				&ISOUDS_IOctrlFrtHeatPwr
																			},
																			{
																				ISOUDS_IOCTL_REARHEATPWRCTRL,
																				(EXTENDED_SESS),
																				3,
																				{0, 1, 2},
																				5,
																				ISOUDS_FALSE,
																				1,
																				{UnlockedL1},
																				&ISOUDS_IOctrlRearHeatPwr
																			},
																			{
																				ISOUDS_IOCTL_VENTPWRCTRL,
																				(EXTENDED_SESS),
																				3,
																				{0, 1, 2},
																				5,
																				ISOUDS_FALSE,
																				1,
																				{UnlockedL1},
																				&ISOUDS_IOctrlFrtVentPwr
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
** Function                 : ISOUDS_Get_IOContrlMaxSubFun

** Description              : Return the Number of ID configured for IO control

** Paramete           		: None

** Return value             : retVal : Number of IO control IDs Supported

** Remarks                  : None
***************************************************************************************************/
uint8_t ISOUDS_Get_IOContrlMaxSubFun(void)
{
	return ISOUDS_IOContrlMaxSubFun;
}
/*******************************************************************************
** Function                 : ISOUDS_IOControlParameterSupp
**
** Description              : Checks Checks if the IO control parameter is supported or not
**
** Parameters 				: CommType  : Communication Type received
**
**
** Return value             : RetVal : Communication type validity
*******************************************************************************/
uint8_t ISOUDS_IOControlParameterSupp(uint8_t IOcontrlParam, uint8_t RoutineIDIndex)
{
	uint8_t RetVal = ISOUDS_FALSE;
	uint8_t Index;
	uint8_t IOParam_Found;

	IOParam_Found = ISOUDS_FALSE;
	for (Index = 0; (Index < ISOUDS_IOCntrlCfg_Tbl[RoutineIDIndex].NumOfIOCntrlParamSup) && (ISOUDS_FALSE == IOParam_Found); Index++)
	{
		if (IOcontrlParam == ISOUDS_IOCntrlCfg_Tbl[RoutineIDIndex].IOContrlParamSupp[Index])
		{
			/* Neither Normal nor Network Management request */
			RetVal = ISOUDS_TRUE;

			IOParam_Found = ISOUDS_TRUE;
		}
		else
		{
			/* Do nothing */
		}
	}

	return RetVal;
}

/*******************************************************************************
** Function                 : ISOUDS_IOCntrlPreCondCheck
**
** Description              : Checks the pre conditions for IO Control
**
** Parameters 				: None
**
**
** Return value             : RetVal : Pre condition validity
*******************************************************************************/
uint8_t ISOUDS_IOCntrlPreCondCheck(void)
{
	uint8_t 	RetVal = ISOUDS_TRUE;



	/* Add Code to check the Pre-conditions and update RetVal accordingly */
	RetVal = HAL_IOCntrlPreCondCheck();

	return RetVal;
}

/**************************** Internal Function definitions *******************/
/*******************************************************************************
** Function                 : ISOUDS_IOctrlTestRtn
**
** Description              : API for IO Contol Test Routine
**
** Parameters 				: ControlType : Communication Control Type
**            				: CommType : Communication Type
**							: Data Pointer: Point to Node Identification Number if required
** Return value             : None
*******************************************************************************/
static uint8_t ISOUDS_IOctrlTestRtn(uint16_t IOCntrlID, uint8_t IOCntrlParam, uint8_t *Data, uint16_t *RespLenth)
{
	uint8_t RespVal = ISOUDS_POSRES;

	

	/* Manual code start */

	/* Perform Operation and strore the Response code into RespVal */
    RespVal = HAL_IOctrlTestRtn(IOCntrlID, IOCntrlParam, Data, RespLenth);
	/* Manual Code End */

	return RespVal;
}

/*******************************************************************************
** Function                 : ISOUDS_IOctrlFrtHeatPwr
**
** Description              : API for IO Contol Test Routine
**
** Parameters 				: ControlType : Communication Control Type
**            				: CommType : Communication Type
**							: Data Pointer: Point to Node Identification Number if required
** Return value             : None
*******************************************************************************/
static uint8_t ISOUDS_IOctrlFrtHeatPwr(uint16_t IOCntrlID, uint8_t IOCntrlParam, uint8_t *Data, uint16_t *RespLenth)
{
	uint8_t RespVal = ISOUDS_POSRES;

	/* Manual code start */
	switch(IOCntrlParam)
	{
		case ISOUDS_IOCTL_FRTHEATPWR:
			//setForcedHeatControl(SEAT_DRIVER, Data[0]);
			//setForcedHeatControl(SEAT_PASSENGER, Data[0]);
		break;
		case ISOUDS_IOCTL_DRVHEATPWR:
			//setForcedHeatControl(SEAT_DRIVER, Data[0]);
		break;
		case ISOUDS_IOCTL_PSGHEATPWR:
			//setForcedHeatControl(SEAT_PASSENGER, Data[0]);
		break;

		default:
		break;
	}

	/* Perform Operation and store the Response code into RespVal */
    RespVal = HAL_IOctrlFrtHeatPwr(IOCntrlID, IOCntrlParam, Data, RespLenth);
	/* Manual Code End */

	return RespVal;
}

/*******************************************************************************
** Function                 : ISOUDS_IOctrlRearHeatPwr
**
** Description              : API for IO Contol Test Routine
**
** Parameters 				: ControlType : Communication Control Type
**            				: CommType : Communication Type
**							: Data Pointer: Point to Node Identification Number if required
** Return value             : None
*******************************************************************************/
static uint8_t ISOUDS_IOctrlRearHeatPwr(uint16_t IOCntrlID, uint8_t IOCntrlParam, uint8_t *Data, uint16_t *RespLenth)
{
	uint8_t RespVal = ISOUDS_POSRES;

	/* Manual code start */
	switch(IOCntrlParam)
	{
		case ISOUDS_IOCTL_REARHEATPWR:
			//setForcedHeatControl(SEAT_REAR_LEFT, Data[0]);
			//setForcedHeatControl(SEAT_REAR_RIGHT, Data[0]);
		break;
		case ISOUDS_IOCTL_RLHEATPWR:
			//setForcedHeatControl(SEAT_REAR_LEFT, Data[0]);
		break;
		case ISOUDS_IOCTL_RRHEATPWR:
			//setForcedHeatControl(SEAT_REAR_RIGHT, Data[0]);
		break;

		default:
		break;
	}

	/* Perform Operation and store the Response code into RespVal */
    RespVal = HAL_IOctrlRearHeatPwr(IOCntrlID, IOCntrlParam, Data, RespLenth);
	/* Manual Code End */

	return RespVal;
}

/*******************************************************************************
** Function                 : ISOUDS_IOctrlFrtVentPwr
**
** Description              : API for IO Contol Test Routine
**
** Parameters 				: ControlType : Communication Control Type
**            				: CommType : Communication Type
**							: Data Pointer: Point to Node Identification Number if required
** Return value             : None
*******************************************************************************/
static uint8_t ISOUDS_IOctrlFrtVentPwr(uint16_t IOCntrlID, uint8_t IOCntrlParam, uint8_t *Data, uint16_t *RespLenth)
{
	uint8_t RespVal = ISOUDS_POSRES;

	/* Manual code start */
	switch(IOCntrlParam)
	{
		case ISOUDS_IOCTL_FRTVENTPWR:
			//setForcedVentControl(SEAT_DRIVER, Data[0]);
			//setForcedVentControl(SEAT_PASSENGER, Data[0]);
		break;
		case ISOUDS_IOCTL_DRVVENTPWR:
			//setForcedVentControl(SEAT_DRIVER, Data[0]);
		break;
		case ISOUDS_IOCTL_PSGVENTPWR:
			//setForcedVentControl(SEAT_PASSENGER, Data[0]);
		break;

		default:
		break;
	}

	/* Perform Operation and strore the Response code into RespVal */
    RespVal = HAL_IOctrlFrtVentPwr(IOCntrlID, IOCntrlParam, Data, RespLenth);
	/* Manual Code End */

	return RespVal;
}

#endif

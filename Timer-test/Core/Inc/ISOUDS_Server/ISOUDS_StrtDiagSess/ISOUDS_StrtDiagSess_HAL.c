/***************************************************************************************************
**
** -------------------------------------------------------------------------------------------------
** File Name    : ISOUDS_StrtDiagSess.c
**
** Description  : Start Diagnostic session
**
** -------------------------------------------------------------------------------------------------
**
***************************************************************************************************/

/**************************************** Inclusion files *****************************************/
#include "ISOUDS_Server_Cfg.h"
#include "ISOUDS_StrtDiagSess.h"
#include "ISOUDS_StrtDiagSess_Cfg.h"
#include "ISOUDS_StrtDiagSess_HAL.h"
#include "ISOUDS_StrtDiagSess_HAL.h"

#if (SYMC_SECURITY == 1)
#include "fsymc_security.h"
#endif

#if (ISOUDS_APP_CONFIG == ISOUDS_SERVER)
/********************** Declaration of local symbol and constants *********************************/

/********************************* Declaration of local macros ************************************/

#define EEPROM_REPRO_ID             0x0000

#define REPRO_MODE                  0xB5
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
** Function                 : ISOUDS_StrDiagSessDefault_Cbk

** Description              : Check for conditions and switch to default session

** Parameter                : None

** Return value             :  RespVal -> Returns the response for the service request
***************************************************************************************************/
uint8_t HAL_StrDiagSessDefault_Cbk(void)
{
	uint8_t RespVal;

	RespVal = ISOUDS_POSRES;

	#if 0
	uint8_t RespVal;
    /*User specific implementation*/
	RespVal = ISOUDS_POSRES;
	return(RespVal);
	#endif
#ifdef ISOUDS_SA_SERV 
	/* Session change so lock the security*/
	ISOUDS_SAReset();
#endif 
	return RespVal;
}

/***************************************************************************************************
** Function                 : HAL_StrDiagSessExtended_Cbk

** Description              : Check for conditions and switch to extended session

** Parameter                : None

** Return value             :  RespVal -> Returns the response for the service request

** Remarks                  : None
***************************************************************************************************/
uint8_t HAL_StrDiagSessExtended_Cbk(void)
{
	uint8_t RespVal;

	RespVal = ISOUDS_POSRES;

	#if 0
	uint8_t RespVal;
    /*User specific implementation*/
	RespVal = ISOUDS_POSRES;
	return(RespVal);
	#endif

#if (SYMC_SECURITY == 1)
	SYMC_UpdateSeed();
#endif

#ifdef ISOUDS_SA_SERV 
	/* Session change so lock the security*/
	ISOUDS_SAReset();
#endif
	return RespVal;
}

/***************************************************************************************************
** Function                 : HAL_StrDiagSessProgramming_Cbk

** Description              : Check for conditions and switch to Programming session

** Parameter                : None

** Return value             : RespVal -> Returns the response for the service request

** Remarks                  : None
***************************************************************************************************/
uint8_t HAL_StrDiagSessProgramming_Cbk(void)
{
	uint8_t RespVal = ISOUDS_POSRES;
	static uint8_t l_ReprgFlg = ISOUDS_FALSE;
	uint8_t data[1];

	#ifdef ISOUDS_SA_SERV 
	
	if (ISOUDS_FALSE ==	l_ReprgFlg)
	{
#if (SYMC_SECURITY == 1)
		SYMC_UpdateSeed();
#endif
		/*Update EEPROM Flag to indicate ReProgramming request is active*/
		data[0] = REPRO_MODE;

		//(void)writeEeprom(EEPROM_REPRO_ID, (uint16_t)ISOUDS_ONE, (uint32_t)data);
		/* update the flag*/
		ISOUDS_ReqECUReset();
		RespVal = ISOUDS_RCRRP;
		l_ReprgFlg = ISOUDS_TRUE;
	}
	else
	{
		
		RespVal = ISOUDS_RCRRP;
		
	}

					
	/* Session change so lock the security*/
	ISOUDS_SAReset();
	#endif
	return RespVal;
}


/***************************************************************************************************
** Function                 : HAL_StrDiagSessSafety_Cbk

** Description              : Check for conditions and switch to Safety session

** Parameter                : None

** Return value             :  RespVal -> Returns the response for the service request

** Remarks                  : None
***************************************************************************************************/
uint8_t HAL_StrDiagSessSafety_Cbk(void)
{
	uint8_t RespVal;

	RespVal = ISOUDS_POSRES;

	#if 0
	uint8_t RespVal;
    /*User specific implementation*/
	RespVal = ISOUDS_POSRES;
	return(RespVal);
	#endif
#ifdef ISOUDS_SA_SERV
	/* Session change so lock the security*/
	ISOUDS_SAReset();
#endif
	return RespVal;
}
/***************************************************************************************************
** Function                 : HAL_StrDiagSessVehManuEOL_Cbk

** Description              : Check for conditions and switch to Vehicle Manufacturer EOL sess

** Parameter                : None

** Return value             : RespVal -> Returns the response for the service request

** Remarks                  : None
***************************************************************************************************/
uint8_t HAL_StrDiagSessVehManuEOL_Cbk(void)
{
	uint8_t RespVal;

	RespVal = ISOUDS_POSRES;
	#if 0
	uint8_t RespVal;
    /*User specific implementation*/
	RespVal = ISOUDS_POSRES;
	return(RespVal);
	#endif
#ifdef ISOUDS_SA_SERV 
	/* Session change so lock the security*/
	ISOUDS_SAReset();
#endif 
	return RespVal;
}

#endif

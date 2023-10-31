/*******************************************************************************
**
** -----------------------------------------------------------------------------
** File Name    : ISOUDSSecurDtaTrans.c
**
** Description  : Tester Present Service
**
** -----------------------------------------------------------------------------
**
*******************************************************************************/

/**************************************** Inclusion files *********************/
#include "ISOUDSSecurDtaTrans.h"
#include "ISOUDSSecurDtaTrans_Cfg.h"
#include "ISOUDSSecurDtaTrans_HAL.h"
#include "ISOUDS_Server.h"

#if (ISOUDS_APP_CONFIG == ISOUDS_SERVER)

#if (ISOUDS_SECDATATRANS_ENABLE == TRUE)
/********************** Declaration of local symbol and constants *************/

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

/*******************************************************************************
** Function                 	: SecureDtaTrans_Decode

** Description              	: Decode the Secured Data send by service
								request

** Parameter canSrvDConfPtr 	: Pointer to ISOTP service configuration structure

** Return value             : TRUE or FALSE
*******************************************************************************/
uint8_t ISOUDS_SecureDtaTrans_Decode(uint16_t nBytes, uint8_t *tpBuff)
{
	uint8_t loop;
	uint8_t return_value;

	if(ISOUDS_GetSecurityFlagStatus() == ISOUDS_FALSE)
	{
		/* Decrypt the Data */
		for(loop = ONE; loop < nBytes; loop++)
		{
			tpBuff[loop - ONE] = tpBuff[loop] ^ SecureData;
		}

		return_value = ISOUDS_TRUE;
	}
	else
	{
		return_value = ISOUDS_FALSE;
	}
	return return_value;
}
#endif

#endif


/*******************************************************************************
**
** -----------------------------------------------------------------------------
** File Name    : ISOUDS_DyDfDaIDCfg.c
**
** Description  : Read Data Identifier configuration
**
** -----------------------------------------------------------------------------
**
*******************************************************************************/

/**************************************** Inclusion files *********************/
#include "ISOUDS_DyDfDaIDCfg.h"
#include "ISOUDS_DyDfDaID_HAL.h"

#if (ISOUDS_APP_CONFIG == ISOUDS_SERVER)
/********************************* Declaration of local macros ****************/

/********************************* Declaration of local types *****************/

/******************************* Declaration of local variables ***************/

/******************************* Declaration of local constants ***************/

/****************************** Declaration of exported variables *************/
/****************************** Declaration of exported constants *************/

ISOUDS_DyDidType ISOUDS_DyDDConfTab[ISOUDS_DYDDCONFTABSIZE] =
{

	{
        (uint16_t)0xF300,
        (uint8_t)2,
		{(uint8_t)100},
        (uint8_t)(EXTENDED_SESS|DEFAULT_SESS),
        ISOUDS_FALSE,
		1,
	 	{UnlockedL1}
    },
	{
        (uint16_t)0xF301,
        (uint8_t)2,
		{(uint8_t)50},
        (uint8_t)(EXTENDED_SESS|DEFAULT_SESS),
        ISOUDS_FALSE,
		1,
	 	{UnlockedL1}
    },
};


/***************************************************************************************************
** Function                 : ISOUDS_Get_DYDDCONFTABSIZE

** Description              : Return the Number of Subfunctions configured for Dynamically Define DID

** Paramete           		: None

** Return value             : retVal : Number of DIDs Supported

** Remarks                  : None
***************************************************************************************************/
uint16_t ISOUDS_Get_DYDDCONFTABSIZE(void)
{
	return ISOUDS_DYDDCONFTABSIZE;
}
/************************************************************************/

#endif

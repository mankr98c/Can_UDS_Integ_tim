/*******************************************************************************
**
** -----------------------------------------------------------------------------
** File Name    : ISOUDS_CntrlDTCSetting_Cfg.h
**
** Description  : Include component of ISOUDS_CntrlDTCSetting_Cfg.c
**
** -----------------------------------------------------------------------------
**
*******************************************************************************/

/* To avoid multi-inclusions */
#ifndef ISOUDS_CONTRLDTCSET_CFG_H
#define ISOUDS_CONTRLDTCSET_CFG_H


/************************************* Inclusion files ************************/

/************************** Declaration of global symbol and constants ****************************/

/********************************* Declaration of global macros ***************/
#define ISOUDS_CntrlDTCSetMaxSubFun		(2U)
#define ISOUDS_CntrlDTCSetMaxSAlevel		(1)
/********************************* Declaration of global types ****************/
typedef enum
{
	ISOUDS_DTC_SETNG_ON = 0x01,
	ISOUDS_DTC_SETNG_OFF = 0x02
}ISOUDS_DTCSettingType_e;
typedef struct
{
	ISOUDS_DTCSettingType_e DTCSettingType;
	uint8_t SuptdSession;
	uint8_t SecAccssSup;
    uint8_t NoSecAccssSup;
    ISOUDS_SASuppLevel SecAccssLevl[ISOUDS_CntrlDTCSetMaxSAlevel];
	uint8_t (*SubFunCbk)(uint8_t DTCSettingType,const uint8_t *Data, uint16_t DataLen);
}ISOUDS_CntrlDTCSetCfg_t;



/****************************** External CANks of global variables ************/
extern ISOUDS_CntrlDTCSetCfg_t ISOUDS_CntrlDTCSetCfgTbl[ISOUDS_CntrlDTCSetMaxSubFun];
/****************************** External CANks of global constants ************/

/*******************************************************************************
**                                      FUNCTIONS                              *
*******************************************************************************/

/********************************** Function Declarations **********************/
/***************************************************************************************************
** Function                 : ISOUDS_Get_CntrlDTCSetMaxSubFun

** Description              : Return the Number of Subfunctions configured for the Control DTC settings

** Paramete           		: None

** Return value             : retVal : Number of subfunctions

** Remarks                  : None
***************************************************************************************************/
extern uint8_t ISOUDS_Get_CntrlDTCSetMaxSubFun(void);

/*******************************************************************************
** Function                 : ISOUDS_CntrlDTCSetngPreCondCheck
**
** Description              : Checks the pre conditions for Control DTC setting
**
** Parameters 				: None
**
**
** Return value             : RetVal : Pre condition validity
*******************************************************************************/
extern uint8_t ISOUDS_CntrlDTCSetngPreCondCheck(void);

#endif /* ISOUDS_COMMCNTRL_CFG_H */

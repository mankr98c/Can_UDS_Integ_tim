/*******************************************************************************
**
** -----------------------------------------------------------------------------
** File Name    : ISOUDS_CommCntrl.h
**
** Description  : Include component of ISOUDS_CommCntrl.c
**
** -----------------------------------------------------------------------------
**
*******************************************************************************/

/* To avoid multi-inclusions */
#ifndef ISOUDS_COMMCNTRL_CFG_H
#define ISOUDS_COMMCNTRL_CFG_H


/************************************* Inclusion files ************************/

/************************** Declaration of global symbol and constants ****************************/

/********************************* Declaration of global macros ***************/
#define ISOUDS_ComContMaxSubFun		(4U)
#define ISOUDS_ComContMaxSAlevel		(1)
/********************************* Declaration of global types ****************/
typedef enum
{
	EnblRxTx = 0x00,
	EnblRxDisablTx = 0x01,
	DisablRxEnblTx = 0x02,
	DisablRxTx = 0x03
}ISOUDS_ContType_e;

typedef struct
{
	ISOUDS_ContType_e ControlType;
	uint8_t SuptdSession;
	uint8_t SecAccssSup;
    uint8_t NoSecAccssSup;
    ISOUDS_SASuppLevel SecAccssLevl[ISOUDS_ComContMaxSAlevel];
    uint8_t (*SubFunCbk)(uint8_t ControlType, uint8_t CommType, const uint8_t *Data);
}ISOUDS_ComCntCfg_t;



/****************************** External CANks of global variables ************/
extern ISOUDS_ComCntCfg_t ISOUDS_ComContCfgTbl[ISOUDS_ComContMaxSubFun];
/****************************** External CANks of global constants ************/

/*******************************************************************************
**                                      FUNCTIONS                              *
*******************************************************************************/

/********************************** Function Declarations **********************/

/***************************************************************************************************
** Function                 : ISOUDS_Get_ComContMaxSubFun

** Description              : Return the Number of Subfunctions configured for Communication control

** Paramete           		: None

** Return value             : retVal : Number of subfunctions

** Remarks                  : None
***************************************************************************************************/
extern uint8_t ISOUDS_Get_ComContMaxSubFun(void);

/*******************************************************************************
** Function                 : ISOUDS_CommTypeSupp
**
** Description              : Checks Communication Validity
**
** Parameters 				: CommType  : Communication Type received
**
**
** Return value             : RetVal : Communication type validity
*******************************************************************************/
extern uint8_t ISOUDS_CommTypeSupp(uint8_t CommType);

/*******************************************************************************
** Function                 : ISOUDS_CommCntlPreCondCheck
**
** Description              : Checks the pre conditions for Communication control
**
** Parameters 				: None
**
**
** Return value             : RetVal : Pre condition validity
*******************************************************************************/
extern uint8_t ISOUDS_CommCntlPreCondCheck(void);


#endif /* ISOUDS_COMMCNTRL_CFG_H */

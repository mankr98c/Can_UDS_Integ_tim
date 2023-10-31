/*******************************************************************************
**
** -----------------------------------------------------------------------------
** File Name    : ISOUDS_LinkCntrlCfg.h
**
** Description  : Include component of ISOUDS_LinkCntrlCfg.c
**
** -----------------------------------------------------------------------------
**
*******************************************************************************/

/* To avoid multi-inclusions */
#ifndef ISOUDS_LINKCNTRL_CFG_H
#define ISOUDS_LINKCNTRL_CFG_H


/************************************* Inclusion files ************************/

/************************** Declaration of global symbol and constants ****************************/

/********************************* Declaration of global macros ***************/
#define ISOUDS_LinkContMaxSubFun		(3U)

#define ISOUDS_LinkContrlMaxSAlevel		(1U)
/********************************* Declaration of global types ****************/
typedef enum
{
	VMTWFP = 1U,
	VMTWSP = 2U,
	TM = 3U
}ISOUDS_LinkContType_e;

typedef struct
{
	ISOUDS_LinkContType_e ControlType;
	uint8_t SuptdSession;
	uint8_t SecAccssSup;
	uint8_t NoSecAccssSup;
    ISOUDS_SASuppLevel SecAccssLevl[ISOUDS_LinkContrlMaxSAlevel];
	uint8_t (*SubFunCbk)(uint8_t ControlType, uint8_t *Data);
}ISOUDS_LinkCntCfg_t;



/****************************** External CANks of global variables ************/
extern ISOUDS_LinkCntCfg_t ISOUDS_LinkContCfgTbl[ISOUDS_LinkContMaxSubFun];
/****************************** External CANks of global constants ************/

/*******************************************************************************
**                                      FUNCTIONS                              *
*******************************************************************************/

/********************************** Function Declarations **********************/

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
extern uint8_t ISOUDS_LinkCntlPreCondCheck(void);

/***************************************************************************************************
** Function                 : ISOUDS_Get_LinkContMaxSubFun

** Description              : Return the Number of Subfunction configured for Link control

** Paramete           		: None

** Return value             : retVal : Number of Link control Subfunctions Supported

** Remarks                  : None
***************************************************************************************************/
extern uint8_t ISOUDS_Get_LinkContMaxSubFun(void);


#endif /* ISOUDS_COMMCNTRL_CFG_H */

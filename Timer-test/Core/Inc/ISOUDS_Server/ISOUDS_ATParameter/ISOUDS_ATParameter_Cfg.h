/*******************************************************************************
**
** -----------------------------------------------------------------------------
** File Name    : ISOUDS_ATParameterCfg.h
**
** Description  : Include component of ISOUDS_ATParameterCfg.c
**
** -----------------------------------------------------------------------------
**
*******************************************************************************/

/* To avoid multi-inclusions */
#ifndef ISOUDS_ACCESSTIMINGPARAMETER_CFG_H
#define ISOUDS_ACCESSTIMINGPARAMETER_CFG_H


/************************************* Inclusion files ************************/

/************************** Declaration of global symbol and constants ****************************/

/********************************* Declaration of global macros ***************/
#define ISOUDS_AccTimPartMaxSubFun		(4U)
#define ISOUDS_P2MINRANGE_MIN   (0U)
#define ISOUDS_P2MINRANGE_MAX   (5000U)
#define ISOUDS_S2MINRANGE_MIN   (0U)
#define ISOUDS_S2MINRANGE_MAX   (10U)

#define ISOUDS_ATParamMaxSAlevel		(1U)
/********************************* Declaration of global types ****************/
typedef enum
{
	readExtendedTimingParameterSet = 0x01,
	setTimingParametersToDefaultValues = 0x02,
	readCurrentlyActiveTimingParameters = 0x03,
	setTimingParametersToGivenValues = 0x04
}ISOUDS_AccessTimParSubType_e;

typedef struct
{
	ISOUDS_AccessTimParSubType_e timingParameterAccessType;
	uint8_t SuptdSession;
	uint8_t SecAccssSup;
	uint8_t NoSecAccssSup;
    ISOUDS_SASuppLevel SecAccssLevl[ISOUDS_ATParamMaxSAlevel];
	uint8_t (*SubFunCbk)(uint8_t timingParameterAccessType, uint8_t *Data, uint16_t *RespByes);
}ISOUDS_AccessTimParSubCfg_t;



/****************************** External CANks of global variables ************/
extern ISOUDS_AccessTimParSubCfg_t ISOUDS_AccessTimParSubCfg[ISOUDS_AccTimPartMaxSubFun];
/****************************** External CANks of global constants ************/

/*******************************************************************************
**                                      FUNCTIONS                              *
*******************************************************************************/

/********************************** Function Declarations **********************/

/***************************************************************************************************
** Function                 : ISOUDS_Get_AccTimeParMaxSubFun

** Description              : Return the Number of Subfunctions configured for the Server

** Paramete           		: None

** Return value             : retVal : Number of subfunctions

** Remarks                  : None
***************************************************************************************************/
extern uint8_t ISOUDS_Get_AccTimeParMaxSubFun(void);

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
** Function                 : ISOUDS_AccessTimParamPreCondCheck
**
** Description              : Checks the pre conditions for Access Timing Params
**
** Parameters 				: None
**
**
** Return value             : RetVal : Pre condition validity
*******************************************************************************/
extern uint8_t ISOUDS_AccessTimParamPreCondCheck(void);



#endif /* ISOUDS_COMMCNTRL_CFG_H */

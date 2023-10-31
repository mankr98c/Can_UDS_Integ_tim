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
#ifndef ISOUDS_IOCNTRL_CFG_H
#define ISOUDS_IOCNTRL_CFG_H


/************************************* Inclusion files ************************/

/************************** Declaration of global symbol and constants ****************************/

/********************************* Declaration of global macros ***************/
#define ISOUDS_IOContrlMaxSubFun		(4U)

#define ISOUDS_NUMBER_OF_IO_PARAM_SUPP	(4U)
#define ISOUDS_IO_PARAMMaxSAlevel		(1U)
/********************************* Declaration of global types ****************/
typedef struct
{
	uint16_t IOCntrlID;
	uint8_t SuptdSession;
	uint8_t NumOfIOCntrlParamSup;
	uint8_t IOContrlParamSupp[ISOUDS_NUMBER_OF_IO_PARAM_SUPP];
	uint16_t IOCntrlIDLen;
	uint8_t SecAccssSup;
	uint8_t NoSecAccssSup;
	uint8_t SecAccssLevl[ISOUDS_IO_PARAMMaxSAlevel];
	uint8_t (*SubFunCbk)(uint16_t IOCntrlID, uint8_t IOCntrlParam, uint8_t *Data, uint16_t *RespLenth);
}ISOUDS_IOCntrlCfg_t;

#define ISOUDS_IOCTL_TESTRTN			(0xE800U)
#define ISOUDS_IOCTL_FRTHEATPWRCTRL		(0xE801U)
#define ISOUDS_IOCTL_REARHEATPWRCTRL	(0xE802U)
#define ISOUDS_IOCTL_VENTPWRCTRL		(0xE803U)

#define ISOUDS_IOCTL_FRTHEATPWR			0
#define ISOUDS_IOCTL_DRVHEATPWR			1
#define ISOUDS_IOCTL_PSGHEATPWR			2

#define ISOUDS_IOCTL_FRTVENTPWR			0
#define ISOUDS_IOCTL_DRVVENTPWR			1
#define ISOUDS_IOCTL_PSGVENTPWR			2

#define ISOUDS_IOCTL_REARHEATPWR		0
#define ISOUDS_IOCTL_RLHEATPWR			1
#define ISOUDS_IOCTL_RRHEATPWR			2

/****************************** External CANks of global variables ************/
extern ISOUDS_IOCntrlCfg_t ISOUDS_IOCntrlCfg_Tbl[ISOUDS_IOContrlMaxSubFun];
/****************************** External CANks of global constants ************/

/*******************************************************************************
**                                      FUNCTIONS                              *
*******************************************************************************/

/********************************** Function Declarations **********************/
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
uint8_t ISOUDS_IOControlParameterSupp(uint8_t IOcontrlParam, uint8_t RoutineIDIndex);

/*******************************************************************************
** Function                 : ISOUDS_IOCntrlPreCondCheck
**
** Description              : Checks the pre conditions for Routine control
**
** Parameters 				: None
**
**
** Return value             : RetVal : Pre condition validity
*******************************************************************************/
extern uint8_t ISOUDS_IOCntrlPreCondCheck(void);

/***************************************************************************************************
** Function                 : ISOUDS_Get_IOContrlMaxSubFun

** Description              : Return the Number of ID configured for IO control

** Paramete           		: None

** Return value             : retVal : Number of IO control IDs Supported

** Remarks                  : None
***************************************************************************************************/
extern uint8_t ISOUDS_Get_IOContrlMaxSubFun(void);


#endif /* ISOUDS_IOCNTRL_CFG_H */

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
#ifndef ISOUDS_RDDRCINF_CFG_H
#define ISOUDS_RDDRCINF_CFG_H


/************************************* Inclusion files ************************/

/************************** Declaration of global symbol and constants ****************************/

/********************************* Declaration of global macros ***************/
#define ISOUDS_RdDTCMaxSubFun		(4U)
/********************************* Declaration of global types ****************/


typedef enum
{
	reportNumberOfDTCByStatusMask = 0x01,
	reportDTCByStatusMask = 0x02,
	reportDTCSnapshotIdentification = 0x03,
	reportDTCSnapshotRecordByDTCNumber = 0x4,
	reportDTCStoredDataByRecordNumber = 0x5,
	reportDTCExtDataRecordByDTCNumber = 0x6,
	reportNumberOfDTCBySeverityMaskRecord = 0x7,
	reportDTCBySeverityMaskRecord = 0x8,
	reportSeverityInformationOfDTC = 0x9,
	reportSupportedDTC = 0x0A,
	reportFirstTestFailedDTC = 0x0B,
	reportFirstConfirmedDTC = 0x0C,
	reportMostRecentTestFailedDTC = 0x0D,
	reportMostRecentConfirmedDTC = 0x0E,
	reportMirrorMemoryDTCByStatusMask = 0x0F,
	reportMirrorMemoryDTCExtDataRecordByDTCNumber = 0x10,
	reportNumberOfMirrorMemoryDTCByStatusMask = 0x11,
	reportNumberOfEmissionsOBDDTCByStatusMask = 0x12,
	reportEmissionsOBDDTCByStatusMask = 0x13,
	reportDTCFaultDetectionCounter = 0x14,
	reportDTCWithPermanentStatus = 0x15,
	reportDTCExtDataRecordByRecordNumber = 0x16,
	reportUserDefMemoryDTCByStatusMask = 0x17,
	reportUserDefMemoryDTCSnapshotRecordByDTCNumber = 0x18,
	reportUserDefMemoryDTCExtDataRecordByDTCNumber = 0x19,
	reportWWHOBDDTCByMaskRecord = 0x42,
	reportWWHOBDDTCWithPermanentStatus = 0x55
}ISOUDS_RdDTCSubfn_e;

typedef struct
{
	ISOUDS_RdDTCSubfn_e Subfunction;
	uint8_t SubfnLen;
	uint8_t SuptdSession;
	uint8_t SecAccssSup;
	uint8_t SecAccssLevl;
	uint8_t (*RdDTCInf_funPtr) (uint8_t *Data, uint16_t *RespLen);/*Function pointer*/
}ISOUDS_RdDTCCfg_t;

/****************************** External CANks of global variables ************/
extern ISOUDS_RdDTCCfg_t ISOUDS_RdDTCCfg_Tbl[ISOUDS_RdDTCMaxSubFun];
/****************************** External CANks of global constants ************/

/*******************************************************************************
**                                      FUNCTIONS                              *
*******************************************************************************/

/********************************** Function Declarations **********************/

/*******************************************************************************
** Function                 : ISOUDS_RdDTCPreCondCheck
**
** Description              : Checks the pre conditions for Read DTC
**
** Parameters 				: None
**
**
** Return value             : RetVal : Pre condition validity
*******************************************************************************/
extern uint8_t ISOUDS_RdDTCPreCondCheck(void);
#endif /* ISOUDS_RDDRCINF_CFG_H */

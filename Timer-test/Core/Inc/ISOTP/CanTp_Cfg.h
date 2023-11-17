/***************************************************************************************************
** Copyright (c) 2018 Embitel
**
** This software is the property of Embitel.
** It can not be used or duplicated without Embitel.
**
** -------------------------------------------------------------------------------------------------
** File Name    : ISOTP_Cfg.c
** Module name  : Can Transport layer configuration file.
** -------------------------------------------------------------------------------------------------
**
** Description  : Provides configuration of CAN TP layer.
**
** -------------------------------------------------------------------------------------------------
**
** Documentation reference : None
**
****************************************************************************************************
** R E V I S I O N H I S T O R Y
****************************************************************************************************
** V01.00
** - Baseline for CANTP module
**
***************************************************************************************************/
/* To avoid multi-inclusions */
#ifndef ISOTP_CFG_H
#define ISOTP_CFG_H

/************************************* Inclusion files ********************************************/
#include <stdint.h>
/********************************* Declaration of global macros ***********************************/
/********************************* Declaration of global types ************************************/
/****************************** External links of global variables ********************************/
/****************************** External links of global constants ********************************/

/************************** Declaration of global symbol and constants ****************************/
/* The periodic scheduling interval of iso15765 in units of 0.1 ms */
#define     ISOTP_PERIOD_SCHED      	(5U)

#define		ISOTP_NORMAL_ADD 			(0U)
#define		ISOTP_NORMAL_FIXED_ADD		(1U)
#define		ISOTP_EXTENDED_ADD			(2U)
#define		ISOTP_MIXED_ADD				(3U)
#define		ISOTP_ADDRESSING			ISOTP_NORMAL_ADD



#if ((ISOTP_ADDRESSING == ISOTP_NORMAL_ADD) || (ISOTP_ADDRESSING == ISOTP_NORMAL_FIXED_ADD))
#define		ISOTP_ADD_MODE_OFST				0x00U
#elif (ISOTP_ADDRESSING == ISOTP_EXTENDED_ADD)
#define		ISOTP_ADD_MODE_OFST				0x01U
#define		ISOTP_SOURCE_ADDRESS			(0x12U)
#define		ISOTP_DEST_ADDRESS				(0x34U)
#else
#define		ISOTP_ADD_MODE_OFST				0x01U
#define		ISOTP_ADDRESS_EXTENSION			(0x12U)
#define		ISOTP_SOURCE_ADDRESS			ISOTP_ADDRESS_EXTENSION
#define		ISOTP_DEST_ADDRESS				ISOTP_ADDRESS_EXTENSION
#endif

/* iso15765 buffer size */
#define     ISOTP_BUFFSIZE           (4095U)

/* Flow control block size */
#define     ISOTP_FCBS               (0x08U)

/* Padding data value */
#define     ISOTP_PADDATA_VAL         0xAA
/* Flow control minimum segmentation time */
#define     ISOTP_FCSTMIN            (20U)

/* Maximum number of FC.Wait frame transmissions */


/* Sender timeout values */
#define     ISOTP_NAS_TIMEOUT_MS      (900U)    /* N_As timeout value in ms */
#define     ISOTP_NBS_TIMEOUT_MS      (900U)    /* N_Bs timeout value in ms */
#define     ISOTP_NCS_TIMEOUT_MS      (900U)    /* N_Cs timeout value in ms */

/* Receiver timeout values */
#define     ISOTP_NAR_TIMEOUT_MS      (900U)    /* N_Ar timeout value in ms */
#define     ISOTP_NBR_TIMEOUT_MS      (900U)    /* N_Br timeout value in ms */
#define     ISOTP_NCR_TIMEOUT_MS      (900U)    /* N_Cr timeout value in ms */

/* Padding related values. */
#define     ISOTP_PAD_REQUIRED        0x00U
#define     ISOTP_PAD_NOTREQ          0x01U

#define     ISOTP_ST_PADDING          ISOTP_PAD_REQUIRED


/* Timeout Table Size. */
#define     ISOTP_TIMEOUT_TAB         0x02


typedef enum
{
	ISOTP_FUNCTIONALREQ = 1,
	ISOTP_PHYSICALREQ = 2
}ISOTP_ReqType;

typedef struct
{
    uint8_t frmInfo;                    /* Byte #1 of PCI */
    uint8_t seqNum;                     /* Sequence number (for Segmented frames) */
    uint16_t nBytes;                    /* total number of bytes */
    uint8_t tpBuff[ISOTP_BUFFSIZE];  /* data buffer */
    ISOTP_ReqType ReqType;
}ISOTP_CfgType;

extern uint32_t ISOTP_TxMesgID;
extern uint8_t ISOTP_TxMesgID_Type;
extern ISOTP_CfgType ISOTP_FrmCfg;
extern ISOTP_ReqType ISOTP_CheckReqType(uint32_t MesgID, uint8_t MesgType);
extern uint8_t ISOTP_CheckRxMesgID(uint32_t MesgID, uint8_t MesgType);
extern uint8_t ISOTP_CheckTxMesgID(uint32_t MesgID, uint8_t MesgType);
extern void ISOTP_SetRxPhysReqID(uint32_t MesgID, uint8_t MesgType);
extern void ISOTP_SetRxFuncReqID(uint32_t MesgID, uint8_t MesgType);
extern void ISOTP_SetTxmesgMesgID(uint32_t MesgID, uint8_t MesgType);
extern uint32_t ISOTP_GetSchedPeriod(void);
extern uint32_t ISOTP_GetFCSTMIN(void);
extern uint8_t ISOTP_GetPADVal(void);
extern uint8_t ISOTP_GetFCBS(void);
extern uint32_t ISOTP_GetBUFFSIZE(void);
extern uint8_t ISOTP_STPadding(void);

#endif

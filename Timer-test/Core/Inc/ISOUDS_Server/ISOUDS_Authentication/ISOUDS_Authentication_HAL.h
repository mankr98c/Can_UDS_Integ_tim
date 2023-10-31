/***************************************************************************************************
** Copyright (c) 2020 EMBITEL
**
** This software is the property of EMBITEL .
** It can not be used or duplicated without EMBITEL authorization .
**
** -------------------------------------------------------------------------------------------------
** File Name   : ISOUDS_Authetication_HAL.h
** Module Name : UDS
** -------------------------------------------------------------------------------------------------
**
** Description : Authentication Service
**
** -------------------------------------------------------------------------------------------------
**
** Documentation reference :
**
****************************************************************************************************
** R E V I S I O N H I S T O R Y
****************************************************************************************************
** V01.00
** - Baseline for UDS module
**
***************************************************************************************************/

/* To avoid multi-inclusions */
#ifndef ISOUDS_AUTHETICATION_HAL_H
#define ISOUDS_AUTHETICATION_HAL_H

/************************************* Inclusion files ********************************************/
#include "ISOUDS_Server.h"

/************************** Declaration of global symbol and constants ****************************/

/********************************* Declaration of global macros ***********************************/
/* AITHENTICATION NRCs */
#define ISOUDS_CERTIVERIFIALD_INVALIDTIME			(0x50)
#define ISOUDS_CERTIVERIFIALD_INVALIDSIGN			(0x51)
#define ISOUDS_CERTIVERIFIALD_INVALIDCHAINOFTRUST	(0x52)
#define ISOUDS_CERTIVERIFIALD_INVALIDTYPE			(0x53)
#define ISOUDS_CERTIVERIFIALD_INVALIDTFORMAT		(0x54)
#define ISOUDS_CERTIVERIFIALD_INVALIDTCONTENT		(0x55)
#define ISOUDS_CERTIVERIFIALD_INVALIDTSCOPE			(0x56)
#define ISOUDS_CERTIVERIFIALD_INVALIDCERTIFICATE	(0x57)
#define ISOUDS_OWNERSHIPVERIFICATIONFAILED			(0x58)
#define ISOUDS_CHALLENGECALCULATIONFAILED			(0x59)
#define ISOUDS_SETTINGACCESSRIGHTFAILED				(0x5A)
#define ISOUDS_SESSIONCREATIONDERIVATIONFAILED		(0x5B)
#define ISOUDS_CONFIGDATAUSAGEFAILED				(0x5C)
#define ISOUDS_DEAUTHENFAILED						(0x5D)
/********************************* Declaration of global types ************************************/

/****************************** External CANks of global variables ********************************/

/****************************** External CANks of global constants ********************************/

/***************************************************************************************************
**                                      FUNCTIONS                              					   *
***************************************************************************************************/

/********************************** Function definitions ******************************************/

extern uint8_t HAL_DeAuthentication_Cbk(void);

extern uint8_t HAL_VerifyCertiUniDir_Cbk(uint8_t CommConfig, uint16_t CertiClientLen,uint8_t *CertificateClient,
									uint16_t ChallangeClientLen, uint8_t *ChallengeClient);
												
extern uint8_t HAL_VerifyCertiBiDir_cbk(uint8_t CommConfig, uint16_t CertiClientLen,uint8_t *CertificateClient,
												uint16_t ChallangeClientLen, uint8_t *ChallengeClient);
												
extern uint8_t HAL_ProofOfOwnership_Cbk(uint16_t LenProofOwner, uint8_t *ProofOfOwner,
									  uint16_t LenEmphPubKeyClnt, uint8_t *EmphPubKeyClnt);
									  
extern uint8_t HAL_TransmitCertificate_Cbk(uint16_t CertiEvalnID,uint16_t LenofCertiData, 
												uint8_t *CertiData);

extern uint8_t HAL_RequestChallangeforAuthent_Cbk(uint8_t CommConfig, uint8_t LenofAlgoIndictor,
													uint8_t *AlgoIndicator);

extern uint8_t HAL_VerifyProofofOwnerUniDir_Cbk(uint8_t LenOfAlgoIndicator,uint8_t *AlgoIndicator,
												uint16_t LenProofOfOwner,uint8_t *ProofofOwner,
												uint16_t LenChallClint, uint8_t *ChallClint,
												uint16_t LenAddParam, uint8_t *AddParameter);

extern uint8_t HAL_VerifyProofofOwnerBiDir_Cbk(uint8_t LenOfAlgoIndicator,uint8_t *AlgoIndicator,
												uint16_t LenProofOfOwner,uint8_t *ProofofOwner,
												uint16_t LenChallClint, uint8_t *ChallClint,
												uint16_t LenAddParam, uint8_t *AddParameter);

extern uint8_t HAL_AuthenticationConfig_Cbk(void);


extern uint8_t HAL_RespDeauthenticate_API(uint8_t *dataBuff);

extern uint8_t HAL_SendChallServerUiniDir_API(uint16_t LenChaServer, uint8_t *ChallServer, uint16_t LenEphPubKeyServr,
										uint8_t *EphmPubKeyServr);

extern uint8_t HAL_SendChallServerBiDir_API(uint16_t LenChaServer, uint8_t *ChallServer, uint16_t LenCertiServr,
											uint8_t *CertiServr, uint16_t LenProoFOwner, uint8_t *ProoofOwner,
											uint16_t LenEphPubKeyServr,uint8_t *EphmPubKeyServr);

extern uint8_t HAL_SendRespwithSessKey_API(uint16_t LenSessKeyInfo, uint8_t *SessKeyInfo);


extern uint8_t HAL_RespTransCerti_API(uint8_t dataBuff[]);

extern uint8_t HAL_SndChaServerwithAlgoInd_API(uint8_t LenAlgoIndictr,uint8_t *AlgoIndctr, uint16_t LenChaServer, uint8_t *ChallServer,
											uint16_t LenAddParam, uint8_t *NeededAddParam);

extern uint8_t HAL_SndProofOwnerUniDir_API(uint8_t LenAlgoIndictr, uint8_t *AlgoIndctr, uint16_t LenSessionKeyInfo,
															uint8_t *SessionKeyInfo);

extern uint8_t HAL_SndProofOwnerBiDir_API(uint8_t LenAlgoIndictr,uint8_t *AlgoIndctr, uint16_t LenProofOwner, uint8_t *ProofofOwner,
										uint16_t LenSessionKeyInfo, uint8_t *SessionKeyInfo);

extern uint8_t HAL_RespAuthenConfig_API(uint8_t dataBuff[],uint32_t *RespLenth);

#endif  /* _ISOUDS_AUTHETICATION_HAL_H_ */

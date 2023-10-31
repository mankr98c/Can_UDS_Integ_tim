/***************************************************************************************************
** Copyright (c) 2020 EMBITEL
**
** This software is the property of EMBITEL .
** It can not be used or duplicated without EMBITEL authorization .
**
** -------------------------------------------------------------------------------------------------
** File Name   : ISOUDS_Authentication_HAL.c
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

/**************************************** Inclusion files *****************************************/
#include "ISOUDS_Server.h"
#include "ISOUDS_Authentication.h"
#include "ISOUDS_Authentication_Cfg.h"
#include "ISOUDS_Authentication_HAL.h"

#if (ISOUDS_APP_CONFIG == ISOUDS_SERVER)
/********************** Declaration of local symbol and constants *********************************/


/********************************* Declaration of local macros ************************************/

/********************************* Declaration of local types *************************************/

/******************************* Declaration of local variables ***********************************/

/******************************* Declaration of local constants ***********************************/

/****************************** Declaration of exported variables *********************************/

/****************************** Declaration of exported constants *********************************/

/***************************************************************************************************
**                                      FUNCTIONS                             					   *
***************************************************************************************************/

/**************************** Internal functions declarations *************************************/

/******************************** Function definitions ********************************************/

/***************************************************************************************************
** Function                 : HAL_DeAuthentication_Cbk

** Description              : API to dea-uthenticate .

** Parameters 				: None

** Return value             : ISOUDS response code. refer ISOUDS_Server.h
***************************************************************************************************/

extern uint8_t HAL_DeAuthentication_Cbk(void)
{
	/* Response value */
	uint8_t RespVal;
	/* Initialize */
	RespVal = ISOUDS_POSRES;
	/* Return Response value */
	return RespVal;
	
}

/***************************************************************************************************
** Function                 : HAL_VerifyCertiUniDir_Cbk

** Description              : API to Verify Certificate

** Parameters 				: CommConfig : Communication configuration

**							: CertiClientLen : Length of Client Certificate

**							: CertificateClient : Pointer to Client Certificate

**							: ChallangeClientLen : Length of Client Challenge

**							: ChallengeClient : Pointer to Client Challenge

**							: RespLenth : Pointer to get the Length for Response

** Return value             : ISOUDS response code. refer ISOUDS_Server.h
***************************************************************************************************/
uint8_t HAL_VerifyCertiUniDir_Cbk(uint8_t CommConfig, uint16_t CertiClientLen,uint8_t *CertificateClient,
							uint16_t ChallangeClientLen, uint8_t *ChallengeClient)
{
	/* Response value */
	uint8_t RespVal;

	(void)CommConfig;
	(void)CertiClientLen;
	(void)CertificateClient;
	(void)ChallangeClientLen;
	(void)ChallengeClient;

	/* Initialize */
	RespVal = ISOUDS_POSRES;

	/* Return Response value */
	return RespVal;
}

/***************************************************************************************************
** Function                 : HAL_VerifyCertiBiDir_cbk

** Description              : API to Verify Certificate

** Parameters 				:  CommConfig : Communication configuration

**							: CertiClientLen : Length of Client Certificate

**							: CertificateClient : Pointer to Client Certificate

**							: ChallangeClientLen : Length of Client Challenge

**							: ChallengeClient : Pointer to Client Challange

**							: RespLenth : Pointer to get the Length for Response

** Return value             : ISOUDS response code. refer ISOUDS_Server.h
***************************************************************************************************/

uint8_t HAL_VerifyCertiBiDir_cbk(uint8_t CommConfig, uint16_t CertiClientLen,uint8_t *CertificateClient,
									  uint16_t ChallangeClientLen, uint8_t *ChallengeClient)
{
	/* Response value */
	uint8_t RespVal;

	(void)CommConfig;
	(void)CertiClientLen;
	(void)CertificateClient;
	(void)ChallangeClientLen;
	(void)ChallengeClient;

	/* Initialize */
	RespVal = ISOUDS_POSRES;


	/* Return Response value */
	return RespVal;
	
}


/***************************************************************************************************
** Function                 : HAL_ProofOfOwnership_Cbk

** Description              : API to verify proof of Ownership

** Parameters 				: LenProofOwner : Length of Proof of Ownership

**							: ProofOfOwner : Pointer to Proof of Ownership

**							: LenEmphPubKeyClnt : Length of Emphermal Public key Client

**							: EmphPubKeyClnt : Pointer to Emphermal Public key Client

**							: RespLenth : Pointer to get the Length for Response

** Return value             : ISOUDS response code. refer ISOUDS_Server.h
***************************************************************************************************/
uint8_t HAL_ProofOfOwnership_Cbk(uint16_t LenProofOwner, uint8_t *ProofOfOwner,
									  uint16_t LenEmphPubKeyClnt, uint8_t *EmphPubKeyClnt)
{
	/* Response value */
	uint8_t RespVal;

	(void)LenProofOwner;
	(void)ProofOfOwner;
	(void)LenEmphPubKeyClnt;
	(void)EmphPubKeyClnt;

	/* Initialize */
	RespVal = ISOUDS_POSRES;

	/* Return Response value */
	return RespVal;
	
}

/***************************************************************************************************
** Function                 : HAL_TransmitCertificate_Cbk

** Description              : API to Transmit certificate

** Parameters 				: CertiEvalnID : Certificate Evaluation Identifier

**							: LenofCertiData : Length of Certificate Data

**							: CertiData : Pointer to Certificate Data

**							: RespLenth : Pointer to get the Length for Response

** Return value             : ISOUDS response code. refer ISOUDS_Server.h
***************************************************************************************************/
uint8_t HAL_TransmitCertificate_Cbk(uint16_t CertiEvalnID,uint16_t LenofCertiData,
												uint8_t *CertiData)
{
	/* Response value */
	uint8_t RespVal;

	(void)CertiEvalnID;
	(void)LenofCertiData;
	(void)CertiData;

	/* Initialise */
	RespVal = ISOUDS_POSRES;
	/* Resturn Resposne value */
	return RespVal;
	
}

/***************************************************************************************************
** Function                 : HAL_RequestChallangeforAuthent_Cbk

** Description              : API Request challage for authentication

** Parameters 				: CommConfig : Communication Configuration Parameter

**							: AlgoIndicator : Pointer to Algorithm Indicator

**							: RespLenth : Pointer to get the Length for Response

** Return value             : ISOUDS response code. refer ISOUDS_Server.h
***************************************************************************************************/
uint8_t HAL_RequestChallangeforAuthent_Cbk(uint8_t CommConfig, uint8_t LenofAlgoIndictor,
											uint8_t *AlgoIndicator)
{
	/* Response value */
	uint8_t RespVal;

	(void)CommConfig;
	(void)LenofAlgoIndictor;
	(void)AlgoIndicator;

	/* Initialize */
	RespVal = ISOUDS_POSRES;
	/* Return Response value */
	return RespVal;
	
	
}

/***************************************************************************************************
** Function                 : HAL_VerifyProofofOwnerUniDir_Cbk

** Description              : API to Verify Proof of Ownership client unidirection

** Parameters 				: AlgoIndicator : Pointer to Algorithm Indicator

**							: LenProofOfOwner : Length of Proof of Ownership

**							: ProofofOwner : Pointer to Proof of Ownership

**							: ChallangeClientLen : Length of Client Challenge

**							: ChallengeClient : Pointer to Client Challange

**							: LenAddParam : Length of Additional parameter

**							: AddParameter : Pointer to Additional Parameter

**							: RespLenth : Pointer to get the Length for Response

** Return value             : ISOUDS response code. refer ISOUDS_Server.h
***************************************************************************************************/
uint8_t HAL_VerifyProofofOwnerUniDir_Cbk(uint8_t LenOfAlgoIndicator,uint8_t *AlgoIndicator,
										uint16_t LenProofOfOwner,uint8_t *ProofofOwner,uint16_t LenChallClint,
										uint8_t *ChallClint,uint16_t LenAddParam, uint8_t *AddParameter)
{
	/* Response value */
	uint8_t RespVal;

	(void)LenOfAlgoIndicator;
	(void)AlgoIndicator;
	(void)LenProofOfOwner;
	(void)ProofofOwner;
	(void)LenChallClint;
	(void)ChallClint;
	(void)LenAddParam;
	(void)AddParameter;
	/* Initialise */
	RespVal = ISOUDS_POSRES;
	/* Resturn Resposne value */
	return RespVal;
	
	
}

/***************************************************************************************************
** Function                 : HAL_VerifyProofofOwnerBiDir_Cbk

** Description              : API to Verify Proof of Ownership client Bidirection

** Parameters 				: AlgoIndicator : Pointer to Algorithm Indicator

**							: LenProofOfOwner : Length of Proof of Ownership

**							: ProofofOwner : Pointer to Proof of Ownership

**							: ChallangeClientLen : Length of Client Challenge

**							: ChallengeClient : Pointer to Client Challange

**							: LenAddParam : Length of Additional parameter

**							: AddParameter : Pointer to Additional Parameter

**							: RespLenth : Pointer to get the Length for Response

** Return value             : ISOUDS response code. refer ISOUDS_Server.h
***************************************************************************************************/
uint8_t HAL_VerifyProofofOwnerBiDir_Cbk(uint8_t LenOfAlgoIndicator,uint8_t *AlgoIndicator,uint16_t LenProofOfOwner,
								uint8_t *ProofofOwner,uint16_t LenChallClint, uint8_t *ChallClint,
								uint16_t LenAddParam, uint8_t *AddParameter)
{
	/* Response value */
	uint8_t RespVal;

	(void)LenOfAlgoIndicator;
	(void)AlgoIndicator;
	(void)LenProofOfOwner;
	(void)ProofofOwner;
	(void)LenChallClint;
	(void)ChallClint;
	(void)LenAddParam;
	(void)AddParameter;
	/* Initialise */
	RespVal = ISOUDS_POSRES;
	/* Resturn Resposne value */
	return RespVal;
	
	
}

/***************************************************************************************************
** Function                 : HAL_AuthenticationConfig_Cbk

** Description              : API to Authetication Configuration

** Parameters 				: None

** Return value             : ISOUDS response code. refer ISOUDS_Server.h
***************************************************************************************************/
uint8_t HAL_AuthenticationConfig_Cbk(void)
{
	/* Response value */
	uint8_t RespVal;
	/* Initialise */
	RespVal = ISOUDS_POSRES;
	/* Resturn Resposne value */
	return RespVal;
	
}


/***************************************************************************************************
** Function                 : HAL_RespDeauthenticate_API 

** Description              : API to Send respose to Deauthentication

** Parameters 				: RespLenth : Response Length

** Return value             : ISOUDS response code. refer ISOUDS_Server.h
***************************************************************************************************/

uint8_t HAL_RespDeauthenticate_API(uint8_t *dataBuff)
{
	/* Response value */
	uint8_t RespVal;
	/* Initialize */
	(void)dataBuff;

	RespVal = ISOUDS_POSRES;
	/* Return Response value */
	return RespVal;
}
										
/***************************************************************************************************
** Function                 : HAL_SendChallServerUiniDir_API 

** Description              : API to Send Challenge server

** Parameters 				: LenChaServer : Length of Challenge Server

**							: ChallServer : Pointer to Challenge Server

**							: LenEphPubKeyServr : Length of Ephermal Public key Server

**							: EphmPubKeyServr : Pointer to Ephermal Public key Server

** Return value             : ISOUDS response code. refer ISOUDS_Server.h
***************************************************************************************************/
uint8_t HAL_SendChallServerUiniDir_API(uint16_t LenChaServer, uint8_t *ChallServer, uint16_t LenEphPubKeyServr,
										uint8_t *EphmPubKeyServr)
{
	/* Response value */
	uint8_t RespVal;
	(void)LenChaServer;
	(void)ChallServer;
	(void)LenEphPubKeyServr;
	(void)EphmPubKeyServr;


	/* Initialise */
	RespVal = ISOUDS_POSRES;
	/* Resturn Resposne value */
	return RespVal;
}

/***************************************************************************************************
** Function                 : HAL_SendChallServerBiDir_API

** Description              : API to Send Challenge server

** Parameters 				: LenChaServer : Length of Challenge Server

**							: ChallServer : Pointer to Challenge Server

**							: LenCertiServr : Length of Certiicate Server

**							: CertiServr : Pointer to Certificate Server

**							: LenProoFOwner : Length of Proof of Ownership Server

**							: ProoofOwner : Pointer to Proof of Ownership Server

**							: LenEphPubKeyServr : Length of Ephermal Public key Server

**							: EphmPubKeyServr : Pointer to Ephermal Public key Server

** Return value             : ISOUDS response code. refer ISOUDS_Server.h
***************************************************************************************************/
uint8_t HAL_SendChallServerBiDir_API(uint16_t LenChaServer, uint8_t *ChallServer, uint16_t LenCertiServr,
											uint8_t *CertiServr, uint16_t LenProoFOwner, uint8_t *ProoofOwner,
											uint16_t LenEphPubKeyServr,uint8_t *EphmPubKeyServr)
{
	/* Response value */
	uint8_t RespVal;
	(void)LenChaServer;
	(void)ChallServer;
	(void)LenCertiServr;
	(void)CertiServr;
	(void)LenProoFOwner;
	(void)ProoofOwner;
	(void)LenEphPubKeyServr;
	(void)EphmPubKeyServr;

	/* Initialise */
	RespVal = ISOUDS_POSRES;
	/* Resturn Resposne value */
	return RespVal;
}
		
/***************************************************************************************************
** Function                 : ISOUDS_SendRespwithSessKey_API

** Description              : API to SendChallenge server

** Parameters 				: LenSessKeyInfo : Length of Session Key Info

**							: SessKeyInfo : Pointer to Session Key Info


** Return value             : ISOUDS response code. refer ISOUDS_Server.h
***************************************************************************************************/
uint8_t HAL_SendRespwithSessKey_API(uint16_t LenSessKeyInfo, uint8_t *SessKeyInfo)
{
	/* Response value */
	uint8_t RespVal;
	/* Initialise */
	(void)LenSessKeyInfo;
	(void)SessKeyInfo;

	RespVal = ISOUDS_POSRES;
	/* Resturn Resposne value */
	return RespVal;
}


/***************************************************************************************************
** Function                 : HAL_RespTransCerti_API 

** Description              : API to Send Response to Transmit certificate

** Parameters 				: RespLenth : Response Length

** Return value             : ISOUDS response code. refer ISOUDS_Server.h
***************************************************************************************************/

uint8_t HAL_RespTransCerti_API(uint8_t dataBuff[])
{
	/* Response value */
	uint8_t RespVal;

	(void)dataBuff;
	/* Initialise */
	RespVal = ISOUDS_POSRES;

	/* Resturn Resposne value */
	return RespVal;
}

					
/***************************************************************************************************
** Function                 : HAL_SndChaServerwithAlgoInd_API

** Description              : API to SendChallenge server with Algoirthm Indicator

** Parameters 				: AlgoIndctr : Pointer to Algorithm Indicator

**							: LenChaServer : Length of Challenge Server

**							: ChallServer : Pointer to Challenge Server

**							: LenAddParam : Length of Needed Additional Parameter

**							: NeededAddParam : Pointer to Needed Additional Parameter

** Return value             : ISOUDS response code. refer ISOUDS_Server.h
***************************************************************************************************/
uint8_t HAL_SndChaServerwithAlgoInd_API(uint8_t LenAlgoIndictr,uint8_t *AlgoIndctr, uint16_t LenChaServer, uint8_t *ChallServer,
											uint16_t LenAddParam, uint8_t *NeededAddParam)
{
	/* Response value */
	uint8_t RespVal;
	(void)LenAlgoIndictr;
	(void)AlgoIndctr;
	(void)LenChaServer;
	(void)ChallServer;
	(void)LenAddParam;
	(void)NeededAddParam;


	/* Initialise */
	RespVal = ISOUDS_POSRES;
	
	/* Resturn Resposne value */
	return RespVal;
	
}



/***************************************************************************************************
** Function                 : HAL_SndProofOwnerUniDir_API

** Description              : API to Send Proof of Ownership Uni Dir

** Parameters 				: AlgoIndctr : Pointer to Algorithm Indicator

**							: LenSessionKeyInfo : Length of Session Key Info

**							: SessionKeyInfo : Pointer to Session Key Info

** Return value             : ISOUDS response code. refer ISOUDS_Server.h
***************************************************************************************************/
uint8_t HAL_SndProofOwnerUniDir_API(uint8_t LenAlgoIndictr,uint8_t *AlgoIndctr, uint16_t LenSessionKeyInfo,
															uint8_t *SessionKeyInfo)
{
	/* Response value */
	uint8_t RespVal;
	(void)LenAlgoIndictr;
	(void)AlgoIndctr;
	(void)LenSessionKeyInfo;
	(void)SessionKeyInfo;

	/* Initialise */
	RespVal = ISOUDS_POSRES;
	
	/* Resturn Resposne value */
	return RespVal;
}

/***************************************************************************************************
** Function                 : HAL_SndProofOwnerBiDir_API

** Description              : API to Send Proof of Ownership Bi Dir

** Parameters 				: AlgoIndctr : Pointer to Algorithm Indicator

**							: LenProofOwner : Length of Proof of Ownership

**							: ProofofOwner : Pointer to Proof of Ownership

**							: LenSessionKeyInfo : Length of Session Key Info

**							: SessionKeyInfo : Pointer to Session Key Info

** Return value             : ISOUDS response code. refer ISOUDS_Server.h
***************************************************************************************************/
uint8_t HAL_SndProofOwnerBiDir_API(uint8_t LenAlgoIndictr,uint8_t *AlgoIndctr, uint16_t LenProofOwner, uint8_t *ProofofOwner,
										uint16_t LenSessionKeyInfo, uint8_t *SessionKeyInfo)
{
	/* Response value */
	uint8_t RespVal;
	(void)LenAlgoIndictr;
	(void)AlgoIndctr;
	(void)LenProofOwner;
	(void)ProofofOwner;
	(void)LenSessionKeyInfo;
	(void)SessionKeyInfo;

	/* Initialise */
	RespVal = ISOUDS_POSRES;
	
	/* Resturn Resposne value */
	return RespVal;
	
}

/***************************************************************************************************
** Function                 : HAL_RespAuthenConfig_API 

** Description              : API to Send Response to Authentication Configuration

** Parameters 				: RespLenth : Response Length

** Return value             : ISOUDS response code. refer ISOUDS_Server.h
***************************************************************************************************/

uint8_t HAL_RespAuthenConfig_API(uint8_t dataBuff[],uint32_t *RespLenth)
{
	/* Response value */
	uint8_t RespVal;

	(void)dataBuff;
	/* Initialise */
	RespVal = ISOUDS_POSRES;
	*RespLenth = NO_1;
	/* Resturn Resposne value */
	return RespVal;
}


#endif

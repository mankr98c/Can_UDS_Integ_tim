/***************************************************************************************************
** Copyright (c) 2018 EMBITEL
**
** This software is the property of EMBITEL.
** It can not be used or duplicated without EMBITEL authorization.
**
** -------------------------------------------------------------------------------------------------
** File Name    : ISOUDS_ReqUpld.c
** Module Name  : ISOUDS_ReqUpld
** -------------------------------------------------------------------------------------------------
**
** Description : Values for types defined in ISOUDS_ReqUpld.h will reside in this file.
**
** -------------------------------------------------------------------------------------------------
**
** Documentation reference : EME-17ST013-Xxxxx.01(SWLLD ISOUDS_ReqUpld)
**
****************************************************************************************************
** R E V I S I O N H I S T O R Y
****************************************************************************************************
** V01.00 16/07/2018
** - Baseline Created
**
***************************************************************************************************/

/**************************************** Inclusion files *****************************************/
#include "ISOUDS_Server_Cfg.h"
#include "ISOUDS_ReqUpld_Cfg.h"
#include "ISOUDS_ReqUpld_HAL.h"

#if (ISOUDS_APP_CONFIG == ISOUDS_SERVER)
/********************************* Declaration of local macros ************************************/

/********************************* Declaration of local types *************************************/

/******************************* Declaration of local variables ***********************************/

/******************************* Declaration of local constants ***********************************/

/****************************** Declaration of exported variables *********************************/

/****************************** Declaration of exported constants *********************************/
//TODO need to update
const ISOUDS_ReqUpldType ISOUDS_ReqUpldConfTab[ISOUDS_ReqUpldMaxentries] =
{

	 {
	   1U,	/* if physical value we rgetting then place it here , otherwise keep it as 0,	 Memory Address Length */ 
	   1U,  /*if physical value we rgetting then place it here , otherwise keep it as 0, Memory size Length */
	   0u, /* if physical value we rgetting then place it here , otherwise keep it as 0, , Compression Methods */
	   0u,/* if physical value we rgetting then place it here , otherwise keep it as 0, , Encryption Methods */
	 (PROGRAMMING_SESS ),
	 ISOUDS_TRUE,
	 1,
	 {UnlockedL1},
	 &ISOUDS_ReqUpldReqCbk,/* Function pointer to callback*/
	 },
	 {
	   1U,	/* if physical value we rgetting then place it here , otherwise keep it as 0,	 Memory Address Length */ 
	   2U,  /*if physical value we rgetting then place it here , otherwise keep it as 0, Memory size Length */
	   0u, /* if physical value we rgetting then place it here , otherwise keep it as 0, , Compression Methods */
	   0u,/* if physical value we rgetting then place it here , otherwise keep it as 0, , Encryption Methods */
	 (PROGRAMMING_SESS ),
	 ISOUDS_TRUE,
	 1,
	 {UnlockedL1},
	 &ISOUDS_ReqUpldReqCbk,/* Function pointer to callback*/
	 },
	 {
	   1U,	/* if physical value we rgetting then place it here , otherwise keep it as 0,	 Memory Address Length */ 
	   3U,  /*if physical value we rgetting then place it here , otherwise keep it as 0, Memory size Length */
	   0u, /* if physical value we rgetting then place it here , otherwise keep it as 0, , Compression Methods */
	   0u,/* if physical value we rgetting then place it here , otherwise keep it as 0, , Encryption Methods */
	 (PROGRAMMING_SESS ),
	 ISOUDS_TRUE,
	 1,
	 {UnlockedL1},
	 &ISOUDS_ReqUpldReqCbk,/* Function pointer to callback*/
	 },
	 {
	   1U,	/* if physical value we rgetting then place it here , otherwise keep it as 0,	 Memory Address Length */ 
	   4U,  /*if physical value we rgetting then place it here , otherwise keep it as 0, Memory size Length */
	   0u, /* if physical value we rgetting then place it here , otherwise keep it as 0, , Compression Methods */
	   0u,/* if physical value we rgetting then place it here , otherwise keep it as 0, , Encryption Methods */
	 (PROGRAMMING_SESS ),
	 ISOUDS_TRUE,
	 1,
	 {UnlockedL1},
	 &ISOUDS_ReqUpldReqCbk,/* Function pointer to callback*/
	 },
	 {
	   2U,	/* if physical value we rgetting then place it here , otherwise keep it as 0,	 Memory Address Length */ 
	   1U,  /*if physical value we rgetting then place it here , otherwise keep it as 0, Memory size Length */
	   0u, /* if physical value we rgetting then place it here , otherwise keep it as 0, , Compression Methods */
	   0u,/* if physical value we rgetting then place it here , otherwise keep it as 0, , Encryption Methods */
	 (PROGRAMMING_SESS ),
	 ISOUDS_TRUE,
	 1,
	 {UnlockedL1},
	 &ISOUDS_ReqUpldReqCbk,/* Function pointer to callback*/
	 },
	 {
	   2U,	/* if physical value we rgetting then place it here , otherwise keep it as 0,	 Memory Address Length */ 
	   2U,  /*if physical value we rgetting then place it here , otherwise keep it as 0, Memory size Length */
	   0u, /* if physical value we rgetting then place it here , otherwise keep it as 0, , Compression Methods */
	   0u,/* if physical value we rgetting then place it here , otherwise keep it as 0, , Encryption Methods */
	 (PROGRAMMING_SESS ),
	 ISOUDS_TRUE,
	 1,
	 {UnlockedL1},
	 &ISOUDS_ReqUpldReqCbk,/* Function pointer to callback*/
	 },
	 {
	   2U,	/* if physical value we rgetting then place it here , otherwise keep it as 0,	 Memory Address Length */ 
	   3U,  /*if physical value we rgetting then place it here , otherwise keep it as 0, Memory size Length */
	   0u, /* if physical value we rgetting then place it here , otherwise keep it as 0, , Compression Methods */
	   0u,/* if physical value we rgetting then place it here , otherwise keep it as 0, , Encryption Methods */
	 (PROGRAMMING_SESS ),
	 ISOUDS_TRUE,
	 1,
	 {UnlockedL1},
	 &ISOUDS_ReqUpldReqCbk,/* Function pointer to callback*/
	 },
	 {
	   2U,	/* if physical value we rgetting then place it here , otherwise keep it as 0,	 Memory Address Length */ 
	   4U,  /*if physical value we rgetting then place it here , otherwise keep it as 0, Memory size Length */
	   0u, /* if physical value we rgetting then place it here , otherwise keep it as 0, , Compression Methods */
	   0u,/* if physical value we rgetting then place it here , otherwise keep it as 0, , Encryption Methods */
	 (PROGRAMMING_SESS ),
	 ISOUDS_TRUE,
	 1,
	 {UnlockedL1},
	 &ISOUDS_ReqUpldReqCbk,/* Function pointer to callback*/
	 },
	 {
	   3U,	/* if physical value we rgetting then place it here , otherwise keep it as 0,	 Memory Address Length */ 
	   1U,  /*if physical value we rgetting then place it here , otherwise keep it as 0, Memory size Length */
	   0u, /* if physical value we rgetting then place it here , otherwise keep it as 0, , Compression Methods */
	   0u,/* if physical value we rgetting then place it here , otherwise keep it as 0, , Encryption Methods */
	 (PROGRAMMING_SESS ),
	 ISOUDS_TRUE,
	 1,
	 {UnlockedL1},
	 &ISOUDS_ReqUpldReqCbk,/* Function pointer to callback*/
	 },
	 {
	   3U,	/* if physical value we rgetting then place it here , otherwise keep it as 0,	 Memory Address Length */ 
	   2U,  /*if physical value we rgetting then place it here , otherwise keep it as 0, Memory size Length */
	   0u, /* if physical value we rgetting then place it here , otherwise keep it as 0, , Compression Methods */
	   0u,/* if physical value we rgetting then place it here , otherwise keep it as 0, , Encryption Methods */
	 (PROGRAMMING_SESS ),
	 ISOUDS_TRUE,
	 1,
	 {UnlockedL1},
	 &ISOUDS_ReqUpldReqCbk,/* Function pointer to callback*/
	 },
	 {
	   3U,	/* if physical value we rgetting then place it here , otherwise keep it as 0,	 Memory Address Length */ 
	   3U,  /*if physical value we rgetting then place it here , otherwise keep it as 0, Memory size Length */
	   0u, /* if physical value we rgetting then place it here , otherwise keep it as 0, , Compression Methods */
	   0u,/* if physical value we rgetting then place it here , otherwise keep it as 0, , Encryption Methods */
	 (PROGRAMMING_SESS ),
	 ISOUDS_TRUE,
	 1,
	 {UnlockedL1},
	 &ISOUDS_ReqUpldReqCbk,/* Function pointer to callback*/
	 },
	 {
	   3U,	/* if physical value we rgetting then place it here , otherwise keep it as 0,	 Memory Address Length */ 
	   4U,  /*if physical value we rgetting then place it here , otherwise keep it as 0, Memory size Length */
	   0u, /* if physical value we rgetting then place it here , otherwise keep it as 0, , Compression Methods */
	   0u,/* if physical value we rgetting then place it here , otherwise keep it as 0, , Encryption Methods */
	 (PROGRAMMING_SESS ),
	 ISOUDS_TRUE,
	 1,
	 {UnlockedL1},
	 &ISOUDS_ReqUpldReqCbk,/* Function pointer to callback*/
	 },
	 {
	   4U,	/* if physical value we rgetting then place it here , otherwise keep it as 0,	 Memory Address Length */ 
	   1U,  /*if physical value we rgetting then place it here , otherwise keep it as 0, Memory size Length */
	   0u, /* if physical value we rgetting then place it here , otherwise keep it as 0, , Compression Methods */
	   0u,/* if physical value we rgetting then place it here , otherwise keep it as 0, , Encryption Methods */
	 (PROGRAMMING_SESS ),
	 ISOUDS_TRUE,
	 1,
	 {UnlockedL1},
	 &ISOUDS_ReqUpldReqCbk,/* Function pointer to callback*/
	 },
	 {
	   4U,	/* if physical value we rgetting then place it here , otherwise keep it as 0,	 Memory Address Length */ 
	   2U,  /*if physical value we rgetting then place it here , otherwise keep it as 0, Memory size Length */
	   0u, /* if physical value we rgetting then place it here , otherwise keep it as 0, , Compression Methods */
	   0u,/* if physical value we rgetting then place it here , otherwise keep it as 0, , Encryption Methods */
	 (PROGRAMMING_SESS ),
	 ISOUDS_TRUE,
	 1,
	 {UnlockedL1},
	 &ISOUDS_ReqUpldReqCbk,/* Function pointer to callback*/
	 },
	 {
	   4U,	/* if physical value we rgetting then place it here , otherwise keep it as 0,	 Memory Address Length */ 
	   3U,  /*if physical value we rgetting then place it here , otherwise keep it as 0, Memory size Length */
	   0u, /* if physical value we rgetting then place it here , otherwise keep it as 0, , Compression Methods */
	   0u,/* if physical value we rgetting then place it here , otherwise keep it as 0, , Encryption Methods */
	 (PROGRAMMING_SESS ),
	 ISOUDS_TRUE,
	 1,
	 {UnlockedL1},
	 &ISOUDS_ReqUpldReqCbk,/* Function pointer to callback*/
	 },
	 {
	   4U,	/* if physical value we rgetting then place it here , otherwise keep it as 0,	 Memory Address Length */ 
	   4U,  /*if physical value we rgetting then place it here , otherwise keep it as 0, Memory size Length */
	   0u, /* if physical value we rgetting then place it here , otherwise keep it as 0, , Compression Methods */
	   0u,/* if physical value we rgetting then place it here , otherwise keep it as 0, , Encryption Methods */
	 (PROGRAMMING_SESS ),
	 ISOUDS_TRUE,
	 1,
	 {UnlockedL1},
	 &ISOUDS_ReqUpldReqCbk,/* Function pointer to callback*/
	 },
	 {
	   4U,	/* if physical value we rgetting then place it here , otherwise keep it as 0,	 Memory Address Length */ 
	   5U,  /*if physical value we rgetting then place it here , otherwise keep it as 0, Memory size Length */
	   0u, /* if physical value we rgetting then place it here , otherwise keep it as 0, , Compression Methods */
	   0u,/* if physical value we rgetting then place it here , otherwise keep it as 0, , Encryption Methods */
	 (PROGRAMMING_SESS ),
	 ISOUDS_TRUE,
	 1,
	 {UnlockedL1},
	 &ISOUDS_ReqUpldReqCbk,/* Function pointer to callback*/
	 },



};

/****************************************************************************************************/

#endif

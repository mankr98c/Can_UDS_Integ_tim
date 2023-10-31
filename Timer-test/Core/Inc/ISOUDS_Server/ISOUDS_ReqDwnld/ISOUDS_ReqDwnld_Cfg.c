/***************************************************************************************************
** Copyright (c) 2018 EMBITEL
**
** This software is the property of EMBITEL.
** It can not be used or duplicated without EMBITEL authorization.
**
** -------------------------------------------------------------------------------------------------
** File Name    : ISOUDS_ReqDwnld.c
** Module Name  : ISOUDS_ReqDwnld
** -------------------------------------------------------------------------------------------------
**
** Description : Values for types defined in ISOUDS_ReqDwnld.h will reside in this file.
**
** -------------------------------------------------------------------------------------------------
**
** Documentation reference : EME-17ST013-Xxxxx.01(SWLLD ISOUDS_ReqDwnld)
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
#include "ISOUDS_ReqDwnld_Cfg.h"
#include "ISOUDS_ReqDwnld_HAL.h"

#if (ISOUDS_APP_CONFIG == ISOUDS_SERVER)
/********************************* Declaration of local macros ************************************/
  //need to check
/********************************* Declaration of local types *************************************/

/******************************* Declaration of local variables ***********************************/

/******************************* Declaration of local constants ***********************************/

/****************************** Declaration of exported variables *********************************/

/****************************** Declaration of exported constants *********************************/

const ISOUDS_ReqDwnldType ISOUDS_ReqDwnldConfTab[ISOUDS_ReqDwnldMaxentries] =
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
	 &ISOUDS_ReqDwnldReqCbk,/* Function pointer to callback*/
	 },
	 {
	   1U,	/* if physical value we rgetting then place it here , otherwise keep it as 0,	 Memory Address Length */ 
	   2U,  /*if physical value we rgetting then place it here , otherwise keep it as 0, Memory size Length */
	   0u, /* if physical value we rgetting then place it here , otherwise keep it as 0, , Compression Methods */
	   0u,/* if physical value we rgetting then place it here , otherwise keep it as 0, , Encryption Methods */
	 (PROGRAMMING_SESS ),
	 ISOUDS_TRUE,
	 1,
	 {UnlockedL4},
	 &ISOUDS_ReqDwnldReqCbk,/* Function pointer to callback*/
	 },
	 {
	   1U,	/* if physical value we rgetting then place it here , otherwise keep it as 0,	 Memory Address Length */ 
	   3U,  /*if physical value we rgetting then place it here , otherwise keep it as 0, Memory size Length */
	   0u, /* if physical value we rgetting then place it here , otherwise keep it as 0, , Compression Methods */
	   0u,/* if physical value we rgetting then place it here , otherwise keep it as 0, , Encryption Methods */
	 (PROGRAMMING_SESS ),
	 ISOUDS_TRUE,
	 1,
	 {UnlockedL4},
	 &ISOUDS_ReqDwnldReqCbk,/* Function pointer to callback*/
	 },
	 {
	   1U,	/* if physical value we rgetting then place it here , otherwise keep it as 0,	 Memory Address Length */ 
	   4U,  /*if physical value we rgetting then place it here , otherwise keep it as 0, Memory size Length */
	   0u, /* if physical value we rgetting then place it here , otherwise keep it as 0, , Compression Methods */
	   0u,/* if physical value we rgetting then place it here , otherwise keep it as 0, , Encryption Methods */
	 (PROGRAMMING_SESS ),
	 ISOUDS_TRUE,
	 1,
	 {UnlockedL4},
	 &ISOUDS_ReqDwnldReqCbk,/* Function pointer to callback*/
	 },
	 {
	   2U,	/* if physical value we rgetting then place it here , otherwise keep it as 0,	 Memory Address Length */ 
	   1U,  /*if physical value we rgetting then place it here , otherwise keep it as 0, Memory size Length */
	   0u, /* if physical value we rgetting then place it here , otherwise keep it as 0, , Compression Methods */
	   0u,/* if physical value we rgetting then place it here , otherwise keep it as 0, , Encryption Methods */
	 (PROGRAMMING_SESS ),
	 ISOUDS_TRUE,
	 1,
	 {UnlockedL4},
	 &ISOUDS_ReqDwnldReqCbk,/* Function pointer to callback*/
	 },
	 {
	   2U,	/* if physical value we rgetting then place it here , otherwise keep it as 0,	 Memory Address Length */ 
	   2U,  /*if physical value we rgetting then place it here , otherwise keep it as 0, Memory size Length */
	   0u, /* if physical value we rgetting then place it here , otherwise keep it as 0, , Compression Methods */
	   0u,/* if physical value we rgetting then place it here , otherwise keep it as 0, , Encryption Methods */
	 (PROGRAMMING_SESS ),
	 ISOUDS_TRUE,
	 1,
	 {UnlockedL4},
	 &ISOUDS_ReqDwnldReqCbk,/* Function pointer to callback*/
	 },
	 {
	   2U,	/* if physical value we rgetting then place it here , otherwise keep it as 0,	 Memory Address Length */ 
	   3U,  /*if physical value we rgetting then place it here , otherwise keep it as 0, Memory size Length */
	   0u, /* if physical value we rgetting then place it here , otherwise keep it as 0, , Compression Methods */
	   0u,/* if physical value we rgetting then place it here , otherwise keep it as 0, , Encryption Methods */
	 (PROGRAMMING_SESS ),
	 ISOUDS_TRUE,
	 1,
	 {UnlockedL4},
	 &ISOUDS_ReqDwnldReqCbk,/* Function pointer to callback*/
	 },
	 {
	   2U,	/* if physical value we rgetting then place it here , otherwise keep it as 0,	 Memory Address Length */ 
	   4U,  /*if physical value we rgetting then place it here , otherwise keep it as 0, Memory size Length */
	   0u, /* if physical value we rgetting then place it here , otherwise keep it as 0, , Compression Methods */
	   0u,/* if physical value we rgetting then place it here , otherwise keep it as 0, , Encryption Methods */
	 (PROGRAMMING_SESS ),
	 ISOUDS_TRUE,
	 1,
	 {UnlockedL4},
	 &ISOUDS_ReqDwnldReqCbk,/* Function pointer to callback*/
	 },
	 {
	   3U,	/* if physical value we rgetting then place it here , otherwise keep it as 0,	 Memory Address Length */ 
	   1U,  /*if physical value we rgetting then place it here , otherwise keep it as 0, Memory size Length */
	   0u, /* if physical value we rgetting then place it here , otherwise keep it as 0, , Compression Methods */
	   0u,/* if physical value we rgetting then place it here , otherwise keep it as 0, , Encryption Methods */
	 (PROGRAMMING_SESS ),
	 ISOUDS_TRUE,
	 1,
	 {UnlockedL4},
	 &ISOUDS_ReqDwnldReqCbk,/* Function pointer to callback*/
	 },
	 {
	   3U,	/* if physical value we rgetting then place it here , otherwise keep it as 0,	 Memory Address Length */ 
	   2U,  /*if physical value we rgetting then place it here , otherwise keep it as 0, Memory size Length */
	   0u, /* if physical value we rgetting then place it here , otherwise keep it as 0, , Compression Methods */
	   0u,/* if physical value we rgetting then place it here , otherwise keep it as 0, , Encryption Methods */
	 (PROGRAMMING_SESS ),
	 ISOUDS_TRUE,
	 1,
	 {UnlockedL4},
	 &ISOUDS_ReqDwnldReqCbk,/* Function pointer to callback*/
	 },
	 {
	   3U,	/* if physical value we rgetting then place it here , otherwise keep it as 0,	 Memory Address Length */ 
	   3U,  /*if physical value we rgetting then place it here , otherwise keep it as 0, Memory size Length */
	   0u, /* if physical value we rgetting then place it here , otherwise keep it as 0, , Compression Methods */
	   0u,/* if physical value we rgetting then place it here , otherwise keep it as 0, , Encryption Methods */
	 (PROGRAMMING_SESS ),
	 ISOUDS_TRUE,
	 1,
	 {UnlockedL4},
	 &ISOUDS_ReqDwnldReqCbk,/* Function pointer to callback*/
	 },
	 {
	   3U,	/* if physical value we rgetting then place it here , otherwise keep it as 0,	 Memory Address Length */ 
	   4U,  /*if physical value we rgetting then place it here , otherwise keep it as 0, Memory size Length */
	   0u, /* if physical value we rgetting then place it here , otherwise keep it as 0, , Compression Methods */
	   0u,/* if physical value we rgetting then place it here , otherwise keep it as 0, , Encryption Methods */
	 (PROGRAMMING_SESS ),
	 ISOUDS_TRUE,
	 1,
	 {UnlockedL4},
	 &ISOUDS_ReqDwnldReqCbk,/* Function pointer to callback*/
	 },
	 {
	   4U,	/* if physical value we rgetting then place it here , otherwise keep it as 0,	 Memory Address Length */ 
	   1U,  /*if physical value we rgetting then place it here , otherwise keep it as 0, Memory size Length */
	   0u, /* if physical value we rgetting then place it here , otherwise keep it as 0, , Compression Methods */
	   0u,/* if physical value we rgetting then place it here , otherwise keep it as 0, , Encryption Methods */
	 (PROGRAMMING_SESS ),
	 ISOUDS_TRUE,
	 1,
	 {UnlockedL4},
	 &ISOUDS_ReqDwnldReqCbk,/* Function pointer to callback*/
	 },
	 {
	   4U,	/* if physical value we rgetting then place it here , otherwise keep it as 0,	 Memory Address Length */ 
	   2U,  /*if physical value we rgetting then place it here , otherwise keep it as 0, Memory size Length */
	   0u, /* if physical value we rgetting then place it here , otherwise keep it as 0, , Compression Methods */
	   0u,/* if physical value we rgetting then place it here , otherwise keep it as 0, , Encryption Methods */
	 (PROGRAMMING_SESS ),
	 ISOUDS_TRUE,
	 1,
	 {UnlockedL4},
	 &ISOUDS_ReqDwnldReqCbk,/* Function pointer to callback*/
	 },
	 {
	   4U,	/* if physical value we rgetting then place it here , otherwise keep it as 0,	 Memory Address Length */ 
	   3U,  /*if physical value we rgetting then place it here , otherwise keep it as 0, Memory size Length */
	   0u, /* if physical value we rgetting then place it here , otherwise keep it as 0, , Compression Methods */
	   0u,/* if physical value we rgetting then place it here , otherwise keep it as 0, , Encryption Methods */
	 (PROGRAMMING_SESS ),
	 ISOUDS_TRUE,
	 1,
	 {UnlockedL4},
	 &ISOUDS_ReqDwnldReqCbk,/* Function pointer to callback*/
	 },
	 {
	   4U,	/* if physical value we rgetting then place it here , otherwise keep it as 0,	 Memory Address Length */ 
	   4U,  /*if physical value we rgetting then place it here , otherwise keep it as 0, Memory size Length */
	   0u, /* if physical value we rgetting then place it here , otherwise keep it as 0, , Compression Methods */
	   0u,/* if physical value we rgetting then place it here , otherwise keep it as 0, , Encryption Methods */
	 (PROGRAMMING_SESS ),
	 ISOUDS_TRUE,
	 1,
	 {UnlockedL4},
	 &ISOUDS_ReqDwnldReqCbk,/* Function pointer to callback*/
	 },
	 {
	   4U,	/* if physical value we rgetting then place it here , otherwise keep it as 0,	 Memory Address Length */ 
	   5U,  /*if physical value we rgetting then place it here , otherwise keep it as 0, Memory size Length */
	   0u, /* if physical value we rgetting then place it here , otherwise keep it as 0, , Compression Methods */
	   0u,/* if physical value we rgetting then place it here , otherwise keep it as 0, , Encryption Methods */
	 (PROGRAMMING_SESS ),
	 ISOUDS_TRUE,
	 1,
	 {UnlockedL4},
	 &ISOUDS_ReqDwnldReqCbk,/* Function pointer to callback*/
	 },


};

/****************************************************************************************************/

#endif

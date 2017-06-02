/*
*********************************************************************************************************
*                                                uC/OS-II
*                                          The Real-Time Kernel
*
*                          (c) Copyright 1992-2002, Jean J. Labrosse, Weston, FL
*                                           All Rights Reserved
*
* File : uCOS_II.C
* By   : Jean J. Labrosse
*********************************************************************************************************
*/

#define  OS_GLOBALS                           /* Declare GLOBAL variables                              */
#include "../h/ucos/includes.h"


#define  OS_MASTER_FILE                       /* Prevent the following files from including includes.h */
#include "os_core.h"
#include "os_flag.h"
#include "os_mbox.h"
#include "os_mem.h"
#include "os_mutex.h"
#include "os_q.h"
#include "os_sem.h"
#include "os_task.h"
#include "os_time.h"

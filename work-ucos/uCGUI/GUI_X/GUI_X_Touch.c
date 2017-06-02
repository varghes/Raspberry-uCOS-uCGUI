/*
*********************************************************************************************************
*                                                uC/GUI
*                        Universal graphic software for embedded applications
*
*                       (c) Copyright 2002, Micrium Inc., Weston, FL
*                       (c) Copyright 2002, SEGGER Microcontroller Systeme GmbH
*
*              µC/GUI is protected by international copyright laws. Knowledge of the
*              source code may not be used to write a similar product. This file may
*              only be used in accordance with a license and should not be redistributed
*              in any way. We appreciate your understanding and fairness.
*
----------------------------------------------------------------------
File        : GUI_TOUCH_X.C
Purpose     : Config / System dependent externals for GUI
---------------------------END-OF-HEADER------------------------------
*/

#include "../core/GUI.h"
#include "../core/GUI_X.h"
//#include "Touch_s.h"
//#include "touch.h"
//#include "gt811.h"
//extern u16 TP_X,TP_Y;

void GUI_TOUCH_X_ActivateX(void) 
{
}

void GUI_TOUCH_X_ActivateY(void) 
{
}

int  GUI_TOUCH_X_MeasureX(void) 
{
//	GT811_Scan(); varghese
	//return ctp_dev.x[0];
return 0;
	}

int  GUI_TOUCH_X_MeasureY(void) 
{
//	GT811_Scan(); //varghese
	//return ctp_dev.y[0];
return 0;
	}



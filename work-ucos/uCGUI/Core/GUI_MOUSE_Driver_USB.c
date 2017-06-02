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
File        : GUITOUCH.C
Purpose     : Touch screen manager
----------------------------------------------------------------------
This module handles the touch screen. It is configured in the file
GUITouch.conf.h (Should be located in the Config\ directory).
----------------------------------------------------------------------
*/

#include "LCD_Private.h"      /* private modul definitions & config */
#include "GUI_Protected.h"
#include "../csud/usbd.h"
#include "../csud/mouse.h"
/*********************************************************************
*
*       Static data
*
**********************************************************************
*/

static int  _ScreenX              = 0;    /* x-pos              */
static int  _ScreenY              = 0;    /* y-pos              */
static int  _NumBytesInBuffer     = 0;    /* bytes in rx buffer */
static U8   _Buttons              = 0;    /* button status      */
static U8   _abInBuffer[3];               /* mouse rx buffer    */

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/
/*********************************************************************
*
*       _EvaPacket
*
* Purpose:
*   Process data packet from mouse:
*
*             | D7    D6    D5    D4    D3    D2    D1    D0
*   ----------+----------------------------------------------
*   1st byte  | --    --    Y-    X-     1    --    LB    RB
*   2nd byte  | X7    X6    X5    X4    X3    X2    X1    X0
*   3rd byte  | Y7    Y6    Y5    Y4    Y3    Y2    Y1    Y0
*/


/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       GUI_MOUSE_DRIVER_PS2_OnRx
*
* Purpose:
*   Mouse receive interrupt handler. The PS2 mouse interrupt gets
*   in three bytes from the mouse, then wakes up the mouse LSR.
*/
int _Xscr=0;

void GUI_MOUSE_DRIVER_USB_OnRx(void) {
	u32 mouseAddress;
	  GUI_PID_STATE State;
	bool click;
	UsbCheckForChange();
	if(MouseCount() != 0)
		{
			mouseAddress= MouseGetAddress(0);
			MousePoll(mouseAddress);	
			_ScreenY = MouseGetPositionY(mouseAddress);
			_ScreenX = MouseGetPositionX(mouseAddress);
            //   _ScreenX=_Xscr++;
              //  _ScreenY=_Xscr;
			click =MouseGetButtonIsPressed(mouseAddress,MouseDeviceButtonLeft);
			 /* check min/max positions */    
			if (_ScreenX < 0) 
			{
				_ScreenX = 0;
			}
			else if (_ScreenX > LCD_XSIZE-1)
			{
				_ScreenX = LCD_XSIZE-1;
			}
			if (_ScreenY < 0) 
			{
			_ScreenY = 0;
			} 
			else if (_ScreenY > LCD_YSIZE-1) 
			{
				_ScreenY = LCD_YSIZE-1;
			}
			if(click)// only left button is working
			{
				_Buttons=0x2;
			}
			else
			{
				_Buttons=0x0;
			}
			/* signal new mouse data */
			State.x       = _ScreenX;
			State.y       = _ScreenY;
			State.Pressed = _Buttons;
			GUI_MOUSE_StoreState(&State);
			//GUI_DispDecAt(_ScreenX, 400, 100, 4);
			//GUI_DispDecAt(_ScreenY, 470, 100, 4);
			}
}

/*********************************************************************
*
*       GUI_MOUSE_DRIVER_PS2_Init
*/
void GUI_MOUSE_DRIVER_USB_Init(void) {
 UsbInitialise(); 
}

/*************************** End of file ****************************/

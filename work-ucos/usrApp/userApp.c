//#include <stdint.h>
#include "uart.h"
#include "ucos/includes.h"
//#include "../bsp/framebuffer.h"
//#include "string.h"
#include "../uCGUI/WM/WM.h"
#include "../uCGUI/Widget/DIALOG.h"
#include "../uCGUI/Widget/LISTBOX.h"
#include "../uCGUI/Widget/EDIT.h"
#include "../uCGUI/Widget/SLIDER.h"
#include "../uCGUI/Widget/FRAMEWIN.h"
//#include "../uCGUI/Core/GUI.h"
// mouse handle

//mouse
static const char FromSample[] = "sample";


static const GUI_WIDGET_CREATE_INFO aDialogCreate[] = 
{
  { FRAMEWIN_CreateIndirect, "Dialog", 0,               10,   10, 162, 214, FRAMEWIN_CF_MOVEABLE},
  { BUTTON_CreateIndirect,   "OK",     GUI_ID_OK,       90,    5,  60,  20 },
  { BUTTON_CreateIndirect,   "Cancel", GUI_ID_CANCEL,   90,   30,  60,  20 },
  { TEXT_CreateIndirect,     "LText",  0,                5,   59,  43,  15, TEXT_CF_LEFT  },
  { TEXT_CreateIndirect,     "RText",  0,                5,   79,  43,  15, TEXT_CF_RIGHT },
  { TEXT_CreateIndirect,     "Hex",    0,                5,   99,  48,  15, TEXT_CF_LEFT  },
  { TEXT_CreateIndirect,     "Bin",    0,                5,  119,  48,  15, TEXT_CF_LEFT  },
  { EDIT_CreateIndirect,     "",       GUI_ID_EDIT0,    50,   59, 100,  15, EDIT_CF_LEFT,  50 },
  { EDIT_CreateIndirect,     "",       GUI_ID_EDIT1,    50,   79, 100,  15, EDIT_CF_RIGHT, 50 },
  { EDIT_CreateIndirect,     "",       GUI_ID_EDIT2,    50,   99, 100,  15, EDIT_CF_RIGHT, 6  },
  { EDIT_CreateIndirect,     "",       GUI_ID_EDIT3,    50,  119, 100,  15, EDIT_CF_LEFT,  0  },
  { LISTBOX_CreateIndirect,  "",       GUI_ID_LISTBOX0,  5,    5,  75,  45, 0, 0 },
  { SLIDER_CreateIndirect,   NULL,     GUI_ID_SLIDER1,   5,  140, 100,  20, 0, 0 },
  { SLIDER_CreateIndirect,   NULL,     GUI_ID_SLIDER0,   5,  165, 145,  26, 0, 0 }
};


static const GUI_WIDGET_CREATE_INFO aDialogCreate2[] = 
{
  { FRAMEWIN_CreateIndirect, "Dialog", 0,               10,   10, 162, 214, FRAMEWIN_CF_MOVEABLE},
  { BUTTON_CreateIndirect,   "OK",     GUI_ID_OK,       90,    5,  60,  20 },
  { BUTTON_CreateIndirect,   "Cancel", GUI_ID_CANCEL,   90,   30,  60,  20 },
  { TEXT_CreateIndirect,     "LText",  0,                5,   59,  43,  15, TEXT_CF_LEFT  },
  { TEXT_CreateIndirect,     "RText",  0,                5,   79,  43,  15, TEXT_CF_RIGHT },
  { TEXT_CreateIndirect,     "Hex",    0,                5,   99,  48,  15, TEXT_CF_LEFT  },
  { TEXT_CreateIndirect,     "Bin",    0,                5,  119,  48,  15, TEXT_CF_LEFT  },
  { EDIT_CreateIndirect,     "",       GUI_ID_EDIT0,    50,   59, 100,  15, EDIT_CF_LEFT,  50 },
  { EDIT_CreateIndirect,     "",       GUI_ID_EDIT1,    50,   79, 100,  15, EDIT_CF_RIGHT, 50 },
  { EDIT_CreateIndirect,     "",       GUI_ID_EDIT2,    50,   99, 100,  15, EDIT_CF_RIGHT, 6  },
  { EDIT_CreateIndirect,     "",       GUI_ID_EDIT3,    50,  119, 100,  15, EDIT_CF_LEFT,  0  },
  { LISTBOX_CreateIndirect,  "",       GUI_ID_LISTBOX0,  5,    5,  75,  45, 0, 0 },
  { SLIDER_CreateIndirect,   NULL,     GUI_ID_SLIDER1,   5,  140, 100,  20, 0, 0 },
  { SLIDER_CreateIndirect,   NULL,     GUI_ID_SLIDER0,   5,  165, 145,  26, 0, 0 }
};
static const GUI_ConstString _apListBox[] = 
{
  "English", "Deutsch", "French", "Japanese", "Italiano", NULL
};


static void _cbCallback(WM_MESSAGE * pMsg)
{
  WM_HWIN hWin = pMsg->hWin;
  int NCode, Id;
	WM_HWIN hListBox;
  switch (pMsg->MsgId) 
	{
    case WM_INIT_DIALOG:
         /* Initialize all widgets */
         EDIT_SetText(WM_GetDialogItem(hWin, GUI_ID_EDIT0), "EDIT widget 0");
         EDIT_SetText(WM_GetDialogItem(hWin, GUI_ID_EDIT1), "EDIT widget 1");
         EDIT_SetHexMode(WM_GetDialogItem(hWin, GUI_ID_EDIT2), 0x1234, 0, 0xffffff);
         EDIT_SetBinMode(WM_GetDialogItem(hWin, GUI_ID_EDIT3), 0x1234, 0, 0xffff);
         hListBox = WM_GetDialogItem(hWin, GUI_ID_LISTBOX0);
         LISTBOX_SetText(hListBox, _apListBox);
         SCROLLBAR_CreateAttached(hListBox, SCROLLBAR_CF_VERTICAL);
         break;
    case WM_KEY:
         switch (((WM_KEY_INFO*)(pMsg->Data.p))->Key) 
		     {
            //case GUI_KEY_ESCAPE: GUI_EndDialog(hWin, 1); break;
            //case GUI_KEY_ENTER:  GUI_EndDialog(hWin, 0); break;
         }
         break;
    case WM_NOTIFY_PARENT:
         Id    = WM_GetId(pMsg->hWinSrc);    // Id of widget 
         NCode = pMsg->Data.v;               // Notification code 
         switch (NCode) 
		     {
           case WM_NOTIFICATION_RELEASED:    // React only if released 
                if (Id == GUI_ID_OK)     
                { 
									//GUI_MessageBox("Button OK","Caption/Title",GUI_MESSAGEBOX_CF_MOVEABLE);
                   //GUI_EndDialog(hWin, 0); 
                } // OK Button 
                if (Id == GUI_ID_CANCEL) { GUI_EndDialog(hWin, 1); } // Cancel Button 
                break;
           case WM_NOTIFICATION_SEL_CHANGED: // Selection changed 
                FRAMEWIN_SetText(hWin, "Dialog - sel changed");
                break;
           default:
                FRAMEWIN_SetText(hWin, "Dialog - notification received");
         }
         break;
     default:
         WM_DefaultProc(pMsg);
  }
}

void GUIDEMO_Dialog(void) 
{
  WM_HWIN hWin;
  /* Use memory devices for all windows */
  WM_SetCreateFlags(WM_CF_MEMDEV);
  WM_EnableMemdev(WM_HBKWIN);
  WM_SetDesktopColor(GUI_GREEN);
  GUI_CURSOR_Show();
  hWin = GUI_CreateDialogBox(aDialogCreate, GUI_COUNTOF(aDialogCreate), _cbCallback, 0, 0, 0);
	//NVIC_EnableIRQ(TIM3_IRQn);         // Enable interrupt from TIM3 (NVIC level)
	while(WM_IsWindow(hWin))
	{
	//	GUI_TOUCH_Exec();
		GUI_Delay(100);
	}
	WM_DeleteWindow(hWin);
}



static void _cbCallback2(WM_MESSAGE * pMsg)
{
  WM_HWIN hWin = pMsg->hWin;
  int NCode, Id;
	WM_HWIN hListBox;
  switch (pMsg->MsgId) 
	{
    case WM_INIT_DIALOG:
         /* Initialize all widgets */
         EDIT_SetText(WM_GetDialogItem(hWin, GUI_ID_EDIT0), "EDIT widget 0");
         EDIT_SetText(WM_GetDialogItem(hWin, GUI_ID_EDIT1), "EDIT widget 1");
         EDIT_SetHexMode(WM_GetDialogItem(hWin, GUI_ID_EDIT2), 0x1234, 0, 0xffffff);
         EDIT_SetBinMode(WM_GetDialogItem(hWin, GUI_ID_EDIT3), 0x1234, 0, 0xffff);
         hListBox = WM_GetDialogItem(hWin, GUI_ID_LISTBOX0);
         LISTBOX_SetText(hListBox, _apListBox);
         SCROLLBAR_CreateAttached(hListBox, SCROLLBAR_CF_VERTICAL);
         break;
    case WM_KEY:
         switch (((WM_KEY_INFO*)(pMsg->Data.p))->Key) 
		     {
            //case GUI_KEY_ESCAPE: GUI_EndDialog(hWin, 1); break;
            //case GUI_KEY_ENTER:  GUI_EndDialog(hWin, 0); break;
         }
         break;
    case WM_NOTIFY_PARENT:
         Id    = WM_GetId(pMsg->hWinSrc);    // Id of widget 
         NCode = pMsg->Data.v;               // Notification code 
         switch (NCode) 
		     {
           case WM_NOTIFICATION_RELEASED:    // React only if released 
                if (Id == GUI_ID_OK)     
                { 
									//GUI_MessageBox("Button OK","Caption/Title",GUI_MESSAGEBOX_CF_MOVEABLE);
                   //GUI_EndDialog(hWin, 0); 
                } // OK Button 
                if (Id == GUI_ID_CANCEL) { GUI_EndDialog(hWin, 1); } // Cancel Button 
                break;
           case WM_NOTIFICATION_SEL_CHANGED: // Selection changed 
                FRAMEWIN_SetText(hWin, "Dialog - sel changed");
                break;
           default:
                FRAMEWIN_SetText(hWin, "Dialog - notification received");
         }
         break;
     default:
         WM_DefaultProc(pMsg);
  }
}

void GUIDEMO_Dialog2(void) 
{
  WM_HWIN hWin;
  /* Use memory devices for all windows */
  WM_SetCreateFlags(WM_CF_MEMDEV);
  WM_EnableMemdev(WM_HBKWIN);
  WM_SetDesktopColor(GUI_GREEN);
  GUI_CURSOR_Show();
  hWin = GUI_CreateDialogBox(aDialogCreate2, GUI_COUNTOF(aDialogCreate2), _cbCallback2, 0, 200, 200);
	//NVIC_EnableIRQ(TIM3_IRQn);         // Enable interrupt from TIM3 (NVIC level)
	while(WM_IsWindow(hWin))
	{
	//	GUI_TOUCH_Exec();
		GUI_Delay(100);
	}
	WM_DeleteWindow(hWin);
}

void userApp2(void * args)
{

	while(1)
	{
	    uart_string("OS app1\r\n");
		GUIDEMO_Dialog();
	}
}
// mouse scan routine
void userApp1(void * args)
{
	GUI_MOUSE_DRIVER_USB_Init();
	while(1)
	{
		//uart_string("OS app2\r\n");
		//console_write("OS app2\r\n");
	GUI_MOUSE_DRIVER_USB_OnRx();
	OSTimeDly(300);	
	}

}

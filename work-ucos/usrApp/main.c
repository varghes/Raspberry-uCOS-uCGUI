#include "uart.h"
#include "regs.h"
#include "timer.h"
//#include <stdint.h>
#include "ucos/includes.h"
//#include "../bsp/framebuffer.h"
//#include "string.h"
//Csonsole headers 
#include "../h/interrupts.h"
#include "../uCGUI/WM/WM.h"
#include "../uCGUI/Widget/DIALOG.h"
#include "../uCGUI/Widget/LISTBOX.h"
#include "../uCGUI/Widget/EDIT.h"
#include "../uCGUI/Widget/SLIDER.h"
#include "../uCGUI/Widget/FRAMEWIN.h"

#include "../csud/usbd.h"



OS_STK  userAppTaskStk1[1000];
OS_STK  userAppTaskStk2[1000];

extern void userApp1(void *);
extern void userApp2(void *);

void main()
{
	//FramebufferInit();
	uart_init();
	uart_string("UART init");
 	GUI_Init();
   GUI_DispString("Hello world!");
	InitInterruptController();
	DisableInterrupts();
	timer_init();

	OSInit();
	OSTaskCreate(userApp1, (void *) 0, &userAppTaskStk1[1000-1],5);
	OSTaskCreate(userApp2, (void *) 0, &userAppTaskStk2[1000-1],6);
	OSStart();
//console_write("OS Start\r\n");
	while(1);
}

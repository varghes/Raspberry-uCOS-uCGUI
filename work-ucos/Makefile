PREFIX=C:/Program Files/GNU Tools ARM Embedded/4.7 2013q3/lib/gcc/arm-none-eabi/4.7.4
ARMGNU ?= arm-none-eabi
#INCLUDEPATH ?= "D:/Study/Raspberry/uCProject/working/work-ucos/h"
INCLUDEPATH ?= h
FONTS_DIR=fonts
ICONS_DIR=icons
TARGET ?= NONE

LIB_ARM_V6 ?= 1
LIB_BCM2835 ?= 1
LIB_DWC ?= 1
#-std=gnu99
COPS = -Wall -O2 -lm -lgcc  -std=gnu99 -nostdlib -nostartfiles -ffreestanding -mcpu=arm1176jzf-s -I  $(INCLUDEPATH)
COPSW = -Wall -fpack-struct -Wno-packed-bitfield-compat -fshort-wchar -O2 -lm -lgcc  -std=gnu99 -nostdlib -nostartfiles -ffreestanding -mcpu=arm1176jzf-s -I  $(INCLUDEPATH)

gcc : kernel.img

OBJS = build/startup.o 

OBJS += Logo_24b_260x194.o
OBJS += font_mono_8x16.o
OBJS += build/uart.o
OBJS += build/timer.o
OBJS += build/interrupts.o
OBJS += build/mailbox.o
OBJS += build/string.o 
OBJS +=build/rpiframe.o 
OBJS +=build/LCD_GUI.o 

OBJS +=build/armv6.o
OBJS +=build/broadcom2835.o
OBJS +=build/configuration.o
OBJS +=build/designware20.o
OBJS +=build/hid.o
OBJS +=build/hub.o
OBJS +=build/keyboard.o
OBJS +=build/mouse.o
OBJS +=build/platform.o
OBJS +=build/roothub.o
OBJS +=build/usbd.o


OBJS += build/OS_Cpu_a.o
OBJS += build/OS_Cpu_c.o

OBJS += build/ucos_ii.o


OBJS += build/GUIAAArc.o
OBJS += build/GUIAAChar2.o
OBJS += build/GUIAAChar4.o
OBJS += build/GUIAAChar.o
OBJS += build/GUIAACircle.o
OBJS += build/GUIAALib.o
OBJS += build/GUIAALine.o
OBJS += build/GUIAAPoly.o
OBJS += build/GUIAAPolyOut.o

OBJS += build/LCDP111.o
OBJS += build/LCDP222.o
OBJS += build/LCDP233.o
OBJS += build/LCDP323.o
OBJS += build/LCDP332.o
OBJS += build/LCDP444_12.o
OBJS += build/LCDP444_12_1.o
OBJS += build/LCDP444_16.o
OBJS += build/LCDP555.o
OBJS += build/LCDP556.o
OBJS += build/LCDP565.o
OBJS += build/LCDP655.o
OBJS += build/LCDP8666.o
OBJS += build/LCDP8666_1.o
OBJS += build/LCDPM233.o
OBJS += build/LCDPM323.o
OBJS += build/LCDPM332.o
OBJS += build/LCDPM444_12.o
OBJS += build/LCDPM444_16.o
OBJS += build/LCDPM555.o
OBJS += build/LCDPM556.o
OBJS += build/LCDPM565.o
OBJS += build/LCDPM655.o

OBJS += build/LCDP0.o
OBJS += build/LCDP2.o
OBJS += build/LCDP4.o


OBJS +=build/GUI__AddSpaceHex.o
OBJS +=build/GUI__CalcTextRect.o
OBJS +=build/GUI__DivideRound32.o
OBJS +=build/GUI__DivideRound.o
OBJS +=build/GUI__GetFontSizeY.o
OBJS +=build/GUI__GetNumChars.o
OBJS +=build/GUI__HandleEOLine.o
OBJS +=build/GUI__IntersectRect.o
OBJS +=build/GUI__IntersectRects.o
OBJS +=build/GUI__memset16.o
OBJS +=build/GUI__memset.o
OBJS +=build/GUI__Read.o
OBJS +=build/GUI__ReduceRect.o
OBJS +=build/GUI__SetText.o
OBJS +=build/GUI__strcmp.o
OBJS +=build/GUI__strlen.o
OBJS +=build/GUI__Wrap.o
OBJS +=build/GUI_AddBin.o
OBJS +=build/GUI_AddDec.o
OBJS +=build/GUI_AddDecMin.o
OBJS +=build/GUI_AddDecShift.o
OBJS +=build/GUI_AddHex.o
OBJS +=build/GUI_AddKeyMsgHook.o
OBJS +=build/GUI_ALLOC_AllocInit.o
OBJS +=build/GUI_ALLOC_AllocZero.o
OBJS +=build/GUI_BMP.o
OBJS +=build/GUI_BMP_Serialize.o
OBJS +=build/GUI_CalcColorDist.o
OBJS +=build/GUI_ClearRectEx.o
OBJS +=build/GUI_Color2VisColor.o
OBJS +=build/GUI_CursorArrowL.o
OBJS +=build/GUI_CursorArrowLI.o
OBJS +=build/GUI_CursorArrowLPx.o
OBJS +=build/GUI_CursorArrowM.o
OBJS +=build/GUI_CursorArrowMI.o
OBJS +=build/GUI_CursorArrowMPx.o
OBJS +=build/GUI_CursorArrowS.o
OBJS +=build/GUI_CursorArrowSI.o
OBJS +=build/GUI_CursorArrowSPx.o
OBJS +=build/GUI_CursorCrossL.o
OBJS +=build/GUI_CursorCrossLI.o
OBJS +=build/GUI_CursorCrossLPx.o
OBJS +=build/GUI_CursorCrossM.o
OBJS +=build/GUI_CursorCrossMI.o
OBJS +=build/GUI_CursorCrossMPx.o
OBJS +=build/GUI_CursorCrossS.o
OBJS +=build/GUI_CursorCrossSI.o
OBJS +=build/GUI_CursorCrossSPx.o
OBJS +=build/GUI_CursorHeaderM.o
OBJS +=build/GUI_CursorHeaderMI.o
OBJS +=build/GUI_CursorHeaderMPx.o
OBJS +=build/GUI_CursorPal.o
OBJS +=build/GUI_CursorPalI.o
OBJS +=build/GUI_DispBin.o
OBJS +=build/GUI_DispCEOL.o
OBJS +=build/GUI_DispChar.o
OBJS +=build/GUI_DispChars.o
OBJS +=build/GUI_DispHex.o
OBJS +=build/GUI_DispString.o
OBJS +=build/GUI_DispStringAt.o
OBJS +=build/GUI_DispStringAtCEOL.o
OBJS +=build/GUI_DispStringHCenter.o
OBJS +=build/GUI_DispStringInRect.o
OBJS +=build/GUI_DispStringInRectEx.o
OBJS +=build/GUI_DispStringInRectMax.o
OBJS +=build/GUI_DispStringLen.o
OBJS +=build/GUI_DrawBitmap.o
OBJS +=build/GUI_DrawBitmapEx.o
OBJS +=build/GUI_DrawBitmapExp.o
OBJS +=build/GUI_DrawBitmapMag.o
OBJS +=build/GUI_DrawFocusRect.o
OBJS +=build/GUI_DrawGraph.o
OBJS +=build/GUI_DrawHLine.o
OBJS +=build/GUI_DrawPie.o
OBJS +=build/GUI_DrawPolyline.o
OBJS +=build/GUI_DrawRectEx.o
OBJS +=build/GUI_DrawVLine.o
OBJS +=build/GUI_ErrorOut.o
OBJS +=build/GUI_Exec.o
OBJS +=build/GUI_FillPolygon.o
OBJS +=build/GUI_FillRect.o
OBJS +=build/GUI_FillRectEx.o
OBJS +=build/GUI_GetBitmapPixelColor.o
OBJS +=build/GUI_GetBitmapPixelIndex.o
OBJS +=build/GUI_GetClientRect.o
OBJS +=build/GUI_GetColor.o
OBJS +=build/GUI_GetDispPos.o
OBJS +=build/GUI_GetFont.o
OBJS +=build/GUI_GetFontInfo.o
OBJS +=build/GUI_GetFontSizeY.o
OBJS +=build/GUI_GetLineStyle.o
OBJS +=build/GUI_GetStringDistX.o
OBJS +=build/GUI_GetTextAlign.o
OBJS +=build/GUI_GetTextExtend.o
OBJS +=build/GUI_GetTextMode.o
OBJS +=build/GUI_GetVersionString.o
OBJS +=build/GUI_GetYSizeOfFont.o
OBJS +=build/GUI_Goto.o
OBJS +=build/GUI_InitLUT.o
OBJS +=build/GUI_InvertRect.o
OBJS +=build/GUI_IsInFont.o
OBJS +=build/GUI_Log.o
OBJS +=build/GUI_MergeRect.o
OBJS +=build/GUI_MOUSE.o
OBJS +=build/GUI_MOUSE_DriverPS2.o
OBJS +=build/GUI_MOUSE_Driver_USB.o
OBJS +=build/GUI_MoveRect.o
OBJS +=build/GUI_OnKey.o
OBJS +=build/GUI_Pen.o
OBJS +=build/GUI_PID.o
OBJS +=build/GUI_RectsIntersect.o
OBJS +=build/GUI_SaveContext.o
OBJS +=build/GUI_SelectLayer.o
OBJS +=build/GUI_SelectLCD.o
OBJS +=build/GUI_SetColor.o
OBJS +=build/GUI_SetColorIndex.o
OBJS +=build/GUI_SetDecChar.o
OBJS +=build/GUI_SetDefault.o
OBJS +=build/GUI_SetDrawMode.o
OBJS +=build/GUI_SetFont.o
OBJS +=build/GUI_SetLBorder.o
OBJS +=build/GUI_SetLineStyle.o
OBJS +=build/GUI_SetLUTColor.o
OBJS +=build/GUI_SetLUTColorEx.o
OBJS +=build/GUI_SetLUTEntry.o
OBJS +=build/GUI_SetOrg.o
OBJS +=build/GUI_SetPixelIndex.o
OBJS +=build/GUI_SetTextAlign.o
OBJS +=build/GUI_SetTextMode.o
OBJS +=build/GUI_SetTextStyle.o
OBJS +=build/GUI_SIF.o
OBJS +=build/GUI_SIF_Prop.o
OBJS +=build/GUI_TOUCH.o
OBJS +=build/GUI_UC.o
OBJS +=build/GUI_UC_DispString.o
OBJS +=build/GUI_UC_EncodeNone.o
OBJS +=build/GUI_UC_EncodeUTF8.o
OBJS +=build/GUI_WaitEvent.o
OBJS +=build/GUI_WaitKey.o
OBJS +=build/GUI_Warn.o
OBJS +=build/GUIAlloc.o
OBJS +=build/GUI2DLib.o
OBJS +=build/GUIArc.o
OBJS +=build/GUIChar.o
OBJS +=build/GUICharLine.o
OBJS +=build/GUICharM.o
OBJS +=build/GUICharP.o
OBJS +=build/GUICirc.o
OBJS +=build/GUIColor2Index.o
OBJS +=build/GUICore.o
OBJS +=build/GUICurs.o
OBJS +=build/GUIEncJS.o
OBJS +=build/GUIIndex2Color.o
OBJS +=build/GUIPolyE.o
OBJS +=build/GUIPolyM.o
OBJS +=build/GUIPolyR.o
OBJS +=build/GUIRealloc.o 
OBJS +=build/GUIStream.o 
OBJS +=build/GUITask.o
OBJS +=build/GUITime.o
OBJS +=build/GUITimer.o
OBJS +=build/GUIUC0.o
OBJS +=build/GUIVal.o
OBJS +=build/GUIValf.o
OBJS +=build/LCD.o
OBJS +=build/LCD_API.o
OBJS +=build/LCD_DrawVLine.o
OBJS +=build/LCD_GetColorIndex.o
OBJS +=build/LCD_GetEx.o 
OBJS +=build/LCD_GetNumDisplays.o
OBJS +=build/LCD_GetPixelColor.o
OBJS +=build/LCD_Index2ColorEx.o
OBJS +=build/LCD_L0_Generic.o 
OBJS +=build/LCD_Mirror.o 
OBJS +=build/LCD_MixColors256.o
OBJS +=build/LCD_Rotate180.o
OBJS +=build/LCD_RotateCCW.o
OBJS +=build/LCD_RotateCW.o 
OBJS +=build/LCD_SelectLCD.o
OBJS +=build/LCD_SetAPI.o
OBJS +=build/LCD_SetClipRectEx.o
OBJS +=build/LCD_UpdateColorIndices.o
OBJS +=build/LCDAA.o
OBJS +=build/LCDColor.o
OBJS +=build/LCDGetP.o 
OBJS +=build/LCDInfo0.o
OBJS +=build/LCDInfo1.o
OBJS +=build/LCDInfo.o
OBJS +=build/LCDL0Delta.o
OBJS +=build/LCDL0Mag.o
OBJS +=build/LCDP1.o
OBJS +=build/LCDP565_Index2Color.o
OBJS +=build/LCDPM565_Index2Color.o
OBJS +=build/LCDRLE4.o
OBJS +=build/LCDRLE8.o


OBJS +=build/F4x6.o  
OBJS +=build/F6x8.o  
OBJS +=build/F08_1.o  
OBJS +=build/F08_ASCII.o  
OBJS +=build/F8x8.o  
OBJS +=build/F8x10_ASCII.o  
OBJS +=build/F8x12_ASCII.o  
OBJS +=build/F8x13_1.o  
OBJS +=build/F8x13_ASCII.o  
OBJS +=build/F8x15B_1.o  
OBJS +=build/F8x15B_ASCII.o  
OBJS +=build/F8x16.o  
OBJS +=build/F10_1.o  
OBJS +=build/F10_ASCII.o  
OBJS +=build/F10S_1.o  
OBJS +=build/F10S_ASCII.o  
OBJS +=build/F13_1.o  
OBJS +=build/F13_ASCII.o  
OBJS +=build/F13B_1.o  
OBJS +=build/F13B_ASCII.o  
OBJS +=build/F13H_1.o  
OBJS +=build/F13H_ASCII.o  
OBJS +=build/F13HB_1.o  
OBJS +=build/F13HB_ASCII.o  
OBJS +=build/F16_1.o  
OBJS +=build/F16_1HK.o  
OBJS +=build/F16_ASCII.o  
OBJS +=build/F16_HK.o  
OBJS +=build/F16B_1.o  
OBJS +=build/F16B_ASCII.o  
OBJS +=build/F24_1.o  
OBJS +=build/F24_ASCII.o  
OBJS +=build/F24B_1.o  
OBJS +=build/F24B_ASCII.o  
OBJS +=build/F32_1.o  
OBJS +=build/F32_ASCII.o  
OBJS +=build/F32B_1.o  
OBJS +=build/F32B_ASCII.o  
OBJS +=build/FComic18B_1.o  
OBJS +=build/FComic18B_ASCII.o  
OBJS +=build/FComic24B_1.o  
OBJS +=build/FComic24B_ASCII.o  
OBJS +=build/FD24x32.o  
OBJS +=build/FD32.o  
OBJS +=build/FD36x48.o  
OBJS +=build/FD48.o  
OBJS +=build/FD48x64.o  
OBJS +=build/FD60x80.o  
OBJS +=build/FD64.o  
OBJS +=build/FD80.o

OBJS +=build/BUTTON.o  
OBJS +=build/BUTTON__SetBitmapObj.o  
OBJS +=build/BUTTON_Bitmap.o  
OBJS +=build/BUTTON_BMP.o  
OBJS +=build/BUTTON_Create.o  
OBJS +=build/BUTTON_CreateIndirect.o  
OBJS +=build/BUTTON_Default.o  
OBJS +=build/BUTTON_Get.o   
OBJS +=build/BUTTON_IsPressed.o  
OBJS +=build/BUTTON_SelfDraw.o  
OBJS +=build/BUTTON_SetTextAlign.o  
OBJS +=build/BUTTON_StreamedBitmap.o  
OBJS +=build/CHECKBOX.o  
OBJS +=build/CHECKBOX_Create.o  
OBJS +=build/CHECKBOX_CreateIndirect.o  
OBJS +=build/CHECKBOX_Default.o  
OBJS +=build/CHECKBOX_GetState.o  
OBJS +=build/CHECKBOX_Image.o  
OBJS +=build/CHECKBOX_IsChecked.o  
OBJS +=build/CHECKBOX_SetBkColor.o  
OBJS +=build/CHECKBOX_SetDefaultImage.o    
OBJS +=build/CHECKBOX_SetFont.o  
OBJS +=build/CHECKBOX_SetImage.o  
OBJS +=build/CHECKBOX_SetNumStates.o  
OBJS +=build/CHECKBOX_SetSpacing.o  
OBJS +=build/CHECKBOX_SetState.o  
OBJS +=build/CHECKBOX_SetText.o  
OBJS +=build/CHECKBOX_SetTextAlign.o  
OBJS +=build/CHECKBOX_SetTextColor.o  
OBJS +=build/DIALOG.o  
OBJS +=build/DROPDOWN.o  
OBJS +=build/DROPDOWN_Create.o  
OBJS +=build/DROPDOWN_CreateIndirect.o    
OBJS +=build/DROPDOWN_DeleteItem.o  
OBJS +=build/DROPDOWN_InsertString.o  
OBJS +=build/DROPDOWN_ItemSpacing.o  
OBJS +=build/DROPDOWN_SetAutoScroll.o  
OBJS +=build/DROPDOWN_SetTextAlign.o    
OBJS +=build/DROPDOWN_SetTextHeight.o  
OBJS +=build/EDIT.o  
OBJS +=build/EDIT_Create.o  
OBJS +=build/EDIT_CreateIndirect.o  
OBJS +=build/EDIT_Default.o    
OBJS +=build/EDIT_GetNumChars.o  
OBJS +=build/EDIT_SetCursorAtChar.o  
OBJS +=build/EDIT_SetInsertMode.o  
OBJS +=build/EDIT_SetpfAddKeyEx.o  
OBJS +=build/EDIT_SetpfUpdateBuffer.o  
OBJS +=build/EDIT_SetSel.o  
OBJS +=build/EDITBin.o  
OBJS +=build/EDITDec.o  
OBJS +=build/EDITFloat.o  
OBJS +=build/EDITHex.o    
OBJS +=build/FRAMEWIN.o  
OBJS +=build/FRAMEWIN__UpdateButtons.o  
OBJS +=build/FRAMEWIN_AddMenu.o  
OBJS +=build/FRAMEWIN_Button.o  
OBJS +=build/FRAMEWIN_ButtonClose.o  
OBJS +=build/FRAMEWIN_ButtonMax.o  
OBJS +=build/FRAMEWIN_ButtonMin.o  
OBJS +=build/FRAMEWIN_Create.o  
OBJS +=build/FRAMEWIN_CreateIndirect.o  
OBJS +=build/FRAMEWIN_Default.o  
OBJS +=build/FRAMEWIN_Get.o  
OBJS +=build/FRAMEWIN_IsMinMax.o  
OBJS +=build/FRAMEWIN_MinMaxRest.o  
OBJS +=build/FRAMEWIN_SetBorderSize.o  
OBJS +=build/FRAMEWIN_SetColors.o  
OBJS +=build/FRAMEWIN_SetFont.o  
OBJS +=build/FRAMEWIN_SetResizeable.o  
OBJS +=build/FRAMEWIN_SetTitleHeight.o  
OBJS +=build/FRAMEWIN_SetTitleVis.o  
OBJS +=build/GUI_ARRAY.o  
OBJS +=build/GUI_ARRAY_DeleteItem.o  
OBJS +=build/GUI_ARRAY_InsertItem.o  
OBJS +=build/GUI_ARRAY_ResizeItem.o  
OBJS +=build/GUI_DRAW.o  
OBJS +=build/GUI_DRAW_BITMAP.o  
OBJS +=build/GUI_DRAW_BMP.o  
OBJS +=build/GUI_DRAW_Self.o  
OBJS +=build/GUI_DRAW_STREAMED.o  
OBJS +=build/GUI_EditBin.o  
OBJS +=build/GUI_EditDec.o  
OBJS +=build/GUI_EditFloat.o  
OBJS +=build/GUI_EditHex.o  
OBJS +=build/GUI_EditString.o  
OBJS +=build/GUI_HOOK.o  
OBJS +=build/HEADER.o  
OBJS +=build/HEADER__SetDrawObj.o  
OBJS +=build/HEADER_Bitmap.o  
OBJS +=build/HEADER_BMP.o  
OBJS +=build/HEADER_Create.o  
OBJS +=build/HEADER_CreateIndirect.o    
OBJS +=build/HEADER_StreamedBitmap.o  
OBJS +=build/LISTBOX.o  
OBJS +=build/LISTBOX_Create.o  
OBJS +=build/LISTBOX_CreateIndirect.o  
OBJS +=build/LISTBOX_Default.o  
OBJS +=build/LISTBOX_DeleteItem.o  
OBJS +=build/LISTBOX_Font.o  
OBJS +=build/LISTBOX_GetItemText.o  
OBJS +=build/LISTBOX_GetNumItems.o    
OBJS +=build/LISTBOX_InsertString.o  
OBJS +=build/LISTBOX_ItemDisabled.o  
OBJS +=build/LISTBOX_ItemSpacing.o  
OBJS +=build/LISTBOX_MultiSel.o  
OBJS +=build/LISTBOX_ScrollStep.o  
OBJS +=build/LISTBOX_SetAutoScroll.o  
OBJS +=build/LISTBOX_SetBkColor.o  
OBJS +=build/LISTBOX_SetOwner.o  
OBJS +=build/LISTBOX_SetOwnerDraw.o   
OBJS +=build/LISTBOX_SetScrollbarWidth.o  
OBJS +=build/LISTBOX_SetString.o   
OBJS +=build/LISTBOX_SetTextColor.o  
OBJS +=build/LISTVIEW.o  
OBJS +=build/LISTVIEW_Create.o  
OBJS +=build/LISTVIEW_CreateIndirect.o  
OBJS +=build/LISTVIEW_Default.o  
OBJS +=build/LISTVIEW_DeleteColumn.o  
OBJS +=build/LISTVIEW_DeleteRow.o  
OBJS +=build/LISTVIEW_GetBkColor.o  
OBJS +=build/LISTVIEW_GetFont.o  
OBJS +=build/LISTVIEW_GetHeader.o   
OBJS +=build/LISTVIEW_GetNumColumns.o  
OBJS +=build/LISTVIEW_GetNumRows.o  
OBJS +=build/LISTVIEW_GetSel.o  
OBJS +=build/LISTVIEW_GetTextColor.o  
OBJS +=build/LISTVIEW_SetBkColor.o  
OBJS +=build/LISTVIEW_SetColumnWidth.o  
OBJS +=build/LISTVIEW_SetFont.o  
OBJS +=build/LISTVIEW_SetGridVis.o  
OBJS +=build/LISTVIEW_SetItemColor.o  
OBJS +=build/LISTVIEW_SetItemText.o  
OBJS +=build/LISTVIEW_SetLBorder.o  
OBJS +=build/LISTVIEW_SetRBorder.o  
OBJS +=build/LISTVIEW_SetRowHeight.o  
OBJS +=build/LISTVIEW_SetSel.o  
OBJS +=build/LISTVIEW_SetTextAlign.o  
OBJS +=build/LISTVIEW_SetTextColor.o   
OBJS +=build/MENU.o  
OBJS +=build/MENU__FindItem.o  
OBJS +=build/MENU_Attach.o  
OBJS +=build/MENU_CreateIndirect.o  
OBJS +=build/MENU_Default.o  
OBJS +=build/MENU_DeleteItem.o  
OBJS +=build/MENU_DisableItem.o  
OBJS +=build/MENU_EnableItem.o  
OBJS +=build/MENU_GetItem.o  
OBJS +=build/MENU_GetItemText.o  
OBJS +=build/MENU_GetNumItems.o  
OBJS +=build/MENU_InsertItem.o  
OBJS +=build/MENU_Popup.o  
OBJS +=build/MENU_SetBkColor.o  
OBJS +=build/MENU_SetBorderSize.o  
OBJS +=build/MENU_SetFont.o  
OBJS +=build/MENU_SetItem.o  
OBJS +=build/MENU_SetTextColor.o  
OBJS +=build/MESSAGEBOX.o  
OBJS +=build/MULTIEDIT.o  
OBJS +=build/MULTIEDIT_Create.o  
OBJS +=build/MULTIEDIT_CreateIndirect.o  
OBJS +=build/MULTIPAGE.o  
OBJS +=build/MULTIPAGE_Create.o  
OBJS +=build/MULTIPAGE_CreateIndirect.o  
OBJS +=build/MULTIPAGE_Default.o  
OBJS +=build/PROGBAR.o  
OBJS +=build/PROGBAR_Create.o  
OBJS +=build/PROGBAR_CreateIndirect.o  
OBJS +=build/RADIO.o  
OBJS +=build/RADIO_Create.o  
OBJS +=build/RADIO_CreateIndirect.o  
OBJS +=build/RADIO_Default.o    
OBJS +=build/RADIO_Image.o  
OBJS +=build/RADIO_SetBkColor.o  
OBJS +=build/RADIO_SetDefaultImage.o   
OBJS +=build/RADIO_SetFont.o  
OBJS +=build/RADIO_SetGroupId.o  
OBJS +=build/RADIO_SetImage.o  
OBJS +=build/RADIO_SetText.o  
OBJS +=build/RADIO_SetTextColor.o  
OBJS +=build/SCROLLBAR.o  
OBJS +=build/SCROLLBAR_Create.o  
OBJS +=build/SCROLLBAR_CreateIndirect.o  
OBJS +=build/SCROLLBAR_Defaults.o  
OBJS +=build/SCROLLBAR_GetValue.o   
OBJS +=build/SCROLLBAR_SetWidth.o  
OBJS +=build/SLIDER.o  
OBJS +=build/SLIDER_Create.o  
OBJS +=build/SLIDER_CreateIndirect.o   
OBJS +=build/TEXT.o  
OBJS +=build/TEXT_Create.o  
OBJS +=build/TEXT_CreateIndirect.o  
OBJS +=build/TEXT_SetBkColor.o  
OBJS +=build/TEXT_SetFont.o  
OBJS +=build/TEXT_SetText.o  
OBJS +=build/TEXT_SetTextAlign.o  
OBJS +=build/TEXT_SetTextColor.o  
OBJS +=build/WIDGET.o  
OBJS +=build/WIDGET_Effect_3D1L.o  
OBJS +=build/WIDGET_Effect_3D2L.o  
OBJS +=build/WIDGET_Effect_3D.o  
OBJS +=build/WIDGET_Effect_None.o    
OBJS +=build/WIDGET_FillStringInRect.o  
OBJS +=build/WIDGET_SetEffect.o  
OBJS +=build/WIDGET_SetWidth.o  
OBJS +=build/WINDOW.o  
OBJS +=build/WINDOW_Default.o

WMOBJS = 
OBJS +=build/WM.o  
OBJS +=build/WM__ForEachDesc.o  
OBJS +=build/WM__GetFirstSibling.o  
OBJS +=build/WM__GetFocussedChild.o  
OBJS +=build/WM__GetLastSibling.o  
OBJS +=build/WM__GetOrg_AA.o  
OBJS +=build/WM__GetPrevSibling.o  
OBJS +=build/WM__IsAncestor.o  
OBJS +=build/WM__IsChild.o  
OBJS +=build/WM__IsEnabled.o  
OBJS +=build/WM__NotifyVisChanged.o  
OBJS +=build/WM__Screen2Client.o  
OBJS +=build/WM__SendMessage.o  
OBJS +=build/WM__SendMessageIfEnabled.o  
OBJS +=build/WM__SendMessageNoPara.o  
OBJS +=build/WM__UpdateChildPositions.o  
OBJS +=build/WM_AttachWindow.o  
OBJS +=build/WM_BringToBottom.o  
OBJS +=build/WM_BringToTop.o  
OBJS +=build/WM_Broadcast.o  
OBJS +=build/WM_CheckScrollPos.o  
OBJS +=build/WM_CriticalHandle.o  
OBJS +=build/WM_DIAG.o  
OBJS +=build/WM_EnableWindow.o  
OBJS +=build/WM_ForEachDesc.o  
OBJS +=build/WM_GetBkColor.o  
OBJS +=build/WM_GetClientRect.o  
OBJS +=build/WM_GetClientWindow.o  
OBJS +=build/WM_GetDesktopWindow.o  
OBJS +=build/WM_GetDesktopWindowEx.o  
OBJS +=build/WM_GetDiagInfo.o  
OBJS +=build/WM_GetDialogItem.o  
OBJS +=build/WM_GetFirstChild.o  
OBJS +=build/WM_GetFlags.o  
OBJS +=build/WM_GetFocussedWindow.o  
OBJS +=build/WM_GetId.o  
OBJS +=build/WM_GetInsideRect.o  
OBJS +=build/WM_GetInsideRectExScrollbar.o  
OBJS +=build/WM_GetInvalidRect.o  
OBJS +=build/WM_GetNextSibling.o  
OBJS +=build/WM_GetOrg.o  
OBJS +=build/WM_GetParent.o  
OBJS +=build/WM_GetPrevSibling.o  
OBJS +=build/WM_GetScrollbar.o  
OBJS +=build/WM_GetScrollPartner.o   
OBJS +=build/WM_GetScrollState.o  
OBJS +=build/WM_GetWindowRect.o  
OBJS +=build/WM_GetWindowSize.o  
OBJS +=build/WM_HasCaptured.o  
OBJS +=build/WM_HasFocus.o  
OBJS +=build/WM_Hide.o   
OBJS +=build/WM_IsCompletelyVisible.o  
OBJS +=build/WM_IsEnabled.o  
OBJS +=build/WM_IsFocussable.o  
OBJS +=build/WM_IsVisible.o  
OBJS +=build/WM_IsWindow.o  
OBJS +=build/WM_MakeModal.o  
OBJS +=build/WM_Move.o  
OBJS +=build/WM_MoveChildTo.o  
OBJS +=build/WM_NotifyParent.o  
OBJS +=build/WM_OnKey.o  
OBJS +=build/WM_Paint.o   
OBJS +=build/WM_PID__GetPrevState.o  
OBJS +=build/WM_ResizeWindow.o  
OBJS +=build/WM_Screen2Win.o  
OBJS +=build/WM_SendMessageNoPara.o  
OBJS +=build/WM_SendToParent.o  
OBJS +=build/WM_SetAnchor.o  
OBJS +=build/WM_SetCallback.o  
OBJS +=build/WM_SetCapture.o  
OBJS +=build/WM_SetCaptureMove.o  
OBJS +=build/WM_SetCreateFlags.o  
OBJS +=build/WM_SetDesktopColor.o  
OBJS +=build/WM_SetFocus.o  
OBJS +=build/WM_SetFocusOnNextChild.o  
OBJS +=build/WM_SetFocusOnPrevChild.o  
OBJS +=build/WM_SetId.o  
OBJS +=build/WM_SetpfPollPID.o  
OBJS +=build/WM_SetScrollbar.o   
OBJS +=build/WM_SetScrollState.o  
OBJS +=build/WM_SetSize.o  
OBJS +=build/WM_SetTrans.o  
OBJS +=build/WM_SetTransState.o  
OBJS +=build/WM_SetUserClipRect.o  
OBJS +=build/WM_SetXSize.o  
OBJS +=build/WM_SetYSize.o  
OBJS +=build/WM_Show.o   
OBJS +=build/WM_StayOnTop.o  
OBJS +=build/WM_Timer.o  
OBJS +=build/WM_TimerExternal.o   
OBJS +=build/WM_UserData.o  
OBJS +=build/WM_Validate.o  
OBJS +=build/WM_ValidateWindow.o  
OBJS +=build/WMMemDev.o  
OBJS +=build/WMTouch.o

OBJS +=build/GUIDEV.o 
OBJS +=build/GUIDEV_1.o  
OBJS +=build/GUIDEV_8.o  
OBJS +=build/GUIDEV_16.o  
OBJS +=build/GUIDEV_AA.o  
OBJS +=build/GUIDEV_Auto.o  
OBJS +=build/GUIDEV_Banding.o  
OBJS +=build/GUIDEV_Clear.o  
OBJS +=build/GUIDEV_CmpWithLCD.o  
OBJS +=build/GUIDEV_CopyFromLCD.o  
OBJS +=build/GUIDEV_CreateFixed.o  
OBJS +=build/GUIDEV_GetDataPtr.o  
OBJS +=build/GUIDEV_GetXSize.o  
OBJS +=build/GUIDEV_GetYSize.o  
OBJS +=build/GUIDEV_Measure.o  
OBJS +=build/GUIDEV_ReduceYSize.o  
OBJS +=build/GUIDEV_SetOrg.o  
OBJS +=build/GUIDEV_Usage.o  
OBJS +=build/GUIDEV_UsageBM.o  
OBJS +=build/GUIDEV_Write.o  
OBJS +=build/GUIDEV_WriteAlpha.o  
OBJS +=build/GUIDEV_WriteEx.o  
OBJS +=build/GUIDEV_XY2PTR.o
	
OBJS +=build/GUI_X_uCOS.o
OBJS +=build/GUI_X_Touch.o
OBJS +=build/GUI_X.o
OBJS +=lib/libm.a
OBJS += lib/libc.a
OBJS += lib/libgcc.a 


OBJS += build/main.o
OBJS += build/userApp.o

clean :
	rm -f build/*.o
	rm -f *.bin
	rm -f *.hex
	rm -f *.elf
	rm -f *.list
	rm -f *.img
	rm -f build/*.bc

build/%.o : port/%.s
	$(ARMGNU)-gcc $(COPS) -D__ASSEMBLY__ -c -o $@ $<
	
build/%.o : init/%.s
	$(ARMGNU)-gcc $(COPS) -D__ASSEMBLY__ -c -o $@ $<
	
build/%.o : port/%.c
	$(ARMGNU)-gcc $(COPS)  -c -o $@ $<
		
build/%.o : bsp/%.c
	$(ARMGNU)-gcc $(COPS)  -c -o $@ $<
	
build/%.o : usrApp/%.c
	$(ARMGNU)-gcc $(COPS) -c -o $@ $<

build/%.o : csud/%.c
	$(ARMGNU)-gcc $(COPSW) -c -o $@ $<	

build/%.o : uCGUI/AntiAlias/%.c
	$(ARMGNU)-gcc $(COPS)  -c -o $@ $<

build/%.o : uCGUI/ConvertColor/%.c
	$(ARMGNU)-gcc $(COPS)  -c -o $@ $<

build/%.o : uCGUI/ConvertMono/%.c
	$(ARMGNU)-gcc $(COPS)  -c -o $@ $<
	
build/%.o : uCGUI/Core/%.c
	$(ARMGNU)-gcc $(COPS)  -c -o $@ $<
	
build/%.o : uCGUI/Font/%.c
	$(ARMGNU)-gcc $(COPS)  -c -o $@ $<
	
build/%.o : uCGUI/JPEG/%.c
	$(ARMGNU)-gcc $(COPS)  -c -o $@ $<
	
build/%.o : uCGUI/MemDev/%.c
	$(ARMGNU)-gcc $(COPS)  -c -o $@ $<

build/%.o : uCGUI/Widget/%.c
	$(ARMGNU)-gcc $(COPS)  -c -o $@ $<

build/%.o : uCGUI/WM/%.c
	$(ARMGNU)-gcc $(COPS)  -c -o $@ $<

build/%.o : uCGUI/GUI_X/%.c
	$(ARMGNU)-gcc $(COPS)  -c -o $@ $<	

build/ucos_ii.o : ucos/ucos_ii.c
	$(ARMGNU)-gcc $(COPS) ucos/ucos_ii.c -c -o build/ucos_ii.o

%.o: $(FONTS_DIR)/%.bin
	$(ARMGNU)-objcopy -I binary -O elf32-littlearm -B arm $< $@
	
%.o: $(ICONS_DIR)/%.bin
	$(ARMGNU)-objcopy -I binary -O elf32-littlearm -B arm $< $@

kernel.img : raspberrypi.ld $(OBJS)
	$(ARMGNU)-ld $(OBJS) -T raspberrypi.ld -o ucos_bcm2835.elf 
	$(ARMGNU)-objdump -D ucos_bcm2835.elf > ucos_bcm2835.list
	$(ARMGNU)-objcopy ucos_bcm2835.elf -O ihex ucos_bcm2835.hex
	$(ARMGNU)-objcopy ucos_bcm2835.elf -O binary ucos_bcm2835.bin
	$(ARMGNU)-objcopy ucos_bcm2835.elf. -O binary kernel.img
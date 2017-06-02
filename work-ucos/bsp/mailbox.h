#ifndef _MAILBOX_H_
#define _MAILBOX_H_
#include "../ucGUI/core/LCD.h"
void MailboxWrite(u32 message, u32 mailbox);
u32 MailboxRead(u32 mailbox);

#endif // _MAILBOX_H_
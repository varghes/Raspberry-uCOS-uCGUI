#include <stdint.h>
#include <stdarg.h>
//#include "uart.h"
#include "string.h"

void *memset(void *ptr, int set, size_t size)
{
    char *p=ptr;
    
    while(size--){
        *p++ = (int)set;
    }
    
    return p;
}

void *memcpy(void *dest, const void *src, size_t count)
{
	char *tmp = dest;
	const char *s = src;
    
	while (count--)
		*tmp++ = *s++;
	return dest;
}

char *itoa(int val)
{
	static char ascii_val[11];
	int pos=0, temp=val;

	// First round is to get the length
	if(val<0)
		pos++;

	while(temp && (pos<=10)){
		temp = temp/10;
		pos++;
	}

	ascii_val[pos] = 0;

	// Second round is to do the actual conversion
	if(val<0)
		ascii_val[--pos] = '-';

	while(val && pos--){
		ascii_val[pos] = 0x30 + (val%10);
		val = val/10;
	}

	return ascii_val;
}

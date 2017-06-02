#ifndef _STRING_H_
#define _STRING_H_

typedef unsigned int size_t;

void *memset(void *ptr, int set, size_t size);
void *memcpy(void *dest, const void *src, size_t count);
char *itoa(int val);

#endif // _STRING_H_

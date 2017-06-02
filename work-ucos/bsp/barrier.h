#ifndef _BARRIER_H_
#define _BARRIER_H_

#define data_mem_barrier() __asm__ __volatile__ ("mcr p15, 0, %[reg], c7, c10, 5"::[reg] "r" (0))
#define data_sync_barrier() __asm__ __volatile__ ("mcr p15, 0, %[reg], c7, c10, 4"::[reg] "r" (0))

#endif // _BARRIER_H_

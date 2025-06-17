
#ifndef __SWO_H_INCLUDED__
#define __SWO_H_INCLUDED__

#include "stdio.h"
#include "stdint.h"
#include "stdbool.h"


#define IS_INSIDE_INTERRUPT()           (__get_IPSR() != 0)

#define IS_DEBUGGER_ATTACHED()          ((CoreDebug->DHCSR & CoreDebug_DHCSR_C_DEBUGEN_Msk) != 0)

#define EXTERN_SECTOR(sector)           extern char Image$$##sector##$$Base;\
                                        extern char Image$$##sector##$$Length;\
                                        extern char Load$$##sector##$$Base;\
                                        extern char Load$$##sector##$$Length

#define COPY_FUNCTIONS_TO_RAM(sector)   memcpy(&Image$$##sector##$$Base, &Load$$##sector##$$Base, (size_t)&Load$$##sector##$$Length)

#endif //__SWO_H_INCLUDED__

#ifndef __SWO_H_INCLUDED__
#define __SWO_H_INCLUDED__

#ifdef __cplusplus
  extern "C"{
#endif //__cplusplus

#include "stdio.h"
#include "stdint.h"
#include "stdbool.h"



#define YES                            1
#define NO                             0

#define IS_INSIDE_INTERRUPT()          (__get_IPSR() != 0)

#define IS_DEBUGGER_ATTACHED()         ((CoreDebug->DHCSR & CoreDebug_DHCSR_C_DEBUGEN_Msk) != 0)

#define EXTERN_SECTOR(sector)          extern char Image$$##sector##$$Base;\
                                       extern char Image$$##sector##$$Length;\
                                       extern char Load$$##sector##$$Base;\
                                       extern char Load$$##sector##$$Length

#define COPY_FUNCTIONS_TO_RAM(sector)  memcpy(&Image$$##sector##$$Base, &Load$$##sector##$$Base, (size_t)&Load$$##sector##$$Length)

#define __CONCAT1(x)                   x
#define __CONCAT2(x, y)                x##y
#define __CONCAT3(x, y, z)             x##y##z
#define __CONCAT4(x, y, z, w)          x##y##z##w
#define __CONCAT5(x, y, z, w, u)       x##y##z##w##u
                                        
#define ___TO_STRING_(x)               #x
#define TO_STRING(x)                   ___TO_STRING_(x)

#define __POSITION(_1, _2, _3, _4, _5, FN, ...) FN
#define POSITION(...)                  __POSITION(__VA_ARGS__, __CONCAT5, __CONCAT4, __CONCAT3, __CONCAT2, __CONCAT1)(__VA_ARGS__)
#define CONCAT(...)                    POSITION(__VA_ARGS__)

                                        
#define ___COUNT_(a01, a02, a03, a04, a05, a06, a07, a08, a09, a10,\
                  a11, a12, a13, a14, a15, a16, a17, a18, a19, a20,\
                  a21, a22, a23, a24, a25, a26, a27, a28, a29, a30,\
                  a31, a32, a33, a34, a35, a36, a37, a38, a39, a40,\
                  a41, a42, a43, a44, a45, a46, a47, a48, a49, a50,\
                  N, ...)              N

#define COUNT(...)                     ___COUNT_(__VA_ARGS__,  50, 49, 48, 47, 46, 45, 44, 43, 42, 41,\
                                                               40, 39, 38, 37, 36, 35, 34, 33, 32, 31,\
                                                               30, 29, 28, 27, 26, 25, 24, 23, 22, 21,\
                                                               20, 19, 18, 17, 16, 15, 14, 13, 12, 11,\
                                                               10,  9,  8,  7,  6,  5,  4,  3,  2, 1)


#define BB_PERIPH(base, offset, bit)   (*(volatile uint32_t*)(PERIPH_BB_BASE + ((uint32_t)base + offset) * 32U + (bit * 4U)))
#define BB_SRAM(addr, bit)             (*((volatile uint32_t*)(SRAM_BB_BASE + (((uint32_t)(addr) - SRAM_BASE) * 32U + (bit) * 4U))))


#define BB_GPIO_ODR(port, pin)         BB_PERIPH(CONCAT(GPIO, CONCAT(port, _BASE)), 0x14, pin)




#ifdef __cplusplus
  }
#endif //__cplusplus
#endif //__SWO_H_INCLUDED__
#ifndef _JTEST_CYCLE_H_
#define _JTEST_CYCLE_H_

                                                                                    
              
                                                                                    

#include "jtest_fw.h"                                  
#include "jtest_systick.h"
#include "jtest_util.h"                    

                                                                                    
                              
                                                                                    
extern const char * JTEST_CYCLE_STRF;

                                                                                    
                        
                                                                                    

   
                                                                              
            
   
                              
                                                         
                                                         
                                                         
                                                         
                                                         
                                                         
                                                         
                                                         
                                                         
                                                         
                                                         
                                                         
                                                         
                                                   
                                                         
                                                         
                                                         
                                                         
               
  
#ifndef ARMv7A

#define JTEST_COUNT_CYCLES(fn_call)                     \
    do                                                  \
    {                                                   \
        uint32_t __jtest_cycle_end_count;               \
                                                        \
        JTEST_SYSTICK_RESET(SysTick);                   \
        JTEST_SYSTICK_START(SysTick);                   \
                                                        \
        fn_call;                                        \
                                                        \
        __jtest_cycle_end_count =                       \
            JTEST_SYSTICK_VALUE(SysTick);               \
                                                        \
		JTEST_SYSTICK_RESET(SysTick);           \
        JTEST_DUMP_STRF(JTEST_CYCLE_STRF,               \
                        (JTEST_SYSTICK_INITIAL_VALUE -  \
                         __jtest_cycle_end_count));     \
    } while (0)

#else
          
#define JTEST_COUNT_CYCLES(fn_call)                     \
    do                                                  \
    {                                                   \
		fn_call;   										\
    } while (0)

#endif

#endif                      



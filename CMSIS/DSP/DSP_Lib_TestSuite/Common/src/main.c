#include "jtest.h"
#include "all_tests.h"
#include "arm_math.h"


#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050) && !defined (__MICROLIB)
__asm(" .global __ARM_use_no_argv\n");
#endif


void debug_init(void)
{
    uint32_t * SHCSR_ptr = (uint32_t *) 0xE000ED24;                                                
    *SHCSR_ptr |= 0x70000;                                                                   
}

int main(void)
{
#if !defined(FILEIO)
    debug_init();
#endif

    JTEST_INIT();                                               

    JTEST_GROUP_CALL(all_tests);                     

    JTEST_ACT_EXIT_FW();                                   
#if !defined(FILEIO)
    while (1);                                      
#endif
}

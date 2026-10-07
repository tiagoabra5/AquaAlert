#ifndef _JTEST_TEST_CALL_H_
#define _JTEST_TEST_CALL_H_

                                                                                    
              
                                                                                    
#include "jtest_test.h"
#include "jtest_test_define.h"
#include "jtest_fw.h"

                                                                                    
                        
                                                                                    

   
                                                                                
                                           
   
#define JTEST_TEST_RUN(retval, test_fn)                                 \
    do                                                                  \
    {                                                                   \
        JTEST_DUMP_STR("Test Name:\n");                                 \
        JTEST_DUMP_STR(JTEST_TEST_STRUCT_NAME(test_fn).test_fn_str);    \
        JTEST_DUMP_STR("Function Under Test:\n");                       \
        JTEST_DUMP_STR(JTEST_TEST_STRUCT_NAME(test_fn).fut_str);        \
        retval = JTEST_TEST_STRUCT_NAME(test_fn).test_fn_ptr();         \
    } while (0)

   
                                                                        
                
  
                                                                   
  
                                                                    
                   
   
#define JTEST_TEST_UPDATE_PARENT_GROUP_PF(test_retval)              \
    do                                                              \
    {                                                               \
                                                                    \
        if (test_retval == JTEST_TEST_PASSED)                       \
        {                                                           \
            JTEST_GROUP_INC_PASSED(JTEST_CURRENT_GROUP_PTR(), 1);   \
        } else {                                                    \
            JTEST_GROUP_INC_FAILED(JTEST_CURRENT_GROUP_PTR(), 1);   \
        }                                                           \
    } while (0)

   
                                                                         
  
                                                                   
   
#define JTEST_TEST_UPDATE_FW_PF(test_retval)                        \
    do                                                              \
    {                                                               \
                                                                     \
        if (test_retval == JTEST_TEST_PASSED)                       \
        {                                                           \
            JTEST_FW_INC_PASSED( 1);                                \
        } else {                                                    \
            JTEST_FW_INC_FAILED(1);                                 \
        }                                                           \
    } while (0)

   
                                                                      
                                                             
  
                                                                   
   
#define JTEST_TEST_UPDATE_PARENT_GROUP_OR_FW_PF(test_retval)            \
    do                                                                  \
    {                                                                   \
                                                                        \
        if (JTEST_CURRENT_GROUP_PTR()               )                    \
        {                                                               \
            JTEST_TEST_UPDATE_PARENT_GROUP_PF(test_retval);             \
        } else {                                                        \
            JTEST_TEST_UPDATE_FW_PF(test_retval);                       \
        }                                                               \
    } while (0)

   
                                                      
   
#define JTEST_TEST_DUMP_RESULTS(test_retval)        \
        do                                          \
        {                                           \
            if (test_retval == JTEST_TEST_PASSED)   \
            {                                       \
                JTEST_DUMP_STR("Test Passed\n");      \
            } else {                                \
                JTEST_DUMP_STR("Test Failed\n");      \
            }                                       \
        } while (0)

   
                                                                  
   
#define JTEST_TEST_CALL(test_fn)                                        \
    do                                                                  \
    {                                                                   \
        if (JTEST_TEST_IS_ENABLED(&JTEST_TEST_STRUCT_NAME(test_fn)))    \
        {                                                               \
                                                                        \
            JTEST_TEST_RET_t __jtest_test_ret = JTEST_TEST_FAILED;      \
                                                                        \
            JTEST_ACT_TEST_START();                                     \
            JTEST_TEST_RUN(__jtest_test_ret, test_fn);                  \
                                                                        \
                                                                        \
            JTEST_TEST_UPDATE_PARENT_GROUP_OR_FW_PF(__jtest_test_ret);  \
                                                                        \
            JTEST_TEST_DUMP_RESULTS(__jtest_test_ret);                  \
            JTEST_ACT_TEST_END();                                       \
        }                                                               \
    } while (0)

#endif                          

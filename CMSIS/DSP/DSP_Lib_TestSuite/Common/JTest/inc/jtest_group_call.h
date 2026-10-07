#ifndef _JTEST_GROUP_CALL_H_
#define _JTEST_GROUP_CALL_H_

                                                                                    
              
                                                                                    

#include "jtest_fw.h"
#include <inttypes.h>

                                                                                    
                        
                                                                                    

   
                                                                                
             
   
#define JTEST_GROUP_RUN(group_fn)                                   \
    do                                                              \
    {                                                               \
        JTEST_DUMP_STR("Group Name:\n");                            \
        JTEST_DUMP_STR(JTEST_GROUP_STRUCT_NAME(group_fn).name_str); \
        JTEST_GROUP_STRUCT_NAME(group_fn).group_fn_ptr();           \
    } while (0)


   
                                                                         
                             
  
                                                           
                                                              
  
                                                                               
                                          
   
#define JTEST_GROUP_UPDATE_PARENT_GROUP_PF(group_ptr, parent_group_ptr) \
    do                                                                  \
    {                                                                   \
        JTEST_GROUP_INC_PASSED(parent_group_ptr,                        \
                               (group_ptr)->passed);                    \
        JTEST_GROUP_INC_FAILED(parent_group_ptr,                        \
                               (group_ptr)->failed);                    \
    } while (0)

   
                                                                  
                     
   
#define JTEST_GROUP_UPDATE_FW_PF(group_ptr)                     \
    do                                                          \
    {                                                           \
        JTEST_FW_INC_PASSED((group_ptr)->passed);               \
        JTEST_FW_INC_FAILED((group_ptr)->failed);               \
    } while (0)

   
                                                                            
                                                                          
                                          
   
#define JTEST_GROUP_UPDATE_PARENT_GROUP_OR_FW_PF(group_ptr,         \
                                                 parent_group_ptr)  \
    do                                                              \
    {                                                               \
                                                                    \
        if (parent_group_ptr                      )                 \
        {                                                           \
            JTEST_GROUP_UPDATE_PARENT_GROUP_PF(                     \
                group_ptr,                                          \
                parent_group_ptr);                                  \
        } else {                                                    \
            JTEST_GROUP_UPDATE_FW_PF(                               \
                group_ptr);                                         \
        }                                                           \
    } while (0)

   
                                                                        
   
#define JTEST_GROUP_DUMP_RESULTS(group_ptr)                             \
        do                                                              \
        {                                                               \
            JTEST_DUMP_STRF(                                            \
                "Tests Run: %" PRIu32 "\n"                              \
                "----------\n"                                          \
                "   Passed: %" PRIu32 "\n"                              \
                "   Failed: %" PRIu32 "\n",                             \
                (group_ptr)->passed + (group_ptr)->failed,              \
                (group_ptr)->passed,                                    \
                (group_ptr)->failed);                                   \
        } while (0)

   
                                                                    
   
#define JTEST_GROUP_CALL(group_fn)                                      \
        do                                                              \
        {                                                                \
                                                                        \
            JTEST_GROUP_t * __jtest_temp_group_ptr =                    \
                JTEST_CURRENT_GROUP_PTR();                              \
            JTEST_SET_CURRENT_GROUP(&JTEST_GROUP_STRUCT_NAME(group_fn)); \
                                                                        \
                                                                        \
                                                                        \
            JTEST_GROUP_RESET_PF(JTEST_CURRENT_GROUP_PTR());            \
                                                                        \
                                                                        \
            JTEST_ACT_GROUP_START();                                    \
            JTEST_GROUP_RUN(group_fn);                                  \
            JTEST_ACT_GROUP_END();                                      \
                                                                        \
                                                                          \
            JTEST_GROUP_UPDATE_PARENT_GROUP_OR_FW_PF(                   \
                JTEST_CURRENT_GROUP_PTR(),                              \
                __jtest_temp_group_ptr);                                \
                                                                        \
            JTEST_GROUP_DUMP_RESULTS(JTEST_CURRENT_GROUP_PTR());        \
                                                                        \
                                                                        \
            JTEST_SET_CURRENT_GROUP(__jtest_temp_group_ptr);            \
        } while (0)

#endif                           

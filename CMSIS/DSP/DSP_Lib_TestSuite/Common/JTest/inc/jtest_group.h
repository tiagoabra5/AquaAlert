#ifndef _JTEST_GROUP_H_
#define _JTEST_GROUP_H_

                                                                                    
              
                                                                                    

#include "jtest_pf.h"
#include "jtest_util.h"

                                                                                    
                      
                                                                                    

   
                                                                              
                                                                 
   
typedef struct JTEST_GROUP_struct
{
    void (* group_fn_ptr) (void);                                  
    char * name_str;                                       
    
                                                              
    JTEST_PF_MEMBERS;
} JTEST_GROUP_t;

                                                                                    
                        
                                                                                    

   
                                  
   
#define JTEST_GROUP_SET_NAME(group_ptr, name)     \
    JTEST_SET_STRUCT_ATTRIBUTE(group_ptr, name_str, name)

#define JTEST_GROUP_SET_FN(group_ptr, fn_ptr)     \
    JTEST_SET_STRUCT_ATTRIBUTE(group_ptr, group_fn_ptr, fn_ptr)

   
                                                                           
              
   
#define JTEST_GROUP_INC_PASSED(group_ptr, amount) \
    JTEST_PF_INC_PASSED(group_ptr, amount)

   
                                                                           
              
   
#define JTEST_GROUP_INC_FAILED(group_ptr, amount) \
    JTEST_PF_INC_FAILED(group_ptr, amount)

   
                                                                       
              
   
#define JTEST_GROUP_RESET_PF(group_ptr)         \
    do                                          \
    {                                           \
        JTEST_PF_RESET_PASSED(group_ptr);       \
        JTEST_PF_RESET_FAILED(group_ptr);       \
    } while (0)

#endif                      

#ifndef _JTEST_TEST_H_
#define _JTEST_TEST_H_

                                                                                    
              
                                                                                    

#include <stdint.h>
#include "jtest_util.h"
#include "jtest_test_ret.h"

                                                                                    
                      
                                                                                    

   
                                                                            
                                                             
   
typedef struct JTEST_TEST_struct
{
    JTEST_TEST_RET_t ( * test_fn_ptr)(void);                                      
    char   * test_fn_str;                                                     
    char   * fut_str;                                                   

       
                                                        
       
    union {
        struct {
            unsigned enabled : 1;
            unsigned unused  : 7;
        } bits;
        uint8_t byte;                                          
    } flags;
    
} JTEST_TEST_t;

                                                                                    
                        
                                                                                    

   
                                                       
   
#define JTEST_TEST_SET_FN(jtest_test_ptr, fn_ptr)                   \
    JTEST_SET_STRUCT_ATTRIBUTE(jtest_test_ptr, test_fn_ptr, fn_ptr)

   
                                                                     
   
#define JTEST_TEST_SET_FUT(jtest_test_ptr, str)                 \
    JTEST_SET_STRUCT_ATTRIBUTE(jtest_test_ptr, fut_str, str)

                                          
                                                                                    

#define JTEST_TEST_FLAG_SET 1                                           
#define JTEST_TEST_FLAG_CLR 0                                               

   
                                                           
   
#define JTEST_TEST_FLAG(jtest_test_ptr, flag_name)  \
    ((jtest_test_ptr)->flags.bits.flag_name)

   
                                                                
  
                                                            
                                                                             
                                                     
  
                                                                               
   
#define JTEST_TEST_XXX_FLAG(jtest_test_ptr, flag_name, xxx)                  \
    do                                                                       \
    {                                                                        \
        JTEST_TEST_FLAG(jtest_test_ptr, flag_name) = JTEST_TEST_FLAG_##xxx ; \
    } while (0)

   
                                                                     
   
#define JTEST_TEST_SET_FLAG(jtest_test_ptr, flag_name)                       \
    JTEST_TEST_XXX_FLAG(jtest_test_ptr, flag_name, SET)

   
                                                                       
   
#define JTEST_TEST_CLR_FLAG(jtest_test_ptr, flag_name)                       \
    JTEST_TEST_XXX_FLAG(jtest_test_ptr, flag_name, CLR)

   
                                                     
   
#define JTEST_TEST_IS_ENABLED(jtest_test_ptr)                           \
    (JTEST_TEST_FLAG(jtest_test_ptr, enabled) == JTEST_TEST_FLAG_SET)

#endif                     

#ifndef _JTEST_TEST_DEFINE_H_
#define _JTEST_TEST_DEFINE_H_

                                                                                    
              
                                                                                    

#include "jtest_util.h"
#include "jtest_define.h"
#include "jtest_test.h"

                                                 
#include "opt_arg/opt_arg.h"

                                                                                    
                        
                                                                                    

   
                                         
   
#define JTEST_TEST_STRUCT_NAME_PREFIX G_JTEST_TEST_STRUCT_

   
                                                     
   
#define JTEST_TEST_FN_TEMPLATE(test_fn)                         \
    JTEST_TEST_RET_t test_fn(void)

#define JTEST_TEST_FN_PROTOTYPE JTEST_TEST_FN_TEMPLATE               
                                                                                     

   
                                                                             
   
#define JTEST_TEST_STRUCT_NAME(test_fn)                         \
    JTEST_STRUCT_NAME(JTEST_TEST_STRUCT_NAME_PREFIX, test_fn)

   
                                                             
   
#define JTEST_TEST_DEFINE_STRUCT(test_fn)                   \
    JTEST_DEFINE_STRUCT(JTEST_TEST_t,                       \
                        JTEST_TEST_STRUCT_NAME(test_fn))

   
                                                              
   
#define JTEST_TEST_DECLARE_STRUCT(test_fn)      \
    JTEST_DECLARE_STRUCT(JTEST_TEST_DEFINE_STRUCT(test_fn))

   
                                                        
   
#define JTEST_TEST_STRUCT_INIT(test_fn, fut, enable)    \
    test_fn,                                            \
        STR_NL(test_fn),                                   \
        STR_NL(fut),                                       \
    {                                                   \
        {                                               \
            enable,                                     \
                0                                       \
        }                                               \
    }                                                   \
        

   
                                                      
   
#define JTEST_TEST_INIT(test_fn, fut, enable)              \
    JTEST_TEST_DEFINE_STRUCT(test_fn) = {                  \
        JTEST_TEST_STRUCT_INIT(test_fn, fut, enable)       \
    }

                           
                                                                                    

   
                                                      
   
#define _JTEST_DEFINE_TEST(test_fn, fut, enable)           \
    JTEST_TEST_FN_PROTOTYPE(test_fn);                      \
    JTEST_TEST_INIT(test_fn, fut, enable);                 \
    JTEST_TEST_FN_PROTOTYPE(test_fn)                                   

   
                                                                 
   
#define JTEST_DECLARE_TEST(test_fn)                                     \
    JTEST_TEST_FN_PROTOTYPE(test_fn);                                   \
    JTEST_TEST_DECLARE_STRUCT(test_fn)                                 

                                                                                    
                                    
                                                                                    

                         
#define JTEST_DEFINE_TEST(...)                             \
    JTEST_DEFINE_TEST_(PP_NARG(__VA_ARGS__), ##__VA_ARGS__)

                   
#define JTEST_DEFINE_TEST_(N, ...)                         \
    SPLICE(JTEST_DEFINE_TEST_, N)(__VA_ARGS__)

                       
#define JTEST_DEFINE_TEST_DEFAULT_FUT            
#define JTEST_DEFINE_TEST_DEFAULT_ENABLE                   \
    JTEST_TRUE                                                    
                                                              

                   
#define JTEST_DEFINE_TEST_1(_1)                            \
    _JTEST_DEFINE_TEST(                                    \
        _1,                                                \
        JTEST_DEFINE_TEST_DEFAULT_FUT,                     \
        JTEST_DEFINE_TEST_DEFAULT_ENABLE                   \
        )

#define JTEST_DEFINE_TEST_2(_1, _2)                        \
    _JTEST_DEFINE_TEST(                                    \
        _1,                                                \
        _2,                                                \
        JTEST_DEFINE_TEST_DEFAULT_ENABLE                   \
        )

#define JTEST_DEFINE_TEST_3(_1, _2, _3)                    \
    _JTEST_DEFINE_TEST(                                    \
        _1,                                                \
        _2,                                                \
        _3                                                 \
        )

#endif                            

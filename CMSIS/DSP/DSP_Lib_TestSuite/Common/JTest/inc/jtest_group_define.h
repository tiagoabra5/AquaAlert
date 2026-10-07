#ifndef _JTEST_GROUP_DEFINE_H_
#define _JTEST_GROUP_DEFINE_H_


                                                                                    
              
                                                                                    

#include "jtest_util.h"
#include "jtest_define.h"
#include "jtest_group.h"

                                                 
#include "opt_arg/opt_arg.h"

                                                                                    
                        
                                                                                    

   
                                          
   
#define JTEST_GROUP_STRUCT_NAME_PREFIX G_JTEST_GROUP_STRUCT_

   
                                                      
   
#define JTEST_GROUP_FN_TEMPLATE(group_fn)    \
    void group_fn(void)

#define JTEST_GROUP_FN_PROTOTYPE JTEST_GROUP_FN_TEMPLATE               
                                                                                        

   
                                                                               
   
#define JTEST_GROUP_STRUCT_NAME(group_fn)    \
    JTEST_STRUCT_NAME(JTEST_GROUP_STRUCT_NAME_PREFIX, group_fn)

   
                                                               
   
#define JTEST_GROUP_DEFINE_STRUCT(group_fn)  \
    JTEST_DEFINE_STRUCT(JTEST_GROUP_t,       \
                        JTEST_GROUP_STRUCT_NAME(group_fn))

   
                                                                
   
#define JTEST_GROUP_DECLARE_STRUCT(group_fn) \
    JTEST_DECLARE_STRUCT(JTEST_GROUP_DEFINE_STRUCT(group_fn))

   
                                                         
   
#define JTEST_GROUP_STRUCT_INIT(group_fn)    \
    group_fn,                                \
        STR_NL(group_fn),                       \
        JTEST_PF_MEMBER_INIT

   
                                                       
   
#define JTEST_GROUP_INIT(group_fn)           \
    JTEST_GROUP_DEFINE_STRUCT(group_fn) = {  \
        JTEST_GROUP_STRUCT_INIT(group_fn)    \
    }

                           
                                                                                    

   
                                                       
   
#define JTEST_DEFINE_GROUP(group_fn)         \
    JTEST_GROUP_FN_PROTOTYPE(group_fn);      \
    JTEST_GROUP_INIT(group_fn);              \
    JTEST_GROUP_FN_PROTOTYPE(group_fn)                                   

   
                                                                  
   
#define JTEST_DECLARE_GROUP(group_fn)        \
    JTEST_GROUP_FN_PROTOTYPE(group_fn);      \
    JTEST_GROUP_DECLARE_STRUCT(group_fn)                                 

#endif                             

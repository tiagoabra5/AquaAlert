#ifndef _JTEST_UTIL_H_
#define _JTEST_UTIL_H_

                                                                                    
              
                                                                                    

#include "util/util.h"

                                                                                    
                        
                                                                                    

                                              
#define JTEST_TRUE  1                                                
#define JTEST_FALSE 0                                                 

   
                                                                           
   
#define JTEST_SET_STRUCT_ATTRIBUTE(struct_ptr, attribute, value)    \
    do                                                              \
    {                                                               \
        (struct_ptr)->attribute = (value);                          \
    } while (0)

#endif                     

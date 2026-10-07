#ifndef _CONTROLLER_TEMPLATES_H_
#define _CONTROLLER_TEMPLATES_H_

                                                                                    
              
                                                                                    

#include "test_templates.h"
#include <string.h>                           

                                                                                    
                              
                                                                                    

   
                                                                        
   
#define CONTROLLER_SNR_THRESHOLD_float32_t 110
#define CONTROLLER_SNR_THRESHOLD_q31_t     100
#define CONTROLLER_SNR_THRESHOLD_q15_t     45

   
                                                                      
                       
   
#define CONTROLLER_SNR_COMPARE_INTERFACE(block_size,    \
                                         output_type)   \
    do                                                  \
    {                                                   \
        TEST_CONVERT_AND_ASSERT_SNR(                    \
            controller_output_f32_ref,                  \
            (output_type *) controller_output_ref,      \
            controller_output_f32_fut,                  \
            (output_type *) controller_output_fut,      \
            block_size,                                 \
            output_type,                                \
            CONTROLLER_SNR_THRESHOLD_##output_type      \
            );                                          \
    } while (0)


                                                                                    
                    
                                                                                    

#endif                               

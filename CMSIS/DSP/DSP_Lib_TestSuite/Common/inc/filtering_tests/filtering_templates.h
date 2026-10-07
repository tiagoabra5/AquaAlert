#ifndef _FILTERING_TEMPLATES_H_
#define _FILTERING_TEMPLATES_H_

                                                                                    
              
                                                                                    
#include "test_templates.h"

                                                                                    
                              
                                                                                    

  
                                                                         
   
#define FILTERING_SNR_THRESHOLD_float64_t 120
#define FILTERING_SNR_THRESHOLD_float32_t 99
#define FILTERING_SNR_THRESHOLD_q31_t 90
#define FILTERING_SNR_THRESHOLD_q15_t 60
#define FILTERING_SNR_THRESHOLD_q7_t 30

   
                                                
  
                                                                   
   
#define FILTERING_SNR_COMPARE_INTERFACE(block_size,                     \
                                        output_type)                    \
    FILTERING_SNR_COMPARE_INTERFACE_OFFSET(0, block_size, output_type)

   
                                                                        
   
#define FILTERING_SNR_COMPARE_INTERFACE_OFFSET(offset,      \
                                               block_size,  \
                                               output_type) \
    do                                                      \
    {                                                       \
        TEST_CONVERT_AND_ASSERT_SNR(                        \
            filtering_output_f32_ref,                       \
            (output_type *) filtering_output_ref + offset,  \
            filtering_output_f32_fut,                       \
            (output_type *) filtering_output_fut + offset,  \
            block_size,                                     \
            output_type,                                    \
            FILTERING_SNR_THRESHOLD_##output_type           \
            );                                              \
    } while (0)                                              

   
                                                                        
                              
   
#define FILTERING_DBL_SNR_COMPARE_INTERFACE(block_size,  				\
                                            output_type) 				\
    do                                                      		\
    {                                                       		\
        TEST_ASSERT_DBL_SNR(                        						\
            (float64_t*)filtering_output_ref,               \
            (float64_t*)filtering_output_fut,               \
            block_size,                                     		\
            FILTERING_SNR_THRESHOLD_##output_type           		\
            );                                              		\
    } while (0)                                              
		
                                                                                    
                      
                                                                                    
  
            
                                                                             
                                                                        
  
                                                        
  
                                
                             
  
                                                                               
                                                                          
                          
   


                                                                                    
                    
                                                                                    



#endif                              

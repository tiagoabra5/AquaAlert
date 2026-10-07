#ifndef _STATISTICS_TEMPLATES_H_
#define _STATISTICS_TEMPLATES_H_

                                                                                    
              
                                                                                    

#include "test_templates.h"

                                                                                    
                              
                                                                                    

   
                                                                                
   
#define STATISTICS_COMPARE_INTERFACE(block_size,    \
                                     output_type)   \
    do                                              \
    {                                               \
        TEST_ASSERT_BUFFERS_EQUAL(                  \
            statistics_output_ref.data_ptr,         \
            statistics_output_fut.data_ptr,         \
            1 * sizeof(output_type)                                 \
            );                                      \
        TEST_ASSERT_EQUAL(                          \
            statistics_idx_fut,                     \
            statistics_idx_ref);                    \
    } while (0)                                      \

  
                                                                         
   
#define STATISTICS_SNR_THRESHOLD_float32_t 120
#define STATISTICS_SNR_THRESHOLD_q31_t 100
#define STATISTICS_SNR_THRESHOLD_q15_t 60
#define STATISTICS_SNR_THRESHOLD_q7_t 30

   
                                                
  
                                                                   
   
#define STATISTICS_SNR_COMPARE_INTERFACE(block_size,    \
                                         output_type)   \
    do                                                  \
    {                                                   \
        TEST_CONVERT_AND_ASSERT_SNR(                    \
            statistics_output_f32_ref,                  \
            statistics_output_ref.data_ptr,             \
            statistics_output_f32_fut,                  \
            statistics_output_fut.data_ptr,             \
                1,                                      \
            output_type,                                \
            STATISTICS_SNR_THRESHOLD_##output_type      \
            );                                          \
    } while (0)



                                                                                    
                      
                                                                                    
  
            
                                                                             
                                                                        
  
                                                        
  
                                
                             
  
                                                                               
                                                                          
                          
   

#define ARM_max_INPUT_INTERFACE(input, block_size)              \
    PAREN(input, block_size,                                    \
          statistics_output_fut.data_ptr, &statistics_idx_fut)

#define REF_max_INPUT_INTERFACE(input, block_size)              \
    PAREN(input, block_size,                                    \
          statistics_output_ref.data_ptr, &statistics_idx_ref)

#define ARM_mean_INPUT_INTERFACE(input, block_size)             \
    PAREN(input, block_size, statistics_output_fut.data_ptr)

#define REF_mean_INPUT_INTERFACE(input, block_size)             \
    PAREN(input, block_size, statistics_output_ref.data_ptr)

#define ARM_min_INPUT_INTERFACE(input, block_size)              \
    PAREN(input, block_size,                                    \
          statistics_output_fut.data_ptr, &statistics_idx_fut)

#define REF_min_INPUT_INTERFACE(input, block_size)              \
    PAREN(input, block_size,                                    \
          statistics_output_ref.data_ptr, &statistics_idx_ref)

#define ARM_power_INPUT_INTERFACE(input, block_size)            \
    PAREN(input, block_size, statistics_output_fut.data_ptr)

#define REF_power_INPUT_INTERFACE(input, block_size)            \
    PAREN(input, block_size, statistics_output_ref.data_ptr)

#define ARM_rms_INPUT_INTERFACE(input, block_size)              \
    PAREN(input, block_size, statistics_output_fut.data_ptr)

#define REF_rms_INPUT_INTERFACE(input, block_size)              \
    PAREN(input, block_size, statistics_output_ref.data_ptr)

#define ARM_std_INPUT_INTERFACE(input, block_size)              \
    PAREN(input, block_size, statistics_output_fut.data_ptr)

#define REF_std_INPUT_INTERFACE(input, block_size)              \
    PAREN(input, block_size, statistics_output_ref.data_ptr)

#define ARM_var_INPUT_INTERFACE(input, block_size)              \
    PAREN(input, block_size, statistics_output_fut.data_ptr)

#define REF_var_INPUT_INTERFACE(input, block_size)              \
    PAREN(input, block_size, statistics_output_ref.data_ptr)


                                                                                    
                    
                                                                                    

   
                                                                     
  
                                                                           
                             
   
#define STATISTICS_DEFINE_TEST_TEMPLATE_BUF1_BLK(fn_name,       \
                                                 suffix,        \
                                                 input_type,    \
                                                 output_type,   \
                                                 comparison_interface)  \
    JTEST_DEFINE_TEST(arm_##fn_name##_##suffix##_test,          \
                      arm_##fn_name##_##suffix)                 \
    {                                                           \
        TEST_TEMPLATE_BUF1_BLK(                                 \
            statistics_f_all,                                   \
            statistics_block_sizes,                             \
            input_type,                                         \
            output_type,                                        \
            arm_##fn_name##_##suffix,                           \
            ARM_##fn_name##_INPUT_INTERFACE,                    \
            ref_##fn_name##_##suffix,                           \
            REF_##fn_name##_INPUT_INTERFACE,                    \
            comparison_interface);                              \
    }


#endif                               

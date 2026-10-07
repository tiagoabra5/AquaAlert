#ifndef _COMPLEX_MATH_TEMPLATES_H_
#define _COMPLEX_MATH_TEMPLATES_H_

                                                                                    
              
                                                                                    
#include "test_templates.h"

                                                                                    
                              
                                                                                    

   
                                                                           
             
   
#define COMPLEX_MATH_COMPARE_RE_INTERFACE(block_size, output_type)  \
    TEST_ASSERT_BUFFERS_EQUAL(                                      \
        complex_math_output_ref_a.data_ptr,                         \
        complex_math_output_fut_a.data_ptr,                         \
        block_size * sizeof(output_type))

   
                                                                               
                       
   
#define COMPLEX_MATH_COMPARE_CMPLX_INTERFACE(block_size, output_type)   \
    do                                                                  \
    {                                                                   \
        COMPLEX_MATH_COMPARE_RE_INTERFACE(block_size * 2, output_type); \
    } while (0)


  
                                                                           
   
#define COMPLEX_MATH_SNR_THRESHOLD_float32_t 120
#define COMPLEX_MATH_SNR_THRESHOLD_q31_t 100
#define COMPLEX_MATH_SNR_THRESHOLD_q15_t 75

   
                                                
  
                                                                   
                                                                         
  
                                   
                                   
                               
                               
  
                                                                   
   
#define COMPLEX_MATH_SNR_COMPARE_OUT_INTERFACE(block_size,      \
                                               output_type,     \
                                               output_suffix)   \
    do                                                          \
    {                                                           \
        TEST_CONVERT_AND_ASSERT_SNR(                            \
            complex_math_output_f32_ref_##output_suffix,        \
            complex_math_output_ref_##output_suffix.data_ptr,   \
            complex_math_output_f32_fut_##output_suffix,        \
            complex_math_output_fut_##output_suffix.data_ptr,   \
            block_size,                                         \
            output_type,                                        \
            COMPLEX_MATH_SNR_THRESHOLD_##output_type            \
            );                                                  \
    } while (0)

   
                                                                            
   
#define COMPLEX_MATH_SNR_COMPARE_RE_INTERFACE(block_size,       \
                                                   output_type) \
    COMPLEX_MATH_SNR_COMPARE_OUT_INTERFACE(block_size,          \
                                           output_type,         \
                                           a)

   
                                                                               
   
#define COMPLEX_MATH_SNR_COMPARE_CMPLX_INTERFACE(block_size,    \
                                                 output_type)   \
        COMPLEX_MATH_SNR_COMPARE_OUT_INTERFACE(block_size * 2,  \
                                               output_type,     \
                                               a)

   
                                                      
  
                                                                           
            
   
#define COMPLEX_MATH_SNR_COMPARE_SPLIT_INTERFACE(block_size,    \
                                                 output_type)   \
        do                                                      \
        {                                                       \
            COMPLEX_MATH_SNR_COMPARE_OUT_INTERFACE(block_size,  \
                                                   output_type, \
                                                   a);          \
            COMPLEX_MATH_SNR_COMPARE_OUT_INTERFACE(block_size,  \
                                                   output_type, \
                                                   b);          \
        } while (0)


                                                                                    
                      
                                                                                    
  
            
                                                                             
                                                                        
  
                                                        
  
                                
                             
  
                                                                               
                                                                          
                          
   

#define ARM_cmplx_conj_INPUT_INTERFACE(input, block_size)           \
    PAREN(input, complex_math_output_fut_a.data_ptr, block_size)

#define REF_cmplx_conj_INPUT_INTERFACE(input, block_size)           \
    PAREN(input, complex_math_output_ref_a.data_ptr, block_size)

#define ARM_cmplx_dot_prod_INPUT_INTERFACE(input_a, input_b, block_size) \
    PAREN(input_a, input_b, block_size,                                 \
          complex_math_output_fut_a.data_ptr,                          \
          complex_math_output_fut_b.data_ptr)

#define REF_cmplx_dot_prod_INPUT_INTERFACE(input_a, input_b, block_size) \
    PAREN(input_a, input_b, block_size,                                 \
          complex_math_output_ref_a.data_ptr,                          \
          complex_math_output_ref_b.data_ptr)

#define ARM_cmplx_mag_INPUT_INTERFACE(input, block_size)            \
    PAREN(input, complex_math_output_fut_a.data_ptr, block_size)

#define REF_cmplx_mag_INPUT_INTERFACE(input, block_size)            \
    PAREN(input, complex_math_output_ref_a.data_ptr, block_size)

#define ARM_cmplx_mag_squared_INPUT_INTERFACE(input, block_size)    \
    PAREN(input, complex_math_output_fut_a.data_ptr, block_size)

#define REF_cmplx_mag_squared_INPUT_INTERFACE(input, block_size)    \
    PAREN(input, complex_math_output_ref_a.data_ptr, block_size)

#define ARM_cmplx_mult_cmplx_INPUT_INTERFACE(input_a, input_b, block_size) \
    PAREN(input_a, input_b, complex_math_output_fut_a.data_ptr, block_size)

#define REF_cmplx_mult_cmplx_INPUT_INTERFACE(input_a, input_b, block_size) \
    PAREN(input_a, input_b, complex_math_output_ref_a.data_ptr, block_size)

#define ARM_cmplx_mult_real_INPUT_INTERFACE(input_a, input_b, block_size) \
    PAREN(input_a, input_b, complex_math_output_fut_a.data_ptr, block_size)

#define REF_cmplx_mult_real_INPUT_INTERFACE(input_a, input_b, block_size) \
    PAREN(input_a, input_b, complex_math_output_ref_a.data_ptr, block_size)

                                                                                    
                    
                                                                                    

   
                                                                       
  
                                                                           
                             
   
#define COMPLEX_MATH_DEFINE_TEST_TEMPLATE_BUF1_BLK(fn_name,         \
                                                   suffix,          \
                                                   input_type,      \
                                                   output_type,     \
                                                   comparison_interface) \
    JTEST_DEFINE_TEST(arm_##fn_name##_##suffix##_test,              \
                      arm_##fn_name##_##suffix)                     \
    {                                                               \
        TEST_TEMPLATE_BUF1_BLK(                                     \
            complex_math_f_all,                                     \
            complex_math_block_sizes,                               \
            input_type,                                             \
            output_type,                                            \
            arm_##fn_name##_##suffix,                               \
            ARM_##fn_name##_INPUT_INTERFACE,                        \
            ref_##fn_name##_##suffix,                               \
            REF_##fn_name##_INPUT_INTERFACE,                        \
            comparison_interface);                                  \
    }

   
                                                                        
  
                                                                           
                             
   
#define COMPLEX_MATH_DEFINE_TEST_TEMPLATE_BUF2_BLK(fn_name,         \
                                                   suffix,          \
                                                   input_type,      \
                                                   output_type,     \
                                                   comparison_interface) \
    JTEST_DEFINE_TEST(arm_##fn_name##_##suffix##_test,              \
                      arm_##fn_name##_##suffix)                     \
    {                                                               \
        TEST_TEMPLATE_BUF2_BLK(                                     \
            complex_math_f_all,                                     \
            complex_math_f_all,                                     \
            complex_math_block_sizes,                               \
            input_type,                                             \
            output_type,                                            \
            arm_##fn_name##_##suffix,                               \
            ARM_##fn_name##_INPUT_INTERFACE,                        \
            ref_##fn_name##_##suffix,                               \
            REF_##fn_name##_INPUT_INTERFACE,                        \
            comparison_interface);                                  \
    }

#endif                                 

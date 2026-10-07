#ifndef _BASIC_MATH_TEMPLATES_H_
#define _BASIC_MATH_TEMPLATES_H_

                                                                                    
              
                                                                                    
#include "test_templates.h"

                                                                                    
                              
                                                                                    

   
                                                                                
                           
   
#define BASIC_MATH_COMPARE_INTERFACE(block_size, output_type)   \
    TEST_ASSERT_BUFFERS_EQUAL(                                  \
        basic_math_output_ref.data_ptr,                         \
        basic_math_output_fut.data_ptr,                         \
        block_size * sizeof(output_type))

  
                                                                         
   
#define BASIC_MATH_SNR_THRESHOLD_float32_t 120
#define BASIC_MATH_SNR_THRESHOLD_q31_t 100
#define BASIC_MATH_SNR_THRESHOLD_q15_t 75
#define BASIC_MATH_SNR_THRESHOLD_q7_t 25

   
                                                
  
                                                                   
   
#define BASIC_MATH_SNR_COMPARE_INTERFACE(block_size, output_type)   \
    do                                                              \
    {                                                               \
        TEST_CONVERT_AND_ASSERT_SNR(                                \
            basic_math_output_f32_ref,                              \
            basic_math_output_ref.data_ptr,                         \
            basic_math_output_f32_fut,                              \
            basic_math_output_fut.data_ptr,                         \
            block_size,                                             \
            output_type,                                            \
            BASIC_MATH_SNR_THRESHOLD_##output_type                  \
            );                                                      \
    } while (0)


   
                                                
  
                                                                   
   
#define BASIC_MATH_SNR_ELT1_COMPARE_INTERFACE(block_size, output_type)  \
    do                                                                  \
    {                                                                   \
        TEST_CONVERT_AND_ASSERT_SNR(                                    \
            basic_math_output_f32_ref,                                  \
            basic_math_output_ref.data_ptr,                             \
            basic_math_output_f32_fut,                                  \
            basic_math_output_fut.data_ptr,                             \
            1,                                                          \
            output_type,                                                \
            BASIC_MATH_SNR_THRESHOLD_##output_type                      \
            );                                                          \
    } while (0)



                                                                                    
                      
                                                                                    
  
            
                                                                             
                                                                        
  
                                                        
  
                                
                             
  
                                                                               
                                                                          
                          
   

#define ARM_abs_INPUT_INTERFACE(input, block_size)              \
    PAREN(input, basic_math_output_fut.data_ptr, block_size)

#define REF_abs_INPUT_INTERFACE(input, block_size)              \
    PAREN(input, basic_math_output_ref.data_ptr, block_size)

#define ARM_add_INPUT_INTERFACE(input_a, input_b, block_size)           \
    PAREN(input_a, input_b, basic_math_output_fut.data_ptr, block_size) \

#define REF_add_INPUT_INTERFACE(input_a, input_b, block_size)           \
    PAREN(input_a, input_b, basic_math_output_ref.data_ptr, block_size) \

#define ARM_dot_prod_INPUT_INTERFACE(input_a, input_b, block_size)      \
    PAREN(input_a, input_b, block_size, basic_math_output_fut.data_ptr) \

#define REF_dot_prod_INPUT_INTERFACE(input_a, input_b, block_size)      \
    PAREN(input_a, input_b, block_size, basic_math_output_ref.data_ptr) \

#define ARM_mult_INPUT_INTERFACE(input_a, input_b, block_size)          \
    PAREN(input_a, input_b, basic_math_output_fut.data_ptr, block_size) \

#define REF_mult_INPUT_INTERFACE(input_a, input_b, block_size)          \
    PAREN(input_a, input_b, basic_math_output_ref.data_ptr, block_size) \

#define ARM_negate_INPUT_INTERFACE(input, block_size)           \
    PAREN(input, basic_math_output_fut.data_ptr, block_size)

#define REF_negate_INPUT_INTERFACE(input, block_size)           \
    PAREN(input, basic_math_output_ref.data_ptr, block_size)

#define ARM_offset_INPUT_INTERFACE(input, elt, block_size)          \
    PAREN(input, elt, basic_math_output_fut.data_ptr, block_size)   \

#define REF_offset_INPUT_INTERFACE(input, elt, block_size)          \
    PAREN(input, elt, basic_math_output_ref.data_ptr, block_size)   \

#define ARM_shift_INPUT_INTERFACE(input, elt, block_size)           \
    PAREN(input, elt, basic_math_output_fut.data_ptr, block_size)   \

#define REF_shift_INPUT_INTERFACE(input, elt, block_size)           \
    PAREN(input, elt, basic_math_output_ref.data_ptr, block_size)   \

#define ARM_scale_float_INPUT_INTERFACE(input, elt, block_size)     \
    PAREN(input, elt, basic_math_output_fut.data_ptr, block_size)   \

#define REF_scale_float_INPUT_INTERFACE(input, elt, block_size)     \
    PAREN(input, elt, basic_math_output_ref.data_ptr, block_size)   \

                                                 
#define ARM_scale_INPUT_INTERFACE(input, elt1, elt2, block_size)        \
    PAREN(input, elt1, elt2, basic_math_output_fut.data_ptr, block_size) \

#define REF_scale_INPUT_INTERFACE(input, elt1, elt2, block_size)        \
    PAREN(input, elt1, elt2, basic_math_output_ref.data_ptr, block_size) \

#define ARM_sub_INPUT_INTERFACE(input_a, input_b, block_size)           \
    PAREN(input_a, input_b, basic_math_output_fut.data_ptr, block_size) \

#define REF_sub_INPUT_INTERFACE(input_a, input_b, block_size)           \
    PAREN(input_a, input_b, basic_math_output_ref.data_ptr, block_size) \


                                                                                    
                    
                                                                                    

   
                                                                     
  
                                                                           
                             
   
#define BASIC_MATH_DEFINE_TEST_TEMPLATE_BUF1_BLK(fn_name,       \
                                                 suffix,        \
                                                 input_type,    \
                                                 output_type)   \
    JTEST_DEFINE_TEST(arm_##fn_name##_##suffix##_test,          \
                      arm_##fn_name##_##suffix)                 \
    {                                                           \
        TEST_TEMPLATE_BUF1_BLK(                                 \
            basic_math_f_all,                                   \
            basic_math_block_sizes,                             \
            input_type,                                         \
            output_type,                                        \
            arm_##fn_name##_##suffix,                           \
            ARM_##fn_name##_INPUT_INTERFACE,                    \
            ref_##fn_name##_##suffix,                           \
            REF_##fn_name##_INPUT_INTERFACE,                    \
            BASIC_MATH_COMPARE_INTERFACE);                      \
    }

   
                                                                     
  
                                                                           
                             
   
#define BASIC_MATH_DEFINE_TEST_TEMPLATE_BUF2_BLK(fn_name,               \
                                                 suffix,                \
                                                 input_type,            \
                                                 output_type,           \
                                                 comparison_interface)  \
    JTEST_DEFINE_TEST(arm_##fn_name##_##suffix##_test,                  \
                      arm_##fn_name##_##suffix)                         \
    {                                                                   \
        TEST_TEMPLATE_BUF2_BLK(                                         \
            basic_math_f_all,                                           \
            basic_math_f_all,                                           \
            basic_math_block_sizes,                                     \
            input_type,                                                 \
            output_type,                                                \
            arm_##fn_name##_##suffix,                                   \
            ARM_##fn_name##_INPUT_INTERFACE,                            \
            ref_##fn_name##_##suffix,                                   \
            REF_##fn_name##_INPUT_INTERFACE,                            \
            comparison_interface);                                      \
    }

   
                                                                          
  
                                                                           
                             
   
#define BASIC_MATH_DEFINE_TEST_TEMPLATE_BUF1_ELT1_BLK(fn_name,      \
                                                      suffix,       \
                                                      input_type,   \
                                                      elt_type,     \
                                                      output_type)  \
    JTEST_DEFINE_TEST(arm_##fn_name##_##suffix##_test,              \
                      arm_##fn_name##_##suffix)                     \
    {                                                               \
        TEST_TEMPLATE_BUF1_ELT1_BLK(                                \
            basic_math_f_all,                                       \
            basic_math_elts,                                        \
            basic_math_block_sizes,                                 \
            input_type,                                             \
            elt_type,                                               \
            output_type,                                            \
            arm_##fn_name##_##suffix,                               \
            ARM_##fn_name##_INPUT_INTERFACE,                        \
            ref_##fn_name##_##suffix,                               \
            REF_##fn_name##_INPUT_INTERFACE,                        \
            BASIC_MATH_COMPARE_INTERFACE);                          \
    }

   
                                                                          
  
                                                                           
                             
   
#define BASIC_MATH_DEFINE_TEST_TEMPLATE_BUF1_ELT2_BLK(fn_name,      \
                                                      suffix,       \
                                                      input_type,   \
                                                      elt1_type,    \
                                                      elt2_type,    \
                                                      output_type)  \
    JTEST_DEFINE_TEST(arm_##fn_name##_##suffix##_test,              \
                      arm_##fn_name##_##suffix)                     \
    {                                                               \
        TEST_TEMPLATE_BUF1_ELT2_BLK(                                \
            basic_math_f_all,                                       \
            basic_math_elts,                                        \
            basic_math_elts2,                                       \
            basic_math_block_sizes,                                 \
            input_type,                                             \
            elt1_type,                                              \
            elt2_type,                                              \
            output_type,                                            \
            arm_##fn_name##_##suffix,                               \
            ARM_##fn_name##_INPUT_INTERFACE,                        \
            ref_##fn_name##_##suffix,                               \
            REF_##fn_name##_INPUT_INTERFACE,                        \
            BASIC_MATH_COMPARE_INTERFACE);                          \
    }

#endif                               

#include "jtest.h"
#include "filtering_test_data.h"
#include "arr_desc.h"
#include "arm_math.h"                     
#include "ref.h"                                         
#include "test_templates.h"
#include "filtering_templates.h"
#include "type_abbrev.h"

                                                                                    
                  
                                                                                    

#define CONV_MAX_INPUT_ELTS  32
#define CONV_MAX_OUTPUT_ELTS (CONV_MAX_INPUT_ELTS * 2)

#define CONV_TEST_VALID_PARTIAL_PARAMS(input_a_len, input_b_len,           \
                                       first_index, num_points)            \
    (((((input_a_len) + (input_b_len) - 1)) >= num_points + first_index )  \
    && (num_points > 0))

                                                                                    
                      
                                                                                    
  
            
                                                                             
                                                                        
  
                                                        
  
                                
                             
  
                                                                               
                                                                          
                          
   

#define CONV_arm_conv_INPUT_INTERFACE(input_a, input_a_len, input_b, input_b_len) \
    PAREN(input_a, input_a_len, input_b, input_b_len, (void*)filtering_output_fut)

#define CONV_ref_conv_INPUT_INTERFACE(input_a, input_a_len, input_b, input_b_len) \
    PAREN(input_a, input_a_len, input_b, input_b_len, (void*)filtering_output_ref)

#define CONV_arm_conv_opt_INPUT_INTERFACE(              \
    input_a, input_a_len,                               \
    input_b, input_b_len)                               \
    PAREN(input_a, input_a_len, input_b, input_b_len,   \
          (void*) filtering_output_fut,                 \
          (void*) filtering_scratch,                    \
          (void*) filtering_scratch2)

#define CONV_ref_conv_opt_INPUT_INTERFACE(              \
    input_a, input_a_len,                               \
    input_b, input_b_len)                               \
    PAREN(input_a, input_a_len, input_b, input_b_len,   \
          (void*) filtering_output_ref,                 \
          (void*) filtering_scratch,                    \
          (void*) filtering_scratch2)

#define CONV_arm_conv_fast_INPUT_INTERFACE(input_a, input_a_len,        \
                                           input_b, input_b_len)        \
    PAREN(input_a, input_a_len, input_b, input_b_len, (void*)filtering_output_fut)

#define CONV_ref_conv_fast_INPUT_INTERFACE(input_a, input_a_len,        \
                                           input_b, input_b_len)        \
    PAREN(input_a, input_a_len, input_b, input_b_len, (void*)filtering_output_ref)

#define CONV_arm_conv_fast_opt_INPUT_INTERFACE(         \
    input_a, input_a_len,                               \
    input_b, input_b_len)                               \
    PAREN(input_a, input_a_len, input_b, input_b_len,   \
          (void*) filtering_output_fut,                 \
          (void*) filtering_scratch,                    \
          (void*) filtering_scratch2)

#define CONV_ref_conv_fast_opt_INPUT_INTERFACE(         \
    input_a, input_a_len,                               \
    input_b, input_b_len)                               \
    PAREN(input_a, input_a_len, input_b, input_b_len,   \
          (void*) filtering_output_ref,                 \
          (void*) filtering_scratch,                    \
          (void*) filtering_scratch2)

#define CONV_arm_conv_partial_INPUT_INTERFACE(input_a, input_a_len,     \
                                              input_b, input_b_len,     \
                                              first_index, num_points)  \
    PAREN(input_a, input_a_len, input_b, input_b_len,                   \
          (void*)filtering_output_fut, first_index, num_points)

#define CONV_ref_conv_partial_INPUT_INTERFACE(input_a, input_a_len,     \
                                              input_b, input_b_len,     \
                                              first_index, num_points)  \
    PAREN(input_a, input_a_len, input_b, input_b_len,                   \
          (void*)filtering_output_ref, first_index, num_points)

#define CONV_arm_conv_partial_fast_INPUT_INTERFACE(input_a, input_a_len,   \
                                              input_b, input_b_len,        \
                                              first_index, num_points)     \
    PAREN(input_a, input_a_len, input_b, input_b_len,                      \
          (void*)filtering_output_fut, first_index, num_points)

#define CONV_ref_conv_partial_fast_INPUT_INTERFACE(input_a, input_a_len,   \
                                              input_b, input_b_len,        \
                                              first_index, num_points)     \
    PAREN(input_a, input_a_len, input_b, input_b_len,                      \
          (void*)filtering_output_ref, first_index, num_points)

#define CONV_arm_conv_partial_opt_INPUT_INTERFACE(input_a, input_a_len, \
                                              input_b, input_b_len,     \
                                              first_index, num_points)  \
    PAREN(input_a, input_a_len, input_b, input_b_len,                   \
          (void*)filtering_output_fut, first_index, num_points,         \
          (void*) filtering_scratch,                                    \
          (void*) filtering_scratch2)

#define CONV_ref_conv_partial_opt_INPUT_INTERFACE(input_a, input_a_len, \
                                              input_b, input_b_len,     \
                                              first_index, num_points)  \
    PAREN(input_a, input_a_len, input_b, input_b_len,                   \
          (void*)filtering_output_ref, first_index, num_points,         \
          (void*) filtering_scratch,                                    \
          (void*) filtering_scratch2)

#define CONV_arm_conv_partial_fast_opt_INPUT_INTERFACE(input_a, input_a_len,  \
                                              input_b, input_b_len,           \
                                              first_index, num_points)        \
    PAREN(input_a, input_a_len, input_b, input_b_len,                         \
          (void*)filtering_output_fut, first_index, num_points,               \
          (void*) filtering_scratch,                                          \
          (void*) filtering_scratch2)

#define CONV_ref_conv_partial_fast_opt_INPUT_INTERFACE(input_a, input_a_len,  \
                                              input_b, input_b_len,           \
                                              first_index, num_points)        \
    PAREN(input_a, input_a_len, input_b, input_b_len,                         \
          (void*)filtering_output_ref, first_index, num_points,               \
          (void*) filtering_scratch,                                          \
          (void*) filtering_scratch2)

                                                                                    
                        
                                                                                    

                                                              
  
                         
                        
  
                                                                        
  
                                                                                
                                                                            
                                     
  
   
#define CONV_f32_INPUTS filtering_f32_inputs
#define CONV_q31_INPUTS filtering_q31_inputs
#define CONV_q15_INPUTS filtering_q31_inputs
#define CONV_q7_INPUTS  filtering_q31_inputs

   
                                                                         
           
   
#define CONV_DEFINE_RAND_INPUT_ARR_DESCS(type_suffix)           \
    ARR_DESC_DEFINE_USING_ARR(                                  \
        TYPE_FROM_ABBREV(type_suffix),                          \
        conv_input_rand1_##type_suffix,                         \
        CONV_##type_suffix##_INPUTS,                            \
        0,                                                      \
        CONV_MAX_INPUT_ELTS);                                   \
                                                                \
    ARR_DESC_DEFINE_USING_ARR(                                  \
        TYPE_FROM_ABBREV(type_suffix),                          \
        conv_input_rand2_##type_suffix,                         \
        CONV_##type_suffix##_INPUTS,                            \
        1,                                                      \
        CONV_MAX_INPUT_ELTS)                                  

CONV_DEFINE_RAND_INPUT_ARR_DESCS(f32);
CONV_DEFINE_RAND_INPUT_ARR_DESCS(q31);
CONV_DEFINE_RAND_INPUT_ARR_DESCS(q15);
CONV_DEFINE_RAND_INPUT_ARR_DESCS(q7);
ARR_DESC_DEFINE(float32_t, conv_input_zeros, CONV_MAX_INPUT_ELTS, CURLY(0));

   
                                                   
  
                                                                              
                                     
  
                               
                                 
                               
                                           
   
#define CONV_DEFINE_ALL_INPUTS(type_suffix)                 \
    ARR_DESC_DEFINE(ARR_DESC_t *,                           \
                    conv_##type_suffix##_a_inputs,          \
                    4,                                      \
                    CURLY(                                  \
                        &conv_input_zeros,                  \
                        &conv_input_zeros,                  \
                        &conv_input_rand1_##type_suffix,    \
                        &conv_input_rand1_##type_suffix     \
                        ));                                 \
    ARR_DESC_DEFINE(ARR_DESC_t *,                           \
                    conv_##type_suffix##_b_inputs,          \
                    4,                                      \
                    CURLY(                                  \
                        &conv_input_zeros,                  \
                        &conv_input_rand1_##type_suffix,    \
                        &conv_input_zeros,                  \
                        &conv_input_rand2_##type_suffix     \
                        ))                                 

CONV_DEFINE_ALL_INPUTS(f32);
CONV_DEFINE_ALL_INPUTS(q31);
CONV_DEFINE_ALL_INPUTS(q15);
CONV_DEFINE_ALL_INPUTS(q7);

                                                                                    
                         
                                                                                    

  
                                                                                
                                                                           
                    
  
                                               
                                                               
                                                               
                                                               
                                     
   
ARR_DESC_DEFINE(uint32_t,
                conv_lens_a,
                5,
                CURLY(
                    1,
                    1,
                    17,
                    15,
                    CONV_MAX_INPUT_ELTS
                    ));

ARR_DESC_DEFINE(uint32_t,
                conv_lens_b,
                5,
                CURLY(
                    1,
                    2,
                    1,
                    CONV_MAX_INPUT_ELTS,
                    CONV_MAX_INPUT_ELTS
                    ));

                                                                                    
                      
                                                                                    

ARR_DESC_DEFINE(uint32_t,
                first_index_arr_desc,
                4,
                CURLY(
                    0,
                    1,
                    CONV_MAX_INPUT_ELTS / 2,
                    CONV_MAX_INPUT_ELTS
                    ));

ARR_DESC_DEFINE(uint32_t,
                num_points_arr_desc,
                3,
                CURLY(
                    1,
                    CONV_MAX_OUTPUT_ELTS / 2,
                    CONV_MAX_OUTPUT_ELTS
                    ));

                                                                                    
                       
                                                                                    

#define CONV_TEST_TEMPLATE(fut, fut_arg_interface,                            \
                           ref, ref_arg_interface,                            \
                           suffix, output_type)                               \
    JTEST_DEFINE_TEST(fut##_tests, fut)                                       \
    {                                                                         \
        TEMPLATE_DO_ARR_DESC(                                                 \
            input_idx, ARR_DESC_t *, input_ptr, conv_##suffix##_a_inputs      \
            ,                                                                 \
            void * input_a_ptr = input_ptr->data_ptr;                         \
            void * input_b_ptr = ARR_DESC_ELT(                                \
                ARR_DESC_t *, input_idx,                                      \
                &(conv_##suffix##_b_inputs))->data_ptr;                       \
                                                                              \
            TEMPLATE_DO_ARR_DESC(                                             \
                conv_len_idx, uint32_t, conv_len_a, conv_lens_a               \
                ,                                                             \
                uint32_t conv_len_b = ARR_DESC_ELT(                           \
                    uint32_t, conv_len_idx, &(conv_lens_b));                  \
                                                                              \
                JTEST_DUMP_STRF("Input A Length: %d\n"                        \
                                "Input B Length: %d\n",                       \
                                (int)conv_len_a,                              \
                                (int)conv_len_b);                             \
                                                                              \
                TEST_CALL_FUT_AND_REF(                                        \
                    fut, fut_arg_interface(                                   \
                        input_a_ptr, conv_len_a, input_b_ptr, conv_len_b),    \
                    ref, ref_arg_interface(                                   \
                        input_a_ptr, conv_len_a, input_b_ptr, conv_len_b));   \
                                                                              \
                FILTERING_SNR_COMPARE_INTERFACE(                              \
                    conv_len_a + conv_len_b - 1,                              \
                    output_type)));                                           \
                                                                              \
        return JTEST_TEST_PASSED;                                             \
    }                                                                         \
                                                                              \

#define CONV_PARTIAL_TEST_TEMPLATE(fut, fut_arg_interface,                    \
                                   ref, ref_arg_interface,                    \
                                   suffix, output_type)                       \
    JTEST_DEFINE_TEST(fut##_tests, fut)                                       \
    {                                                                         \
        TEMPLATE_DO_ARR_DESC(                                                 \
            input_idx, ARR_DESC_t *, input_ptr, conv_##suffix##_a_inputs      \
            ,                                                                 \
            void * input_a_ptr = input_ptr->data_ptr;                         \
            void * input_b_ptr = ARR_DESC_ELT(                                \
                ARR_DESC_t *, input_idx,                                      \
                &(conv_##suffix##_b_inputs))->data_ptr;                       \
            TEMPLATE_DO_ARR_DESC(                                             \
                conv_len_idx, uint32_t, conv_len_a, conv_lens_a               \
                ,                                                             \
                uint32_t conv_len_b = ARR_DESC_ELT(                           \
                    uint32_t, conv_len_idx, &(conv_lens_b));                  \
                                                                              \
                TEMPLATE_DO_ARR_DESC(                                         \
                    first_index_idx, uint32_t, first_index,                   \
                    first_index_arr_desc                                      \
                    ,                                                         \
                    TEMPLATE_DO_ARR_DESC(                                     \
                        num_points_idx, uint32_t, num_points,                 \
                        num_points_arr_desc                                   \
                        ,                                                     \
                        if (CONV_TEST_VALID_PARTIAL_PARAMS(                   \
                                conv_len_a, conv_len_b,                       \
                                first_index, num_points))                     \
                        {                                                     \
                                                                              \
                            JTEST_DUMP_STRF("Input A Length: %d\n"            \
                                            "Input B Length: %d\n"            \
                                            "First Sample Index: %d\n"        \
                                            "Number of Output Points: %d\n",  \
                                            (int)conv_len_a,                  \
                                            (int)conv_len_b,                  \
                                            (int)first_index,                 \
                                            (int)num_points);                 \
                                                                              \
                           memset(filtering_output_ref,0,                     \
                                 (2*CONV_MAX_INPUT_ELTS)*sizeof(output_type)); \
                           memset(filtering_output_fut,0,                     \
                                 (2*CONV_MAX_INPUT_ELTS)*sizeof(output_type)); \
                                                                              \
                            TEST_CALL_FUT_AND_REF(                            \
                                fut, fut_arg_interface(                       \
                                    input_a_ptr, conv_len_a,                  \
                                    input_b_ptr, conv_len_b,                  \
                                    first_index, num_points),                 \
                                ref, ref_arg_interface(                       \
                                    input_a_ptr, conv_len_a,                  \
                                    input_b_ptr, conv_len_b,                  \
                                    first_index, num_points));                \
                                                                              \
                            FILTERING_SNR_COMPARE_INTERFACE_OFFSET(           \
                                first_index,                                  \
                                num_points,                                   \
                                output_type);                                 \
                        } else {                                              \
                                                                              \
                                                                              \
                                                                              \
                                                                              \
                            arm_status conv_test_retval;                      \
                            TEST_CALL_FUT(                                    \
                                conv_test_retval = fut,                       \
                                fut_arg_interface(                            \
                                    input_a_ptr, conv_len_a,                  \
                                    input_b_ptr, conv_len_b,                  \
                                    first_index, num_points));                \
                                                                              \
                            if (conv_test_retval != ARM_MATH_ARGUMENT_ERROR) { \
                                JTEST_DUMP_STR("FUT failed to raise error."); \
                                                                              \
                            }                                                 \
                        }))));                                                \
                                                                              \
        return JTEST_TEST_PASSED;                                             \
    }

#define CONV_DEFINE_TEST(fn_name, suffix, output_type, test_template)   \
    test_template(                                                      \
        arm_##fn_name##_##suffix,                                       \
        CONV_arm_##fn_name##_INPUT_INTERFACE,                           \
        ref_##fn_name##_##suffix,                                       \
        CONV_ref_##fn_name##_INPUT_INTERFACE,                           \
        suffix,                                                         \
        output_type                                                     \
        )                                

                                                
CONV_DEFINE_TEST(conv          , f32, float32_t, CONV_TEST_TEMPLATE);
CONV_DEFINE_TEST(conv          , q31, q31_t    , CONV_TEST_TEMPLATE);
CONV_DEFINE_TEST(conv          , q15, q15_t    , CONV_TEST_TEMPLATE);
CONV_DEFINE_TEST(conv          , q7 , q7_t     , CONV_TEST_TEMPLATE);
CONV_DEFINE_TEST(conv_opt      , q15, q15_t    , CONV_TEST_TEMPLATE);
CONV_DEFINE_TEST(conv_opt      , q7 , q7_t     , CONV_TEST_TEMPLATE);
CONV_DEFINE_TEST(conv_fast     , q31, q31_t    , CONV_TEST_TEMPLATE);
CONV_DEFINE_TEST(conv_fast     , q15, q15_t    , CONV_TEST_TEMPLATE);
CONV_DEFINE_TEST(conv_fast_opt , q15, q15_t    , CONV_TEST_TEMPLATE);

                                              
CONV_DEFINE_TEST(conv_partial          , f32, float32_t, CONV_PARTIAL_TEST_TEMPLATE);
CONV_DEFINE_TEST(conv_partial          , q31, q31_t    , CONV_PARTIAL_TEST_TEMPLATE);
CONV_DEFINE_TEST(conv_partial          , q15, q15_t    , CONV_PARTIAL_TEST_TEMPLATE);
CONV_DEFINE_TEST(conv_partial          , q7 , q7_t     , CONV_PARTIAL_TEST_TEMPLATE);
CONV_DEFINE_TEST(conv_partial_fast     , q31, q31_t    , CONV_PARTIAL_TEST_TEMPLATE);
CONV_DEFINE_TEST(conv_partial_fast     , q15, q15_t    , CONV_PARTIAL_TEST_TEMPLATE);
CONV_DEFINE_TEST(conv_partial_fast_opt , q15, q15_t    , CONV_PARTIAL_TEST_TEMPLATE);
CONV_DEFINE_TEST(conv_partial_opt      , q15, q15_t    , CONV_PARTIAL_TEST_TEMPLATE);
CONV_DEFINE_TEST(conv_partial_opt      , q7 , q7_t     , CONV_PARTIAL_TEST_TEMPLATE);

                                                                                    
                                   
                                                                                    

JTEST_DEFINE_GROUP(conv_tests)
{
    
                                   
    
  JTEST_TEST_CALL(arm_conv_f32_tests);
  JTEST_TEST_CALL(arm_conv_q31_tests);
  JTEST_TEST_CALL(arm_conv_q15_tests);
  JTEST_TEST_CALL(arm_conv_q7_tests);

  JTEST_TEST_CALL(arm_conv_opt_q15_tests);
  JTEST_TEST_CALL(arm_conv_opt_q7_tests);

  JTEST_TEST_CALL(arm_conv_fast_q31_tests);
  JTEST_TEST_CALL(arm_conv_fast_q15_tests);

  JTEST_TEST_CALL(arm_conv_fast_opt_q15_tests);

  JTEST_TEST_CALL(arm_conv_partial_f32_tests);
  JTEST_TEST_CALL(arm_conv_partial_q31_tests);
  JTEST_TEST_CALL(arm_conv_partial_q15_tests);
  JTEST_TEST_CALL(arm_conv_partial_q7_tests);

  JTEST_TEST_CALL(arm_conv_partial_fast_q31_tests);
  JTEST_TEST_CALL(arm_conv_partial_fast_q15_tests);

  JTEST_TEST_CALL(arm_conv_partial_fast_opt_q15_tests);

  JTEST_TEST_CALL(arm_conv_partial_opt_q15_tests);
  JTEST_TEST_CALL(arm_conv_partial_opt_q7_tests);
}

#include "jtest.h"
#include "ref.h"
#include "arr_desc.h"
#include "transform_templates.h"
#include "transform_test_data.h"

#define CFFT_SNR_THRESHOLD 120

  
                                                                              
                                                                             
  
#define CFFT_TEST_BODY(ifft_flag, suffix, output_type)                                  \
    do                                                                                  \
    {                                                                                   \
                                                                                        \
        TEMPLATE_DO_ARR_DESC(                                                           \
            cfft_inst_idx, const arm_cfft_instance_##suffix *, cfft_inst_ptr,           \
            transform_cfft_##suffix##_structs                                           \
            ,                                                                           \
                                                                                        \
            TRANSFORM_PREPARE_INPLACE_INPUTS(                                           \
                transform_fft_##suffix##_inputs,                                        \
                cfft_inst_ptr->fftLen *                                                 \
                sizeof(output_type) *                                                   \
                2                   );                                                  \
                                                                                        \
                                                                                        \
                JTEST_DUMP_STRF("Block Size: %d\n"                                      \
                                "Inverse-transform flag: %d\n",                         \
                                (int)cfft_inst_ptr->fftLen,                             \
                                (int)ifft_flag);                                        \
                                                                                        \
                                                                                        \
            JTEST_COUNT_CYCLES(                                                         \
                arm_cfft_##suffix(cfft_inst_ptr,                                        \
                             (void *) transform_fft_inplace_input_fut,                  \
                             ifft_flag,                                                 \
                             1));                                                       \
            ref_cfft_##suffix(cfft_inst_ptr,                                            \
                         (void *) transform_fft_inplace_input_ref,                      \
                         ifft_flag,                                                     \
                         1);                                                            \
                                                                                        \
                                                                                        \
            TRANSFORM_SNR_COMPARE_CMPLX_INTERFACE(                                      \
                cfft_inst_ptr->fftLen,                                                  \
                output_type));                                                          \
                                                                                        \
        return JTEST_TEST_PASSED;                                                       \
    } while (0)


  
                                                                                    
                                                                                      
  
#define CFFT_DOWNSHIFT_INPUT_TEST_BODY(ifft_flag, suffix, output_type)                  \
    do                                                                                  \
    {                                                                                   \
                                                                                        \
        TEMPLATE_DO_ARR_DESC(                                                           \
            cfft_inst_idx, const arm_cfft_instance_##suffix *, cfft_inst_ptr,           \
            transform_cfft_##suffix##_structs                                           \
            ,                                                                           \
                                                                                        \
            TRANSFORM_PREPARE_INPLACE_INPUTS_DOWNSHIFT(                                 \
                transform_fft_##suffix##_inputs,                                        \
                cfft_inst_ptr->fftLen *                                                 \
                sizeof(output_type) *                                                   \
                2                   , output_type);                                     \
                                                                                        \
                                                                                        \
            JTEST_DUMP_STRF("Block Size: %d\n"                                          \
                            "Inverse-transform flag: %d\n",                             \
                            (int)cfft_inst_ptr->fftLen,                                 \
                            (int)ifft_flag);                                            \
                                                                                        \
                                                                                        \
            JTEST_COUNT_CYCLES(                                                         \
                arm_cfft_##suffix(cfft_inst_ptr,                                        \
                             (void *) transform_fft_inplace_input_fut,                  \
                             ifft_flag,                                                 \
                             1));                                                       \
            ref_cfft_##suffix(cfft_inst_ptr,                                            \
                         (void *) transform_fft_inplace_input_ref,                      \
                         ifft_flag,                                                     \
                         1);                                                            \
                                                                                        \
                                                                                        \
            TRANSFORM_SNR_COMPARE_CMPLX_INTERFACE(                                      \
                cfft_inst_ptr->fftLen,                                                  \
                output_type));                                                          \
                                                                                        \
        return JTEST_TEST_PASSED;                                                       \
    } while (0)


                       
JTEST_DEFINE_TEST(cfft_f32_test, cfft_f32)
{
    CFFT_TEST_BODY((uint8_t) 0, f32, float32_t);
}

JTEST_DEFINE_TEST(cfft_f32_ifft_test, cfft_f32)
{
    CFFT_TEST_BODY((uint8_t) 1, f32, float32_t);
}

JTEST_DEFINE_TEST(cfft_q31_test, cfft_q31)
{
    CFFT_TEST_BODY((uint8_t) 0, q31, q31_t);
}

JTEST_DEFINE_TEST(cfft_q31_ifft_test, cfft_q31)
{
    CFFT_TEST_BODY((uint8_t) 1, q31, q31_t);
}

JTEST_DEFINE_TEST(cfft_q15_test, cfft_q15)
{
    CFFT_TEST_BODY((uint8_t) 0, q15, q15_t);
}

JTEST_DEFINE_TEST(cfft_q15_ifft_test, cfft_q15)
{
    CFFT_TEST_BODY((uint8_t) 1, q15, q15_t);
}

                                                                                    
                                  
                                                                                    

JTEST_DEFINE_GROUP(cfft_tests)
{
    JTEST_TEST_CALL(cfft_f32_test);
    JTEST_TEST_CALL(cfft_f32_ifft_test);

    JTEST_TEST_CALL(cfft_q31_test);
    JTEST_TEST_CALL(cfft_q31_ifft_test);

    JTEST_TEST_CALL(cfft_q15_test);
    JTEST_TEST_CALL(cfft_q15_ifft_test);
}

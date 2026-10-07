#include "jtest.h"
#include "ref.h"
#include "arr_desc.h"
#include "transform_templates.h"
#include "transform_test_data.h"
#include "type_abbrev.h"

  
                                                                             
                                                                                  
                                                         
  
#define RFFT_DEFINE_TEST(suffix, config_suffix,                         \
                         ifft_flag, input_type, output_type)            \
    JTEST_DEFINE_TEST(arm_rfft_##suffix##_##config_suffix##_test,       \
                      arm_rfft_##suffix)                                \
    {                                                                   \
        CONCAT(arm_rfft_instance_, suffix) rfft_inst_fut = {0};         \
        CONCAT(arm_rfft_instance_, suffix) rfft_inst_ref = {0};         \
                                                                        \
                                                                        \
        TEMPLATE_DO_ARR_DESC(                                           \
            fftlen_idx, uint16_t, fftlen, transform_rfft_fftlens        \
            ,                                                           \
                                                                        \
                                                                        \
            arm_rfft_init_##suffix(                                     \
                &rfft_inst_fut,                                         \
                (uint32_t) fftlen, ifft_flag, 1U);                      \
                                                                        \
            arm_rfft_init_##suffix(                                     \
                &rfft_inst_ref,                                         \
                (uint32_t) fftlen, ifft_flag, 1U);                      \
                                                                        \
            if (ifft_flag)                                               \
            {                                                           \
               TRANSFORM_PREPARE_INVERSE_INPUTS(                        \
                   transform_fft_##suffix##_inputs,                     \
                   fftlen, input_type,                                  \
                   fftlen *                                             \
                   sizeof(input_type));                                 \
            }                                                           \
            else                                                        \
            {                                                           \
               TRANSFORM_COPY_INPUTS(                                   \
                   transform_fft_##suffix##_inputs,                     \
                   fftlen *                                             \
                   sizeof(input_type));                                 \
            }                                                           \
                                                                        \
                                                                        \
            JTEST_DUMP_STRF("Block Size: %d\n"                          \
                            "Inverse-transform flag: %d\n",             \
                         (int)fftlen,                                   \
                         (int)ifft_flag);                               \
                                                                        \
                                                                        \
            JTEST_COUNT_CYCLES(                                         \
                arm_rfft_##suffix(                                      \
                    &rfft_inst_fut,                                     \
                    (void *) transform_fft_input_fut,                   \
                    (void *) transform_fft_output_fut));                \
                                                                        \
            ref_rfft_##suffix(                                          \
                &rfft_inst_ref,                                         \
                (void *) transform_fft_input_ref,                       \
                (void *) transform_fft_output_ref);                     \
                                                                        \
                                                                        \
            TRANSFORM_SNR_COMPARE_INTERFACE(                            \
                fftlen,                                                 \
                output_type));                                          \
                                                                        \
            return JTEST_TEST_PASSED;                                   \
    }

RFFT_DEFINE_TEST(q31, forward, 0U, TYPE_FROM_ABBREV(q31), TYPE_FROM_ABBREV(q31));
RFFT_DEFINE_TEST(q15, forward, 0U, TYPE_FROM_ABBREV(q15), TYPE_FROM_ABBREV(q15));
                                                                                   
RFFT_DEFINE_TEST(q31, inverse, 1U, TYPE_FROM_ABBREV(q31), TYPE_FROM_ABBREV(q31));
RFFT_DEFINE_TEST(q15, inverse, 1U, TYPE_FROM_ABBREV(q15), TYPE_FROM_ABBREV(q15));

                                                                                    
                                  
                                                                                    

JTEST_DEFINE_GROUP(rfft_tests)
{
    JTEST_TEST_CALL(arm_rfft_q31_forward_test);
    JTEST_TEST_CALL(arm_rfft_q15_forward_test);
                                                 
    JTEST_TEST_CALL(arm_rfft_q31_inverse_test);
    JTEST_TEST_CALL(arm_rfft_q15_inverse_test);
}

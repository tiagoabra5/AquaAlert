#include "jtest.h"
#include "ref.h"
#include "arm_math.h"
#include "arr_desc.h"
#include "transform_templates.h"
#include "transform_test_data.h"
#include "type_abbrev.h"
#include <math.h>                            

                                                                                    
                                    
                                                                                    
#define ref_sqrt_f32(x) sqrtf(x)

                                                                                    
                      
                                                                                    

  
                                                                        
                                                            
  
#define DCT4_DEFINE_TEST(suffix, input_type)                            \
    JTEST_DEFINE_TEST(arm_dct4_##suffix##_test, arm_dct4_##suffix)      \
    {                                                                   \
        CONCAT(arm_dct4_instance_,suffix) dct4_inst_fut        = {0};   \
        CONCAT(arm_rfft_instance_,suffix) rfft_inst_fut        = {0};   \
        CONCAT(arm_cfft_radix4_instance_,suffix) cfft_inst_fut = {0};   \
                                                                        \
        CONCAT(arm_dct4_instance_,suffix) dct4_inst_ref        = {0};   \
        CONCAT(arm_rfft_instance_,suffix) rfft_inst_ref        = {0};   \
        CONCAT(arm_cfft_radix4_instance_,suffix) cfft_inst_ref = {0};   \
                                                                        \
                                                                        \
        TEMPLATE_DO_ARR_DESC(                                           \
            fftlen_idx, uint16_t, fftlen, transform_dct_fftlens         \
            ,                                                           \
                                                                        \
            float32_t normalize_f32 =                                   \
                  ref_sqrt_f32((2.0f/(float32_t)fftlen));               \
            input_type normalize;                                       \
                                                                        \
                                                                        \
            TEST_CONVERT_FLOAT_TO(&normalize_f32, &normalize,           \
                                  1, input_type);                       \
                                                                        \
                                                                        \
            arm_dct4_init_##suffix(                                     \
                &dct4_inst_fut, &rfft_inst_fut, &cfft_inst_fut,         \
                fftlen,                                                 \
                fftlen/2,                                               \
                normalize);                                             \
                                                                        \
            arm_dct4_init_##suffix(                                     \
                &dct4_inst_ref, &rfft_inst_ref, &cfft_inst_ref,         \
                fftlen,                                                 \
                fftlen/2,                                               \
                normalize);                                             \
                                                                        \
             memset( transform_fft_input_fut,0,                         \
                     fftlen*sizeof(input_type));                        \
                                                                        \
            TRANSFORM_PREPARE_INPLACE_INPUTS(                           \
                transform_fft_##suffix##_inputs,                        \
                fftlen * sizeof(input_type));                           \
                                                                        \
                                                                        \
            JTEST_DUMP_STRF("Block Size: %d\n",                         \
                         (int)fftlen);                                  \
                                                                        \
                                                                         
                                                                        \
            JTEST_COUNT_CYCLES(                                         \
                arm_dct4_##suffix(                                      \
                    &dct4_inst_fut,                                     \
                    (void *) transform_fft_input_fut,                   \
                    (void *) transform_fft_inplace_input_fut));         \
                                                                        \
             memset( transform_fft_input_ref,0,                         \
                     fftlen*sizeof(input_type));                        \
                                                                        \
                                                                        \
                                                                        \
            ref_dct4_##suffix(                                          \
                &dct4_inst_ref,                                         \
                (void *) transform_fft_input_ref,                       \
                (void *) transform_fft_inplace_input_ref);              \
                                                                        \
                                                                        \
            DCT_TRANSFORM_SNR_COMPARE_INTERFACE(                        \
                fftlen,                                                 \
                input_type));                                           \
                                                                        \
        return JTEST_TEST_PASSED;                                       \
    }

  
                                                                          
                                                                             
         
  
#define DCT4_FIXED_POINT_DEFINE_TEST(suffix, input_type, prefix)           \
    JTEST_DEFINE_TEST(arm_dct4_##suffix##_test, arm_dct4_##suffix)         \
    {                                                                      \
        CONCAT(arm_dct4_instance_,suffix) dct4_inst_fut        = {0};      \
        CONCAT(arm_rfft_instance_,suffix) rfft_inst_fut        = {0};      \
        CONCAT(arm_cfft_radix4_instance_,suffix) cfft_inst_fut = {0};      \
                                                                           \
        CONCAT(arm_dct4_instance_,suffix) dct4_inst_ref        = {0};      \
        CONCAT(arm_rfft_instance_,suffix) rfft_inst_ref        = {0};      \
        CONCAT(arm_cfft_radix4_instance_,suffix) cfft_inst_ref = {0};      \
                                                                           \
        TEMPLATE_DO_ARR_DESC(                                              \
            fftlen_idx, uint16_t, fftlen, transform_dct_fftlens            \
            ,                                                              \
            uint32_t i;                                                    \
            float32_t normalize_f32 =                                      \
                  ref_sqrt_f32((2.0f/(float32_t)fftlen));                  \
            input_type normalize;                                          \
                                                                           \
                                                                           \
            TEST_CONVERT_FLOAT_TO(&normalize_f32, &normalize,              \
                                  1, input_type);                          \
                                                                           \
                                                                           \
            arm_dct4_init_##suffix(                                        \
                &dct4_inst_fut, &rfft_inst_fut, &cfft_inst_fut,            \
                fftlen,                                                    \
                fftlen/2,                                                  \
                normalize);                                                \
                                                                           \
            arm_dct4_init_##suffix(                                        \
                &dct4_inst_ref, &rfft_inst_ref, &cfft_inst_ref,            \
                fftlen,                                                    \
                fftlen/2,                                                  \
                normalize);                                                \
                                                                           \
                                                                            
                                                                            
                                                                            
                                                                            
                                                                           \
             for(i=0; i < fftlen; i++)                                     \
             {                                                             \
               ((input_type*)transform_fft_inplace_input_fut)[i] =         \
                        prefix##transform_fft_##suffix##_inputs[i] >> 1;   \
               ((input_type*)transform_fft_inplace_input_ref)[i] =         \
                        prefix##transform_fft_##suffix##_inputs[i] >> 1;   \
             }                                                             \
                                                                           \
             memset( transform_fft_input_fut,0,                            \
                     fftlen*sizeof(input_type));                           \
                                                                           \
                                                                           \
            JTEST_DUMP_STRF("Block Size: %d\n",                            \
                         (int)fftlen);                                     \
                                                                           \
                                                                            
                                                                           \
            JTEST_COUNT_CYCLES(                                            \
                arm_dct4_##suffix(                                         \
                    &dct4_inst_fut,                                        \
                    (void *) transform_fft_input_fut,                      \
                    (void *) transform_fft_inplace_input_fut));            \
                                                                           \
             memset( transform_fft_input_ref,0,                            \
                     fftlen*sizeof(input_type));                           \
                                                                           \
                                                                           \
                                                                           \
            ref_dct4_##suffix(                                             \
                &dct4_inst_ref,                                            \
                (void *) transform_fft_input_ref,                          \
                (void *) transform_fft_inplace_input_ref);                 \
                                                                           \
                                                                           \
            DCT_TRANSFORM_SNR_COMPARE_INTERFACE(                           \
                fftlen,                                                    \
                input_type));                                              \
                                                                           \
        return JTEST_TEST_PASSED;                                          \
    }

DCT4_DEFINE_TEST(f32, float32_t);
DCT4_FIXED_POINT_DEFINE_TEST(q31, q31_t,);
DCT4_FIXED_POINT_DEFINE_TEST(q15, q15_t, dct4_);

                                                                                    
                                  
                                                                                    

JTEST_DEFINE_GROUP(dct4_tests)
{
    JTEST_TEST_CALL(arm_dct4_f32_test);
    JTEST_TEST_CALL(arm_dct4_q31_test);
    JTEST_TEST_CALL(arm_dct4_q15_test);
}

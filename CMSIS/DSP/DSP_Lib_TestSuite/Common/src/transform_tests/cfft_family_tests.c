#include "jtest.h"
#include "ref.h"
#include "arr_desc.h"
#include "transform_templates.h"
#include "transform_test_data.h"
#include "type_abbrev.h"

                                                                                    
                        
                                                                                    

#define CFFT_FN_NAME(fn_specifier, type_suffix) \
    arm_cfft_##fn_specifier##_##type_suffix     \

#define CFFT_TEST_NAME(fn_specifier, type_suffix, config_suffix)        \
    arm_cfft_##fn_specifier##_##type_suffix##_##config_suffix##_test    \

                                                                                    
                      
                                                                                    

                                                                              
                
#define arm_cfft_mag_init_f32 arm_cfft_radix4_init_f32
#define arm_cfft_mag_init_q31 arm_cfft_radix4_init_q31
#define arm_cfft_mag_init_q15 arm_cfft_radix4_init_q15
#define arm_cfft_mag_instance_f32 arm_cfft_radix4_instance_f32
#define arm_cfft_mag_instance_q31 arm_cfft_radix4_instance_q31
#define arm_cfft_mag_instance_q15 arm_cfft_radix4_instance_q15
#define transform_mag_fftlens transform_radix4_fftlens

                                                                                    
                     
                                                                                    

   
                                                     
  
                                           
  
                         
                         
                      
  
                                      
  
                                                            
                                                      
  
                                                                             
                                                       

                                                                            
            
  
                                                                  
                                    
  
                                                                               
                       
   
#define CFFT_FAMILY_DEFINE_TEST(fn_specifier,                               \
                                type_suffix,                                \
                                config_suffix,                                     \
                                comparison_interface,                       \
                                output_type,                                \
                                ifft_flag)                                  \
    JTEST_DEFINE_TEST(CFFT_TEST_NAME(fn_specifier, type_suffix,             \
                                     config_suffix),                        \
                      CFFT_FN_NAME(fn_specifier, type_suffix))              \
    {                                                                       \
        arm_cfft_##fn_specifier##_instance_##type_suffix cfft_inst_fut;     \
        arm_cfft_##fn_specifier##_instance_##type_suffix cfft_inst_ref;     \
                                                                            \
        TEMPLATE_DO_ARR_DESC(                                               \
            fftlen_idx, uint16_t, fftlen, transform_##fn_specifier##_fftlens \
            ,                                                               \
                                                                            \
                                                                            \
            arm_cfft_##fn_specifier##_init_##type_suffix(                   \
                &cfft_inst_fut, fftlen, ifft_flag, (uint8_t)1);             \
            arm_cfft_##fn_specifier##_init_##type_suffix(                   \
                &cfft_inst_ref, fftlen, ifft_flag, (uint8_t)1);             \
                                                                            \
            TRANSFORM_PREPARE_INPLACE_INPUTS(                               \
                transform_fft_##type_suffix##_inputs,                       \
                fftlen *                                                    \
                sizeof(TYPE_FROM_ABBREV(type_suffix)) *                     \
                2                   );                                      \
                                                                            \
                                                                            \
            JTEST_DUMP_STRF("Block Size: %d\n"                              \
                            "Inverse-transform flag: %d\n",                 \
                            (int)fftlen,                                    \
                            (int)ifft_flag);                                \
                                                                            \
                                                                            \
            JTEST_COUNT_CYCLES(                                             \
                arm_cfft_##fn_specifier##_##type_suffix(                    \
                    &cfft_inst_fut,                                         \
                    (void*) transform_fft_inplace_input_fut));              \
                                                                            \
            ref_cfft_##fn_specifier##_##type_suffix(                        \
                &cfft_inst_ref,                                             \
                (void *) transform_fft_inplace_input_ref);                  \
                                                                            \
                                                                            \
            comparison_interface(                                           \
                fftlen,                                                     \
                output_type));                                              \
                                                                            \
        return JTEST_TEST_PASSED;                                           \
    }

   
                                                                             
  
                                                                              
                           
   
#define CFFT_FAMILY_DEFINE_ALL_TESTS(config_suffix, ifft_flag)      \
                                                                    \
    CFFT_FAMILY_DEFINE_TEST(radix2, q31, config_suffix,             \
                            TRANSFORM_SNR_COMPARE_CMPLX_INTERFACE,  \
                            TYPE_FROM_ABBREV(q31),                  \
                            ifft_flag);                             \
    CFFT_FAMILY_DEFINE_TEST(radix2, q15, config_suffix,             \
                            TRANSFORM_SNR_COMPARE_CMPLX_INTERFACE,  \
                            TYPE_FROM_ABBREV(q15),                  \
                            ifft_flag);                             \
                                                                    \
    CFFT_FAMILY_DEFINE_TEST(radix4, q31, config_suffix,             \
                            TRANSFORM_SNR_COMPARE_CMPLX_INTERFACE,  \
                            TYPE_FROM_ABBREV(q31),                  \
                            ifft_flag);                             \
    CFFT_FAMILY_DEFINE_TEST(radix4, q15, config_suffix,             \
                            TRANSFORM_SNR_COMPARE_CMPLX_INTERFACE,  \
                            TYPE_FROM_ABBREV(q15),                  \
                            ifft_flag)
                                                                             
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                            

CFFT_FAMILY_DEFINE_ALL_TESTS(forward, 0U);
CFFT_FAMILY_DEFINE_ALL_TESTS(inverse, 1U);

                                                                                    
                                  
                                                                                    

JTEST_DEFINE_GROUP(cfft_family_tests)
{
                           
    JTEST_TEST_CALL(arm_cfft_radix2_q31_forward_test);
    JTEST_TEST_CALL(arm_cfft_radix2_q15_forward_test);
    JTEST_TEST_CALL(arm_cfft_radix4_q31_forward_test);
    JTEST_TEST_CALL(arm_cfft_radix4_q15_forward_test);

                           
    JTEST_TEST_CALL(arm_cfft_radix2_q31_inverse_test);
    JTEST_TEST_CALL(arm_cfft_radix2_q15_inverse_test);
    JTEST_TEST_CALL(arm_cfft_radix4_q31_inverse_test);
    JTEST_TEST_CALL(arm_cfft_radix4_q15_inverse_test);

                                                                              
                            
                                                         
                                                         
                                                         
                                                         
                                                         
                                                         
}

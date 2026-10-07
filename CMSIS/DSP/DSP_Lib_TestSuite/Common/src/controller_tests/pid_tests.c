#include "jtest.h"
#include "arr_desc.h"
#include "arm_math.h"
#include "ref.h"
#include "type_abbrev.h"
#include "test_templates.h"
#include "controller_test_data.h"
#include "controller_templates.h"

   
                                                                      
           
   
#define ARM_PID_TEST(suffix,type)                                       \
    JTEST_DEFINE_TEST(arm_pid_##suffix##_test, arm_pid_##suffix)        \
    {                                                                   \
            uint32_t i,j;                                               \
                                                                        \
            arm_pid_instance_##suffix fut_pid_inst = { 0 };             \
            arm_pid_instance_##suffix ref_pid_inst = { 0 };             \
                                                                        \
            for(i=0;i<CONTROLLER_MAX_COEFFS_LEN/3;i++)                  \
            {                                                           \
                fut_pid_inst.Kp = controller_##suffix##_coeffs[i*3+0];  \
                fut_pid_inst.Ki = controller_##suffix##_coeffs[i*3+1];  \
                fut_pid_inst.Kd = controller_##suffix##_coeffs[i*3+2];  \
                ref_pid_inst.Kp = controller_##suffix##_coeffs[i*3+0];  \
                ref_pid_inst.Ki = controller_##suffix##_coeffs[i*3+1];  \
                ref_pid_inst.Kd = controller_##suffix##_coeffs[i*3+2];  \
                                                                        \
                arm_pid_init_##suffix(&fut_pid_inst, 1);                \
                arm_pid_init_##suffix(&ref_pid_inst, 1);                \
                                                                        \
                                                                        \
                JTEST_DUMP_STRF("Block Size: %d\n",                     \
                                (int)CONTROLLER_MAX_LEN);               \
                                                                        \
                                                                        \
                JTEST_COUNT_CYCLES(                                     \
                    for(j=0;j<CONTROLLER_MAX_LEN;j++)                   \
                    {                                                   \
                       *((type*)controller_output_fut + j) =            \
                           arm_pid_##suffix(&fut_pid_inst,              \
                           controller_##suffix##_inputs[j]);            \
                    });                                                 \
                                                                        \
                for(j=0;j<CONTROLLER_MAX_LEN;j++)                       \
                {                                                       \
                   *((type*)controller_output_ref + j) =                \
                        ref_pid_##suffix(&ref_pid_inst,                 \
                        controller_##suffix##_inputs[j]);               \
                }                                                       \
                                                                        \
                                                                        \
                CONTROLLER_SNR_COMPARE_INTERFACE(                       \
                        CONTROLLER_MAX_LEN,                             \
                        type);                                          \
            }                                                           \
                                                                        \
            return JTEST_TEST_PASSED;                                   \
    }

ARM_PID_TEST(f32,float32_t);
ARM_PID_TEST(q31,q31_t);
ARM_PID_TEST(q15,q15_t);

                                                                                    
                                  
                                                                                    

JTEST_DEFINE_GROUP(pid_tests)
{
      
                                     
      
    JTEST_TEST_CALL(arm_pid_f32_test);
    JTEST_TEST_CALL(arm_pid_q31_test);
    JTEST_TEST_CALL(arm_pid_q15_test);
}

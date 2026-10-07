#include "jtest.h"
#include "statistics_test_data.h"
#include "arr_desc.h"
#include "arm_math.h"                     
#include "ref.h"                                         
#include "test_templates.h"
#include "statistics_templates.h"
#include "type_abbrev.h"

#define JTEST_ARM_POWER_TEST(suffix, output_type)   \
    STATISTICS_DEFINE_TEST_TEMPLATE_BUF1_BLK(       \
        power,                                      \
        suffix,                                     \
        TYPE_FROM_ABBREV(suffix),                   \
        TYPE_FROM_ABBREV(suffix),                   \
        STATISTICS_SNR_COMPARE_INTERFACE)

JTEST_ARM_POWER_TEST(f32, float32_t);
JTEST_ARM_POWER_TEST(q31, q63_t);
JTEST_ARM_POWER_TEST(q15, q63_t);
JTEST_ARM_POWER_TEST(q7,  q31_t);

                                                                                    
                                   
                                                                                    

JTEST_DEFINE_GROUP(power_tests)
{
      
                                     
      
    JTEST_TEST_CALL(arm_power_f32_test);
    JTEST_TEST_CALL(arm_power_q31_test);
    JTEST_TEST_CALL(arm_power_q15_test);
    JTEST_TEST_CALL(arm_power_q7_test);
}

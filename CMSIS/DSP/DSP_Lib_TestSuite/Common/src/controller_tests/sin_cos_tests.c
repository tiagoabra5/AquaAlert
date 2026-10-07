#include "jtest.h"
#include "arr_desc.h"
#include "arm_math.h"
#include "ref.h"
#include "type_abbrev.h"
#include "test_templates.h"

                                                                                    
                
                                                                                    

ARR_DESC_DEFINE(float32_t,
                arm_sin_cos_degrees_f32,
                9,
                CURLY(
                    0,
                    17,
                    45,
                    90,
                    180,
                    360,
                    362,
                    -73,
                    -191.111
                      ));

                                                                            
                                        
ARR_DESC_DEFINE(q31_t,
                arm_sin_cos_degrees_q31,
                6,
                CURLY(
                    0,
                    0x80000000,         
                    0x7fffffff,              
                                 
                    0xf7badafa,
                    0x285954a1,
                    0xb9d09511
                      ));

                                                                                    
                      
                                                                                    
float32_t sin_val_fut = 0;
float32_t cos_val_fut = 0;
float32_t sin_val_ref = 0;
float32_t cos_val_ref = 0;

                                                                                    
                      
                                                                                    

#define MAX_DELTA_f32 50.0e-8f
#define ABS(x) ((x) > 0 ? (x) : -(x))

  
                                                                                       
  
#define COMPARISON_INTERFACE(type, threshold)                           \
    if ( (ABS((type) sin_val_ref - (type) sin_val_fut) >                 \
         (type) threshold ) ||                                          \
        (ABS((type) cos_val_ref - (type) cos_val_fut) >                 \
         (type) threshold))                                             \
    {                                                                   \
        JTEST_DUMP_STRF("Error: %f %f\n",                               \
                        ABS((type) sin_val_ref - (type) sin_val_fut),   \
                        ABS((type) cos_val_ref - (type) cos_val_fut));  \
        return JTEST_TEST_FAILED;                                       \
    }

  
                                                   
  
JTEST_DEFINE_TEST(arm_sin_cos_f32_test, arm_sin_cos_f32)
{
                                                   
    TEMPLATE_DO_ARR_DESC(
        degree_idx, TYPE_FROM_ABBREV(f32),
        degree, arm_sin_cos_degrees_f32
        ,
                                              
        JTEST_COUNT_CYCLES(
            arm_sin_cos_f32(
                degree,
                (TYPE_FROM_ABBREV(f32) *) &sin_val_fut,
                (TYPE_FROM_ABBREV(f32) *) &cos_val_fut)
        );
        ref_sin_cos_f32(
            degree,
            (TYPE_FROM_ABBREV(f32) *) &sin_val_ref,
            (TYPE_FROM_ABBREV(f32) *) &cos_val_ref);

                              
        COMPARISON_INTERFACE(
            TYPE_FROM_ABBREV(f32),
            MAX_DELTA_f32));

    return JTEST_TEST_PASSED;
}


  
                                               
  
JTEST_DEFINE_TEST(arm_sin_cos_q31_test,
                  arm_sin_cos_q31)
{
                                                   
    TEMPLATE_DO_ARR_DESC(
        degree_idx, TYPE_FROM_ABBREV(q31),
        degree, arm_sin_cos_degrees_q31
        ,
                                              
        JTEST_COUNT_CYCLES(
            arm_sin_cos_q31(
                degree,
                (TYPE_FROM_ABBREV(q31) *) &sin_val_fut,
                (TYPE_FROM_ABBREV(q31) *) &cos_val_fut)
        );
        ref_sin_cos_q31(
            degree,
            (TYPE_FROM_ABBREV(q31) *) &sin_val_ref,
            (TYPE_FROM_ABBREV(q31) *) &cos_val_ref);

                                                                   
        ref_q31_t_to_float((TYPE_FROM_ABBREV(q31) *) &sin_val_fut, &sin_val_fut, 1);
        ref_q31_t_to_float((TYPE_FROM_ABBREV(q31) *) &cos_val_fut, &cos_val_fut, 1);
        ref_q31_t_to_float((TYPE_FROM_ABBREV(q31) *) &sin_val_ref, &sin_val_ref, 1);
        ref_q31_t_to_float((TYPE_FROM_ABBREV(q31) *) &cos_val_ref, &cos_val_ref, 1);

                              
        COMPARISON_INTERFACE(
            TYPE_FROM_ABBREV(f32),
            MAX_DELTA_f32));

    return JTEST_TEST_PASSED;
}

                                                                                    
                                  
                                                                                    

JTEST_DEFINE_GROUP(sin_cos_tests)
{
      
                                     
      
    JTEST_TEST_CALL(arm_sin_cos_f32_test);
    JTEST_TEST_CALL(arm_sin_cos_q31_test);
}

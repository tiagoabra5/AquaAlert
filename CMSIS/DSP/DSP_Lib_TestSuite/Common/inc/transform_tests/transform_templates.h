#ifndef _TRANSFORM_TEMPLATES_H_
#define _TRANSFORM_TEMPLATES_H_

                                                                                    
              
                                                                                    

#include "test_templates.h"
#include <string.h>                           

                                                                                    
                              
                                                                                    

   
                                                                        
   
#define TRANSFORM_SNR_THRESHOLD_float32_t 90
#define TRANSFORM_SNR_THRESHOLD_q31_t     90
#define TRANSFORM_SNR_THRESHOLD_q15_t     30

#define DCT4_TRANSFORM_SNR_THRESHOLD_float32_t 80
#define DCT4_TRANSFORM_SNR_THRESHOLD_q31_t     75
#define DCT4_TRANSFORM_SNR_THRESHOLD_q15_t     11

   
                                                                      
                       
   
#define TRANSFORM_SNR_COMPARE_INTERFACE(block_size,     \
                                        output_type)    \
    do                                                  \
    {                                                   \
        TEST_CONVERT_AND_ASSERT_SNR(                    \
            transform_fft_output_f32_ref,               \
            (output_type *) transform_fft_output_ref,   \
            transform_fft_output_f32_fut,               \
            (output_type *) transform_fft_output_fut,   \
            block_size,                                 \
            output_type,                                \
            TRANSFORM_SNR_THRESHOLD_##output_type       \
            );                                          \
    } while (0)
    
   
                                                                      
                       
   
#define DCT_TRANSFORM_SNR_COMPARE_INTERFACE(block_size,  \
                                            output_type) \
    do                                                   \
    {                                                    \
        TEST_CONVERT_AND_ASSERT_SNR(                     \
            transform_fft_output_f32_ref,                \
            (output_type *) transform_fft_output_ref,    \
            transform_fft_output_f32_fut,                \
            (output_type *) transform_fft_output_fut,    \
            block_size,                                  \
            output_type,                                 \
            DCT4_TRANSFORM_SNR_THRESHOLD_##output_type   \
            );                                           \
    } while (0)                                           \

   
                                                                              
                         
   
#define TRANSFORM_SNR_COMPARE_CMPLX_INTERFACE(block_size, output_type)  \
                                                                        \
    TRANSFORM_SNR_COMPARE_INTERFACE(block_size * 2, output_type )

   
                                                              
  
                                                                               
                                                                             
                     
   
#define TRANSFORM_COPY_INPUTS(input_ptr,        \
                              bytes)            \
    do                                          \
    {                                           \
        memcpy(                                 \
            transform_fft_input_fut,            \
            input_ptr,                          \
            bytes);                             \
        memcpy(                                 \
            transform_fft_input_ref,            \
            input_ptr,                          \
            bytes);                             \
    } while (0)

   
                                                                              
                                         
  
                                                                            
                                            
  
                                                                               
                                                                             
                     
   
#define TRANSFORM_PREPARE_INVERSE_INPUTS(input_ptr,                              \
                              fftlen, input_type, bytes)                         \
    do                                                                           \
    {                                                                            \
        uint32_t i;                                                              \
                                                                                 \
        memcpy(                                                                  \
            transform_fft_input_fut,                                             \
            input_ptr,                                                           \
            bytes);                                                              \
                                                                                 \
        ((input_type*)transform_fft_input_fut)[1] = 0;                           \
        ((input_type*)transform_fft_input_fut)[fftlen + 0] = 0;                  \
        ((input_type*)transform_fft_input_fut)[fftlen + 1] = 0;                  \
        for(i=1;i<fftlen/2;i++)                                                  \
        {                                                                        \
           *((input_type*)transform_fft_input_fut + fftlen + 2*i + 0) =          \
               *((input_type*)transform_fft_input_fut + fftlen - 2*i + 0);       \
           *((input_type*)transform_fft_input_fut + fftlen + 2*i + 1) =          \
               -(*((input_type*)transform_fft_input_fut + fftlen - 2*i + 1));    \
                                                                                 \
        }                                                                        \
                                                                                 \
        memcpy(                                                                  \
            transform_fft_input_ref,                                             \
            transform_fft_input_fut,                                             \
            bytes * 2);                                                          \
    } while (0)

   
                                                                           
  
                                                                               
                                                                             
                     
   
#define TRANSFORM_PREPARE_INPLACE_INPUTS_DOWNSHIFT(input_ptr,       \
                                         bytes,                     \
                                         type)                      \
    do                                                              \
    {                                                               \
        uint32_t i;                                                 \
        memcpy(                                                     \
            transform_fft_inplace_input_fut,                        \
            input_ptr,                                              \
            bytes);                                                 \
        memcpy(                                                     \
            transform_fft_inplace_input_ref,                        \
            input_ptr,                                              \
            bytes);                                                 \
        for(i=0;i<bytes/sizeof(type);i++) {                         \
            *((type*)transform_fft_inplace_input_fut + i) >>= 1;    \
            *((type*)transform_fft_inplace_input_ref + i) >>= 1;}   \
    } while (0)

   
                                                                           
  
                                                                               
                                                                             
                     
   
#define TRANSFORM_PREPARE_INPLACE_INPUTS(input_ptr, \
                                         bytes)     \
    do                                              \
    {                                               \
        memcpy(                                     \
            transform_fft_inplace_input_fut,        \
            input_ptr,                              \
            bytes);                                 \
        memcpy(                                     \
            transform_fft_inplace_input_ref,        \
            input_ptr,                              \
            bytes);                                 \
    } while (0)


#endif                              

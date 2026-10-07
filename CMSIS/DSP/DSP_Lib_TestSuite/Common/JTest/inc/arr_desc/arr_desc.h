#ifndef _ARR_DESC_H_
#define _ARR_DESC_H_

                                                                                    
              
                                                                                    
#include <stdint.h>
#include <string.h>                           
#include "../util/util.h"                     

                                                                                    
                      
                                                                                    

   
                            
   
typedef struct ARR_DESC_struct
{
    void *  data_ptr;                                                    
    int32_t element_count;                                            
    int32_t element_size;                                                    
    int32_t underlying_size;                                                 
} ARR_DESC_t;

                                                                                    
                        
                                                                                    

   
                                                                           
                                
   
#define ARR_DESC_ARR_PREFIX ARR_DESC_ARR_

   
                                                                             
                                
   
#define ARR_DESC_ARR_NAME(name)                 \
    CONCAT(ARR_DESC_ARR_PREFIX, name)

   
                                    
  
                                                                     
                
   
#define ARR_DESC_INTERNAL_DEFINE(name, data_ptr,                \
                                 element_count, element_size)   \
    ARR_DESC_t name = {                                         \
        data_ptr,                                               \
        element_count,                                          \
        element_size,                                           \
        element_count * element_size                            \
    }                                                           \

   
                                                              
  
                                                                             
                                                 
   
#define ARR_DESC_DEFINE(type, name, element_count, content)             \
    type ARR_DESC_ARR_NAME(name)[element_count] = content;              \
    ARR_DESC_INTERNAL_DEFINE(name,                                      \
                             &ARR_DESC_ARR_NAME(name),                  \
                             element_count,                             \
                             sizeof(type))                                 

   
                                                                         
  
                                                                       
                                                                     
   
#define ARR_DESC_DEFINE_SUBSET(name, original, element_cnt)         \
    ARR_DESC_INTERNAL_DEFINE(name,                                  \
                             &ARR_DESC_ARR_NAME(original),          \
                             element_cnt,                           \
                             sizeof(ARR_DESC_ARR_NAME(original)[0]) \
        )                                 

   
                                                                       
  
                                                          
                                                                        
  
            
  
                                                  
  
                                                            
  
                                                                    
                                                                    
  
            
  
                       
                       
  
                                                                              
                        
   
#define ARR_DESC_DEFINE_USING_ARR(type, name, array_ptr, start_idx, element_cnt) \
    ARR_DESC_INTERNAL_DEFINE(                                           \
        name,                                                           \
        (type *) (array_ptr + start_idx),                               \
        element_cnt,                                                    \
        sizeof(type)                                                    \
        )                                

   
                                  
   
#define ARR_DESC_DECLARE(name)                              \
    extern ARR_DESC_t name                                 

   
                                                              
   
#define ARR_DESC_BYTES(arr_desc_ptr)                                \
    ((arr_desc_ptr)->element_count * (arr_desc_ptr)->element_size)

   
                                             
   
#define ARR_DESC_MEMSET(arr_desc_ptr, value, bytes)     \
    do                                                  \
    {                                                   \
        memset((arr_desc_ptr)->data_ptr,                \
               value,                                   \
               BOUND(0,                                 \
                     (arr_desc_ptr)->underlying_size,   \
                     bytes)                             \
            );                                          \
    } while (0)

   
                                                                        
                            
   
#define ARR_DESC_MEMCPY(arr_desc_dest_ptr, arr_desc_src_ptr, bytes) \
    do                                                              \
    {                                                               \
        memcpy((arr_desc_dest_ptr)->data_ptr,                       \
               (arr_desc_src_ptr)->data_ptr,                        \
               BOUND(0,                                             \
                     (arr_desc_dest_ptr)->underlying_size,          \
                     bytes));                                       \
    } while (0)

   
                                                                         
                                                
   
#define ARR_DESC_COPYABLE(arr_desc_dest_ptr, arr_desc_src_ptr)  \
      (ARR_DESC_BYTES(arr_desc_src_ptr) <=                      \
       (arr_desc_dest_ptr)->underlying_size)

   
                                                                    
                
  
                                                                                
                                        
   
#define ARR_DESC_COPY(arr_desc_dest_ptr, arr_desc_src_ptr)      \
    do                                                          \
    {                                                           \
        if (ARR_DESC_COPYABLE(arr_desc_dest_ptr,                 \
                             arr_desc_src_ptr))                 \
        {                                                       \
            ARR_DESC_MEMCPY(arr_desc_dest_ptr,                  \
                            arr_desc_src_ptr,                   \
                            ARR_DESC_BYTES(arr_desc_src_ptr));  \
                                                                \
            (arr_desc_dest_ptr)->element_count =                \
                (arr_desc_src_ptr)->element_count;              \
            (arr_desc_dest_ptr)->element_size =                 \
                (arr_desc_src_ptr)->element_size;               \
        }                                                       \
    } while (0)

   
                                                                           
          
   
#define ARR_DESC_MEMCMP(arr_desc_ptr_a, arr_desc_ptr_b, bytes)  \
        memcmp((arr_desc_ptr_a)->data_ptr,                      \
            (arr_desc_ptr_b)->data_ptr,                         \
               bytes)                                           \

   
                                             
   
#define ARR_DESC_ZERO(arr_desc_ptr)             \
        ARR_DESC_MEMSET(arr_desc_ptr,           \
                        0,                      \
                        (arr_desc_ptr)->underlying_size)

   
                                                          
   
#define ARR_DESC_DATA_ADDR(type, arr_desc_ptr, offset)  \
        ((void*)(((type *)                              \
                  ((arr_desc_ptr)->data_ptr))           \
                 + offset))

   
                                                            
   
#define ARR_DESC_ELT(type, idx, arr_desc_ptr)           \
        (*((type *) ARR_DESC_DATA_ADDR(type,            \
                                       arr_desc_ptr,    \
                                       idx)))

#endif                   

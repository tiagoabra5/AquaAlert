#ifndef _TEMPLATE_H_
#define _TEMPLATE_H_

                                                                                    
                           
                                                                                    

   
                                                 
   
#define TEMPLATE_LOOP(setup, loop_def, body)    \
    do                                          \
    {                                           \
        setup;                                  \
        loop_def {                              \
            body;                               \
        }                                       \
    } while (0)

   
                                                     
   
#define TEMPLATE_DO_ARR_LIKE(iter_idx, type,                            \
                             arr, arr_length,                           \
                             iter_elem_setup,                           \
                             body)                                      \
    do                                                                  \
    {                                                                   \
        TEMPLATE_LOOP(                                                  \
            int iter_idx,                                               \
            for(iter_idx = 0; iter_idx < (arr_length); ++iter_idx),     \
            iter_elem_setup;                                            \
            body);                                                      \
    } while (0)

   
                                                       
   
#define TEMPLATE_DO_ARR(iter_idx, type, iter_elem, arr, arr_length, body) \
    do                                                                  \
    {                                                                   \
        TEMPLATE_DO_ARR_LIKE(                                           \
            iter_idx, type, arr, arr_length,                            \
            type iter_elem = (arr)[iter_idx],                           \
            body);                                                      \
    } while (0)

   
                                                           
   
#define TEMPLATE_DO_ARR_DESC(iter_idx, type, iter_elem, arr_desc, body) \
    do                                                                  \
    {                                                                   \
        TEMPLATE_DO_ARR_LIKE(                                           \
            iter_idx, type, arr_desc, (arr_desc).element_count,         \
            type iter_elem = ARR_DESC_ELT(type, iter_idx, &(arr_desc)), \
            body);                                                      \
    } while (0)

                                                                                    
                     
                                                                                    

   
                                                 
   
#define TEMPLATE_TEST(setup, body, teardown)    \
        do                                      \
        {                                       \
            setup;                              \
            body;                               \
            teardown;                           \
        } while (0)

   
                                    
  
                                                              
  
            
                                     
  
                                           
   
#define TEMPLATE_CALL_FN(fn, fn_args)           \
        fn fn_args

#endif                   

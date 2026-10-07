#ifndef _JTEST_PF_H_
#define _JTEST_PF_H_

                                                                                    
             
                                                                                    
                                                                     


                                                                                    
                        
                                                                                    

   
                                                                               
                               
   
#define JTEST_PF_MEMBERS                            \
    uint32_t passed;                                \
    uint32_t failed                                 \

   
                                                                   
   
#define JTEST_PF_MEMBER_INIT                    \
    0,                                          \
    0

                                
                                                                                    

   
                                                      
  
                                         
   
#define JTEST_PF_INC_XXX(xxx, struct_pf_ptr, amount)    \
    do                                                  \
    {                                                   \
        ((struct_pf_ptr)->xxx) += (amount);             \
    } while (0)

   
                                                                         
           
   
#define JTEST_PF_INC_PASSED(struct_pf_ptr, amount)  \
    JTEST_PF_INC_XXX(passed, struct_pf_ptr, amount)


   
                                                                         
           
   
#define JTEST_PF_INC_FAILED(struct_pf_ptr, amount)  \
    JTEST_PF_INC_XXX(failed, struct_pf_ptr, amount)


                             
                                                                                    

   
                                                         
  
                                         
   
#define JTEST_PF_RESET_XXX(xxx, struct_pf_ptr)  \
    do                                          \
    {                                           \
        ((struct_pf_ptr)->xxx) = UINT32_C(0);   \
    } while (0)

   
                                                                  
   
#define JTEST_PF_RESET_PASSED(struct_pf_ptr)    \
    JTEST_PF_RESET_XXX(passed, struct_pf_ptr)

   
                                                                  
   
#define JTEST_PF_RESET_FAILED(struct_pf_ptr)    \
    JTEST_PF_RESET_XXX(failed, struct_pf_ptr)

#endif                   

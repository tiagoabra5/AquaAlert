#ifndef _JTEST_DEFINE_H_
#define _JTEST_DEFINE_H_

                                                                                    
                        
                                                                                    

   
                                                                                
                                                                               
                                                                       
   
#define JTEST_STRUCT_NAME(prefix, specifier)    \
    CONCAT(prefix, specifier)

   
                                                                            
   
#define JTEST_DEFINE_STRUCT(type, struct_name)    \
    type struct_name

   
                                                                             
   
#define JTEST_DECLARE_STRUCT(struct_definition) \
    extern struct_definition

   
                                                                           
                                   
   
#define JTEST_INIT_STRUCT(struct_definition, init_values)       \
    struct_definition = {                                       \
        init_values                                             \
    }

#endif                       

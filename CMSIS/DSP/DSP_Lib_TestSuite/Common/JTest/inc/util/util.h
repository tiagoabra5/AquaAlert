#ifndef _UTIL_H_
#define _UTIL_H_

                                                                                    
                        
                                                                                    

   
                                                     
   
#define STR_NL(x)  STR1_NL(x)
#define STR1_NL(x) (STR2_NL(x)"\n")
#define STR2_NL(x) #x

   
                                 
   
#define STR(x)  STR1(x)
#define STR1(x) STR2(x)
#define STR2(x) #x

   
                            
   
#define CONCAT(a, b)  CONCAT1(a, b)
#define CONCAT1(a, b) CONCAT2(a, b)
#define CONCAT2(a, b) a##b


   
                                                                   
   
#define CURLY(...) {__VA_ARGS__}

   
                                                                  
   
#define PAREN(...) (__VA_ARGS__)

                              
#define MIN(x,y) (((x) < (y)) ? (x) : (y) )
#define MAX(x,y) (((x) > (y)) ? (x) : (y) )

   
                                          
  
                                                          
   
#define BOUND(low, high, value)                 \
    MAX(MIN(high, value), low)

#endif               

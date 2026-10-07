#ifndef _JTEST_FW_H_
#define _JTEST_FW_H_

                                                                                    
              
                                                                                    

#include <stdint.h>                          
#include <string.h>                           
#include <stdio.h>                             
#include "jtest_pf.h"                                                      
#include "jtest_group.h"

                                                                                    
                      
                                                                                    

   
                                                      
   
typedef struct JTEST_FW_struct
{
                                                                                
                                                                       
    volatile int32_t test_start;
    volatile int32_t test_end;
    volatile int32_t group_start;
    volatile int32_t group_end;
    volatile int32_t dump_str;
    volatile int32_t dump_data;
    volatile int32_t exit_fw;

    JTEST_GROUP_t * current_group_ptr;

                                                                       
                                                                              
                                                                            
                                       
    char * str_buffer;
    char * data_buffer;

                        
    JTEST_PF_MEMBERS;

} JTEST_FW_t;

                                                                                    
                        
                                                                                    

   
                                         
  
                                                                               
                     
   
#ifndef JTEST_FW
#define JTEST_FW JTEST_FW
#endif

   
                                             
  
                                                                               
                     
   
#ifndef JTEST_FW_STR_BUFFER
#define JTEST_FW_STR_BUFFER JTEST_FW_STR_BUFFER
#endif

   
                                                  
  
                                                                            
                                                                               
                                                  
   
#define JTEST_BUF_SIZE 256


   
                                                                        
   
#define JTEST_STR_MAX_OUTPUT_SIZE 128

   
                                                                             
                               
   
#define JTEST_STR_MAX_OUTPUT_SEGMENTS           \
    (JTEST_BUF_SIZE / JTEST_STR_MAX_OUTPUT_SIZE)

   
                                   
   
#define JTEST_INIT()                                                    \
    do                                                                  \
    {                                                                   \
        JTEST_FW.str_buffer = JTEST_FW_STR_BUFFER;                      \
    } while (0)

                                       
                                                                                    

   
                                                                   
   
#define JTEST_TRIGGER_ACTION(action_name)       \
    do                                          \
    {                                           \
        action_name();                          \
    } while (0)

   
                                                         
   
#define JTEST_ACT_TEST_START()                  \
    JTEST_TRIGGER_ACTION(test_start)

   
                                                       
   
#define JTEST_ACT_TEST_END()                    \
    JTEST_TRIGGER_ACTION(test_end)


   
                                                          
   
#define JTEST_ACT_GROUP_START()                 \
    JTEST_TRIGGER_ACTION(group_start)

   
                                                        
   
#define JTEST_ACT_GROUP_END()                   \
    JTEST_TRIGGER_ACTION(group_end)


   
                                                                              
                 
   
#if defined(ARMv7A) || defined(FILEIO)

#define JTEST_ACT_DUMP(action, buf_name, value) \
    do                                          \
    {                                           \
        JTEST_CLEAR_BUFFER(buf_name);           \
	    printf("%s",value);                     \
        strcpy(JTEST_FW.buf_name, (value));     \
        JTEST_TRIGGER_ACTION(action);           \
    } while (0)

#else

#define JTEST_ACT_DUMP(action, buf_name, value) \
    do                                          \
    {                                           \
        JTEST_CLEAR_BUFFER(buf_name);           \
        strcpy(JTEST_FW.buf_name, (value));     \
        JTEST_TRIGGER_ACTION(action);           \
    } while (0)

#endif
   
                                                             
   
#define JTEST_ACT_EXIT_FW()                     \
    do                                          \
    {                                           \
        JTEST_TRIGGER_ACTION(exit_fw);          \
    } while (0)


                                
                                                                                    

   
                                                 
   
#define JTEST_CLEAR_BUFFER(buf_name)                    \
    do                                                  \
    {                                                   \
        memset(JTEST_FW.buf_name, 0, JTEST_BUF_SIZE);   \
    } while (0)

   
                                                             
   
#define JTEST_CLEAR_STR_BUFFER()                \
        JTEST_CLEAR_BUFFER(str_buffer)

   
                                                           
   
#define JTEST_CLEAR_DATA_BUFFER()               \
        JTEST_CLEAR_BUFFER(data_buffer)

   
                                               
   
#define JTEST_DUMP_STR(string)                          \
        JTEST_ACT_DUMP(dump_str, str_buffer, string)

   
                                                 
   
#if defined(ARMv7A) || defined(FILEIO)

#define JTEST_DUMP_STRF(format_str, ... )                               \
    do                                                                  \
    {                                                                   \
        JTEST_CLEAR_STR_BUFFER();                                       \
        sprintf(JTEST_FW.str_buffer,format_str, __VA_ARGS__);           \
        printf("%s",JTEST_FW.str_buffer);                               \
        jtest_dump_str_segments();                                      \
    } while (0)

#else

#define JTEST_DUMP_STRF(format_str, ... )                               \
    do                                                                  \
    {                                                                   \
        JTEST_CLEAR_STR_BUFFER();                                       \
        sprintf(JTEST_FW.str_buffer,format_str, __VA_ARGS__);           \
        jtest_dump_str_segments();                                      \
    } while (0)

#endif

                      
                                                                                    

   
                                                      
   
#define JTEST_FW_INC_PASSED(amount)             \
        JTEST_PF_INC_PASSED(&JTEST_FW, amount)

   
                                                      
   
#define JTEST_FW_INC_FAILED(amount)             \
        JTEST_PF_INC_FAILED(&JTEST_FW, amount)

                                    
                                                                                    

   
                                                   
   
#define JTEST_CURRENT_GROUP_PTR()               \
    (JTEST_FW.current_group_ptr)

#define JTEST_SET_CURRENT_GROUP(group_ptr)      \
    do                                          \
    {                                           \
        JTEST_CURRENT_GROUP_PTR() = group_ptr;  \
    } while (0)

                                                                                    
                              
                                                                                    
extern char JTEST_FW_STR_BUFFER[JTEST_BUF_SIZE];
extern volatile JTEST_FW_t JTEST_FW;

                                                                                    
                         
                                                                                    
void jtest_dump_str_segments(void);

void test_start  (void);
void test_end    (void);
void group_start (void);
void group_end   (void);
void dump_str    (void);
void dump_data   (void);
void exit_fw     (void);


#endif                   

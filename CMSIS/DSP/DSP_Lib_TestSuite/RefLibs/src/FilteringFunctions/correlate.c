#include "ref.h"

void ref_correlate_f32(
  float32_t * pSrcA,
  uint32_t srcALen,
  float32_t * pSrcB,
  uint32_t srcBLen,
  float32_t * pDst)
{
  float32_t *pIn1 = pSrcA;                                              
  float32_t *pIn2 = pSrcB + (srcBLen - 1U);                             
  float32_t sum;                                                      
  uint32_t i = 0U, j;                                                  
  uint32_t inv = 0U;                                                      
  uint32_t tot = 0U;                                                

                                                                         
                                               
                                                                    
                                             
                                                                                                 
                                     
                                                                              
                                                                                 
                                                                   
                                                                                
                                   
                                                                               
                                 
                                                                               
                                                                 
    

                                                      
  tot = srcALen + srcBLen - 2U;

  if (srcALen > srcBLen)
  {
                                                                    
                                                   
    pDst += srcALen - srcBLen;
  }
  else if (srcALen < srcBLen)
  {
                                          
    pIn1 = pSrcB;

                                                     
    pIn2 = pSrcA + srcALen - 1U;

                                                          
    pDst += tot;

                              
    j = srcALen;
    srcALen = srcBLen;
    srcBLen = j;

                                  
    inv = 1;
  }

                                                                       
  for (i = 0U; i <= tot; i++)
  {
                                                             
    sum = 0.0f;

                                                                          
    for (j = 0U; j <= i; j++)
    {
                                       
      if ((i - j < srcBLen) && (j < srcALen))
      {
                                   
        sum += pIn1[j] * pIn2[-((int32_t)i - j)];
      }
    }
                                                    
    if (inv == 1)
      *pDst-- = sum;
    else
      *pDst++ = sum;
  }
}

void ref_correlate_q31(
  q31_t * pSrcA,
  uint32_t srcALen,
  q31_t * pSrcB,
  uint32_t srcBLen,
  q31_t * pDst)
{
  q31_t *pIn1 = pSrcA;                                                             
  q31_t *pIn2 = pSrcB + (srcBLen - 1U);                                            
  q63_t sum;                                                                        
  uint32_t i = 0U, j;                                               
  uint32_t inv = 0U;                                                     
  uint32_t tot = 0U;                                         

                                                      
  tot = ((srcALen + srcBLen) - 2U);

  if (srcALen > srcBLen)
  {
                                                                    
    j = srcALen - srcBLen;

                                                   
    pDst += j;
  }

  else if (srcALen < srcBLen)
  {
                                          
    pIn1 = pSrcB;

                                                     
    pIn2 = pSrcA + (srcALen - 1U);

                                                          
    pDst = pDst + tot;

                              
    j = srcALen;
    srcALen = srcBLen;
    srcBLen = j;

                                  
    inv = 1;

  }

                                                                       
  for (i = 0U; i <= tot; i++)
  {
                                                             
    sum = 0;

                                                                          
    for (j = 0U; j <= i; j++)
    {
                                       
      if ((((i - j) < srcBLen) && (j < srcALen)))
      {
                                   
        sum += ((q63_t) pIn1[j] * pIn2[-((int32_t) i - j)]);
      }
    }
                                                    
    if (inv == 1)
      *pDst-- = (q31_t)(sum >> 31U);
    else
      *pDst++ = (q31_t)(sum >> 31U);
  }
}

void ref_correlate_fast_q31(
  q31_t * pSrcA,
  uint32_t srcALen,
  q31_t * pSrcB,
  uint32_t srcBLen,
  q31_t * pDst)
{
  q31_t *pIn1 = pSrcA;                                                             
  q31_t *pIn2 = pSrcB + (srcBLen - 1U);                                            
  q63_t sum;                                                                        
  uint32_t i = 0U, j;                                               
  uint32_t inv = 0U;                                                     
  uint32_t tot = 0U;                                         

                                                      
  tot = ((srcALen + srcBLen) - 2U);

  if (srcALen > srcBLen)
  {
                                                                    
    j = srcALen - srcBLen;

                                                   
    pDst += j;
  }

  else if (srcALen < srcBLen)
  {
                                          
    pIn1 = pSrcB;

                                                     
    pIn2 = pSrcA + (srcALen - 1U);

                                                          
    pDst = pDst + tot;

                              
    j = srcALen;
    srcALen = srcBLen;
    srcBLen = j;

                                  
    inv = 1;

  }

                                                                       
  for (i = 0U; i <= tot; i++)
  {
                                                             
    sum = 0;

                                                                          
    for (j = 0U; j <= i; j++)
    {
                                       
      if ((((i - j) < srcBLen) && (j < srcALen)))
      {
                                   
        sum = (q31_t) ((((q63_t) sum << 32) +
												((q63_t) pIn1[j] * pIn2[-((int32_t) i - j)])) >> 32);
      }
    }
                                                    
    if (inv == 1)
      *pDst-- = (q31_t)(sum << 1U);
    else
      *pDst++ = (q31_t)(sum << 1U);
  }          
}

void ref_correlate_q15(
  q15_t * pSrcA,
  uint32_t srcALen,
  q15_t * pSrcB,
  uint32_t srcBLen,
  q15_t * pDst)
{
  q15_t *pIn1 = pSrcA;                                                             
  q15_t *pIn2 = pSrcB + (srcBLen - 1U);                                            
  q63_t sum;                                                                        
  uint32_t i = 0U, j;                                               
  uint32_t inv = 0U;                                                     
  uint32_t tot = 0U;                                         

                                                      
  tot = ((srcALen + srcBLen) - 2U);

  if (srcALen > srcBLen)
  {
                                                                    
    j = srcALen - srcBLen;

                                                   
    pDst += j;
  }

  else if (srcALen < srcBLen)
  {
                                          
    pIn1 = pSrcB;

                                                     
    pIn2 = pSrcA + (srcALen - 1U);

                                                          
    pDst = pDst + tot;

                              
    j = srcALen;
    srcALen = srcBLen;
    srcBLen = j;

                                  
    inv = 1;

  }

                                                                       
  for (i = 0U; i <= tot; i++)
  {
                                                             
    sum = 0;

                                                                          
    for (j = 0U; j <= i; j++)
    {
                                       
      if ((((i - j) < srcBLen) && (j < srcALen)))
      {
                                   
        sum += ((q31_t) pIn1[j] * pIn2[-((int32_t) i - j)]);
      }
    }
                                                    
    if (inv == 1)
      *pDst-- = (q15_t) ref_sat_q15(sum >> 15U);
    else
      *pDst++ = (q15_t) ref_sat_q15(sum >> 15U);
  }
}

void ref_correlate_fast_q15(
  q15_t * pSrcA,
  uint32_t srcALen,
  q15_t * pSrcB,
  uint32_t srcBLen,
  q15_t * pDst)
{
  q15_t *pIn1 = pSrcA;                                                             
  q15_t *pIn2 = pSrcB + (srcBLen - 1U);                                            
  q63_t sum;                                                                        
  uint32_t i = 0U, j;                                               
  uint32_t inv = 0U;                                                     
  uint32_t tot = 0U;                                         

                                                      
  tot = ((srcALen + srcBLen) - 2U);

  if (srcALen > srcBLen)
  {
                                                                    
    j = srcALen - srcBLen;

                                                   
    pDst += j;
  }

  else if (srcALen < srcBLen)
  {
                                          
    pIn1 = pSrcB;

                                                     
    pIn2 = pSrcA + (srcALen - 1U);

                                                          
    pDst = pDst + tot;

                              
    j = srcALen;
    srcALen = srcBLen;
    srcBLen = j;

                                  
    inv = 1;

  }

                                                                       
  for (i = 0U; i <= tot; i++)
  {
                                                             
    sum = 0;

                                                                          
    for (j = 0U; j <= i; j++)
    {
                                       
      if ((((i - j) < srcBLen) && (j < srcALen)))
      {
                                   
        sum += ((q31_t) pIn1[j] * pIn2[-((int32_t) i - j)]);
      }
    }
                                                    
    if (inv == 1)
      *pDst-- = (q15_t)(sum >> 15U);
    else
      *pDst++ = (q15_t)(sum >> 15U);
  }
}

void ref_correlate_fast_opt_q15(
  q15_t * pSrcA,
  uint32_t srcALen,
  q15_t * pSrcB,
  uint32_t srcBLen,
  q15_t * pDst,
  q15_t * pScratch)
{
  q15_t *pIn1 = pSrcA;                                                             
  q15_t *pIn2 = pSrcB + (srcBLen - 1U);                                            
  q31_t sum;                                                                        
  uint32_t i = 0U, j;                                               
  uint32_t inv = 0U;                                                     
  uint32_t tot = 0U;                                         

                                                      
  tot = ((srcALen + srcBLen) - 2U);

  if (srcALen > srcBLen)
  {
                                                                    
    j = srcALen - srcBLen;

                                                   
    pDst += j;
  }

  else if (srcALen < srcBLen)
  {
                                          
    pIn1 = pSrcB;

                                                     
    pIn2 = pSrcA + (srcALen - 1U);

                                                          
    pDst = pDst + tot;

                              
    j = srcALen;
    srcALen = srcBLen;
    srcBLen = j;

                                  
    inv = 1;

  }

                                                                       
  for (i = 0U; i <= tot; i++)
  {
                                                             
    sum = 0;

                                                                          
    for (j = 0U; j <= i; j++)
    {
                                       
      if ((((i - j) < srcBLen) && (j < srcALen)))
      {
                                   
        sum += ((q31_t) pIn1[j] * pIn2[-((int32_t) i - j)]);
      }
    }
                                                    
    if (inv == 1)
      *pDst-- = (q15_t) ref_sat_q15(sum >> 15U);
    else
      *pDst++ = (q15_t) ref_sat_q15(sum >> 15U);
  }
}

void ref_correlate_q7(
  q7_t * pSrcA,
  uint32_t srcALen,
  q7_t * pSrcB,
  uint32_t srcBLen,
  q7_t * pDst)
{
  q7_t *pIn1 = pSrcA;                                                
  q7_t *pIn2 = pSrcB + (srcBLen - 1U);                               
  q31_t sum;                                                      
  uint32_t i = 0U, j;                                               
  uint32_t inv = 0U;                                                     
  uint32_t tot = 0U;                                         

                                                      
  tot = ((srcALen + srcBLen) - 2U);

  if (srcALen > srcBLen)
  {
                                                                    
    j = srcALen - srcBLen;

                                                   
    pDst += j;
  }

  else if (srcALen < srcBLen)
  {
                                          
    pIn1 = pSrcB;

                                                     
    pIn2 = pSrcA + (srcALen - 1U);

                                                          
    pDst = pDst + tot;

                              
    j = srcALen;
    srcALen = srcBLen;
    srcBLen = j;

                                  
    inv = 1;

  }

                                                                       
  for (i = 0U; i <= tot; i++)
  {
                                                             
    sum = 0;

                                                                          
    for (j = 0U; j <= i; j++)
    {
                                       
      if ((((i - j) < srcBLen) && (j < srcALen)))
      {
                                   
        sum += ((q15_t) pIn1[j] * pIn2[-((int32_t) i - j)]);
      }
    }
                                                    
    if (inv == 1)
      *pDst-- = (q7_t) __SSAT((sum >> 7U), 8U);
    else
      *pDst++ = (q7_t) __SSAT((sum >> 7U), 8U);
  }
}

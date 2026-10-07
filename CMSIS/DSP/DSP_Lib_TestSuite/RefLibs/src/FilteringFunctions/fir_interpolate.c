#include "ref.h"

void ref_fir_interpolate_f32(
  const arm_fir_interpolate_instance_f32 * S,
        float32_t * pSrc,
        float32_t * pDst,
        uint32_t blockSize)
{
        float32_t *pState = S->pState;                                    
  const float32_t *pCoeffs = S->pCoeffs;                                        
        float32_t *pStateCurnt;                                                                       
        float32_t *ptr1;                                                                       
  const float32_t *ptr2;                                                                             
        float32_t sum;                                                  
        uint32_t i, blkCnt;                                               
        uint16_t phaseLen = S->phaseLength, tapCnt;                                                   


                                                                       
                                                                                     
  pStateCurnt = S->pState + phaseLen - 1;

                                      
  blkCnt = blockSize;

                                
  while (blkCnt > 0U)
  {
                                                     
    *pStateCurnt++ = *pSrc++;

                                             
    i = S->L;

    while (i > 0U)
    {
                                   
      sum = 0.0f;

                                    
      ptr1 = pState;

                                          
      ptr2 = pCoeffs + i - 1;

                                          
      tapCnt = phaseLen;

      while (tapCnt > 0U)
      {
                                             
        sum += *ptr1++ * *ptr2;

                                                                              
        ptr2 += S->L;

                                        
        tapCnt--;
      }

                                                                              
      *pDst++ = sum;

                                      
      i--;
    }

                                                
                                                                          
    pState = pState + 1;

                                    
    blkCnt--;
  }

                                     
                                                                                     
                                                                   

                                               
  pStateCurnt = S->pState;

  tapCnt = phaseLen - 1U;

  while (tapCnt > 0U)
  {
    *pStateCurnt++ = *pState++;

                                    
    tapCnt--;
  }

}

void ref_fir_interpolate_q31(
  const arm_fir_interpolate_instance_q31 * S,
        q31_t * pSrc,
        q31_t * pDst,
        uint32_t blockSize)
{
        q31_t *pState = S->pState;                                        
  const q31_t *pCoeffs = S->pCoeffs;                                            
        q31_t *pStateCurnt;                                                                           
        q31_t *ptr1;                                                                           
  const q31_t *ptr2;                                                                                 
        q63_t sum;                                                      
        q31_t x0, c0;                                                                                                
        uint32_t i, blkCnt;                                               
        uint16_t phaseLen = S->phaseLength, tapCnt;                                                   


                                                                       
                                                                                     
  pStateCurnt = S->pState + (q31_t)phaseLen - 1;

                                      
  blkCnt = blockSize;

                                
  while (blkCnt > 0U)
  {
                                                     
    *pStateCurnt++ = *pSrc++;

                                             
    i = S->L;

    while (i > 0U)
    {
                                   
      sum = 0;

                                    
      ptr1 = pState;

                                          
      ptr2 = pCoeffs + i - 1;

      tapCnt = phaseLen;

      while (tapCnt > 0U)
      {
                                  
        c0 = *(ptr2);

                                                                              
        ptr2 += S->L;

                                   
        x0 = *ptr1++;

                                             
        sum += (q63_t) x0 *c0;

                                        
        tapCnt--;
      }

                                                                              
      *pDst++ = (q31_t)(sum >> 31);

                                      
      i--;
    }

                                                
                                                                          
    pState = pState + 1;

                                    
    blkCnt--;
  }

                                     
                                                                                     
                                                                   

                                               
  pStateCurnt = S->pState;

  tapCnt = phaseLen - 1U;

                 
  while (tapCnt > 0U)
  {
    *pStateCurnt++ = *pState++;

                                    
    tapCnt--;
  }

}

void ref_fir_interpolate_q15(
  const arm_fir_interpolate_instance_q15 * S,
        q15_t * pSrc,
        q15_t * pDst,
        uint32_t blockSize)
{
        q15_t *pState = S->pState;                                                                                   
  const q15_t *pCoeffs = S->pCoeffs;                                                                                 
        q15_t *pStateCurnt;                                                                                          
        q15_t *ptr1;                                                                           
  const q15_t *ptr2;                                                                                 
        q63_t sum;                                                      
        q15_t x0, c0;                                                                                                
        uint32_t i, blkCnt, tapCnt;                                                                                  
        uint16_t phaseLen = S->phaseLength;                                                           


                                                                       
                                                                                     
  pStateCurnt = S->pState + phaseLen - 1;

                                      
  blkCnt = blockSize;

                                
  while (blkCnt > 0U)
  {
                                                     
    *pStateCurnt++ = *pSrc++;

                                             
    i = S->L;

    while (i > 0U)
    {
                                   
      sum = 0;

                                    
      ptr1 = pState;

                                          
      ptr2 = pCoeffs + i - 1;

                                          
      tapCnt = (uint32_t)phaseLen;

      while (tapCnt > 0U)
      {
                                  
        c0 = *ptr2;

                                                                              
        ptr2 += S->L;

                                   
        x0 = *ptr1++;

                                             
        sum += (q31_t) x0 * c0;

                                        
        tapCnt--;
      }

                                                                                      
      *pDst++ = ref_sat_q15(sum >> 15);

                                      
      i--;
    }

                                                
                                                                          
    pState = pState + 1;

                                    
    blkCnt--;
  }

                                     
                                                                                     
                                                                   

                                               
  pStateCurnt = S->pState;

  i = (uint32_t) phaseLen - 1U;

  while (i > 0U)
  {
    *pStateCurnt++ = *pState++;

                                    
    i--;
  }

}

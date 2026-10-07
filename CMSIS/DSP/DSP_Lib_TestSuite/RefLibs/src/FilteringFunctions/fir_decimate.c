#include "ref.h"

void ref_fir_decimate_f32(
  const arm_fir_decimate_instance_f32 * S,
  float32_t * pSrc,
  float32_t * pDst,
  uint32_t blockSize)
{
        float32_t *pState = S->pState;                                    
  const float32_t *pCoeffs = S->pCoeffs;                                        
        float32_t *pStateCurnt;                                                                       
        float32_t sum0;                                                 
        float32_t x0, c0;                                                                                            
        uint32_t numTaps = S->numTaps;                                                                  
        uint32_t i, blkCnt;  									 				                    

                                                                      
                                                                                     
  pStateCurnt = S->pState + numTaps - 1U;

                                                     
  blkCnt = blockSize / S->M;

  while (blkCnt > 0U)
  {
                                                                                  
    i = S->M;

    do
    {
      *pStateCurnt++ = *pSrc++;
    } while (--i);

                                 
    sum0 = 0.0f;

		for(i=0;i<numTaps;i++)
		{
                             
      c0 = pCoeffs[i];

                                  
      x0 = pState[i];

                                           
      sum0 += x0 * c0;
		}

                                                                    
                                                                       
    pState += S->M;

                                                                            
    *pDst++ = sum0;

                                    
    blkCnt--;
  }
                                     
                                                                                    
                                                                   

                                               
  pStateCurnt = S->pState;

                                     
  i = numTaps - 1U;

                 
  while (i > 0U)
  {
    *pStateCurnt++ = *pState++;

                                    
    i--;
  }
}

void ref_fir_decimate_q31(
  const arm_fir_decimate_instance_q31 * S,
  q31_t * pSrc,
  q31_t * pDst,
  uint32_t blockSize)
{
        q31_t *pState = S->pState;                                        
  const q31_t *pCoeffs = S->pCoeffs;                                            
        q31_t *pStateCurnt;                                                                           
        q31_t x0, c0;                                                                                                
        q63_t sum0;                                                     
        uint32_t numTaps = S->numTaps;                                     
        uint32_t i, blkCnt;  													                    

                                                                      
                                                                                     
  pStateCurnt = S->pState + numTaps - 1U;

                                                     
  blkCnt = blockSize / S->M;

  while (blkCnt > 0U)
  {
                                                                                  
    i = S->M;

    do
    {
      *pStateCurnt++ = *pSrc++;

    } while (--i);

                                 
    sum0 = 0;

		for(i=0;i<numTaps;i++)
		{
                             
      c0 = pCoeffs[i];

                                  
      x0 = pState[i];

                                           
      sum0 += (q63_t)x0 * c0;
		}

                                                                    
                                                                       
    pState = pState + S->M;

                                                                            
    *pDst++ = (q31_t) (sum0 >> 31);

                                    
    blkCnt--;
  }

                                     
                                                                                    
                                                                   

                                               
  pStateCurnt = S->pState;

  i = numTaps - 1U;

                 
  while (i > 0U)
  {
    *pStateCurnt++ = *pState++;

                                    
    i--;
  }
}

void ref_fir_decimate_fast_q31(
  const arm_fir_decimate_instance_q31 * S,
  q31_t * pSrc,
  q31_t * pDst,
  uint32_t blockSize)
{
        q31_t *pState = S->pState;                                        
  const q31_t *pCoeffs = S->pCoeffs;                                            
        q31_t *pStateCurnt;                                                                           
        q31_t x0, c0;                                                                                                
        q31_t sum0;                                                     
        uint32_t numTaps = S->numTaps;                                     
        uint32_t i, blkCnt;  													                    

                                                                      
                                                                                     
  pStateCurnt = S->pState + numTaps - 1U;

                                                     
  blkCnt = blockSize / S->M;

  while (blkCnt > 0U)
  {
                                                                                  
    i = S->M;

    do
    {
      *pStateCurnt++ = *pSrc++;

    } while (--i);

                                 
    sum0 = 0;

		for(i=0;i<numTaps;i++)
		{
                             
      c0 = pCoeffs[i];

                                  
      x0 = pState[i];

                                           
			sum0 = (q31_t)((((q63_t) sum0 << 32) + ((q63_t) x0 * c0)) >> 32);
		}

                                                                    
                                                                       
    pState = pState + S->M;

                                                                            
    *pDst++ = (q31_t) (sum0 << 1);

                                    
    blkCnt--;
  }

                                     
                                                                                    
                                                                   

                                               
  pStateCurnt = S->pState;

  i = numTaps - 1U;

                 
  while (i > 0U)
  {
    *pStateCurnt++ = *pState++;

                                    
    i--;
  }
}

void ref_fir_decimate_q15(
  const arm_fir_decimate_instance_q15 * S,
  q15_t * pSrc,
  q15_t * pDst,
  uint32_t blockSize)
{
        q15_t *pState = S->pState;                                        
  const q15_t *pCoeffs = S->pCoeffs;                                            
        q15_t *pStateCurnt;                                                                           
        q31_t x0, c0;                                                                                                
        q63_t sum0;                                                     
        uint32_t numTaps = S->numTaps;                                     
        uint32_t i, blkCnt;  													                    

                                                                      
                                                                                     
  pStateCurnt = S->pState + numTaps - 1U;

                                                     
  blkCnt = blockSize / S->M;

  while (blkCnt > 0U)
  {
                                                                                  
    i = S->M;

    do
    {
      *pStateCurnt++ = *pSrc++;

    } while (--i);

                                 
    sum0 = 0;

		for(i=0;i<numTaps;i++)
		{
                             
      c0 = pCoeffs[i];

                                  
      x0 = pState[i];

                                           
      sum0 += (q31_t)x0 * c0;
		}

                                                                    
                                                                       
    pState = pState + S->M;

                                                                            
    *pDst++ = ref_sat_q15(sum0 >> 15);

                                    
    blkCnt--;
  }

                                     
                                                                                    
                                                                   

                                               
  pStateCurnt = S->pState;

  i = numTaps - 1U;

                 
  while (i > 0U)
  {
    *pStateCurnt++ = *pState++;

                                    
    i--;
  }
}

void ref_fir_decimate_fast_q15(
  const arm_fir_decimate_instance_q15 * S,
  q15_t * pSrc,
  q15_t * pDst,
  uint32_t blockSize)
{
        q15_t *pState = S->pState;                                        
  const q15_t *pCoeffs = S->pCoeffs;                                            
        q15_t *pStateCurnt;                                                                           
        q15_t x0, c0;                                                                                                
        q31_t sum0;                                                     
        uint32_t numTaps = S->numTaps;                                     
        uint32_t i, blkCnt;  													                    

                                                                      
                                                                                     
  pStateCurnt = S->pState + numTaps - 1U;

                                                     
  blkCnt = blockSize / S->M;

  while (blkCnt > 0U)
  {
                                                                                  
    i = S->M;

    do
    {
      *pStateCurnt++ = *pSrc++;

    } while (--i);

                                 
    sum0 = 0;

		for(i=0;i<numTaps;i++)
		{
                             
      c0 = pCoeffs[i];

                                  
      x0 = pState[i];

                                           
      sum0 += x0 * c0;
		}

                                                                    
                                                                       
    pState = pState + S->M;

                                                                            
    *pDst++ = ref_sat_q15(sum0 >> 15);

                                    
    blkCnt--;
  }

                                     
                                                                                    
                                                                   

                                               
  pStateCurnt = S->pState;

  i = numTaps - 1U;

                 
  while (i > 0U)
  {
    *pStateCurnt++ = *pState++;

                                    
    i--;
  }
}


#include "ref.h"

void ref_lms_f32(
  const arm_lms_instance_f32 * S,
  float32_t * pSrc,
  float32_t * pRef,
  float32_t * pOut,
  float32_t * pErr,
  uint32_t blockSize)
{
  float32_t *pState = S->pState;                                    
  float32_t *pCoeffs = S->pCoeffs;                                        
  float32_t *pStateCurnt;                                                                       
  float32_t mu = S->mu;                                               
  uint32_t numTaps = S->numTaps;                                                                  
  uint32_t i, blkCnt;                     			                    
  float32_t sum, e, d;                                                                          
  float32_t w = 0.0f;                                               

  e = 0.0f;
  d = 0.0f;

                                                                                           
                                                                                     
  pStateCurnt = &(S->pState[numTaps - 1U]);

  blkCnt = blockSize;

  while (blkCnt > 0U)
  {
                                                         
    *pStateCurnt++ = *pSrc++;

                                     
    sum = 0.0f;
		
		for(i=0;i<numTaps;i++)
		{                                      
      sum += pState[i] * pCoeffs[i];
		}

                                                         
    *pOut++ = sum;

                                 
    d = *pRef++;
    e = d - sum;
    *pErr++ = e;

                                              
    w = e * mu;
		
		for(i=0;i<numTaps;i++)
		{                                      
      pCoeffs[i] += w * pState[i];
		}

                                                        
    pState++;

                                    
    blkCnt--;
  }

                                                                                 
                                                                              
                           
	for(i=0;i<numTaps-1;i++)
  {
    S->pState[i] = pState[i];
  }
}

void ref_lms_norm_f32(
  arm_lms_norm_instance_f32 * S,
  float32_t * pSrc,
  float32_t * pRef,
  float32_t * pOut,
  float32_t * pErr,
  uint32_t blockSize)
{
  float32_t *pState = S->pState;                                    
  float32_t *pCoeffs = S->pCoeffs;                                        
  float32_t *pStateCurnt;                                                                       
  float32_t mu = S->mu;                                               
  uint32_t numTaps = S->numTaps;                                                                  
  uint32_t i, blkCnt;                    				                    
  float32_t energy;                                                       
  float32_t sum, e, d;                                                                          
  float32_t w, x0, in;                                                                                                 

                                                                 
  e = 0.0f;
  d = 0.0f;
  w = 0.0f;

  energy = S->energy;
  x0 = S->x0;

                                                                                      
                                                                                     
  pStateCurnt = &(S->pState[numTaps - 1U]);

  for(blkCnt = blockSize; blkCnt > 0U; blkCnt--)
  {
                                                         
    *pStateCurnt++ = *pSrc;

                                           
    in = *pSrc++;

                                       
    energy -= x0 * x0;
    energy += in * in;

                                     
    sum = 0.0f;
		
		for(i=0;i<numTaps;i++)
		{                                      
      sum += pState[i] * pCoeffs[i];
		}

                                                                            
    *pOut++ = sum;

                                 
    d = *pRef++;
    e = d - sum;
    *pErr++ = e;

                                                                          
                                          
    w = e * mu / (energy + 0.000000119209289f);

		for(i=0;i<numTaps;i++)
    {
                                           
      pCoeffs[i] += w * pState[i];
    }

    x0 = *pState;

                                                        
    pState++;
  }

  S->energy = energy;
  S->x0 = x0;

                                                                                 
                                                                              
                           
	for(i=0;i<numTaps-1;i++)
  {
    S->pState[i] = pState[i];
  }
}

void ref_lms_q31(
  const arm_lms_instance_q31 * S,
  q31_t * pSrc,
  q31_t * pRef,
  q31_t * pOut,
  q31_t * pErr,
  uint32_t blockSize)
{
  q31_t *pState = S->pState;                                        
  uint32_t numTaps = S->numTaps;                                                                  
  q31_t *pCoeffs = S->pCoeffs;                                            
  q31_t *pStateCurnt;                                                                           
  q31_t mu = S->mu;                                                   
  q31_t *px;                                                                      
  q31_t *pb;                                                                                   
  uint32_t tapCnt, blkCnt;                                          
  q63_t acc;                                                      
  q31_t e = 0;                                                             
  q31_t alpha;                                                                              
  q31_t coef;                                                                     
  q31_t acc_l, acc_h;                                                  
  uint32_t uShift = (uint32_t)S->postShift + 1;
  uint32_t lShift = 32U - uShift;                                                        

                                                                                      
                                                                                     
  pStateCurnt = &(S->pState[(numTaps - 1U)]);

  for(blkCnt = blockSize; blkCnt > 0U; blkCnt--)
  {
                                                         
    *pStateCurnt++ = *pSrc++;

                                   
    px = pState;

                                    
    pb = pCoeffs;

                                     
    acc = 0;

                                            
    tapCnt = numTaps;

    while (tapCnt > 0U)
    {
                                           
      acc += (q63_t)(*px++) * (*pb++);

                                      
      tapCnt--;
    }

                                              
                                                                        
                                
    acc_l = acc & 0xffffffff;

                                
    acc_h = (acc >> 32) & 0xffffffff;

    acc = (uint32_t)acc_l >> lShift | acc_h << uShift;

    *pOut++ = (q31_t)acc;

                                 
    e = *pRef++ - (q31_t)acc;

    *pErr++ = (q31_t)e;

                                              
    alpha = (q31_t)(((q63_t)e * mu) >> 31);

                                   
                                                        
    px = pState++;

                                    
    pb = pCoeffs;

                                            
    tapCnt = numTaps;

    while (tapCnt > 0U)
    {
                                           
      coef = (q31_t)(((q63_t) alpha * (*px++)) >> 32);
      *pb = ref_sat_q31((q63_t)*pb + (coef << 1));
      pb++;

                                      
      tapCnt--;
    }
  }

                                                                              
                                                                         
                           

                                                
  pStateCurnt = S->pState;

                                     
  tapCnt = numTaps - 1;

                     
  while (tapCnt > 0U)
  {
    *pStateCurnt++ = *pState++;

                                    
    tapCnt--;
  }
}

void ref_lms_norm_q31(
  arm_lms_norm_instance_q31 * S,
  q31_t * pSrc,
  q31_t * pRef,
  q31_t * pOut,
  q31_t * pErr,
  uint32_t blockSize)
{
  q31_t *pState = S->pState;                                        
  q31_t *pCoeffs = S->pCoeffs;                                            
  q31_t *pStateCurnt;                                                                           
  q31_t *px, *pb;                                                                                          
  q31_t mu = S->mu;                                                   
  uint32_t numTaps = S->numTaps;                                                                  
  uint32_t tapCnt, blkCnt;                                          
  q63_t energy;                                                           
  q63_t acc;                                                      
  q31_t e = 0, d = 0;                                                              
  q31_t w = 0, in;                                                            
  q31_t x0;                                                                                      
  q63_t errorXmu;                   				                                                                                 
  q31_t coef;                                                                     
  q31_t acc_l, acc_h;                                                  
  uint32_t uShift = ((uint32_t) S->postShift + 1U);
  uint32_t lShift = 32U - uShift;                                                        

  energy = S->energy;
  x0 = S->x0;

                                                                                      
                                                                                     
  pStateCurnt = &(S->pState[(numTaps - 1U)]);

  for(blkCnt = blockSize; blkCnt > 0U; blkCnt--)
  {

                                                         
    *pStateCurnt++ = *pSrc;

                                   
    px = pState;

                                    
    pb = pCoeffs;

                                           
    in = *pSrc++;

                                       
    energy = (q31_t)((((q63_t)energy << 32) - (((q63_t)x0 * x0) << 1)) >> 32) & 0xffffffff;
    energy = (q31_t)(((((q63_t)in * in) << 1) + ((q63_t)energy << 32)) >> 32) & 0xffffffff;

                                     
    acc = 0;

                                            
    tapCnt = numTaps;

    while (tapCnt > 0U)
    {
                                           
      acc += ((q63_t) (*px++)) * (*pb++);

                                      
      tapCnt--;
    }

                                              
                                
    acc_l = acc & 0xffffffff;

                                
    acc_h = (acc >> 32) & 0xffffffff;

    acc = (uint32_t)acc_l >> lShift | acc_h << uShift;

                                                                        
    *pOut++ = (q31_t)acc;

                                 
    d = *pRef++;
    e = d - (q31_t)acc;
    *pErr++ = e;

                                            
    errorXmu = (q63_t)e * mu;

                                                     
    w = ref_sat_q31(errorXmu / (energy + DELTA_Q31));

                                   
    px = pState;

                                  
    pb = pCoeffs;

                                            
    tapCnt = numTaps;

    while (tapCnt > 0U)
    {
                                           
                                  
      coef = (q31_t)(((q63_t)w * (*px++)) >> 32);
                                                    
      *pb = ref_sat_q31((q63_t)*pb + (coef << 1U));
                                                         
      pb++;

                                      
      tapCnt--;
    }

                                           
    x0 = *pState;

                                                        
    pState++;
  }

                                                    
  S->energy = (q31_t)energy;
  S->x0 = x0;

                                                                              
                                                                              
                           

                                                
  pStateCurnt = S->pState;

                                            
  tapCnt = numTaps - 1;

                                     
  while (tapCnt > 0U)
  {
    *pStateCurnt++ = *pState++;

                                    
    tapCnt--;
  }
}

void ref_lms_q15(
  const arm_lms_instance_q15 * S,
  q15_t * pSrc,
  q15_t * pRef,
  q15_t * pOut,
  q15_t * pErr,
  uint32_t blockSize)
{
  q15_t *pState = S->pState;                                        
  uint32_t numTaps = S->numTaps;                                                                  
  q15_t *pCoeffs = S->pCoeffs;                                            
  q15_t *pStateCurnt;                                                                           
  q15_t mu = S->mu;                                                   
  q15_t *px;                                                                      
  q15_t *pb;                                                                                   
  uint32_t tapCnt, blkCnt;                                          
  q63_t acc;                                                      
  q15_t e = 0;                                                             
  q15_t alpha;                                                                              
  q31_t coef;                                                                           
  q31_t acc_l, acc_h;
  int32_t lShift = 15 - (int32_t)S->postShift;                     
  int32_t uShift = 32 - lShift;

                                                                                      
                                                                                     
  pStateCurnt = &(S->pState[(numTaps - 1U)]);

  for(blkCnt = blockSize; blkCnt > 0U; blkCnt--)
  {
                                                         
    *pStateCurnt++ = *pSrc++;

                                   
    px = pState;

                                    
    pb = pCoeffs;

                                     
    acc = 0;

                                            
    tapCnt = numTaps;

    while (tapCnt > 0U)
    {
                                           
      acc += (q63_t)((q31_t)(*px++) * (*pb++));

                                      
      tapCnt--;
    }

                                
    acc_l = acc & 0xffffffff;

                                
    acc_h = (acc >> 32) & 0xffffffff;

                                                                 
    acc = (uint32_t)acc_l >> lShift | acc_h << uShift;

                                                                      
    acc = ref_sat_q15(acc);

                                                                        
    *pOut++ = (q15_t)acc;

                                 
    e = *pRef++ - (q15_t)acc;

    *pErr++ = (q15_t)e;

                                                                  
    alpha = (q15_t)(((q31_t)e * mu) >> 15);

                                   
                                                        
    px = pState++;

                                    
    pb = pCoeffs;

                                            
    tapCnt = numTaps;

    while (tapCnt > 0U)
    {
                                           
      coef = (q31_t) * pb + (((q31_t) alpha * (*px++)) >> 15);
      *pb++ = (q15_t) ref_sat_q15(coef);

                                      
      tapCnt--;
    }
  }

                                                                                 
                                                                         
                           

                                                
  pStateCurnt = S->pState;

                                     
  tapCnt = numTaps - 1;

                     
  while (tapCnt > 0U)
  {
    *pStateCurnt++ = *pState++;

                                    
    tapCnt--;
  }
}

void ref_lms_norm_q15(
  arm_lms_norm_instance_q15 * S,
  q15_t * pSrc,
  q15_t * pRef,
  q15_t * pOut,
  q15_t * pErr,
  uint32_t blockSize)
{
  q15_t *pState = S->pState;                                        
  q15_t *pCoeffs = S->pCoeffs;                                            
  q15_t *pStateCurnt;                                                                           
  q15_t *px, *pb;                                                                                          
  q15_t mu = S->mu;                                                   
  uint32_t numTaps = S->numTaps;                                                                  
  uint32_t tapCnt, blkCnt;                                          
  q31_t energy;                                                           
  q63_t acc;                                                      
  q15_t e = 0, d = 0;                                                              
  q15_t w = 0, in;                                                            
  q15_t x0;                                                                                   
  q15_t errorXmu, oneByEnergy;                                                                                                   
                                                                                                                           
  q15_t postShift;                                                                                                    
  q31_t coef;                                                                           
  q31_t acc_l, acc_h;
  int32_t lShift = 15 - (int32_t)S->postShift;                    
  int32_t uShift = 32 - lShift;

  energy = S->energy;
  x0 = S->x0;

                                                                                      
                                                                                     
  pStateCurnt = &(S->pState[(numTaps - 1U)]);

  for(blkCnt = blockSize; blkCnt > 0U; blkCnt--)
  {
                                                         
    *pStateCurnt++ = *pSrc;

                                   
    px = pState;

                                    
    pb = pCoeffs;

                                           
    in = *pSrc++;

                                       
    energy -= (((q31_t)x0 * x0) >> 15) & 0xffff;
    energy += (((q31_t)in * in) >> 15) & 0xffff;

                                     
    acc = 0;

                                            
    tapCnt = numTaps;

    while (tapCnt > 0U)
    {
                                           
      acc += (q31_t)*px++ * (*pb++);

                                      
      tapCnt--;
    }

                                
    acc_l = acc & 0xffffffff;

                                
    acc_h = (acc >> 32) & 0xffffffff;

                                                                 
    acc = (uint32_t) acc_l >> lShift | acc_h << uShift;

                                                                      
    acc = ref_sat_q15(acc);

                                                                        
    *pOut++ = (q15_t) acc;

                                 
    d = *pRef++;
    e = d - (q15_t) acc;
    *pErr++ = e;
    
#if 0
                                     
    errorXmu = (q31_t) e * mu;

                                               
    acc = errorXmu / (energy + DELTA_Q15);
#endif

                                 
    postShift = arm_recip_q15((q15_t) energy + DELTA_Q15,
                              &oneByEnergy, S->recipTable);

                                     
    errorXmu = (q15_t) (((q31_t) e * mu) >> 15);

                                                    
    acc = (((q31_t) errorXmu * oneByEnergy) >> (15 - postShift));
    
                                                     
    w = ref_sat_q15((q31_t)acc);

                                   
    px = pState;

                                  
    pb = pCoeffs;

                                            
    tapCnt = numTaps;

    while (tapCnt > 0U)
    {
                                           
      coef = *pb + (((q31_t)w * (*px++)) >> 15);
      *pb++ = ref_sat_q15(coef);

                                      
      tapCnt--;
    }

                                           
    x0 = *pState;

                                                        
    pState = pState + 1U;
  }

                                                    
  S->energy = (q15_t)energy;
  S->x0 = x0;

                                                                                 
                                                                              
                           

                                                
  pStateCurnt = S->pState;

                                
  tapCnt = numTaps - 1;

                 
  while (tapCnt > 0U)
  {
    *pStateCurnt++ = *pState++;

                                    
    tapCnt--;
  }
}

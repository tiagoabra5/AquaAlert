#include "ref.h"

void ref_iir_lattice_f32(
  const arm_iir_lattice_instance_f32 * S,
  float32_t * pSrc,
  float32_t * pDst,
  uint32_t blockSize)
{
  float32_t fcurr, fnext = 0, gcurr, gnext;                                                  
  float32_t acc;                                                 
  uint32_t blkCnt, tapCnt;                                                           
  float32_t *px1, *px2, *pk, *pv;                                                           
  uint32_t numStages = S->numStages;                                   
  float32_t *pState;                                                
  float32_t *pStateCurnt;                                                   

  blkCnt = blockSize;
  pState = &S->pState[0];

                         
  while (blkCnt > 0U)
  {
                                       
                      
    fcurr = *pSrc++;

                                       
    px1 = pState;
                                        
    px2 = pState;
                                 
    acc = 0.0f;
                                         
    pv = &S->pvCoeffs[0];
                                             
    pk = &S->pkCoeffs[0];

                                      
    tapCnt = numStages;

    while (tapCnt > 0U)
    {
      gcurr = *px1++;
                                        
      fnext = fcurr - (*pk) * gcurr;
      gnext = fnext * (*pk++) + gcurr;

                                        
      acc += gnext * (*pv++);
      *px2++ = gnext;
      fcurr = fnext;

                                     
      tapCnt--;
    }

                            
    acc += fnext * (*pv);

    *px2++ = fnext;

                             
    *pDst++ = acc;

                                                                             
    pState = pState + 1U;
    blkCnt--;
  }

                                                                                                 
                                                 

                                               
  pStateCurnt = &S->pState[0];
  pState = &S->pState[blockSize];

  tapCnt = numStages;

                     
  while (tapCnt > 0U)
  {
    *pStateCurnt++ = *pState++;

                                    
    tapCnt--;
  }
}

void ref_iir_lattice_q31(
  const arm_iir_lattice_instance_q31 * S,
  q31_t * pSrc,
  q31_t * pDst,
  uint32_t blockSize)
{
  q31_t fcurr, fnext = 0, gcurr = 0, gnext;                                                  
  q63_t acc;                                                     
  uint32_t blkCnt, tapCnt;                                                           
  q31_t *px1, *px2, *pk, *pv;                                                               
  uint32_t numStages = S->numStages;                                   
  q31_t *pState;                                                    
  q31_t *pStateCurnt;                                                       

  blkCnt = blockSize;
  pState = &S->pState[0];

                         
  while (blkCnt > 0U)
  {
                                       
                      
    fcurr = *pSrc++;

                                       
    px1 = pState;
                                        
    px2 = pState;
                                 
    acc = 0;
                                         
    pv = &S->pvCoeffs[0];
                                             
    pk = &S->pkCoeffs[0];

    tapCnt = numStages;

    while (tapCnt > 0U)
    {
      gcurr = *px1++;
                          
                                            
      fnext =
        ref_sat_q31(((q63_t) fcurr -
                         ((q31_t) (((q63_t) gcurr * (*pk)) >> 31))));
                                            
      gnext =
        ref_sat_q31(((q63_t) gcurr +
                         ((q31_t) (((q63_t) fnext * (*pk++)) >> 31))));
                          
                               
      acc += ((q63_t) gnext * *pv++);
                                                                 
      *px2++ = gnext;
                                                           
      fcurr = fnext;

      tapCnt--;
    }

                            
    acc += (q63_t) fnext *(*pv++);

    *px2++ = fnext;

                             
    *pDst++ = (q31_t) (acc >> 31U);

                                                                             
    pState = pState + 1U;
    blkCnt--;
  }

                                                                                                 
                                                 

                                               
  pStateCurnt = &S->pState[0];
  pState = &S->pState[blockSize];

  tapCnt = numStages;

                                     
  while (tapCnt > 0U)
  {
    *pStateCurnt++ = *pState++;

                                    
    tapCnt--;
  }
}

void ref_iir_lattice_q15(
  const arm_iir_lattice_instance_q15 * S,
  q15_t * pSrc,
  q15_t * pDst,
  uint32_t blockSize)
{
  q31_t fcurr, fnext = 0, gcurr = 0, gnext;                                                  
  uint32_t stgCnt;                                                                   
  q63_t acc;                                                     
  uint32_t blkCnt, tapCnt;                                                           
  q15_t *px1, *px2, *pk, *pv;                                                               
  uint32_t numStages = S->numStages;                                   
  q15_t *pState;                                                    
  q15_t *pStateCurnt;                                                       
  q15_t out;                                                                        

  blkCnt = blockSize;
  pState = &S->pState[0];

                         
  while (blkCnt > 0U)
  {
                                       
                      
    fcurr = *pSrc++;

                                       
    px1 = pState;
                                        
    px2 = pState;
                                 
    acc = 0;
                                         
    pv = &S->pvCoeffs[0];
                                             
    pk = &S->pkCoeffs[0];

    tapCnt = numStages;

    while (tapCnt > 0U)
    {
      gcurr = *px1++;
                          
                                            
      fnext = fcurr - ((gcurr * (*pk)) >> 15);
      fnext = ref_sat_q15(fnext);
                                            
      gnext = ((fnext * (*pk++)) >> 15) + gcurr;
      gnext = ref_sat_q15(gnext);
                          
                              
      acc += (q31_t) ((gnext * (*pv++)));
                                                             
      *px2++ = (q15_t) gnext;
                                                           
      fcurr = fnext;

      tapCnt--;
    }

                            
    acc += (q31_t) ((fnext * (*pv++)));

    out = ref_sat_q15(acc >> 15);
    *px2++ = (q15_t) fnext;

                             
    *pDst++ = out;

                                                                             
    pState = pState + 1U;
    blkCnt--;
  }

                                                                                                 
                                                 
                                               
  pStateCurnt = &S->pState[0];
  pState = &S->pState[blockSize];

  stgCnt = numStages;

                 
  while (stgCnt > 0U)
  {
    *pStateCurnt++ = *pState++;

                                    
    stgCnt--;
  }
}

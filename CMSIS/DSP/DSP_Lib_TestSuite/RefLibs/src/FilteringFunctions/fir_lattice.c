#include "ref.h"

void ref_fir_lattice_f32(
  const arm_fir_lattice_instance_f32 * S,
        float32_t * pSrc,
        float32_t * pDst,
        uint32_t blockSize)
{
        float32_t *pState;                                                
  const float32_t *pCoeffs = S->pCoeffs;                                        
        float32_t *px;                                                              
  const float32_t *pk;                                                                    
        float32_t fcurr, fnext, gcurr, gnext;                                   
        uint32_t numStages = S->numStages;                                       
        uint32_t blkCnt, stageCnt;                                                         

  pState = &S->pState[0];

  blkCnt = blockSize;

  while (blkCnt > 0U)
  {
                      
    fcurr = *pSrc++;

                                  
    pk = pCoeffs;

                                  
    px = pState;

                                        
    gcurr = *px;

                                 
                                       
    fnext = fcurr + ((*pk) * gcurr);
                                        
    gnext = (fcurr * (*pk++)) + gcurr;

                                    
    *px++ = fcurr;

                                          
                                   
    fcurr = fnext;

    stageCnt = (numStages - 1U);

                    
    while (stageCnt > 0U)
    {
                                        
      gcurr = *px;

                                      
      *px++ = gnext;

                                            
                                         
      fnext = fcurr + ((*pk) * gcurr);
                                          
      gnext = (fcurr * (*pk++)) + gcurr;

                                             
                                     
      fcurr = fnext;

      stageCnt--;
    }

                      
    *pDst++ = fcurr;

    blkCnt--;
  }
}

void ref_fir_lattice_q31(
  const arm_fir_lattice_instance_q31 * S,
        q31_t * pSrc,
        q31_t * pDst,
        uint32_t blockSize)
{
        q31_t *pState;                                                    
  const q31_t *pCoeffs = S->pCoeffs;                                            
        q31_t *px;                                                                  
  const q31_t *pk;                                                                        
        q31_t fcurr, fnext, gcurr, gnext;                                       
        uint32_t numStages = S->numStages;                                       
        uint32_t blkCnt, stageCnt;                                                         

  pState = &S->pState[0];

  blkCnt = blockSize;

  while (blkCnt > 0U)
  {
                      
    fcurr = *pSrc++;

                                  
    pk = pCoeffs;

                                  
    px = pState;

                                        
    gcurr = *px;

                                 
                                       
    fnext = (q31_t) (((q63_t) gcurr * (*pk)) >> 31) + fcurr;
                                        
    gnext = (q31_t) (((q63_t) fcurr * (*pk++)) >> 31) + gcurr;
                                    
    *px++ = fcurr;

                                           
                                   
    fcurr = fnext;

    stageCnt = (numStages - 1U);

                    
    while (stageCnt > 0U)
    {
                                        
      gcurr = *px;

                                      
      *px++ = gnext;

                                            
                                         
      fnext = (q31_t) (((q63_t) gcurr * (*pk)) >> 31) + fcurr;
                                          
      gnext = (q31_t) (((q63_t) fcurr * (*pk++)) >> 31) + gcurr;

                                             
                                     
      fcurr = fnext;

      stageCnt--;

    }

                      
    *pDst++ = fcurr;

    blkCnt--;

  }
}

void ref_fir_lattice_q15(
  const arm_fir_lattice_instance_q15 * S,
        q15_t * pSrc,
        q15_t * pDst,
        uint32_t blockSize)
{
        q15_t *pState;                                                    
  const q15_t *pCoeffs = S->pCoeffs;                                            
        q15_t *px;                                                                  
  const q15_t *pk;                                                                        
        q31_t fcurnt, fnext, gcurnt, gnext;                                     
        uint32_t numStages = S->numStages;                                       
        uint32_t blkCnt, stageCnt;                                                         

  pState = &S->pState[0];

  blkCnt = blockSize;

  while (blkCnt > 0U)
  {
                      
    fcurnt = *pSrc++;

                                  
    pk = (pCoeffs);

                                  
    px = pState;

                                        
    gcurnt = *px;

                                 
                                       
    fnext = ((gcurnt * (*pk)) >> 15U) + fcurnt;
    fnext = ref_sat_q15(fnext);


                                        
    gnext = ((fcurnt * (*pk++)) >> 15U) + gcurnt;
    gnext = ref_sat_q15(gnext);

                                    
    *px++ = (q15_t) fcurnt;

                                           
                                   
    fcurnt = fnext;

    stageCnt = (numStages - 1U);

                    
    while (stageCnt > 0U)
    {
                                          
      gcurnt = *px;

                                        
      *px++ = (q15_t) gnext;

                                            
                                         
      fnext = ((gcurnt * (*pk)) >> 15U) + fcurnt;
      fnext = ref_sat_q15(fnext);

                                          
      gnext = ((fcurnt * (*pk++)) >> 15U) + gcurnt;
      gnext = ref_sat_q15(gnext);


                                             
                                     
      fcurnt = fnext;

      stageCnt--;

    }

                      
    *pDst++ = ref_sat_q15(fcurnt);


    blkCnt--;

  }
}

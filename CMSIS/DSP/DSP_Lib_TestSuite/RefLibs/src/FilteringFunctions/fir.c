#include "ref.h"

void ref_fir_f32(
	const arm_fir_instance_f32 * S,
	      float32_t * pSrc,
	      float32_t * pDst,
	      uint32_t blockSize)
{
        float32_t *pState = S->pState;                                    
	const float32_t *pCoeffs = S->pCoeffs;                                        
        float32_t *pStateCurnt;                                                                       
        uint32_t numTaps = S->numTaps;                                                                  
        uint32_t i;                    								                   
        float32_t acc;

                                                                                            
                                                                                      
   pStateCurnt = &(S->pState[(numTaps - 1U)]);

   while (blockSize > 0U)
   {
                                                       
      *pStateCurnt++ = *pSrc++;

                                       
      acc = 0.0f;

			for(i=0;i<numTaps;i++)
			{
				                                      
				acc += pState[i] * pCoeffs[i];
			}

                                                          
      *pDst++ = acc;

                                                          
      pState++;

      blockSize--;
   }

                                      
                                                                                       
                                                                   

                                                
   pStateCurnt = S->pState;

                  
	 for(i=0;i<numTaps-1;i++)
	 {
      pStateCurnt[i] = pState[i];
	 }
}

void ref_fir_q31(
  const arm_fir_instance_q31 * S,
        q31_t * pSrc,
        q31_t * pDst,
        uint32_t blockSize)
{
        q31_t *pState = S->pState;                                    
	const q31_t *pCoeffs = S->pCoeffs;                                        
        q31_t *pStateCurnt;                                                                       
        uint32_t numTaps = S->numTaps;                                                              
        uint32_t i;                                                  
        q63_t acc;

                                                                                            
                                                                                      
   pStateCurnt = &(S->pState[(numTaps - 1U)]);

   while (blockSize > 0U)
   {
                                                       
      *pStateCurnt++ = *pSrc++;

                                       
      acc = 0.0f;

			for(i=0;i<numTaps;i++)
			{
				                                      
				acc += (q63_t)pState[i] * pCoeffs[i];
			}

                                                          
      *pDst++ = (q31_t)(acc >> 31);

                                                          
      pState++;

      blockSize--;
   }

                                      
                                                                                       
                                                                   

                                                
   pStateCurnt = S->pState;

                  
	 for(i=0;i<numTaps-1;i++)
	 {
      pStateCurnt[i] = pState[i];
	 }
}

void ref_fir_fast_q31(
  const arm_fir_instance_q31 * S,
        q31_t * pSrc,
        q31_t * pDst,
        uint32_t blockSize)
{
        q31_t *pState = S->pState;                                    
	const q31_t *pCoeffs = S->pCoeffs;                                        
        q31_t *pStateCurnt;                                                                       
        uint32_t numTaps = S->numTaps;                                                              
        uint32_t i;                                                  
        q31_t acc;

                                                                                            
                                                                                      
   pStateCurnt = &(S->pState[(numTaps - 1U)]);

   while (blockSize > 0U)
   {
                                                       
      *pStateCurnt++ = *pSrc++;

                                       
      acc = 0.0f;

			for(i=0;i<numTaps;i++)
			{
				                                      
				acc = (q31_t) (((((q63_t) acc) << 32) + ((q63_t) pState[i] * pCoeffs[i]) + 0x80000000LL ) >> 32);
			}

                                                          
      *pDst++ = (q31_t)(acc << 1);

                                                          
      pState++;

      blockSize--;
   }

                                      
                                                                                       
                                                                   

                                                
   pStateCurnt = S->pState;

                  
	 for(i=0;i<numTaps-1;i++)
	 {
      pStateCurnt[i] = pState[i];
	 }
}

void ref_fir_q15(
  const arm_fir_instance_q15 * S,
        q15_t * pSrc,
        q15_t * pDst,
        uint32_t blockSize)
{
        q15_t *pState = S->pState;                                    
	const q15_t *pCoeffs = S->pCoeffs;                                        
        q15_t *pStateCurnt;                                                                       
        uint32_t numTaps = S->numTaps;                                                              
        uint32_t i;                                                  
        q63_t acc;

                                                                                            
                                                                                      
   pStateCurnt = &(S->pState[(numTaps - 1U)]);

   while (blockSize > 0U)
   {
                                                       
      *pStateCurnt++ = *pSrc++;

                                       
      acc = 0.0f;

			for(i=0;i<numTaps;i++)
			{
				                                      
				acc += (q31_t)pState[i] * pCoeffs[i];
			}

                                                          
      *pDst++ = ref_sat_q15(acc >> 15);

                                                          
      pState++;

      blockSize--;
   }

                                      
                                                                                       
                                                                   

                                                
   pStateCurnt = S->pState;

                  
	 for(i=0;i<numTaps;i++)
	 {
      pStateCurnt[i] = pState[i];
	 }
}

void ref_fir_fast_q15(
  const arm_fir_instance_q15 * S,
        q15_t * pSrc,
        q15_t * pDst,
        uint32_t blockSize)
{
        q15_t *pState = S->pState;                                    
	const q15_t *pCoeffs = S->pCoeffs;                                        
        q15_t *pStateCurnt;                                                                       
        uint32_t numTaps = S->numTaps;                                                              
        uint32_t i;                                                  
        q31_t acc;

                                                                                            
                                                                                      
   pStateCurnt = &(S->pState[(numTaps - 1U)]);

   while (blockSize > 0U)
   {
                                                       
      *pStateCurnt++ = *pSrc++;

                                       
      acc = 0.0f;

			for(i=0;i<numTaps;i++)
			{
				                                      
				acc += (q31_t)pState[i] * pCoeffs[i];
			}

                                                          
      *pDst++ = ref_sat_q15(acc >> 15);

                                                          
      pState++;

      blockSize--;
   }

                                      
                                                                                       
                                                                   

                                                
   pStateCurnt = S->pState;

                  
	 for(i=0;i<numTaps-1;i++)
	 {
      pStateCurnt[i] = pState[i];
	 }
}

void ref_fir_q7(
  const arm_fir_instance_q7 * S,
        q7_t * pSrc,
        q7_t * pDst,
        uint32_t blockSize)
{
        q7_t *pState = S->pState;                                    
	const q7_t *pCoeffs = S->pCoeffs;                                        
        q7_t *pStateCurnt;                                                                       
        uint32_t numTaps = S->numTaps;                                                             
        uint32_t i;                                                 
        q31_t acc;

                                                                                            
                                                                                      
   pStateCurnt = &(S->pState[(numTaps - 1U)]);

   while (blockSize > 0U)
   {
                                                       
      *pStateCurnt++ = *pSrc++;

                                       
      acc = 0.0f;

			for(i=0;i<numTaps;i++)
			{
				                                      
				acc += (q31_t)pState[i] * pCoeffs[i];
			}

                                                          
      *pDst++ = ref_sat_q7(acc >> 7);

                                                          
      pState++;

      blockSize--;
   }

                                      
                                                                                       
                                                                   

                                                
   pStateCurnt = S->pState;

                  
	 for(i=0;i<numTaps-1;i++)
	 {
      pStateCurnt[i] = pState[i];
	 }
}

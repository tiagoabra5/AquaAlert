#include "ref.h"

void ref_fir_sparse_f32(
        arm_fir_sparse_instance_f32 * S,
        float32_t * pSrc,
        float32_t * pDst,
        float32_t * pScratchIn,
        uint32_t blockSize)
{
        float32_t *pState = S->pState;                                    
  const float32_t *pCoeffs = S->pCoeffs;                                        
        float32_t *px;                                                             
        float32_t *py = pState;                                                                 
        float32_t *pb = pScratchIn;                                                               
        float32_t *pOut;                                                        
        int32_t *pTapDelay = S->pTapDelay;                                                                                     
        uint32_t delaySize = S->maxDelay + blockSize;                    
        uint16_t numTaps = S->numTaps;                                                                   
        int32_t readIndex;                                                                 
        uint32_t tapCnt, blkCnt;                                          
        float32_t coeff = *pCoeffs++;                                                        


                                                                   
                                                                               
  arm_circularWrite_f32((int32_t *) py, delaySize, &S->stateIndex, 1,
                        (int32_t *) pSrc, 1, blockSize);


                                                                              
  readIndex = ((int32_t) S->stateIndex - (int32_t) blockSize) - *pTapDelay++;

                               
  if (readIndex < 0)
  {
    readIndex += (int32_t) delaySize;
  }

                                                   
  py = pState;

                                                        
  arm_circularRead_f32((int32_t *) py, delaySize, &readIndex, 1,
                       (int32_t *) pb, (int32_t *) pb, blockSize, 1,
                       blockSize);

                                              
  px = pb;

                                              
  pOut = pDst;

  blkCnt = blockSize;

  while (blkCnt > 0U)
  {
                                                                 
    *pOut++ = *px++ * coeff;

                                    
    blkCnt--;
  }

                                     
  tapCnt = (uint32_t) numTaps - 1U;

  while (tapCnt > 0U)
  {
                                     
                                                                           
    coeff = *pCoeffs++;

                                                                                
    readIndex = ((int32_t) S->stateIndex - (int32_t) blockSize) - *pTapDelay++;

                                 
    if (readIndex < 0)
    {
      readIndex += (int32_t) delaySize;
    }

                                                     
    py = pState;

                                                          
    arm_circularRead_f32((int32_t *) py, delaySize, &readIndex, 1,
                         (int32_t *) pb, (int32_t *) pb, blockSize, 1,
                         blockSize);

                                                
    px = pb;

                                                
    pOut = pDst;

    blkCnt = blockSize;

    while (blkCnt > 0U)
    {
                                       
      *pOut++ += *px++ * coeff;

                                      
      blkCnt--;
    }

                                        
    tapCnt--;
  }
}

void ref_fir_sparse_q31(
        arm_fir_sparse_instance_q31 * S,
        q31_t * pSrc,
        q31_t * pDst,
        q31_t * pScratchIn,
        uint32_t blockSize)
{
        q31_t *pState = S->pState;                                        
  const q31_t *pCoeffs = S->pCoeffs;                                            
        q31_t *px;                                                                 
        q31_t *py = pState;                                                                     
        q31_t *pb = pScratchIn;                                                                   
        q31_t *pOut;                                                            
        q63_t out;                                                                    
        int32_t *pTapDelay = S->pTapDelay;                                                                                     
        uint32_t delaySize = S->maxDelay + blockSize;                    
        uint16_t numTaps = S->numTaps;                                   
        int32_t readIndex;                                                                 
        uint32_t tapCnt, blkCnt;                                          
        q31_t coeff = *pCoeffs++;                                                            
        q31_t in;


                                                                   
                                                                               
  arm_circularWrite_f32((int32_t *) py, delaySize, &S->stateIndex, 1,
                        (int32_t *) pSrc, 1, blockSize);

                                                                              
  readIndex = (int32_t) (S->stateIndex - blockSize) - *pTapDelay++;

                               
  if (readIndex < 0)
  {
    readIndex += (int32_t) delaySize;
  }

                                                   
  py = pState;

                                                        
  arm_circularRead_f32((int32_t *) py, delaySize, &readIndex, 1,
                       (int32_t *) pb, (int32_t *) pb, blockSize, 1,
                       blockSize);

                                                              
  px = pb;

                                                           
  pOut = pDst;
  
  blkCnt = blockSize;

  while (blkCnt > 0U)
  {
                                                                     
    *pOut++ = (q31_t) (((q63_t) * px++ * coeff) >> 32);

                                    
    blkCnt--;
  }

                                     
  tapCnt = (uint32_t) numTaps - 1U;

  while (tapCnt > 0U)
  {
                                                
                                                                           
    coeff = *pCoeffs++;

                                                                                
    readIndex = (int32_t) (S->stateIndex - blockSize) - *pTapDelay++;

                                 
    if (readIndex < 0)
    {
      readIndex += (int32_t) delaySize;
    }

                                                     
    py = pState;

                                                          
    arm_circularRead_f32((int32_t *) py, delaySize, &readIndex, 1,
                         (int32_t *) pb, (int32_t *) pb, blockSize, 1,
                         blockSize);

                                                                
    px = pb;

                                                             
    pOut = pDst;

    blkCnt = blockSize;

    while (blkCnt > 0U)
    {
                                       
      out = *pOut;
      out += ((q63_t) * px++ * coeff) >> 32;
      *pOut++ = (q31_t) (out);

                                      
      blkCnt--;
    }

                                        
    tapCnt--;
  }

                                         
  pOut = pDst;

                                             
  blkCnt = blockSize;

  while (blkCnt > 0U)
  {
    in = *pOut << 1;
    *pOut++ = in;

                                    
    blkCnt--;
  }
}

void ref_fir_sparse_q15(
        arm_fir_sparse_instance_q15 * S,
        q15_t * pSrc,
        q15_t * pDst,
        q15_t * pScratchIn,
        q31_t * pScratchOut,
        uint32_t blockSize)
{
        q15_t *pState = S->pState;                                        
  const q15_t *pCoeffs = S->pCoeffs;                                            
        q15_t *pIn = pSrc;                                                            
        q15_t *pOut = pDst;                                                            
        q15_t *px;                                                                                
        q15_t *pb = pScratchIn;                                                                   
        q15_t *py = pState;                                                                     
        int32_t *pTapDelay = S->pTapDelay;                                                                                     
        uint32_t delaySize = S->maxDelay + blockSize;                    
        uint16_t numTaps = S->numTaps;                                   
        int32_t readIndex;                                                                 
        uint32_t tapCnt, blkCnt;                                          
        q15_t coeff = *pCoeffs++;                                                            
        q31_t *pScr2 = pScratchOut;                                                         

                                                                   
                                                                               
  arm_circularWrite_q15(py, delaySize, &S->stateIndex, 1, pIn, 1, blockSize);

                                     
  tapCnt = numTaps;

                                                                              
  readIndex = (S->stateIndex - blockSize) - *pTapDelay++;

                               
  if (readIndex < 0)
  {
    readIndex += (int32_t) delaySize;
  }

                                                   
  py = pState;

                                                        
  arm_circularRead_q15(py, delaySize, &readIndex, 1,
                       pb, pb, blockSize, 1, blockSize);

                                                              
  px = pb;

                                                           
  pScratchOut = pScr2;

  blkCnt = blockSize;

  while (blkCnt > 0U)
  {
                                                                
    *pScratchOut++ = ((q31_t) * px++ * coeff);

                                    
    blkCnt--;
  }

                                     
  tapCnt = (uint32_t) numTaps - 1U;

  while (tapCnt > 0U)
  {
                                                
                                                                           
    coeff = *pCoeffs++;

                                                                                
    readIndex = (S->stateIndex - blockSize) - *pTapDelay++;

                                 
    if (readIndex < 0)
    {
      readIndex += (int32_t) delaySize;
    }

                                                     
    py = pState;

                                                          
    arm_circularRead_q15(py, delaySize, &readIndex, 1,
                         pb, pb, blockSize, 1, blockSize);

                                                                
    px = pb;

                                                             
    pScratchOut = pScr2;

    blkCnt = blockSize;

    while (blkCnt > 0U)
    {
                                       
      *pScratchOut++ += (q31_t) * px++ * coeff;

                                      
      blkCnt--;
    }

                                        
    tapCnt--;
  }

                                                            
                                                                                    
                                
  blkCnt = blockSize;

  while (blkCnt > 0U)
  {
    *pOut++ = (q15_t) __SSAT(*pScr2++ >> 15, 16);
    blkCnt--;
  }
}

void ref_fir_sparse_q7(
        arm_fir_sparse_instance_q7 * S,
        q7_t *pSrc,
        q7_t *pDst,
        q7_t *pScratchIn,
        q31_t * pScratchOut,
        uint32_t blockSize)
{
        q7_t *pState = S->pState;                                         
  const q7_t *pCoeffs = S->pCoeffs;                                             
        q7_t *px;                                                                  
        q7_t *py = pState;                                                                      
        q7_t *pb = pScratchIn;                                                                    
        q7_t *pOut = pDst;                                                      
        int32_t *pTapDelay = S->pTapDelay;                                                                                     
        uint32_t delaySize = S->maxDelay + blockSize;                    
        uint16_t numTaps = S->numTaps;                                   
        int32_t readIndex;                                                                 
        uint32_t tapCnt, blkCnt;                                          
        q7_t coeff = *pCoeffs++;                                                       
        q31_t *pScr2 = pScratchOut;                                                                             
        q31_t in;

                                                                   
                                                                               
  arm_circularWrite_q7(py, (int32_t) delaySize, &S->stateIndex, 1, pSrc, 1,
                       blockSize);

                                     
  tapCnt = numTaps;

                                                                              
  readIndex = ((int32_t) S->stateIndex - (int32_t) blockSize) - *pTapDelay++;

                               
  if (readIndex < 0)
  {
    readIndex += (int32_t) delaySize;
  }

                                                   
  py = pState;

                                                        
  arm_circularRead_q7(py, (int32_t) delaySize, &readIndex, 1, pb, pb,
                      (int32_t) blockSize, 1, blockSize);

                                                              
  px = pb;

                                                           
  pScratchOut = pScr2;

                               
  blkCnt = blockSize;

  while (blkCnt > 0U)
  {
                                                                
    *pScratchOut++ = ((q31_t) * px++ * coeff);

                                    
    blkCnt--;
  }

                                     
  tapCnt = (uint32_t) numTaps - 1U;

  while (tapCnt > 0U)
  {
                                                
                                                                           
    coeff = *pCoeffs++;

                                                                                
    readIndex = ((int32_t) S->stateIndex - (int32_t) blockSize) - *pTapDelay++;

                                 
    if (readIndex < 0)
    {
      readIndex += (int32_t) delaySize;
    }

                                                     
    py = pState;

                                                          
    arm_circularRead_q7(py, (int32_t) delaySize, &readIndex, 1, pb, pb,
                        (int32_t) blockSize, 1, blockSize);

                                                                
    px = pb;

                                                             
    pScratchOut = pScr2;

                                 
    blkCnt = blockSize;

    while (blkCnt > 0U)
    {
                                       
      in = *pScratchOut + ((q31_t) * px++ * coeff);
      *pScratchOut++ = in;

                                      
      blkCnt--;
    }

                                        
    tapCnt--;
  }

                                                            
                                                                                    
                                
  blkCnt = blockSize;

  while (blkCnt > 0U)
  {
    *pOut++ = (q7_t) __SSAT(*pScr2++ >> 7, 8);

                                              
    blkCnt--;
  }
}

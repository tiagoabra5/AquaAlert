#include "ref.h"

void ref_biquad_cascade_df2T_f32(
	const arm_biquad_cascade_df2T_instance_f32 * S,
	float32_t * pSrc,
	float32_t * pDst,
	uint32_t blockSize)
{
        float32_t *pIn = pSrc;                                                         
        float32_t *pOut = pDst;                                                        
        float32_t *pState = S->pState;                                                 
  const float32_t *pCoeffs = S->pCoeffs;                                               
        float32_t acc;                                                                 
        float32_t b0, b1, b2, a1, a2;                                                  
        float32_t Xn;                                                                  
        float32_t d1, d2;                                                              
        uint32_t sample, stage = S->numStages;                                         

   do
   {
                                    
      b0 = *pCoeffs++;
      b1 = *pCoeffs++;
      b2 = *pCoeffs++;
      a1 = *pCoeffs++;
      a2 = *pCoeffs++;

                                   
      d1 = pState[0];
      d2 = pState[1];

      sample = blockSize;

      while (sample > 0U)
      {
                             
         Xn = *pIn++;

                                    
         acc = (b0 * Xn) + d1;

                                                                             
         *pOut++ = acc;

                                                                               
                                              
         d1 = (b1 * Xn + a1 * acc) + d2;

                                         
         d2 = (b2 * Xn) + (a2 * acc);

                                         
         sample--;
      }

                                                                       
      *pState++ = d1;
      *pState++ = d2;

                                                                            
      pIn = pDst;

                                           
      pOut = pDst;

                                      
      stage--;

   } while (stage > 0U);
}


void ref_biquad_cascade_stereo_df2T_f32(
	const arm_biquad_cascade_stereo_df2T_instance_f32 * S,
	      float32_t * pSrc,
	      float32_t * pDst,
	      uint32_t blockSize)
{
        float32_t *pIn = pSrc;                                                         
        float32_t *pOut = pDst;                                                        
        float32_t *pState = S->pState;                                                 
  const float32_t *pCoeffs = S->pCoeffs;                                               
        float32_t acc1a, acc1b;                                                        
        float32_t b0, b1, b2, a1, a2;                                                  
        float32_t Xn1a, Xn1b;                                                          
        float32_t d1a, d2a, d1b, d2b;                                                  
        uint32_t sample, stage = S->numStages;                                         

    do
    {
                                      
        b0 = *pCoeffs++;
        b1 = *pCoeffs++;
        b2 = *pCoeffs++;
        a1 = *pCoeffs++;
        a2 = *pCoeffs++;

                                     
        d1a = pState[0];
        d2a = pState[1];
        d1b = pState[2];
        d2b = pState[3];

        sample = blockSize;

        while (sample > 0U)
        {
                                
            Xn1a = *pIn++;            
            Xn1b = *pIn++;            

                                       
            acc1a = (b0 * Xn1a) + d1a;
            acc1b = (b0 * Xn1b) + d1b;

                                                                                
            *pOut++ = acc1a;
            *pOut++ = acc1b;

                                                                                  
                                                 
            d1a = ((b1 * Xn1a) + (a1 * acc1a)) + d2a;
            d1b = ((b1 * Xn1b) + (a1 * acc1b)) + d2b;

                                            
            d2a = (b2 * Xn1a) + (a2 * acc1a);
            d2b = (b2 * Xn1b) + (a2 * acc1b);

                                            
            sample--;
        }

                                                                         
        *pState++ = d1a;
        *pState++ = d2a;
        *pState++ = d1b;
        *pState++ = d2b;

                                                                              
        pIn = pDst;

                                             
        pOut = pDst;

                                        
        stage--;

    } while (stage > 0U);
	
}

void ref_biquad_cascade_df2T_f64(
	const arm_biquad_cascade_df2T_instance_f64 * S,
	float64_t * pSrc,
	float64_t * pDst,
	uint32_t blockSize)
{
   float64_t *pIn = pSrc;                                                         
   float64_t *pOut = pDst;                                                        
   float64_t *pState = S->pState;                                                 
   float64_t *pCoeffs = S->pCoeffs;                                               
   float64_t acc;                                                                 
   float64_t b0, b1, b2, a1, a2;                                                  
   float64_t Xn;                                                                  
   float64_t d1, d2;                                                              
   uint32_t sample, stage = S->numStages;                                         

   do
   {
                                    
      b0 = *pCoeffs++;
      b1 = *pCoeffs++;
      b2 = *pCoeffs++;
      a1 = *pCoeffs++;
      a2 = *pCoeffs++;

                                   
      d1 = pState[0];
      d2 = pState[1];

      sample = blockSize;

      while (sample > 0U)
      {
                             
         Xn = *pIn++;

                                    
         acc = (b0 * Xn) + d1;

                                                                             
         *pOut++ = acc;

                                                                               
                                              
         d1 = (b1 * Xn + a1 * acc) + d2;

                                         
         d2 = (b2 * Xn) + (a2 * acc);

                                         
         sample--;
      }

                                                                       
      *pState++ = d1;
      *pState++ = d2;

                                                                            
      pIn = pDst;

                                           
      pOut = pDst;

                                      
      stage--;

   } while (stage > 0U);
}

void ref_biquad_cascade_df1_f32(
  const arm_biquad_casd_df1_inst_f32 * S,
        float32_t * pSrc,
        float32_t * pDst,
        uint32_t blockSize)
{
        float32_t *pIn = pSrc;                                                         
        float32_t *pOut = pDst;                                                        
        float32_t *pState = S->pState;                                                 
  const float32_t *pCoeffs = S->pCoeffs;                                               
        float32_t acc;                                                                 
        float32_t b0, b1, b2, a1, a2;                                                  
        float32_t Xn1, Xn2, Yn1, Yn2;                                                  
        float32_t Xn;                                                                  
        uint32_t sample, stage = S->numStages;                                         

  do
  {
                                  
    b0 = *pCoeffs++;
    b1 = *pCoeffs++;
    b2 = *pCoeffs++;
    a1 = *pCoeffs++;
    a2 = *pCoeffs++;

                                   
    Xn1 = pState[0];
    Xn2 = pState[1];
    Yn1 = pState[2];
    Yn2 = pState[3];

                                                                              
                                                                                            
       

    sample = blockSize;

    while (sample > 0U)
    {
                          
      Xn = *pIn++;

                                                                                    
      acc = (b0 * Xn) + (b1 * Xn1) + (b2 * Xn2) + (a1 * Yn1) + (a2 * Yn2);

                                                                          
      *pOut++ = acc;

                                                                            
                                               
                        
                        
                        
                       
      Xn2 = Xn1;
      Xn1 = Xn;
      Yn2 = Yn1;
      Yn1 = acc;

                                      
      sample--;
    }

                                                                       
    *pState++ = Xn1;
    *pState++ = Xn2;
    *pState++ = Yn1;
    *pState++ = Yn2;

                                                                           
                                                                    
    pIn = pDst;

                                  
    pOut = pDst;

                                    
    stage--;

  } while (stage > 0U);
}

void ref_biquad_cas_df1_32x64_q31(
  const arm_biquad_cas_df1_32x64_ins_q31 * S,
        q31_t * pSrc,
        q31_t * pDst,
        uint32_t blockSize)
{
        q31_t *pIn = pSrc;                                                                    
        q31_t *pOut = pDst;                                                                   
        q63_t *pState = S->pState;                                                            
  const q31_t *pCoeffs = S->pCoeffs;                                                          
        q63_t acc;                                                                            
        q31_t Xn1, Xn2;                                                                       
        q63_t Yn1, Yn2;                                                                       
        q31_t b0, b1, b2, a1, a2;                                                             
        q31_t Xn;                                                                             
        int32_t shift = (int32_t) S->postShift + 1;                                             
        uint32_t sample, stage = S->numStages;                                                  
        q31_t acc_l, acc_h;                                                                   
        uint32_t uShift = ((uint32_t) S->postShift + 1U);
        uint32_t lShift = 32U - uShift;                                                         

  do
  {
                                  
    b0 = *pCoeffs++;
    b1 = *pCoeffs++;
    b2 = *pCoeffs++;
    a1 = *pCoeffs++;
    a2 = *pCoeffs++;

                                  
    Xn1 = pState[0];
    Xn2 = pState[1];
    Yn1 = pState[2];
    Yn2 = pState[3];

    sample = blockSize;

    while (sample > 0U)
    {
                          
      Xn = *pIn++;

                                                                                    
      acc = (q63_t)Xn*b0 + (q63_t)Xn1*b1 + (q63_t)Xn2*b2;
                               
      acc += mult32x64(Yn1, a1);
                               
      acc += mult32x64(Yn2, a2);

                                                                            
      Xn2 = Xn1;
      Xn1 = Xn;
      Yn2 = Yn1;

                                                                    
      Yn1 = acc << shift;

                                  
      acc_l = acc & 0xffffffff;

                                  
      acc_h = (acc >> 32) & 0xffffffff;

                                                                   
      acc_h = (uint32_t) acc_l >> lShift | acc_h << uShift;

                                                                      
      *pOut++ = acc_h;

                                      
      sample--;
    }

                                                                        
    pIn = pDst;

                                                     
    pOut = pDst;

                                                                       
    *pState++ = (q63_t) Xn1;
    *pState++ = (q63_t) Xn2;
    *pState++ = Yn1;
    *pState++ = Yn2;

  } while (--stage);
}

void ref_biquad_cascade_df1_q31(
  const arm_biquad_casd_df1_inst_q31 * S,
  q31_t * pSrc,
  q31_t * pDst,
  uint32_t blockSize)
{	
        q63_t acc;                                                                         
        uint32_t uShift = ((uint32_t) S->postShift + 1U);
        uint32_t lShift = 32U - uShift;                                                        
        q31_t *pIn = pSrc;                                                                 
        q31_t *pOut = pDst;                                                                
        q31_t *pState = S->pState;                                                         
  const q31_t *pCoeffs = S->pCoeffs;                                                       
        q31_t Xn1, Xn2, Yn1, Yn2;                                                          
        q31_t b0, b1, b2, a1, a2;                                                          
        q31_t Xn;                                                                          
        uint32_t sample, stage = S->numStages;                                             

  do
  {
                                  
    b0 = *pCoeffs++;
    b1 = *pCoeffs++;
    b2 = *pCoeffs++;
    a1 = *pCoeffs++;
    a2 = *pCoeffs++;

                                  
    Xn1 = pState[0];
    Xn2 = pState[1];
    Yn1 = pState[2];
    Yn2 = pState[3];

                                                                               
                                                                                           
       

    sample = blockSize;

    while (sample > 0U)
    {
                          
      Xn = *pIn++;

                                                                                    
                            
      acc = (q63_t) b0 *Xn;

                               
      acc += (q63_t) b1 *Xn1;
                                 
      acc += (q63_t) b2 *Xn2;
                               
      acc += (q63_t) a1 *Yn1;
                               
      acc += (q63_t) a2 *Yn2;

                                            
      acc = acc >> lShift;

                                                                            
                                             
                        
                        
                        
                        
      Xn2 = Xn1;
      Xn1 = Xn;
      Yn2 = Yn1;
      Yn1 = (q31_t) acc;

                                                       
      *pOut++ = (q31_t) acc;

                                      
      sample--;
    }

                                                                           
                                                                
    pIn = pDst;

                                      
    pOut = pDst;

                                                                       
    *pState++ = Xn1;
    *pState++ = Xn2;
    *pState++ = Yn1;
    *pState++ = Yn2;

  } while (--stage);
}


void ref_biquad_cascade_df1_fast_q31(
  const arm_biquad_casd_df1_inst_q31 * S,
  q31_t * pSrc,
  q31_t * pDst,
  uint32_t blockSize)
{
        q31_t acc = 0;                                                                     
        q31_t Xn1, Xn2, Yn1, Yn2;                                                          
        q31_t b0, b1, b2, a1, a2;                                                          
        q31_t *pIn = pSrc;                                                                 
        q31_t *pOut = pDst;                                                                
        q31_t *pState = S->pState;                                                         
  const q31_t *pCoeffs = S->pCoeffs;                                                       
        q31_t Xn;                                                                          
        int32_t shift = (int32_t) S->postShift + 1;                                            
        uint32_t sample, stage = S->numStages;                                                 

  do
  {
                                  
    b0 = *pCoeffs++;
    b1 = *pCoeffs++;
    b2 = *pCoeffs++;
    a1 = *pCoeffs++;
    a2 = *pCoeffs++;

                                  
    Xn1 = pState[0];
    Xn2 = pState[1];
    Yn1 = pState[2];
    Yn2 = pState[3];
		
    sample = blockSize;

   while (sample > 0U)
   {
                          
      Xn = *pIn++;

                                                                                        
      mult_32x32_keep32_R(acc, b0, Xn);
      multAcc_32x32_keep32_R(acc, b1, Xn1);
      multAcc_32x32_keep32_R(acc, b2, Xn2);
      multAcc_32x32_keep32_R(acc, a1, Yn1);
      multAcc_32x32_keep32_R(acc, a2, Yn2);

                                            
      acc <<= shift;

                                                                            
      Xn2 = Xn1;
      Xn1 = Xn;
      Yn2 = Yn1;
      Yn1 = acc;

                                                       
      *pOut++ = acc;

                                      
      sample--;
   }

                                                                           
                                                                
    pIn = pDst;

                                      
    pOut = pDst;

                                                                       
    *pState++ = Xn1;
    *pState++ = Xn2;
    *pState++ = Yn1;
    *pState++ = Yn2;

  } while (--stage);
}

void ref_biquad_cascade_df1_fast_q15(
  const arm_biquad_casd_df1_inst_q15 * S,
  q15_t * pSrc,
  q15_t * pDst,
  uint32_t blockSize)
{
	      q15_t *pIn = pSrc;                             			                                               
	      q15_t *pOut = pDst;                            			                                               
	      q15_t b0, b1, b2, a1, a2;                      			                                        
	      q15_t Xn1, Xn2, Yn1, Yn2;                      			                                        
	      q15_t Xn;                                      			                                        
	      q31_t acc;                                     			                                               
	      int32_t shift = (15 - (int32_t) S->postShift); 			                                               
	      q15_t *pState = S->pState;                     			                                               
  const q15_t *pCoeffs = S->pCoeffs;                   			                                               
        uint32_t sample, stage = (uint32_t) S->numStages;                                                     

  do
  {
                                  
    b0 = *pCoeffs++;
    pCoeffs++;                           
    b1 = *pCoeffs++;
    b2 = *pCoeffs++;
    a1 = *pCoeffs++;
    a2 = *pCoeffs++;

                                  
    Xn1 = pState[0];
    Xn2 = pState[1];
    Yn1 = pState[2];
    Yn2 = pState[3];

    sample = blockSize;

    while (sample > 0U)
    {
                          
      Xn = *pIn++;

                                                                                    
      acc = (q31_t)b0*Xn + (q31_t)b1*Xn1 + (q31_t)b2*Xn2 + (q31_t)a1*Yn1 + (q31_t)a2*Yn2;

                                            
      acc = ref_sat_q15(acc >> shift);

                                                                            
      Xn2 = Xn1;
      Xn1 = Xn;
      Yn2 = Yn1;
      Yn1 = (q15_t) acc;

                                                       
      *pOut++ = (q15_t) acc;

                                      
      sample--;
    }

                                                                           
                                                                
    pIn = pDst;

                                      
    pOut = pDst;

                                                                       
    *pState++ = Xn1;
    *pState++ = Xn2;
    *pState++ = Yn1;
    *pState++ = Yn2;

  } while (--stage);
}

void ref_biquad_cascade_df1_q15(
  const arm_biquad_casd_df1_inst_q15 * S,
  q15_t * pSrc,
  q15_t * pDst,
  uint32_t blockSize)
{
	      q15_t *pIn = pSrc;                             			                                               
	      q15_t *pOut = pDst;                            			                                               
	      q15_t b0, b1, b2, a1, a2;                      			                                        
	      q15_t Xn1, Xn2, Yn1, Yn2;                      			                                        
	      q15_t Xn;                                      			                                        
	      q63_t acc;                                     			                                               
	      int32_t shift = (15 - (int32_t) S->postShift); 			                                               
	      q15_t *pState = S->pState;                     			                                               
  const q15_t *pCoeffs = S->pCoeffs;                   			                                               
        uint32_t sample, stage = (uint32_t) S->numStages;                                                     

  do
  {
                                  
    b0 = *pCoeffs++;
    pCoeffs++;                           
    b1 = *pCoeffs++;
    b2 = *pCoeffs++;
    a1 = *pCoeffs++;
    a2 = *pCoeffs++;

                                  
    Xn1 = pState[0];
    Xn2 = pState[1];
    Yn1 = pState[2];
    Yn2 = pState[3];

    sample = blockSize;

    while (sample > 0U)
    {
                          
      Xn = *pIn++;

                                                                                    
      acc = (q31_t)b0*Xn + (q31_t)b1*Xn1 + (q31_t)b2*Xn2 + (q31_t)a1*Yn1 + (q31_t)a2*Yn2;

                                            
      acc = ref_sat_q15(acc >> shift);

                                                                            
      Xn2 = Xn1;
      Xn1 = Xn;
      Yn2 = Yn1;
      Yn1 = (q15_t) acc;

                                                       
      *pOut++ = (q15_t) acc;

                                      
      sample--;
    }

                                                                           
                                                                
    pIn = pDst;

                                      
    pOut = pDst;

                                                                       
    *pState++ = Xn1;
    *pState++ = Xn2;
    *pState++ = Yn1;
    *pState++ = Yn2;

  } while (--stage);
}

#include "ref.h"


;      
                                             
                                                                                           
                                                         
                                                                
                   
   
void ref_arm_bitreversal_32(uint32_t *pSrc, uint32_t bitRevLen, uint32_t *pBitRevTab)
{
	uint32_t a,b,i,tmp;
	
	for(i=0; i<bitRevLen; i++) 
	{
		 a = pBitRevTab[2*i];
		 b = pBitRevTab[2*i + 1];

	      
		 tmp = pSrc[a];
		 pSrc[a] = pSrc[b];
		 pSrc[b] = tmp;

	         
		 tmp = pSrc[a+1];
		 pSrc[a+1] = pSrc[b+1];
		 pSrc[b+1] = tmp;
	}
}

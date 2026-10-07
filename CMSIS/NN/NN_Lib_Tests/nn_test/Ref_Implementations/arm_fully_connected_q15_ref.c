/*
 * Copyright (C) 2010-2018 Arm Limited or its affiliates. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "ref_functions.h"

void arm_fully_connected_q15_ref(const q15_t * pV,                      
                                 const q15_t * pM,                      
                                 const uint16_t dim_vec,                           
                                 const uint16_t num_of_rows,                  
                                 const uint16_t bias_shift,                                 
                                 const uint16_t out_shift,                                     
                                 const q15_t * bias, q15_t * pOut,                   
                                 q15_t * vec_buffer)
{
    for (int i = 0; i < num_of_rows; i++)
    {
#ifndef ARM_NN_TRUNCATE
        int       ip_out = (bias[i] << bias_shift) + (0x1 << (out_shift - 1));
#else
        int       ip_out = bias[i] << bias_shift;
#endif
        for (int j = 0; j < dim_vec; j++)
        {
            ip_out += pV[j] * pM[i * dim_vec + j];
        }
        pOut[i] = (q15_t) __SSAT((ip_out >> out_shift), 16);
    }
}

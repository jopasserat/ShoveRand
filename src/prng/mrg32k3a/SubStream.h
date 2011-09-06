/*
 *  SubStream.h
 *  
 *
 * WATCH OUT! Be sure to include this file AFTER Stream.cu so that utils.h
 * definitions are available. It's the only way to have constant memory variables
 * visible in the whole application without being redeclared twice (distinct 
 * constant memory locations would be created otherwise...).
 *
 *  Created by Jonathan PASSERAT-PALMBACH on 4/7/11.
 *  Copyright 2011 ISIMA/LIMOS. All rights reserved.
 *
 */

#ifndef SUBSTREAM_H
#define SUBSTREAM_H


#include <utils.h>

namespace shoverand {
	namespace prng {
		namespace MRG32k3a {
			
			
			class SubStream {
				
			private:
				typedef ::MRG32k3a::ParameterizedStatusMRG32k3a ParameterizedStatus;
				
			public:
				/** Current sub-stream state */
				double Cg_[6];
				
				/** Starting state of the current sub-stream */
				double Bg_[6];
				
				ParameterizedStatus* params_;
				
			public:

				
				/** Constructor based on the Streams array. 
					Calls init with the array as parameter.
					\param streams Stream array to init the current SubStream
				*/
				__device__ 
				SubStream(ParameterizedStatus* param)
					:params_(param)
				{
					this->init(params_->allStreams_);
				}
				
				
				/** Init through RngStream
				\param s Stream used as a base for current sub-stream
				*/
				__device__
				void init(Stream* allStreams) {
					
					// get stream corresponding to block id
					Stream* stream  = allStreams + (gridDim.x * blockIdx.y + blockIdx.x);
					
					// copy stream state in current SubStream
					for (unsigned i = 0; i < 6; ++i) {
						Cg_[i] = stream->getCg(i);
						Bg_[i] = stream->getBg(i);
					}
					
					// advance to the SubStream corresponding to thread id IN THE BLOCK
					this->jumpAhead(blockDim.y * blockDim.x * threadIdx.z + blockDim.x * threadIdx.y + threadIdx.x);
				}
				
				
				/** Draw next number */
				__host__ __device__
				double next() {
					
					long k;
					double p1, p2, u;
					
					// Component 1
					p1 = a12 * Cg_[1] - a13n * Cg_[0];
					k = static_cast<long> (p1 / m1);
					p1 -= k * m1;
					
					if (p1 < 0.0)  p1 += m1;
					
					Cg_[0] = Cg_[1]; Cg_[1] = Cg_[2]; Cg_[2] = p1;
					
					// Component 2
					p2 = a21 * Cg_[5] - a23n * Cg_[3];
					k = static_cast<long> (p2 / m2);
					p2 -= k * m2;
					
					if (p2 < 0.0) p2 += m2;
					
					Cg_[3] = Cg_[4]; Cg_[4] = Cg_[5]; Cg_[5] = p2;
					
					// Combination
					u = ((p1 > p2) ? (p1 - p2) * norm : (p1 - p2 + m1) * norm);
					
					return u;
				}
				
			
			private:
				
				/** Jump n SubStreams ahead in current stream
				\param pow Number of sub-streams to jump
				*/
				__device__ void jumpAhead(long pow) {
					
					/** A1^N temporary matrix */
					double A1_pN[3][3] = {
						{       0.0,        1.0,       0.0 },
						{       0.0,        0.0,       1.0 },
						{ -810728.0,  1403580.0,       0.0 }
					};
					
					/** A2^N temporary matrix */
					double A2_pN[3][3] = {
						{        0.0,        1.0,       0.0 },
						{        0.0,        0.0,       1.0 },
						{ -1370589.0,        0.0,  527612.0 }
					};
					

					shoverand::utils::Math::MatPowModM(params_->A1p76, A1_pN, m1, pow);  // (A1^(2^76))^n mod m
					shoverand::utils::Math::MatPowModM(params_->A2p76, A2_pN, m2, pow);  // (A2^(2^76))^n mod m
					
					shoverand::utils::Math::MatVecModM(A1_pN, Bg_, Bg_, m1);
					shoverand::utils::Math::MatVecModM(A2_pN, &Bg_[3], &Bg_[3], m2);
					
					for (unsigned i = 0; i < 6; ++i) {
						Cg_[i] = Bg_[i];
					}
				}
				
			};
			
		} // end of namespace MRG32k3a
	} // end of namespace prng
} // end of namespace shoverand

#endif // SUBSTREAM_H

#include "ParameterizedStatus.h"

#include <cuda.h>
#include <cutil.h>
#include <cutil_inline_runtime.h>


// TODO is there a way to declare const arrays as extern?
#include "Stream.cu"

__host__
void ParameterizedStatus<MRG32k3a::MRG32k3a>::setUp (unsigned short blocksNumber) {

			// create streams on the host and initiate them correctly
			// THIS MUST BE DONE SEQUENTIALLY since current state relies on previsou ones
			allStreams_host = new MRG32k3a::Stream [blocksNumber];
	
			// allocate memory for streams on the device
			cutilSafeCall( cudaMalloc( (void**)&allStreams_, sizeof(MRG32k3a::Stream) * blocksNumber) );
			// transfer Streams
			cutilSafeCall( cudaMemcpy( allStreams_,
												allStreams_host,
												sizeof(MRG32k3a::Stream) * blocksNumber,
												cudaMemcpyHostToDevice) );

			// allocate and copy from host to device matrices
			cutilSafeCall( cudaMalloc((void**) &A1p76, sizeof(double) * 9) );
			cutilSafeCall( cudaMemcpy(A1p76, MRG32k3a::A1p76_host, sizeof(double) * 9, cudaMemcpyHostToDevice ) );
			cutilSafeCall( cudaMalloc((void**) &A2p76, sizeof(double) * 9) );
			cutilSafeCall( cudaMemcpy(A2p76, MRG32k3a::A2p76_host, sizeof(double) * 9, cudaMemcpyHostToDevice ) );
			cutilSafeCall( cudaMalloc((void**) &A1p127, sizeof(double) * 9) );
			cutilSafeCall( cudaMemcpy(A1p127, MRG32k3a::A1p127_host, sizeof(double) * 9, cudaMemcpyHostToDevice ) );
			cutilSafeCall( cudaMalloc((void**) &A2p127, sizeof(double) * 9) );
			cutilSafeCall( cudaMemcpy(A2p127, MRG32k3a::A2p127_host, sizeof(double) * 9, cudaMemcpyHostToDevice ) );
			
			cutilSafeCall( cudaMalloc((void**) &A1_pows, sizeof(double) * 11 * 3 * 3) );
			cutilSafeCall( cudaMemcpy(A1_pows, MRG32k3a::A1_pows_host, sizeof(double) * 11 * 3 * 3, cudaMemcpyHostToDevice ) );
			cutilSafeCall( cudaMalloc((void**) &A2_pows, sizeof(double) * 11 * 3 * 3) );
			cutilSafeCall( cudaMemcpy(A2_pows, MRG32k3a::A2_pows_host, sizeof(double) * 11 * 3 * 3, cudaMemcpyHostToDevice ) );
}

__host__
void ParameterizedStatus<MRG32k3a::MRG32k3a>::release() {

	cutilSafeCall( cudaFree(A2_pows) );
	cutilSafeCall( cudaFree(A1_pows) );
	cutilSafeCall( cudaFree(A2p127) );
	cutilSafeCall( cudaFree(A1p127) );
	cutilSafeCall( cudaFree(A2p76) );
	cutilSafeCall( cudaFree(A1p76) );
	cutilSafeCall( cudaFree(allStreams_) );
	
	delete [] allStreams_host;
}
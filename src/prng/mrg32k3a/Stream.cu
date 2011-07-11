/***********************************************************************\
 * \file Created by jH@CKtheRipper, 04/04/11 
 *       Stream and Substream classes declarations
 *       Inspired from Pierre L'Ecuyer's original RngStream.h
 * \author jH@CKtheRipper
 \***********************************************************************/


#include <cuda.h>
#include <cutil.h>
#include <cutil_inline_runtime.h>

#include <Stream.h>
#include <utils.h>

#include <iostream> // debug purpose


/******** Host equivalents to device constants *********/
const double A1p0_host[3][3] = {
   {       0.0,        1.0,       0.0 },
   {       0.0,        0.0,       1.0 },
   { -810728.0,  1403580.0,       0.0 }
};

const double A2p0_host[3][3] = {
   {        0.0,        1.0,       0.0 },
   {        0.0,        0.0,       1.0 },
   { -1370589.0,        0.0,  527612.0 }
};

const double A1p76_host[3][3] = {
   {      82758667.0, 1871391091.0, 4127413238.0 },
   {    3672831523.0,   69195019.0, 1871391091.0 },
   {    3672091415.0, 3528743235.0,   69195019.0 }
};

const double A2p76_host[3][3] = {
   {    1511326704.0, 3759209742.0, 1610795712.0 },
   {    4292754251.0, 1511326704.0, 3889917532.0 },
   {    3859662829.0, 4292754251.0, 3708466080.0 }
};

const double A1p127_host[3][3] = {
   {    2427906178.0, 3580155704.0,  949770784.0 },
   {     226153695.0, 1230515664.0, 3580155704.0 },
   {    1988835001.0,  986791581.0, 1230515664.0 }
};

const double A2p127_host[3][3] = {
   {    1464411153.0,  277697599.0, 1610723613.0 },
   {      32183930.0, 1464411153.0, 1022607788.0 },
   {    2824425944.0,   32183930.0, 2093834863.0 }
};

const double A1_pows_host [11][3][3] = { 
   {  { 1.0, 0.0, 0.0 }, { 0.0, 1.0, 0.0 }, { 0.0, 0.0, 1.0 } },
   {  { 82758667.0, 1871391091.0, 4127413238.0 }, { 3672831523.0,   69195019.0, 1871391091.0 }, { 3672091415.0, 3528743235.0, 69195019.0 } },
   {  { 3.36137e+09, 2.3293e+09, 9.96519e+07 } , { 2.00867e+09, 2.93176e+09, 2.3293e+09 } , { 1.11353e+09, 2.3741e+09, 2.93176e+09 } },
   {  { 2.13871e+09, 3.21018e+09, 2.30172e+08 } , { 1.01179e+09, 3.53602e+09, 3.21018e+09 } , { 2.84722e+09, 6.20673e+08, 3.53602e+09 } },
   {  { 1.83159e+09, 1.58826e+09, 1.31433e+09 } , { 2.38599e+09, 2.50808e+09, 1.58826e+09 } , { 1.78762e+09, 6.61437e+08, 2.50808e+09 } },
   {  { 2.04282e+09, 4.01645e+08, 4.01041e+09 } , { 3.99806e+09, 2.10605e+09, 4.01645e+08 } , { 2.29685e+09, 5.3118e+08, 2.10605e+09 } },
   {  { 2.1845e+09, 2.70304e+09, 2.30761e+09 } , { 1.51704e+09, 2.8237e+09, 2.70304e+09 } , { 1.78608e+09, 6.1756e+07, 2.8237e+09 } },
   {  { 3.24248e+09, 4.21073e+09, 5.20437e+08 } , { 6.68035e+07, 3.70726e+09, 4.21073e+09 } , { 1.46074e+09, 2.92168e+09, 3.70726e+09 } },
   {  { 2.32605e+09, 4.18359e+09, 4.04901e+09 } , { 2.60453e+09, 1.45391e+09, 4.18359e+09 } , { 2.31193e+09, 1.80536e+09, 1.45391e+09 } },
   {  { 4.14073e+09, 7.52526e+08, 2.82814e+09 } , { 1.99111e+09, 2.09751e+09, 7.52526e+08 } , { 1.67327e+09, 1.60257e+09, 2.09751e+09 } },
   {  { 1.96542e+09, 3.22182e+09, 2.04071e+09 } , { 1.26818e+09, 1.82502e+09, 3.22182e+09 } , { 2.88049e+09, 1.51013e+08, 1.82502e+09 } }
};

const double A2_pows_host [11][3][3] = {
   {  { 1.0, 0.0, 0.0 }, { 0.0, 1.0, 0.0 }, { 0.0, 0.0, 1.0 } },
   {  { 1.51133e+09, 3.75921e+09, 1.6108e+09 } , { 4.29275e+09, 1.51133e+09, 3.88992e+09 } , { 3.85966e+09, 4.29275e+09, 3.70847e+09 }},
   {  { 9.72103e+08, 9.64808e+08, 8.78036e+08 } , { 4.24855e+09, 9.72103e+08, 1.92663e+09 } , { 1.44863e+09, 4.24855e+09, 3.19611e+09 } },
   {  { 9.07239e+08, 2.92629e+09, 2.86585e+09 } , { 8.40689e+08, 9.07239e+08, 1.2492e+09 } , { 4.27877e+09, 8.40689e+08, 3.3311e+09 } },
   {  { 3.49738e+09, 3.17425e+09, 3.18251e+09 } , { 3.86482e+09, 3.49738e+09, 3.0384e+09 } , { 2.54688e+09, 3.86482e+09, 2.98021e+09 } },
   {  { 7.84581e+08, 2.65342e+09, 3.8428e+08 } , { 3.46234e+09, 7.84581e+08, 1.92303e+09 } , { 3.69099e+07, 3.46234e+09, 5.64222e+08 } },
   {  { 1.40581e+09, 4.17421e+09, 2.38421e+09 } , { 1.1278e+08, 1.40581e+09, 3.41212e+09 } , { 3.92527e+09, 1.1278e+08, 1.36504e+09 } },
   {  { 2.61947e+09, 3.13258e+06, 8.04703e+08 } , { 3.63047e+09, 2.61947e+09, 2.64523e+09 } , { 3.21677e+09, 3.63047e+09, 4.07219e+09 } },
   {  { 1.77634e+09, 1.18994e+09, 4.09576e+09 } , { 3.8136e+09, 1.77634e+09, 7.89476e+08 } , { 4.1197e+09, 3.8136e+09, 2.14536e+09 } },
   {  { 3.76949e+09, 1.0387e+09, 2.72404e+09 } , { 2.82675e+08, 3.76949e+09, 8.45493e+07 } , { 3.83672e+09, 2.82675e+08, 1.4121e+09 } },
   {  { 3.41941e+08, 2.19094e+09, 3.28734e+09 } , { 4.80943e+08, 3.41941e+08, 2.6028e+09 } , { 8.53742e+08, 4.80943e+08, 4.22841e+09 } }
};



// static members instanciation
MRG32k3a::Stream* MRG32k3a::Stream::allStreams_host;
MRG32k3a::Stream* MRG32k3a::Stream::allStreams;

namespace MRG32k3a {
   
   //*************************************************************************
   // Public members of the Stream class start here
   
   
   /**
    The default seed of the package; will be the seed of the first
    declared RngStream, unless SetPackageSeed is called.
    */
   double Stream::nextSeed__[6] =
   {
      12345.0, 12345.0, 12345.0, 12345.0, 12345.0, 12345.0
   };
   
   
   /**
    * Stream constructor
    */
   __host__
   Stream::Stream () {
      
      /* Information on a stream. The arrays {Cg, Bg, Ig} contain respecively 
			the current state of the stream, the starting state of the current 
			SubStream, and the starting state of the stream. nextSeed__
			will be the seed of the next declared RngStream. */
      
      for (int i = 0; i < 6; ++i) {
         Bg_[i] = Cg_[i] = Ig_[i] = nextSeed__[i];
      } 

      MatVecModM (A1p127_host, nextSeed__, nextSeed__, m1);
      MatVecModM (A2p127_host, &nextSeed__[3], &nextSeed__[3], m2);
   }
   
   /** Stream constants initializations */
   __host__ 
   void Stream::init(unsigned int blocksNumber) {
   
//       // copies to constant memory
// //       cutilSafeCall( cudaMemcpyToSymbol(A1p0, A1p0_host, sizeof(double) * 9) );
// //       cutilSafeCall( cudaMemcpyToSymbol(A2p0, A2p0_host, sizeof(double) * 9) );
// //       cutilSafeCall( cudaMemcpyToSymbol(A1p76, A1p76_host, sizeof(double) * 9) );
// //       cutilSafeCall( cudaMemcpyToSymbol(A2p76, A2p76_host, sizeof(double) * 9) );
//          
//          cutilSafeCall( cudaMalloc(&A2p76, sizeof(double) * 9) );
//          cutilSafeCall( cudaMemcpy(A2p76, A2p76_host, sizeof(double) * 9, cudaMemcpyHostToDevice ) );
//          cutilSafeCall( cudaMemcpyToSymbol(A2p76_adress, &A2p76, sizeof(double**)));
// 
// //       cutilSafeCall( cudaMemcpyToSymbol(A1p127, A1p127_host, sizeof(double) * 9) );
// //       cutilSafeCall( cudaMemcpyToSymbol(A2p127, A2p127_host, sizeof(double) * 9) );
// //       
// //       cutilSafeCall( cudaMemcpyToSymbol(A1_pows, A1_pows_host, sizeof(double) * 11 * 3 * 3) );
// //       cutilSafeCall( cudaMemcpyToSymbol(A2_pows, A2_pows_host, sizeof(double) * 11 * 3 * 3) );
// 
//          cutilSafeCall( cudaMalloc(&A2_pows, sizeof(double) * 11 * 3 * 3) );
//          cutilSafeCall( cudaMemcpy(A2_pows, A2_pows_host, sizeof(double) * 11 * 3 * 3, cudaMemcpyHostToDevice ) );
//          cutilSafeCall( cudaMemcpyToSymbol(A2_pows_adress, &A2_pows_adress, sizeof(double***)));
// 
//       // create streams on the host
//       Stream::allStreams_host = new Stream[blocksNumber];
//       
//       // allocate memory for streams on the device
//       cutilSafeCall( cudaMalloc( (void**)&Stream::allStreams, sizeof(Stream) * blocksNumber) );
//       
//       // transfer Streams 
//       cutilSafeCall( cudaMemcpy( Stream::allStreams,
//                                  Stream::allStreams_host,
//                                  sizeof(Stream) * blocksNumber,
//                                  cudaMemcpyHostToDevice) );
//       
   }

      	std::ostream& operator<< (std::ostream& os, const Stream& s) {
		os << "Stream <" << &s << ">" << std::endl;

		for (unsigned i = 0; i < 6; ++i)	os << "Cg_[" << i << "] = " << s.Cg_[i] << " ";	
		os << std::endl;
		for (unsigned i = 0; i < 6; ++i)	os << "Bg_[" << i << "] = " << s.Bg_[i] << " ";	
		os << std::endl;
		for (unsigned i = 0; i < 6; ++i)	os << "Ig_[" << i << "] = " << s.Ig_[i] << " ";	
		os << std::endl;
		for (unsigned i = 0; i < 6; ++i)	os << "nextSeed__[" << i << "] = " << Stream::nextSeed__[i] << " ";	
		os << std::endl;

		return os;
	}


} // end of namespace MRG32k3a


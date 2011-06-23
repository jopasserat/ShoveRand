#ifndef MRG32K3A_PARAMETERIZED_STATUS
#define MRG32K3A_PARAMETERIZED_STATUS

namespace MRG32k3a {

   class ParameterizedStatus {
      
      public:
         MRG32k3a::Stream* allStreams_;
       	MRG32k3a::Stream* allStreams_host;
         
         double* A1p76;
         double* A2p76;
         double* A1p127;
         double* A2p127;

         double* A1_pows;
         double* A2_pows;

      
      private:
	//public:
         __host__
         void init(unsigned short blocksNumber) {
            // create streams on the host
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
            cutilSafeCall( cudaMemcpy(A1p76, A1p76_host, sizeof(double) * 9, cudaMemcpyHostToDevice ) );
            cutilSafeCall( cudaMalloc((void**) &A2p76, sizeof(double) * 9) );
            cutilSafeCall( cudaMemcpy(A2p76, A2p76_host, sizeof(double) * 9, cudaMemcpyHostToDevice ) );
            cutilSafeCall( cudaMalloc((void**) &A1p127, sizeof(double) * 9) );
            cutilSafeCall( cudaMemcpy(A1p127, A1p127_host, sizeof(double) * 9, cudaMemcpyHostToDevice ) );
            cutilSafeCall( cudaMalloc((void**) &A2p127, sizeof(double) * 9) );
            cutilSafeCall( cudaMemcpy(A2p127, A2p127_host, sizeof(double) * 9, cudaMemcpyHostToDevice ) );
            
            cutilSafeCall( cudaMalloc((void**) &A1_pows, sizeof(double) * 11 * 3 * 3) );
            cutilSafeCall( cudaMemcpy(A1_pows, A1_pows_host, sizeof(double) * 11 * 3 * 3, cudaMemcpyHostToDevice ) );
            cutilSafeCall( cudaMalloc((void**) &A2_pows, sizeof(double) * 11 * 3 * 3) );
            cutilSafeCall( cudaMemcpy(A2_pows, A2_pows_host, sizeof(double) * 11 * 3 * 3, cudaMemcpyHostToDevice ) );
         }
         
      public:
         __host__ 
         ParameterizedStatus(unsigned short blocksNumber) {
            this->init(blocksNumber);
         }
      
   };
  
  
}

#endif // MRG32K3A_PARAMETERIZED_STATUS

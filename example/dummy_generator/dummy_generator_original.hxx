#pragma once

// ---- class containing PRNG algorithm --- 

template < typename T >
class DummyGenerator
{
   private:
      T nextValue_;
      T difference_;

   public:

      __host__ __device__
      explicit DummyGenerator(T inNextValue = 0, T inDifference = 0)
       :nextValue_(inNextValue), difference_(inDifference)
       {}

      __host__ __device__
      T next() {
         T outValue = nextValue_;
         nextValue_ += difference_;
         return outValue; 
      }
};


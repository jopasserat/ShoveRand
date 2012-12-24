#pragma once

// --- Shoverand includes ----

#include <shoverand/core/SeedStatus.hxx>
#include <shoverand/core/ParameterizedStatus.hxx>

// ---- Shoverand bindings for DummyGenerator ----

template <class T>
class DummyGenerator;

template <>
struct SeedStatus<DummyGenerator > {
   float nextValue_;
};

template <>
struct ParameterizedStatus<DummyGenerator> {
   float difference_;

   __device__
   ParameterizedStatus<DummyGenerator>( float inDifference ) 
    :difference_(inDifference) {}
};

typedef ::SeedStatus < DummyGenerator > SeedStatusDummyGenerator;
typedef ::ParameterizedStatus < DummyGenerator > ParameterizedStatusDummyGenerator;

// ---- class containing PRNG algorithm --- 

template < typename T >
class DummyGenerator
{
   public: 
      typedef SeedStatusDummyGenerator 			 SeedStatusType;
      typedef ParameterizedStatusDummyGenerator 	 ParameterizedStatusType;
   
   public: // to ease concept checking 
      SeedStatusType ss_;
      ParameterizedStatusType* ps_;

   public:

      __host__ __device__
      explicit DummyGenerator(T inNextValue = 0, T inDifference = 0)
       :ps_ (new ParameterizedStatusType(inDifference))
       {
         ss_.nextValue_ = inNextValue;
       }

      __host__
      // now, fit shoverand's constraints
      static void init( int nbBlocks ) {
         
      }

      __host__
      static void release() {
         // usually release device memory
      }

      __host__ __device__
      T next() {
         T outValue = ss_.nextValue_;
         ss_.nextValue_ += ps_->difference_;
         return outValue; 
      }
};


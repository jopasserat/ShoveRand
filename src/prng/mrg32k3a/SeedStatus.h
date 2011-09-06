#ifndef MRG32k3A_SEED_STATUS
#define MRG32k3A_SEED_STATUS


// forward declaration of class MRG32k3a
namespace shoverand { namespace prng {	 namespace MRG32k3a {
			
			template <class T>
			class MRG32k3a;
			
		}
	} // end of namespace prng
} // end of namespace shoverand


// out of namespace to allow template specialization 
// TODO add to core namespace

	/** SeedStatus specialization for MRG32k3a */
	template <>
	class SeedStatus<MRG32k3a::MRG32k3a> {
		// TODO
	public: 
		int toto;	
		
		__host__ __device__
		SeedStatus<MRG32k3a::MRG32k3a> (int i):toto(i) {} 
	};

	typedef ::SeedStatus < ::MRG32k3a::MRG32k3a > SeedStatusMRG32k3a;

#endif // MRG32k3A_SEED_STATUS

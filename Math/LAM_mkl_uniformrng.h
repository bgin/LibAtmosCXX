
#ifndef __LAM_MKL_UNIFORMRNG_H__
#define __LAM_MKL_UNIFORMRNG_H__

namespace file_info {
const unsigned int gLAM_MKL_UNIFORMRNG_MAJOR = 1U;

const unsigned int gLAM_MKL_UNIFORMRNG_MINOR = 0U;

const unsigned int gLAM_MKL_UNIFORMRNG_MICRO = 0U;

const unsigned int gLAM_MKL_UNIFORMRNG_FULLVER = 
	1000U*gLAM_MKL_UNIFORMRNG_MAJOR + 100U*gLAM_MKL_UNIFORMRNG_MINOR + 10U*gLAM_MKL_UNIFORMRNG_MICRO;

const char * const pgLAM_MKL_UNIFORMRNG_CREATE_DATE = "24-04-2018 08:42 +00200 (TUE 24 APR 2018 GMT+2)";

const char * const pgLAM_MKL_UNIFORMRNG_BUILD_DATE = "00-00-0000 00:00";

const char * const pgLAM_MKL_UNIFORMRNG_AUTHOR = "Programmer: Bernard Gingold, e-mail: beniekg@gmail.com";

const char * const pgLAM_MKL_UNIFORMRNG_DESCRIPT = "C++ wrapper over MKL vdRngUniform procedure.";

}

#include <iostream>
#include "../LAM_config.h"
#if (USE_MKL) == 1
#include <mkl_vsl.h>
#endif

namespace lam {
	namespace math {
		namespace stat {

			//
			//	C++ wrapper around Intel MKL vdRngUniform procedure.
			//

			__declspec(align(64))struct MKLUniformRNG{
					
				    _Field_size_(m_nvalues) double * __restrict m_rvec; // vector of random values

				    double   m_a; // param 'a'

				    double   m_b;   // param 'b'

#if (USE_STRUCT_PADDING) == 1
					PAD_TO(1,8)
#endif
					
					MKL_INT m_nvalues; // number of random values in vector m_rvec
#if (USE_STRUCT_PADDING) == 1
					PAD_TO(2,4)
#endif
					MKL_UINT m_brng;  // Basic random number generator
#if (USE_STRUCT_PADDING) == 1
					PAD_TO(3,4)
#endif
					MKL_INT  m_seed;  // initial seed 
#if (USE_STRUCT_PADDING) == 1
					PAD_TO(4,4)
#endif
					MKL_INT  m_error; // error returned by the MKL
#if (USE_STRUCT_PADDING) == 1
					PAD_TO(5,4)
#endif
					

					//
					//	Constructor and destructor
					//

					MKLUniformRNG();

					MKLUniformRNG(_In_ const MKL_INT,
								  _In_ const MKL_UINT,
								  _In_ const MKL_INT,
								  _In_ const double,
								  _In_ const double);

					MKLUniformRNG(_In_ const MKLUniformRNG &);

					MKLUniformRNG(_In_ MKLUniformRNG &&)noexcept(true);

					~MKLUniformRNG()noexcept(true);

					MKLUniformRNG & operator=(_In_ const MKLUniformRNG &);

					MKLUniformRNG & operator=(_In_ MKLUniformRNG &&)noexcept(true);

					void compute_rand_distribution(_In_ const MKL_INT);

					void compute_rand_distribution(_Inout_ VSLStreamStatePtr, _In_ const MKL_INT);
			};

			std::ostream &
			operator<<(_In_ std::ostream &, _In_ const MKLUniformRNG &);
		}
	}
}

#endif /*__LAM_MKL_UNIFORMRNG_H__*/
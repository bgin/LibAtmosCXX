
#ifndef __LAM_MKL_UNIFORMRNG_H__
#define __LAM_MKL_UNIFORMRNG_H__

#if !defined (LAM_MKL_UNIFORMRNG_MAJOR)
#define LAM_MKL_UNIFORMRNG_MAJOR 1
#endif

#if !defined (LAM_MKL_UNIFORMRNG_MINOR)
#define LAM_MKL_UNIFORMRNG_MAJOR 0
#endif

#if !defined (LAM_MKL_UNIFORMRNG_MICRO)
#define LAM_MKL_UNIFORMRNG_MICRO 0
#endif

#if !defined (LAM_MKL_UNIFORMRNG_FULLVER)
#define LAM_MKL_UNIFORMRNG_FULLVER 1000
#endif

#if !defined (LAM_MKL_UNIFORMRNG_CREATE_DATE)
#define LAM_MKL_UNIFORMRNG_CREATE_DATE "24-04-2018 08:42 +00200 (TUE 24 APR 2018 GMT+2)"
#endif

#if !defined (LAM_MKL_UNIFORMRNG_BUILD_DATE)
#define LAM_MKL_UNIFORMRNG_BUILD_DATE " "
#endif

#if !defined (LAM_MKL_UNIFORMRNG_AUTHOR)
#define LAM_MKL_UNIFORMRNG_AUTHOR "Programmer: Bernard Gingold, e-mail: beniekg@gmail.com"
#endif

#if !defined (LAM_MKL_UNIFORMRNG_DESCRIPT)
#define LAM_MKL_UNIFORMRNG_DESCRIPT "C++ wrapper over MKL vdRngUniform procedure."
#endif

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
					
					MKL_INT m_nvalues; // number of random values in vector m_rvec

					MKL_UINT m_brng;  // Basic random number generator

					MKL_INT  m_seed;  // initial seed 

					MKL_INT  m_error; // error returned by the MKL

					double   m_a; // param 'a'

					double   m_b;   // param 'b'

					_Field_size_(m_nvalues) double * __restrict m_rvec; // vector of random values

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
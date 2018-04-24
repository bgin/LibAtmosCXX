
#ifndef __LAM_MKL_EXPONENTIALRNG_H__
#define __LAM_MKL_EXPONENTIALRNG_H__

#if !defined (LAM_MKL_EXPONENTIALRNG_MAJOR)
#define LAM_MKL_EXPONENTIALRNG_MAJOR 1
#endif

#if !defined (LAM_MKL_EXPONENTIALRNG_MINOR)
#define LAM_MKL_EXPONENTIALRNG_MINOR 0
#endif

#if !defined (LAM_MKL_EXPONENTIALRNG_MICRO)
#define LAM_MKL_EXPONENTIALRNG_MICRO 0
#endif

#if !defined (LAM_MKL_EXPONENTIALRNG_FULLVER)
#define LAM_MKL_EXPONENTIALRNG_FULLVER 1000
#endif

#if !defined (LAM_MKL_EXPONENTIALRNG_CREATE_DATE)
#define LAM_MKL_EXPONENTIALRNG_CREATE_DATE "24-04-2018 15:25 +00200 (TUE 24 APR 2018 GMT+2)"
#endif

#if !defined (LAM_MKL_EXPONENTIALRNG_BUILD_DATE)
#define LAM_MKL_EXPONENTIALRNG_BUILD_DATE " "
#endif

#if !defined (LAM_MKL_EXPONENTIALRNG_AUTHOR)
#define LAM_MKL_EXPONENTIALRNG_AUTHOR "Programmer: Bernard Gingold, e-mail: beniekg@gmail.com"
#endif

#if !defined (LAM_MKL_EXPONENTIALRNG_DESCRIPT)
#define LAM_MKL_EXPONENTIALRNG_DESCRIPT "C++ wrapper around Intel MKL vdRngExponential procedure."
#endif

#include <iostream>
#include "../LAM_config.h"
#if (USE_MKL) == 1
#include <mkl_vsl.h>
#endif

namespace lam{
	namespace math {
		namespace stat {

			// C++ wrapper around Intel MKL vdRngExponential procedure.
			__declspec(align(64)) struct MKLExponentialRNG{
					
					MKL_INT m_nvalues;

					MKL_UINT m_brng;

					MKL_INT  m_seed;

					MKL_INT  m_error;

					double   m_a;

					double   m_beta;

					_Field_size_(m_nvalues)double * __restrict m_rvec;

					//
					//	Constructor and destructor
					//
					MKLExponentialRNG();

					MKLExponentialRNG(_In_ const MKL_INT,
									  _In_ const MKL_UINT,
									  _In_ const MKL_INT,
									  _In_ const double,
									  _In_ const double);

					MKLExponentialRNG(_In_ const MKLExponentialRNG &);

					MKLExponentialRNG(_In_ MKLExponentialRNG &&)noexcept(true);

					~MKLExponentialRNG()noexcept(true);

					MKLExponentialRNG & operator=(_In_ const MKLExponentialRNG &);

					MKLExponentialRNG & operator=(_In_ MKLExponentialRNG &&)noexcept(true);

					void compute_rand_distribution(_In_ const MKL_INT);

					void compute_rand_distribution(_Inout_ VSLStreamStatePtr, _In_ const MKL_INT);

			};

			std::ostream &
			operator<<(_In_ std::ostream &,
					   _In_ const MKLExponentialRNG &);
		}
	}
}


#endif /*__LAM_MKL_EXPONENTIALRNG_H__*/
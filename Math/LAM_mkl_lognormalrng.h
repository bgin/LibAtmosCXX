
#ifndef __LAM_MKL_LOGNORMALRNG_H__
#define __LAM_MKL_LOGNORMALRNG_H__

#if !defined (LAM_MKL_LOGNORMALRNG_MAJOR)
#define LAM_MKL_LOGNORMALRNG_MAJOR 1
#endif

#if !defined (LAM_MKL_LOGNORMALRNG_MINOR)
#define LAM_MKL_LOGNORMALRNG_MINOR 0
#endif

#if !defined (LAM_MKL_LOGNORMALRNG_MICRO)
#define LAM_MKL_LOGNORMALRNG_MICRO 0
#endif

#if !defined (LAM_MKL_LOGNORMALRNG_FULLVER)
#define LAM_MKL_LOGNORMALRNG_FULLVER 1000
#endif

#if !defined (LAM_MKL_LOGNORMALRNG_CREATE_DATE)
#define LAM_MKL_LOGNORMALRNG_CREATE_DATE "25-04-2018 11:55 +00200 (WED 25 APR 2018 GMT+2)"
#endif

#if !defined (LAM_MKL_LOGNORMALRNG_BUILD_DATE)
#define LAM_MKL_LOGNORMALRNG_BUILD_DATE " "
#endif

#if !defined (LAM_MKL_LOGNORMALRNG_AUTHOR)
#define LAM_MKL_LOGNORMALRNG_AUTHOR "Programmer: Bernard Gingold, e-mail: beniekg@gmail.com"
#endif

#if !defined (LAM_MKL_LOGNORMALRNG_DESCRIPT)
#define LAM_MKL_LOGNORMALRNG_DESCRIPT "C++ wrapper around Intel MKL vdRngLognormal procedure."
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
				//	C++ wrapper around Intel MKL vdRngLognormal procedure.
				//
				
			__declspec(align(64)) struct  MKLLognormalRNG{
					
					MKL_INT m_nvalues;

					MKL_UINT m_brng;

					MKL_INT  m_seed;

					MKL_INT  m_error;

					double   m_a;

					double   m_sigma;

					double   m_b;

					double   m_beta;

					_Field_size_(m_nvalues) double * __restrict m_rvec;

					//
					//	Construction and destruction.
					//

					MKLLognormalRNG();

					MKLLognormalRNG(_In_ const MKL_INT,
								    _In_ const MKL_UINT,
									_In_ const MKL_INT,
									_In_ const double,
									_In_ const double,
									_In_ const double,
									_In_ const double);

					MKLLognormalRNG(_In_ const MKLLognormalRNG &);

					MKLLognormalRNG(_In_ MKLLognormalRNG &&)noexcept(true);

					~MKLLognormalRNG()noexcept(true);

					MKLLognormalRNG & operator=(_In_ const MKLLognormalRNG &);

					MKLLognormalRNG & operator=(_In_ MKLLognormalRNG &&)noexcept(true);

					void compute_rand_distribution(_In_ const MKL_INT);

					void compute_rand_distribution(_Inout_ VSLStreamStatePtr, _In_ const MKL_INT);

			};

			std::ostream &
			operator<<(_In_ std::ostream &,
					   _In_ const MKLLognormalRNG &);
		}
	}
}




#endif /*__LAM_MKL_LOGNORMALRNG_H__*/
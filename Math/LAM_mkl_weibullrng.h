
#ifndef __LAM_MKL_WIEBULLRNG_H__
#define __LAM_MKL_WEIBULLRNG_H__

#if !defined (LAM_MKL_WEIBULLRNG_MAJOR)
#define LAM_MKL_WEIBULLRNG_MAJOR 1
#endif

#if !defined (LAM_MKL_WEIBULLRNG_MINOR)
#define LAM_MKL_WEIBULLRNG_MINOR 0
#endif

#if !defined (LAM_MKL_WEIBULLRNG_MICRO)
#define LAM_MKL_WEIBULLRNG_MICRO 0
#endif

#if !defined (LAM_MKL_WEIBULLRNG_FULLVER)
#define LAM_MKL_WEIBULLRNG_FULLVER 1000
#endif

#if !defined (LAM_MKL_WEIBULLRNG_CREATE_DATE)
#define LAM_MKL_WEIBULLRNG_CREATE_DATE "26-04-2018 14:17 +00200 (THR 26 APR 2018 GMT+2)"
#endif

#if !defined (LAM_MKL_WEIBULLRNG_BUILD_DATE)
#define LAM_MKL_WEIBULLRNG_BUILD_DATE " "
#endif

#if !defined (LAM_MKL_WEIBULLRNG_AUTHOR)
#define LAM_MKL_WEIBULLRNG_AUTHOR "Programmer: Bernard Gingold, e-mail: beniekg@gmail.com"
#endif

#if !defined (LAM_MKL_WEIBULLRNG_DESCRIPT)
#define LAM_MKL_WEIBULLRNG_DESCRIPT "C++ wrapper for Intel MKL vdRngWeibull procedure."
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
			//	C++ wrapper for Intel MKL vdRngWeibull procedure
			//

			__declspec(align(64)) struct MKLWeibullRNG{
					
					MKL_INT m_nvalues;

					MKL_UINT m_brng;

					MKL_INT  m_seed;

					MKL_INT  m_error;

					double   m_alpha;

					double   m_a;

					double   m_beta;

					_Field_size_(m_nvalues)double * __restrict m_rvec;

					//
					//	Constuction and destruction
					//

					MKLWeibullRNG();

					MKLWeibullRNG(_In_ const MKL_INT,
							      _In_ const MKL_UINT,
								  _In_ const MKL_INT,
								  _In_ const double,
								  _In_ const double,
								  _In_ const double);

					MKLWeibullRNG(_In_ const MKLWeibullRNG &);

					MKLWeibullRNG(_In_ MKLWeibullRNG &&)noexcept(true);

					~MKLWeibullRNG()noexcept(true);

					MKLWeibullRNG & operator=(_In_ const MKLWeibullRNG &);

					MKLWeibullRNG & operator=(_In_  MKLWeibullRNG &&)noexcept(true);

					void compute_rand_distribution(_In_ const MKL_INT);

					void compute_rand_distribution(_Inout_ VSLStreamStatePtr, _In_ const MKL_INT);
			};

			std::ostream &
			operator<<(_In_ std::ostream &,
					   _In_ const MKLWeibullRNG &);


		}
	}
}



#endif /*__LAM_WEIBULLRNG_H__*/

#ifndef __LAM_MKL_LAPLACERNG_H__
#define __LAM_MKL_LAPLACERNG_H__

#if !defined (LAM_MKL_LAPLACERNG_MAJOR)
#define LAM_MKL_LAPLACERNG_MAJOR 1
#endif

#if !defined (LAM_MKL_LAPLACERNG_MINOR)
#define LAM_MKL_LAPLACERNG_MINOR 0
#endif

#if !defined (LAM_MKL_LAPLACERNG_MICRO)
#define LAM_MKL_LAPLACERNG_MICRO 0
#endif

#if !defined (LAM_MKL_LAPLACERNG_FULLVER)
#define LAM_MKL_LAPLACERNG_FULLVER 1000
#endif

#if !defined (LAM_MKL_LAPLACERNG_CREATE_DATE)
#define LAM_MKL_LAPLACERNG_CREATE_DATE "25-04-2018 09:25 +00200 (WED 25 APR 2018 GMT+2)"
#endif

#if !defined (LAM_MKL_LAPLACERNG_BUILD_DATE)
#define LAM_MKL_LAPLACERNG_BUILD_DATE " "
#endif

#if !defined (LAM_MKL_LAPLACERNG_AUTHOR)
#define LAM_MKL_LAPLACERNG_AUTHOR "Programmer: Bernard Gingold, e-mail: beniekg@gmail.com"
#endif

#if !defined (LAM_MKL_LAPLACERNG_DESCRIPT)
#define LAM_MKL_LAPLACERNG_DESCRIPT "C++ wrapper for Intel MKL vdRngLaplace procedure."
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
				//	C++ wrapper around Intel MKL vdRngLaplace procedure.
				//

			__declspec(align(64)) struct MKLLaplaceRNG{
					
					MKL_INT m_nvalues;

					MKL_UINT m_brng;

					MKL_INT m_seed;

					MKL_INT m_error;

					double  m_a;

					double  m_beta;

					_Field_size_(m_nvalues)double * __restrict m_rvec;

					//
					//	Construction and destruction
					//

					MKLLaplaceRNG();

					MKLLaplaceRNG(_In_ const MKL_INT,
								  _In_ const MKL_UINT,
								  _In_ const MKL_INT,
								  _In_ const double,
								  _In_ const double);

					MKLLaplaceRNG(_In_ const MKLLaplaceRNG &);

					MKLLaplaceRNG(_In_ MKLLaplaceRNG &&)noexcept(true);

					~MKLLaplaceRNG()noexcept(true);

					MKLLaplaceRNG & operator=(_In_ const MKLLaplaceRNG &);

					MKLLaplaceRNG & operator=(_In_ MKLLaplaceRNG &&)noexcept(true);

					void compute_rand_distribution(_In_ const MKL_INT);

					void compute_rand_distribution(_Inout_ VSLStreamStatePtr, _In_ const MKL_INT);
			};

			std::ostream &
			operator<<(_In_ std::ostream &, _In_ const MKLLaplaceRNG &);
		}
	}
}




#endif /*__LAM_MKL_LAPLACERNG_H__*/
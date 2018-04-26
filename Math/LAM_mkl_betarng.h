
#ifndef __LAM_MKL_BETARNG_H__
#define __LAM_MKL_BETARNG_H__

#if !defined (LAM_MKL_BETARNG_MAJOR)
#define LAM_MKL_BETARNG_MAJOR 1
#endif

#if !defined (LAM_MKL_BETARNG_MINOR)
#define LAM_MKL_BETARNG_MINOR 0
#endif

#if !defined (LAM_MKL_BETARNG_MICRO)
#define LAM_MKL_BETARNG_MICRO 0
#endif

#if !defined (LAM_MKL_BETARNG_FULLVER)
#define LAM_MKL_BETARNG_FULLVER 1000
#endif

#if !defined (LAM_MKL_BETARNG_CREATE_DATE)
#define LAM_MKL_BETARNG_CREATE_DATE "25-04-2018 15:37 +00200 (WED 25 APR 2018 GMT+2)"
#endif

#if !defined (LAM_MKL_BETARNG_BUILD_DATE)
#define LAM_MKL_BETARNG_BUILD_DATE " "
#endif

#if !defined (LAM_MKL_BETARNG_AUTHOR)
#define LAM_MKL_BETARNG_AUTHOR "Programmer: Bernard Gingold, e-mail: beniekg@gmail.com"
#endif

#if !defined (LAM_MKL_BETARNG_DESCRIPT)
#define LAM_MKL_BETARNG_DESCRIPT "C++ wrapper for Intel MKL vdRngBeta procedure."
#endif

#include <iostream>
#include "../LAM_config.h"
#if (USE_MKL) == 1
#include <mkl_vsl.h>
#endif

namespace lam{
	namespace math {
		namespace stat {
				
				//
				//	C++ wrapper for Intel MKL vdRngBeta procedure.
				//

			__declspec(align(64)) struct  MKLBetaRNG {
					
					MKL_INT  m_nvalues;

					MKL_UINT m_brng;

					MKL_INT  m_seed;

					MKL_INT  m_error;

					double   m_p;

					double   m_q;

					double   m_a;

					double   m_beta;

					_Field_size_(m_nvalues)double * __restrict m_rvec;

					//
					//	Construction and destruction
					//

					MKLBetaRNG();

					MKLBetaRNG(_In_ const MKL_INT,
							   _In_ const MKL_UINT,
							   _In_ const MKL_INT,
							   _In_ const double,
							   _In_ const double,
							   _In_ const double,
							   _In_ const double);

					MKLBetaRNG(_In_ const MKLBetaRNG &);

					MKLBetaRNG(_In_ MKLBetaRNG &&)noexcept(true);

					~MKLBetaRNG()noexcept(true);

					MKLBetaRNG & operator=(_In_ const MKLBetaRNG &);

					MKLBetaRNG & operator=(_In_ MKLBetaRNG &&)noexcept(true);

					void compute_rand_distribution(_In_ const MKL_INT);

					void compute_rand_distribution(_Inout_ VSLStreamStatePtr, _In_ const MKL_INT);

			};

			std::ostream &
			operator<<(_In_ std::ostream &,
					   _In_ const MKLBetaRNG &);
		}
	}
}


#endif /*__LAM_MKL_BETARNG_H_*/
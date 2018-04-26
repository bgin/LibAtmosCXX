
#ifndef __LAM_MKL_GUMBELRNG_H__
#define __LAM_MKL_GUMBELRNG_H__

#if !defined (LAM_MKL_GUMBELRNG_MAJOR)
#define LAM_MKL_GUMBELRNG_MAJOR 1
#endif

#if !defined (LAM_MKL_GUMBELRNG_MINOR)
#define LAM_MKL_GUMBELRNG_MINOR 0
#endif

#if !defined (LAM_MKL_GUMBELRNG_MICRO)
#define LAM_MKL_GUMBELRNG_MICRO 0
#endif

#if !defined (LAM_MKL_GUMBELRNG_FULLVER)
#define LAM_MKL_GUMBELRNG_FULLVER 1000
#endif

#if !defined (LAM_MKL_GUMBELRNG_CREATE_DATE)
#define LAM_MKL_GUMBELRNG_CREATE_DATE "26-04-2018 10:47 +00200 (THR 26 APR 2018 GMT+2)"
#endif

#if !defined (LAM_MKL_GUMBELRNG_BUILD_DATE)
#define LAM_MKL_GUMBELRNG_BUILD_DATE " "
#endif

#if !defined (LAM_MKL_GUMBELRNG_AUTHOR)
#define LAM_MKL_GUMBELRNG_AUTHOR "Programmer: Bernard Gingold, e-mail: beniekg@gmail.com"
#endif

#if !defined (LAM_MKL_GUMBELRNG_DESCRIPT)
#define LAM_MKL_GUMBELRNG_DESCRIPT "C++ wrapper around Intel MKL vdRngGumbel procedure."
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
			//	C++ wrapper for Intel MKL vdRngGumbel procedure.
			//

			__declspec(align(64)) struct  MKLGumbelRNG {

					MKL_INT		m_nvalues;

					MKL_UINT    m_brng;

					MKL_INT     m_seed;

					MKL_INT     m_error;

					double      m_a;

					double      m_beta;

					_Field_size_(m_nvalues)double * __restrict m_rvec;

					//
					//	Construction and destruction
					//

					MKLGumbelRNG();

					MKLGumbelRNG(_In_ const MKL_INT,
								 _In_ const MKL_UINT,
								 _In_ const MKL_INT,
								 _In_ const double,
								 _In_ const double);

					MKLGumbelRNG(_In_ const MKLGumbelRNG &);

					MKLGumbelRNG(_In_ MKLGumbelRNG &&)noexcept(true);

					~MKLGumbelRNG()noexcept(true);

					MKLGumbelRNG & operator=(_In_ const MKLGumbelRNG &);

					MKLGumbelRNG & operator=(_In_ MKLGumbelRNG &&)noexcept(true);

					void compute_rand_distribution(_In_ const MKL_INT);

					void compute_rand_distribution(_Inout_ VSLStreamStatePtr, _In_ const MKL_INT);
			};

			std::ostream &
			operator<<(_In_ std::ostream &,
					   _In_ const MKLGumbelRNG &);
		}
	}
}



#endif /*__LAM_MKL_GUMBELRNG_H__*/
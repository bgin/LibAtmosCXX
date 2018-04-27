
#ifndef __LAM_MKL_RAYLEIGHRNG_H__
#define __LAM_MKL_RAYLEIGHRNG_H__

#if !defined (LAM_MKL_RAYLEIGHRNG_MAJOR)
#define LAM_MKL_RAYLEIGHRNG_MAJOR 1
#endif

#if !defined (LAM_MKL_RAYLEIGHRNG_MINOR)
#define LAM_MKL_RAYLEIGHRNG_MINOR 0
#endif

#if !defined (LAM_MKL_RAYLEIGHRNG_MICRO)
#define LAM_MKL_RAYLEIGHRNG_MICRO 0
#endif

#if !defined (LAM_MKL_RAYLEIGHRNG_FULLVER)
#define LAM_MKL_RAYLEIGHRNG_FULLVER 1000
#endif

#if !defined (LAM_MKL_RAYLEIGHRNG_CREATE_DATE)
#define LAM_MKL_RAYLEIGHRNG_CREATE_DATE "27-04-2018 09:31 +00200 (FRI 27 APR 2018 GMT+2)"
#endif

#if !defined (LAM_MKL_RAYLEIGHRNG_BUILD_DATE)
#define LAM_MKL_RAYLEIGHRNG_BUILD_DATE " "
#endif

#if !defined (LAM_MKL_RAYLEIGHRNG_AUTHOR)
#define LAM_MKL_RAYLEIGHRNG_AUTHOR "Programmer: Bernard Gingold, e-mail: beniekg@gmail.com"
#endif

#if !defined (LAM_MKL_RAYLEIGHRNG_DESCRIPT)
#define LAM_MKL_RAYLEIGHRNG_DESCRIPT "C++ wrapper for Intel MKL vdRngRayleigh procedure."
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
			//	C++ wrapper for Intel MKL vdRngRayleigh procedure.
			//

			__declspec(align(64))  struct MKLRayleighRNG{

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

					MKLRayleighRNG();

					MKLRayleighRNG(_In_ const MKL_INT,
								   _In_ const MKL_UINT,
								   _In_ const MKL_INT,
								   _In_ const double,
								   _In_ const double);

					MKLRayleighRNG(_In_ const MKLRayleighRNG &);

					MKLRayleighRNG(_In_ MKLRayleighRNG &&)noexcept(true);

					~MKLRayleighRNG()noexcept(true);

					MKLRayleighRNG & operator=(_In_ const MKLRayleighRNG &);

					MKLRayleighRNG & operator=(_In_ MKLRayleighRNG &&)noexcept(true);

					void compute_rand_distribution(_In_ const MKL_INT);

					void compute_rand_distribution(_Inout_ VSLStreamStatePtr, _In_ const MKL_INT);
			};

			std::ostream &
			operator<<(_Inout_ std::ostream &,
					   _In_ const MKLRayleighRNG &);
		}
	}
}



#endif /*__LAM_MKL_RAYLEIGHRNG_H__*/
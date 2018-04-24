
#ifndef __LAM_MKL_CAUCHYRNG_H__
#define __LAM_MKL_CAYCHYRNG_H__

#if !defined (LAM_MKL_CAUCHYRNG_MAJOR)
#define LAM_MKL_CAUCHYRNG_MAJOR 1
#endif

#if !defined (LAM_MKL_CAUCHYRNG_MINOR)
#define LAM_MKL_CAUCHYRNG_MINOR 0
#endif

#if !defined (LAM_MKL_CAUCHYRNG_MICRO)
#define LAM_MKL_CAUCHYRNG_MICRO 0
#endif

#if !defined (LAM_MKL_CAUCHYRNG_FULLVER)
#define LAM_MKL_CAUCHYRNG_FULLVER 1000
#endif

#if !defined (LAM_MKL_CAUCHYRNG_CREATE_DATE)
#define LAM_MKL_CAUCHYRNG_CREATE_DATE "23-04-2018 09:16 +00200 (MON 23 APR 2018 GMT+2)"
#endif

#if !defined (LAM_MKL_CAUCHYRNG_BUILD_DATE)
#define LAM_MKL_CAUCHYRNG_BUILD_DATE ""
#endif

#if !defined (LAM_MKL_CAUCHYRNG_AUTHOR)
#define LAM_MKL_CAUCHYRNG_AUTHOR "Programmer: Bernard Gingold, e-mail: beniekg@gmail.com"
#endif

#if !defined (LAM_MKL_CAUCHYRNG_DESCRIPT)
#define LAM_MKL_CAUCHYRNG_DESCRIPT "C++ wrapper over MKL vdRngCauchy procedure."
#endif

#include <iostream>
#include "../LAM_config.h"
#if (USE_MKL) == 1
#include <mkl_vsl.h>
#endif

namespace lam {
	namespace math {
		namespace stat {

			// Wrapper around Mkl_Api(int,vdRngCauchy,(const MKL_INT  , VSLStreamStatePtr  , const MKL_INT  , double [], const double  , const double  ))

			__declspec(align(64))struct MKLCauchyRNG{

				MKL_INT m_nvalues;  // number of random values in vector m_rvec

				MKL_UINT m_brng;    // Basic random number generator

				MKL_INT m_seed;     // initial seed

				MKL_INT m_error;   // error returned by the MKL

				double m_a;       // param 'a'

				double m_beta;   // param 'beta'

				_Field_size_(m_nvalues) double * __restrict m_rvec; // vector of random values

				//
				//	Construction and destruction
				//
				MKLCauchyRNG();

				MKLCauchyRNG(_In_ const MKL_INT,
							 _In_ const MKL_UINT,
							 _In_ const MKL_INT,
							 _In_ const double,
							 _In_ const double);

				MKLCauchyRNG(_In_ const MKLCauchyRNG &);

				MKLCauchyRNG(_In_ MKLCauchyRNG &&)noexcept(true);

				~MKLCauchyRNG()noexcept(true);

				MKLCauchyRNG & operator=(_In_ const MKLCauchyRNG &);

				MKLCauchyRNG & operator=(_In_ MKLCauchyRNG &&)noexcept(true);

				void compute_rand_distribution(_In_ const MKL_INT);

				void compute_rand_distribution(_Inout_ VSLStreamStatePtr,
											   _In_ const MKL_INT);


			};

			std::ostream &
			operator<<(_In_ std::ostream &, _In_ const MKLCauchyRNG &);
		}
	}
}



#endif /*__LAM_MKL_CAUCHYRNG_H__*/
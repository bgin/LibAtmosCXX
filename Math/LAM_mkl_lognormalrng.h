
#ifndef __LAM_MKL_LOGNORMALRNG_H__
#define __LAM_MKL_LOGNORMALRNG_H__

namespace file_info {

#include "../LAM_version.h"
const unsigned int gLAM_MKL_LOGNORMALRNG_MAJOR = lam::common::gVersionInfo.m_VersionMajor;

const unsigned int gLAM_MKL_LOGNORMALRNG_MINOR = lam::common::gVersionInfo.m_VersionMinor;

const unsigned int gLAM_MKL_LOGNORMALRNG_MICRO = lam::common::gVersionInfo.m_VersionMicro;

const unsigned int gLAM_MKL_LOGNORMALRNG_FULLVER = 
	1000U*gLAM_MKL_LOGNORMALRNG_MAJOR + 100U*gLAM_MKL_LOGNORMALRNG_MINOR + 10U*gLAM_MKL_LOGNORMALRNG_MICRO;

const char * const pgLAM_MKL_LOGNORMALRNG_CREATE_DATE = "25-04-2018 11:55 +00200 (WED 25 APR 2018 GMT+2)";

const char * const pgLAM_MKL_LOGNORMALRNG_BUILD_DATE = "00-00-0000 00:00";

const char * const pgLAM_MKL_LOGNORMALRNG_AUTHOR = "Programmer: Bernard Gingold, e-mail: beniekg@gmail.com";

const char * const pgLAM_MKL_LOGNORMALRNG_DESCRIPT = "C++ wrapper around Intel MKL vdRngLognormal procedure.";

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
				//	C++ wrapper around Intel MKL vdRngLognormal procedure.
				//

			__declspec(align(64)) struct MKLLRNGData {

				_Field_size_(m_nvalues) double * __restrict m_rvec;

				double   m_a;

				double   m_sigma;

				double   m_b;

				double   m_beta;
#if (USE_STRUCT_PADDING) == 1
				PAD_TO(1, 8)
#endif

				MKL_INT m_nvalues;

				MKL_UINT m_brng;

				MKL_INT  m_seed;

				MKL_INT  m_error;
			};

				
			__declspec(align(64)) struct  MKLLognormalRNG{

				  
					
					
					MKLLRNGData data;

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
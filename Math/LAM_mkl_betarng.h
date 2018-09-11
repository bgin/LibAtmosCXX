
#ifndef __LAM_MKL_BETARNG_H__
#define __LAM_MKL_BETARNG_H__

namespace file_info {
 // Include master version file
#include "../LAM_version.h"

const unsigned int gLAM_MKL_BETARNG_MAJOR = lam::common::gVersionInfo.m_VersionMajor;

const unsigned int gLAM_MKL_BETARNG_MINOR = lam::common::gVersionInfo.m_VersionMinor;

const unsigned int gLAM_MKL_BETARNG_MICRO = lam::common::gVersionInfo.m_VersionMicro;

const unsigned int gLAM_MKL_BETARNG_FULLVER = 
	1000U*gLAM_MKL_BETARNG_MAJOR + 100U*gLAM_MKL_BETARNG_MINOR + 10U*gLAM_MKL_BETARNG_MICRO;



const char * const pgLAM_MKL_BETARNG_CREATE_DATE = "25-04-2018 15:37 +00200 (WED 25 APR 2018 GMT+2)";

const char * const pgLAM_MKL_BETARNG_BUILD_DATE = "00-00-0000 00:00";

const char * const pgLAM_MKL_BETARNG_AUTHOR = "Programmer: Bernard Gingold, e-mail: beniekg@gmail.com";

const char * const pgLAM_MKL_BETARNG_DESCRIPT = "C++ wrapper around Intel MKL vdRngBeta procedure.";

}

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

			__declspec(align(64)) struct MKLBRNGData{ // POD and trivial type.
				// Payload aligned on 8-byte and starting at 64-byte boundary.
				_Field_size_(m_nvalues) double * __restrict m_rvec;
				double m_p;
				double m_q;
				double m_a;
				double m_beta;
#if (USE_STRUCT_PADDING) == 1
				PAD_TO(1,8)
#endif
				MKL_INT m_nvalues;
				MKL_INT m_brng;
				MKL_INT m_seed;
				MKL_INT m_error;
			};

			__declspec(align(64)) struct  MKLBetaRNG { // Non POD type and non trivial type.

				  

					
					MKLBRNGData datum;
					

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
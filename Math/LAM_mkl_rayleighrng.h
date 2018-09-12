
#ifndef __LAM_MKL_RAYLEIGHRNG_H__
#define __LAM_MKL_RAYLEIGHRNG_H__

namespace file_info {

#include "../LAM_version.h"

	const unsigned int gLAM_MKL_RAYLEIGHRNG_MAJOR = lam::common::gVersionInfo.m_VersionMajor;

	const unsigned int gLAM_MKL_RAYLEIGHRNG_MINOR = lam::common::gVersionInfo.m_VersionMinor;

	const unsigned int gLAM_MKL_RAYLEIGHRNG_MICRO = lam::common::gVersionInfo.m_VersionMicro;

	const unsigned int gLAM_MKL_RAYLEIGHRNG_FULLVER = 
	     1000U * gLAM_MKL_RAYLEIGHRNG_MAJOR + 100U*gLAM_MKL_RAYLEIGHRNG_MINOR + 10U*gLAM_MKL_RAYLEIGHRNG_MICRO;


	const char * const pgLAM_MKL_RAYLEIGHRNG_CREATE_DATE = "27-04-2018 09:31 +00200 (FRI 27 APR 2018 GMT+2)";

	const char * const pgLAM_MKL_RAYLEIGHRNG_BUILD_DATE = "00-00-0000 00:00";

	const char * const pgLAM_MKL_RAYLEIGHRNG_AUTHOR = "Programmer: Bernard Gingold, e-mail: beniekg@gmail.com";

	const char * const pgLAM_MKL_RAYLEIGHRNG_DESCRIPT = "C++ wrapper for Intel MKL vdRngRayleigh procedure.";

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
			//	C++ wrapper for Intel MKL vdRngRayleigh procedure.
			//

			__declspec(align(64)) struct MKLRNGData {

				_Field_size_(m_nvalues)double * __restrict m_rvec;

				double      m_a;

				double      m_beta;
#if (USE_STRUCT_PADDING) == 1
				PAD_TO(1, 8)
#endif

					MKL_INT		m_nvalues;
#if (USE_STRUCT_PADDING) == 1
				PAD_TO(2, 4)
#endif
					MKL_UINT    m_brng;
#if (USE_STRUCT_PADDING) == 1
				PAD_TO(3, 4)
#endif
					MKL_INT     m_seed;
#if (USE_STRUCT_PADDING) == 1
				PAD_TO(4, 4)
#endif
					MKL_INT     m_error;
#if (USE_STRUCT_PADDING) == 1
				PAD_TO(5, 4)
#endif
				
			};

			__declspec(align(64))  struct MKLRayleighRNG{

				
					
					MKLRNGData datum;
					

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
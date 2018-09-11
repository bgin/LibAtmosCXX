
#ifndef __LAM_MKL_WIEBULLRNG_H__
#define __LAM_MKL_WEIBULLRNG_H__
#include <thread>
namespace file_info {

#include "../LAM_version.h"

const unsigned int gLAM_MKL_WEIBULLRNG_MAJOR = lam::common::gVersionInfo.m_VersionMajor;

const unsigned int gLAM_MKL_WEIBULLRNG_MINOR = lam::common::gVersionInfo.m_VersionMinor;

const unsigned int gLAM_MKL_WEIBULLRNG_MICRO = lam::common::gVersionInfo.m_VersionMicro;

const unsigned int gLAM_MKL_WEIBULLRNG_FULLER = 
	1000U*gLAM_MKL_WEIBULLRNG_MAJOR + 100U*gLAM_MKL_WEIBULLRNG_MINOR + 10U*gLAM_MKL_WEIBULLRNG_MICRO;

const char * const pgLAM_MKL_WEIBULLRNG_CREATE_DATE = "26-04-2018 14:17 +00200 (THR 26 APR 2018 GMT+2)";

const char * const pgLAM_MKL_WEIBULLRNG_BUILD_DATE = "00-00-0000 00:00";

const char * const pgLAM_MKL_WEIBULLRNG_AUTHOR = "Programmer: Bernard Gingold, e-mail: beniekg@gmail.com";

const char * const pgLAM_MKL_WEIBULLRNG_DESCRIPT = "C++ wrapper for Intel MKL vdRngWeibull procedure.";

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
			//	C++ wrapper for Intel MKL vdRngWeibull procedure
			//

			__declspec(align(64)) struct MKLWRNGData {
				
				_Field_size_(m_nvalues)double * __restrict m_rvec;
				   double m_alpha;
				   double m_a;
				   double m_beta;
				   MKL_INT m_nvalues;
#if (USE_STRUCT_PADDING) == 1
				   PAD_TO(1, 4)
#endif
				   MKL_INT m_brng;
#if (USE_STRUCT_PADDING) == 1
				   PAD_TO(2, 4)
#endif
			       MKL_INT m_seed;
#if (USE_STRUCT_PADDING) == 1
				   PAD_TO(3, 4)
#endif
				   MKL_INT m_error;
#if (USE_STRUCT_PADDING) == 1
				   PAD_TO(4, 4)
#endif
			};

			

				   

				  
					

			__declspec(align(64)) struct MKLWeibullRNG{
			    
				MKLWRNGData data;
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
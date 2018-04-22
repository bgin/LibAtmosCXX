
#ifndef __LAM_MKL_GAUSSIANRNG_H__
#define __LAM_MKL_GAUSSIANRNG_H__

#if !defined (LAM_MKL_GAUSSIANRNG_MAJOR)
#define LAM_MKL_GAUSSIANRNG_MAJOR 1
#endif

#if !defined (LAM_MKL_GAUSSIANRNG_MINOR)
#define LAM_MKL_GAUSSIANRNG_MINOR 0
#endif

#if !defined (LAM_MKL_GAUSSIANRNG_MICRO)
#define LAM_MKL_GAUSSIANRNG_MICRO 0
#endif

#if !defined (LAM_MKL_GAUSSIANRNG_FULLVER)
#define LAM_MKL_GAUSSIANRNG_FULLVER 1000
#endif

#if !defined (LAM_MKL_GAUSSIANRNG_CREATE_DATE)
#define LAM_MKL_GAUSSIANRNG_CREATE_DATE "22-04-2018 12:16 +00200 (SUN 22 APR 2018 GMT+2)"
#endif

#if !defined (LAM_MKL_GAUSSIANRNG_BUILD_DATE)
#define LAM_MKL_GAUSSIANRNG_BUILD_DATE " "
#endif

#if !defined (LAM_MKL_GAUSSIANRNG_AUTHOR)
#define LAM_MKL_GAUSSIANRNG_AUTHOR "Programmer: Bernard Gingold, e-mail: beniekg@gmail.com"
#endif

#if !defined (LAM_MKL_GAUSSIANRNG_DESCRIPT)
#define LAM_MKL_GAUSSIANRNG_DESCRIPT "C++ wrappers around Intel MKL random number generator procedures."
#endif

#include <cstdint>
#include <iostream>
#include "../LAM_config.h"
#if (USE_MKL) == 1
#include <mkl_vsl.h>
#endif

namespace lam{
	namespace math {
		namespace stat {
			
				// Wrapper around MKL vsrnggaussian( method, stream, n, r, a, sigma )

			__declspec(align(64))struct MKLGaussianRNG{
					
					

					MKL_INT m_nvalues;

					MKL_UINT m_brng;

					MKL_INT  m_seed;

					MKL_INT  m_error;

					double m_a;

					double m_sigma;
					
					_Field_size_(m_nvalues) double * __restrict m_rvec;

					//
					//	Construction and Destruction
					//
					MKLGaussianRNG();

					MKLGaussianRNG(_In_ const MKL_INT, 
								   _In_ const MKL_UINT,
								   _In_ const MKL_INT,
								   _In_ const double,
								   _In_ const double );

					MKLGaussianRNG(_In_ const MKLGaussianRNG &);

					MKLGaussianRNG(_In_ MKLGaussianRNG &&) noexcept(true);

					~MKLGaussianRNG() noexcept(true);

					MKLGaussianRNG & operator=(_In_ const MKLGaussianRNG &);

					MKLGaussianRNG & operator=(_In_ const MKLGaussianRNG & );

					MKLGaussianRNG & operator=(_In_ MKLGaussianRNG &&)noexcept(true);

					void compute_rand_distribution(); // Should be an interface in case of static polymorphism.
			};

			std::ostream & operator<<(_In_ std::ostream &,
									  _In_ const MKLGaussianRNG &);




		}
	}
}


#endif /*__LAM_MKL_RANDOM_H__*/
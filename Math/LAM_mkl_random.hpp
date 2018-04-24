
#ifndef  __LAM_MKL_RANDOM_HPP__
#define  __LAM_MKL_RANDOM_HPP__

#if !defined (LAM_MKL_RANDOM_MAJOR)
#define LAM_MKL_RANDOM_MAJOR 1
#endif

#if !defined (LAM_MKL_RANDOM_MINOR)
#define LAM_MKL_RANDOM_MINOR 0
#endif

#if !defined (LAM_MKL_RANDOM_MICRO)
#define LAM_MKL_RANDOM_MICRO 0
#endif

#if !defined (LAM_MKL_RANDOM_FULLVER)
#define LAM_MKL_RANDOM_FULLVER 1000
#endif

#if !defined (LAM_MKL_RANDOM_CREATE_DATE)
#define LAM_MKL_RANDOM_CREATE_DATE "24-04-2018 12:12 +00200 (TUE 24 APR 2018 GMT+2)"
#endif

#if !defined (LAM_MKL_RANDOM_BUILD_DATE)
#define LAM_MKL_RANDOM_BUILD_DATE " "
#endif

#if !defined (LAM_MKL_RANDOM_AUTHOR)
#define LAM_MKL_RANDOM_AUTHOR "Programmer: Bernard Gingold, e-mail: beniekg@gmail.com"
#endif

#if !defined (LAM_MKL_RANDOM_DESCRIPT)
#define LAM_MKL_RANDOM_DESCRIPT "C++ template class-wrapper around MKL random distribution procedures."
#endif

#include <iostream>
#include "../LAM_config.h"
#if (USE_MKL) == 1
#include <mkl_vsl.h>
#endif
#include "../LAM_common.h"
#include "../LAM_malloc.h"
#include "../LAM_error_macros.h"

namespace lam {
	namespace math {
		namespace stat {
				
			template<class MKLRandFx>  struct  MKLRandDistribution {

				MKL_INT m_nvalues;

				MKL_UINT m_brng;

				MKL_INT m_seed;

				MKL_INT m_error;

				double m_val1;

				double m_val2;

				_Field_size_(m_nvalues)double * __restrict m_rvec;

				MKLRandFx &m_randfx;

				//
				//	Construction and destruction.
				//
				MKLRandDistribution() = delete;

				MKLRandDistribution(_In_ const MKL_INT nvalues,
								    _In_ const MKL_UINT brng,
									_In_ const MKL_INT seed,
									_In_ const double val1,
									_In_ const double val2,
									_In_ MKLRandFx &randfx)
				:
				m_nvalues{ nvalues },
				m_brng{ brng },
				m_seed{ seed },
				m_error{ 1 },
				m_val1{ val1 },
				m_val2{val2},
				m_rvec(lam::common::lam_edmalloca(static_cast<size_t>(m_nvalues),align64B)),
				m_randfx(randfx){
					lam::common::avx256_init_unroll8x(&m_rvec[0], static_cast<size_t>(m_nvalues),0.0L);
				}

				MKLRandDistribution(_In_ const MKLRandDistribution &x)
				:
				m_nvalues{ x.m_nvalues },
				m_brng{ x.m_brng },
				m_seed{ x.m_seed },
				m_error{ x.m_error },
				m_val1{ x.m_val1 },
				m_val2{x.m_val2},
				m_rvec(lam::common::lam_edmalloca(static_cast<size_t(m_nvalues),align64B)),
				m_randfx(x.m_randfx) {
					lam::common::avx256_memcpy8x(&m_rvec[0], &x.m_rvec[0], static_cast<size_t>(m_nvalues));
				}

				
				~MKLRandDistribution()noexcept(true){
					if (NULL != m_rvec) {
						_mm_free(m_rvec);
						m_rvec = NULL;
					}
				}

				MKLRandDistribution & operator=(_In_ const MKLRandDistribution &x){
					if (this == ) return (*this);
					m_nvalues = x.m_nvalues;
					m_brng = x.m_brng;
					m_seed = x.m_seed;
					m_error = x.m_error;
					m_val1 = x.m_val1;
					m_val2 = x.m_val2;
					_mm_free(m_rvec);
					_Field_size_(m_nvalues)double * __restrict rvec{ lam::common::lam_edmalloca(static_cast<size_t>(m_nvalues),align64B) };
					lam::common::avx256_memcpy8x(&rvec[0], &x.m_rvec[0], static_cast<size_t>(m_nvalues));
					m_randfx = x.m_randfx;
					m_rvec = x.m_rvec[0];
					return (*this);
				}

			

				void compute_rand_distribution(_In_ const MKL_INT method) {
					VSLStreamStatePtr stream;
					m_error = vslNewStream(&stream,m_brng,m_seed);
					if (VSL_ERROR_OK != m_error) {
						PRINT_ERROR_VALUE("vslNewStream -- failed with an error value: ", m_error)
						DUMP_CALLSTACK_ON_ERROR
						return;
					}
					
					m_error = m_randfx(method, stream, m_nvalues, &m_rvec[0],m_val1,m_val2);
					if (VSL_ERROR_OK != m_error) {
						PRINT_ERROR_VALUE(typeid(m_randfx).name(), m_error)
						DUMP_CALLSTACK_ON_ERROR
						return;
					}
					m_error = vslDeleteStream(&stream);
					if (VSL_ERROR_OK != m_error) {
						PRINT_ERROR_VALUE("vslDeleteStream -- failed with an error value: ", m_error)
						DUMP_CALLSTACK_ON_ERROR
						return;
					}
				}

				void compute_rand_distribution(_Inout_ VSLStreamStatePtr stream,
										       _In_ const MKL_INT method) {
					m_error = vslNewStream(&stream, m_brng, m_seed);
					if (VSL_ERROR_OK != m_error) {
						PRINT_ERROR_VALUE("vslNewStream -- failed with an error value: ", m_error)
						DUMP_CALLSTACK_ON_ERROR
							return;
					}

					m_error = m_randfx(method, stream, m_nvalues, &m_rvec[0], m_val1, m_val2);
					if (VSL_ERROR_OK != m_error) {
						PRINT_ERROR_VALUE(typeid(m_randfx).name(), m_error)
						DUMP_CALLSTACK_ON_ERROR
							return;
					}
					// Caller of this method will deallocate (deinitialize) stream.
				}

			};

		}
	}
}


#endif /*__LAM_MKL_RANDOM_HPP__*/

#ifndef __LAM_ARMA_MODEL_H__
#define __LAM_ARMA_MODEL_H__

#if !defined (LAM_ARMA_MODEL_MAJOR)
#define LAM_ARMA_MODEL_MAJOR 1
#endif

#if !defined (LAM_ARMA_MODEL_MINOR)
#define LAM_ARMA_MODEL_MINOR 0
#endif

#if !defined (LAM_ARMA_MODEL_MICRO)
#define LAM_ARMA_MODEL_MICRO 0
#endif

#if !defined (LAM_ARMA_MODEL_FULLVER)
#define LAM_ARMA_MODEL_FULLVER 1000
#endif

#if !defined (LAM_ARMA_MODEL_CREATE_DATE)
#define LAM_ARMA_MODEL_CREATE_DATE "19-08-2018 15:31 +00200 (SUN 19 AUG 2018 GMT+2)"
#endif

#if !defined (LAM_ARMA_MODEL_BUILD_DATE)
#define LAM_ARMA_MODEL_BUILD_DATE " "
#endif

#if !defined (LAM_ARMA_MODEL_AUTHOR)
#define LAM_ARMA_MODEL_AUTHOR "Programmer: Bernard Gingold, contact: beniekg@gmail.com"
#endif

#if !defined (LAM_ARMA_MODEL_DESCRIPT)
#define LAM_ARMA_MODEL_DESCRIPT " AUTOMATIC AR-MA MODEL FITTING; SCALAR CASE "
#endif

#include "../LAM_config.h"

#if defined (__INTEL_COMPILER)
#include <../perf_headers/c++/valarray>
#else
#include <valarray>
#endif

#include <cstdint>

namespace lam {
	namespace math {
		namespace stat {

			struct ArmaModel {

				using VAf64 = std::valarray<double>;
				using VAi32 = std::valarray<int32_t>;

				/*
				Low-level computational code -- members are public.
				*/
				

				int32_t  m_newn;

				int32_t  m_nmax;

				int32_t  m_mmax;

				int32_t  m_kq;

				int32_t  m_kp;

				double   m_aicm;

				VAi32    m_iq;

				VAf64    m_b2;

				VAi32    m_ip;

				VAf64    m_a2;

				VAf64    m_std;

				VAf64    m_cxx2;

				VAf64    m_g;

				VAf64    m_saic;

				ArmaModel() = default;

				ArmaModel(_In_ const int32_t,
						  _In_ const int32_t,
						  _In_ const int32_t,
						  _In_ const double);

				ArmaModel(_In_ const ArmaModel &);

				ArmaModel(_In_ ArmaModel &&) noexcept(true);

				~ArmaModel() = default;

				ArmaModel & operator=(_In_ const ArmaModel &);

				ArmaModel & operator=(_In_ ArmaModel &&) noexcept(true);

				void compute_arma_model(_In_ int32_t,
									    _In_ int32_t,
										_In_ VAf64 &,
										_In_ int32_t,
										_In_ VAi32 &,
										_In_ VAf64 &,
										_In_ VAi32 &,
										_In_ VAf64 &,
										_In_ int32_t,
										_Inout_ int32_t[6] );


			};
		}
	}
}


#endif  /*__LAM_ARMA_MODEL_H__*/
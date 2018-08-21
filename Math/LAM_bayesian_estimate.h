
#ifndef __LAM_BAYESIAN_ESTIMATE_H__
#define __LAM_BAYESIAN_ESTIMATE_H__

#if !defined (LAM_BAYESIAN_ESTIMATE_MAJOR)
#define LAM_BAYESIAN_ESTIMATE_MAJOR 1
#endif

#if !defined (LAM_BAYESIAN_ESTIMATE_MINOR)
#define LAM_BAYESIAN_ESTIMATE_MINOR 0
#endif

#if !defined (LAM_BAYESIAN_ESTIMATE_MICRO)
#define LAM_BAYESIAN_ESTIMATE_MICRO 0
#endif

#if !defined (LAM_BAYESIAN_ESTIMATE_FULLVER)
#define LAM_BAYESIAN_ESTIMATE_FULLVER 1000
#endif

#if !defined (LAM_BAYESIAN_ESTIMATE_CREATE_DATE)
#define LAM_BAYESIAN_ESTIMATE_CREATE_DATE " 20-08-2018 11:41 +00200 (MON 20 AUG 2018 GMT+2) "
#endif

#if !defined (LAM_BAYESIAN_ESTIMATE_BUILD_DATE)
#define LAM_BAYESIAN_ESTIMATE_BUILD_DATE " "
#endif

#if !defined (LAM_BAYESIAN_ESTIMATE_AUTHOR)
#define LAM_BAYESIAN_ESTIMATE_AUTHOR "Programmer: Bernard Gingold, contact: beniekg@gmail.com"
#endif

#if !defined (LAM_BAYESIAN_ESTIMATE_DESCRIPT)
#define LAM_BAYESIAN_ESTIMATE_DESCRIPT " BAYESIAN ESTIMATES OF TIME SERIES MODELS "
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

			struct BayesEstimate {
					
				using VAf64 = std::valarray<double>;
				using VAi32 = std::valarray<int32_t>;

				/*
					Low-level computational code -- members are public.
				*/

				int32_t m_k;

				int32_t m_n;

				int32_t m_il;

				int32_t m_mj2;

				int32_t m_m;

				double m_zmean;

				double m_sum;

				double m_aicm;

				double m_sdm;

				double m_aicb;

				double m_sdb;

				double m_ek;

				double m_oeic;

				double m_omean;

				double m_om;

				VAi32  m_ind;

				VAf64  m_a1;

				VAf64  m_sd;

				VAf64  m_aic;

				VAf64  m_dic;

				VAf64  m_a2;

				VAf64  m_c;

				VAf64  m_c1;

				VAf64  m_c2;

				VAf64  m_b;

				VAf64  m_esum;

				VAf64  m_e;

				VAf64  m_emean;

				VAf64  m_vari;

				VAf64  m_skew;

				VAf64  m_peak;

				VAf64  m_cov;

				VAf64  m_sxx;

				BayesEstimate() = default;

				BayesEstimate(_In_ const int32_t ,
							  _In_ const int32_t ,
							  _In_ const int32_t ,
							  _In_ const int32_t ,
							  _In_ const int32_t ,
							  _In_ const double );

				BayesEstimate(_In_ const BayesEstimate &);

				BayesEstimate(_In_ BayesEstimate &&) noexcept(true);

				~BayesEstimate() = default;

				BayesEstimate & operator=(_In_ const BayesEstimate &);

				BayesEstimate & operator=(_In_ BayesEstimate &&) noexcept(true);

				void compute(_In_ VAf64 &,
							 _In_ int32_t,
							 _In_ int32_t,
							 _In_ VAi32 &,
							 _In_ VAi32 &,
							 _In_ int32_t[6]);


			};
		}
	}
}



#endif /*__LAM_BAYESIAN_ESTIMATE_H__*/
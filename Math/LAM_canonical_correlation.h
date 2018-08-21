

#ifndef __LAM_CANONICAL_CORRELATION_H__
#define __LAM_CANONICAL_CORRELATION_H__

#if !defined (LAM_CANONICAL_CORRELATION_MAJOR)
#define LAM_CANONICAL_CORRELATION_MAJOR 1
#endif

#if !defined (LAM_CANONICAL_CORRELATION_MINOR)
#define LAM_CANONICAL_CORRELATION_MINOR 0
#endif

#if !defined (LAM_CANONICAL_CORRELATION_MICRO)
#define LAM_CANONICAL_CORRELATION_MICRO 0
#endif

#if !defined (LAM_CANONICAL_CORRELATION_FULLVER)
#define LAM_CANONICAL_CORRELATION_FULLVER 1000
#endif

#if !defined (LAM_CANONICAL_CORRELATION_CREATE_DATE)
#define LAM_CANONICAL_CORRELATION_CREATE_DATE "21-08-2018 12:31 +00200 (TUE 21 AUG 2018 GMT+2) "
#endif

#if !defined (LAM_CANONICAL_CORRELATION_BUILD_DATE)
#define LAM_CANONICAL_CORRELATION_BUILD_DATE " "
#endif

#if !defined (LAM_CANONICAL_CORRELATION_AUTHOR)
#define LAM_CANONICAL_CORRELATION_AUTHOR "Programmer: Bernard Gingold, contact: beniekg@gmail.com"
#endif

#if !defined (LAM_CANONICAL_CORRELATION_DESCRIPT)
#define LAM_CANONICAL_CORRELATION_DESCRIPT "CANONICAL CORRELATION ANALYSIS OF SCALAR TIME SERIES"
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

			struct CanonicalCorrelation {

				using VAf64 = std::valarray<double>;
				using VAi32 = std::valarray<int32_t>;

				/*
				    Low-level computational code -- members are public.
				*/

				int32_t m_mj1;

				int32_t m_mj2;

				int32_t m_mo;

				int32_t m_nc;

				int32_t m_m1m;

				int32_t m_m1n;

				double  m_oaic;

				VAf64   m_coeff;

				VAf64   m_sd;

				VAf64   m_aic;

				VAf64   m_a;

				VAi32   m_mm1;

				VAi32   m_mm2;

				VAf64   m_v;

				VAf64   m_z;

				VAf64   m_y;

				VAf64   m_xx;

				VAi32   m_ndt;

				VAf64   m_x3;

				VAf64   m_x3min;

				VAi32   m_min3;

				VAf64   m_beta;

				VAf64   m_alpha;

				CanonicalCorrelation() = default;

				CanonicalCorrelation(_In_ const int32_t,
									 _In_ const int32_t,
									 _In_ const int32_t,
									 _In_ const double);

				CanonicalCorrelation(_In_ const CanonicalCorrelation &);

				CanonicalCorrelation(_In_ CanonicalCorrelation &&) noexcept(true);

				~CanonicalCorrelation() noexcept = default;

				CanonicalCorrelation & operator=(_In_ const CanonicalCorrelation &);

				CanonicalCorrelation & operator=(_In_ CanonicalCorrelation &&) noexcept(true);

				void compute(_In_ int32_t,
							 _In_ int32_t,
							 _In_ VAf64 &,
							 _In_ int32_t,
							 _Inout_ int32_t[6]);
							 

			};
		}
	}
}






#endif  /*__LAM_CANONICAL_CORRELATION_H__*/
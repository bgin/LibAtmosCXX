
#ifndef __LAM_VA_MARKOV_MODEL_H__
#define __LAM_VA_MARKOV_MODEL_H__

#if !defined (LAM_VA_MARKOV_MODEL_MAJOR)
#define LAM_VA_MARKOV_MODEL_MAJOR 1
#endif

#if !defined (LAM_VA_MARKOV_MODEL_MINOR)
#define LAM_VA_MARKOV_MODEL_MINOR 0
#endif

#if !defined (LAM_VA_MARKOV_MODEL_MICRO)
#define LAM_VA_MARKOV_MODEL_MICRO 0
#endif

#if !defined (LAM_VA_MARKOV_MODEL_FULLVER)
#define LAM_VA_MARKOV_MODEL_FULLVER 1000
#endif

#if !defined (LAM_VA_MARKOV_MODEL_CREATE_DATE)
#define LAM_VA_MARKOV_MODEL_CREATE_DATE " 19-08-2018 11:11 +00200 (SUN 19 AUG 2018 GMT+2) "
#endif

#if !defined (LAM_VA_MARKOV_MODEL_BUILD_DATE)
#define LAM_VA_MARKOV_MODEL_BUILD_DATE " "
#endif

#if !defined (LAM_VA_MARKOV_MODEL_AUTHOR)
#define LAM_VA_MARKOV_MODEL_AUTHOR "Programmer: Bernard Gingold, contact: beniekg@gmail.com"
#endif

#if !defined (LAM_VA_MARKOV_MODEL_DESCRIPT)
#define LAM_MARKOV_MODEL_DESCRIPT "MAXIMUM LIKELIHOOD COMPUTATION OF MARKOVIAN MODEL (Intel optmised valarray-based version) "
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


		
				
			struct MarkovModelVa {


				using VAf64 = std::valarray<double>;
				using VAi32 = std::valarray<int32_t>;

				/*
						Low-level computational code -- members are public.
				*/

				int32_t  m_k;

				int32_t  m_id;

				int32_t  m_mj4;

				int32_t  m_mj6;

				int32_t  m_mj7;

				int32_t  m_ipq;

				int32_t  m_iqm;

				double   m_aicd;

				VAi32    m_idd;

				VAi32    m_ir;

				VAi32    m_ij;

				VAi32    m_ik;

				VAf64    m_g;

				VAf64    m_a1;

				VAf64    m_a;

				VAf64    m_b;

				VAf64    m_vd;

				VAf64    m_bm;

				VAf64    m_au;

				VAf64    m_zz;

				VAf64    m_c0;

				MarkovModelVa() = default;

				MarkovModelVa(_In_ const int32_t,
							  _In_ const int32_t,
							  _In_ const int32_t,
							  _In_ const int32_t,
							  _In_ const int32_t,
							  _In_ const int32_t,
							  _In_ const double );

				MarkovModelVa(_In_ const MarkovModelVa &);

				MarkovModelVa(_In_ MarkovModelVa &&) noexcept(true);

				~MarkovModelVa() = default;

				MarkovModelVa & operator=(_In_ const MarkovModelVa &);

				MarkovModelVa & operator=(_In_ MarkovModelVa &&) noexcept(true);

				void compute_markov_model(_In_ int32_t,
									      _In_ int32_t,
										  _In_ VAf64 &,
										  _In_ VAi32 &,
										  _In_ int32_t,
										  _In_ VAf64 &,
										  _In_ VAf64 &,
										  _In_ int32_t,
										  _In_ int32_t,
										  _In_ int32_t[6]);

			};
		}
	}
}





#endif /*__LAM_VA_MARKOV_MODEL_H__*/
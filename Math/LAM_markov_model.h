
#ifndef __LAM_MARKOV_MODEL_H__
#define __LAM_MARKOV_MODEL_H__

#if !defined (LAM_MARKOV_MODEL_MAJOR)
#define LAM_MARKOV_MODEL_MAJOR 1
#endif

#if !defined (LAM_MARKOV_MODEL_MINOR)
#define LAM_MARKOV_MODEL_MINOR 0
#endif

#if !defined (LAM_MARKOV_MODEL_MICRO)
#define LAM_MARKOV_MODEL_MICRO 0
#endif

#if !defined (LAM_MARKOV_MODEL_FULLVER)
#define LAM_MARKOV_MODEL_FULLVER 1000
#endif

#if !defined (LAM_MARKOV_MODEL_CREATE_DATE)
#define LAM_MARKOV_MODEL_CREATE_DATE " 17-08-2018 15:55 +00200 (FRI 17 AUG 2018 GMT+2)"
#endif

#if !defined (LAM_MARKOV_MODEL_BUILD_DATE)
#define LAM_MARKOV_MODEL_BUILD_DATE " "
#endif

#if !defined (LAM_MARKOV_MODEL_AUTHOR)
#define LAM_MARKOV_MODEL_AUTHOR "Programmer: Bernard Gingold, contact: beniekg@gmail.com"
#endif

#if !defined (LAM_MARKOV_MODEL_DESCRIPT)
#define LAM_MARKOV_MODEL_DESCRIPT " MAXIMUM LIKELIHOOD COMPUTATION OF MARKOVIAN MODEL "
#endif

#include <cstdint>

namespace lam{
	namespace math {
		namespace stat {
					
			__declspec(align(64)) struct MarkovModel{

				/*
					Public member access low-level computational
					code.
				*/

				int32_t	  m_k;

				int32_t   m_id;

				int32_t   m_mj4;

				int32_t   m_mj6;

				int32_t   m_mj7;

				int32_t   m_ipq;

				int32_t   m_iqm;

				double    m_aicd;

				_Field_size_(m_k)	          int32_t * __restrict m_idd;

				_Field_size_(m_k)	          int32_t * __restrict m_ir;

				_Field_size_(m_k)	          int32_t * __restrict m_ij;
				
				_Field_size_(m_k)	          int32_t * __restrict m_ik;

				_Field_size_(m_mj4)           double  * __restrict m_g;

				_Field_size_(m_k*m_k)         double  * __restrict m_a1;

				_Field_size_(m_k*m_k)         double  * __restrict m_a;

				_Field_size_(m_k*m_id)        double  * __restrict m_b;

				_Field_size_(m_mj4*m_mj4)     double  * __restrict m_vd;

				_Field_size_(m_id*m_id*m_mj6) double  * __restrict m_bm;

				_Field_size_(m_id*m_id*m_mj7) double  * __restrict m_au;

				_Field_size_(m_id*m_id*m_mj7) double  * __restrict m_zz;

				_Field_size_(m_id*m_id)       double  * __restrict m_c0;

				MarkovModel();

				MarkovModel(_In_ const int32_t,
							_In_ const int32_t,
							_In_ const int32_t,
							_In_ const int32_t,
							_In_ const int32_t);

				MarkovModel(_In_ const MarkovModel &);

				MarkovModel(_In_ MarkovModel &&) noexcept(true);

				~MarkovModel() noexcept(true);

				MarkovModel & operator=(_In_ const MarkovModel &);

				MarkovModel & operator=(_In_ MarkovModel &&) noexcept(true);

				void compute_markov_model(_In_    int32_t,
									      _In_    int32_t,
										  _In_    double * __restrict,
										  _In_    int32_t * __restrict,
										  _In_    int32_t,
										  _In_    double * __restrict,
										  _In_    double * __restrict,
										  _In_    int32_t,
										  _In_    int32_t ,
										  _Inout_ int32_t[6]);
			};
		}
	}
}


#endif /*__LAM_MARKOV_MODEL_H__*/

#include "LAM_markov_model.h"
#include "LAM_timsac_iface.h"
#include "../LAM_malloc.h"
#include "../LAM_error_macros.h"
#include "../LAM_config.h"
#include "../LAM_indices.h"
#include "../LAM_common.h"
#include "LAM_fpexcept.h"

#if !defined (LAM_MARKOV_MODEL_DEALLOCATE_ARRAYS)
#define LAM_MARKOV_MODEL_DEALLOCATE_ARRAYS    \
	_mm_free(m_c0);							  \
	_mm_free(m_zz);						      \
	_mm_free(m_au);							  \
	_mm_free(m_bm);							  \
	_mm_free(m_vd);							  \
	_mm_free(m_b);						      \
	_mm_free(m_a);							  \
	_mm_free(m_a1);							  \
	_mm_free(m_g);							  \
	_mm_free(m_ik);							  \
	_mm_free(m_ij);							  \
	_mm_free(m_ir);							  \
	_mm_free(m_idd);
#endif

#if !defined (LAM_MARKOV_MODEL_ALLOCATE_TEMP_ARRAYS)
#define LAM_MARKOV_MODEL_ALLOCATE_TEMP_ARRAYS										       \
	int32_t * __restrict idd(lam_eimalloca4(static_cast<size_t>(m_k),align64B));           \
	int32_t * __restrict ir(lam_eimalloca4(static_cast<size_t>(m_k),align64B));            \
	int32_t * __restrict ij(lam_eimalloca4(static_cast<size_t>(m_k),align64B));            \
	int32_t * __restrict ik(lam_eimalloca4(static_cast<size_t>(m_k),align64B));            \
	double  * __restrict g(lam_edmalloca(static_cast<size_t>(m_mj4),align64B));            \
	double  * __restrict a1(lam_edmalloca(static_cast<size_t>(m_k*m_k),align64B));         \
	double  * __restrict a(lam_edmalloca(static_cast<size_t>(m_k*m_k),align64B));          \
	double  * __restrict b(lam_edmalloca(static_cast<size_t>(m_k*m_id),align64B));         \
	double  * __restrict vd(lam_edmalloca(static_cast<size_t>(m_mj4*m_mj4),align64B));     \
	double  * __restrict bm(lam_edmalloca(static_cast<size_t>(m_id*m_id*m_mj6),align64B)); \
	double  * __restrict au(lam_edmalloca(static_cast<size_t>(m_id*m_id*m_mj7),align64B)); \
	double  * __restrict zz(lam_edmalloca(static_cast<size_t>(m_id*m_id*m_mj7),align64B)); \
	double  * __restrict c0(lam_edmalloca(static_cast<size_t>(m_id*m_id),align64B));
#endif

#if !defined (LAM_MARKOV_MODEL_FP_EXCEPT_PROLOG)
#define LAM_MARKOV_MODEL_FP_EXCEPT_PROLOG(status)       \
	(status) = clear_fpexcepts();                       \
 if (0 != (status))  {                                  \
	  std::cerr << "clear_fpexcpets failed to clear FP environment!!!  Detection of floating-point exceptions will not be possible!!!\n"; \
	}
#endif

#if !defined (LAM_MARKOV_MODEL_FP_EXCEPT_EPILOG)
#define LAM_MARKOV_MODEL_FP_EXCEPT_EPILOG(status,fpexcepts)         \
	do {		                                                    \
									                                \
		if (0 != (status)) {                                        \
		  (fpexcepts[0]) = test_feinvalid(FE_INVALID);		        \
		  (fpexcepts[1]) = test_feinexact(FE_INEXACT);              \
		  (fpexcepts[2]) = test_fedivbyzero(FE_DIVBYZERO);          \
		  (fpexcepts[3]) = test_feunormal(FE_DENORMAL);             \
		  (fpexcepts[4]) = test_feoverflow(FE_OVERFLOW);            \
		  (fpexcepts[5]) = test_feunderflow(FE_UNDERFLOW);          \
		}											                \
  } while (0); 
#endif





using namespace lam::common;

lam::math::stat::MarkovModel
::MarkovModel()
:
m_k{},
m_id{},
m_mj4{},
m_mj6{},
m_mj7{},
m_ipq{},
m_iqm{},
m_aicd{},
m_idd(NULL),
m_ir(NULL),
m_ij(NULL),
m_ik(NULL),
m_g(NULL),
m_a1(NULL),
m_a(NULL),
m_b(NULL),
m_vd(NULL),
m_bm(NULL),
m_au(NULL),
m_zz(NULL),
m_c0(NULL) {}

lam::math::stat::
MarkovModel
::MarkovModel(_In_ const int32_t k,
			  _In_ const int32_t id,
			  _In_ const int32_t mj4,
			  _In_ const int32_t mj6,
			  _In_ const int32_t mj7)
:
m_k{ k },
m_id{ id },
m_mj4{ mj4 },
m_mj6{ mj6 },
m_mj7{ mj7 },
m_ipq{},
m_iqm{},
m_aicd{},
m_idd(lam_eimalloca4(static_cast<size_t>(m_k),align64B)),
m_ir(lam_eimalloca4(static_cast<size_t>(m_k),align64B)),
m_ij(lam_eimalloca4(static_cast<size_t>(m_k),align64B)),
m_ik(lam_eimalloca4(static_cast<size_t>(m_k),align64B)),
m_g(lam_edmalloca(static_cast<size_t>(m_mj4),align64B)),
m_a1(lam_edmalloca(static_cast<size_t>(m_k*m_k),align64B)),
m_a(lam_edmalloca(static_cast<size_t>(m_k*m_k),align64B)),
m_b(lam_edmalloca(static_cast<size_t>(m_k*m_id),align64B)),
m_vd(lam_edmalloca(static_cast<size_t>(m_mj4*m_mj4),align64B)),
m_bm(lam_edmalloca(static_cast<size_t>(m_id*m_id*m_mj6),align64B)),
m_au(lam_edmalloca(static_cast<size_t>(m_id*m_id*m_mj7),align64B)),
m_zz(lam_edmalloca(static_cast<size_t>(m_id*m_id*m_mj7),align64B)),
m_c0(lam_edmalloca(static_cast<size_t>(m_id*m_id), align64B)) {

	init_array(&m_idd[0], static_cast<uint64_t>(m_k),-1);
	init_array(&m_ir[0], static_cast<uint64_t>(m_k), -1);
	init_array(&m_ij[0], static_cast<uint64_t>(m_k),-1);
	init_array(&m_ik[0], static_cast<uint64_t>(m_k), -1);
	avx256_init_unroll8x(&m_g[0],  static_cast<size_t>(m_mj4),           0.0);
	avx256_init_unroll8x(&m_a1[0], static_cast<size_t>(m_k*m_k),         0.0);
	avx256_init_unroll8x(&m_a[0],  static_cast<size_t>(m_k*m_k),         0.0);
	avx256_init_unroll8x(&m_b[0],  static_cast<size_t>(m_k*m_id),        0.0);
	avx256_init_unroll8x(&m_vd[0], static_cast<size_t>(m_mj4*m_mj4),     0.0);
	avx256_init_unroll8x(&m_bm[0], static_cast<size_t>(m_id*m_id*m_mj6), 0.0);
	avx256_init_unroll8x(&m_au[0], static_cast<size_t>(m_id*m_id*m_mj7), 0.0);
	avx256_init_unroll8x(&m_zz[0], static_cast<size_t>(m_id*m_id*m_mj7), 0.0);
	avx256_init_unroll8x(&m_c0[0], static_cast<size_t>(m_id*m_id),       0.0);
}

lam::math::stat
::MarkovModel
::MarkovModel(_In_ const MarkovModel &x)
:
m_k{ x.m_k },
m_id{ x.m_id },
m_mj4{ x.m_mj4 },
m_mj6{ x.m_mj6 },
m_mj7{ x.m_mj7 },
m_ipq{ x.m_ipq },
m_iqm{ x.m_iqm },
m_aicd{x.m_aicd},
m_idd(lam_eimalloca4(static_cast<size_t>(m_k), align64B)),
m_ir(lam_eimalloca4(static_cast<size_t>(m_k), align64B)),
m_ij(lam_eimalloca4(static_cast<size_t>(m_k), align64B)),
m_ik(lam_eimalloca4(static_cast<size_t>(m_k), align64B)),
m_g(lam_edmalloca(static_cast<size_t>(m_mj4), align64B)),
m_a1(lam_edmalloca(static_cast<size_t>(m_k*m_k), align64B)),
m_a(lam_edmalloca(static_cast<size_t>(m_k*m_k), align64B)),
m_b(lam_edmalloca(static_cast<size_t>(m_k*m_id), align64B)),
m_vd(lam_edmalloca(static_cast<size_t>(m_mj4*m_mj4), align64B)),
m_bm(lam_edmalloca(static_cast<size_t>(m_id*m_id*m_mj6), align64B)),
m_au(lam_edmalloca(static_cast<size_t>(m_id*m_id*m_mj7), align64B)),
m_zz(lam_edmalloca(static_cast<size_t>(m_id*m_id*m_mj7), align64B)),
m_c0(lam_edmalloca(static_cast<size_t>(m_id*m_id), align64B)) {

	memcpy(&m_idd[0], &x.m_idd[0],        static_cast<size_t>(m_k));
	memcpy(&m_ir[0],  &x.m_ir[0],         static_cast<size_t>(m_k));
	memcpy(&m_ij[0],  &x.m_ij[0],         static_cast<size_t>(m_k));
	memcpy(&m_ik[0],  &x.m_ik[0],         static_cast<size_t>(m_k));
	avx256_memcpy8x(&m_g[0], &x.m_g[0],   static_cast<size_t>(m_mj4));
	avx256_memcpy8x(&m_a1[0], &x.m_a1[0], static_cast<size_t>(m_k*m_k));
	avx256_memcpy8x(&m_a[0], &x.m_a[0],   static_cast<size_t>(m_k*m_k));
	avx256_memcpy8x(&m_b[0], &x.m_b[0],   static_cast<size_t>(m_k*m_id));
	avx256_memcpy8x(&m_vd[0], &x.m_vd[0], static_cast<size_t>(m_mj4*m_mj4));
	avx256_memcpy8x(&m_bm[0], &x.m_bm[0], static_cast<size_t>(m_id*m_id*m_mj6));
	avx256_memcpy8x(&m_au[0], &x.m_au[0], static_cast<size_t>(m_id*m_id*m_mj7));
	avx256_memcpy8x(&m_zz[0], &x.m_zz[0], static_cast<size_t>(m_id*m_id*m_mj7));
	avx256_memcpy8x(&m_c0[0], &x.m_c0[0], static_cast<size_t>(m_id*m_id));
}

lam::math::stat
::MarkovModel
::MarkovModel(_In_ MarkovModel &&x)
:
m_k{ x.m_k },
m_id{ x.m_id },
m_mj4{ x.m_mj4 },
m_mj6{ x.m_mj6 },
m_mj7{ x.m_mj7 },
m_ipq{ x.m_ipq },
m_iqm{ x.m_iqm },
m_aicd{ x.m_aicd },
m_idd(NULL),
m_ir(NULL),
m_ij(NULL),
m_ik(NULL),
m_g(NULL),
m_a1(NULL),
m_a(NULL),
m_b(NULL),
m_vd(NULL),
m_bm(NULL),
m_au(NULL),
m_zz(NULL),
m_c0(NULL) {

	m_idd = x.m_idd,m_ir = x.m_ir,
	m_ij  = x.m_ij, m_ik = x.m_ik,
	m_g   = x.m_g,  m_a1 = x.m_a1,
	m_a   = x.m_a,  m_b  = x.m_b,
	m_vd  = x.m_vd, m_bm = x.m_bm,
	m_au  = x.m_au, m_zz = x.m_zz,
	m_c0  = x.m_c0;

	x.m_k = 0, x.m_id = 0, 
	x.m_mj4 = 0, x.m_mj6 = 0,
	x.m_mj7 = 0;
	x.m_idd = NULL, x.m_ir = NULL,
	x.m_ij  = NULL, x.m_ik = NULL,
	x.m_g   = NULL, x.m_a1 = NULL,
	x.m_a   = NULL, x.m_b  = NULL,
	x.m_vd  = NULL, x.m_bm = NULL,
	x.m_au  = NULL, x.m_zz = NULL,
	x.m_c0  = NULL;
}

lam::math::stat
::MarkovModel
::~MarkovModel() {

	if (m_c0 != NULL) {
		_mm_free(m_c0);
		m_c0 = NULL;
	}
	if (m_zz != NULL){
		_mm_free(m_zz);
		m_zz = NULL;
	}
	if (m_au != NULL) {
		_mm_free(m_au);
		m_au = NULL;
	}
	if (m_bm != NULL) {
		_mm_free(m_bm);
		m_bm = NULL;
	}
	if (m_vd != NULL) {
		_mm_free(m_vd);
		m_vd = NULL;
	}
	if (m_b != NULL) {
		_mm_free(m_b);
		m_b = NULL;
	}
	if (m_a != NULL) {
		_mm_free(m_a);
		m_a = NULL;
	}
	if (m_a1 != NULL) {
		_mm_free(m_a1);
		m_a1 = NULL;
	}
	if (m_g != NULL) {
		_mm_free(m_g);
		m_g = NULL;
	}
	if (m_ik != NULL) {
		_mm_free(m_ik);
		m_ik = NULL;
	}
	if (m_ij != NULL) {
		_mm_free(m_ij);
		m_ij  = NULL;
	}
	if (m_ir != NULL) {
		_mm_free(m_ir);
		m_ir = NULL;
	}
	if (m_idd != NULL) {
		_mm_free(m_idd);
		m_idd = NULL;
	}
}

lam::math::stat::MarkovModel &
lam::math::stat::MarkovModel
::operator=(_In_ const MarkovModel &x) {

	if (this == &x) return (*this);
	m_k = x.m_k, m_id = x.m_id,
	m_mj4 = x.m_mj4, m_mj6 = x.m_mj6,
	m_mj7 = x.m_mj7, m_ipq = x.m_ipq,
	m_iqm = x.m_iqm, m_aicd = x.m_aicd;
	LAM_MARKOV_MODEL_DEALLOCATE_ARRAYS

	LAM_MARKOV_MODEL_ALLOCATE_TEMP_ARRAYS

	memcpy(&idd[0], &x.m_idd[0],        static_cast<size_t>(m_k));
	memcpy(&ir[0],  &x.m_ir[0],         static_cast<size_t>(m_k));
	memcpy(&ij[0],  &x.m_ij[0],         static_cast<size_t>(m_k));
	memcpy(&ik[0],  &x.m_ik[0],         static_cast<size_t>(m_k));
	avx256_memcpy8x(&g[0],  &x.m_g[0],  static_cast<size_t>(m_mj4));
	avx256_memcpy8x(&a1[0], &x.m_a1[0], static_cast<size_t>(m_k*m_k));
	avx256_memcpy8x(&a[0],  &x.m_a[0],  static_cast<size_t>(m_k*m_k));
	avx256_memcpy8x(&b[0],  &x.m_b[0],  static_cast<size_t>(m_k*m_id));
	avx256_memcpy8x(&vd[0], &x.m_vd[0], static_cast<size_t>(m_mj4*m_mj4));
	avx256_memcpy8x(&bm[0], &x.m_bm[0], static_cast<size_t>(m_id*m_id*m_mj6));
	avx256_memcpy8x(&au[0], &x.m_au[0], static_cast<size_t>(m_id*m_id*m_mj7));
	avx256_memcpy8x(&zz[0], &x.m_zz[0], static_cast<size_t>(m_id*m_id*m_mj7));
	avx256_memcpy8x(&c0[0], &x.m_c0[0], static_cast<size_t>(m_id*m_id));

	m_idd = idd, m_ir = ir,
	m_ij  = ij,  m_ik = ik,
	m_g   = g,   m_a1 = a1,
	m_a   = a,   m_b  = b,
	m_vd  = vd,  m_bm = bm,
	m_au  = au,  m_zz = zz,
	m_c0  = c0;

	return (*this);
}

lam::math::stat::MarkovModel &
lam::math::stat::MarkovModel
::operator=(_In_ MarkovModel &&x) {
	
	if (this == &x)  return (*this);

	m_k = x.m_k, m_id = x.m_id,
	m_mj4 = x.m_mj4, m_mj6 = x.m_mj6,
	m_mj7 = x.m_mj7, m_ipq = x.m_ipq,
	m_iqm = x.m_iqm, m_aicd = x.m_aicd;

	LAM_MARKOV_MODEL_DEALLOCATE_ARRAYS

	m_idd = x.m_idd, m_ir = x.m_ir,
	m_ij  = x.m_ij,  m_ik = x.m_ik,
	m_g   = x.m_g,   m_a1 = x.m_a1,
	m_a   = x.m_a,   m_b  = x.m_b,
	m_vd  = x.m_vd,  m_bm = x.m_bm,
	m_au  = x.m_au,  m_zz = x.m_zz,
	m_c0  = x.m_c0;

	x.m_k   = 0, x.m_id  = 0,
	x.m_mj4 = 0, x.m_mj6 = 0,
	x.m_mj7 = 0;

	x.m_idd = NULL, x.m_ir = NULL,
	x.m_ij  = NULL, x.m_ik = NULL,
	x.m_g   = NULL, x.m_a1 = NULL,
	x.m_a   = NULL, x.m_b  = NULL,
	x.m_vd  = NULL, x.m_bm = NULL,
	x.m_au  = NULL, x.m_zz = NULL,
	x.m_c0  = NULL;

	return (*this);
}

void
lam::math::stat
::MarkovModel
::compute_markov_model(_In_  int32_t n,
					   _In_  int32_t lagh3,
					   _In_  double * __restrict cyy0,
					   _In_  int32_t * __restrict nh,
					   _In_  int32_t jaw,
					   _In_  double * __restrict aw1,
					   _In_  double * __restrict b1,
					   _In_  int32_t icont,
					   _In_  int32_t mj3,
					   _Inout_ int32_t fpexcepts[6]) {

	int32_t status{};

	LAM_MARKOV_MODEL_FP_EXCEPT_PROLOG(status)
	// Call F77 C-wrapper
	MOD_TIMSAC_mp_MARKOVF(&n,
						  &lagh3,
						  &m_id,
						  &cyy0[0],
						  &m_k,
						  &nh[0],
						  &jaw,
						  &aw1[0],
						  &b1[0],
						  &icont, 
						  &m_idd[0],
						  &m_ir[0],
						  &m_ij[0],
						  &m_ik[0],
						  &m_ipq,
						  &m_g[0],
						  &m_a1[0],
						  &m_a[0],
						  &m_b[0],
						  &m_vd[0],
						  &m_iqm,
						  &m_bm[0],
						  &m_au[0],
						  &m_zz[0],
						  &m_c0[0],
						  &m_aicd,
						  &mj3,
						  &m_mj4,
						  &m_mj6,
						  &m_mj7 );

	LAM_MARKOV_MODEL_FP_EXCEPT_EPILOG(status,fpexcepts)

}



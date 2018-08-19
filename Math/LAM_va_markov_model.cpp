
#include <iostream>

#include "LAM_va_markov_model.h"
#include "LAM_timsac_iface.h"

#include "LAM_fpexcept.h"

#if !defined (LAM_VA_MARKOV_MODEL_FP_EXCEPT_PROLOG)
#define LAM_VA_MARKOV_MODEL_FP_EXCEPT_PROLOG(status)        \
	(status) = clear_fpexcepts();                           \
    if (0 != (status))  {                                   \
	  std::cerr << "clear_fpexcpets failed to clear FP environment!!!  Detection of floating-point exceptions will not be possible!!!\n"; \
	}
#endif

#if !defined (LAM_VA_MARKOV_MODEL_FP_EXCEPT_EPILOG)
#define LAM_VA_MARKOV_MODEL_FP_EXCEPT_EPILOG(status,fpexcepts)      \
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

lam::math::stat
::MarkovModelVa
::MarkovModelVa(_In_ const int32_t k,
			    _In_ const int32_t id,
				_In_ const int32_t mj4,
				_In_ const int32_t mj6,
				_In_ const int32_t mj7,
				_In_ const int32_t ival,
				_In_ const double  dval)
:
m_k{ k },
m_id{ id },
m_mj4{ mj4 },
m_mj6{ mj6 },
m_mj7{ mj7 },
m_ipq{},
m_iqm{},
m_aicd{},
m_idd(ival, static_cast<size_t>(m_k)),
m_ir(ival,  static_cast<size_t>(m_k)),
m_ij(ival,  static_cast<size_t>(m_k)),
m_ik(ival,  static_cast<size_t>(m_k)),
m_g( dval,  static_cast<size_t>(m_mj4)),
m_a1(dval,  static_cast<size_t>(m_k*m_k)),
m_a(dval,   static_cast<size_t>(m_k*m_k)),
m_b(dval,   static_cast<size_t>(m_k*m_id)),
m_vd(dval,  static_cast<size_t>(m_mj4*m_mj4)),
m_bm(dval,  static_cast<size_t>(m_id*m_id*m_mj6)),
m_au(dval,  static_cast<size_t>(m_id*m_id*m_mj7)),
m_zz(dval,  static_cast<size_t>(m_id*m_id*m_mj7)),
m_c0(dval,  static_cast<size_t>(m_id*m_id)) {}

lam::math::stat
::MarkovModelVa
::MarkovModelVa(_In_ const MarkovModelVa &x)
:
m_k{ x.m_k },
m_id{ x.m_id },
m_mj4{ x.m_mj4 },
m_mj6{ x.m_mj6 },
m_mj7{ x.m_mj7 },
m_ipq{ x.m_ipq },
m_iqm{ x.m_iqm },
m_aicd{x.m_aicd},
m_idd(x.m_idd),
m_ir(x.m_ir),
m_ij(x.m_ij),
m_ik(x.m_ik),
m_g(x.m_g),
m_a1(x.m_a1),
m_a(x.m_a),
m_b(x.m_b),
m_vd(x.m_vd),
m_bm(x.m_bm),
m_au(x.m_au),
m_zz(x.m_zz),
m_c0(x.m_c0)  {}


lam::math::stat
::MarkovModelVa
::MarkovModelVa(_In_ MarkovModelVa &&x)
:
m_k{    x.m_k },
m_id{   x.m_id },
m_mj4{  x.m_mj4 },
m_mj6{  x.m_mj6 },
m_mj7{  x.m_mj7 },
m_ipq{  x.m_ipq },
m_iqm{  x.m_iqm },
m_aicd{ x.m_aicd },
m_idd(  std::move(x.m_idd)),
m_ir(   std::move(x.m_ir)),
m_ij(   std::move(x.m_ij)),
m_ik(   std::move(x.m_ik)),
m_g(    std::move(x.m_g)),
m_a1(   std::move(x.m_a1)),
m_a(    std::move(x.m_a)),
m_b(    std::move(x.m_b)),
m_vd(   std::move(x.m_vd)),
m_bm(   std::move(x.m_bm)),
m_au(   std::move(x.m_au)),
m_zz(   std::move(x.m_zz)),
m_c0(   std::move(x.m_c0))  {}

lam::math::stat::MarkovModelVa &
lam::math::stat
::MarkovModelVa::operator=(_In_ const MarkovModelVa &x) {
	if (this == &x) return (*this);

	m_k   = x.m_k,   m_id  = x.m_id,
	m_mj4 = x.m_mj4, m_mj6 = x.m_mj6,
	m_mj7 = x.m_mj7, m_ipq = x.m_ipq,
	m_iqm = x.m_iqm, m_aicd = x.m_aicd;

	m_idd.operator=(x.m_idd),
	m_ir.operator=( x.m_ir),
	m_ij.operator=( x.m_ij),
	m_ik.operator=( x.m_ik),
	m_g.operator=(  x.m_g),
	m_a1.operator=( x.m_a1),
	m_a.operator=(  x.m_a),
	m_b.operator=(  x.m_b),
	m_vd.operator=( x.m_vd),
	m_bm.operator=( x.m_bm),
	m_au.operator=( x.m_au),
	m_zz.operator=( x.m_zz),
	m_c0.operator=( x.m_c0);

	return (*this);
}

lam::math::stat::MarkovModelVa &
lam::math::stat
::MarkovModelVa::operator=(_In_ MarkovModelVa &&x) {
	if (this == &x) return (*this);

	m_k = x.m_k, m_id = x.m_id,
	m_mj4 = x.m_mj4, m_mj6 = x.m_mj6,
	m_mj7 = x.m_mj7, m_ipq = x.m_ipq,
	m_iqm = x.m_iqm, m_aicd = x.m_aicd;
	
	m_idd.operator=( std::move(x.m_idd)),
	m_ir.operator=(  std::move(x.m_ir)),
	m_ij.operator=(  std::move(x.m_ij)),
	m_ik.operator=(  std::move(x.m_ik)),
	m_g.operator=(   std::move(x.m_g)),
	m_a1.operator=(  std::move(x.m_a1)),
	m_a.operator=(   std::move(x.m_a)),
	m_b.operator=(   std::move(x.m_b)),
    m_vd.operator=(  std::move(x.m_vd)),
	m_bm.operator=(  std::move(x.m_bm)),
	m_au.operator=(  std::move(x.m_au)),
	m_zz.operator=(  std::move(x.m_zz)),
	m_c0.operator=(  std::move(x.m_c0));

	return (*this);
}

void
lam::math::stat
::MarkovModelVa
::compute_markov_model(_In_ int32_t n,
					   _In_ int32_t lagh3,
					   _In_ VAf64 & cyy0,
					   _In_ VAi32 & nh,
					   _In_ int32_t jaw,
					   _In_ VAf64 & aw1,
					   _In_ VAf64 & b1,
					   _In_ int32_t icont,
					   _In_ int32_t mj3,
					   _In_ int32_t fpexcepts[6]) {

	int32_t status{};
	// Call F77 C-wrapper
	LAM_VA_MARKOV_MODEL_FP_EXCEPT_PROLOG(status)

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
						  &m_mj7);

	LAM_VA_MARKOV_MODEL_FP_EXCEPT_EPILOG(status,fpexcepts)

}








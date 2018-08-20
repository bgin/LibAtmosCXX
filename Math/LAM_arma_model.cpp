
#include <iostream>
#include "LAM_arma_model.h"
#include "LAM_timsac_iface.h"
#include "LAM_fpexcept.h"


#if !defined (LAM_ARMA_MODEL_FP_EXCEPT_PROLOG)
#define LAM_ARMA_MODEL_FP_EXCEPT_PROLOG(status)             \
	(status) = clear_fpexcepts();                           \
    if (0 != (status))  {                                   \
	  std::cerr << "clear_fpexcpets failed to clear FP environment!!!  Detection of floating-point exceptions will not be possible!!!\n"; \
	}
#endif

#if !defined (LAM_ARMA_MODEL_FP_EXCEPT_EPILOG)
#define LAM_ARMA_MODEL_FP_EXCEPT_EPILOG(status,fpexcepts)  \
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
::ArmaModel
::ArmaModel(_In_ const int32_t nmax,
			_In_ const int32_t mmax,
		    _In_ const int32_t ival,
		    _In_ const double  dval)
:
m_newn{},
m_nmax{ nmax },
m_mmax{ mmax },
m_kq{},
m_kp{},
m_aicm{},
m_iq(ival,static_cast<size_t>(m_nmax)),
m_b2(dval,static_cast<size_t>(m_mmax*m_nmax)),
m_ip(ival,static_cast<size_t>(m_nmax)),
m_a2(dval,static_cast<size_t>(m_mmax*m_nmax)),
m_std(dval,static_cast<size_t>(m_mmax*m_nmax)),
m_cxx2(dval,static_cast<size_t>(m_nmax)),
m_g(dval,static_cast<size_t>(m_mmax*m_nmax)),
m_saic(dval,static_cast<size_t>(m_nmax)) {}

lam::math::stat
::ArmaModel
::ArmaModel(_In_ const ArmaModel &x)
:
m_newn{ x.m_newn },
m_nmax{ x.m_nmax },
m_mmax{ x.m_mmax },
m_kq{   x.m_kq },
m_kp{   x.m_kp },
m_aicm{ x.m_aicm},
m_iq(   x.m_iq),
m_b2(   x.m_b2),
m_ip(   x.m_ip),
m_a2(   x.m_a2),
m_std(  x.m_std),
m_cxx2( x.m_cxx2),
m_g(    x.m_g),
m_saic( x.m_saic)  {}

lam::math::stat
::ArmaModel
::ArmaModel(_In_ ArmaModel &&x)
:
m_newn{ x.m_newn },
m_nmax{ x.m_nmax },
m_mmax{ x.m_mmax },
m_kq{   x.m_kq },
m_kp{   x.m_kp },
m_aicm{ x.m_aicm},
m_iq(   std::move(x.m_iq)),
m_b2(   std::move(x.m_b2)),
m_ip(   std::move(x.m_ip)),
m_a2(   std::move(x.m_a2)),
m_std(  std::move(x.m_std)),
m_cxx2( std::move(x.m_cxx2)),
m_g(    std::move(x.m_g)),
m_saic( std::move(x.m_saic))  {}

lam::math::stat::ArmaModel &
lam::math::stat::ArmaModel
::operator=(_In_ const ArmaModel &x) {

	if (this == &x) return (*this);

	m_newn = x.m_newn, m_nmax = x.m_nmax,
	m_mmax = x.m_mmax, m_kq   = x.m_kq,
	m_kp   = x.m_kp,   m_aicm = x.m_aicm;

	m_iq.operator=(   x.m_iq),
	m_b2.operator=(   x.m_b2),
	m_ip.operator=(   x.m_ip),
	m_a2.operator=(   x.m_a2),
	m_std.operator=(  x.m_std),
	m_cxx2.operator=( x.m_cxx2),
	m_g.operator=(    x.m_g),
	m_saic.operator=( x.m_saic);

	return (*this);
}

lam::math::stat::ArmaModel &
lam::math::stat::ArmaModel
::operator=(_In_ ArmaModel &&x) {
	
	if (this == &x) return (*this);

	m_newn = x.m_newn, m_nmax = x.m_nmax,
	m_mmax = x.m_mmax, m_kq = x.m_kq,
	m_kp = x.m_kp, m_aicm = x.m_aicm;

	m_iq.operator=(   std::move(x.m_iq)),
	m_b2.operator=(   std::move(x.m_b2)),
	m_ip.operator=(   std::move(x.m_ip)),
	m_a2.operator=(   std::move(x.m_a2)),
	m_std.operator=(  std::move(x.m_std)),
	m_cxx2.operator=( std::move(x.m_cxx2)),
	m_g.operator=(    std::move(x.m_g)),
	m_saic.operator=( std::move(x.m_saic));

	return (*this);
}

void
lam::math::stat
::ArmaModel::compute_arma_model(_In_ int32_t n,
							   _In_ int32_t lagh01,
							   _In_ VAf64 & cyy1,
							   _In_ int32_t newl1,
						       _In_ VAi32 & iqi1,
							   _In_ VAf64 & b1,
							   _In_ VAi32 & ipi1,
							   _In_ VAf64 & a1,
							   _In_ int32_t lmax,
							   _Inout_ int32_t fpexcepts[6]) {

	int32_t status{};

	LAM_ARMA_MODEL_FP_EXCEPT_PROLOG(status)

	MOD_TIMSAC_mp_AUTARMF(&n,
						  &lagh01,
						  &cyy1[0],
						  &newl1,
						  &iqi1[0],
						  &b1[0],
						  &ipi1[0],
						  &a1[0],
						  &m_newn,
						  &m_iq[0],
						  &m_b2[0],
						  &m_ip[0],
						  &m_a2[0],
						  &m_std[0],
						  &m_cxx2[0],
						  &m_g[0],
						  &m_saic[0],
						  &m_aicm,
						  &m_kq,
						  &m_kp,
						  &lmax,
						  &m_mmax,
						  &m_nmax );

	LAM_ARMA_MODEL_FP_EXCEPT_EPILOG(status,fpexcepts)

}










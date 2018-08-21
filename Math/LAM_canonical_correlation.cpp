
#include <iostream>
#include "LAM_canonical_correlation.h"
#include "LAM_timsac_iface.h"
#include "LAM_fpexcept.h"

#if !defined (LAM_CANONICAL_CORRELATION_FP_EXCEPT_PROLOG)
#define LAM_CANONICAL_CORRELATION_FP_EXCEPT_PROLOG(status)  \
	(status) = clear_fpexcepts();                           \
    if (0 != (status))  {                                   \
	  std::cerr << "clear_fpexcpets failed to clear FP environment!!!  Detection of floating-point exceptions will not be possible!!!\n"; \
	}
#endif

#if !defined (LAM_CANONICAL_CORRELATION_FP_EXCEPT_EPILOG)
#define LAM_CANONICAL_CORRELATION_FP_EXCEPT_EPILOG(status,fpexcepts) \
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
::CanonicalCorrelation
::CanonicalCorrelation(_In_ const int32_t mj1,
					   _In_ const int32_t mj2,
					   _In_ const int32_t ival,
					   _In_ const double dval)
:
m_mj1{ mj1 },
m_mj2{ mj2 },
m_mo{},
m_nc{},
m_m1m{},
m_m1n{},
m_oaic{},
m_coeff(dval,  static_cast<size_t>(m_mj2)),
m_sd(dval,     static_cast<size_t>(m_mj1+1)),
m_aic(dval,    static_cast<size_t>(m_mj1+1)),
m_a(dval,      static_cast<size_t>(m_mj1)),
m_mm1(ival,    static_cast<size_t>(m_mj1)),
m_mm2(ival,    static_cast<size_t>(m_mj1)),
m_v(dval,      static_cast<size_t>(m_mj1*m_mj1*m_mj1)),
m_z(dval,      static_cast<size_t>(m_mj1*m_mj1)),
m_y(dval,      static_cast<size_t>(m_mj1*m_mj1)),
m_xx(dval,     static_cast<size_t>(m_mj1*m_mj1)),
m_ndt(ival,    static_cast<size_t>(m_mj1*m_mj1)),
m_x3(dval,     static_cast<size_t>(m_mj1*m_mj1)),
m_x3min(dval,  static_cast<size_t>(m_mj1)),
m_min3(ival,   static_cast<size_t>(m_mj1)),
m_beta(dval,   static_cast<size_t>(m_mj1)),
m_alpha(dval,  static_cast<size_t>(m_mj1)) {}

lam::math::stat
::CanonicalCorrelation
::CanonicalCorrelation(_In_ const CanonicalCorrelation &x)
:
m_mj1{   x.m_mj1 },
m_mj2{   x.m_mj2 },
m_mo{    x.m_mo },
m_nc{    x.m_nc },
m_m1m{   x.m_m1m },
m_m1n{   x.m_m1n },
m_oaic{  x.m_oaic },
m_coeff{ x.m_coeff },
m_sd{    x.m_sd },
m_aic{   x.m_aic },
m_a{     x.m_a },
m_mm1{   x.m_mm1 },
m_mm2{   x.m_mm2 },
m_v{     x.m_v },
m_z{     x.m_z },
m_y{     x.m_y },
m_xx{    x.m_xx },
m_ndt{   x.m_ndt },
m_x3{    x.m_x3 },
m_x3min{ x.m_x3min },
m_min3{  x.m_min3 },
m_beta{  x.m_beta },
m_alpha{ x.m_alpha } {}

lam::math::stat
::CanonicalCorrelation
::CanonicalCorrelation(_In_ CanonicalCorrelation &&x)
:
m_mj1{ x.m_mj1 },
m_mj2{ x.m_mj2 },
m_mo{ x.m_mo },
m_nc{ x.m_nc },
m_m1m{ x.m_m1m },
m_m1n{ x.m_m1n },
m_oaic{ x.m_oaic },
m_coeff{ std::move(x.m_coeff) },
m_sd{ std::move(x.m_sd) },
m_aic{ std::move(x.m_aic) },
m_a{ std::move(x.m_a) },
m_mm1{ std::move(x.m_mm1) },
m_mm2{ std::move(x.m_mm2) },
m_v{ std::move(x.m_v) },
m_z{ std::move(x.m_z) },
m_y{ std::move(x.m_y) },
m_xx{ std::move(x.m_xx) },
m_ndt{ std::move(x.m_ndt) },
m_x3{ std::move(x.m_x3) },
m_x3min{ std::move(x.m_x3min) },
m_min3{ std::move(x.m_min3) },
m_beta{ std::move(x.m_beta) },
m_alpha{ std::move(x.m_alpha) } {}

lam::math::stat::CanonicalCorrelation &
lam::math::stat::CanonicalCorrelation
::operator=(_In_ const CanonicalCorrelation &x){
	if (this == &x) return (*this);

	CanonicalCorrelation tmp{x};
	std::swap(*this,tmp);
	return (*this);
}

lam::math::stat::CanonicalCorrelation &
lam::math::stat::CanonicalCorrelation
::operator=(_In_ CanonicalCorrelation &&x) {
	if (this == &x) return (*this);

	*this = std::move(x);
	return (*this);
}

void
lam::math::stat
::CanonicalCorrelation::compute(_In_ int32_t n,
							    _In_ int32_t lagh3,
							    _In_ VAf64 & cyy,
								_In_ int32_t ifpl1,
								_Inout_ int32_t fpexcepts[6]) {

	int32_t status{};

	LAM_CANONICAL_CORRELATION_FP_EXCEPT_PROLOG(status)

		MOD_TIMSAC_mp_CANARMF(&n,
							  &lagh3,
							  &cyy[0],
							  &m_coeff[0],
							  &ifpl1,
							  &m_sd[0],
							  &m_aic[0],
							  &m_oaic,
							  &m_mo,
							  &m_a[0],
							  &m_nc,
							  &m_mm1[0],
							  &m_mm2[0],
							  &m_v[0],
							  &m_z[0],
							  &m_y[0],
							  &m_xx[0],
							  &m_ndt[0],
							  &m_x3[0],
							  &m_x3min[0],
							  &m_min3[0],
							  &m_m1m,
							  &m_beta[0],
							  &m_m1n,
							  &m_alpha[0],
							  &m_mj1,
							  &m_mj2);

	LAM_CANONICAL_CORRELATION_FP_EXCEPT_EPILOG(status,fpexcepts)
}




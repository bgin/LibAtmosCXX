
#include "LAM_wsr88d_vcs.h"
#include "../LAM_malloc.h"
#include "../LAM_common.h"
#include "../LAM_error_macros.h"
#include "../LAM_config.h"
#include "../Math/LAM_constants.h"

using namespace lam::common;

#if !defined LAM_WSR88D_VCS_DEALLOCATE_MEMBERS
#define LAM_WSR88D_VCS_DEALLOCATE_MEMBERS \
do {									  \
	_mm_free(m_HMinV);					  \
    _mm_free(m_MinV);					  \
    _mm_free(m_HMaxV);					  \
    _mm_free(m_MaxV);					  \
    _mm_free(m_Range);					  \
    _mm_free(m_Azimuth);				 \
  } while (0);
#endif

lam::wsr88d::
VCS_t::VCS_t()
:
m_nsize{},
m_Azimuth(NULL),
m_Range(NULL),
m_MaxV(NULL),
m_HMaxV(NULL),
m_MinV(NULL),
m_HMinV(NULL) {}

lam::wsr88d::
VCS_t::VCS_t(_In_ const int32_t nsize)
:
m_nsize{nsize},
m_Azimuth(lam_edmalloca(static_cast<size_t>(m_nsize),align64B)),
m_Range(lam_edmalloca(static_cast<size_t>(m_nsize), align64B)),
m_MaxV(lam_edmalloca(static_cast<size_t>(m_nsize), align64B)),
m_HMaxV(lam_edmalloca(static_cast<size_t>(m_nsize), align64B)),
m_MinV(lam_edmalloca(static_cast<size_t>(m_nsize), align64B)),
m_HMinV(lam_edmalloca(static_cast<size_t>(m_nsize), align64B)) {
	using namespace lam::math::constants;
	int32_t i;
	for (i = 0; i != ROUND_TO_FOUR(m_nsize,4); i += 8) {
		_mm256_store_pd(&m_Azimuth[i+0], vinf);
		_mm256_store_pd(&m_Azimuth[i+4], vinf);
		_mm256_store_pd(&m_Range[i+0],   vinf);
		_mm256_store_pd(&m_Range[i+4],   vinf);
		_mm256_store_pd(&m_MaxV[i+0],    vinf);
		_mm256_store_pd(&m_MaxV[i+4],    vinf);
		_mm256_store_pd(&m_HMaxV[i+0],   vinf);
		_mm256_store_pd(&m_HMaxV[i+4],   vinf);
		_mm256_store_pd(&m_MinV[i+0],    vinf);
		_mm256_store_pd(&m_MinV[i+4],    vinf);
		_mm256_store_pd(&m_HMinV[i+0],   vinf);
		_mm256_store_pd(&m_HMinV[i+4],   vinf);
	}
	for (; i != m_nsize; ++i) {
		m_Azimuth[i] = dinf;
		m_Range[i]   = dinf;
		m_MaxV[i]    = dinf;
		m_HMaxV[i]   = dinf;
		m_MinV[i]    = dinf;
		m_HMinV[i]   = dinf;
	}

}

lam::wsr88d::
VCS_t::VCS_t(_In_ const VCS_t &x)
:
m_nsize{x.m_nsize},
m_Azimuth(lam_edmalloca(static_cast<size_t>(m_nsize),align64B)),
m_Range(lam_edmalloca(static_cast<size_t>(m_nsize), align64B)),
m_MaxV(lam_edmalloca(static_cast<size_t>(m_nsize), align64B)),
m_HMaxV(lam_edmalloca(static_cast<size_t>(m_nsize), align64B)),
m_MinV(lam_edmalloca(static_cast<size_t>(m_nsize), align64B)),
m_HMinV(lam_edmalloca(static_cast<size_t>(m_nsize), align64B)) {
	
	avx256_memcpy8x(&m_Azimuth[0],&x.m_Azimuth[0],static_cast<size_t>(m_nsize));
	avx256_memcpy8x(&m_Range[0],  &x.m_Range[0],  static_cast<size_t>(m_nsize));
	avx256_memcpy8x(&m_MaxV[0],   &x.m_MaxV[0],   static_cast<size_t>(m_nsize));
	avx256_memcpy8x(&m_HMaxV[0],  &x.m_HMaxV[0],  static_cast<size_t>(m_nsize));
	avx256_memcpy8x(&m_MinV[0],   &x.m_MinV[0],   static_cast<size_t>(m_nsize));
	avx256_memcpy8x(&m_HMinV[0],  &x.m_HMinV[0],  static_cast<size_t>(m_nsize));

}

lam::wsr88d::
VCS_t::VCS_t(_In_ VCS_t &&x)
:
m_nsize{x.m_nsize},
m_Azimuth(NULL),
m_Range(NULL),
m_MaxV(NULL),
m_HMaxV(NULL),
m_MinV(NULL),
m_HMinV(NULL) {
	m_Azimuth = &x.m_Azimuth[0];
	m_Range   = &x.m_Range[0];
	m_MaxV    =	&x.m_MaxV[0];
	m_HMaxV   = &x.m_HMaxV[0];
	m_MinV    = &x.m_MinV[0];
	m_HMinV   = &x.m_HMinV[0];
	x.m_nsize = 0;
	x.m_Azimuth = NULL;
	x.m_Range   = NULL;
	x.m_MaxV    = NULL;
	x.m_HMaxV   = NULL;
	x.m_MinV    = NULL;
	x.m_HMinV   = NULL;
}

lam::wsr88d::
VCS_t::~VCS_t() {
	if (NULL != m_HMinV){
		_mm_free(m_HMinV);
		m_HMinV = NULL;
	}
	if (NULL != m_MinV) {
		_mm_free(m_MinV);
		m_MinV = NULL;
	}
	if (NULL != m_HMaxV) {
		_mm_free(m_HMaxV);
		m_HMaxV = NULL;
	}
	if (NULL != m_MaxV) {
		_mm_free(m_MaxV);
		m_MaxV = NULL;
	}
	if (NULL != m_Range) {
		_mm_free(m_Range);
		m_Range = NULL;
	}
	if (NULL != m_Azimuth) {
		_mm_free(m_Azimuth);
		m_Azimuth = NULL;
	}
}

lam::wsr88d::VCS_t &
lam::wsr88d::VCS_t::operator=(_In_ const VCS_t &x) {
	if (this == &x) return (*this);
	m_nsize = x.m_nsize;
	LAM_WSR88D_VCS_DEALLOCATE_MEMBERS
	double * __restrict Azimuth{ lam_edmalloca(static_cast<size_t>(m_nsize), align64B) };
	double * __restrict Range{   lam_edmalloca(static_cast<size_t>(m_nsize), align64B) };
	double * __restrict MaxV{    lam_edmalloca(static_cast<size_t>(m_nsize), align64B) };
	double * __restrict HMaxV{   lam_edmalloca(static_cast<size_t>(m_nsize), align64B) };
	double * __restrict MinV{    lam_edmalloca(static_cast<size_t>(m_nsize), align64B) };
	double * __restrict HMinV{   lam_edmalloca(static_cast<size_t>(m_nsize), align64B) };
	
	avx256_memcpy8x(&Azimuth[0], &x.m_Azimuth[0], static_cast<size_t>(m_nsize));
	avx256_memcpy8x(&Range[0],   &x.m_Range[0],   static_cast<size_t>(m_nsize));
	avx256_memcpy8x(&MaxV[0],	 &x.m_MaxV[0],    static_cast<size_t>(m_nsize));
	avx256_memcpy8x(&HMaxV[0],   &x.m_Azimuth[0], static_cast<size_t>(m_nsize));
	avx256_memcpy8x(&MinV[0],    &x.m_MinV[0],    static_cast<size_t>(m_nsize));
	avx256_memcpy8x(&HMinV[0],   &x.m_HMinV[0],   static_cast<size_t>(m_nsize));

	m_Azimuth = Azimuth,m_Range = Range,
	m_MaxV = MaxV,m_HMaxV = HMaxV,
	m_MinV = MinV,m_HMinV = HMinV;
	return (*this);
}

lam::wsr88d::VCS_t &
lam::wsr88d::VCS_t::operator=(_In_ VCS_t &&x) {
	if (this == &x) return (*this);
	m_nsize = x.m_nsize;
	LAM_WSR88D_VCS_DEALLOCATE_MEMBERS
	m_Azimuth = &x.m_Azimuth[0];
	m_Range = &x.m_Range[0];
	m_MaxV = &x.m_MaxV[0];
	m_HMaxV = &x.m_HMaxV[0];
	m_MinV = &x.m_MinV[0];
	m_HMinV = &x.m_HMinV[0];
	x.m_nsize = 0;
	x.m_Azimuth = NULL;
	x.m_Range = NULL;
	x.m_MaxV = NULL;
	x.m_HMaxV = NULL;
	x.m_MinV = NULL;
	x.m_HMinV = NULL;
	return (*this);
}

std::ostream &
lam::wsr88d::operator<<(_In_ std::ostream &os,
						_In_ const VCS_t &x) {
	
	for (int32_t i = 0; i != x.m_nsize; ++i) {
		os << std::setprecision(15) << std::fixed <<
			std::showpoint << " m_Azimuth (deg) = " << "[" << x.m_Azimuth << "]"   
			               << " m_Range   (nmi) = " << "[" << x.m_Range   << "]"
						   << " m_MaxV    (Kts) = " << "[" << x.m_MaxV    << "]"
						   << " m_HMaxV   (Kft) = " << "[" << x.m_HMaxV   << "]"
						   << " m_MinV    (Kts) = " << "[" << x.m_MinV    << "]"
						   << " m_HMinV   (Kft) = " << "[" << x.m_HMinV   << "]" << "\n";
	}
	return (os);
}
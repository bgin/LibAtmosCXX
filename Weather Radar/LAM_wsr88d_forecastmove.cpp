
//
//	Implementation.
//
#include "LAM_wsr88d_forecastmove.h"
#include "../LAM_malloc.h"
#include "../LAM_error_macros.h"
#include "../LAM_common.h"
#include "../LAM_config.h"
#include "../Math/LAM_constants.h"

using namespace lam::common;

lam::wsr88d::ForecastMove_t::
ForecastMove_t(_In_ const int32_t nsize)
:
m_nsize{ nsize },
m_StormSpeed{ lam_edmalloca(static_cast<size_t>(m_nsize),align64B) },
m_StormDir{   lam_edmalloca(static_cast<size_t>(m_nsize), align64B) } {
	using namespace lam::math::constants;
	int32_t i;
	for (i = 0; i != ROUND_TO_FOUR(m_nsize,4); i += 8) {
		_mm256_store_pd(&m_StormSpeed[i+0], vinf);
		_mm256_store_pd(&m_StormSpeed[i+4], vinf);
		_mm256_store_pd(&m_StormDir[i+0],   vinf);
		_mm256_store_pd(&m_StormDir[i+4],   vinf);
	}
	for (; i != m_nsize; ++i) {
		m_StormSpeed[i] = dinf;
		m_StormDir[i]   = dinf;
	}

}

lam::wsr88d::ForecastMove_t::
ForecastMove_t(_In_ const ForecastMove_t &rhs)
:
m_nsize{ rhs.m_nsize },
m_StormSpeed{ lam_edmalloca(static_cast<size_t>(m_nsize), align64B) },
m_StormDir{   lam_edmalloca(static_cast<size_t>(m_nsize), align64B) } {

	avx256_memcpy8x(&m_StormSpeed[0], &rhs.m_StormSpeed[0], static_cast<size_t>(m_nsize));
	avx256_memcpy8x(&m_StormDir[0], &rhs.m_StormDir[0], static_cast<size_t>(m_nsize));

}

lam::wsr88d::ForecastMove_t::
ForecastMove_t(_In_ ForecastMove_t &&rhs)
:
m_nsize{ rhs.m_nsize },
m_StormSpeed{ NULL },
m_StormDir{ NULL } {
	m_StormSpeed = &rhs.m_StormSpeed[0];
	m_StormDir = &rhs.m_StormDir[0];
	rhs.m_nsize = 0;
	rhs.m_StormSpeed = NULL;
	rhs.m_StormDir   = NULL;
}

lam::wsr88d::ForecastMove_t::
~ForecastMove_t() {
	if (NULL != m_StormSpeed) {
		_mm_free(m_StormSpeed);
		m_StormSpeed = NULL;
	}
	if (NULL != m_StormDir) {
		_mm_free(m_StormDir);
		m_StormDir = NULL;
	}
}

lam::wsr88d::ForecastMove_t &
lam::wsr88d::ForecastMove_t::operator=(_In_ const ForecastMove_t &rhs) {
	if (this == &rhs) return (*this);
	m_nsize = rhs.m_nsize;
	_mm_free(m_StormSpeed);
	_mm_free(m_StormDir);
	double * __restrict StormSpeed{ lam_edmalloca(static_cast<size_t>(m_nsize),align64B) };
	double * __restrict StormDir{   lam_edmalloca(static_cast<size_t>(m_nsize), align64B) };

	avx256_memcpy8x(&StormSpeed[0], &rhs.m_StormSpeed[0], static_cast<size_t>(m_nsize));
	avx256_memcpy8x(&StormDir[0], &rhs.m_StormDir[0], static_cast<size_t>(m_nsize));
	m_StormSpeed = StormSpeed;
	m_StormDir = StormDir;
	return (*this);
}	


lam::wsr88d::ForecastMove_t &
lam::wsr88d::ForecastMove_t::operator=(_In_ ForecastMove_t &&rhs) {
	if (this == &rhs) return (*this);
	m_nsize = rhs.m_nsize;
	_mm_free(m_StormSpeed);
	_mm_free(m_StormDir);
	m_StormSpeed = &rhs.m_StormSpeed[0];
	m_StormDir = &rhs.m_StormDir[0];
	rhs.m_nsize = 0;
	rhs.m_StormSpeed = NULL;
	rhs.m_StormDir   = NULL;
	return (*this);
}

std::ostream &
lam::wsr88d::operator<<(_In_ std::ostream & os, _In_ const lam::wsr88d::ForecastMove_t &rhs) {
	for (int32_t i = 0; i != rhs.m_nsize; ++i) {
		os << std::setprecision(16) << std::showpoint << std::setw(4) <<
			"Storm Speed (nmi)       value: " << rhs.m_StormSpeed[i] << std::setw(12) <<
			"Storm Direction  (nmi)  value: " << rhs.m_StormDir[i] << "\n";
	}
	return (os);
}
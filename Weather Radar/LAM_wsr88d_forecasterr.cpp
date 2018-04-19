
#include "LAM_wsr88d_forecasterr.h"
#include "../LAM_malloc.h"
#include "../LAM_error_macros.h"
#include "../LAM_config.h"
#include "../LAM_common.h"
#include "../Math/LAM_constants.h"
//
//	Implementation
//


using namespace lam::common;

lam::wsr88d::ForecastErr_t::
ForecastErr_t(_In_ const int32_t nsize) :
m_nsize{ nsize },
m_Err{  lam_edmalloca(static_cast<size_t>(m_nsize),align64B) },
m_Mean{ lam_edmalloca(static_cast<size_t>(m_nsize), align64B) } {
	
	using namespace lam::math::constants;
	int32_t i;
	for (i = 0; i != ROUND_TO_FOUR(m_nsize,4); i += 8) {
		_mm256_store_pd(&m_Err[i+0],  vinf);
		_mm256_store_pd(&m_Err[i+4],  vinf);
		_mm256_store_pd(&m_Mean[i+0], vinf);
		_mm256_store_pd(&m_Mean[i+4], vinf);
	}
	for (; i != m_nsize; ++i) {
		m_Err[i]  = dinf;
		m_Mean[i] = dinf;
	}
}


lam::wsr88d::ForecastErr_t::
ForecastErr_t(_In_ const ForecastErr_t &rhs) :
m_nsize{ rhs.m_nsize },
m_Err{  lam_edmalloca(static_cast<size_t>(m_nsize), align64B) },
m_Mean{ lam_edmalloca(static_cast<size_t>(m_nsize), align64B) } {
	
	avx256_memcpy8x(&m_Err[0],  &rhs.m_Err[0],  static_cast<size_t>(m_nsize));
	avx256_memcpy8x(&m_Mean[0], &rhs.m_Mean[0], static_cast<size_t>(m_nsize));
}


lam::wsr88d::ForecastErr_t::
ForecastErr_t(_In_ ForecastErr_t && rhs) :
m_nsize{ rhs.m_nsize },
m_Err{ NULL },
m_Mean{ NULL } {
	m_Err  = &rhs.m_Err[0];
	m_Mean = &rhs.m_Mean[0];
	rhs.m_nsize = 0;
	rhs.m_Err   = NULL;
	rhs.m_Mean  = NULL;
}

lam::wsr88d::ForecastErr_t::
~ForecastErr_t() {

	if (NULL != m_Err) {
		_mm_free(m_Err);
		m_Err = NULL;
	}
	if (NULL != m_Mean) {
		_mm_free(m_Mean);
		m_Mean = NULL;
	}
}

lam::wsr88d::ForecastErr_t & 
lam::wsr88d::ForecastErr_t::operator=(_In_ const ForecastErr_t &rhs) {
	if (this == &rhs) return (*this);
	m_nsize = rhs.m_nsize;
	_mm_free(m_Mean);
	_mm_free(m_Err);
	double * __restrict Err { lam_edmalloca(static_cast<size_t>(m_nsize),align64B)  };
	double * __restrict Mean{ lam_edmalloca(static_cast<size_t>(m_nsize), align64B) };
	avx256_memcpy8x(&Err[0],  &rhs.m_Err[0],  static_cast<size_t>(m_nsize));
	avx256_memcpy8x(&Mean[0], &rhs.m_Mean[0], static_cast<size_t>(m_nsize));

	m_Err = Err;
	m_Mean = Mean;
	return (*this);
}

lam::wsr88d::ForecastErr_t &
lam::wsr88d::ForecastErr_t::operator=(_In_ ForecastErr_t &&rhs) {
	if (this == &rhs) return (*this);
	m_nsize = rhs.m_nsize;
	_mm_free(m_Mean);
	_mm_free(m_Err);
	m_Err  = &rhs.m_Err[0];
	m_Mean = &rhs.m_Mean[0];
	rhs.m_nsize = 0;
	rhs.m_Mean = NULL;
	rhs.m_Err  = NULL;
	return (*this);
}

std::ostream &  
lam::wsr88d::operator<<(_In_ std::ostream &os, const lam::wsr88d::ForecastErr_t &rhs) {
	
	for (int32_t i = 0; i != rhs.m_nsize; ++i) {
		os << std::setprecision(16) << std::showpoint << std::setw(4) <<
			"Forecast Error (nmi)  value: " << rhs.m_Err[i] << std::setw(12) <<
			"Forecast Mean  (nmi)  value: " << rhs.m_Mean[i] << "\n";
	}
	return (os);
}

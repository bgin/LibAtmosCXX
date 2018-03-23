
#include "LAM_wsr88d_forecasterr.h"
#include "../LAM_config.h"
#if (PRINT_CALLSTACK_ON_ERROR) == 1
#include "../System/StackWalker.h"
#endif
//
//	Implementation
//




lam::wsr88d::ForecastErr_t::
ForecastErr_t(_In_ const int32_t nsize) :
m_nsize{ nsize },
m_Err{ reinterpret_cast<double*>( _mm_malloc(m_nsize * sizeof(double), align64B)) },
m_Mean{ reinterpret_cast<double*>(_mm_malloc(m_nsize * sizeof(double), align64B)) } {
	
	if ((NULL == m_Err && m_nsize != 0ULL) || 
		(NULL == m_Mean && m_nsize != 0ULL)) {
#if (PRINT_CALLSTACK_ON_ERROR) == 1
		StackWalker sw{};
		sw.ShowCallstack();
#endif
		ABORT_ON_ERROR("ForecastErr_t::ForecastErr_t(int32_t) -- !!! Mmeory Allocation Failure !!!", MALLOC_FAILED)
	}
#if USE_AUTO_VEC == 1

#pragma simd
#pragma unroll(4)
	for (int32_t i = 0; i != m_nsize; ++i) {
		m_Err[i]  = std::numeric_limits<double>::infinity();
		m_Mean[i] = std::numeric_limits<double>::infinity();
	}
#else
	for (int32_t i = 0; i != m_nsize; ++i) {
		m_Err[i] = std::numeric_limits<double>::infinity();
		m_Mean[i] = std::numeric_limits<double>::infinity();
	}
#endif
}

 lam::wsr88d::ForecastErr_t::
	 ForecastErr_t(_In_ const ForecastErr_t &rhs) :
m_nsize{ rhs.m_nsize },
m_Err{ reinterpret_cast<double*>(_mm_malloc(m_nsize * sizeof(double), align64B)) },
m_Mean{ reinterpret_cast<double*>(_mm_malloc(m_nsize * sizeof(double), align64B)) } {
	
		 if ((NULL == m_Err && m_nsize != 0ULL) || 
		    (NULL == m_Mean && m_nsize != 0ULL)) {

#if (PRINT_CALLSTACK_ON_ERROR) == 1
			 StackWalker sw{};
			 sw.ShowCallstack();
#endif
			 ABORT_ON_ERROR("ForecastErr_t::ForecastErr_t(ForecastErr_t &) -- !!! Memory Allocation Failure !!! ", -1)
		 }
#if (USE_AUTO_VEC) == 1
		 double * __restrict t1 = &rhs.m_Err[0];
		 double * __restrict t2 = &rhs.m_Mean[0];
#pragma prefetch t1:0:4
#pragma prefetch t2:0:4
#pragma simd
#pragma unroll(4)
		 for (int32_t i = 0; i != m_nsize; ++i) {
			 m_Err[i]  = t1[i];
			 m_Mean[i] = t2[i];
		 }
		 t1 = NULL;
		 t2 = NULL;
#else
		 for (int32_t i = 0; i != m_nsize; ++i) {
			 m_Err[i] = rhs.m_Err[i];
			 m_Mean[i] = rhs.m_Mean[i];
		 }
#endif
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
	double * __restrict Err  = reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double),align64B));
	double * __restrict Mean = reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double),align64B));
	if ((NULL == Err && m_nsize != 0ULL) || 
	    (NULL == Mean && m_nsize != 0ULL)) {
#if (PRINT_CALLSTACK_ON_ERROR) == 1
		StackWalker sw{};
		sw.ShowCallstack();
#endif
		ABORT_ON_ERROR("ForecastErr_t::operator=(ForecastErr_t &) -- !!! Mmeory Allocation Failure !!! ",MALLOC_FAILED)
	}
#if (USE_AUTO_VEC) == 1
	double * __restrict t1 = &rhs.m_Err[0];
	double * __restrict t2 = &rhs.m_Mean[0];
#pragma prefetch t1:0:4 
#pragma prefetch t2:0:4
#pragma simd
#pragma unroll(4)
	for (int32_t i = 0; i != m_nsize; ++i) {
		Err[i]  = t1[i];
		Mean[i] = t2[i];
	}
	t1 = NULL;
	t2 = NULL;
#else
	for (int32_t i = 0; i != m_nsize; ++i) {
		Err[i] = rhs.m_Err[i];
		Mean[i] = rhs.m_Mean[i];
	}
#endif
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

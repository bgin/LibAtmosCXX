
//
//	Implementation.
//
#include "LAM_wsr88d_forecastmove.h"
#include "../LAM_config.h"
#if (PRINT_CALLSTACK_ON_ERROR) == 1
#include "../System/StackWalker.h"
#endif

lam::wsr88d::ForecastMove_t::
ForecastMove_t(_In_ const int32_t nsize)
:
m_nsize{ nsize },
m_StormSpeed{ reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double), align64B)) },
m_StormDir{   reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double), align64B)) } {
	if ((NULL == m_StormSpeed && m_nsize != 0) ||
		(NULL == m_StormDir   && m_nsize != 0)) {
#if (PRINT_CALLSTACK_ON_ERROR) == 1
		StackWalker sw{};
		sw.ShowCallstack();
#endif
		ABORT_ON_ERROR("ForecastMove_t::ForecastMove_t(uint32_t ) -- !!! Memory Allocation Failure !!! ", MALLOC_FAILED)
	}
#if (USE_AUTO_VEC) == 1
#pragma simd
#pragma unroll(4)
	for(int32_t i = 0; i != m_nsize; ++i) {
		m_StormSpeed[i] = std::numeric_limits<double>::infinity();
		m_StormDir[i]   = std::numeric_limits<double>::infinity();
	}
#else
	for(int32_t i = 0; i != m_nsize; ++i) {
		m_StormSpeed[i] = std::numeric_limits<double>::infinity();
		m_StormDir[i]   = std::numeric_limits<double>::infinity();
	}
#endif
}

lam::wsr88d::ForecastMove_t::
ForecastMove_t(_In_ const ForecastMove_t &rhs)
:
m_nsize{ rhs.m_nsize },
m_StormSpeed{ reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double), align64B)) },
m_StormDir{   reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double), align64B)) } {
	if ((NULL == m_StormSpeed && m_nsize != 0ULL) ||
		(NULL == m_StormDir   && m_nsize != 0ULL)) {
#if (PRINT_CALLSTACK_ON_ERROR) == 1
		StackWalker sw{};
		sw.ShowCallstack();
#endif
		ABORT_ON_ERROR("ForecastMove_t::ForecastMove_t( ForecastMove_t &) -- !!! Memory Allocation Failure !!!", MALLOC_FAILED)
	}
#if (USE_AUTO_VEC) == 1
#pragma prefetch rhs.m_StormSpeed:0:2 // Probably ICC will not prefetch it
#pragma prefetch rhs.m_StormDir:0:2
#pragma simd
#pragma unroll(4)
	for (int32_t i = 0; i != m_nsize; ++i) {
		m_StormSpeed[i] = rhs.m_StormSpeed[i];
		m_StormDir[i]   = rhs.m_StormDir[i];
	}
#else
	for (int32_t i = 0; i != m_nsize; ++i) {
		m_StormSpeed[i] = rhs.m_StormSpeed[i];
		m_StormDir[i]   = rhs.m_StormDir[i];
	}
#endif
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
	double * __restrict StormSpeed = reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double),align64B));
	double * __restrict StormDir   = reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double),align64B));
	if ((NULL == StormSpeed && m_nsize != 0) ||
		(NULL == StormDir && m_nsize != 0)) {
#if (PRINT_CALLSTACK_ON_ERROR) == 1
		StackWalker sw{};
		sw.ShowCallstack();
#endif
		ABORT_ON_ERROR("ForecastMove_t::operator=(ForecastMove_t &) -- !!! Memory Allocation Failure !!! ", MALLOC_FAILED)
	}
#pragma simd
#pragma unroll(4)
	for (int32_t i = 0; i != m_nsize; ++i) {
		StormSpeed[i] = rhs.m_StormSpeed[i];
		StormDir[i]   = rhs.m_StormDir[i];
	}
	m_StormSpeed = StormSpeed;
	m_StormDir   = StormDir;
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
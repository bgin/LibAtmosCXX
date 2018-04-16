
#include "LAM_wsr88d_vcs.h"
#include "../LAM_error_macros.h"
#include "../LAM_config.h"

#if !defined LAM_WSR88D_VCS_DEALLOCATE_MEMBERS
#define LAM_WSR88D_VCS_DEALLOCATE_MEMBERS \
	_mm_free(m_HMinV);					  \
    _mm_free(m_MinV);					  \
    _mm_free(m_HMaxV);					  \
    _mm_free(m_MaxV);					  \
    _mm_free(m_Range);					  \
    _mm_free(m_Azimuth);
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
m_Azimuth(reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double),align64B))),
m_Range(reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double),align64B))),
m_MaxV(reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double),align64B))),
m_HMaxV(reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double),align64B))),
m_MinV(reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double),align64B))),
m_HMinV(reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double), align64B))) {
	if (NULL == m_Azimuth && m_nsize != 0 ||
		NULL == m_Range   && m_nsize != 0 ||
		NULL == m_MaxV    && m_nsize != 0 ||
		NULL == m_HMaxV   && m_nsize != 0 ||
		NULL == m_MinV    && m_nsize != 0 ||
		NULL == m_HMinV   && m_nsize != 0) {
#if (PRINT_CALLSTACK_ON_ERROR) == 1
		DUMP_CALLSTACK_ON_ERROR
#endif
			ABORT_ON_ERROR("VCS_t::VCS_t(int) -- !!! Memory Allocation Failure !!! ",  MALLOC_FAILED)
	}
#if (USE_AUTO_VEC) == 1
#pragma simd vectorlengthfor(double) vecremainder
#pragma unroll(4)
	for(int32_t i = 0; i != m_nsize; ++i) {
		m_Azimuth[i] = std::numeric_limits<double>::infinity();
		m_Range[i]   = std::numeric_limits<double>::infinity();
		m_MaxV[i]    = std::numeric_limits<double>::infinity();
		m_HMaxV[i]   = std::numeric_limits<double>::infinity();
		m_MinV[i]    = std::numeric_limits<double>::infinity();
		m_HMinV[i]   = std::numeric_limits<double>::infinity();
	}
#else
	for (int32_t i = 0; i != m_nsize; ++i) {
		m_Azimuth[i] = std::numeric_limits<double>::infinity();
		m_Range[i] = std::numeric_limits<double>::infinity();
		m_MaxV[i] = std::numeric_limits<double>::infinity();
		m_HMaxV[i] = std::numeric_limits<double>::infinity();
		m_MinV[i] = std::numeric_limits<double>::infinity();
		m_HMinV[i] = std::numeric_limits<double>::infinity();
	}
#endif
}

lam::wsr88d::
VCS_t::VCS_t(_In_ const VCS_t &x)
:
m_nsize{x.m_nsize},
m_Azimuth(reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double), align64B))),
m_Range(reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double), align64B))),
m_MaxV(reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double), align64B))),
m_HMaxV(reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double), align64B))),
m_MinV(reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double), align64B))),
m_HMinV(reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double), align64B))) {
	if (NULL == m_Azimuth && m_nsize != 0 ||
		NULL == m_Range   && m_nsize != 0 ||
		NULL == m_MaxV    && m_nsize != 0 ||
		NULL == m_HMaxV   && m_nsize != 0 ||
		NULL == m_MinV    && m_nsize != 0 ||
		NULL == m_HMinV   && m_nsize != 0) {
#if (PRINT_CALLSTACK_ON_ERROR) == 1
		DUMP_CALLSTACK_ON_ERROR
#endif
			ABORT_ON_ERROR("VCS_t::VCS_t(int) -- !!! Memory Allocation Failure !!! ", MALLOC_FAILED)
	}
	
#if (USE_AUTO_VEC) == 1
	double * __restrict t1 = &x.m_Azimuth[0];
	double * __restrict t2 = &x.m_Range[0];
	double * __restrict t3 = &x.m_MaxV[0];
	double * __restrict t4 = &x.m_HMaxV[0];
	double * __restrict t5 = &x.m_MinV[0];
	double * __restrict t6 = &x.m_HMinV[0];
#pragma prefetch t1:0:4
#pragma prefetch t2:0:4
#pragma prefetch t3:0:4
#pragma prefetch t4:0:4
#pragma prefetch t5:0:4
#pragma prefetch t6:0:4
#pragma simd vectorlengthfor(double) vecremainder
#pragma unroll(4)
	for (int32_t i = 0; i != m_nsize; ++i) {
		m_Azimuth[i] = t1[i];
		m_Range[i]   = t2[i];
		m_MaxV[i]	 = t3[i];
		m_HMaxV[i]	 = t4[i];
		m_MinV[i]    = t5[i];
		m_HMinV[i]   = t6[i];
	}
	t1 = NULL,t2 = NULL,t3 = NULL,
	t4 = NULL,t5 = NULL,t6 = NULL;
#else
	for (int32_t i = 0; i != m_nsize; ++i) {
		m_Azimuth[i] = x.m_Azimuth[i];
		m_Range[i]   = x.m_Range[i];
		m_MaxV[i]    = x.m_MaxV[i];
		m_HMaxV[i]   = x.m_HMaxV[i];
		m_MinV[i]	 = x.m_MinV[i];
		m_HMinV[i]   = x.m_HMinV[i];
	}
#endif
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
	double * __restrict Azimuth = 
	reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double),align64B));
	double * __restrict Range = 
	reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double),align64B));
	double * __restrict MaxV = 
	reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double), align64B));
	double * __restrict HMaxV = 
	reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double), align64B));
	double * __restrict MinV = 
	reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double), align64B));
	double * __restrict HMinV = 
	reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double), align64B));
	if (NULL == Azimuth && m_nsize != 0 ||
		NULL == Range   && m_nsize != 0 ||
		NULL == MaxV    && m_nsize != 0 ||
		NULL == HMaxV   && m_nsize != 0 ||
		NULL == MinV    && m_nsize != 0 ||
		NULL == HMinV   && m_nsize != 0) {
#if (PRINT_CALLSTACK_ON_ERROR) == 1
		DUMP_CALLSTACK_ON_ERROR
#endif
			ABORT_ON_ERROR("VCS_t::operator=(VCS_t &) -- !!! Memory Allocation Failure !!! ", MALLOC_FAILED)
	}
#if (USE_AUTO_VEC) == 1
	double * __restrict t1 = &x.m_Azimuth[0];
	double * __restrict t2 = &x.m_Range[0];
	double * __restrict t3 = &x.m_MaxV[0];
	double * __restrict t4 = &x.m_HMaxV[0];
	double * __restrict t5 = &x.m_MinV[0];
	double * __restrict t6 = &x.m_HMinV[0];
#pragma prefetch t1:0:4
#pragma prefetch t2:0:4
#pragma prefetch t3:0:4
#pragma prefetch t4:0:4
#pragma prefetch t5:0:4
#pragma prefetch t6:0:4
#pragma simd vectorlengthfor(double) vecremainder
#pragma unroll(4)
	for (int32_t i = 0; i != m_nsize; ++i) {
		Azimuth[i] = t1[i];
		Range[i]   = t2[i];
		MaxV[i]    = t3[i];
		HMaxV[i]   = t4[i];
		MinV[i]    = t5[i];
		HMinV[i]   = t6[i];
	}
	t1 = NULL, t2 = NULL, t3 = NULL,
	t4 = NULL, t5 = NULL, t6 = NULL;
#else
	for (int32_t i = 0; i != m_nsize; ++i) {
		Azimuth[i] = x.m_Azimuth[i];
		Range[i]   = x.m_Range[i];
		MaxV[i]    = x.m_MaxV[i];
		HMaxV[i]   = x.m_HMaxV[i];
		MinV[i]    = x.m_MinV[i];
		HMinV[i]   = x.m_HMinV[i];
	}
#endif
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

#include "LAM_wsr88d_vadwind.h"
#include "../LAM_error_macros.h"
#include "../LAM_config.h"
#include "../LAM_indices.h"

//
//	Implementation
//

#if !defined (LAM_WSR88D_VADWIND_DEALLOCATE_ARRAYS)
#define LAM_WSR88D_VADWIND_DEALLOCATE_ARRAYS   \
	_mm_free(m_W);							   \
	_mm_free(m_V);							   \
	_mm_free(m_U);							   \
	_mm_free(m_Elev);						   \
	_mm_free(m_Srng);						   \
	_mm_free(m_Rms);						   \
	_mm_free(m_Spd);						   \
	_mm_free(m_Dir);						   \
	_mm_free(m_Alt);			
#endif

lam::wsr88d::VADWind_t::
VADWind_t()
:
m_nsize{},
m_ims{},
m_ime{},
m_kms{},
m_kme{},
m_jms{},
m_jme{},
m_Alt(NULL),
m_Dir(NULL),
m_Spd(NULL),
m_Rms(NULL),
m_Srng(NULL),
m_Elev(NULL),
m_U(NULL),
m_V(NULL),
m_W(NULL) {}

lam::wsr88d::VADWind_t::
VADWind_t(_In_ const int64_t nsize,
		  _In_ const int64_t ims,
		  _In_ const int64_t ime,
		  _In_ const int64_t kms,
		  _In_ const int64_t kme,
		  _In_ const int64_t jms,
		  _In_ const int64_t jme)
:
m_nsize{ nsize },
m_ims{ ims },
m_ime{ ime },
m_kms{ kms },
m_kme{ kme },
m_jms{ jms },
m_jme{jme},
m_Alt(reinterpret_cast<double*>( _mm_malloc(m_nsize*sizeof(double),align64B))),
m_Dir(reinterpret_cast<double*>( _mm_malloc(m_nsize*sizeof(double),align64B))),
m_Spd(reinterpret_cast<double*>( _mm_malloc(m_nsize*sizeof(double),align64B))),
m_Rms(reinterpret_cast<double*>( _mm_malloc(m_nsize*sizeof(double),align64B))),
m_Srng(reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double),align64B))),
m_Elev(reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double),align64B))),
m_U(reinterpret_cast<double*>(_mm_malloc((m_jme*m_kme*m_ime)*sizeof(double),align64B))),
m_V(reinterpret_cast<double*>(_mm_malloc((m_jme*m_kme*m_ime)*sizeof(double),align64B))),
m_W(reinterpret_cast<double*>(_mm_malloc((m_jme*m_kme*m_ime)*sizeof(double), align64B))) {
	
	if (NULL == m_Alt   && m_nsize != 0 ||
		NULL == m_Dir   && m_nsize != 0 ||
		NULL == m_Spd   && m_nsize != 0 ||
		NULL == m_Rms   && m_nsize != 0 ||
		NULL == m_Srng  && m_nsize != 0 ||
		NULL == m_Elev  && m_nsize != 0 ||
		NULL == m_U && (m_jme*m_kme*m_ime) != 0LL ||
		NULL == m_V && (m_jme*m_kme*m_ime) != 0LL ||
		NULL == m_W && (m_jme*m_kme*m_ime) != 0LL) {
#if (PRINT_CALLSTACK_ON_ERROR) == 1
		DUMP_CALLSTACK_ON_ERROR
#endif
			ABORT_ON_ERROR("VADWind_t::VADWind_t(int32_t,int64_t,int64_t,int64_t,int64_t,int64_t,int64_t) -- !!! Memory Allocation Failure !!!",MALLOC_FAILED)
	}		
#if (USE_AUTO_VEC) == 1
#pragma simd vectorlengthfor(double) vecremainder
#pragma unroll(4)
	for(int32_t i = 0; i != m_nsize; ++i) {
		m_Alt[i]  = std::numeric_limits<double>::infinity();
		m_Dir[i]  = std::numeric_limits<double>::infinity();
		m_Spd[i]  = std::numeric_limits<double>::infinity();
		m_Rms[i]  = std::numeric_limits<double>::infinity();
		m_Srng[i] = std::numeric_limits<double>::infinity();
		m_Elev[i] = std::numeric_limits<double>::infinity();
	}
	for(int64_t j = m_jms; j != m_jme; ++j) {
		for(int64_t k = m_kms; k != m_kme; ++k) {
#pragma simd vectorlengthfor(double) vecremainder
#pragma unroll(4)
			for (int64_t i = m_ims; i != m_ime; ++i) {
				m_U[Dim3(j, k, i)] = std::numeric_limits<double>::infinity();
				m_V[Dim3(j, k, i)] = std::numeric_limits<double>::infinity();
				m_W[Dim3(j, k, i)] = std::numeric_limits<double>::infinity();
			}
		}
	}
#else
	for (int32_t i = 0; i != m_nsize; ++i) {
		m_Alt[i] = std::numeric_limits<double>::infinity();
		m_Dir[i] = std::numeric_limits<double>::infinity();
		m_Spd[i] = std::numeric_limits<double>::infinity();
		m_Rms[i] = std::numeric_limits<double>::infinity();
		m_Srng[i] = std::numeric_limits<double>::infinity();
		m_Elev[i] = std::numeric_limits<double>::infinity();
	}
	for (int64_t j = m_jms; j != m_jme; ++j) {
		for (int64_t k = m_kms; k != m_kme; ++k) {
			for (int64_t i = m_ims; i != m_ime; ++i) {
				m_U[Dim3(j, k, i)] = std::numeric_limits<double>::infinity();
				m_V[Dim3(j, k, i)] = std::numeric_limits<double>::infinity();
				m_W[Dim3(j, k, i)] = std::numeric_limits<double>::infinity();
			}
		}	
	}	
	
#endif
}

lam::wsr88d::VADWind_t::
VADWind_t(_In_ const VADWind_t &x)
:
m_nsize{ x.m_nsize },
m_ims{ x.m_ims },
m_ime{ x.m_ime },
m_kms{ x.m_kms },
m_kme{ x.m_kme },
m_jms{ x.m_jms },
m_jme{x.m_jme},
m_Alt(reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double), align64B))),
m_Dir(reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double), align64B))),
m_Spd(reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double), align64B))),
m_Rms(reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double), align64B))),
m_Srng(reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double), align64B))),
m_Elev(reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double), align64B))),
m_U(reinterpret_cast<double*>(_mm_malloc((m_jme*m_kme*m_ime)*sizeof(double), align64B))),
m_V(reinterpret_cast<double*>(_mm_malloc((m_jme*m_kme*m_ime)*sizeof(double), align64B))),
m_W(reinterpret_cast<double*>(_mm_malloc((m_jme*m_kme*m_ime)*sizeof(double), align64B))) {
	if (NULL == m_Alt   && m_nsize != 0 ||
		NULL == m_Dir   && m_nsize != 0 ||
		NULL == m_Spd   && m_nsize != 0 ||
		NULL == m_Rms   && m_nsize != 0 ||
		NULL == m_Srng  && m_nsize != 0 ||
		NULL == m_Elev  && m_nsize != 0 ||
		NULL == m_U && (m_jme*m_kme*m_ime) != 0LL ||
		NULL == m_V && (m_jme*m_kme*m_ime) != 0LL ||
		NULL == m_W && (m_jme*m_kme*m_ime) != 0LL) {
#if (PRINT_CALLSTACK_ON_ERROR) == 1
		DUMP_CALLSTACK_ON_ERROR
#endif
			ABORT_ON_ERROR("VADWind_t::VADWind_t(VADWind_t &) -- !!! Memory Allocation Failure !!!", MALLOC_FAILED)
	}
#if (USE_AUTO_VEC) == 1
#pragma simd vectorlengthfor(double) vecremainder
#pragma unroll(4)
	for(int32_t i = 0; i != m_nsize; ++i) {
		m_Alt[i]  = x.m_Alt[i];
		m_Dir[i]  = x.m_Dir[i];
		m_Spd[i]  = x.m_Spd[i];
		m_Rms[i]  = x.m_Rms[i];
		m_Srng[i] = x.m_Srng[i];
		m_Elev[i] = x.m_Elev[i];
	}
	for (int64_t j = m_jms; j != m_jme; ++j) {
		for (int64_t k = m_kms; k != m_kme; ++k) {
#pragma simd vectorlengthfor(double) vecremainder
#pragma unroll(4)
			for (int64_t i = m_ims; i != m_ime; ++j) {
				m_U[Dim3(j, k, i)] = x.m_U[Dim3(j,k,i)];
				m_V[Dim3(j, k, i)] = x.m_V[Dim3(j,k,i)];
				m_W[Dim3(j, k, i)] = x.m_W[Dim3(j,k,i)];
			}
		}
	}
#else
	for (int32_t i = 0; i != m_nsize; ++i) {
		m_Alt[i] = x.m_Alt[i];
		m_Dir[i] = x.m_Dir[i];
		m_Spd[i] = x.m_Spd[i];
		m_Rms[i] = x.m_Rms[i];
		m_Srng[i] = x.m_Srng[i];
		m_Elev[i] = x.m_Elev[i];
	}
	for (int64_t j = m_jms; j != m_jme; ++j) {
		for (int64_t k = m_kms; k != m_kme; ++k) {
			for (int64_t i = m_ims; i != m_ime; ++j) {
				m_U[Dim3(j, k, i)] = x.m_U[Dim3(j, k, i)];
				m_V[Dim3(j, k, i)] = x.m_V[Dim3(j, k, i)];
				m_W[Dim3(j, k, i)] = x.m_W[Dim3(j, k, i)];
			}
		}	
	}	
#endif	
}

lam::wsr88d::VADWind_t::
VADWind_t(_In_ VADWind_t &&x)
:
m_nsize{ x.m_nsize },
m_ims{ x.m_ims },
m_ime{ x.m_ime },
m_kms{ x.m_kms },
m_kme{ x.m_kme },
m_jms{ x.m_jms },
m_jme{ x.m_jme },
m_Alt(NULL),
m_Dir(NULL),
m_Spd(NULL),
m_Rms(NULL),
m_Srng(NULL),
m_Elev(NULL),
m_U(NULL),
m_V(NULL),
m_W(NULL) {
	m_Alt  = &x.m_Alt[0];
	m_Dir  = &x.m_Dir[0];
	m_Spd  = &x.m_Spd[0];
	m_Rms  = &x.m_Rms[0];
	m_Srng = &x.m_Srng[0];
	m_Elev = &x.m_Elev[0];
	m_U	   = &x.m_U[0];
	m_V    = &x.m_V[0];
	m_W    = &x.m_W[0];

	x.m_nsize = 0;
	x.m_ims = 0LL,x.m_ime = 0LL,
	x.m_kms = 0LL,x.m_kme = 0LL,
	x.m_jms = 0LL,x.m_jme = 0LL;
	x.m_Alt  = NULL,x.m_Dir  = NULL,
	x.m_Spd  = NULL,x.m_Rms  = NULL,
	x.m_Srng = NULL,x.m_Elev = NULL,
	x.m_U    = NULL,x.m_V    = NULL,
	x.m_W    = NULL;
}

lam::wsr88d::VADWind_t::
~VADWind_t() {
	if (NULL != m_W) {
		_mm_free(m_W);
		m_W = NULL;
	}
	if (NULL != m_U) {
		_mm_free(m_U);
		m_U = NULL;
	}
	if (NULL != m_V) {
		_mm_free(m_V);
		m_V = NULL;
	}
	if (NULL != m_Elev) {
		_mm_free(m_Elev);
		m_Elev = NULL;
	}
	if (NULL != m_Srng) {
		_mm_free(m_Srng);
		m_Srng = NULL;
	}
	if (NULL != m_Rms) {
		_mm_free(m_Rms);
		m_Rms = NULL;
	}
	if (NULL != m_Spd) {
		_mm_free(m_Spd);
		m_Spd = NULL;
	}
	if (NULL != m_Dir) {
		_mm_free(m_Dir);
		m_Dir = NULL;
	}
	if (NULL != m_Alt) {
		_mm_free(m_Alt);
		m_Alt = NULL;
	}
}

lam::wsr88d::VADWind_t &
lam::wsr88d::VADWind_t::operator=(_In_ const VADWind_t &x) {
	if (this == &x) return (*this);
	m_nsize = x.m_nsize;
	m_ims = x.m_ims,m_ime = x.m_ime,
	m_kms = x.m_kms,m_kme = x.m_kme,
	m_jms = x.m_jms,m_jme = x.m_jme;
	LAM_WSR88D_VADWIND_DEALLOCATE_ARRAYS
	double * __restrict Alt = 
	reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double),align64B));
	double * __restrict Dir = 
	reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double), align64B));
	double * __restrict Spd = 
	reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double), align64B));
	double * __restrict Rms = 
	reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double), align64B));
	double * __restrict Srng = 
	reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double), align64B));
	double * __restrict Elev = 
	reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double), align64B));
	double * __restrict U = 
	reinterpret_cast<double*>(_mm_malloc((m_jme*m_kme*m_ime)*sizeof(double), align64B));
	double * __restrict V = 
	reinterpret_cast<double*>(_mm_malloc((m_jme*m_kme*m_ime)*sizeof(double), align64B));
	double * __restrict W = 
	reinterpret_cast<double*>(_mm_malloc((m_jme*m_kme*m_ime)*sizeof(double), align64B));
	if (NULL == Alt   && m_nsize != 0 ||
		NULL == Dir   && m_nsize != 0 ||
		NULL == Spd   && m_nsize != 0 ||
		NULL == Rms   && m_nsize != 0 ||
		NULL == Srng  && m_nsize != 0 ||
		NULL == Elev  && m_nsize != 0 ||
		NULL == U && (m_jme*m_kme*m_ime) != 0LL ||
		NULL == V && (m_jme*m_kme*m_ime) != 0LL ||
		NULL == W && (m_jme*m_kme*m_ime) != 0LL) {
#if (PRINT_CALLSTACK_ON_ERROR) == 1
		DUMP_CALLSTACK_ON_ERROR
#endif
			ABORT_ON_ERROR("VADWind_t::operator=(VADWind_t &) -- !!! Memory Allocation Failure !!!", MALLOC_FAILED)
	}
#if (USE_AUTO_VEC) == 1
#pragma simd vectorlengthfor(double) vecremainder
#pragma unroll(4)
	for(int32_t i = 0; i != m_nsize; ++i) {
		Alt[i]  = x.m_Alt[i];
		Dir[i]  = x.m_Dir[i];
		Spd[i]  = x.m_Spd[i];
		Rms[i]  = x.m_Rms[i];
		Srng[i] = x.m_Srng[i];
		Elev[i] = x.m_Elev[i];
	}
	for (int64_t j = m_jms; j != m_jme; ++j) {
		for (int64_t k = m_kms; k != m_kme; ++k) {
#pragma simd vectorlengthfor(double) vecremainder
#pragma unroll(4)
			for (int64_t i = m_ims; i != m_ime; ++i) {
				U[Dim3(j, k, i)]   = x.m_U[Dim3(j,k,i)];
				V[Dim3(j, k, i)]   = x.m_V[Dim3(j,k,i)];
				W[Dim3(j, k, i)]   = x.m_W[Dim3(j,k,i)];
			}
		}
	}
	
#else
	for (int32_t i = 0; i != m_nsize; ++i) {
		Alt[i] = x.m_Alt[i];
		Dir[i] = x.m_Dir[i];
		Spd[i] = x.m_Spd[i];
		Rms[i] = x.m_Rms[i];
		Srng[i] = x.m_Srng[i];
		Elev[i] = x.m_Elev[i];
	}
	for (int64_t j = m_jms; j != m_jme; ++j) {
		for (int64_t k = m_kms; k != m_kme; ++k) {
			for (int64_t i = m_ims; i != m_ime; ++i) {
				U[Dim3(j, k, i)] = x.m_U[Dim3(j, k, i)];
				V[Dim3(j, k, i)] = x.m_V[Dim3(j, k, i)];
				W[Dim3(j, k, i)] = x.m_W[Dim3(j, k, i)];
			}
		}	
	}
#endif      
	m_Alt = Alt,m_Dir = Dir,m_Spd = Spd,
	m_Rms = Rms,m_Srng = Srng,m_Elev = Elev,
	m_U = U,m_V = V,m_W = W;
	return (*this);
}

lam::wsr88d::VADWind_t &
lam::wsr88d::VADWind_t::operator=(_In_ VADWind_t &&x) {
	if (this == &x) return (*this);
	m_nsize = x.m_nsize;
	m_ims = x.m_ims, m_ime = x.m_ime,
	m_kms = x.m_kms, m_kme = x.m_kme,
	m_jms = x.m_jms, m_jme = x.m_jme;
	LAM_WSR88D_VADWIND_DEALLOCATE_ARRAYS
	m_Alt = &x.m_Alt[0];
	m_Dir = &x.m_Dir[0];
	m_Spd = &x.m_Spd[0];
	m_Rms = &x.m_Rms[0];
	m_Srng = &x.m_Srng[0];
	m_Elev = &x.m_Elev[0];
	m_U = &x.m_U[0];
	m_V = &x.m_V[0];
	m_W = &x.m_W[0];

	x.m_nsize = 0;
	x.m_ims = 0LL, x.m_ime = 0LL,
	x.m_kms = 0LL, x.m_kme = 0LL,
	x.m_jms = 0LL, x.m_jme = 0LL;
	x.m_Alt = NULL, x.m_Dir = NULL,
	x.m_Spd = NULL, x.m_Rms = NULL,
	x.m_Srng = NULL, x.m_Elev = NULL,
	x.m_U = NULL, x.m_V = NULL,
	x.m_W = NULL;
	return (*this);
}



#include "LAM_wsr88d_vadwind.h"
#include "../LAM_malloc.h"
#include "../LAM_error_macros.h"
#include "../LAM_config.h"
#include "../LAM_indices.h"
#include "../LAM_common.h"
#include "../Math/LAM_constants.h"

//
//	Implementation
//

using namespace lam::common;


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
m_Alt(lam_edmalloca(static_cast<std::size_t>(m_nsize),align64B)),
m_Dir(lam_edmalloca(static_cast<std::size_t>(m_nsize),align64B)),
m_Spd(lam_edmalloca(static_cast<std::size_t>(m_nsize),align64B)),
m_Rms(lam_edmalloca(static_cast<std::size_t>(m_nsize), align64B)),
m_Srng(lam_edmalloca(static_cast<std::size_t>(m_nsize), align64B)),
m_Elev(lam_edmalloca(static_cast<std::size_t>(m_nsize), align64B)),
m_U(lam_edmalloca(static_cast<std::size_t>(m_jme*m_kme*m_ime),align64B)),
m_V(lam_edmalloca(static_cast<std::size_t>(m_jme*m_kme*m_ime),align64B)),
m_W(lam_edmalloca(static_cast<std::size_t>(m_jme*m_kme*m_ime),align64B)) {
	
	using namespace lam::math::constants;
	int32_t i;
	int64_t j;
	for (i = 0; i != ROUND_TO_FOUR(m_nsize,4); i += 8) {
		_mm256_store_pd(&m_Alt[i+0],    vinf);
		_mm256_store_pd(&m_Alt[i+4],    vinf);
		_mm256_store_pd(&m_Dir[i+0],    vinf);
		_mm256_store_pd(&m_Dir[i+4],    vinf);
		_mm256_store_pd(&m_Spd[i+0],    vinf);
		_mm256_store_pd(&m_Spd[i+4],    vinf);
		_mm256_store_pd(&m_Rms[i+0],    vinf);
		_mm256_store_pd(&m_Rms[i+4],    vinf);
		_mm256_store_pd(&m_Srng[i + 0], vinf);
		_mm256_store_pd(&m_Srng[i + 4], vinf);
		_mm256_store_pd(&m_Elev[i + 0], vinf);
		_mm256_store_pd(&m_Elev[i + 4], vinf);
	}
	for (; i != m_nsize; ++i) {
		m_Alt[i]  =  dinf;
		m_Dir[i]  =  dinf;
		m_Spd[i]  =  dinf;
		m_Rms[i]  =  dinf;
		m_Srng[i] =  dinf;
		m_Elev[i] =  dinf;
	}
	// 3D loop collapsed to 1D
	for (j = m_jms; j != ROUND_TO_FOUR((m_jme*m_kme*m_ime),4LL); i += 8LL) {
		_mm256_store_pd(&m_U[j+0LL], vinf);
		_mm256_store_pd(&m_U[j+4LL], vinf);
		_mm256_store_pd(&m_V[j+0LL], vinf);
		_mm256_store_pd(&m_V[j+4LL], vinf);
		_mm256_store_pd(&m_W[j+0LL], vinf);
		_mm256_store_pd(&m_W[j+4LL], vinf);
	}
	for (; j != (m_jme*m_kme*m_ime); ++j) {
		m_U[j] = dinf;
		m_V[j] = dinf;
		m_W[j] = dinf;
	}
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
m_Alt(lam_edmalloca(static_cast<std::size_t>(m_nsize), align64B)),
m_Dir(lam_edmalloca(static_cast<std::size_t>(m_nsize), align64B)),
m_Spd(lam_edmalloca(static_cast<std::size_t>(m_nsize), align64B)),
m_Rms(lam_edmalloca(static_cast<std::size_t>(m_nsize), align64B)),
m_Srng(lam_edmalloca(static_cast<std::size_t>(m_nsize), align64B)),
m_Elev(lam_edmalloca(static_cast<std::size_t>(m_nsize), align64B)),
m_U(lam_edmalloca(static_cast<std::size_t>(m_jme*m_kme*m_ime), align64B)),
m_V(lam_edmalloca(static_cast<std::size_t>(m_jme*m_kme*m_ime), align64B)),
m_W(lam_edmalloca(static_cast<std::size_t>(m_jme*m_kme*m_ime), align64B)) {

	using namespace lam::common;
	avx256_memcpy8x(&m_Alt[0],  &x.m_Alt[0],  static_cast<int64_t>(  m_nsize));
	avx256_memcpy8x(&m_Dir[0],  &x.m_Dir[0],  static_cast<int64_t>(  m_nsize));
	avx256_memcpy8x(&m_Spd[0],  &x.m_Spd[0],  static_cast<int64_t>(  m_nsize));
	avx256_memcpy8x(&m_Rms[0],  &x.m_Rms[0],  static_cast<int64_t>(  m_nsize));
	avx256_memcpy8x(&m_Srng[0], &x.m_Srng[0], static_cast<int64_t>(m_nsize));
	avx256_memcpy8x(&m_Elev[0], &x.m_Elev[0], static_cast<int64_t>(m_nsize));
	avx256_memcpy8x(&m_U[0],	&x.m_U[0],    static_cast<size_t>((m_jme*m_kme*m_ime)));
	avx256_memcpy8x(&m_V[0],    &x.m_V[0],    static_cast<size_t>((m_jme*m_kme*m_ime)));
	avx256_memcpy8x(&m_W[0],    &x.m_W[0],    static_cast<size_t>((m_jme*m_kme*m_ime)));

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
	const std::size_t len    = static_cast<std::size_t>(m_nsize);
	double * __restrict Alt{ lam_edmalloca(len,align64B)};
	double * __restrict Dir{ lam_edmalloca(len,align64B)};
	double * __restrict Spd{ lam_edmalloca(len,align64B)};
	double * __restrict Rms{ lam_edmalloca(len,align64B)};
	double * __restrict Srng{lam_edmalloca(len,align64B)};
	double * __restrict Elev{lam_edmalloca(len,align64B)};
	const std::size_t len3d  =  static_cast<std::size_t>((m_jme*m_kme*m_ime));
	double * __restrict U{ lam_edmalloca(len3d,align64B)};
	double * __restrict V{ lam_edmalloca(len3d,align64B)};
	double * __restrict W{ lam_edmalloca(len3d,align64B)};
	
	avx256_memcpy8x(&Alt[0],  &x.m_Alt[0],len);
	avx256_memcpy8x(&Dir[0],  &x.m_Dir[0],len);
	avx256_memcpy8x(&Spd[0],  &x.m_Spd[0],len);
	avx256_memcpy8x(&Rms[0],  &x.m_Alt[0],len);
	avx256_memcpy8x(&Srng[0], &x.m_Srng[0],len);
	avx256_memcpy8x(&Elev[0], &x.m_Elev[0],len);
	avx256_memcpy8x(&U[0], &x.m_U[0],len3d);
	avx256_memcpy8x(&V[0], &x.m_V[0],len3d);
	avx256_memcpy8x(&W[0], &x.m_W[0],len3d);
	m_Alt = Alt, m_Dir = Dir, m_Spd = Spd,
	m_Rms = Rms, m_Srng = Srng, m_Elev = Elev,
	m_U = U, m_V = V, m_W = W;
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


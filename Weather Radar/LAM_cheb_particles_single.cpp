
#include "LAM_cheb_particles_single.h"
#include "../LAM_malloc.h"
#include "../LAM_error_macros.h"
#include "../LAM_config.h"
#include "../LAM_indices.h"
#include "../LAM_common.h"
#include "../Math/LAM_constants.h"

//
//	Implementation
//

#if !defined(LAM_WSR88D_CHEB_PARTICLES_DEALLOCATE_ARRAYS)
#define LAM_WSR88D_CHEB_PARTICLES_DEALLOCATE_ARRAYS      \
	_mm_free(m_pmass);									 \
	_mm_free(m_ptmp);									 \
	_mm_free(m_pvf);									 \
	_mm_free(m_ppz);									 \
	_mm_free(m_ppy);						             \
	_mm_free(m_ppx);									 \
	_mm_free(m_psarea);									 \
	_mm_free(m_pvol);									 \
	_mm_free(m_pphi);								     \
	_mm_free(m_ptheta);									 \
	_mm_free(m_prdist);								     \
	_mm_free(m_pradii);									 \
	_mm_free(m_xsect);									 \
	_mm_free(m_ptypes);
#endif


using namespace lam::common;

lam::wsr88d::Chebyshev_psingle_t
::Chebyshev_psingle_t() : 
m_np{},
m_nt{},
m_maxx{},
m_maxy{},
m_maxz{},
m_maxsp{},
m_ptypes(NULL),
m_xsect(NULL),
m_pradii(NULL),
m_prdist(NULL),
m_ptheta(NULL),
m_pphi(NULL),
m_pvol(NULL),
m_psarea(NULL),
m_ppx(NULL),
m_ppy(NULL),
m_ppz(NULL),
m_pvf(NULL),
m_ptmp(NULL),
m_pmass(NULL) {}

lam::wsr88d::Chebyshev_psingle_t
::Chebyshev_psingle_t(_In_ const int32_t np,
					  _In_ const int32_t nt,
					  _In_ const int32_t maxx,
					  _In_ const int32_t maxy,
					  _In_ const int32_t maxz,
					  _In_ const int32_t maxsp)
:
m_np{ np },
m_nt{ nt },
m_maxx{ maxx },
m_maxy{ maxy },
m_maxz{ maxz },
m_maxsp{maxsp},
m_ptypes(lam_eimalloca( static_cast<size_t>( m_np),	                align64B)),
m_xsect( lam_edmalloca( static_cast<size_t>( m_np*m_maxsp),         align64B)),
m_pradii(lam_edmalloca( static_cast<size_t>( m_np),                 align64B)),
m_prdist(lam_edmalloca( static_cast<size_t>( m_np*m_nt),            align64B)),
m_ptheta(lam_edmalloca( static_cast<size_t>( m_np*m_nt),            align64B)),
m_pphi(  lam_edmalloca( static_cast<size_t>( m_np*m_nt),            align64B)),
m_pvol(  lam_edmalloca( static_cast<size_t>( m_np),			        align64B)),
m_psarea(lam_edmalloca( static_cast<size_t>( m_np),                 align64B)),
m_ppx(   lam_edmalloca( static_cast<size_t>( m_np*m_maxx),		    align64B)),
m_ppy(   lam_edmalloca( static_cast<size_t>( m_np*m_maxy),          align64B)),
m_ppz(   lam_edmalloca( static_cast<size_t>( m_np*m_maxz),          align64B)),
m_pvf(   lam_edmalloca( static_cast<size_t>( m_np*m_nt),            align64B)),
m_ptmp(  lam_edmalloca( static_cast<size_t>( m_np),				    align64B)),
m_pmass( lam_edmalloca( static_cast<size_t>( m_np),                 align64B)) {
	
	using namespace lam::math::constants;
	init_array(&m_ptypes[0],          static_cast<uint64_t>(m_np), -1LL);
	avx256_init_unroll8x(&m_xsect[0], static_cast<size_t>(m_np*m_maxsp),dinf);
	avx256_init_unroll8x(&m_pradii[0],static_cast<size_t>(m_np),dinf);
	avx256_init_unroll8x(&m_prdist[0],static_cast<size_t>(m_np*m_nt),dinf);
	avx256_init_unroll8x(&m_ptheta[0],static_cast<size_t>(m_np*m_nt),dinf);
	avx256_init_unroll8x(&m_pphi[0],  static_cast<size_t>(m_np*m_nt),dinf);
	avx256_init_unroll8x(&m_pvol[0],  static_cast<size_t>(m_np),dinf);
	avx256_init_unroll8x(&m_psarea[0],static_cast<size_t>(m_np),dinf);
	avx256_init_unroll8x(&m_ppx[0],   static_cast<size_t>(m_np*m_maxx),dinf);
	avx256_init_unroll8x(&m_ppy[0],   static_cast<size_t>(m_np*m_maxy),dinf);
	avx256_init_unroll8x(&m_ppz[0],   static_cast<size_t>(m_np*m_maxz),dinf);
	avx256_init_unroll8x(&m_pvf[0],   static_cast<size_t>(m_np*m_nt),dinf);
	avx256_init_unroll8x(&m_ptmp[0],  static_cast<size_t>(m_np),dinf);
	avx256_init_unroll8x(&m_pmass[0], static_cast<size_t>(m_np),dinf);
}

lam::wsr88d::Chebyshev_psingle_t
::Chebyshev_psingle_t(_In_ const Chebyshev_psingle_t &x)
:
m_np{ x.m_np },
m_nt{ x.m_nt },
m_maxx{ x.m_maxx },
m_maxy{ x.m_maxy },
m_maxz{ x.m_maxz },
m_maxsp{x.m_maxsp},
m_ptypes( lam_eimalloca(static_cast<size_t>(m_np),         align64B)),
m_xsect(  lam_edmalloca(static_cast<size_t>(m_np*m_maxsp), align64B)),
m_pradii( lam_edmalloca(static_cast<size_t>(m_np),         align64B)),
m_prdist( lam_edmalloca(static_cast<size_t>(m_np*m_nt),    align64B)),
m_ptheta( lam_edmalloca(static_cast<size_t>(m_np*m_nt),    align64B)),
m_pphi(   lam_edmalloca(static_cast<size_t>(m_np*m_nt),    align64B)),
m_pvol(   lam_edmalloca(static_cast<size_t>(m_np),         align64B)),
m_psarea( lam_edmalloca(static_cast<size_t>(m_np),         align64B)),
m_ppx(    lam_edmalloca(static_cast<size_t>(m_np*m_maxx),  align64B)),
m_ppy(    lam_edmalloca(static_cast<size_t>(m_np*m_maxy),  align64B)),
m_ppz(    lam_edmalloca(static_cast<size_t>(m_np*m_maxz),  align64B)),
m_pvf(    lam_edmalloca(static_cast<size_t>(m_np*m_nt),    align64B)),
m_ptmp(   lam_edmalloca(static_cast<size_t>(m_np),         align64B)),
m_pmass(  lam_edmalloca(static_cast<size_t>(m_np),         align64B)) {

	memcpy(&m_ptypes[0],          &x.m_ptypes[0], static_cast<size_t>(m_np));
	avx256_memcpy8x(&m_xsect[0],  &x.m_xsect[0],  static_cast<size_t>(m_np*m_maxsp));
	avx256_memcpy8x(&m_pradii[0], &x.m_pradii[0], static_cast<size_t>(m_np));
	avx256_memcpy8x(&m_prdist[0], &x.m_prdist[0], static_cast<size_t>(m_np*m_nt));
	avx256_memcpy8x(&m_ptheta[0], &x.m_ptheta[0], static_cast<size_t>(m_np*m_nt));
	avx256_memcpy8x(&m_pphi[0],   &x.m_pphi[0],   static_cast<size_t>(m_np*m_nt));
	avx256_memcpy8x(&m_pvol[0],   &x.m_pvol[0],   static_cast<size_t>(m_np));
	avx256_memcpy8x(&m_psarea[0], &x.m_psarea[0], static_cast<size_t>(m_np));
	avx256_memcpy8x(&m_ppx[0],	  &x.m_ppx[0],    static_cast<size_t>(m_np*m_maxx));
	avx256_memcpy8x(&m_ppy[0],	  &x.m_ppy[0],    static_cast<size_t>(m_np*m_maxy)); 
	avx256_memcpy8x(&m_ppz[0],	  &x.m_ppz[0],    static_cast<size_t>(m_np*m_maxz));
	avx256_memcpy8x(&m_pvf[0],	  &x.m_pvf[0],	  static_cast<size_t>(m_np*m_nt));	
	avx256_memcpy8x(&m_ptmp[0],   &x.m_ptmp[0],   static_cast<size_t>(m_np));
	avx256_memcpy8x(&m_pmass[0],  &x.m_pmass[0],  static_cast<size_t>(m_np));
}

lam::wsr88d::Chebyshev_psingle_t
::Chebyshev_psingle_t(_In_ Chebyshev_psingle_t &&x)
:
m_np{ x.m_np },
m_nt{ x.m_nt },
m_maxx{ x.m_maxx },
m_maxy{ x.m_maxy },
m_maxz{ x.m_maxz },
m_maxsp{x.m_maxsp},
m_ptypes(NULL),
m_xsect(NULL),
m_pradii(NULL),
m_prdist(NULL),
m_ptheta(NULL),
m_pphi(NULL),
m_pvol(NULL),
m_psarea(NULL),
m_ppx(NULL),
m_ppy(NULL),
m_ppz(NULL),
m_pvf(NULL),
m_ptmp(NULL),
m_pmass(NULL) {

	m_ptypes = x.m_ptypes;
	m_xsect  = x.m_xsect;
	m_pradii = x.m_pradii;
	m_prdist = x.m_prdist;
	m_ptheta = x.m_ptheta;
	m_pphi   = x.m_pphi;
	m_pvol   = x.m_pvol;
	m_psarea = x.m_psarea;
	m_ppx    = x.m_ppx;
	m_ppy    = x.m_ppy;
	m_ppz    = x.m_ppz;
	m_pvf    = x.m_pvf;
	m_ptmp   = x.m_ptmp;
	m_pmass  = x.m_pmass;

	x.m_np   = 0,  x.m_nt   = 0,
	x.m_maxx = 0,  x.m_maxy = 0,
	x.m_maxz = 0;
	x.m_ptypes = NULL, x.m_xsect  = NULL,
	x.m_pradii = NULL, x.m_prdist = NULL,
	x.m_ptheta = NULL, x.m_pphi   = NULL,
	x.m_pvol   = NULL, x.m_psarea = NULL,
	x.m_ppx    = NULL, x.m_ppy    = NULL,
	x.m_ppz    = NULL, x.m_pvf    = NULL,
	x.m_ptmp   = NULL, x.m_pmass  = NULL;
}

lam::wsr88d::Chebyshev_psingle_t
::~Chebyshev_psingle_t() {
	if (m_pmass != NULL) {
		_mm_free(m_pmass);
		m_pmass = NULL;
	}
	if (m_ptmp != NULL) {
		_mm_free(m_ptmp);
		m_ptmp = NULL;
	}
	if (m_pvf != NULL) {
		_mm_free(m_pvf);
		m_pvf = NULL;
	}
	if (m_ppz != NULL) {
		_mm_free(m_ppz);
		m_ppz = NULL;
	}
	if (m_ppy != NULL) {
		_mm_free(m_ppy);
		m_ppy = NULL;
	}
	if (m_ppx != NULL) {
		_mm_free(m_ppx);
		m_ppx = NULL;
	}
	if (m_psarea != NULL) {
		_mm_free(m_psarea);
		m_psarea = NULL;
	}
	if (m_pvol != NULL) {
		_mm_free(m_pvol);
		m_pvol = NULL;
	}
	if (m_pphi != NULL) {
		_mm_free(m_pphi);
		m_pphi = NULL;
	}
	if (m_ptheta != NULL) {
		_mm_free(m_ptheta);
		m_ptheta = NULL;
	}
	if (m_prdist != NULL) {
		_mm_free(m_prdist);
		m_prdist  = NULL;
	}
	if (m_pradii != NULL) {
		_mm_free(m_pradii);
		m_pradii = NULL;
	}
	if (m_xsect != NULL) {
		_mm_free(m_xsect);
		m_xsect = NULL;
	}
	if (m_ptypes != NULL) {
		_mm_free(m_ptypes);
		m_ptypes = NULL;
	}
}

lam::wsr88d::Chebyshev_psingle_t &
lam::wsr88d::Chebyshev_psingle_t::operator=(_In_ const Chebyshev_psingle_t &x) {
	if (this == &x) return (*this);

	m_np   = x.m_np,  m_nt   = x.m_nt,
	m_maxx = x.m_maxx,m_maxy = x.m_maxy,
	m_maxz = x.m_maxz;
	LAM_WSR88D_CHEB_PARTICLES_DEALLOCATE_ARRAYS

	int64_t* __restrict ptypes{ lam_eimalloca(static_cast<size_t>(m_np),         align64B) };
	double*  __restrict xsect{  lam_edmalloca(static_cast<size_t>(m_np*m_maxsp), align64B) };
	double*  __restrict pradii{ lam_edmalloca(static_cast<size_t>(m_np),         align64B) };
	double*  __restrict prdist{ lam_edmalloca(static_cast<size_t>(m_np*m_nt),    align64B) };
	double*  __restrict ptheta{ lam_edmalloca(static_cast<size_t>(m_np*m_nt),    align64B) };
	double*  __restrict pphi{   lam_edmalloca(static_cast<size_t>(m_np*m_nt),    align64B) };
	double*  __restrict pvol{   lam_edmalloca(static_cast<size_t>(m_np),         align64B) };
	double*  __restrict psarea{ lam_edmalloca(static_cast<size_t>(m_np),         align64B) };
	double*  __restrict ppx{    lam_edmalloca(static_cast<size_t>(m_np*m_maxx),  align64B) };
	double*  __restrict ppy{    lam_edmalloca(static_cast<size_t>(m_np*m_maxy),  align64B) };
	double*  __restrict ppz{    lam_edmalloca(static_cast<size_t>(m_np*m_maxz),  align64B) };
	double*  __restrict pvf{    lam_edmalloca(static_cast<size_t>(m_np),         align64B) };
	double*  __restrict ptmp{   lam_edmalloca(static_cast<size_t>(m_np),         align64B) };
	double*  __restrict pmass{  lam_edmalloca(static_cast<size_t>(m_np),         align64B) };
	memcpy(&ptypes[0], &x.m_ptypes[0],static_cast<size_t>(m_np));
	avx256_memcpy8x(&xsect[0],  &x.m_xsect[0],  static_cast<size_t>(m_np*m_maxsp));
	avx256_memcpy8x(&pradii[0], &x.m_pradii[0], static_cast<size_t>(m_np));
	avx256_memcpy8x(&prdist[0], &x.m_prdist[0], static_cast<size_t>(m_np*m_nt));
	avx256_memcpy8x(&ptheta[0], &x.m_ptheta[0], static_cast<size_t>(m_np*m_nt));
	avx256_memcpy8x(&pphi[0],   &x.m_pphi[0], static_cast<size_t>(  m_np*m_nt));
	avx256_memcpy8x(&pvol[0],   &x.m_pvol[0], static_cast<size_t>(m_np));
	avx256_memcpy8x(&psarea[0], &x.m_psarea[0], static_cast<size_t>(m_np));
	avx256_memcpy8x(&ppx[0],    &x.m_ppx[0], static_cast<size_t>(m_np*m_maxx));
	avx256_memcpy8x(&ppy[0],    &x.m_ppy[0], static_cast<size_t>(m_np*m_maxy));
	avx256_memcpy8x(&ppz[0],    &x.m_ppz[0], static_cast<size_t>(m_np*m_maxz));
	avx256_memcpy8x(&pvf[0],    &x.m_pvf[0], static_cast<size_t>(m_np*m_nt));
	avx256_memcpy8x(&ptmp[0],   &x.m_ptmp[0], static_cast<size_t>(m_np));
	avx256_memcpy8x(&pmass[0],  &x.m_pmass[0], static_cast<size_t>(m_np));

	m_ptypes = ptypes, m_xsect  = xsect,
	m_pradii = pradii, m_prdist = prdist,
	m_ptheta = ptheta, m_pphi   = pphi,
	m_pvol   = pvol,   m_psarea = psarea,
	m_ppx    = ppx,    m_ppy    = ppy,
	m_ppz    = ppz,    m_pvf    = pvf,
	m_ptmp   = ptmp,   m_pmass  = pmass;
	return (*this);
}

lam::wsr88d::Chebyshev_psingle_t &
lam::wsr88d::Chebyshev_psingle_t::operator=(_In_ Chebyshev_psingle_t &&x) {
	if (this == &x) return (*this);

	m_np = x.m_np, m_nt = x.m_nt,
    m_maxx = x.m_maxx, m_maxy = x.m_maxy,
    m_maxz = x.m_maxz;
	LAM_WSR88D_CHEB_PARTICLES_DEALLOCATE_ARRAYS

    m_ptypes = x.m_ptypes, m_xsect = x.m_xsect,
	m_pradii = x.m_pradii, m_prdist = x.m_prdist,
	m_ptheta = x.m_ptheta, m_pphi = x.m_pphi,
	m_pvol   = x.m_pvol,   m_psarea = x.m_psarea,
	m_ppx    = x.m_ppx,    m_ppy = x.m_ppy,
	m_ppz    = x.m_ppz,    m_pvf = x.m_pvf,
	m_ptmp   = x.m_ptmp,   m_pmass = x.m_pmass;

	x.m_np   = 0, x.m_nt    = 0,
	x.m_maxx = 0, x.m_maxy  = 0,
	x.m_maxz = 0, x.m_maxsp = 0;
	x.m_ptypes = NULL, x.m_xsect  = NULL,
	x.m_pradii = NULL, x.m_prdist = NULL,
	x.m_ptheta = NULL, x.m_pphi   = NULL,
	x.m_pvol   = NULL, x.m_psarea = NULL,
	x.m_ppx    = NULL, x.m_ppy    = NULL,
	x.m_ppz    = NULL, x.m_pvf    = NULL,
	x.m_ptmp   = NULL, x.m_pmass  = NULL;

	return (*this);
}

void
lam::wsr88d::Chebyshev_psingle_t
::set_ptypes(_In_ const int64_t * __restrict ptypes,
			 _In_ const int32_t vlen ) {
#if (LAM_DEBUG_ON) == 1
	_ASSERTE(m_np == vlen);
#else
	assert(m_np == vlen);
#endif
	
	memcpy(&m_ptypes[0], &ptypes[0], vlen);
}

void
lam::wsr88d::Chebyshev_psingle_t
::print_object_state() const {

	std::cout << " Dumping state of : -- " << typeid(*this).raw_name() << "\n";
	std::cout << "========================================================\n";
	std::cout << " Scalar members: \n";
	std::cout <<  " m_np:    "   << m_np   <<
		          " m_nt:    "   << m_nt   <<
				  " m_maxx:  "   << m_maxx <<
				  " m_maxy:  "   << m_maxy <<
				  " m_maxz:  "   << m_maxz <<
				  " m_maxsp:  "  << m_maxsp << "\n\n";
	std::cout << "========================================================\n";
	std::cout << " Array members:  \n";
	std::cout << " m_ptypes   :     m_pradii    :     m_pvol    :    m_psarea    :     m_ptmp     :     m_pmass   \n";
	for (int32_t i = 0; i != m_np; ++i) {
		std::cout << std::setprecision(15) << std::showpoint << std::setw(4) << 
			m_ptypes[i] << std::setw(8) << m_pradii[i] << std::setw(12) << m_pvol[i] << 
			std::setw(16) << m_psarea[i] << std::setw(20) << m_ptmp[i] << std::setw(24) << m_pmass[i] << "\n";
	}
	std::cout << " m_prdist   :     m_ptheta    :    m_pphi     :    m_pvf    \n";
	for (int32_t i = 0; i != m_np; ++i) {
		for (int32_t j = 0; j != m_nt; ++j) {
			std::cout << std::setprecision(15) << std::showpoint << std::setw(4) <<
				m_prdist[Ix2D(i, m_nt, j)] << std::setw(8) << m_ptheta[Ix2D(i,m_nt,j)] <<
				std::setw(12) << m_pphi[Ix2D(i, m_nt, j)] << std::setw(16) << m_pvf[Ix2D(i,m_nt,j)] << "\n";
		}
	}
	std::cout << " m_ppx     :     m_ppy        :    m_ppz           \n";
	for (int32_t i = 0; i != m_np; ++i) {
		for (int32_t j = 0; j != m_maxx; ++j) {
			std::cout << std::setprecision(15) << std::showpoint << std::setw(4) <<
				m_ppx[Ix2D(i, m_maxx, j)] << std::setw(8) << m_ppy[Ix2D(i, m_maxx, j)] <<
				std::setw(12) << m_ppz[Ix2D(i, m_maxx, j)] << "\n";
		}
	}
	std::cout << " m_xsect \n";
	for (int32_t i = 0; i != m_np; ++i) {
		for (int32_t j = 0; j != m_maxsp; ++j) {
			std::cout << std::setprecision(15) << std::showpoint << std::setw(4) <<
				m_xsect[Ix2D(i, m_maxsp, j)] << "\n";
		}     
	}
	std::cout << "================================================================== \n";
	std::cout << "							End of object dump				          \n\n";		
}

bool lam::wsr88d::Chebyshev_psingle_t
::compute_cross_section(_In_ const double * __restrict chebn,
						_In_ const double * __restrict sphrad,
						_In_ const double * __restrict cdeform,
						_In_ const int32_t vlen,
						_In_ const double inith,
						_In_ const double incth,
						_In_ const bool verbose,
						_In_ const bool curve_type) {
	using namespace lam::math::constants;
	double term,theta;
#if (LAM_DEBUG_ON) == 1
	_ASSERTE(vlen == this->m_np);
#else
	assert(vlen == this->m_np);
#endif
	if (inith < 0.0) {
		if (verbose) {
			PRINT_ERROR_INFO(" !!! <Invalid Argument> !!! : -- Invalid curve starting value (inith) ")
		}
		return (false);
	}
	for (int32_t i = 0; i != 16; ++i) {
		if (incth != LAM_dtcoeff[i]) {
			if (verbose) {
				PRINT_ERROR_INFO(" !!! <Invalid Argument> !!! : -- Invalid radian increment (incth) ")
			}
			return (false);
		}
	}
	for (int32_t i = 0; i != vlen; ++i) {
		if (chebn[i] < 0.0 || cdeform[i] > 1.0) {
			if (verbose) {
				PRINT_ERROR_INFO(" !!! <Invalid Argument> !!! : -- Invalid Chebyshev polynomial order, or invalid deform coefficient ")
			}
			return (false);
		}
	}
	term = 0.0, theta = inith;
	if (curve_type == true) {
	    for (int32_t i = 0; i != m_np; ++i) {

		      for (int32_t j = 0; j != m_maxsp; ++j) {
			       theta += incth;
			       term = 1.0 + cdeform[i] * std::cos(chebn[i] * theta);
			       m_xsect[Ix2D(i, m_maxsp, j)] = sphrad[i] * term;
		      }
	     }
	}
	else if (curve_type == false) {
		for (int32_t i = 0; i != m_np; ++i) {

			for (int32_t j = 0; j != m_maxsp; ++j) {
				theta += incth;
				term = 1.0 - cdeform[i] * std::cos(chebn[i] * theta);
				m_xsect[Ix2D(i, m_maxsp, j)] = sphrad[i] * term;
			}
		}
	}
	return (true);
}

void
lam::wsr88d::Chebyshev_psingle_t
::compute_volume(_In_ const double * __restrict sphrad,
						   _In_ const double * __restrict chebn,
						   _In_ const double * __restrict cdeform,
						   _In_ const int32_t vlen) {
	 using namespace lam::math::constants;
#if (LAM_DEBUG_ON) == 1
	_ASSERTE(m_np == vlen);
#else
	assert(m_np == vlen);
#endif
	double term1{}, term1a{}, term2{}, term3{}, term4{};
	
	for (int32_t i = 0; i != m_np; ++i) {

		term1  = LAM_THIRD*4.0*LAM_PI*sphrad[i]*sphrad[i]*sphrad[i];
		term1a = 1.0 + 1.5*cdeform[i]*cdeform[i]* 
			     4.0*chebn[i]*chebn[i]-2.0 / (4.0*chebn[i] * chebn[i]-1.0);
		if ((static_cast<uint32_t>(chebn[i]) & 1) == 0) {
			   term2 = 3.0 * cdeform[i] * (1.0 + cdeform[i] * cdeform[i]*0.25) / 
				      (chebn[i] * chebn[i] - 1.0);
			   term3 = 0.25 * cdeform[i] * cdeform[i] * cdeform[i] / 
				      (9.0 * chebn[i] * chebn[i] - 1.0);
			   term4 = term1 * (term1a - term2 - term3);
			   m_pvol[i] = term4;
		}
		 else {
			   term2 = term1 * term1a;
		       m_pvol[i] = term2;
		 }
	  }

}

void
lam::wsr88d::Chebyshev_psingle_t
::compute_surface_area(_In_ const double * __restrict sphrad,
					   _In_ const double * __restrict chebn,
					   _In_ const double * __restrict cdeform,
					   _In_ const int32_t vlen) {
	 using namespace lam::math::constants;
#if (LAM_DEBUG_ON) == 1
	_ASSERTE(m_np == vlen);
#else
	assert(m_np == vlen);
#endif
	double term1{}, term2{}, term3{}, term4{}, term5{}, term5a{};
	for (int32_t i = 0; i != m_np; ++i) {
		term1 = 4.0 * LAM_PI * sphrad[i] * sphrad[i];
		if ((static_cast<uint32_t>(chebn[i]) & 1) == 0) {
			term2  = 1.0 - 2.0 * cdeform[i] / (chebn[i] * chebn[i] - 1.0);
			term3  = cdeform[i] * cdeform[i] * chebn[i] * chebn[i] * chebn[i] * chebn[i] + 2.0 * 
					chebn[i] * chebn[i] - 1.0 / (4.0 * chebn[i] * chebn[i] - 1.0);
			term4  = 3.0 * cdeform[i] * cdeform[i] * cdeform[i] * cdeform[i] * std::pow(chebn[i],8.0) / 
				    (64.0 * chebn[i] * chebn[i] * chebn[i] * chebn[i] - 12.0 * chebn[i] * chebn[i] + 1.0);
			term5  = -6.0 * std::pow(cdeform[i], 5.0) * std::pow(chebn[i],8.0);
			term5a = 1.0 / ((chebn[i] * chebn[i] - 1.0) * (9.0 * chebn[i] * chebn[i] - 1.0) * (25.0 * chebn[i] * chebn[i] - 1.0));
			m_psarea[i] = term1 * (term2 + term3 - term4 - term5 * term5a);
		}
		else {
			term2 = 1.0 + cdeform[i] * cdeform[i] * chebn[i] * chebn[i] * chebn[i] * chebn[i] + 2.0 * chebn[i] * chebn[i] - 1.0 / 
					(4.0 * chebn[i] * chebn[i] - 1.0);
			term3 = 3.0 * std::pow(cdeform[i], 4.0) * std::pow(chebn[i],4.0) * 0.015625;
			term4 = 1.0 + 20.0 * chebn[i] * chebn[i] - 1.0 / 
				    (16.0 * chebn[i] * chebn[i] - 1.0)*(4.0 * chebn[i] * chebn[i] - 1.0);
			m_psarea[i] = term1 * (term2 - term3 * term4);
		}
	     
	}

}



bool
lam::wsr88d::Chebyshev_psingle_t
::compute_x_param(_In_ const double * __restrict sphrad, 
				  _In_ const double * __restrict cdeform,
				  _In_ const double * __restrict chebn,
				  _In_ const int32_t vlen,
				  _In_ const double inith,
				  _In_ const double incth,
				  _In_ const double iniphi,
				  _In_ const double incphi,
				  _In_ const bool verbose,
				  _In_ const bool curve_type  ) {
	using namespace lam::math::constants;
#if (LAM_DEBUG_ON) == 1
	_ASSERTE(m_np == vlen);
#else
	assert(m_np == vlen);
#endif
	double term{}, theta{}, phi{}, x{};
	if (iniphi < 0.0 || iniphi > 4.0 * Deg90toRad) {
		if (verbose) {
			PRINT_ERROR_INFO(" !!! <Invalid Argument> !!! : -- Invalid value of phi angle")
		}
		return (false);
	}
	for (int32_t i = 0; i != 16; ++i) {
		if (incphi != LAM_dtcoeff[i]) {
			if (verbose) {
				PRINT_ERROR_INFO(" !!! <Invalid Argument> !!! : -- Invalid phi angle increment")
			}
			return (false);
		}
	}
	theta = inith, phi = iniphi;
	if (curve_type == true) {
	     for (int32_t i = 0; i != m_np; ++i) {

		       for (int32_t j = 0; j != m_maxx; ++j) {
			        theta += incth;
					phi   += incphi;
					term = sphrad[i] * (1.0 + cdeform[i] * std::cos(chebn[i] * theta));
					x = term * std::sin(theta) * std::cos(phi);
					m_ppx[Ix2D(i,m_maxx,j)] = x;
		     }
	     }

	}
	else {
		for (int32_t i = 0; i != m_np; ++i) {

			for (int32_t j = 0; j != m_maxx; ++j) {
				theta += incth;
				phi += incphi;
				term = sphrad[i] * (1.0 - cdeform[i] * std::cos(chebn[i] * theta));
				x = term * std::sin(theta) * std::cos(phi);
				m_ppx[Ix2D(i, m_maxx, j)] = x;
			}
		}
	}
	return (true);
}

bool
lam::wsr88d::Chebyshev_psingle_t
::compute_y_param(_In_ const double * __restrict sphrad,
				  _In_ const double * __restrict cdeform,
				  _In_ const double * __restrict chebn,
				  _In_ const int32_t vlen,
				  _In_ const double inith,
				  _In_ const double incth,
				  _In_ const double iniphi,
			      _In_ const double incphi,
				  _In_ const bool verbose,
				  _In_ const bool curve_type) {
	using namespace lam::math::constants;
#if (LAM_DEBUG_ON) == 1
	_ASSERTE(m_np == vlen);
#else
	assert(m_np == vlen);
#endif
	double term{}, theta{}, phi{}, y{};
	if (iniphi < 0.0 || iniphi > 4.0 * Deg90toRad) {
		if (verbose) {
			PRINT_ERROR_INFO(" !!! <Invalid Argument> !!! : -- Invalid value of phi angle")
		}
		return (false);
	}
	for (int32_t i = 0; i != 16; ++i) {
		if (incphi != LAM_dtcoeff[i]) {
			if (verbose) {
				PRINT_ERROR_INFO(" !!! <Invalid Argument> !!! : -- Invalid phi angle increment")
			}
			return (false);
		}
	}
	theta = inith, phi = iniphi;
	if (curve_type == true) {
		for (int32_t i = 0; i != m_np; ++i) {

			for (int32_t j = 0; j != m_maxy; ++j) {
				 theta += incth;
				 phi   += incphi;
				 term = sphrad[i] * (1.0 + cdeform[i] * std::cos(chebn[i] * theta));
				 y = term * std::sin(theta) * std::sin(phi);
				 m_ppy[Ix2D(i,m_maxy,j)] = y;
			}
		}
	}
	else {
		for (int32_t i = 0; i != m_np; ++i) {

			for (int32_t j = 0; j != m_maxy; ++j) {
				theta += incth;
				phi += incphi;
				term = sphrad[i] * (1.0 - cdeform[i] * std::cos(chebn[i] * theta));
				y = term * std::sin(theta) * std::sin(phi);
				m_ppy[Ix2D(i, m_maxy, j)] = y;
			}
		}
	}
	return (true);
}


bool
lam::wsr88d::Chebyshev_psingle_t
::compute_z_param(_In_ const double * __restrict sphrad,
				  _In_ const double * __restrict chebn,
				  _In_ const double * __restrict cdeform,
				  _In_ const int32_t vlen,
				  _In_ const double inith,
				  _In_ const double incth,
				  _In_ const bool verbose,
				  _In_ const bool curve_type) {
	using namespace lam::math::constants;
#if (LAM_DEBUG_ON) == 1
	_ASSERTE(m_np == vlen);
#else
	asserte(m_np == vlen);
#endif
	double term{}, theta{}, z{};
	if (curve_type == true) {
		for (int32_t i = 0; i != m_np; ++i) {
			for (int32_t j = 0; j != m_maxz; ++j) {
				 theta += incth;
				 term = sphrad[i] * (1.0 + cdeform[i] * std::cos(chebn[i] * theta));
				 z = term * std::cos(theta);
				 m_ppz[Ix2D(i,m_maxz,j)] = z;
			}
		}
	}
	else {
		for (int32_t i = 0; i != m_np; ++i) {
			for (int32_t j = 0; j != m_maxz; ++j) {
				theta += incth;
				term = sphrad[i] * (1.0 - cdeform[i] * std::cos(chebn[i] * theta));
				z = term * std::cos(theta);
				m_ppz[Ix2D(i, m_maxz, j)] = z;
			}
		}
	}
	return (true);
}

void
lam::wsr88d::Chebyshev_psingle_t
::compute_vfall(_In_ const double * __restrict aRe,
				_In_ const double * __restrict bRe,
				_In_ const double * __restrict vb,
				_In_ const double * __restrict kvisc,
				_In_ const int32_t np,
				_In_ const int32_t nt,
				_In_ const int32_t nx,
				_In_ const int32_t ny,
				_In_ const int32_t nz,
				_In_ const double * __restrict A,
				_In_ const double * __restrict rho_b,
				_In_ const double * __restrict rho_f,
				_In_ const double Re,
				_In_ const double * __restrict mD,
				_In_ const double * __restrict bRet,
				_In_ const double * __restrict aRet) {
	using namespace lam::math::constants;
#if (LAM_DEBUG_ON) == 1
	_ASSERTE(np == m_np && nt == m_nt);
#else
	assert(np == m_np && nt == m_nt);
#endif
	double term1{}, term2{}, term2a{}, term3{}, 
		   tmp1{}, tmp2{};
	if ((std::abs(Re) - 999.0) <= DEPS) {

		for (int32_t i = 0; i != m_np; ++i) {
			for (int32_t j = 0; j != m_nt; ++j) {

				for (int32_t ix = 0; ix != nx; ++ix) {
					for (int32_t iy = 0; iy != ny; ++iy) {
						for (int32_t iz = 0; iz != nz; ++iz) {
							 tmp1 = 1.0 - 2.0 * bRet[Ix2D(i,m_nt,j)];
							 term1 = aRet[Ix2D(i, m_nt, j)] * std::pow(kvisc[Ix3D(ix,ny,iy,nz,iz)],tmp1);
							 term2 = (2.0 * vb[i] * 9.81) / A[i];
							 if (rho_b[i] > rho_f[Ix3D(ix, ny, iy, nz, iz)]) 
								 term2a = std::abs(rho_b[i] / rho_f[Ix3D(ix, ny, iy, nz, iz)]);
							 else
								 term2a = std::abs(rho_b[i] / rho_f[Ix3D(ix, ny, iy, nz, iz)] - 1.0);
							 tmp2 = 2.0 * bRet[Ix2D(i,m_nt,j)] - 1.0;
							 term3 = std::pow(mD[i],tmp2);
							 m_pvf[Ix2D(i, m_nt, j)] = term1 * std::pow(term2 * term2a, bRet[Ix2D(i,m_nt,j)]) * term3;
						}
					}
				}
			}
		}
	}
	else {
			
		for (int32_t i = 0; i != m_np; ++i) {
			for (int32_t j = 0; j != m_nt; ++j) {

				for (int32_t ix = 0; ix != nx; ++ix) {
					for (int32_t iy = 0; iy != ny; ++iy) {
						for (int32_t iz = 0; iz != nz; ++iz) {
							tmp1 = 1.0 - 2.0 * bRe[Ix2D(i, m_nt, j)];
							term1 = aRe[Ix2D(i, m_nt, j)] * std::pow(kvisc[Ix3D(ix, ny, iy, nz, iz)], tmp1);
							term2 = (2.0 * vb[i] * 9.81) / A[i];
							if (rho_b[i] > rho_f[Ix3D(ix, ny, iy, nz, iz)])
								term2a = std::abs(rho_b[i] / rho_f[Ix3D(ix, ny, iy, nz, iz)]);
							else
								term2a = std::abs(rho_b[i] / rho_f[Ix3D(ix, ny, iy, nz, iz)] - 1.0);
							tmp2 = 2.0 * bRe[Ix2D(i, m_nt, j)] - 1.0;
							term3 = std::pow(mD[i], tmp2);
							m_pvf[Ix2D(i, m_nt, j)] = term1 * std::pow(term2 * term2a, bRe[Ix2D(i, m_nt, j)]) * term3;
						}
					}
				}
			}
		}
	}
}





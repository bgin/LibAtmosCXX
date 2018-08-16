

#include "LAM_cheb_particles_aggregate.h"
#include "../LAM_malloc.h"
#include "../LAM_error_macros.h"
#include "../LAM_config.h"
#include "../LAM_indices.h"
#include "../LAM_common.h"
#include "../Math/LAM_constants.h"

//
//	Implementation
//

#if !defined (LAM_CHEB_PARTICLES_AGGREGATE_DEALLOCATE_ARRAYS)
#define LAM_CHEB_PARTICLES_AGGREGATE_DEALLOCATE_ARRAYS    \
      _mm_free(m_pfv);								      \
	  _mm_free(m_ppz);									  \
	  _mm_free(m_ppy);									  \
	  _mm_free(m_ppx);									  \
	  _mm_free(m_pes);									  \
	  _mm_free(m_pphi);									  \
	  _mm_free(m_ptheta);							      \
	  _mm_free(m_prdist);								  \
	  _mm_free(m_pradii);								  \
	  _mm_free(m_pcs);
#endif

using namespace lam::common;

lam::wsr88d::Chebyshev_paggregate_t
::Chebyshev_paggregate_t()
:
m_np{},
m_ID{},
m_nt{},
m_maxx{},
m_maxy{},
m_maxz{},
m_msval{},
m_htype{},
m_tpv{},
m_tps{},
m_tpm{},
m_pcs(NULL),
m_pradii(NULL),
m_prdist(NULL),
m_ptheta(NULL),
m_pphi(NULL),
m_pes(NULL),
m_ppx(NULL),
m_ppy(NULL),
m_ppz(NULL),
m_pfv(NULL) {}

lam::wsr88d::Chebyshev_paggregate_t
::Chebyshev_paggregate_t(_In_ const int32_t  np,
					     _In_ const uint32_t ID,
						 _In_ const int32_t  nt,
						 _In_ const int32_t  maxx,
						 _In_ const int32_t  maxy,
						 _In_ const int32_t  maxz,
						 _In_ const int32_t  msval,
						 _In_ const uint32_t htype)
:
m_np{ np },
m_ID{ ID },
m_nt{ nt },
m_maxx{ maxx },
m_maxy{ maxy },
m_maxz{ maxz },
m_msval{ msval },
m_htype{ htype },
m_tpv{},
m_tps{},
m_tpm{},
m_pcs(   lam_edmalloca(static_cast<size_t>(m_np*m_msval),  align64B)),
m_pradii(lam_edmalloca(static_cast<size_t>(m_np),          align64B)),
m_prdist(lam_edmalloca(static_cast<size_t>(m_np*m_nt),     align64B)),
m_ptheta(lam_edmalloca(static_cast<size_t>(m_np*m_nt),     align64B)),
m_pphi(  lam_edmalloca(static_cast<size_t>(m_np*m_nt),     align64B)),
m_pes(   lam_edmalloca(static_cast<size_t>(3*m_np),        align64B)),
m_ppx(   lam_edmalloca(static_cast<size_t>(m_np*m_maxx),   align64B)),
m_ppy(   lam_edmalloca(static_cast<size_t>(m_np*m_maxy),   align64B)),
m_ppz(   lam_edmalloca(static_cast<size_t>(m_np*m_maxz),   align64B)),
m_pfv(   lam_edmalloca(static_cast<size_t>(m_nt),          align64B)) {
	
	using namespace lam::math::constants;
	avx256_init_unroll8x(&m_pcs[0],    static_cast<size_t>(m_np*m_msval),dinf);
	avx256_init_unroll8x(&m_pradii[0], static_cast<size_t>(m_np),dinf);
	avx256_init_unroll8x(&m_prdist[0], static_cast<size_t>(m_np*m_nt),dinf);
	avx256_init_unroll8x(&m_ptheta[0], static_cast<size_t>(m_np*m_nt),dinf);
	avx256_init_unroll8x(&m_pphi[0],   static_cast<size_t>(m_np*m_nt), dinf);
	avx256_init_unroll8x(&m_pes[0],    static_cast<size_t>(3*m_np), dinf);
	avx256_init_unroll8x(&m_ppx[0],    static_cast<size_t>(m_np*m_maxx),dinf);
	avx256_init_unroll8x(&m_ppy[0],    static_cast<size_t>(m_np*m_maxy), dinf);
	avx256_init_unroll8x(&m_ppz[0],    static_cast<size_t>(m_np*m_maxz), dinf);
	avx256_init_unroll8x(&m_pfv[0],	   static_cast<size_t>(m_nt), dinf);
}

lam::wsr88d::Chebyshev_paggregate_t
::Chebyshev_paggregate_t(_In_ const Chebyshev_paggregate_t &x)
:
m_np{ x.m_np },
m_ID{ x.m_ID },
m_nt{ x.m_nt },
m_maxx{ x.m_maxx },
m_maxy{ x.m_maxy },
m_maxz{ x.m_maxz },
m_msval{ x.m_msval },
m_htype{ x.m_htype },
m_tpv{ x.m_tpv },
m_tps{ x.m_tps },
m_tpm{ x.m_tpm},
m_pcs(   lam_edmalloca(static_cast<size_t>(m_np*m_msval), align64B)),
m_pradii(lam_edmalloca(static_cast<size_t>(m_np),         align64B)),
m_prdist(lam_edmalloca(static_cast<size_t>(m_np*m_nt),    align64B)),
m_ptheta(lam_edmalloca(static_cast<size_t>(m_np*m_nt),    align64B)),
m_pphi(  lam_edmalloca(static_cast<size_t>(m_np*m_nt),    align64B)),
m_pes(   lam_edmalloca(static_cast<size_t>(3 * m_np),     align64B)),
m_ppx(   lam_edmalloca(static_cast<size_t>(m_np*m_maxx),  align64B)),
m_ppy(   lam_edmalloca(static_cast<size_t>(m_np*m_maxy),  align64B)),
m_ppz(   lam_edmalloca(static_cast<size_t>(m_np*m_maxz),  align64B)),
m_pfv(   lam_edmalloca(static_cast<size_t>(m_nt),         align64B)) {
	
	avx256_memcpy8x(&m_pcs[0],    &x.m_pcs[0],    static_cast<size_t>(m_np*m_msval));
	avx256_memcpy8x(&m_pradii[0], &x.m_pradii[0], static_cast<size_t>(m_np));
	avx256_memcpy8x(&m_prdist[0], &x.m_pradii[0], static_cast<size_t>(m_np*m_nt));
	avx256_memcpy8x(&m_ptheta[0], &x.m_ptheta[0], static_cast<size_t>(m_np*m_nt));
	avx256_memcpy8x(&m_pphi[0],   &x.m_pphi[0],   static_cast<size_t>(m_np*m_nt));
	avx256_memcpy8x(&m_pes[0],	  &x.m_pes[0],    static_cast<size_t>(3 * m_np));
	avx256_memcpy8x(&m_ppx[0],    &x.m_ppx[0],    static_cast<size_t>(m_np*m_maxx));
	avx256_memcpy8x(&m_ppy[0],    &x.m_ppy[0],    static_cast<size_t>(m_np*m_maxy)); 
	avx256_memcpy8x(&m_ppz[0],	  &x.m_ppz[0],    static_cast<size_t>(m_np*m_maxz));
	avx256_memcpy8x(&m_pfv[0],    &x.m_pfv[0],    static_cast<size_t>(m_nt));

}

lam::wsr88d::Chebyshev_paggregate_t
::Chebyshev_paggregate_t(_In_ Chebyshev_paggregate_t &&x)
:
m_np{ x.m_np },
m_ID{ x.m_ID },
m_nt{ x.m_nt },
m_maxx{ x.m_maxx },
m_maxy{ x.m_maxy },
m_maxz{ x.m_maxz },
m_msval{ x.m_msval },
m_htype{ x.m_htype },
m_tpv{ x.m_tpv },
m_tps{ x.m_tps },
m_tpm{ x.m_tpm },
m_pcs(NULL),
m_pradii(NULL),
m_prdist(NULL),
m_ptheta(NULL),
m_pphi(NULL),
m_pes(NULL),
m_ppx(NULL),
m_ppy(NULL),
m_ppz(NULL),
m_pfv(NULL) {

	m_pcs    = x.m_pcs,   m_pradii = x.m_pradii,
	m_prdist = x.m_prdist,m_ptheta = x.m_ptheta,
	m_pphi   = x.m_pphi,     m_pes = x.m_pes,
	m_ppx    = x.m_ppx,      m_ppy = x.m_ppy,m_ppz = x.m_ppz,
	m_pfv    = x.m_pfv;

	x.m_np = 0, x.m_ID = 9999,
	x.m_nt = 0, x.m_maxx = 0,
	x.m_maxy = 0, x.m_maxz = 0,
	x.m_msval = 0, x.m_htype = 9999,
	x.m_tpv = 0.0,x.m_tps = 0.0,
	x.m_tpm = 0.0;

	x.m_pcs    = NULL, x.m_pradii = NULL,
	x.m_prdist = NULL, x.m_ptheta = NULL,
	x.m_pphi   = NULL, x.m_pes    = NULL,
	x.m_ppx    = NULL, x.m_ppy    = NULL,
	x.m_ppz    = NULL, x.m_pfv    = NULL;
}

lam::wsr88d::Chebyshev_paggregate_t
::~Chebyshev_paggregate_t() {

	if (m_pfv != NULL) {
		_mm_free(m_pfv);
		m_pfv = NULL;
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
	if (m_pes != NULL) {
		_mm_free(m_pes);
		m_pes = NULL;
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
		m_prdist = NULL;
	}
	if (m_pradii != NULL) {
		_mm_free(m_pradii);
		m_pradii = NULL;
	}
	if (m_pcs != NULL) {
		_mm_free(m_pcs);
		m_pcs = NULL;
	}
}

lam::wsr88d::Chebyshev_paggregate_t &
lam::wsr88d::Chebyshev_paggregate_t
::operator=(_In_ const Chebyshev_paggregate_t &x) {
	if (this == &x) return (*this);

	m_np    = x.m_np,    m_ID = x.m_ID,
	m_nt    = x.m_nt,    m_maxx = x.m_maxx,
	m_maxy  = x.m_maxy,  m_maxz = x.m_maxz,
	m_msval = x.m_msval,m_htype = x.m_htype,
	m_tpv   = x.m_tpv,    m_tps = x.m_tps,
	m_tpm   = x.m_tpm;
	LAM_CHEB_PARTICLES_AGGREGATE_DEALLOCATE_ARRAYS

    double * __restrict pcs(lam_edmalloca(static_cast<size_t>(m_np*m_msval), align64B));
	double * __restrict pradii(lam_edmalloca(static_cast<size_t>(m_np), align64B));
	double * __restrict prdist(lam_edmalloca(static_cast<size_t>(m_np*m_nt), align64B));
	double * __restrict ptheta(lam_edmalloca(static_cast<size_t>(m_np*m_nt), align64B));
	double * __restrict pphi(lam_edmalloca(static_cast<size_t>(m_np*m_nt), align64B));
	double * __restrict pes(lam_edmalloca(static_cast<size_t>(3 * m_np), align64B));
	double * __restrict ppx(lam_edmalloca(static_cast<size_t>(m_np*m_maxx), align64B));
	double * __restrict ppy(lam_edmalloca(static_cast<size_t>(m_np*m_maxy), align64B));
	double * __restrict ppz(lam_edmalloca(static_cast<size_t>(m_np*m_maxz), align64B));
	double * __restrict pfv(lam_edmalloca(static_cast<size_t>(m_nt), align64B));

	avx256_memcpy8x(&pcs[0],    &x.m_pcs[0], static_cast<size_t>(m_np*m_msval));
	avx256_memcpy8x(&pradii[0], &x.m_pradii[0], static_cast<size_t>(m_np));
	avx256_memcpy8x(&prdist[0], &x.m_prdist[0], static_cast<size_t>(m_np*m_nt));
	avx256_memcpy8x(&ptheta[0], &x.m_ptheta[0], static_cast<size_t>(m_np*m_nt));
	avx256_memcpy8x(&pphi[0],   &x.m_pphi[0], static_cast<size_t>(m_np*m_nt));
	avx256_memcpy8x(&pes[0],    &x.m_pes[0], static_cast<size_t>(3 * m_np));
	avx256_memcpy8x(&ppx[0],    &x.m_ppx[0], static_cast<size_t>(m_np*m_maxx));
	avx256_memcpy8x(&ppy[0],    &x.m_ppy[0], static_cast<size_t>(m_np*m_maxy));
	avx256_memcpy8x(&ppz[0],    &x.m_ppz[0], static_cast<size_t>(m_np*m_maxz));
	avx256_memcpy8x(&pfv[0],    &x.m_pfv[0], static_cast<size_t>(m_nt));

	m_pcs = pcs, m_pradii = pradii,
	m_prdist = prdist,m_ptheta = ptheta,
	m_pphi = pphi,m_pes = pes,
	m_ppx = ppx,m_ppy = ppy,
	m_ppz = ppz,m_pfv = pfv;

	return (*this);
}

lam::wsr88d::Chebyshev_paggregate_t &
lam::wsr88d::Chebyshev_paggregate_t
::operator=(_In_ Chebyshev_paggregate_t &&x) {
	if (this == &x) return (*this);

	    m_np = x.m_np, m_ID = x.m_ID,
		m_nt = x.m_nt, m_maxx = x.m_maxx,
		m_maxy = x.m_maxy, m_maxz = x.m_maxz,
		m_msval = x.m_msval, m_htype = x.m_htype,
		m_tpv = x.m_tpv, m_tps = x.m_tps,
		m_tpm = x.m_tpm;
	    LAM_CHEB_PARTICLES_AGGREGATE_DEALLOCATE_ARRAYS

	    m_pcs = x.m_pcs, m_pradii = x.m_pradii,
	    m_prdist = x.m_prdist, m_ptheta = x.m_ptheta,
	    m_pphi = x.m_pphi, m_pes = x.m_pes,
		m_ppx = x.m_ppx, m_ppy = x.m_ppy, m_ppz = x.m_ppz,
		m_pfv = x.m_pfv;

		x.m_np = 0, x.m_ID = 9999,
		x.m_nt = 0, x.m_maxx = 0,
		x.m_maxy = 0, x.m_maxz = 0,
		x.m_msval = 0, x.m_htype = 9999,
		x.m_tpv = 0.0, x.m_tps = 0.0,
		x.m_tpm = 0.0;

		x.m_pcs = NULL, x.m_pradii = NULL,
		x.m_prdist = NULL, x.m_ptheta = NULL,
		x.m_pphi = NULL, x.m_pes = NULL,
		x.m_ppx = NULL, x.m_ppy = NULL,
		x.m_ppz = NULL, x.m_pfv = NULL;

		return (*this);
}

void
lam::wsr88d::Chebyshev_paggregate_t
::print_object_state() const {

	std::cout << "		Dumping state of: -- " << typeid(*this).raw_name() << "\n";
	std::cout << "=============================================================\n";
	std::cout << "		Scalar members:										   \n";
	std::cout << "	m_np:	" << m_np    <<
				 "  m_ID:	" << m_ID    <<
				 "  m_nt:	" << m_nt    <<
				 "  m_maxx: " << m_maxx  <<
				 "  m_maxy: " << m_maxy  <<
				 "  m_maxz: " << m_maxz  <<
				 "  m_msval:" << m_msval <<
				 "  m_htype:" << m_htype <<
				 "  m_tpv:	" << m_tpv   <<
				 "  m_tps:  " << m_tps   <<
				 "  m_tpm:  " << m_tpm   << "\n\n";
	std::cout << "============================================================\n";
	std::cout << "     Array members:										  \n";
	std::cout << "  m_pcs:												      \n";
	for (int32_t i = 0; i != m_np; ++i) {
		for (int32_t j = 0; j != m_msval; ++j) {
			std::cout << std::setw(4) << std::setprecision(15) << std::showpoint <<
				m_pcs[Ix2D(i, m_msval, j)] << "\n";
		}
		std::cout << "\n";
	}
	std::cout << "  m_pradii:												   \n";
	for (int32_t i = 0; i != m_np; ++i) {
		std::cout << std::setw(4) << std::setprecision(15) << std::showpoint <<
			m_pradii[i] << "\n";
	}
	std::cout << " m_prdist		:       m_ptheta	 :         m_pphi          \n";
	for (int32_t i = 0; i != m_np; ++i) {
		for (int32_t j = 0; j != m_nt; ++j) {
			std::cout << std::setw(4) << std::setprecision(15) << std::showpoint <<
				m_prdist[Ix2D(i, m_nt, j)] << std::setw(8) << m_ptheta[Ix2D(i,m_nt,j)] <<
				std::setw(12) << m_pphi[Ix2D(i, m_nt, j)] << "\n";
		}
		std::cout << "\n";
	}
	std::cout << " m_pes													   \n";
	for (int32_t i = 0; i != 3; ++i) {
		for (int32_t j = 0; j != m_np; ++j) {
			std::cout << std::setw(4) << std::setprecision(15) << std::showpoint <<
				m_pes[Ix2D(i, m_np, j)] << "\n";
		}
		std::cout << "\n";
	}
	if (m_maxx == m_maxy && m_maxx == m_maxz) {
		std::cout << " m_ppx      :       m_ppy       :        m_ppz           \n";
		for (int32_t i = 0; i != m_np; ++i) {
			for (int32_t j = 0; j != m_maxx; ++j) {
				std::cout << std::setw(4) << std::setprecision(15) << std::showpoint <<
					m_ppx[Ix2D(i, m_maxx, j)] << std::setw(8) << m_ppy[Ix2D(i,m_maxx,j)] <<
					m_ppz[Ix2D(i, m_maxx, j)] << "\n";
			}
			std::cout << "\n";
		}
	}
	else {
		std::cout << " m_ppx                                                   \n";
		for (int32_t i = 0; i != m_np; ++i) {
			for (int32_t j = 0; j != m_maxx; ++j) {
				std::cout << std::setw(4) << std::setprecision(15) << std::showpoint <<
					m_ppx[Ix2D(i, m_maxx, j)] << "\n";
			}
		}
		std::cout << " m_ppy                                                   \n";
		for (int32_t i = 0; i != m_np; ++i) {
			for (int32_t j = 0; j != m_maxy; ++j) {
				std::cout << std::setw(4) << std::setprecision(15) << std::showpoint <<
					m_ppy[Ix2D(i, m_maxy, j)] << "\n";
			}
		}
		std::cout << " m_ppz                                                   \n";
		for (int32_t i = 0; i != m_np; ++i) {
			for (int32_t j = 0; j != m_maxz; ++j) {
				std::cout << std::setw(4) << std::setprecision(15) << std::showpoint <<
					m_ppz[Ix2D(i, m_maxz, j)] << "\n";
			}
		}
	}
	std::cout << "   m_pfv                                                     \n";
	for (int32_t i = 0; i != m_nt; ++i) {
		std::cout << std::setw(4) << std::setprecision(15) << std::showpoint <<
			m_pfv[i] << "\n";
	}
	std::cout << "        End of object:   --  " << typeid(*this).raw_name() << " dump. " << "\n";
}

bool
lam::wsr88d::Chebyshev_paggregate_t
::compute_cross_section(_In_ const double * __restrict sphrad,
					    _In_ const double * __restrict chebn,
						_In_ const double * __restrict cdeform,
						_In_ const int32_t vlen,
						_In_ const double inith,
						_In_ const double incth,
						_In_ const bool verbose,
						_In_ const bool curve_type) {

#if (LAM_DEBUG_ON) == 1
	_ASSERTE(vlen == m_np);
#else
	assert(vlen == m_np);
#endif
	double theta{}, term{}, r{};
	using namespace lam::math::constants;
	if (inith < 0.0) {
		if (verbose) {
			PRINT_ERROR_INFO("  !!! <Invalid Argument> !!! : -- Invalid curve starting value (inith)")
		}
		return (false);
	}
	for (int32_t i = 0; i != 16; ++i) {
		if (incth != LAM_dtcoeff[i]) {
			if (verbose) {
				PRINT_ERROR_INFO("  !!! <Invalid Argument> !!! : -- Invalid radian increment (incth)  ")
			}
			return (false);
		}
	}
	for (int32_t i = 0; i != m_np; ++i) {
		if (chebn[i] < 0.0 || std::abs(cdeform[i]) > 1.0) {
			if (verbose) {
				PRINT_ERROR_INFO(" !!! <Invalid Argument> !!! : -- Invalid Chebyshev polynomial order, or invalid deform coefficient ")
			}
			return (false);
		}
	}
	theta = inith;
	if (curve_type == true) {
		for (int32_t i = 0; i != m_np; ++i) {
			for (int32_t j = 0; j != m_msval; ++j) {
				 theta += incth;
				 term = 1.0 + cdeform[i] * std::cos(chebn[i] * theta);
				 m_pcs[Ix2D(i, m_msval, j)] = sphrad[i] * term;
			}
		}
	}
	else {
		for (int32_t i = 0; i != m_np; ++i) {
			for (int32_t j = 0; j != m_msval; ++j) {
				theta += incth;
				term = 1.0 - cdeform[i] * std::cos(chebn[i] * theta);
				m_pcs[Ix2D(i, m_msval, j)] = sphrad[i] * term;
			}
		}
	}
	return (true);
}

bool 
lam::wsr88d::Chebyshev_paggregate_t
::compute_ensemble_shape(_In_ const double inz,
					     _In_ const double incz,
						 _In_ const EnsembleShapes shape_type,
						 _In_ const double r,
						 _In_ const double inphi,
						 _In_ const double inth,
						 _In_ const double incphi,
						 _In_ const double incth,
						 _In_ const double sphrad,
						 _In_ const double chebn,
						 _In_ const double cdeform,
						 _In_ const bool  verbose,
						 _In_ const bool curve_type) {

	double term1{}, phi{}, theta{}, x{}, y{}, z{}, u{};
	switch (shape_type) {
		case EnsembleShapes::Cylindrical : {
				z = inz;
				theta = inth;
				for (int32_t i = 0; i != 3; ++i) {
					for (int32_t j = 0; j != m_np; ++j) {
						theta += incth;
						z += incz;
						if (i == 0) {
							m_pes[Ix2D(i, m_np, j)] = r * cos(theta);
						}
						else if (i == 1) {
							m_pes[Ix2D(i, m_np, j)] = r * sin(theta);
						}
						else if (i == 2) {
							m_pes[Ix2D(i,m_np,j)]  = z;
						}
					}
				}
	      }
		     break;
		case EnsembleShapes::Spheroidal: {
			    theta = inth;
				phi = inphi;
				for (int32_t i = 0; i != 3; ++i) {
					for (int32_t j = 0; j != m_np; ++j) {
						 theta += incth;
						 phi += incphi;
						 u = r * cos(phi);
						 if (i == 0) {
							 m_pes[Ix2D(i, m_np, j)] = std::sqrt(r*r - u * u) * cos(theta);
						 }
						 else if (i == 1) {
							 m_pes[Ix2D(i, m_np, j)] = std::sqrt(r*r - u * u) * sin(theta);
						 }
						 else if (i == 2) {
							 m_pes[Ix2D(i,m_np,j)]  = u;
						 }
					}
				}
		}
		   break;
		case EnsembleShapes::Chebyshev: {
			    theta = inth;
				phi = inphi;
				if (curve_type == true){

				    for (int32_t i = 0; i != 3; ++i) {
					     for (int32_t j = 0; j != m_np; ++j) {
						       theta += incth;
						       phi += incphi;
							   term1 = sphrad * (1.0 + cdeform * cos(chebn * theta));
							   if (i == 0) {
								   x = term1 * sin(theta) * cos(phi);
								   m_pes[Ix2D(i,m_np,j)] = x;
							   }
							   else if (i == 1) {
								   y = term1 * sin(theta) * sin(phi);
								   m_pes[Ix2D(i,m_np,j)] = y;
							   }
							   else if (i == 2) {
								   z = term1 * cos(theta);
								   m_pes[Ix2D(i,m_np,j)] = z;
							   }
					}
				}
			}
				else {

					for (int32_t i = 0; i != 3; ++i) {
						for (int32_t j = 0; j != m_np; ++j) {
							theta += incth;
							phi += incphi;
							term1 = sphrad * (1.0 - cdeform * cos(chebn * theta));
							if (i == 0) {
								x = term1 * sin(theta) * cos(phi);
								m_pes[Ix2D(i, m_np, j)] = x;
							}
							else if (i == 1) {
								y = term1 * sin(theta) * sin(phi);
								m_pes[Ix2D(i, m_np, j)] = y;
							}
							else if (i == 2) {
								z = term1 * cos(theta);
								m_pes[Ix2D(i, m_np, j)] = z;
							}
						}
					}
				}
		}
		  break;
		default: {
					 if (verbose) {
						 PRINT_ERROR_INFO(" !!! <Invalid Argument> !!! : -- Invalid argument to switch statement.")
					 }
					 return (false);
		}
	}
	return (true);
}

bool
lam::wsr88d::Chebyshev_paggregate_t
::compute_x_param(_In_ const double * __restrict sphrad,
				  _In_ const double * __restrict chebn,
				  _In_ const double * __restrict cdeform,
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
		// Additive curve
		for (int32_t i = 0; i != m_np; ++i) {
			for (int32_t j = 0; j != m_maxx; ++j) {
				theta += incth;
				phi += incphi;
				term = sphrad[i] * (1.0 + cdeform[i] * cos(chebn[i] * theta));
				x = term * sin(theta) * cos(phi);
				m_ppx[Ix2D(i,m_maxx,j)] = x;
			}
		}
	}
	else {
		// Subtractive curve
		for (int32_t i = 0; i != m_np; ++i) {
			for (int32_t j = 0; j != m_maxx; ++j) {
				theta += incth;
				phi += incphi;
				term = sphrad[i] * (1.0 - cdeform[i] * cos(chebn[i] * theta));
				x = term * sin(theta) * cos(phi);
				m_ppx[Ix2D(i, m_maxx, j)] = x;
			}
		}
	}
	return (true);
}

bool
lam::wsr88d::Chebyshev_paggregate_t
::compute_y_param(_In_ const double * __restrict sphrad,
				  _In_ const double * __restrict chebn,
				  _In_ const double * __restrict cdeform,
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
		// Additive
		for (int32_t i = 0; i != m_np; ++i) {
			for (int32_t j = 0; j != m_maxy; ++j) {
				theta += incth;
				phi   += incphi;
				term = sphrad[i] * (1.0 + cdeform[i] * cos(chebn[i] * theta));
				y = term * sin(theta) * sin(phi);
				m_ppy[Ix2D(i,m_maxy,j)] = y;
			}
		}
	}
	else {
		// Subtractive
		for (int32_t i = 0; i != m_np; ++i) {
			for (int32_t j = 0; j != m_maxy; ++j) {
				theta += incth;
				phi += incphi;
				term = sphrad[i] * (1.0 - cdeform[i] * cos(chebn[i] * theta));
				y = term * sin(theta) * sin(phi);
				m_ppy[Ix2D(i, m_maxy, j)] = y;
			}
		}
	}
	return (true);
}

void
lam::wsr88d::Chebyshev_paggregate_t
::compute_z_param(_In_ const double * __restrict sphrad,
			      _In_ const double * __restrict chebn,
				  _In_ const double * __restrict cdeform,
				  _In_ const int32_t vlen,
				  _In_ const double inith,
				  _In_ const double incth,

				  _In_ const bool curve_type) {
#if (LAM_DEBUG_ON) == 1
	_ASSERTE(m_np == vlen);
#else
	asserte(m_np == vlen);
#endif
	double term{}, theta{}, z{};
	theta = inith;
	if (curve_type == true) {

		for (int32_t i = 0; i != m_np; ++i) {
			for (int32_t j = 0; j != m_maxz; ++j) {
				 theta += incth;
				 term = sphrad[i] * (1.0 + cdeform[i] + cos(chebn[i] * theta));
				 z = term * cos(theta);
				 m_ppz[Ix2D(i,m_np,j)] = z;
		  }
	   }
	}
	else {

		for (int32_t i = 0; i != m_np; ++i) {
			for (int32_t j = 0; j != m_maxz; ++j) {
				theta += incth;
				term = sphrad[i] * (1.0 - cdeform[i] + cos(chebn[i] * theta));
				z = term * cos(theta);
				m_ppz[Ix2D(i, m_np, j)] = z;
			}
		}
	}
}

void
lam::wsr88d::Chebyshev_paggregate_t
::compute_ensemble_vol(_In_ const double * __restrict sphrad,
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

		term1 = LAM_THIRD*4.0*LAM_PI*sphrad[i] * sphrad[i] * sphrad[i];
		term1a = 1.0 + 1.5*cdeform[i] * cdeform[i] *
			4.0*chebn[i] * chebn[i] - 2.0 / (4.0*chebn[i] * chebn[i] - 1.0);
		if ((static_cast<uint32_t>(chebn[i]) & 1) == 0) {
			term2 = 3.0 * cdeform[i] * (1.0 + cdeform[i] * cdeform[i] * 0.25) /
				(chebn[i] * chebn[i] - 1.0);
			term3 = 0.25 * cdeform[i] * cdeform[i] * cdeform[i] /
				(9.0 * chebn[i] * chebn[i] - 1.0);
			term4 = term1 * (term1a - term2 - term3);
			m_tpv += term4;
		}
		else {
			term2 = term1 * term1a;
			m_tpv += term2;
		}
	}
}

void
lam::wsr88d::Chebyshev_paggregate_t
::compute_ensemble_surf(_In_ const double * __restrict sphrad,
					    _In_ const double * __restrict chebn,
					    _In_ const double * __restrict cdeform,
					    _In_ const int32_t vlen) {
	using namespace lam::math::constants;
#if (LAM_DEBUG_ON) == 1
	_ASSERTE(m_np == vlen);
#else
	assert(m_np == vlen);
#endif
	double term1{}, term2{}, term3{}, term4{}, term5{}, term5a{}, tmp{};
	for (int32_t i = 0; i != m_np; ++i) {
		term1 = 4.0 * LAM_PI * sphrad[i] * sphrad[i];
		if ((static_cast<uint32_t>(chebn[i]) & 1) == 0) {
			term2 = 1.0 - 2.0 * cdeform[i] / (chebn[i] * chebn[i] - 1.0);
			term3 = cdeform[i] * cdeform[i] * chebn[i] * chebn[i] * chebn[i] * chebn[i] + 2.0 *
				chebn[i] * chebn[i] - 1.0 / (4.0 * chebn[i] * chebn[i] - 1.0);
			term4 = 3.0 * cdeform[i] * cdeform[i] * cdeform[i] * cdeform[i] * std::pow(chebn[i], 8.0) /
				(64.0 * chebn[i] * chebn[i] * chebn[i] * chebn[i] - 12.0 * chebn[i] * chebn[i] + 1.0);
			term5 = -6.0 * std::pow(cdeform[i], 5.0) * std::pow(chebn[i], 8.0);
			term5a = 1.0 / ((chebn[i] * chebn[i] - 1.0) * (9.0 * chebn[i] * chebn[i] - 1.0) * (25.0 * chebn[i] * chebn[i] - 1.0));
			tmp = term1 * (term2 + term3 - term4 - term5 * term5a);
			m_tps += tmp;
		}
		else {
			term2 = 1.0 + cdeform[i] * cdeform[i] * chebn[i] * chebn[i] * chebn[i] * chebn[i] + 2.0 * chebn[i] * chebn[i] - 1.0 /
				(4.0 * chebn[i] * chebn[i] - 1.0);
			term3 = 3.0 * std::pow(cdeform[i], 4.0) * std::pow(chebn[i], 4.0) * 0.015625;
			term4 = 1.0 + 20.0 * chebn[i] * chebn[i] - 1.0 /
				(16.0 * chebn[i] * chebn[i] - 1.0)*(4.0 * chebn[i] * chebn[i] - 1.0);
			tmp = term1 * (term2 - term3 * term4);
			m_tps += tmp;
		}

	}
}

void
lam::wsr88d::Chebyshev_paggregate_t
::compute_vertical_fall(_In_ const double * __restrict aRe,
						_In_ const double * __restrict bRe,
						_In_ const int32_t vlen,
						_In_ const double vb,
						_In_ const double * __restrict kvisc,
						_In_ const int32_t nx,
						_In_ const int32_t ny,
						_In_ const int32_t nz,
						_In_ const double A,
						_In_ const double rho_b,
						_In_ const double * __restrict rho_f,
						_In_ const double mD,
						_In_ const double Re,
						_In_ const double * __restrict aRet,
						_In_ const double * __restrict bRet) {
	using namespace lam::math::constants;
#if (LAM_DEBUG_ON) == 1
	_ASSERTE(m_np == vlen);
#else
	assert(m_np == vlen);
#endif
	double term1{}, term2{}, term2a{}, term3{}, tmp{},tmp2{};
	if ((std::abs(Re) - 999.0) <= DEPS) {
#if (USE_OPENMP) == 1
#pragma omp parallel for private(i) schedule(runtime)	
#endif	
		for (int32_t i = 0; i != m_nt; ++i) {

			for (int32_t ix = 0; ix != nx; ++ix) {
				for (int32_t iy = 0; iy != ny; ++iy) {
					for (int32_t iz = 0; iz != nz; ++iz) {
						tmp = 1.0 - 2.0 * bRet[i];
						term1 = aRet[i] * std::pow(kvisc[Ix3D(ix,ny,iy,nz,iz)],tmp);
						term2 = (2.0 * vb * 9.81) / A;
						if (rho_b > rho_f[Ix3D(ix, ny, iy, nz, iz)]) {
							term2a = std::abs(rho_b / rho_f[Ix3D(ix,ny,iy,nz,iz)]);
						}
						else {
							term2a = std::abs(rho_b / rho_f[Ix3D(ix, ny, iy, nz, iz)] - 1.0);
						}
						tmp2 = 2.0 * bRet[i] - 1.0;
						term3 = std::pow(mD,tmp2);
						m_pfv[i] = term1 * std::pow(term2*term2a, bRet[i]*term3);
					}
				}
			}
		}
	}
	else {
#if (USE_OPENMP) == 1
#pragma omp parallel for private(i) schedule(runtime)
#endif			
		for (int32_t i = 0; i != m_nt; ++i) {

			for (int32_t ix = 0; ix != nx; ++ix) {
				for (int32_t iy = 0; iy != ny; ++iy) {
					for (int32_t iz = 0; iz != nz; ++iz) {
						tmp = 1.0 - 2.0 * bRe[i];
						term1 = aRe[i] * std::pow(kvisc[Ix3D(ix, ny, iy, nz, iz)], tmp);
						term2 = (2.0 * vb * 9.81) / A;
						if (rho_b > rho_f[Ix3D(ix, ny, iy, nz, iz)]) {
							term2a = std::abs(rho_b / rho_f[Ix3D(ix, ny, iy, nz, iz)]);
						}
						else {
							term2a = std::abs(rho_b / rho_f[Ix3D(ix, ny, iy, nz, iz)] - 1.0);
						}
						tmp2 = 2.0 * bRe[i] - 1.0;
						term3 = std::pow(mD, tmp2);
						m_pfv[i] = term1 * std::pow(term2*term2a, bRe[i] * term3);
					}
				}
			}
		}
	}
}





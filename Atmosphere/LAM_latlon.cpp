
#include <iostream>
#include <iomanip>

#include "LAM_latlon.h"
#include "../LAM_config.h"
#include "../LAM_simd_defs.h"

//
//	Implementation
//

lam::atmosphere::
LatLon::LatLon(_In_ const uint64_t idx[18])
:
m_ims{ idx[0] },  m_ime{ idx[1] },
m_jms{ idx[2] },  m_jme{ idx[3] },
m_ids{ idx[4] },  m_ide{ idx[5] },
m_jds{ idx[6] },  m_jde{ idx[7] },
m_its{ idx[8] },  m_ite{ idx[9] },
m_jts{ idx[10] }, m_jte{ idx[11] },
m_lat(reinterpret_cast<double*>(_mm_malloc((m_ime*m_jme)*sizeof(double),align32B))),
m_long(reinterpret_cast<double*>(_mm_malloc((m_ime*m_jme)*sizeof(double), align32B))){
	if (NULL == m_long || NULL == m_lat) {
#if LAM_VERBOSE_ON == 1
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
													Memory allocation failure in: LatLon::LatLon(uint64_t *)\n";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
#endif
		throw std::runtime_error("Memory allocation failure in: LatLon::LatLon(uint64_t *)");
	}
	uint64_t j,i;
	for (j = m_jts; j != m_jte; ++j) {
		for (i = m_its; i != ROUND_TO_FOUR(m_ite, 4ULL); i += 4ULL) {
			_mm256_storeu_pd(&m_lat[j + m_jte*i], _mm256_set1_pd(0.0L));
			_mm256_storeu_pd(&m_long[j + m_jte*i], _mm256_set1_pd(0.0L));
		}
	}
	// Scalar reminder
	for (; j != m_jte; ++j) {
		for (; i != m_ite; ++i) {
			m_lat[j+m_jte*i] = 0.0L;
			m_long[j+m_jte*i] = 0.0L;
		}
	}
	m_isalloc = true;
}

lam::atmosphere::
LatLon::LatLon(_In_ const uint64_t idx[12],
			   _In_ const double* __restrict lat,
			   _In_ const double* __restrict lon)
:
m_ims{ idx[0] },  m_ime{ idx[1] },
m_jms{ idx[2] },  m_jme{ idx[3] },
m_ids{ idx[4] },  m_ide{ idx[5] },
m_jds{ idx[6] },  m_jde{ idx[7] },
m_its{ idx[8] },  m_ite{ idx[9] },
m_jts{ idx[10] }, m_jte{ idx[11] },
m_lat(reinterpret_cast<double*>(_mm_malloc((m_ime*m_jme)*sizeof(double),align32B))),
m_long(reinterpret_cast<double*>(_mm_malloc((m_ime*m_jme)*sizeof(double), align32B))){
	if (NULL == m_long || NULL == m_lat) {
#if LAM_VERBOSE_ON == 1
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
														Memory allocation failure in: LatLon::LatLon(uint64_t *,double*,double*)\n";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
#endif
		throw std::runtime_error("Memory allocation failure in: LatLon::LatLon(uint64_t *,double*,double*)");
	}
	uint64_t j,i;
	for (j = m_jts; j != m_jte; ++j) {
#pragma prefetch lat:0:4
#pragma prefetch lon:0:4
		for (i = m_its; i != ROUND_TO_FOUR(m_ite, 4ULL); i += 4ULL) {
			_mm256_storeu_pd(&m_lat[j + m_jte*i],  _mm256_loadu_pd(&lat[j+m_jte*i]));
			_mm256_storeu_pd(&m_long[j + m_jte*i], _mm256_loadu_pd(&lon[j+m_jte*i]));
		}
	}
	// Scalar reminder
	for (; j != m_jte; ++j) {
		for (; i != m_ite; ++i) {
			m_lat[j + m_jte*i]  = lat[j+m_jte*i];
			m_long[j + m_jte*i] = lon[j+m_jte*i];
		}
	}
	m_isalloc = true;
}

lam::atmosphere::
LatLon::LatLon(_In_ const LatLon &x)
:
m_ims{ x.m_ims }, m_ime{ x.m_ime },
m_jms{ x.m_jms }, m_jme{ x.m_jme },
m_ids{ x.m_ids }, m_ide{ x.m_ide },
m_jds{ x.m_jds }, m_jde{ x.m_jde },
m_its{ x.m_its }, m_ite{ x.m_ite },
m_jts{ x.m_jte }, m_jte{x.m_jte},
m_lat(reinterpret_cast<double*>(_mm_malloc((m_ime*m_jme)*sizeof(double),align32B))),
m_long(reinterpret_cast<double*>(_mm_malloc((m_ime*m_jme)*sizeof(double), align32B))) {
	if (NULL == m_long || NULL == m_lat) {
#if LAM_VERBOSE_ON == 1
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
											Memory allocation failure in: LatLon::LatLon(const LatLon &)\n";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
#endif
		throw std::runtime_error("Memory allocation failure in: LatLon::LatLon(const LatLon &)");
	}
	uint64_t j,i;
	for (j = m_jts; j != m_jte; ++j) {
#pragma prefetch x.m_lat:0:2
#pragma prefetch x.m_long:0:2
		for (i = m_its; i != ROUND_TO_FOUR(m_ite, 4ULL); i += 4ULL) {
			_mm256_storeu_pd(&m_lat[j + m_jte*i],  _mm256_loadu_pd(&x.m_lat[j+m_jte*i]));
			_mm256_storeu_pd(&m_long[j + m_jte*i], _mm256_loadu_pd(&x.m_long[j+m_jte*i]));
		}
	}
	// Scalar reminder
	for (; j != m_jte; ++j) {
		for (; i != m_ite; ++i) {
			m_lat[j + m_jte*i]  = x.m_lat[j+m_jte*i];
			m_long[j + m_jte*i] = x.m_long[j+m_jte*i];
		}
	}
	m_isalloc = true;
}

lam::atmosphere::
LatLon::LatLon(_In_ LatLon &&x)
:
m_ims{ x.m_ims }, m_ime{ x.m_ime },
m_jms{ x.m_jms }, m_jme{ x.m_jme },
m_ids{ x.m_ids }, m_ide{ x.m_ide },
m_jds{ x.m_jds }, m_jde{ x.m_jde },
m_its{ x.m_its }, m_ite{ x.m_ite },
m_jts{ x.m_jte }, m_jte{ x.m_jte },
m_lat(NULL),
m_long(NULL) {
	m_lat  = &x.m_lat[0];
	m_long = &x.m_long[0];
	m_isalloc = true;
	x.m_ims = 0ULL,x.m_ime = 0ULL,
	x.m_jms = 0ULL,x.m_jme = 0ULL,
	x.m_ids = 0ULL,x.m_ide = 0ULL,
	x.m_jds = 0ULL,x.m_jde = 0ULL,
	x.m_its = 0ULL,x.m_ite = 0ULL,
	x.m_jts = 0ULL,x.m_jte = 0ULL;
	x.m_lat = NULL;
	x.m_long = NULL;
	x.m_isalloc = false;
}

lam::atmosphere::
LatLon::~LatLon() {
	if (NULL != m_lat) {
		_mm_free(m_lat);
		m_lat = NULL;
	}
	if (NULL != m_long) {
		_mm_free(m_long);
		m_long = NULL;
		m_isalloc = false;
	}
}

lam::atmosphere::LatLon &
lam::atmosphere::LatLon::operator=(_In_ const LatLon &x) {
	if (this == &x)
		return (*this);
	m_ims = x.m_ims,m_ime = x.m_ime,
	m_jms = x.m_jms,m_jme = x.m_jme,
	m_ids = x.m_ids,m_ide = x.m_ide,
	m_jds = x.m_jds,m_jde = x.m_jde,
	m_its = x.m_its,m_ite = x.m_ite,
	m_jts = x.m_jts,m_jte = x.m_jte;
	_mm_free(m_lat);
	_mm_free(m_long);
	uint64_t j,i;
	for (j = m_jts; j != m_jte; ++j) {
#pragma prefetch x.m_lat:0:2
#pragma prefetch x.m_long:0:2
		for (i = m_its; i != ROUND_TO_FOUR(m_ite, 4ULL); i += 4ULL) {
			_mm256_storeu_pd(&m_lat[j + m_jte*i],  _mm256_loadu_pd(&x.m_lat[j+m_jte*i]));
			_mm256_storeu_pd(&m_long[j + m_jte*i], _mm256_loadu_pd(&x.m_long[j+m_jte*i]));
		}
	}
	// Scalar remainder
	for (; j != m_jte; ++j) {
		for (; i != m_ite; ++i) {
			m_lat[j + m_jte*i]  = x.m_lat[j+m_jte*i];
			m_long[j + m_jte*i] = x.m_long[j+m_jte*i];
		}
	}
	m_isalloc = x.m_isalloc;
	return (*this);
}

lam::atmosphere::LatLon &
lam::atmosphere::LatLon::operator=(_In_ LatLon &&x) {
	if (this == &x)
		return (*this);
	_mm_free(m_lat);
	_mm_free(m_long);
	m_ims = x.m_ims, m_ime = x.m_ime,
	m_jms = x.m_jms, m_jme = x.m_jme,
	m_ids = x.m_ids, m_ide = x.m_ide,
	m_jds = x.m_jds, m_jde = x.m_jde,
	m_its = x.m_its, m_ite = x.m_ite,
	m_jts = x.m_jts, m_jte = x.m_jte;
	m_lat = &x.m_lat[0];
	m_long = &x.m_long[0];
	m_isalloc = x.m_isalloc;
	x.m_ims = 0ULL, x.m_ime = 0ULL,
	x.m_jms = 0ULL, x.m_jme = 0ULL,
	x.m_ids = 0ULL, x.m_ide = 0ULL,
	x.m_jds = 0ULL, x.m_jde = 0ULL,
	x.m_its = 0ULL, x.m_ite = 0ULL,
	x.m_jts = 0ULL, x.m_jte = 0ULL;
	x.m_lat = NULL;
	x.m_long = NULL;
	x.m_isalloc = false;
	return (*this);
}

std::pair<double*,double*>
lam::atmosphere::LatLon::operator==(_In_ const LatLon &x) {
#if LAM_DEBUG_ON == 1
	_ASSERTE(x.m_isalloc      &&
			 m_ime == x.m_ime &&
			 m_jme == x.m_jme);
#else
	if (!x.m_isalloc ||
		m_ime != x.m_ime ||
		m_jme != x.m_jme) {
		throw std::runtime_error("LatLon::operator==,  [loc:231] -- Invalid arguments or size mismatch!!")
	}
#endif
	double* __restrict bres1 = 
	reinterpret_cast<double*>(_mm_malloc((m_ime*m_jme)*sizeof(double),align32B));
	double* __restrict bres2 = 
	reinterpret_cast<double*>(_mm_malloc((m_ime*m_jme)*sizeof(double),align32B));
	if (NULL == bres2 || NULL == bres1) {
#if LAM_VERBOSE_ON == 1
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
														Memory allocation failure in: LatLon::operator==(const LatLon &)\n";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
#endif
		throw std::runtime_error("Memory allocation failure in: LatLon::operator==(const LatLon &)");
	}
	std::pair<double*,double*> retp;
	uint64_t j,i;
	const double eps = std::numeric_limits<double>::epsilon();
	for (j = m_jts; j != m_jte; ++j) {
		for (i = m_its; i != ROUND_TO_FOUR(m_ite, 4ULL); i += 4ULL) {
			_mm256_storeu_pd(&bres1[j + m_jte*i], 
			     _mm256_cmp_pd(_mm256_loadu_pd(&m_lat[j+m_jte*i]),
				      _mm256_loadu_pd(&x.m_lat[j+m_jte*i]),_CMP_EQ_OQ));
			_mm256_storeu_pd(&bres2[j + m_jte*i], 
			    _mm256_cmp_pd(_mm256_loadu_pd(&m_long[j+m_jte*i]),
				      _mm256_loadu_pd(&x.m_long[j+m_jte*i]),_CMP_EQ_OQ));
		}
	}
	// Scalar remainder
	for (; j != m_jte; ++j) {
		for (; i != m_ite; ++i) {
			if ((std::fabs(m_lat[j + m_jte*i] - x.m_lat[j + m_jte*i])) <= eps) {
				bres1[j+m_jte*i] = 1.0L;
			}
			else{
				bres1[j+m_jte*i] = 0.0L;
			}
			if ((std::fabs(m_long[j + m_jte*i] - x.m_long[j + m_jte*i])) <= eps) {
				bres2[j+m_jte*i] = 1.0L;
			}
			else{
				bres2[j+m_jte*i] = 0.0L;
			}
			    
		}
	}
	retp = std::make_pair(bres1, bres2);
	return (retp);
}

std::pair<double*,double*>
lam::atmosphere::LatLon::operator!=(_In_ const LatLon &x) {
#if LAM_DEBUG_ON == 1
	_ASSERTE(x.m_isalloc      &&
		     m_ime == x.m_ime &&
		     m_jme == x.m_jme);
#else
	if (!x.m_isalloc ||
		m_ime != x.m_ime ||
		m_jme != x.m_jme) {
		throw std::runtime_error("LatLon::operator!=,  [loc:291] -- Invalid arguments or size mismatch!!")
	}
#endif
	double* __restrict bres1 =
		reinterpret_cast<double*>(_mm_malloc((m_ime*m_jme)*sizeof(double), align32B));
	double* __restrict bres2 =
		reinterpret_cast<double*>(_mm_malloc((m_ime*m_jme)*sizeof(double), align32B));
	if (NULL == bres2 || NULL == bres1) {
#if LAM_VERBOSE_ON == 1
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
													Memory allocation failure in: LatLon::operator!=(const LatLon &)\n";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
#endif
		throw std::runtime_error("Memory allocation failure in: LatLon::operator!=(const LatLon &)");
	}
	std::pair<double*, double*> retp;
	uint64_t j, i;
	const double eps = std::numeric_limits<double>::epsilon();
	for (j = m_jts; j != m_jte; ++j) {
		for (i = m_its; i != ROUND_TO_FOUR(m_ite, 4ULL); i += 4ULL) {
			_mm256_storeu_pd(&bres1[j + m_jte*i],
				_mm256_cmp_pd(_mm256_loadu_pd(&m_lat[j + m_jte*i]),
				        _mm256_loadu_pd(&x.m_lat[j + m_jte*i]), _CMP_NEQ_OQ));
			_mm256_storeu_pd(&bres2[j + m_jte*i],
				_mm256_cmp_pd(_mm256_loadu_pd(&m_long[j + m_jte*i]),
				       _mm256_loadu_pd(&x.m_long[j + m_jte*i]), _CMP_NEQ_OQ));
		}         
	}
	// Scalar remainder
	for (; j != m_jte; ++j) {
		for (; i != m_ite; ++i) {
			if ((std::fabs(m_lat[j + m_jte*i] - x.m_lat[j + m_jte*i])) > eps) {
				bres1[j + m_jte*i] = 1.0L;
			}
			else{
				bres1[j + m_jte*i] = 0.0L;
			}
			if ((std::fabs(m_long[j + m_jte*i] - x.m_long[j + m_jte*i])) > eps) {
				bres2[j + m_jte*i] = 1.0L;
			}
			else{
				bres2[j + m_jte*i] = 0.0L;
			}

		}
	}
	retp = std::make_pair(bres1, bres2);
	return (retp);
}

std::pair<double*,double*>
lam::atmosphere::LatLon::operator>(_In_ const LatLon &x) {
#if LAM_DEBUG_ON == 1
	_ASSERTE(x.m_isalloc      &&
		m_ime == x.m_ime &&
		m_jme == x.m_jme);
#else
	if (!x.m_isalloc ||
		m_ime != x.m_ime ||
		m_jme != x.m_jme) {
		throw std::runtime_error("LatLon::operator>,  [loc:351] -- Invalid arguments or size mismatch!!")
	}
#endif
	double* __restrict bres1 =
		reinterpret_cast<double*>(_mm_malloc((m_ime*m_jme)*sizeof(double), align32B));
	double* __restrict bres2 =
		reinterpret_cast<double*>(_mm_malloc((m_ime*m_jme)*sizeof(double), align32B));
	if (NULL == bres2 || NULL == bres1) {
#if LAM_VERBOSE_ON == 1
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
													Memory allocation failure in: LatLon::operator>(const LatLon &)\n";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
#endif
		throw std::runtime_error("Memory allocation failure in: LatLon::operator>(const LatLon &)");
	}
	std::pair<double*, double*> retp;
	uint64_t j, i;
	const double eps = std::numeric_limits<double>::epsilon();
	for (j = m_jts; j != m_jte; ++j) {
		for (i = m_its; i != ROUND_TO_FOUR(m_ite, 4ULL); i += 4ULL) {
			_mm256_storeu_pd(&bres1[j + m_jte*i],
				_mm256_cmp_pd(_mm256_loadu_pd(&m_lat[j + m_jte*i]),
				   _mm256_loadu_pd(&x.m_lat[j + m_jte*i]), _CMP_GT_OQ));
			_mm256_storeu_pd(&bres2[j + m_jte*i],
				_mm256_cmp_pd(_mm256_loadu_pd(&m_long[j + m_jte*i]),
				   _mm256_loadu_pd(&x.m_long[j + m_jte*i]), _CMP_GT_OQ));
		}
	}
	// Scalar remainder
	for (; j != m_jte; ++j) {
		for (; i != m_ite; ++i) {
			if (m_lat[j + m_jte*i] > x.m_lat[j + m_jte*i]) // Dependency on Compiler
				bres1[j+m_jte+i] = 1.0L;
			else
				bres1[j+m_jte*i]  = 0.0L;

			if (m_long[j + m_jte*i] > x.m_long[j+m_jte*i]) // Dependency on Compiler
				bres2[j+m_jte*i] = 1.0L;
		    else
				bres2[j+m_jte*i] = 0.0L;
		}
	}
	retp = std::make_pair(bres1,bres2);
	return (retp);
}

std::pair<double*,double*>
lam::atmosphere::LatLon::operator<(_In_ const LatLon &x) {
#if LAM_DEBUG_ON == 1
	_ASSERTE(x.m_isalloc      &&
			 m_ime == x.m_ime &&
		     m_jme == x.m_jme);
#else
	if (!x.m_isalloc     ||
		m_ime != x.m_ime ||
		m_jme != x.m_jme) {
		throw std::runtime_error("LatLon::operator<,  [loc:351] -- Invalid arguments or size mismatch!!")
	}
#endif
	double* __restrict bres1 =
		reinterpret_cast<double*>(_mm_malloc((m_ime*m_jme)*sizeof(double), align32B));
	double* __restrict bres2 =
		reinterpret_cast<double*>(_mm_malloc((m_ime*m_jme)*sizeof(double), align32B));
	if (NULL == bres2 || NULL == bres1) {
#if LAM_VERBOSE_ON == 1
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
															Memory allocation failure in: LatLon::operator<(const LatLon &)\n";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
#endif
		throw std::runtime_error("Memory allocation failure in: LatLon::operator<(const LatLon &)");
	}
	std::pair<double*, double*> retp;
	uint64_t j, i;
	const double eps = std::numeric_limits<double>::epsilon();
	for (j = m_jts; j != m_jte; ++j) {
		for (i = m_its; i != ROUND_TO_FOUR(m_ite, 4ULL); i += 4ULL) {
			_mm256_storeu_pd(&bres1[j + m_jte*i],
				_mm256_cmp_pd(_mm256_loadu_pd(&m_lat[j + m_jte*i]),
				  _mm256_loadu_pd(&x.m_lat[j + m_jte*i]), _CMP_LT_OQ));
			_mm256_storeu_pd(&bres2[j + m_jte*i],
				_mm256_cmp_pd(_mm256_loadu_pd(&m_long[j + m_jte*i]),
				   _mm256_loadu_pd(&x.m_long[j + m_jte*i]), _CMP_LT_OQ));
		}
	}
	// Scalar remainder
	for (; j != m_jte; ++j) {
		for (; i != m_ite; ++i) {
			if (m_lat[j + m_jte*i] < x.m_lat[j + m_jte*i]) // Dependency on Compiler
				bres1[j + m_jte + i] = 1.0L;
			else
				bres1[j + m_jte*i] = 0.0L;

			if (m_long[j + m_jte*i] < x.m_long[j + m_jte*i]) // Dependency on Compiler
				bres2[j + m_jte*i] = 1.0L;
			else
				bres2[j + m_jte*i] = 0.0L;
		}
	}
	retp = std::make_pair(bres1, bres2);
	return (retp);
}

std::ostream &
lam::atmosphere::operator<<(_In_ std::ostream &os,
							_In_ const LatLon &x) {
	for (uint64_t j = x.m_jts; j != x.m_jte; ++j) {
		for (uint64_t i = x.m_its; i != x.m_ite; ++i) {
			os << std::fixed << std::setprecision(15) << std::showpoint <<
				std::setw(4)  << "Latitude   (deg): " << x.m_lat[j+x.m_jte*i] << 
				std::setw(12) << "Longtitude (deg): " << x.m_long[j + x.m_jte*i] << "\n";
		}
		os << "\n";
	}
	return (os);
}



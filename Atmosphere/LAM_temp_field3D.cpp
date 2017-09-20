
#include <iostream>

#include "LAM_temp_field3D.h"
#include "../LAM_config.h"
#include "../LAM_simd_defs.h"
#include <iomanip>

lam::atmosphere::TempField3D::
                 TempField3D(_In_ const uint64_t indices[18])
:
m_ims{ indices[0] },
m_ime{ indices[1] },
m_kms{ indices[2] },
m_kme{ indices[3] },
m_jms{ indices[4] },
m_jme{ indices[5] },
m_ids{ indices[6] },
m_ide{ indices[7] },
m_kds{ indices[8] },
m_kde{ indices[9] },
m_jds{ indices[10] },
m_jde{ indices[11] },
m_its{ indices[12] },
m_ite{ indices[13] },
m_kts{ indices[14] },
m_kte{ indices[15] },
m_jts{ indices[16] },
m_jte{ indices[17] },
m_t3d(reinterpret_cast<double*>(_mm_malloc((m_ime*m_kme*m_jme)*sizeof(double), align32B))){
	if (NULL == m_t3d) {
#if LAM_VERBOSE_ON == 1
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
												Memory allocation failure in: TempField3D::TempField3D(uint64_t *)\n";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
#endif
		throw std::runtime_error("TempField3D::TempField3D(uint64_t*)-> [loc:30]: Memory allocation failure!!");
		}
		uint64_t i,j,k;
		for (j = m_jts; j != m_jte; ++j) {
			for (k = m_kts; k != m_kte; ++k) {
				for (i = m_its; i != ROUND_TO_FOUR(m_ite, 4ULL); i += 4ULL){
					_mm256_storeu_pd(&m_t3d[j + m_jte*k + m_kte*i], _mm256_set1_pd(0.0L));
				}
			}
		}
	   // Scalar remainder
		for (; j != m_jte; ++j) {
			for (; k != m_kte; ++k) {
				for (; i != m_ite; ++i) {
					m_t3d[j+m_jte*k+m_kte*i] = 0.0L;
				}
			}
		}
		this->m_isalloc = true;
}

lam::atmosphere::TempField3D::
TempField3D(_In_ const uint64_t indices[18],
			_In_ const double* __restrict t3d)
:
m_ims{ indices[0] },
m_ime{ indices[1] },
m_kms{ indices[2] },
m_kme{ indices[3] },
m_jms{ indices[4] },
m_jme{ indices[5] },
m_ids{ indices[6] },
m_ide{ indices[7] },
m_kds{ indices[8] },
m_kde{ indices[9] },
m_jds{ indices[10] },
m_jde{ indices[11] },
m_its{ indices[12] },
m_ite{ indices[13] },
m_kts{ indices[14] },
m_kte{ indices[15] },
m_jts{ indices[16] },
m_jte{ indices[17] },
m_t3d(reinterpret_cast<double*>(_mm_malloc((m_ime*m_kme*m_jme)*sizeof(double), align32B))) {
	if (NULL == m_t3d || NULL == t3d) {
#if LAM_VERBOSE_ON == 1
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
												Memory allocation failure in: TempField3D::TempField3D(uint64_t *, const double*)\n";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
#endif
		throw std::runtime_error("Memory allocation failure in: TempField3D::TempField3D(uint64_t *, const double*)");
	}
	uint64_t j,k,i;

	for (j = m_jts; j != m_jte; ++j) {
		for (k = m_kts; k != m_kte; ++k) {
#pragma prefetch t3d:0:2
			for (i = m_its; i != ROUND_TO_FOUR(m_ite, 4ULL); i += 4ULL) {
				_mm256_storeu_pd(&m_t3d[j + m_jte*k + m_kte*i], 
				                       _mm256_loadu_pd(&t3d[j+m_jte*k+m_kte*i]));
			}
		}
	}
	// Scalar reminder
	for (; j != m_jte; ++j) {
		for (; k != m_kte; ++k) {
#pragma prefetch t3d:0:2
			for (; i != m_ite; ++i) {
				m_t3d[j + m_jte*k + m_kte*i] = t3d[j+m_jte*k+m_kte*i];
			}
		}
	}
	m_isalloc = true;
}

lam::atmosphere::TempField3D::
				 TempField3D(_In_ const TempField3D &x)
:
m_ims{ x.m_ims },
m_ime{ x.m_ime },
m_kms{ x.m_kms },
m_kme{ x.m_kme },
m_jms{ x.m_jms },
m_jme{ x.m_jme },
m_ids{ x.m_ids },
m_ide{ x.m_ide },
m_kds{ x.m_kds },
m_kde{ x.m_kde },
m_jds{ x.m_jds },
m_jde{ x.m_jde },
m_its{ x.m_its },
m_ite{ x.m_ite },
m_kts{ x.m_kts },
m_kte{ x.m_kte},
m_jts{ x.m_jts },
m_jte{ x.m_jte},
m_t3d(reinterpret_cast<double*>(_mm_malloc((m_ime*m_kme*m_jme)*sizeof(double), align32B))) {
	if (NULL == m_t3d){
#if LAM_VERBOSE_ON == 1
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
									Memory allocation failure in: TempField3D::TempField3D(TempField3D &)\n";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
#endif
		throw std::runtime_error("Memory allocation failure in: TempField3D::TempField3D(TempField3D &)");
	}
	uint64_t j,k,i;
	for (j = m_jts; j != m_jte; ++j) {
		for (k = m_kts; k != m_kte; ++k) {
#pragma prefetch:0:2
			for (i = m_its; i != ROUND_TO_FOUR(m_ite,4ULL); ++i) {
				_mm256_storeu_pd(&m_t3d[j + m_jte*k + m_kte*i], 
				                       _mm256_loadu_pd(&x.m_t3d[j+m_jte*k+m_kte*i]));
			}
		}
	}
	// Scalar reminder.
	for (; j != m_jte; ++j) {
		for (; k != m_kte; ++k) {
			for (; i != m_ite; ++i) {
				m_t3d[j + m_jte*k + m_kte*i] = x.m_t3d[j+m_jte*k+m_kte*i];
			}
		}
	}
	m_isalloc = true;
}

lam::atmosphere::TempField3D::
				 TempField3D(_In_ TempField3D &&x)
:
m_ims{ x.m_ims },
m_ime{ x.m_ime },
m_kms{ x.m_kms },
m_kme{ x.m_kme },
m_jms{ x.m_jms },
m_jme{ x.m_jme },
m_ids{ x.m_ids },
m_ide{ x.m_ide },
m_kds{ x.m_kds },
m_kde{ x.m_kde },
m_jds{ x.m_jds },
m_jde{ x.m_jde },
m_its{ x.m_its },
m_ite{ x.m_ite },
m_kts{ x.m_kts },
m_kte{ x.m_kte },
m_jts{ x.m_jts },
m_jte{ x.m_jte },
m_t3d(NULL) {
	m_t3d = x.m_t3d;
	m_isalloc = true;
	x.m_ims = 0ULL;
	x.m_ime = 0ULL;
	x.m_kms = 0ULL;
	x.m_kme = 0ULL;
	x.m_jms = 0ULL;
	x.m_jme = 0ULL;
	x.m_ids = 0ULL;
	x.m_ide = 0ULL;
	x.m_kds = 0ULL;
	x.m_kde = 0ULL;
	x.m_jds = 0ULL;
	x.m_jde = 0ULL;
	x.m_its = 0ULL;
	x.m_ite = 0ULL;
	x.m_kts = 0ULL;
	x.m_kte = 0ULL;
	x.m_jts = 0ULL;
	x.m_jte = 0ULL;
	x.m_t3d = NULL;
	x.m_isalloc = false;
}

lam::atmosphere::TempField3D::
				~TempField3D() {
	if (this->m_t3d != NULL) {
		_mm_free(this->m_t3d);
		this->m_t3d = NULL;
		this->m_isalloc = false;
	}
}

lam::atmosphere::TempField3D &
lam::atmosphere::TempField3D::operator=(_In_ const TempField3D &x) {
	if (this == &x) return (*this);

	m_ims = x.m_ims,m_ime = x.m_ime,
	m_jms = x.m_jms,m_jme = x.m_jme,
	m_ids = x.m_ids,m_ide = x.m_ide,
	m_jds = x.m_jds,m_jde = x.m_jde,
	m_its = x.m_its,m_ite = x.m_ite,
	m_jts = x.m_jts,m_jte = x.m_jte;
	_mm_free(this->m_t3d);
	uint64_t j,k,i;
	for (j = m_jts; j != m_jte; ++j) {
		for (k = m_kts; k != m_kte; ++k) {
#pragma prefetch x.m_t3d:0:2
#pragma prefetch x.m_t3d:1:16
			for (i = m_its; i != ROUND_TO_FOUR(m_ite, 4ULL); i += 4ULL) {
				_mm256_storeu_pd(&this->m_t3d[j+m_jte*k+m_kte*i], 
								             _mm256_loadu_pd(&x.m_t3d[j+m_jte*k+m_kte*i]));
			}
		}
	}
	//Scalar remainder
	for (; j != m_jte; ++j) {
		for (; k != m_kte; ++k) {
			for (; i != m_ite; ++i) {
				this->m_t3d[j + m_jte*k + m_kte*i] = x.m_t3d[j+m_jte*k+m_kte*i];
			}
		}
	}
	m_isalloc = x.m_isalloc;
	return (*this);
}

lam::atmosphere::TempField3D &
lam::atmosphere::TempField3D::operator=(_In_ TempField3D &&x) {
	if (this == &x) return (*this);

	_mm_free(this->m_t3d);
	m_ims = x.m_ims, m_ime = x.m_ime,
	m_jms = x.m_jms, m_jme = x.m_jme,
	m_ids = x.m_ids, m_ide = x.m_ide,
	m_jds = x.m_jds, m_jde = x.m_jde,
	m_its = x.m_its, m_ite = x.m_ite,
	m_jts = x.m_jts, m_jte = x.m_jte;
	this->m_t3d = &x.m_t3d[0];
	m_isalloc = true;
	x.m_ims=0ULL,x.m_ime=0ULL,
	x.m_jms=0ULL,x.m_jme=0ULL,
	x.m_ids=0ULL,x.m_ide=0ULL,
	x.m_jds=0ULL,x.m_jde=0ULL,
	x.m_its=0ULL,x.m_ite=0ULL,
	x.m_jts=0ULL,x.m_jte=0ULL;
	x.m_t3d = NULL;
	x.m_isalloc = false;
	return (*this);
}

lam::atmosphere::TempField3D &
lam::atmosphere::TempField3D::operator+=(_In_ const TempField3D &x) {
#if LAM_DEBUG_ON == 1
	_ASSERTE(x.m_isalloc         && 
			 m_ime == x.m_ime	 &&
			 m_kme == x.m_kme	 &&
			 m_jme == x.m_jme);
#else
	if (!x.m_isalloc     ||
		m_ime != x.m_ime ||
		m_kme != x.m_kme ||
		m_jme != x.m_jme) {
		throw std::invalid_argument("TempField3D::operator+=, [loc:277] -- Invalid arguments or size mismatch!!");
	}
#endif
	uint64_t j,k,i;
	for (j = m_jts; j != m_jte; ++j) {
		for (k = m_kts; k != m_kte; ++k) {
#pragma prefetch x.m_t3d:0:2
#pragma prefetch x.m_t3d:0:16
			for (i = m_its; i != ROUND_TO_FOUR(m_ite,4ULL); i += 4ULL) {
				_mm256_storeu_pd(&m_t3d[j + m_jte*k + m_kte*i], 
				      _mm256_add_pd(_mm256_loadu_pd(&m_t3d[j+m_jte*k+m_kte*i]),
				                          _mm256_loadu_pd(&x.m_t3d[j+m_jte*k+m_kte*i])));
			}
		}
	}
	// Scalar remiander
	for (; j != m_jte; ++j) {
		for (; k != m_kte; ++k) {
			for (; i != m_ite; ++i) {
				m_t3d[j + m_jte*k + m_kte*i] += x.m_t3d[j+m_jte*k+m_kte*i];
			}
		}
	}
	return (*this);
}

lam::atmosphere::TempField3D &
lam::atmosphere::TempField3D::operator-=(_In_ const TempField3D &x) {
#if LAM_DEBUG_ON == 1
	_ASSERTE(x.m_isalloc         &&
			m_ime == x.m_ime	 &&
			m_kme == x.m_kme	 &&
			m_jme == x.m_jme);
#else
	if (!x.m_isalloc     ||
		m_ime != x.m_ime ||
		m_kme != x.m_kme ||
		m_jme != x.m_jme) {
		throw std::invalid_argument("TempField3D::operator-=, [loc:308] -- Invalid arguments or size mismatch!!");
	}
#endif
	uint64_t j,k,i;
	for (j = m_jts; j != m_jte; ++j) {
		for (k = m_kts; k != m_kte; ++k) {
#pragma prefetch x.m_t3d:0:2
#pragma prefetch x.m_t3d:0:16
			for (i = m_its; i != ROUND_TO_FOUR(m_ite, 4ULL); i += 4ULL) {
				_mm256_storeu_pd(&m_t3d[j + m_jte*k + m_kte*i], 
				        _mm256_sub_pd(_mm256_loadu_pd(&m_t3d[j+m_jte*k+m_kte*i]),
					                      _mm256_loadu_pd(&x.m_t3d[j+m_jte*k+m_kte*i])));
			}
		}
	}
	// Scalar remainder
	for (; j != m_jte; ++j) {
		for (; k != m_kte; ++k) {
			for (; i != m_ite; ++i) {
				m_t3d[j + m_jte*k + m_kte*i] -= x.m_t3d[j+m_jte*k+m_kte*i];
			}
		}
	}
	return (*this);
}

lam::atmosphere::TempField3D &
lam::atmosphere::TempField3D::operator*=(_In_ const TempField3D &x) {
#if LAM_DEBUG_ON == 1
	_ASSERTE(x.m_isalloc         &&
			m_ime == x.m_ime	 &&
			m_kme == x.m_kme	 &&
			m_jme == x.m_jme);
#else
	if (!x.m_isalloc     ||
		m_ime != x.m_ime ||
		m_kme != x.m_kme ||
		m_jme != x.m_jme) {
		throw std::invalid_argument("TempField3D::operator*=,  [loc:337] -- Invalid arguments or size mismatch!!");
	}
#endif
	uint64_t j,k,i;
	for (j = m_jts; j != m_jte; ++j) {
		for (k = m_kts; k != m_kte; ++k) {
#pragma prefetch x.m_t3d:0:2
#pragma prefetch x.m_t3d:0:16
			for (i = m_its; i != ROUND_TO_FOUR(m_ite, 4ULL); i += 4ULL) {
				_mm256_storeu_pd(&m_t3d[j + m_jte*k + m_kte*i], 
				        _mm256_mul_pd(_mm256_loadu_pd(&m_t3d[j+m_jte*k+m_kte*i]),
					                    _mm256_loadu_pd(&x.m_t3d[j+m_jte*k+m_kte*i])));
			}
		}
	}
	// Scalar remainder
	for (; j != m_jte; ++j) {
		for (; k != m_kte; ++k) {
			for (; i != m_ite; ++i) {
				m_t3d[j + m_jte*k + m_kte*i] *= x.m_t3d[j+m_jte*k+m_kte*i];
			}
		}
	}
	return (*this);
}

lam::atmosphere::TempField3D &
lam::atmosphere::TempField3D::operator*=(_In_ const double s) {
	uint64_t j,k,i;
	for (j = m_jms; j != m_jme; ++j) {
		for (k = m_kms; k != m_kme; ++k) {
#pragma prefetch x.m_t3d:0:2
#pragma prefetch x.m_t3d:0:16
			for (i = m_ims; i != ROUND_TO_FOUR(m_ite, 4ULL); i += 4ULL) {
				_mm256_storeu_pd(&m_t3d[j + m_jte*k + m_kte*i], 
				     _mm256_mul_pd(_mm256_loadu_pd(&m_t3d[j+m_jte*k+m_kte*i]),
					       _mm256_set1_pd(s)));
			}
		}
	}
	// Scalar remainder
	for (; j != m_jte; ++j) {
		for (; k != m_kte; ++k) {
			for (; i != m_ite; ++i) {
				m_t3d[j+m_jte*k+m_kte*i] *= s;
			}
		}
	}
	return (*this);
}

#include "../LAM_common.h"

lam::atmosphere::TempField3D &
lam::atmosphere::TempField3D::operator/=(_In_ const TempField3D &x) {
	using namespace lam::common;
#if LAM_DEBUG_ON == 1
	_ASSERTE(x.m_isalloc         &&
			m_ime == x.m_ime	 &&
			m_kme == x.m_kme	 &&
			m_jme == x.m_jme);
#else
	if (!x.m_isalloc ||
		m_ime != x.m_ime ||
		m_kme != x.m_kme ||
		m_jme != x.m_jme) {
		throw std::invalid_argument("TempField3D::operator/=,  [loc:398] -- Invalid arguments or size mismatch!!");
	}
#endif
	if (vzero_check3D(x.m_t3d, x.m_its, x.m_ite, x.m_kts,
		                       x.m_kte, x.m_jts, x.m_jte)){
		throw std::domain_error("TempField3D::operator/= [loc:405] --> Found '0.0' ");
	}
	uint64_t j,k,i;
	for (j = m_jts; j != m_jte; ++j) {
		for (k = m_kts; k != m_kte; ++k) {
#pragma prefetch x.m_t3d:0:2
#pragma prefetch x.m_t3d:0:16
			for (i = m_its; i != ROUND_TO_FOUR(m_ite, 4ULL); i += 4ULL) {
				_mm256_storeu_pd(&m_t3d[j + m_jte*k + m_kte*i], 
				     _mm256_div_pd(_mm256_loadu_pd(&m_t3d[j+m_jte*k+m_kte*i]),
					                _mm256_loadu_pd(&x.m_t3d[j+m_jte*k+m_kte*i])));
			}
		}
	}
	// Scalar remainder
	for (; j != m_jte; ++j) {
		for (; k != m_kte; ++k) {
			for (; i != m_ite; ++i) {
				m_t3d[j + m_jte*k + m_kte*i] /= x.m_t3d[j+m_jte*k+m_kte*i];
			}
		}
	}
	return (*this);
}

lam::atmosphere::TempField3D &
lam::atmosphere::TempField3D::operator/=(_In_ const double s) {
#if LAM_DEBUG_ON == 1
	_ASSERTE( s != 0.0L);
#else
	if(s == 0.0L)
		throw std::domain_error("TempField3D::operator/= [loc:465] --> Found '0.0'");
#endif
	uint64_t j,k,i;
	for (j = m_jts; i != m_jte; ++j) {
		for (k = m_kts; k != m_kte; ++k) {
#pragma prefetch m_t3d:0:2
#pragma prefetch m_t3d:1:16
			for (i = m_its; i != ROUND_TO_FOUR(m_ite, 4ULL); i += 4ULL) {
				_mm256_storeu_pd(&m_t3d[j + m_jte*k + m_kte*i], 
						_mm256_div_pd(_mm256_loadu_pd(&m_t3d[j+m_jte*k+m_kte*i]),
																	_mm256_set1_pd(s)));
			}
		}
	}
	// Scalar remainder
	for (; j != m_jte; ++j) {
		for (; k != m_kte; ++k) {
			for (; i != m_ite; ++i) {
				m_t3d[j+m_jte*k+m_kte*i] /= s;
			}
		}
	}
	return (*this);
}

double *
lam::atmosphere::TempField3D::operator!=(_In_ const TempField3D &x) {
#if LAM_DEBUG_ON == 1
	_ASSERTE(x.m_isalloc         &&
		     m_ime == x.m_ime	 &&
		     m_kme == x.m_kme	 &&
		     m_jme == x.m_jme);
#else
	if (!x.m_isalloc ||
		m_ime != x.m_ime ||
		m_kme != x.m_kme ||
		m_jme != x.m_jme) {
		throw std::invalid_argument("TempField3D::operator!=,  [loc:499] -- Invalid arguments or size mismatch!!");
	}
#endif
	double * __restrict bres = 
	reinterpret_cast<double*>(_mm_malloc((m_ime*m_kme*m_jme)*sizeof(double),align32B));
	if (NULL == bres) {
#if LAM_VERBOSE_ON == 1
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
												TempField3D::operator== [loc:508] --> Memory allocation failure!!";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
#endif
		throw std::runtime_error("TempField3D::operator!= [loc:508] --> Memory allocation failure!!");
	}
	uint64_t j, k, i;
	const double eps = std::numeric_limits<double>::epsilon();
	for (j = m_jts; j != m_jte; ++j) {
		for (k = m_kts; k != m_kte; ++k) {
#pragma prefetch x.m_t3d:0:2
#pragma prefetch x.m_t3d:0:16
			for (i = m_its; i != ROUND_TO_FOUR(m_ite, 4ULL); i += 4ULL) {
				_mm256_storeu_pd(&bres[j + m_jte*k + m_kte*i],
					_mm256_cmp_pd(_mm256_loadu_pd(&m_t3d[j + m_jte*k + m_kte*i]),
					   _mm256_loadu_pd(&x.m_t3d[j + m_jte*k + m_kte*i]), _CMP_NEQ_OQ));
			}
		}
	}
	// Scalar remainder
	for (; j != m_jte; ++j) {
		for (; k != m_kte; ++k) {
			for (; i != m_ite; ++i) {
				if ((std::fabs(m_t3d[j + m_jte*k + m_kte*i] -
					x.m_t3d[j + m_jte*k + m_kte])) >= eps){
					bres[j + m_jte*k + m_kte*i] = 1.0L;
				}
				else
				{
					bres[j + m_jte*k + m_kte*i] = 0.0L;
				}
			}
		}
	}
	return (bres);
}

double * 
lam::atmosphere::TempField3D::operator==(_In_ const TempField3D &x) {
#if LAM_DEBUG_ON == 1
	_ASSERTE(x.m_isalloc         &&
			m_ime == x.m_ime	 &&
			m_kme == x.m_kme	 &&
			m_jme == x.m_jme);
#else
	if (!x.m_isalloc ||
		m_ime != x.m_ime ||
		m_kme != x.m_kme ||
		m_jme != x.m_jme) {
		throw std::invalid_argument("TempField3D::operator==,  [loc:549] -- Invalid arguments or size mismatch!!");
	}
#endif
	double* __restrict bres = 
	reinterpret_cast<double*>(_mm_malloc((m_ime*m_kme*m_jme)*sizeof(double),align32B));
	if (NULL == bres) {
#if LAM_VERBOSE_ON == 1
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
												TempField3D::operator== [loc:508] --> Memory allocation failure!!";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
#endif
		throw std::runtime_error("TempField3D::operator== [loc:564] --> Memory allocation failure!!");
	}
	uint64_t j,k,i;
	const double eps = std::numeric_limits<double>::epsilon();
	for (j = m_jts; j != m_jte; ++j) {
		for (k = m_kts; k != m_kte; ++k) {
#pragma prefetch x.m_t3d:0:2
#pragma prefetch x.m_t3d:0:16
			for (i = m_its; i != ROUND_TO_FOUR(m_ite, 4ULL); i += 4ULL) {
				_mm256_storeu_pd(&bres[j + m_jte*k + m_kte*i], 
					_mm256_cmp_pd(_mm256_loadu_pd(&m_t3d[j+m_jte*k+m_kte*i]),
						_mm256_loadu_pd(&x.m_t3d[j+m_jte*k+m_kte*i]),_CMP_EQ_OQ));
			}
		}
	}
	// Scalar remainder
	for (; j != m_jte; ++j) {
		for (; k != m_kte; ++k) {
			for (; i != m_ite; ++i) {
				if ((std::fabs(m_t3d[j + m_jte*k + m_kte*i] -
					x.m_t3d[j + m_jte*k + m_kte])) <= eps){
					bres[j+m_jte*k+m_kte*i] = 1.0L;
				}
				else
				{
					bres[j+m_jte*k+m_kte*i] = 0.0L;
				}
			}
		}
	}
	return (bres);
}

 double * 
lam::atmosphere::TempField3D::operator>(_In_ const TempField3D &x) {
#if LAM_DEBUG_ON == 1
	_ASSERTE(x.m_isalloc      &&
			 m_ime == x.m_ime &&
			 m_kme == x.m_kme &&
			 m_jme == x.m_jme);
#else
	if (!x.m_isalloc	 ||
		m_ime != x.m_ime ||
		m_kme != x.m_kme ||
		m_jme != x.m_jme) {
		throw std::invalid_argument("TempField3D::operator>,  [loc:604] -- Invalid arguments or size mismatch!!");
#endif
    double* __restrict bres = 
	reinterpret_cast<double*>(_mm_malloc((m_ime*m_kme*m_jme)*sizeof(double),align32B));
	if (NULL == bres) {
#if LAM_VERBOSE_ON == 1
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
													TempField3D::operator> [loc:620] --> Memory allocation failure!!";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
#endif	
		throw std::runtime_error("TempField3D::operator> [loc:620] --> Memory allocation failure!!");
	}
	uint64_t j,k,i;
	for (j = m_jms; j != m_jme; ++j) {
		for (k = m_kms; k != m_kme; ++k) {
#pragma prefetch x.m_t3d:0:2
#pragma prefetch x.m_t3d:0:16
			for (i = m_ims; i != ROUND_TO_FOUR(m_ite, 4ULL); i += 4ULL) {
				_mm256_storeu_pd(&bres[j + m_jte*k + m_kte*i], 
				   _mm256_cmp_pd(_mm256_loadu_pd(&m_t3d[j+m_jte*k+m_kte*i]),
					   _mm256_loadu_pd(&x.m_t3d[j+m_jte*k+m_kte*i]),_CMP_GT_OQ));
			}
		}
	}
	// Scalar remainder
	for (; j != m_jte; ++j) {
		for (; k != m_kte; ++k) {
			for (; i != m_ite; ++i) {
				if (m_t3d[j + m_jte*k + m_kte*i] > x.m_t3d[j + m_jte*k + m_kte*i]) {
					bres[j+m_jte*k+m_kte*i] = 1.0L; // Crude comparison
				}
				else {
					bres[j+m_jte*k+m_kte*i] = 0.0L;
				}
			}
		}
	}
	return (bres);
}

double * 
lam::atmosphere::TempField3D::operator<(_In_ const TempField3D &x) {
#if LAM_DEBUG_ON == 1
	_ASSERTE(x.m_isalloc      &&
		m_ime == x.m_ime &&
		m_kme == x.m_kme &&
		m_jme == x.m_jme);
#else
	if (!x.m_isalloc	 ||
		m_ime != x.m_ime ||
		m_kme != x.m_kme ||
		m_jme != x.m_jme) {
		throw std::invalid_argument("TempField3D::operator<,  [loc:662] -- Invalid arguments or size mismatch!!");
	}
#endif
	double* __restrict bres = 
	reinterpret_cast<double*>(_mm_malloc((m_ime*m_kme*m_jme)*sizeof(double),align32B));
	if (NULL == bres) {
#if LAM_VERBOSE_ON == 1
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
												TempField3D::operator< [loc:672] --> Memory allocation failure!!";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
#endif
		throw std::runtime_error("TempField3D::operator< [loc:672] --> Memory allocation failure!!");
	}
	uint64_t j, k, i;
	for (j = m_jms; j != m_jme; ++j) {
		for (k = m_kms; k != m_kme; ++k) {
#pragma prefetch x.m_t3d:0:2
#pragma prefetch x.m_t3d:0:16
			for (i = m_ims; i != ROUND_TO_FOUR(m_ite, 4ULL); i += 4ULL) {
				_mm256_storeu_pd(&bres[j + m_jte*k + m_kte*i],
					_mm256_cmp_pd(_mm256_loadu_pd(&m_t3d[j + m_jte*k + m_kte*i]),
					_mm256_loadu_pd(&x.m_t3d[j + m_jte*k + m_kte*i]), _CMP_LT_OQ));
			}
		}
	}
	// Scalar remainder
	for (; j != m_jte; ++j) {
		for (; k != m_kte; ++k) {
			for (; i != m_ite; ++i) {
				if (m_t3d[j + m_jte*k + m_kte*i] < x.m_t3d[j + m_jte*k + m_kte*i]) {
					bres[j + m_jte*k + m_kte*i] = 1.0L; // Crude comparison
				}
				else {
					bres[j + m_jte*k + m_kte*i] = 0.0L;
				}
			}
		}
	}
	return (bres);
}

std::ostream &
lam::atmosphere::operator<<(_In_ std::ostream &os, _In_ const TempField3D &x) {
	
	for (uint64_t j = x.m_jts; j != x.m_jte; ++j) {
		for (uint64_t k = x.m_kts; k != x.m_kte; ++k) {
			for (uint64_t i = x.m_its; i != x.m_ite; ++i) {
				os << std::fixed << std::showpoint << std::setprecision(15) <<
					std::setw(4) << "Temp field: " << x.m_t3d[j + x.m_jte*k + x.m_kte*i] << "\n";
			}
			os << "\n";
		}
		os << "\n";
	}
	return (os);
}

#include <math.h>

void 
lam::atmosphere::TempField3D::gradient(_In_ double* __restrict grad,
									   _In_ const uint64_t ime,
									   _In_ const uint64_t kme,
									   _In_ const uint64_t jme,
									   _Inout_ int& ierr)const  {
#if LAM_DEBUG_ON == 1
	_ASSERTE( NULL != grad &&
			 ime == m_ime &&
			 kme == m_kme &&
			 jme == m_jme);
#else
	if(ierr <= 0) ierr = 9999;
	if (NULL == grad ||
		ime != m_ime ||
		kme != m_kme ||
		jme != m_jme) {
		ierr = -1;
		return;
	}
#endif
	uint64_t j,k,i;	
	constexpr uint64_t sf = 1000000000000000ULL;
	constexpr double third = 0.333333333333333333333333L;
	double eps{}, tmp{}, isf{};
	isf = 1.0 / static_cast<double>(sf);
	eps = std::numeric_limits<double>::epsilon()*third;
	// Scalar version only
	for (j = m_jts + 1ULL; j != m_jte - 1ULL; ++j) {
		for (k = m_kts + 1ULL; k != m_kte - 1ULL; ++k) {
#pragma prefetch m_t3d:0:2
#pragma prefetch m_t3d:0:16
			for (i = m_its + 1ULL; i != m_ite - 1ULL; ++i) {
				tmp = m_t3d[(j+1ULL)+m_jte*(k+1ULL)+m_kte*(i+1ULL)] - 
					  m_t3d[j+m_jte*k+m_kte*i];
				grad[j + m_jte*k + m_kte*i] = tmp / 
				                             (2.0*eps*std::fmax(std::fabs(tmp), isf)*std::copysign(tmp,tmp));
			}
		}
	}
	ierr = 0ULL;
}

void 
lam::atmosphere::TempField3D::laplacian(_Inout_ double* __restrict laplac,
										_In_ const uint64_t ime,
										_In_ const uint64_t kme,
										_In_ const uint64_t jme,
										_Inout_ int& ierr) const {
#if LAM_DEBUG_ON == 1
	_ASSERTE(NULL != laplac &&
			 ime == m_ime,  &&
			 kme == m_kme   &&
			 jme == m_jme);
#else
	if (ierr <= 0) ierr = 9999;
	if (NULL == laplac ||
		ime != m_ime   ||
		kme != m_kme   ||
		jme != m_jme) {
		ierr = -1;
		return;
	}
#endif
	uint64_t j, k, i;
	constexpr uint64_t sf = 1000000000000000ULL; // Create static class with definitions of constants
	constexpr double third = 0.333333333333333333333333L;
	double eps{}, tmp{}, isf{};
	isf = 1.0 / static_cast<double>(sf);
	eps = std::numeric_limits<double>::epsilon()*third;
	// Scalar version only
	this->gradient(&laplac[0],ime,kme,jme,ierr);
	if (ierr < 0){
		ierr = -1;
		return;
	}
	// Compute laplacian in-place
	for (j = m_jts + 1ULL; j != m_jte - 1ULL; ++j) {
		for (k = m_kts + 1ULL; k != m_kte - 1ULL; ++k) {
			for (i = m_its + 1ULL; i != m_ite - 1ULL; ++i) {
				tmp = laplac[(j+1ULL)+m_jte*(k+1ULL)+m_kte*(i+1ULL)] - 
					  laplac[j+m_jte*k+m_kte*i];
				laplac[j + m_jte*k + m_kte*i] = tmp / 
				                                (2.0L*eps*std::fmax(std::fabs(tmp), isf)*std::copysign(tmp,tmp));
			}
		}
	}
	ierr = 0;
}

void
lam::atmosphere::TempField3D::laplacian(_In_ double* __restrict grad,
									    _Inout_ double* __restrict laplac,
									    _In_ const uint64_t ime,
										_In_ const uint64_t kme,
										_In_ const uint64_t jme,
										_Inout_ int& ierr) const {
#if LAM_DEBUG_ON == 1
	_ASSERTE(NULL != grad   &&
			 NULL != laplac &&
		     ime == m_ime,  &&
		     kme == m_kme   &&
		     jme == m_jme);
#else
	if (ierr <= 0) ierr = 9999;
	if (NULL == grad   ||
	    NULL == laplac ||
		ime != m_ime   ||
		kme != m_kme   ||
		jme != m_jme) {
		ierr = -1;
		return;
	}
#endif
	uint64_t j, k, i;
	constexpr uint64_t sf = 1000000000000000ULL; // Create static class with definitions of constants
	constexpr double third = 0.333333333333333333333333L;
	double eps{}, tmp{}, isf{};
	isf = 1.0 / static_cast<double>(sf);
	eps = std::numeric_limits<double>::epsilon()*third;
	// Scalar version only
	this->gradient(&grad[0],ime,kme,jme,ierr);
	if (ierr < 0) {
		ierr = -1;
		return;
	}
	for (j = m_jts + 1ULL; j != m_jte - 1ULL; ++j) {
		for (k = m_kts + 1ULL; k != m_kte - 1ULL; ++k) {
			for (i = m_its + 1ULL; i != m_ite - 1ULL; ++i) {
				tmp = grad[(j + 1ULL) + m_jte*(k + 1ULL) + m_kte*(i + 1ULL)] -
					  grad[j + m_jte*k + m_kte*i];
				laplac[j + m_jte*k + m_kte*i] = tmp /
					(2.0L*eps*std::fmax(std::fabs(tmp), isf)*std::copysign(tmp, tmp));
			}
		}
	}
	ierr = 0;
}





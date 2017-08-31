
#include "LAM_avxcomplex.h"
//
//	Implementation
//

lam::math::AVXVComplex1D::
           AVXVComplex1D(_In_ const uint64_t nsize)
:
m_nsize{nsize},
m_Re(reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double),align32B))),
m_Im(reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double),align32B)))
{
	if (this->m_Re == NULL ||
		this->m_Im == NULL ||
		(this->m_nsize%4ULL) != 0ULL) {
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
		Memory allocation failure in: AVXVComplex1D(int64_t)\n";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
		std::exit(-1);
	}

	for (uint64_t i = 0ULL; this->m_nsize - 4ULL; i += 4ULL) {
#if LAM_CACHE_MEM_STORES == 1
		_mm256_storeu_pd(&this->m_Re[i], _mm256_setzero_pd());
		_mm256_storeu_pd(&this->m_Im[i], _mm256_setzero_pd());
#else
		_mm256_stream_pd(&this->m_Re[i], _mm256_setzero_pd());
		_mm256_stream_pd(&this->m_Im[i], _mm256_setzero_pd());
#endif
	}
	this->m_isbuilt = true;
}

lam::math::AVXVComplex1D::
		   AVXVComplex1D(_In_ const uint64_t nsize,
					     _In_ const double* __restrict Re,
						 _In_ const double* __restrict Im)
:
m_nsize{nsize},
m_Re(reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double),align32B))),
m_Im(reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double),align32B)))
{
	if (this->m_Re == NULL ||
		this->m_Im == NULL ||
		Re         == NULL ||
		Im         == NULL ||
		(this->m_nsize % 4ULL) != 0ULL) {
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
										Memory allocation failure in: AVXVComplex1D(int64_t,double*,double*)\n";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
		std::exit(-1);
	}

	for (uint64_t i = 0ULL; i != this->m_nsize - 4ULL; i += 4ULL) {
#if LAM_CACHE_MEM_STORES == 1
		_mm256_storeu_pd(&this->m_Re[i], _mm256_loadu_pd(&Re[i]));
		_mm256_storeu_pd(&this->m_Im[i], _mm256_loadu_pd(&Im[i]));
#else
		_mm256_stream_pd(&this->m_Re[i], _mm256_loadu_pd(&Re[i]));
		_mm256_stream_pd(&this->m_Im[i], _mm256_loadu_pd(&Im[i]));
#endif
	}
	this->m_isbuilt = true;
}

lam::math::AVXVComplex1D::
		   AVXVComplex1D(_In_ const AVXVComplex1D &x)
:
m_nsize{x.m_nsize},
m_Re(reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double),align32B))),
m_Im(reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double),align32B))) {
		
	if (this->m_Re == NULL ||
		this->m_Im == NULL) {
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
										Memory allocation failure in: AVXVComplex1D(AVXVComplex1D &)\n";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
		std::exit(-1);
	}

	for (uint64_t i = 0ULL; i != this->m_nsize - 4ULL; i += 4ULL) {
#if LAM_MAN_PREFETCH == 1
		_mm_prefetch(reinterpret_cast<const char*>(&x.getRe()[i+4]),_MM_HINT_T0);
		_mm_prefetch(reinterpret_cast<const char*>(&x.getIm()[i+4]),_MM_HINT_T0);
#endif
#if LAM_CACHE_MEM_STORES == 1
		_mm256_storeu_pd(&this->m_Re[i], _mm256_loadu_pd(&x.getRe()[i]));
		_mm256_storeu_pd(&this->m_Im[i], _mm256_loadu_pd(&x.getIm()[i]));
#else
		_mm256_stream_pd(&this->m_Re[i], _mm256_loadu_pd(&x.getRe()[i]));
		_mm256_stream_pd(&this->m_Im[i], _mm256_loadu_pd(&x.getIm()[i]));
#endif
	}
	this->m_isbuilt = true;
}

lam::math::AVXVComplex1D::
		   AVXVComplex1D(_In_ AVXVComplex1D &&x)
:
m_nsize{x.m_nsize},
m_Re(NULL),
m_Im(NULL) {

	this->m_Re = &x.getRe()[0];
	this->m_Im = &x.getIm()[0];
	this->m_isbuilt = true;
	x.m_nsize = 0ULL;
	x.m_Re = NULL;
	x.m_Im = NULL;
	x.m_isbuilt = false;
}

lam::math::AVXVComplex1D::
		  ~AVXVComplex1D() {

	this->m_nsize = 0ULL;
	if (this->m_Re) {
		_mm_free(this->m_Re);
		this->m_Re = NULL;
	}
	if (this->m_Im) {
		_mm_free(this->m_Im);
		this->m_Im = NULL;
	}
	this->m_isbuilt = false;
}

lam::math::AVXVComplex1D &
lam::math::AVXVComplex1D::operator=(_In_ const AVXVComplex1D &x) {
	if (this == &x || 
		!x.get_isbuilt()) return (*this);

	this->m_nsize = x.get_nsize();
	_mm_free(this->m_Re);
	_mm_free(this->m_Im);

	for (uint64_t i = 0ULL; i != this->m_nsize - 4ULL; i += 4ULL) {
#if LAM_MAN_PREFETCH == 1
		_mm_prefetch(reinterpret_cast<const char*>(&x.getRe()[i+4]),_MM_HINT_T0);
		_mm_prefetch(reinterpret_cast<const char*>(&x.getIm()[i+4]),_MM_HINT_T0);
#endif
#if LAM_CACHE_MEM_STORES == 1
		_mm256_storeu_pd(&this->m_Re[i], _mm256_loadu_pd(&x.getRe()[i]));
		_mm256_storeu_pd(&this->m_Im[i], _mm256_loadu_pd(&x.getIm()[i]));
#else
		_mm256_stream_pd(&this->m_Re[i], _mm256_loadu_pd(&x.getRe()[i]));
		_mm256_stream_pd(&this->m_Im[i], _mm256_loadu_pd(&x.getIm()[i]));
#endif
	}
	this->m_isbuilt = x.get_isbuilt();
	return (*this);
}

lam::math::AVXVComplex1D &
lam::math::AVXVComplex1D::operator=(_In_ AVXVComplex1D &&x) {
	if (this == &x ||
		!x.get_isbuilt()) return (*this);

	_mm_free(this->m_Re);
	_mm_free(this->m_Im);
	this->m_nsize = x.get_nsize();
	this->m_Re = x.getRe();
	this->m_Im = x.getIm();
	this->m_isbuilt = x.get_isbuilt();
	x.m_Re = 0ULL;
	x.m_Re = NULL;
	x.m_Im = NULL;
	x.m_isbuilt = false;
	return (*this);
}

lam::math::AVXVComplex1D &
lam::math::AVXVComplex1D::operator+=(_In_ const AVXVComplex1D &x) {
	if (!x.get_isbuilt() ||
		this->m_nsize != x.get_nsize()) {
		throw std::invalid_argument("AVXVComplex1D::operator+= [loc:194] --> Invalid argument!!");
	}

	for (uint64_t i = 0ULL; i != this->m_nsize - 4ULL; i += 4ULL) {
#if LAM_MAN_PREFETCH == 1
		_mm_prefetch(reinterpret_cast<const char*>(&x.getRe()[i+4]),_MM_HINT_T0);
		_mm_prefetch(reinterpret_cast<const char*>(&x.getIm()[i+4]),_MM_HINT_T0);
#endif
#if LAM_CACHE_MEM_STORES == 1
		_mm256_storeu_pd(&this->m_Re[i], _mm256_add_pd(_mm256_loadu_pd(&this->m_Re[i]),
													   _mm256_loadu_pd(&x.getRe()[i])));
		_mm256_storeu_pd(&this->m_Im[i], _mm256_add_pd(_mm256_loadu_pd(&this->m_Im[i]),
													   _mm256_loadu_pd(&x.getIm()[i])));
#else
		_mm256_stream_pd(&this->m_Re[i], _mm256_add_pd(_mm256_loadu_pd(&this->m_Re[i]),
													   _mm256_loadu_pd(&x.getRe()[i])));
		_mm256_stream_pd(&this->m_Im[i], _mm256_add_pd(_mm256_loadu_pd(&this->m_Im[i]),
													   _mm256_loadu_pd(&x.getIm()[i])));
#endif
	}
	return (*this);
}

lam::math::AVXVComplex1D &
lam::math::AVXVComplex1D::operator+=(_In_ const double* __restrict v) {
	if (v == NULL) {
		throw std::invalid_argument("AVXVComplex1D::operator+= [loc:225] --> v == NULL!");
	}

	for (uint64_t i = 0ULL; i != this->m_nsize - 4ULL; i += 4ULL) {
#if LAM_MAN_PREFETCH == 1
		_mm_prefetch(reinterpret_cast<const char*>(&v[i+4]),_MM_HINT_T0);
#endif
#if LAM_CACHE_MEM_STORES == 1
		_mm256_storeu_pd(&this->m_Re[i], _mm256_add_pd(_mm256_loadu_pd(&this->m_Re[i]),
													   _mm256_loadu_pd(&v[i])));
#else
		_mm256_stream_pd(&this->m_Re[i], _mm256_add_pd(_mm256_loadu_pd(&this->m_Re[i]),
													   _mm256_loadu_pd(&v[i])));
#endif		
	}
	return (*this);
}

lam::math::AVXVComplex1D &
lam::math::AVXVComplex1D::operator-=(_In_ const AVXVComplex1D &x) {
	if (!x.get_isbuilt() ||
		this->m_nsize != x.get_nsize()) {
		throw std::invalid_argument("AVXVComplex1D::operator-= [loc:250] --> Invalid argument(s)!!");
	}

	for (uint64_t i = 0ULL; i != this->m_nsize - 4ULL; i += 4ULL) {
#if LAM_MAN_PREFETCH == 1
		_mm_prefetch(reinterpret_cast<const char*>(&x.getRe()[i+4]),_MM_HINT_T0);
		_mm_prefetch(reinterpret_cast<const char*>(&x.getIm()[i+4]),_MM_HINT_T0);
#endif
#if LAM_CACHE_MEM_STORES == 1
		_mm256_storeu_pd(&this->m_Re[i], _mm256_sub_pd(_mm256_loadu_pd(&this->m_Re[i]),
													   _mm256_loadu_pd(&x.getRe()[i])));
		_mm256_storeu_pd(&this->m_Im[i], _mm256_sub_pd(_mm256_loadu_pd(&this->m_Im[i]),
													   _mm256_loadu_pd(&x.getIm()[i])));
#else
		_mm256_stream_pd(&this->m_Re[i], _mm256_sub_pd(_mm256_loadu_pd(&this->m_Re[i]),
													   _mm256_loadu_pd(&x.getRe()[i])));
		_mm256_stream_pd(&this->m_Im[i], _mm256_sub_pd(_mm256_loadu_pd(&this->m_Im[i]),
													   _mm256_loadu_pd(&x.getIm()[i])));
#endif
	}
	return (*this);
}

lam::math::AVXVComplex1D &
lam::math::AVXVComplex1D::operator-=(_In_ const double* __restrict v) {
	if (v == NULL) 
		throw std::invalid_argument("AVXVComplex1D::operator-= [loc:281] --> v == NULL!!");

	for (uint64_t i = 0ULL; i != this->m_nsize - 4ULL; i += 4ULL) {
#if LAM_MAN_PREFETCH == 1
		_mm_prefetch(reinterpret_cast<const char*>(&v[i+4]),_MM_HINT_T0);
#endif
#if LAM_CACHE_MEM_STORES == 1
		_mm256_storeu_pd(&this->m_Re[i], _mm256_sub_pd(_mm256_loadu_pd(&this->m_Re[i]),
												       _mm256_loadu_pd(&v[i])));
#else		
		_mm256_stream_pd(&this->m_Re[i], _mm256_sub_pd(_mm256_loadu_pd(&this->m_Re[i]),
												       _mm256_loadu_pd(&v[i])));
#endif
	}
	return (*this);
}

lam::math::AVXVComplex1D &
lam::math::AVXVComplex1D::operator*=(_In_ const AVXVComplex1D &x) {
	if (!x.get_isbuilt() ||
		this->m_nsize != x.get_nsize()) {
		throw std::invalid_argument("AVXVComplex1D::operator*= [loc:305] --> Invalid argument(s)!!");
	}

	for (uint64_t i = 0ULL; i != this->m_nsize - 4ULL; i += 4ULL) {
#if LAM_MAN_PREFETCH == 1
		_mm_prefetch(reinterpret_cast<const char*>(&x.getRe()[i+4]),_MM_HINT_T0);
		_mm_prefetch(reinterpret_cast<const char*>(&x.getIm()[i+4]),_MM_HINT_T0);
#endif
#if LAM_CACHE_MEM_STORES == 1
		_mm256_storeu_pd(&this->m_Re[i], _mm256_sub_pd(_mm256_mul_pd(_mm256_loadu_pd(&this->m_Re[i]),
			           _mm256_loadu_pd(&x.getRe()[i])),_mm256_mul_pd(_mm256_loadu_pd(&this->m_Im[i]),
			           _mm256_loadu_pd(&x.getIm()[i]))));
		_mm256_storeu_pd(&this->m_Im[i], _mm256_add_pd(_mm256_mul_pd(_mm256_loadu_pd(&this->m_Im[i]),
					   _mm256_loadu_pd(&x.getRe()[i])), _mm256_mul_pd(_mm256_loadu_pd(&this->m_Re[i]),
			           _mm256_loadu_pd(&x.getIm()[i]))));
#else
		_mm256_stream_pd(&this->m_Re[i], _mm256_sub_pd(_mm256_mul_pd(_mm256_loadu_pd(&this->m_Re[i]),
			          _mm256_loadu_pd(&x.getRe()[i])), _mm256_mul_pd(_mm256_loadu_pd(&this->m_Im[i]),
			          _mm256_loadu_pd(&x.getIm()[i]))));
		_mm256_stream_pd(&this->m_Im[i], _mm256_add_pd(_mm256_mul_pd(_mm256_loadu_pd(&this->m_Im[i]),
			          _mm256_loadu_pd(&x.getRe()[i])), _mm256_mul_pd(_mm256_loadu_pd(&this->m_Re[i]),
			          _mm256_loadu_pd(&x.getIm()[i]))));
#endif
	}
	return (*this);
}

lam::math::AVXVComplex1D &
lam::math::AVXVComplex1D::operator*=(_In_ const double* __restrict v) {
	if (v == NULL)
		throw std::invalid_argument("AVXVComplex1D::operator*= [loc:340] --> v == NULL!!");

	for (uint64_t i = 0ULL; i != this->m_nsize - 4ULL; i += 4ULL) {
#if LAM_MAN_PREFETCH == 1
		_mm_prefetch(reinterpret_cast<const char*>(&v[i+4]),_MM_HINT_T0);
#endif
#if LAM_CACHE_MEM_STORES == 1
		_mm256_storeu_pd(&this->m_Re[i], _mm256_mul_pd(_mm256_loadu_pd(&this->m_Re[i]),
													   _mm256_loadu_pd(&v[i])));
		_mm256_storeu_pd(&this->m_Im[i], _mm256_mul_pd(_mm256_loadu_pd(&this->m_Im[i]),
												       _mm256_loadu_pd(&v[i])));
#else
		_mm256_storeu_pd(&this->m_Re[i], _mm256_mul_pd(_mm256_loadu_pd(&this->m_Re[i]),
			_mm256_loadu_pd(&v[i])));
		_mm256_storeu_pd(&this->m_Im[i], _mm256_mul_pd(_mm256_loadu_pd(&this->m_Im[i]),
			_mm256_loadu_pd(&v[i])));
#endif
	}
	return (*this);
}

lam::math::AVXVComplex1D &
lam::math::AVXVComplex1D::operator/=(_In_ const AVXVComplex1D &x) {
	if (!x.get_isbuilt() ||
		this->m_nsize != x.get_nsize()) {
		throw std::invalid_argument("AVXVComplex1D::operator/= [loc:368] --> Invalid argument(s)!!");
	}
	__m256d zmask1( _mm256_setzero_pd() );
	__m256d zmask2( _mm256_setzero_pd() );
	__m256i vres(_mm256_setr_epi64x(0LL,0LL,0LL,0LL));
	const __m256d vzero(_mm256_set1_pd(0.0));
	for (uint64_t i = 0ULL; i != this->m_nsize - 4ULL; i += 4ULL) {
#if LAM_MAN_PREFETCH == 1
		_mm_prefetch(reinterpret_cast<const char*>(&x.getRe()[i+4]),_MM_HINT_T0);
		_mm_prefetch(reinterpret_cast<const char*>(&x.getIm()[i+4]),_MM_HINT_T0);
#endif
		zmask1 = _mm256_cmp_pd(vzero, _mm256_loadu_pd(&x.getRe()[i]),_CMP_EQ_OQ);
		zmask2 = _mm256_cmp_pd(vzero, _mm256_loadu_pd(&x.getIm()[i]),_CMP_EQ_OQ);
		if (_mm256_testc_pd(zmask1, _mm256_setzero_pd()) ||
			_mm256_testc_pd(zmask2, _mm256_setzero_pd())) {
			vres = _mm256_setr_epi64x(1LL,1LL,1LL,1LL);
			break;
		}
	}
	if (vres.m256i_u64[0] == 1LL ||
		vres.m256i_u64[1] == 1LL ||
		vres.m256i_u64[2] == 1LL ||
		vres.m256i_u64[3] == 1LL) {
		throw std::domain_error("AVXVComplex1D::operator/= [loc:389] --> found '0.0' in AVXVComplex1D!");
	}
	

	for (uint64_t i = 0ULL; i != this->m_nsize - 4ULL; i += 4ULL) {
#if LAM_MAN_PREFETCH == 1
		_mm_prefetch(reinterpret_cast<const char*>(&x.getRe()[i + 4]), _MM_HINT_T0);
		_mm_prefetch(reinterpret_cast<const char*>(&x.getIm()[i + 4]), _MM_HINT_T0);
#endif
#if LAM_CACHE_MEM_STORES == 1
		__m256d tre = _mm256_add_pd(_mm256_mul_pd(_mm256_loadu_pd(&this->m_Re[i]),
			_mm256_loadu_pd(&x.getIm()[i])),_mm256_mul_pd(_mm256_loadu_pd(&this->m_Im[i]),
			_mm256_loadu_pd(&x.getIm()[i])));
		__m256d tim = _mm256_sub_pd(_mm256_mul_pd(_mm256_loadu_pd(&this->m_Im[i]),
			_mm256_loadu_pd(&x.getIm()[i])), _mm256_mul_pd(_mm256_loadu_pd(&this->m_Re[i]),
			_mm256_loadu_pd(&x.getIm()[i])));
		__m256d tmp = _mm256_add_pd(_mm256_mul_pd(_mm256_loadu_pd(&x.getRe()[i]),
			_mm256_loadu_pd(&x.getRe()[i])), _mm256_mul_pd(_mm256_loadu_pd(&x.getIm()[i]),
			_mm256_loadu_pd(&x.getIm()[i])));
		_mm256_storeu_pd(&this->m_Re[i], _mm256_div_pd(tre,tmp));
		_mm256_storeu_pd(&this->m_Im[i], _mm256_div_pd(tim,tmp));
#else
		__m256d tre = _mm256_add_pd(_mm256_mul_pd(_mm256_loadu_pd(&this->m_Re[i]),
			_mm256_loadu_pd(&x.getIm()[i])), _mm256_mul_pd(_mm256_loadu_pd(&this->m_Im[i]),
			_mm256_loadu_pd(&x.getIm()[i])));
		__m256d tim = _mm256_sub_pd(_mm256_mul_pd(_mm256_loadu_pd(&this->m_Im[i]),
			_mm256_loadu_pd(&x.getIm()[i])), _mm256_mul_pd(_mm256_loadu_pd(&this->m_Re[i]),
			_mm256_loadu_pd(&x.getIm()[i])));
		__m256d tmp = _mm256_add_pd(_mm256_mul_pd(_mm256_loadu_pd(&x.getRe()[i]),
			_mm256_loadu_pd(&x.getRe()[i])), _mm256_mul_pd(_mm256_loadu_pd(&x.getIm()[i]),
			_mm256_loadu_pd(&x.getIm()[i])));
		_mm256_stream_pd(&this->m_Re[i], _mm256_div_pd(tre, tmp));
		_mm256_stream_pd(&this->m_Im[i], _mm256_div_pd(tim, tmp));
#endif
	}
	return (*this);
}

lam::math::AVXVComplex1D &
lam::math::AVXVComplex1D::operator/=(_In_ const double* __restrict v) {
	if (v == NULL)
		throw std::invalid_argument("AVXVComplex1D::operator/= [loc:437] --> v == NULL!!");
	__m256d zmask1(_mm256_setzero_pd());
	
	__m256i vres(_mm256_setr_epi64x(0LL, 0LL, 0LL, 0LL));
	const __m256d vzero(_mm256_set1_pd(0.0));
	for (uint64_t i = 0ULL; i != this->m_nsize - 4ULL; i += 4ULL) {
#if LAM_MAN_PREFETCH == 1
		_mm_prefetch(reinterpret_cast<const char*>(&v[i]),_MM_HINT_T0);
#endif
		zmask1 = _mm256_cmp_pd(vzero, _mm256_loadu_pd(&v[i]), _CMP_EQ_OQ);
		if (_mm256_testc_pd(zmask1, _mm256_setzero_pd())) {
			vres = _mm256_setr_epi64x(1LL,1LL,1LL,1LL);
			break;
		}
	}
	if (vres.m256i_u64[0] == 1LL ||
		vres.m256i_u64[1] == 1LL ||
		vres.m256i_u64[2] == 1LL ||
		vres.m256i_u64[3] == 1LL) {
		throw std::domain_error("AVXVComplex1D::operator/= [loc:453] --> found '0.0' in double* !");
	}

	for (uint64_t i = 0ULL; i != this->m_nsize - 4ULL; i += 4ULL) {
#if LAM_MAN_PREFETCH == 1
		_mm_prefetch(reinterpret_cast<const char*>(&v[i]), _MM_HINT_T0);
#endif
#if LAM_CACHE_MEM_STORES == 1
		_mm256_storeu_pd(&this->m_Re[i], _mm256_div_pd(_mm256_loadu_pd(&this->m_Re[i]),
													   _mm256_loadu_pd(&v[i])));
		_mm256_storeu_pd(&this->m_Im[i], _mm256_div_pd(_mm256_loadu_pd(&this->m_Im[i]),
													   _mm256_loadu_pd(&v[i])));
#else
		_mm256_stream_pd(&this->m_Re[i], _mm256_div_pd(_mm256_loadu_pd(&this->m_Re[i]),
			_mm256_loadu_pd(&v[i])));
		_mm256_stream_pd(&this->m_Im[i], _mm256_div_pd(_mm256_loadu_pd(&this->m_Im[i]),
			_mm256_loadu_pd(&v[i])));
#endif
	}
	return (*this);
}

std::pair<double*,double*> 
lam::math::AVXVComplex1D::operator==(_In_ const AVXVComplex1D &x) {
	if (!x.get_isbuilt() ||
		this->m_nsize != x.get_nsize()) {
		throw std::invalid_argument("AVXVComplex1D::operator== [loc:487] --> Invalid argument(s)!!");
	}
	double * __restrict pr1 = 
	reinterpret_cast<double*>(_mm_malloc(this->m_nsize*sizeof(double),align32B));
	double * __restrict pr2 = 
	reinterpret_cast<double*>(_mm_malloc(this->m_nsize*sizeof(double),align32B));
	std::pair<double*,double*> pret;
	if (pr1 == NULL || pr2 == NULL) {
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
														Memory allocation failure in: AVXVComplex1D::operator==\n";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
		std::exit(-1);
	}
	for (uint64_t i = 0ULL; i != this->m_nsize - 4ULL; i += 4ULL){
		  _mm256_storeu_pd(&pr1[i], _mm256_set_pd(-1.0,-1.0,-1.0,-1.0));
		  _mm256_storeu_pd(&pr2[i], _mm256_set_pd(-1.0,-1.0,-1.0,-1.0));
		}
	pret = std::make_pair(pr1,pr2);


	for (uint64_t i = 0ULL; i != this->m_nsize - 4ULL; i += 4ULL) {
#if LAM_MAN_PREFETCH == 1
		_mm_prefetch(reinterpret_cast<const char*>(&x.getRe()[i]),_MM_HINT_T0);
		_mm_prefetch(reinterpret_cast<const char*>(&x.getIm()[i]),_MM_HINT_T0);
#endif
#if LAM_CACHE_MEM_STORES == 1
		_mm256_storeu_pd(&pret.first[i],_mm256_cmp_pd(_mm256_loadu_pd(&this->m_Re[i]),
										_mm256_loadu_pd(&x.getRe()[i]),_CMP_EQ_OQ));
		_mm256_storeu_pd(&pret.second[i], _mm256_cmp_pd(_mm256_loadu_pd(&this->m_Im[i]),
									    _mm256_loadu_pd(&x.getIm()[i]),_CMP_EQ_OQ));
#else
		_mm256_stream_pd(&pret.first[i], _mm256_cmp_pd(_mm256_loadu_pd(&this->m_Re[i]),
			_mm256_loadu_pd(&x.getRe()[i]), _CMP_EQ_OQ));
		_mm256_stream_pd(&pret.second[i], _mm256_cmp_pd(_mm256_loadu_pd(&this->m_Im[i]),
			_mm256_loadu_pd(&x.getIm()[i]), _CMP_EQ_OQ));
#endif
	}	
	return (pret);
}

std::pair<double*,double*>
lam::math::AVXVComplex1D::operator!=(_In_ const AVXVComplex1D &x) {
	if (!x.get_isbuilt() ||
		this->m_nsize != x.get_nsize()) {
		throw std::invalid_argument("AVXVComplex1D::operator!= [loc:535] --> Invalid argument(s)!!");
	}
	double * __restrict pr1 =
		reinterpret_cast<double*>(_mm_malloc(this->m_nsize*sizeof(double), align32B));
	double * __restrict pr2 =
		reinterpret_cast<double*>(_mm_malloc(this->m_nsize*sizeof(double), align32B));
	std::pair<double*, double*> pret;
	if (pr1 == NULL || pr2 == NULL) {
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
												Memory allocation failure in: AVXVComplex1D::operator!=\n";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
		std::exit(-1);
	}
	for (uint64_t i = 0ULL; i != this->m_nsize - 4ULL; i += 4ULL){
		_mm256_storeu_pd(&pr1[i], _mm256_set_pd(-1.0, -1.0, -1.0, -1.0));
		_mm256_storeu_pd(&pr2[i], _mm256_set_pd(-1.0, -1.0, -1.0, -1.0));
	}
	pret = std::make_pair(pr1, pr2);


	for (uint64_t i = 0ULL; i != this->m_nsize - 4ULL; i += 4ULL) {
#if LAM_MAN_PREFETCH == 1
		_mm_prefetch(reinterpret_cast<const char*>(&x.getRe()[i]), _MM_HINT_T0);
		_mm_prefetch(reinterpret_cast<const char*>(&x.getIm()[i]), _MM_HINT_T0);
#endif
#if LAM_CACHE_MEM_STORES == 1
		_mm256_storeu_pd(&pret.first[i], _mm256_cmp_pd(_mm256_loadu_pd(&this->m_Re[i]),
			_mm256_loadu_pd(&x.getRe()[i]), _CMP_NEQ_OQ)); 
		_mm256_storeu_pd(&pret.second[i], _mm256_cmp_pd(_mm256_loadu_pd(&this->m_Im[i]),
			_mm256_loadu_pd(&x.getIm()[i]), _CMP_NEQ_OQ));
#else
		_mm256_stream_pd(&pret.first[i], _mm256_cmp_pd(_mm256_loadu_pd(&this->m_Re[i]),
			_mm256_loadu_pd(&x.getRe()[i]), _CMP_NEQ_OQ));
		_mm256_stream_pd(&pret.second[i], _mm256_cmp_pd(_mm256_loadu_pd(&this->m_Im[i]),
			_mm256_loadu_pd(&x.getIm()[i]), _CMP_NEQ_OQ));
#endif
	}
	return (pret);
}

std::ostream & 
lam::math::operator<<(_In_ std::ostream &os, _In_ const AVXVComplex1D &x) {
	if (!x.get_isbuilt())
		throw std::invalid_argument("lam::math::operator<< [loc:581] --> AVXVComplex1D in invalid state!!");
	for (uint64_t i = 0ULL; i != x.get_nsize(); ++i) {
		os << std::fixed << std::showpoint << std::setprecision(15) << std::setw(4) << "Re: " << x.getRe()[i] <<
			std::setw(12) << "Im: " << x.getIm()[i] << std::endl;
	}	
	return (os);
}

lam::math::AVXVComplex1D &
lam::math::AVXVComplex1D::vcnormalize(_In_ const AVXVComplex1D &x) {
	if (!x.get_isbuilt() ||
		this->m_nsize != x.get_nsize()) {
		throw std::invalid_argument("AVXVComplex1D::vconrmalize [loc:592] --> AVXVComplex1D in invalid state!!");
	}


	for (uint64_t i = 0ULL; i != this->m_nsize - 4ULL; i += 4ULL) {
#if LAM_MAN_PREFETCH == 1
		_mm_prefetch(reinterpret_cast<const char*>(&x.getRe()[i+4]),_MM_HINT_T0);
		_mm_prefetch(reinterpret_cast<const char*>(&x.getIm()[i+4]),_MM_HINT_T0);
#endif
#if LAM_CACHE_MEM_STORES == 1
		_mm256_storeu_pd(&this->m_Re[i], _mm256_sub_pd(_mm256_mul_pd(_mm256_loadu_pd(&this->m_Re[i]),
						_mm256_loadu_pd(&x.getRe()[i])),_mm256_mul_pd(_mm256_loadu_pd(&this->m_Im[i]),
						_mm256_loadu_pd(&x.getIm()[i]))));
		_mm256_storeu_pd(&this->m_Im[i], _mm256_add_pd(_mm256_mul_pd(_mm256_loadu_pd(&this->m_Im[i]),
						_mm256_loadu_pd(&x.getRe()[i])), _mm256_mul_pd(_mm256_loadu_pd(&this->m_Re[i]),
						_mm256_loadu_pd(&x.getIm()[i]))));
		
		__m256d cmag = _mm256_sqrt_pd(_mm256_add_pd(_mm256_mul_pd(_mm256_loadu_pd(&this->m_Re[i]),
				   _mm256_loadu_pd(&this->m_Re[i])),_mm256_mul_pd(_mm256_loadu_pd(&this->m_Im[i]),
			       _mm256_loadu_pd(&this->m_Im[i]))));
		_mm256_storeu_pd(&this->m_Re[i], _mm256_div_pd(_mm256_loadu_pd(&this->m_Re[i]),cmag));
		_mm256_storeu_pd(&this->m_Im[i], _mm256_div_pd(_mm256_loadu_pd(&this->m_Im[i]),cmag));
#else
		_mm256_storeu_pd(&this->m_Re[i], _mm256_sub_pd(_mm256_mul_pd(_mm256_loadu_pd(&this->m_Re[i]),
			_mm256_loadu_pd(&x.getRe()[i])), _mm256_mul_pd(_mm256_loadu_pd(&this->m_Im[i]),
			_mm256_loadu_pd(&x.getIm()[i]))));
		_mm256_storeu_pd(&this->m_Im[i], _mm256_add_pd(_mm256_mul_pd(_mm256_loadu_pd(&this->m_Im[i]),
			_mm256_loadu_pd(&x.getRe()[i])), _mm256_mul_pd(_mm256_loadu_pd(&this->m_Re[i]),
			_mm256_loadu_pd(&x.getIm()[i]))));

		__m256d cmag = _mm256_sqrt_pd(_mm256_add_pd(_mm256_mul_pd(_mm256_loadu_pd(&this->m_Re[i]),
			_mm256_loadu_pd(&this->m_Re[i])), _mm256_mul_pd(_mm256_loadu_pd(&this->m_Im[i]),
			_mm256_loadu_pd(&this->m_Im[i]))));
		_mm256_storeu_pd(&this->m_Re[i], _mm256_div_pd(_mm256_loadu_pd(&this->m_Re[i]), cmag));
		_mm256_storeu_pd(&this->m_Im[i], _mm256_div_pd(_mm256_loadu_pd(&this->m_Im[i]), cmag));
#endif
	}
	return (*this);
}

std::complex<double> 
lam::math::AVXVComplex1D::vcmean(_In_ const AVXVComplex1D &x) {
	if (!x.get_isbuilt() ||
		this->m_nsize != x.get_nsize()) {
		throw std::invalid_argument("AVXVComplex1D::vcmean [loc:640] --> AVXVComplex1D in invalid state!!");
	}
	const uint64_t vlen{ x.get_nsize() };
	double sr{}, si{},acc1{},acc2{};
	// First pass vector summation.
	for (uint64_t i = 0; i != this->m_nsize - 4ULL; i += 4ULL) {
#if LAM_MAN_PREFETCH == 1
		_mm_prefetch(reinterpret_cast<const char*>(&x.getRe()[i+4]),_MM_HINT_T0);
		_mm_prefetch(reinterpret_cast<const char*>(&x.getIm()[i+4]),_MM_HINT_T0);
#endif 
		_mm256_storeu_pd(&this->m_Re[i], _mm256_add_pd(_mm256_loadu_pd(&this->m_Re[i]),
										 _mm256_loadu_pd(&x.getRe()[i])));
		_mm256_storeu_pd(&this->m_Im[i], _mm256_add_pd(_mm256_loadu_pd(&this->m_Im[i]),
										 _mm256_loadu_pd(&x.getIm()[i])));
	}
	// Second pass Re and Im horizontal summation
	
	for (uint64_t i = 0ULL; i != this->m_nsize - 4ULL; i += 4ULL) {
#if LAM_MAN_PREFETCH == 1
		_mm_prefetch(reinterpret_cast<const char*>(&this->m_Re[i+4]),_MM_HINT_T0);
		_mm_prefetch(reinterpret_cast<const char*>(&this->m_Im[i+4]), _MM_HINT_T0);
#endif
		__m256d t1 = _mm256_loadu_pd(&this->m_Re[i]);
		__m256d tsum = _mm256_add_pd(t1,_mm256_permute2f128_pd(t1,t1,0x1));
		__m256d t2 = _mm256_loadu_pd(&this->m_Im[i]);
		__m256d tsum2 = _mm256_add_pd(t2, _mm256_permute2f128_pd(t2,t2,0x1));
		_mm_store_pd(&sr, _mm_hadd_pd(_mm256_castpd256_pd128(tsum), _mm256_castpd256_pd128(tsum)));
		acc1 += sr;
		_mm_store_pd(&si, _mm_hadd_pd(_mm256_castpd256_pd128(tsum2),_mm256_castpd256_pd128(tsum2)));
		acc2 += si;
	}
	return(std::complex<double>{acc1/vlen,acc2/vlen});
}

void 
lam::math::AVXVComplex1D::vcmag(_Inout_ double* __restrict mag, 
							    _In_ const uint64_t size) {
	if (mag == NULL ||
		this->m_nsize != size) {
		throw std::invalid_argument("AVXVComplex1D::vcmag [loc:615] --> Invalid argument or null pointer!!");
	}
	for (uint64_t i = 0ULL; i != this->m_nsize - 4ULL; i += 4ULL) {

#if LAM_CACHE_MEM_STORES == 1
		_mm256_storeu_pd(&mag[i], _mm256_sqrt_pd(_mm256_add_pd(_mm256_mul_pd(_mm256_loadu_pd(&this->m_Re[i]),
			                      _mm256_loadu_pd(&this->m_Re[i])),_mm256_mul_pd(_mm256_loadu_pd(&this->m_Im[i]),
			                      _mm256_loadu_pd(&this->m_Im[i])))));
#else
		_mm256_stream_pd(&mag[i], _mm256_sqrt_pd(_mm256_add_pd(_mm256_mul_pd(_mm256_loadu_pd(&this->m_Re[i]),
			_mm256_loadu_pd(&this->m_Re[i])), _mm256_mul_pd(_mm256_loadu_pd(&this->m_Im[i]),
			_mm256_loadu_pd(&this->m_Im[i])))));
#endif
	}
}	

void
lam::math::AVXVComplex1D::vcdeg(_Inout_ double* __restrict vdeg,
							    _In_ const uint64_t size) {
	if (vdeg == NULL ||
		this->m_nsize != size) {
		throw std::invalid_argument("AVXVComplex1D::vcdeg [loc:639] --> Invalid argument or null pointer!!");
	}
	const __m256d vrad_to_deg( _mm256_set1_pd(57.29577951308092));
	// Not checking for 0.0 values in *this
	for (uint64_t i = 0ULL; i != this->m_nsize - 4ULL; i += 4ULL) {
#if LAM_MAN_PREFETCH == 1
		_mm_prefetch(reinterpret_cast<const char*>(&this->m_Re[i+4]),_MM_HINT_T0);
		_mm_prefetch(reinterpret_cast<const char*>(&this->m_Im[i+4]),_MM_HINT_T0);
#endif
#if LAM_CACHE_MEM_STORES == 1
		_mm256_storeu_pd(&vdeg[i], _mm256_mul_pd(vrad_to_deg, _mm256_atan2_pd(_mm256_loadu_pd(&this->m_Re[i]),
								   _mm256_loadu_pd(&this->m_Im[i]))));
#else		
		_mm256_stream_pd(&vdeg[i], _mm256_mul_pd(vrad_to_deg, _mm256_atan2_pd(_mm256_loadu_pd(&this->m_Re[i]),
								  _mm256_loadu_pd(&this->m_Im[i]))));
#endif		 
	}
}	

void 
lam::math::AVXVComplex1D::vcrad(_Inout_ double* __restrict vrad,
								_In_ const uint64_t size) {
	if (vrad == NULL ||
		this->m_nsize != size) {
		throw std::invalid_argument("AVXVComplex1D::vcrad [loc:660] --> Invalid argument or null pointer!!");
	}
	// Not checking for 0.0 values in *this
	for (uint64_t i = 0ULL; i != this->m_nsize - 4ULL; i += 4ULL) {
#if LAM_MAN_PREFETCH == 1
		_mm_prefetch(reinterpret_cast<const char*>(&this->m_Re[i + 4]), _MM_HINT_T0);
		_mm_prefetch(reinterpret_cast<const char*>(&this->m_Im[i + 4]), _MM_HINT_T0);
#endif
#if LAM_CACHE_MEM_STORES == 1
		_mm256_storeu_pd(&vrad[i], _mm256_atan2_pd(_mm256_loadu_pd(&this->m_Re[i]),
								   _mm256_loadu_pd(&this->m_Im[i])));
#else
		_mm256_stream_pd(&vrad[i], _mm256_atan2_pd(_mm256_loadu_pd(&this->m_Re[i]),
			_mm256_loadu_pd(&this->m_Im[i])));
#endif		
	}
}

void 
lam::math::AVXVComplex1D::vcpow(_Inout_ double* __restrict vpow,
							    _In_ const uint64_t size) {
	if (vpow == NULL ||
		this->m_nsize != size) {
		throw std::invalid_argument("AVXVComplex1D::vcpow [loc:684] --> Invalid argument or null pointer!!");
	}
	for (uint64_t i = 0ULL; i != this->m_nsize - 4ULL; i += 4ULL) {
#if LAM_MAN_PREFETCH == 1
		_mm_prefetch(reinterpret_cast<const char*>(&this->m_Re[i + 4]), _MM_HINT_T0);
		_mm_prefetch(reinterpret_cast<const char*>(&this->m_Im[i + 4]), _MM_HINT_T0);
#endif
#if LAM_CACHE_MEM_STORES == 1
		_mm256_storeu_pd(&vpow[i], _mm256_add_pd(_mm256_mul_pd(_mm256_loadu_pd(&this->m_Re[i]),
			    _mm256_loadu_pd(&this->m_Re[i])),_mm256_mul_pd(_mm256_loadu_pd(&this->m_Im[i]),
			    _mm256_loadu_pd(&this->m_Im[i]))));
#else
		_mm256_stream_pd(&vpow[i], _mm256_add_pd(_mm256_mul_pd(_mm256_loadu_pd(&this->m_Re[i]),
			_mm256_loadu_pd(&this->m_Re[i])), _mm256_mul_pd(_mm256_loadu_pd(&this->m_Im[i]),
			_mm256_loadu_pd(&this->m_Im[i]))));
#endif
	}
}

	









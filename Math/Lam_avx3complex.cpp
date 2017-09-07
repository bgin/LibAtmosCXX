
#include "LAM_avx3complex.h"
#include "../LAM_config.h"
#include "../LAM_common.h"
#include <zmmintrin.h>

//
// Implementation
//

lam::math::AVX512VComplex1D::
AVX512VComplex1D(_In_ const uint64_t nsize)
:
m_nsize{nsize},
m_Re(reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double),align64B))),
m_Im(reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double),align64B)))
{
	if (this->m_Re == NULL ||
		this->m_Im == NULL ||
		(this->m_nsize % 8) != 0ULL) {
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
										Memory allocation failure in: AVX512VComplex1D(uint64_t)\n";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
		std::exit(-1);
	}
	for (uint64_t i = 0ULL; i != this->m_nsize; i += 16ULL) {
#if LAM_CACHE_MEM_STORES == 1
		_mm512_storeu_pd(&this->m_Re[i],_mm512_setzero_pd());
		_mm512_storeu_pd(&this->m_Re[i+8ULL],_mm512_setzero_pd());
		_mm512_storeu_pd(&this->m_Im[i],_mm512_setzero_pd());
		_mm512_storeu_pd(&this->m_Im[i+8ULL], _mm512_setzero_pd());
#else
		_mm512_stream_pd(&this->m_Re[i],_mm512_setzero_pd());
		_mm512_stream_pd(&this->m_Re[i + 8ULL], _mm512_setzero_pd());
		_mm512_stream_pd(&this->m_Im[i], _mm512_setzero_pd());
		_mm512_stream_pd(&this->m_Im[i + 8ULL], _mm512_setzero_pd());
#endif
	}
	this->m_isbuilt = true;
}

lam::math::AVX512VComplex1D::
AVX512VComplex1D(_In_ const uint64_t nsize,
				 _In_ const double* __restrict Re,
				 _In_ const double* __restrict Im)
:
m_nsize{nsize},
m_Re(reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double),align64B))),
m_Im(reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double),align64B)))
{
	if (this->m_Re == NULL ||
		this->m_Im == NULL ||
		Re == NULL		   ||
		Im == NULL		   ||
		(this->m_nsize % 8ULL) != 0ULL) {
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
										Memory allocation failure in: AVX512VComplex1D(uint64_t,double*,double*)\n";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
		std::exit(-1);
	}
	for (uint64_t i = 0ULL; i != this->m_nsize; i += 16ULL) {
#if LAM_CACHE_MEM_STORES == 1
		_mm512_storeu_pd(&this->m_Re[i], _mm512_loadu_pd(&Re[i]));
		_mm512_storeu_pd(&this->m_Re[i+8ULL], _mm512_loadu_pd(&Re[i+8ULL]));
		_mm512_storeu_pd(&this->m_Im[i], _mm512_loadu_pd(&Im[i]));
		_mm512_storeu_pd(&this->m_Im[i + 8ULL], _mm512_loadu_pd(&Im[i+8ULL]));
#else
		_mm512_stream_pd(&this->m_Re[i], _mm512_loadu_pd(&Re[i]));
		_mm512_stream_pd(&this->m_Re[i + 8ULL], _mm512_loadu_pd(&Re[i + 8ULL]));
		_mm512_stream_pd(&this->m_Im[i], _mm512_loadu_pd(&Im[i]));
		_mm512_stream_pd(&this->m_Im[i + 8ULL], _mm512_loadu_pd(&Im[i + 8ULL]));
#endif
	}
	this->m_isbuilt = true;
}

lam::math::AVX512VComplex1D::
AVX512VComplex1D(_In_ const AVX512VComplex1D &x)
:
m_nsize{ x.get_nsize() },
m_Re(reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double),align64B))),
m_Im(reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double),align64B)))
{
	if (this->m_Re == NULL ||
		this->m_Im == NULL) {
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
								Memory allocation failure in: AVX512VComplex1D(AVX512VComplex &)\n";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
		std::exit(-1);
	}
	for (uint64_t i = 0ULL; i != this->m_nsize; i += 16ULL) {
#if LAM_CACHE_MEM_STORES == 1
		_mm512_storeu_pd(&this->m_Re[i], _mm512_loadu_pd(&x.getRe()[i]));
		_mm512_storeu_pd(&this->m_Re[i+8ULL], _mm512_loadu_pd(&x.getRe()[i+8ULL]));
		_mm512_storeu_pd(&this->m_Im[i], _mm512_loadu_pd(&x.getIm()[i]));
		_mm512_storeu_pd(&this->m_Im[i + 8ULL], _mm512_loadu_pd(&x.getRe()[i+8ULL]));
#else
		_mm512_stream_pd(&this->m_Re[i], _mm512_loadu_pd(&x.getRe()[i]));
		_mm512_stream_pd(&this->m_Re[i + 8ULL], _mm512_loadu_pd(&x.getRe()[i + 8ULL]));
		_mm512_stream_pd(&this->m_Im[i], _mm512_loadu_pd(&x.getIm()[i]));
		_mm512_stream_pd(&this->m_Im[i + 8ULL], _mm512_loadu_pd(&x.getRe()[i + 8ULL]));
#endif
	}
	this->m_isbuilt = x.get_isbuilt();
}

lam::math::AVX512VComplex1D::
AVX512VComplex1D(_In_ AVX512VComplex1D &&x)
:
m_nsize{ x.get_nsize() },
m_Re(NULL),
m_Im(NULL){

	this->m_Re = &x.getRe()[0];
	this->m_Im = &x.getIm()[0];
	this->m_isbuilt = true;
	x.m_nsize = 0ULL;
	x.m_Re = NULL;
	x.m_Im = NULL;
	x.m_isbuilt = false;
}

lam::math::AVX512VComplex1D::
~AVX512VComplex1D() {

	this->m_nsize = 0ULL;
	if (this->m_Re) {
		_mm_free(this->m_Re);
		this->m_Re = NULL;
	}
	if (this->m_Im) {
		_mm_free(this->m_Im);
		this->m_Im = NULL;
	}
}

lam::math::AVX512VComplex1D &
lam::math::AVX512VComplex1D::operator=(_In_ const AVX512VComplex1D &x) {
	if (this == &x ||
		!x.get_isbuilt()) {
		return (*this);
	}
	this->m_nsize = x.get_nsize();
	_mm_free(this->m_Re);
	_mm_free(this->m_Im);
	for (uint64_t i = 0ULL; i != this->m_nsize; i += 16ULL) {
#if LAM_CACHE_MEM_STORES == 1
		_mm512_storeu_pd(&this->m_Re[i], _mm512_loadu_pd(&x.getRe()[i]));
		_mm512_storeu_pd(&this->m_Re[i+8ULL], _mm512_loadu_pd(&x.getRe()[i+8ULL]));
		_mm512_storeu_pd(&this->m_Im[i], _mm512_loadu_pd(&x.getIm()[i]));
		_mm512_storeu_pd(&this->m_Im[i + 8ULL], _mm512_loadu_pd(&x.getIm()[i+8ULL]));
#else
		_mm512_stream_pd(&this->m_Re[i], _mm512_loadu_pd(&x.getRe()[i]));
		_mm512_stream_pd(&this->m_Re[i + 8ULL], _mm512_loadu_pd(&x.getRe()[i + 8ULL]));
		_mm512_stream_pd(&this->m_Im[i], _mm512_loadu_pd(&x.getIm()[i]));
		_mm512_stream_pd(&this->m_Im[i + 8ULL], _mm512_loadu_pd(&x.getIm()[i + 8ULL]));
#endif
	}
	this->m_isbuilt = x.get_isbuilt();
	return (*this);
}

lam::math::AVX512VComplex1D &
lam::math::AVX512VComplex1D::operator=(_In_ AVX512VComplex1D &&x) {
	if (this == &x ||
		!x.get_isbuilt()) {
		return (*this);
	}
	_mm_free(this->m_Re);
	_mm_free(this->m_Im);
	this->m_nsize = x.get_nsize();
	this->m_Re = &x.getRe()[0];
	this->m_Im = &x.getIm()[0];
	x.m_Re = 0ULL;
	x.m_Re = NULL;
	x.m_Im = NULL;
	x.m_isbuilt = false;
	return (*this);
}

lam::math::AVX512VComplex1D &
lam::math::AVX512VComplex1D::operator+=(_In_ const AVX512VComplex1D &x) {
#if LAM_DEBUG_ON == 1
	_ASSERTE(x.get_isbuilt() && 
		this->m_nsize == x.get_nsize());
#else
	if (!x.get_isbuilt() ||
		this->m_nsize != x.get_nsize()) {
		throw std::invalid_argument("AVX512VComplex1D::operator+= [loc:182]: Invalid argument(s)!!");
	}
#endif
	for (uint64_t i = 0ULL; i != this->m_nsize; i += 16ULL) {
#if LAM_MAN_PREFETCH == 1
		_mm_prefetch(reinterpret_cast<const char*>(&x.getRe()[i]),_MM_HINT_T0);
		_mm_prefetch(reinterpret_cast<const char*>(&x.getIm()[i]),_MM_HINT_T0);
#endif
#if LAM_CACHE_MEM_STORES == 1
		_mm512_storeu_pd(&this->m_Re[i], 
		_mm512_add_pd(_mm512_loadu_pd(&this->m_Re[i]),
	    _mm512_loadu_pd(&x.getRe()[i])));
		_mm512_storeu_pd(&this->m_Re[i+8ULL], 
		_mm512_add_pd(_mm512_loadu_pd(&this->m_Re[i+8ULL]),
		_mm512_loadu_pd(&x.getRe()[i+8ULL])));
		_mm512_storeu_pd(&this->m_Im[i],
		_mm512_add_pd(_mm512_loadu_pd(&this->m_Re[i]),
		_mm512_loadu_pd(&x.getIm()[i])));
		_mm512_storeu_pd(&this->m_Im[i + 8ULL], 
		_mm512_add_pd(_mm512_loadu_pd(&this->m_Im[i+8ULL]),
		_mm512_loadu_pd(&x.getIm()[i+8ULL])));
#else
		_mm512_stream_pd(&this->m_Re[i],
			_mm512_add_pd(_mm512_loadu_pd(&this->m_Re[i]),
			_mm512_loadu_pd(&x.getRe()[i])));
		_mm512_stream_pd(&this->m_Re[i + 8ULL],
			_mm512_add_pd(_mm512_loadu_pd(&this->m_Re[i + 8ULL]),
			_mm512_loadu_pd(&x.getRe()[i + 8ULL])));
		_mm512_stream_pd(&this->m_Im[i],
			_mm512_add_pd(_mm512_loadu_pd(&this->m_Re[i]),
			_mm512_loadu_pd(&x.getIm()[i])));
		_mm512_stream_pd(&this->m_Im[i + 8ULL],
			_mm512_add_pd(_mm512_loadu_pd(&this->m_Im[i + 8ULL]),
			_mm512_loadu_pd(&x.getIm()[i + 8ULL])));
#endif
	}
	return (*this);
}

lam::math::AVX512VComplex1D &
lam::math::AVX512VComplex1D::operator+=(_In_ const double* __restrict v) {
#if LAM_DEBUG_ON == 1
	_ASSERTE(v != NULL);
#else
	if (v == NULL) {
		throw std::invalid_argument("AVX512VComplex1D::operator+= [loc:224]: v == NULL!!");
	}
#endif
	for (uint64_t i = 0ULL; i != this->m_nsize; i += 16ULL) {
#if LAM_MAN_PREFETCH == 1
		_mm_prefetch(reinterpret_cast<const char*>(&v[i]),_MM_HINT_T0);
#endif
#if LAM_CACHE_MEM_STORES == 1
		_mm512_storeu_pd(&this->m_Re[i], 
		_mm512_add_pd(_mm512_loadu_pd(&this->m_Re[i]),
		_mm512_loadu_pd(&v[i])));
		_mm512_storeu_pd(&this->m_Re[i + 8ULL], 
		_mm512_add_pd(_mm512_loadu_pd(&this->m_Re[i+8ULL]),
		_mm512_loadu_pd(&v[i+8ULL])));
#else
		_mm512_stream_pd(&this->m_Re[i],
			_mm512_add_pd(_mm512_loadu_pd(&this->m_Re[i]),
			_mm512_loadu_pd(&v[i])));
		_mm512_stream_pd(&this->m_Re[i + 8ULL],
			_mm512_add_pd(_mm512_loadu_pd(&this->m_Re[i + 8ULL]),
			_mm512_loadu_pd(&v[i + 8ULL])));
#endif
	}
	return (*this);
}

lam::math::AVX512VComplex1D &
lam::math::AVX512VComplex1D::operator-=(_In_ const AVX512VComplex1D &x) {
#if LAM_DEBUG_ON == 1
	_ASSERTE(x.get_isbuilt() && 
		this->m_nsize == x.get_nsize());
#else
	if (!x.get_isbuilt() ||
		this->m_nsize != x.get_nsize()) {
		throw std::invalid_argument("AVX512VComplex1D::operator-= [loc:252]: Invalid argument(s)!!");
	}
#endif
	for (uint64_t i = 0ULL; i != this->m_nsize; i += 16ULL) {
#if LAM_MAN_PREFETCH == 1
		_mm_prefetch(reinterpret_cast<const char*>(&x.getRe()[i]), _MM_HINT_T0);
		_mm_prefetch(reinterpret_cast<const char*>(&x.getIm()[i]), _MM_HINT_T0);
#endif
#if LAM_CACHE_MEM_STORES == 1
		_mm512_storeu_pd(&this->m_Re[i], 
		_mm512_sub_pd(_mm512_loadu_pd(&this->m_Re[i]),
		_mm512_loadu_pd(&x.getRe()[i])));
		_mm512_storeu_pd(&this->m_Re[i + 8ULL], 
		_mm512_sub_pd(_mm512_loadu_pd(&this->m_Re[i+8ULL]),
		_mm512_loadu_pd(&x.getRe()[i+8ULL])));
		_mm512_storeu_pd(&this->m_Im[i], 
		_mm512_sub_pd(_mm512_loadu_pd(&this->m_Im[i]),
		_mm512_loadu_pd(&x.getIm()[i])));
		_mm512_storeu_pd(&this->m_Im[i + 8ULL], 
		_mm512_sub_pd(_mm512_loadu_pd(&this->m_Im[i+8ULL]),
		_mm512_loadu_pd(&x.getIm()[i + 8ULL])));
#else
		_mm512_stream_pd(&this->m_Re[i],
			_mm512_sub_pd(_mm512_loadu_pd(&this->m_Re[i]),
			_mm512_loadu_pd(&x.getRe()[i])));
		_mm512_stream_pd(&this->m_Re[i + 8ULL],
			_mm512_sub_pd(_mm512_loadu_pd(&this->m_Re[i + 8ULL]),
			_mm512_loadu_pd(&x.getRe()[i + 8ULL])));
		_mm512_stream_pd(&this->m_Im[i],
			_mm512_sub_pd(_mm512_loadu_pd(&this->m_Im[i]),
			_mm512_loadu_pd(&x.getIm()[i])));
		_mm512_stream_pd(&this->m_Im[i + 8ULL],
			_mm512_sub_pd(_mm512_loadu_pd(&this->m_Im[i + 8ULL]),
			_mm512_loadu_pd(&x.getIm()[i + 8ULL])));
#endif
	}
	return (*this);
}

lam::math::AVX512VComplex1D &
lam::math::AVX512VComplex1D::operator-=(_In_ const double* __restrict v) {
#if LAM_DEBUG_ON == 1
	_ASSERTE(v != NULL);
#else
	if(v == NULL)
		throw std::invalid_argument("AVX512VComplex1D::operator-= [loc:311] --> v == NULL!!");
#endif
	for (uint64_t i = 0ULL; i != this->m_nsize; i += 16ULL) {
#if LAM_MAN_PREFETCH == 1
		_mm_prefetch(reinterpret_cast<const char*>(&v[i+8]),_MM_HINT_T0);
#endif
#if LAM_CACHE_MEM_STORES == 1
		_mm512_storeu_pd(&this->m_Re[i], 
		_mm512_sub_pd(_mm512_loadu_pd(&this->m_Re[i]),
		_mm512_loadu_pd(&v[i])));
		_mm512_storeu_pd(&this->m_Re[i + 8ULL], 
		_mm512_sub_pd(_mm512_loadu_pd(&this->m_Re[i+8ULL]),
		_mm512_loadu_pd(&v[i+8ULL])));
#else
		_mm512_stream_pd(&this->m_Re[i],
			_mm512_sub_pd(_mm512_loadu_pd(&this->m_Re[i]),
			_mm512_loadu_pd(&v[i])));
		_mm512_stream_pd(&this->m_Re[i + 8ULL],
			_mm512_sub_pd(_mm512_loadu_pd(&this->m_Re[i + 8ULL]),
			_mm512_loadu_pd(&v[i + 8ULL])));
#endif
	}
	return (*this);
}

lam::math::AVX512VComplex1D &
lam::math::AVX512VComplex1D::operator*=(_In_ const AVX512VComplex1D &x) {
#if LAM_DEBUG_ON == 1
	_ASSERTE(x.get_isbuilt() && 
		this->m_nsize == x.get_nsize());
#else
	if (!x.get_isbuilt() ||
		this->m_nsize != x.get_nsize()) {
		throw std::invalid_argument("AVX512VComplex1D::operator*= [loc:343] --> Invalid argument(s)!!");
	}
#endif
	for (uint64_t i = 0ULL; i != this->m_nsize; i += 16ULL) {
#if LAM_MAN_PREFETCH == 1
		_mm_prefetch(reinterpret_cast<const char*>(&x.getRe()[i]),_MM_HINT_T0);
		_mm_prefetch(reinterpret_cast<const char*>(&x.getIm()[i]),_MM_HINT_T0);
#endif
#if LAM_CACHE_MEM_STORES == 1
		_mm512_storeu_pd(&this->m_Re[i], 
		_mm512_sub_pd(_mm512_mul_pd(_mm512_loadu_pd(&this->m_Re[i]),
		_mm512_loadu_pd(&x.getRe()[i])),_mm512_mul_pd(_mm512_loadu_pd(&this->m_Im[i]),
		_mm512_loadu_pd(&x.getIm()[i]))));
		_mm512_storeu_pd(&this->m_Re[i+8ULL],
		_mm512_sub_pd(_mm512_mul_pd(_mm512_loadu_pd(&this->m_Re[i+8ULL]),
		_mm512_loadu_pd(&x.getRe()[i+8ULL])), _mm512_mul_pd(_mm512_loadu_pd(&this->m_Im[i+8ULL]),
		_mm512_loadu_pd(&x.getIm()[i+8ULL]))));
		_mm512_storeu_pd(&this->m_Im[i], 
		_mm512_add_pd(_mm512_mul_pd(_mm512_loadu_pd(&this->m_Im[i]),
		_mm512_loadu_pd(&x.getRe()[i])), _mm512_mul_pd(_mm512_loadu_pd(&this->m_Re[i]),
		_mm512_loadu_pd(&x.getIm()[i]))));
		_mm512_storeu_pd(&this->m_Im[i+8ULL],
		_mm512_add_pd(_mm512_mul_pd(_mm512_loadu_pd(&this->m_Im[i+8ULL]),
		_mm512_loadu_pd(&x.getRe()[i+8ULL])), _mm512_mul_pd(_mm512_loadu_pd(&this->m_Re[i+8ULL]),
		_mm512_loadu_pd(&x.getIm()[i+8ULL]))));
#else
		_mm512_stream_pd(&this->m_Re[i],
			_mm512_sub_pd(_mm512_mul_pd(_mm512_loadu_pd(&this->m_Re[i]),
			_mm512_loadu_pd(&x.getRe()[i])), _mm512_mul_pd(_mm512_loadu_pd(&this->m_Im[i]),
			_mm512_loadu_pd(&x.getIm()[i]))));
		_mm512_stream_pd(&this->m_Re[i + 8ULL],
			_mm512_sub_pd(_mm512_mul_pd(_mm512_loadu_pd(&this->m_Re[i + 8ULL]),
			_mm512_loadu_pd(&x.getRe()[i + 8ULL])), _mm512_mul_pd(_mm512_loadu_pd(&this->m_Im[i + 8ULL]),
			_mm512_loadu_pd(&x.getIm()[i + 8ULL]))));
		_mm512_stream_pd(&this->m_Im[i],
			_mm512_add_pd(_mm512_mul_pd(_mm512_loadu_pd(&this->m_Im[i]),
			_mm512_loadu_pd(&x.getRe()[i])), _mm512_mul_pd(_mm512_loadu_pd(&this->m_Re[i]),
			_mm512_loadu_pd(&x.getIm()[i]))));
		_mm512_stream_pd(&this->m_Im[i + 8ULL],
			_mm512_add_pd(_mm512_mul_pd(_mm512_loadu_pd(&this->m_Im[i + 8ULL]),
			_mm512_loadu_pd(&x.getRe()[i + 8ULL])), _mm512_mul_pd(_mm512_loadu_pd(&this->m_Re[i + 8ULL]),
			_mm512_loadu_pd(&x.getIm()[i + 8ULL]))));
#endif
	}
	return (*this);
}

lam::math::AVX512VComplex1D &
lam::math::AVX512VComplex1D::operator*=(_In_ const double* __restrict v) {
#if LAM_DEBUG_ON == 1
	_ASSERTE(v != NULL);
#else
	if(v == NULL)
		throw std::invalid_argument("AVX512VComplex1D::operator*= [loc:397] --> v == NULL!!");
#endif
	for (uint64_t i = 0ULL; i != this->m_nsize; i += 16ULL) {
#if LAM_MAN_PREFETCH == 1
		_mm_prefetch(reinterpret_cast<const char*>(&v[i]),_MM_HINT_T0);
#endif	
#if LAM_CACHE_MEM_STORES == 1
		_mm512_storeu_pd(&this->m_Re[i+0ULL], 
		_mm512_mul_pd(_mm512_loadu_pd(&this->m_Re[i+0ULL]),
		_mm512_loadu_pd(&v[i+0ULL])));
		_mm512_storeu_pd(&this->m_Re[i + 8ULL], 
		_mm512_mul_pd(_mm512_loadu_pd(&this->m_Re[i+8ULL]),
		_mm512_loadu_pd(&v[i+8ULL])));
		_mm512_storeu_pd(&this->m_Im[i+0ULL], 
		_mm512_mul_pd(_mm512_loadu_pd(&this->m_Im[i+0ULL]),
		_mm512_loadu_pd(&v[i+0ULL])));
		_mm512_storeu_pd(&this->m_Im[i + 8ULL], 
		_mm512_mul_pd(_mm512_loadu_pd(&this->m_Im[i+8ULL]),
		_mm512_loadu_pd(&v[i+8ULL])));
#else
		_mm512_stream_pd(&this->m_Re[i + 0ULL],
			_mm512_mul_pd(_mm512_loadu_pd(&this->m_Re[i + 0ULL]),
			_mm512_loadu_pd(&v[i + 0ULL])));
		_mm512_stream_pd(&this->m_Re[i + 8ULL],
			_mm512_mul_pd(_mm512_loadu_pd(&this->m_Re[i + 8ULL]),
			_mm512_loadu_pd(&v[i + 8ULL])));
		_mm512_stream_pd(&this->m_Im[i + 0ULL],
			_mm512_mul_pd(_mm512_loadu_pd(&this->m_Im[i + 0ULL]),
			_mm512_loadu_pd(&v[i + 0ULL])));
		_mm512_stream_pd(&this->m_Im[i + 8ULL],
			_mm512_mul_pd(_mm512_loadu_pd(&this->m_Im[i + 8ULL]),
			_mm512_loadu_pd(&v[i + 8ULL])));
#endif	

	}
	return (*this);
}

lam::math::AVX512VComplex1D &
lam::math::AVX512VComplex1D::operator/=(_In_ const AVX512VComplex1D &x) {
#if LAM_DEBUG_ON == 1
	_ASSERTE(x.get_isbuilt() && 
		this->m_nsize == x.get_nsize());
#else
	if (!x.get_isbuilt() ||
		this->m_nsize != x.get_nsize()) {
		throw std::invalid_argument("AVX512VComplex1D::operator/= [loc:442] --> Invalid argument(s)!!");
	}
#endif
	// As for now using AVX to check for 0.0 values
	__m256d zmask1(_mm256_setzero_pd());
	__m256d zmask2(_mm256_setzero_pd());
	__m256i vres(_mm256_setr_epi64x(0LL, 0LL, 0LL, 0LL));
	const __m256d vzero(_mm256_set1_pd(0.0));
	for (uint64_t i = 0ULL; i != this->m_nsize; i += 4ULL) {

		zmask1 = _mm256_cmp_pd(vzero, _mm256_loadu_pd(&x.getRe()[i]), _CMP_EQ_OQ);
		zmask2 = _mm256_cmp_pd(vzero, _mm256_loadu_pd(&x.getIm()[i]), _CMP_EQ_OQ);
		if (_mm256_testc_pd(zmask1, _mm256_setzero_pd()) ||
			_mm256_testc_pd(zmask2, _mm256_setzero_pd())) {
			vres = _mm256_setr_epi64x(1LL, 1LL, 1LL, 1LL);
			break;
		}
	}
	if (vres.m256i_u64[0] == 1LL ||
		vres.m256i_u64[1] == 1LL ||
		vres.m256i_u64[2] == 1LL ||
		vres.m256i_u64[3] == 1LL) {
		throw std::domain_error("AVX512VComplex1D::operator/= [loc:462] --> found '0.0' in AVXVComplex1D!");
	}
	for (uint64_t i = 0ULL; i != this->m_nsize; i += 16ULL) {
#if LAM_CACHE_MEM_STORES == 1
		__m512d tre1 = _mm512_add_pd(_mm512_mul_pd(_mm512_loadu_pd(&this->m_Re[i+0ULL]),
			_mm512_loadu_pd(&x.getIm()[i+0ULL])),_mm512_mul_pd(_mm512_loadu_pd(&this->m_Im[i+0ULL]),
			_mm512_loadu_pd(&x.getIm()[i+0ULL])));
		__m512d tre2 = _mm512_add_pd(_mm512_mul_pd(_mm512_loadu_pd(&this->m_Re[i + 8ULL]),
			_mm512_loadu_pd(&x.getIm()[i + 8ULL])), _mm512_mul_pd(_mm512_loadu_pd(&this->m_Im[i + 8ULL]),
			_mm512_loadu_pd(&x.getIm()[i + 8ULL])));
		__m512d tim1 = _mm512_sub_pd(_mm512_mul_pd(_mm512_loadu_pd(&this->m_Im[i+0ULL]),
			_mm512_loadu_pd(&x.getIm()[i + 0ULL])), _mm512_mul_pd(_mm512_loadu_pd(&this->m_Re[i+0ULL]),
			_mm512_loadu_pd(&x.getIm()[i+0ULL])));
		__m512d tim2 = _mm512_sub_pd(_mm512_mul_pd(_mm512_loadu_pd(&this->m_Im[i + 8ULL]),
			_mm512_loadu_pd(&x.getIm()[i + 8ULL])), _mm512_mul_pd(_mm512_loadu_pd(&this->m_Re[i + 8ULL]),
			_mm512_loadu_pd(&x.getIm()[i + 8ULL])));
		__m512d den1 = _mm512_add_pd(_mm512_mul_pd(_mm512_loadu_pd(&x.getRe()[i+0ULL]),
			_mm512_loadu_pd(&x.getRe()[i + 0ULL])), _mm512_mul_pd(_mm512_loadu_pd(&x.getIm()[i+0ULL]),
			_mm512_loadu_pd(&x.getIm()[i+0ULL])));
		__m512d den2 = _mm512_add_pd(_mm512_mul_pd(_mm512_loadu_pd(&x.getRe()[i + 8ULL]),
			_mm512_loadu_pd(&x.getRe()[i + 8ULL])), _mm512_mul_pd(_mm512_loadu_pd(&x.getIm()[i + 8ULL]),
			_mm512_loadu_pd(&x.getIm()[i + 8ULL])));

		_mm512_storeu_pd(&this->m_Re[i + 0ULL], _mm512_div_pd(tre1,den1));
		_mm512_storeu_pd(&this->m_Re[i + 8ULL], _mm512_div_pd(tre2,den2));
		_mm512_storeu_pd(&this->m_Im[i + 0ULL], _mm512_div_pd(tim1,den1));
		_mm512_storeu_pd(&this->m_Im[i + 8ULL], _mm512_div_pd(tim2,den2));
#else
		__m512d tre1 = _mm512_add_pd(_mm512_mul_pd(_mm512_loadu_pd(&this->m_Re[i + 0ULL]),
			_mm512_loadu_pd(&x.getIm()[i + 0ULL])), _mm512_mul_pd(_mm512_loadu_pd(&this->m_Im[i + 0ULL]),
			_mm512_loadu_pd(&x.getIm()[i + 0ULL])));
		__m512d tre2 = _mm512_add_pd(_mm512_mul_pd(_mm512_loadu_pd(&this->m_Re[i + 8ULL]),
			_mm512_loadu_pd(&x.getIm()[i + 8ULL])), _mm512_mul_pd(_mm512_loadu_pd(&this->m_Im[i + 8ULL]),
			_mm512_loadu_pd(&x.getIm()[i + 8ULL])));
		__m512d tim1 = _mm512_sub_pd(_mm512_mul_pd(_mm512_loadu_pd(&this->m_Im[i + 0ULL]),
			_mm512_loadu_pd(&x.getIm()[i + 0ULL])), _mm512_mul_pd(_mm512_loadu_pd(&this->m_Re[i + 0ULL]),
			_mm512_loadu_pd(&x.getIm()[i + 0ULL])));
		__m512d tim2 = _mm512_sub_pd(_mm512_mul_pd(_mm512_loadu_pd(&this->m_Im[i + 8ULL]),
			_mm512_loadu_pd(&x.getIm()[i + 8ULL])), _mm512_mul_pd(_mm512_loadu_pd(&this->m_Re[i + 8ULL]),
			_mm512_loadu_pd(&x.getIm()[i + 8ULL])));
		__m512d den1 = _mm512_add_pd(_mm512_mul_pd(_mm512_loadu_pd(&x.getRe()[i + 0ULL]),
			_mm512_loadu_pd(&x.getRe()[i + 0ULL])), _mm512_mul_pd(_mm512_loadu_pd(&x.getIm()[i + 0ULL]),
			_mm512_loadu_pd(&x.getIm()[i + 0ULL])));
		__m512d den2 = _mm512_add_pd(_mm512_mul_pd(_mm512_loadu_pd(&x.getRe()[i + 8ULL]),
			_mm512_loadu_pd(&x.getRe()[i + 8ULL])), _mm512_mul_pd(_mm512_loadu_pd(&x.getIm()[i + 8ULL]),
			_mm512_loadu_pd(&x.getIm()[i + 8ULL])));

		_mm512_stream_pd(&this->m_Re[i + 0ULL], _mm512_div_pd(tre1, den1));
		_mm512_stream_pd(&this->m_Re[i + 8ULL], _mm512_div_pd(tre2, den2));
		_mm512_stream_pd(&this->m_Im[i + 0ULL], _mm512_div_pd(tim1, den1));
		_mm512_stream_pd(&this->m_Im[i + 8ULL], _mm512_div_pd(tim2, den2));
#endif
	}
	return (*this);
}

lam::math::AVX512VComplex1D &
lam::math::AVX512VComplex1D::operator/=(_In_ const double* __restrict v) {
#if LAM_DEBUG_ON == 1
	_ASSERTE(v != NULL);
#else
	if(v == NULL)
		throw std::invalid_argument("AVX512VComplex1D::operator/= [loc:527] --> v == NULL!!");
#endif
	__m256d zmask1(_mm256_setzero_pd());

	__m256i vres(_mm256_setr_epi64x(0LL, 0LL, 0LL, 0LL));
	const __m256d vzero(_mm256_set1_pd(0.0));
	for (uint64_t i = 0ULL; i != this->m_nsize; i += 4ULL) {
#if LAM_MAN_PREFETCH == 1
		_mm_prefetch(reinterpret_cast<const char*>(&v[i]), _MM_HINT_T0);
#endif
		zmask1 = _mm256_cmp_pd(vzero, _mm256_loadu_pd(&v[i]), _CMP_EQ_OQ);
		if (_mm256_testc_pd(zmask1, _mm256_setzero_pd())) {
			vres = _mm256_setr_epi64x(1LL, 1LL, 1LL, 1LL);
			break;
		}
	}
	if (vres.m256i_u64[0] == 1LL ||
		vres.m256i_u64[1] == 1LL ||
		vres.m256i_u64[2] == 1LL ||
		vres.m256i_u64[3] == 1LL) {
		throw std::domain_error("AVX512VComplex1D::operator/= [loc:544] --> found '0.0' in double* v !");
	}
	for (uint64_t i = 0ULL; i != this->m_nsize; i += 16ULL) {
#if LAM_CACHE_MEM_STORES == 1
		_mm512_storeu_pd(&this->m_Re[i + 0ULL], 
		_mm512_div_pd(_mm512_loadu_pd(&this->m_Re[i+0ULL]),
		_mm512_loadu_pd(&v[i+0ULL])));
		_mm512_storeu_pd(&this->m_Im[i + 8ULL], 
		_mm512_div_pd(_mm512_loadu_pd(&this->m_Re[i+8ULL]),
		_mm512_loadu_pd(&v[i+8ULL])));
		_mm512_storeu_pd(&this->m_Im[i + 0ULL], 
		_mm512_div_pd(_mm512_loadu_pd(&this->m_Im[i+0ULL]),
		_mm512_loadu_pd(&v[i+0ULL])));
		_mm512_storeu_pd(&this->m_Im[i + 8ULL], 
		_mm512_div_pd(_mm512_loadu_pd(&this->m_Im[i+8ULL]),
		_mm512_loadu_pd(&v[i+8ULL])));
#else
		_mm512_stream_pd(&this->m_Re[i + 0ULL],
			_mm512_div_pd(_mm512_loadu_pd(&this->m_Re[i + 0ULL]),
			_mm512_loadu_pd(&v[i + 0ULL])));
		_mm512_stream_pd(&this->m_Im[i + 8ULL],
			_mm512_div_pd(_mm512_loadu_pd(&this->m_Re[i + 8ULL]),
			_mm512_loadu_pd(&v[i + 8ULL])));
		_mm512_stream_pd(&this->m_Im[i + 0ULL],
			_mm512_div_pd(_mm512_loadu_pd(&this->m_Im[i + 0ULL]),
			_mm512_loadu_pd(&v[i + 0ULL])));
		_mm512_stream_pd(&this->m_Im[i + 8ULL],
			_mm512_div_pd(_mm512_loadu_pd(&this->m_Im[i + 8ULL]),
			_mm512_loadu_pd(&v[i + 8ULL])));
#endif
	}
	return (*this);
}

std::pair<double*,double*>
lam::math::AVX512VComplex1D::operator==(_In_ const AVX512VComplex1D &x) {
#if LAM_DEBUG_ON == 1
	_ASSERTE(x.get_isbuilt() &&
		this->m_nsize == x.get_nsize());
#else
	if (!x.get_isbuilt() ||
		this->m_nsize != x.get_nsize()) {
		throw std::invalid_argument("AVXVComplex1D::operator== [loc:588] --> Invalid argument(s)!!");
	}
#endif
	double* __restrict pr1 = 
	reinterpret_cast<double*>(_mm_malloc(this->m_nsize*sizeof(double),align64B));
	double* __restrict pr2 = 
	reinterpret_cast<double*>(_mm_malloc(this->m_nsize*sizeof(double),align64B));
	std::pair<double*,double*> pret;
	if (pr1 == NULL || pr2 == NULL) {
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
										Memory allocation failure in: AVX512VComplex1D::operator==\n";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
		std::exit(-1);
	}
	
	lam::common::init_varray(pr1,this->m_nsize,-1.0);
	lam::common::init_varray(pr2,this->m_nsize,-1.0);
	for (uint64_t i = 0ULL; i != this->m_nsize; i += 8ULL) {
#if LAM_CACHE_MEM_STORES == 1
		// Using AVX for comparison.
		// Unrolled 2x in order to match perfectly
		// per core 2 load operations per cycle.
		_mm256_storeu_pd(&pret.first[i+0ULL], 
		_mm256_cmp_pd(_mm256_loadu_pd(&this->m_Re[i+0ULL]),
		_mm256_loadu_pd(&x.getRe()[i+0ULL]),_CMP_EQ_OQ));
		_mm256_storeu_pd(&pret.first[i+4ULL],
		_mm256_cmp_pd(_mm256_loadu_pd(&this->m_Re[i + 4ULL]),
		_mm256_loadu_pd(&x.getRe()[i + 4ULL]), _CMP_EQ_OQ));
		_mm256_storeu_pd(&pret.second[i + 0ULL], 
		_mm256_cmp_pd(_mm256_loadu_pd(&this->m_Im[i+0ULL]),
		_mm256_loadu_pd(&x.getIm()[i+0ULL]),_CMP_EQ_OQ));
		_mm256_storeu_pd(&pret.second[i + 4ULL],
		_mm256_cmp_pd(_mm256_loadu_pd(&this->m_Im[i + 4ULL]),
		_mm256_loadu_pd(&x.getIm()[i + 4ULL]), _CMP_EQ_OQ));
#else
		// Stream version in order to not pollute the cache
		// on store operation.
		_mm256_stream_pd(&pret.first[i + 0ULL],
			_mm256_cmp_pd(_mm256_loadu_pd(&this->m_Re[i + 0ULL]),
			_mm256_loadu_pd(&x.getRe()[i + 0ULL]), _CMP_EQ_OQ));
		_mm256_stream_pd(&pret.first[i + 4ULL],
			_mm256_cmp_pd(_mm256_loadu_pd(&this->m_Re[i + 4ULL]),
			_mm256_loadu_pd(&x.getRe()[i + 4ULL]), _CMP_EQ_OQ));
		_mm256_stream_pd(&pret.second[i + 0ULL],
			_mm256_cmp_pd(_mm256_loadu_pd(&this->m_Im[i + 0ULL]),
			_mm256_loadu_pd(&x.getIm()[i + 0ULL]), _CMP_EQ_OQ));
		_mm256_stream_pd(&pret.second[i + 4ULL],
			_mm256_cmp_pd(_mm256_loadu_pd(&this->m_Im[i + 4ULL]),
			_mm256_loadu_pd(&x.getIm()[i + 4ULL]), _CMP_EQ_OQ));
#endif
	}
	return (pret);
}

std::pair<double*,double*>
lam::math::AVX512VComplex1D::operator!=(_In_ const AVX512VComplex1D &x) {
#if LAM_DEBUG_ON == 1
	_ASSERTE(x.get_isbuilt() &&
		this->m_nsize == x.get_nsize());
#else
	if (!x.get_isbuilt() ||
		this->m_nsize != x.get_nsize()) {
		throw std::invalid_argument("AVXVComplex1D::operator!= [loc:651] --> Invalid argument(s)!!");
	}
#endif
	double* __restrict pr1 =
		reinterpret_cast<double*>(_mm_malloc(this->m_nsize*sizeof(double), align64B));
	double* __restrict pr2 =
		reinterpret_cast<double*>(_mm_malloc(this->m_nsize*sizeof(double), align64B));
	std::pair<double*, double*> pret;
	if (pr1 == NULL || pr2 == NULL) {
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
									Memory allocation failure in: AVX512VComplex1D::operator!=\n";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
		std::exit(-1);
	}

	lam::common::init_varray(pr1, this->m_nsize, -1.0);
	lam::common::init_varray(pr2, this->m_nsize, -1.0);
	for (uint64_t i = 0ULL; i != this->m_nsize; i += 8ULL) {
#if LAM_CACHE_MEM_STORES == 1
		// Using AVX for comparison.
		// Unrolled 2x in order to match perfectly
		// per core 2 load operations per cycle.
		_mm256_storeu_pd(&pret.first[i + 0ULL],
			_mm256_cmp_pd(_mm256_loadu_pd(&this->m_Re[i + 0ULL]),
			_mm256_loadu_pd(&x.getRe()[i + 0ULL]), _CMP_NEQ_OQ));
		_mm256_storeu_pd(&pret.first[i + 4ULL],
			_mm256_cmp_pd(_mm256_loadu_pd(&this->m_Re[i + 4ULL]),
			_mm256_loadu_pd(&x.getRe()[i + 4ULL]), _CMP_NEQ_OQ));
		_mm256_storeu_pd(&pret.second[i + 0ULL],
			_mm256_cmp_pd(_mm256_loadu_pd(&this->m_Im[i + 0ULL]),
			_mm256_loadu_pd(&x.getIm()[i + 0ULL]), _CMP_NEQ_OQ));
		_mm256_storeu_pd(&pret.second[i + 4ULL],
			_mm256_cmp_pd(_mm256_loadu_pd(&this->m_Im[i + 4ULL]),
			_mm256_loadu_pd(&x.getIm()[i + 4ULL]), _CMP_NEQ_OQ));
#else
		// Stream version in order to not pollute the cache
		// on store operation.
		_mm256_stream_pd(&pret.first[i + 0ULL],
			_mm256_cmp_pd(_mm256_loadu_pd(&this->m_Re[i + 0ULL]),
			_mm256_loadu_pd(&x.getRe()[i + 0ULL]), _CMP_NEQ_OQ));
		_mm256_stream_pd(&pret.first[i + 4ULL],
			_mm256_cmp_pd(_mm256_loadu_pd(&this->m_Re[i + 4ULL]),
			_mm256_loadu_pd(&x.getRe()[i + 4ULL]), _CMP_NEQ_OQ));
		_mm256_stream_pd(&pret.second[i + 0ULL],
			_mm256_cmp_pd(_mm256_loadu_pd(&this->m_Im[i + 0ULL]),
			_mm256_loadu_pd(&x.getIm()[i + 0ULL]), _CMP_NEQ_OQ));
		_mm256_stream_pd(&pret.second[i + 4ULL],
			_mm256_cmp_pd(_mm256_loadu_pd(&this->m_Im[i + 4ULL]),
			_mm256_loadu_pd(&x.getIm()[i + 4ULL]), _CMP_NEQ_OQ));
#endif
	}
	return (pret);
}

std::ostream &
lam::math::operator<<(_In_ std::ostream &os, _In_ const AVX512VComplex1D &x) {
#if LAM_DEBUG_ON == 1
	_ASSERTE(x.get_isbuilt());
#else
	if (!x.get_isbuilt())
		throw std::invalid_argument("lam::math::operator<< [loc:709] --> AVX512VComplex1D in invalid state!!");
#endif
	for (uint64_t i = 0ULL; i != x.get_nsize(); ++i) {
		os << std::fixed << std::showpoint << std::setprecision(15) << 
		std::setw(4)  << "Re: " << x.getRe()[i] <<
		std::setw(12) << "Im: " << x.getIm()[i] << std::endl;
	}
	return (os);
}

lam::math::AVX512VComplex1D &
lam::math::AVX512VComplex1D::vcnormalize(_In_ const AVX512VComplex1D &x) {
#if LAM_DEBUG_ON == 1
	_ASSERTE(x.get_isbuilt() &&
		this->m_nsize == x.get_nsize());
#else
	if (!x.get_isbuilt() ||
		this->m_nsize != x.get_nsize()) {
		throw std::invalid_argument("AVX512VComplex1D::vconrmalize [loc:729] --> AVX512VComplex1D in invalid state!!");
	}
#endif
	for (uint64_t i = 0ULL; i != this->m_nsize; i += 16ULL) {
#if LAM_CACHE_MEM_STORES == 1
		_mm512_storeu_pd(&this->m_Re[i + 0ULL], _mm512_sub_pd(_mm512_mul_pd(_mm512_loadu_pd(&this->m_Re[i+0ULL]),
			_mm512_loadu_pd(&x.getRe()[i+0ULL])),_mm512_mul_pd(_mm512_loadu_pd(&this->m_Im[i+0ULL]),
			_mm512_loadu_pd(&x.getIm()[i+0ULL]))));
		_mm512_storeu_pd(&this->m_Re[i + 8ULL], _mm512_sub_pd(_mm512_mul_pd(_mm512_loadu_pd(&this->m_Re[i + 8ULL]),
			_mm512_loadu_pd(&x.getRe()[i + 8ULL])), _mm512_mul_pd(_mm512_loadu_pd(&this->m_Im[i + 8ULL]),
			_mm512_loadu_pd(&x.getIm()[i + 8ULL]))));

		_mm512_storeu_pd(&this->m_Im[i + 0ULL], _mm512_add_pd(_mm512_mul_pd(_mm512_loadu_pd(&this->m_Im[i+0ULL]),
			_mm512_loadu_pd(&x.getRe()[i + 0ULL])), _mm512_mul_pd(_mm512_loadu_pd(&this->m_Re[i+0ULL]),
			_mm512_loadu_pd(&x.getIm()[i+0ULL]))));
		_mm512_storeu_pd(&this->m_Im[i + 8ULL], _mm512_add_pd(_mm512_mul_pd(_mm512_loadu_pd(&this->m_Im[i + 8ULL]),
			_mm512_loadu_pd(&x.getRe()[i + 8ULL])), _mm512_mul_pd(_mm512_loadu_pd(&this->m_Re[i + 8ULL]),
			_mm512_loadu_pd(&x.getIm()[i + 8ULL]))));

		__m512d cmag1 = _mm512_sqrt_pd(_mm512_add_pd(_mm512_mul_pd(_mm512_loadu_pd(&this->m_Re[i+0ULL]),
			_mm512_loadu_pd(&this->m_Re[i + 0ULL])), _mm512_mul_pd(_mm512_loadu_pd(&this->m_Im[i+0ULL]),
			_mm512_loadu_pd(&this->m_Im[i+0ULL]))));
		__m512d cmag2 = _mm512_sqrt_pd(_mm512_add_pd(_mm512_mul_pd(_mm512_loadu_pd(&this->m_Re[i + 8ULL]),
			_mm512_loadu_pd(&this->m_Re[i + 8ULL])), _mm512_mul_pd(_mm512_loadu_pd(&this->m_Im[i + 8ULL]),
			_mm512_loadu_pd(&this->m_Im[i + 8ULL]))));

		_mm512_storeu_pd(&this->m_Re[i + 0ULL], _mm512_div_pd(_mm512_loadu_pd(&this->m_Re[i+0ULL]),cmag1));
		_mm512_storeu_pd(&this->m_Re[i + 8ULL], _mm512_div_pd(_mm512_loadu_pd(&this->m_Re[i+8ULL]),cmag2));
		_mm512_storeu_pd(&this->m_Im[i + 0ULL], _mm512_div_pd(_mm512_loadu_pd(&this->m_Im[i+0ULL]),cmag1));
		_mm512_storeu_pd(&this->m_Im[i + 8ULL], _mm512_div_pd(_mm512_loadu_pd(&this->m_Im[i+8ULL]),cmag2));
#else
		_mm512_stream_pd(&this->m_Re[i + 0ULL], _mm512_sub_pd(_mm512_mul_pd(_mm512_loadu_pd(&this->m_Re[i + 0ULL]),
			_mm512_loadu_pd(&x.getRe()[i + 0ULL])), _mm512_mul_pd(_mm512_loadu_pd(&this->m_Im[i + 0ULL]),
			_mm512_loadu_pd(&x.getIm()[i + 0ULL]))));
		_mm512_stream_pd(&this->m_Re[i + 8ULL], _mm512_sub_pd(_mm512_mul_pd(_mm512_loadu_pd(&this->m_Re[i + 8ULL]),
			_mm512_loadu_pd(&x.getRe()[i + 8ULL])), _mm512_mul_pd(_mm512_loadu_pd(&this->m_Im[i + 8ULL]),
			_mm512_loadu_pd(&x.getIm()[i + 8ULL]))));

		_mm512_stream_pd(&this->m_Im[i + 0ULL], _mm512_add_pd(_mm512_mul_pd(_mm512_loadu_pd(&this->m_Im[i + 0ULL]),
			_mm512_loadu_pd(&x.getRe()[i + 0ULL])), _mm512_mul_pd(_mm512_loadu_pd(&this->m_Re[i + 0ULL]),
			_mm512_loadu_pd(&x.getIm()[i + 0ULL]))));
		_mm512_stream_pd(&this->m_Im[i + 8ULL], _mm512_add_pd(_mm512_mul_pd(_mm512_loadu_pd(&this->m_Im[i + 8ULL]),
			_mm512_loadu_pd(&x.getRe()[i + 8ULL])), _mm512_mul_pd(_mm512_loadu_pd(&this->m_Re[i + 8ULL]),
			_mm512_loadu_pd(&x.getIm()[i + 8ULL]))));

		__m512d cmag1 = _mm512_sqrt_pd(_mm512_add_pd(_mm512_mul_pd(_mm512_loadu_pd(&this->m_Re[i + 0ULL]),
			_mm512_loadu_pd(&this->m_Re[i + 0ULL])), _mm512_mul_pd(_mm512_loadu_pd(&this->m_Im[i + 0ULL]),
			_mm512_loadu_pd(&this->m_Im[i + 0ULL]))));
		__m512d cmag2 = _mm512_sqrt_pd(_mm512_add_pd(_mm512_mul_pd(_mm512_loadu_pd(&this->m_Re[i + 8ULL]),
			_mm512_loadu_pd(&this->m_Re[i + 8ULL])), _mm512_mul_pd(_mm512_loadu_pd(&this->m_Im[i + 8ULL]),
			_mm512_loadu_pd(&this->m_Im[i + 8ULL]))));

		_mm512_stream_pd(&this->m_Re[i + 0ULL], _mm512_div_pd(_mm512_loadu_pd(&this->m_Re[i + 0ULL]), cmag1));
		_mm512_stream_pd(&this->m_Re[i + 8ULL], _mm512_div_pd(_mm512_loadu_pd(&this->m_Re[i + 8ULL]), cmag2));
		_mm512_stream_pd(&this->m_Im[i + 0ULL], _mm512_div_pd(_mm512_loadu_pd(&this->m_Im[i + 0ULL]), cmag1));
		_mm512_stream_pd(&this->m_Im[i + 8ULL], _mm512_div_pd(_mm512_loadu_pd(&this->m_Im[i + 8ULL]), cmag2));
#endif
	}
	return (*this);
}

std::complex<double>
lam::math::AVX512VComplex1D::vcmean(_In_ const AVX512VComplex1D &x) {
#if LAM_DEBUG_ON == 1
	_ASSERTE(x.get_isbuilt() &&
		this->m_nsize == x.get_nsize());
#else
	if (!x.get_isbuilt() ||
		this->m_nsize != x.get_nsize()) {
		throw std::invalid_argument("AVX512VComplex1D::vcmean [loc:798] --> AVX512VComplex1D in invalid state!!");
	}
#endif
	const uint64_t vlen = this->m_nsize;
	double sre{}, sim{}, acc1{}, acc2{},
		sre2{}, sim2{}, acc3{}, acc4{};
	
	for (uint64_t i = 0ULL; i != this->m_nsize; i += 16) {
#if LAM_CACHE_MEM_STORES == 1
		_mm512_storeu_pd(&this->m_Re[i+0ULL], _mm512_add_pd(_mm512_loadu_pd(&this->m_Re[i+0ULL]),
			_mm512_loadu_pd(&x.getRe()[i+0ULL])));
		_mm512_storeu_pd(&this->m_Re[i+8ULL], _mm512_add_pd(_mm512_loadu_pd(&this->m_Re[i+8ULL]),
			_mm512_loadu_pd(&x.getRe()[i + 8ULL])));
		_mm512_storeu_pd(&this->m_Im[i+0ULL], _mm512_add_pd(_mm512_loadu_pd(&this->m_Im[i+0ULL]),
			_mm512_loadu_pd(&x.getIm()[i+0ULL])));
		_mm512_storeu_pd(&this->m_Im[i+8ULL], _mm512_add_pd(_mm512_loadu_pd(&this->m_Im[i+8ULL]),
			_mm512_loadu_pd(&x.getIm()[i+8ULL])));
#else
		_mm512_stream_pd(&this->m_Re[i + 0ULL], _mm512_add_pd(_mm512_loadu_pd(&this->m_Re[i + 0ULL]),
			_mm512_loadu_pd(&x.getRe()[i + 0ULL])));
		_mm512_stream_pd(&this->m_Re[i + 8ULL], _mm512_add_pd(_mm512_loadu_pd(&this->m_Re[i + 8ULL]),
			_mm512_loadu_pd(&x.getRe()[i + 8ULL])));
		_mm512_stream_pd(&this->m_Im[i + 0ULL], _mm512_add_pd(_mm512_loadu_pd(&this->m_Im[i + 0ULL]),
			_mm512_loadu_pd(&x.getIm()[i + 0ULL])));
		_mm512_stream_pd(&this->m_Im[i + 8ULL], _mm512_add_pd(_mm512_loadu_pd(&this->m_Im[i + 8ULL]),
			_mm512_loadu_pd(&x.getIm()[i + 8ULL])));
#endif
	}
	for (uint64_t i = 0ULL; i != this->m_nsize; i += 16ULL) {
		sre = _mm512_reduce_add_pd(_mm512_loadu_pd(&this->m_Re[i+0ULL]));
		acc1 += sre;
		sre2 = _mm512_reduce_add_pd(_mm512_loadu_pd(&this->m_Re[i+8ULL]));
		acc2 += sre2;
		sim = _mm512_reduce_add_pd(_mm512_loadu_pd(&this->m_Im[i+0ULL]));
		acc3 += sim;
		sim2 = _mm512_reduce_add_pd(_mm512_loadu_pd(&this->m_Im[i+8ULL]));
		acc4 += sim2;
	}
	acc2 += acc1;
	acc4 += acc3;
	return(std::complex<double>(acc2/vlen,acc3/vlen));
}

void
lam::math::AVX512VComplex1D::vcmag(_Inout_ double* __restrict mag,
								   _In_ const uint64_t size) {
#if LAM_DEBUG_ON == 1
	_ASSERTE(mag != NULL &&
		this->m_nsize == size);
#else
	if (mag == NULL ||
		this->m_nsize != size) {
		throw std::invalid_argument("AVX512VComplex1D::vcmag [loc:850] --> Invalid argument or null pointer!!");
	}
#endif
	for (uint64_t i = 0ULL; i != this->m_nsize; i += 16ULL) {
#if LAM_CACHE_MEM_STORES == 1
		_mm512_storeu_pd(&mag[i + 0ULL], _mm512_sqrt_pd(_mm512_add_pd(_mm512_mul_pd(_mm512_loadu_pd(&this->m_Re[i+0ULL]),
			_mm512_loadu_pd(&this->m_Re[i+0ULL])),_mm512_mul_pd(_mm512_loadu_pd(&this->m_Im[i+0ULL]),
			_mm512_loadu_pd(&this->m_Im[i+0ULL])))));
		_mm512_storeu_pd(&mag[i + 8ULL], _mm512_sqrt_pd(_mm512_add_pd(_mm512_mul_pd(_mm512_loadu_pd(&this->m_Re[i + 8ULL]),
			_mm512_loadu_pd(&this->m_Re[i + 8ULL])), _mm512_mul_pd(_mm512_loadu_pd(&this->m_Im[i + 8ULL]),
			_mm512_loadu_pd(&this->m_Im[i + 8ULL])))));
#else
		_mm512_stream_pd(&mag[i + 0ULL], _mm512_sqrt_pd(_mm512_add_pd(_mm512_mul_pd(_mm512_loadu_pd(&this->m_Re[i+0ULL]),
			_mm512_loadu_pd(&this->m_Re[i + 0ULL])), _mm512_mul_pd(_mm512_loadu_pd(&this->m_Im[i + 0ULL]),
			_mm512_loadu_pd(&this->m_Im[i + 0ULL])))));
		_mm512_stream_pd(&mag[i + 8ULL], _mm512_sqrt_pd(_mm512_add_pd(_mm512_mul_pd(_mm512_loadu_pd(&this->m_Re[i + 8ULL]),
			_mm512_loadu_pd(&this->m_Re[i + 8ULL])), _mm512_mul_pd(_mm512_loadu_pd(&this->m_Im[i + 8ULL]),
			_mm512_loadu_pd(&this->m_Im[i + 8ULL])))));
#endif
	}
}

void
lam::math::AVX512VComplex1D::vcdeg(_Inout_ double* __restrict vdeg,
								   _In_ const uint64_t size) {
#if LAM_DEBUG_ON == 1
	_ASSERTE(vdeg != NULL &&
		this->m_nsize == size);
#else
	if (vdeg == NULL ||
		this->m_nsize != size) {
		throw std::invalid_argument("AVX512VComplex1D::vcdeg [loc:881] --> Invalid argument or null pointer!!");
	}
#endif
	for (uint64_t i = 0ULL; i != this->m_nsize; i += 16ULL) {
#if LAM_CACHE_MEM_STORES == 1
		_mm512_storeu_pd(&vdeg[i + 0ULL],
		_mm512_mul_pd(lam::common::vrad8_to_deg, _mm512_atan2_pd(_mm512_loadu_pd(&this->m_Re[i+0ULL]),
		_mm512_loadu_pd(&this->m_Im[i+0ULL]))));
		_mm512_storeu_pd(&vdeg[i + 8ULL],
		_mm512_mul_pd(lam::common::vrad8_to_deg, _mm512_atan2_pd(_mm512_loadu_pd(&this->m_Re[i + 8ULL]),
		_mm512_loadu_pd(&this->m_Im[i + 8ULL]))));
#else
		_mm512_stream_pd(&vdeg[i + 0ULL],
			_mm512_mul_pd(lam::common::vrad8_to_deg, _mm512_atan2_pd(_mm512_loadu_pd(&this->m_Re[i + 0ULL]),
			_mm512_loadu_pd(&this->m_Im[i + 0ULL]))));
		_mm512_stream_pd(&vdeg[i + 8ULL],
			_mm512_mul_pd(lam::common::vrad8_to_deg, _mm512_atan2_pd(_mm512_loadu_pd(&this->m_Re[i + 8ULL]),
			_mm512_loadu_pd(&this->m_Im[i + 8ULL]))));
#endif
	}
}

void
lam::math::AVX512VComplex1D::vcrad(_Inout_ double* __restrict vrad,
							      _In_ const uint64_t size) {
#if LAM_DEBUG_ON == 1
	_ASSERTE(vrad != NULL &&
		this->m_nsize == size);
#else
	if (vrad == NULL ||
		this->m_nsize != size) {
		throw std::invalid_argument("AVX512VComplex1D::vcrad [loc:912] --> Invalid argument or null pointer!!");
	}
#endif
	// Not checking for 0.0 values in *this
	for (uint64_t i = 0ULL; i != this->m_nsize; i += 16ULL) {
#if LAM_CACHE_MEM_STORES == 1
		_mm512_storeu_pd(&vrad[i + 0ULL], 
		_mm512_atan2_pd(_mm512_loadu_pd(&this->m_Re[i+0ULL]),
		_mm512_loadu_pd(&this->m_Im[i+0ULL])));
		_mm512_storeu_pd(&vrad[i + 8ULL],
		_mm512_atan2_pd(_mm512_loadu_pd(&this->m_Re[i + 8ULL]),
		_mm512_loadu_pd(&this->m_Im[i + 8ULL])));
#else
		_mm512_stream_pd(&vrad[i + 0ULL],
			_mm512_atan2_pd(_mm512_loadu_pd(&this->m_Re[i + 0ULL]),
			_mm512_loadu_pd(&this->m_Im[i + 0ULL])));
		_mm512_stream_pd(&vrad[i + 8ULL],
			_mm512_atan2_pd(_mm512_loadu_pd(&this->m_Re[i + 8ULL]),
			_mm512_loadu_pd(&this->m_Im[i + 8ULL])));
#endif
	}
}

void
lam::math::AVX512VComplex1D::vcpow(_Inout_ double* __restrict vpow,
								   _In_ const uint64_t size) {
#if LAM_DEBUG_ON == 1
	_ASSERTE(vpow != NULL &&
		this->m_nsize == size);
#else
	if (vpow == NULL ||
		this->m_nsize != size) {
		throw std::invalid_argument("AVX512VComplex1D::vcpow [loc:944] --> Invalid argument or null pointer!!");
	}
#endif
	for (uint64_t i = 0ULL; i != this->m_nsize; i += 16ULL) {
#if LAM_CACHE_MEM_STORES == 1
		_mm512_storeu_pd(&vpow[i + 0ULL],
		   _mm512_add_pd(_mm512_mul_pd(_mm512_loadu_pd(&this->m_Re[i+0ULL]),
		   _mm512_loadu_pd(&this->m_Re[i+0ULL])),_mm512_mul_pd(_mm512_loadu_pd(&this->m_Im[i+0ULL]),
		   _mm512_loadu_pd(&this->m_Im[i+0ULL]))));
		_mm512_storeu_pd(&vpow[i + 0ULL],
		   _mm512_add_pd(_mm512_mul_pd(_mm512_loadu_pd(&this->m_Re[i + 8ULL]),
		   _mm512_loadu_pd(&this->m_Re[i + 8ULL])), _mm512_mul_pd(_mm512_loadu_pd(&this->m_Im[i + 8ULL]),
		   _mm512_loadu_pd(&this->m_Im[i + 8ULL]))));
#else
		_mm512_stream_pd(&vpow[i + 0ULL],
			_mm512_add_pd(_mm512_mul_pd(_mm512_loadu_pd(&this->m_Re[i + 0ULL]),
			_mm512_loadu_pd(&this->m_Re[i + 0ULL])), _mm512_mul_pd(_mm512_loadu_pd(&this->m_Im[i + 0ULL]),
			_mm512_loadu_pd(&this->m_Im[i + 0ULL]))));
		_mm512_stream_pd(&vpow[i + 0ULL],
			_mm512_add_pd(_mm512_mul_pd(_mm512_loadu_pd(&this->m_Re[i + 8ULL]),
			_mm512_loadu_pd(&this->m_Re[i + 8ULL])), _mm512_mul_pd(_mm512_loadu_pd(&this->m_Im[i + 8ULL]),
			_mm512_loadu_pd(&this->m_Im[i + 8ULL]))));
#endif
	}
}






#include "LAM_avx3complex.h"

#include "../LAM_config.h"
#include "../LAM_common.h"
#include "../LAM_error_macros.h"
#include "../System/StackWalker.h"

#include <zmmintrin.h>

//
// Implementation
//

//
//	Parametrized macros
//

#if !defined (AVX3_COMPLEX_PREFETCH_FROM_OBJ)
#define AVX3_COMPLEX_PREFETCH_FROM_OBJ(obj,idx,off,hint) \
	_mm_prefetch(reinterpret_cast<const char*>(&(obj).m_Re[(idx)+(off)]),(hint)); \
	_mm_prefetch(reinterpret_cast<const char*>(&(obj).m_Im[(idx)+(off)]),(hint));
#endif

#if !defined (AVX3_COMPLEX_PREFETCH_FROM_PTR)
#define AVX3_COMPLEX_PREFETCH_FROM_PTR(ptr,idx,off,hint) \
	_mm_prefetch(reinterpret_cast<const char*>(&(ptr)[(idx)+(off)]),(hint));
#endif

#if !defined (AVX3_COMPLEX_CHECK_FATAL_ERROR)
#define AVX3_COMPLEX_CHECK_FATAL_ERROR(ptr1,ptr2,nsize,msg) \
	 do {													  \
		if ((NULL  == (ptr1) && (nsize) != 0ULL) ||        \
		     (NULL == (ptr2) && (nsize) != 0ULL) ) {      \
			    StackWalker sw{};						  \
			    sw.ShowCallstack();						  \
			    ABORT_ON_ERROR(msg,MALLOC_FAILED)		  \
	 }											          \
  } while (0);
#endif

#if !defined (AVX3_COMPLEX_ADDITION)
#define AVX3_COMPLEX_ADDITION(out,v1,v2,idx,off) \
	(out) = _mm512_add_pd(_mm512_mul_pd(_mm512_load_pd(&(v1).m_Re[(idx)+(off)]), \
	_mm512_load_pd(&(v2).m_Re[(idx)+(off)])), _mm512_mul_pd(_mm512_load_pd(&(v1).m_Im[(idx)+(off)]), \
	_mm512_load_pd(&(v2).m_Im[(idx)+(off)])));
#endif

#if !defined (AVX3_COMPLEX_SUBTRACTION)
#define AVX3_COMPLEX_SUBTRACTION(out,v1,v2,idx,off) \
	(out) = _mm512_sub_pd(_mm512_mul_pd(_mm512_load_pd(&(v1).m_Im[(idx)+(off)]), \
	_mm512_load_pd(&(v2).m_Re[(idx)+(off)])), _mm512_mul_pd(_mm512_load_pd(&(v1).m_Re[(idx)+(off)]), \
	_mm512_load_pd(&(v2).m_Im[(idx)+(off)])));
#endif

	// Warning macro parameter v2 must be an exact copy
	// of parameter v1. This should done by calling class (AVX512VComplex1D)
	// Move Constructor.
#if !defined (AVX3_COMPLEX_MAGNITUDE)
#define AVX3_COMPLEX_MAGNITUDE(out,v1,v2,idx,off) \
	(out) = _mm512_sqrt_pd(_mm512_add_pd(_mm512_mul_pd(_mm512_load_pd(&(v1).m_Re[(idx)+(off)]), \
	_mm512_load_pd(&(v2).m_Re[(idx)+(off)])), _mm512_mul_pd(_mm512_load_pd(&(v1).m_Im[(idx)+(off)]), \
	_mm512_load_pd(&(v2).m_Im[(idx)+(off)]))));
#endif


lam::math::AVX512VComplex1D::
AVX512VComplex1D()
:
m_nsize{0ULL},
m_Re{NULL},
m_Im{NULL} {}

lam::math::AVX512VComplex1D::
AVX512VComplex1D(_In_ const std::uint64_t nsize)
:
m_nsize{nsize},
m_Re(reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double),align64B))),
m_Im(reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double),align64B)))
{
	AVX3_COMPLEX_CHECK_FATAL_ERROR(m_Re, m_Im, m_nsize, "AVX512VComplex1D::AVX512VComplex1D(uint64_t) -- !!! Memory Allocation Failure !!!")
	std::uint64_t i;
	for ( i = 0ULL; i != ROUND_TO_EIGHT(m_nsize,8ULL); i += 16ULL) {
#if (LAM_CACHE_MEM_STORES) == 1
		_mm512_store_pd(&this->m_Re[i],_mm512_setzero_pd());
		_mm512_store_pd(&this->m_Re[i+8ULL],_mm512_setzero_pd());
		_mm512_store_pd(&this->m_Im[i],_mm512_setzero_pd());
		_mm512_store_pd(&this->m_Im[i+8ULL], _mm512_setzero_pd());
#else
		_mm512_stream_pd(&this->m_Re[i],_mm512_setzero_pd());
		_mm512_stream_pd(&this->m_Re[i + 8ULL], _mm512_setzero_pd());
		_mm512_stream_pd(&this->m_Im[i], _mm512_setzero_pd());
		_mm512_stream_pd(&this->m_Im[i + 8ULL], _mm512_setzero_pd());
#endif
	}
	for (; i != m_nsize; ++i) {
		this->m_Re[i] = 0.0;
		this->m_Im[i] = 0.0;
	}
}


lam::math::AVX512VComplex1D::
AVX512VComplex1D(_In_ const AVX512VComplex1D &x)
:
m_nsize{ x.m_nsize },
m_Re(reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double),align64B))),
m_Im(reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double),align64B)))
{
	AVX3_COMPLEX_CHECK_FATAL_ERROR(m_Re, m_Im, m_nsize, "AVX512VComplex1D(AVX512VComplex1D &) -- !!! Memory Allocation Failure !!!")
	std::uint64_t i;
#if (LAM_MAN_PREFETCH) == 1
#pragma noprefetch
#endif
	for (i = 0ULL; i != ROUND_TO_EIGHT(m_nsize,8ULL); i += 16ULL) {
#if (LAM_MAN_PREFETCH) == 1
		AVX3_COMPLEX_PREFETCH_FROM_OBJ(x,i,16ULL,_MM_HINT_T0)
#endif
#if (LAM_CACHE_MEM_STORES) == 1
		_mm512_store_pd(&this->m_Re[i+0ULL], 
					_mm512_load_pd(&x.m_Re[i+0ULL]));
		_mm512_store_pd(&this->m_Re[i+8ULL], 
					_mm512_load_pd(&x.m_Re[i+8ULL]));
		_mm512_store_pd(&this->m_Im[i+0ULL], 
					_mm512_load_pd(&x.m_Im[i+0ULL]));
		_mm512_store_pd(&this->m_Im[i+8ULL], 
					_mm512_load_pd(&x.m_Im[i+8ULL]));
#else
		_mm512_stream_pd(&this->m_Re[i+0ULL], 
					_mm512_load_pd(&x.m_Re[i+0ULL]));
		_mm512_stream_pd(&this->m_Re[i + 8ULL], 
					_mm512_load_pd(&x.m_Re[i + 8ULL]));
		_mm512_stream_pd(&this->m_Im[i+0ULL], 
					_mm512_load_pd(&x.getIm()[i+0ULL]));
		_mm512_stream_pd(&this->m_Im[i + 8ULL], 
					_mm512_load_pd(&x.m_Im[i + 8ULL]));
#endif
	}
	for (; i != m_nsize; ++i) {
		m_Re[i] = x.m_Re[i];
		m_Im[i] = x.m_Im[i];
	}
}

lam::math::AVX512VComplex1D::
AVX512VComplex1D(_In_ AVX512VComplex1D &&x)
:
m_nsize{ x.m_nsize },
m_Re(NULL),
m_Im(NULL){

	this->m_Re = &x.m_Re[0];
	this->m_Im = &x.m_Im[0];
	x.m_nsize = 0ULL;
	x.m_Re = NULL;
	x.m_Im = NULL;
}	
	


lam::math::AVX512VComplex1D::
~AVX512VComplex1D() {

	
	if (NULL != this->m_Re) {
		_mm_free(this->m_Re);
		this->m_Re = NULL;
	}
	if (NULL != this->m_Im) {
		_mm_free(this->m_Im);
		this->m_Im = NULL;
	}
}

lam::math::AVX512VComplex1D &
lam::math::AVX512VComplex1D::operator=(_In_ const AVX512VComplex1D &x) {
	if (this == &x) return (*this);
	this->m_nsize = x.m_nsize;
	_mm_free(this->m_Re);
	_mm_free(this->m_Im);
	double * __restrict Re = reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double),align64B));
	double * __restrict Im = reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double),align64B));
	AVX3_COMPLEX_CHECK_FATAL_ERROR(Re, Im, m_nsize, "AVX512VComplex1D::operator(AVX512VComplex1D &) -- !!! Mmeory Allocation Failure !!!")
	std::uint64_t i;
#if (LAM_MAN_PREFETCH) == 1
#pragma noprefetch
#endif
	for (i = 0ULL; i != ROUND_TO_EIGHT(m_nsize,8ULL); i += 16ULL) {
#if (LAM_MAN_PREFETCH) == 1
		AVX3_COMPLEX_PREFETCH_FROM_OBJ(x, i, 16ULL, _MM_HINT_T0)
#endif
#if (LAM_CACHE_MEM_STORES) == 1
		_mm512_store_pd(&this->m_Re[i+0ULL], _mm512_load_pd(&x.m_Re[i+0ULL]));
		_mm512_store_pd(&this->m_Re[i+8ULL], _mm512_load_pd(&x.m_Re[i+8ULL]));
		_mm512_store_pd(&this->m_Im[i+0ULL], _mm512_load_pd(&x.m_Im[i+0ULL]));
		_mm512_store_pd(&this->m_Im[i+8ULL], _mm512_load_pd(&x.m_Im[i+8ULL]));
#else
		_mm512_stream_pd(&this->m_Re[i+0ULL], _mm512_load_pd(&x.m_Re[i+0ULL]));
		_mm512_stream_pd(&this->m_Re[i + 8ULL], _mm512_load_pd(&x.m_Re[i + 8ULL]));
		_mm512_stream_pd(&this->m_Im[i+0ULL], _mm512_load_pd(&x.m_Im[i+0ULL]));
		_mm512_stream_pd(&this->m_Im[i + 8ULL], _mm512_load_pd(&x.m_Im[i + 8ULL]));
#endif
	}
	for (; i != m_nsize; ++i) {
		Re[i] = x.m_Re[i];
		Im[i] = x.m_Im[i];
	}
	m_Re = Re;
	m_Im = Im;
	return (*this);
}

lam::math::AVX512VComplex1D &
lam::math::AVX512VComplex1D::operator=(_In_ AVX512VComplex1D &&x) {
	if (this == &x) return (*this);
		
	_mm_free(this->m_Re);
	_mm_free(this->m_Im);
	this->m_nsize = x.m_nsize;
	this->m_Re = &x.m_Re[0];
	this->m_Im = &x.m_Im[0];
	x.m_nsize = 0ULL;
	x.m_Re = NULL;
	x.m_Im = NULL;
	return (*this);
}	


lam::math::AVX512VComplex1D &
lam::math::AVX512VComplex1D::operator+=(_In_ const AVX512VComplex1D &x) {
	std::uint64_t i;
#if (LAM_MAN_PREFETCH) == 1
#pragma noprefetch
#endif
	for ( i = 0ULL; i != ROUND_TO_EIGHT(m_nsize,8ULL); i += 16ULL) {
#if (LAM_MAN_PREFETCH) == 1
		AVX3_COMPLEX_PREFETCH_FROM_OBJ(x, i, 16ULL, _MM_HINT_T0)
#endif
#if (LAM_CACHE_MEM_STORES) == 1
		_mm512_store_pd(&this->m_Re[i+0ULL], 
				_mm512_add_pd(_mm512_load_pd(&this->m_Re[i+0ULL]),
										_mm512_load_pd(&x.m_Re[i+0ULL])));
		_mm512_store_pd(&this->m_Re[i+8ULL], 
				_mm512_add_pd(_mm512_load_pd(&this->m_Re[i+8ULL]),
										_mm512_load_pd(&x.m_Re[i+8ULL])));
		_mm512_store_pd(&this->m_Im[i+0ULL],
				_mm512_add_pd(_mm512_load_pd(&this->m_Re[i+0ULL]),
										_mm512_load_pd(&x.m_Im[i+0ULL])));
		_mm512_store_pd(&this->m_Im[i + 8ULL], 
				_mm512_add_pd(_mm512_load_pd(&this->m_Im[i+8ULL]),
										_mm512_load_pd(&x.m_Im[i+8ULL])));
#else
		_mm512_stream_pd(&this->m_Re[i+0ULL],
				_mm512_add_pd(_mm512_load_pd(&this->m_Re[i+0ULL]),
										_mm512_load_pd(&x.m_Re[i+0ULL])));
		_mm512_stream_pd(&this->m_Re[i + 8ULL],
				_mm512_add_pd(_mm512_load_pd(&this->m_Re[i + 8ULL]),
									  _mm512_load_pd(&x.m_Re[i + 8ULL])));
		_mm512_stream_pd(&this->m_Im[i+0ULL],
				_mm512_add_pd(_mm512_load_pd(&this->m_Re[i+0ULL]),
										_mm512_load_pd(&x.m_Im[i+0ULL])));
		_mm512_stream_pd(&this->m_Im[i + 8ULL],
				_mm512_add_pd(_mm512_load_pd(&this->m_Im[i + 8ULL]),
									  _mm512_load_pd(&x.m_Im[i + 8ULL])));
#endif
	}
	for (; i != m_nsize; ++i) {
		m_Re[i] += x.m_Re[i];
		m_Im[i] += x.m_Im[i];
	}
	return (*this);
}

lam::math::AVX512VComplex1D &
lam::math::AVX512VComplex1D::operator+=(_In_ const double* __restrict v) {
	std::uint64_t i;
#if (LAM_MAN_PREFETCH) == 1
#pragma noprefetch
#endif
	for ( i = 0ULL; i != ROUND_TO_EIGHT(m_nsize,8ULL); i += 16ULL) {
#if (LAM_MAN_PREFETCH) == 1
		AVX3_COMPLEX_PREFETCH_FROM_PTR(v,i,16ULL,_MM_HINT_T0)
#endif
#if (LAM_CACHE_MEM_STORES) == 1
		_mm512_store_pd(&this->m_Re[i+0ULL], 
				_mm512_add_pd(_mm512_load_pd(&this->m_Re[i+0ULL]),
											_mm512_load_pd(&v[i+0ULL])));
		_mm512_storeu_pd(&this->m_Re[i + 8ULL], 
				_mm512_add_pd(_mm512_load_pd(&this->m_Re[i+8ULL]),
											_mm512_load_pd(&v[i+8ULL])));
#else
		_mm512_stream_pd(&this->m_Re[i+0ULL],
				_mm512_add_pd(_mm512_load_pd(&this->m_Re[i+0ULL]),
											_mm512_load_pd(&v[i+0ULL])));
		_mm512_stream_pd(&this->m_Re[i + 8ULL],
				_mm512_add_pd(_mm512_load_pd(&this->m_Re[i + 8ULL]),
										  _mm512_load_pd(&v[i + 8ULL])));
#endif
	}
	for (; i != m_nsize; ++i) {
		m_Re[i] += v[i];
		m_Im[i] += v[i];
	}
	return (*this);
}

lam::math::AVX512VComplex1D &
lam::math::AVX512VComplex1D::operator-=(_In_ const AVX512VComplex1D &x) {
	std::uint64_t i;
#if (LAM_MAN_PREFETCH) == 1
#pragma noprefetch
#endif
	for ( i = 0ULL; i != ROUND_TO_EIGHT(m_nsize,8ULL); i += 16ULL) {
#if (LAM_MAN_PREFETCH) == 1
		AVX3_COMPLEX_PREFETCH_FROM_OBJ(x,i,16ULL,_MM_HINT_T0)
#endif
#if (LAM_CACHE_MEM_STORES) == 1
		_mm512_store_pd(&this->m_Re[i+0ULL], 
				_mm512_sub_pd(_mm512_load_pd(&this->m_Re[i+0ULL]),
										_mm512_load_pd(&x.m_Re[i+0ULL])));
		_mm512_store_pd(&this->m_Re[i + 8ULL], 
				_mm512_sub_pd(_mm512_load_pd(&this->m_Re[i+8ULL]),
										_mm512_load_pd(&x.m_Re[i+8ULL])));
		_mm512_store_pd(&this->m_Im[i], 
				_mm512_sub_pd(_mm512_load_pd(&this->m_Im[i]),
											 _mm512_load_pd(&x.m_Im[i])));
		_mm512_store_pd(&this->m_Im[i + 8ULL], 
				_mm512_sub_pd(_mm512_load_pd(&this->m_Im[i+8ULL]),
									  _mm512_load_pd(&x.m_Im[i + 8ULL])));
#else
		_mm512_stream_pd(&this->m_Re[i+0ULL],
				_mm512_sub_pd(_mm512_load_pd(&this->m_Re[i+0ULL]),
										_mm512_load_pd(&x.m_Re[i+0ULL])));
		_mm512_stream_pd(&this->m_Re[i + 8ULL],
				_mm512_sub_pd(_mm512_load_pd(&this->m_Re[i + 8ULL]),
										_mm512_load_pd(&x.m_Re[i + 8ULL])));
		_mm512_stream_pd(&this->m_Im[i+0ULL],
				_mm512_sub_pd(_mm512_load_pd(&this->m_Im[i+0ULL]),
										 _mm512_load_pd(&x.m_Im[i+0ULL])));
		_mm512_stream_pd(&this->m_Im[i + 8ULL],
				_mm512_sub_pd(_mm512_load_pd(&this->m_Im[i + 8ULL]),
										_mm512_load_pd(&x.m_Im[i + 8ULL])));
#endif
	}
	for (; i != m_nsize; ++i) {
		m_Re[i] -= x.m_Re[i];
		m_Im[i] -= x.m_Im[i];
	}
	return (*this);
}

lam::math::AVX512VComplex1D &
lam::math::AVX512VComplex1D::operator-=(_In_ const double* __restrict v) {
    std::uint64_t i;
#if (LAM_MAN_PREFETCH) == 1
#pragma noprefetch
#endif
	for ( i = 0ULL; i != ROUND_TO_EIGHT(m_nsize,8ULL); i += 16ULL) {
#if LAM_MAN_PREFETCH == 1
		AVX3_COMPLEX_PREFETCH_FROM_PTR(v,i,16ULL,_MM_HINT_T0)
#endif
#if (LAM_CACHE_MEM_STORES) == 1
		_mm512_store_pd(&this->m_Re[i+0ULL], 
		_mm512_sub_pd(_mm512_load_pd(&this->m_Re[i+0ULL]),
		_mm512_load_pd(&v[i+0ULL])));
		_mm512_store_pd(&this->m_Re[i + 8ULL], 
		_mm512_sub_pd(_mm512_load_pd(&this->m_Re[i+8ULL]),
		_mm512_load_pd(&v[i+8ULL])));
#else
		_mm512_stream_pd(&this->m_Re[i+0ULL],
			_mm512_sub_pd(_mm512_load_pd(&this->m_Re[i+0ULL]),
			_mm512_load_pd(&v[i+0ULL])));
		_mm512_stream_pd(&this->m_Re[i + 8ULL],
			_mm512_sub_pd(_mm512_load_pd(&this->m_Re[i + 8ULL]),
			_mm512_load_pd(&v[i + 8ULL])));
#endif
	}
	for (; i != m_nsize; ++i) {
		m_Re[i] -= v[i];
		m_Im[i] -= v[i];
	}
	return (*this);
}

lam::math::AVX512VComplex1D &
lam::math::AVX512VComplex1D::operator*=(_In_ const AVX512VComplex1D &x) {
	std::uint64_t i; 
#if (LAM_MAN_PREFETCH) == 1
#pragma noprefetch
#endif 
	for ( i = 0ULL; i != ROUND_TO_EIGHT(m_nsize,8ULL); i += 16ULL) {
#if (LAM_MAN_PREFETCH) == 1
		AVX3_COMPLEX_PREFETCH_FROM_OBJ(x,i,16ULL,_MM_HINT_T0)
#endif
#if (LAM_CACHE_MEM_STORES) == 1
		_mm512_store_pd(&this->m_Re[i+0ULL], 
		_mm512_sub_pd(_mm512_mul_pd(_mm512_load_pd(&this->m_Re[i+0ULL]),
		_mm512_load_pd(&x.m_Re[i+0ULL])),_mm512_mul_pd(_mm512_load_pd(&this->m_Im[i+0ULL]),
		_mm512_load_pd(&x.m_Im[i+0ULL])))); 
		_mm512_store_pd(&this->m_Re[i+8ULL],
		_mm512_sub_pd(_mm512_mul_pd(_mm512_load_pd(&this->m_Re[i+8ULL]),
		_mm512_load_pd(&x.m_Re[i+8ULL])), _mm512_mul_pd(_mm512_load_pd(&this->m_Im[i+8ULL]),
		_mm512_load_pd(&x.m_Im[i+8ULL]))));
		_mm512_store_pd(&this->m_Im[i+0ULL], 
		_mm512_add_pd(_mm512_mul_pd(_mm512_load_pd(&this->m_Im[i+0ULL]),
		_mm512_load_pd(&x.m_Re[i+0ULL])), _mm512_mul_pd(_mm512_load_pd(&this->m_Re[i+0ULL]),
		_mm512_load_pd(&x.m_Im[i+0ULL]))));
		_mm512_store_pd(&this->m_Im[i+8ULL],
		_mm512_add_pd(_mm512_mul_pd(_mm512_load_pd(&this->m_Im[i+8ULL]),
		_mm512_load_pd(&x.m_Re[i+8ULL])), _mm512_mul_pd(_mm512_load_pd(&this->m_Re[i+8ULL]),
		_mm512_loadu_pd(&x.m_Im[i+8ULL]))));
#else
		_mm512_stream_pd(&this->m_Re[i+0ULL],
			_mm512_sub_pd(_mm512_mul_pd(_mm512_load_pd(&this->m_Re[i+0ULL]),
			_mm512_load_pd(&x.m_Re[i+0ULL])), _mm512_mul_pd(_mm512_load_pd(&this->m_Im[i+0ULL]),
			_mm512_load_pd(&x.m_Im[i+0ULL]))));
		_mm512_stream_pd(&this->m_Re[i + 8ULL],
			_mm512_sub_pd(_mm512_mul_pd(_mm512_load_pd(&this->m_Re[i + 8ULL]),
			_mm512_loadu_pd(&x.m_Re[i + 8ULL])), _mm512_mul_pd(_mm512_load_pd(&this->m_Im[i + 8ULL]),
			_mm512_loadu_pd(&x.m_Im[i + 8ULL]))));
		_mm512_stream_pd(&this->m_Im[i+0ULL],
			_mm512_add_pd(_mm512_mul_pd(_mm512_load_pd(&this->m_Im[i+0ULL]),
			_mm512_load_pd(&x.m_Re[i+0ULL])), _mm512_mul_pd(_mm512_load_pd(&this->m_Re[i+0ULL]),
			_mm512_load_pd(&x.m_Im[i+0ULL]))));
		_mm512_stream_pd(&this->m_Im[i + 8ULL],
			_mm512_add_pd(_mm512_mul_pd(_mm512_load_pd(&this->m_Im[i + 8ULL]),
			_mm512_load_pd(&x.m_Re[i + 8ULL])), _mm512_mul_pd(_mm512_load_pd(&this->m_Re[i + 8ULL]),
			_mm512_load_pd(&x.m_Im[i + 8ULL]))));
#endif
	}
	for (; i != m_nsize; ++i) {
		m_Re[i] = (m_Re[i] * x.m_Re[i]) - (m_Im[i] * x.m_Im[i]);
		m_Im[i] = (m_Im[i] * x.m_Re[i]) + (m_Re[i] * x.m_Im[i]);
	}
	return (*this);
}

lam::math::AVX512VComplex1D &
lam::math::AVX512VComplex1D::operator*=(_In_ const double* __restrict v) {
	std::uint64_t i;
#if (LAM_MAN_PREFETCH) == 1
#pragma noprefetch
#endif 
	for ( i = 0ULL; i != ROUND_TO_EIGHT(m_nsize,8ULL); i += 16ULL) {
#if LAM_MAN_PREFETCH == 1
		AVX3_COMPLEX_PREFETCH_FROM_PTR(v,i,16ULL,_MM_HINT_T0)
#endif	
#if (LAM_CACHE_MEM_STORES) == 1
		_mm512_store_pd(&this->m_Re[i+0ULL], 
		_mm512_mul_pd(_mm512_load_pd(&this->m_Re[i+0ULL]),
		_mm512_load_pd(&v[i+0ULL])));
		_mm512_store_pd(&this->m_Re[i + 8ULL], 
		_mm512_mul_pd(_mm512_load_pd(&this->m_Re[i+8ULL]),
		_mm512_load_pd(&v[i+8ULL])));
		_mm512_store_pd(&this->m_Im[i+0ULL], 
		_mm512_mul_pd(_mm512_load_pd(&this->m_Im[i+0ULL]),
		_mm512_load_pd(&v[i+0ULL])));
		_mm512_store_pd(&this->m_Im[i + 8ULL], 
		_mm512_mul_pd(_mm512_load_pd(&this->m_Im[i+8ULL]),
		_mm512_load_pd(&v[i+8ULL])));
#else
		_mm512_stream_pd(&this->m_Re[i + 0ULL],
			_mm512_mul_pd(_mm512_load_pd(&this->m_Re[i + 0ULL]),
			_mm512_load_pd(&v[i + 0ULL])));
		_mm512_stream_pd(&this->m_Re[i + 8ULL],
			_mm512_mul_pd(_mm512_load_pd(&this->m_Re[i + 8ULL]),
			_mm512_load_pd(&v[i + 8ULL])));
		_mm512_stream_pd(&this->m_Im[i + 0ULL],
			_mm512_mul_pd(_mm512_load_pd(&this->m_Im[i + 0ULL]),
			_mm512_load_pd(&v[i + 0ULL])));
		_mm512_stream_pd(&this->m_Im[i + 8ULL],
			_mm512_mul_pd(_mm512_load_pd(&this->m_Im[i + 8ULL]),
			_mm512_load_pd(&v[i + 8ULL])));
#endif	

	}
	for (; i != m_nsize; ++i) {
		m_Re[i] *= v[i];
		m_Im[i] *= v[i];
	}
	return (*this);
}

lam::math::AVX512VComplex1D &
lam::math::AVX512VComplex1D::operator/=(_In_ const AVX512VComplex1D &x) {
	std::uint64_t i;
#if (LAM_MAN_PREFETCH) == 1
#pragma noprefetch
#endif 	
	for ( i = 0ULL; i != ROUND_TO_EIGHT(m_nsize,8ULL); i += 16ULL) {
#if (LAM_MAN_PREFETCH) == 1
		AVX3_COMPLEX_PREFETCH_FROM_OBJ(x, i, 16ULL, _MM_HINT_T0)
#endif
#if LAM_CACHE_MEM_STORES == 1
		const __m512d tre1 = _mm512_add_pd(_mm512_mul_pd(_mm512_load_pd(&this->m_Re[i+0ULL]),
			_mm512_load_pd(&x.m_Im[i+0ULL])),_mm512_mul_pd(_mm512_load_pd(&this->m_Im[i+0ULL]),
			_mm512_load_pd(&x.m_Im[i+0ULL])));
		const __m512d tre2 = _mm512_add_pd(_mm512_mul_pd(_mm512_load_pd(&this->m_Re[i + 8ULL]),
			_mm512_load_pd(&x.m_Im[i + 8ULL])), _mm512_mul_pd(_mm512_load_pd(&this->m_Im[i + 8ULL]),
			_mm512_load_pd(&x.m_Im[i + 8ULL])));
		const __m512d tim1 = _mm512_sub_pd(_mm512_mul_pd(_mm512_load_pd(&this->m_Im[i+0ULL]),
			_mm512_load_pd(&x.m_Im[i + 0ULL])), _mm512_mul_pd(_mm512_load_pd(&this->m_Re[i+0ULL]),
			_mm512_load_pd(&x.m_Im[i+0ULL])));
		const __m512d tim2 = _mm512_sub_pd(_mm512_mul_pd(_mm512_load_pd(&this->m_Im[i + 8ULL]),
			_mm512_load_pd(&x.m_Im[i + 8ULL])), _mm512_mul_pd(_mm512_load_pd(&this->m_Re[i + 8ULL]),
			_mm512_load_pd(&x.m_Im[i + 8ULL])));
		const __m512d den1 = _mm512_add_pd(_mm512_mul_pd(_mm512_load_pd(&x.m_Re[i+0ULL]),
			_mm512_load_pd(&x.m_Re[i + 0ULL])), _mm512_mul_pd(_mm512_load_pd(&x.m_Im[i+0ULL]),
			_mm512_load_pd(&x.m_Im[i+0ULL])));
		const __m512d den2 = _mm512_add_pd(_mm512_mul_pd(_mm512_load_pd(&x.m_Re[i + 8ULL]),
			_mm512_load_pd(&x.m_Re[i + 8ULL])), _mm512_mul_pd(_mm512_load_pd(&x.m_Im[i + 8ULL]),
			_mm512_load_pd(&x.m_Im[i + 8ULL])));

		_mm512_store_pd(&this->m_Re[i + 0ULL], _mm512_div_pd(tre1,den1));
		_mm512_store_pd(&this->m_Re[i + 8ULL], _mm512_div_pd(tre2,den2));
		_mm512_store_pd(&this->m_Im[i + 0ULL], _mm512_div_pd(tim1,den1));
		_mm512_store_pd(&this->m_Im[i + 8ULL], _mm512_div_pd(tim2,den2));
#else
		const __m512d tre1 = _mm512_add_pd(_mm512_mul_pd(_mm512_load_pd(&this->m_Re[i + 0ULL]),
			_mm512_load_pd(&x.m_Im[i + 0ULL])), _mm512_mul_pd(_mm512_load_pd(&this->m_Im[i + 0ULL]),
			_mm512_load_pd(&x.m_Im[i + 0ULL])));
		const __m512d tre2 = _mm512_add_pd(_mm512_mul_pd(_mm512_load_pd(&this->m_Re[i + 8ULL]),
			_mm512_load_pd(&x.m_Im[i + 8ULL])), _mm512_mul_pd(_mm512_load_pd(&this->m_Im[i + 8ULL]),
			_mm512_load_pd(&x.m_Im[i + 8ULL])));
		const __m512d tim1 = _mm512_sub_pd(_mm512_mul_pd(_mm512_load_pd(&this->m_Im[i + 0ULL]),
			_mm512_load_pd(&x.Im[i + 0ULL])), _mm512_mul_pd(_mm512_load_pd(&this->m_Re[i + 0ULL]),
			_mm512_load_pd(&x.m_Im[i + 0ULL])));
		const __m512d tim2 = _mm512_sub_pd(_mm512_mul_pd(_mm512_load_pd(&this->m_Im[i + 8ULL]),
			_mm512_load_pd(&x.m_Im[i + 8ULL])), _mm512_mul_pd(_mm512_load_pd(&this->m_Re[i + 8ULL]),
			_mm512_load_pd(&x.m_Im[i + 8ULL])));
		const __m512d den1 = _mm512_add_pd(_mm512_mul_pd(_mm512_load_pd(&x.m_Re[i + 0ULL]),
			_mm512_load_pd(&x.m_Re[i + 0ULL])), _mm512_mul_pd(_mm512_load_pd(&x.m_Im[i + 0ULL]),
			_mm512_load_pd(&x.m_Im[i + 0ULL])));
		const __m512d den2 = _mm512_add_pd(_mm512_mul_pd(_mm512_load_pd(&x.m_Re[i + 8ULL]),
			_mm512_load_pd(&x.m_Re[i + 8ULL])), _mm512_mul_pd(_mm512_load_pd(&x.m_Im[i + 8ULL]),
			_mm512_load_pd(&x.m_Im[i + 8ULL])));
			// Stall on divider 
		_mm512_stream_pd(&this->m_Re[i + 0ULL], _mm512_div_pd(tre1, den1));
		_mm512_stream_pd(&this->m_Re[i + 8ULL], _mm512_div_pd(tre2, den2));
		_mm512_stream_pd(&this->m_Im[i + 0ULL], _mm512_div_pd(tim1, den1));
		_mm512_stream_pd(&this->m_Im[i + 8ULL], _mm512_div_pd(tim2, den2));
#endif
	}
	for (; i != m_nsize; ++i) {
		const double tre = (m_Re[i] * x.m_Im[i]) + (m_Im[i] * x.m_Im[i]);
		const double tim = (m_Im[i] * x.m_Im[i]) - (m_Re[i] * x.m_Im[i]);
		const double den = (x.m_Re[i] * x.m_Re[i]) + (x.m_Im[i] * x.m_Im[i]);
		m_Re[i] = tre / den;
		m_Im[i] = tim / den;
	}
	return (*this);
}

lam::math::AVX512VComplex1D &
lam::math::AVX512VComplex1D::operator/=(_In_ const double* __restrict v) {
	std::uint64_t i;
#if (LAM_MAN_PREFETCH) == 1
#pragma noprefetch
#endif	
	for ( i = 0ULL; i != ROUND_TO_EIGHT(m_nsize,8ULL); i += 16ULL) {
#if LAM_MAN_PREFETCH == 1
		AVX3_COMPLEX_PREFETCH_FROM_PTR(v, i, 16ULL, _MM_HINT_T0)
#endif	
#if (LAM_CACHE_MEM_STORES) == 1
		_mm512_store_pd(&this->m_Re[i + 0ULL], 
		_mm512_div_pd(_mm512_load_pd(&this->m_Re[i+0ULL]),
		_mm512_load_pd(&v[i+0ULL])));
		_mm512_store_pd(&this->m_Im[i + 8ULL], 
		_mm512_div_pd(_mm512_load_pd(&this->m_Re[i+8ULL]),
		_mm512_load_pd(&v[i+8ULL])));
		_mm512_store_pd(&this->m_Im[i + 0ULL], 
		_mm512_div_pd(_mm512_load_pd(&this->m_Im[i+0ULL]),
		_mm512_load_pd(&v[i+0ULL])));
		_mm512_store_pd(&this->m_Im[i + 8ULL], 
		_mm512_div_pd(_mm512_load_pd(&this->m_Im[i+8ULL]),
		_mm512_load_pd(&v[i+8ULL])));
#else
		_mm512_stream_pd(&this->m_Re[i + 0ULL],
			_mm512_div_pd(_mm512_load_pd(&this->m_Re[i + 0ULL]),
			_mm512_load_pd(&v[i + 0ULL])));
		_mm512_stream_pd(&this->m_Im[i + 8ULL],
			_mm512_div_pd(_mm512_load_pd(&this->m_Re[i + 8ULL]),
			_mm512_load_pd(&v[i + 8ULL])));
		_mm512_stream_pd(&this->m_Im[i + 0ULL],
			_mm512_div_pd(_mm512_load_pd(&this->m_Im[i + 0ULL]),
			_mm512_load_pd(&v[i + 0ULL])));
		_mm512_stream_pd(&this->m_Im[i + 8ULL],
			_mm512_div_pd(_mm512_load_pd(&this->m_Im[i + 8ULL]),
			_mm512_load_pd(&v[i + 8ULL])));
#endif
	}
	for (; i != m_nsize; ++i) {
		m_Re[i] /= v[i];
		m_Im[i] /= v[i];
	}
	return (*this);
}

std::pair< double*, double*>
lam::math::AVX512VComplex1D::operator==(_In_ const AVX512VComplex1D &x) {

	double* __restrict pr1 = 
	reinterpret_cast< double*>(_mm_malloc(this->m_nsize*sizeof(double),align64B));
	 double* __restrict pr2 = 
	reinterpret_cast< double*>(_mm_malloc(this->m_nsize*sizeof(double),align64B));
	std::pair<double*,double*> pret;
	AVX3_COMPLEX_CHECK_FATAL_ERROR(pr1, pr2, m_nsize, "AVX512VComplex1D::operator==(AVX512VComplex1D &) -- !!! Memory Allocation Failure !!!")

	lam::common::init_varray(pr1,m_nsize,-1.0);
	lam::common::init_varray(pr2,m_nsize,-1.0);
	pret = std::make_pair(pr1,pr2);
	std::uint64_t i;
#if (LAM_MAN_PREFETCH) == 1
#pragma noprefetch
#endif
	for ( i = 0ULL; i != ROUND_TO_FOUR(m_nsize,4ULL); i += 8ULL) {
#if (LAM_MAN_PREFETCH) == 1
		AVX3_COMPLEX_PREFETCH_FROM_OBJ(x, i, 8ULL, _MM_HINT_T0)
#endif 
#if (LAM_CACHE_MEM_STORES) == 1
		// Using AVX for comparison.
		// Unrolled 2x in order to match perfectly
		// per core 2 load operations per cycle.
		
		_mm256_store_pd(&pret.first[i + 0ULL],
		_mm256_cmp_pd(_mm256_load_pd(&this->m_Re[i + 0ULL]),
		_mm256_load_pd(&x.m_Re[i + 0ULL]), _CMP_EQ_OQ));
		_mm256_store_pd(&pret.first[i+4ULL],
		_mm256_cmp_pd(_mm256_load_pd(&this->m_Re[i + 4ULL]),
		_mm256_load_pd(&x.m_Re[i + 4ULL]), _CMP_EQ_OQ));
		_mm256_store_pd(&pret.second[i + 0ULL], 
		_mm256_cmp_pd(_mm256_load_pd(&this->m_Im[i+0ULL]),
		_mm256_load_pd(&x.m_Im[i+0ULL]),_CMP_EQ_OQ));
		_mm256_store_pd(&pret.second[i + 4ULL],
		_mm256_cmp_pd(_mm256_load_pd(&this->m_Im[i + 4ULL]),
		_mm256_load_pd(&x.m_Im[i + 4ULL]), _CMP_EQ_OQ));
#else
		// Stream version in order to not pollute the cache
		// on store operation.
		_mm256_stream_pd(&pret.first[i + 0ULL],
			_mm256_cmp_pd(_mm256_load_pd(&this->m_Re[i + 0ULL]),
			_mm256_loadu_pd(&x.m_Re[i + 0ULL]), _CMP_EQ_OQ));
		_mm256_stream_pd(&pret.first[i + 4ULL],
			_mm256_cmp_pd(_mm256_load_pd(&this->m_Re[i + 4ULL]),
			_mm256_loadu_pd(&x.m_Re[i + 4ULL]), _CMP_EQ_OQ));
		_mm256_stream_pd(&pret.second[i + 0ULL],
			_mm256_cmp_pd(_mm256_load_pd(&this->m_Im[i + 0ULL]),
			_mm256_load_pd(&x.m_Im[i + 0ULL]), _CMP_EQ_OQ));
		_mm256_stream_pd(&pret.second[i + 4ULL],
			_mm256_cmp_pd(_mm256_load_pd(&this->m_Im[i + 4ULL]),
			_mm256_loadu_pd(&x.m_Im[i + 4ULL]), _CMP_EQ_OQ));
#endif
	}
	for (; i != m_nsize; ++i) {
		if (m_Re[i] == x.m_Re[i])
			pret.first[i] = 1.0;
		pret.first[i] = 0.0;
		if (m_Im[i] == x.m_Im[i])
			pret.second[i] = 1.0;
		pret.second[i] = 0.0;
	}		
	return (pret);
}		
	
	


std::pair<double*,double*>
lam::math::AVX512VComplex1D::operator!=(_In_ const AVX512VComplex1D &x) {

	double* __restrict pr1 =
		reinterpret_cast<double*>(_mm_malloc(this->m_nsize*sizeof(double), align64B));
	double* __restrict pr2 =
		reinterpret_cast<double*>(_mm_malloc(this->m_nsize*sizeof(double), align64B));
	std::pair<double*, double*> pret;
	AVX3_COMPLEX_CHECK_FATAL_ERROR(pr1, pr2, m_nsize, "AVX512VComplex1D::operator!=(AVX512VComplex1D &) -- !!! Memory Allocation Failure !!!")
		pret = std::make_pair(pr1,pr2);
	lam::common::init_varray(pr1, this->m_nsize, -1.0);
	lam::common::init_varray(pr2, this->m_nsize, -1.0);
	std::uint64_t i;
#if (LAM_MAN_PREFETCH) == 1
#pragma noprefetch
#endif
	for ( i = 0ULL; i != ROUND_TO_FOUR(m_nsize,4ULL); i += 8ULL) {
#if (LAM_MAN_PREFETCH) == 1
		AVX3_COMPLEX_PREFETCH_FROM_OBJ(x,i,8ULL,_MM_HINT_T0)
#endif
#if (LAM_CACHE_MEM_STORES) == 1
		// Using AVX for comparison.
		// Unrolled 2x in order to match perfectly
		// per core 2 load operations per cycle.
		_mm256_store_pd(&pret.first[i + 0ULL],
			_mm256_cmp_pd(_mm256_load_pd(&this->m_Re[i + 0ULL]),
			_mm256_load_pd(&x.m_Re[i + 0ULL]), _CMP_NEQ_OQ));
		_mm256_store_pd(&pret.first[i + 4ULL],
			_mm256_cmp_pd(_mm256_load_pd(&this->m_Re[i + 4ULL]),
			_mm256_load_pd(&x.m_Re[i + 4ULL]), _CMP_NEQ_OQ));
		_mm256_store_pd(&pret.second[i + 0ULL],
			_mm256_cmp_pd(_mm256_load_pd(&this->m_Im[i + 0ULL]),
			_mm256_load_pd(&x.m_Im[i + 0ULL]), _CMP_NEQ_OQ));
		_mm256_store_pd(&pret.second[i + 4ULL],
			_mm256_cmp_pd(_mm256_load_pd(&this->m_Im[i + 4ULL]),
			_mm256_load_pd(&x.m_Im[i + 4ULL]), _CMP_NEQ_OQ));
#else
		// Stream version in order to not pollute the cache
		// on store operation.
		_mm256_stream_pd(&pret.first[i + 0ULL],
			_mm256_cmp_pd(_mm256_load_pd(&this->m_Re[i + 0ULL]),
			_mm256_load_pd(&x.m_Re[i + 0ULL]), _CMP_NEQ_OQ));
		_mm256_stream_pd(&pret.first[i + 4ULL],
			_mm256_cmp_pd(_mm256_load_pd(&this->m_Re[i + 4ULL]),
			_mm256_load_pd(&x.m_Re[i + 4ULL]), _CMP_NEQ_OQ));
		_mm256_stream_pd(&pret.second[i + 0ULL],
			_mm256_cmp_pd(_mm256_load_pd(&this->m_Im[i + 0ULL]),
			_mm256_load_pd(&x.m_Im[i + 0ULL]), _CMP_NEQ_OQ));
		_mm256_stream_pd(&pret.second[i + 4ULL],
			_mm256_cmp_pd(_mm256_load_pd(&this->m_Im[i + 4ULL]),
			_mm256_load_pd(&x.m_Im[i + 4ULL]), _CMP_NEQ_OQ));
#endif
	}
	for (; i != m_nsize; ++i) {
		if (m_Re[i] != x.m_Re[i])
			pret.first[i] = 1.0;
		 pret.first[i] = 0.0;
		 if (m_Im[i] != x.m_Im[i])
			 pret.second[i] = 1.0;
		 pret.second[i] = 0.0;
	 }
	return (pret);
}		
	
	


std::ostream &
lam::math::operator<<(_In_ std::ostream &os, _In_ const AVX512VComplex1D &x) {

	for (uint64_t i = 0ULL; i != x.m_nsize; ++i) {
		os << std::fixed << std::showpoint << std::setprecision(15) << 
			  std::setw(4)  << "Re: " << "{" << x.m_Re[i] << "}" <<
		      std::setw(12) << "Im: " << "{" << x.m_Im[i] << "}" << std::endl;
	}
	return (os);
}


void
lam::math::v512cnormalize_product(_Inout_ AVX512VComplex1D &vout, 
								  _In_ const AVX512VComplex1D &v1,
								  _In_ const AVX512VComplex1D &v2) {
	std::uint64_t i;
#if (LAM_MAN_PREFETCH) == 1
#pragma noprefetch
#endif
	for (i = 0ULL; i != ROUND_TO_EIGHT(vout.m_nsize, 8ULL); i += 8ULL) {
#if (LAM_MAN_PREFETCH) == 1
		AVX3_COMPLEX_PREFETCH_FROM_OBJ(v1,i,8ULL,_MM_HINT_T0)
		AVX3_COMPLEX_PREFETCH_FROM_OBJ(v2,i,8ULL,_MM_HINT_T0)
#endif
#if (LAM_CACHE_MEM_STORES) == 1
		const __m512d vre = _mm512_sub_pd(_mm512_mul_pd(_mm512_load_pd(&v1.m_Re[i]),
		_mm512_load_pd(&v2.m_Re[i])), _mm512_mul_pd(_mm512_load_pd(&v1.m_Im[i]),
		_mm512_load_pd(&v2.m_Im[i])));
		const __m512d vim = _mm512_add_pd(_mm512_mul_pd(_mm512_load_pd(&v1.m_Im[i]),
		_mm512_load_pd(&v2.m_Re[i])),_mm512_mul_pd(_mm512_load_pd(&v1.m_Re[i]),
		_mm512_load_pd(&v2.m_Im[i])));
		const __m512d cmag = _mm512_sqrt_pd(_mm512_add_pd(_mm512_mul_pd(vre,vre),
		_mm512_mul_pd(vim,vim)));
		_mm512_store_pd(&vout.m_Re[i], _mm512_div_pd(vre,cmag));
		_mm512_store_pd(&vout.m_Im[i], _mm512_div_pd(vim,cmag));
#else
		const __m512d vre = _mm512_sub_pd(_mm512_mul_pd(_mm512_load_pd(&v1.m_Re[i]),
		_mm512_load_pd(&v2.m_Re[i])), _mm512_mul_pd(_mm512_load_pd(&v1.m_Im[i]),
		_mm512_load_pd(&v2.m_Im[i])));
		const __m512d vim = _mm512_add_pd(_mm512_mul_pd(_mm512_load_pd(&v1.m_Im[i]),
		_mm512_load_pd(&v2.m_Re[i])), _mm512_mul_pd(_mm512_load_pd(&v1.m_Re[i]),
		_mm512_load_pd(&v2.m_Im[i])));
		const __m512d cmag = _mm512_sqrt_pd(_mm512_add_pd(_mm512_mul_pd(vre,vre),
		_mm512_mul_pd(vim,vim)));
		_mm512_stream_pd(&vout.m_Re[i], _mm512_div_pd(vre, cmag));
		_mm512_stream_pd(&vout.m_Im[i], _mm512_div_pd(vim, cmag));
#endif
	}
	for (; i != vout.m_nsize; ++i) {
		const double re = (v1.m_Re[i] * v2.m_Re[i]) - (v1.m_Im[i] * v2.m_Im[i]);
		const double im = (v1.m_Im[i] * v2.m_Re[i]) + (v1.m_Re[i] * v2.m_Im[i]);
		const double mag = std::sqrt((re*re) + (im*im));
		vout.m_Re[i] = re / mag;
		vout.m_Im[i] = im / mag;
	}
}



void
lam::math::v512cmean_product(_Inout_ std::complex<double> &mean, 
							 _In_ const AVX512VComplex1D &v1,
							 _In_ const AVX512VComplex1D &v2) {
	double sumre{}, sumim{}, acre{}, acim{};
	std::uint64_t i;
#if (LAM_MAN_PREFETCH) == 1
#pragma noprefetch
#endif
	for (i = 0ULL; i != ROUND_TO_EIGHT(v1.m_nsize, 8ULL); i += 8ULL) {
#if (LAM_MAN_PREFETCH) == 1
		AVX3_COMPLEX_PREFETCH_FROM_OBJ(v1,i,8ULL,_MM_HINT_T0)
		AVX3_COMPLEX_PREFETCH_FROM_OBJ(v2,i,8ULL,_MM_HINT_T0)
#endif
		const __m512d re = _mm512_sub_pd(_mm512_mul_pd(_mm512_load_pd(&v1.m_Re[i]),
		_mm512_load_pd(&v2.m_Re[i])), _mm512_mul_pd(_mm512_load_pd(&v1.m_Im[i]),
		_mm512_load_pd(&v2.m_Im[i])));
		const __m512d im = _mm512_add_pd(_mm512_mul_pd(_mm512_load_pd(&v1.m_Im[i]),
		_mm512_load_pd(&v2.m_Re[i])), _mm512_mul_pd(_mm512_load_pd(&v1.m_Re[i]),
		_mm512_load_pd(&v2.m_Im[i])));
		sumre = _mm512_reduce_add_pd(re);
		acre += sumre;
		sumim = _mm512_reduce_add_pd(im);
		acim += sumim;
	}
	for (; i != v1.m_nsize; ++i) {
		acre += (v1.m_Re[i] * v2.m_Re[i]) - (v1.m_Im[i] * v2.m_Im[i]);
		acim += (v1.m_Im[i] * v2.m_Re[i]) + (v1.m_Re[i] * v2.m_Im[i]);
	}
	mean.real = acre /= static_cast<double>(v1.m_nsize);
	mean.imag = acim /= static_cast<double>(v1.m_nsize);
}

void
lam::math::v512cmean_quotient(_Inout_ std::complex<double> &mean,
							  _In_ const AVX512VComplex1D &v1,
							  _In_ const AVX512VComplex1D &v2) {
	double sumre{}, sumim{}, acre{}, acim{};
	std::uint64_t i;
#if (LAM_MAN_PREFETCH) == 1
#pragma noprefetch
#endif
	for (i = 0ULL; i != ROUND_TO_EIGHT(v1.m_nsize,8ULL); i += 8ULL) {
#if (LAM_MAN_PREFETCH) == 1
		AVX3_COMPLEX_PREFETCH_FROM_OBJ(v1, i, 8ULL, _MM_HINT_T0)
		AVX3_COMPLEX_PREFETCH_FROM_OBJ(v2, i, 8ULL, _MM_HINT_T0)
#endif
		const __m512d re = _mm512_sub_pd(_mm512_mul_pd(_mm512_load_pd(&v1.m_Re[i]),
		_mm512_load_pd(&v2.m_Re[i])), _mm512_mul_pd(_mm512_load_pd(&v1.m_Im[i]),
		_mm512_load_pd(&v2.m_Im[i])));
		const __m512d im = _mm512_add_pd(_mm512_mul_pd(_mm512_load_pd(&v1.m_Im[i]),
		_mm512_load_pd(&v2.m_Re[i])), _mm512_mul_pd(_mm512_load_pd(&v1.m_Re[i]),
		_mm512_load_pd(&v2.m_Im[i])));
		const __m512d den = _mm512_add_pd(_mm512_mul_pd(_mm512_load_pd(&v2.m_Re[i]),
		_mm512_load_pd(&v2.m_Re[i])), _mm512_mul_pd(_mm512_load_pd(&v2.m_Im[i]),
		_mm512_load_pd(&v2.m_Im[i])));
		sumre = _mm512_reduce_add_pd(_mm512_div_pd(re,den));
		acre += sumre;
		sumim = _mm512_reduce_add_pd(_mm512_div_pd(im,den));
		acim += sumim;
	}
	double t1{},t2{};
	for (; i != v1.m_nsize; ++i) {
		const double re = (v1.m_Re[i] * v2.m_Re[i]) - (v1.m_Im[i] * v2.m_Im[i]);
		const double im = (v1.m_Im[i] * v2.m_Re[i]) + (v1.m_Re[i] * v2.m_Im[i]);
		const double den = (v2.m_Re[i] * v2.m_Re[i]) + (v2.m_Im[i] * v2.m_Im[i]);
		t1 += re/den;
		t2 += im / den;
	}
	acre += t1;
	acim += t2;
	mean.real = acre / static_cast<double>(v1.m_nsize);
	mean.imag = acim / static_cast<double>(v2.m_nsize);
}

void
lam::math::v512cconj_product(_Inout_ AVX512VComplex1D    &vout,
							 _In_ const AVX512VComplex1D &v1,
							 _In_ const AVX512VComplex1D &v2) {
	std::uint64_t i;
#if (LAM_MAN_PREFETCH) == 1
#pragma noprefetch
#endif	
	for (i = 0ULL; i != ROUND_TO_EIGHT(v1.m_nsize,8ULL); i += 8ULL) {
#if (LAM_MAN_PREFETCH) == 1
		AVX3_COMPLEX_PREFETCH_FROM_OBJ(v1, i, 8ULL, _MM_HINT_T0)
		AVX3_COMPLEX_PREFETCH_FROM_OBJ(v2, i, 8ULL, _MM_HINT_T0)
#endif
		_mm512_store_pd(&vout.m_Re[i], _mm512_add_pd(_mm512_mul_pd(_mm512_load_pd(&v1.m_Re[i]),
		_mm512_load_pd(&v2.m_Re[i])), _mm512_mul_pd(_mm512_load_pd(&v1.m_Im[i]),
		_mm512_load_pd(&v2.m_Im[i]))));
		_mm512_store_pd(&vout.m_Im[i], _mm512_sub_pd(_mm512_mul_pd(_mm512_load_pd(&v1.m_Im[i]),
		_mm512_load_pd(&v2.m_Re[i])), _mm512_mul_pd(_mm512_load_pd(&v1.m_Re[i]),
		_mm512_load_pd(&v2.m_Im[i]))));
	}
	for (; i != v1.m_nsize; ++i) {
		vout.m_Re[i] = (v1.m_Re[i] * v2.m_Re[i]) + (v1.m_Im[i] * v2.m_Im[i]);
		vout.m_Im[i] = (v1.m_Im[i] * v2.m_Re[i]) - (v1.m_Re[i] * v2.m_Im[i]);
	}	
	
}

void
lam::math::v512cnorm_conjprod(_Inout_ AVX512VComplex1D    &vout,
							  _In_ const AVX512VComplex1D &v1,
							  _In_ const AVX512VComplex1D &v2) {
	std::uint64_t i;
#if (LAM_MAN_PREFETCH) == 1
#pragma noprefetch
#endif	
	for (i = 0ULL; i != ROUND_TO_EIGHT(v1.m_nsize,8ULL); i += 8ULL) {
#if (LAM_MAN_PREFETCH) == 1
		AVX3_COMPLEX_PREFETCH_FROM_OBJ(v1, i, 8ULL, _MM_HINT_T0)
		AVX3_COMPLEX_PREFETCH_FROM_OBJ(v2, i, 8ULL, _MM_HINT_T0)
#endif
		const __m512d vre = _mm512_add_pd(_mm512_mul_pd(_mm512_load_pd(&v1.m_Re[i]),
		_mm512_load_pd(&v2.m_Re[i])), _mm512_mul_pd(_mm512_load_pd(&v1.m_Im[i]),
		_mm512_load_pd(&v2.m_Im[i])));
		const __m512d vim = _mm512_sub_pd(_mm512_mul_pd(_mm512_load_pd(&v1.m_Im[i]),
		_mm512_load_pd(&v2.m_Re[i])), _mm512_mul_pd(_mm512_load_pd(&v1.m_Re[i]),
		_mm512_load_pd(&v2.m_Im[i])));
		const __m512d vmag = _mm512_sqrt_pd(_mm512_add_pd(_mm512_mul_pd(vre,vre),
		_mm512_mul_pd(vim,vim)));
		_mm512_store_pd(&vout.m_Re[i], _mm512_div_pd(vre,vmag));
		_mm512_store_pd(&vout.m_Im[i], _mm512_div_pd(vim,vmag));
	}
	for (; i != v1.m_nsize; ++i) {
		const double re = (v1.m_Re[i] * v2.m_Re[i]) - (v1.m_Im[i] * v2.m_Im[i]);
		const double im = (v1.m_Im[i] * v2.m_Re[i]) + (v1.m_Re[i] * v2.m_Im[i]);
		const double mag = std::sqrt((re*re) + (im*im));
		vout.m_Re[i] = re / mag;
		vout.m_Im[i] = im / mag;
	}
}

void
lam::math::v512cmean_conjprod(_Inout_ std::complex<double> &mean,
							  _In_ const AVX512VComplex1D &v1,
							  _In_ const AVX512VComplex1D &v2) {
	std::uint64_t i;
	double sumre{},sumim{},acre{},acim{};
	__m512d re = _mm512_setzero_pd();
	__m512d im = _mm512_setzero_pd();
#if (LAM_MAN_PREFETCH) == 1
#pragma noprefetch
#endif	
	for (i = 0ULL; i != ROUND_TO_EIGHT(v1.m_nsize,8ULL); i += 8ULL) {
#if (LAM_MAN_PREFETCH) == 1
		AVX3_COMPLEX_PREFETCH_FROM_OBJ(v1, i, 8ULL, _MM_HINT_T0)
		AVX3_COMPLEX_PREFETCH_FROM_OBJ(v2, i, 8ULL, _MM_HINT_T0)
#endif
		AVX3_COMPLEX_ADDITION(re,v1,v2,i,0ULL)
		AVX3_COMPLEX_SUBTRACTION(im,v1,v2,i,0ULL)
		sumre = _mm512_reduce_add_pd(re);
		acre += sumre;
		sumim = _mm512_reduce_add_pd(im);
		acim += sumim;
	}
	for (; i != v1.m_nsize; ++i) {
		const double re = (v1.m_Re[i] * v2.m_Re[i]) + (v1.m_Im[i] * v2.m_Im[i]);
		const double im = (v1.m_Im[i] * v2.m_Re[i]) - (v1.m_Re[i] * v2.m_Im[i]);
		acre += re;
		acim += im;
	}
	mean.real = acre / static_cast<double>(v1.m_nsize);
	mean.imag = acim / static_cast<double>(v1.m_nsize);
}

void
lam::math::v512c_arithmean(_Inout_ std::complex<double> &mean,
						   _In_ const AVX512VComplex1D &v1) {
	std::uint64_t i;
	double sumre{},sumim{},acre{},acim{};
#if (LAM_MAN_PREFETCH) == 1
#pragma noprefetch
#endif	
	for (i = 0ULL; i != ROUND_TO_EIGHT(v1.m_nsize,8ULL); i += 8ULL) {
#if (LAM_MAN_PREFETCH) == 1
		AVX3_COMPLEX_PREFETCH_FROM_OBJ(v1,i,8ULL,_MM_HINT_T0)
#endif
			sumre = _mm512_reduce_add_pd(_mm512_load_pd(&v1.m_Re[i]));
			acre += sumre;
			sumim = _mm512_reduce_add_pd(_mm512_load_pd(&v1.m_Im[i]));
			acim += sumim;
	}
	for (; i != v1.m_nsize; ++i) {
		acre += v1.m_Re[i];
		acim += v1.m_Im[i];
	}
	mean.real = acre / static_cast<double>(v1.m_nsize);
	mean.imag = acim / static_cast<double>(v1.m_nsize);
}

void
lam::math::v512c_normalize(_Inout_ AVX512VComplex1D &vnorm,
						   _In_ const AVX512VComplex1D &v,
						   _In_ const AVX512VComplex1D &cv) {
	std::uint64_t i;
	__m512d cmag = _mm512_setzero_pd();
#if (LAM_MAN_PREFETCH) == 1
#pragma noprefetch
#endif
	for (i = 0ULL; i != ROUND_TO_EIGHT(v.m_nsize, 8ULL); i += 8ULL) {
#if (LAM_MAN_PREFETCH) == 1
			AVX3_COMPLEX_PREFETCH_FROM_OBJ(v, i, 8ULL, _MM_HINT_T0)
			AVX3_COMPLEX_PREFETCH_FROM_OBJ(cv, i, 8ULL, _MM_HINT_T0)
#endif
			AVX3_COMPLEX_MAGNITUDE(cmag,v,cv,i,0ULL)
			_mm512_store_pd(&vnorm.m_Re[i], _mm512_div_pd(_mm512_load_pd(&v.m_Re[i]),cmag));
			_mm512_store_pd(&vnorm.m_Im[i], _mm512_div_pd(_mm512_load_pd(&v.m_Im[i]),cmag));
	}
	for (; i != v.m_nsize; ++i) {
		const double cmag = std::sqrt(v.m_Re[i] * cv.m_Re[i] + (v.m_Im[i] * cv.m_Im[i]));
		vnorm.m_Re[i] = v.m_Re[i] / cmag;
		vnorm.m_Im[i] = v.m_Im[i] / cmag;
	}
}

void
lam::math::v512c_magnitude(_Inout_ double * __restrict vmag,
						   _In_ const AVX512VComplex1D &v,
						   _In_ const AVX512VComplex1D &cv) {
	std::uint64_t i;
	__m512d cmag = _mm512_setzero_pd();
#if (LAM_MAN_PREFETCH) ==1
#pragma noprefetch
#endif
	for (i = 0ULL; i != ROUND_TO_EIGHT(v.m_nsize,8ULL); i += 8ULL) {
#if (LAM_MAN_PREFETCH) == 1
		    AVX3_COMPLEX_PREFETCH_FROM_OBJ(v,  i, 8ULL, _MM_HINT_T0)
			AVX3_COMPLEX_PREFETCH_FROM_OBJ(cv, i, 8ULL, _MM_HINT_T0)
#endif
			AVX3_COMPLEX_MAGNITUDE(cmag,v,cv,i,0ULL)
			_mm512_store_pd(&vmag[i], cmag);
	}
	for (; i != v.m_nsize; ++i) 
		vmag[i] = std::sqrt(v.m_Re[i] * cv.m_Re[i] + (v.m_Im[i] * cv.m_Im[i]));
}	








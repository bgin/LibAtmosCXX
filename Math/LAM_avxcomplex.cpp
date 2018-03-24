
#include "../LAM_config.h"
#include "../LAM_simd_defs.h"
#include "LAM_avxcomplex.h"
#if (PRINT_CALLSTACK_ON_ERROR) == 1
#include "../System/StackWalker.h"
#endif
//
//	Implementation
//

// Parametrized macros

#if !defined (AVXCOMPLEX_PREFETCH_FROM_OBJ)
#define AVXCOMPLEX_PREFETCH_FROM_OBJ(obj,idx,off,hint) \
	_mm_prefetch(reinterpret_cast<const char*>(&(obj).m_Re[(idx)+(off)]),(hint)); \
    _mm_prefetch(reinterpret_cast<const char*>(&(obj).m_Im[(idx)+(off)]),(hint));
#endif

#if !defined (AVXCOMPLEX_PREFETCH_FROM_PTR)
#define AVXCOMPLEX_PREFETCH_FROM_PTR(ptr,idx,off,hint) \
	_mm_prefetch(reinterpret_cast<const char*>(&(ptr)[(idx)+(off)]),(hint));
#endif

#if !defined (AVCOMPLEX_PREFETCH_FROM_THIS)
#define AVXCOMPLEX_PREFETCH_FROM_THIS(obj,idx,off,hint) \
	_mm_prefetch(reinterpret_cast<const char*>(&(obj)->m_Re[(idx)+(off)]),(hint)); \
	_mm_prefetch(reinterpret_cast<const char*>(&(obj)->m_Im[(idx)+(off)]),(hint));
#endif

#if !defined (AVXCOMPLEX_CHECK_FATAL_ERROR)
#define AVXCOMPLEX_CHECK_FATAL_ERROR(ptr1,ptr2,nsize,msg) \
  do {													  \
		if ((NULL  == (ptr1) && (nsize) != 0ULL) ||        \
		     (NULL == (ptr2) && (nsize) != 0ULL) ) {      \
			    StackWalker sw{};						  \
			    sw.ShowCallstack();						  \
			    ABORT_ON_ERROR(msg,MALLOC_FAILED)		  \
	 }											          \
  } while (0);
#endif

lam::math::AVXVComplex1D::
AVXVComplex1D()
:
m_nsize{0ULL},
m_Re{NULL},
m_Im{NULL} {}

lam::math::AVXVComplex1D::
           AVXVComplex1D(_In_ const uint64_t nsize)
:
m_nsize{nsize},
m_Re(reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double),align64B))),
m_Im(reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double),align64B)))
{
	AVXCOMPLEX_CHECK_FATAL_ERROR(m_Re, m_Im, m_nsize, "AVXComplex1D::AVXComplex1D(uint64_t) -- !!! Memory Allocation Failure !!! ")
	
	uint64_t i;
	for ( i = 0ULL; ROUND_TO_FOUR(m_nsize,4ULL); i += 4ULL) {
#if (LAM_CACHE_MEM_STORES) == 1
		_mm256_storeu_pd(&this->m_Re[i], _mm256_setzero_pd());
		_mm256_storeu_pd(&this->m_Im[i], _mm256_setzero_pd());
#else
		_mm256_stream_pd(&this->m_Re[i], _mm256_setzero_pd());
		_mm256_stream_pd(&this->m_Im[i], _mm256_setzero_pd());
#endif
	}
	// Scalar remainder

	for (; i != m_nsize; ++i) {
		m_Re[i] = 0.0;
		m_Im[i] = 0.0;
	}
	
}    


	




lam::math::AVXVComplex1D::
		   AVXVComplex1D(_In_ const AVXVComplex1D &x)
:
m_nsize{x.m_nsize},
m_Re(reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double),align64B))),
m_Im(reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double),align64B))) {
	
	AVXCOMPLEX_CHECK_FATAL_ERROR(m_Re, m_Im, m_nsize, "AVXVComplex1D::AVXVComplex1D( AVXVComplex1D &) -- !!! Memory Allocation Failure !!!")
	
#if (LAM_MAN_PREFETCH) == 1
#pragma noprefetch
#endif
	uint64_t i;
	for ( i = 0ULL; i != ROUND_TO_FOUR(m_nsize,4ULL); i += 4ULL) {
#if LAM_MAN_PREFETCH == 1
		_mm_prefetch(reinterpret_cast<const char*>(&x.m_Re[i+4ULL]),_MM_HINT_T0);
		_mm_prefetch(reinterpret_cast<const char*>(&x.m_Im[i+4ULL]),_MM_HINT_T0);
#endif
#if LAM_CACHE_MEM_STORES == 1
		_mm256_storeu_pd(&this->m_Re[i], _mm256_loadu_pd(&x.m_Re[i]));
		_mm256_storeu_pd(&this->m_Im[i], _mm256_loadu_pd(&x.m_Im[i]));
#else
		_mm256_stream_pd(&this->m_Re[i], _mm256_loadu_pd(&x.m_Re[i]));
		_mm256_stream_pd(&this->m_Im[i], _mm256_loadu_pd(&x.m_Im[i]));
#endif
	}
	for (; i != m_nsize; ++i) {
		m_Re[i] = x.m_Re[i];
		m_Im[i] = x.m_Im[i];
	}
	
}

lam::math::AVXVComplex1D::
		   AVXVComplex1D(_In_ AVXVComplex1D &&x)
:
m_nsize{x.m_nsize},
m_Re(NULL),
m_Im(NULL) {

	this->m_Re = &x.m_Re[0];
	this->m_Im = &x.m_Im[0];
	
	x.m_nsize = 0ULL;
	x.m_Re = NULL;
	x.m_Im = NULL;
	
}

lam::math::AVXVComplex1D::
		  ~AVXVComplex1D() {

	
	if (this->m_Re) {
		_mm_free(this->m_Re);
		this->m_Re = NULL;
	}
	if (this->m_Im) {
		_mm_free(this->m_Im);
		this->m_Im = NULL;
	}
	
}

lam::math::AVXVComplex1D &
lam::math::AVXVComplex1D::operator=(_In_ const AVXVComplex1D &x) {
	if (this == &x) return (*this);
		
	 m_nsize = x.m_nsize;
	_mm_free(this->m_Re);
	_mm_free(this->m_Im);
	double * __restrict Re = reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double),align64B));
	double * __restrict Im = reinterpret_cast<double*>(_mm_malloc(m_nsize*sizeof(double),align64B));
	AVXCOMPLEX_CHECK_FATAL_ERROR(Re, Im, m_nsize, "AVXVComplex1D::operator=( AVXVComplex1D &) -- !!! Memory Allocation Failure !!!")
	
#if (LAM_MAN_PREFETCH) == 1
#pragma noprefetch
#endif
	uint64_t i;
	for ( i = 0ULL; i != ROUND_TO_FOUR(m_nsize,4ULL); i += 4ULL) {
#if (LAM_MAN_PREFETCH) == 1
		AVXCOMPLEX_PREFETCH_FROM_OBJ(x, i, 4ULL, _MM_HINT_T0)
		
#endif
#if LAM_CACHE_MEM_STORES == 1
		_mm256_storeu_pd(&Re[i], _mm256_loadu_pd(&x.m_Re[i]));
		_mm256_storeu_pd(&Im[i], _mm256_loadu_pd(&x.m_Im[i]));
#else
		_mm256_stream_pd(&Re[i], _mm256_loadu_pd(&x.m_Re[i]));
		_mm256_stream_pd(&Im[i], _mm256_loadu_pd(&x.m_Im[i]));
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

lam::math::AVXVComplex1D &
lam::math::AVXVComplex1D::operator=(_In_ AVXVComplex1D &&x) {
	if (this == &x) return (*this);

	_mm_free(this->m_Re);
	_mm_free(this->m_Im);
	this->m_nsize = x.m_nsize;
	this->m_Re = x.m_Re;
	this->m_Im = x.m_Im;

	x.m_Re = 0ULL;
	x.m_Re = NULL;
	x.m_Im = NULL;
	return (*this);
}	
	
	


lam::math::AVXVComplex1D &
lam::math::AVXVComplex1D::operator+=(_In_ const AVXVComplex1D &x) {
#if LAM_DEBUG_ON
	_ASSERTE(m_nsize == x.m_nsize);
		    
#else
	if (this->m_nsize != x.m_nsize) {
#if (PRINT_CALLSTACK_ON_ERROR) == 1
	 StackWalker sw{};
	 sw.ShowCallstack();
#endif		
		throw std::invalid_argument("AVXVComplex1D::operator+= [loc:194] --> Invalid argument!!");
	}
#endif
#if (LAM_MAN_PREFETCH) == 1
#pragma noprefetch
#endif
    uint64_t i;
	for ( i = 0ULL; i != ROUND_TO_FOUR(m_nsize,4ULL); i += 4ULL) {
#if LAM_MAN_PREFETCH == 1
		AVXCOMPLEX_PREFETCH_FROM_OBJ(x,i,4ULL,_MM_HINT_T0)
		
#endif
#if (LAM_CACHE_MEM_STORES) == 1
		_mm256_storeu_pd(&this->m_Re[i], _mm256_add_pd(_mm256_loadu_pd(&this->m_Re[i]),
													   _mm256_loadu_pd(&x.m_Re[i])));
		_mm256_storeu_pd(&this->m_Im[i], _mm256_add_pd(_mm256_loadu_pd(&this->m_Im[i]),
													   _mm256_loadu_pd(&x.m_Im[i])));
#else
		_mm256_stream_pd(&this->m_Re[i], _mm256_add_pd(_mm256_loadu_pd(&this->m_Re[i]),
													   _mm256_loadu_pd(&x.m_Re[i])));
		_mm256_stream_pd(&this->m_Im[i], _mm256_add_pd(_mm256_loadu_pd(&this->m_Im[i]),
													   _mm256_loadu_pd(&x.m_Im[i])));
#endif
	}
	for (; i != m_nsize; ++i) {
		m_Re[i] += x.m_Re[i];
		m_Im[i] += x.m_Im[i];
	}
	return (*this);
}

lam::math::AVXVComplex1D &
lam::math::AVXVComplex1D::operator+=(_In_ const double* __restrict v) {
#if (LAM_DEBUG_ON) == 1
	_ASSERTE(v != NULL);
#else
	if (NULL == v) {
#if (PRINT_CALLSTACK_ON_ERROR) == 1
		StackWalker sw{};
		sw.ShowCallstack();
#endif	
		throw std::invalid_argument("AVXVComplex1D::operator+= [loc:225] --> v == NULL!");
	}
#endif
#if (LAM_MAN_PREFETCH) == 1
#pragma noprefetch
#endif
    uint64_t i;
	for ( i = 0ULL; i != ROUND_TO_FOUR(m_nsize,4ULL); i += 4ULL) {
#if (LAM_MAN_PREFETCH) == 1
		AVXCOMPLEX_PREFETCH_FROM_PTR(v,i,4ULL,_MM_HINT_T0)
		
#endif
#if (LAM_CACHE_MEM_STORES) == 1
		_mm256_storeu_pd(&this->m_Re[i], _mm256_add_pd(_mm256_loadu_pd(&this->m_Re[i]),
													   _mm256_loadu_pd(&v[i])));
#else
		_mm256_stream_pd(&this->m_Re[i], _mm256_add_pd(_mm256_loadu_pd(&this->m_Re[i]),
													   _mm256_loadu_pd(&v[i])));
#endif		
	}
	for (; i != m_nsize; ++i) {
		m_Re[i] += v[i];
		m_Im[i] += v[i];
	}
	return (*this);
}

lam::math::AVXVComplex1D &
lam::math::AVXVComplex1D::operator-=(_In_ const AVXVComplex1D &x) {
#if (LAM_DEBUG_ON) == 1

	_ASSERTE(this->m_nsize == x.m_nsize);
		
#else
	if (this->m_nsize != x.M_nsize){
#if (PRINT_CALLSTACK_ON_ERROR) == 1
     StackWalker sw{};
	 sw.ShowCallstack();
#endif		 
		throw std::invalid_argument("AVXVComplex1D::operator-= [loc:250] --> Invalid argument(s)!!");
	}
#endif
#if (LAM_MAN_PREFETCH) == 1
#pragma noprefetch
#endif
	uint64_t i;
	for ( i = 0ULL; i != ROUND_TO_FOUR(m_nsize,4ULL); i += 4ULL) {
#if (LAM_MAN_PREFETCH) == 1
		AVXCOMPLEX_PREFETCH_FROM_OBJ(x,i,4ULL,_MM_HINT_T0)
		
#endif
#if LAM_CACHE_MEM_STORES == 1
		_mm256_storeu_pd(&this->m_Re[i], _mm256_sub_pd(_mm256_loadu_pd(&this->m_Re[i]),
													   _mm256_loadu_pd(&x.m_Re[i])));
		_mm256_storeu_pd(&this->m_Im[i], _mm256_sub_pd(_mm256_loadu_pd(&this->m_Im[i]),
													   _mm256_loadu_pd(&x.m_Im[i])));
#else
		_mm256_stream_pd(&this->m_Re[i], _mm256_sub_pd(_mm256_loadu_pd(&this->m_Re[i]),
													   _mm256_loadu_pd(&x.m_Re[i])));
		_mm256_stream_pd(&this->m_Im[i], _mm256_sub_pd(_mm256_loadu_pd(&this->m_Im[i]),
													   _mm256_loadu_pd(&x.m_Im[i])));
#endif
	}
	for (; i != m_nsize; ++i) {
		m_Re[i] -= x.m_Re[i];
		m_Im[i] -= x.m_Im[i];
	}
	return (*this);
}

lam::math::AVXVComplex1D &
lam::math::AVXVComplex1D::operator-=(_In_ const double* __restrict v) {
#if LAM_DEBUG_ON == 1
	_ASSERTE(v != NULL);
#else
	if (NULL == v) 
#if (PRINT_CALLSTACK_ON_ERROR) == 1
		StackWalker sw{};
		sw.ShowCallstack();
#endif
		throw std::invalid_argument("AVXVComplex1D::operator-= [loc:281] --> v == NULL!!");
#endif
#if (LAM_MAN_PREFETCH) == 1
#pragma noprefetch
#endif
    uint64_t i;
	for ( i = 0ULL; i != ROUND_TO_FOUR(m_nsize,4ULL); i += 4ULL) {
#if (LAM_MAN_PREFETCH) == 1
		AVXCOMPLEX_PREFETCH_FROM_PTR(v,i,4ULL,_MM_HINT_T0)
		
#endif
#if (LAM_CACHE_MEM_STORES) == 1
		_mm256_storeu_pd(&this->m_Re[i], _mm256_sub_pd(_mm256_loadu_pd(&this->m_Re[i]),
												       _mm256_loadu_pd(&v[i])));
#else		
		_mm256_stream_pd(&this->m_Re[i], _mm256_sub_pd(_mm256_loadu_pd(&this->m_Re[i]),
												       _mm256_loadu_pd(&v[i])));
#endif
	}
	for (; i != m_nsize; ++i) {
		m_Re[i] -= v[i];
	}
	return (*this);
}

lam::math::AVXVComplex1D &
lam::math::AVXVComplex1D::operator*=(_In_ const AVXVComplex1D &x) {
#if (LAM_DEBUG_ON) == 1
	_ASSERTE(this->m_nsize == x.m_nsize);
		    
#else
	if (this->m_nsize != x.m_nsize) {
#if (PRINT_CALLSTACK_ON_ERROR) == 1
		StackWalker sw{};
		sw.ShowCallstack();
#endif		
		throw std::invalid_argument("AVXVComplex1D::operator*= [loc:305] --> Invalid argument(s)!!");
	}
#endif
#if (LAM_MAN_PREFETCH) == 1
#pragma noprefetch
#endif
    uint64_t i;
	for ( i = 0ULL; i != ROUND_TO_FOUR(m_nsize,4ULL); i += 4ULL) {
#if (LAM_MAN_PREFETCH) == 1
		AVXCOMPLEX_PREFETCH_FROM_OBJ(x,i,4ULL,_MM_HINT_T0)
		
#endif
#if (LAM_CACHE_MEM_STORES) == 1
		_mm256_storeu_pd(&this->m_Re[i], _mm256_sub_pd(_mm256_mul_pd(_mm256_loadu_pd(&this->m_Re[i]),
			           _mm256_loadu_pd(&x.m_Re[i])),_mm256_mul_pd(_mm256_loadu_pd(&this->m_Im[i]),
			           _mm256_loadu_pd(&x.m_Im[i]))));
		_mm256_storeu_pd(&this->m_Im[i], _mm256_add_pd(_mm256_mul_pd(_mm256_loadu_pd(&this->m_Im[i]),
					   _mm256_loadu_pd(&x.m_Re[i])), _mm256_mul_pd(_mm256_loadu_pd(&this->m_Re[i]),
			           _mm256_loadu_pd(&x.m_Im[i]))));
#else
		_mm256_stream_pd(&this->m_Re[i], _mm256_sub_pd(_mm256_mul_pd(_mm256_loadu_pd(&this->m_Re[i]),
			          _mm256_loadu_pd(&x.m_Re[i])), _mm256_mul_pd(_mm256_loadu_pd(&this->m_Im[i]),
			          _mm256_loadu_pd(&x.m_Im[i]))));
		_mm256_stream_pd(&this->m_Im[i], _mm256_add_pd(_mm256_mul_pd(_mm256_loadu_pd(&this->m_Im[i]),
			          _mm256_loadu_pd(&x.m_Re[i])), _mm256_mul_pd(_mm256_loadu_pd(&this->m_Re[i]),
			          _mm256_loadu_pd(&x.m_Im[i]))));
#endif
	}
	for (; i != m_nsize; ++i) {
		m_Re[i] = (m_Re[i] * x.m_Re[i]) - (m_Im[i] * x.m_Im[i]);
		m_Im[i] = (m_Im[i] * x.m_Re[i]) + (m_Re[i] * x.m_Im[i]);
	}
	return (*this);
}

lam::math::AVXVComplex1D &
lam::math::AVXVComplex1D::operator*=(_In_ const double* __restrict v) {
#if (LAM_DEBUG_ON) == 1
	_ASSERTE(v != NULL);
#else
	if (NULL == v) {
#if (PRINT_CALLSTACK_ON_ERROR) == 1
		StackWalker sw{};
		sw.ShowCallstack();
#endif
		throw std::invalid_argument("AVXVComplex1D::operator*= [loc:340] --> v == NULL!!");
 }
#endif
#if (LAM_MAN_PREFETCH) == 1
#pragma noprefetch
#endif
	uint64_t i;
	for ( i = 0ULL; i != ROUND_TO_FOUR(m_nsize,4ULL); i += 4ULL) {
#if (LAM_MAN_PREFETCH) == 1
		AVXCOMPLEX_PREFETCH_FROM_PTR(v,i,4ULL,_MM_HINT_T0)
	
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
	for (; i != m_nsize; ++i) {
		m_Re[i] *= v[i];
		m_Im[i] *= v[i];
	}
	return (*this);
}

lam::math::AVXVComplex1D &
lam::math::AVXVComplex1D::operator/=(_In_ const AVXVComplex1D &x) {
#if (LAM_DEBUG_ON) == 1
	_ASSERTE(this->m_nsize == x.m_nsize);
		
#else
	if (this->m_nsize != x.m_nsize) {
#if (PRINT_CALLSTACK_ON_ERROR) == 1
		StackWalker sw{};
		sw.ShowCallstack();
#endif		
		throw std::invalid_argument("AVXVComplex1D::operator/= [loc:368] --> Invalid argument(s)!!");
	}
#endif
	__m256d zmask1( _mm256_setzero_pd() );
	__m256d zmask2( _mm256_setzero_pd() );
	__m256i vres(_mm256_setr_epi64x(0LL,0LL,0LL,0LL));
	const __m256d vzero(_mm256_set1_pd(0.0));
#if (LAM_MAN_PREFETCH) == 1
#pragma noprefetch
#endif
	uint64_t i;
	for ( i = 0ULL; i != ROUND_TO_FOUR(m_nsize,4ULL); i += 4ULL) {
#if (LAM_MAN_PREFETCH) == 1
		AVXCOMPLEX_PREFETCH_FROM_OBJ(x,i,4ULL,_MM_HINT_T0)
		
#endif
		zmask1 = _mm256_cmp_pd(vzero, _mm256_loadu_pd(&x.m_Re[i]),_CMP_EQ_OQ);
		zmask2 = _mm256_cmp_pd(vzero, _mm256_loadu_pd(&x.m_Im[i]),_CMP_EQ_OQ);
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
	for (; i != m_nsize; ++i) {
		if (x.m_Re[i] == 0.0 || x.m_Im[i] == 0.0)
			throw std::domain_error("AVXVComplex1D::operator/= [loc:389] --> found '0.0' in AVXVComplex1D!");
	}
	
	i = 0ULL;
#if (LAM_MAN_PREFETCH) == 1
#pragma noprefetch
#endif
	for (; i != ROUND_TO_FOUR(m_nsize,4ULL); i += 4ULL) {
#if (LAM_MAN_PREFETCH) == 1
		AVXCOMPLEX_PREFETCH_FROM_OBJ(x,i,4ULL,_MM_HINT_T0)
		
#endif
#if (LAM_CACHE_MEM_STORES) == 1
		__m256d tre = _mm256_add_pd(_mm256_mul_pd(_mm256_loadu_pd(&this->m_Re[i]),
			_mm256_loadu_pd(&x.m_Im[i])),_mm256_mul_pd(_mm256_loadu_pd(&this->m_Im[i]),
			_mm256_loadu_pd(&x.m_Im[i])));
		__m256d tim = _mm256_sub_pd(_mm256_mul_pd(_mm256_loadu_pd(&this->m_Im[i]),
			_mm256_loadu_pd(&x.m_Im[i])), _mm256_mul_pd(_mm256_loadu_pd(&this->m_Re[i]),
			_mm256_loadu_pd(&x.m_Im[i])));
		__m256d tmp = _mm256_add_pd(_mm256_mul_pd(_mm256_loadu_pd(&x.m_Re[i]),
			_mm256_loadu_pd(&x.m_Re[i])), _mm256_mul_pd(_mm256_loadu_pd(&x.m_Im[i]),
			_mm256_loadu_pd(&x.m_Im[i])));
		_mm256_storeu_pd(&this->m_Re[i], _mm256_div_pd(tre,tmp));
		_mm256_storeu_pd(&this->m_Im[i], _mm256_div_pd(tim,tmp));
#else
		__m256d tre = _mm256_add_pd(_mm256_mul_pd(_mm256_loadu_pd(&this->m_Re[i]),
			_mm256_loadu_pd(&x.m_Im[i])), _mm256_mul_pd(_mm256_loadu_pd(&this->m_Im[i]),
			_mm256_loadu_pd(&x.m_Im[i])));
		__m256d tim = _mm256_sub_pd(_mm256_mul_pd(_mm256_loadu_pd(&this->m_Im[i]),
			_mm256_loadu_pd(&x.m_Im[i])), _mm256_mul_pd(_mm256_loadu_pd(&this->m_Re[i]),
			_mm256_loadu_pd(&x.m_Im[i])));
		__m256d tmp = _mm256_add_pd(_mm256_mul_pd(_mm256_loadu_pd(&x.m_Re[i]),
			_mm256_loadu_pd(&x.m_Re[i])), _mm256_mul_pd(_mm256_loadu_pd(&x.m_Im[i]),
			_mm256_loadu_pd(&x.m_Im[i])));
		_mm256_stream_pd(&this->m_Re[i], _mm256_div_pd(tre, tmp));
		_mm256_stream_pd(&this->m_Im[i], _mm256_div_pd(tim, tmp));
#endif
	}
	for (; i != m_nsize; ++i) {
		double tre = (m_Re[i] * x.m_Im[i]) + (m_Im[i] * x.m_Im[i]);
		double tim = (m_Im[i] * x.m_Im[i]) - (m_Re[i] * x.m_Im[i]);
		double den = (x.m_Re[i] * x.m_Re[i]) + (x.m_Im[i] * x.m_Im[i]);
		m_Re[i] = tre / den;
		m_Im[i] = tim / den;
	}
	return (*this);
}

lam::math::AVXVComplex1D &
lam::math::AVXVComplex1D::operator/=(_In_ const double* __restrict v) {
#if (LAM_DEBUG_ON) == 1
	_ASSERTE(v != NULL);
#else
	if (NULL == v)
#if (PRINT_CALLSTACK_ON_ERROR) == 1
		StackWalker sw{};
	sw.ShowCallstack();
#endif	
		throw std::invalid_argument("AVXVComplex1D::operator/= [loc:437] --> v == NULL!!");
#endif
	__m256d zmask1(_mm256_setzero_pd());
	
	__m256i vres(_mm256_setr_epi64x(0LL, 0LL, 0LL, 0LL));
	const __m256d vzero(_mm256_set1_pd(0.0));
	uint64_t i;
#if (LAM_MAN_PREFETCH) == 1
#pragma noprefetch
#endif
	for ( i = 0ULL; i != ROUND_TO_FOUR(m_nsize,4ULL); i += 4ULL) {
#if (LAM_MAN_PREFETCH) == 1
		AVXCOMPLEX_PREFETCH_FROM_PTR(v,i,4ULL,_MM_HINT_T0)
		
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
	for (; i != m_nsize; ++i) {
		if (v[i] == 0.0)
			throw std::domain_error("AVXVComplex1D::operator/= [loc:453] --> found '0.0' in double* !");
	}
	i = 0ULL;
#if (LAM_MAN_PREFETCH) == 1
#pragma noprefetch
#endif
	for (; i != ROUND_TO_FOUR(m_nsize,4ULL); i += 4ULL) {
#if (LAM_MAN_PREFETCH) == 1
		AVXCOMPLEX_PREFETCH_FROM_PTR(v,i,4ULL,_MM_HINT_T0)
		
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
	for (; i != m_nsize; ++i) {
		m_Re[i] /= v[i];
		m_Im[i] /= v[i];
	}
	return (*this);
}

std::pair<double*,double*> 
lam::math::AVXVComplex1D::operator==(_In_ const AVXVComplex1D &x) {
#if (LAM_DEBUG_ON) == 1
	_ASSERTE(this->m_nsize == x.m_nsize);
		
#else
	if (this->m_nsize != x.m_nsize) {
#if (PRINT_CALLSTACK_ON_ERROR) == 1
		StackWalker sw{};
		sw.ShowCallstack();
#endif		
		throw std::invalid_argument("AVXVComplex1D::operator== [loc:487] --> Invalid argument(s)!!");
	}
#endif
	double * __restrict pr1 = 
	reinterpret_cast<double*>(_mm_malloc(this->m_nsize*sizeof(double),align64B));
	double * __restrict pr2 = 
	reinterpret_cast<double*>(_mm_malloc(this->m_nsize*sizeof(double),align64B));
	std::pair<double*,double*> pret;
	AVXCOMPLEX_CHECK_FATAL_ERROR(pr1, pr2, m_nsize, "AVXVComplex1D::operator==(AVXVComplex1D &) -- !!! Memory Allocation Failure !!!")
	
	uint64_t i;
	for (i = 0ULL; i != ROUND_TO_FOUR(m_nsize,4ULL); i += 4ULL){
		  _mm256_storeu_pd(&pr1[i], _mm256_set_pd(-1.0,-1.0,-1.0,-1.0));
		  _mm256_storeu_pd(&pr2[i], _mm256_set_pd(-1.0,-1.0,-1.0,-1.0));
		}
	for (; i != m_nsize; ++i) {
		pr1[i] = -1.0;
		pr2[i] = -1.0;
	}
	pret = std::make_pair(pr1,pr2);
	i = 0ULL;
#if (LAM_MAN_PREFETCH) == 1
#pragma noprefetch
#endif
	for (; i != ROUND_TO_FOUR(m_nsize,4ULL); i += 4ULL) {
#if (LAM_MAN_PREFETCH) == 1
		AVXCOMPLEX_PREFETCH_FROM_OBJ(x,i,4ULL,_MM_HINT_T0)
		
#endif
#if (LAM_CACHE_MEM_STORES) == 1
		_mm256_storeu_pd(&pret.first[i],_mm256_cmp_pd(_mm256_loadu_pd(&this->m_Re[i]),
										_mm256_loadu_pd(&x.m_Re[i]),_CMP_EQ_OQ));
		_mm256_storeu_pd(&pret.second[i], _mm256_cmp_pd(_mm256_loadu_pd(&this->m_Im[i]),
									    _mm256_loadu_pd(&x.m_Im[i]),_CMP_EQ_OQ));
#else
		_mm256_stream_pd(&pret.first[i], _mm256_cmp_pd(_mm256_loadu_pd(&this->m_Re[i]),
			_mm256_loadu_pd(&x.m_Re[i]), _CMP_EQ_OQ));
		_mm256_stream_pd(&pret.second[i], _mm256_cmp_pd(_mm256_loadu_pd(&this->m_Im[i]),
			_mm256_loadu_pd(&x.m_Im[i]), _CMP_EQ_OQ));
#endif
	}
	for (; i != m_nsize; ++i) {
		if (m_Re[i] == x.m_Re[i])
			pret.first[i] = 1.0;
		else
			pret.first[i] = 0.0;

		if (m_Im[i] == x.m_Im[i])
			pret.second[i] = 1.0;
		else
			pret.second[i] = 0.0;
	}
	return (pret);
}

std::pair<double*,double*>
lam::math::AVXVComplex1D::operator!=(_In_ const AVXVComplex1D &x) {
#if (LAM_DEBUG_ON) == 1
	_ASSERTE(this->m_nsize == x.m_nsize);
		
#else
	if (this->m_nsize != x.m_nsize) {
#if (PRINT_CALLSTACK_ON_ERROR) == 1
		StackWalker sw{};
		sw.ShowCallstack();
#endif			
		throw std::invalid_argument("AVXVComplex1D::operator!= [loc:535] --> Invalid argument(s)!!");
	}
#endif
	double * __restrict pr1 =
		reinterpret_cast<double*>(_mm_malloc(this->m_nsize*sizeof(double), align64B));
	double * __restrict pr2 =
		reinterpret_cast<double*>(_mm_malloc(this->m_nsize*sizeof(double), align64B));
	std::pair<double*, double*> pret;
	AVXCOMPLEX_CHECK_FATAL_ERROR(pr1, pr2, m_nsize, "AVXVComplex1D::operator!=(AVXVComplex1D &) -- !!! Memory Allocation Failure !!!")
	
	uint64_t i;
	for ( i = 0ULL; i != ROUND_TO_FOUR(m_nsize,4ULL); i += 4ULL){
		_mm256_storeu_pd(&pr1[i], _mm256_set_pd(-1.0, -1.0, -1.0, -1.0));
		_mm256_storeu_pd(&pr2[i], _mm256_set_pd(-1.0, -1.0, -1.0, -1.0));
	}
	for (; i != m_nsize; ++i) {
		pr1[i] = -1.0;
		pr2[i] = -1.0;
	}
	pret = std::make_pair(pr1, pr2);

	i = 0ULL;
#if (LAM_MAN_PREFETCH) == 1
#pragma noprefetch
#endif
	for (; i != ROUND_TO_FOUR(m_nsize,4ULL); i += 4ULL) {
#if (LAM_MAN_PREFETCH) == 1
		AVXCOMPLEX_PREFETCH_FROM_OBJ(x,i,4ULL,_MM_HINT_T0)
		
#endif
#if (LAM_CACHE_MEM_STORES) == 1
		_mm256_storeu_pd(&pret.first[i], _mm256_cmp_pd(_mm256_loadu_pd(&this->m_Re[i]),
			_mm256_loadu_pd(&x.m_Re[i]), _CMP_NEQ_OQ)); 
		_mm256_storeu_pd(&pret.second[i], _mm256_cmp_pd(_mm256_loadu_pd(&this->m_Im[i]),
			_mm256_loadu_pd(&x.m_Im[i]), _CMP_NEQ_OQ));
#else
		_mm256_stream_pd(&pret.first[i], _mm256_cmp_pd(_mm256_loadu_pd(&this->m_Re[i]),
			_mm256_loadu_pd(&x.m_Re[i]), _CMP_NEQ_OQ));
		_mm256_stream_pd(&pret.second[i], _mm256_cmp_pd(_mm256_loadu_pd(&this->m_Im[i]),
			_mm256_loadu_pd(&x.m_Im[i]), _CMP_NEQ_OQ));
#endif
	}
	for (; i != m_nsize; ++i) {
		if (m_Re[i] != x.m_Re[i])
			pret.first[i] = 1.0;
		else
			pret.first[i] = 0.0;

		if (m_Im[i] != x.m_Im[i])
			pret.second[i] = 1.0;
		else
			pret.second[i] = 0.0;
	}
	return (pret);
}

std::ostream & 
lam::math::operator<<(_In_ std::ostream &os, _In_ const AVXVComplex1D &x) {

	for (uint64_t i = 0ULL; i != x.m_nsize; ++i) {
		os << std::fixed << std::showpoint << std::setprecision(15) << std::setw(4) << "Re: " << "{" << x.m_Re[i] << "}"
		   << std::setw(12) << "Im: " << "{" <<  x.m_Im[i] << "}" <<  std::endl;
	}	
	return (os);
}

lam::math::AVXVComplex1D &
lam::math::AVXVComplex1D::vcnormalize(_In_ const AVXVComplex1D &x) {
#if (LAM_DEBUG_ON) == 1
	_ASSERTE(this->m_nsize == x.m_nsize);
			
#else
	if ( this->m_nsize != x.m_nsize) {
#if (PRINT_CALLSTACK_ON_ERROR) == 1
		StackWalker sw{};
		sw.ShowCallstack();
#endif		
		throw std::invalid_argument("AVXVComplex1D::vconrmalize [loc:592] --> AVXVComplex1D in invalid state!!");
	}
#endif
	uint64_t i;
#if (LAM_MAN_PREFETCH) == 1
#pragma noprefetch
#endif
	for ( i = 0ULL; i != ROUND_TO_FOUR(m_nsize,4ULL); i += 4ULL) {
#if (LAM_MAN_PREFETCH) == 1
		AVXCOMPLEX_PREFETCH_FROM_OBJ(x,i,4ULL,_MM_HINT_T0)
		
#endif
#if (LAM_CACHE_MEM_STORES) == 1
		_mm256_storeu_pd(&this->m_Re[i], _mm256_sub_pd(_mm256_mul_pd(_mm256_loadu_pd(&this->m_Re[i]),
						_mm256_loadu_pd(&x.m_Re[i])),_mm256_mul_pd(_mm256_loadu_pd(&this->m_Im[i]),
						_mm256_loadu_pd(&x.m_Im[i]))));
		_mm256_storeu_pd(&this->m_Im[i], _mm256_add_pd(_mm256_mul_pd(_mm256_loadu_pd(&this->m_Im[i]),
						_mm256_loadu_pd(&x.m_Re[i])), _mm256_mul_pd(_mm256_loadu_pd(&this->m_Re[i]),
						_mm256_loadu_pd(&x.m_Im[i]))));
		
		__m256d cmag =	_mm256_sqrt_pd(_mm256_add_pd(_mm256_mul_pd(_mm256_loadu_pd(&this->m_Re[i]),
						_mm256_loadu_pd(&this->m_Re[i])),_mm256_mul_pd(_mm256_loadu_pd(&this->m_Im[i]),
						_mm256_loadu_pd(&this->m_Im[i]))));
		_mm256_storeu_pd(&this->m_Re[i], _mm256_div_pd(_mm256_loadu_pd(&this->m_Re[i]),cmag));
		_mm256_storeu_pd(&this->m_Im[i], _mm256_div_pd(_mm256_loadu_pd(&this->m_Im[i]),cmag));
#else
		_mm256_storeu_pd(&this->m_Re[i], _mm256_sub_pd(_mm256_mul_pd(_mm256_loadu_pd(&this->m_Re[i]),
					   _mm256_loadu_pd(&x.m_Re[i])), _mm256_mul_pd(_mm256_loadu_pd(&this->m_Im[i]),
			           _mm256_loadu_pd(&x.m_Im[i]))));
		_mm256_storeu_pd(&this->m_Im[i], _mm256_add_pd(_mm256_mul_pd(_mm256_loadu_pd(&this->m_Im[i]),
			           _mm256_loadu_pd(&x.m_Re[i])), _mm256_mul_pd(_mm256_loadu_pd(&this->m_Re[i]),
			           _mm256_loadu_pd(&x.m_Im[i]))));

		__m256d cmag = _mm256_sqrt_pd(_mm256_add_pd(_mm256_mul_pd(_mm256_loadu_pd(&this->m_Re[i]),
			           _mm256_loadu_pd(&this->m_Re[i])), _mm256_mul_pd(_mm256_loadu_pd(&this->m_Im[i]),
			           _mm256_loadu_pd(&this->m_Im[i]))));
		_mm256_storeu_pd(&this->m_Re[i], _mm256_div_pd(_mm256_loadu_pd(&this->m_Re[i]), cmag));
		_mm256_storeu_pd(&this->m_Im[i], _mm256_div_pd(_mm256_loadu_pd(&this->m_Im[i]), cmag));
#endif
	}
	for (; i != m_nsize; ++i) {
		m_Re[i] = (m_Re[i] * x.m_Re[i]) - (m_Im[i] * x.m_Im[i]);
		m_Im[i] = (m_Im[i] * x.m_Re[i]) + (m_Re[i] * x.m_Im[i]);
		double cmag = std::sqrt((m_Re[i] * m_Re[i]) + (m_Im[i] * m_Im[i]));
		m_Re[i] /= cmag;
		m_Im[i] /= cmag;
	}
	return (*this);
}

std::complex<double> 
lam::math::AVXVComplex1D::vcmean(_In_ const AVXVComplex1D &x) {
#if (LAM_DEBUG_ON) == 1
	_ASSERTE(this->m_nsize == x.m_nsize);
		
#else
	if (this->m_nsize != x.m_nsize) {
#if (PRINT_CALLSTACK_ON_ERROR) == 1
		StackWalker sw{};
		sw.ShowCallstack();
#endif		
		throw std::invalid_argument("AVXVComplex1D::vcmean [loc:640] --> AVXVComplex1D in invalid state!!");
	}
#endif
	const uint64_t vlen{ x.m_nsize };
	double sr{}, si{},acc1{},acc2{};
	// First pass vector summation.
#if (LAM_MAN_PREFETCH) == 1
#pragma noprefetch
#endif
	for (uint64_t i = 0; i != this->m_nsize; i += 4ULL) {
#if (LAM_MAN_PREFETCH) == 1
		AVXCOMPLEX_PREFETCH_FROM_OBJ(x,i,4ULL,_MM_HINT_T0)
		
#endif 
		_mm256_storeu_pd(&this->m_Re[i], _mm256_add_pd(_mm256_loadu_pd(&this->m_Re[i]),
										 _mm256_loadu_pd(&x.m_Re[i])));
		_mm256_storeu_pd(&this->m_Im[i], _mm256_add_pd(_mm256_loadu_pd(&this->m_Im[i]),
										 _mm256_loadu_pd(&x.m_Im[i])));
	}
	// Second pass Re and Im horizontal summation
	
	for (uint64_t i = 0ULL; i != this->m_nsize; i += 4ULL) {
#if (LAM_MAN_PREFETCH) == 1
		AVXCOMPLEX_PREFETCH_FROM_OBJ(x, i, 4ULL, _MM_HINT_T0)
		
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
#if (LAM_DEBUG_ON) == 1
	_ASSERTE(mag != NULL && 
			this->m_nsize == size);
#else
	if (mag == NULL ||
		this->m_nsize != size) {
#if (PRINT_CALLSTACK_ON_ERROR) == 1
		StackWalker sw{};
		sw.ShowCallstack();
#endif	
		throw std::invalid_argument("AVXVComplex1D::vcmag [loc:615] --> Invalid argument or null pointer!!");
	}
#endif
	uint64_t i;
	for ( i = 0ULL; i != ROUND_TO_FOUR(m_nsize,4ULL); i += 4ULL) {

#if (LAM_CACHE_MEM_STORES) == 1
		_mm256_storeu_pd(&mag[i], _mm256_sqrt_pd(_mm256_add_pd(_mm256_mul_pd(_mm256_loadu_pd(&this->m_Re[i]),
			                      _mm256_loadu_pd(&this->m_Re[i])),_mm256_mul_pd(_mm256_loadu_pd(&this->m_Im[i]),
			                      _mm256_loadu_pd(&this->m_Im[i])))));
#else
		_mm256_stream_pd(&mag[i], _mm256_sqrt_pd(_mm256_add_pd(_mm256_mul_pd(_mm256_loadu_pd(&this->m_Re[i]),
			_mm256_loadu_pd(&this->m_Re[i])), _mm256_mul_pd(_mm256_loadu_pd(&this->m_Im[i]),
			_mm256_loadu_pd(&this->m_Im[i])))));
#endif
	}
	for (; i != m_nsize; ++i) {
		mag[i] = std::sqrt((m_Re[i]*m_Re[i]) + (m_Im[i]*m_Im[i]));
	}
}	

void
lam::math::AVXVComplex1D::vcdeg(_Inout_ double* __restrict vdeg,
							    _In_ const uint64_t size) {
#if (LAM_DEBUG_ON) == 1
	_ASSERTE(vdeg != NULL && 
			this->m_nsize == size);
#else
	if (vdeg == NULL ||
		this->m_nsize != size) {
#if (PRINT_CALLSTACK_ON_ERROR) == 1
		StackWalker sw{};
		sw.ShowCallstack();
#endif	
		throw std::invalid_argument("AVXVComplex1D::vcdeg [loc:639] --> Invalid argument or null pointer!!");
	}
#endif
	const __m256d vrad_to_deg( _mm256_set1_pd(57.29577951308092));
	// Not checking for 0.0 values in *this
	uint64_t i;
#if (LAM_MAN_PREFETCH) == 1
#pragma noprefetch
#endif
	for ( i = 0ULL; i != ROUND_TO_FOUR(m_nsize,4ULL); i += 4ULL) {
#if LAM_MAN_PREFETCH == 1
		AVXCOMPLEX_PREFETCH_FROM_THIS(this,i,4ULL,_MM_HINT_T0)
		
#endif
#if LAM_CACHE_MEM_STORES == 1
		_mm256_storeu_pd(&vdeg[i], _mm256_mul_pd(vrad_to_deg, _mm256_atan2_pd(_mm256_loadu_pd(&this->m_Re[i]),
								   _mm256_loadu_pd(&this->m_Im[i]))));
#else		
		_mm256_stream_pd(&vdeg[i], _mm256_mul_pd(vrad_to_deg, _mm256_atan2_pd(_mm256_loadu_pd(&this->m_Re[i]),
								  _mm256_loadu_pd(&this->m_Im[i]))));
#endif		 
	}
	for (; i != m_nsize; ++i) {
		vdeg[i] = 57.29577951308092 * std::atan2(m_Re[i], m_Im[i]);
	}
}	

void 
lam::math::AVXVComplex1D::vcrad(_Inout_ double* __restrict vrad,
								_In_ const uint64_t size) {
#if (LAM_DEBUG_ON) == 1
	_ASSERTE(vrad != NULL && 
			 this->m_nsize == size);
#else
	if (vrad == NULL ||
		this->m_nsize != size) {
#if (PRINT_CALLSTACK_ON_ERROR) == 1
		StackWalker sw{};
		sw.ShowCallstack();
#endif
		throw std::invalid_argument("AVXVComplex1D::vcrad [loc:660] --> Invalid argument or null pointer!!");
	}
#endif
	// Not checking for 0.0 values in *this
	uint64_t i;
#if (LAM_MAN_PREFETCH) == 1
#pragma noprefetch
#endif
	for ( i = 0ULL; i != ROUND_TO_FOUR(m_nsize,4ULL); i += 4ULL) {
#if (LAM_MAN_PREFETCH) == 1
		AVXCOMPLEX_PREFETCH_FROM_THIS(this,i,4ULL,_MM_HINT_T0)
		
#endif
#if (LAM_CACHE_MEM_STORES) == 1
		_mm256_storeu_pd(&vrad[i], _mm256_atan2_pd(_mm256_loadu_pd(&this->m_Re[i]),
								   _mm256_loadu_pd(&this->m_Im[i])));
#else
		_mm256_stream_pd(&vrad[i], _mm256_atan2_pd(_mm256_loadu_pd(&this->m_Re[i]),
			_mm256_loadu_pd(&this->m_Im[i])));
#endif		
	}
	for (; i != m_nsize; ++i) 
		vrad[i] = std::atan2(m_Re[i],m_Im[i]);
	
}

void 
lam::math::AVXVComplex1D::vcpow(_Inout_ double* __restrict vpow,
							    _In_ const uint64_t size) {
#if (LAM_DEBUG_ON) == 1
	_ASSERTE(vpow != NULL && 
		    this->m_nsize == size);
#else
	if (vpow == NULL ||
		this->m_nsize != size) {
#if (PRINT_CALLSTACK_ON_ERROR) == 1
		StackWalker sw{};
		sw.ShowCallstack();
#endif
		throw std::invalid_argument("AVXVComplex1D::vcpow [loc:684] --> Invalid argument or null pointer!!");
	}
#endif
	uint64_t i;
	for ( i = 0ULL; i != ROUND_TO_FOUR(m_nsize,4ULL); i += 4ULL) {
#if (LAM_MAN_PREFETCH) == 1
		AVXCOMPLEX_PREFETCH_FROM_THIS(this,i,4ULL,_MM_HINT_T0)
		
#endif
#if (LAM_CACHE_MEM_STORES) == 1
		_mm256_storeu_pd(&vpow[i], _mm256_add_pd(_mm256_mul_pd(_mm256_loadu_pd(&this->m_Re[i]),
			    _mm256_loadu_pd(&this->m_Re[i])),_mm256_mul_pd(_mm256_loadu_pd(&this->m_Im[i]),
			    _mm256_loadu_pd(&this->m_Im[i]))));
#else
		_mm256_stream_pd(&vpow[i], _mm256_add_pd(_mm256_mul_pd(_mm256_loadu_pd(&this->m_Re[i]),
			_mm256_loadu_pd(&this->m_Re[i])), _mm256_mul_pd(_mm256_loadu_pd(&this->m_Im[i]),
			_mm256_loadu_pd(&this->m_Im[i]))));
#endif
	}
	for (; i != m_nsize; ++i)
		vpow[i] = (m_Re[i] * m_Re[i]) + (m_Im[i] * m_Im[i]);
}

	









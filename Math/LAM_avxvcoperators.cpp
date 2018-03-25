
//
// LAM_avxvcoperators -- Implementation
//

#include "LAM_avxvcoperators.h"
#include "../LAM_config.h"
#if (PRINT_CALLSTACK_ON_ERROR) == 1
#include "../System/StackWalker.h"
#endif

#if !defined (AVXVCOPERATORS_PREFETCH_FROM_OBJS)
#define AVXVCOPERATORS_PREFETCH_FROM_OBJS(obj1,obj2,idx,off,hint) \
	_mm_prefetch(reinterpret_cast<const char*>(&(obj1).m_Re[(idx)+(off)]),(hint)); \
	_mm_prefetch(reinterpret_cast<const char*>(&(obj2).m_Re[(idx)+(off)]),(hint)); \
	_mm_prefetch(reinterpret_cast<const char*>(&(obj1).m_Im[(idx)+(off)]),(hint)); \
	_mm_prefetch(reinterpret_cast<const char*>(&(obj2).m_Im[(idx)+(off)]),(hint));
#endif

#if !defined (AVXVCOPERATORS_PREFETCH_FROM_OBJ_PTR)
#define AVXVCOPERATORS_PREFETCH_FROM_OBJ_PTR(obj,ptr,idx,off,hint) \
	_mm_prefetch(reinterpret_cast<const char*>(&(obj).m_Re[(idx)+(off)]), (hint)); \
	_mm_prefetch(reinterpret_cast<const char*>(&(ptr)[(idx)+(off)]), (hint));	   \
	_mm_prefetch(reinterpret_cast<const char*>(&(obj).m_Im[(idx)+(off)]), (hint));
#endif

lam::math::AVXVComplex1D
lam::math::operator+(_In_ const AVXVComplex1D &v1,
					 _In_ const AVXVComplex1D &v2) {
#if (LAM_DEBUG_ON) == 1
	_ASSERTE(v1.m_nsize == v2.m_nsize);
#else
	if(v1.m_nsize != v2.m_nsize) {
		throw std::invalid_argument("lam::math::operator+ [loc:15]: v1.get_nsize() != v2.get_nsize()");
	}
#endif
	AVXVComplex1D ret{v1.m_nsize};
    uint64_t i;	
	for ( i = 0ULL; i != ROUND_TO_FOUR(v1.m_nsize,4ULL); i += 8ULL) {
#if (LAM_MAN_PREFETCH) == 1
		AVXVCOPERATORS_PREFETCH_FROM_OBJS(v1,v2,i,4ULL,_MM_HINT_T0)
#endif
#if (LAM_CACHE_MEM_STORES) == 1
		// Using AVX for comparison.
		// Unrolled 2x in order to match perfectly
		// per core 2 load operations per cycle.
		_mm256_storeu_pd(&ret.m_Re[i + 0ULL], _mm256_add_pd(_mm256_loadu_pd(&v1.m_Re[i+0ULL]),
			_mm256_loadu_pd(&v2.m_Re[i+0ULL])));
		_mm256_storeu_pd(&ret.m_Re[i + 4ULL], _mm256_add_pd(_mm256_loadu_pd(&v1.m_Re[i + 4ULL]),
			_mm256_loadu_pd(&v2.m_Re[i + 4ULL])));
		_mm256_storeu_pd(&ret.m_Im[i + 0ULL], _mm256_add_pd(_mm256_loadu_pd(&v1.m_Im[i+0ULL]),
			_mm256_loadu_pd(&v2.m_Im[i+0ULL])));
		_mm256_storeu_pd(&ret.m_Im[i + 4ULL], _mm256_add_pd(_mm256_loadu_pd(&v1.m_Im[i + 4ULL]),
			_mm256_loadu_pd(&v2.m_Im[i + 4ULL])));
#else
	//	Do not pollute cache on memory stores
	//  You must be sure that stores will not be
	// used later, so do not keep them in cache.
		_mm256_stream_pd(&ret.m_Re[i + 0ULL], _mm256_add_pd(_mm256_loadu_pd(&v1.m_Re[i + 0ULL]),
			_mm256_loadu_pd(&v2.m_Re[i + 0ULL])));
		_mm256_stream_pd(&ret.m_Re[i + 4ULL], _mm256_add_pd(_mm256_loadu_pd(&v1.m_Re[i + 4ULL]),
			_mm256_loadu_pd(&v2.m_Re[i + 4ULL])));
		_mm256_stream_pd(&ret.m_Im[i + 0ULL], _mm256_add_pd(_mm256_loadu_pd(&v1.m_Im[i + 0ULL]),
			_mm256_loadu_pd(&v2.m_Im[i + 0ULL])));
		_mm256_stream_pd(&ret.m_Im[i + 4ULL], _mm256_add_pd(_mm256_loadu_pd(&v1.m_Im[i + 4ULL]),
			_mm256_loadu_pd(&v2.m_Im[i + 4ULL])));
#endif
	}
	for (; i != ret.m_nsize; ++i) {
		ret.m_Re[i] = v1.m_Re[i] + v2.m_Re[i];
		ret.m_Im[i] = v1.m_Im[i] + v2.m_Im[i];
	}
	return (ret);
}

lam::math::AVXVComplex1D
lam::math::operator+(_In_ const AVXVComplex1D &v1,
					 _In_ const double* __restrict v2) {
#if (LAM_DEBUG_ON == 1)
	_ASSERTE(v2 != NULL);
#else
	if(v2 == NULL)
		throw std::invalid_argument("lam::math::operator+[loc:71]: v2 == NULL ");
#endif
	AVXVComplex1D ret{v1.m_nsize};
	uint64_t i;
	
	for ( i = 0ULL; i != ROUND_TO_FOUR(ret.m_nsize,4ULL); i += 8ULL) {
#if (LAM_MAN_PREFETCH) == 1
		AVXVCOPERATORS_PREFETCH_FROM_OBJ_PTR(v1, v2, ret.m_nsize, 4ULL, _MM_HINT_T0)
#endif
#if (LAM_CACHE_MEM_STORES) == 1
		// Using AVX for comparison.
		// Unrolled 2x in order to match perfectly
		// per core 2 load operations per cycle.

		_mm256_storeu_pd(&ret.m_Re[i + 0ULL], _mm256_add_pd(_mm256_loadu_pd(&v1.m_Re[i+0ULL]), 
										 _mm256_loadu_pd(&v2[i+0ULL])));
		_mm256_storeu_pd(&ret.m_Re[i + 4ULL], _mm256_add_pd(_mm256_loadu_pd(&v1.m_Re[i+4ULL]), 
										 _mm256_loadu_pd(&v2[i + 4ULL])));
#else
		//	Do not pollute cache on memory stores
		//  You must be sure that stores will not be
		// used later, so do not keep them in cache.
		_mm256_stream_pd(&ret.m_Re[i + 0ULL], _mm256_add_pd(_mm256_loadu_pd(&v1.m_Re[i + 0ULL]),
			_mm256_loadu_pd(&v2[i + 0ULL])));
		_mm256_stream_pd(&ret.m_Re[i + 4ULL], _mm256_add_pd(_mm256_loadu_pd(&v1.m_Re[i + 4ULL]),
			_mm256_loadu_pd(&v2[i + 4ULL])));
#endif
	}
	for (; i != ret.m_nsize; ++i) 
		ret.m_Re[i] = v1.m_Re[i] + v2[i];
	
	return (ret);
}

lam::math::AVXVComplex1D
lam::math::operator+(_In_ const double* __restrict v1,
					 _In_ const AVXVComplex1D &v2) {
#if LAM_DEBUG_ON == 1
	_ASSERTE(v1 != NULL);
#else
	if(v1 == NULL)
		throw std::invalid_argument("lam::math::operator+[loc:112]: v1 == NULL");
#endif
	AVXVComplex1D ret{v2.m_nsize};
	uint64_t i;
	for ( i = 0ULL; i != ROUND_TO_FOUR(ret.m_nsize,4ULL); i += 8ULL) {
#if (LAM_MAN_PREFETCH) == 1
		AVXVCOPERATORS_PREFETCH_FROM_OBJ_PTR(v2,v1,i,4ULL,_MM_HINT_T0)
#endif
#if (LAM_CACHE_MEM_STORES) == 1
		// Using AVX for comparison.
		// Unrolled 2x in order to match perfectly
		// per core 2 load operations per cycle.
		_mm256_storeu_pd(&ret.m_Re[i + 0ULL], _mm256_add_pd(_mm256_loadu_pd(&v1[i+0ULL]),
			_mm256_loadu_pd(&v2.m_Re[i+0ULL])));
		_mm256_storeu_pd(&ret.m_Re[i + 4ULL], _mm256_add_pd(_mm256_loadu_pd(&v1[i + 4ULL]),
			_mm256_loadu_pd(&v2.m_Re[i + 4ULL])));
#else
		//	Do not pollute cache on memory stores
		//  You must be sure that stores will not be
		// used later, so do not keep them in cache.
		_mm256_stream_pd(&ret.m_Re[i + 0ULL], _mm256_add_pd(_mm256_loadu_pd(&v1[i + 0ULL]),
			_mm256_loadu_pd(&v2.m_Re[i + 0ULL])));
		_mm256_stream_pd(&ret.m_Re[i + 4ULL], _mm256_add_pd(_mm256_loadu_pd(&v1[i + 4ULL]),
			_mm256_loadu_pd(&v2.m_Re[i + 4ULL])));
#endif
	}
	for (; i != ret.m_nsize; ++i)
		ret.m_Re[i] = v1[i] + v2.m_Re[i];

	return (ret);
}

lam::math::AVXVComplex1D
lam::math::operator-(_In_ const AVXVComplex1D &v1,
					 _In_ const AVXVComplex1D &v2) {
#if LAM_DEBUG_ON == 1
	_ASSERTE(v1.m_nsize == v2.m_nsize);
#else
	if(v1.get_nsize() != v2.get_nsize())
		throw std::invalid_argument("lam::math::operator- [loc:158]: v1.get_nsize() != v2.get_nsize()");
#endif
	AVXVComplex1D ret{v1.m_nsize};
	uint64_t i;
	for ( i = 0ULL; i != ROUND_TO_FOUR(ret.m_nsize,4ULL); i += 8ULL) {
#if (LAM_MAN_PREFETCH) == 1
		AVXVCOPERATORS_PREFETCH_FROM_OBJS(v1,v2,i,4ULL,_MM_HINT_T0)
#endif
#if (LAM_CACHE_MEM_STORES) == 1
		// Using AVX for comparison.
		// Unrolled 2x in order to match perfectly
		// per core 2 load operations per cycle.
		_mm256_storeu_pd(&ret.m_Re[i + 0ULL], _mm256_sub_pd(_mm256_loadu_pd(&v1.m_Re[i+0ULL]),
			_mm256_loadu_pd(&v2.m_Re[i+0ULL])));
		_mm256_storeu_pd(&ret.m_Re[i + 4ULL], _mm256_sub_pd(_mm256_loadu_pd(&v1.m_Re[i + 4ULL]),
			_mm256_loadu_pd(&v2.m_Re[i + 4ULL])));
		_mm256_storeu_pd(&ret.m_Im[i + 0ULL], _mm256_sub_pd(_mm256_loadu_pd(&v1.m_Im[i+0ULL]),
			_mm256_loadu_pd(&v2.m_Im[i+0ULL])));
		_mm256_storeu_pd(&ret.m_Im[i + 4ULL], _mm256_sub_pd(_mm256_loadu_pd(&v1.m_Im[i + 4ULL]),
			_mm256_loadu_pd(&v2.m_Im[i + 4ULL])));
#else
		//	Do not pollute cache on memory stores
		//  You must be sure that stores will not be
		// used later, so do not keep them in cache.
		_mm256_stream_pd(&ret.m_Re[i + 0ULL], _mm256_sub_pd(_mm256_loadu_pd(&v1.m_Re[i + 0ULL]),
			_mm256_loadu_pd(&v2.m_Re[i + 0ULL])));
		_mm256_stream_pd(&ret.m_Re[i + 4ULL], _mm256_sub_pd(_mm256_loadu_pd(&v1.m_Re[i + 4ULL]),
			_mm256_loadu_pd(&v2.m_Re[i + 4ULL])));
		_mm256_stream_pd(&ret.m_Im[i + 0ULL], _mm256_sub_pd(_mm256_loadu_pd(&v1.m_Im[i + 0ULL]),
			_mm256_loadu_pd(&v2.m_Im[i + 0ULL])));
		_mm256_stream_pd(&ret.m_Im[i + 4ULL], _mm256_sub_pd(_mm256_loadu_pd(&v1.m_Im[i + 4ULL]),
			_mm256_loadu_pd(&v2.m_Im[i + 4ULL])));
#endif
	}
	for (; i != ret.m_nsize; ++i) {
		ret.m_Re[i] = v1.m_Re[i] - v2.m_Re[i];
		ret.m_Im[i] = v1.m_Im[i] - v2.m_Im[i];
	}
	return (ret);
}

lam::math::AVXVComplex1D
lam::math::operator-(_In_ const AVXVComplex1D &v1,
					 _In_ const double* __restrict v2) {
#if (LAM_DEBUG_ON) == 1
	_ASSERTE(v2 != NULL);
#else
	if(v2 == NULL)
		throw std::invalid_argument("lam::math::operator- [loc:158]: v2 == NULL");
#endif
	AVXVComplex1D ret{v1.m_nsize};
	uint64_t i;
	for ( i = 0ULL; i != ROUND_TO_FOUR(ret.m_nsize,4ULL); i += 8ULL) {
#if (LAM_MAN_PREFETCH) == 1
		AVXVCOPERATORS_PREFETCH_FROM_OBJ_PTR(v1,v2,i,4ULL,_MM_HINT_T0)
#endif
#if (LAM_CACHE_MEM_STORES) == 1
		// Using AVX for comparison.
		// Unrolled 2x in order to match perfectly
		// per core 2 load operations per cycle.
		_mm256_storeu_pd(&ret.m_Re[i + 0ULL], _mm256_sub_pd(_mm256_loadu_pd(&v1.m_Re[i+0ULL]),
			_mm256_loadu_pd(&v2[i+0ULL])));
		_mm256_storeu_pd(&ret.m_Re[i + 4ULL], _mm256_sub_pd(_mm256_loadu_pd(&v1.m_Re[i+4ULL]),
			_mm256_loadu_pd(&v2[i + 4ULL])));
#else
		//	Do not pollute cache on memory stores
		//  You must be sure that stores will not be
		// used later, so do not keep them in cache.
		_mm256_stream_pd(&ret.m_Re[i + 0ULL], _mm256_sub_pd(_mm256_loadu_pd(&v1.m_Re[i + 0ULL]),
			_mm256_loadu_pd(&v2[i + 0ULL])));
		_mm256_stream_pd(&ret.m_Re[i + 4ULL], _mm256_sub_pd(_mm256_loadu_pd(&v1.m_Re[i + 4ULL]),
			_mm256_loadu_pd(&v2[i + 4ULL])));
#endif
	}
	for (; i != ret.m_nsize; ++i)
		ret.m_Re[i] = v1.m_Re[i] - v2[i];

	return (ret);
}

lam::math::AVXVComplex1D
lam::math::operator-(_In_ const double* __restrict v1,
					 _In_ const AVXVComplex1D &v2) {
#if LAM_DEBUG_ON == 1
	_ASSERTE(v1 != NULL);
#else
	if(v1 == NULL)
		throw std::invalid_argument("lam::math::operator- [loc:258]: v1 == NULL")
#endif
		AVXVComplex1D ret{v2.m_nsize};
		uint64_t i;
		for ( i = 0ULL; i != ROUND_TO_FOUR(ret.m_nsize,4ULL); i += 8ULL) {
#if (LAM_MAN_PREFETCH) == 1
			AVXVCOPERATORS_PREFETCH_FROM_OBJ_PTR(v2,v1,i,4ULL,_MM_HINT_T0)
#endif
#if LAM_CACHE_MEM_STORES == 1
			// Using AVX for comparison.
			// Unrolled 2x in order to match perfectly
			// per core 2 load operations per cycle.
			_mm256_storeu_pd(&ret.m_Re[i + 0ULL], _mm256_sub_pd(_mm256_loadu_pd(&v1[i+0ULL]),
				_mm256_loadu_pd(&v2.m_Re[i+0ULL])));
			_mm256_storeu_pd(&ret.m_Re[i + 4ULL], _mm256_sub_pd(_mm256_loadu_pd(&v1[i + 4ULL]),
				_mm256_loadu_pd(&v2.m_Re[i + 4ULL])));
#else
			//	Do not pollute cache on memory stores
			//  You must be sure that stores will not be
			// used later, so do not keep them in cache.
			_mm256_stream_pd(&ret.m_Re[i + 0ULL], _mm256_sub_pd(_mm256_loadu_pd(&v1[i + 0ULL]),
				_mm256_loadu_pd(&v2.m_Re[i + 0ULL])));
			_mm256_stream_pd(&ret.m_Re[i + 4ULL], _mm256_sub_pd(_mm256_loadu_pd(&v1[i + 4ULL]),
				_mm256_loadu_pd(&v2.m_Re[i + 4ULL])));
#endif
		}
		for (; i != ret.m_nsize; ++i)
			ret.m_Re[i] = v1[i] - v2.m_Re[i];

		return (ret);
}

lam::math::AVXVComplex1D 
lam::math::operator*(_In_ const AVXVComplex1D &v1,
					 _In_ const AVXVComplex1D &v2) {
#if LAM_DEBUG_ON == 1
	_ASSERTE(v1.m_nsize != v2.m_nsize);
#else
	if(v1.m_nsize != v2.m_nsize)
		throw std::invalid_argument("lam::math::operator* [loc:302]: v1.get_nsize() != v2.get_nsize()");
#endif
	AVXVComplex1D ret{v1.m_nsize};
	uint64_t i;
	for ( i = 0ULL; i != ROUND_TO_FOUR(ret.m_nsize,4ULL); i += 8ULL) {
#if (LAM_MAN_PREFETCH) == 1
		AVXVCOPERATORS_PREFETCH_FROM_OBJS(v1,v2,i,4ULL,_MM_HINT_T0)
#endif
#if (LAM_CACHE_MEM_STORES) == 1
		// Using AVX for comparison.
		// Unrolled 2x in order to match perfectly
		// per core 2 load operations per cycle.
		_mm256_storeu_pd(&ret.m_Re[i + 0ULL], _mm256_sub_pd(_mm256_mul_pd(_mm256_loadu_pd(&v1.m_Re[i+0ULL]),
			_mm256_loadu_pd(&v2.m_Re[i + 0ULL])), _mm256_mul_pd(_mm256_loadu_pd(&v1.m_Im[i+0ULL]),
			_mm256_loadu_pd(&v2.m_Im[i+0ULL]))));
		_mm256_storeu_pd(&ret.m_Re[i + 4ULL], _mm256_sub_pd(_mm256_mul_pd(_mm256_loadu_pd(&v1.m_Re[i + 4ULL]),
			_mm256_loadu_pd(&v2.m_Re[i + 4ULL])), _mm256_mul_pd(_mm256_loadu_pd(&v1.m_Im[i + 4ULL]),
			_mm256_loadu_pd(&v2.m_Im[i + 4ULL]))));
		_mm256_storeu_pd(&ret.m_Im[i + 0ULL], _mm256_add_pd(_mm256_mul_pd(_mm256_loadu_pd(&v1.m_Im[i+0ULL]),
			_mm256_loadu_pd(&v2.m_Re[i + 0ULL])), _mm256_mul_pd(_mm256_loadu_pd(&v1.m_Re[i+0ULL]),
			_mm256_loadu_pd(&v2.m_Im[i+0ULL]))));
		_mm256_storeu_pd(&ret.m_Im[i + 4ULL], _mm256_add_pd(_mm256_mul_pd(_mm256_loadu_pd(&v1.m_Im[i + 4ULL]),
			_mm256_loadu_pd(&v2.m_Re[i + 4ULL])), _mm256_mul_pd(_mm256_loadu_pd(&v1.m_Re[i + 4ULL]),
			_mm256_loadu_pd(&v2.m_Im[i + 4ULL]))));
#else
		//	Do not pollute cache on memory stores
		//  You must be sure that stores will not be
		// used later, so do not keep them in cache.
		_mm256_stream_pd(&ret.m_Re[i + 0ULL], _mm256_sub_pd(_mm256_mul_pd(_mm256_loadu_pd(&v1.m_Re[i + 0ULL]),
			_mm256_loadu_pd(&v2.m_Re[i + 0ULL])), _mm256_mul_pd(_mm256_loadu_pd(&v1.m_Im[i + 0ULL]),
			_mm256_loadu_pd(&v2.m_Im[i + 0ULL]))));
		_mm256_stream_pd(&ret.m_Re[i + 4ULL], _mm256_sub_pd(_mm256_mul_pd(_mm256_loadu_pd(&v1.m_Re[i + 4ULL]),
			_mm256_loadu_pd(&v2.m_Re[i + 4ULL])), _mm256_mul_pd(_mm256_loadu_pd(&v1.m_Im[i + 4ULL]),
			_mm256_loadu_pd(&v2.m_Im[i + 4ULL]))));
		_mm256_stream_pd(&ret.m_Im[i + 0ULL], _mm256_add_pd(_mm256_mul_pd(_mm256_loadu_pd(&v1.m_Im[i + 0ULL]),
			_mm256_loadu_pd(&v2.m_Re[i + 0ULL])), _mm256_mul_pd(_mm256_loadu_pd(&v1.m_Re[i + 0ULL]),
			_mm256_loadu_pd(&v2.m_Im[i + 0ULL]))));
		_mm256_stream_pd(&ret.m_Im[i + 4ULL], _mm256_add_pd(_mm256_mul_pd(_mm256_loadu_pd(&v1.m_Im[i + 4ULL]),
			_mm256_loadu_pd(&v2.m_Re[i + 4ULL])), _mm256_mul_pd(_mm256_loadu_pd(&v1.m_Re[i + 4ULL]),
			_mm256_loadu_pd(&v2.m_Im[i + 4ULL]))));
#endif
	}
	for (; i != ret.m_nsize; ++i) {
		ret.m_Re[i] = (v1.m_Re[i] * v2.m_Re[i]) - (v1.m_Im[i] * v2.m_Im[i]);
		ret.m_Im[i] = (v1.m_Im[i] * v2.m_Re[i]) + (v1.m_Re[i] * v2.m_Im[i]);
	}
	return (ret);
}

lam::math::AVXVComplex1D
lam::math::operator*(_In_ const AVXVComplex1D &v1,
					 _In_ const double* __restrict v2) {
#if LAM_DEBUG_ON == 1
	_ASSERTE( v2 != NULL);
#else
	if(v2 == NULL)
		throw std::invalid_argument("lam::math::operator* [loc:302]: v2 == NULL");
#endif
	AVXVComplex1D ret{v1.m_nsize};
	uint64_t i;
	for ( i = 0ULL; i != ROUND_TO_FOUR(ret.m_nsize,4ULL); i += 8ULL) {
#if (LAM_MAN_PREFETCH) == 1
		AVXVCOPERATORS_PREFETCH_FROM_OBJ_PTR(v1,v2,i,4ULL,_MM_HINT_T0)
#endif
#if (LAM_CACHE_MEM_STORES) == 1
		// Using AVX for comparison.
		// Unrolled 2x in order to match perfectly
		// per core 2 load operations per cycle.
		_mm256_storeu_pd(&ret.m_Re[i + 0ULL], _mm256_mul_pd(_mm256_loadu_pd(&v1.m_Re[i+0ULL]),
			_mm256_loadu_pd(&v2[i+0ULL])));
		_mm256_storeu_pd(&ret.m_Re[i + 4ULL], _mm256_mul_pd(_mm256_loadu_pd(&v1.m_Re[i + 4ULL]),
			_mm256_loadu_pd(&v2[i + 4ULL])));
		_mm256_storeu_pd(&ret.m_Im[i + 0ULL], _mm256_mul_pd(_mm256_loadu_pd(&v1.m_Im[i+0ULL]),
			_mm256_loadu_pd(&v2[i+0ULL])));
		_mm256_storeu_pd(&ret.m_Im[i + 4ULL], _mm256_mul_pd(_mm256_loadu_pd(&v1.m_Im[i + 4ULL]),
			_mm256_loadu_pd(&v2[i + 4ULL])));
#else
		//	Do not pollute cache on memory stores
		//  You must be sure that stores will not be
		// used later, so do not keep them in cache.
		_mm256_stream_pd(&ret.m_Re[i + 0ULL], _mm256_mul_pd(_mm256_loadu_pd(&v1.m_Re[i + 0ULL]),
			_mm256_loadu_pd(&v2[i + 0ULL])));
		_mm256_stream_pd(&ret.m_Re[i + 4ULL], _mm256_mul_pd(_mm256_loadu_pd(&v1.m_Re[i + 4ULL]),
			_mm256_loadu_pd(&v2[i + 4ULL])));
		_mm256_stream_pd(&ret.m_Im[i + 0ULL], _mm256_mul_pd(_mm256_loadu_pd(&v1.m_Im[i + 0ULL]),
			_mm256_loadu_pd(&v2[i + 0ULL])));
		_mm256_stream_pd(&ret.m_Im[i + 4ULL], _mm256_mul_pd(_mm256_loadu_pd(&v1.m_Im[i + 4ULL]),
			_mm256_loadu_pd(&v2[i + 4ULL])));
#endif
	}
	for (; i != ret.m_nsize; ++i) {
		ret.m_Re[i] = v1.m_Re[i] * v2[i];
		ret.m_Im[i] = v1.m_Im[i] * v2[i];
	}
	return (ret);
}

lam::math::AVXVComplex1D
lam::math::operator*(_In_ const double* __restrict v1,
					 _In_ const AVXVComplex1D &v2) {
#if LAM_DEBUG_ON == 1
	_ASSERTE(NULL != v1);
#else
	if(NULL == v1)
		throw std::invalid_argument("lam::math::operator* [loc:420]: NULL == v1");
#endif
	AVXVComplex1D ret{v2.m_nsize};
	uint64_t i;
	for ( i = 0ULL; i != ROUND_TO_FOUR(ret.m_nsize,4ULL); i += 8ULL) {
#if (LAM_MAN_PREFETCH) == 1
		AVXVCOPERATORS_PREFETCH_FROM_OBJ_PTR(v2,v1,i,4ULL,_MM_HINT_T0)
#endif
#if (LAM_CACHE_MEM_STORES) == 1
		// Using AVX for comparison.
		// Unrolled 2x in order to match perfectly
		// per core 2 load operations per cycle.
		_mm256_storeu_pd(&ret.m_Re[i + 0ULL], _mm256_mul_pd(_mm256_loadu_pd(&v1[i+0ULL]),
			_mm256_loadu_pd(&v2.m_Re[i+0ULL])));
		_mm256_storeu_pd(&ret.m_Re[i + 4ULL], _mm256_mul_pd(_mm256_loadu_pd(&v1[i + 4ULL]),
			_mm256_loadu_pd(&v2.m_Re[i + 4ULL])));
		_mm256_storeu_pd(&ret.m_Im[i + 0ULL], _mm256_mul_pd(_mm256_loadu_pd(&v1[i+0ULL]),
			_mm256_loadu_pd(&v2.m_Im[i+0ULL])));
		_mm256_storeu_pd(&ret.m_Im[i + 4ULL], _mm256_mul_pd(_mm256_loadu_pd(&v1[i + 4ULL]),
			_mm256_loadu_pd(&v2.m_Im[i + 4ULL])));
#else
		//	Do not pollute cache on memory stores
		//  You must be sure that stores will not be
		// used later, so do not keep them in cache.
		_mm256_stream_pd(&ret.m_Re[i + 0ULL], _mm256_mul_pd(_mm256_loadu_pd(&v1[i + 0ULL]),
			_mm256_loadu_pd(&v2.m_Re[i + 0ULL])));
		_mm256_stream_pd(&ret.m_Re[i + 4ULL], _mm256_mul_pd(_mm256_loadu_pd(&v1[i + 4ULL]),
			_mm256_loadu_pd(&v2.m_Re[i + 4ULL])));
		_mm256_stream_pd(&ret.m_Im[i + 0ULL], _mm256_mul_pd(_mm256_loadu_pd(&v1[i + 0ULL]),
			_mm256_loadu_pd(&v2.m_Im[i + 0ULL])));
		_mm256_stream_pd(&ret.m_Im[i + 4ULL], _mm256_mul_pd(_mm256_loadu_pd(&v1[i + 4ULL]),
			_mm256_loadu_pd(&v2.m_Im[i + 4ULL])));
#endif
	}
	for (; i != ret.m_nsize; ++i) {
		ret.m_Re[i] = v1[i] * v2.m_Re[i];
		ret.m_Im[i] = v1[i] * v2.m_Im[i];
	}
	return (ret);
}

#include "../LAM_common.h"

lam::math::AVXVComplex1D
lam::math::operator/(_In_ const AVXVComplex1D &v1,
					 _In_ const AVXVComplex1D &v2) {
	using namespace lam::common;
#if LAM_DEBUG_ON == 1
	_ASSERTE(v1.m_nsize == v2.m_nsize);
#else
	if(v1.m_nsize != v2.m__nsize)
		throw std::invalid_argument("lam::math::operator/ [loc:479]: v1.get_nsize() != v2.get_nsize()");
#endif
	if (vzero_check(v1.m_Re, v1.m_Im, v1.m_nsize) ||
		vzero_check(v2.m_Re, v2.m_Im, v2.m_nsize)) {
		throw std::domain_error("AVXVComplex1D::operator/ [loc:482] --> found '0.0' in AVXVComplex1D");
	}
	AVXVComplex1D ret{v1.m_nsize};
	uint64_t i;
	for ( i = 0ULL; i != ROUND_TO_FOUR(ret.m_nsize,4ULL); i += 8ULL) {
#if (LAM_MAN_PREFETCH) == 1
		AVXVCOPERATORS_PREFETCH_FROM_OBJS(v1,v2,i,4ULL,_MM_HINT_T0)
#endif
#if (LAM_DEBUG_ON) == 1
		// Using AVX for comparison.
		// Unrolled 2x in order to match perfectly
		// per core 2 load operations per cycle.
		__m256d tre1 = _mm256_add_pd(_mm256_mul_pd(_mm256_loadu_pd(&v1.m_Re[i+0ULL]),
			_mm256_loadu_pd(&v2.m_Im[i+0ULL])), _mm256_mul_pd(_mm256_loadu_pd(&v1.m_Im[i+0ULL]),
			_mm256_loadu_pd(&v2.m_Im[i+0ULL])));
		__m256d tre2 = _mm256_add_pd(_mm256_mul_pd(_mm256_loadu_pd(&v1.m_Re[i + 4ULL]),
			_mm256_loadu_pd(&v2.m_Im[i + 4ULL])), _mm256_mul_pd(_mm256_loadu_pd(&v1.m_Im[i + 4ULL]),
			_mm256_loadu_pd(&v2.m_Im[i + 4ULL])));
		__m256d tim1 = _mm256_sub_pd(_mm256_mul_pd(_mm256_loadu_pd(&v1.m_Im[i+0ULL]),
			_mm256_loadu_pd(&v2.m_Im[i + 0ULL])), _mm256_mul_pd(_mm256_loadu_pd(&v1.m_Re[i+0ULL]),
			_mm256_loadu_pd(&v2.m_Im[i+0ULL])));
		__m256d tim2 = _mm256_sub_pd(_mm256_mul_pd(_mm256_loadu_pd(&v1.m_Im[i + 4ULL]),
			_mm256_loadu_pd(&v2.m_Im[i + 4ULL])), _mm256_mul_pd(_mm256_loadu_pd(&v1.m_Re[i + 4ULL]),
			_mm256_loadu_pd(&v2.m_Im[i + 4ULL])));
		__m256d den1 = _mm256_add_pd(_mm256_mul_pd(_mm256_loadu_pd(&v2.m_Re[i+0ULL]),
			_mm256_loadu_pd(&v2.m_Re[i + 0ULL])), _mm256_mul_pd(_mm256_loadu_pd(&v2.m_Im[i+0ULL]),
			_mm256_loadu_pd(&v2.m_Im[i+0ULL])));
		__m256d den2 = _mm256_add_pd(_mm256_mul_pd(_mm256_loadu_pd(&v2.m_Re[i + 4ULL]),
			_mm256_loadu_pd(&v2.m_Re[i + 4ULL])), _mm256_mul_pd(_mm256_loadu_pd(&v2.m_Im[i + 4ULL]),
			_mm256_loadu_pd(&v2.m_Im[i + 4ULL])));

		_mm256_storeu_pd(&ret.m_Re[i + 0ULL], _mm256_div_pd(tre1,den1));
		_mm256_storeu_pd(&ret.m_Re[i + 4ULL], _mm256_div_pd(tre2,den2));
		_mm256_storeu_pd(&ret.m_Im[i + 0ULL], _mm256_div_pd(tim1,den1));
		_mm256_storeu_pd(&ret.m_Im[i + 4ULL], _mm256_div_pd(tim2,den2));
#else
		//	Do not pollute cache on memory stores
		//  You must be sure that stores will not be
		// used later, so do not keep them in cache.
		__m256d tre1 = _mm256_add_pd(_mm256_mul_pd(_mm256_loadu_pd(&v1.m_Re[i + 0ULL]),
			_mm256_loadu_pd(&v2.m_Im[i + 0ULL])), _mm256_mul_pd(_mm256_loadu_pd(&v1.m_Im[i + 0ULL]),
			_mm256_loadu_pd(&v2.m_Im[i + 0ULL])));
		__m256d tre2 = _mm256_add_pd(_mm256_mul_pd(_mm256_loadu_pd(&v1.m_Re[i + 4ULL]),
			_mm256_loadu_pd(&v2.m_Im[i + 4ULL])), _mm256_mul_pd(_mm256_loadu_pd(&v1.m_Im[i + 4ULL]),
			_mm256_loadu_pd(&v2.m_Im[i + 4ULL])));
		__m256d tim1 = _mm256_sub_pd(_mm256_mul_pd(_mm256_loadu_pd(&v1.m_Im[i + 0ULL]),
			_mm256_loadu_pd(&v2.m_Im[i + 0ULL])), _mm256_mul_pd(_mm256_loadu_pd(&v1.m_Re[i + 0ULL]),
			_mm256_loadu_pd(&v2.m_Im[i + 0ULL])));
		__m256d tim2 = _mm256_sub_pd(_mm256_mul_pd(_mm256_loadu_pd(&v1.m_Im[i + 4ULL]),
			_mm256_loadu_pd(&v2.m_Im[i + 4ULL])), _mm256_mul_pd(_mm256_loadu_pd(&v1.m_Re[i + 4ULL]),
			_mm256_loadu_pd(&v2.m_Im[i + 4ULL])));
		__m256d den1 = _mm256_add_pd(_mm256_mul_pd(_mm256_loadu_pd(&v2.m_Re[i + 0ULL]),
			_mm256_loadu_pd(&v2.m_Re[i + 0ULL])), _mm256_mul_pd(_mm256_loadu_pd(&v2.m_Im[i + 0ULL]),
			_mm256_loadu_pd(&v2.m_Im[i + 0ULL])));
		__m256d den2 = _mm256_add_pd(_mm256_mul_pd(_mm256_loadu_pd(&v2.m_Re[i + 4ULL]),
			_mm256_loadu_pd(&v2.m_Re[i + 4ULL])), _mm256_mul_pd(_mm256_loadu_pd(&v2.m_Im[i + 4ULL]),
			_mm256_loadu_pd(&v2.m_Im[i + 4ULL])));

		_mm256_stream_pd(&ret.m_Re[i + 0ULL], _mm256_div_pd(tre1, den1));
		_mm256_stream_pd(&ret.m_Re[i + 4ULL], _mm256_div_pd(tre2, den2));
		_mm256_stream_pd(&ret.m_Im[i + 0ULL], _mm256_div_pd(tim1, den1));
		_mm256_stream_pd(&ret.m_Im[i + 4ULL], _mm256_div_pd(tim2, den2));
#endif
	}
	for (; i != ret.m_nsize; ++i) {
		double tre = (v1.m_Re[i] * v2.m_Im[i]) + (v1.m_Im[i] * v2.m_Im[i]);
		double tim = (v1.m_Im[i] * v2.m_Im[i]) - (v1.m_Re[i] * v2.m_Im[i]);
		double den = (v2.m_Re[i] * v2.m_Re[i]) + (v1.m_Im[i] * v2.m_Im[i]);
		ret.m_Re[i] = tre / den;
		ret.m_Im[i] = tim / den;
	}
	return (ret);
}

lam::math::AVXVComplex1D
lam::math::operator/(_In_ const double* __restrict v1,
					 _In_ const AVXVComplex1D &v2) {
	using namespace lam::common;
#if LAM_DEBUG_ON == 1
	_ASSERTE(NULL != v1);
#else
	if(NULL == v1)
		throw std::invalid_argument("lam::math::operator/ [loc:479]: NULL == v1");
#endif
	if (vzero_check1(v1, v2.m_nsize) ||
		vzero_check(v2.m_Re, v2.m_Im, v2.m_nsize)) {
		throw std::domain_error("AVXVComplex1D::operator/ [loc:569] --> found '0.0' in AVXVComplex1D");
	}
	AVXVComplex1D ret{v2.m_nsize};
	uint64_t i;
	for ( i = 0ULL; i != ROUND_TO_FOUR(ret.m_nsize,4ULL); i += 8ULL) {
#if (LAM_MAN_PREFETCH) == 1
		AVXVCOPERATORS_PREFETCH_FROM_OBJ_PTR(v2,v1,i,4ULL,_MM_HINT_T0)
#endif
#if (LAM_CACHE_MEM_STORES) == 1
	
		// Unrolled 2x in order to match perfectly
		// per core 2 load operations per cycle.
		_mm256_storeu_pd(&ret.m_Re[i + 0ULL], _mm256_div_pd(_mm256_loadu_pd(&v1[i+0ULL]),
			_mm256_loadu_pd(&v2.m_Re[i+0ULL])));
		_mm256_storeu_pd(&ret.m_Re[i + 4ULL], _mm256_div_pd(_mm256_loadu_pd(&v1[i+4ULL]),
			_mm256_loadu_pd(&v2.m_Re[i + 4ULL])));
		_mm256_storeu_pd(&ret.m_Im[i+0ULL], _mm256_div_pd(_mm256_loadu_pd(&v1[i+0ULL]), 
			_mm256_loadu_pd(&v2.m_Im[i+0ULL])));
		_mm256_storeu_pd(&ret.m_Im[i + 4ULL], _mm256_div_pd(_mm256_loadu_pd(&v1[i + 4ULL]),
			_mm256_loadu_pd(&v2.m_Im[i + 4ULL])));
#else
		//	Do not pollute cache on memory stores
		//  You must be sure that stores will not be
		// used later, so do not keep them in cache.
		_mm256_stream_pd(&ret.m_Re[i + 0ULL], _mm256_div_pd(_mm256_loadu_pd(&v1[i + 0ULL]),
			_mm256_loadu_pd(&v2.m_Re[i + 0ULL])));
		_mm256_stream_pd(&ret.m_Re[i + 4ULL], _mm256_div_pd(_mm256_loadu_pd(&v1[i + 4ULL]),
			_mm256_loadu_pd(&v2.m_Re[i + 4ULL])));
		_mm256_stream_pd(&ret.m_Im[i + 0ULL], _mm256_div_pd(_mm256_loadu_pd(&v1[i + 0ULL]),
			_mm256_loadu_pd(&v2.m_Im[i + 0ULL])));
		_mm256_stream_pd(&ret.m_Im[i + 4ULL], _mm256_div_pd(_mm256_loadu_pd(&v1[i + 4ULL]),
			_mm256_loadu_pd(&v2.m_Im[i + 4ULL])));
#endif
	}
	for (; i != ret.m_nsize; ++i) {
		ret.m_Re[i] = v1[i] / v2.m_Re[i];
		ret.m_Im[i] = v1[i] / v2.m_Im[i];
	}
	return (ret);
}

std::pair<double*,double*>
lam::math::operator==(_In_ const AVXVComplex1D &v1,
					  _In_ const AVXVComplex1D &v2) {
	 using namespace lam::common;
#if LAM_DEBUG_ON == 1
	_ASSERTE(v1.m_nsize == v2.m_nsize);
#else
	if(v1.m_nsize != v2.m_nsize)
		throw std::invalid_argument("lam::math::operator== [loc:628]: v1.get_nsize() == v2.get_nsize()");
#endif
	const uint64_t vlen = v1.m_nsize;
	double* __restrict pr1 = 
	reinterpret_cast<double*>(_mm_malloc(vlen*sizeof(double),align64B));
	double* __restrict pr2 =
	reinterpret_cast<double*>(_mm_malloc(vlen*sizeof(double),align64B));
	if ((NULL == pr1 && vlen != 0ULL) ||
		(NULL == pr2 && vlen != 0ULL)) {
#if (PRINT_CALLSTACK_ON_ERROR) == 1
		StackWalker sw{};
		sw.ShowCallstack();
#endif	
		ABORT_ON_ERROR("operator==(AVXVComplex1D &, AVXVComplex1D &) -- !!! Memory Allocation Failure !!! ", MALLOC_FAILED)
	}
	std::pair<double*,double*> pret;
	init_varray(pr1,vlen,-1.0);
	init_varray(pr2,vlen,-1.0);
	pret = std::make_pair(pr1,pr2);
	uint64_t i;
	for ( i = 0ULL; i != ROUND_TO_FOUR(vlen,4ULL); i += 8ULL) {
#if (LAM_MAN_PREFETCH) == 1
		AVXVCOPERATORS_PREFETCH_FROM_OBJS(v1,v2,i,4ULL,_MM_HINT_T0)
#endif
#if (LAM_CACHE_MEM_STORES) == 1
		
		// Unrolled 2x in order to match perfectly
		// per core 2 load operations per cycle.
		_mm256_storeu_pd(&pret.first[i + 0ULL], _mm256_cmp_pd(_mm256_loadu_pd(&v1.m_Re[i+0ULL]),
			_mm256_loadu_pd(&v2.m_Re[i+0ULL]),_CMP_EQ_OQ));
		_mm256_storeu_pd(&pret.first[i + 4ULL], _mm256_cmp_pd(_mm256_loadu_pd(&v1.m_Re[i + 4ULL]),
			_mm256_loadu_pd(&v2.m_Re[i + 4ULL]), _CMP_EQ_OQ));
		_mm256_storeu_pd(&pret.second[i + 0ULL], _mm256_cmp_pd(_mm256_loadu_pd(&v1.m_Im[i+0ULL]),
			_mm256_loadu_pd(&v2.m_Im[i+0ULL]),_CMP_EQ_OQ));
		_mm256_storeu_pd(&pret.second[i + 4ULL], _mm256_cmp_pd(_mm256_loadu_pd(&v1.m_Im[i + 4ULL]),
			_mm256_loadu_pd(&v2.m_Im[i + 4ULL]), _CMP_EQ_OQ));
#else
		//	Do not pollute cache on memory stores
		//  You must be sure that stores will not be
		// used later, so do not keep them in cache.
		_mm256_stream_pd(&pret.first[i + 0ULL], _mm256_cmp_pd(_mm256_loadu_pd(&v1.m_Re[i + 0ULL]),
			_mm256_loadu_pd(&v2.m_Re[i + 0ULL]), _CMP_EQ_OQ));
		_mm256_stream_pd(&pret.first[i + 4ULL], _mm256_cmp_pd(_mm256_loadu_pd(&v1.m_Re[i + 4ULL]),
			_mm256_loadu_pd(&v2.m_Re[i + 4ULL]), _CMP_EQ_OQ));
		_mm256_stream_pd(&pret.second[i + 0ULL], _mm256_cmp_pd(_mm256_loadu_pd(&v1.m_Im[i + 0ULL]),
			_mm256_loadu_pd(&v2.m_Im[i + 0ULL]), _CMP_EQ_OQ));
		_mm256_stream_pd(&pret.second[i + 4ULL], _mm256_cmp_pd(_mm256_loadu_pd(&v1.m_Im[i + 4ULL]),
			_mm256_loadu_pd(&v2.m_Im[i + 4ULL]), _CMP_EQ_OQ));
#endif
	}
	for (; i != vlen; ++i) {
		if (v1.m_Re[i] == v2.m_Re[i])
			pret.first[i] = 1.0;
		else
		   pret.first[i] = 0.0;

		if (v1.m_Im[i] == v2.m_Im[i])
			pret.second[i] = 1.0;
		else
			pret.second[i] = 0.0;
	}
	return (pret);
}

std::pair<double*,double*>
lam::math::operator!=(_In_ const AVXVComplex1D &v1,
					  _In_ const AVXVComplex1D &v2) {
	using namespace lam::common;
#if (LAM_DEBUG_ON) == 1
	_ASSERTE(v1.m_nsize == v2.m_nsize);
#else
	if (v1.m_nsize != v2.m_nsize)
		throw std::invalid_argument("lam::math::operator!= [loc:684]: v1.get_nsize() == v2.get_nsize()");
#endif
	const uint64_t vlen = v1.m_nsize;
	double* __restrict pr1 =
		reinterpret_cast<double*>(_mm_malloc(vlen*sizeof(double), align64B));
	double* __restrict pr2 =
		reinterpret_cast<double*>(_mm_malloc(vlen*sizeof(double), align64B));
	if ((NULL == pr1 && vlen != 0ULL) ||
		(NULL == pr2 && vlen != 0ULL)) {
#if (PRINT_CALLSTACK_ON_ERROR) == 1
		StackWalker sw{};
		sw.ShowCallstack();
#endif	
		ABORT_ON_ERROR("operator!=(AVXVComplex1D &, AVXVComplex1D &) -- !!! Memory Allocation Failure !!! ", MALLOC_FAILED)
	}
	std::pair<double*, double*> pret;
	init_varray(pr1, vlen, -1.0);
	init_varray(pr2, vlen, -1.0);
	pret = std::make_pair(pr1,pr2);
	uint64_t i;
	for (i = 0ULL; i != ROUND_TO_FOUR(vlen,4ULL); i += 8ULL) {
#if (LAM_MAN_PREFETCH) == 1
		AVXVCOPERATORS_PREFETCH_FROM_OBJS(v1,v2,i,4ULL,_MM_HINT_T0)
#endif
#if (LAM_CACHE_MEM_STORES) == 1

		// Unrolled 2x in order to match perfectly
		// per core 2 load operations per cycle.
		_mm256_storeu_pd(&pret.first[i + 0ULL], _mm256_cmp_pd(_mm256_loadu_pd(&v1.m_Re[i + 0ULL]),
			_mm256_loadu_pd(&v2.m_Re[i + 0ULL]), _CMP_NEQ_OQ));
		_mm256_storeu_pd(&pret.first[i + 4ULL], _mm256_cmp_pd(_mm256_loadu_pd(&v1.m_Re[i + 4ULL]),
			_mm256_loadu_pd(&v2.m_Re[i + 4ULL]), _CMP_NEQ_OQ));
		_mm256_storeu_pd(&pret.second[i + 0ULL], _mm256_cmp_pd(_mm256_loadu_pd(&v1.m_Im[i + 0ULL]),
			_mm256_loadu_pd(&v2.m_Im[i + 0ULL]), _CMP_NEQ_OQ));
		_mm256_storeu_pd(&pret.second[i + 4ULL], _mm256_cmp_pd(_mm256_loadu_pd(&v1.m_Im[i + 4ULL]),
			_mm256_loadu_pd(&v2.m_Im[i + 4ULL]), _CMP_NEQ_OQ));
#else
		//	Do not pollute cache on memory stores
		//  You must be sure that stores will not be
		// used later, so do not keep them in cache.
		_mm256_stream_pd(&pret.first[i + 0ULL], _mm256_cmp_pd(_mm256_loadu_pd(&v1.m_Re[i + 0ULL]),
			_mm256_loadu_pd(&v2.m_Re[i + 0ULL]), _CMP_NEQ_OQ));
		_mm256_stream_pd(&pret.first[i + 4ULL], _mm256_cmp_pd(_mm256_loadu_pd(&v1.m_Re[i + 4ULL]),
			_mm256_loadu_pd(&v2.m_Re[i + 4ULL]), _CMP_NEQ_OQ));
		_mm256_stream_pd(&pret.second[i + 0ULL], _mm256_cmp_pd(_mm256_loadu_pd(&v1.m_Im[i + 0ULL]),
			_mm256_loadu_pd(&v2.m_Im[i + 0ULL]), _CMP_NEQ_OQ));
		_mm256_stream_pd(&pret.second[i + 4ULL], _mm256_cmp_pd(_mm256_loadu_pd(&v1.m_Im[i + 4ULL]),
			_mm256_loadu_pd(&v2.m_Im[i + 4ULL]), _CMP_NEQ_OQ));
#endif
	}
	for (; i != vlen; ++i) {
		if (v1.m_Re[i] != v2.m_Re[i])
			pret.first[i] = 1.0;
		else
			pret.first[i] = 0.0;

		if (v1.m_Im[i] != v2.m_Im[i])
			pret.second[i] = 1.0;
		else
			pret.second[i] = 0.0;
	}
	return (pret);
}


#include "LAM_avx3vcprocedures.h"
#include "../LAM_config.h"

//
//	Implementation
//

// I think, that these macros should be put into some header file.
#if !defined (AVX3VCPROCEDURES_PREFETCH_FROM_OBJS)
#define AVX3VCPROCEDURES_PREFETCH_FROM_OBJS(obj1,obj2,idx,off,hint) \
	_mm_prefetch(reinterpret_cast<const char*>(&(obj1).m_Re[(idx)+(off)]), (hint)); \
	_mm_prefetch(reinterpret_cast<const char*>(&(obj2).m_Re[(idx)+(off)]), (hint)); \
	_mm_prefetch(reinterpret_cast<const char*>(&(obj1).m_Im[(idx)+(off)]), (hint)); \
	_mm_prefetch(reinterpret_cast<const char*>(&(obj2).m_Im[(idx)+(off)]), (hint));
#endif

#if !defined (AVX3VCPROCEDURES_PREFETCH_FROM_OBJ_PTR)
#define AVX3VCPROCEDURES_PREFETCH_FROM_OBJ_PTR(obj,ptr,idx,off,hint)  \
	_mm_prefetch(reinterpret_cast<const char*>(&(obj).m_Re[(idx)+(off)]), (hint)); \
	_mm_prefetch(reinterpret_cast<const char*>(&(ptr)[(idx)+(off)]), (hint));	   \
	_mm_prefetch(reinterpret_cast<const char*>(&(obj).m_Im[(idx)+(off)]), (hint));
#endif	


void
lam::math::avx3vcomplex_add(_Inout_ AVX512VComplex1D &c,
						    _In_ const AVX512VComplex1D &a,
						    _In_ const AVX512VComplex1D &b) {
	std::uint64_t i;
#if (LAM_MAN_PREFETCH) == 1
 std::size_t len = c.m_nsize;
#define CACHE_SIZE (len)
#pragma noprefetch
#endif
	for (i = 0ULL; i != ROUND_TO_EIGHT(c.m_nsize, 8ULL); i += 16ULL) {
#if (LAM_MAN_PREFETCH) == 1

#if (CACHE_SIZE) <= (L1_MAX_DOUBLES)
		AVX3VCPROCEDURES_PREFETCH_FROM_OBJS(a,b,i,8ULL,_MM_HINT_T0)
#else
		AVX3VCPROCEDURES_PREFETCH_FROM_OBJS(a,b,i,8ULL,_MM_HINT_T0)
		AVX3VCPROCEDURES_PREFETCH_FROM_OBJS(a,b,i,16ULL,_MM_HINT_T1)
#endif
#endif
#if (LAM_CACHE_MEM_STORES) == 1
		// Using AVX for comparison.
		// Unrolled 2x in order to match perfectly
		// per core 2 load operations per cycle.
		_mm512_store_pd(&c.m_Re[i + 0ULL], 
					_mm512_add_pd(_mm512_load_pd(&a.m_Re[i+0ULL]),
										_mm512_load_pd(&b.m_Re[i+0ULL])));
		_mm512_store_pd(&c.m_Re[i + 8ULL], 
					_mm512_add_pd(_mm512_load_pd(&a.m_Re[i + 8ULL]),
										_mm512_load_pd(&b.m_Re[i + 8ULL])));
		_mm512_store_pd(&c.m_Im[i + 0ULL], 
					_mm512_add_pd(_mm512_load_pd(&a.m_Im[i+0ULL]),
										_mm512_load_pd(&b.m_Im[i+0ULL])));
		_mm512_store_pd(&c.m_Im[i + 8ULL], 
					_mm512_add_pd(_mm512_load_pd(&a.m_Im[i + 8ULL]),
										_mm512_load_pd(&b.m_Im[i + 8ULL])));
#else
		//	Do not pollute cache on memory stores
		//  You must be sure that stores will not be
		// used later, so do not keep them in cache.
		_mm512_stream_pd(&c.m_Re[i + 0ULL], 
					_mm512_add_pd(_mm512_load_pd(&a.m_Re[i + 0ULL]),
										_mm512_load_pd(&b.m_Re[i + 0ULL])));
		_mm512_stream_pd(&c.m_Re[i + 8ULL], 
					_mm512_add_pd(_mm512_load_pd(&a.m_Re[i + 8ULL]),
										_mm512_load_pd(&b.m_Re[i + 8ULL])));
		_mm512_stream_pd(&c.m_Im[i + 0ULL], 
					_mm512_add_pd(_mm512_load_pd(&a.m_Im[i + 0ULL]),
										_mm512_load_pd(&b.m_Im[i + 0ULL])));
		_mm512_stream_pd(&c.m_Im[i + 8ULL], 
					_mm512_add_pd(_mm512_load_pd(&a.m_Im[i + 8ULL]),
										_mm512_load_pd(&b.m_Im[i + 8ULL])));
#endif		
 }
	for (; i != c.m_nsize; ++i) {
		c.m_Re[i] = a.m_Re[i] + b.m_Re[i];
		c.m_Im[i] = a.m_Im[i] + b.m_Im[i];
	}
}

void
lam::math::avx3vcomplex_add(_Inout_ AVX512VComplex1D &c,
						    _In_ const AVX512VComplex1D &a,
					        _In_ const double * __restrict b) {
	std::uint64_t i;							
#if (LAM_MAN_PREFETCH) == 1
	std::size_t len = c.m_nsize;
#define CACHE_SIZE (len)
#pragma noprefetch
#endif	
	
	for (i = 0ULL; i != ROUND_TO_EIGHT(c.m_nsize, 8ULL); i += 16ULL) {
#if (LAM_MAN_PREFETCH) == 1
#if (CACHE_SIZE) <= (L1_MAX_DOUBLES)
		AVX3VCPROCEDURES_PREFETCH_FROM_OBJ_PTR(a,b,i,8ULL,_MM_HINT_T0)
#else
		AVX3VCPROCEDURES_PREFETCH_FROM_OBJ_PTR(a, b, i, 8ULL, _MM_HINT_T0)
		AVX3VCPROCEDURES_PREFETCH_FROM_OBJ_PTR(a,b,i,16ULL,_MM_HINT_T1)
#endif
#endif
#if (LAM_CACHE_MEM_STORES) == 1
		// Using AVX for comparison.
		// Unrolled 2x in order to match perfectly
		// per core 2 load operations per cycle.
		_mm512_store_pd(&c.m_Re[i + 0ULL],
						_mm512_add_pd(_mm512_load_pd(&a.m_Re[i+0ULL]),
											_mm512_load_pd(&b[i+0ULL])));
		_mm512_store_pd(&c.m_Re[i + 8ULL], 
						_mm512_add_pd(_mm512_load_pd(&a.m_Re[i + 8ULL]),
											_mm512_load_pd(&b[i + 8ULL])));
		
#else
		//	Do not pollute cache on memory stores
		//  You must be sure that stores will not be
		// used later, so do not keep them in cache.
		_mm512_stream_pd(&c.m_Re[i + 0ULL], 
						_mm512_add_pd(_mm512_load_pd(&a.m_Re[i + 0ULL]),
											_mm512_load_pd(&b[i + 0ULL])));
		_mm512_stream_pd(&c.m_Re[i + 8ULL], 
						_mm512_add_pd(_mm512_load_pd(&a.m_Re[i + 8ULL]),
											_mm512_load_pd(&b[i + 8ULL])));
#endif
	}
	for (; i != c.m_nsize; ++i) 
		c.m_Re[i] = a.m_Re[i] + b[i];
}	

void
lam::math::avx3vcomplex_sub(_Inout_ AVX512VComplex1D &c,
						    _In_ const AVX512VComplex1D &a,
							_In_ const AVX512VComplex1D &b) {
	std::uint64_t i;
#if (LAM_MAN_PREFETCH) == 1
	std::size_t len = c.m_nsize;
#define CACHE_SIZE (len)
#pragma noprefetch
#endif	
	for (i = 0ULL; i != ROUND_TO_FOUR(c.m_nsize, 8ULL); i += 16ULL) {
#if (LAM_MAN_PREFETCH) == 1

#if (CACHE_SIZE) <= (L1_MAX_DOUBLES)
		AVX3VCPROCEDURES_PREFETCH_FROM_OBJS(a, b, i, 8ULL, _MM_HINT_T0)
#else
		AVX3VCPROCEDURES_PREFETCH_FROM_OBJS(a, b, i, 8ULL, _MM_HINT_T0)
		AVX3VCPROCEDURES_PREFETCH_FROM_OBJS(a, b, i, 16ULL, _MM_HINT_T1)
#endif
#endif
#if (LAM_CACHE_MEM_STORES) == 1
		// Using AVX for comparison.
		// Unrolled 2x in order to match perfectly
		// per core 2 load operations per cycle.
		_mm512_store_pd(&c.m_Re[i + 0ULL], 
		        _mm512_sub_pd(_mm512_load_pd(&a.m_Re[i+0ULL]),
		                             _mm512_load_pd(&b.m_Re[i+0ULL])));
		_mm512_store_pd(&c.m_Re[i + 8ULL],
				_mm512_sub_pd(_mm512_load_pd(&a.m_Re[i + 8ULL]),
									_mm512_load_pd(&b.m_Re[i + 8ULL])));
		_mm512_store_pd(&c.m_Im[i + 0ULL], 
				_mm512_sub_pd(_mm512_load_pd(&a.m_Im[i+0ULL]),
									_mm512_load_pd(&b.m_Im[i+0ULL])));
		_mm512_store_pd(&c.m_Im[i + 8ULL],
				_mm512_sub_pd(_mm512_load_pd(&a.m_Im[i + 8ULL]),
									_mm512_load_pd(&b.m_Im[i + 8ULL])));
#else
		//	Do not pollute cache on memory stores
		//  You must be sure that stores will not be
		// used later, so do not keep them in cache.
		_mm512_stream_pd(&c.m_Re[i + 0ULL],
				_mm512_sub_pd(_mm512_load_pd(&a.m_Re[i + 0ULL]),
									_mm512_load_pd(&b.m_Re[i + 0ULL])));
		_mm512_stream_pd(&c.m_Re[i + 8ULL],
				_mm512_sub_pd(_mm512_load_pd(&a.m_Re[i + 8ULL]),
									_mm512_load_pd(&b.m_Re[i + 8ULL])));
		_mm512_stream_pd(&c.m_Im[i + 0ULL],
				_mm512_sub_pd(_mm512_load_pd(&a.m_Im[i + 0ULL]),
									_mm512_load_pd(&b.m_Im[i + 0ULL])));
		_mm512_stream_pd(&c.m_Im[i + 8ULL],
				_mm512_sub_pd(_mm512_load_pd(&a.m_Im[i + 8ULL]),
									_mm512_load_pd(&b.m_Im[i + 8ULL])));
#endif
	}
	for (; i != c.m_nsize; ++i) {
		c.m_Re[i] = a.m_Re[i] - b.m_Re[i];
		c.m_Im[i] = a.m_Im[i] - b.m_Im[i];
	}
}

void
lam::math::avx3vcomplex_sub(_Inout_ AVX512VComplex1D &c,
							_In_ const AVX512VComplex1D &a,
							_In_ const double * __restrict b) {
	std::uint64_t i;
#if (LAM_MAN_PREFETCH) == 1
	std::size_t len = c.m_nsize;
#define CACHE_SIZE (len)
#pragma noprefetch
#endif	
	for (i = 0ULL; i != ROUND_TO_EIGHT(c.m_nsize, 8ULL); i += 16ULL) {
#if (LAM_MAN_PREFETCH) == 1
#if (CACHE_SIZE) <= (L1_MAX_DOUBLES)
		AVX3VCPROCEDURES_PREFETCH_FROM_OBJ_PTR(a, b, i, 8ULL, _MM_HINT_T0)
#else
		AVX3VCPROCEDURES_PREFETCH_FROM_OBJ_PTR(a, b, i, 8ULL, _MM_HINT_T0)
		AVX3VCPROCEDURES_PREFETCH_FROM_OBJ_PTR(a, b, i, 16ULL, _MM_HINT_T1)
#endif
#endif
#if (LAM_CACHE_MEM_STORES) == 1
		// Using AVX for comparison.
		// Unrolled 2x in order to match perfectly
		// per core 2 load operations per cycle.
		_mm512_store_pd(&c.m_Re[i+0ULL], 
						_mm512_sub_pd(_mm512_load_pd(&a.m_Re[i+0ULL]),
												_mm512_load_pd(&b[i+0ULL])));
		_mm512_store_pd(&c.m_Re[i + 8ULL],
						_mm512_sub_pd(_mm512_load_pd(&a.m_Re[i + 8ULL]),
											   _mm512_load_pd(&b[i + 8ULL])));
#else
		//	Do not pollute cache on memory stores
		//  You must be sure that stores will not be
		// used later, so do not keep them in cache.
		_mm512_stream_pd(&c.m_Re[i + 0ULL],
					_mm512_sub_pd(_mm512_load_pd(&a.m_Re[i + 0ULL]),
												_mm512_load_pd(&b[i + 0ULL])));
		_mm512_stream_pd(&c.m_Re[i + 8ULL],
					_mm512_sub_pd(_mm512_load_pd(&a.m_Re[i + 8ULL]),
												_mm512_load_pd(&b[i + 8ULL])));
#endif
	}
	for (; i != c.m_nsize; ++i) 
		c.m_Re[i] = a.m_Re[i] - b[i];
}

void
lam::math::avx3vcomplex_mul(_Inout_ AVX512VComplex1D &c,
							_In_ const AVX512VComplex1D &a,
							_In_ const AVX512VComplex1D &b) {
	std::uint64_t i;
#if (LAM_MAN_PREFETCH) == 1
	std::size_t len = c.m_nsize;
#define CACHE_SIZE (len)
#pragma noprefetch
#endif	
	for (i = 0ULL; i != ROUND_TO_EIGHT(c.m_nsize, 8ULL); i += 16ULL) {
#if (LAM_MAN_PREFETCH) == 1

#if (CACHE_SIZE) <= (L1_MAX_DOUBLES)
		AVX3VCPROCEDURES_PREFETCH_FROM_OBJS(a, b, i, 8ULL, _MM_HINT_T0)
#else
		AVX3VCPROCEDURES_PREFETCH_FROM_OBJS(a, b, i, 8ULL, _MM_HINT_T0)
		AVX3VCPROCEDURES_PREFETCH_FROM_OBJS(a, b, i, 16ULL, _MM_HINT_T1)
#endif
#endif
#if (LAM_CACHE_MEM_STORES) == 1
		// Using AVX for comparison.
		// Unrolled 2x in order to match perfectly
		// per core 2 load operations per cycle.
		_mm512_store_pd(&c.m_Re[i + 0ULL], 
				_mm512_sub_pd(_mm512_mul_pd(_mm512_load_pd(&a.m_Re[i+0ULL]),
					_mm512_load_pd(&b.m_Re[i + 0ULL])), _mm512_mul_pd(_mm512_load_pd(&a.m_Im[i+0ULL]),
																		_mm512_load_pd(&b.m_Im[i+0ULL]))));
		_mm512_store_pd(&c.m_Re[i + 8ULL],
			_mm512_sub_pd(_mm512_mul_pd(_mm512_load_pd(&a.m_Re[i + 8ULL]),
					_mm512_load_pd(&b.m_Re[i + 8ULL])), _mm512_mul_pd(_mm512_load_pd(&a.m_Im[i+8ULL]),
																	  _mm512_load_pd(&b.m_Im[i + 8ULL]))));

		_mm512_store_pd(&c.m_Im[i + 0ULL], 
				_mm512_add_pd(_mm512_mul_pd(_mm512_load_pd(&a.m_Im[i+0ULL]),
					_mm512_load_pd(&b.m_Im[i + 0ULL])), _mm512_mul_pd(_mm512_load_pd(&a.m_Re[i+0ULL]),
																		_mm512_load_pd(&b.m_Im[i+0ULL]))));

		_mm512_store_pd(&c.m_Im[i + 8ULL],
			_mm512_add_pd(_mm512_mul_pd(_mm512_load_pd(&a.m_Im[i + 8ULL]),
					_mm512_load_pd(&b.m_Im[i + 8ULL])), _mm512_mul_pd(_mm512_load_pd(&a.m_Re[i + 8ULL]),
																	   _mm512_load_pd(&b.m_Im[i + 8ULL]))));
#else
		//	Do not pollute cache on memory stores
		//  You must be sure that stores will not be
		// used later, so do not keep them in cache.
		_mm512_stream_pd(&c.m_Re[i + 0ULL],
				_mm512_sub_pd(_mm512_mul_pd(_mm512_load_pd(&a.m_Re[i + 0ULL]),
						_mm512_load_pd(&b.m_Re[i + 0ULL])), _mm512_mul_pd(_mm512_load_pd(&a.m_Im[i + 0ULL]),
																			_mm512_load_pd(&b.m_Im[i + 0ULL]))));
		_mm512_stream_pd(&c.m_Re[i + 8ULL],
				_mm512_sub_pd(_mm512_mul_pd(_mm512_load_pd(&a.m_Re[i + 8ULL]),
						_mm512_load_pd(&b.m_Re[i + 8ULL])), _mm512_mul_pd(_mm512_load_pd(&a.m_Im[i + 8ULL]),
																			_mm512_load_pd(&b.m_Im[i + 8ULL]))));

		_mm512_stream_pd(&c.m_Im[i + 0ULL],
				_mm512_add_pd(_mm512_mul_pd(_mm512_load_pd(&a.m_Im[i + 0ULL]),
						_mm512_load_pd(&b.m_Im[i + 0ULL])), _mm512_mul_pd(_mm512_load_pd(&a.m_Re[i + 0ULL]),
																			_mm512_load_pd(&b.m_Im[i + 0ULL]))));

		_mm512_stream_pd(&c.m_Im[i + 8ULL],
				_mm512_add_pd(_mm512_mul_pd(_mm512_load_pd(&a.m_Im[i + 8ULL]),
						_mm512_load_pd(&b.m_Im[i + 8ULL])), _mm512_mul_pd(_mm512_load_pd(&a.m_Re[i + 8ULL]),
																			_mm512_load_pd(&b.m_Im[i + 8ULL]))));
#endif
	}
	for (; i != c.m_nsize; ++i) {
		c.m_Re[i] = (a.m_Re[i] * b.m_Re[i]) - (a.m_Im[i] * b.m_Im[i]);
		c.m_Im[i] = (a.m_Im[i] * b.m_Re[i]) + (a.m_Re[i] * b.m_Im[i]);
	}
}

void
lam::math::avx3vcomplex_mul(_Inout_ AVX512VComplex1D &c,
							_In_ const AVX512VComplex1D &a,
							_In_ const double * __restrict b) {
	std::uint64_t i;
#if (LAM_MAN_PREFETCH) == 1
	std::size_t len = c.m_nsize;
#define CACHE_SIZE (len)
#pragma noprefetch
#endif	
	for (i = 0ULL; i != ROUND_TO_EIGHT(c.m_nsize, 8ULL); i += 16ULL) {
#if (LAM_MAN_PREFETCH) == 1
#if (CACHE_SIZE) <= (L1_MAX_DOUBLES)
		AVX3VCPROCEDURES_PREFETCH_FROM_OBJ_PTR(a, b, i, 8ULL, _MM_HINT_T0)
#else
		AVX3VCPROCEDURES_PREFETCH_FROM_OBJ_PTR(a, b, i, 8ULL, _MM_HINT_T0)
		AVX3VCPROCEDURES_PREFETCH_FROM_OBJ_PTR(a, b, i, 16ULL, _MM_HINT_T1)
#endif
#endif
#if (LAM_CACHE_MEM_STORES) == 1
		// Using AVX for comparison.
		// Unrolled 2x in order to match perfectly
		// per core 2 load operations per cycle.
		_mm512_store_pd(&c.m_Re[i + 0ULL], 
					_mm512_mul_pd(_mm512_load_pd(&a.m_Re[i+0ULL]),
											_mm512_load_pd(&b[i+0ULL])));
		_mm512_store_pd(&c.m_Re[i + 8ULL], 
					_mm512_mul_pd(_mm512_load_pd(&a.m_Re[i + 8ULL]),
											_mm512_load_pd(&b[i + 8ULL])));

		_mm512_store_pd(&c.m_Im[i + 0ULL], 
					_mm512_mul_pd(_mm512_load_pd(&a.m_Im[i+0ULL]),
											  _mm512_load_pd(&b[i+0ULL])));

		_mm512_store_pd(&c.m_Im[i + 8ULL],
					_mm512_mul_pd(_mm512_load_pd(&a.m_Im[i + 8ULL]),
											_mm512_load_pd(&b[i + 8ULL])));
#else
		//	Do not pollute cache on memory stores
		//  You must be sure that stores will not be
		// used later, so do not keep them in cache.
		_mm512_stream_pd(&c.m_Re[i + 0ULL],
					_mm512_mul_pd(_mm512_load_pd(&a.m_Re[i + 0ULL]),
										_mm512_load_pd(&b[i + 0ULL])));
		_mm512_stream_pd(&c.m_Re[i + 8ULL],
					_mm512_mul_pd(_mm512_load_pd(&a.m_Re[i + 8ULL]),
										_mm512_load_pd(&b[i + 8ULL])));

		_mm512_stream_pd(&c.m_Im[i + 0ULL],
					_mm512_mul_pd(_mm512_load_pd(&a.m_Im[i + 0ULL]),
										_mm512_load_pd(&b[i + 0ULL])));

		_mm512_stream_pd(&c.m_Im[i + 8ULL],
					_mm512_mul_pd(_mm512_load_pd(&a.m_Im[i + 8ULL]),
										_mm512_load_pd(&b[i + 8ULL])));
#endif
	}
	for (; i != c.m_nsize; ++i) {
		c.m_Re[i] = a.m_Re[i] * b[i];
		c.m_Im[i] = a.m_Im[i] * b[i];
	}
	      
}

void
lam::math::avx3vcomplex_div(_Inout_ AVX512VComplex1D &c,
						    _In_ const AVX512VComplex1D &a,
						    _In_ const AVX512VComplex1D &b,
							_In_ const AVX512VComplex1D &cb) {
	std::uint64_t i;
#if (LAM_MAN_PREFETCH) == 1
	std::size_t len = c.m_nsize;
#define CACHE_SIZE (len)
#pragma noprefetch
#endif	
	for (i = 0ULL; i != ROUND_TO_EIGHT(c.m_nsize, 8ULL); i += 16ULL) {
#if (LAM_MAN_PREFETCH) == 1

#if (CACHE_SIZE) <= (L1_MAX_DOUBLES)
		AVX3VCPROCEDURES_PREFETCH_FROM_OBJS(a, b, i, 8ULL, _MM_HINT_T0)
#else
		AVX3VCPROCEDURES_PREFETCH_FROM_OBJS(a, b, i, 8ULL, _MM_HINT_T0)
		AVX3VCPROCEDURES_PREFETCH_FROM_OBJS(a, b, i, 16ULL, _MM_HINT_T1)
#endif
#endif
#if (LAM_CACHE_MEM_STORES) == 1
		// Using AVX for comparison.
		// Unrolled 2x in order to match perfectly
		// per core 2 load operations per cycle.
		const __m512d re1 = _mm512_add_pd(_mm512_mul_pd(_mm512_load_pd(&a.m_Re[i+0ULL]),
				_mm512_load_pd(&b.m_Im[i + 0ULL])), _mm512_mul_pd(_mm512_load_pd(&a.m_Im[i+0ULL]),
																		_mm512_load_pd(&b.m_Im[i+0ULL])));
		const __m512d re2 = _mm512_add_pd(_mm512_mul_pd(_mm512_load_pd(&a.m_Re[i + 8ULL]),
				_mm512_load_pd(&b.m_Im[i + 8ULL])), _mm512_mul_pd(_mm512_load_pd(&a.m_Im[i + 8ULL]),
																	  _mm512_load_pd(&b.m_Im[i + 8ULL])));
		const __m512d im1 = _mm512_sub_pd(_mm512_mul_pd(_mm512_load_pd(&a.m_Im[i+0ULL]),
			   _mm512_load_pd(&b.m_Im[i + 0ULL])), _mm512_mul_pd(_mm512_load_pd(&a.m_Re[i+0ULL]),
																	    _mm512_load_pd(&b.m_Im[i+0ULL])));
		const __m512d im2 = _mm512_sub_pd(_mm512_mul_pd(_mm512_load_pd(&a.m_Im[i + 8ULL]),
				_mm512_load_pd(&b.m_Im[i + 8ULL])), _mm512_mul_pd(_mm512_load_pd(&a.m_Re[i + 8ULL]),
																	  _mm512_load_pd(&b.m_Im[i + 8ULL])));
		const __m512d den1 = _mm512_add_pd(_mm512_mul_pd(_mm512_load_pd(&b.m_Re[i+0ULL]),
				_mm512_load_pd(&cb.m_Re[i + 0ULL])), _mm512_mul_pd(_mm512_load_pd(&b.m_Im[i+0ULL]),
																	  _mm512_load_pd(&cb.m_Im[i+0ULL])));
		const __m512d den2 = _mm512_add_pd(_mm512_mul_pd(_mm512_load_pd(&b.m_Re[i + 8ULL]),
				_mm512_load_pd(&cb.m_Re[i + 8ULL])), _mm512_mul_pd(_mm512_load_pd(&b.m_Im[i + 8ULL]),
																	_mm512_load_pd(&cb.m_Im[i + 8ULL])));
		_mm512_store_pd(&c.m_Re[i + 0ULL], _mm512_div_pd(re1,den1));
		_mm512_store_pd(&c.m_Re[i + 8ULL], _mm512_div_pd(re2,den2));
		_mm512_store_pd(&c.m_Im[i + 0ULL], _mm512_div_pd(im1,den1));
		_mm512_store_pd(&c.m_Im[i + 8ULL], _mm512_div_pd(im2,den2));

#else
		//	Do not pollute cache on memory stores
		//  You must be sure that stores will not be
		// used later, so do not keep them in cache.
		const __m512d re1 = _mm512_add_pd(_mm512_mul_pd(_mm512_load_pd(&a.m_Re[i + 0ULL]),
				_mm512_load_pd(&b.m_Im[i + 0ULL])), _mm512_mul_pd(_mm512_load_pd(&a.m_Im[i + 0ULL]),
																	_mm512_load_pd(&b.m_Im[i + 0ULL])));
		const __m512d re2 = _mm512_add_pd(_mm512_mul_pd(_mm512_load_pd(&a.m_Re[i + 8ULL]),
				_mm512_load_pd(&b.m_Im[i + 8ULL])), _mm512_mul_pd(_mm512_load_pd(&a.m_Im[i + 8ULL]),
																	_mm512_load_pd(&b.m_Im[i + 8ULL])));
		const __m512d im1 = _mm512_sub_pd(_mm512_mul_pd(_mm512_load_pd(&a.m_Im[i + 0ULL]),
				_mm512_load_pd(&b.m_Im[i + 0ULL])), _mm512_mul_pd(_mm512_load_pd(&a.m_Re[i + 0ULL]),
																	_mm512_load_pd(&b.m_Im[i + 0ULL])));
		const __m512d im2 = _mm512_sub_pd(_mm512_mul_pd(_mm512_load_pd(&a.m_Im[i + 8ULL]),
				_mm512_load_pd(&b.m_Im[i + 8ULL])), _mm512_mul_pd(_mm512_load_pd(&a.m_Re[i + 8ULL]),
																	_mm512_load_pd(&b.m_Im[i + 8ULL])));
		const __m512d den1 = _mm512_add_pd(_mm512_mul_pd(_mm512_load_pd(&b.m_Re[i + 0ULL]),
				_mm512_load_pd(&cb.m_Re[i + 0ULL])), _mm512_mul_pd(_mm512_load_pd(&b.m_Im[i + 0ULL]),
																   _mm512_load_pd(&cb.m_Im[i + 0ULL])));
		const __m512d den2 = _mm512_add_pd(_mm512_mul_pd(_mm512_load_pd(&b.m_Re[i + 8ULL]),
				_mm512_load_pd(&cb.m_Re[i + 8ULL])), _mm512_mul_pd(_mm512_load_pd(&b.m_Im[i + 8ULL]),
																   _mm512_load_pd(&cb.m_Im[i + 8ULL])));
		_mm512_stream_pd(&c.m_Re[i + 0ULL], _mm512_div_pd(re1, den1));
		_mm512_stream_pd(&c.m_Re[i + 8ULL], _mm512_div_pd(re2, den2));
		_mm512_stream_pd(&c.m_Im[i + 0ULL], _mm512_div_pd(im1, den1));
		_mm512_stream_pd(&c.m_Im[i + 8ULL], _mm512_div_pd(im2, den2));
#endif
	}
	for (; i != c.m_nsize; ++i) {
		const double re = (a.m_Re[i] * b.m_Im[i]) + (a.m_Im[i] * b.m_Im[i]);
		const double im = (a.m_Im[i] * b.m_Im[i]) - (a.m_Re[i] * b.m_Im[i]);
		const double den = (b.m_Re[i] * cb.m_Re[i]) + (b.m_Im[i] * cb.m_Im[i]);
		c.m_Re[i] = re / den;
		c.m_Im[i] = im / den;
	}
}

void
lam::math::avx3vcomplex_div(_Inout_ AVX512VComplex1D &c,
							_In_ const AVX512VComplex1D &a,
							_In_ const double * __restrict b) {
	std::uint64_t i;
#if (LAM_MAN_PREFETCH) == 1
	std::size_t len = c.m_nsize;
#define CACHE_SIZE (len)
#pragma noprefetch
#endif	
	for (i = 0ULL; i != ROUND_TO_EIGHT(c.m_nsize, 8ULL); i += 16ULL) {
#if (LAM_MAN_PREFETCH) == 1
#if (CACHE_SIZE) <= (L1_MAX_DOUBLES)
		AVX3VCPROCEDURES_PREFETCH_FROM_OBJ_PTR(a, b, i, 8ULL, _MM_HINT_T0)
#else
		AVX3VCPROCEDURES_PREFETCH_FROM_OBJ_PTR(a, b, i, 8ULL, _MM_HINT_T0)
		AVX3VCPROCEDURES_PREFETCH_FROM_OBJ_PTR(a, b, i, 16ULL, _MM_HINT_T1)
#endif
#endif
#if (LAM_CACHE_MEM_STORES) == 1
		// Unrolled 2x in order to match perfectly
		// per core 2 load operations per cycle.
		// At expense of divider stall.
		_mm512_store_pd(&c.m_Re[i + 0ULL], 
			_mm512_div_pd(_mm512_load_pd(&a.m_Re[i+0ULL]),
									_mm512_load_pd(&b[i+0ULL])));
		_mm512_store_pd(&c.m_Re[i + 8ULL],
			_mm512_div_pd(_mm512_load_pd(&a.m_Re[i + 8ULL]),
								  _mm512_load_pd(&b[i + 8ULL])));
		_mm512_store_pd(&c.m_Im[i + 0ULL], 
			_mm512_div_pd(_mm512_load_pd(&a.m_Im[i+0ULL]),
									_mm512_load_pd(&b[i+0ULL])));
		_mm512_store_pd(&c.m_Im[i + 8ULL],
			_mm512_div_pd(_mm512_load_pd(&a.m_Im[i + 8ULL]),
								  _mm512_load_pd(&b[i + 8ULL])));
#else
		//	Do not pollute cache on memory stores
		//  You must be sure that stores will not be
		// used later, so do not keep them in cache.
		_mm512_stream_pd(&c.m_Re[i + 0ULL],
			_mm512_div_pd(_mm512_load_pd(&a.m_Re[i + 0ULL]),
									_mm512_load_pd(&b[i + 0ULL])));
		_mm512_stream_pd(&c.m_Re[i + 8ULL],
			_mm512_div_pd(_mm512_load_pd(&a.m_Re[i + 8ULL]),
									_mm512_load_pd(&b[i + 8ULL])));
		_mm512_stream_pd(&c.m_Im[i + 0ULL],
			_mm512_div_pd(_mm512_load_pd(&a.m_Im[i + 0ULL]),
									_mm512_load_pd(&b[i + 0ULL])));
		_mm512_stream_pd(&c.m_Im[i + 8ULL],
			_mm512_div_pd(_mm512_load_pd(&a.m_Im[i + 8ULL]),
									_mm512_load_pd(&b[i + 8ULL])));
#endif
	}
	for (; i != c.m_nsize; ++i) {
		c.m_Re[i] = a.m_Re[i] / b[i];
		c.m_Im[i] = a.m_Im[i] / b[i];
	}
}

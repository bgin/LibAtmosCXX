
#include "LAM_avx3complex.h"

#if (LAM_DEBUG_ON) == 1
#include "../LAM_debug.h"
#else
#include "../LAM_malloc.h"
#endif

#include "../LAM_error_macros.h"
#include "LAM_avx3complex_common.h"

//#include <zmmintrin.h>

//
// Implementation
//

//
//	Parametrized macros
//
#if (LAM_MAN_PREFETCH) == 1

#if !defined (AVX3_COMPLEX_PREFETCH_FROM_OBJ)
#define AVX3_COMPLEX_PREFETCH_FROM_OBJ(obj,idx,off,hint) \
	_mm_prefetch(reinterpret_cast<const char*>(&(obj).data.m_Re[(idx)+(off)]),(hint)); \
	_mm_prefetch(reinterpret_cast<const char*>(&(obj).data.m_Im[(idx)+(off)]),(hint));
#endif

#if !defined (AVX3_COMPLEX_PREFETCH_FROM_PTR)
#define AVX3_COMPLEX_PREFETCH_FROM_PTR(ptr,idx,off,hint) \
	_mm_prefetch(reinterpret_cast<const char*>(&(ptr)[(idx)+(off)]),(hint));
#endif
#endif


/*#if !defined (AVX3_COMPLEX_CHECK_FATAL_ERROR)
#define AVX3_COMPLEX_CHECK_FATAL_ERROR(ptr1,ptr2,nsize,msg) \
	 do {													  \
		if ((NULL  == (ptr1) && (nsize) != 0ULL) ||        \
		     (NULL == (ptr2) && (nsize) != 0ULL) ) {      \
			    StackWalker sw{};						  \
			    sw.ShowCallstack();						  \
			    ABORT_ON_ERROR(msg,MALLOC_FAILED)		  \
	 }											          \
  } while (0);
#endif*/

#if !defined (AVX3_COMPLEX_ADDITION)
#define AVX3_COMPLEX_ADDITION(out,v1,v2,idx,off) \
	(out) = _mm512_add_pd(_mm512_mul_pd(_mm512_load_pd(&(v1).data.m_Re[(idx)+(off)]), \
	_mm512_load_pd(&(v2).data.m_Re[(idx)+(off)])), _mm512_mul_pd(_mm512_load_pd(&(v1).data.m_Im[(idx)+(off)]), \
	_mm512_load_pd(&(v2).data.m_Im[(idx)+(off)])));
#endif

#if !defined (AVX3_COMPLEX_SUBTRACTION)
#define AVX3_COMPLEX_SUBTRACTION(out,v1,v2,idx,off) \
	(out) = _mm512_sub_pd(_mm512_mul_pd(_mm512_load_pd(&(v1).data.m_Im[(idx)+(off)]), \
	_mm512_load_pd(&(v2).data.m_Re[(idx)+(off)])), _mm512_mul_pd(_mm512_load_pd(&(v1).data.m_Re[(idx)+(off)]), \
	_mm512_load_pd(&(v2).data.m_Im[(idx)+(off)])));
#endif

	// Warning macro parameter v2 must be an exact copy
	// of parameter v1. This should done by calling class (AVX512VComplex1D)
	// Move Constructor.
#if !defined (AVX3_COMPLEX_MAGNITUDE)
#define AVX3_COMPLEX_MAGNITUDE(out,v1,v2,idx,off) \
	(out) = _mm512_sqrt_pd(_mm512_add_pd(_mm512_mul_pd(_mm512_load_pd(&(v1).data.m_Re[(idx)+(off)]), \
	_mm512_load_pd(&(v2).data.m_Re[(idx)+(off)])), _mm512_mul_pd(_mm512_load_pd(&(v1).data.m_Im[(idx)+(off)]), \
	_mm512_load_pd(&(v2).data.m_Im[(idx)+(off)]))));
#endif


lam::math
::AVX512VComplex1D::
AVX512VComplex1D() {
   data.m_Re = NULL;
   data.m_Im = NULL;
   data.m_nsize = 0;
}


lam::math
::AVX512VComplex1D::
AVX512VComplex1D(_In_ const int32_t nsize) {
	using namespace lam::common;
#if (LAM_DEBUG_ON) == 1
	data.m_Re = lam_edmalloca_dbg(static_cast<size_t>(nsize),align64B,__FILE__,__LINE__);
	data.m_Im = lam_edmalloca_dbg(static_cast<size_t>(nsize),align64B,__FILE__,__LINE__);
#else
	data.m_Re = lam_edmalloca(static_cast<size_t>(nsize),align64B);
	data.m_Im = lam_edmalloca(static_cast<size_t>(nsize),align64B);
#endif
    data.m_nsize = nsize;
	avx512_init_unroll8x(&data.m_Re[0], data.m_nsize, 0.0); // <<---- Memory 'first touch' here
	avx512_init_unroll8x(&data.m_Im[0], data.m_nsize, 0.0); // <<---- Memory 'first touch' here
}

lam::math::
AVX512VComplex1D
::AVX512VComplex1D(_In_ const double * __restrict Re,
				   _In_ const double * __restrict Im,
				   _In_ const int32_t nsize) {
	using namespace lam::common;
#if (LAM_DEBUG_ON) == 1
	data.m_Re = lam_edmalloca_dbg(static_cast<size_t>(nsize), align64B, __FILE__, __LINE__);
	data.m_Im = lam_edmalloca_dbg(static_cast<size_t>(nsize), align64B, __FILE__, __LINE__);
#else 
	data.m_Re = lam_edmalloca(static_cast<size_t>(nsize),align64B);
	data.m_Im = lam_edmalloca(static_cast<size_t>(nsize), align64B);
#endif
    data.m_nsize = nsize;
#if (USE_NT_STORES) == 1
	avx512_uncached_memmove(&data.m_Re[0], &Re[0], data.m_nsize);
	avx512_uncached_memmove(&data.m_Im[0], &Im[0], data.m_nsize);
#else
	avx512_cached_memmove(&data.m_Re[0], &Re[0], data.m_nsize);
	avx512_cached_memmove(&data.m_Im[0], &Im[0], data.m_nsize);
#endif
}



lam::math::AVX512VComplex1D::
AVX512VComplex1D(_In_ const AVX512VComplex1D &x) {
	using namespace lam::common;
#if (LAM_DEBUG_ON) == 1
	data.m_Re = lam_edmalloca_dbg(static_cast<size_t>(x.data.m_nsize), align64B, __FILE__, __LINE__);
	data.m_Im = lam_edmalloca_dbg(static_cast<size_t>(x.data.m_nsize), align64B, __FILE__, __LINE__);
#else
	data.m_Re = lam_edmalloca(static_cast<size_t>(x.m_data.m_nsize), align64B);
	data.m_Im = lam_edmalloca(static_cast<size_t>(x.m_data.m_nsize), align64B);
#endif
	data.m_nsize = x.data.m_nsize;
#if (USE_AVX3COMPLEX_NT_STORES) == 1
	avx512_uncached_memmove(&data.m_Re[0], &x.m_data.m_Re[0], data.m_nsize);
	avx512_uncached_memmove(&data.m_Im[0], &x.m_data.m_Im[0], data.m_nsize);
#else
	avx512_cached_memmove(&data.m_Re[0], &x.data.m_Re[0], data.m_nsize);
	avx512_cached_memmove(&data.m_Im[0], &x.data.m_Im[0], data.m_nsize);
#endif
}

lam::math
::AVX512VComplex1D::
AVX512VComplex1D(_In_ AVX512VComplex1D &&x) {
	data.m_Re    = &x.data.m_Re[0];
	data.m_Im    = &x.data.m_Im[0];
	data.m_nsize = x.data.m_nsize;
	x.data.m_Re = NULL;
	x.data.m_Im = NULL;
	x.data.m_nsize = 0;
}

	


lam::math
::AVX512VComplex1D::
~AVX512VComplex1D() {
#if (LAM_DEBUG_ON) == 1
	if (NULL  != data.m_Re) _aligned_free_dbg(data.m_Re); data.m_Re = NULL;
	if (NULL  != data.m_Im) _aligned_free_dbg(data.m_Im); data.m_Im = NULL;
#else
	if (NULL != data.m_Re) _mm_free(data.m_Re); data.m_Re = NULL;
	if (NULL != data.m_Im) _mm_free(data.m_Im); data.m_Im = NULL;
#endif
}	
	

lam::math::AVX512VComplex1D &
lam::math::AVX512VComplex1D
::operator=(_In_ const AVX512VComplex1D &x) {
	using namespace lam::common;
	if (this == &x) return (*this);
	if (data.m_nsize != x.data.m_nsize) {
#if (LAM_DEBUG_ON) == 1
		_aligned_free_dbg(data.m_Re);
		_aligned_free_dbg(data.m_Im);
#else
		_mm_free(data.m_Re);
		_mm_free(data.m_Im);
#endif
		data.m_nsize = 0; // Preserve an invariant here!!
		data.m_Re = NULL;
		data.m_Im = NULL;
	
#if (LAM_DEBUG_ON) == 1
		data.m_Re = lam_edmalloca_dbg(static_cast<size_t>(x.data.m_nsize),align64B,__FILE__,__LINE__);
		data.m_Im = lam_edmalloca_dbg(static_cast<size_t>(x.data.m_nsize),align64B,__FILE__,__LINE__);
#else
		data.m_Re = lam_edmalloca(static_cast<size_t>(x.data.m_nsize), align64B);
		data.m_Im = lam_edmalloca(static_cast<size_t>(x.data.m_nsize), align64B);
#endif	
   }
   else {
       
#if (USE_AVX3COMPLEX_NT_STORES) == 1
		avx512_uncached_memmove(&data.m_Re[0], &x.data.m_Re[0], x.data.m_nsize);
		avx512_uncached_memmove(&data.m_Im[0], &x.data.m_Im[0], x.data.m_nsize);
#else
		avx512_cached_memmove(&data.m_Re[0], &x.data.m_Re[0], x.data.m_nsize);
		avx512_cached_memmove(&data.m_Im[0], &x.data.m_Im[0], x.data.m_nsize);
#endif
   }
	
	return (*this);
}

lam::math::AVX512VComplex1D &
lam::math::AVX512VComplex1D
::operator=(_In_ AVX512VComplex1D &&x) {
	if (this == &x) return (*this);
#if (LAM_DEBUG_ON) == 1
	_aligned_free_dbg(data.m_Re);
	_aligned_free_dbg(data.m_Im);
#else		
	_mm_free(data.m_Re);
	_mm_free(data.m_Im);
#endif
	data.m_Re      = x.data.m_Re;
	data.m_Im      = x.data.m_Im;
	data.m_nsize   = x.data.m_nsize;
	x.data.m_Re    = NULL;
	x.data.m_Im    = NULL;
	x.data.m_nsize = 0;
	return (*this);
}	


lam::math
::AVX512VComplex1D
lam::math::operator+(_In_ const AVX512VComplex1D &x,
				     _In_ const AVX512VComplex1D &y) {
	
	if (x.data.m_nsize != y.data.m_nsize) {
		return (AVX512VComplex1D{});
	}
	AVX512VComplex1D ret_vec{x.data.m_nsize};
	int32_t i;

	for (i = 0; i != ROUND_TO_EIGHT(ret_vec.data.m_nsize, 8); i += 16)  {
		 // Linearly growing indices, no need for software prefetch.


		const __m512d zmm0 = _mm512_load_pd(&x.data.m_Re[i + 0]);
		const __m512d zmm1 = _mm512_load_pd(&y.data.m_Re[i + 0]);
#if (USE_AVX3COMPLEX_NT_STORES) == 1
		_mm512_stream_pd(&ret_vec.data.m_Re[i + 0], _mm512_add_pd(zmm0, zmm1));
#else
		_mm512_store_pd(&ret_vec.data.m_Re[i + 0], _mm512_add_pd(zmm0, zmm1));
#endif
		const __m512d zmm2 = _mm512_load_pd(&x.data.m_Re[i + 8]);
		const __m512d zmm3 = _mm512_load_pd(&y.data.m_Re[i + 8]);
#if (USE_AVX3COMPLEX_NT_STORES) == 1
		_mm512_stream_pd(&ret_vec.data.m_Re[i + 8LL], _mm512_add_pd(zmm2, zmm3));
#else
		_mm512_store_pd(&ret_vec.data.m_Re[i + 8], _mm512_add_pd(zmm2, zmm3));
#endif
		const __m512d zmm4 = _mm512_load_pd(&x.data.m_Im[i + 0]);
		const __m512d zmm5 = _mm512_load_pd(&y.data.m_Im[i + 0]);
#if (USE_AVX3COMPLEX_NT_STORES) == 1
		_mm512_stream_pd(&ret_vec.data.m_Im[i + 0], _mm512_add_pd(zmm4, zmm5));
#else
		_mm512_store_pd(&ret_vec.data.m_Im[i + 0], _mm512_add_pd(zmm4, zmm5));
#endif
		const __m512d zmm6 = _mm512_load_pd(&x.data.m_Im[i + 8]);
		const __m512d zmm7 = _mm512_load_pd(&y.data.m_Im[i + 8]);
#if (USE_AVX3COMPLEX_NT_STORES) == 1
		_mm512_stream_pd(&ret_vec.data.m_Im[i + 8], _mm512_add_pd(zmm6, zmm7));
#else
		_mm512_store_pd(&ret_vec.data.m_Im[i + 8], _mm512_add_pd(zmm6, zmm7));
#endif
		}	
	for (; i != ret_vec.data.m_nsize; ++i) {
		ret_vec.data.m_Re[i] = x.data.m_Re[i] + y.data.m_Re[i];
		ret_vec.data.m_Im[i] = x.data.m_Im[i] + y.data.m_Re[i];
	}
	return (ret_vec);
}		


	
	


lam::math::AVX512VComplex1D
lam::math::operator+(_In_ const AVX512VComplex1D &x,
					 _In_ const double * __restrict Re) {
	using namespace lam::common;
	if (!Is_ptr_aligned64(Re)) { return (AVX512VComplex1D{});}
	AVX512VComplex1D ret_vec{x.data.m_nsize};
	int32_t i;
	for (i = 0; i != ROUND_TO_EIGHT(ret_vec.data.m_nsize,8); i += 16) {

		const __m512d zmm0 = _mm512_load_pd(&x.data.m_Re[i + 0]);
		const __m512d zmm1 = _mm512_load_pd(&Re[i + 0]);
#if (USE_AVX3COMPLEX_NT_STORES) == 1
		_mm512_stream_pd(&ret_vec.data.m_Re[i + 0], _mm512_add_pd(zmm0, zmm1));
#else
		_mm512_store_pd(&ret_vec.data.m_Re[i + 0], _mm512_add_pd(zmm0, zmm1));
#endif
		const __m512d zmm2 = _mm512_load_pd(&x.data.m_Re[i + 8]);
		const __m512d zmm3 = _mm512_load_pd(&Re[i + 8]);
#if (USE_AVX3COMPLEX_NT_STORES) == 1
		_mm512_stream_pd(&ret_vec.data.m_Re[i + 8], _mm512_add_pd(zmm2, zmm3));
#else
		_mm512_store_pd(&ret_vec.data.m_Re[i + 8], _mm512_add_pd(zmm2, zmm3));
#endif
	}	
	for (; i != ret_vec.data.m_nsize; ++i) {
		ret_vec.data.m_Re[i] = x.data.m_Re[i] + Re[i];
	}
	return (ret_vec);
}	
	


lam::math
::AVX512VComplex1D
lam::math::operator-(_In_ const AVX512VComplex1D &x,
					 _In_ const AVX512VComplex1D &y) {
	if (x.data.m_nsize != y.data.m_nsize) {
		return (AVX512VComplex1D{});
	}
	AVX512VComplex1D ret_vec{x.data.m_nsize};
	int32_t i;
	for (i = 0; i != ROUND_TO_EIGHT(ret_vec.data.m_nsize,8); i += 16) {


		const __m512d zmm0 = _mm512_load_pd(&x.data.m_Re[i + 0]);
		const __m512d zmm1 = _mm512_load_pd(&y.data.m_Re[i + 0]);
#if (USE_AVX3COMPLEX_NT_STORES) == 1
		_mm512_stream_pd(&ret_vec.data.m_Re[i + 0], _mm512_sub_pd(zmm0, zmm1));
#else
		_mm512_store_pd(&ret_vec.data.m_Re[i + 0], _mm512_sub_pd(zmm0, zmm1));
#endif
		const __m512d zmm2 = _mm512_load_pd(&x.data.m_Re[i + 8]);
		const __m512d zmm3 = _mm512_load_pd(&y.data.m_Re[i + 8]);
#if (USE_AVX3COMPLEX_NT_STORES) == 1
		_mm512_stream_pd(&ret_vec.data.m_Re[i + 8], _mm512_sub_pd(zmm2, zmm3));
#else
		_mm512_store_pd(&ret_vec.data.m_Re[i + 8], _mm512_sub_pd(zmm2, zmm3));
#endif
		const __m512d zmm4 = _mm512_load_pd(&x.data.m_Im[i + 0]);
		const __m512d zmm5 = _mm512_load_pd(&y.data.m_Im[i + 0]);
#if (USE_AVX3COMPLEX_NT_STORES) == 1
		_mm512_stream_pd(&ret_vec.data.m_Im[i + 0], _mm512_sub_pd(zmm4, zmm5));
#else
		_mm512_store_pd(&ret_vec.data.m_Im[i + 0], _mm512_sub_pd(zmm4, zmm5));
#endif
		const __m512d zmm6 = _mm512_load_pd(&x.data.m_Im[i + 8]);
		const __m512d zmm7 = _mm512_load_pd(&y.data.m_Im[i + 8]);
#if (USE_AVX3COMPLEX_NT_STORES) == 1
		_mm512_stream_pd(&ret_vec.data.m_Im[i + 8], _mm512_sub_pd(zmm6, zmm7));
#else
		_mm512_store_pd(&ret_vec.data.m_Im[i + 8], _mm512_sub_pd(zmm6, zmm7));
#endif
	}
	for (; i != ret_vec.data.m_nsize; ++i) {
		ret_vec.data.m_Re[i] = x.data.m_Re[i] - y.data.m_Re[i];
		ret_vec.data.m_Im[i] = x.data.m_Im[i] - y.data.m_Im[i];
	}
	return (ret_vec);
}		

	


lam::math::AVX512VComplex1D
lam::math::operator-(_In_ const AVX512VComplex1D &x,
					 _In_ const double * __restrict Re) {
	using namespace lam::common;
	if (!Is_ptr_aligned64(Re)) { return (AVX512VComplex1D{});}
	AVX512VComplex1D ret_vec{x.data.m_nsize};
	int32_t i;
	for (i = 0; i != ROUND_TO_EIGHT(ret_vec.data.m_nsize,8); i += 16) {

	    
		const __m512d zmm0 = _mm512_load_pd(&x.data.m_Re[i + 0]);
		const __m512d zmm1 = _mm512_load_pd(&Re[i + 0]);
#if (USE_AVX3COMPLEX_NT_STORES) == 1
		_mm512_stream_pd(&ret_vec.data.m_Re[i + 0], _mm512_sub_pd(zmm0, zmm1));
#else
		_mm512_store_pd(&ret_vec.data.m_Re[i + 0], _mm512_sub_pd(zmm0, zmm1));
#endif
		const __m512d zmm2 = _mm512_load_pd(&x.data.m_Re[i + 8]);
		const __m512d zmm3 = _mm512_load_pd(&Re[i + 8]);
#if (USE_AVX3COMPLEX_NT_STORES) == 1
		_mm512_stream_pd(&ret_vec.data.m_Re[i + 8], _mm512_sub_pd(zmm2, zmm3));
#else
		_mm512_store_pd(&ret_vec.data.m_Re[i + 8], _mm512_sub_pd(zmm2, zmm3));
#endif		

	}
	for (; i != ret_vec.data.m_nsize; ++i) {
		ret_vec.data.m_Re[i] = x.data.m_Re[i] - Re[i];
	}
	return (ret_vec);
}

lam::math::AVX512VComplex1D
lam::math::operator*(_In_ const AVX512VComplex1D &x,
					 _In_ const AVX512VComplex1D &y) {
	if (x.data.m_nsize != y.data.m_nsize) {
		return (AVX512VComplex1D{});	
	}
	AVX512VComplex1D ret_vec{x.data.m_nsize};
	int32_t i;
	for (i = 0; i != ROUND_TO_EIGHT(ret_vec.data.m_nsize,8); i += 16) {

	
		const __m512d zmm0 = _mm512_load_pd(&x.data.m_Re[i+0]);
		const __m512d zmm1 = _mm512_load_pd(&y.data.m_Re[i+0]);
		const __m512d zmm2 = _mm512_load_pd(&x.data.m_Im[i+0]);
		const __m512d zmm3 = _mm512_load_pd(&y.data.m_Im[i+0]);
#if (USE_AVX3COMPLEX_NT_STORES) == 1
		_mm512_stream_pd(&ret_vec.data.m_Re[i + 0], _mm512_sub_pd(
			_mm512_mul_pd(zmm0, zmm1), _mm512_mul_pd(zmm2,zmm3)));
		_mm512_stream_pd(&ret_vec.data.m_Im[i + 0], _mm512_add_pd(
			_mm512_mul_pd(zmm2, zmm1), _mm512_mul_pd(zmm0, zmm3)));
#else
		_mm512_store_pd(&ret_vec.data.m_Re[i + 0], _mm512_sub_pd(
			_mm512_mul_pd(zmm0, zmm1), _mm512_mul_pd(zmm2, zmm3)));
		_mm512_store_pd(&ret_vec.data.m_Im[i + 0], _mm512_add_pd(
			_mm512_mul_pd(zmm2, zmm1), _mm512_mul_pd(zmm0, zmm3)));

#endif
		const __m512d zmm4 = _mm512_load_pd(&x.data.m_Re[i+8]);
		const __m512d zmm5 = _mm512_load_pd(&y.data.m_Re[i+8]);
		const __m512d zmm6 = _mm512_load_pd(&x.data.m_Im[i+8]);
		const __m512d zmm7 = _mm512_load_pd(&y.data.m_Im[i+8]);
#if (USE_AVX3COMPLEX_NT_STORES) == 1
		_mm512_stream_pd(&ret_vec.data.m_Re[i + 8], _mm512_sub_pd(
			_mm512_mul_pd(zmm4, zmm5), _mm512_mul_pd(zmm6,zmm7)));
		_mm512_stream_pd(&ret_vec.data.m_Im[i + 8], _mm512_add_pd(
			_mm512_mul_pd(zmm6, zmm5), _mm512_mul_pd(zmm4, zmm7)));
#else
		_mm512_store_pd(&ret_vec.data.m_Re[i + 8], _mm512_sub_pd(
			_mm512_mul_pd(zmm4, zmm5), _mm512_mul_pd(zmm6, zmm7)));
		_mm512_store_pd(&ret_vec.data.m_Im[i + 8], _mm512_add_pd(
			_mm512_mul_pd(zmm6, zmm5), _mm512_mul_pd(zmm4, zmm7)));
#endif		

	}

	for (; i != ret_vec.data.m_nsize; ++i) {
		ret_vec.data.m_Re[i] = (x.data.m_Re[i] * y.data.m_Re[i]) - (x.data.m_Im[i] * y.data.m_Im[i]);
		ret_vec.data.m_Im[i] = (x.data.m_Im[i] * y.data.m_Re[i]) + (x.data.m_Re[i] * y.data.m_Im[i]);
	}
	return (ret_vec);
}

lam::math::AVX512VComplex1D
lam::math::operator*(_In_ const AVX512VComplex1D &x,
					 _In_ const double * __restrict Re) {
	using namespace lam::common;
	if (!Is_ptr_aligned64(Re)) { return (AVX512VComplex1D{}); }
	AVX512VComplex1D ret_vec{x.data.m_nsize}; // <<-- here occurs Memory first touch.
	int32_t i;
	for (i = 0; i != ROUND_TO_EIGHT(ret_vec.data.m_nsize,8); i += 16) {

		__m512d zmm0 = _mm512_load_pd(&x.data.m_Re[i + 0]);
		__m512d zmm1 = _mm512_load_pd(&Re[i + 0]);
#if (USE_AVX3COMPLEX_NT_STORES) == 1
		_mm512_stream_pd(&ret_vec.data.m_Re[i + 0], _mm512_mul_pd(zmm0, zmm1));
#else
		_mm512_store_pd(&ret_vec.data.m_Re[i + 0], _mm512_mul_pd(zmm0, zmm1));
#endif
		__m512d zmm2 = _mm512_load_pd(&x.data.m_Re[i + 8]);
		__m512d zmm3 = _mm512_load_pd(&Re[i + 8]);
#if (USE_AVX3COMPLEX_NT_STORES) == 1
		_mm512_stream_pd(&ret_vec.data.m_Re[i + 8], _mm512_mul_pd(zmm2, zmm3));
#else
		_mm512_store_pd(&ret_vec.data.m_Re[i + 8], _mm512_mul_pd(zmm2, zmm3));
#endif
		__m512d zmm4 = _mm512_load_pd(&x.data.m_Im[i + 0]);
#if (USE_AVX3COMPLEX_NT_STORES) == 1
		_mm512_stream_pd(&ret_vec.data.m_Im[i + 0], _mm512_mul_pd(zmm4, zmm1));
#else
		_mm512_store_pd(&ret_vec.data.m_Im[i + 0], _mm512_mul_pd(zmm4, zmm1));
#endif
		__m512d zmm5 = _mm512_load_pd(&x.data.m_Im[i + 8]);
#if (USE_AVX3COMPLEX_NT_STORES) == 1
		_mm512_stream_pd(&ret_vec.data.m_Im[i + 8], _mm512_mul_pd(zmm5, zmm3));
#else
		_mm512_store_pd(&ret_vec.data.m_Im[i + 8], _mm512_mul_pd(zmm5, zmm3));
#endif
		

	}

	for (; i != ret_vec.data.m_nsize; ++i) {
		ret_vec.data.m_Re[i] = x.data.m_Re[i] * Re[i];
		ret_vec.data.m_Im[i] = x.data.m_Im[i] * Re[i];
	}
	return (ret_vec);
}

lam::math::AVX512VComplex1D
lam::math::operator/(_In_ const AVX512VComplex1D &x,
					 _In_ const AVX512VComplex1D &y) {
	if (x.data.m_nsize != y.data.m_nsize) { return (AVX512VComplex1D{}); }
	AVX512VComplex1D ret_vec{x.data.m_nsize}; // <<--- here memory first touch
	int32_t i;
	for (i = 0; i != ROUND_TO_EIGHT(ret_vec.data.m_nsize,8); i += 8) {
			// Will unrolling 2x not saturate divider unit.
			// We have two parallel division so at least second
			// operation will be pipelined at divider level.

		const __m512d zmm0 = _mm512_load_pd(&x.data.m_Re[i + 0]);
		const __m512d zmm1 = _mm512_load_pd(&y.data.m_Im[i + 0]);
		const __m512d zmm2 = _mm512_load_pd(&x.data.m_Im[i + 0]);
		const __m512d re_term1 = _mm512_add_pd(
			_mm512_mul_pd(zmm0, zmm1), _mm512_mul_pd(zmm2, zmm1));
		const __m512d re_term2 = _mm512_add_pd(
			_mm512_mul_pd(zmm2, zmm1), _mm512_mul_pd(zmm0, zmm1));
		const __m512d zmm3 = _mm512_load_pd(&y.data.m_Re[i + 0]);
		const __m512d den_term = _mm512_add_pd(
			_mm512_mul_pd(zmm3, zmm3), _mm512_mul_pd(zmm1, zmm1));
#if (USE_AVX3COMPLEX_NT_STORES) == 1
		_mm512_stream_pd(&ret_vec.data.m_Re[i + 0], _mm512_div_pd(re_term1, den_term));
#else
		_mm512_store_pd(&ret_vec.data.m_Re[i + 0], _mm512_div_pd(re_term1, den_term));
#endif
#if (USE_AVX3COMPLEX_NT_STORES) == 1
		_mm512_stream_pd(&ret_vec.data.m_Im[i + 0], _mm512_div_pd(re_term2, den_term));
#else
		_mm512_store_pd(&ret_vec.data.m_Im[i + 0], _mm512_div_pd(re_term2, den_term));
#endif

	}
	
	for (; i != ret_vec.data.m_nsize; ++i) {
		const double tre = (x.data.m_Re[i] * y.data.m_Im[i]) + (x.data.m_Im[i] * y.data.m_Im[i]);
		const double tim = (x.data.m_Im[i] * y.data.m_Im[i]) - (x.data.m_Re[i] * y.data.m_Im[i]);
		const double den = (y.data.m_Re[i] * y.data.m_Re[i]) + (y.data.m_Im[i] * y.data.m_Im[i]);
		ret_vec.data.m_Re[i] = tre / den;
		ret_vec.data.m_Im[i] = tim / den;
	}
}

lam::math::AVX512VComplex1D
lam::math::operator/(_In_ const  AVX512VComplex1D &x,
					 _In_ const double * __restrict Re) {
	 using namespace lam::common;
	if (!Is_ptr_aligned64(Re)) { return (AVX512VComplex1D{});}
	AVX512VComplex1D ret_vec{x.data.m_nsize};
	int32_t i;
	for (i = 0; i != ROUND_TO_EIGHT(ret_vec.data.m_nsize, 8); i += 8) {
		// Will unrolling 2x not saturate divider unit.
		// We have two parallel division so at least second
		// operation will be pipelined at divider level.

		const __m512d zmm0 = _mm512_load_pd(&x.data.m_Re[i]);
		const __m512d zmm1 = _mm512_load_pd(&Re[i]);
#if (USE_AVX3COMPLEX_NT_STORES) == 1
		_mm512_stream_pd(&ret_vec.data.m_Re[i], _mm512_div_pd(zmm0, zmm1));
#else
		_mm512_store_pd(&ret_vec.data.m_Re[i], _mm512_div_pd(zmm0, zmm1));
#endif
		const __m512d zmm2 = _mm512_load_pd(&x.data.m_Im[i]);
#if (USE_AVX3COMPLEX_NT_STORES) == 1
		_mm512_stream_pd(&ret_vec.data.m_Im[i], _mm512_div_pd(zmm2, zmm1));
#else
		_mm512_store_pd(&ret_vec.data.m_Im[i], _mm512_div_pd(zmm2, zmm1));
#endif
	}

	for (; i != ret_vec.data.m_nsize; ++i) {
		ret_vec.data.m_Re[i] = x.data.m_Re[i] / Re[i];
		ret_vec.data.m_Im[i] = x.data.m_Im[i] / Re[i];
	}
	return (ret_vec);
}






	
std::ostream &
lam::math::operator<<(_In_ std::ostream &os, _In_ const AVX512VComplex1D &x) {

	for (int64_t i = 0LL; i != x.data.m_nsize; ++i) {
		os << std::fixed << std::showpoint << std::setprecision(15) <<
			std::setw(4) << "Re: " << "{" << x.data.m_Re[i] << "}" <<
			std::setw(12) << "Im: " << "{" << x.data.m_Im[i] << "}" << std::endl;
	}
	return (os);
}



	
	




// vout size must be equal to v1 and v2 size.
void
lam::math::v512cnormalize_product(_Inout_    AVX512VComplex1D &vout, 
								  _In_ const AVX512VComplex1D &v1,
								  _In_ const AVX512VComplex1D &v2,
								  _In_ const bool do_nt_stream) {
	
	avx512_cnormalize_prod<AVX512VComplex1D>(vout,v1,v2,do_nt_stream);
}	




void
lam::math::v512cmean_product(_Inout_ std::complex<double> &mean, 
							 _In_ const AVX512VComplex1D &v1,
							 _In_ const AVX512VComplex1D &v2) {
	
	avx512_cmean_prod<AVX512VComplex1D>(mean,v1,v2);
}
	


void
lam::math::v512cmean_quotient(_Inout_ std::complex<double> &mean,
							  _In_ const AVX512VComplex1D &v1,
							  _In_ const AVX512VComplex1D &v2) {
	
	avx512_cmean_quot<AVX512VComplex1D>(mean,v1,v2);
}

void
lam::math::v512cconj_product(_Inout_ AVX512VComplex1D    &vout,
							 _In_ const AVX512VComplex1D &v1,
							 _In_ const AVX512VComplex1D &v2,
							 _In_ const bool do_nt_store) {
	
	avx512_cconj_prod<AVX512VComplex1D>(vout,v1,v2,do_nt_store);
}      


void
lam::math::v512cnorm_conjprod(_Inout_ AVX512VComplex1D    &vout,
							  _In_ const AVX512VComplex1D &v1,
							  _In_ const AVX512VComplex1D &v2,
							  _In_ const bool do_nt_store) {
	
	avx512_cnorm_conjprod<AVX512VComplex1D>(vout,v1,v2,do_nt_store);
}


void
lam::math::v512cmean_conjprod(_Inout_ std::complex<double> &mean,
							  _In_ const AVX512VComplex1D &v1,
							  _In_ const AVX512VComplex1D &v2) {
	
	avx512_cmean_conjprod<AVX512VComplex1D>(mean,v1,v2);
}

void
lam::math::v512c_arithmean(_Inout_ std::complex<double> &mean,
						   _In_ const AVX512VComplex1D &v1) {
	
	avx512_arith_mean<AVX512VComplex1D>(mean,v1);
	
}

void
lam::math::v512c_normalize(_Inout_ AVX512VComplex1D &vnorm,
						   _In_ const AVX512VComplex1D &v,
						   _In_ const AVX512VComplex1D &cv,
						   _In_ const bool do_nt_store) {
	
	avx512_cnormalize<AVX512VComplex1D>(vnorm,v,cv,do_nt_store);
}

void
lam::math::v512c_magnitude(_Inout_ double * __restrict vmag,
						   _In_ const AVX512VComplex1D &v,
						   _In_ const AVX512VComplex1D &cv) {
	
	avx512_cmagnitude<AVX512VComplex1D>(vmag,v,cv);
}	








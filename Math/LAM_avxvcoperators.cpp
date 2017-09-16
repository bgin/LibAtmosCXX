
//
// LAM_avxvcoperators -- Implementation
//

#include "LAM_avxvcoperators.h"


lam::math::AVXVComplex1D
lam::math::operator+(_In_ const AVXVComplex1D &v1,
					 _In_ const AVXVComplex1D &v2) {
#if LAM_DEBUG_ON == 1
	_ASSERTE(v1.get_nsize() == v2.get_nsize());
#else
	if(v1.get_nsize() != v2.get_nsize()) {
		throw std::invalid_argument("lam::math::operator+ [loc:15]: v1.get_nsize() != v2.get_nsize()");
	}
#endif
	const uint64_t vlen = v1.get_nsize();
	double* __restrict tRe = 
	reinterpret_cast<double*>(_mm_malloc(vlen*sizeof(double),align32B));
	double* __restrict tIm = 
	reinterpret_cast<double*>(_mm_malloc(vlen*sizeof(double),align32B));
	if (tRe == NULL || tIm == NULL) {
#if LAM_VERBOSE_ON == 1
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
													lam::math::operator+ [loc:24] --> Memory allocation failure!!";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
#endif
		throw std::runtime_error("lam::math::operator+ [loc:24] --> Memory allocation failure!!");
	}
	for (uint64_t i = 0ULL; i != vlen; i += 8ULL) {
#if LAM_CACHE_MEM_STORES == 1
		// Using AVX for comparison.
		// Unrolled 2x in order to match perfectly
		// per core 2 load operations per cycle.
		_mm256_storeu_pd(&tRe[i + 0ULL], _mm256_add_pd(_mm256_loadu_pd(&v1.getRe()[i+0ULL]),
			_mm256_loadu_pd(&v2.getRe()[i+0ULL])));
		_mm256_storeu_pd(&tRe[i + 4ULL], _mm256_add_pd(_mm256_loadu_pd(&v1.getRe()[i + 4ULL]),
			_mm256_loadu_pd(&v2.getRe()[i + 4ULL])));
		_mm256_storeu_pd(&tIm[i + 0ULL], _mm256_add_pd(_mm256_loadu_pd(&v1.getIm()[i+0ULL]),
			_mm256_loadu_pd(&v2.getIm()[i+0ULL])));
		_mm256_storeu_pd(&tIm[i + 4ULL], _mm256_add_pd(_mm256_loadu_pd(&v1.getIm()[i + 4ULL]),
			_mm256_loadu_pd(&v2.getIm()[i + 4ULL])));
#else
	//	Do not pollute cache on memory stores
	//  You must be sure that stores will not be
	// used later, so do not keep them in cache.
		_mm256_stream_pd(&tRe[i + 0ULL], _mm256_add_pd(_mm256_loadu_pd(&v1.getRe()[i + 0ULL]),
			_mm256_loadu_pd(&v2.getRe()[i + 0ULL])));
		_mm256_stream_pd(&tRe[i + 4ULL], _mm256_add_pd(_mm256_loadu_pd(&v1.getRe()[i + 4ULL]),
			_mm256_loadu_pd(&v2.getRe()[i + 4ULL])));
		_mm256_stream_pd(&tIm[i + 0ULL], _mm256_add_pd(_mm256_loadu_pd(&v1.getIm()[i + 0ULL]),
			_mm256_loadu_pd(&v2.getIm()[i + 0ULL])));
		_mm256_stream_pd(&tIm[i + 4ULL], _mm256_add_pd(_mm256_loadu_pd(&v1.getIm()[i + 4ULL]),
			_mm256_loadu_pd(&v2.getIm()[i + 4ULL])));
#endif
	}
	lam::math::AVXVComplex1D vres{vlen,tRe,tIm};
	_mm_free(tIm);
	_mm_free(tRe);
	return (vres);
}

lam::math::AVXVComplex1D
lam::math::operator+(_In_ const AVXVComplex1D &v1,
					 _In_ const double* __restrict v2) {
#if LAM_DEBUG_ON == 1
	_ASSERTE(v2 != NULL);
#else
	if(v2 == NULL)
		throw std::invalid_argument("lam::math::operator+[loc:71]: v2 == NULL ");
#endif
	const uint64_t vlen = v1.get_nsize();
	double* __restrict tRe = 
	reinterpret_cast<double*>(_mm_malloc(vlen*sizeof(double),align32B));
	if (tRe == NULL) {
#if LAM_VERBOSE_ON == 1
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
													lam::math::operator+ [loc:77] --> Memory allocation failure!!";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
#endif
		throw std::runtime_error("lam::math::operator+ [loc:77] --> Memory allocation failure!!");
	}
	for (uint64_t i = 0ULL; i != vlen; i += 8ULL) {
#if LAM_CACHE_MEM_STORES == 1
		// Using AVX for comparison.
		// Unrolled 2x in order to match perfectly
		// per core 2 load operations per cycle.
		_mm256_storeu_pd(&tRe[i + 0ULL], _mm256_add_pd(_mm256_loadu_pd(&v1.getRe()[i+0ULL]), 
										 _mm256_loadu_pd(&v2[i+0ULL])));
		_mm256_storeu_pd(&tRe[i + 4ULL], _mm256_add_pd(_mm256_loadu_pd(&v1.getRe()[i+4ULL]), 
										 _mm256_loadu_pd(&v2[i + 4ULL])));
#else
		//	Do not pollute cache on memory stores
		//  You must be sure that stores will not be
		// used later, so do not keep them in cache.
		_mm256_stream_pd(&tRe[i + 0ULL], _mm256_add_pd(_mm256_loadu_pd(&v1.getRe()[i + 0ULL]),
			_mm256_loadu_pd(&v2[i + 0ULL])));
		_mm256_stream_pd(&tRe[i + 4ULL], _mm256_add_pd(_mm256_loadu_pd(&v1.getRe()[i + 4ULL]),
			_mm256_loadu_pd(&v2[i + 4ULL])));
#endif
	}
	lam::math::AVXVComplex1D vres{ vlen, tRe, v1.getIm() };
	_mm_free(tRe);
	return (vres);
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
	const uint64_t vlen = v2.get_nsize();
	double* __restrict tRe = 
	reinterpret_cast<double*>(_mm_malloc(vlen*sizeof(double),align32B));
	if (tRe == NULL) {
#if LAM_VERBOSE_ON == 1
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
												lam::math::operator+ [loc:120] --> Memory allocation failure!!";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
#endif
		throw std::runtime_error("lam::math::operator+ [loc:120] --> Memory allocation failure!!");
	}
	for (uint64_t i = 0ULL; i != vlen; i += 8ULL) {
#if LAM_CACHE_MEM_STORES == 1
		// Using AVX for comparison.
		// Unrolled 2x in order to match perfectly
		// per core 2 load operations per cycle.
		_mm256_storeu_pd(&tRe[i + 0ULL], _mm256_add_pd(_mm256_loadu_pd(&v1[i+0ULL]),
			_mm256_loadu_pd(&v2.getRe()[i+0ULL])));
		_mm256_storeu_pd(&tRe[i + 4ULL], _mm256_add_pd(_mm256_loadu_pd(&v1[i + 4ULL]),
			_mm256_loadu_pd(&v2.getRe()[i + 4ULL])));
#else
		//	Do not pollute cache on memory stores
		//  You must be sure that stores will not be
		// used later, so do not keep them in cache.
		_mm256_stream_pd(&tRe[i + 0ULL], _mm256_add_pd(_mm256_loadu_pd(&v1[i + 0ULL]),
			_mm256_loadu_pd(&v2.getRe()[i + 0ULL])));
		_mm256_stream_pd(&tRe[i + 4ULL], _mm256_add_pd(_mm256_loadu_pd(&v1[i + 4ULL]),
			_mm256_loadu_pd(&v2.getRe()[i + 4ULL])));
#endif
	}
	lam::math::AVXVComplex1D vres{ vlen, tRe, v2.getIm() };
	_mm_free(tRe);
	return (vres);
}

lam::math::AVXVComplex1D
lam::math::operator-(_In_ const AVXVComplex1D &v1,
					 _In_ const AVXVComplex1D &v2) {
#if LAM_DEBUG_ON == 1
	_ASSERTE(v1.get_nsize() == v2.get_nsize());
#else
	if(v1.get_nsize() != v2.get_nsize())
		throw std::invalid_argument("lam::math::operator- [loc:158]: v1.get_nsize() != v2.get_nsize()");
#endif
	const uint64_t vlen = v1.get_nsize();
	double* __restrict tRe = 
	reinterpret_cast<double*>(_mm_malloc(vlen*sizeof(double),align32B));
	double* __restrict tIm = 
	reinterpret_cast<double*>(_mm_malloc(vlen*sizeof(double),align32B));
	if (tRe == NULL || tIm == NULL) {
#if LAM_VERBOSE_ON == 1
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
																lam::math::operator- [loc:166] --> Memory allocation failure!!";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
#endif
		throw std::runtime_error("lam::math::operator- [loc:166] --> Memory allocation failure!!");
	}
	for (uint64_t i = 0ULL; i != vlen; i += 8ULL) {
#if LAM_CACHE_MEM_STORES == 1
		// Using AVX for comparison.
		// Unrolled 2x in order to match perfectly
		// per core 2 load operations per cycle.
		_mm256_storeu_pd(&tRe[i + 0ULL], _mm256_sub_pd(_mm256_loadu_pd(&v1.getRe()[i+0ULL]),
			_mm256_loadu_pd(&v2.getRe()[i+0ULL])));
		_mm256_storeu_pd(&tRe[i + 4ULL], _mm256_sub_pd(_mm256_loadu_pd(&v1.getRe()[i + 4ULL]),
			_mm256_loadu_pd(&v2.getRe()[i + 4ULL])));
		_mm256_storeu_pd(&tIm[i + 0ULL], _mm256_sub_pd(_mm256_loadu_pd(&v1.getIm()[i+0ULL]),
			_mm256_loadu_pd(&v2.getIm()[i+0ULL])));
		_mm256_storeu_pd(&tIm[i + 4ULL], _mm256_sub_pd(_mm256_loadu_pd(&v1.getIm()[i + 4ULL]),
			_mm256_loadu_pd(&v2.getIm()[i + 4ULL])));
#else
		//	Do not pollute cache on memory stores
		//  You must be sure that stores will not be
		// used later, so do not keep them in cache.
		_mm256_stream_pd(&tRe[i + 0ULL], _mm256_sub_pd(_mm256_loadu_pd(&v1.getRe()[i + 0ULL]),
			_mm256_loadu_pd(&v2.getRe()[i + 0ULL])));
		_mm256_stream_pd(&tRe[i + 4ULL], _mm256_sub_pd(_mm256_loadu_pd(&v1.getRe()[i + 4ULL]),
			_mm256_loadu_pd(&v2.getRe()[i + 4ULL])));
		_mm256_stream_pd(&tIm[i + 0ULL], _mm256_sub_pd(_mm256_loadu_pd(&v1.getIm()[i + 0ULL]),
			_mm256_loadu_pd(&v2.getIm()[i + 0ULL])));
		_mm256_stream_pd(&tIm[i + 4ULL], _mm256_sub_pd(_mm256_loadu_pd(&v1.getIm()[i + 4ULL]),
			_mm256_loadu_pd(&v2.getIm()[i + 4ULL])));
#endif
	}
	lam::math::AVXVComplex1D vres{vlen,tRe,tIm};
	_mm_free(tIm);
	_mm_free(tRe);
	return (vres);
}

lam::math::AVXVComplex1D
lam::math::operator-(_In_ const AVXVComplex1D &v1,
					 _In_ const double* __restrict v2) {
#if LAM_DEBUG_ON == 1
	_ASSERTE(v2 != NULL);
#else
	if(v2 == NULL)
		throw std::invalid_argument("lam::math::operator- [loc:158]: v2 == NULL");
#endif
	const uint64_t vlen = v1.get_nsize();
	double* __restrict tRe = 
	reinterpret_cast<double*>(_mm_malloc(vlen*sizeof(double),align32B));
	if (tRe == NULL) {
#if LAM_VERBOSE_ON == 1
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
											lam::math::operator- [loc:219] --> Memory allocation failure!!";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
#endif
		throw std::runtime_error("lam::math::operator- [loc:219] --> Memory allocation failure!!");
	}
	for (uint64_t i = 0ULL; i != vlen; i += 8ULL) {
#if LAM_CACHE_MEM_STORES == 1
		// Using AVX for comparison.
		// Unrolled 2x in order to match perfectly
		// per core 2 load operations per cycle.
		_mm256_storeu_pd(&tRe[i + 0ULL], _mm256_sub_pd(_mm256_loadu_pd(&v1.getRe()[i+0ULL]),
			_mm256_loadu_pd(&v2[i+0ULL])));
		_mm256_storeu_pd(&tRe[i + 4ULL], _mm256_sub_pd(_mm256_loadu_pd(&v1.getRe()[i+4ULL]),
			_mm256_loadu_pd(&v2[i + 4ULL])));
#else
		//	Do not pollute cache on memory stores
		//  You must be sure that stores will not be
		// used later, so do not keep them in cache.
		_mm256_stream_pd(&tRe[i + 0ULL], _mm256_sub_pd(_mm256_loadu_pd(&v1.getRe()[i + 0ULL]),
			_mm256_loadu_pd(&v2[i + 0ULL])));
		_mm256_stream_pd(&tRe[i + 4ULL], _mm256_sub_pd(_mm256_loadu_pd(&v1.getRe()[i + 4ULL]),
			_mm256_loadu_pd(&v2[i + 4ULL])));
#endif
	}
	lam::math::AVXVComplex1D vres{ vlen, tRe, v1.getIm() };
	_mm_free(tRe);
	return (vres);
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
		const uint64_t vlen = v2.get_nsize();
		double* __restrict tRe = 
		reinterpret_cast<double*>(_mm_malloc(vlen*sizeof(double),align32B));
		if (tRe == NULL) {
#if LAM_VERBOSE_ON == 1
			std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
												lam::math::operator- [loc:263] --> Memory allocation failure!!";
			std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
#endif
			throw std::runtime_error("lam::math::operator- [loc:263] --> Memory allocation failure!!");

		}
		for (uint64_t i = 0ULL; i != vlen; i += 8ULL) {
#if LAM_CACHE_MEM_STORES == 1
			// Using AVX for comparison.
			// Unrolled 2x in order to match perfectly
			// per core 2 load operations per cycle.
			_mm256_storeu_pd(&tRe[i + 0ULL], _mm256_sub_pd(_mm256_loadu_pd(&v1[i+0ULL]),
				_mm256_loadu_pd(&v2.getRe()[i+0ULL])));
			_mm256_storeu_pd(&tRe[i + 4ULL], _mm256_sub_pd(_mm256_loadu_pd(&v1[i + 4ULL]),
				_mm256_loadu_pd(&v2.getRe()[i + 4ULL])));
#else
			//	Do not pollute cache on memory stores
			//  You must be sure that stores will not be
			// used later, so do not keep them in cache.
			_mm256_stream_pd(&tRe[i + 0ULL], _mm256_sub_pd(_mm256_loadu_pd(&v1[i + 0ULL]),
				_mm256_loadu_pd(&v2.getRe()[i + 0ULL])));
			_mm256_stream_pd(&tRe[i + 4ULL], _mm256_sub_pd(_mm256_loadu_pd(&v1[i + 4ULL]),
				_mm256_loadu_pd(&v2.getRe()[i + 4ULL])));
#endif
		}
		lam::math::AVXVComplex1D vres{ vlen, tRe, v2.getIm() };
		_mm_free(tRe);
		return (vres);
}

lam::math::AVXVComplex1D 
lam::math::operator*(_In_ const AVXVComplex1D &v1,
					 _In_ const AVXVComplex1D &v2) {
#if LAM_DEBUG_ON == 1
	_ASSERTE(v1.get_nsize() != v2.get_nsize());
#else
	if(v1.get_nsize() != v2.get_nsize())
		throw std::invalid_argument("lam::math::operator* [loc:302]: v1.get_nsize() != v2.get_nsize()");
#endif
	const uint64_t vlen = v1.get_nsize();
	double* __restrict tRe = 
	reinterpret_cast<double*>(_mm_malloc(vlen*sizeof(double),align32B));
	double* __restrict tIm = 
	reinterpret_cast<double*>(_mm_malloc(vlen*sizeof(double),align32B));
	if (tRe == NULL || tIm == NULL) {
#if LAM_VERBOSE_ON == 1
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
											lam::math::operator* [loc:311] --> Memory allocation failure!!";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
#endif
		throw std::runtime_error("lam::math::operator* [loc:311] --> Memory allocation failure!!");
	}
	for (uint64_t i = 0ULL; i != vlen; i += 8ULL) {
#if LAM_CACHE_MEM_STORES == 1
		// Using AVX for comparison.
		// Unrolled 2x in order to match perfectly
		// per core 2 load operations per cycle.
		_mm256_storeu_pd(&tRe[i + 0ULL], _mm256_sub_pd(_mm256_mul_pd(_mm256_loadu_pd(&v1.getRe()[i+0ULL]),
			_mm256_loadu_pd(&v2.getRe()[i + 0ULL])), _mm256_mul_pd(_mm256_loadu_pd(&v1.getIm()[i+0ULL]),
			_mm256_loadu_pd(&v2.getIm()[i+0ULL]))));
		_mm256_storeu_pd(&tRe[i + 4ULL], _mm256_sub_pd(_mm256_mul_pd(_mm256_loadu_pd(&v1.getRe()[i + 4ULL]),
			_mm256_loadu_pd(&v2.getRe()[i + 4ULL])), _mm256_mul_pd(_mm256_loadu_pd(&v1.getIm()[i + 4ULL]),
			_mm256_loadu_pd(&v2.getIm()[i + 4ULL]))));
		_mm256_storeu_pd(&tIm[i + 0ULL], _mm256_add_pd(_mm256_mul_pd(_mm256_loadu_pd(&v1.getIm()[i+0ULL]),
			_mm256_loadu_pd(&v2.getRe()[i + 0ULL])), _mm256_mul_pd(_mm256_loadu_pd(&v1.getRe()[i+0ULL]),
			_mm256_loadu_pd(&v2.getIm()[i+0ULL]))));
		_mm256_storeu_pd(&tIm[i + 4ULL], _mm256_add_pd(_mm256_mul_pd(_mm256_loadu_pd(&v1.getIm()[i + 4ULL]),
			_mm256_loadu_pd(&v2.getRe()[i + 4ULL])), _mm256_mul_pd(_mm256_loadu_pd(&v1.getRe()[i + 4ULL]),
			_mm256_loadu_pd(&v2.getIm()[i + 4ULL]))));
#else
		//	Do not pollute cache on memory stores
		//  You must be sure that stores will not be
		// used later, so do not keep them in cache.
		_mm256_stream_pd(&tRe[i + 0ULL], _mm256_sub_pd(_mm256_mul_pd(_mm256_loadu_pd(&v1.getRe()[i + 0ULL]),
			_mm256_loadu_pd(&v2.getRe()[i + 0ULL])), _mm256_mul_pd(_mm256_loadu_pd(&v1.getIm()[i + 0ULL]),
			_mm256_loadu_pd(&v2.getIm()[i + 0ULL]))));
		_mm256_stream_pd(&tRe[i + 4ULL], _mm256_sub_pd(_mm256_mul_pd(_mm256_loadu_pd(&v1.getRe()[i + 4ULL]),
			_mm256_loadu_pd(&v2.getRe()[i + 4ULL])), _mm256_mul_pd(_mm256_loadu_pd(&v1.getIm()[i + 4ULL]),
			_mm256_loadu_pd(&v2.getIm()[i + 4ULL]))));
		_mm256_stream_pd(&tIm[i + 0ULL], _mm256_add_pd(_mm256_mul_pd(_mm256_loadu_pd(&v1.getIm()[i + 0ULL]),
			_mm256_loadu_pd(&v2.getRe()[i + 0ULL])), _mm256_mul_pd(_mm256_loadu_pd(&v1.getRe()[i + 0ULL]),
			_mm256_loadu_pd(&v2.getIm()[i + 0ULL]))));
		_mm256_stream_pd(&tIm[i + 4ULL], _mm256_add_pd(_mm256_mul_pd(_mm256_loadu_pd(&v1.getIm()[i + 4ULL]),
			_mm256_loadu_pd(&v2.getRe()[i + 4ULL])), _mm256_mul_pd(_mm256_loadu_pd(&v1.getRe()[i + 4ULL]),
			_mm256_loadu_pd(&v2.getIm()[i + 4ULL]))));
#endif
	}
	lam::math::AVXVComplex1D vres{vlen,tRe,tIm};
	_mm_free(tIm);
	_mm_free(tRe);
	return (vres);
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
	const uint64_t vlen = v1.get_nsize();
	double*  __restrict tRe = 
	reinterpret_cast<double*>(_mm_malloc(vlen*sizeof(double),align32B));
	double* __restrict tIm = 
	reinterpret_cast<double*>(_mm_malloc(vlen*sizeof(double),align32B));
	if (tRe == NULL || tIm == NULL) {
#if LAM_VERBOSE_ON == 1
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
													lam::math::operator* [loc:373] --> Memory allocation failure!!";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
#endif
		throw std::runtime_error("lam::math::operator* [loc:373] --> Memory allocation failure!!");
	}
	for (uint64_t i = 0ULL; i != vlen; i += 8ULL) {
#if LAM_CACHE_MEM_STORES == 1
		// Using AVX for comparison.
		// Unrolled 2x in order to match perfectly
		// per core 2 load operations per cycle.
		_mm256_storeu_pd(&tRe[i + 0ULL], _mm256_mul_pd(_mm256_loadu_pd(&v1.getRe()[i+0ULL]),
			_mm256_loadu_pd(&v2[i+0ULL])));
		_mm256_storeu_pd(&tRe[i + 4ULL], _mm256_mul_pd(_mm256_loadu_pd(&v1.getRe()[i + 4ULL]),
			_mm256_loadu_pd(&v2[i + 4ULL])));
		_mm256_storeu_pd(&tIm[i + 0ULL], _mm256_mul_pd(_mm256_loadu_pd(&v1.getIm()[i+0ULL]),
			_mm256_loadu_pd(&v2[i+0ULL])));
		_mm256_storeu_pd(&tIm[i + 4ULL], _mm256_mul_pd(_mm256_loadu_pd(&v1.getIm()[i + 4ULL]),
			_mm256_loadu_pd(&v2[i + 4ULL])));
#else
		//	Do not pollute cache on memory stores
		//  You must be sure that stores will not be
		// used later, so do not keep them in cache.
		_mm256_stream_pd(&tRe[i + 0ULL], _mm256_mul_pd(_mm256_loadu_pd(&v1.getRe()[i + 0ULL]),
			_mm256_loadu_pd(&v2[i + 0ULL])));
		_mm256_stream_pd(&tRe[i + 4ULL], _mm256_mul_pd(_mm256_loadu_pd(&v1.getRe()[i + 4ULL]),
			_mm256_loadu_pd(&v2[i + 4ULL])));
		_mm256_stream_pd(&tIm[i + 0ULL], _mm256_mul_pd(_mm256_loadu_pd(&v1.getIm()[i + 0ULL]),
			_mm256_loadu_pd(&v2[i + 0ULL])));
		_mm256_stream_pd(&tIm[i + 4ULL], _mm256_mul_pd(_mm256_loadu_pd(&v1.getIm()[i + 4ULL]),
			_mm256_loadu_pd(&v2[i + 4ULL])));
#endif
	}
	lam::math::AVXVComplex1D vres{vlen,tRe,tIm};
	_mm_free(tIm);
	_mm_free(tRe);
	return (vres);
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
	const uint64_t vlen = v2.get_nsize();
	double* __restrict tRe = 
	reinterpret_cast<double*>(_mm_malloc(vlen*sizeof(double),align32B));
	double* __restrict tIm = 
	reinterpret_cast<double*>(_mm_malloc(vlen*sizeof(double),align32B));
	if (NULL == tRe || NULL == tIm) {
#if LAM_VERBOSE_ON == 1
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
													lam::math::operator* [loc:428] --> Memory allocation failure!!";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
#endif
		throw std::runtime_error("lam::math::operator* [loc:428] --> Memory allocation failure!!");
	}
	for (uint64_t i = 0ULL; i != vlen; i += 8ULL) {
#if LAM_CACHE_MEM_STORES == 1
		// Using AVX for comparison.
		// Unrolled 2x in order to match perfectly
		// per core 2 load operations per cycle.
		_mm256_storeu_pd(&tRe[i + 0ULL], _mm256_mul_pd(_mm256_loadu_pd(&v1[i+0ULL]),
			_mm256_loadu_pd(&v2.getRe()[i+0ULL])));
		_mm256_storeu_pd(&tRe[i + 4ULL], _mm256_mul_pd(_mm256_loadu_pd(&v1[i + 4ULL]),
			_mm256_loadu_pd(&v2.getRe()[i + 4ULL])));
		_mm256_storeu_pd(&tIm[i + 0ULL], _mm256_mul_pd(_mm256_loadu_pd(&v1[i+0ULL]),
			_mm256_loadu_pd(&v2.getIm()[i+0ULL])));
		_mm256_storeu_pd(&tIm[i + 4ULL], _mm256_mul_pd(_mm256_loadu_pd(&v1[i + 4ULL]),
			_mm256_loadu_pd(&v2.getIm()[i + 4ULL])));
#else
		//	Do not pollute cache on memory stores
		//  You must be sure that stores will not be
		// used later, so do not keep them in cache.
		_mm256_stream_pd(&tRe[i + 0ULL], _mm256_mul_pd(_mm256_loadu_pd(&v1[i + 0ULL]),
			_mm256_loadu_pd(&v2.getRe()[i + 0ULL])));
		_mm256_stream_pd(&tRe[i + 4ULL], _mm256_mul_pd(_mm256_loadu_pd(&v1[i + 4ULL]),
			_mm256_loadu_pd(&v2.getRe()[i + 4ULL])));
		_mm256_stream_pd(&tIm[i + 0ULL], _mm256_mul_pd(_mm256_loadu_pd(&v1[i + 0ULL]),
			_mm256_loadu_pd(&v2.getIm()[i + 0ULL])));
		_mm256_stream_pd(&tIm[i + 4ULL], _mm256_mul_pd(_mm256_loadu_pd(&v1[i + 4ULL]),
			_mm256_loadu_pd(&v2.getIm()[i + 4ULL])));
#endif
	}
	lam::math::AVXVComplex1D vres{vlen,tRe,tIm};
	_mm_free(tIm);
	_mm_free(tRe);
	return (vres);
}

#include "../LAM_common.h"

lam::math::AVXVComplex1D
lam::math::operator/(_In_ const AVXVComplex1D &v1,
					 _In_ const AVXVComplex1D &v2) {
	using namespace lam::common;
#if LAM_DEBUG_ON == 1
	_ASSERTE(v1.get_nsize() == v2.get_nsize());
#else
	if(v1.get_nsize() != v2.get_nsize())
		throw std::invalid_argument("lam::math::operator/ [loc:479]: v1.get_nsize() != v2.get_nsize()");
#endif
	if (vzero_check(v1.getRe(), v1.getIm(), v1.get_nsize()) ||
		vzero_check(v2.getRe(), v2.getIm(), v2.get_nsize())) {
		throw std::domain_error("AVXVComplex1D::operator/ [loc:482] --> found '0.0' in AVXVComplex1D");
	}
	const uint64_t vlen = v1.get_nsize();
	double* __restrict tRe = 
	reinterpret_cast<double*>(_mm_malloc(vlen*sizeof(double),align32B));
	double* __restrict tIm = 
	reinterpret_cast<double*>(_mm_malloc(vlen*sizeof(double),align32B));
	if (NULL == tRe || NULL == tIm) {
#if LAM_VERBOSE_ON == 1
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
											lam::math::operator/ [loc:491] --> Memory allocation failure!!";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
#endif
		throw std::runtime_error("lam::math::operator/ [loc:491] --> Memory allocation failure!!");
	}
	for (uint64_t i = 0ULL; i != vlen; i += 8ULL) {
#if LAM_DEBUG_ON == 1
		// Using AVX for comparison.
		// Unrolled 2x in order to match perfectly
		// per core 2 load operations per cycle.
		__m256d tre1 = _mm256_add_pd(_mm256_mul_pd(_mm256_loadu_pd(&v1.getRe()[i+0ULL]),
			_mm256_loadu_pd(&v2.getIm()[i+0ULL])), _mm256_mul_pd(_mm256_loadu_pd(&v1.getIm()[i+0ULL]),
			_mm256_loadu_pd(&v2.getIm()[i+0ULL])));
		__m256d tre2 = _mm256_add_pd(_mm256_mul_pd(_mm256_loadu_pd(&v1.getRe()[i + 4ULL]),
			_mm256_loadu_pd(&v2.getIm()[i + 4ULL])), _mm256_mul_pd(_mm256_loadu_pd(&v1.getIm()[i + 4ULL]),
			_mm256_loadu_pd(&v2.getIm()[i + 4ULL])));
		__m256d tim1 = _mm256_sub_pd(_mm256_mul_pd(_mm256_loadu_pd(&v1.getIm()[i+0ULL]),
			_mm256_loadu_pd(&v2.getIm()[i + 0ULL])), _mm256_mul_pd(_mm256_loadu_pd(&v1.getRe()[i+0ULL]),
			_mm256_loadu_pd(&v2.getIm()[i+0ULL])));
		__m256d tim2 = _mm256_sub_pd(_mm256_mul_pd(_mm256_loadu_pd(&v1.getIm()[i + 4ULL]),
			_mm256_loadu_pd(&v2.getIm()[i + 4ULL])), _mm256_mul_pd(_mm256_loadu_pd(&v1.getRe()[i + 4ULL]),
			_mm256_loadu_pd(&v2.getIm()[i + 4ULL])));
		__m256d den1 = _mm256_add_pd(_mm256_mul_pd(_mm256_loadu_pd(&v2.getRe()[i+0ULL]),
			_mm256_loadu_pd(&v2.getRe()[i + 0ULL])), _mm256_mul_pd(_mm256_loadu_pd(&v2.getIm()[i+0ULL]),
			_mm256_loadu_pd(&v2.getIm()[i+0ULL])));
		__m256d den2 = _mm256_add_pd(_mm256_mul_pd(_mm256_loadu_pd(&v2.getRe()[i + 4ULL]),
			_mm256_loadu_pd(&v2.getRe()[i + 4ULL])), _mm256_mul_pd(_mm256_loadu_pd(&v2.getIm()[i + 4ULL]),
			_mm256_loadu_pd(&v2.getIm()[i + 4ULL])));

		_mm256_storeu_pd(&tRe[i + 0ULL], _mm256_div_pd(tre1,den1));
		_mm256_storeu_pd(&tRe[i + 4ULL], _mm256_div_pd(tre2,den2));
		_mm256_storeu_pd(&tIm[i + 0ULL], _mm256_div_pd(tim1,den1));
		_mm256_storeu_pd(&tIm[i + 4ULL], _mm256_div_pd(tim2,den2));
#else
		//	Do not pollute cache on memory stores
		//  You must be sure that stores will not be
		// used later, so do not keep them in cache.
		__m256d tre1 = _mm256_add_pd(_mm256_mul_pd(_mm256_loadu_pd(&v1.getRe()[i + 0ULL]),
			_mm256_loadu_pd(&v2.getIm()[i + 0ULL])), _mm256_mul_pd(_mm256_loadu_pd(&v1.getIm()[i + 0ULL]),
			_mm256_loadu_pd(&v2.getIm()[i + 0ULL])));
		__m256d tre2 = _mm256_add_pd(_mm256_mul_pd(_mm256_loadu_pd(&v1.getRe()[i + 4ULL]),
			_mm256_loadu_pd(&v2.getIm()[i + 4ULL])), _mm256_mul_pd(_mm256_loadu_pd(&v1.getIm()[i + 4ULL]),
			_mm256_loadu_pd(&v2.getIm()[i + 4ULL])));
		__m256d tim1 = _mm256_sub_pd(_mm256_mul_pd(_mm256_loadu_pd(&v1.getIm()[i + 0ULL]),
			_mm256_loadu_pd(&v2.getIm()[i + 0ULL])), _mm256_mul_pd(_mm256_loadu_pd(&v1.getRe()[i + 0ULL]),
			_mm256_loadu_pd(&v2.getIm()[i + 0ULL])));
		__m256d tim2 = _mm256_sub_pd(_mm256_mul_pd(_mm256_loadu_pd(&v1.getIm()[i + 4ULL]),
			_mm256_loadu_pd(&v2.getIm()[i + 4ULL])), _mm256_mul_pd(_mm256_loadu_pd(&v1.getRe()[i + 4ULL]),
			_mm256_loadu_pd(&v2.getIm()[i + 4ULL])));
		__m256d den1 = _mm256_add_pd(_mm256_mul_pd(_mm256_loadu_pd(&v2.getRe()[i + 0ULL]),
			_mm256_loadu_pd(&v2.getRe()[i + 0ULL])), _mm256_mul_pd(_mm256_loadu_pd(&v2.getIm()[i + 0ULL]),
			_mm256_loadu_pd(&v2.getIm()[i + 0ULL])));
		__m256d den2 = _mm256_add_pd(_mm256_mul_pd(_mm256_loadu_pd(&v2.getRe()[i + 4ULL]),
			_mm256_loadu_pd(&v2.getRe()[i + 4ULL])), _mm256_mul_pd(_mm256_loadu_pd(&v2.getIm()[i + 4ULL]),
			_mm256_loadu_pd(&v2.getIm()[i + 4ULL])));

		_mm256_stream_pd(&tRe[i + 0ULL], _mm256_div_pd(tre1, den1));
		_mm256_stream_pd(&tRe[i + 4ULL], _mm256_div_pd(tre2, den2));
		_mm256_stream_pd(&tIm[i + 0ULL], _mm256_div_pd(tim1, den1));
		_mm256_stream_pd(&tIm[i + 4ULL], _mm256_div_pd(tim2, den2));
#endif
	}
	lam::math::AVXVComplex1D vres{vlen,tRe,tIm};
	_mm_free(tIm);
	_mm_free(tRe);
	return (vres);
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
	if (vzero_check1(v1, v2.get_nsize()) ||
		vzero_check(v2.getRe(), v2.getIm(), v2.get_nsize())) {
		throw std::domain_error("AVXVComplex1D::operator/ [loc:569] --> found '0.0' in AVXVComplex1D");
	}
	const uint64_t vlen = v2.get_nsize();
	double* __restrict tRe = 
	reinterpret_cast<double*>(_mm_malloc(vlen*sizeof(double),align32B));
	double* __restrict tIm = 
	reinterpret_cast<double*>(_mm_malloc(vlen*sizeof(double),align32B));
	if (NULL == tRe || NULL == tIm) {
#if LAM_VERBOSE_ON == 1
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
												lam::math::operator/ [loc:578] --> Memory allocation failure!!";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
#endif
		throw std::runtime_error("lam::math::operator/ [loc:578] --> Memory allocation failure!!");
	}
	for (uint64_t i = 0ULL; i != vlen; i += 8ULL) {
#if LAM_CACHE_MEM_STORES == 1
	
		// Unrolled 2x in order to match perfectly
		// per core 2 load operations per cycle.
		_mm256_storeu_pd(&tRe[i + 0ULL], _mm256_div_pd(_mm256_loadu_pd(&v1[i+0ULL]),
			_mm256_loadu_pd(&v2.getRe()[i+0ULL])));
		_mm256_storeu_pd(&tRe[i + 4ULL], _mm256_div_pd(_mm256_loadu_pd(&v1[i+4ULL]),
			_mm256_loadu_pd(&v2.getRe()[i + 4ULL])));
		_mm256_storeu_pd(&tIm[i+0ULL], _mm256_div_pd(_mm256_loadu_pd(&v1[i+0ULL]), 
			_mm256_loadu_pd(&v2.getIm()[i+0ULL])));
		_mm256_storeu_pd(&tIm[i + 4ULL], _mm256_div_pd(_mm256_loadu_pd(&v1[i + 4ULL]),
			_mm256_loadu_pd(&v2.getIm()[i + 4ULL])));
#else
		//	Do not pollute cache on memory stores
		//  You must be sure that stores will not be
		// used later, so do not keep them in cache.
		_mm256_stream_pd(&tRe[i + 0ULL], _mm256_div_pd(_mm256_loadu_pd(&v1[i + 0ULL]),
			_mm256_loadu_pd(&v2.getRe()[i + 0ULL])));
		_mm256_stream_pd(&tRe[i + 4ULL], _mm256_div_pd(_mm256_loadu_pd(&v1[i + 4ULL]),
			_mm256_loadu_pd(&v2.getRe()[i + 4ULL])));
		_mm256_stream_pd(&tIm[i + 0ULL], _mm256_div_pd(_mm256_loadu_pd(&v1[i + 0ULL]),
			_mm256_loadu_pd(&v2.getIm()[i + 0ULL])));
		_mm256_stream_pd(&tIm[i + 4ULL], _mm256_div_pd(_mm256_loadu_pd(&v1[i + 4ULL]),
			_mm256_loadu_pd(&v2.getIm()[i + 4ULL])));
#endif
	}
	lam::math::AVXVComplex1D vres{vlen,tRe,tIm};
	_mm_free(tIm);
	_mm_free(tRe);
	return (vres);
}

std::pair<double*,double*>
lam::math::operator==(_In_ const AVXVComplex1D &v1,
					  _In_ const AVXVComplex1D &v2) {
	 using namespace lam::common;
#if LAM_DEBUG_ON == 1
	_ASSERTE(v1.get_nsize() == v2.get_nsize());
#else
	if(v1.get_nsize() != v2.get_nsize())
		throw std::invalid_argument("lam::math::operator== [loc:628]: v1.get_nsize() == v2.get_nsize()");
#endif
	const uint64_t vlen = v1.get_nsize();
	double* __restrict pr1 = 
	reinterpret_cast<double*>(_mm_malloc(vlen*sizeof(double),align32B));
	double* __restrict pr2 =
	reinterpret_cast<double*>(_mm_malloc(vlen*sizeof(double),align32B));
	if (NULL == pr1 || NULL == pr2) {
#if LAM_VERBOSE_ON == 1
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
												lam::math::operator== [loc:636] --> Memory allocation failure!!";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
#endif
		throw std::runtime_error("lam::math::operator== [loc:636] --> Memory allocation failure!! ");
	}
	std::pair<double*,double*> pret;
	init_varray(pr1,vlen,-1.0);
	init_varray(pr2,vlen,-1.0);
	for (uint64_t i = 0ULL; i != vlen; i += 8ULL) {
#if LAM_CACHE_MEM_STORES == 1
		
		// Unrolled 2x in order to match perfectly
		// per core 2 load operations per cycle.
		_mm256_storeu_pd(&pret.first[i + 0ULL], _mm256_cmp_pd(_mm256_loadu_pd(&v1.getRe()[i+0ULL]),
			_mm256_loadu_pd(&v2.getRe()[i+0ULL]),_CMP_EQ_OQ));
		_mm256_storeu_pd(&pret.first[i + 4ULL], _mm256_cmp_pd(_mm256_loadu_pd(&v1.getRe()[i + 4ULL]),
			_mm256_loadu_pd(&v2.getRe()[i + 4ULL]), _CMP_EQ_OQ));
		_mm256_storeu_pd(&pret.second[i + 0ULL], _mm256_cmp_pd(_mm256_loadu_pd(&v1.getIm()[i+0ULL]),
			_mm256_loadu_pd(&v2.getIm()[i+0ULL]),_CMP_EQ_OQ));
		_mm256_storeu_pd(&pret.second[i + 4ULL], _mm256_cmp_pd(_mm256_loadu_pd(&v1.getIm()[i + 4ULL]),
			_mm256_loadu_pd(&v2.getIm()[i + 4ULL]), _CMP_EQ_OQ));
#else
		//	Do not pollute cache on memory stores
		//  You must be sure that stores will not be
		// used later, so do not keep them in cache.
		_mm256_stream_pd(&pret.first[i + 0ULL], _mm256_cmp_pd(_mm256_loadu_pd(&v1.getRe()[i + 0ULL]),
			_mm256_loadu_pd(&v2.getRe()[i + 0ULL]), _CMP_EQ_OQ));
		_mm256_stream_pd(&pret.first[i + 4ULL], _mm256_cmp_pd(_mm256_loadu_pd(&v1.getRe()[i + 4ULL]),
			_mm256_loadu_pd(&v2.getRe()[i + 4ULL]), _CMP_EQ_OQ));
		_mm256_stream_pd(&pret.second[i + 0ULL], _mm256_cmp_pd(_mm256_loadu_pd(&v1.getIm()[i + 0ULL]),
			_mm256_loadu_pd(&v2.getIm()[i + 0ULL]), _CMP_EQ_OQ));
		_mm256_stream_pd(&pret.second[i + 4ULL], _mm256_cmp_pd(_mm256_loadu_pd(&v1.getIm()[i + 4ULL]),
			_mm256_loadu_pd(&v2.getIm()[i + 4ULL]), _CMP_EQ_OQ));
#endif
	}
	return (pret);
}

std::pair<double*,double*>
lam::math::operator!=(_In_ const AVXVComplex1D &v1,
					  _In_ const AVXVComplex1D &v2) {
	using namespace lam::common;
#if LAM_DEBUG_ON == 1
	_ASSERTE(v1.get_nsize() == v2.get_nsize());
#else
	if (v1.get_nsize() != v2.get_nsize())
		throw std::invalid_argument("lam::math::operator!= [loc:684]: v1.get_nsize() == v2.get_nsize()");
#endif
	const uint64_t vlen = v1.get_nsize();
	double* __restrict pr1 =
		reinterpret_cast<double*>(_mm_malloc(vlen*sizeof(double), align32B));
	double* __restrict pr2 =
		reinterpret_cast<double*>(_mm_malloc(vlen*sizeof(double), align32B));
	if (NULL == pr1 || NULL == pr2) {
#if LAM_VERBOSE_ON == 1
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
												lam::math::operator!= [loc:693] --> Memory allocation failure!!";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
#endif
		throw std::runtime_error("lam::math::operator!= [loc:693] --> Memory allocation failure!! ");
	}
	std::pair<double*, double*> pret;
	init_varray(pr1, vlen, -1.0);
	init_varray(pr2, vlen, -1.0);
	for (uint64_t i = 0ULL; i != vlen; i += 8ULL) {
#if LAM_CACHE_MEM_STORES == 1

		// Unrolled 2x in order to match perfectly
		// per core 2 load operations per cycle.
		_mm256_storeu_pd(&pret.first[i + 0ULL], _mm256_cmp_pd(_mm256_loadu_pd(&v1.getRe()[i + 0ULL]),
			_mm256_loadu_pd(&v2.getRe()[i + 0ULL]), _CMP_NEQ_OQ));
		_mm256_storeu_pd(&pret.first[i + 4ULL], _mm256_cmp_pd(_mm256_loadu_pd(&v1.getRe()[i + 4ULL]),
			_mm256_loadu_pd(&v2.getRe()[i + 4ULL]), _CMP_NEQ_OQ));
		_mm256_storeu_pd(&pret.second[i + 0ULL], _mm256_cmp_pd(_mm256_loadu_pd(&v1.getIm()[i + 0ULL]),
			_mm256_loadu_pd(&v2.getIm()[i + 0ULL]), _CMP_NEQ_OQ));
		_mm256_storeu_pd(&pret.second[i + 4ULL], _mm256_cmp_pd(_mm256_loadu_pd(&v1.getIm()[i + 4ULL]),
			_mm256_loadu_pd(&v2.getIm()[i + 4ULL]), _CMP_NEQ_OQ));
#else
		//	Do not pollute cache on memory stores
		//  You must be sure that stores will not be
		// used later, so do not keep them in cache.
		_mm256_stream_pd(&pret.first[i + 0ULL], _mm256_cmp_pd(_mm256_loadu_pd(&v1.getRe()[i + 0ULL]),
			_mm256_loadu_pd(&v2.getRe()[i + 0ULL]), _CMP_NEQ_OQ));
		_mm256_stream_pd(&pret.first[i + 4ULL], _mm256_cmp_pd(_mm256_loadu_pd(&v1.getRe()[i + 4ULL]),
			_mm256_loadu_pd(&v2.getRe()[i + 4ULL]), _CMP_NEQ_OQ));
		_mm256_stream_pd(&pret.second[i + 0ULL], _mm256_cmp_pd(_mm256_loadu_pd(&v1.getIm()[i + 0ULL]),
			_mm256_loadu_pd(&v2.getIm()[i + 0ULL]), _CMP_NEQ_OQ));
		_mm256_stream_pd(&pret.second[i + 4ULL], _mm256_cmp_pd(_mm256_loadu_pd(&v1.getIm()[i + 4ULL]),
			_mm256_loadu_pd(&v2.getIm()[i + 4ULL]), _CMP_NEQ_OQ));
#endif
	}
	return (pret);
}

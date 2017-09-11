
#include "LAM_avx3vcoperators.h"
#include "../LAM_config.h"
#include "../LAM_common.h"

//
//	Implementation
//

lam::math::AVX512VComplex1D
lam::math::operator+(_In_ const AVX512VComplex1D &v1,
					 _In_ const AVX512VComplex1D &v2) {
#if LAM_DEBUG_ON == 1
	_ASSERTE(v1.get_nsize() == v2.get_nsize());
#else
	if (v1.get_nsize() != v2.get_nsize()) {
		throw std::invalid_argument("lam::math::operator+ [loc:15]: Invalid argument(s)!!");
	}
#endif
	const uint64_t vlen = v1.get_nsize();
	double* __restrict tRe = 
	reinterpret_cast<double*>(_mm_malloc(vlen*sizeof(double),align64B));
	double* __restrict tIm = 
	reinterpret_cast<double*>(_mm_malloc(vlen*sizeof(double),align64B));
	if (tRe == NULL || tIm == NULL) {
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
											lam::math::operator+ [loc:24] --> Memory allocation failure!!";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
		std::exit(-1);
	}
	for (uint64_t i = 0ULL; i != v1.get_nsize(); i += 16ULL) {
#if LAM_CACHE_MEM_STORES == 1
		_mm512_storeu_pd(&tRe[i + 0ULL], 
		_mm512_add_pd(_mm512_loadu_pd(&v1.getRe()[i+0ULL]),
		_mm512_loadu_pd(&v2.getRe()[i+0ULL])));
		_mm512_storeu_pd(&tRe[i+8ULL], 
		_mm512_add_pd(_mm512_loadu_pd(&v1.getRe()[i+8ULL]),
		_mm512_loadu_pd(&v2.getRe()[i+8ULL])));
		_mm512_storeu_pd(&tIm[i + 0ULL], 
		_mm512_add_pd(_mm512_loadu_pd(&v1.getIm()[i+0ULL]),
		_mm512_loadu_pd(&v2.getIm()[i+0ULL])));
		_mm512_storeu_pd(&tIm[i + 8ULL], 
		_mm512_add_pd(_mm512_loadu_pd(&v1.getIm()[i + 8ULL]),
		_mm512_loadu_pd(&v2.getIm()[i + 8ULL])));
#else
		_mm512_stream_pd(&tRe[i + 0ULL],
			_mm512_add_pd(_mm512_loadu_pd(&v1.getRe()[i + 0ULL]),
			_mm512_loadu_pd(&v2.getRe()[i + 0ULL])));
		_mm512_stream_pd(&tRe[i + 8ULL],
			_mm512_add_pd(_mm512_loadu_pd(&v1.getRe()[i + 8ULL]),
			_mm512_loadu_pd(&v2.getRe()[i + 8ULL])));
		_mm512_stream_pd(&tIm[i + 0ULL],
			_mm512_add_pd(_mm512_loadu_pd(&v1.getIm()[i + 0ULL]),
			_mm512_loadu_pd(&v2.getIm()[i + 0ULL])));
		_mm512_stream_pd(&tIm[i + 8ULL],
			_mm512_add_pd(_mm512_loadu_pd(&v1.getIm()[i + 8ULL]),
			_mm512_loadu_pd(&v2.getIm()[i + 8ULL])));
#endif
	}
	lam::math::AVX512VComplex1D vres(vlen,tRe,tIm);
	_mm_free(tIm);
	_mm_free(tRe);
	return (vres);
}

lam::math::AVX512VComplex1D
lam::math::operator+(_In_ const AVX512VComplex1D &v1,
					 _In_ const double* __restrict v2) {
#if LAM_DEBUG_ON == 1
	_ASSERTE(v2 != NULL); 
			 
#else
	if(v2 == NULL)
		throw std::invalid_argument("lam::math::operator+ [loc:71]: Invalid argument(s)!!")
#endif
		const uint64_t vlen = v1.get_nsize();
		double* __restrict tRe = 
		reinterpret_cast<double*>(_mm_malloc(vlen*sizeof(double),align64B));
		if (tRe == NULL) {
			std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
													lam::math::operator+ [loc:77] --> Memory allocation failure!!";
			std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
			std::exit(-1);
		}
		for (uint64_t i = 0ULL; i != vlen; i += 16ULL) {
#if LAM_CACHE_MEM_STORES == 1
			_mm512_storeu_pd(&tRe[i + 0ULL], 
			_mm512_add_pd(_mm512_loadu_pd(&v1.getRe()[i+0ULL]),
			_mm512_loadu_pd(&v2[i+0ULL])));
			_mm512_storeu_pd(&tRe[i+8ULL], 
			_mm512_add_pd(_mm512_loadu_pd(&v1.getRe()[i+8ULL]),
			_mm512_loadu_pd(&v2[i+8ULL])));
#else
			_mm512_stream_pd(&tRe[i + 0ULL],
				_mm512_add_pd(_mm512_loadu_pd(&v1.getRe()[i + 0ULL]),
				_mm512_loadu_pd(&v2[i + 0ULL])));
			_mm512_stream_pd(&tRe[i + 8ULL],
				_mm512_add_pd(_mm512_loadu_pd(&v1.getRe()[i + 8ULL]),
				_mm512_loadu_pd(&v2[i + 8ULL])));
#endif
		}
		lam::math::AVX512VComplex1D vres{ vlen, tRe, v1.getIm() };
		_mm_free(tRe);
		return (vres);
}

lam::math::AVX512VComplex1D
lam::math::operator+(_In_ const double* __restrict v1,
					 _In_ const AVX512VComplex1D &v2) {
#if LAM_DEBUG_ON == 1
	_ASSERTE(v1 != NULL);
#else
	if(v1 == NULL)
		throw std::invalid_argument("lam::math::operator+ [loc:112]: Invalid argument(s)!!")
#endif
		const uint64_t vlen = v2.get_nsize();
		double* __restrict tRe = 
		reinterpret_cast<double*>(_mm_malloc(vlen*sizeof(double),align64B));
		if (tRe == NULL) {
			std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
															lam::math::operator+ [loc:118] --> Memory allocation failure!!";
			std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
			std::exit(-1);
		}
		for (uint64_t i = 0ULL; i != vlen; i += 16ULL) {
#if LAM_CACHE_MEM_STORES == 1
			_mm512_storeu_pd(&tRe[i + 0ULL], 
			_mm512_add_pd(_mm512_loadu_pd(&v1[i+0ULL]),
			_mm512_loadu_pd(&v2.getRe()[i+0ULL])));
			_mm512_storeu_pd(&tRe[i + 8ULL], 
			_mm512_add_pd(_mm512_loadu_pd(&v1[i+8ULL]),
			_mm512_loadu_pd(&v2.getRe()[i + 8ULL])));
#else
			_mm512_stream_pd(&tRe[i + 0ULL],
				_mm512_add_pd(_mm512_loadu_pd(&v1[i + 0ULL]),
				_mm512_loadu_pd(&v2.getRe()[i + 0ULL])));
			_mm512_stream_pd(&tRe[i + 8ULL],
				_mm512_add_pd(_mm512_loadu_pd(&v1[i + 8ULL]),
				_mm512_loadu_pd(&v2.getRe()[i + 8ULL])));
#endif
		}
		lam::math::AVX512VComplex1D vres{ vlen, tRe, v2.getIm() };
		_mm_free(tRe);
		return (vres);
}

lam::math::AVX512VComplex1D
lam::math::operator-(_In_ const AVX512VComplex1D &v1,
					 _In_ const AVX512VComplex1D &v2) {
#if LAM_DEBUG_ON == 1
	_ASSERTE(v1.get_nsize() == v2.get_nsize());
#else
	if(v1.get_nsize() != v2.get_nsize())
		throw std::invalid_argument("lam::math::operator- [loc:152]: Invalid argument(s)!!")
#endif
		const uint64_t vlen = v1.get_nsize();
		double* __restrict tRe = 
		reinterpret_cast<double*>(_mm_malloc(vlen*sizeof(double),align64B));
		double* __restrict tIm = 
		reinterpret_cast<double*>(_mm_malloc(vlen*sizeof(double),align64B));
		if (tRe == NULL || tIm == NULL) {
			std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
											lam::math::operator- [loc:160] --> Memory allocation failure!!";
			std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
			std::exit(-1);
		}
		for (uint64_t i = 0ULL; i != vlen; i += 16ULL) {
#if LAM_CACHE_MEM_STORES == 1
			_mm512_storeu_pd(&tRe[i + 0ULL], 
			_mm512_sub_pd(_mm512_loadu_pd(&v1.getRe()[i+0ULL]),
			_mm512_loadu_pd(&v2.getRe()[i+0ULL])));
			_mm512_storeu_pd(&tRe[i + 8ULL], 
			_mm512_sub_pd(_mm512_loadu_pd(&v1.getRe()[i+8ULL]),
			_mm512_loadu_pd(&v2.getRe()[i + 8ULL])));
			_mm512_storeu_pd(&tIm[i + 0ULL], 
			_mm512_sub_pd(_mm512_loadu_pd(&v1.getIm()[i+0ULL]),
			_mm512_loadu_pd(&v2.getIm()[i+0ULL])));
			_mm512_storeu_pd(&tIm[i + 8ULL], 
			_mm512_sub_pd(_mm512_loadu_pd(&v1.getIm()[i + 8ULL]),
			_mm512_loadu_pd(&v2.getIm()[i + 8ULL])));
#else
			_mm512_stream_pd(&tRe[i + 0ULL],
				_mm512_sub_pd(_mm512_loadu_pd(&v1.getRe()[i + 0ULL]),
				_mm512_loadu_pd(&v2.getRe()[i + 0ULL])));
			_mm512_stream_pd(&tRe[i + 8ULL],
				_mm512_sub_pd(_mm512_loadu_pd(&v1.getRe()[i + 8ULL]),
				_mm512_loadu_pd(&v2.getRe()[i + 8ULL])));
			_mm512_stream_pd(&tIm[i + 0ULL],
				_mm512_sub_pd(_mm512_loadu_pd(&v1.getIm()[i + 0ULL]),
				_mm512_loadu_pd(&v2.getIm()[i + 0ULL])));
			_mm512_stream_pd(&tIm[i + 8ULL],
				_mm512_sub_pd(_mm512_loadu_pd(&v1.getIm()[i + 8ULL]),
				_mm512_loadu_pd(&v2.getIm()[i + 8ULL])));
#endif
		}
		lam::math::AVX512VComplex1D vres{vlen,tRe,tIm};
		_mm_free(tIm);
		_mm_free(tRe);
		return (vres);
}

lam::math::AVX512VComplex1D
lam::math::operator-(_In_ const AVX512VComplex1D &v1,
					 _In_ const double* __restrict v2) {
#if LAM_DEBUG_ON == 1
	_ASSERTE(v2 != NULL);
#else
	if(v2 == NULL)
		throw std::invalid_argument("lam::math::operator- [loc:207]: Invalid argument(s)!!")
#endif
		const uint64_t vlen = v1.get_nsize();
		double * __restrict tRe = 
		reinterpret_cast<double*>(_mm_malloc(vlen*sizeof(double),align64B));
		if (tRe == NULL) {
			std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
													lam::math::operator- [loc:213] --> Memory allocation failure!!";
			std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
			std::exit(-1);
		}
		for (uint64_t i = 0ULL; i != vlen; i += 16ULL) {
#if LAM_CACHE_MEM_STORES == 1
			_mm512_storeu_pd(&tRe[i + 0ULL], 
			_mm512_sub_pd(_mm512_loadu_pd(&v1.getRe()[i+0ULL]),
			_mm512_loadu_pd(&v2[i+0ULL])));
			_mm512_storeu_pd(&tRe[i + 8ULL], 
			_mm512_sub_pd(_mm512_loadu_pd(&v1.getRe()[i+8ULL]),
			_mm512_loadu_pd(&v2[i + 8ULL])));
#else
			_mm512_stream_pd(&tRe[i + 0ULL],
				_mm512_sub_pd(_mm512_loadu_pd(&v1.getRe()[i + 0ULL]),
				_mm512_loadu_pd(&v2[i + 0ULL])));
			_mm512_stream_pd(&tRe[i + 8ULL],
				_mm512_sub_pd(_mm512_loadu_pd(&v1.getRe()[i + 8ULL]),
				_mm512_loadu_pd(&v2[i + 8ULL])));
#endif
		}
		lam::math::AVX512VComplex1D vres{ vlen, tRe, v1.getIm() };
		_mm_free(tRe);
		return (vres);
}

lam::math::AVX512VComplex1D
lam::math::operator-(_In_ const double* __restrict v1,
					 _In_ const AVX512VComplex1D &v2) {
#if LAM_DEBUG_ON == 1
	_ASSERTE(v1 != NULL);
#else
	if(v1 == NULL)
		throw std::invalid_argument("lam::math::operator- [loc:247]: Invalid argument(s)!!")
#endif
		const uint64_t vlen = v2.get_nsize();
		double * __restrict tRe = 
		reinterpret_cast<double*>(_mm_malloc(vlen*sizeof(double),align64B));
		if (tRe == NULL) {
			std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
																	lam::math::operator- [loc:253] --> Memory allocation failure!!";
			std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
			std::exit(-1);
		}
		for (uint64_t i = 0ULL; i != vlen; i += 16ULL) {
#if LAM_CACHE_MEM_STORES == 1
			_mm512_storeu_pd(&tRe[i + 0ULL], 
			_mm512_sub_pd(_mm512_loadu_pd(&v1[i+0ULL]),
			_mm512_loadu_pd(&v2.getRe()[i+0ULL])));
			_mm512_storeu_pd(&tRe[i + 8ULL], 
			_mm512_sub_pd(_mm512_loadu_pd(&v1[i+8ULL]),
			_mm512_loadu_pd(&v2.getRe()[i + 8ULL])));
#else
			_mm512_stream_pd(&tRe[i + 0ULL],
				_mm512_sub_pd(_mm512_loadu_pd(&v1[i + 0ULL]),
				_mm512_loadu_pd(&v2.getRe()[i + 0ULL])));
			_mm512_stream_pd(&tRe[i + 8ULL],
				_mm512_sub_pd(_mm512_loadu_pd(&v1[i + 8ULL]),
				_mm512_loadu_pd(&v2.getRe()[i + 8ULL])));
#endif
		}
		lam::math::AVX512VComplex1D vres{ vlen, tRe, v2.getIm() };
		_mm_free(tRe);
		return (vres);
}

lam::math::AVX512VComplex1D
lam::math::operator*(_In_ const AVX512VComplex1D &v1,
					 _In_ const AVX512VComplex1D &v2) {
#if LAM_DEBUG_ON == 1
	_ASSERTE(v1.get_nsize() == v2.get_nsize());
#else
	if(v1.get_nsize() != v2.get_nsize()) {
		throw std::invalid_argument("lam::math::operator* [loc:287]: v1.get_nsize() != v2.get_nsize()!!")
	}
#endif
	const uint64_t vlen = v1.get_nsize();
	double * __restrict tRe = 
	reinterpret_cast<double*>(_mm_malloc(vlen*sizeof(double),align64B));
	double * __restrict tIm = 
	reinterpret_cast<double*>(_mm_malloc(vlen*sizeof(double),align64B));
	if (tRe == NULL || tIm == NULL) {
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
													lam::math::operator* [loc:296] --> Memory allocation failure!!";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
		std::exit(-1);
	}
	for (uint64_t i = 0ULL; i != vlen; i += 16ULL) {
#if LAM_CACHE_MEM_STORES == 1
		_mm512_storeu_pd(&tRe[i + 0ULL], _mm512_sub_pd(_mm512_mul_pd(_mm512_loadu_pd(&v1.getRe()[i+0ULL]),
			_mm512_loadu_pd(&v2.getRe()[i+0ULL])),_mm512_mul_pd(_mm512_loadu_pd(&v1.getIm()[i+0ULL]),
			_mm512_loadu_pd(&v2.getIm()[i+0ULL]))));
		_mm512_storeu_pd(&tRe[i + 8ULL], _mm512_sub_pd(_mm512_mul_pd(_mm512_loadu_pd(&v1.getRe()[i + 8ULL]),
			_mm512_loadu_pd(&v2.getRe()[i + 8ULL])), _mm512_mul_pd(_mm512_loadu_pd(&v1.getIm()[i + 8ULL]),
			_mm512_loadu_pd(&v2.getIm()[i + 8ULL]))));
		_mm512_storeu_pd(&tIm[i + 0ULL], _mm512_add_pd(_mm512_mul_pd(_mm512_loadu_pd(&v1.getIm()[i+0ULL]),
			_mm512_loadu_pd(&v2.getRe()[i + 0ULL])), _mm512_mul_pd(_mm512_loadu_pd(&v1.getRe()[i+0ULL]),
			_mm512_loadu_pd(&v2.getIm()[i+0ULL]))));
		_mm512_storeu_pd(&tIm[i + 8ULL], _mm512_add_pd(_mm512_mul_pd(_mm512_loadu_pd(&v1.getIm()[i + 8ULL]),
			_mm512_loadu_pd(&v2.getRe()[i + 8ULL])), _mm512_mul_pd(_mm512_loadu_pd(&v1.getRe()[i + 8ULL]),
			_mm512_loadu_pd(&v2.getIm()[i + 8ULL]))));
#else
		_mm512_stream_pd(&tRe[i + 0ULL], _mm512_sub_pd(_mm512_mul_pd(_mm512_loadu_pd(&v1.getRe()[i + 0ULL]),
			_mm512_loadu_pd(&v2.getRe()[i + 0ULL])), _mm512_mul_pd(_mm512_loadu_pd(&v1.getIm()[i + 0ULL]),
			_mm512_loadu_pd(&v2.getIm()[i + 0ULL]))));
		_mm512_stream_pd(&tRe[i + 8ULL], _mm512_sub_pd(_mm512_mul_pd(_mm512_loadu_pd(&v1.getRe()[i + 8ULL]),
			_mm512_loadu_pd(&v2.getRe()[i + 8ULL])), _mm512_mul_pd(_mm512_loadu_pd(&v1.getIm()[i + 8ULL]),
			_mm512_loadu_pd(&v2.getIm()[i + 8ULL]))));
		_mm512_stream_pd(&tIm[i + 0ULL], _mm512_add_pd(_mm512_mul_pd(_mm512_loadu_pd(&v1.getIm()[i + 0ULL]),
			_mm512_loadu_pd(&v2.getRe()[i + 0ULL])), _mm512_mul_pd(_mm512_loadu_pd(&v1.getRe()[i + 0ULL]),
			_mm512_loadu_pd(&v2.getIm()[i + 0ULL]))));
		_mm512_stream_pd(&tIm[i + 8ULL], _mm512_add_pd(_mm512_mul_pd(_mm512_loadu_pd(&v1.getIm()[i + 8ULL]),
			_mm512_loadu_pd(&v2.getRe()[i + 8ULL])), _mm512_mul_pd(_mm512_loadu_pd(&v1.getRe()[i + 8ULL]),
			_mm512_loadu_pd(&v2.getIm()[i + 8ULL]))));
#endif
	}
	lam::math::AVX512VComplex1D vres{vlen,tRe,tIm};
	_mm_free(tIm);
	_mm_free(tRe);
	return (vres);
}

lam::math::AVX512VComplex1D
lam::math::operator*(_In_ const AVX512VComplex1D &v1,
					 _In_ const double* __restrict v2) {
#if LAM_DEBUG_ON == 1
	_ASSERTE(v2 != NULL);
#else
	if(v2 == NULL)
		throw std::invalid_argument("lam::math::operator* [loc:287]: v2 == NULL");
#endif
	const uint64_t vlen = v1.get_nsize();
	double* __restrict tRe = 
	reinterpret_cast<double*>(_mm_malloc(vlen*sizeof(double),align64B));
	double* __restrict tIm = 
	reinterpret_cast<double*>(_mm_malloc(vlen*sizeof(double),align64B));
	if (tRe == NULL || tIm == NULL) {
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
												 	lam::math::operator* [loc:349] --> Memory allocation failure!!";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
		std::exit(-1);
	}
	for (uint64_t i = 0ULL; i != vlen; i += 16ULL) {
#if LAM_CACHE_MEM_STORES == 1
		_mm512_storeu_pd(&tRe[i+0ULL], _mm512_mul_pd(_mm512_loadu_pd(&v1.getRe()[i+0ULL]),
			_mm512_loadu_pd(&v2[i+0ULL])));
		_mm512_storeu_pd(&tRe[i + 8ULL], _mm512_mul_pd(_mm512_loadu_pd(&v1.getRe()[i + 8ULL]),
			_mm512_loadu_pd(&v2[i + 8ULL])));
		_mm512_storeu_pd(&tIm[i + 0ULL], _mm512_mul_pd(_mm512_loadu_pd(&v1.getIm()[i+0ULL]),
			_mm512_loadu_pd(&v2[i+0ULL])));
		_mm512_storeu_pd(&tIm[i + 8ULL], _mm512_mul_pd(_mm512_loadu_pd(&v1.getIm()[i + 8ULL]),
			_mm512_loadu_pd(&v2[i + 8ULL])));
#else
		_mm512_stream_pd(&tRe[i + 0ULL], _mm512_mul_pd(_mm512_loadu_pd(&v1.getRe()[i + 0ULL]),
			_mm512_loadu_pd(&v2[i + 0ULL])));
		_mm512_stream_pd(&tRe[i + 8ULL], _mm512_mul_pd(_mm512_loadu_pd(&v1.getRe()[i + 8ULL]),
			_mm512_loadu_pd(&v2[i + 8ULL])));
		_mm512_stream_pd(&tIm[i + 0ULL], _mm512_mul_pd(_mm512_loadu_pd(&v1.getIm()[i + 0ULL]),
			_mm512_loadu_pd(&v2[i + 0ULL])));
		_mm512_stream_pd(&tIm[i + 8ULL], _mm512_mul_pd(_mm512_loadu_pd(&v1.getIm()[i + 8ULL]),
			_mm512_loadu_pd(&v2[i + 8ULL])));
#endif
	}
	lam::math::AVX512VComplex1D vres{vlen,tRe,tIm};
	_mm_free(tIm);
	_mm_free(tRe);
	return (vres);
}

lam::math::AVX512VComplex1D
lam::math::operator*(_In_ const double* __restrict v1,
					 _In_ const AVX512VComplex1D &v2) {
#if LAM_DEBUG_ON == 1
	_ASSERTE(v1 != NULL);
#else
	if(v1 == NULL)
		throw std::invalid_argument("lam::math::operator* [loc:390]: v1 == NULL");
#endif
		const uint64_t vlen = v2.get_nsize();
		double* __restrict tRe = 
		reinterpret_cast<double*>(_mm_malloc(vlen*sizeof(double),align64B));
		double* __restrict tIm = 
	    reinterpret_cast<double*>(_mm_malloc(vlen*sizeof(double),align64B));
		if (tRe == NULL || tIm == NULL) {
			std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
														 	lam::math::operator* [loc:398] --> Memory allocation failure!!";
			std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
			std::exit(-1);
		}
		for (uint64_t i = 0ULL; i != vlen; i += 16ULL) {
#if LAM_CACHE_MEM_STORES == 1
			_mm512_storeu_pd(&tRe[i + 0ULL], _mm512_mul_pd(_mm512_loadu_pd(&v1[i+0ULL]),
				_mm512_loadu_pd(&v2.getRe()[i+0ULL])));
			_mm512_storeu_pd(&tRe[i + 8ULL], _mm512_mul_pd(_mm512_loadu_pd(&v1[i+8ULL]),
				_mm512_loadu_pd(&v2.getRe()[i + 8ULL])));
			_mm512_storeu_pd(&tIm[i + 0ULL], _mm512_mul_pd(_mm512_loadu_pd(&v1[i+0ULL]),
				_mm512_loadu_pd(&v2.getIm()[i+0ULL])));
			_mm512_storeu_pd(&tIm[i + 8ULL], _mm512_mul_pd(_mm512_loadu_pd(&v1[i + 8ULL]),
				_mm512_loadu_pd(&v2.getIm()[i + 8ULL])));
#else
			_mm512_stream_pd(&tRe[i + 0ULL], _mm512_mul_pd(_mm512_loadu_pd(&v1[i + 0ULL]),
				_mm512_loadu_pd(&v2.getRe()[i + 0ULL])));
			_mm512_stream_pd(&tRe[i + 8ULL], _mm512_mul_pd(_mm512_loadu_pd(&v1[i + 8ULL]),
				_mm512_loadu_pd(&v2.getRe()[i + 8ULL])));
			_mm512_stream_pd(&tIm[i + 0ULL], _mm512_mul_pd(_mm512_loadu_pd(&v1[i + 0ULL]),
				_mm512_loadu_pd(&v2.getIm()[i + 0ULL])));
			_mm512_stream_pd(&tIm[i + 8ULL], _mm512_mul_pd(_mm512_loadu_pd(&v1[i + 8ULL]),
				_mm512_loadu_pd(&v2.getIm()[i + 8ULL])));
#endif
		}
		lam::math::AVX512VComplex1D vres{vlen,tRe,tIm};
		_mm_free(tIm);
		_mm_free(tRe);
		return (vres);
}

lam::math::AVX512VComplex1D
lam::math::operator/(_In_ const AVX512VComplex1D &v1,
					 _In_ const AVX512VComplex1D &v2) {
#if LAM_DEBUG_ON == 1
	_ASSERTE(v1.get_nsize() == v2.get_nsize());
#else
	if(v1.get_nsize() != v2.get_nsize()) 
		throw std::invalid_argument("lam::math::operator/ [loc:437]: v1.get_nsize() != v2.get_nsize()");
#endif
	if (lam::common::vzero_check(v1.getRe(),v1.getIm(),v1.get_nsize()) ||
		lam::common::vzero_check(v2.getRe(),v2.getIm(),v2.get_nsize())) {
		throw std::domain_error("AVX512VComplex1D::operator/ [loc:462] --> found '0.0' in AVX512VComplex1D");
	}
	const uint64_t vlen = v1.get_nsize();
	double* __restrict tRe = 
	reinterpret_cast<double*>(_mm_malloc(vlen*sizeof(double),align64B));
	double* __restrict tIm = 
	reinterpret_cast<double*>(_mm_malloc(vlen*sizeof(double),align64B));
	if (tRe == NULL || tIm == NULL) {
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
														lam::math::operator/ [loc:450] --> Memory allocation failure!!";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
		std::exit(-1);
	}
	for (uint64_t i = 0ULL; i != vlen; i += 16ULL) {
#if LAM_DEBUG_ON == 1
		__m512d tre1 = _mm512_add_pd(_mm512_mul_pd(_mm512_loadu_pd(&v1.getRe()[i+0ULL]),
			_mm512_loadu_pd(&v2.getIm()[i+0ULL])),_mm512_mul_pd(_mm512_loadu_pd(&v1.getIm()[i+0ULL]),
			_mm512_loadu_pd(&v2.getIm()[i+0ULL])));
		__m512d tre2 = _mm512_add_pd(_mm512_mul_pd(_mm512_loadu_pd(&v1.getRe()[i + 8ULL]),
			_mm512_loadu_pd(&v2.getIm()[i + 8ULL])), _mm512_mul_pd(_mm512_loadu_pd(&v1.getIm()[i + 8ULL]),
			_mm512_loadu_pd(&v2.getIm()[i + 8ULL])));
		__m512d tim1 = _mm512_sub_pd(_mm512_mul_pd(_mm512_loadu_pd(&v1.getIm()[i+0ULL]),
			_mm512_loadu_pd(&v2.getIm()[i + 0ULL])), _mm512_mul_pd(_mm512_loadu_pd(&v1.getRe()[i+0ULL]),
			_mm512_loadu_pd(&v2.getIm()[i+0ULL])));
		__m512d tim2 = _mm512_sub_pd(_mm512_mul_pd(_mm512_loadu_pd(&v1.getIm()[i + 8ULL]),
			_mm512_loadu_pd(&v2.getIm()[i + 8ULL])), _mm512_mul_pd(_mm512_loadu_pd(&v1.getRe()[i + 8ULL]),
			_mm512_loadu_pd(&v2.getIm()[i + 8ULL])));
		__m512d den1 = _mm512_add_pd(_mm512_mul_pd(_mm512_loadu_pd(&v2.getRe()[i+0ULL]),
			_mm512_loadu_pd(&v2.getRe()[i + 0ULL])), _mm512_mul_pd(_mm512_loadu_pd(&v2.getIm()[i+0ULL]),
			_mm512_loadu_pd(&v2.getIm()[i+0ULL])));
		__m512d den2 = _mm512_add_pd(_mm512_mul_pd(_mm512_loadu_pd(&v2.getRe()[i + 8ULL]),
			_mm512_loadu_pd(&v2.getRe()[i + 8ULL])), _mm512_mul_pd(_mm512_loadu_pd(&v2.getIm()[i + 8ULL]),
			_mm512_loadu_pd(&v2.getIm()[i + 8ULL])));

		_mm512_storeu_pd(&tRe[i + 0ULL], _mm512_div_pd(tre1,den1));
		_mm512_storeu_pd(&tRe[i + 8ULL], _mm512_div_pd(tre2,den2));
		_mm512_storeu_pd(&tIm[i + 0ULL], _mm512_div_pd(tim1,den1));
		_mm512_storeu_pd(&tIm[i + 8ULL], _mm512_div_pd(tim2,den2));
#else
		__m512d tre1 = _mm512_add_pd(_mm512_mul_pd(_mm512_loadu_pd(&v1.getRe()[i + 0ULL]),
			_mm512_loadu_pd(&v2.getIm()[i + 0ULL])), _mm512_mul_pd(_mm512_loadu_pd(&v1.getIm()[i + 0ULL]),
			_mm512_loadu_pd(&v2.getIm()[i + 0ULL])));
		__m512d tre2 = _mm512_add_pd(_mm512_mul_pd(_mm512_loadu_pd(&v1.getRe()[i + 8ULL]),
			_mm512_loadu_pd(&v2.getIm()[i + 8ULL])), _mm512_mul_pd(_mm512_loadu_pd(&v1.getIm()[i + 8ULL]),
			_mm512_loadu_pd(&v2.getIm()[i + 8ULL])));
		__m512d tim1 = _mm512_sub_pd(_mm512_mul_pd(_mm512_loadu_pd(&v1.getIm()[i + 0ULL]),
			_mm512_loadu_pd(&v2.getIm()[i + 0ULL])), _mm512_mul_pd(_mm512_loadu_pd(&v1.getRe()[i + 0ULL]),
			_mm512_loadu_pd(&v2.getIm()[i + 0ULL])));
		__m512d tim2 = _mm512_sub_pd(_mm512_mul_pd(_mm512_loadu_pd(&v1.getIm()[i + 8ULL]),
			_mm512_loadu_pd(&v2.getIm()[i + 8ULL])), _mm512_mul_pd(_mm512_loadu_pd(&v1.getRe()[i + 8ULL]),
			_mm512_loadu_pd(&v2.getIm()[i + 8ULL])));
		__m512d den1 = _mm512_add_pd(_mm512_mul_pd(_mm512_loadu_pd(&v2.getRe()[i + 0ULL]),
			_mm512_loadu_pd(&v2.getRe()[i + 0ULL])), _mm512_mul_pd(_mm512_loadu_pd(&v2.getIm()[i + 0ULL]),
			_mm512_loadu_pd(&v2.getIm()[i + 0ULL])));
		__m512d den2 = _mm512_add_pd(_mm512_mul_pd(_mm512_loadu_pd(&v2.getRe()[i + 8ULL]),
			_mm512_loadu_pd(&v2.getRe()[i + 8ULL])), _mm512_mul_pd(_mm512_loadu_pd(&v2.getIm()[i + 8ULL]),
			_mm512_loadu_pd(&v2.getIm()[i + 8ULL])));

		_mm512_stream_pd(&tRe[i + 0ULL], _mm512_div_pd(tre1, den1));
		_mm512_stream_pd(&tRe[i + 8ULL], _mm512_div_pd(tre2, den2));
		_mm512_stream_pd(&tIm[i + 0ULL], _mm512_div_pd(tim1, den1));
		_mm512_stream_pd(&tIm[i + 8ULL], _mm512_div_pd(tim2, den2));
#endif
	}
	lam::math::AVX512VComplex1D vres{vlen,tRe,tIm};
	_mm_free(tIm);
	_mm_free(tRe);
	return (vres);
}

lam::math::AVX512VComplex1D
lam::math::operator/(_In_ const double* __restrict v1,
					 _In_ const AVX512VComplex1D &v2) {
	 using namespace lam::common;
#if LAM_DEBUG_ON == 1
	_ASSERTE(v1 != NULL);
#else
	if(v1 == NULL)
		throw std::invalid_argument("lam::math::operator/ [loc:437]: v1 == NULL");
#endif
	const uint64_t vlen = v2.get_nsize();
	if (vzero_check1(v1, v2.get_nsize()) ||
		vzero_check(v2.getRe(), v2.getIm(), v2.get_nsize())) {
		throw std::domain_error("AVX512VComplex1D::operator/ [loc:524] --> found '0.0' in AVX512VComplex1D");
	}
	double* __restrict tRe = 
	reinterpret_cast<double*>(_mm_malloc(vlen*sizeof(double),align64B));
	double* __restrict tIm = 
	reinterpret_cast<double*>(_mm_malloc(vlen*sizeof(double),align64B));
	if (tRe == NULL || tIm == NULL) {
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
													lam::math::operator/ [loc:450] --> Memory allocation failure!!";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
		std::exit(-1);
	}
	for (uint64_t i = 0ULL; i != vlen; i += 16ULL) {
#if LAM_CACHE_MEM_STORES == 1
		
		_mm512_storeu_pd(&tRe[i + 0ULL], _mm512_div_pd(_mm512_loadu_pd(&v1[i+0ULL]),
			_mm512_loadu_pd(&v2.getRe()[i+0ULL])));
		_mm512_storeu_pd(&tRe[i + 8ULL], _mm512_div_pd(_mm512_loadu_pd(&v1[i+8ULL]),
			_mm512_loadu_pd(&v2.getRe()[i + 8ULL])));
		_mm512_storeu_pd(&tIm[i + 0ULL], _mm512_div_pd(_mm512_loadu_pd(&v1[i+0ULL]),
			_mm512_loadu_pd(&v2.getIm()[i+0ULL])));
		_mm512_storeu_pd(&tIm[i + 8ULL], _mm512_div_pd(_mm512_loadu_pd(&v1[i + 8ULL]),
			_mm512_loadu_pd(&v2.getIm()[i + 8ULL])));
#else
		
		_mm512_stream_pd(&tRe[i + 0ULL], _mm512_div_pd(_mm512_loadu_pd(&v1[i + 0ULL]),
			_mm512_loadu_pd(&v2.getRe()[i + 0ULL])));
		_mm512_stream_pd(&tRe[i + 8ULL], _mm512_div_pd(_mm512_loadu_pd(&v1[i + 8ULL]),
			_mm512_loadu_pd(&v2.getRe()[i + 8ULL])));
		_mm512_stream_pd(&tIm[i + 0ULL], _mm512_div_pd(_mm512_loadu_pd(&v1[i + 0ULL]),
			_mm512_loadu_pd(&v2.getIm()[i + 0ULL])));
		_mm512_stream_pd(&tIm[i + 8ULL], _mm512_div_pd(_mm512_loadu_pd(&v1[i + 8ULL]),
			_mm512_loadu_pd(&v2.getIm()[i + 8ULL])));
#endif
	}
	lam::math::AVX512VComplex1D vres{vlen,tRe,tIm};
	_mm_free(tIm);
	_mm_free(tRe);
	return (vres);
}

std::pair<double*,double*>
lam::math::operator==(_In_ const AVX512VComplex1D &v1,
					  _In_ const AVX512VComplex1D &v2) {
#if LAM_DEBUG_ON == 1
	_ASSERTE(v1.get_nsize() == v2.get_nsize());
#else
	if(v1.get_nsize() != v2.get_nsize())
		throw std::invalid_argument("lam::math::operator== [loc:573]: 1.get_nsize() == v2.get_nsize() ");
#endif
	const uint64_t vlen = v1.get_nsize();
	double* __restrict pr1 = 
	reinterpret_cast<double*>(_mm_malloc(vlen*sizeof(double),align64B));
	double* __restrict pr2 = 
	reinterpret_cast<double*>(_mm_malloc(vlen*sizeof(double),align64B));
	if (pr1 == NULL || pr2 == NULL) {
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
												lam::math::operator== [loc:581] --> Memory allocation failure!!";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
		std::exit(-1);
	}
	std::pair<double*,double*> pret;
	lam::common::init_varray(pr1,vlen,-1.0);
	lam::common::init_varray(pr2,vlen,-1.0);
	for (uint64_t i = 0ULL; i != vlen; i += 8ULL) {
#if LAM_CACHE_MEM_STORES == 1
		// Using AVX for comparison.
		// Unrolled 2x in order to match perfectly
		// per core 2 load operations per cycle.
		_mm256_storeu_pd(&pret.first[i + 0ULL],
			_mm256_cmp_pd(_mm256_loadu_pd(&v1.getRe()[i+0ULL]),
			_mm256_loadu_pd(&v2.getRe()[i+0ULL]),_CMP_EQ_OQ));
		_mm256_storeu_pd(&pret.first[i + 4ULL],
			_mm256_cmp_pd(_mm256_loadu_pd(&v1.getRe()[i + 4ULL]),
			_mm256_loadu_pd(&v2.getRe()[i + 4ULL]), _CMP_EQ_OQ));
		_mm256_storeu_pd(&pret.second[i + 0ULL],
			_mm256_cmp_pd(_mm256_loadu_pd(&v1.getIm()[i + 0ULL]),
			_mm256_loadu_pd(&v2.getIm()[i + 0ULL]), _CMP_EQ_OQ));
		_mm256_storeu_pd(&pret.second[i + 4ULL],
			_mm256_cmp_pd(_mm256_loadu_pd(&v1.getIm()[i + 4ULL]),
			_mm256_loadu_pd(&v2.getIm()[i + 4ULL]), _CMP_EQ_OQ));
#else
		// Stream version in order to not pollute the cache
		// on store operation.
		_mm256_stream_pd(&pret.first[i + 0ULL],
			_mm256_cmp_pd(_mm256_loadu_pd(&v1.getRe()[i + 0ULL]),
			_mm256_loadu_pd(&v2.getRe()[i + 0ULL]), _CMP_EQ_OQ));
		_mm256_stream_pd(&pret.first[i + 4ULL],
			_mm256_cmp_pd(_mm256_loadu_pd(&v1.getRe()[i + 4ULL]),
			_mm256_loadu_pd(&v2.getRe()[i + 4ULL]), _CMP_EQ_OQ));
		_mm256_stream_pd(&pret.second[i + 0ULL],
			_mm256_cmp_pd(_mm256_loadu_pd(&v1.getIm()[i + 0ULL]),
			_mm256_loadu_pd(&v2.getIm()[i + 0ULL]), _CMP_EQ_OQ));
		_mm256_stream_pd(&pret.second[i + 4ULL],
			_mm256_cmp_pd(_mm256_loadu_pd(&v1.getIm()[i + 4ULL]),
			_mm256_loadu_pd(&v2.getIm()[i + 4ULL]), _CMP_EQ_OQ));
#endif
	}
	return (pret);
}

std::pair<double*,double*>
lam::math::operator!=(_In_ const AVX512VComplex1D &v1,
					  _In_ const AVX512VComplex1D &v2) {
#if LAM_DEBUG_ON == 1
	_ASSERTE(v1.get_nsize() == v2.get_nsize());
#else
	if (v1.get_nsize() != v2.get_nsize())
		throw std::invalid_argument("lam::math::operator!= [loc:633]: 1.get_nsize() == v2.get_nsize() ");
#endif
	const uint64_t vlen = v1.get_nsize();
	double* __restrict pr1 =
		reinterpret_cast<double*>(_mm_malloc(vlen*sizeof(double), align64B));
	double* __restrict pr2 =
		reinterpret_cast<double*>(_mm_malloc(vlen*sizeof(double), align64B));
	if (pr1 == NULL || pr2 == NULL) {
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
											lam::math::operator!= [loc:641] --> Memory allocation failure!!";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
		std::exit(-1);
	}
	std::pair<double*, double*> pret;
	lam::common::init_varray(pr1, vlen, -1.0);
	lam::common::init_varray(pr2, vlen, -1.0);
	for (uint64_t i = 0ULL; i != vlen; i += 8ULL) {
#if LAM_CACHE_MEM_STORES == 1
		// Using AVX for comparison.
		// Unrolled 2x in order to match perfectly
		// per core 2 load operations per cycle.
		_mm256_storeu_pd(&pret.first[i + 0ULL],
			_mm256_cmp_pd(_mm256_loadu_pd(&v1.getRe()[i + 0ULL]),
			_mm256_loadu_pd(&v2.getRe()[i + 0ULL]), _CMP_NEQ_OQ));
		_mm256_storeu_pd(&pret.first[i + 4ULL],
			_mm256_cmp_pd(_mm256_loadu_pd(&v1.getRe()[i + 4ULL]),
			_mm256_loadu_pd(&v2.getRe()[i + 4ULL]), _CMP_NEQ_OQ));
		_mm256_storeu_pd(&pret.second[i + 0ULL],
			_mm256_cmp_pd(_mm256_loadu_pd(&v1.getIm()[i + 0ULL]),
			_mm256_loadu_pd(&v2.getIm()[i + 0ULL]), _CMP_NEQ_OQ));
		_mm256_storeu_pd(&pret.second[i + 4ULL],
			_mm256_cmp_pd(_mm256_loadu_pd(&v1.getIm()[i + 4ULL]),
			_mm256_loadu_pd(&v2.getIm()[i + 4ULL]), _CMP_NEQ_OQ));
#else
		// Stream version in order to not pollute the cache
		// on store operation.
		_mm256_stream_pd(&pret.first[i + 0ULL],
			_mm256_cmp_pd(_mm256_loadu_pd(&v1.getRe()[i + 0ULL]),
			_mm256_loadu_pd(&v2.getRe()[i + 0ULL]), _CMP_NEQ_OQ));
		_mm256_stream_pd(&pret.first[i + 4ULL],
			_mm256_cmp_pd(_mm256_loadu_pd(&v1.getRe()[i + 4ULL]),
			_mm256_loadu_pd(&v2.getRe()[i + 4ULL]), _CMP_NEQ_OQ));
		_mm256_stream_pd(&pret.second[i + 0ULL],
			_mm256_cmp_pd(_mm256_loadu_pd(&v1.getIm()[i + 0ULL]),
			_mm256_loadu_pd(&v2.getIm()[i + 0ULL]), _CMP_NEQ_OQ));
		_mm256_stream_pd(&pret.second[i + 4ULL],
			_mm256_cmp_pd(_mm256_loadu_pd(&v1.getIm()[i + 4ULL]),
			_mm256_loadu_pd(&v2.getIm()[i + 4ULL]), _CMP_NEQ_OQ));
#endif
	}
	return (pret);
}
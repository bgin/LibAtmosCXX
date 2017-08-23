
//
//	Implementation
//

typedef std::vector<bool>::size_type st;

template<typename Real_t> 
lam::math::VComplex1D<Real_t>
lam::math::operator+(_In_ const VComplex1D<Real_t> &v1,
                     _In_ const VComplex1D<Real_t> &v2) {

	if (!v1.get_isbuilt() || !v2.get_isbuilt() ||
		 v1.get_nsize() != v2.get_nsize()) {
#if LAM_VERBOSE_DEBUG_ON == 1
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
						lam::math::operator+ [loc:11] --> Invalid argument(s)";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
#endif
		throw std::invalid_argument("lam::math::operator+ [loc:11] --> Invalid argument(s)!!");
	}
	Real_t* __restrict tRe = 
	reinterpret_cast<Real_t*>(_mm_malloc(v1.get_nsize()*sizeof(Real_t),align32B));
	Real_t* __restrict tIm = 
	reinterpret_cast<Real_t*>(_mm_malloc(v1.get_nsize()*sizeof(Real_t),align32B));
	if (tRe == NULL || tIm == NULL) {
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
											lam::math::operator+ [loc:11] --> Memory allocation failure!!";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
		std::exit(-1);
	}
#if USE_AUTO_VEC == 1
#pragma ivdep
#pragma simd
#pragma unroll(4)
#endif
	for (uint64_t i = 0; i != v1.get_nsize(); ++i) {
		tRe[i] = v1.get_Re()[i] + v2.get_Re()[i];
		tIm[i] = v1.get_Im()[i] + v2.get_Im()[i];
	}
	VComplex1D<Real_t> vres{ v1.get_nsize(),tRe,tIm };
	_mm_free(tIm);
	_mm_free(tRe);

	return (vres);
}		  


template<typename Real_t>
lam::math::VComplex1D<Real_t>
lam::math::operator+(_In_ const VComplex1D<Real_t> &v1,
			         _In_ const Real_t* __restrict v2) {
		
	if (!v1.get_isbuilt() || v2 == NULL) {
#if LAM_VERBOSE_DEBUG_ON == 1
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
									lam::math::operator+ [loc:52] --> Invalid argument(s)";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
#endif
		throw std::invalid_argument("lam::math::operator+ [loc:52] --> Invalid argument(s)");
	}
	Real_t* __restrict tRe = 
	reinterpret_cast<Real_t*>(_mm_malloc(v1.get_nsize()*sizeof(Real_t),align32B));
	if (tRe == NULL) {
#if LAM_VERBOSE_DEBUG_ON == 1
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
													lam::math::operator+ [loc:62] --> Memory allocation failure!!";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
#endif		
		std::exit(-1);
	}	
	
#if USE_AUTO_VEC == 1
#pragma ivdep
#pragma simd
#pragma unroll(4)
#endif
	for (uint64_t i = 0; i != v1.get_nsize(); ++i) {
		tRe[i] = v1.get_Re()[i] + v2[i];
	}
	VComplex1D<Real_t> vres{ v1.get_nsize(), tRe, v1.get_Im() };
	_mm_free(tRe);

	return (vres);
}

template<typename Real_t>
lam::math::VComplex1D<Real_t>
lam::math::operator+(_In_ const Real_t* __restrict v1,
					 _In_ const VComplex1D<Real_t> &v2) {

	if (v1 == NULL || !v2.get_isbuilt()) {
#if LAM_VERBOSE_DEBUG_ON == 1
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
											lam::math::operator+ [loc:90] --> Invalid argument(s)";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
#endif
		throw std::invalid_argument("lam::math::operator+ [loc:90] --> Invalid argument(s)!");
	}
	Real_t* __restrict tRe = 
	reinterpret_cast<Real_t*>(_mm_malloc(v2.get_nsize()*sizeof(Real_t),align32B));
	if (tRe == NULL) {
#if LAM_VERBOSE_DEBUG_ON == 1
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
												lam::math::operator+ [loc:100] --> Memory allocation failure!!";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
#endif
		std::exit(-1);
	}
#if USE_AUTO_VEC == 1
#pragma ivdep
#pragma simd
#pragma unroll(4)
#endif
	for (uint64_t i = 0; i != v2.get_nsize(); ++i) {
		tRe[i] = v1[i] + v2.get_Re()[i];
	}
	VComplex1D<Real_t> vres{ v2.get_nsize(), tRe, v2.get_Im() };
	_mm_free(tRe);
	return (vres);
}

template<typename Real_t>
lam::math::VComplex1D<Real_t>
lam::math::operator-(_In_ const VComplex1D<Real_t> &v1,
					 _In_ const VComplex1D<Real_t> &v2) {

	if (!v1.get_isbuilt() || !v2.get_isbuilt() ||
		 v1.get_nsize() != v2.get_nsize()) {
#if LAM_VERBOSE_DEBUG_ON
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
												lam::math::operator- [loc:126] --> Invalid argument(s)";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
#endif
		throw std::invalid_argument("lam::math::operator- [loc:126] --> Invalid argument(s)!");
	}
	Real_t* __restrict tRe =
	 reinterpret_cast<Real_t*>(_mm_malloc(v1.get_nsize()*sizeof(Real_t),align32B));
	Real_t* __restrict tIm = 
	 reinterpret_cast<Real_t*>(_mm_malloc(v1.get_nsize()*sizeof(Real_t),align32B));
	if (tRe == NULL || tIm == NULL) {
#if LAM_VERBOSE_DEBUG_ON == 1
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
													lam::math::operator- [loc:139] --> Memory allocation failure!!";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
#endif
		std::exit(-1);
	}
#if USE_AUTO_VEC == 1
#pragma ivdep
#pragma simd
#pragma unroll(4)
#endif
	for (uint64_t i = 0; i != v1.get_nsize(); ++i) {
		tRe[i] = v1.get_Re()[i] - v2.get_Re()[i];
		tIm[i] = v1.get_Im()[i] - v2.get_Im()[i];
	}
	VComplex1D<Real_t> vres{ v1.get_nsize(),tRe,tIm };
	_mm_free(tRe);
	_mm_free(tIm);
	return (vres);
}

template<typename Real_t>
lam::math::VComplex1D<Real_t>
lam::math::operator-(_In_ const VComplex1D<Real_t> &v1,
			         _In_ const Real_t* __restrict v2) {

	if (!v1.get_isbuilt() || v2 == NULL) {
#if LAM_VERBOSE_DEBUG_ON == 1
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
												lam::math::operator- [loc:167] --> Invalid argument(s)";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
#endif
		throw std::invalid_argument("lam::math::operator- [loc:167] --> Invalid argument(s)!");
	}
	Real_t* __restrict tRe = 
	reinterpret_cast<Real_t*>(_mm_malloc(v1.get_nsize()*sizeof(Real_t),align32B));
	if (tRe == NULL) {
#if LAM_VERBOSE_DEBUG_ON == 1
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
										lam::math::operator+ [loc:175] --> Memory allocation failure!!";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
#endif
		std::exit(-1);
	}
#if USE_AUTO_VEC == 1
#pragma ivdep
#pragma simd
#pragma unroll(4)
#endif
	for (uint64_t i = 0; i != v1.get_nsize(); ++i) {
		tRe[i] = v1.get_Re()[i] - v2[i];
	}
	VComplex1D<Real_t> vres{ v1.get_nsize(), tRe, v1.get_Im() };
	_mm_free(tRe);
	return (vres);
}

template<typename Real_t>
lam::math::VComplex1D<Real_t>
lam::math::operator-(_In_ const Real_t* __restrict v1,
					 _In_ const VComplex1D<Real_t> &v2) {
	
	if (v1 == NULL || !v2.get_isbuilt()) {
#if LAM_VERBOSE_DEBUG_ON == 1
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
												lam::math::operator- [loc:203] --> Invalid argument(s)";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
#endif
		throw std::invalid_argument("lam::math::operator- [loc:203] --> Invalid argument(s)");
	}
	Real_t* __restrict tRe = 
	reinterpret_cast<Real_t*>(_mm_malloc(v2.get_nsize()*sizeof(Real_t),align32B));
	if (tRe == NULL) {
#if LAM_VERBOSE_DEBUG_ON == 1
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
												lam::math::operator- [loc:213] --> Memory allocation failure!!";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
#endif
		std::exit(-1);
	}
#if USE_AUTO_VEC == 1
#pragma prefetch
#pragma ivdep
#pragma simd
#pragma unroll(4)
#endif
	for (uint64_t i = 0; i != v2.get_nsize(); ++i) {
		tRe[i] = v1[i] = v2.get_Re()[i];
	}
	VComplex1D<Real_t> vres{ v2.get_nsize(), tRe, v2.get_Im() };
	_mm_free(tRe);
	return (vres);
}

template<typename Real_t>
lam::math::VComplex1D<Real_t>
lam::math::operator*(_In_ const VComplex1D<Real_t> &v1,
					 _In_ const VComplex1D<Real_t> &v2) {

	if (!v1.get_isbuilt() || !v2.get_isbuilt() ||
		 v1.get_nsize() != v2.get_nsize()) {
#if LAM_VERBOSE_DEBUG_ON == 1
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
													lam::math::operator* [loc:240] --> Invalid argument(s)";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
#endif
		throw std::invalid_argument("lam::math::operator* [loc:240] --> Invalid argument(s)!");
	}
	Real_t* __restrict tRe = 
	reinterpret_cast<Real_t*>(_mm_malloc(v1.get_nsize()*sizeof(Real_t),align32B));
	Real_t* __restrict tIm = 
	reinterpret_cast<Real_t*>(_mm_malloc(v1.get_nsize()*sizeof(Real_t),align32B));
	if (tRe == NULL || tIm == NULL) {
#if LAM_VERBOSE_DEBUG_ON == 1
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
												lam::math::operator* [loc:253] --> Memory allocation failure!!";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
#endif
		std::exit(-1);
	}
#if USE_AUTO_VEC == 1
#pragma prefetch
#pragma ivdep
#pragma simd
#pragma unroll(4)
#endif
	for (uint64_t i = 0; i != v1.get_nsize(); ++i) {
		tRe[i] = (v1.get_Re()[i] * v2.get_Re()[i]) - (v1.get_Im()[i] * v2.get_Im()[i]);
		tIm[i] = (v1.get_Im()[i] * v2.get_Re()[i]) + (v1.get_Re()[i] * v2.get_Im()[i]);
	}
	VComplex1D<Real_t> vres{ v1.get_nsize(),tRe,tIm };
	_mm_free(tRe);
	_mm_free(tIm);
	return (vres);
}

template<typename Real_t>
lam::math::VComplex1D<Real_t>
lam::math::operator*(_In_ const VComplex1D<Real_t> &v1,
					 _In_ const Real_t* __restrict v2) {

	if (!v1.get_isbuilt() || v2 == NULL) {
#if LAM_VERBOSE_DEBUG_ON == 1
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
																  lam::math::operator* [loc:282] --> Invalid argument(s)";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
#endif
		throw std::invalid_argument("lam::math::operator* [loc:282] --> Invalid argument(s)!");
	}
	Real_t* __restrict tRe = 
	reinterpret_cast<Real_t*>(_mm_malloc(v1.get_nsize()*sizeof(Real_t),align32B));
	Real_t* __restrict tIm = 
	reinterpret_cast<Real_t*>(_mm_malloc(v1.get_nsize()*sizeof(Real_t),align32B));
	if (tRe == NULL || tIm == NULL) {
#if LAM_VERBOSE_DEBUG_ON == 1
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
												lam::math::operator* [loc:295] --> Memory allocation failure!!";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
#endif
		std::exit(-1);
	}
#if USE_AUTO_VEC == 1
#pragma prefetch
#pragma ivdep
#pragma simd
#pragma unroll(4)
#endif
	for (uint64_t i = 0; i != v1.get_nsize(); ++i) {
		tRe[i] = v1.get_Re()[i] * v2[i];
		tIm[i] = v1.get_Im()[i] * v2[i];
	}
	VComplex1D<Real_t> vres{ v1.get_nsize(),tRe,tIm };
	_mm_free(tRe);
	_mm_free(tIm);
	return (vres);
}

template<typename Real_t>
lam::math::VComplex1D<Real_t>
lam::math::operator*(_In_ const Real_t* __restrict v1,
					 _In_ const VComplex1D<Real_t> &v2) {

	if (v1 == NULL || !v2.get_isbuilt()) {
#if LAM_VERBOSE_DEBUG_ON == 1
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
												lam::math::operator* [loc:324] --> Invalid argument(s)";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
#endif
		throw std::invalid_argument("lam::math::operator* [loc:324] --> Invalid argument(s)");
	}
	Real_t* __restrict tRe = 
	reinterpret_cast<Real_t*>(_mm_malloc(v2.get_nsize()*sizeof(Real_t),align32B));
	Real_t* __restrict tIm = 
	reinterpret_cast<Real_t*>(_mm_malloc(v2.get_nsize()*sizeof(Real_t),align32B));
	if (tRe == NULL || tIm = NULL) {
#if LAM_VERBOSE_DEBUG_ON == 1
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
							lam::math::operator* [loc:335] --> Memory allocation failure!!";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
#endif
		std::exit(-1);
	}
#if USE_AUTO_VEC == 1
#pragma prefetch
#pragma ivdep
#pragma simd
#pragma unroll(4)
#endif
	for (uint64_t i = 0; i != v2.get_nsize(); ++i) {
		tRe[i] = v1[i] * v2.get_Re()[i];
		tIm[i] = v1[i] * v2.get_Im()[i];
	}
	VComplex1D<Real_t> vres{ v2.get_nsize(),tRe,tIm };
	_mm_free(tRe);
	_mm_free(tIm);
	return (vres);
}

template<typename Real_t>
lam::math::VComplex1D<Real_t>
lam::math::operator/(_In_ const VComplex1D<Real_t> &v1,
					 _In_ const VComplex1D<Real_t> &v2) {
	
	if (!v1.get_isbuilt() || 
	    !v2.get_isbuilt() ||
		v1.get_nsize() != v2.get_nsize()) {
#if LAM_VERBOSE_DEBUG_ON == 1
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
											lam::math::operator/ [loc:364] --> Invalid argument(s)";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
#endif
		throw std::invalid_argument("lam::math::operator/ [loc:364] --> Invalid argument(s)")
	}
	// Check for 0.0, Nan
	// if present then throw an exception.
	bool invalid = false;
	for (uint64_t i = 0; i != v1.get_nsize(); ++i) {
		if (v1.get_Re()[i] == 0.0 ||
			v1.get_Im()[i] == 0.0 ||
			v2.get_Re()[i] == 0.0 ||
			v2.get_Im()[i] == 0.0 ||
			std::isnan(v1.get_Re()[i]) ||
			std::isnan(v1.get_Im()[i]) ||
			std::isnan(v2.get_Re()[i]) ||
			std::isnan(v2.get_Im()[i])) {
			invalid = true;
		}
	}
	if (invalid) {
#if LAM_VERBOSE_DEBUG_ON == 1
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
												lam::math::operator/ [loc:377] --> Detected: 0.0 or NAN!!";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
#endif
		throw std::domain_error("lam::math::operator/ [loc:377] --> Detected: 0.0 or NAN!!");
	}
	Real_t tmp = static_cast<Real_t>(0.0);
	Real_t tr =  static_cast<Real_t>(0.0);
	Real_t ti = static_cast<Real_t>(0.0);
	Real_t* __restrict tRe = 
	reinterpret_cast<Real_t*>(_mm_malloc(v1.get_nsize()*sizeof(Real_t),align32B));
	Real_t* __restrict tIm = 
	reinterpret_cast<Real_t*>(_mm_malloc(v1.get_nsize()*sizeof(Real_t),align32B));
	if (tRe == NULL || tIm == NULL) {
#if LAM_VERBOSE_DEBUG_ON == 1
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
													lam::math::operator/ [loc:404] --> Memory allocation failure!!";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
#endif
		std::exit(-1);
	}
#if USE_AUTO_VEC == 1
#pragma prefetch
#pragma ivdep
#pragma simd
#pragma unroll(4)
#endif
	for (uint64_t i = 0; i != v1.get_nsize(); ++i) {
		tr = (v1.get_Re()[i] * v2.get_Re()[i]) + (v1.get_Im()[i] * v2.get_Im()[i]);
		ti = (v1.get_Im()[i] * v2.get_Re()[i]) - (v1.get_Re()[i] * v2.get_Im()[i]);
		tmp = (v2.get_Re()[i] * v2.get_Re()[i]) + (v2.get_Im()*v2.get_Im()[i]);
		tRe[i] = tr/tmp;
		tIm[i] = ti/tmp;
	}
	VComplex1D<Real_t>{v1.get_nsize(),tRe,tIm};
	_mm_free(tRe);
	_mm_free(tIm);
	return (vres);
}

template<typename Real_t>
lam::math::VComplex1D<Real_t>
lam::math::operator/(_In_ const VComplex1D<Real_t> &v1,
				     _In_ const Real_t* __restrict v2) {

	if (!v1.get_isbuilt() || v2 == NULL) {
#if LAM_VERBOSE_DEBUG_ON == 1
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
													lam::math::operator/ [loc:438] --> Invalid argument(s)";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
#endif
		throw std::invalid_argument("lam::math::operator/ [loc:438] --> Invalid argument(s)!!");
	}
	// Check for 0.0, Nan
	// if present then throw an exception.
	bool invalid = false;
	for (uint64_t i = 0; i != v1.get_nsize(); ++i) {
		if (v1.get_Re()[i] == 0.0      ||
			v1.get_Im()[i] == 0.0      ||
			v2[i] == 0.0               ||
			std::isnan(v1.get_Re()[i]) ||
			std::isnan(v1.get_Im()[i]) ||
			std::isnan(v2[i])) {
			invalid = true;
		}
	}
	if (invalid) {
#if LAM_VERBOSE_DEBUG_ON == 1
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
													lam::math::operator/ [loc:457] --> Detected: 0.0 or NAN!!";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
#endif
		throw std::domain_error("lam::math::operator/ [loc:457] --> Detected: 0.0 or NAN!!");
	}
	Real_t __restrict tRe = 
	reinterpret_cast<Real_t*>(_mm_malloc(v1.get_nsize()*sizeof(Real_t),align32B));
	Real_t __restrict tIm = 
	reinterpret_cast<Real_t*>(_mm_malloc(v1.get_nsize()*sizeof(Real_t),align32B));
	if (tRe == NULL || tIm == NULL) {
#if LAM_VERBOSE_DEBUG_ON == 1
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
															lam::math::operator/ [loc:469] --> Memory allocation failure!!";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
#endif
		std::exit(-1);
	}
#if USE_AUTO_VEC == 1
#pragma prefetch
#pragma ivdep
#pragma simd
#pragma unroll(4)
#endif
	for (uint64_t i = 0; i != v1.get_nsize(); ++i) {
		tRe[i] = v1.get_Re()[i] / v2[i];
		tIm[i] = v1.get_Im()[i] / v2[i];
	}
	VComplex1D<Real_t> vres{ v1.get_nsize(),tRe,tIm };
	_mm_free(tRe);
	_mm_free(tIm);
	return (vres);
}

template<typename Real_t>
lam::math::VComplex1D<Real_t>
lam::math::operator/(_In_ const Real_t* __restrict v1,
					 _In_ const VComplex1D<Real_t> &v2) {
	
	if (v1 == NULL || !v2.get_isbuilt()) {
#if LAM_VERBOSE_DEBUG_ON == 1
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
													lam::math::operator/ [loc:498] --> Invalid argument(s)";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
#endif
		throw std::invalid_argument("lam::math::operator/ [loc:498] --> Invalid argument(s)");
	}
	// Check for 0.0, Nan
	// if present then throw an exception.
	bool invalid = false;
	for (uint64_t i = 0; i != v2.get_nsize(); ++i) {
		if (v1[i] == 0.0               ||
			v2.get_Re()[i] == 0.0      ||
			v2.get_Im()[i] == 0.0      ||
			std::isnan(v1[i])          ||
			std::isnan(v2.get_Re()[i]) ||
			std::isnan(v2.get_Im()[i])) {
			invalid = true;
		}
	}
	if (invalid) {
#if LAM_VERBOSE_DEBUG_ON == 1
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
														lam::math::operator/ [loc:519] --> Detected: 0.0 or NAN!!";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
#endif
		throw std::domain_error("lam::math::operator/ [loc:519] --> Detected: 0.0 or NAN!!");
	}
	Real_t* __restrict tRe = 
	reinterpret_cast<Real_t*>(_mm_malloc(v2.get_nsize()*sizeof(Real_t),align32B));
	Real_t* __restrict tIm = 
	reinterpret_cast<Real_t*>(_mm_malloc(v2.get_nsize()*sizeof(Real_t),align32B));
	if (tRe == NULL || tIm == NULL) {
#if LAM_VERBOSE_DEBUG_ON == 1
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
															lam::math::operator/ [loc:531] --> Memory allocation failure!!";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
#endif
		std::exit(-1);
	}
#if USE_AUTO_VEC == 1
#pragma prefetch
#pragma ivdep
#pragma simd
#pragma unroll(4)
#endif
	for (uint64_t i = 0; i != v2.get_nsize(); ++i) {
		tRe[i] = v1[i] / v2.get_Re()[i];
		tIm[i] = v1[i] / v2.get_Im()[i];
	}
	VComplex1D<Real_t> vres{ v2.get_nsize(),tRe,tIm };
	_mm_free(tRe);
	_mm_free(tIm);
	return (vres);
}

template<typename Real_t>
std::vector<bool>
lam::math::operator==(_In_ const VComplex1D<Real_t> &v1,
					  _In_ const VComplex1D<Real_t> &v2) {
	
	if (!v1.get_isbuilt() || !v2.get_isbuilt() ||
		 v1.get_nsize() != v2.get_nsize()) {
#if LAM_VERBOSE_DEBUG_ON == 1
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
																 lam::math::operator== [loc:560] --> Invalid argument(s)";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
#endif
		throw std::invalid_argument("lam::math::operator== [loc:560] --> Invalid argument(s)");
	}
	std::vector<bool> vbres;
	vbres.resize(static_cast<st>(v1.get_nsize()),false);
	for (uint64_t i = 0; i != v1.get_nsize(); ++i) {
		if (v1.get_Re()[i] == v2.get_Re()[i] &&
			v1.get_Im()[i] == v2.get_Im()[i]) {
			vbres[i] = true;
		}
		else {
			vbres[i] = false;
		}
	}
	return (vbres);
}

template<typename Real_t>
std::vector<bool>
lam::math::operator!=(_In_ const VComplex1D<Real_t> &v1,
					  _In_ const VComplex1D<Real_t> &v2) {
	
	if (!v1.get_isbuilt() || !v2.get_isbuilt() ||
		v1.get_nsize() != v2.get_nsize()) {
#if LAM_VERBOSE_DEBUG_ON == 1
		std::cerr << "[" << __DATE__ << ":" << __TIME__ << "]" << "***FATAL-ERROR*** -> \
													lam::math::operator!= [loc:590] --> Invalid argument(s)";
		std::cerr << "at " << __FILE__ << ":" << __LINE__ << "(" << std::hex << "0x" << __FUNCTIONW__ << ")" << "\n";
#endif
		throw std::invalid_argument("lam::math::operator!= [loc:590] --> Invalid argument(s)");
	}
	std::vector<bool> vbres;
	vbres.resize(static_cast<st>(v1.get_nsize()), false);
	for (uint64_t i = 0; i != v1.get_nsize(); ++i) {
		if (v1.get_Re()[i] != v2.get_Re()[i] &&
			v1.get_Im()[i] != v2.get_Im()[i]) {
			vbres[i] = true;
		}
		else {
			vbres[i] = false;
		}
	}
	return (vbres);
}






	     



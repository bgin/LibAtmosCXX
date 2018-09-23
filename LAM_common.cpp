
#include <math.h>
#include "LAM_common.h"
#include "LAM_simd_defs.h"
#include "LAM_config.h"
//
//	Implementation
//


bool
lam::common
::approximately_equalf64(_In_ const double a,
						_In_ const double b,
						_In_ const double eps) {
	return fabs(a - b) <= ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * eps);
}

bool
lam::common
::essentialy_equalf64(_In_ const double a,
					  _In_ const double b,
					  _In_ const double eps) {
	return fabs(a - b) <= ((fabs(a) > fabs(b) ? fabs(b) : fabs(a)) * eps);
}

bool
lam::common
::definitely_greaterf64(_In_ const double a,
					    _In_ const double b,
					    _In_ const double eps) {
	return fabs(a - b) > ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * eps);
}

bool
lam::common
::definitely_lessf64(_In_ const double a,
				     _In_ const double b,
				     _In_ const double eps) {
	return fabs(b - a) > ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * eps);
}

bool
lam::common
::Is_ptr_aligned32(_In_ const double * __restrict x) {
	if ((reinterpret_cast<uintptr_t>(x)& 0x1F) == 0ULL) {
		return (true);
	}
	else { return (false); }
}

bool
lam::common
::Is_ptr_aligned32(_In_ const int64_t * __restrict x) {
	if ((reinterpret_cast<uintptr_t>(x) & 0x1F) == 0ULL) {
		return (true);
	}
	else { return (false); }
}

bool
lam::common::
Is_ptr_aligned64(_In_ const double * __restrict x) {
	if ((reinterpret_cast<uintptr_t>(x)& 0x3F) == 0ULL) {
		return (true);
	}
	else { return (false); }
}

bool
lam::common
::Is_ptr_aligned64(_In_ const int64_t * __restrict x) {
	if ((reinterpret_cast<uintptr_t>(x)& 0x3F) == 0ULL) {
		return (true);
	}
	else { return (false); }
}

void lam::common::
init_array(_Inout_ double* __restrict ar,
           _In_ const int64_t arlen,
           _In_ const double val) {
	__assume_aligned(ar,64);
	for (int64_t i = 0LL; i != arlen; ++i) {
		 ar[i] = val;
	}
}

void
lam::common::
init_array( _Inout_ int64_t * __restrict in,
			_In_ const int64_t len,
			_In_ const int64_t val) {
	__assume_aligned(in,64);
	for (int64_t i = 0LL; i != len; ++i) {
		 in[i] = val;
	}
}

void
lam::common::
init_array(_Inout_ int32_t * __restrict in,
		   _In_ const int64_t len,
		  _In_ const int32_t val) {
	__assume_aligned(in,64);
	for (int64_t i = 0LL; i != len; ++i) {
		in[i] = val;
	}
}

void lam::common::
init_array(_Inout_ unsigned char* __restrict ar,
		   _In_ const int64_t arlen,
		   _In_ const unsigned char val) {
	__assume_aligned(ar,64);
	for (int64_t i = 0LL; i != arlen; ++i) {
		 ar[i] = val;
	}
}

void lam::common::
init_varray(_Inout_ double* __restrict ar,
			_In_ const int64_t arlen,
			_In_ const double val) {
	if ((reinterpret_cast<uintptr_t>(ar)& 0x1F) != 0ULL) {
		for (int64_t i = 0LL; i != arlen; i += 8LL) {
			_mm256_storeu_pd(&ar[i + 0LL], _mm256_set1_pd(val));
			_mm256_storeu_pd(&ar[i + 4LL], _mm256_set1_pd(val));
		}
	}
	else {
	     for (int64_t i = 0LL; i != arlen; i += 8LL) {
		     _mm256_store_pd(&ar[i + 0LL], _mm256_set1_pd(val));
		     _mm256_store_pd(&ar[i + 4LL], _mm256_set1_pd(val));
	  }
   }
}

void
lam::common::
avx256_init_unroll2x(_Inout_ double * __restrict v,
				     _In_ const int64_t vlen,
					 _In_ const double val) {
	
	const __m256d vec = _mm256_set1_pd(val);
	int64_t i;
	if ((reinterpret_cast<uintptr_t>(v)& 0x1F) != 0ULL) {
		for (i = 0ULL; i != ROUND_TO_FOUR(vlen, 4LL); i += 8LL) {
			_mm256_storeu_pd(&v[i + 0LL], vec);
			_mm256_storeu_pd(&v[i + 4LL], vec);
		}
	}
	else {
     	for (i = 0ULL; i != ROUND_TO_EIGHT(vlen, 4LL); i += 8LL) {
		    _mm256_store_pd(&v[i+0LL], vec);
		    _mm256_store_pd(&v[i+4LL], vec);
	   }
	}
	for (; i != vlen; ++i) {
		v[i] = val;
	}
}

void
lam::common::
avx256_init_unroll4x(_Inout_ double * __restrict v,
				     _In_ const int64_t vlen,
					 _In_ const double val) {
	
	const __m256d vec = _mm256_set1_pd(val);
	int64_t i;
	if ((reinterpret_cast<uintptr_t>(v)& 0x1F) != 0ULL) {
		for (i = 0LL; i != ROUND_TO_FOUR(vlen, 4LL); i += 16LL) {
			_mm256_storeu_pd(&v[i + 0LL], vec);
			_mm256_storeu_pd(&v[i + 4LL], vec);
			_mm256_storeu_pd(&v[i + 8LL], vec);
			_mm256_storeu_pd(&v[i + 12LL], vec);
		}
	}
	else {
	      for (i = 0LL; i != ROUND_TO_FOUR(vlen, 4LL); i += 16LL) {
		       _mm256_store_pd(&v[i+0LL],  vec);
		       _mm256_store_pd(&v[i+4LL],  vec);
		       _mm256_store_pd(&v[i+8LL],  vec);
		       _mm256_store_pd(&v[i+12LL], vec);
	      }
	   }
	for (; i != vlen; ++i) {
		v[i] = val;
	}
}


void
lam::common::
avx256_init_unroll8x(_Inout_ double * __restrict v,
					_In_ const int64_t vlen,
					_In_ const double val) {
	
	const __m256d vec = _mm256_set1_pd(val);
	int64_t i; 
	if ((reinterpret_cast<uintptr_t>(v)& 0x1F) != 0) {
		for (i = 0LL; i != ROUND_TO_FOUR(vlen, 4LL); i += 32LL) {
			    _mm256_storeu_pd(&v[i + 0LL], vec);
			    _mm256_storeu_pd(&v[i + 4LL], vec);
			    _mm256_storeu_pd(&v[i + 8LL], vec);
			    _mm256_storeu_pd(&v[i + 12LL], vec);
			    _mm256_storeu_pd(&v[i + 16LL], vec);
			    _mm256_storeu_pd(&v[i + 20LL], vec);
			    _mm256_storeu_pd(&v[i + 24LL], vec);
			    _mm256_storeu_pd(&v[i + 28LL], vec);
		}
	}
	else {
	      for ( i = 0LL; i != ROUND_TO_FOUR(vlen, 4LL); i += 32LL) {
		         _mm256_store_pd(&v[i+0LL], vec);
		         _mm256_store_pd(&v[i+4LL], vec);
		         _mm256_store_pd(&v[i+8LL], vec);
		         _mm256_store_pd(&v[i+12LL],vec);
		         _mm256_store_pd(&v[i+16LL],vec);
		         _mm256_store_pd(&v[i+20LL],vec);
		         _mm256_store_pd(&v[i+24LL],vec);
		         _mm256_store_pd(&v[i+28LL],vec);
	     }
	}
	for (; i != vlen; ++i)
		v[i] = val;
}

void
lam::common::
avx512_init_unroll8x(_Inout_ double * __restrict v,
					 _In_ const int64_t vlen,
					 _In_ const double val) {
	
	const __m512d vec = _mm512_set1_pd(val);
	int64_t i;
	if ((reinterpret_cast<uintptr_t>(v)& 0x3F) != 0ULL) {
		for (i = 0LL; i != ROUND_TO_EIGHT(vlen, 8LL); i += 64LL) {
			_mm512_storeu_pd(&v[i + 0LL], vec);
			_mm512_storeu_pd(&v[i + 8LL], vec);
			_mm512_storeu_pd(&v[i + 16LL], vec);
			_mm512_storeu_pd(&v[i + 24LL], vec);
			_mm512_storeu_pd(&v[i + 32LL], vec);
			_mm512_storeu_pd(&v[i + 40LL], vec);
			_mm512_storeu_pd(&v[i + 48LL], vec);
			_mm512_storeu_pd(&v[i + 56LL], vec);
		}
	}
	else {
	   for (i = 0LL; i != ROUND_TO_EIGHT(vlen, 8LL); i += 64LL) {
		   _mm512_store_pd(&v[i+0LL],vec);
		   _mm512_store_pd(&v[i+8LL],vec);
		   _mm512_store_pd(&v[i+16LL],vec);
		   _mm512_store_pd(&v[i+24LL],vec);
		   _mm512_store_pd(&v[i+32LL],vec);
		   _mm512_store_pd(&v[i+40LL],vec);
		   _mm512_store_pd(&v[i+48LL],vec);
		   _mm512_store_pd(&v[i+56LL],vec);
	   }
	}
	for (; i != vlen; ++i)
		v[i] = val;
}

bool lam::common::
vzero_check(_In_ double* __restrict re,
			_In_ double* __restrict im,
			_In_ const int64_t len) {
	//using namespace lam::common;
	__m256d zmask1(_mm256_setzero_pd());
	__m256d zmask2(_mm256_setzero_pd());
	//__m256i vres(_mm256_setr_epi64x(0LL,0LL,0LL,0LL));
	const __m256d vzero = _mm256_set1_pd(0.0);
	
	bool bres = false;
	for (int64_t i = 1LL; i != len; i += 4LL) {
		zmask1 = _mm256_cmp_pd(vzero, _mm256_loadu_pd(&re[i]),_CMP_EQ_OQ);
		zmask2 = _mm256_cmp_pd(vzero, _mm256_loadu_pd(&im[i]),_CMP_EQ_OQ);
		if (_mm256_testc_pd(zmask1, _mm256_setzero_pd()) ||
			_mm256_testc_pd(zmask2, _mm256_setzero_pd())) {
			//vres = _mm256_setr_epi64x(1LL,1LL,1LL,1LL);
			goto found;
		}
	}
	found:
	bres = true;
	return (bres);
}

bool lam::common::
vzero_check1(_In_ const double* __restrict re,
			_In_ const int64_t len) {
	__m256d zmask1(_mm256_setzero_pd());
	//__m256i vres(_mm256_setr_epi64x(0LL,0LL,0LL,0LL));
	const __m256d vzero = _mm256_setzero_pd();
	bool bres = false;
	for (int64_t i = 0LL; i != len; i += 4LL) {
		zmask1 = _mm256_cmp_pd(vzero, _mm256_loadu_pd(&re[i]),_CMP_EQ_OQ);
		if (_mm256_testc_pd(zmask1, _mm256_setzero_pd())) {
			//vres = _mm256_setr_epi64x(1LL,1LL,1LL,1LL);
			goto found;
		}
	}
	
	found:
	bres = true;
	return (bres);
}

bool lam::common::
vzero_check3D(_In_ const double* __restrict data,
			  _In_ const int64_t nx,
			  _In_ const int64_t ny,
			  _In_ const int64_t nz) {
	__m256d zmask1(_mm256_setzero_pd());
	//__m256i vres(_mm256_setr_epi64x(0LL,0LL,0LL,0LL));
	const __m256d vzero = _mm256_setzero_pd();
	bool bres = false;
	for (int64_t i = 0; i != nx; ++i) {
		for (int64_t j = 0; j != ny; ++j) {
			for (int64_t k = 0; k != nz; k += 4LL) {
				zmask1 = _mm256_cmp_pd(vzero, _mm256_loadu_pd(&data[i+nx*j+ny*k]),_CMP_EQ_OQ);
				if (_mm256_testc_pd(zmask1, _mm256_setzero_pd())) {
					//vres = _mm256_setr_epi64x(1LL,1LL,1LL,1LL);
					goto found;
				}
			}
		}
	}
	found:
	bres = true;
	return (bres);
}

bool lam::common::
vzero_check3D(_In_ const double* __restrict data,
			  _In_ const int64_t its,
		      _In_ const int64_t ite,
              _In_ const int64_t kts,
              _In_ const int64_t kte,
              _In_ const int64_t jts,
              _In_ const int64_t jte) {
	__m256d zmask1(_mm256_setzero_pd());
	//__m256i vres(_mm256_setr_epi64x(0LL,0LL,0LL,0LL));
	const __m256d vzero = _mm256_setzero_pd();
	bool bres = false;
	int64_t j,k,i;
	for (j = jts; j != jte; ++j) {
		for (k = kts; k != kte; ++k) {
			for (i = its; i != ROUND_TO_FOUR(ite, 4ULL); i += 4ULL) {
				zmask1 = _mm256_cmp_pd(vzero, _mm256_loadu_pd(&data[j+jte*k+kte*i]),_CMP_EQ_OQ);
				if (_mm256_testc_pd(zmask1, _mm256_setzero_pd())) {
					goto found;
				}
			}
		}
	}
	// Scalar remainder
	for (; j != jte; ++j) {
		for (; k != kte; ++k) {
			for (; i != ite; ++i) {
				if (data[j + jte*k + kte*i] == 0.0) {
					goto found;
				}
			}
		}
	}
	found:
	bres = true;
	return (bres);
}



void
lam::common::
avx256_memcpy2x_nt(_Inout_  double * __restrict dst,
				   _In_  const double * __restrict src,
				   _In_ const int64_t len) {
	if ((reinterpret_cast<uintptr_t>(dst)& 0x1F) != 0ULL ||
		(reinterpret_cast<uintptr_t>(src)& 0x1F) == 0ULL) {
		 return;
	}
	int64_t i;
	if ((reinterpret_cast<uintptr_t>(dst)& 0x1F) != 0ULL &&
		(reinterpret_cast<uintptr_t>(src)& 0x1F) != 0ULL) {
		for (i = 0ULL; i != ROUND_TO_FOUR(len, 4ULL); i += 8LL) {
			_mm256_stream_pd(&dst[i + 0LL], _mm256_loadu_pd(&src[i + 0LL]));
			_mm256_stream_pd(&dst[i + 0LL], _mm256_loadu_pd(&src[i + 4LL]));
		}
		_mm_sfence();
	}
	if ((reinterpret_cast<uintptr_t>(dst)& 0x1F) == 0ULL &&
	    (reinterpret_cast<uintptr_t>(src)& 0x1F) == 0ULL) {
	
	   for (i = 0ULL; i != ROUND_TO_FOUR(len, 4ULL); i += 8LL) {
		    _mm256_stream_pd(&dst[i + 0LL], _mm256_load_pd(&src[i + 0LL]));
		    _mm256_stream_pd(&dst[i + 0LL], _mm256_load_pd(&src[i + 4LL]));
	   }
	  _mm_sfence();
	}
	for (; i != len; ++i)
		dst[i] = src[i];
}

void
lam::common::
avx256_memcpy4x_nt(_Inout_ double * __restrict dst,
				   _In_ const double * __restrict src,
				   _In_ const int64_t len) {
	if ((reinterpret_cast<uintptr_t>(dst)& 0x1F) != 0ULL ||
		(reinterpret_cast<uintptr_t>(src)& 0x1F) == 0ULL) {
		return;
	}
	int64_t i;
	if ((reinterpret_cast<uintptr_t>(dst) & 0x1F) != 0ULL &&
		(reinterpret_cast<uintptr_t>(src) & 0x1F) != 0ULL) {
		for (i = 0LL; i != ROUND_TO_FOUR(len, 4LL); i += 16LL) {
			_mm256_stream_pd(&dst[i + 0LL],  _mm256_loadu_pd(&src[i + 0LL]));
			_mm256_stream_pd(&dst[i + 4LL],  _mm256_loadu_pd(&src[i + 4LL]));
			_mm256_stream_pd(&dst[i + 8LL],  _mm256_loadu_pd(&src[i + 8LL]));
			_mm256_stream_pd(&dst[i + 12LL], _mm256_loadu_pd(&src[i + 12LL]));
		}
		   _mm_sfence();
	} 
	else {
	    for (i = 0LL; i != ROUND_TO_FOUR(len, 4LL); i += 16LL) {
		    _mm256_stream_pd(&dst[i + 0LL],  _mm256_load_pd(&src[i + 0LL]));
		    _mm256_stream_pd(&dst[i + 4LL],  _mm256_load_pd(&src[i + 4LL]));
		    _mm256_stream_pd(&dst[i + 8LL],  _mm256_load_pd(&src[i + 8LL]));
		    _mm256_stream_pd(&dst[i + 12LL], _mm256_load_pd(&src[i + 12LL]));
	   }
	      _mm_sfence();
	}
	for (; i != len; ++i)
		dst[i] = src[i];
}

void
lam::common::
avx256_memcpy8x_nt(_Inout_ double * __restrict dst,
				   _In_ const double * __restrict src,
				   _In_ const int64_t len) {
	if ((reinterpret_cast<uintptr_t>(dst) & 0x1F) != 0ULL ||
		(reinterpret_cast<uintptr_t>(src) & 0x1F) == 0ULL) {
		return;
	}
	int64_t i;
	if ((reinterpret_cast<uintptr_t>(dst)& 0x1F) != 0ULL &&
		(reinterpret_cast<uintptr_t>(src)& 0x1F) != 0ULL) {
		for (i = 0LL; i != ROUND_TO_FOUR(len, 4LL); i += 32LL) {
			_mm256_stream_pd(&dst[i + 0LL],  _mm256_loadu_pd(&src[i + 0LL]));
			_mm256_stream_pd(&dst[i + 4LL],  _mm256_loadu_pd(&src[i + 4LL]));
			_mm256_stream_pd(&dst[i + 8LL],  _mm256_loadu_pd(&src[i + 8LL]));
			_mm256_stream_pd(&dst[i + 12LL], _mm256_loadu_pd(&src[i + 12LL]));
			_mm256_stream_pd(&dst[i + 16LL], _mm256_loadu_pd(&src[i + 16LL]));
			_mm256_stream_pd(&dst[i + 20LL], _mm256_loadu_pd(&src[i + 20LL]));
			_mm256_stream_pd(&dst[i + 24LL], _mm256_loadu_pd(&src[i + 24LL]));
			_mm256_stream_pd(&dst[i + 28LL], _mm256_loadu_pd(&src[i + 28LL]));
		}
		_mm_sfence();
	}
	else {
	     for (i = 0LL; i != ROUND_TO_FOUR(len, 4LL); i += 32LL) {
		     _mm256_stream_pd(&dst[i + 0LL],  _mm256_load_pd(&src[i+0LL]));
		     _mm256_stream_pd(&dst[i + 4LL],  _mm256_load_pd(&src[i+4LL]));
		     _mm256_stream_pd(&dst[i + 8LL],  _mm256_load_pd(&src[i+8LL]));
		     _mm256_stream_pd(&dst[i + 12LL], _mm256_load_pd(&src[i+12LL]));
		     _mm256_stream_pd(&dst[i + 16LL], _mm256_load_pd(&src[i+16LL]));
		     _mm256_stream_pd(&dst[i + 20LL], _mm256_load_pd(&src[i+20LL]));
		     _mm256_stream_pd(&dst[i + 24LL], _mm256_load_pd(&src[i+24LL]));
		     _mm256_stream_pd(&dst[i + 28LL], _mm256_load_pd(&src[i+28LL]));
	}
	_mm_sfence();
  }
	for (; i != len ; ++i)
		dst[i] = src[i];
}

void
lam::common::
avx256_memcpy2x(_Inout_ double * __restrict dst,
			    _In_ const double * __restrict src,
			    _In_ const int64_t len) {
	if ((reinterpret_cast<uintptr_t>(dst) & 0x1F) != 0ULL ||
		(reinterpret_cast<uintptr_t>(src) & 0x1F) == 0ULL) {
		return;
	}
	int64_t i;
	if ((reinterpret_cast<uintptr_t>(dst) & 0x1F) != 0ULL &&
		(reinterpret_cast<uintptr_t>(src) & 0x1F) != 0ULL) {
		for (i = 0LL; i != ROUND_TO_FOUR(len, 4LL); i += 8LL) {
			_mm256_storeu_pd(&dst[i + 0LL], _mm256_loadu_pd(&src[i + 0LL]));
			_mm256_storeu_pd(&dst[i + 4LL], _mm256_loadu_pd(&src[i + 4LL]));
		}
	}
	else {
	    for (i = 0LL; i != ROUND_TO_FOUR(len, 4LL); i += 8LL) {
		     _mm256_store_pd(&dst[i + 0LL], _mm256_load_pd(&src[i+0LL]));
		     _mm256_store_pd(&dst[i + 4LL], _mm256_load_pd(&src[i+4LL]));
	    }
	}
	for (; i != len; ++i)
		dst[i] = src[i];
}

void
lam::common::
avx256_memcpy4x(_Inout_ double * __restrict dst,
			    _In_ const double * __restrict src,
				_In_ const int64_t len) {
	if ((reinterpret_cast<uintptr_t>(dst) & 0x1F) != 0ULL ||
		(reinterpret_cast<uintptr_t>(src) & 0x1F) == 0ULL) {
		return;
	}
	int64_t i;
	if ((reinterpret_cast<uintptr_t>(dst)& 0x1F) != 0ULL &&
		(reinterpret_cast<uintptr_t>(src)& 0x1F) != 0ULL) {
	
	    for (i = 0LL; i != ROUND_TO_FOUR(len, 4LL); i += 16LL) {
		      _mm256_storeu_pd(&dst[i + 0LL],  _mm256_loadu_pd(&src[i+0LL]));
		      _mm256_storeu_pd(&dst[i + 4LL],  _mm256_loadu_pd(&src[i+4LL]));
		      _mm256_storeu_pd(&dst[i + 8LL],  _mm256_loadu_pd(&src[i+8LL]));
		      _mm256_storeu_pd(&dst[i + 12LL], _mm256_loadu_pd(&src[i+12LL]));
	     }
	 }
	else {
		for (i = 0LL; i != ROUND_TO_FOUR(len, 4LL); i += 16LL) {
			_mm256_store_pd(&dst[i + 0LL],  _mm256_load_pd(&src[i + 0LL]));
			_mm256_store_pd(&dst[i + 4LL],  _mm256_load_pd(&src[i + 4LL]));
			_mm256_store_pd(&dst[i + 8LL],  _mm256_load_pd(&src[i + 8LL]));
			_mm256_store_pd(&dst[i + 12LL], _mm256_load_pd(&src[i + 12LL]));
		}
	}
	for (; i != len; ++i)
		dst[i] = src[i];
}

void
lam::common::
avx256_memcpy8x(_Inout_ double    *    __restrict dst,
				_In_ const double *    __restrict src,
				_In_ const int64_t len) {
	if ((reinterpret_cast<uintptr_t>(dst)& 0x1F) != 0ULL ||
		(reinterpret_cast<uintptr_t>(src)& 0x1F) == 0ULL) {
		return;
	}
	int64_t i;
	if ((reinterpret_cast<uintptr_t>(dst)& 0x1F) != 0ULL &&
		(reinterpret_cast<uintptr_t>(src)& 0x1F) != 0ULL) {
	
	       for (i = 0LL; i != ROUND_TO_FOUR(len, 4LL); i += 32LL) {
		       _mm256_storeu_pd(&dst[i + 0LL], _mm256_loadu_pd(&src[i + 0LL]));
		       _mm256_storeu_pd(&dst[i + 4LL], _mm256_loadu_pd(&src[i + 4LL]));
		       _mm256_storeu_pd(&dst[i + 8LL], _mm256_loadu_pd(&src[i + 8LL]));
		       _mm256_storeu_pd(&dst[i + 12LL], _mm256_loadu_pd(&src[i + 12LL]));
		       _mm256_storeu_pd(&dst[i + 16LL], _mm256_loadu_pd(&src[i+16LL]));
		       _mm256_storeu_pd(&dst[i + 20LL], _mm256_loadu_pd(&src[i+20LL]));
		       _mm256_storeu_pd(&dst[i + 24LL], _mm256_loadu_pd(&src[i+24LL]));
		       _mm256_storeu_pd(&dst[i + 28LL], _mm256_loadu_pd(&src[i+28LL]));
	      }
	}
	else {
		for (i = 0LL; i != ROUND_TO_FOUR(len, 4LL); i += 32LL) {
			_mm256_store_pd(&dst[i + 0LL], _mm256_load_pd(&src[i + 0LL]));
			_mm256_store_pd(&dst[i + 4LL], _mm256_load_pd(&src[i + 4LL]));
			_mm256_store_pd(&dst[i + 8LL], _mm256_load_pd(&src[i + 8LL]));
			_mm256_store_pd(&dst[i + 12LL], _mm256_load_pd(&src[i + 12LL]));
			_mm256_store_pd(&dst[i + 16LL], _mm256_load_pd(&src[i + 16LL]));
			_mm256_store_pd(&dst[i + 20LL], _mm256_load_pd(&src[i + 20LL]));
			_mm256_store_pd(&dst[i + 24LL], _mm256_load_pd(&src[i + 24LL]));
			_mm256_store_pd(&dst[i + 28LL], _mm256_load_pd(&src[i + 28LL]));
		}
	}
	for (; i != len; ++i)
		dst[i] = src[i];
}

void
lam::common
::avx256_cached_memmove(_Out_ void * __restrict _Dst,
				        _In_ const void * __restrict _Src,
					    _In_ const int32_t _nelems) {
	if (MEMMOVE_1ELEM <= _nelems) { return;}
	char * __restrict dst = (char *)_Dst;
	const char * __restrict src = (const char *)_Src;
	if ( _nelems <= MEMMOVE_16ELEMS) {
		const __m256 ymm0(_mm256_loadu_ps((float*)&src[0]));
		const __m256 ymm1(_mm256_loadu_ps((float*)&src[1*YMM_LEN]));
		_mm256_storeu_ps((float*)&dst[0],  ymm0);
		_mm256_storeu_ps((float*)&dst[1*YMM_LEN], ymm1);
		return;
	}
	else if ( _nelems <= MEMMOVE_32ELEMS) {
		const __m256 ymm0(_mm256_loadu_ps((float*)&src[0]));
		const __m256 ymm1(_mm256_loadu_ps((float*)&src[1*YMM_LEN]));
		const __m256 ymm2(_mm256_loadu_ps((float*)&src[2*YMM_LEN]));
		const __m256 ymm3(_mm256_loadu_ps((float*)&src[3*YMM_LEN]));
		_mm256_storeu_ps((float*)&dst[0], ymm0);
		_mm256_storeu_ps((float*)&dst[1*YMM_LEN],ymm1);
		_mm256_storeu_ps((float*)&dst[2*YMM_LEN],ymm2);
		_mm256_storeu_ps((float*)&dst[3*YMM_LEN],ymm3);
		return;
	}
	else if ( _nelems <= MEMMOVE_64ELEMS){
		const __m256 ymm0(_mm256_loadu_ps((float*)&src[0]));
		const __m256 ymm1(_mm256_loadu_ps((float*)&src[1*YMM_LEN]));
		const __m256 ymm2(_mm256_loadu_ps((float*)&src[2*YMM_LEN]));
		const __m256 ymm3(_mm256_loadu_ps((float*)&src[3*YMM_LEN]));
		const __m256 ymm4(_mm256_loadu_ps((float*)&src[4*YMM_LEN]));
		const __m256 ymm5(_mm256_loadu_ps((float*)&src[5*YMM_LEN]));
		const __m256 ymm6(_mm256_loadu_ps((float*)&src[6*YMM_LEN]));
		const __m256 ymm7(_mm256_loadu_ps((float*)&src[7*YMM_LEN]));
		_mm256_storeu_ps((float*)&dst[0], ymm0);
		_mm256_storeu_ps((float*)&dst[1*YMM_LEN], ymm1);
		_mm256_storeu_ps((float*)&dst[2*YMM_LEN], ymm2);
		_mm256_storeu_ps((float*)&dst[3*YMM_LEN], ymm3);
		_mm256_storeu_ps((float*)&dst[4*YMM_LEN], ymm4);
		_mm256_storeu_ps((float*)&dst[5*YMM_LEN], ymm5);
		_mm256_storeu_ps((float*)&dst[6*YMM_LEN], ymm6);
		_mm256_storeu_ps((float*)&dst[7*YMM_LEN], ymm7);
		return;
	}
	else if ( _nelems <= MEMMOVE_128ELEMS) {

		_mm_prefetch((const char*)&src[0], _MM_HINT_T0);
		_mm_prefetch((const char*)&src[2*YMM_LEN],_MM_HINT_T0);
		_mm_prefetch((const char*)&src[4*YMM_LEN],_MM_HINT_T0);
		_mm_prefetch((const char*)&src[6*YMM_LEN],_MM_HINT_T0);
		_mm_prefetch((const char*)&src[8*YMM_LEN],_MM_HINT_T0);

		const __m256 ymm0(_mm256_loadu_ps((float*)&src[0]));
		const __m256 ymm1(_mm256_loadu_ps((float*)&src[1*YMM_LEN]));
		const __m256 ymm2(_mm256_loadu_ps((float*)&src[2*YMM_LEN]));
		const __m256 ymm3(_mm256_loadu_ps((float*)&src[3*YMM_LEN]));
		const __m256 ymm4(_mm256_loadu_ps((float*)&src[4*YMM_LEN]));
		const __m256 ymm5(_mm256_loadu_ps((float*)&src[5*YMM_LEN]));
		const __m256 ymm6(_mm256_loadu_ps((float*)&src[6*YMM_LEN]));
		const __m256 ymm7(_mm256_loadu_ps((float*)&src[7*YMM_LEN]));
		const __m256 ymm8(_mm256_loadu_ps((float*)&src[8*YMM_LEN]));
		const __m256 ymm9(_mm256_loadu_ps((float*)&src[9*YMM_LEN]));
		const __m256 ymm10(_mm256_loadu_ps((float*)&src[10*YMM_LEN]));
		const __m256 ymm11(_mm256_loadu_ps((float*)&src[11*YMM_LEN]));
		const __m256 ymm12(_mm256_loadu_ps((float*)&src[12*YMM_LEN]));
		const __m256 ymm13(_mm256_loadu_ps((float*)&src[13*YMM_LEN]));
		const __m256 ymm14(_mm256_loadu_ps((float*)&src[14*YMM_LEN]));
		const __m256 ymm15(_mm256_loadu_ps((float*)&src[15*YMM_LEN]));
		_mm256_storeu_ps((float*)&dst[0], ymm0);
		_mm256_storeu_ps((float*)&dst[1*YMM_LEN], ymm1);
		_mm256_storeu_ps((float*)&dst[2*YMM_LEN], ymm2);
		_mm256_storeu_ps((float*)&dst[3*YMM_LEN], ymm3);
		_mm256_storeu_ps((float*)&dst[4*YMM_LEN], ymm4);
		_mm256_storeu_ps((float*)&dst[5*YMM_LEN], ymm5);
		_mm256_storeu_ps((float*)&dst[6*YMM_LEN], ymm6);
		_mm256_storeu_ps((float*)&dst[7*YMM_LEN], ymm7);
		_mm256_storeu_ps((float*)&dst[8*YMM_LEN], ymm8);
		_mm256_storeu_ps((float*)&dst[9*YMM_LEN], ymm9);
		_mm256_storeu_ps((float*)&dst[10*YMM_LEN],ymm10);
		_mm256_storeu_ps((float*)&dst[11*YMM_LEN],ymm11);
		_mm256_storeu_ps((float*)&dst[12*YMM_LEN],ymm12);
		_mm256_storeu_ps((float*)&dst[13*YMM_LEN],ymm13);
		_mm256_storeu_ps((float*)&dst[14*YMM_LEN],ymm14);
		_mm256_storeu_ps((float*)&dst[15*YMM_LEN],ymm15);
		return;
	}
	else if (_nelems <= MAXFLOATSPERPAGE4KiB){
		int32_t i;
		for (i = 0; i != ROUND_TO_EIGHT(_nelems, 8); i += 64) {
			_mm_prefetch((const char*)&src[i], _MM_HINT_T0);
			const __m256 ymm0(_mm256_loadu_ps((float*)&src[i+0]));
			const __m256 ymm1(_mm256_loadu_ps((float*)&src[i+1*YMM_LEN]));
			const __m256 ymm2(_mm256_loadu_ps((float*)&src[i+2*YMM_LEN]));
			const __m256 ymm3(_mm256_loadu_ps((float*)&src[i+3*YMM_LEN]));
			const __m256 ymm4(_mm256_loadu_ps((float*)&src[i+4*YMM_LEN]));
			const __m256 ymm5(_mm256_loadu_ps((float*)&src[i+5*YMM_LEN]));
			const __m256 ymm6(_mm256_loadu_ps((float*)&src[i+6*YMM_LEN]));
			const __m256 ymm7(_mm256_loadu_ps((float*)&src[i+7*YMM_LEN]));
			_mm256_storeu_ps((float*)&dst[i+0], ymm0);
			_mm256_storeu_ps((float*)&dst[i+1*YMM_LEN], ymm1);
			_mm256_storeu_ps((float*)&dst[i+2*YMM_LEN], ymm2);
			_mm256_storeu_ps((float*)&dst[i+3*YMM_LEN], ymm3);
			_mm256_storeu_ps((float*)&dst[i+4*YMM_LEN], ymm4);
			_mm256_storeu_ps((float*)&dst[i+5*YMM_LEN], ymm5);
			_mm256_storeu_ps((float*)&dst[i+6*YMM_LEN], ymm6);
			_mm256_storeu_ps((float*)&dst[i+7*YMM_LEN], ymm7);
		}
		for (; i != _nelems; ++i) {
			dst[i] = src[i];
		}
		return;
	}
	else if (_nelems > MAXFLOATSPERPAGE4KiB) {
		int32_t j;
		
			
		for (int32_t k = 0; k != _nelems; k += MAXFLOATSPERPAGE4KiB) {
			volatile float t = src[k + MAXFLOATSPERPAGE4KiB];
			for (j = k + 128; j != k + MAXFLOATSPERPAGE4KiB; j += 64) {
				_mm_prefetch((const char*)&src[j], _MM_HINT_T0);
			}
			for (j = k; j != ROUND_TO_EIGHT(k + MAXFLOATSPERPAGE4KiB, 8); j += 64) {
				const __m256 ymm0(_mm256_loadu_ps((float*)&src[j+0]));
				const __m256 ymm1(_mm256_loadu_ps((float*)&src[j+1*YMM_LEN]));
				const __m256 ymm2(_mm256_loadu_ps((float*)&src[j+2*YMM_LEN]));
				const __m256 ymm3(_mm256_loadu_ps((float*)&src[j+3*YMM_LEN]));
				const __m256 ymm4(_mm256_loadu_ps((float*)&src[j+4*YMM_LEN]));
				const __m256 ymm5(_mm256_loadu_ps((float*)&src[j+5*YMM_LEN]));
				const __m256 ymm6(_mm256_loadu_ps((float*)&src[j+6*YMM_LEN]));
				const __m256 ymm7(_mm256_loadu_ps((float*)&src[j+7*YMM_LEN]));
				_mm256_storeu_ps((float*)&dst[j+0], ymm0);
				_mm256_storeu_ps((float*)&dst[j+1*YMM_LEN], ymm1);
				_mm256_storeu_ps((float*)&dst[j+2*YMM_LEN], ymm2);
				_mm256_storeu_ps((float*)&dst[j+3*YMM_LEN], ymm3);
				_mm256_storeu_ps((float*)&dst[j+4*YMM_LEN], ymm4);
				_mm256_storeu_ps((float*)&dst[j+5*YMM_LEN], ymm5);
				_mm256_storeu_ps((float*)&dst[j+6*YMM_LEN], ymm6);
				_mm256_storeu_ps((float*)&dst[j+7*YMM_LEN], ymm7);
			}
			for (; j != _nelems; ++j) {
				dst[j] = src[j];
			}
		}
		return;
	}
}

void
lam::common
::avx256_uncached_memmove(_Out_ void * __restrict _Dst,
					      _In_ const void * __restrict _Src,
					      _In_ const int32_t _nelems) {
	if (_nelems < MEMMOVE_1ELEM) { return;}
	char * __restrict dst = (char*)_Dst;
	const char * __restrict src = (const char*)_Src;
	uintptr_t dst_len = (uintptr_t)dst;
	int32_t _nbytes = 4*_nelems;
	int32_t misalign = 0;
	if (dst_len & 0x1F) {
		misalign = min_val(0x20 - (dst_len & 0x1F),_nbytes);
		dst += misalign;
		dst_len += misalign;
		_nbytes -= misalign;
	}
	if (_nelems <= MEMMOVE_16ELEMS) {
		const __m256 ymm0(_mm256_loadu_ps((float*)&src[0]));
		const __m256 ymm1(_mm256_loadu_ps((float*)&src[1 * YMM_LEN]));
		_mm256_stream_ps((float*)&dst[0], ymm0);
		_mm256_stream_ps((float*)&dst[1 * YMM_LEN], ymm1);
		_mm_sfence();
		return;
	}
	else if (_nelems <= MEMMOVE_32ELEMS) {
		const __m256 ymm0(_mm256_loadu_ps((float*)&src[0]));
		const __m256 ymm1(_mm256_loadu_ps((float*)&src[1 * YMM_LEN]));
		const __m256 ymm2(_mm256_loadu_ps((float*)&src[2 * YMM_LEN]));
		const __m256 ymm3(_mm256_loadu_ps((float*)&src[3 * YMM_LEN]));
		_mm256_stream_ps((float*)&dst[0], ymm0);
		_mm256_stream_ps((float*)&dst[1 * YMM_LEN], ymm1);
		_mm256_stream_ps((float*)&dst[2 * YMM_LEN], ymm2);
		_mm256_stream_ps((float*)&dst[3 * YMM_LEN], ymm3);
		_mm_sfence();
		return;
	}
	else if (_nelems <= MEMMOVE_64ELEMS){
		const __m256 ymm0(_mm256_loadu_ps((float*)&src[0]));
		const __m256 ymm1(_mm256_loadu_ps((float*)&src[1 * YMM_LEN]));
		const __m256 ymm2(_mm256_loadu_ps((float*)&src[2 * YMM_LEN]));
		const __m256 ymm3(_mm256_loadu_ps((float*)&src[3 * YMM_LEN]));
		const __m256 ymm4(_mm256_loadu_ps((float*)&src[4 * YMM_LEN]));
		const __m256 ymm5(_mm256_loadu_ps((float*)&src[5 * YMM_LEN]));
		const __m256 ymm6(_mm256_loadu_ps((float*)&src[6 * YMM_LEN]));
		const __m256 ymm7(_mm256_loadu_ps((float*)&src[7 * YMM_LEN]));
		_mm256_stream_ps((float*)&dst[0], ymm0);
		_mm256_stream_ps((float*)&dst[1 * YMM_LEN], ymm1);
		_mm256_stream_ps((float*)&dst[2 * YMM_LEN], ymm2);
		_mm256_stream_ps((float*)&dst[3 * YMM_LEN], ymm3);
		_mm256_stream_ps((float*)&dst[4 * YMM_LEN], ymm4);
		_mm256_stream_ps((float*)&dst[5 * YMM_LEN], ymm5);
		_mm256_stream_ps((float*)&dst[6 * YMM_LEN], ymm6);
		_mm256_stream_ps((float*)&dst[7 * YMM_LEN], ymm7);
		_mm_sfence();
		return;
	}
	else if (_nelems <= MEMMOVE_128ELEMS) {

		_mm_prefetch((const char*)&src[0], _MM_HINT_T0);
		_mm_prefetch((const char*)&src[2 * YMM_LEN], _MM_HINT_T0);
		_mm_prefetch((const char*)&src[4 * YMM_LEN], _MM_HINT_T0);
		_mm_prefetch((const char*)&src[6 * YMM_LEN], _MM_HINT_T0);
		_mm_prefetch((const char*)&src[8 * YMM_LEN], _MM_HINT_T0);

		const __m256 ymm0(_mm256_loadu_ps((float*)&src[0]));
		const __m256 ymm1(_mm256_loadu_ps((float*)&src[1 * YMM_LEN]));
		const __m256 ymm2(_mm256_loadu_ps((float*)&src[2 * YMM_LEN]));
		const __m256 ymm3(_mm256_loadu_ps((float*)&src[3 * YMM_LEN]));
		const __m256 ymm4(_mm256_loadu_ps((float*)&src[4 * YMM_LEN]));
		const __m256 ymm5(_mm256_loadu_ps((float*)&src[5 * YMM_LEN]));
		const __m256 ymm6(_mm256_loadu_ps((float*)&src[6 * YMM_LEN]));
		const __m256 ymm7(_mm256_loadu_ps((float*)&src[7 * YMM_LEN]));
		const __m256 ymm8(_mm256_loadu_ps((float*)&src[8 * YMM_LEN]));
		const __m256 ymm9(_mm256_loadu_ps((float*)&src[9 * YMM_LEN]));
		const __m256 ymm10(_mm256_loadu_ps((float*)&src[10 * YMM_LEN]));
		const __m256 ymm11(_mm256_loadu_ps((float*)&src[11 * YMM_LEN]));
		const __m256 ymm12(_mm256_loadu_ps((float*)&src[12 * YMM_LEN]));
		const __m256 ymm13(_mm256_loadu_ps((float*)&src[13 * YMM_LEN]));
		const __m256 ymm14(_mm256_loadu_ps((float*)&src[14 * YMM_LEN]));
		const __m256 ymm15(_mm256_loadu_ps((float*)&src[15 * YMM_LEN]));
		_mm256_stream_ps((float*)&dst[0], ymm0);
		_mm256_stream_ps((float*)&dst[1 * YMM_LEN], ymm1);
		_mm256_stream_ps((float*)&dst[2 * YMM_LEN], ymm2);
		_mm256_stream_ps((float*)&dst[3 * YMM_LEN], ymm3);
		_mm256_stream_ps((float*)&dst[4 * YMM_LEN], ymm4);
		_mm256_stream_ps((float*)&dst[5 * YMM_LEN], ymm5);
		_mm256_stream_ps((float*)&dst[6 * YMM_LEN], ymm6);
		_mm256_stream_ps((float*)&dst[7 * YMM_LEN], ymm7);
		_mm256_stream_ps((float*)&dst[8 * YMM_LEN], ymm8);
		_mm256_stream_ps((float*)&dst[9 * YMM_LEN], ymm9);
		_mm256_stream_ps((float*)&dst[10 * YMM_LEN], ymm10);
		_mm256_stream_ps((float*)&dst[11 * YMM_LEN], ymm11);
		_mm256_stream_ps((float*)&dst[12 * YMM_LEN], ymm12);
		_mm256_stream_ps((float*)&dst[13 * YMM_LEN], ymm13);
		_mm256_stream_ps((float*)&dst[14 * YMM_LEN], ymm14);
		_mm256_stream_ps((float*)&dst[15 * YMM_LEN], ymm15);
		_mm_sfence();
		return;
	}
	else if (_nelems <= MAXFLOATSPERPAGE4KiB){
		int32_t i;
		for (i = 0; i != ROUND_TO_EIGHT(_nelems, 8); i += 64) {
			_mm_prefetch((const char*)&src[i], _MM_HINT_T0);
			const __m256 ymm0(_mm256_loadu_ps((float*)&src[i + 0]));
			const __m256 ymm1(_mm256_loadu_ps((float*)&src[i + 1 * YMM_LEN]));
			const __m256 ymm2(_mm256_loadu_ps((float*)&src[i + 2 * YMM_LEN]));
			const __m256 ymm3(_mm256_loadu_ps((float*)&src[i + 3 * YMM_LEN]));
			const __m256 ymm4(_mm256_loadu_ps((float*)&src[i + 4 * YMM_LEN]));
			const __m256 ymm5(_mm256_loadu_ps((float*)&src[i + 5 * YMM_LEN]));
			const __m256 ymm6(_mm256_loadu_ps((float*)&src[i + 6 * YMM_LEN]));
			const __m256 ymm7(_mm256_loadu_ps((float*)&src[i + 7 * YMM_LEN]));
			_mm256_stream_ps((float*)&dst[i + 0], ymm0);
			_mm256_stream_ps((float*)&dst[i + 1 * YMM_LEN], ymm1);
			_mm256_stream_ps((float*)&dst[i + 2 * YMM_LEN], ymm2);
			_mm256_stream_ps((float*)&dst[i + 3 * YMM_LEN], ymm3);
			_mm256_stream_ps((float*)&dst[i + 4 * YMM_LEN], ymm4);
			_mm256_stream_ps((float*)&dst[i + 5 * YMM_LEN], ymm5);
			_mm256_stream_ps((float*)&dst[i + 6 * YMM_LEN], ymm6);
			_mm256_stream_ps((float*)&dst[i + 7 * YMM_LEN], ymm7);
		}
		_mm_sfence();
		for (; i != _nelems; ++i) {
			dst[i] = src[i];
		}
		return;
	}
	else if (_nelems > MAXFLOATSPERPAGE4KiB) {
		int32_t j;


		for (int32_t k = 0; k != _nelems; k += MAXFLOATSPERPAGE4KiB) {
			volatile float t = src[k + MAXFLOATSPERPAGE4KiB];
			for (j = k + 128; j != k + MAXFLOATSPERPAGE4KiB; j += 64) {
				_mm_prefetch((const char*)&src[j], _MM_HINT_T0);
			}
			for (j = k; j != k + MAXFLOATSPERPAGE4KiB; j += 64) {
				const __m256 ymm0(_mm256_loadu_ps((float*)&src[j + 0]));
				const __m256 ymm1(_mm256_loadu_ps((float*)&src[j + 1 * YMM_LEN]));
				const __m256 ymm2(_mm256_loadu_ps((float*)&src[j + 2 * YMM_LEN]));
				const __m256 ymm3(_mm256_loadu_ps((float*)&src[j + 3 * YMM_LEN]));
				const __m256 ymm4(_mm256_loadu_ps((float*)&src[j + 4 * YMM_LEN]));
				const __m256 ymm5(_mm256_loadu_ps((float*)&src[j + 5 * YMM_LEN]));
				const __m256 ymm6(_mm256_loadu_ps((float*)&src[j + 6 * YMM_LEN]));
				const __m256 ymm7(_mm256_loadu_ps((float*)&src[j + 7 * YMM_LEN]));
				_mm256_stream_ps((float*)&dst[j + 0], ymm0);
				_mm256_stream_ps((float*)&dst[j + 1 * YMM_LEN], ymm1);
				_mm256_stream_ps((float*)&dst[j + 2 * YMM_LEN], ymm2);
				_mm256_stream_ps((float*)&dst[j + 3 * YMM_LEN], ymm3);
				_mm256_stream_ps((float*)&dst[j + 4 * YMM_LEN], ymm4);
				_mm256_stream_ps((float*)&dst[j + 5 * YMM_LEN], ymm5);
				_mm256_stream_ps((float*)&dst[j + 6 * YMM_LEN], ymm6);
				_mm256_stream_ps((float*)&dst[j + 7 * YMM_LEN], ymm7);
			}
			
		}
		_mm_sfence();
		return;
	}
}

void
lam::common
::avx512_cached_memmove(_Out_ void * __restrict _Dst,
					    _In_  const void * __restrict _Src,
			            _In_ const int32_t _nelems) {
	if (MEMMOVE_1ELEM <= _nelems) { return; }
    char * __restrict dst = (char *)_Dst;
	const char * __restrict src = (char *)_Src;
	
	if (_nelems <= MEMMOVE_16ELEMS) {
		const __m512 zmm0(_mm512_loadu_ps((float*)&src[0]));
		_mm512_storeu_ps((float*)&dst[0],zmm0);
		return;
	}
	 else if ( _nelems <= MEMMOVE_32ELEMS) {
		const __m512 zmm0(_mm512_loadu_ps((float*)&src[0]));
		const __m512 zmm1(_mm512_loadu_ps((float*)&src[1*ZMM_LEN]));
		_mm512_storeu_ps((float*)&dst[0], zmm0);
		_mm512_storeu_ps((float*)&dst[1*ZMM_LEN], zmm1);
		return;
	}	
	 else if ( _nelems <= MEMMOVE_64ELEMS) {
		 const __m512 zmm0(_mm512_loadu_ps((float*)&src[0]));
		 const __m512 zmm1(_mm512_loadu_ps((float*)&src[1*ZMM_LEN]));
		 const __m512 zmm2(_mm512_loadu_ps((float*)&src[2*ZMM_LEN]));
		 const __m512 zmm3(_mm512_loadu_ps((float*)&src[3*ZMM_LEN]));
		 _mm512_storeu_ps((float*)&dst[0],zmm0);
		 _mm512_storeu_ps((float*)&dst[1*ZMM_LEN],zmm1);
		 _mm512_storeu_ps((float*)&dst[2*ZMM_LEN],zmm2);
		 _mm512_storeu_ps((float*)&dst[3*ZMM_LEN],zmm3);
		 return;
	 }
	 else if ( _nelems <= MEMMOVE_128ELEMS) {
		 const __m512 zmm0(_mm512_loadu_ps((float*)&src[0]));
		 const __m512 zmm1(_mm512_loadu_ps((float*)&src[1*ZMM_LEN]));
		 const __m512 zmm2(_mm512_loadu_ps((float*)&src[2*ZMM_LEN]));
		 const __m512 zmm3(_mm512_loadu_ps((float*)&src[3*ZMM_LEN]));
		 const __m512 zmm4(_mm512_loadu_ps((float*)&src[4*ZMM_LEN]));
		 const __m512 zmm5(_mm512_loadu_ps((float*)&src[5*ZMM_LEN]));
		 const __m512 zmm6(_mm512_loadu_ps((float*)&src[6*ZMM_LEN]));
		 const __m512 zmm7(_mm512_loadu_ps((float*)&src[7*ZMM_LEN]));
		 _mm512_storeu_ps((float*)&dst[0],   zmm0);
		 _mm512_storeu_ps((float*)&dst[1*ZMM_LEN],  zmm1);
		 _mm512_storeu_ps((float*)&dst[2*ZMM_LEN],  zmm2);
		 _mm512_storeu_ps((float*)&dst[3*ZMM_LEN],  zmm3);
		 _mm512_storeu_ps((float*)&dst[4*ZMM_LEN],  zmm4);
		 _mm512_storeu_ps((float*)&dst[5*ZMM_LEN],  zmm5);
		 _mm512_storeu_ps((float*)&dst[6*ZMM_LEN],  zmm6);
		 _mm512_storeu_ps((float*)&dst[7*ZMM_LEN],  zmm7);
		 return;
	 }
	 else if ( _nelems <= MEMMOVE_256ELEMS) {
		 _mm_prefetch((const char *)&src[0],          _MM_HINT_T0);
		 _mm_prefetch((const char *)&src[1*ZMM_LEN],  _MM_HINT_T0);
		 _mm_prefetch((const char *)&src[2*ZMM_LEN],  _MM_HINT_T0);
		 _mm_prefetch((const char *)&src[3*ZMM_LEN],  _MM_HINT_T0);
		 _mm_prefetch((const char *)&src[4*ZMM_LEN],  _MM_HINT_T0);
		 _mm_prefetch((const char *)&src[5*ZMM_LEN],  _MM_HINT_T0);
		 _mm_prefetch((const char *)&src[6*ZMM_LEN],  _MM_HINT_T0);
		 _mm_prefetch((const char *)&src[7*ZMM_LEN],  _MM_HINT_T0);
		 _mm_prefetch((const char *)&src[8*ZMM_LEN],  _MM_HINT_T0);
		 _mm_prefetch((const char *)&src[9*ZMM_LEN],  _MM_HINT_T0);
		 _mm_prefetch((const char *)&src[10*ZMM_LEN], _MM_HINT_T0);
		 _mm_prefetch((const char *)&src[11*ZMM_LEN], _MM_HINT_T0);
		 _mm_prefetch((const char *)&src[12*ZMM_LEN], _MM_HINT_T0);
		 _mm_prefetch((const char *)&src[13*ZMM_LEN], _MM_HINT_T0);
		 _mm_prefetch((const char *)&src[14*ZMM_LEN], _MM_HINT_T0);
		 _mm_prefetch((const char *)&src[15*ZMM_LEN], _MM_HINT_T0);
		 const __m512 zmm0(_mm512_loadu_ps((float*)&src[0]));
		 const __m512 zmm1(_mm512_loadu_ps((float*)&src[1*ZMM_LEN]));
		 const __m512 zmm2(_mm512_loadu_ps((float*)&src[2*ZMM_LEN]));
		 const __m512 zmm3(_mm512_loadu_ps((float*)&src[3*ZMM_LEN]));
		 const __m512 zmm4(_mm512_loadu_ps((float*)&src[4*ZMM_LEN]));
		 const __m512 zmm5(_mm512_loadu_ps((float*)&src[5*ZMM_LEN]));
		 const __m512 zmm6(_mm512_loadu_ps((float*)&src[6*ZMM_LEN]));
		 const __m512 zmm7(_mm512_loadu_ps((float*)&src[7*ZMM_LEN]));
		 const __m512 zmm8(_mm512_loadu_ps((float*)&src[8*ZMM_LEN]));
		 const __m512 zmm9(_mm512_loadu_ps((float*)&src[9*ZMM_LEN]));
		 const __m512 zmm10(_mm512_loadu_ps((float*)&src[10*ZMM_LEN]));
		 const __m512 zmm11(_mm512_loadu_ps((float*)&src[11*ZMM_LEN]));
		 const __m512 zmm12(_mm512_loadu_ps((float*)&src[12*ZMM_LEN]));
		 const __m512 zmm13(_mm512_loadu_ps((float*)&src[13*ZMM_LEN]));
		 const __m512 zmm14(_mm512_loadu_ps((float*)&src[14*ZMM_LEN]));
		 const __m512 zmm15(_mm512_loadu_ps((float*)&src[15*ZMM_LEN]));
		 _mm512_storeu_ps((float*)&dst[0],	 zmm0);
		 _mm512_storeu_ps((float*)&dst[1*ZMM_LEN],  zmm1);
		 _mm512_storeu_ps((float*)&dst[2*ZMM_LEN],  zmm2);
		 _mm512_storeu_ps((float*)&dst[3*ZMM_LEN],  zmm3);
		 _mm512_storeu_ps((float*)&dst[4*ZMM_LEN],  zmm4);
		 _mm512_storeu_ps((float*)&dst[5*ZMM_LEN],  zmm5);
		 _mm512_storeu_ps((float*)&dst[6*ZMM_LEN],  zmm6);
		 _mm512_storeu_ps((float*)&dst[7*ZMM_LEN],  zmm7);
		 _mm512_storeu_ps((float*)&dst[8*ZMM_LEN],  zmm8);
		 _mm512_storeu_ps((float*)&dst[9*ZMM_LEN],  zmm9);
		 _mm512_storeu_ps((float*)&dst[10*ZMM_LEN], zmm10);
		 _mm512_storeu_ps((float*)&dst[11*ZMM_LEN], zmm11);
		 _mm512_storeu_ps((float*)&dst[12*ZMM_LEN], zmm12);
		 _mm512_storeu_ps((float*)&dst[13*ZMM_LEN], zmm13);
		 _mm512_storeu_ps((float*)&dst[14*ZMM_LEN], zmm14);
		 _mm512_storeu_ps((float*)&dst[15*ZMM_LEN], zmm15);
		 return;
	 }
	 else if ( _nelems <= PAGE4KiB) {
		 int32_t i;
		 for (i = 0; i != ROUND_TO_SIXTEEN(_nelems,16); i += 128) {
			 _mm_prefetch((const char *)&src[i+0], _MM_HINT_T0);
			 const __m512 zmm0(_mm512_loadu_ps((float*)&src[i+0]));
			 const __m512 zmm1(_mm512_loadu_ps((float*)&src[i+1*ZMM_LEN]));
			 const __m512 zmm2(_mm512_loadu_ps((float*)&src[i+2*ZMM_LEN]));
			 const __m512 zmm3(_mm512_loadu_ps((float*)&src[i+3*ZMM_LEN]));
			 const __m512 zmm4(_mm512_loadu_ps((float*)&src[i+4*ZMM_LEN]));
			 const __m512 zmm5(_mm512_loadu_ps((float*)&src[i+5*ZMM_LEN]));
			 const __m512 zmm6(_mm512_loadu_ps((float*)&src[i+6*ZMM_LEN]));
			 const __m512 zmm7(_mm512_loadu_ps((float*)&src[i+7*ZMM_LEN]));
			 _mm512_storeu_ps((float*)&dst[i+0],   zmm0);
			 _mm512_storeu_ps((float*)&dst[i+1*ZMM_LEN],  zmm1);
			 _mm512_storeu_ps((float*)&dst[i+2*ZMM_LEN],  zmm2);
			 _mm512_storeu_ps((float*)&dst[i+3*ZMM_LEN],  zmm3);
			 _mm512_storeu_ps((float*)&dst[i+4*ZMM_LEN],  zmm4);
			 _mm512_storeu_ps((float*)&dst[i+5*ZMM_LEN],  zmm5);
			 _mm512_storeu_ps((float*)&dst[i+6*ZMM_LEN],  zmm6);
			 _mm512_storeu_ps((float*)&dst[i+7*ZMM_LEN],  zmm7);
		 }
		 for (; i != _nelems; ++i) {
			 dst[i] = src[i];
		 }
		 return;
	 }
	 else if (_nelems > MAXFLOATSPERPAGE4KiB) {
		 int32_t j;
		 for (int32_t k = 0; k != _nelems; k += MAXFLOATSPERPAGE4KiB) {
			volatile float t = src[k + MAXFLOATSPERPAGE4KiB];

			 for ( j = k + 128; j != k + MAXFLOATSPERPAGE4KiB; j += 128) {
				 _mm_prefetch((const char*)&src[j], _MM_HINT_T0);
			 }

			 for (j = k; j != k + MAXFLOATSPERPAGE4KiB; j += 128) {
				 const __m512 zmm0(_mm512_loadu_ps((float*)&src[j+0]));
				 const __m512 zmm1(_mm512_loadu_ps((float*)&src[j+1*ZMM_LEN]));
				 const __m512 zmm2(_mm512_loadu_ps((float*)&src[j+2*ZMM_LEN]));
				 const __m512 zmm3(_mm512_loadu_ps((float*)&src[j+3*ZMM_LEN]));
				 const __m512 zmm4(_mm512_loadu_ps((float*)&src[j+4*ZMM_LEN]));
				 const __m512 zmm5(_mm512_loadu_ps((float*)&src[j+5*ZMM_LEN]));
				 const __m512 zmm6(_mm512_loadu_ps((float*)&src[j+6*ZMM_LEN]));
				 const __m512 zmm7(_mm512_loadu_ps((float*)&src[j+7*ZMM_LEN]));
				 _mm512_storeu_ps((float*)&dst[j+0], zmm0);
				 _mm512_storeu_ps((float*)&dst[j+1*ZMM_LEN], zmm1);
				 _mm512_storeu_ps((float*)&dst[j+2*ZMM_LEN], zmm2);
				 _mm512_storeu_ps((float*)&dst[j+3*ZMM_LEN], zmm3);
				 _mm512_storeu_ps((float*)&dst[j+4*ZMM_LEN], zmm4);
				 _mm512_storeu_ps((float*)&dst[j+5*ZMM_LEN], zmm5);
				 _mm512_storeu_ps((float*)&dst[j+6*ZMM_LEN], zmm6);
				 _mm512_storeu_ps((float*)&dst[j+7*ZMM_LEN], zmm7);
			 }
			
		 }
		 return;
	 }

}

void
lam::common
::avx512_uncached_memmove(_Out_ void * __restrict _Dst,
						  _In_ const void * __restrict _Src,
					      _In_  int32_t _nelems) {
	if (MEMMOVE_1ELEM <= _nelems) { return; }
	char * __restrict dst = (char*)_Dst;
	const char * __restrict src = (char*)_Src;
	uintptr_t dst_val = (uintptr_t)dst;
	int32_t misalign = 0;
	int32_t nbytes = 4*_nelems;
	if (dst_val & 0x3F) {
	     misalign = min_val(0x40 - (dst_val & 0x3F), nbytes);
		dst += misalign;
		dst_val += misalign;
		nbytes -= misalign;
	}
	if (_nelems <= MEMMOVE_16ELEMS) {
		const __m512 zmm0(_mm512_loadu_ps((float*)&src[0]));
		_mm512_stream_ps((float*)&dst[0], zmm0);
		_mm_sfence();
		return;
	}
	else if (_nelems <= MEMMOVE_32ELEMS) {
		const __m512 zmm0(_mm512_loadu_ps((float*)&src[0]));
		const __m512 zmm1(_mm512_loadu_ps((float*)&src[1 * ZMM_LEN]));
		_mm512_stream_ps((float*)&dst[0], zmm0);
		_mm512_stream_ps((float*)&dst[1 * ZMM_LEN], zmm1);
		_mm_sfence();
		return;
	}
	else if (_nelems <= MEMMOVE_64ELEMS) {
		const __m512 zmm0(_mm512_loadu_ps((float*)&src[0]));
		const __m512 zmm1(_mm512_loadu_ps((float*)&src[1 * ZMM_LEN]));
		const __m512 zmm2(_mm512_loadu_ps((float*)&src[2 * ZMM_LEN]));
		const __m512 zmm3(_mm512_loadu_ps((float*)&src[3 * ZMM_LEN]));
		_mm512_stream_ps((float*)&dst[0], zmm0);
		_mm512_stream_ps((float*)&dst[1 * ZMM_LEN], zmm1);
		_mm512_stream_ps((float*)&dst[2 * ZMM_LEN], zmm2);
		_mm512_stream_ps((float*)&dst[3 * ZMM_LEN], zmm3);
		_mm_sfence();
		return;
	}
	else if (_nelems <= MEMMOVE_128ELEMS) {
		const __m512 zmm0(_mm512_loadu_ps((float*)&src[0]));
		const __m512 zmm1(_mm512_loadu_ps((float*)&src[1 * ZMM_LEN]));
		const __m512 zmm2(_mm512_loadu_ps((float*)&src[2 * ZMM_LEN]));
		const __m512 zmm3(_mm512_loadu_ps((float*)&src[3 * ZMM_LEN]));
		const __m512 zmm4(_mm512_loadu_ps((float*)&src[4 * ZMM_LEN]));
		const __m512 zmm5(_mm512_loadu_ps((float*)&src[5 * ZMM_LEN]));
		const __m512 zmm6(_mm512_loadu_ps((float*)&src[6 * ZMM_LEN]));
		const __m512 zmm7(_mm512_loadu_ps((float*)&src[7 * ZMM_LEN]));
		_mm512_stream_ps((float*)&dst[0], zmm0);
		_mm512_stream_ps((float*)&dst[1 * ZMM_LEN], zmm1);
		_mm512_stream_ps((float*)&dst[2 * ZMM_LEN], zmm2);
		_mm512_stream_ps((float*)&dst[3 * ZMM_LEN], zmm3);
		_mm512_stream_ps((float*)&dst[4 * ZMM_LEN], zmm4);
		_mm512_stream_ps((float*)&dst[5 * ZMM_LEN], zmm5);
		_mm512_stream_ps((float*)&dst[6 * ZMM_LEN], zmm6);
		_mm512_stream_ps((float*)&dst[7 * ZMM_LEN], zmm7);
		_mm_sfence();
		return;
	}
	else if (_nelems <= MEMMOVE_256ELEMS) {
		_mm_prefetch((const char *)&src[0], _MM_HINT_T0);
		_mm_prefetch((const char *)&src[1 * ZMM_LEN], _MM_HINT_T0);
		_mm_prefetch((const char *)&src[2 * ZMM_LEN], _MM_HINT_T0);
		_mm_prefetch((const char *)&src[3 * ZMM_LEN], _MM_HINT_T0);
		_mm_prefetch((const char *)&src[4 * ZMM_LEN], _MM_HINT_T0);
		_mm_prefetch((const char *)&src[5 * ZMM_LEN], _MM_HINT_T0);
		_mm_prefetch((const char *)&src[6 * ZMM_LEN], _MM_HINT_T0);
		_mm_prefetch((const char *)&src[7 * ZMM_LEN], _MM_HINT_T0);
		_mm_prefetch((const char *)&src[8 * ZMM_LEN], _MM_HINT_T0);
		_mm_prefetch((const char *)&src[9 * ZMM_LEN], _MM_HINT_T0);
		_mm_prefetch((const char *)&src[10 * ZMM_LEN], _MM_HINT_T0);
		_mm_prefetch((const char *)&src[11 * ZMM_LEN], _MM_HINT_T0);
		_mm_prefetch((const char *)&src[12 * ZMM_LEN], _MM_HINT_T0);
		_mm_prefetch((const char *)&src[13 * ZMM_LEN], _MM_HINT_T0);
		_mm_prefetch((const char *)&src[14 * ZMM_LEN], _MM_HINT_T0);
		_mm_prefetch((const char *)&src[15 * ZMM_LEN], _MM_HINT_T0);
		const __m512 zmm0(_mm512_loadu_ps((float*)&src[0]));
		const __m512 zmm1(_mm512_loadu_ps((float*)&src[1 * ZMM_LEN]));
		const __m512 zmm2(_mm512_loadu_ps((float*)&src[2 * ZMM_LEN]));
		const __m512 zmm3(_mm512_loadu_ps((float*)&src[3 * ZMM_LEN]));
		const __m512 zmm4(_mm512_loadu_ps((float*)&src[4 * ZMM_LEN]));
		const __m512 zmm5(_mm512_loadu_ps((float*)&src[5 * ZMM_LEN]));
		const __m512 zmm6(_mm512_loadu_ps((float*)&src[6 * ZMM_LEN]));
		const __m512 zmm7(_mm512_loadu_ps((float*)&src[7 * ZMM_LEN]));
		const __m512 zmm8(_mm512_loadu_ps((float*)&src[8 * ZMM_LEN]));
		const __m512 zmm9(_mm512_loadu_ps((float*)&src[9 * ZMM_LEN]));
		const __m512 zmm10(_mm512_loadu_ps((float*)&src[10 * ZMM_LEN]));
		const __m512 zmm11(_mm512_loadu_ps((float*)&src[11 * ZMM_LEN]));
		const __m512 zmm12(_mm512_loadu_ps((float*)&src[12 * ZMM_LEN]));
		const __m512 zmm13(_mm512_loadu_ps((float*)&src[13 * ZMM_LEN]));
		const __m512 zmm14(_mm512_loadu_ps((float*)&src[14 * ZMM_LEN]));
		const __m512 zmm15(_mm512_loadu_ps((float*)&src[15 * ZMM_LEN]));
		_mm512_stream_ps((float*)&dst[0], zmm0);
		_mm512_stream_ps((float*)&dst[1 * ZMM_LEN], zmm1);
		_mm512_stream_ps((float*)&dst[2 * ZMM_LEN], zmm2);
		_mm512_stream_ps((float*)&dst[3 * ZMM_LEN], zmm3);
		_mm512_stream_ps((float*)&dst[4 * ZMM_LEN], zmm4);
		_mm512_stream_ps((float*)&dst[5 * ZMM_LEN], zmm5);
		_mm512_stream_ps((float*)&dst[6 * ZMM_LEN], zmm6);
		_mm512_stream_ps((float*)&dst[7 * ZMM_LEN], zmm7);
		_mm512_stream_ps((float*)&dst[8 * ZMM_LEN], zmm8);
		_mm512_stream_ps((float*)&dst[9 * ZMM_LEN], zmm9);
		_mm512_stream_ps((float*)&dst[10 * ZMM_LEN], zmm10);
		_mm512_stream_ps((float*)&dst[11 * ZMM_LEN], zmm11);
		_mm512_stream_ps((float*)&dst[12 * ZMM_LEN], zmm12);
		_mm512_stream_ps((float*)&dst[13 * ZMM_LEN], zmm13);
		_mm512_stream_ps((float*)&dst[14 * ZMM_LEN], zmm14);
		_mm512_stream_ps((float*)&dst[15 * ZMM_LEN], zmm15);
		_mm_sfence();
		return;
	}
	else if (_nelems <= PAGE4KiB) {
		int32_t i;
		for (i = 0; i != ROUND_TO_SIXTEEN(_nelems, 16); i += 128) {
			_mm_prefetch((const char *)&src[i + 0], _MM_HINT_T0);
			const __m512 zmm0(_mm512_loadu_ps((float*)&src[i + 0]));
			const __m512 zmm1(_mm512_loadu_ps((float*)&src[i + 1 * ZMM_LEN]));
			const __m512 zmm2(_mm512_loadu_ps((float*)&src[i + 2 * ZMM_LEN]));
			const __m512 zmm3(_mm512_loadu_ps((float*)&src[i + 3 * ZMM_LEN]));
			const __m512 zmm4(_mm512_loadu_ps((float*)&src[i + 4 * ZMM_LEN]));
			const __m512 zmm5(_mm512_loadu_ps((float*)&src[i + 5 * ZMM_LEN]));
			const __m512 zmm6(_mm512_loadu_ps((float*)&src[i + 6 * ZMM_LEN]));
			const __m512 zmm7(_mm512_loadu_ps((float*)&src[i + 7 * ZMM_LEN]));
			_mm512_stream_ps((float*)&dst[i + 0], zmm0);
			_mm512_stream_ps((float*)&dst[i + 1 * ZMM_LEN], zmm1);
			_mm512_stream_ps((float*)&dst[i + 2 * ZMM_LEN], zmm2);
			_mm512_stream_ps((float*)&dst[i + 3 * ZMM_LEN], zmm3);
			_mm512_stream_ps((float*)&dst[i + 4 * ZMM_LEN], zmm4);
			_mm512_stream_ps((float*)&dst[i + 5 * ZMM_LEN], zmm5);
			_mm512_stream_ps((float*)&dst[i + 6 * ZMM_LEN], zmm6);
			_mm512_stream_ps((float*)&dst[i + 7 * ZMM_LEN], zmm7);
		}
		_mm_sfence();
		for (; i != _nelems; ++i) {
			dst[i] = src[i];
		}
		return;
	}
	else if (_nelems > MAXFLOATSPERPAGE4KiB) {
		int32_t j;
		for (int32_t k = 0; k != _nelems; k += MAXFLOATSPERPAGE4KiB) {
			volatile float t = src[k + MAXFLOATSPERPAGE4KiB];

			for (j = k + 128; j != k + MAXFLOATSPERPAGE4KiB; j += 128) {
				_mm_prefetch((const char*)&src[j], _MM_HINT_T0);
			}

			for (j = k; j != k + MAXFLOATSPERPAGE4KiB; j += 128) {
				const __m512 zmm0(_mm512_loadu_ps((float*)&src[j + 0]));
				const __m512 zmm1(_mm512_loadu_ps((float*)&src[j + 1 * ZMM_LEN]));
				const __m512 zmm2(_mm512_loadu_ps((float*)&src[j + 2 * ZMM_LEN]));
				const __m512 zmm3(_mm512_loadu_ps((float*)&src[j + 3 * ZMM_LEN]));
				const __m512 zmm4(_mm512_loadu_ps((float*)&src[j + 4 * ZMM_LEN]));
				const __m512 zmm5(_mm512_loadu_ps((float*)&src[j + 5 * ZMM_LEN]));
				const __m512 zmm6(_mm512_loadu_ps((float*)&src[j + 6 * ZMM_LEN]));
				const __m512 zmm7(_mm512_loadu_ps((float*)&src[j + 7 * ZMM_LEN]));
				_mm512_stream_ps((float*)&dst[j + 0], zmm0);
				_mm512_stream_ps((float*)&dst[j + 1 * ZMM_LEN], zmm1);
				_mm512_stream_ps((float*)&dst[j + 2 * ZMM_LEN], zmm2);
				_mm512_stream_ps((float*)&dst[j + 3 * ZMM_LEN], zmm3);
				_mm512_stream_ps((float*)&dst[j + 4 * ZMM_LEN], zmm4);
				_mm512_stream_ps((float*)&dst[j + 5 * ZMM_LEN], zmm5);
				_mm512_stream_ps((float*)&dst[j + 6 * ZMM_LEN], zmm6);
				_mm512_stream_ps((float*)&dst[j + 7 * ZMM_LEN], zmm7);
			}

		}
		_mm_sfence();
		return;
	}
	
}



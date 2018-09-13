
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





#include "LAM_mkl_weibullrng.h"
#include "../LAM_common.h"
#if (LAM_DEBUG_ON) == 1
#include "../LAM_debug.h"
#else
#include "../LAM_malloc.h"
#endif
#include "../LAM_error_macros.h"
#include "../Math/LAM_constants.h"
//
//	Implementation
//

lam::math::stat::
MKLWeibullRNG::
MKLWeibullRNG() {
	using namespace lam::math::constants;
	data.m_rvec    = NULL;
	data.m_alpha   = dinf;
	data.m_a       = dinf;
	data.m_beta    = dinf;
	data.m_nvalues = 0;
	data.m_brng    = 0;
	data.m_seed    = 0;
	data.m_error   = 1;
}



lam::math::stat::
MKLWeibullRNG::
MKLWeibullRNG(_In_ const MKL_INT nvalues,
			  _In_ const MKL_UINT brng,
			  _In_ const MKL_INT seed,
			  _In_ const double alpha,
			  _In_ const double a,
			  _In_ const double beta) {
		using namespace lam::common;
#if (LAM_DEBUG_ON) == 1
		data.m_rvec    = lam_edmalloca_dbg(static_cast<size_t>(nvalues),align64B,__FILE__,__LINE__);
#else
	    data.m_rvec    = lam_edmalloca(static_cast<size_t>(nvalues), align64B); // <-- Upon touching m_rvec load 64byte(whole object) to cache
#endif
	data.m_alpha   = alpha;
	data.m_a       = a;
	data.m_beta    = beta;
	data.m_nvalues = nvalues;
	data.m_brng    = brng;
	data.m_seed    = seed;
	data.m_error   = 0;
	avx256_init_unroll8x(&data.m_rvec[0], static_cast<int64_t>(data.m_nvalues), 0.0); // m_rvec should be in cache
}
	





lam::math::stat::
MKLWeibullRNG::
MKLWeibullRNG(_In_ const MKLWeibullRNG &x) {
	using namespace lam::common;
#if (LAM_DEBUG_ON) == 1
	data.m_rvec = lam_edmalloca_dbg(static_cast<size_t>(x.data.m_nvalues),align64B,__FILE__,__LINE__);
#else
	data.m_rvec      = lam_edmalloca(static_cast<size_t>(x.m_nvalues), align64B);
#endif
	data.m_alpha   = x.data.m_alpha;
	data.m_a       = x.data.m_a;
	data.m_beta    = x.data.m_beta;
	data.m_nvalues = x.data.m_nvalues;
	data.m_brng    = x.data.m_brng;
	data.m_seed    = x.data.m_seed;
	data.m_error   = x.data.m_error;
#if (USE_NT_STORES) == 1
	avx256_memcpy8x_nt(&data.m_rvec[0], &x.data.m_rvec[0], static_cast<size_t>(data.m_nvalues));
#else
	avx256_memcpy8x(&data.m_rvec[0], &x.data.m_rvec[0], static_cast<size_t>(data.m_nvalues));
#endif
}	
	




lam::math::stat::
MKLWeibullRNG::
MKLWeibullRNG(_In_ MKLWeibullRNG &&x){
	
	data.m_rvec      = &x.data.m_rvec[0];
	data.m_alpha     = x.data.m_alpha;
	data.m_a         = x.data.m_a;
	data.m_beta      = x.data.m_beta;
	data.m_nvalues   = x.data.m_nvalues;
	data.m_brng      = x.data.m_brng;
	data.m_seed      = x.data.m_seed;
	data.m_error     = x.data.m_error;
	x.data.m_nvalues = 0;
	x.data.m_rvec    = NULL;
}	
	




lam::math::stat::
MKLWeibullRNG::
~MKLWeibullRNG() {
#if (LAM_DEBUG_ON) == 1
	if (NULL != data.m_rvec) _aligned_free_dbg(data.m_rvec); data.m_rvec = NULL;
#else
	if (NULL != data.m_rvec) _mm_free(data.m_rvec); data.m_rvec = NULL;
#endif
}		
		
	


lam::math::stat::MKLWeibullRNG &
lam::math::stat::MKLWeibullRNG::
operator=(_In_ const MKLWeibullRNG &x){
    using namespace lam::common;
	if (this == &x) return (*this);
	if (data.m_nvalues != x.data.m_nvalues) { // Handle size mismatch
#if (LAM_DEBUG_ON) == 1
	_aligned_free_dbg(data.m_rvec);
#else
	_mm_free(data.m_rvec);
#endif
	data.m_alpha = 0.0; data.m_a = 0.0;
	data.m_beta = 0.0;  data.m_nvalues = 0;
	data.m_brng = 0;    data.m_seed = 0;
	data.m_error = 1;
#if (LAM_DEBUG_ON) == 1
	  data.m_rvec = lam_edmalloca_dbg(static_cast<size_t>(x.data.m_nvalues), align64B, __FILE__, __LINE__);
#else
	  data.m_rvec = lam_edmalloca(static_cast<size_t>(x.data.m_nvalues), align64B);
#endif	
	}
	else {
		// Copy state
		data.m_alpha = x.data.m_alpha;data.m_a = x.data.m_a;
		data.m_beta  = x.data.m_beta; data.m_nvalues = x.data.m_nvalues;
		data.m_brng  = x.data.m_brng; data.m_seed   = x.data.m_seed;
		data.m_error = x.data.m_error;
#if (USE_NT_STORES) == 1
		avx256_memcpy8x_nt(&data.m_rvec[0], &x.data.m_rvec[0], static_cast<size_t>(x.data.m_nvalues));
#else
		avx256_memcpy8x(&data.m_rvec[0], &x.data.m_rvec[0], static_cast<size_t>(x.data.m_nvalues));
#endif
	}
	return (*this);
}	
	

	

	
	
	
	



lam::math::stat::MKLWeibullRNG &
lam::math::stat::MKLWeibullRNG::
operator=(_In_  MKLWeibullRNG &&x) {
	if (this == &x) return (*this);
#if (LAM_DEBUG_ON) == 1
	_aligned_free_dbg(data.m_rvec);
#else
	_mm_free(data.m_rvec);
#endif
	data.m_rvec      = &x.data.m_rvec[0];
	data.m_alpha     = x.data.m_alpha;
	data.m_a         = x.data.m_a;
	data.m_beta      = x.data.m_beta;
	data.m_nvalues   = x.data.m_nvalues;
	data.m_brng      = x.data.m_brng;
	data.m_seed      = x.data.m_seed;
	data.m_error     = x.data.m_error;
	x.data.m_nvalues = 0;
	x.data.m_rvec    = NULL;
	return (*this);
}	
	
	


void
lam::math::stat::MKLWeibullRNG::
compute_rand_distribution(_In_ const MKL_INT method) {
	VSLStreamStatePtr stream;
	data.m_error = vslNewStream(&stream,data.m_brng,data.m_seed);
	if (VSL_ERROR_OK != data.m_error) {
		PRINT_ERROR_VALUE("vslNewStream -- failed with an error value: ", data.m_error)
		DUMP_CALLSTACK_ON_ERROR
		return;
	}
	data.m_error = vdRngWeibull(method, stream, data.m_nvalues, &data.m_rvec[0],data.m_alpha,data.m_a,data.m_beta);
	if (VSL_ERROR_OK != data.m_error) {
		PRINT_ERROR_VALUE("vdRngWeibull -- failed with an error value: ", data.m_error)
		DUMP_CALLSTACK_ON_ERROR
		return;
	}
	data.m_error = vslDeleteStream(&stream);
	if (VSL_ERROR_OK != data.m_error) {
		PRINT_ERROR_VALUE("vslDeleteStream -- failed with an error value: ", data.m_error)
		DUMP_CALLSTACK_ON_ERROR
		return;
	}
}

void
lam::math::stat::MKLWeibullRNG::
compute_rand_distribution(_Inout_ VSLStreamStatePtr stream, 
						  _In_ const MKL_INT method) {
	// Stream must be deallocated (deinitialized) by the caller of this procedure.
	data.m_error = vslNewStream(&stream, data.m_brng, data.m_seed);
	if (VSL_ERROR_OK != data.m_error) {
		PRINT_ERROR_VALUE("vslNewStream -- failed with an error value: ", data.m_error)
		DUMP_CALLSTACK_ON_ERROR
			return;
	}
	data.m_error = vdRngWeibull(method, stream, data.m_nvalues, &data.m_rvec[0], data.m_alpha, data.m_a, data.m_beta);
	if (VSL_ERROR_OK != data.m_error) {
		PRINT_ERROR_VALUE("vdRngWeibull -- failed with an error value: ", data.m_error)
		DUMP_CALLSTACK_ON_ERROR
		return;
	}
}

std::ostream &
lam::math::stat::
operator<<(_In_ std::ostream &os,
		   _In_ const MKLWeibullRNG &x) {
	for (MKL_INT i = 0; i != x.data.m_nvalues; ++i) {
		os << std::setprecision(15) << std::showpoint <<
			"Random Weibull distribution: m_rvec = " << x.data.m_rvec[i] << std::endl;
	}
	return (os);
}
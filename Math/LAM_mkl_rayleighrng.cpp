
#include "LAM_mkl_rayleighrng.h"
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
MKLRayleighRNG::
MKLRayleighRNG() {
	using namespace lam::math::constants;
	datum.m_rvec = NULL;
	datum.m_a    = dinf;
	datum.m_beta = dinf;
	datum.m_nvalues = 0;
	datum.m_brng    = 0;
	datum.m_seed    = 0;
	datum.m_error   = 1;
}


lam::math::stat::
MKLRayleighRNG::
MKLRayleighRNG( _In_ const MKL_INT nvalues,
			    _In_ const MKL_UINT brng,
				_In_ const MKL_INT seed,
				_In_ const double a,
				_In_ const double beta) {
	using namespace lam::common;
#if (LAM_DEBUG_ON) == 1
	datum.m_rvec = lam_edmalloca_dbg(static_cast<size_t>(nvalues),align64B,__FILE__,__LINE__);
#else
	datum.m_rvec    = lam_edmalloca(static_cast<size_t>(nvalues), align64B);
#endif
	datum.m_a       = a;
	datum.m_beta    = beta;
	datum.m_nvalues = nvalues;
	datum.m_brng    = brng;
	datum.m_seed    = seed;
	datum.m_error   = 1;
	avx256_init_unroll8x(&datum.m_rvec[0], datum.m_nvalues,0.0);
}


lam::math::stat::
MKLRayleighRNG::
MKLRayleighRNG(_In_ const MKLRayleighRNG &x) {
	using namespace lam::common;
#if (LAM_DEBUG_ON) == 1
	datum.m_rvec = lam_edmalloca_dbg(static_cast<size_t>(x.datum.m_nvalues),align64B,__FILE__,__LINE__);
#else
	datum.m_rvec = lam_edmalloca(static_cast<size_t>(x.datum.m_nvalues), align64B);
#endif
	datum.m_a       = x.datum.m_a;
	datum.m_beta    = x.datum.m_beta;
	datum.m_nvalues = x.datum.m_nvalues;
	datum.m_brng    = x.datum.m_brng;
	datum.m_seed    = x.datum.m_seed;
	datum.m_error   = x.datum.m_error;
#if (USE_NT_STORES) == 1
	avx256_memcpy8x_nt(&datum.m_rvec[0], &x.datum.m_rvec[0], datum.m_nvalues);
#else
	avx256_memcpy8x(&datum.m_rvec[0], &x.datum.m_rvec[0], datum.m_nvalues);
#endif
}


lam::math::stat::
MKLRayleighRNG::
MKLRayleighRNG(_In_ MKLRayleighRNG &&x) {
	datum.m_rvec      = &x.datum.m_rvec[0];
	datum.m_a         = x.datum.m_a;
	datum.m_beta      = x.datum.m_beta;
	datum.m_nvalues   = x.datum.m_nvalues;
	datum.m_brng      = x.datum.m_brng;
	datum.m_seed      = x.datum.m_seed;
	datum.m_error     = x.datum.m_error;
	x.datum.m_rvec    =  NULL;
	x.datum.m_nvalues = 0;
}


lam::math::stat::
MKLRayleighRNG::
~MKLRayleighRNG() {
#if (LAM_DEBUG_ON) == 1
	if (NULL != datum.m_rvec) _aligned_free_dbg(datum.m_rvec); datum.m_rvec = NULL;
#else
	if (NULL != datum.m_rvec) _mm_free(datum.m_rvec); datum.m_rvec = NULL;
#endif
}		
		
	


lam::math::stat::MKLRayleighRNG &
lam::math::stat::MKLRayleighRNG::
operator=(_In_ const MKLRayleighRNG &x) {
	using namespace lam::common;
	if (this == &x) return (*this);
#if (LAM_DEBUG_ON) == 1
	_aligned_free_dbg(datum.m_rvec);
#else
	_mm_free(datum.m_rvec);
#endif
	datum.m_a       = x.datum.m_a;
	datum.m_beta    = x.datum.m_beta;
	datum.m_nvalues = x.datum.m_nvalues;
	datum.m_brng    = x.datum.m_brng;
	datum.m_seed    = x.datum.m_seed;
	datum.m_error   = x.datum.m_error;
	_Field_size_(m_nvalues)double * __restrict rvec = NULL;
#if (LAM_DEBUG_ON) == 1
	rvec = lam_edmalloca_dbg(static_cast<size_t>(datum.m_nvalues), align64B, __FILE__,__LINE__);
#else
	rvec =  lam_edmalloca(static_cast<size_t>(datum.m_nvalues), align64B) };
#endif
#if (USE_NT_STORES) == 1
	avx256_memcpy8x_nt(&rvec[0], &x.datum.m_rvec[0], datum.m_nvalues);
#else
	avx256_memcpy8x(&rvec[0], &x.datum.m_rvec[0], datum.m_nvalues);
#endif
	datum.m_rvec = &rvec[0];
	return (*this);
}	
	


lam::math::stat::MKLRayleighRNG &
lam::math::stat::MKLRayleighRNG::
operator=(_In_ MKLRayleighRNG &&x) {
	if (this == &x) return (*this);
#if (LAM_DEBUG_ON) == 1
	_aligned_free_dbg(datum.m_rvec);
#else
	_mm_free(datum.m_rvec);
#endif
	datum.m_rvec = &x.datum.m_rvec[0];
	datum.m_a = x.datum.m_a;
	datum.m_beta = x.datum.m_beta;
	datum.m_nvalues = x.datum.m_nvalues;
	datum.m_brng = x.datum.m_brng;
	datum.m_seed = x.datum.m_seed;
	datum.m_error = x.datum.m_error;
	
	x.datum.m_nvalues = 0;
	x.datum.m_rvec = NULL;
	return (*this);
}	
	


void
lam::math::stat::
MKLRayleighRNG::
compute_rand_distribution(_In_ const MKL_INT method) {
	VSLStreamStatePtr stream;
	datum.m_error = vslNewStream(&stream,datum.m_brng,datum.m_seed);
	if (VSL_ERROR_OK != datum.m_error) {
		PRINT_ERROR_VALUE("vslNewStream -- failed with an error value: ", datum.m_error)
		DUMP_CALLSTACK_ON_ERROR
		return;
	}
	datum.m_error = vdRngRayleigh(method, stream, datum.m_nvalues, &datum.m_rvec[0],datum.m_a,datum.m_beta);
	if (VSL_ERROR_OK != datum.m_error) {
		PRINT_ERROR_VALUE("vdRngRayleigh -- failed with an error value: ", datum.m_error)
		DUMP_CALLSTACK_ON_ERROR
		return;
	}
	datum.m_error = vslDeleteStream(&stream);
	if (VSL_ERROR_OK != datum.m_error) {
		PRINT_ERROR_VALUE("vslDeleteStream -- failed with an error value: ", datum.m_error)
		DUMP_CALLSTACK_ON_ERROR
		return;
	}
}

void
lam::math::stat::
MKLRayleighRNG::
compute_rand_distribution(_Inout_ VSLStreamStatePtr stream,
						  _In_ const MKL_INT method) {
	// Stream must be deallocated (deinitialized) by the caller of this procedure.
	datum.m_error = vslNewStream(&stream, datum.m_brng, datum.m_seed);
	if (VSL_ERROR_OK != datum.m_error) {
		PRINT_ERROR_VALUE("vslNewStream -- failed with an error value: ", datum.m_error)
		DUMP_CALLSTACK_ON_ERROR
		return;
	}
	datum.m_error = vdRngRayleigh(method, stream, datum.m_nvalues, &datum.m_rvec[0],datum.m_a,datum.m_beta);
	if (VSL_ERROR_OK != datum.m_error) {
		PRINT_ERROR_VALUE("vdRngRayleigh -- failed with an error value: ", datum.m_error)
		DUMP_CALLSTACK_ON_ERROR
		return;
	}
}

std::ostream &
lam::math::stat::
operator<<(_Inout_ std::ostream &os,
		   _In_ const MKLRayleighRNG &x) {
	for (MKL_INT i = 0; i != x.datum.m_nvalues; ++i) {
		os << std::setprecision(15) << std::showpoint <<
			"Random Rayleigh distribution: m_rvec = " << x.datum.m_rvec[i] << std::endl;
	}
	return (os);
}
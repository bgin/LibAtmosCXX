
#include "LAM_mkl_uniformrng.h"
#include "../LAM_common.h"
#include "../LAM_malloc.h"
#include "../LAM_error_macros.h"
#include "../Math/LAM_constants.h"
//
//	Implementation
//

lam::math::stat::
MKLUniformRNG::MKLUniformRNG() {
	using namespace lam::math::constants;
	m_rvec    = NULL;
	m_a       = dinf;
	m_b       = dinf;
	m_nvalues = 0;
	m_brng    = 0;
	m_seed    = 0;
	m_error   = 1;
}



lam::math::stat::
MKLUniformRNG::
MKLUniformRNG(_In_ const MKL_INT nvalues,
			  _In_ const MKL_UINT brng,
			  _In_ const MKL_INT seed,
			  _In_ const double a,
			  _In_ const double b) {
	using namespace lam::common;
	m_rvec = lam_edmalloca(static_cast<size_t>(nvalues), align64B);
	m_a = a;
	m_b = b;
	m_nvalues = nvalues;
	m_brng    = brng;
	m_seed    = seed;
	m_error   = 1;
	avx256_init_unroll8x(&m_rvec[0], static_cast<size_t>(m_nvalues),0.0);
}


lam::math::stat::
MKLUniformRNG::
MKLUniformRNG(_In_ const MKLUniformRNG &x) {
	using namespace lam::common;
	m_rvec    = lam_edmalloca(static_cast<size_t>(x.m_nvalues),align64B);
	m_a       = x.m_a;
	m_b       = x.m_b;
	m_nvalues = x.m_nvalues;
	m_brng    = x.m_brng;
	m_seed    = x.m_seed;
	m_error   = x.m_error;
#if (USE_NT_STORES) == 1
	avx256_memcpy8x_nt(&m_rvec[0], &x.m_rvec[0], static_cast<size_t>(m_nvalues));
#else
	avx256_memcpy8x(&m_rvec[0], &x.m_rvec[0], static_cast<size_t>(m_nvalues));
#endif
}


lam::math::stat::
MKLUniformRNG::
MKLUniformRNG(_In_ MKLUniformRNG &&x) {
	m_rvec      = &x.m_rvec[0];
	m_a         = x.m_a;
	m_b         = x.m_b;
	m_nvalues   = x.m_nvalues;
	m_brng      = x.m_brng;
	m_seed      = x.m_seed;
	m_error     = x.m_error;
	x.m_rvec    = NULL;
	x.m_nvalues = 0;
}



lam::math::stat::
MKLUniformRNG::
~MKLUniformRNG() {
	if (NULL != m_rvec) _mm_free(m_rvec); m_rvec = NULL;
}		
	
	


lam::math::stat::MKLUniformRNG &
lam::math::stat::MKLUniformRNG
::operator=(_In_ const MKLUniformRNG &x) {
	using namespace lam::common;
	if (this == &x) return (*this);
	_mm_free(m_rvec);
	m_a       = x.m_a;
	m_b       = x.m_b;
	m_nvalues = x.m_nvalues;
	m_brng    = x.m_brng;
	m_seed    = x.m_seed;
	m_error   = x.m_error;
	_Field_size_(m_nvalues)double * __restrict rvec{
		lam_edmalloca(static_cast<size_t>(m_nvalues), align64B) };
#if (USE_NT_STORES) == 1
	avx256_memcpy8x_nt(&rvec[0], &x.m_rvec[0], static_cast<size_t>(m_nvalues));
#else
	avx256_memcpy8x(&rvec[0], &x.m_rvec[0], static_cast<size_t>(m_nvalues));
#endif
	m_rvec = &rvec[0];
	return (*this);
}	
	


lam::math::stat::MKLUniformRNG &
lam::math::stat::MKLUniformRNG::operator=(_In_ MKLUniformRNG &&x) {
	if (this == &x) return (*this);
	_mm_free(m_rvec);
	m_rvec = &x.m_rvec[0];
	m_a = x.m_a;
	m_b = x.m_b;
	m_nvalues = x.m_nvalues;
	m_brng = x.m_brng;
	m_seed = x.m_seed;
	m_error = x.m_error;
	
	x.m_nvalues = 0;
	x.m_rvec = NULL;
	return (*this);
}	
	


void
lam::math::stat::
MKLUniformRNG::compute_rand_distribution(_In_ const MKL_INT method) {
	VSLStreamStatePtr stream;
	m_error = vslNewStream(&stream,m_brng,m_seed);
	if (VSL_ERROR_OK != m_error) {
		PRINT_ERROR_VALUE("vslNewStream -- failed with an error value: ", m_error)
		DUMP_CALLSTACK_ON_ERROR
		return;
	}
	m_error = vdRngUniform(method, stream, m_nvalues, &m_rvec[0],m_a,m_b);
	if (VSL_ERROR_OK != m_error) {
		PRINT_ERROR_VALUE("vdRngUniform -- failed with an error value: ", m_error)
		DUMP_CALLSTACK_ON_ERROR
		return;
	}
	m_error = vslDeleteStream(&stream);
	if (VSL_ERROR_OK != m_error) {
		PRINT_ERROR_VALUE("vslDeleteStream -- failed with an error value: ", m_error)
		DUMP_CALLSTACK_ON_ERROR
		return;
	}
}

void
lam::math::stat::
MKLUniformRNG::
compute_rand_distribution(_Inout_ VSLStreamStatePtr stream, 
						  _In_ const MKL_INT method) {
	// caller deinitializes VSLStreamStatePtr
	m_error = vslNewStream(&stream,m_brng,m_seed);
	if (VSL_ERROR_OK != m_error) {
		PRINT_ERROR_VALUE("vslNewStream -- failed with an error value: ", m_error)
		DUMP_CALLSTACK_ON_ERROR
		return;
	}
	m_error = vdRngUniform(method, stream, m_nvalues, &m_rvec[0],m_a,m_b);
	if (VSL_ERROR_OK != m_error) {
		PRINT_ERROR_VALUE("vdRngUniform -- failed with an error value: ", m_error)
		DUMP_CALLSTACK_ON_ERROR
		return;
	}
}

std::ostream &
lam::math::stat::
operator<<(_In_ std::ostream &os,
		   _In_ const MKLUniformRNG &x) {
	
	for (MKL_INT i = 0; i != x.m_nvalues; ++i) {
		os << std::setprecision(15) << std::showpoint <<
			"Randomly Uniform distributed: m_rvec = " << x.m_rvec[i] << std::endl;
	}
	return (os);
}
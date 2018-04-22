
#include "LAM_mkl_gaussianrng.h"
#include "../LAM_common.h"
#include "../LAM_malloc.h"
#include "../LAM_error_macros.h"

//
//	Implementation
//

lam::math::stat::
MKLGaussianRNG::MKLGaussianRNG()
:
m_nvalues{},
m_brng{},
m_seed{},
m_error{},
m_a{},
m_sigma{},
m_rvec(NULL) {}

lam::math::stat::
MKLGaussianRNG::
MKLGaussianRNG(_In_ const MKL_INT nvalues,
			   _In_ const MKL_UINT brng,
			   _In_ const MKL_INT seed,
			   _In_ const double a,
			   _In_ const double sigma )
:
m_nvalues{ nvalues },
m_brng{ brng },
m_seed{ seed },
m_error{ 1 },
m_a{ a },
m_sigma{sigma},
m_rvec(lam::common::lam_edmalloca(static_cast<size_t>(m_nvalues), align64B)){
	for (MKL_INT  i = 0; i != m_nvalues; ++i)
		m_rvec[i] = 0.0;
}	

lam::math::stat::
MKLGaussianRNG::
MKLGaussianRNG(_In_ const MKLGaussianRNG &x)
:
m_nvalues{ x.m_nvalues },
m_brng{ x.m_brng },
m_seed{ x.m_seed },
m_error{ x.m_error },
m_a{ x.m_a },
m_sigma{x.m_sigma},
m_rvec(lam::common::lam_edmalloca(static_cast<size_t>(m_nvalues), align64B)){
	lam::common::avx256_memcpy8x(&m_rvec[0], &x.m_rvec[0], static_cast<size_t>(m_nvalues));
}

lam::math::stat::
MKLGaussianRNG::
MKLGaussianRNG(_In_ MKLGaussianRNG &&x)
:
m_nvalues{ x.m_nvalues },
m_brng{ x.m_brng },
m_seed{ x.m_seed },
m_error{ x.m_error },
m_a{ x.m_a },
m_sigma{x.m_sigma},
m_rvec(NULL) {
	m_rvec = &x.m_rvec[0];
	x.m_nvalues = 0;
	x.m_rvec = NULL;
}

lam::math::stat::
MKLGaussianRNG::
~MKLGaussianRNG() {
	if (NULL != m_rvec) {
		_mm_free(m_rvec);
		m_rvec = NULL;
	}
}

lam::math::stat::MKLGaussianRNG &
lam::math::stat::MKLGaussianRNG::operator=(_In_ const MKLGaussianRNG &x) {
	if (this == &x) return (*this);
	m_nvalues = x.m_nvalues;
	m_brng    = x.m_brng;
	m_seed    = x.m_seed;
	m_error   = x.m_error;
	m_a       = x.m_a;
	m_sigma   = x.m_sigma;
	_mm_free(m_rvec);
	double * __restrict rvec{ lam::common::lam_edmalloca(static_cast<size_t>(m_nvalues),align64B) };
	lam::common::avx256_memcpy8x(&rvec[0], &x.m_rvec[0], static_cast<size_t>(m_nvalues));
	m_rvec = &rvec[0];
	return (*this);
}

lam::math::stat::MKLGaussianRNG &
lam::math::stat::MKLGaussianRNG::operator=(_In_ MKLGaussianRNG &&x) {
	if (this == &x) return (*this);
	m_nvalues = x.m_nvalues;
	m_brng = x.m_brng;
	m_seed = x.m_seed;
	m_error = x.m_error;
	m_a = x.m_a;
	m_sigma = x.m_sigma;
	_mm_free(m_rvec);
	m_rvec = &x.m_rvec[0];
	x.m_nvalues = 0;
	x.m_rvec = NULL;
	return (*this);
}

void
lam::math::stat::MKLGaussianRNG::
compute_rand_distribution(){
	VSLStreamStatePtr streamptr;
	m_error = vslNewStream(&streamptr, m_brng, m_seed);
	if (VSL_ERROR_OK != m_error) {
		PRINT_ERROR_VALUE("vslNewStream -- failed with an error value: ", m_error)
		DUMP_CALLSTACK_ON_ERROR
		return;
	}
	m_error = vdRngGaussian(m_brng, streamptr, m_nvalues, &m_rvec[0],m_a,m_sigma);
	if (VSL_ERROR_OK != m_error) {
		PRINT_ERROR_VALUE("vdRngGaussian -- failed with an error value: ", m_error)
		DUMP_CALLSTACK_ON_ERROR
		return;
	}
	m_error = vslDeleteStream(&streamptr);
	if (VSL_ERROR_OK != m_error) {
		PRINT_ERROR_VALUE("vslDeleteStream -- failed with an error value: ", m_error)
		DUMP_CALLSTACK_ON_ERROR
	    return;
	}
}

std::ostream &
lam::math::stat::
operator<<(_In_ std::ostream &os,
		   _In_ const MKLGaussianRNG &x) {
	
	for (MKL_INT i = 0; i != x.m_nvalues; ++i) {
		os << std::setprecision(15) << std::showpoint <<
			"Randomly gaussian distributed: m_rvec = " << x.m_rvec[i] << std::endl;
	}
	return (os);
}		




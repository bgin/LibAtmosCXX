
//
//	Implementation
//

#include "LAM_mkl_cauchyrng.h"
#include "../LAM_common.h"
#include "../LAM_malloc.h"
#include "../LAM_error_macros.h"

//
//	Implementation
//

lam::math::stat::
MKLCauchyRNG::MKLCauchyRNG()
:
m_nvalues{},
m_brng{},
m_seed{},
m_error{},
m_a{},
m_beta{},
m_rvec(NULL) {}

lam::math::stat::
MKLCauchyRNG::MKLCauchyRNG(_In_ const MKL_INT nvalues,
						   _In_ const MKL_UINT brng,
						   _In_ const MKL_INT seed,
						   _In_ const double a,
						   _In_ const double beta)
:
m_nvalues{ nvalues },
m_brng{ brng },
m_seed{ seed },
m_error{ 1 },
m_a{ a },
m_beta{beta},
m_rvec(lam::common::lam_edmalloca(static_cast<size_t>(m_nvalues), align64B)) {
	lam::common::avx256_init_unroll8x(&m_rvec[0], static_cast<int64_t>(m_nvalues),0.0);
}

lam::math::stat::
MKLCauchyRNG::MKLCauchyRNG(_In_ const MKLCauchyRNG &x)
:
m_nvalues{ x.m_nvalues },
m_brng{ x.m_brng },
m_seed{ x.m_seed },
m_error{ x.m_error },
m_a{ x.m_a },
m_beta{x.m_beta},
m_rvec(lam::common::lam_edmalloca(static_cast<size_t>(m_nvalues), align64B)) {
	lam::common::avx256_memcpy8x(&m_rvec[0], &x.m_rvec[0], static_cast<size_t>(m_nvalues));
}

lam::math::stat::
MKLCauchyRNG::MKLCauchyRNG(_In_ MKLCauchyRNG &&x)
:
m_nvalues{ x.m_nvalues },
m_brng{ x.m_brng },
m_seed{ x.m_seed },
m_error{ x.m_error },
m_a{ x.m_a },
m_beta{x.m_beta},
m_rvec(NULL){
	m_rvec = &x.m_rvec[0];
	x.m_nvalues = 0;
	x.m_rvec = NULL;
}

lam::math::stat::
MKLCauchyRNG::~MKLCauchyRNG() {
	if (NULL != m_rvec) {
		_mm_free(m_rvec);
		m_rvec = NULL;
	}
}

lam::math::stat::MKLCauchyRNG &
lam::math::stat::MKLCauchyRNG::operator=(_In_ const MKLCauchyRNG &x) {
	if (this == &x) return (*this);
	m_nvalues = x.m_nvalues;
	m_brng = x.m_brng;
	m_seed = x.m_seed;
	m_error = x.m_error;
	m_a = x.m_a;
	m_beta = x.m_beta;
	_mm_free(m_rvec);
	double * __restrict rvec{ lam::common::lam_edmalloca(static_cast<size_t>(m_nvalues),align64B) };
	lam::common::avx256_memcpy8x(&rvec[0], &x.m_rvec[0], static_cast<size_t>(m_nvalues));
	m_rvec = &rvec[0];
	return (*this);
}

lam::math::stat::MKLCauchyRNG &
lam::math::stat::MKLCauchyRNG::operator=(_In_ MKLCauchyRNG &&x) {
	if (this == &x) return (*this);
	m_nvalues = x.m_nvalues;
	m_brng = x.m_brng;
	m_seed = x.m_seed;
	m_error = x.m_error;
	m_a = x.m_a;
	m_beta = x.m_beta;
	_mm_free(m_rvec);
	m_rvec = &x.m_rvec[0];
	x.m_rvec = NULL;
	x.m_nvalues = 0;
	return (*this);
}

void
lam::math::stat::
MKLCauchyRNG::compute_rand_distribution(_In_ const MKL_INT method) {
	VSLStreamStatePtr stream;
	m_error = vslNewStream(&stream,m_brng,m_seed);
	if (VSL_ERROR_OK != m_error) {
		PRINT_ERROR_VALUE("vslNewStream -- failed with an error value: ", m_error)
		DUMP_CALLSTACK_ON_ERROR
		return;
	}
	m_error = vdRngCauchy(method,stream,m_nvalues,&m_rvec[0],m_a,m_beta);
	if (VSL_ERROR_OK != m_error) {
		if (VSL_ERROR_OK != m_error) {
			PRINT_ERROR_VALUE("vdRngCauchy -- failed with an error value: ", m_error)
			DUMP_CALLSTACK_ON_ERROR
			return;
		}
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
MKLCauchyRNG::
compute_rand_distribution(_Inout_ VSLStreamStatePtr stream,
										_In_ const MKL_INT method) {
	// VSLStreamStatePtr must deallocated by the caller of compute_rand_distribution.
	m_error = vslNewStream(&stream,m_brng,m_seed);
	if (VSL_ERROR_OK != m_error) {
		PRINT_ERROR_VALUE("vslNewStream -- failed with an error value: ", m_error)
		DUMP_CALLSTACK_ON_ERROR
		return;
	}
	m_error = vdRngCauchy(method, stream, m_nvalues, &m_rvec[0],m_a,m_beta);
	if (VSL_ERROR_OK != m_error) {
		if (VSL_ERROR_OK != m_error) {
			PRINT_ERROR_VALUE("vdRngCauchy -- failed with an error value: ", m_error)
			DUMP_CALLSTACK_ON_ERROR
			return;
		}
	}
	// stream is deleted by the caller.
}

std::ostream &
lam::math::stat::operator<<(_In_ std::ostream &os,
						    _In_  const MKLCauchyRNG &x) {
	
	for (MKL_INT i = 0; i != x.m_nvalues; ++i) {
		os << std::setprecision(15) << std::showpoint <<
			"Randomly Cauchy distributed: m_rvec = " << x.m_rvec[i] << std::endl;
	}
	return (os);
}

#include "LAM_mkl_lognormalrng.h"
#include "../LAM_common.h"
#include "../LAM_malloc.h"
#include "../LAM_error_macros.h"

//
//	Implementation
//

lam::math::stat::
MKLLognormalRNG::
MKLLognormalRNG()
:
m_nvalues{},
m_brng{},
m_seed{},
m_error{},
m_a{},
m_sigma{},
m_b{},
m_beta{},
m_rvec(NULL) {}

lam::math::stat::
MKLLognormalRNG::
MKLLognormalRNG(_In_ const MKL_INT nvalues,
			    _In_ const MKL_UINT brng,
				_In_ const MKL_INT seed,
				_In_ const double a,
				_In_ const double sigma,
				_In_ const double b,
				_In_ const double beta)
:
m_nvalues{ nvalues },
m_brng{ brng },
m_seed{ seed },
m_error{ 1 },
m_a{ a },
m_sigma{ sigma },
m_b{ b },
m_beta{beta},
m_rvec(lam::common::lam_edmalloca(static_cast<size_t>(m_nvalues), align64B)) {
	lam::common::avx256_init_unroll8x(&m_rvec[0], static_cast<int64_t>(m_nvalues),0.0L);
}

lam::math::stat::
MKLLognormalRNG::
MKLLognormalRNG(_In_ const MKLLognormalRNG &x)
:
m_nvalues{ x.m_nvalues },
m_brng{ x.m_brng },
m_seed{ x.m_seed },
m_error{ x.m_error },
m_a{ x.m_a },
m_sigma{ x.m_sigma },
m_b{ x.m_b },
m_beta{x.m_beta},
m_rvec(lam::common::lam_edmalloca(static_cast<size_t>(m_nvalues), align64B)) {
	lam::common::avx256_memcpy8x(&m_rvec[0], &x.m_rvec[0], static_cast<size_t>(m_nvalues));
}

lam::math::stat::
MKLLognormalRNG::
MKLLognormalRNG(_In_ MKLLognormalRNG &&x)
:
m_nvalues{ x.m_nvalues },
m_brng{ x.m_brng },
m_seed{ x.m_seed },
m_error{ x.m_error },
m_a{ x.m_a },
m_sigma{ x.m_sigma },
m_b{ x.m_b },
m_beta{ x.m_beta },
m_rvec(NULL) {
	m_rvec = &x.m_rvec[0];
	x.m_nvalues = 0;
	x.m_rvec = NULL;
}

lam::math::stat::
MKLLognormalRNG::
~MKLLognormalRNG() {
	if (NULL != m_rvec) {
		_mm_free(m_rvec);
		m_rvec = NULL;
	}
}

lam::math::stat::MKLLognormalRNG &
lam::math::stat::MKLLognormalRNG::
operator=(_In_ const MKLLognormalRNG &x) {
	if (this == &x) return (*this);
	m_nvalues = x.m_nvalues;
	m_brng = x.m_brng;
	m_seed = x.m_seed;
	m_error = x.m_error;
	m_a = x.m_a;
	m_sigma = x.m_sigma;
	m_b = x.m_b;
	m_beta = x.m_beta;
	_mm_free(m_rvec);
	_Field_size_(m_nvalues)double * __restrict 
	 rvec{ lam::common::lam_edmalloca(static_cast<size_t>(m_nvalues),align64B) };
	lam::common::avx256_memcpy8x(&rvec[0], &x.m_rvec[0], static_cast<size_t>(m_nvalues));
	m_rvec = &rvec[0];
	return (*this);
}

lam::math::stat::MKLLognormalRNG &
lam::math::stat::MKLLognormalRNG::
operator=(_In_ MKLLognormalRNG &&x) {
	if (this == &x) return (*this);
	m_nvalues = x.m_nvalues;
	m_brng = x.m_brng;
	m_seed = x.m_seed;
	m_error = x.m_error;
	m_a = x.m_a;
	m_sigma = x.m_sigma;
	m_b = x.m_b;
	m_beta = x.m_beta;
	_mm_free(m_rvec);
	m_rvec = &x.m_rvec[0];
	x.m_nvalues= 0;
	x.m_rvec = NULL;
	return (*this);
}

void
lam::math::stat::
MKLLognormalRNG::
compute_rand_distribution(_In_ const MKL_INT method) {
	VSLStreamStatePtr stream;
	m_error = vslNewStream(&stream,m_brng,m_seed);
	if (VSL_ERROR_OK != m_error) {
		PRINT_ERROR_VALUE("vslNewStream -- failed with an error value: ", m_error)
		DUMP_CALLSTACK_ON_ERROR
		return;
	}
	m_error = vdRngLognormal(method, stream, m_nvalues, &m_rvec[0],m_a,m_sigma,m_b,m_beta);
	if (VSL_ERROR_OK != m_error) {
		PRINT_ERROR_VALUE("vdRngLognormal -- failed with an error value: ", m_error)
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
MKLLognormalRNG::
compute_rand_distribution(_Inout_ VSLStreamStatePtr stream, 
					      _In_ const MKL_INT method) {
	// Stream must be deallocated (deinitialized) by the caller of this procedure.
	m_error = vslNewStream(&stream,m_brng,m_seed); 
	if (VSL_ERROR_OK != m_error) {
		PRINT_ERROR_VALUE("vslNewStream -- failed with an error value: ", m_error)
		DUMP_CALLSTACK_ON_ERROR
		return;
	}
	m_error = vdRngLognormal(method, stream, m_nvalues, &m_rvec[0], m_a, m_sigma, m_b, m_beta);
	if (VSL_ERROR_OK != m_error) {
		PRINT_ERROR_VALUE("vdRngLognormal -- failed with an error value: ", m_error)
		DUMP_CALLSTACK_ON_ERROR
		return;
	}
}

std::ostream &
lam::math::stat::operator<<(_In_ std::ostream &os,
							_In_ const MKLLognormalRNG &x) {
	for (MKL_INT i = 0; i != x.m_nvalues; ++i) {
		os << std::setprecision(15) << std::showpoint <<
			"Random Lognormal distribution: m_rvec = " << x.m_rvec[i] << std::endl;
	}
	return (os);
}

//
//	Implementation.
//

lam::math::
AVXC2vf64::AVXC2vf64()
:
m_cv64(_mm256_setzero_pd()) {}

lam::math::
AVXC2vf64::AVXC2vf64(_In_ const double re1,
					 _In_ const double im1,
					 _In_ const double re2,
					 _In_ const double im2)
:
m_cv64(_mm256_setr_pd(re1, im1, re2, im2)) {}

lam::math::
AVXC2vf64::AVXC2vf64(_In_ const double re,
					 _In_ const double im)
:
m_cv64(_mm256_setr_pd(re, im, 0.0, 0.0)) {}

lam::math::
AVXC2vf64::AVXC2vf64(_In_ const double re)
:
m_cv64(_mm256_setr_pd(re,0.0,re,0.0)) {}

lam::math::
AVXC2vf64::AVXC2vf64(_In_ const double re1,
				     _In_ const double re2,
					 _In_ const double re3,
					 _In_ const double re4)
:
m_cv64(_mm256_setr_pd(re1, re2, re3, re4)) {}

lam::math::
AVXC2vf64::AVXC2vf64(_In_ const AVXC2vf64 &c)
:
m_cv64(c.m_cv64) {}

lam::math::
AVXC2vf64::AVXC2vf64(_In_ const __m256d &v)
:
m_cv64(v) {}

const __m256d
lam::math::AVXC2vf64::get_cv64() const {
	return (this->m_cv64);
}

__m256d
lam::math::AVXC2vf64::get_cv64() {
	return (this->m_cv64);
}

__m128d
lam::math::AVXC2vf64::complex_1() const {
	return (_mm256_extractf128_pd(m_cv64,0));
}

__m128d
lam::math::AVXC2vf64::complex_2() const {
	return (_mm256_extractf128_pd(m_cv64,1));
}

lam::math::AVXC2vf64 &
lam::math::AVXC2vf64::load_a(_In_ const double * __restrict mem) {
	m_cv64 = _mm256_load_pd(&mem[0]);
	return (*this);
}

lam::math::AVXC2vf64 &
lam::math::AVXC2vf64::load_u(_In_ const double * __restrict mem) {
	m_cv64 = _mm256_loadu_pd(&mem[0]);
	return (*this);
}

void
lam::math::AVXC2vf64::store_a(_Inout_ double * __restrict mem) const {
	_mm256_store_pd(&mem[0],m_cv64);
}

void
lam::math::AVXC2vf64::store_u(_Inout_ double * __restrict mem) const {
	_mm256_storeu_pd(&mem[0],m_cv64);
}

void
lam::math::AVXC2vf64::stream_store(_Inout_ double * __restrict mem) const {
	_mm256_stream_pd(&mem[0],m_cv64);
}

double
lam::math::AVXC2vf64::extract_component(_In_ const int32_t idx) const {
	__declspec(align(32))double t[4] = {};
	store_a(&t[0]);
	return (t[idx & 3]);
}

lam::math::AVXC2vf64  const &
lam::math::AVXC2vf64::insert(_In_ const int32_t idx,
							 _In_ const double val) {
	__m256d ymm = _mm256_broadcast_sd(&val);
	switch (idx) {
		case 0: 
			m_cv64 = _mm256_blend_pd(m_cv64,ymm,1);
	    break;
		case 1:
			m_cv64 = _mm256_blend_pd(m_cv64,ymm,2);
		break;
		case 2:
			m_cv64 = _mm256_blend_pd(m_cv64,ymm,4);
		break;
		default:
			m_cv64 = _mm256_blend_pd(m_cv64,ymm,8);
		
	}
	return (*this);
}

lam::math::AVXC2vf64 &
lam::math::AVXC2vf64::operator=(_In_ const AVXC2vf64 &c) {
	if (this == &c) return (*this);
	m_cv64 = c.m_cv64;
	return (*this);
}

lam::math::AVXC2vf64::operator __m256d () const {
	return (m_cv64);
}

double
lam::math::AVXC2vf64::operator[](_In_ const uint32_t idx) const {
	return (reinterpret_cast<const double*>(&m_cv64)[idx]);
}

std::ostream &
lam::math::operator<<(_In_ std::ostream &os,
					  _In_ const AVXC2vf64 &c) {
	os << std::fixed << std::showpoint << 
		std::setprecision(15) <<
		"Re1: " << "{" << c.get_cv64().m256d_f64[0] << "}" <<
		"Im1: " << "{" << c.get_cv64().m256d_f64[1] << "}" <<
		"Re2: " << "{" << c.get_cv64().m256d_f64[2] << "}" <<
		"Im2: " << "{" << c.get_cv64().m256d_f64[3] << "}" << "\n";
	return (os);
}

__m128d
lam::math::extract(_In_ AVXC2vf64 &c,
				   _In_ const int32_t idx) {
	return (_mm256_extractf128_pd(c,idx));
}

lam::math::AVXC2vf64 
lam::math::select(_In_ const AVXC2vf64 &x,
				  _In_ const AVXC2vf64 &y,
				  _In_ const __m256d &pred) {
	return (_mm256_blendv_pd(x,y,pred));
}

lam::math::AVXC2vf64
lam::math::operator+(_In_ const AVXC2vf64 &x,
					 _In_ const AVXC2vf64 &y) {
	return (_mm256_add_pd(x,y));
}

lam::math::AVXC2vf64
lam::math::operator+(_In_ const AVXC2vf64 &x,
					 _In_ const double re) {
	return (x + AVXC2vf64{re});
}

lam::math::AVXC2vf64
lam::math::operator+(_In_ const double re,
					 _In_ const AVXC2vf64 &x) {
	return (AVXC2vf64{re} + x);
}

lam::math::AVXC2vf64
lam::math::operator+=(_In_ AVXC2vf64 &x,
					  _In_ const AVXC2vf64 &y) {
	x = x + y;
	return (x);
}

lam::math::AVXC2vf64
lam::math::operator+=(_In_ AVXC2vf64 &x,
					  _In_ const double re) {
	x = x + AVXC2vf64{re};
	return (x);
}

lam::math::AVXC2vf64
lam::math::operator+=(_In_ const double re,
_In_ AVXC2vf64 &x) {
	x = AVXC2vf64{re} / x;
	return (x);
}

lam::math::AVXC2vf64
lam::math::operator-(_In_ const AVXC2vf64 &x,
					 _In_ const AVXC2vf64 &y) {
	return (_mm256_sub_pd(x,y));
}

lam::math::AVXC2vf64
lam::math::operator-(_In_ const AVXC2vf64 &x,
					 _In_ const double re) {
	return (x - AVXC2vf64{re});
}

lam::math::AVXC2vf64
lam::math::operator-(_In_ const double re,
					 _In_ const AVXC2vf64 &x) {
	return (AVXC2vf64{re} - x);
}

lam::math::AVXC2vf64
lam::math::operator-=(_In_ AVXC2vf64 &x,
					  _In_ const AVXC2vf64 &y) {
	x = x - y;
	return (x);
}

lam::math::AVXC2vf64
lam::math::operator-=(_In_ AVXC2vf64 &x,
					  _In_ const double re) {
	x = x - AVXC2vf64{re};
	return (x);
}

lam::math::AVXC2vf64
lam::math::operator-=(_In_ const double re,
					  _In_ AVXC2vf64 &x) {
	x = AVXC2vf64{re} - x;
	return (x);
}

lam::math::AVXC2vf64
lam::math::operator*(_In_ const AVXC2vf64 &x,
					 _In_ const AVXC2vf64 &y) {
	// Assume using AVX
	__m256d ymm0 = _mm256_shuffle_pd(y,y,5);
	__m256d ymm1 = _mm256_shuffle_pd(x,x,0xF); // im part
	__m256d ymm2 = _mm256_shuffle_pd(x,x,0x0); // re part
	__m256d ymm3 = _mm256_mul_pd(ymm1,ymm0);
	return (_mm256_fmaddsub_pd(ymm2,y,ymm3));
}

lam::math::AVXC2vf64
lam::math::operator*(_In_ const AVXC2vf64 &x,
					 _In_ const double re) {
	return (x * AVXC2vf64{re});
}

lam::math::AVXC2vf64
lam::math::operator*(_In_ const double re,
					 _In_ const AVXC2vf64 &x) {
	return (AVXC2vf64{re} * x);
}

lam::math::AVXC2vf64
lam::math::operator*=(_In_ AVXC2vf64 &x,
					  _In_ const AVXC2vf64 &y) {
	x = x * y;
	return (x);
}

lam::math::AVXC2vf64
lam::math::operator*=(_In_ AVXC2vf64 &x,
					  _In_ const double re) {
	x = x / AVXC2vf64{re};
	return (x);
}

lam::math::AVXC2vf64
lam::math::operator*=(_In_ const double re,
					  _In_ AVXC2vf64 &x) {
	x = AVXC2vf64{re} / x;
	return (x);
}

lam::math::AVXC2vf64
lam::math::operator/(_In_ const AVXC2vf64 &x,
					 _In_ const AVXC2vf64 &y) {
	// Assumes AVX is available.
	__m256d ymm0 = _mm256_shuffle_pd(x,x,0); // re
	__m256d ymm1 = _mm256_mul_pd(ymm0,y);
	__m256d ymm2 = _mm256_shuffle_pd(y,y,5);
	__m256d ymm3 = _mm256_shuffle_pd(x,x,0xF); // im
	__m256d ymm4 = _mm256_fmsubadd_pd(ymm3,ymm2,ymm0);
	__m256d ymm5 = _mm256_mul_pd(y,y);
	__m256d ymm6 = _mm256_hadd_pd(ymm5,ymm5);
	return (_mm256_div_pd(ymm4,ymm6));
}

lam::math::AVXC2vf64
lam::math::operator/(_In_ const AVXC2vf64 &x,
					 _In_ const double re) {
	return (x / AVXC2vf64{re});
}

lam::math::AVXC2vf64
lam::math::operator/(_In_ const double re,
					 _In_ const AVXC2vf64 &x) {
	return (AVXC2vf64{re} / x);
}

lam::math::AVXC2vf64
lam::math::operator/=(_In_ AVXC2vf64 &x,
					  _In_ const AVXC2vf64 &y) {
	x = x / y;
	return (x);
}

lam::math::AVXC2vf64
lam::math::operator/=(_In_ AVXC2vf64 &x,
					  _In_ const double re) {
	x = x / AVXC2vf64{re};
	return (x);
}

lam::math::AVXC2vf64
lam::math::operator/=(_In_ const double re,
					  _In_ AVXC2vf64 &x) {
	x = AVXC2vf64{re} / x;
	return (x);
}

lam::math::AVXC2vf64
lam::math::operator-(_In_ AVXC2vf64 &x) {
	__m256d t = _mm256_sub_pd(_mm256_setr_pd(0.0,0.0,0.0,0.0),x);
	return (_mm256_mul_pd(_mm256_setr_pd(-1.0,1.0,-1.0,1.0),t));
}

lam::math::AVXC2vf64
lam::math::operator==(_In_ const AVXC2vf64 &x,
					  _In_ const AVXC2vf64 &y) {
	return (_mm256_cmp_pd(x,y,_CMP_EQ_OQ));
}

lam::math::AVXC2vf64
lam::math::operator!=(_In_ const AVXC2vf64 &x,
					  _In_ const AVXC2vf64 &y) {
	return (_mm256_cmp_pd(x,y,_CMP_NEQ_OQ));
}

lam::math::AVXC2vf64
lam::math::operator>(_In_ const AVXC2vf64 &x,
					 _In_ const AVXC2vf64 &y) {
	return (_mm256_cmp_pd(x,y,_CMP_GT_OQ));
}

lam::math::AVXC2vf64
lam::math::operator>=(_In_ const AVXC2vf64 &x,
					  _In_ const AVXC2vf64 &y) {
	return (_mm256_cmp_pd(x,y,_CMP_GE_OQ));
}

lam::math::AVXC2vf64
lam::math::operator<(_In_ const AVXC2vf64 &x,
					 _In_ const AVXC2vf64 &y) {
	return (_mm256_cmp_pd(x,y,_CMP_LT_OQ));
}

lam::math::AVXC2vf64
lam::math::operator<=(_In_ const AVXC2vf64 &x,
					  _In_ const AVXC2vf64 &y) {
	return (_mm256_cmp_pd(x,y,_CMP_LE_OQ));
}







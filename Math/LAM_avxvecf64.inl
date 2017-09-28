
lam::math::
AVXVecF64::AVXVecF64()
:
m_vf64(_mm256_setzero_pd()) {}

lam::math::
AVXVecF64::AVXVecF64(_In_ const double v[4])
:
m_vf64(_mm256_loadu_pd(v)) {}

lam::math::
AVXVecF64::AVXVecF64(_In_ const double s1,
					 _In_ const double s2,
					 _In_ const double s3,
					 _In_ const double s4)
:
m_vf64(_mm256_setr_pd(s1, s2, s3, s4)){}

lam::math::
AVXVecF64::AVXVecF64(_In_ const double s)
:
m_vf64(_mm256_set1_pd(s)) {}

lam::math::
AVXVecF64::AVXVecF64(_In_ const __m256d v)
:
m_vf64(v) {}

lam::math::
AVXVecF64::AVXVecF64(_In_ const __m256i v)
:
m_vf64(_mm256_castsi256_pd(v)) {}

lam::math::
AVXVecF64::AVXVecF64(_In_ const AVXVecF64 &x)
:
m_vf64(x.m_vf64) {}

lam::math::
AVXVecF64::AVXVecF64(_In_ const __m128d v1,
					 _In_ const __m128d v2){
	m_vf64 = _mm256_insertf128_pd(m_vf64,v1,0);
	m_vf64 = _mm256_insertf128_pd(m_vf64,v2,1);
}

const __m256d 
lam::math::AVXVecF64::get_vf64() const {
	return (m_vf64);
}

__m256d
lam::math::AVXVecF64::get_vf64() {
	return (m_vf64);
}

__m128d
lam::math::AVXVecF64::lo_part() const {
	return (_mm256_extractf128_pd(m_vf64,0));
}

__m128d
lam::math::AVXVecF64::hi_part() const {
	return (_mm256_extractf128_pd(m_vf64,1));
}

lam::math::AVXVecF64 &
lam::math::AVXVecF64::load_a(_In_ const double* __restrict adress) {
	m_vf64 = _mm256_load_pd(adress);
	return (*this);
}

lam::math::AVXVecF64 &
lam::math::AVXVecF64::load_u(_In_ const double* __restrict address) {
	m_vf64 = _mm256_loadu_pd(address);
	return (*this);
}

void
lam::math::AVXVecF64::store_a(_In_ double* __restrict address) const {
	_mm256_store_pd(address,m_vf64);
}

void
lam::math::AVXVecF64::store_u(_In_ double* __restrict address) const {
	_mm256_storeu_pd(address,m_vf64);
}

void
lam::math::AVXVecF64::stream_store(_In_ double* __restrict address) const {
	_mm256_stream_pd(address,m_vf64);
}

double
lam::math::AVXVecF64::extract_scalar(_In_ const uint32_t idx) const {
	__declspec(align(32))double t[4] = {0.0};
	store_a(t);
	return (t[idx & 3]);
}

lam::math::AVXVecF64 &
lam::math::AVXVecF64::operator=(_In_ const AVXVecF64 &x) {
	if (this == &x)
		return (*this);
	m_vf64 = x.m_vf64;
	return (*this);
}

lam::math::AVXVecF64::operator __m256d () const {
	return (m_vf64);
}

double
lam::math::AVXVecF64::operator[](_In_ const uint32_t idx) const {
	return (reinterpret_cast<const double*>(&m_vf64)[idx]);
}

std::ostream &
lam::math::operator<<(_In_ std::ostream &os, 
					  _In_ const AVXVecF64 &x) {
	os << std::fixed << std::showpoint << "x=" << x.m_vf64.m256d_f64[0] <<
										  "y=" << x.m_vf64.m256d_f64[1] <<
										  "z=" << x.m_vf64.m256d_f64[2] <<
										  "w=" << x.m_vf64.m256d_f64[3] << "\n";
	return (os);
}

__m128d
lam::math::extract(_In_ AVXVecF64 &x, _In_ const int32_t idx) {
	return (_mm256_extractf128_pd(x,idx));
}

lam::math::AVXVecF64
lam::math::select_vec(_In_ const AVXVecF64 &a,
					  _In_ const AVXVecF64 &b,
					  _In_ const __m256d pred) {

	return (_mm256_blendv_pd(a,b,pred));
}

lam::math::AVXVecF64
lam::math::max(_In_ const AVXVecF64 &x,
			   _In_ const AVXVecF64 &y) {
	return (_mm256_max_pd(x,y));
}

lam::math::AVXVecF64
lam::math::min(_In_ const AVXVecF64 &x,
			   _In_ const AVXVecF64 &y) {
	return (_mm256_min_pd(x,y));
}

lam::math::AVXVecF64
lam::math::abs(_In_ const AVXVecF64 &x) {
	const __m256d mask = _mm256_set1_pd(0x7FFFFFFFFFFFFFF);
	return (_mm256_and_pd(x,mask));
}

lam::math::AVXVecF64
lam::math::sqrt(_In_ const AVXVecF64 &x) {
	return (_mm256_sqrt_pd(x));
}

lam::math::AVXVecF64
lam::math::sqr(_In_ const AVXVecF64 &x) {
	return (x*x);
}

lam::math::AVXVecF64
lam::math::ceil(_In_ const AVXVecF64 &x) {
	return (_mm256_ceil_pd(x));
}

lam::math::AVXVecF64
lam::math::floor(_In_ const AVXVecF64 &x) {
	return (_mm256_floor_pd(x));
}

lam::math::AVXVecF64
lam::math::round(_In_ const AVXVecF64 &x,
				 _In_ const int32_t by) {
	return (_mm256_round_pd(x,by));
}

lam::math::AVXVecF64
lam::math::sin(_In_ const AVXVecF64 &x) {
	return (_mm256_sin_pd(x));
}

lam::math::AVXVecF64
lam::math::cos(_In_ const AVXVecF64 &x) {
	return (_mm256_cos_pd(x));
}

lam::math::AVXVecF64
lam::math::sinh(_In_ const AVXVecF64 &x) {
	return (_mm256_sinh_pd(x));
}

lam::math::AVXVecF64
lam::math::cosh(_In_ const AVXVecF64 &x) {
	return (_mm256_cosh_pd(x));
}

lam::math::AVXVecF64
lam::math::tan(_In_ const AVXVecF64 &x) {
	return (_mm256_tan_pd(x));
}

lam::math::AVXVecF64
lam::math::tanh(_In_ const AVXVecF64 &x) {
	return (_mm256_tanh_pd(x));
}

lam::math::AVXVecF64
lam::math::asin(_In_ const AVXVecF64 &x) {
	return (_mm256_asin_pd(x));
}

lam::math::AVXVecF64
lam::math::asinh(_In_ const AVXVecF64 &x) {
	return (_mm256_asinh_pd(x));
}

lam::math::AVXVecF64
lam::math::acos(_In_ const AVXVecF64 &x) {
	return (_mm256_acos_pd(x));
}

lam::math::AVXVecF64
lam::math::acosh(_In_ const AVXVecF64 &x) {
	return (_mm256_acosh_pd(x));
}

lam::math::AVXVecF64
lam::math::atan(_In_ const AVXVecF64 &x) {
	return (_mm256_atan_pd(x));
}

lam::math::AVXVecF64
lam::math::atanh(_In_ const AVXVecF64 &x) {
	return (_mm256_atanh_pd(x));
}

lam::math::AVXVecF64
lam::math::atan2(_In_ const AVXVecF64 &x,
			     _In_ const AVXVecF64 &y) {
	return (_mm256_atan2_pd(x,y));
}

lam::math::AVXVecF64
lam::math::fmadd(_In_ const AVXVecF64 &x,
				 _In_ const AVXVecF64 &y,
				 _In_ const AVXVecF64 &z) {
	return (_mm256_fmadd_pd(x,y,z));
}

lam::math::AVXVecF64
lam::math::fmadsubb(_In_ const AVXVecF64 &x,
				    _In_ const AVXVecF64 &y,
				    _In_ const AVXVecF64 &z) {
	return (_mm256_fmaddsub_pd(x,y,z));
}

lam::math::AVXVecF64
lam::math::fmsub(_In_ const AVXVecF64 &x,
				 _In_ const AVXVecF64 &y,
				 _In_ const AVXVecF64 &z) {
	return (_mm256_fmsub_pd(x,y,z));
}

lam::math::AVXVecF64
lam::math::fmsubadd(_In_ const AVXVecF64 &x,
					_In_ const AVXVecF64 &y,
					_In_ const AVXVecF64 &z) {
	return (_mm256_fmsubadd_pd(x,y,z));
}

lam::math::AVXVecF64
lam::math::fnmadd(_In_ const AVXVecF64 &x,
				  _In_ const AVXVecF64 &y,
				  _In_ const AVXVecF64 &z) {
	return (_mm256_fnmadd_pd(x,y,z));
}

lam::math::AVXVecF64
lam::math::fnmsub(_In_ const AVXVecF64 &x,
				  _In_ const AVXVecF64 &y,
				  _In_ const AVXVecF64 &z) {
	return (_mm256_fnmsub_pd(x,y,z));
}

lam::math::AVXVecF64
lam::math::operator+(_In_ const AVXVecF64 &x,
					 _In_ const AVXVecF64 &y) {
	return (_mm256_add_pd(x,y));
}

lam::math::AVXVecF64
lam::math::operator+(_In_ const AVXVecF64 &x,
					 _In_ const double s) {
	return (x + AVXVecF64(s));
}

lam::math::AVXVecF64
lam::math::operator+(_In_ const double s,
					 _In_ const AVXVecF64 &x) {
	return (AVXVecF64(s) + x);
}

lam::math::AVXVecF64
lam::math::operator+=(_In_  AVXVecF64 &x,
					  _In_ const AVXVecF64 &y) {
	x = x + y;
	return (x);
}

lam::math::AVXVecF64
lam::math::operator-(_In_ const AVXVecF64 &x,
					 _In_ const AVXVecF64 &y) {
	return (_mm256_sub_pd(x,y));
}

lam::math::AVXVecF64
lam::math::operator-(_In_ const AVXVecF64 &x,
					 _In_ const double s) {
	return (x - AVXVecF64(s));
}

lam::math::AVXVecF64
lam::math::operator-(_In_ const double s,
					 _In_ const AVXVecF64 &x) {
	return (AVXVecF64(s) - x);
}

lam::math::AVXVecF64
lam::math::operator-=(_In_ AVXVecF64 &x,
					  _In_ const AVXVecF64 &y) {
	x = x - y;
	return (x);
}

lam::math::AVXVecF64
lam::math::operator*(_In_ const AVXVecF64 &x,
					 _In_ const AVXVecF64 &y) {
	return (_mm256_mul_pd(x,y));
}

lam::math::AVXVecF64
lam::math::operator*(_In_ const AVXVecF64 &x,
					 _In_ const double s) {
	return (x * AVXVecF64(s));
}

lam::math::AVXVecF64
lam::math::operator*(_In_ const double s,
					 _In_ const AVXVecF64 &x) {
	return (AVXVecF64(s) * x);
}

lam::math::AVXVecF64
lam::math::operator*=(_In_ AVXVecF64 &x,
					  _In_ const AVXVecF64 &y) {
	x = x * y;
	return (x);
}

lam::math::AVXVecF64
lam::math::operator/(_In_ const AVXVecF64 &x,
				     _In_ const AVXVecF64 &y) {
	return (_mm256_div_pd(x,y));
}

lam::math::AVXVecF64
lam::math::operator/(_In_ const AVXVecF64 &x,
					 _In_ const double s) {
	return (x / AVXVecF64(s));
}

lam::math::AVXVecF64
lam::math::operator/(_In_ const double s,
					 _In_ const AVXVecF64 &x) {
	return (AVXVecF64(s) / x);
}

lam::math::AVXVecF64
lam::math::operator/=(_In_ AVXVecF64 &x,
					  _In_ const AVXVecF64 &y) {
	x = x / y;
	return (x);
}

__m256d
lam::math::operator==(_In_ const AVXVecF64 &x,
					  _In_ const AVXVecF64 &y) {
	return (_mm256_cmp_pd(x,y,_CMP_EQ_OQ));
}

__m256d
lam::math::operator!=(_In_ const AVXVecF64 &x,
				      _In_ const AVXVecF64 &y) {
	return (_mm256_cmp_pd(x,y,_CMP_NEQ_OQ));
}

__m256d
lam::math::operator>(_In_ const AVXVecF64 &x,
					 _In_ const AVXVecF64 &y) {
	return (_mm256_cmp_pd(x,y,_CMP_GT_OQ));
}

__m256d
lam::math::operator<(_In_ const AVXVecF64 &x,
				     _In_ const AVXVecF64 &y) {
	return (_mm256_cmp_pd(x,y,_CMP_LT_OQ));
}

__m256d
lam::math::operator>=(_In_ const AVXVecF64 &x,
					  _In_ const AVXVecF64 &y) {
	return (_mm256_cmp_pd(x, y, _CMP_GE_OQ));
}

__m256d
lam::math::operator<(_In_ const AVXVecF64 &x,
					 _In_ const AVXVecF64 &y) {
	return (_mm256_cmp_pd(x, y, _CMP_LE_OQ));
}

lam::math::AVXVecF64
lam::math::operator&(_In_ const AVXVecF64 &x,
					 _In_ const AVXVecF64 &y) {
	return (_mm256_and_pd(x,y));
}

lam::math::AVXVecF64
lam::math::operator&=(_In_ AVXVecF64 &x,
					  _In_ const AVXVecF64 &y) {
	x = x & y;
	return (x);
}

lam::math::AVXVecF64
lam::math::operator|(_In_ const AVXVecF64 &x,
					 _In_ const AVXVecF64 &y) {
	return (_mm256_or_pd(x,y));
}

lam::math::AVXVecF64
lam::math::operator|=(_In_ AVXVecF64 &x,
					  _In_ const AVXVecF64 &y) {
	x = x | y;
	return (x);
}

lam::math::AVXVecF64
lam::math::operator^(_In_ const AVXVecF64 &x,
					 _In_ const AVXVecF64 &y) {
	return (_mm256_xor_pd(x,y));
}

lam::math::AVXVecF64
lam::math::operator^=(_In_ AVXVecF64 &x,
					  _In_ const AVXVecF64 &y) {
	x = x ^ y;
	return (x);
}

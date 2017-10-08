
//
//	Implementation
//

lam::math::
AVX3VecF64::AVX3VecF64()
:
m_vf64(_mm512_setzero_pd()) {}

lam::math::
AVX3VecF64::AVX3VecF64(_In_ const double v[8])
:
m_vf64(_mm512_loadu_pd(&v[0])) {}

lam::math::
AVX3VecF64::AVX3VecF64(_In_ const double s)
:
m_vf64(_mm512_set1_pd(s)) {}

lam::math::
AVX3VecF64::AVX3VecF64(_In_ const double s0,
					   _In_ const double s1,
					   _In_ const double s2,
					   _In_ const double s3,
					   _In_ const double s4,
					   _In_ const double s5,
					   _In_ const double s6,
					   _In_ const double s7)
:
m_vf64(_mm512_set_pd(s0, s1, s2, s3, s4, s5, s6, s7)) {}

lam::math::
AVX3VecF64::AVX3VecF64(_In_ const __m512d v)
:
m_vf64(v) {}

lam::math::
AVX3VecF64::AVX3VecF64(_In_ const __m512i v)
:
m_vf64(_mm512_castsi512_pd(v)) {}

lam::math::
AVX3VecF64::AVX3VecF64(_In_ const AVX3VecF64 &x)
:
m_vf64(x.m_vf64) {}

lam::math::
AVX3VecF64::AVX3VecF64(_In_ const __m256d v0,
					   _In_ const __m256d v1) {
	m_vf64 = _mm512_insertf64x4(m_vf64,v0,0);
	m_vf64 = _mm512_insertf64x4(m_vf64,v1,1);
}

const __m512d
lam::math::AVX3VecF64::get_vf64() const {
	return (m_vf64);
}

__m512d
lam::math::AVX3VecF64::get_vf64() {
	return (m_vf64);
}

__m256d
lam::math::AVX3VecF64::lo_part() const {
	return (_mm512_extractf64x4_pd(m_vf64,0));
}

__m256d
lam::math::AVX3VecF64::hi_part() const {
	return (_mm512_extractf64x4_pd(m_vf64,1));
}

lam::math::AVX3VecF64 &
lam::math::AVX3VecF64::load_a(_In_ const double* __restrict address) {
	m_vf64 = _mm512_load_pd(address);
	return (*this);
}

lam::math::AVX3VecF64 &
lam::math::AVX3VecF64::load_u(_In_ const double* __restrict address) {
	m_vf64 = _mm512_loadu_pd(address);
	return (*this);
}

void 
lam::math::AVX3VecF64::store_a(_Inout_ double* __restrict dest) const {
	_mm512_store_pd(&dest[0],m_vf64);
}

void
lam::math::AVX3VecF64::store_u(_Inout_ double* __restrict dest) const {
	_mm512_storeu_pd(&dest[0],m_vf64);
}

void
lam::math::AVX3VecF64::stream_store(_Inout_ double* __restrict dest) const {
	_mm512_stream_pd(&dest[0],m_vf64);
}

double
lam::math::AVX3VecF64::extract_scalar(_In_ const uint32_t idx) const {
	__declspec(align(64))double t[8] = {};
	store_a(t);
	return (t[idx&7]);
}

lam::math::AVX3VecF64 &
lam::math::AVX3VecF64::operator=(_In_ const AVX3VecF64 &x) {
	if (this == &x)
		return (*this);
	m_vf64 = x.m_vf64;
	return (*this);
}

lam::math::AVX3VecF64::operator __m512d () const {
	return (m_vf64);
}

double
lam::math::AVX3VecF64::operator[](_In_ const uint32_t idx) const {
	return (reinterpret_cast<const double*>(&m_vf64)[idx]);
}

std::ostream &
lam::math::operator<<(_In_ std::ostream &os,
					  _In_ const AVX3VecF64 &x) {
	for (uint32_t i = 0; i != 7; ++i){
	     os << std::fixed << std::showpoint << 
		 "at position: " << i <<  x[i] << std::endl;
	  }	
	return (os);
}

__m256d
lam::math::extract(_In_ const AVX3VecF64 &x,
				   _In_ const int32_t idx) {
	return (_mm512_extractf64x4_pd(x,idx));
}

lam::math::AVX3VecF64
lam::math::select(_In_ const AVX3VecF64 &x,
				  _In_ const AVX3VecF64 &y,
				  _In_ const __mmask8 pred) {
	return (_mm512_mask_blend_pd(pred,x,y));
}

lam::math::AVX3VecF64
lam::math::max(_In_ const AVX3VecF64 &x,
			   _In_ const AVX3VecF64 &y) {
	return (_mm512_max_pd(x,y));
}

lam::math::AVX3VecF64
lam::math::min(_In_ const AVX3VecF64 &x,
			   _In_ const AVX3VecF64 &y) {
	return (_mm512_min_pd(x,y));
}

lam::math::AVX3VecF64
lam::math::abs(_In_ const AVX3VecF64 &x) {
	return (_mm512_abs_pd(x));
}

lam::math::AVX3VecF64
lam::math::sqrt(_In_ const AVX3VecF64 &x) {
	return (_mm512_sqrt_pd(x));
}

lam::math::AVX3VecF64
lam::math::rsqrt(_In_ const AVX3VecF64 &x) {
	return (_mm512_rsqrt14_pd(x));
}

lam::math::AVX3VecF64
lam::math::cbrt(_In_ const AVX3VecF64 &x) {
	return (_mm512_cbrt_pd(x));
}

double
lam::math::reduce_add(_In_ const AVX3VecF64 &x) {
	return (_mm512_reduce_add_pd(x));
}

double
lam::math::reduce_mul(_In_ const AVX3VecF64 &x) {
	return (_mm512_reduce_mul_pd(x));
}

double
lam::math::reduce_max(_In_ const AVX3VecF64 &x) {
	return (_mm512_reduce_max_pd(x));
}

double
lam::math::reduce_min(_In_ const AVX3VecF64 &x) {
	return (_mm512_reduce_min_pd(x));
}

lam::math::AVX3VecF64
lam::math::ceil(_In_ const AVX3VecF64 &x) {
	return (_mm512_ceil_pd(x));
}

lam::math::AVX3VecF64
lam::math::floor(_In_ const AVX3VecF64 &x) {
	return (_mm512_floor_pd(x));
}

lam::math::AVX3VecF64
lam::math::round(_In_ const AVX3VecF64 &x,
				 _In_ const int32_t imm) {
	return (_mm512_roundscale_pd(x,imm));
}

lam::math::AVX3VecF64
lam::math::sin(_In_ const AVX3VecF64 &x) {
	return (_mm512_sin_pd(x));
}

lam::math::AVX3VecF64
lam::math::sind(_In_ const AVX3VecF64 &x) {
	return (_mm512_sind_pd(x));
}

lam::math::AVX3VecF64
lam::math::cos(_In_ const AVX3VecF64 &x) {
	return (_mm512_cos_pd(x));
}

lam::math::AVX3VecF64
lam::math::cosd(_In_ const AVX3VecF64 &x) {
	return (_mm512_cosd_pd(x));
}

lam::math::AVX3VecF64
lam::math::sinh(_In_ const AVX3VecF64 &x) {
	return (_mm512_sinh_pd(x));
}

lam::math::AVX3VecF64
lam::math::cosh(_In_ const AVX3VecF64 &x) {
	return (_mm512_cosh_pd(x));
}

lam::math::AVX3VecF64
lam::math::tan(_In_ const AVX3VecF64 &x) {
	return (_mm512_tan_pd(x));
}

lam::math::AVX3VecF64
lam::math::tanh(_In_ const AVX3VecF64 &x) {
	return (_mm512_tanh_pd(x));
}

lam::math::AVX3VecF64
lam::math::asin(_In_ const AVX3VecF64 &x) {
	return (_mm512_asin_pd(x));
}

lam::math::AVX3VecF64
lam::math::asinh(_In_ const AVX3VecF64 &x) {
	return (_mm512_asinh_pd(x));
}

lam::math::AVX3VecF64
lam::math::acos(_In_ const AVX3VecF64 &x) {
	return (_mm512_acos_pd(x));
}

lam::math::AVX3VecF64
lam::math::acosh(_In_ const AVX3VecF64 &x) {
	return (_mm512_acosh_pd(x));
}

lam::math::AVX3VecF64
lam::math::atan(_In_ const AVX3VecF64 &x) {
	return (_mm512_atan_pd(x));
}

lam::math::AVX3VecF64
lam::math::atanh(_In_ const AVX3VecF64 &x) {
	return (_mm512_atanh_pd(x));
}

lam::math::AVX3VecF64
lam::math::atan2(_In_ const AVX3VecF64 &x,
				 _In_ const AVX3VecF64 &y) {
	return (_mm512_atan2_pd(x,y));
}

lam::math::AVX3VecF64
lam::math::hypot(_In_ const AVX3VecF64 &x,
				 _In_ const AVX3VecF64 &y) {
	return (_mm512_hypot_pd(x,y));
}

lam::math::AVX3VecF64
lam::math::fmadd(_In_ const AVX3VecF64 &x,
				 _In_ const AVX3VecF64 &y,
				 _In_ const AVX3VecF64 &z) {
	return (_mm512_fmadd_pd(x,y,z));
}

lam::math::AVX3VecF64
lam::math::fmadsubb(_In_ const AVX3VecF64 &x,
				    _In_ const AVX3VecF64 &y,
					_In_ const AVX3VecF64 &z) {
	return (_mm512_fmaddsub_pd(x,y,z));
}

lam::math::AVX3VecF64
lam::math::fmsub(_In_ const AVX3VecF64 &x,
				 _In_ const AVX3VecF64 &y,
				 _In_ const AVX3VecF64 &z) {
	return (_mm512_fmsub_pd(x,y,z));
}

lam::math::AVX3VecF64
lam::math::fmsubadd(_In_ const AVX3VecF64 &x,
					_In_ const AVX3VecF64 &y,
					_In_ const AVX3VecF64 &z) {
	return (_mm512_fmsubadd_pd(x,y,z));
}

lam::math::AVX3VecF64
lam::math::fnmadd(_In_ const AVX3VecF64 &x,
				  _In_ const AVX3VecF64 &y,
				  _In_ const AVX3VecF64 &z) {
	return (_mm512_fnmadd_pd(x,y,z));
}

lam::math::AVX3VecF64
lam::math::fnmsub(_In_ const AVX3VecF64 &x,
				  _In_ const AVX3VecF64 &y,
				  _In_ const AVX3VecF64 &z) {
	return (_mm512_fnmsub_pd(x,y,z));
}

lam::math::AVX3VecF64
lam::math::operator+(_In_ const AVX3VecF64 &x,
					 _In_ const AVX3VecF64 &y) {
	return (_mm512_add_pd(x,y));
}

lam::math::AVX3VecF64
lam::math::operator+(_In_ const AVX3VecF64 &x,
					 _In_ const double s) {
	return (x + AVX3VecF64(s));
}

lam::math::AVX3VecF64
lam::math::operator+(_In_ const double s,
					 _In_ const AVX3VecF64 &x) {
	return (AVX3VecF64{s} + x);
}

lam::math::AVX3VecF64
lam::math::operator+=(_In_  AVX3VecF64 &x,
					  _In_ const AVX3VecF64 &y) {
	x = x + y;
	return (x);
}

lam::math::AVX3VecF64
lam::math::operator-(_In_ const AVX3VecF64 &x,
					 _In_ const AVX3VecF64 &y) {
	return (_mm512_sub_pd(x,y));
}

lam::math::AVX3VecF64
lam::math::operator-(_In_ const AVX3VecF64 &x,
					 _In_ const double s) {
	return (x - AVX3VecF64{s});
}

lam::math::AVX3VecF64
lam::math::operator-(_In_ const double s,
					 _In_ const AVX3VecF64 &x) {
	return (AVX3VecF64{s} - x);
}

lam::math::AVX3VecF64
lam::math::operator-=(_In_		 AVX3VecF64 &x,
					  _In_ const AVX3VecF64 &y) {
	x = x - y;
	return (x);
}

lam::math::AVX3VecF64
lam::math::operator*(_In_ const AVX3VecF64 &x,
					 _In_ const AVX3VecF64 &y) {
	return (_mm512_mul_pd(x,y));
}

lam::math::AVX3VecF64
lam::math::operator*(_In_ const AVX3VecF64 &x,
					 _In_ const double s) {
	return (x * AVX3VecF64{s});
}

lam::math::AVX3VecF64
lam::math::operator*(_In_ const double s,
					 _In_ const AVX3VecF64 &x) {
	return (AVX3VecF64{s} * x);
}

lam::math::AVX3VecF64
lam::math::operator*=(_In_  AVX3VecF64 &x,
					  _In_ const AVX3VecF64 &y) {
	x = x * y;
	return (x);
}

lam::math::AVX3VecF64
lam::math::operator/(_In_ const AVX3VecF64 &x,
					 _In_ const AVX3VecF64 &y) {
	return (_mm512_div_pd(x,y));
}

lam::math::AVX3VecF64
lam::math::operator/(_In_ const AVX3VecF64 &x,
					 _In_ const double s) {
	return (x / AVX3VecF64{s});
}

lam::math::AVX3VecF64
lam::math::operator/(_In_ const double s,
					 _In_ const AVX3VecF64 &x) {
	return (AVX3VecF64{s} / x);
}

lam::math::AVX3VecF64
lam::math::operator/=(_In_       AVX3VecF64 &x,
					  _In_ const AVX3VecF64 &y) {
	x = x / y;
	return (x);
}

__mmask8
lam::math::operator==(_In_ const AVX3VecF64 &x,
					  _In_ const AVX3VecF64 &y) {
	return (_mm512_cmp_pd_mask(x,y,_CMP_EQ_OQ));
}

__mmask8
lam::math::operator!=(_In_ const AVX3VecF64 &x,
					  _In_ const AVX3VecF64 &y) {
	return (_mm512_cmp_pd_mask(x,y,_CMP_NEQ_OQ));
}

__mmask8
lam::math::operator>(_In_ const AVX3VecF64 &x,
					 _In_ const AVX3VecF64 &y) {
	return (_mm512_cmp_pd_mask(x,y,_CMP_GT_OQ));
}

__mmask8
lam::math::operator<(_In_ const AVX3VecF64 &x,
					 _In_ const AVX3VecF64 &y) {
	return (_mm512_cmp_pd_mask(x,y,_CMP_LT_OQ));
}

__mmask8
lam::math::operator>=(_In_ const AVX3VecF64 &x,
					  _In_ const AVX3VecF64 &y) {
	return (_mm512_cmp_pd_mask(x,y,_CMP_GE_OQ));
}

__mmask8
lam::math::operator<=(_In_ const AVX3VecF64 &x,
					 _In_ const AVX3VecF64 &y) {
	return (_mm512_cmp_pd_mask(x,y,_CMP_LE_OQ));
}

lam::math::AVX3VecF64
lam::math::operator&(_In_ const AVX3VecF64 &x,
					 _In_ const AVX3VecF64 &y) {
	return (_mm512_and_pd(x,y));
}

lam::math::AVX3VecF64
lam::math::operator&=(_In_ AVX3VecF64 &x,
					  _In_ const AVX3VecF64 &y) {
	x = x & y;
	return (x);
}

lam::math::AVX3VecF64
lam::math::operator|(_In_ const AVX3VecF64 &x,
					 _In_ const AVX3VecF64 &y) {
	return (_mm512_or_pd(x,y));
}

lam::math::AVX3VecF64
lam::math::operator|=(_In_ AVX3VecF64 &x,
					  _In_ const AVX3VecF64 &y) {
	x = x | y;
	return (x);
}

lam::math::AVX3VecF64
lam::math::operator^(_In_ const AVX3VecF64 &x,
					 _In_ const AVX3VecF64 &y) {
	return (_mm512_xor_pd(x,y));
}

lam::math::AVX3VecF64
lam::math::operator^=(_In_ AVX3VecF64 &x,
					  _In_ const AVX3VecF64 &y) {
	x = x ^ y;
	return (x);
}

lam::math::AVX3VecF64
lam::math::operator++(_In_ AVX3VecF64 &x) {
	x = x + 1.0;
	return (x);
}

lam::math::AVX3VecF64
lam::math::operator--(_In_ AVX3VecF64 &x) {
	x = x - 1.0;
	return (x);
}
			   
		


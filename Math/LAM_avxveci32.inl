
//
//	Implementation
//

lam::math::
AVXVecI32::AVXVecI32() :
m_vi32(_mm256_set1_epi32(0)) {}

lam::math::
AVXVecI32::AVXVecI32(_In_ const int32_t a[8]) :
m_vi32(_mm256_loadu_si256(reinterpret_cast<const __m256i*>(&a[0]))) {}

lam::math::
AVXVecI32::AVXVecI32(_In_ const int32_t x) :
m_vi32(_mm256_set1_epi32(x)) {}

lam::math::
AVXVecI32::AVXVecI32(_In_ const int32_t s0,
				     _In_ const int32_t s1,
                     _In_ const int32_t s2,
					 _In_ const int32_t s3,
					 _In_ const int32_t s4,
					 _In_ const int32_t s5,
					 _In_ const int32_t s6,
					 _In_ const int32_t s7) :
m_vi32(_mm256_setr_epi32(s0, s1, s2, s3, s4, s5, s6, s7)) {}

lam::math::
AVXVecI32::AVXVecI32(_In_ const __m256 &v) :
m_vi32(_mm256_cvtps_epi32(v)) {}

lam::math::
AVXVecI32::AVXVecI32(_In_ const __m256i &v) :
m_vi32(v) {}

lam::math::
AVXVecI32::AVXVecI32(_In_ const AVXVecI32 &x) :
m_vi32(x.m_vi32) {}

lam::math::
AVXVecI32::AVXVecI32(_In_ __m128i const* __restrict lo,
					  _In_ __m128i const* __restrict hi) :
m_vi32(_mm256_loadu2_m128i(lo, hi)) {}

const __m256i
lam::math::AVXVecI32::get_vi32() const {
	return (m_vi32);
}

__m256i
lam::math::AVXVecI32::get_vi32() {
	return (m_vi32);
}

__m128i
lam::math::AVXVecI32::get_lo() const {
	return (_mm256_extractf128_si256(m_vi32,0));
}

__m128i
lam::math::AVXVecI32::get_hi() const {
	return (_mm256_extractf128_si256(m_vi32,1));
}

lam::math::AVXVecI32 &
lam::math::AVXVecI32::load_a(_In_ const void* __restrict mem) {
	m_vi32 = _mm256_load_si256(reinterpret_cast<const __m256i*>(mem));
	return (*this);
}

lam::math::AVXVecI32 &
lam::math::AVXVecI32::load_u(_In_ const void* __restrict mem) {
	m_vi32 = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(mem));
	return (*this);
}

void
lam::math::AVXVecI32::store_a(_In_ void* __restrict mem) const {
	_mm256_store_si256(reinterpret_cast< __m256i*>(mem),m_vi32);
}

void 
lam::math::AVXVecI32::store_u(_In_ void* __restrict mem) const {
	_mm256_storeu_si256(reinterpret_cast<__m256i*>(mem),m_vi32);
}

void
lam::math::AVXVecI32::stream_store(_In_ void* __restrict mem) const {
	_mm256_stream_si256(reinterpret_cast<__m256i*>(mem),m_vi32);
}

int32_t
lam::math::AVXVecI32::extract_scalar(_In_ const uint32_t idx) const {
	__declspec(align(32)) int32_t a[8] = {0};
	store_a(a);
	return a[idx & 7];
}

lam::math::AVXVecI32 &
lam::math::AVXVecI32::operator=(_In_ const AVXVecI32 &x) {
	if (this == &x) return (*this);
	m_vi32 = x.m_vi32;
	return (*this);
}

lam::math::AVXVecI32::operator __m256i () const {
	return (m_vi32);
}

int32_t
lam::math::AVXVecI32::operator[](_In_ const uint32_t idx) const {
	return (reinterpret_cast<const int32_t*>(&m_vi32)[idx]);
}

std::ostream &
lam::math::operator<<(_In_ std::ostream &os,
					  _In_ const AVXVecI32 &x) {
	const char *data[8] = { "s0", "s1", "s2", "s3", "s4", 
						    "s5", "s6", "s7" };
	for (uint32_t i = 0; i != 8; ++i)
		os << data[i] << x.operator[](i) << "\n";
	return (os);
}

__m128i
lam::math::extract( _In_ AVXVecI32 &x,
					_In_ const uint32_t idx) {
	return (_mm256_extracti128_si256(x,idx));
}

lam::math::AVXVecI32
lam::math::select(_In_ const AVXVecI32 &a,
				  _In_ const AVXVecI32 &b,
				  _In_ const int32_t pred) {
	return (_mm256_blend_epi32(a,b,pred));
}

lam::math::AVXVecI32
lam::math::broadcast(_In_ const AVXVecI32 &x) {
	return (_mm256_broadcastsi128_si256(extract(const_cast<lam::math::AVXVecI32&>(x),0)));
}

lam::math::AVXVecI32
lam::math::permute(_In_ const AVXVecI32 &a,
				   _In_ const AVXVecI32 &b){
				    
	return (_mm256_permutevar8x32_epi32(a,b));
}

lam::math::AVXVecI32
lam::math::abs(_In_ const AVXVecI32 &x) {
	return (_mm256_abs_epi32(x));
}

lam::math::AVXVecI32
lam::math::hadd(_In_ const AVXVecI32 &x,
				_In_ const AVXVecI32 &y) {
	return (_mm256_hadd_epi32(x,y));
}

lam::math::AVXVecI32
lam::math::hsub(_In_ const AVXVecI32 &x,
			    _In_ const AVXVecI32 &y) {
	return (_mm256_hsub_epi32(x,y));
}

lam::math::AVXVecI32
lam::math::max(_In_ const AVXVecI32 &x,
			   _In_ const AVXVecI32 &y) {
	return (_mm256_max_epi32(x,y));
}

lam::math::AVXVecI32
lam::math::min(_In_ const AVXVecI32 &x,
			   _In_ const AVXVecI32 &y) {
	return (_mm256_min_epi32(x,y));
}

lam::math::AVXVecI32
lam::math::sign(_In_ const AVXVecI32 &x,
				_In_ const AVXVecI32 &y) {
	return (_mm256_sign_epi32(x,y));
}

lam::math::AVXVecI32
lam::math::operator+(_In_ const AVXVecI32 &x,
					 _In_ const AVXVecI32 &y) {
	return (_mm256_add_epi32(x,y));
}

lam::math::AVXVecI32
lam::math::operator+(_In_ const AVXVecI32 &x,
					 _In_ const int32_t y) {
	return (x + AVXVecI32{y});
}

lam::math::AVXVecI32
lam::math::operator+(_In_ const int32_t x,
					 _In_ const AVXVecI32 &y) {
	return (AVXVecI32{x} + y);
}

lam::math::AVXVecI32
lam::math::operator+=(_In_ AVXVecI32 &x,
					  _In_ const AVXVecI32 &y) {
	x = x+y;
	return (x);
}

lam::math::AVXVecI32
lam::math::operator-(_In_ const AVXVecI32 &x,
					 _In_ const AVXVecI32 &y) {
	return (_mm256_sub_epi32(x,y));
}

lam::math::AVXVecI32
lam::math::operator-(_In_ const AVXVecI32 &x,
					 _In_ const int32_t y) {
	return (x - AVXVecI32{y});
}

lam::math::AVXVecI32
lam::math::operator-(_In_ const int32_t x,
					 _In_ const AVXVecI32 &y) {
	return (AVXVecI32{x} - y);
}

lam::math::AVXVecI32
lam::math::operator-=(_In_ AVXVecI32 &x,
					  _In_ const AVXVecI32 &y) {
	x = x - y;
	return (x);
}

lam::math::AVXVecI32
lam::math::operator*(_In_ const AVXVecI32 &x,
					 _In_ const AVXVecI32 &y) {
	return (_mm256_mul_epi32(x,y));
}

lam::math::AVXVecI32
lam::math::operator*(_In_ const AVXVecI32 &x,
					 _In_ const int32_t y) {
	return (x * AVXVecI32{y});
}

lam::math::AVXVecI32
lam::math::operator*(_In_ const int32_t x,
					  _In_ const AVXVecI32 &y) {
	return (AVXVecI32{x} * y);
}

lam::math::AVXVecI32
lam::math::operator*=(_In_ AVXVecI32 &x,
					  _In_ const AVXVecI32 &y) {
	x = x * y;
	return (x);
}

lam::math::AVXVecI32
lam::math::operator/(_In_ const AVXVecI32 &x,
				     _In_ const AVXVecI32 &y) {
	return (_mm256_div_epi32(x,y));
}

lam::math::AVXVecI32
lam::math::operator/(_In_ const AVXVecI32 &x,
					 _In_ const int32_t y) {
	return (x / AVXVecI32{x});
}

lam::math::AVXVecI32
lam::math::operator/(_In_ const int32_t x,
				     _In_ const AVXVecI32 &y) {
	return (AVXVecI32{x} / y);
}

lam::math::AVXVecI32
lam::math::operator/=(_In_ AVXVecI32 &x,
_In_ const AVXVecI32 &y) {
	x = x / y;
	return (x);
}

lam::math::AVXVecI32
lam::math::operator--(_In_ AVXVecI32 &x) {
	x = _mm256_sub_epi32(x, _mm256_set1_epi32(1));
	return (x);
}

lam::math::AVXVecI32
lam::math::operator++(_In_ AVXVecI32 &x) {
	x = _mm256_add_epi32(x, _mm256_set1_epi32(1));
	return (x);
}

lam::math::AVXVecI32
lam::math::operator>>(_In_ const AVXVecI32 &x,
_In_ const AVXVecI32 &y) {
	return (_mm256_srlv_epi32(x, y));
}

lam::math::AVXVecI32
lam::math::operator>>(_In_ const AVXVecI32 &x,
_In_ const uint32_t y) {
	return (_mm256_srli_epi32(x, y));
}

lam::math::AVXVecI32
lam::math::operator>>=(_In_ AVXVecI32 &x,
_In_ const AVXVecI32 &y) {
	x = x >> y;
	return (x);
}

lam::math::AVXVecI32
lam::math::operator>>=(_In_ AVXVecI32 &x,
_In_ const uint32_t y) {
	x = x >> y;
	return (x);
}

lam::math::AVXVecI32
lam::math::operator<<(_In_ const AVXVecI32 &x,
_In_ const AVXVecI32 &y) {
	return (_mm256_sllv_epi32(x, y));
}

lam::math::AVXVecI32
lam::math::operator<<(_In_ const AVXVecI32 &x,
_In_ const uint32_t y) {
	return (_mm256_slli_epi32(x, y));
}

lam::math::AVXVecI32
lam::math::operator<<=(_In_ AVXVecI32 &x,
_In_ const AVXVecI32 &y) {
	x = x << y;
	return (x);
}

lam::math::AVXVecI32
lam::math::operator<<=(_In_ AVXVecI32 &x,
_In_ const uint32_t y) {
	x = x << y;
	return (x);
}

__mmask8
lam::math::operator!=(_In_ const AVXVecI32 &x,
_In_ const AVXVecI32 &y) {
	return (_mm256_cmpneq_epi32_mask(x, y));
}

__mmask8
lam::math::operator!=(_In_ const AVXVecI32 &x,
					  _In_ const int32_t y) {
	return (x != AVXVecI32{ y });
}

__mmask8
lam::math::operator==(_In_ const AVXVecI32 &x,
					  _In_ const AVXVecI32 &y) {
	return (_mm256_cmpeq_epi32_mask(x, y));
}

__mmask8
lam::math::operator==(_In_ const AVXVecI32 &x,
					  _In_ const int32_t y) {
	return (x == AVXVecI32{y});
}

__mmask8
lam::math::operator>(_In_ const AVXVecI32 &x,
					 _In_ const AVXVecI32 &y) {
	return (_mm256_cmpgt_epi32_mask(x, y));
}

__mmask8
lam::math::operator>(_In_ const AVXVecI32 &x,
					 _In_ const int32_t y) {
	return (x > AVXVecI32{y});
}

__mmask8
lam::math::operator<(_In_ const AVXVecI32 &x,
					 _In_ const AVXVecI32 &y) {
	return (_mm256_cmplt_epi32_mask(x,y));
}

__mmask8
lam::math::operator<(_In_ const AVXVecI32 &x,
				      _In_ const int32_t y) {
	return (x < AVXVecI32{y});
}

lam::math::AVXVecI32
lam::math::operator&(_In_ const AVXVecI32 &x,
					 _In_ const AVXVecI32 &y) {
	return (_mm256_and_si256(x,y));
}

lam::math::AVXVecI32
lam::math::operator&=(_In_ AVXVecI32 &x,
					  _In_ const AVXVecI32 &y) {
	x = x & y;
	return (x);
}

lam::math::AVXVecI32
lam::math::operator|(_In_ const AVXVecI32 &x,
				     _In_ const AVXVecI32 &y) {
	return (_mm256_or_si256(x, y));
}

lam::math::AVXVecI32
lam::math::operator|=(_In_ AVXVecI32 &x,
					  _In_ const AVXVecI32 &y) {
	x = x | y;
	return (x);
}

lam::math::AVXVecI32
lam::math::operator^(_In_ const AVXVecI32 &x,
					 _In_ const AVXVecI32 &y) {
	return (_mm256_xor_si256(x, y));
}

lam::math::AVXVecI32
lam::math::operator^=(_In_ AVXVecI32 &x,
					  _In_ const AVXVecI32 &y) {
	x = x ^ y;
	return (x);
}


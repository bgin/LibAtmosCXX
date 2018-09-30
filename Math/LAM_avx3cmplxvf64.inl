
const lam::math::AVX3C8f64
lam::math::AVX3C8f64::CZERO = AVX3C8f64{};

lam::math::AVX3C8f64
::AVX3C8f64() {
	m_re = _mm512_setzero_pd();
	m_im = _mm512_setzero_pd();
}

lam::math::AVX3C8f64
::AVX3C8f64(_In_ const AVX3C8Payload &x) {
	m_re = _mm512_set_pd(x.re0, x.re1, x.re2, x.re3, x.re4, x.re5, x.re6, x.re7);
	m_im = _mm512_set_pd(x.im0, x.im1, x.im2, x.im3, x.im4, x.im5, x.im6, x.im7);
}

lam::math::AVX3C8f64
::AVX3C8f64(_In_ const double * __restrict Re,
		    _In_ const double * __restrict Im) {
	m_re = _mm512_load_pd(&Re[0]);
	m_im = _mm512_load_pd(&Im[0]);
}

lam::math::AVX3C8f64
::AVX3C8f64(_In_ const double re,
			_In_ const double im) {
	m_re = _mm512_set1_pd(re);
	m_im = _mm512_set1_pd(im);
}

lam::math::AVX3C8f64
::AVX3C8f64(_In_ const double c) {
	m_re = _mm512_set1_pd(c);
	m_im = _mm512_setzero_pd();
}

lam::math::AVX3C8f64
::AVX3C8f64(_In_ const double re0,
			_In_ const double re1,
		    _In_ const double re2,
			_In_ const double re3,
			_In_ const double re4,
			_In_ const double re5,
			_In_ const double re6,
			_In_ const double re7) {
	m_re = _mm512_set_pd(re0, re1, re2, re3, re4, re5, re6, re7);
	m_im = _mm512_setzero_pd();
}

lam::math::AVX3C8f64
::AVX3C8f64(_In_ const __m512d &re,
		   _In_ const __m512d &im) {
	m_re = re;
	m_im = im;
}

lam::math::AVX3C8f64
::AVX3C8f64(_In_ const AVX3C8f64 &x) {
	m_re = x.m_re;
	m_im = x.m_im;
}

lam::math::AVX3C8f64 &
lam::math::AVX3C8f64::load_a(_In_ const double * __restrict Re,
							 _In_ const double * __restrict Im) {
	m_re = _mm512_load_pd(&Re[0]);
	m_im = _mm512_load_pd(&Im[0]);
	return (*this);
}

lam::math::AVX3C8f64 &
lam::math::AVX3C8f64::load_u(_In_ const double * __restrict Re,
							 _In_ const double * __restrict Im) {
	m_re = _mm512_loadu_pd(&Re[0]);
	m_im = _mm512_loadu_pd(&Im[0]);
	return (*this);
}

void 
lam::math::AVX3C8f64::store_a(_Out_ double * __restrict Re,
							  _Out_ double * __restrict Im) const {
	_mm512_store_pd(&Re[0], m_re);
	_mm512_store_pd(&Im[0], m_im);
}

void 
lam::math::AVX3C8f64::store_u(_Out_ double * __restrict Re,
							  _Out_ double * __restrict Im) const {
	_mm512_storeu_pd(&Re[0], m_re);
	_mm512_storeu_pd(&Im[0], m_im);
}

void 
lam::math::AVX3C8f64::stream(_Out_ double * __restrict Re,
						     _Out_ double * __restrict Im) const {
	_mm512_stream_pd(&Re[0], m_re);
	_mm512_stream_pd(&Im[0], m_im);
	_mm_sfence();
}

double 
lam::math::AVX3C8f64::extract_f64(_In_ const int32_t idx) const {
	__declspec(align(64)) double mem[16] = {};
	store_a(&mem[0], &mem[8]);
	return (mem[idx & 0xF]);
}

std::pair<double, double>
lam::math::AVX3C8f64::extract_2f64(_In_ const int32_t re_idx,
								   _In_ const int32_t im_idx) {
	__declspec(align(64)) double re_mem[8] = {};
	__declspec(align(64)) double im_mem[8] = {};
	store_a(&re_mem[0], &im_mem[0]);
	return (std::make_pair(re_mem[re_idx & 0x7], im_mem[im_idx & 0x7]));
}

lam::math::AVX3C8f64 & 
lam::math::AVX3C8f64::insert_1f64(_In_ const int32_t idx,
							      _In_ const double val) {
	__declspec(align(64)) double mem[16] = {};
	store_a(&mem[0], &mem[8]);
	mem[idx & 0xF] = val;
	load_a(&mem[0], &mem[8]);
	return (*this);
}

lam::math::AVX3C8f64 & 
lam::math::AVX3C8f64::insert_2f64(_In_ const int32_t re_idx,
								  _In_ const int32_t im_idx,
								  _In_ const double re,
								  _In_ const double im) {
	__declspec(align(64)) double mem_re[8] = {};
	__declspec(align(64)) double mem_im[8] = {};
	store_a(&mem_re[0], &mem_im[0]);
	mem_re[re_idx & 0x7] = re;
	mem_im[im_idx & 0x7] = im;
	load_a(&mem_re[0], &mem_im[0]);
	return (*this);
}

// Length of 16 doubles
void 
lam::math::AVX3C8f64
::concatenate_a(_Out_ double * __restrict out) const {
	store_a(&out[0], &out[8]);
}

// Length of 16 doubles
void 
lam::math::AVX3C8f64
::concatenate_u(_Out_ double * __restrict out) const {
	store_u(&out[0], &out[8]);
}

lam::math::AVX3C8f64 &
lam::math::AVX3C8f64
::partial_loadu(_In_ const double * __restrict Re,
			    _In_ const int32_t n_re,
				_In_ const double * __restrict Im,
				_In_ const int32_t n_im) {
	m_re = _mm512_maskz_loadu_pd(__mmask8((1 << n_re)-1),Re);
	m_im = _mm512_maskz_loadu_pd(__mmask8((1 << n_im)-1),Im);
	return (*this);
}

lam::math::AVX3C8f64 &
lam::math::AVX3C8f64
::partial_loada(_In_ const double * __restrict Re,
				_In_ const int32_t n_re,
				_In_ const double * __restrict Im,
				_In_ const int32_t n_im) {
	m_re = _mm512_maskz_load_pd(__mmask8((1 << n_re) - 1), Re);
	m_im = _mm512_maskz_load_pd(__mmask8((1 << n_im) - 1), Im);
	return (*this);
}

void
lam::math::AVX3C8f64
::partial_storeu(_Out_ double * __restrict Re,
				 _In_ const int32_t n_re,
				 _Out_ double * __restrict Im,
				 _In_ const int32_t n_im) {
	_mm512_mask_storeu_pd(&Re[0],__mmask8((1<<n_re)-1),m_re);
	_mm512_mask_storeu_pd(&Im[0],__mmask8((1<<n_im)-1),m_im);
}

void
lam::math::AVX3C8f64
::partial_storea(_Out_ double * __restrict Re,
				 _In_ const int32_t n_re,
				 _Out_ double * __restrict Im,
				 _In_ const int32_t n_im) {
	_mm512_mask_store_pd(&Re[0], __mmask8((1 << n_re) - 1), m_re);
	_mm512_mask_store_pd(&Im[0], __mmask8((1 << n_im) - 1), m_im);
}

lam::math::AVX3C8f64 & 
lam::math::AVX3C8f64
::expand(_In_ const AVX3C8f64 &x,
		 _In_ const __mmask8 mask) {
	m_re = _mm512_maskz_expand_pd(mask, x.m_re);
	m_im = _mm512_maskz_expand_pd(mask, x.m_im);
	return (*this);
}

lam::math::AVX3C8f64 & 
lam::math::AVX3C8f64
::expand_load(_In_ const AVX3C8f64 &x,
			  _In_ const __mmask8 mask,
			  _In_ const double * __restrict re,
			  _In_ const double * __restrict im) {
	m_re = _mm512_mask_expandloadu_pd(x.m_re, mask, &re[0]);
	m_im = _mm512_mask_expandloadu_pd(x.m_im, mask, &im[0]);
	return (*this);
}

lam::math::AVX3C8f64 & 
lam::math::AVX3C8f64
::permute(_In_ const __mmask8 mask,
		  _In_ const int32_t imm) {
	m_re = _mm512_mask_permute_pd(m_re, mask, m_im, imm);
	m_im = _mm512_mask_permute_pd(m_im, mask, m_re, imm);
	return (*this);
}

__m256d 
lam::math::AVX3C8f64::re_low2() const {
	return (_mm512_extractf64x4_pd(m_re, 0));
}



__m256d 
lam::math::AVX3C8f64::re_hi2() const {
	return (_mm512_extractf64x4_pd(m_re, 1));
}

__m256d 
lam::math::AVX3C8f64::im_low2() const {
	return (_mm512_extractf64x4_pd(m_im, 0));
}

__m256d 
lam::math::AVX3C8f64::im_hi2() const {
	return (_mm512_extractf64x4_pd(m_im, 1));
}

lam::math::AVX3C8f64 & 
lam::math::AVX3C8f64
::operator=(_In_ const AVX3C8f64 &x) {
	if (this == &x) { return (*this); }
	m_re = x.m_re;
	m_im = x.m_im;
	return (*this);
}

static inline lam::math::AVX3C8f64
lam::math::csin(_In_ const AVX3C8f64 &x) {
	const __m512d re_part =
		_mm512_mul_pd(_mm512_sin_pd(x.m_re),
		_mm512_cosh_pd(x.m_im));
	const __m512d im_part =
		_mm512_mul_pd(_mm512_cos_pd(x.m_re),
		_mm512_sinh_pd(x.m_im));
	return (AVX3C8f64{ re_part, im_part });
}

static inline lam::math::AVX3C8f64
lam::math::ccos(_In_ const AVX3C8f64 &x) {
	const __m512d re_part =
		_mm512_mul_pd(_mm512_cos_pd(x.m_re),
		_mm512_cosh_pd(x.m_im));
	const __m512d im_part =
		_mm512_mul_pd(_mm512_sin_pd(x.m_re),
		_mm512_sinh_pd(x.m_im));
	
	return (AVX3C8f64{ re_part, im_part });
}

static inline lam::math::AVX3C8f64
lam::math::cexp(_In_ const AVX3C8f64 &x) {
	const __m512d re_part =
		_mm512_mul_pd(_mm512_exp_pd(x.m_re),
		_mm512_cos_pd(x.m_im));
	const __m512d im_part =
		_mm512_mul_pd(_mm512_exp_pd(x.m_re),
		_mm512_sin_pd(x.m_im));

	return (AVX3C8f64{ re_part, im_part });
}

static inline lam::math::AVX3C8f64
lam::math::cabs(_In_ const AVX3C8f64 &x) {
	const __m512d re_part =
		_mm512_mul_pd(x.m_re, x.m_re);
	const __m512d im_part =
		_mm512_mul_pd(x.m_im, x.m_im);
	return (AVX3C8f64{ _mm512_sqrt_pd(_mm512_add_pd(re_part, im_part)),
									  _mm512_setzero_pd() });
}

static inline lam::math::AVX3C8f64
lam::math::cpowi(_In_ const AVX3C8f64 &x,
_In_ const double n) {
	const __m512d re_part =
		_mm512_mul_pd(x.m_re, x.m_re);
	const __m512d im_part =
		_mm512_mul_pd(x.m_im, x.m_im);
	const __m512d r =
		_mm512_sqrt_pd(_mm512_add_pd(re_part, im_part));
	const __m512d theta =
		_mm512_atan_pd(_mm512_div_pd(x.m_im, x.m_re));
	const __m512d vn = _mm512_set1_pd(n);
	const __m512d pow_term = _mm512_pow_pd(r, vn);
	const __m512d trig_arg = _mm512_mul_pd(vn, theta);
	return (AVX3C8f64{ _mm512_mul_pd(pow_term, _mm512_cos_pd(trig_arg)),
		_mm512_mul_pd(pow_term, _mm512_sin_pd(trig_arg)) });
}

static inline lam::math::AVX3C8f64
lam::math::select(_In_ const AVX3C8f64 &x,
			      _In_ const AVX3C8f64 &y,
			      _In_ const __mmask8 mask) {

	return (AVX3C8f64{ _mm512_mask_blend_pd(mask, x.m_re, y.m_re),
		_mm512_mask_blend_pd(mask, x.m_im, y.m_im) });
}

static inline lam::math::AVX3C8f64
lam::math::operator+(_In_ const AVX3C8f64 &x,
					 _In_ const AVX3C8f64 &y) {
	return (AVX3C8f64{ _mm512_add_pd(x.m_re, y.m_re),
		_mm512_add_pd(x.m_im, y.m_im) });
}

static inline lam::math::AVX3C8f64
lam::math::operator+(_In_ const AVX3C8f64 &x,
					 _In_ const double s) {
	return (x + AVX3C8f64{ s });
}

static inline lam::math::AVX3C8f64
lam::math::operator+(_In_ const double s,
					 _In_ const AVX3C8f64 &x) {
	return (AVX3C8f64{ s } +x);
}

static inline lam::math::AVX3C8f64
lam::math::operator+=(_In_ AVX3C8f64 &x,
					  _In_ const AVX3C8f64 &y) {
	x = x + y;
	return (x);
}

static inline lam::math::AVX3C8f64
lam::math::operator+=(_In_ AVX3C8f64 &x,
					   _In_ const double s) {
	x = x + AVX3C8f64{s};
	return (x);
}

static inline lam::math::AVX3C8f64
lam::math::operator+=(_In_ const double s,
					  _In_ AVX3C8f64 &x) {
	x = AVX3C8f64{s} + x;
	return (x);
}

static inline lam::math::AVX3C8f64
lam::math::operator-(_In_ const AVX3C8f64 &x,
					  _In_ const AVX3C8f64 &y) {
	return (AVX3C8f64{ _mm512_sub_pd(x.m_re, y.m_re),
		_mm512_sub_pd(x.m_im, y.m_im) });
}

static inline lam::math::AVX3C8f64
lam::math::operator-(_In_ const AVX3C8f64 &x,
					 _In_ const double s) {
	return (x - AVX3C8f64{ s });
}

static inline lam::math::AVX3C8f64
lam::math::operator-(_In_ const double s,
					 _In_ const AVX3C8f64 &x) {
	return(AVX3C8f64{ s } - x);
}

static inline lam::math::AVX3C8f64
lam::math::operator-(_In_  AVX3C8f64 &x) {
	x =  lam::math::AVX3C8f64::CZERO - x; 
	return (x);
}

static inline lam::math::AVX3C8f64
lam::math::operator-=(_In_ AVX3C8f64 &x,
					  _In_ const AVX3C8f64 &y) {
	x = x - y;
	return (x);
}

static inline lam::math::AVX3C8f64
lam::math::operator-=(_In_ AVX3C8f64 &x,
					  _In_ const double s) {
	x = x - AVX3C8f64{s};
	return (x);
}

static inline lam::math::AVX3C8f64
lam::math::operator-=(_In_ const double s,
					  _In_ AVX3C8f64 &x) {
	x = AVX3C8f64{s} - x;
	return (x);
}

static inline lam::math::AVX3C8f64
lam::math::operator*(_In_ const AVX3C8f64 &x,
				     _In_ const AVX3C8f64 &y) {
	const __m512d ymm0(_mm512_mul_pd(x.m_re,y.m_re));
	const __m512d ymm1(_mm512_mul_pd(x.m_im,y.m_im));
	const __m512d ymm2(_mm512_mul_pd(x.m_im,y.m_re));
	const __m512d ymm3(_mm512_mul_pd(x.m_re, y.m_im));
	return (AVX3C8f64{ _mm512_sub_pd(ymm0,ymm1),
					    _mm512_add_pd(ymm2,ymm3) });
}

static inline lam::math::AVX3C8f64
lam::math::operator*(_In_ const AVX3C8f64 &x,
					 _In_ const double s) {
	const __m512d zmm0(_mm512_set1_pd(s));
	return (AVX3C8f64{_mm512_mul_pd(x.m_re,zmm0),
				      _mm512_mul_pd(x.m_im,zmm0)});
}

static inline lam::math::AVX3C8f64
lam::math::operator*(_In_ const double s,
					 _In_ const AVX3C8f64 &x) {
	const __m512d zmm0(_mm512_set1_pd(s));
	return (AVX3C8f64{ _mm512_mul_pd(zmm0,x.m_re),
					   _mm512_mul_pd(zmm0,x.m_im) });
}

static inline lam::math::AVX3C8f64
lam::math::operator*=(_In_ AVX3C8f64 &x,
					  _In_ const AVX3C8f64 &y) {
	x = x * y;
	return (x);
}

static inline lam::math::AVX3C8f64
lam::math::operator*=(_In_ AVX3C8f64 &x,
					  _In_ const double s) {
	const __m512d zmm0(_mm512_set1_pd(s));
	x = x * s;
	return (x);
}

static inline lam::math::AVX3C8f64
lam::math::operator*=(_In_ const double s,
					  _In_ AVX3C8f64 &x) {
	x = s * x;
	return (x);
}

static inline lam::math::AVX3C8f64
lam::math::operator/(_In_ const AVX3C8f64 &x,
					 _In_ const AVX3C8f64 &y) {
	const __m512d ymm0(_mm512_mul_pd(x.m_re, y.m_re));
	const __m512d ymm1(_mm512_mul_pd(x.m_im, y.m_im));
	const __m512d ymm2(_mm512_mul_pd(x.m_im, y.m_re));
	const __m512d ymm3(_mm512_mul_pd(x.m_re, y.m_im));
	const __m512d den(_mm512_add_pd(_mm512_mul_pd(y.m_re,y.m_re),
		_mm512_mul_pd(y.m_im, y.m_im)));
	const __m512d re_part(_mm512_add_pd(ymm0,ymm1));
	const __m512d im_part(_mm512_sub_pd(ymm2, ymm3));
	return (AVX3C8f64{ _mm512_div_pd(re_part,den),
		_mm512_div_pd(im_part,den) });
}

static inline lam::math::AVX3C8f64
lam::math::operator/(_In_ const AVX3C8f64 &x,
					 _In_ const double s) {
	const __m512d zmm0(_mm512_set1_pd(s));
	return (AVX3C8f64{_mm512_div_pd(x.m_re,zmm0),
					  _mm512_div_pd(x.m_im,zmm0)});
}

static inline lam::math::AVX3C8f64
lam::math::operator/(_In_ const double s,
					 _In_ const AVX3C8f64 &x) {
	const __m512d zmm0(_mm512_set1_pd(s));
	return (AVX3C8f64{ _mm512_div_pd(zmm0,x.m_re),
		_mm512_div_pd(zmm0,x.m_im) });
}

static inline lam::math::AVX3C8f64
lam::math::operator/=(_In_ AVX3C8f64 &x,
					  _In_ const AVX3C8f64 &y) {
	x = x / y;
	return (x);
}

static inline lam::math::AVX3C8f64
lam::math::operator/=(_In_ AVX3C8f64 &x,
					  _In_ const double s) {
	x = x / s;
	return (x);
}

static inline lam::math::AVX3C8f64
lam::math::operator/=(_In_ const double s,
					  _In_ AVX3C8f64 &x) {
	x = s / x;
	return (x);
}

static inline lam::math::AVX3C8f64
lam::math::operator~(_In_ AVX3C8f64 &x) {
	x.m_re = _mm512_sub_pd(_mm512_setzero_pd(),x.m_re);
	return (x);
}

static inline std::pair<__mmask8,__mmask8>
lam::math::operator==(_In_ const AVX3C8f64 &x,
					  _In_ const AVX3C8f64 &y) {
	__mmask8 m1(_mm512_cmp_pd_mask(x.m_re,y.m_re,_CMP_EQ_OQ));
	__mmask8 m2(_mm512_cmp_pd_mask(x.m_im,y.m_im,_CMP_EQ_OQ));
	return (std::make_pair(m1,m2));
}

static inline std::pair<__mmask8,__mmask8>
lam::math::operator!=(_In_ const AVX3C8f64 &x,
					  _In_ const AVX3C8f64 &y) {
	__mmask8 m1(_mm512_cmp_pd_mask(x.m_re, y.m_re, _CMP_EQ_OQ));
	__mmask8 m2(_mm512_cmp_pd_mask(x.m_im, y.m_im, _CMP_EQ_OQ));
	return (std::make_pair(m1,m2));
}

static inline std::pair<__mmask8,__mmask8>
lam::math::operator>(_In_ const AVX3C8f64 &x,
					 _In_ const AVX3C8f64 &y) {
	__mmask8 m1(_mm512_cmp_pd_mask(x.m_re, y.m_re, _CMP_GT_OQ));
	__mmask8 m2(_mm512_cmp_pd_mask(x.m_im, y.m_im, _CMP_GT_OQ));
	return (std::make_pair(m1,m2));
}

static inline std::pair<__mmask8,__mmask8>
lam::math::operator<(_In_ const AVX3C8f64 &x,
					 _In_ const AVX3C8f64 &y) {
	__mmask8 m1(_mm512_cmp_pd_mask(x.m_re, y.m_re, _CMP_LT_OQ));
	__mmask8 m2(_mm512_cmp_pd_mask(x.m_im, y.m_im, _CMP_LT_OQ));
	return (std::make_pair(m1, m2));
}

static inline std::pair<__mmask8, __mmask8>
lam::math::operator>=(_In_ const AVX3C8f64 &x,
					  _In_ const AVX3C8f64 &y) {
	__mmask8 m1(_mm512_cmp_pd_mask(x.m_re, y.m_re, _CMP_GE_OQ));
	__mmask8 m2(_mm512_cmp_pd_mask(x.m_im, y.m_im, _CMP_GE_OQ));
	return (std::make_pair(m1, m2));
}

static inline std::pair<__mmask8, __mmask8>
lam::math::operator<=(_In_ const AVX3C8f64 &x,
_In_ const AVX3C8f64 &y) {
	__mmask8 m1(_mm512_cmp_pd_mask(x.m_re, y.m_re, _CMP_LE_OQ));
	__mmask8 m2(_mm512_cmp_pd_mask(x.m_im, y.m_im, _CMP_LE_OQ));
	return (std::make_pair(m1, m2));
}




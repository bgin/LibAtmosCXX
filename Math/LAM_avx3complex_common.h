
#ifndef __LAM_AVX3COMPLEX_COMMON_H__
#define __LAM_AVX3COMPLEX_COMMON_H__

namespace file_info {

#include "../LAM_version.h"

	const unsigned int gLAM_AVX3COMPLEX_COMMON_MAJOR = lam::common::gVersionInfo.m_VersionMajor;

	const unsigned int gLAM_AVX3COMPLEX_COMMON_MINOR = lam::common::gVersionInfo.m_VersionMinor;

	const unsigned int gLAM_AVX3COMPLEX_COMMON_MICRO = lam::common::gVersionInfo.m_VersionMicro;

	const unsigned int gLAM_AVX3COMPLEX_COMMON_FULLVER = 
		1000U*gLAM_AVX3COMPLEX_COMMON_MAJOR + 100U*gLAM_AVX3COMPLEX_COMMON_MINOR + 10U*gLAM_AVX3COMPLEX_COMMON_MICRO;

	const char * const pgLAM_AVX3COMPLEX_COMMON_CREATE_DATE = "15-09-2018 10:28 +00200 (SAT 15 SEP 2018 GMT+2)";

	const char * const pgLAM_AVX3COMPLEX_COMMON_BUILD_DATE = "00-00-0000 00:00";

	const char * const pgLAM_AVX3COMPLEX_AUTHOR = "Programmer: Bernard Gingold, contact: beniekg@gmail.com";

	const char * const pgLAM_AVX3COMPLEX_SYNOPSIS = "Common procedures for AVX3 complex field (1D) classes.";

}


#include <cstdint>
#include <type_traits>
#include <immintrin.h>
#include <complex>
#include "../LAM_config.h"
namespace lam {
	namespace math {

#if !defined (AVX3_COMPLEX_ADDITION)
#define AVX3_COMPLEX_ADDITION(out,v1,v2,idx,off) \
	(out) = _mm512_add_pd(_mm512_mul_pd(_mm512_load_pd(&(v1).data.m_Re[(idx)+(off)]), \
	_mm512_load_pd(&(v2).data.m_Re[(idx)+(off)])), _mm512_mul_pd(_mm512_load_pd(&(v1).data.m_Im[(idx)+(off)]), \
	_mm512_load_pd(&(v2).data.m_Im[(idx)+(off)])));
#endif

#if !defined (AVX3_COMPLEX_SUBTRACTION)
#define AVX3_COMPLEX_SUBTRACTION(out,v1,v2,idx,off) \
	(out) = _mm512_sub_pd(_mm512_mul_pd(_mm512_load_pd(&(v1).data.m_Im[(idx)+(off)]), \
	_mm512_load_pd(&(v2).data.m_Re[(idx)+(off)])), _mm512_mul_pd(_mm512_load_pd(&(v1).data.m_Re[(idx)+(off)]), \
	_mm512_load_pd(&(v2).data.m_Im[(idx)+(off)])));
#endif

		// Warning macro parameter v2 must be an exact copy
		// of parameter v1. This should done by calling class (AVX512VComplex1D)
		// Move Constructor.
#if !defined (AVX3_COMPLEX_MAGNITUDE)
#define AVX3_COMPLEX_MAGNITUDE(out,v1,v2,idx,off) \
	(out) = _mm512_sqrt_pd(_mm512_add_pd(_mm512_mul_pd(_mm512_load_pd(&(v1).data.m_Re[(idx)+(off)]), \
	_mm512_load_pd(&(v2).data.m_Re[(idx)+(off)])), _mm512_mul_pd(_mm512_load_pd(&(v1).data.m_Im[(idx)+(off)]), \
	_mm512_load_pd(&(v2).data.m_Im[(idx)+(off)]))));
#endif

			template<class AVX512VField1D,
				    typename = std::enable_if<
					 std::is_class<AVX512VField1D>::value,void>::type>
					  avx512_cnormalize_prod(_Inout_ AVX512VField1D &out,
										    _In_ const AVX512VField1D &v1,
					                        _In_ const AVX512VField1D &v2,
					                        _In_ const bool do_nt_stream) {
				 if (v1.data.m_nsize != v2.data.m_nsize) {return;}
				 int64_t i;
				 if (do_nt_stream) {// Incurs branch penalty here circa. 50% upon first encounters.
					 for (i = 0LL; i != ROUND_TO_EIGHT(out.data.m_nsize, 8LL); i += 8LL) {

						 const __m512d zmm0 = _mm512_load_pd(&v1.data.m_Re[i]);
						 const __m512d zmm1 = _mm512_load_pd(&v2.data.m_Re[i]);
						 const __m512d zmm2 = _mm512_load_pd(&v1.data.m_Im[i]);
						 const __m512d zmm2 = _mm512_load_pd(&v2.data.m_Im[i]);

						 const __m512d re_part = _mm512_sub_pd(
							 _mm512_mul_pd(zmm0, zmm1), _mm512_mul_pd(zmm2,zmm3));
						 const __m512d im_part = _mm512_add_pd(
							 _mm512_mul_pd(zmm2, zmm1), _mm512_mul_pd(zmm0,zmm3));
						 const __m512d sqrt_term1 = _mm512_mul_pd(re_part,re_part);
						 const __m512d sqrt_term2 = _mm512_mul_pd(im_part,im_part);
						 const __m512d mag_term = _mm512_sqrt_pd(_mm512_add_pd(sqrt_term1,sqrt_term2));
						 _mm512_stream_pd(&out.data.m_Re[i], _mm512_div_pd(re_part,mag_term));
						 _mm512_stream_pd(&out.data.m_Im[i], _mm512_div_pd(im_part,mag_term));
				}
					 // Warning remainder is cached upon store.
					 for (; i != vout.data.m_nsize; ++i) {
						 const double re = (v1.data.m_Re[i] * v2.data.m_Re[i]) - (v1.data.m_Im[i] * v2.data.m_Im[i]);
						 const double im = (v1.data.m_Im[i] * v2.data.m_Re[i]) + (v1.data.m_Re[i] * v2.data.m_Im[i]);
						 const double mag = std::sqrt((re*re) + (im*im));
						 vout.data.m_Re[i] = re / mag;
						 vout.data.m_Im[i] = im / mag;
					 }
			}
				 else {
					    
					 for (i = 0LL; i != ROUND_TO_EIGHT(out.data.m_nsize, 8LL); i += 8LL) {

						 const __m512d zmm0 = _mm512_load_pd(&v1.data.m_Re[i]);
						 const __m512d zmm1 = _mm512_load_pd(&v2.data.m_Re[i]);
						 const __m512d zmm2 = _mm512_load_pd(&v1.data.m_Im[i]);
						 const __m512d zmm2 = _mm512_load_pd(&v2.data.m_Im[i]);

						 const __m512d re_part = _mm512_sub_pd(
							 _mm512_mul_pd(zmm0, zmm1), _mm512_mul_pd(zmm2, zmm3));
						 const __m512d im_part = _mm512_add_pd(
							 _mm512_mul_pd(zmm2, zmm1), _mm512_mul_pd(zmm0, zmm3));
						 const __m512d sqrt_term1 = _mm512_mul_pd(re_part, re_part);
						 const __m512d sqrt_term2 = _mm512_mul_pd(im_part, im_part);
						 const __m512d mag_term = _mm512_sqrt_pd(_mm512_add_pd(sqrt_term1, sqrt_term2));
						 _mm512_store_pd(&out.data.m_Re[i], _mm512_div_pd(re_part, mag_term));
						 _mm512_store_pd(&out.data.m_Im[i], _mm512_div_pd(im_part, mag_term));
					 }

					 for (; i != vout.data.m_nsize; ++i) {
						 const double re = (v1.data.m_Re[i] * v2.data.m_Re[i]) - (v1.data.m_Im[i] * v2.data.m_Im[i]);
						 const double im = (v1.data.m_Im[i] * v2.data.m_Re[i]) + (v1.data.m_Re[i] * v2.data.m_Im[i]);
						 const double mag = std::sqrt((re*re) + (im*im));
						 vout.data.m_Re[i] = re / mag;
						 vout.data.m_Im[i] = im / mag;
					 }
			  }
		}

		template<class AVX512VField1D,
			     typename = std::enable_if<
				 std::is_class<AVX512VField1D>::value,void>::type>
				 avx512_cmean_prod(_Inout_ std::complex<double> &mean,
							       _In_ const AVX512VField1D &v1,
								   _In_ const AVX512VField1D &v2) {
					 if (v1.data.m_nsize != v2.data.m_nsize) { return;}
					 __declspec(align(64)) struct {
						 double sumre{ 0.0 }, sumim{ 0.0 }, accre{ 0.0 }, accim{0.0};
						 int64_t i;
					 } ca;
					 for (ca.i = 0LL; ca.i != ROUND_TO_EIGHT(v1.data.m_nsize, 8LL); ca.i += 8LL) {
						 
						 const __m512d zmm0(_mm512_load_pd(&v1.data.m_Re[i]));
						 const __m512d zmm1(_mm512_load_pd(&v2.data.m_Re[i]));
						 const __m512d zmm2(_mm512_load_pd(&v1.data.m_Im[i]));
						 const __m512d zmm3(_mm512_load_pd(&v2.data.m_Im[i]));
						 const __m512d re_part(_mm512_sub_pd(_mm512_mul_pd(zmm0,zmm1)
											   _mm512_mul_pd(zmm2,zmm3)));
						 const __m512d im_part(_mm512_add_pd(_mm512_mul_pd(zmm2,zmm1),
											   _mm512_mul_pd(zmm0,zmm3)));
						 ca.sumre = _mm512_reduce_pd(re_part);
						 ca.accre += ca.sumre;
						 ca.sumim = _mm512_reduce_pd(im_part);
						 ca.accim += ca.sumim;
				}
					 for (; ca.i != v1.data.m_nsize; ++i) {
						   ca.accre += (v1.data.m_Re[ca.i] * v2.data.m_Re[ca.i]) - (v1.data.m_Im[ca.i] * v2.data.m_Im[ca.i]);
						   ca.accim += (v1.data.m_Im[ca.i] * v2.data.m_Re[ca.i]) + (v1.data.m_Re[ca.i] * v2.data.m_Im[ca.i]);
					 }
					 mean._Val[0] = ca.accre /= static_cast<double>(v1.data.m_nsize);
					 mean._Val[1] = ca.accim /= static_cast<double>(v1.data.m_nsize);
		 }

		 template<class AVX512VField1D,
				  typename = std::enable_if<
				  std::is_class<AVX512VField1D>::value,void>::type>
				  avx512_cmean_quot(_Inout_ std::complex<double> &mean,
									_In_ const AVX512VField1D &v1,
									_In_ const AVX512VField1D &v2) {
				  if (v1.data.m_nsize != v2.data.m_nsize) { return;}
				  __declspec(align(64)) struct {
					  double sumre{ 0.0 }, sumim{ 0.0 }, accre{ 0.0 }, accim{ 0.0 },
					  t1{ 0.0 }, t2{0.0};
					  int64_t i;
				  }ca;
				 
				  for (ca.i = 0LL; ca.i != ROUND_TO_EIGHT(v1.data.m_nsize, 8LL); ca.i += 8LL) {
						
						const __m512d zmm0(_mm512_load_pd(&v1.data.m_Re[i]));
						const __m512d zmm1(_mm512_load_pd(&v2.data.m_Re[i]));
						const __m512d zmm2(_mm512_load_pd(&v1.data.m_Im[i]));
						const __m512d zmm3(_mm512_load_pd(&v2.data.m_Im[i]));
						const __m512d re_part(_mm512_sub_pd(_mm512_mul_pd(zmm0, zmm1),
											  _mm512_mul_pd(zmm2, zmm3)));
						const __m512d im_part(_mm512_add_pd(_mm512_mul_pd(zmm2, zmm1),
											  _mm512_mul_pd(zmm0, zmm3)));
						const __m512d den_term(_mm512_add_pd(_mm512_mul_pd(zmm1, zmm1),
											  _mm512_mul_pd(zmm3, zmm3)));
						const __m512d re_quot(_mm512_div_pd(re_part,den_term));
						ca.sumre = _mm512_reduce_pd(re_quot);
						ca.accre += ca.sumre;
						const __m512d im_quot(_mm512_div_pd(im_part,den_term));
						ca.sumim = _mm512_reduce_pd(im_quot);
						ca.accim += ca.sumim;
			  }
				  for (; ca.i != v1.data.m_nsize; ++ca.i) {
					  const double re = (v1.data.m_Re[ca.i] * v2.data.m_Re[ca.i]) - (v1.data.m_Im[ca.i] * v2.data.m_Im[ca.i]);
					  const double im = (v1.data.m_Im[ca.i] * v2.data.m_Re[ca.i]) + (v1.data.m_Re[ca.i] * v2.data.m_Im[ca.i]);
					  const double den = (v2.data.m_Re[ca.i] * v2.data.m_Re[ca.i]) + (v2.data.m_Im[ca.i] * v2.data.m_Im[ca.i]);
					  ca.t1 += re / den;
					  ca.t2 += im / den;
			 }
			 ca.accre += ca.t1;
			 ca.accim += ca.t2;
			 mean._Val[0] = ca.accre / static_cast<double>(v1.data.m_nsize);
			 mean._Val[1] = ca.accim / static_cast<double>(v1.data.m_nsize);
		}

		template<class AVX512VField1D,
			    typename = std::enable_if<
				std::is_class<AVX512VField1D>::value,void>::type>
				avx512_cconj_prod(_Inout_ AVX512VField1D &out,
								  _In_ const AVX512VField1D &v1,
								  _In_ const AVX512VField1D &v2,
								  _In_ const bool do_nt_store) {
				if (v1.data.m_nsize != v1.data.m_nsize) {return;}
				int64_t i;
				if (do_nt_store) { // Perform streaming-store

					for (i = 0LL; i != ROUND_TO_EIGHT(out.data.m_nsize, 8LL); i += 8LL) {
						 
						const __m512d zmm0(_mm512_load_pd(&v1.data.m_Re[i]));
						const __m512d zmm1(_mm512_load_pd(&v2.data.m_Re[i]));
						const __m512d zmm2(_mm512_load_pd(&v1.data.m_Im[i]));
						const __m512d zmm3(_mm512_load_pd(&v2.data.m_Im[i]));
						_mm512_stream_pd(&out.data.m_Re[i], _mm512_add_pd(
							            _mm512_mul_pd(zmm0, zmm1), _mm512_mul_pd(zmm2, zmm3)));
						_mm512_stream_pd(&out.data.m_Im[i], _mm512_sub_pd(
									    _mm512_mul_pd(zmm2, zmm1), _mm512_mul_pd(zmm0, zmm3)));
					}

					for (; i != v1.data.m_nsize; ++i) { // Cache storing remainder.
						out.data.m_Re[i] = (v1.data.m_Re[i] * v2.data.m_Re[i]) + (v1.data.m_Im[i] * v2.data.m_Im[i]);
						out.data.m_Im[i] = (v1.data.m_Im[i] * v2.data.m_Re[i]) - (v1.data.m_Re[i] * v2.data.m_Im[i]);
					}
				}
				else {
					
					for (i = 0LL; i != ROUND_TO_EIGHT(out.data.m_nsize, 8LL); i += 8LL) {

						const __m512d zmm0(_mm512_load_pd(&v1.data.m_Re[i]));
						const __m512d zmm1(_mm512_load_pd(&v2.data.m_Re[i]));
						const __m512d zmm2(_mm512_load_pd(&v1.data.m_Im[i]));
						const __m512d zmm3(_mm512_load_pd(&v2.data.m_Im[i]));
						_mm512_store_pd(&out.data.m_Re[i], _mm512_add_pd(
							_mm512_mul_pd(zmm0, zmm1), _mm512_mul_pd(zmm2, zmm3)));
						_mm512_store_pd(&out.data.m_Im[i], _mm512_sub_pd(
							_mm512_mul_pd(zmm2, zmm1), _mm512_mul_pd(zmm0, zmm3)));
					}

					for (; i != v1.data.m_nsize; ++i) { 
						out.data.m_Re[i] = (v1.data.m_Re[i] * v2.data.m_Re[i]) + (v1.data.m_Im[i] * v2.data.m_Im[i]);
						out.data.m_Im[i] = (v1.data.m_Im[i] * v2.data.m_Re[i]) - (v1.data.m_Re[i] * v2.data.m_Im[i]);
					}
				}
	        }

			template<class AVX512VField1D,
					 typename = std::enable_if<
					 std::is_class<AVX512VField1D>::value,void>::type>
					 avx512_cnorm_conjprod(_Inout_ AVX512VField1D &out,
										   _In_ const AVX512VField1D &v1,
										   _In_ const AVX512VField1D &v2,
										   _In_ const bool do_nt_store) {
					 if (v1.data.m_nsize != v2.data.m_nsize) { return;}
					 int64_t i;
					 if (do_nt_store) {
							
						 for (i = 0LL; i != ROUND_TO_EIGHT(out.data.m_nsize, 8LL); i += 8LL) {
							
							 const __m512d zmm0(_mm512_load_pd(&v1.data.m_Re[i]));
							 const __m512d zmm1(_mm512_load_pd(&v2.data.m_Re[i]));
							 const __m512d zmm2(_mm512_load_pd(&v1.data.m_Im[i]));
							 const __m512d zmm3(_mm512_load_pd(&v2.data.m_Im[i]));
							 const __m512d re_part(_mm512_add_pd(_mm512_mul_pd(zmm0, zmm1),
													   _mm512_mul_pd(zmm2, zmm3)));
							 const __m512d im_part(_mm512_sub_pd(_mm512_mul_pd(zmm2, zmm1),
													   _mm512_mul_pd(zmm0, zmm3)));
							 const __m512d mag_c1(_mm512_mul_pd(re_part, re_part));
							 const __m512d mag_c2(_mm512_mul_pd(im_part, im_part));
							 const __m512d vcmag(_mm512_sqrt_pd(_mm512_add_pd(mag_c1, mag_c2)));
							 _mm512_stream_pd(&out.data.m_Re[i], _mm512_div_pd(re_part,vcmag));
							 _mm512_stream_pd(&out.data.m_Im[i], _mm512_div_pd(im_part,vcmag));
						 }

						 for (; i != out.data.m_nsize; ++i) { // Cache storing remainder.
							 const double re = (v1.data.m_Re[i] * v2.data.m_Re[i]) - (v1.data.m_Im[i] * v2.data.m_Im[i]);
							 const double im = (v1.data.m_Im[i] * v2.data.m_Re[i]) + (v1.data.m_Re[i] * v2.data.m_Im[i]);
							 const double mag = std::sqrt((re*re) + (im*im));
							 out.data.m_Re[i] = re / mag;
							 out.data.m_Im[i] = im / mag;
						 }
					 }
					 else {
							
						 for (i = 0LL; i != ROUND_TO_EIGHT(out.data.m_nsize, 8LL); i += 8LL) {

							 const __m512d zmm0(_mm512_load_pd(&v1.data.m_Re[i]));
							 const __m512d zmm1(_mm512_load_pd(&v2.data.m_Re[i]));
							 const __m512d zmm2(_mm512_load_pd(&v1.data.m_Im[i]));
							 const __m512d zmm3(_mm512_load_pd(&v2.data.m_Im[i]));
							 const __m512d re_part(_mm512_add_pd(_mm512_mul_pd(zmm0, zmm1),
								 _mm512_mul_pd(zmm2, zmm3)));
							 const __m512d im_part(_mm512_sub_pd(_mm512_mul_pd(zmm2, zmm1),
								 _mm512_mul_pd(zmm0, zmm3)));
							 const __m512d mag_c1(_mm512_mul_pd(re_part, re_part));
							 const __m512d mag_c2(_mm512_mul_pd(im_part, im_part));
							 const __m512d vcmag(_mm512_sqrt_pd(_mm512_add_pd(mag_c1, mag_c2)));
							 _mm512_store_pd(&out.data.m_Re[i], _mm512_div_pd(re_part, vcmag));
							 _mm512_store_pd(&out.data.m_Im[i], _mm512_div_pd(im_part, vcmag));
						 }

						 for (; i != out.data.m_nsize; ++i) { 
							 const double re = (v1.data.m_Re[i] * v2.data.m_Re[i]) - (v1.data.m_Im[i] * v2.data.m_Im[i]);
							 const double im = (v1.data.m_Im[i] * v2.data.m_Re[i]) + (v1.data.m_Re[i] * v2.data.m_Im[i]);
							 const double mag = std::sqrt((re*re) + (im*im));
							 out.data.m_Re[i] = re / mag;
							 out.data.m_Im[i] = im / mag;
						 }
					 }

			    }
		  
		  template<class AVX512VField1D,
				   typename = std::enable_if<
				   std::is_class<AVX512VField1D>::value,void>::type>
				   avx512_cmean_conjprod(_Inout_ std::complex<double> &mean,
									     _In_ const AVX512VField1D &v1,
									     _In_ const AVX512VField1D &v2) {
					   if (v1.data.m_nsize != v2.data.m_nsize) { return;}
					   __declspec(align(64)) struct {
						   double sumre{ 0.0 }, sumim{ 0.0 }, accre{ 0.0 }, accim{ 0.0 };
						   int64_t i;
					   }ca;
					   __m512d re = _mm512_setzero_pd();
					   __m512d im = _mm512_setzero_pd();
					   for (ca.i = 0LL; ca.i != ROUND_TO_EIGHT(v1.data.m_nsize, 8LL); i += 8LL) {
						    
						   AVX3_COMPLEX_ADDITION(re,v1,v2,ca.i,0LL)
						   AVX3_COMPLEX_SUBTRACTION(im,v1,v2,ca.i,0LL)
						   ca.sumre = _mm512_reduce_pd(re);
						   ca.accre += ca.sumre;
						   ca.sumim = _mm512_reduce_pd(im);
						   ca.accim += ca.sumim;
					   }
					   for (; i != v1.data.m_nsize; ++i) {
						   const double re = (v1.data.m_Re[i] * v2.data.m_Re[i]) + (v1.data.m_Im[i] * v2.data.m_Im[i]);
						   const double im = (v1.data.m_Im[i] * v2.data.m_Re[i]) - (v1.data.m_Re[i] * v2.data.m_Im[i]);
						   ca.accre += re;
						   ca.accim += im;
					   }
					   mean._Val[0] = ca.accre / static_cast<double>(v1.data.m_nsize);
					   mean._Val[1] = ca.accim / static_cast<double>(v1.data.m_nsize);
				   }

			
			template<class AVX512VField1D, 
			         typename = std::enable_if<
					 std::is_class<AVX512VField1D>::value,void>::type>
					 avx512_arith_mean(_Inout_ std::complex<double> &mean,
									    _In_ const AVX512VField1D &v) {
						 __declspec(align(64)) struct {
							 double sumre{ 0.0 }, sumim{ 0.0 }, accre{ 0.0 }, accim{ 0.0 };
							 int64_t i;
						 }ca;
						 for (ca.i = 0LL; ca.i != ROUND_TO_EIGHT(v.data.m_nsize, 8LL); ca.i += 8LL) {
							 const __m512d re_part(_mm512_load_pd(&v.data.m_Re[i]));
							 ca.sumre = _mm512_reduce_pd(re_part);
							 ca.accre += ca.sumre;
							 const __m512d im_part(_mm512_load_pd(&v.data.m_Im[i]));
							 ca.sumim = _mm512_redice_pd(im_part);
							 ca.accim += ca.sumim;
						 }
						 for (; ca.i != v.data.m_nsize; ++ca.i) {
							 ca.accre += v.data.m_Re[i];
							 ca.accim += v.data.m_Im[i];
						 }
						 mean._Val[0] = ca.accre / static_cast<double>(v.data.m_nsize);
						 mean._Val[1] = ca.accim / static_cast<double>(v.data.m_nsize);
			}

			template<class AVX512VField1D,
					 typename = std::enable_if<
								std::is_class<AVX512VField1D>::value,void>::type>
								avx512_cnormalize(_Inout_ AVX512VField1D &out,
												  _In_ const AVX512VField1D &v,
												  _In_ const AVX512VField1D &cv,
												  _In_ const bool do_nt_store) {
						if (v.data.m_nsize != cv.data.m_nsize) { return;}
						__m512d cvmag(_mm512_setzero_pd());
						int64_t i;
						if (do_nt_store) {
								
							for (i = 0LL, i != ROUND_TO_EIGHT(out.data.m_nsize, 8LL); i += 8LL) {
								AVX3_COMPLEX_MAGNITUDE(vcmag,v,cv,i,0LL)
								const __m512d re_part(_mm512_load_pd(&v.data.m_Re[i]));
								_mm512_stream_pd(&out.data.m_Re[i], _mm512_div_pd(re_part,vcmag));
								const __m512d im_part(_mm512_load_pd(&v.data.m_Im[i]));
								_mm512_stream_pd(&out.data.m_Im[i], _mm512_div_pd(im_part,vcmag));
							}
							for (; i != v.data.m_nsize; ++i) {
								const double cmag = std::sqrt(v.data.m_Re[i] * cv.data.m_Re[i] + v.data.m_Im[i] * cv.data.m_Im[i]);
								out.data.m_Re[i] = v.data.m_Re[i] / cmag;
								out.data.m_Im[i] = v.data.m_Im[i] / cmag;
							}
						}
						else {
							for (i = 0LL, i != ROUND_TO_EIGHT(out.data.m_nsize, 8LL); i += 8LL) {
								AVX3_COMPLEX_MAGNITUDE(vcmag, v, cv, i, 0LL)
									const __m512d re_part(_mm512_load_pd(&v.data.m_Re[i]));
								_mm512_store_pd(&out.data.m_Re[i], _mm512_div_pd(re_part, vcmag));
								const __m512d im_part(_mm512_load_pd(&v.data.m_Im[i]));
								_mm512_store_pd(&out.data.m_Im[i], _mm512_div_pd(im_part, vcmag));
							}
							for (; i != v.data.m_nsize; ++i) {
								const double cmag = std::sqrt(v.data.m_Re[i] * cv.data.m_Re[i] + v.data.m_Im[i] * cv.data.m_Im[i]);
								out.data.m_Re[i] = v.data.m_Re[i] / cmag;
								out.data.m_Im[i] = v.data.m_Im[i] / cmag;
							}
						}
				}

				template<class AVX512VField1D,
						 typename = std::enable_if<
						 std::is_class<AVX512VField1D>::value,void>::type>
						void avx512_cmagnitude(_Inout_ double * __restrict vmag, 
										   _In_ const AVX512VField1D &v,
										   _In_ const AVX512VField1D &cv) {
						if (v.data.m_nsize != cv.data.m_nsize) { return;}
						__m512d vcmag(_mm512_setzero_pd());
						int64_t i;
						for (i = 0LL; i != ROUND_TO_EIGHT(v.data.m_nsize, 8ULL); i += 8LL) {

							AVX3_COMPLEX_MAGNITUDE(vcmag, v, cv, i, 0LL)
								_mm512_store_pd(&vmag[i], vcmag);
						}
						for (; i != v.data.m_nsize; ++i)
							vmag[i] = std::sqrt(v.data.m_Re[i] * cv.data.m_Re[i] + v.data.m_Im[i] * cv.data.m_Im[i]);
			   }

	}
}

 


#endif /*__LAM_AVX3COMPLEX_COMMON_H__*/
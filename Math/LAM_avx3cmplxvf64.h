
#ifndef __LAM_AVX3CMPLXVF64_H__
#define __LAM_AVX3CMPLXVF64_H__

namespace file_info {
#include "../LAM_version.h"

	const unsigned int gLAM_AVX3CMPLXVF64_MAJOR = lam::common::gVersionInfo.m_VersionMajor;

	const unsigned int gLAM_AVX3CMPLXVF64_MINOR = lam::common::gVersionInfo.m_VersionMinor;

	const unsigned int gLAM_AVX3CMPLXVF64_MICRO = lam::common::gVersionInfo.m_VersionMicro;

	const unsigned int gLAM_AVX3CMPLXVF64_FULLVER = 
		1000U*gLAM_AVX3CMPLXVF64_MAJOR+100U*gLAM_AVX3CMPLXVF64_MINOR+10U*gLAM_AVX3CMPLXVF64_MICRO;

	const char * const pgLAM_AVX3CMPLXVF64_CREATE_DATE = "29-09-2018 11:13 +00200 (SAT 29 SEP 2018 GMT+2)";

	const char * const pgLAM_AVX3CMPLXVF64_BUILD_DATE = "00-00-0000 00:00";

	const char * const pgLAM_AVX3CMPLXVF64_AUTHOR = "Programmer: Bernard Gingold, contact: beniekg@gmail.com";

	const char * const pgLAM_AVX3CMPLXVF64_SYNOPSIS = "AVX-512 complex number class.";
}

#include <cstdint>
#include <iostream>
#include <immintrin.h>
#include "../LAM_config.h"

namespace lam {
	namespace math {



		__declspec(align(64)) struct AVX3C8Payload {
			double re0,re1,re2,re3,re4,re5,re6,re7;
			double im0,im1,im2,im3,im4,im5,im6,im7;
		};

		//static AVX3C8f64 CZERO{ _mm512_setzero_pd(),
		//						_mm512_setzero_pd() };

		__declspec(align(64)) struct AVX3C8f64 {
				
				__m512d m_re;
				
				__m512d m_im;

				static const AVX3C8f64 CZERO;
				
				// Default Ctor (sets components to 0.0)
				AVX3C8f64();
					
				

				AVX3C8f64(_In_ const AVX3C8Payload &x);
					
				
				// Arrays: Re and Im must be aligned on 64-bytes boundary, otherwise GP will be signalled.
				AVX3C8f64(_In_ const double * __restrict ,
					      _In_ const double * __restrict);
					
				
				// From single complex number
				AVX3C8f64(_In_ const double ,
						  _In_ const double ); 
					
				
				// From scalar
				explicit AVX3C8f64(_In_ const double ); 
					
				

				// Real parts only
				AVX3C8f64(_In_ const double ,
						  _In_ const double ,
						  _In_ const double ,
					      _In_ const double,
						  _In_ const double ,
					      _In_ const double ,
					      _In_ const double ,
					      _In_ const double );
					
				

				AVX3C8f64(_In_ const __m512d &,
						  _In_ const __m512d &);
				

				AVX3C8f64(_In_ const AVX3C8f64 &);
					
				

				~AVX3C8f64() noexcept(true) = default;

				
				// Load-store functions
				// Load aligned
				AVX3C8f64 & load_a(_In_ const double * __restrict ,
								   _In_ const double * __restrict );
					
				
				// Load unaligned
				AVX3C8f64 & load_u(_In_ const double * __restrict ,
							       _In_ const double * __restrict );
					
				

				// Store aligned
				void store_a(_Out_ double * __restrict ,
							 _Out_ double * __restrict ) const;
					
				

				// Store unaligned
				void store_u(_Out_ double * __restrict ,
							 _Out_ double * __restrict ) const; 
					
				

				void stream(_Out_ double * __restrict ,
							_Out_ double * __restrict ) const;
					

				double extract_f64(_In_ const int32_t) const;
					

				std::pair<double, double> 
				extract_2f64(_In_ const int32_t ,
							 _In_ const int32_t );
					
				
				AVX3C8f64 & insert_1f64(_In_ const int32_t ,
								       _In_ const double );
					

				AVX3C8f64 & insert_2f64(_In_ const int32_t ,
										_In_ const int32_t ,
									    _In_ const double ,
									    _In_ const double );
					

				// Length of 16 doubles
				void concatenate_a(_Out_ double * __restrict ) const;
					

				// Length of 16 doubles
				void concatenate_u(_Out_ double * __restrict ) const;

				AVX3C8f64 & partial_loadu(_In_ const double const * __restrict,
										  _In_ const int32_t,
										  _In_ const double const * __restrict,
										  _In_ const int32_t );

				AVX3C8f64 & partial_loada(_In_ const double const * __restrict,
										  _In_ const int32_t,
									      _In_ const double const * __restrict,
										  _In_ const int32_t);

				void partial_storeu(_Out_ double * __restrict,
								    _In_ const int32_t,
									_Out_ double * __restrict,
									_In_ const int32_t);

				void partial_storea(_Out_ double * __restrict,
								    _In_ const int32_t,
									_Out_ double * __restrict,
									_In_ const int32_t);
					

				AVX3C8f64 & expand(_In_ const AVX3C8f64 &,
								   _In_ const __mmask8); 

				AVX3C8f64 & expand_load(_In_ const AVX3C8f64 &,
									    _In_ const __mmask8 ,
									    _In_ const double * __restrict ,
										_In_ const double * __restrict );



				AVX3C8f64 & permute(_In_ const __mmask8 ,
									_In_ const int32_t);
					

				__m256d re_low2() const; 

				

				__m256d re_hi2() const; 

				__m256d im_low2() const;

				__m256d im_hi2() const;

				

				AVX3C8f64 & operator=(_In_ const AVX3C8f64 &);

				
		};

		static inline AVX3C8f64 
			csin(_In_ const AVX3C8f64 &);
		

		static inline AVX3C8f64
			ccos(_In_ const AVX3C8f64 &);

		static inline AVX3C8f64
			cexp(_In_ const AVX3C8f64 &); 

		static inline AVX3C8f64
			cabs(_In_ const AVX3C8f64 &); 

		static inline AVX3C8f64
		    cpowi(_In_ const AVX3C8f64 &,
				  _In_ const double );
		
		static inline AVX3C8f64 
		select(_In_ const AVX3C8f64 &,
			   _In_ const AVX3C8f64 &,
			   _In_ const __mmask8);

		static inline AVX3C8f64 
		operator+(_In_ const AVX3C8f64 &,
				  _In_ const AVX3C8f64 &);

		static inline AVX3C8f64
		operator+(_In_ const AVX3C8f64 &,
				  _In_ const double );

		static inline AVX3C8f64
		operator+(_In_ const double ,
				  _In_ const AVX3C8f64 &); 

		static inline AVX3C8f64
		operator+=(_In_ AVX3C8f64 &,
				   _In_ const AVX3C8f64 &); 

		static inline AVX3C8f64
		operator+=(_In_ AVX3C8f64 &,
				   _In_ const double);

		static inline AVX3C8f64
		operator+=(_In_ const double,
				   _In_ AVX3C8f64 &);

		static inline AVX3C8f64
		operator-(_In_ const AVX3C8f64 &,
				  _In_ const AVX3C8f64 &); 

		static inline AVX3C8f64
		operator-(_In_ const AVX3C8f64 &,
				  _In_ const double );

		static inline AVX3C8f64
		operator-(_In_ const double ,
				  _In_ const AVX3C8f64 &);

		static inline AVX3C8f64
		operator-(_In_  AVX3C8f64 &);

		static inline AVX3C8f64
		operator-=(_In_ AVX3C8f64 &,
				   _In_ const AVX3C8f64 &);

		static inline AVX3C8f64
		operator-=(_In_ AVX3C8f64 &,
				   _In_ const double );

		static inline AVX3C8f64
		operator-=(_In_ const double,
					   _In_ AVX3C8f64 &);

		static inline AVX3C8f64
		operator*(_In_ const AVX3C8f64 &,
				  _In_ const AVX3C8f64 &);

		static inline AVX3C8f64
		operator*(_In_ const AVX3C8f64 &,
				  _In_ const double);

		static inline AVX3C8f64
		operator*(_In_ const double,
				  _In_ const AVX3C8f64 &);

		static inline AVX3C8f64
		operator*=(_In_ AVX3C8f64 &,
				   _In_ const AVX3C8f64 &);

	    static inline AVX3C8f64
		operator*=(_In_ AVX3C8f64 &,
					_In_ const double);

		static inline AVX3C8f64
		operator*=(_In_ const double,
				_In_ AVX3C8f64 &);

		static inline AVX3C8f64
		operator/(_In_ const AVX3C8f64 &,
				  _In_ const AVX3C8f64 &);

		static inline AVX3C8f64
		operator/(_In_ const AVX3C8f64 &,
				  _In_ const double);

		static inline AVX3C8f64
		operator/(_In_ const double,
				  _In_ const AVX3C8f64 &);

		static inline AVX3C8f64
		operator/=(_In_ AVX3C8f64 &,
				   _In_ const AVX3C8f64 &);

	    static inline AVX3C8f64
		operator/=(_In_ AVX3C8f64 &,
				  _In_ const double);

		static inline AVX3C8f64
		operator/=(_In_ const double,
					   _In_ AVX3C8f64 &);

		static inline AVX3C8f64
		operator~(_In_ AVX3C8f64 &);

		
		static inline
			std::pair<__mmask8, __mmask8>
		operator==(_In_ const AVX3C8f64 &,
				   _In_ const AVX3C8f64 &);

		static inline 
			std::pair<__mmask8, __mmask8>
		operator!=(_In_ const AVX3C8f64 &,
				   _In_ const AVX3C8f64 &);

		static inline 
			std::pair<__mmask8, __mmask8>
		operator>(_In_ const AVX3C8f64 &,
				  _In_ const AVX3C8f64 &);

		static inline 
			std::pair<__mmask8, __mmask8>
		operator<(_In_ const AVX3C8f64 &,
				  _In_ const AVX3C8f64 &);

		static inline 
			std::pair<__mmask8, __mmask8>
		operator>=(_In_ const AVX3C8f64 &,
				  _In_ const AVX3C8f64 &);

		static inline 
			std::pair<__mmask8, __mmask8>
	    operator<=(_In_ const AVX3C8f64 &,
				  _In_ const AVX3C8f64 &);

#include "LAM_avx3cmplxvf64.inl"	

	}
}



#endif /*__LAM_AVX3CMPLXVF64_H__*/
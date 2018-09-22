
#ifndef __LAM_COMMON_H__
#define __LAM_COMMON_H__

namespace file_info {
#include "LAM_version.h"
	
	const unsigned int gLAM_COMMON_MAJOR = lam::common::gVersionInfo.m_VersionMajor;

	const unsigned int gLAM_COMMON_MINOR = lam::common::gVersionInfo.m_VersionMinor;

	const unsigned int gLAM_COMMON_MICRO = lam::common::gVersionInfo.m_VersionMicro;

	const unsigned int gLAM_COMMON_FULLVER = 
	 1000U*gLAM_COMMON_MAJOR+100U*gLAM_COMMON_MINOR+10U*gLAM_COMMON_MICRO;

	const char * const pgLAM_COMMON_CREATE_DATE = "04-09-2017 16:39 +00200 (MON 04 SEP 2017 GMT+2)";

	const char * const pgLAM_COMMON_BUILD_DATE = "00-00-0000 00:00";

	const char * const pgLAM_COMMON_AUTHOR = "Programmer: Bernard Gingold, contact: beniekg@gmail.com";

	const char * const pgLAM_COMMON_SYNOPSIS = "LAM common functions.";
}


#if !defined (MEMMOVE_1BYTE)
#define MEMMOVE_1BYTE 1
#endif

#if !defined (MEMMOVE_64BYTES)
#define MEMMOVE_64BYTES 64
#endif

#if !defined (MEMMOVE_128BYTES)
#define MEMMOVE_128BYTES 128
#endif

#if !defined (MEMMOVE_256BYTES)
#define MEMMOVE_256BYTES 256
#endif

#if !defined (MEMMOVE_512BYTES)
#define MEMMOVE_512BYTES 512
#endif

#if !defined (MEMMOVE_1024BYTES)
#define MEMMOVE_1024BYTES 1024
#endif

#if !defined (PAGE4KiB)
#define PAGE4KiB 4096
#endif

#if !defined (MAXFLOATSPERPAGE4KiB)
#define MAXFLOATSPERPAGE4KiB 1024
#endif

#if !defined (min_val)
#define min_val(A,B) ((A)<(B)?(A):(B))
#endif

#include <cstdint>

namespace lam{
	namespace common {

		// Degree to radian conversion

		// 256-bit vector
		//const __m256d vrad4_to_deg = _mm256_set1_pd(57.29577951308092);

		// 512-bit vector
		//const __m512d vrad8_to_deg = _mm512_set1_pd(57.29577951308092);

		// Zero-valued vector 256-bit
		//const __m256d vzero4 = _mm256_set1_pd(0.0);

		// Zero-valued vector 512-bit
		///const __m512d vzero8 = _mm512_setzero_pd();

		// D. Knuth safe floating-point comparison

		bool approximately_equalf64(_In_ const double,
								    _In_ const double,
								    _In_ const double);

		bool essentialy_equalf64(_In_ const double,
							     _In_ const double,
								 _In_ const double);

		bool definitely_greaterf64(_In_ const double,
								   _In_ const double,
								   _In_ const double);

		bool definitely_lessf64(_In_ const double,
							    _In_ const double,
								_In_ const double);

		// Pointer alignment
		bool Is_ptr_aligned32(_In_ const int64_t * __restrict);
					

		bool Is_ptr_aligned32(_In_ const double * __restrict);

		bool Is_ptr_aligned64(_In_ const int64_t * __restrict);

		bool Is_ptr_aligned64(_In_ const double * __restrict);

		template<typename PTR, uint32_t Alignment,
			     typename = std::enable_if<(std::is_pointer<PTR>::value &&
										   std::is_floating_point<PTR>::value) ||
										   (std::is_pointer<PTR>::value &&
										    std::is_integral<PTR>::value),bool>::type>
										    Is_ptr_aligned(PTR * ptr) {
						 if ((reinterpret_cast<uintptr_t>(ptr) & Alignment) == 0ULL){
							  return (true);
					}
						 else {
							 return (false);
						 }
			}

		//
		// Array of type double scalar initialization.
		//
		void init_array(_Inout_ double* __restrict, 
		               _In_ const int64_t, 
					   _In_ const double);

		//
		// Array of type uint64_t scalar initialization
		//
		void init_array(_Inout_ uint64_t* __restrict, 
		                _In_ const int64_t, 
						_In_ const uint64_t);

		void init_array(_Inout_ int64_t* __restrict,
		                _In_ const int64_t,
						_In_ const int64_t);

		void init_array(_Inout_ int32_t* __restrict,
						_In_ const int64_t,
						_In_ const int32_t);

		//
		// Array of type unsigned char scalar initialization
		//
		void init_array(_Inout_ unsigned char* __restrict,
					    _In_ const int64_t,
						_In_ const unsigned char);
		//
		//	Array of type double vectorised initialization
		//
		void init_varray(_Inout_ double* __restrict,
						 _In_ const int64_t,
						 _In_ const double );

		//
		//	Array of type double vectorised initialization
		//  Unrolled 2x (using AVX)
		//  Array must be aligned on 64-bytes boundaries.
		//
		void avx256_init_unroll2x(_Inout_ double * __restrict,
							      _In_ const  int64_t,
								  _In_ const double ) noexcept(true);

		//
		//	Array of type double vectorised initialization
		//  Unrolled 2x (using AVX)
		//  Array must be aligned on 64-bytes boundaries.
		//
		void avx256_init_unroll4x(_Inout_ double * __restrict,
								  _In_ const int64_t,
								  _In_ const double) noexcept(true);
		
		//
		//	Array of type double vectorised initialization
		//  Unrolled 8x (using AVX)
		//  Array must be aligned on 64-bytes boundaries.
		//
		void avx256_init_unroll8x(_Inout_ double * __restrict,
								 _In_ const int64_t,
								 _In_ const double) noexcept(true);

		//
		//	Array of type double vectorised initialization
		//  Unrolled 8x (using AVX3)
		//  Array must be aligned on 64-bytes boundaries.
		//
		void avx512_init_unroll8x(_Inout_ double * __restrict,
							      _In_ const int64_t,
								  _In_ const double) noexcept(true);


	   //
	   // Check for zero (0.0) in arrays.
	   // Vectorised version.
	   // @Returns:
	   //			true if 0.0 is detected, 
	   //           otherwise false.
		bool vzero_check(_In_ double*  __restrict,
						 _In_ double*  __restrict,
						 _In_ const int64_t );

		//
		// Check for zero (0.0) in array.
		// Vectorised version.
		// @Returns:
		//			true if 0.0 is detected, 
		//           otherwise false.
		bool vzero_check1(_In_ const double* __restrict,
						 _In_ const int64_t);
						 

		//
		// Check for zero (0.0) in array 3D
		// Vectorised version
		// @Returns:
		//           true on first occurrence of 0.0,
		//			 otherwise false.
		// @Remark:
		//			 Data array should be of length which is: len%4 == 0
		bool vzero_check3D(_In_ const double* __restrict, 
						   _In_ const int64_t, 
						   _In_ const int64_t,
						   _In_ const int64_t);

		//
		// Check for zero (0.0) in array 3D
		// Vectorised version
		// @Returns:
		//           true on first occurrence of 0.0,
		//			 otherwise false.
		// @Remark:
		//			This overloaded version is called from 
		//			various code blocks which operates of fields arrays.
		bool vzero_check3D(_In_ const double* __restrict,
						   _In_ const int64_t,
						   _In_ const int64_t,
						   _In_ const int64_t,
						   _In_ const int64_t,
						   _In_ const int64_t,
						   _In_ const int64_t);

		
	   
		//
		//	Copy memory (AVX unrolled version) from source to destination
		//  Both source and destination are flat arrays.
		//	@Returns: nothing
		//  @Remark:  
		//			  Memory must be aligned on 64-byte boundary.
		//            This version uses stream stores.
		//		      Be sure , that recently stored data will
		//			  not be used soon.
		//			  Unrolled 2x
		//			  This version should be used on data
		//			  being ~ 1/2 size of L3 cache.
		//
	   
		void avx256_memcpy2x_nt(_Inout_ double * __restrict,
							    _In_ const double * __restrict,
								_In_ const int64_t);

		//
		//	Copy memory (AVX unrolled version) from source to destination
		//   Both source and destination are flat arrays.
		//	@Returns: nothing
		//   @Remark:  
		//			  Memory must be aligned on 64-byte boundary.
		//            This version uses stream stores.
		//			  Be sure, that recently stored data will
		//			  not be used soon.
		//			  Unrolled 2x
		//			  This version should be used on data
		//			  being ~ 1/2 size of L3 cache.
		//

		void avx256_memcpy4x_nt(_Inout_ double * __restrict,
							    _In_ const double * __restrict,
								_In_ const int64_t);

	   //
	   //	Copy memory (AVX unrolled version) from source to destination
	   //   Both source and destination are flat arrays.
	   //	@Returns: nothing
	   //   @Remark:  
	   //			  Memory must be aligned on 64-byte boundary.
	   //             This version uses stream stores.
	   //			  Be sure, that recently stored data will
	   //			  not be used soon.
	   //			  Unrolled 8x
	   //			  This version should be used on data
	   //			  being ~ 1/2 size of L3 cache.
	   //

		void  avx256_memcpy8x_nt(_Inout_ double * __restrict,
								 _In_ const double * __restrict,
								 _In_ const int64_t);

		//
		//  Copy memory (AVX unrolled version) from source to destination
		//  Both source and destination are flat arrays.
		//	@Returns: nothing
		//  @Remark:  
		//			  Memory must be aligned on 64-byte boundary.
		//			  Unrolling 2x
		//

		void avx256_memcpy2x(_Inout_ double * __restrict,
							 _In_ const double * __restrict,
							 _In_ const int64_t);

		//
		//  Copy memory (AVX unrolled version) from source to destination
		//  Both source and destination are flat arrays.
		//	@Returns: nothing
		//  @Remark:  
		//			  Memory must be aligned on 64-byte boundary.
		//			  Unrolling 4x
		//

		void avx256_memcpy4x(_Inout_ double * __restrict,
							 _In_ const double * __restrict,
							 _In_ const int64_t);

		//
		//  Copy memory (AVX unrolled version) from source to destination
		//  Both source and destination are flat arrays.
		//	@Returns: nothing
		//  @Remark:  
		//			  Memory must be aligned on 64-byte boundary.
		//			  Unrolling 8x
		//

		void avx256_memcpy8x(_Inout_ double * __restrict,
							 _In_ const double * __restrict,
							 _In_ const int64_t );


		void avx512_cached_memmove(_Out_ void * __restrict ,
								   _In_ const void * __restrict,
								   _In_ const int32_t);

		void avx512_uncached_memmove(_Out_ void * __restrict,
								    _In_ const void * __restrict,
									_In_  int32_t);

		
							
	}
}

#endif /*__LAM_COMMON_H__*/
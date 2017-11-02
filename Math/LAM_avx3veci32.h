
#ifndef __LAM_AVX3VECI32_H__
#define __LAM_AVX3VECI32_H__

#if !defined (LAM_AVX3VECI32_MAJOR)
#define LAM_AVX3VECI32_MAJOR 1
#endif

#if !defined (LAM_AVX3VECI32_MINOR)
#define LAM_AVX3VECI32_MINOR 0
#endif

#if !defined (LAM_AVX3VECI32_MICRO)
#define LAM_AVX3VECI32_MICRO 0
#endif

#if !defined (LAM_AVX3VECI32_FULLVER)
#define LAM_AVX3VECI32_FULLVER 1000
#endif

#if !defined (LAM_AVX3VECI32_CREATE_DATE)
#define LAM_AVX3VECI32_CREATE_DATE "02-11-2017 10:45 +00200 (THR 02 NOV 2017 GMT+2)"
#endif
//
// Set this value after successful compilation.
//
#if !defined (LAM_AVX3VECI32_BUILD_DATE)
#define LAM_AVX3VECI32_BUILD_DATE " "
#endif

#if !defined (LAM_AVX3VECI32_AUTHOR)
#define LAM_AVX3VECI32_AUTHOR "Programmer: Bernard Gingold e-mail: beniekg@gmail.com"
#endif

#if !defined (LAM_AVX3VECI32_DESCRIPT)
#define LAM_AVX3VECI32_DESCRIPT "Wrapper class around __m512i data type."
#endif

/*
	Bernard Gingold copyright notice:
	This file is a part of LibAtmosModelCPP library
	Copyright(C) 2017 Bernard Gingold
	License : GNU General Public Locense version 3 or later,
	for additional information check file LICENSE.txt in
	project directory.
*/

#include <zmmintrin.h>
#include <iostream>
#include <cstdint>

namespace lam {
	namespace math {

		class AVX3VecI32 {


			public:

			//
			// Default Constructor -- null initilaization
			//
			AVX3VecI32();

			AVX3VecI32(_In_ const int32_t[16]);

			AVX3VecI32(_In_ const int32_t);

			AVX3VecI32(_In_ const int32_t,
					   _In_ const int32_t,
					   _In_ const int32_t,
					   _In_ const int32_t,
					   _In_ const int32_t,
					   _In_ const int32_t,
					   _In_ const int32_t,
					   _In_ const int32_t,
					   _In_ const int32_t,
					   _In_ const int32_t,
					   _In_ const int32_t,
					   _In_ const int32_t,
					   _In_ const int32_t,
					   _In_ const int32_t,
					   _In_ const int32_t,
					   _In_ const int32_t);

			AVX3VecI32(_In_ const __m512i &);

			AVX3VecI32(_In_ const __m256i &,
					   _In_ const __m256i &);

			AVX3VecI32(_In_ const __m512 &);

			AVX3VecI32(_In_ const AVX3VecI32 &);

			~AVX3VecI32() = default;

			//
			//	Getters
			//
			const __m512i get_vi32() const;

			__m512i get_vi32();

			const __m512i* get_ptr() const;

			__m256i get_lo() const;

			__m256i get_hi() const

			//
			//	Load-store member function
			//

			// Address argument must be aligned on 64-byte boundary
			AVX3VecI32 & load_a(_In_ const void* __restrict);

			// Unaligned load
			AVX3VecI32 & load_u(_In_ const void* __restrict);

			// Address argument must be aligned on 64-byte boundary
			void store_a(_In_ void* __restrict) const;

			// Unaligned store
			void store_u(_In_ void* __restrict) const;

			// Stream store
			void stream_store(_In_ void* __restrict) const;

			int32_t extract_scalar(_In_ const uint32_t) const;

			//
			//	Few members and friend operators
			//

			AVX3VecI32 & operator=(_In_ const AVX3VecI32 &);

			// Type cast operator
			operator __m512i () const;

			int32_t operator[](_In_ const uint32_t) const;

			friend std::ostream & operator<<(_In_ std::ostream &,
										     _In_ const AVX3VecI32 &);

			private:

			__m512i m_vi32;
		};

		//
		// Global namespace static functions and operators
		//

		//
		// Extract __m128d part. Value of second parameter
		// must be 0 or 1 only.
		static inline __m256i extract(_In_ AVX3VecI32 &,
									  _In_ const uint32_t);

		// branchless conditional selection
		static inline AVX3VecI32 select(_In_ const AVX3VecI32 &,
									    _In_ const AVX3VecI32 &,
										_In_ const int32_t);

		// broadcast low-packed 32-bit integers
		static inline AVX3VecI32 broadcast(_In_ const __m128i &);

		// permute 32-bit integers
		static inline AVX3VecI32 permute(_In_ const AVX3VecI32 &,
										 _In_ const AVX3VecI32 &);

		// Mask alignr
		static inline AVX3VecI32 mask_alignr(_In_ const AVX3VecI32 &,
										     _In_ const __mmask16,
											 _In_  AVX3VecI32 &,
											 _In_  AVX3VecI32 &,
											 _In_ const int32_t);

		// Mask zero alignr
		static inline AVX3VecI32 maskz_alignr(_In_ const __mmask16,
											  _In_ AVX3VecI32 &,
											  _In_ AVX3VecI32 &,
											  _In_ const int32_t);

		// Vector AND NOT
		static inline AVX3VecI32 and_not(_In_ const AVX3VecI32 &,
										 _In_ const AVX3VecI32 &);



		

		//
		//	Arithmentic operations
		//

		// Vector ABS
		static inline AVX3VecI32 abs(_In_ const AVX3VecI32 &);

		// Horizontal addition of 32-bit integers (reduction)
		static inline int32_t reduce_add(_In_ const AVX3VecI32 &);
											

		// Horizontal multiplication of 32-bit integers (reduction)
		static inline int32_t reduce_mul(_In_ const AVX3VecI32 &)
										    

		// Horizontal bitwise AND of 32-bit integers (reduction)
		static inline int32_t reduce_and(_In_ const AVX3VecI32 &);
											

		// Horizontal bitwise OR of 32-bit integers (reduction)
		static inline int32_t reduce_or(_In_ const AVX3VecI32 &);

		// Reduction by MAX of 32-bit integers
		static inline int32_t reduce_max(_In_ const AVX3VecI32 &);

		// Reduction by MIN of 32-bit integers
		static inline int32_t reduce_min(_In_ const AVX3VecI32 &);

		// Vector MAX
		static inline AVX3VecI32 max(_In_ const AVX3VecI32 &,
									 _In_ const AVX3VecI32 &);

		// Vector MIN
		static inline AVX3VecI32 min(_In_ const AVX3VecI32 &,
								     _In_ const AVX3VecI32 &);

		//
		// Global operators
		//

		static inline AVX3VecI32 operator+(_In_ const AVX3VecI32 &,
									       _In_ const AVX3VecI32 &);

		static inline AVX3VecI32 operator+(_In_ const AVX3VecI32 &,
										   _In_ const int32_t);

		static inline AVX3VecI32 operator+(_In_ const int32_t,
										   _In_ const AVX3VecI32 &);

		static inline AVX3VecI32 operator+=(_In_ AVX3VecI32 &,
										    _In_ const AVX3VecI32 &);

		static inline AVX3VecI32 operator-(_In_ const AVX3VecI32 &,
										   _In_ const AVX3VecI32 &);

		static inline AVX3VecI32 operator-(_In_ const AVX3VecI32 &,
										   _In_ const int32_t);

		static inline AVX3VecI32 operator-(_In_ const int32_t,
										   _In_ const AVX3VecI32 &);

		static inline AVX3VecI32 operator-=(_In_ AVX3VecI32 &,
										    _In_ const AVX3VecI32 &);

		static inline AVX3VecI32 operator*(_In_ const AVX3VecI32 &,
										   _In_ const AVX3VecI32 &);

		static inline AVX3VecI32 operator*(_In_ const AVX3VecI32 &,
										   _In_ const int32_t);

		static inline AVX3VecI32 operator*(_In_ const int32_t,
										   _In_ const AVX3VecI32 &);

		static inline AVX3VecI32 operator*=(_In_ AVX3VecI32 &,
											_In_ const AVX3VecI32 &);

		static inline AVX3VecI32 operator/(_In_ const AVX3VecI32 &,
									       _In_ const AVX3VecI32 &);

		static inline AVX3VecI32 operator/(_In_ const AVX3VecI32 &,
										   _In_ const int32_t);

		static inline AVX3VecI32 operator/(_In_ const int32_t,
										   _In_ const AVX3VecI32 &);

		static inline AVX3VecI32 operator/=(_In_ AVX3VecI32 &,
											_In_ const AVX3VecI32 &);

		static inline AVX3VecI32 operator++(_In_ AVX3VecI32 &);

		static inline AVX3VecI32 operator--(_In_ AVX3VecI32 &);

		static inline AVX3VecI32 operator>>(_In_ const AVX3VecI32 &,
											_In_ const AVX3VecI32 &);

		static inline AVX3VecI32 operator>>(_In_ const AVX3VecI32 &,
											_In_ const int32_t);

		static inline AVX3VecI32 operator>>(_In_ const int32_t,
											_In_ const AVX3VecI32 &);

		static inline AVX3VecI32 operator>>=(_In_ AVX3VecI32 &,
											 _In_ const AVX3VecI32 &);

		static inline AVX3VecI32 operator<<(_In_ const AVX3VecI32 &,
										    _In_ const AVX3VecI32 &);

		static inline AVX3VecI32 operator<<(_In_ const AVX3VecI32 &,
											_In_ const int32_t);

		static inline AVX3VecI32 operator<<(_In_ const int32_t,
											_In_ const AVX3VecI32 &);

		static inline AVX3VecI32 operator<<=(_In_ AVX3VecI32 &,
											 _In_ const AVX3VecI32 &);

		static inline __mmask8   operator!=(_In_ const AVX3VecI32 &,
											_In_ const AVX3VecI32 &);

		static inline __mmask8   operator!=(_In_ const AVX3VecI32 &,
											_In_ const int32_t);

		static inline __mmask8   operator!=(_In_ const int32_t,
											_In_ const AVX3VecI32 &);

		static inline __mmask8   operator==(_In_ const AVX3VecI32 &,
										    _In_ const AVX3VecI32 &);

		static inline __mmask8   operator==(_In_ const AVX3VecI32 &,
											_In_ const int32_t);

		static inline __mmask8   operator==(_In_ const int32_t,
											_In_ const AVX3VecI32 &);

		static inline __mmask8   operator>(_In_ const AVX3VecI32 &,
										   _In_ const AVX3VecI32 &);

		static inline __mmask8   operator>(_In_ const AVX3VecI32 &,
										   _In_ const int32_t);

		static inline __mmask8   operator>(_In_ const int32_t,
										   _In_ const AVX3VecI32 &);

		static inline __mmask8   operator>=(_In_ const AVX3VecI32 &,
											_In_ const AVX3VecI32 &);

		static inline __mmask8   operator>=(_In_ const AVX3VecI32 &,
											_In_ const int32_t);

		static inline __mmask8   operator>=(_In_ const int32_t,
											_In_ const AVX3VecI32 &);

		static inline __mmask8   operator<(_In_ const AVX3VecI32 &,
										   _In_ const AVX3VecI32 &);

		static inline __mmask8   operator<(_In_ const AVX3VecI32 &,
										   _In_ const int32_t);

		static inline __mmask8   operator<(_In_ const int32_t,
										   _In_ const AVX3VecI32 &);

		static inline __mmask8   operator<=(_In_ const AVX3VecI32 &,
										    _In_ const AVX3VecI32 &);

		static inline __mmask8   operator<=(_In_ const AVX3VecI32 &,
										    _In_ const int32_t);

		static inline __mmask8   operator<=(_In_ const int32_t,
											_In_ const AVX3VecI32 &);

		static inline AVX3VecI32 operator&(_In_ const AVX3VecI32 &,
										   _In_ const AVX3VecI32 &);

		static inline AVX3VecI32 operator&=(_In_ AVX3VecI32 &,
											_In_ const AVXVecI32 &);

		static inline AVX3VecI32 operator|(_In_ const AVX3VecI32 &,
										   _In_ const AVX3VecI32 &);

		static inline AVX3VecI32 operator|=(_In_ AVX3VecI32 &,
											_In_ const AVXVecI32 &);

		static inline AVX3VecI32 operator^(_In_ const AVX3VecI32 &,
										   _In_ const AVX3VecI32 &);

		static inline AVX3VecI32 operator^=(_In_ AVX3VecI32 &,
											_In_ const AVXVecI32 &);

#include "LAM_avx3veci32.inl"
	}
}


#endif /*__LAM_AVX3VECI32_H__*/
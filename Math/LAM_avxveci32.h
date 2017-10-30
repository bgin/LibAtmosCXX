
#ifndef __LAM_AVXVECI32_H__
#define __LAM_AVXVECI32_H__

#if !defined (LAM_AVXVECI32_MAJOR)
#define LAM_AVXVECI32_MAJOR 1
#endif

#if !defined (LAM_AVXVECI32_MINOR)
#define LAM_AVXVECI32_MINOR 0
#endif

#if !defined (LAM_AVXVECI32_MICRO)
#define LAM_AVXVECI32_MICRO 0
#endif

#if !defined (LAM_AVXVECI32_FULLVER)
#define LAM_AVXVECI32_FULLVER 1000
#endif

#if !defined (LAM_AVXVECI32_CREATE_DATE)
#define LAM_AVXVECI32_CREATE_DATE "28-10-2017 08:13 +00200 (SAT 28 OCT 2017 GMT+2)"
#endif
//
// Set this value after successful compilation.
//
#if !defined (LAM_AVXVECI32_BUILD_DATE)
#define LAM_AVXVECI32_BUILD_DAGE " "
#endif

#if !defined (LAM_AVXVECI32_AUTHOR)
#define LAM_AVXVECI32_AUTHOR "Programmer: Bernard Gingold e-mail: beniekg@gmail.com"
#endif

#if !defined (LAM_AVXVECI32_DESCRIPT)
#define LAM_AVXVECI32_DESCRIPT "Wrapper class around __m256i int32_t data type"
#endif

/*
	Bernard Gingold copyright notice:
	This file is a part of LibAtmosModelCPP library
	Copyright(C) 2017 Bernard Gingold
	License : GNU General Public Locense version 3 or later,
	for additional information check file LICENSE.txt in
	project directory.
*/

#include "../LAM_simd_defs.h"
#include <iostream>
#include <cstdint>

namespace lam {
	namespace math {

		class AVXVecI32 {


			public:

			//
			// Constructors and default Destructor
			//
			AVXVecI32();

			AVXVecI32(_In_ const int32_t[8]);

			AVXVecI32(_In_ const int32_t);

			AVXVecI32(_In_ const int32_t,
					  _In_ const int32_t,
					  _In_ const int32_t,
					  _In_ const int32_t,
					  _In_ const int32_t,
					  _In_ const int32_t,
					  _In_ const int32_t,
					  _In_ const int32_t);

			AVXVecI32(_In_ const __m256 &);

			AVXVecI32(_In_ const __m256i &);

			AVXVecI32(_In_ const AVXVecI32 &);

			AVXVecI32(_In_  __m128i const* __restrict,
					  _In_  __m128i const* __restrict);

			~AVXVecI32() = default;

			//
			// Getters
			//
			const __m256i get_vi32() const;

			__m256i get_vi32();

			__m128i get_lo() const;

			__m128i get_hi() const;

			//
			// Load-store member functions
			//

			// Address argument should be aligned on 32-byte boundary
			AVXVecI32 & load_a(_In_ const void* __restrict);

			

			// Unaligned memory block
			AVXVecI32 & load_u(_In_ const void* __restrict);

			// Address argument should be aligned on 32-byte boundary
			void store_a(_Inout_ void* __restrict) const;

			// Unaligned memory block
			void store_u(_Inout_ void* __restrict) const;

			void stream_store(_Inout_ void* __restrict) const;

			int32_t extract_scalar(_In_ const uint32_t) const;

			//
			//	Few members and friend operators
			//
			
			AVXVecI32 & operator=(_In_ const AVXVecI32 &);

			operator __m256i() const;

			int32_t operator[](_In_ const uint32_t) const;

			friend std::ostream & operator<<(_In_ std::ostream &,
											 _In_ const AVXVecI32 &);


			private:

			__m256i m_vi32;
		};

		//
		// Global namespace static functions and operators
		//

		//
		// Extract __m128d part. Value of second parameter
		// must be 0 or 1 only.
		static inline __m128i extract(_In_ AVXVecI32 &,
									  _In_ const uint32_t);

		// branchless conditional selection
		static inline AVXVecI32 select(_In_ const AVXVecI32 &,
									   _In_ const AVXVecI32 &,
									   _In_ const int32_t);

	    // broadcast low-packed 32-bit integers
		static inline AVXVecI32 broadcast(_In_ const AVXVecI32 &);

		// permute 32-bit integers
		static inline AVXVecI32 permute(_In_ const AVXVecI32 &,
								        _In_ const AVXVecI32 &);
										

		//
		//	Arithmentic operations
		//

		// Abs of 32-bit integers
		static inline AVXVecI32 abs(_In_ const AVXVecI32 &);

		// Horizontal addition of 32-bit integers
		static inline AVXVecI32 hadd(_In_ const AVXVecI32 &,
									 _In_ const AVXVecI32 &);

		// Horizontal subtraction of 32-bit integers
		static inline AVXVecI32 hsub(_In_ const AVXVecI32 &,
									 _In_ const AVXVecI32 &);

		// Maximum of two 32-bit vectors
		static inline AVXVecI32 max(_In_ const AVXVecI32 &,
									_In_ const AVXVecI32 &);

		// Minimum of two 32-bit vectors
		static inline AVXVecI32 min(_In_ const AVXVecI32 &,
									_In_ const AVXVecI32 &);

		// Sign 
		static inline AVXVecI32 sign(_In_ const AVXVecI32 &,
								     _In_ const AVXVecI32 &);

		//
		// Global operators
		//
		static inline AVXVecI32 operator+(_In_ const AVXVecI32 &,
										  _In_ const AVXVecI32 &);

		static inline AVXVecI32 operator+(_In_ const AVXVecI32 &,
										  _In_ const int32_t);

		static inline AVXVecI32 operator+(_In_ const int32_t,
										  _In_ const AVXVecI32 &);

		static inline AVXVecI32 operator+=(_In_  AVXVecI32 &,
										   _In_ const AVXVecI32 &);

		static inline AVXVecI32 operator-(_In_ const AVXVecI32 &,
										  _In_ const AVXVecI32 &);

		static inline AVXVecI32 operator-(_In_ const AVXVecI32 &,
										  _In_ const int32_t);

		static inline AVXVecI32 operator-(_In_ const int32_t,
										  _In_ const AVXVecI32 &);

		static inline AVXVecI32 operator-(_In_ const AVXVecI32 &);

		static inline AVXVecI32 operator-=(_In_ AVXVecI32 &,
										   _In_ const AVXVecI32 &);

		static inline AVXVecI32 operator*(_In_ const AVXVecI32 &,
										  _In_ const AVXVecI32 &);

		static inline AVXVecI32 operator*(_In_ const AVXVecI32 &,
										  _In_ const int32_t);

		static inline AVXVecI32 operator*(_In_ const int32_t,
										  _In_ const AVXVecI32 &);

		static inline AVXVecI32 operator*=(_In_  AVXVecI32 &,
										   _In_ const AVXVecI32 &);

		static inline AVXVecI32 operator/(_In_ const AVXVecI32 &,
										  _In_ const AVXVecI32 &);

		static inline AVXVecI32 operator/(_In_ const AVXVecI32 &,
										  _In_ const int32_t);

		static inline AVXVecI32 operator/(_In_ const int32_t,
										  _In_ const AVXVecI32 &);

		static inline AVXVecI32 operator/=(_In_ AVXVecI32 &,
										   _In_ const AVXVecI32 &);

		static inline AVXVecI32 operator--(_In_  AVXVecI32 &);

		static inline AVXVecI32 operator++(_In_ AVXVecI32 &);

		static inline AVXVecI32 operator>>(_In_ const AVXVecI32 &,
										   _In_ const AVXVecI32 &);

		static inline AVXVecI32 operator>>(_In_ const AVXVecI32 &,
									       _In_ const uint32_t);

		static inline AVXVecI32 operator>>=(_In_ AVXVecI32 &,
											_In_ const AVXVecI32 &);

		static inline AVXVecI32 operator>>=(_In_ AVXVecI32 &,
									        _In_ const uint32_t);

		static inline AVXVecI32 operator<<(_In_ const AVXVecI32 &,
									       _In_ const AVXVecI32 &);

		static inline AVXVecI32 operator<<(_In_ const AVXVecI32 &,
										   _In_ const uint32_t);

		static inline AVXVecI32 operator<<=(_In_ AVXVecI32 &,
										    _In_ const AVXVecI32 &);

		static inline AVXVecI32 operator<<=(_In_ AVXVecI32 &,
										    _In_ const uint32_t);

		static inline __mmask8 operator!=(_In_ const AVXVecI32 &,
										   _In_ const AVXVecI32 &);

		static inline __mmask8 operator!=(_In_ const AVXVecI32 &,
										  _In_ const int32_t ); 

		static inline __mmask8 operator==(_In_ const AVXVecI32 &,
										   _In_ const AVXVecI32 &);

		static inline __mmask8 operator==(_In_ const AVXVecI32 &,
										  _In_ const int32_t );

		static inline __mmask8 operator>(_In_ const AVXVecI32 &,
										  _In_ const AVXVecI32 &);

		static inline __mmask8 operator>(_In_ const AVXVecI32 &,
										 _In_ const int32_t);

		static inline __mmask8 operator<(_In_ const AVXVecI32 &,
									      _In_ const AVXVecI32 &);

		static inline __mmask8 operator<(_In_ const AVXVecI32 &,
										 _In_ const int32_t );

		static inline AVXVecI32 operator&(_In_ const AVXVecI32 &,
										  _In_ const AVXVecI32 &);

		static inline AVXVecI32 operator&=(_In_  AVXVecI32 &,
										   _In_ const AVXVecI32 &);

		static inline AVXVecI32 operator|(_In_ const AVXVecI32 &,
										  _In_ const AVXVecI32 &);

		static inline AVXVecI32 operator|=(_In_ AVXVecI32 &,
										   _In_ const AVXVecI32 &);

		

		static inline AVXVecI32 operator^(_In_ const AVXVecI32 &,
										  _In_ const AVXVecI32 &);

		static inline AVXVecI32 operator^=(_In_ AVXVecI32 &,
										   _In_ const AVXVecI32 & );

		


#include "LAM_avxveci32.inl"
	}
}

#endif /*__LAM_AVXVECI32_H__*/
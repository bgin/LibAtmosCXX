
#ifndef __LAM_AVX3VECF64_H__
#define __LAM_AVX3VECF64_H__


#if !defined (AVX3VECF64_MAJOR)
#define AVX3VECF64_MAJOR 1
#endif

#if !defined (AVX3VECF64_MINOR)
#define AVX3VECF64_MINOR 0
#endif

#if !defined (AVX3VECF64_MICRO)
#define AVX3VECF64_MICRO 0
#endif

#if !defined (AVX3VECF64_FULLVER)
#define AVX3VECF64_FULLVER 1000
#endif

#if !defined (AVX3VECF64_CREATE_DATE)
#define AVX3VECF64_CREATE_DATE "30-09-2017 10:40 +00200 (SAT 30 SEP 2017 GMT+2)"
#endif
//
//	Set this value to last successful build date/time.
//
#if !defined (AVX3VECF64_BUILD_DATE)
#define AVX3VECF64_BUILD_DATE " "
#endif

#if !defined (AVX3VECF64_AUTHOR)
#define AVX3VECF64_AUTHOR "Programmer: Bernard Gingold e-mail: beniekg@gmail.com"
#endif

#if !defined (AVX3VECF64_DESCRIPT)
#define AVX3VECF64_DESCRIPT "Wrapper class around __m512d data type."
#endif


#include <iostream>
#include <cstdint>
#include <zmmintrin.h>

namespace lam {
	namespace math {

		class AVX3VecF64 {
			
		   public:

		   //
		   // Class Constructors and Destructor
		   //
		   AVX3VecF64();

		   AVX3VecF64(_In_ const double[8]); // Unaligned load

		   AVX3VecF64(_In_ const double);

		   AVX3VecF64(_In_ const double,
					  _In_ const double,
					  _In_ const double,
					  _In_ const double,
					  _In_ const double,
					  _In_ const double,
					  _In_ const double,
					  _In_ const double);

		   AVX3VecF64(_In_ const __m512d);

		   AVX3VecF64(_In_ const __m512i);

		   AVX3VecF64(_In_ const AVX3VecF64 &);

		   AVX3VecF64(_In_ const __m256d,
					  _In_ const __m256d);

		   ~AVX3VecF64() = default;

		   //
		   // getters
		   //
		   const __m512d get_vf64() const;

		   __m512d get_vf64();

		   __m256d lo_part() const;

		   __m256d hi_part() const;

		   //
		   //	Load/store functions
		   //

		   // Address argument should be aligned on 64-byte boundary
		   AVX3VecF64 & load_a(_In_ const double* __restrict);

		   AVX3VecF64 & load_u(_In_ const double* __restrict);

		   // Address argument should be aligned on 64-byte boundary
		   void store_a(_Inout_ double* __restrict) const;

		   void store_u(_Inout_ double* __restrict) const;

		   void stream_store(_Inout_ double* __restrict) const;

		   double extract_scalar(_In_ const uint32_t) const;

		   //
		   // Few member and friend operators
		   //

		   AVX3VecF64 & operator=(_In_ const AVX3VecF64 &);

		   // Type-cast operator
		   operator __m512d () const;

		   double operator[](_In_ const uint32_t) const;

		   friend std::ostream & operator<<(_In_ std::ostream &,
											_In_ const AVX3VecF64 &);


		   private:

		   __m512d m_vf64;

		};

		// Global (namespace) static functions

		// Extract __m256d part only
		static inline __m256d extract(_In_ const AVX3VecF64 &,
									  _In_ const int32_t);

		// Branchless conditional selection
		static inline AVX3VecF64 select(_In_ const AVX3VecF64 &,
								        _In_ const AVX3VecF64 &,
								        _In_ const __mmask8);
		//
		//	Arithmetic and mathematical operations
		//

		// SIMD max
		static inline AVX3VecF64 max(_In_ const AVX3VecF64 &,
									 _In_ const AVX3VecF64 &);

		// SIMD min
		static inline AVX3VecF64 min(_In_ const AVX3VecF64 &,
									 _In_ const AVX3VecF64 &);

	    // SIMD abs
		static inline AVX3VecF64 abs(_In_ const AVX3VecF64 &);

	    // SIMD sqrt
		static inline AVX3VecF64 sqrt(_In_ const AVX3VecF64 &); 

	    // SIMD rsqrt
		static inline AVX3VecF64 rsqrt(_In_ const AVX3VecF64 &);

	    // SIMD cbrt
		static inline AVX3VecF64 cbrt(_In_ const AVX3VecF64 &); 

	    // SIMD squared
		static inline AVX3VecF64 sqr(_In_ const AVX3VecF64 &);

		// Horizontal reduction by addition
		static inline double reduce_add(_In_ const AVX3VecF64 &);
		
		// Horizontal reduction by multiplication
		static inline double reduce_mul(_In_ const AVX3VecF64 &);

		// Horizontal reduction by maximum
		static inline double reduce_max(_In_ const AVX3VecF64 &);

		// Horizontal reduction by minimmum
		static inline double reduce_min(_In_ const AVX3VecF64 &);

	    // SIMD ceil
		static inline AVX3VecF64 ceil(_In_ const AVX3VecF64 &);

	    // SIMD floor
		static inline AVX3VecF64 floor(_In_ const AVX3VecF64 &);

	    // SIMD round
		static inline AVX3VecF64 round(_In_ const AVX3VecF64 &,
									   _In_ const int32_t);

	    // SVML sin
		static inline AVX3VecF64 sin(_In_ const AVX3VecF64 &);

		// SVML sind (degree)
		static inline AVX3VecF64 sind(_In_ const AVX3VecF64 &);

	    // SVML cos
		static inline AVX3VecF64 cos(_In_ const AVX3VecF64 &);

		// SVML cosd (degree)
		static inline AVX3VecF64 cosd(_In_ const AVX3VecF64 &);

	    // SVML sinh
		static inline AVX3VecF64 sinh(_In_ const AVX3VecF64 &);

	    //  SVML cosh
		static inline AVX3VecF64 cosh(_In_ const AVX3VecF64 &);

        // SVML tan
		static inline AVX3VecF64 tan(_In_ const AVX3VecF64 &);

	    // SVML tanh
		static inline AVX3VecF64 tanh(_In_ const AVX3VecF64 &);

		// SVML asin
		static inline AVX3VecF64 asin(_In_ const AVX3VecF64 &);

		// SVML asinh
		static inline AVX3VecF64 asinh(_In_ const AVX3VecF64 &);

		// SVML acos
		static inline AVX3VecF64 acos(_In_ const AVX3VecF64 &);

		// SVML acosh
		static inline AVX3VecF64 acosh(_In_ const AVX3VecF64 &);

		// SVML atan
		static inline AVX3VecF64 atan(_In_ const AVX3VecF64 &);

		// SVML atanh
		static inline AVX3VecF64 atanh(_In_ const AVX3VecF64 &);

		// SVML atan2
		static inline AVX3VecF64 atan2(_In_ const AVX3VecF64 &,
									   _In_ const AVX3VecF64 &);

		// SVML hypot
		static inline AVX3VecF64 hypot(_In_ const AVX3VecF64 &,
									   _In_ const AVX3VecF64 & );

		// FMA functions

		// fmadd
		static inline AVX3VecF64 fmadd(_In_ const AVX3VecF64 &,
									   _In_ const AVX3VecF64 &,
									   _In_ const AVX3VecF64 &);

		// fmadsubb
		static inline AVX3VecF64 fmadsubb(_In_ const AVX3VecF64 &,
										  _In_ const AVX3VecF64 &,
										  _In_ const AVX3VecF64 &);

		// fmsub
		static inline AVX3VecF64 fmsub(_In_ const AVX3VecF64 &,
									   _In_ const AVX3VecF64 &,
									   _In_ const AVX3VecF64 &);

		// fmsubadd
		static inline AVX3VecF64 fmsubadd(_In_ const AVX3VecF64 &,
										  _In_ const AVX3VecF64 &,
										  _In_ const AVX3VecF64 &);

		// fnmadd
		static inline AVX3VecF64 fnmadd(_In_ const AVX3VecF64 &,
										_In_ const AVX3VecF64 &,
										_In_ const AVX3VecF64 &);

		// fnmsub
		static inline AVX3VecF64 fnmsub(_In_ const AVX3VecF64 &,
									    _In_ const AVX3VecF64 &,
										_In_ const AVX3VecF64 &);

		//
		// Global (namespace) operators
		//

		// C = A+B, vector + vector
		static inline AVX3VecF64 operator+(_In_ const AVX3VecF64 &,
										   _In_ const AVX3VecF64 &);

		// C = A+B, vector + scalar
		static inline AVX3VecF64 operator+(_In_ const AVX3VecF64 &,
										   _In_ const double);

		// C = A+B, scalar + vector
		static inline AVX3VecF64 operator+(_In_ const double,
										   _In_ const AVX3VecF64 &);

		// A = A+B (in-place)
		static inline AVX3VecF64 operator+=(_In_  AVX3VecF64 &,
										    _In_ const AVX3VecF64 &);

		// C = A-B, vector-vector
		static inline AVX3VecF64 operator-(_In_ const AVX3VecF64 &,
										   _In_ const AVX3VecF64 &);

		// C = A-B, vector - scalar
		static inline AVX3VecF64 operator-(_In_ const AVX3VecF64 &,
										   _In_ const double);

		// C = A-B, scalar - vector
		static inline AVX3VecF64 operator-(_In_ const double,
										   _In_ const AVX3VecF64 &);

		// A = A-B (in-place)
		static inline AVX3VecF64 operator-=(_In_  AVX3VecF64 &,
											_In_ const AVX3VecF64 &);

		// C = A*B, vector * vector
		static inline AVX3VecF64 operator*(_In_ const AVX3VecF64 &,
										   _In_ const AVX3VecF64 &);

		// C = A*B, vector * scalar
		static inline AVX3VecF64 operator*(_In_ const AVX3VecF64 &,
										   _In_ const double);

		// C = A*B, scalar * vector
		static inline AVX3VecF64 operator*(_In_ const double,
										   _In_ const AVX3VecF64 &);

		// A = A*B (in-place)
		static inline AVX3VecF64 operator*=(_In_  AVX3VecF64 &,
											_In_ const AVX3VecF64 &);

		// C = A/B, vector / vector
		static inline AVX3VecF64 operator/(_In_ const AVX3VecF64 &,
										   _In_ const AVX3VecF64 &);

		// C = A/B, vector / scalar
		static inline AVX3VecF64 operator/(_In_ const AVX3VecF64 &,
										   _In_ const double);

		// C = A/B, scalar / vector
		static inline AVX3VecF64 operator/(_In_ const double,
										   _In_ const AVX3VecF64 &);

		// A = A/B (in-place)
		static inline AVX3VecF64 operator/=(_In_	   AVX3VecF64 &,
											_In_ const AVX3VecF64 &);

		// C = A==B, C is of type __mmask8
		static inline __mmask8 operator==(_In_ const AVX3VecF64 &,
										  _In_ const AVX3VecF64 &);

		// C = A!=B, C is of type __mmask8
		static inline __mmask8 operator!=(_In_ const AVX3VecF64 &,
										  _In_ const AVX3VecF64 &);

		// C = A>B, C is of type __mmask8
		static inline __mmask8 operator>(_In_ const AVX3VecF64 &,
									     _In_ const AVX3VecF64 &);

		// C = A<B, C is of type __mmask8
		static inline __mmask8 operator<(_In_ const AVX3VecF64 &,
										  _In_ const AVX3VecF64 &);

		// C = A>=B, C is of type __mmask8
		static inline __mmask8 operator>=(_In_ const AVX3VecF64 &,
										  _In_ const AVX3VecF64 &);

		// C = A<=B, C is of type __mmask8
		static inline __mmask8 operator<=(_In_ const AVX3VecF64 &,
										  _In_ const AVX3VecF64 &);

		// C = A&B
		static inline AVX3VecF64 operator&(_In_ const AVX3VecF64 &,
										   _In_ const AVX3VecF64 &);

		// A = A&B
		static inline AVX3VecF64 operator&=(_In_ AVX3VecF64 &,
										    _In_ const AVX3VecF64 &);

		// C = A|B
		static inline AVX3VecF64 operator|(_In_ const AVX3VecF64 &,
										   _In_ const AVX3VecF64 &);

		// A = A|B
		static inline AVX3VecF64 operator|=(_In_  AVX3VecF64 &,
										    _In_ const AVX3VecF64 &);

		// C = A^B
		static inline AVX3VecF64 operator^(_In_ const AVX3VecF64 &,
										   _In_ const AVX3VecF64 &);

		// A = A^B
		static inline AVX3VecF64 operator^=(_In_  AVX3VecF64 &,
											_In_ const AVX3VecF64 &);

		// A = A + 1.0
		static inline AVX3VecF64 operator++(_In_  AVX3VecF64 &);

		// A = A - 1.0
		static inline AVX3VecF64 operator--(_In_  AVX3VecF64 &);


#include "LAM_avx3vecf64.inl"
	}
}



#endif /*__LAM_AVX3VECF64_H__*/
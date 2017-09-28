
#ifndef __AVXVECF64_H__
#define __AVXVECF64_H__

#if !defined (AVXVECF64_MAJOR)
#define AVXVECF64_MAJOR 1
#endif

#if !defined (AVXVECF64_MINOR)
#define AVXVECF64_MINOR 0
#endif

#if !defined (AVXVECF64_MICRO)
#define AVXVECF64_MICRO 0
#endif

#if !defined (AVXVECF64_FULLVER)
#define AVXVECF64_FULLVER 1000
#endif

#if !defined (AVXVECF64_CREATE_DATE)
#define AVXVECF64_CREATE_DATE "24-09-2017 11:29 +00200 (SUN 24 SEP 2017 GMT+2)"
#endif

//
//	Set this value to last successful build date/time.
//
#if !defined (AVXVECF64_BUILD_DATE)
#define AVXVECF64_BUILD_DATE " "
#endif

#if !defined (AVXVECF64_AUTHOR)
#define AVXVECF64_AUTHOR "Programmer: Bernard Gingold, e-mail: beniekg@gmail.com"
#endif

#if !defined (AVXVECF64_DESCRIPT)
#define AVXVECF64_DESCRIPT "Wrapper class around __m256d data type."
#endif

#include <iostream>
#include <cstdint>
#include "../LAM_simd_defs.h"

namespace lam{
	namespace math {

		class AVXVecF64 {


			public:

				//
				// Class Constructors and Destructor.
				//
			 	AVXVecF64();

				AVXVecF64(_In_ const double[4]);

				AVXVecF64(_In_ const double, 
						  _In_ const double,
						  _In_ const double,
						  _In_ const double);

				AVXVecF64(_In_ const double);

				AVXVecF64(_In_ const __m256d);

				AVXVecF64(_In_ const __m256i);

				AVXVecF64(_In_ const AVXVecF64 &);

				AVXVecF64(_In_ const __m128d, 
						  _In_ const __m128d);

				~AVXVecF64() = default;

				//
				// getters.
				//
				const __m256d get_vf64() const;

			    __m256d get_vf64();

				__m128d lo_part() const;

			 	__m128d hi_part() const;

				//
				// Load-store functions
				//

				// Address argument should be aligned on 32-byte boundary
				AVXVecF64 & load_a(_In_ const double* __restrict);

				AVXVecF64 & load_u(_In_ const double* __restrict);

				void  store_a(_Inout_ double* __restrict) const;

				void  store_u(_Inout_ double* __restrict) const;

				void  stream_store(_Inout_ double* __restrict) const;

				double extract_scalar(_In_ const uint32_t) const;

				//
				// Few member and friend operators
				//
				AVXVecF64 & operator=(_In_ const AVXVecF64 &);

				

				//
				// Type cast operator
				//
				operator __m256d () const;

				double operator[](_In_ const unsigned int) const;

				friend std::ostream & operator<<(_In_ std::ostream &,
				                                 _In_ const AVXVecF64 &);


			private:

			__m256d m_vf64;
		};

		//
		// global(namespace) static functions
		//

		//
		// Extract __m128d part. Value of second parameter
		// must be 0 or 1 only.
		static inline __m128d extract(_In_ AVXVecF64 &,
									  _In_ const int32_t);

		

		// branchless conditional selection
		static inline AVXVecF64 select_vec(_In_ const AVXVecF64 &, 
										   _In_ const AVXVecF64 &,
										   _In_ const __m256d);
	    
		//
		//	Arithmetic and mathematical operations
		//

		// SIMD max
		static inline AVXVecF64 max(_In_ const AVXVecF64 &, 
								    _In_ const AVXVecF64 &);

		// SIMD min
		static inline AVXVecF64 min(_In_ const AVXVecF64 &,
									_In_ const AVXVecF64 &);

		// SIMD abs
		static inline AVXVecF64 abs(_In_ const AVXVecF64 &);

		// SIMD SQRT
		static inline AVXVecF64 sqrt(_In_ const AVXVecF64 &);

		// SIMD squared
		static inline AVXVecF64 sqr(_In_ const AVXVecF64 &);

		// SIMD ceil
		static inline AVXVecF64 ceil(_In_ const AVXVecF64 &);

		// SIMD floor
		static inline AVXVecF64 floor(_In_ const AVXVecF64 &);

		// SIMD round
		// Caller must pass either 0 or 1.
		static inline AVXVecF64 round(_In_ const AVXVecF64 &, 
									  _In_ const int32_t);
		
		// SVML sin
		static inline AVXVecF64 sin(_In_ const AVXVecF64 &);

		// SVML cos
		static inline AVXVecF64 cos(_In_ const AVXVecF64 &);

		// SVML sinh
		static inline AVXVecF64 sinh(_In_ const AVXVecF64 &);

		// SVML cosh
		static inline AVXVecF64 cosh(_In_ const AVXVecF64 &);

		// SVML tan
		static inline AVXVecF64 tan(_In_ const AVXVecF64 &);

		// SVML tanh
		static inline AVXVecF64 tanh(_In_ const AVXVecF64 &);

		// SVML asin
		static inline AVXVecF64 asin(_In_ const AVXVecF64 &);

		// SVML asinh
		static inline AVXVecF64 asinh(_In_ const AVXVecF64 &);

		// SVML acos
		static inline AVXVecF64 acos(_In_ const AVXVecF64 &);

		// SVML acosh
		static inline AVXVecF64 acosh(_In_ const AVXVecF64 &);

		// SVML atan
		static inline AVXVecF64 atan(_In_ const AVXVecF64 &);

		// SVML atanh
		static inline AVXVecF64 atanh(_In_ const AVXVecF64 &);

		// AVML atan2
		static inline AVXVecF64 atan2(_In_ const AVXVecF64 &, _In_ const AVXVecF64 &);

		// FMA functions

		// fmadd
		static inline AVXVecF64 fmadd(_In_ const AVXVecF64 &, 
									  _In_ const AVXVecF64 &,
									  _In_ const AVXVecF64 &);

		// fmadsubb
		static inline AVXVecF64 fmadsubb(_In_ const AVXVecF64 &,
										 _In_ const AVXVecF64 &,
										 _In_ const AVXVecF64 &);

		// fmsub
		static inline AVXVecF64 fmsub(_In_ const AVXVecF64 &,
									  _In_ const AVXVecF64 &,
									  _In_ const AVXVecF64 &);

		// fmsubadd
		static inline AVXVecF64 fmsubadd(_In_ const AVXVecF64 &,
										 _In_ const AVXVecF64 &,
										 _In_ const AVXVecF64 &);

		// fnmadd
		static inline AVXVecF64 fnmadd(_In_ const AVXVecF64 &,
									   _In_ const AVXVecF64 &,
									   _In_ const AVXVecF64 &);

	   // fnmsub
		static inline AVXVecF64 fnmsub(_In_ const AVXVecF64 &,
									   _In_ const AVXVecF64 &,
									   _In_ const AVXVecF64 &);

		//
		// static operators
		//

		// C = A+B, vector + vector
		static inline AVXVecF64 operator+(_In_ const AVXVecF64 &, 
										  _In_ const AVXVecF64 &);

		// C = A+B, vector + scalar
		static inline AVXVecF64 operator+(_In_ const AVXVecF64 &, 
										  _In_ const double);

		// C = A+B, scalar + vector
		static inline AVXVecF64 operator+(_In_ const double, 
										  _In_ const AVXVecF64 &);

		// A = A+B, vector + vector (in-place)
		static inline AVXVecF64 operator+=(_In_  AVXVecF64 &,
										   _In_ const AVXVecF64 &);

	    // C = A-B, vector - vector
		static inline AVXVecF64 operator-(_In_ const AVXVecF64 &,
										  _In_ const AVXVecF64 &);

		// C = A-B, vector - scalar
		static inline AVXVecF64 operator-(_In_ const AVXVecF64 &, 
										  _In_ const double);

		// C = A-B, scalar - vector
		static inline AVXVecF64 operator-(_In_ const double, 
										  _In_ const AVXVecF64 &);

		// A = A-B, vector - vector (in-place)
		static inline AVXVecF64 operator-=(_In_       AVXVecF64 &, 
										   _In_ const AVXVecF64 &);

		// C = A*B, vector * vector
		static inline AVXVecF64 operator*(_In_ const AVXVecF64 &, 
										  _In_ const AVXVecF64 &);

	    // C = A*B, vector * scalar
		static inline AVXVecF64 operator*(_In_ const AVXVecF64 &,
										  _In_ const double);

		// C = A*B, scalar * vector
		static inline AVXVecF64 operator*(_In_ const double,
										  _In_ const AVXVecF64 &);

		// A = A*B, vector * vector (in-place)
		static inline AVXVecF64 operator*=(_In_		  AVXVecF64 &, 
										   _In_ const AVXVecF64 &);

		// C = A/B, vector / vector
		static inline AVXVecF64 operator/(_In_ const AVXVecF64 &, 
										  _In_ const AVXVecF64 &);

		// C = A/B, vector / scalar
		static inline AVXVecF64 operator/(_In_ const AVXVecF64 &,
										  _In_ const double);

		// C = A/B, scalar / vector
		static inline AVXVecF64 operator/(_In_ const double, 
										  _In_ const AVXVecF64 &);

		// A = A/B, vector / vector (in-place)
		static inline AVXVecF64 operator/=(_In_		  AVXVecF64 &, 
										   _In_ const AVXVecF64 &);

		// C = A==B, vector == vector, C is of type __m256d
		static inline __m256d operator==(_In_ const AVXVecF64 &, 
										 _In_ const AVXVecF64 &);

		// C = A != b, vector != vector, C is of type __m256d
		static inline __m256d operator!=(_In_ const AVXVecF64 &, 
										 _In_ const AVXVecF64 &);

		// C = A>B, vector > vector, C is of type __m256d
		static inline __m256d operator>(_In_ const AVXVecF64 &, 
									    _In_ const AVXVecF64 &);

		// C = A<B, vector < vector, C is of type __m256d
		static inline __m256d operator<(_In_ const AVXVecF64 &, 
									    _In_ const AVXVecF64 &);

		// C = A>=B, vector >= B, C is of type __m256d
		static inline __m256d operator>=(_In_ const AVXVecF64 &, 
										 _In_ const AVXVecF64 &);

		// C = A<=B, vector <= vector, C is of type __m256d
		static inline __m256d operator<=(_In_ const AVXVecF64 &, 
										 _In_ const AVXVecF64 &);

		// C = A&B, vector & vector
		static inline AVXVecF64 operator&(_In_ const AVXVecF64 &,
										  _In_ const AVXVecF64 &);

		
		// A = A&B, vector & vector (in-place)
		static inline AVXVecF64 operator&=(_In_		 AVXVecF64 &,
										   _In_ const AVXVecF64 &);


		// C = A | B, vector | vector
		static inline AVXVecF64 operator|(_In_ const AVXVecF64 &,
										  _In_ const AVXVecF64 &);

		
		// A = A | B, vector | vector
		static inline AVXVecF64 operator|=(_In_ AVXVecF64 &,
										   _In_ const AVXVecF64 &);

		// C = A ^ B, vector ^ vector
		static inline AVXVecF64 operator^(_In_ const AVXVecF64 &,
										  _In_ const AVXVecF64 &);

		// A = A ^ B, vector ^ vector
		static inline AVXVecF64 operator^=(_In_ AVXVecF64 &,
										   _In_ const AVXVecF64 &);


#include "LAM_avxvecf64.inl"
	}
}

#endif /*__AVXVECF64_H__*/
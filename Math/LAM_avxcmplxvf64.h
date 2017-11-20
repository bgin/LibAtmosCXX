
#ifndef __LAM_AVXCMPLXVF64_H__
#define __LAM_AVXCMPLXVF64_H__

#if !defined (LAM_AVXCMPLXVF64_MAJOR)
#define LAM_AVXCMPLXVF64_MAJOR 1
#endif

#if !defined (LAM_AVXCMPLXVF64_MINOR)
#define LAM_AVXCMPLXVF64_MINOR 0
#endif

#if !defined (LAM_AVXCMPLXVF64_MICRO)
#define LAM_AVXCMPLXVF64_MICRO 0
#endif

#if !defined (LAM_AVXCMPLXVF64_FULLVER)
#define LAM_AVXCMPLXVF64_FULLVER 1000
#endif

#if !defined (LAM_AVXCMPLXVF64_CREATE_DATE)
#define LAM_AVXCMPLXVF64_CREATE_DATE "17-11-2017 11:13 +00200 (FRI 17 NOV 2017 GMT+2)"
#endif
//
//	Set this value after successful build date time.
//
#if !defined (LAM_AVXCMPLXVF64_BUILD_DATE)
#define LAM_AVXCMPLXVF64_BUILD_DATE " "
#endif

#if !defined (LAM_AVXCMPLXVF64_AUTHOR)
#define LAM_AVXCMPLXVF64_AUTHOR "Programmer: Bernard Gingold e-mail: beniekg@gmail.com"
#endif

#if !defined (LAM_AVXCMPLXVF64_DESCRIPT)
#define LAM_AVXCMPLXVF64_DESCRIPT "Wrapper class around ADT __m256d which represents 2 complex numbers packed."
#endif

#include <iosfwd>
#include <iomanip>
#include <cstdint>
#include "../LAM_simd_defs.h"



namespace lam {
	namespace math {

		

		class AVXC2vf64 {


			//
			// Constructors and Destructor (default)
			//
			public:

			// Implemented default constructor sets member to 
			// default values (0.0,0.0) , (0.0,0.0)
			AVXC2vf64();

			// Constructor from 4 doubles i.e. re,im,re,im
			AVXC2vf64(_In_ const double,
					  _In_ const double,
					  _In_ const double,
					  _In_ const double);

			// Constructs from single complex number
			AVXC2vf64(_In_ const double,
					  _In_ const double);

			// Construct from single re value
			AVXC2vf64(_In_ const double);

			// Constructs from only real parts
			AVXC2vf64(_In_ const double,
					  _In_ const double,
					  _In_ const double,
					  _In_ const double);

			// Copy-Construcor
			AVXC2vf64(_In_ const AVXC2vf64 &);

			// Converting Constructor from __m256d type.
			AVXC2vf64(_In_ const __m256d &);

			// Destructor default.
			~AVXC2vf64() = default;

			//
			// getters
			//
			const __m256d get_cv64() const;

			__m256d get_cv64();

			__m128d complex_1() const;

			__m128d complex_2() const;

			//
			// Load-store function
			//
			// Address argument should be aligned on 32-byte boundary
			AVXC2vf64 & load_a(_In_ const double * __restrict);

			// Unaligned memory load
			AVXC2vf64 & load_u(_In_ const double * __restrict);

			// Address argument should be aligned on 32-byte boundary
			void store_a(_Inout_ double * __restrict ) const;

			// Unaligned memory store
			void store_u(_Inout_ double * __restrict) const;

			// Stream store (bypass caching stores)
			void stream_store(_Inout_ double * __restrict) const;

			// Extract single component of two packed complex numbers
			double extract_component(_In_ const int32_t ) const;

			// Inserts a single double in location 0...3
			// Based on vectorclass insert function (Agner Fog)
			AVXC2vf64 const & insert(_In_ const int32_t,
									 _In_ const double);

			//
			// Member operators
			//
			AVXC2vf64 & operator=(_In_ const AVXC2vf64 &);

			// Type cast operator
			operator __m256d () const;

			// Subscripting
			double operator[](_In_ const uint32_t) const;

			// ostream
			friend std::ostream & operator<<(_In_ std::ostream &,
											 _In_ const AVXC2vf64 &);
			private:

			//
			// Packed 2-complex numbers i.e. re,im,re,im
			//
			__m256d m_cv64;
		};

		//
		// global(namespace) static functions
		//

		//
		// Extract __m128d part i.e. first or second complex component. Value of second parameter
		// must be 0 or 1 only.
		static inline __m128d extract(_In_ AVXC2vf64 &,
									  _In_ const int32_t);

		// branchless conditional selection
		static inline AVXC2vf64  select(_In_ const AVXC2vf64 &,
										 _In_ const AVXC2vf64 &,
										 _In_ const __m256d &);



		//
		// Global operators
		//

		// C = A+B, complex + complex
		static inline AVXC2vf64  operator+(_In_ const AVXC2vf64 &,
									        _In_ const AVXC2vf64 &);

		// C = A+B, complex + scalar
		static inline AVXC2vf64  operator+(_In_ const AVXC2vf64 &,
											_In_ const double);

		// C = A+B, scalar + complex
		static inline AVXC2vf64  operator+(_In_ const double,
											_In_ const AVXC2vf64 &);

		// A = A+B, complex + complex (in-place)
		static inline AVXC2vf64  operator+=(_In_ AVXC2vf64 &,
											_In_ const AVXC2vf64 &);

		// A = A+B, complex + scalar (in-place)
		static inline AVXC2vf64  operator+=(_In_ AVXC2vf64 &,
										    _In_ const double);

		// A = A+B, scalar + complex (in-place)
		static inline AVXC2vf64  operator+=(_In_ const double,
											_In_ AVXC2vf64 &);

		// C = A-B, complex - complex
		static inline AVXC2vf64  operator-(_In_ const AVXC2vf64 &,
											_In_ const AVXC2vf64 &);

		// C = A-B, complex - scalar
		static inline AVXC2vf64  operator-(_In_ const AVXC2vf64 &,
											_In_ const double);

		// C = A-B, scalar - complex
		static inline AVXC2vf64  operator-(_In_ const double,
										    _In_ const AVXC2vf64 &);

		// A = A-B, complex - complex (in-place)
		static inline AVXC2vf64  operator-=(_In_ AVXC2vf64 &,
											_In_ const AVXC2vf64 &);

		// A = A-B complex - scalar (in-place)
		static inline AVXC2vf64  operator-=(_In_  AVXC2vf64 &,
										    _In_ const double );

		// A = -B scalar - complex (in-place)
		static inline AVXC2vf64  operator-=(_In_ const double,
										    _In_ AVXC2vf64 & );

		// C = A*B, complex * complex
		static inline AVXC2vf64  operator*(_In_ const AVXC2vf64 &,
										    _In_ const AVXC2vf64 &);

	    // C = A*B, complex * scalar
		static inline AVXC2vf64  operator*(_In_ const AVXC2vf64 &,
										    _In_ const double);

		// C = A*B, scalar * complex
		static inline AVXC2vf64  operator*(_In_ const double,
										    _In_ const AVXC2vf64 &);

		// A = A*B, complex * complex (in-place)
		static inline AVXC2vf64  operator*=(_In_  AVXC2vf64 &,
										    _In_ const AVXC2vf64 &);

		// A = A*B complex * scalar (in-place)
		static inline AVXC2vf64 operator*=(_In_ AVXC2vf64 &,
										   _In_ const double);

		// A = A*B scalar * complex (in-place)
		static inline AVXC2vf64 operator*=(_In_ const double,
										   _In_ AVXC2vf64 &);

		// C = A/B, complex / complex
		static inline AVXC2vf64  operator/(_In_ const AVXC2vf64 &,
										    _In_ const AVXC2vf64 &);

		// C = A/B, complex / scalar
		static inline AVXC2vf64  operator/(_In_ const AVXC2vf64 &,
											_In_ const double);

		// C = A/B, scalar / complex
		static inline AVXC2vf64  operator/(_In_ const double,
										    _In_ const AVXC2vf64 &);

		// A = A/B, complex / complex (in-place)
		static inline AVXC2vf64  operator/=(_In_ AVXC2vf64 &,
											 _In_ const AVXC2vf64 &);

		// A = A/B complex / scalar (in-place)
		static inline AVXC2vf64  operator/=(_In_ AVXC2vf64 &,
										    _In_ const double);

		// A = A/B scalar / complex (in-place)
		static inline AVXC2vf64 operator/=(_In_ const double,
										   _In_  AVXC2vf64 &);

		// Complex conjugate.
		static inline AVXC2vf64  operator-(_In_  AVXC2vf64 &);

		// Complex equality ==
		static inline AVXC2vf64  operator==(_In_ const AVXC2vf64 &,
											 _In_ const AVXC2vf64 &);

		// Complex inequality
		static inline AVXC2vf64  operator!=(_In_ const AVXC2vf64 &,
											 _In_ const AVXC2vf64 &);

		// Complex comparison >
		static inline AVXC2vf64  operator>(_In_ const AVXC2vf64 &,
									       _In_ const AVXC2vf64 &);

		// Complex comparison >=
		static inline AVXC2vf64  operator>=(_In_ const AVXC2vf64 &,
											_In_ const AVXC2vf64 &);

		// Complex comparison <
		static inline AVXC2vf64  operator<(_In_ const AVXC2vf64 &,
										   _In_ const AVXC2vf64 &);

		// Complex comparison <=
		static inline AVXC2vf64  operator<=(_In_ const AVXC2vf64 &,
											_In_ const AVXC2vf64 &);



#include "LAM_avxcmplxvf64.inl"
	}
}


#endif /*__LAM_AVXCMPLXF64_H__*/
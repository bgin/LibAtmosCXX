
#ifndef __LAM_AVX3COMPLEX_H__
#define __LAM_AVX3COMPLEX_H__

#if !defined (LAM_AVX3COMPLEX_MAJOR)
#define LAM_AVX3COMPLEX_MAJOR 1
#endif

#if !defined (LAM_AVX3COMPLEX_MINOR)
#define LAM_AVX3COMPLEX_MINOR 0
#endif

#if !defined (LAM_AVX3COMPLEX_MICRO)
#define LAM_AVX3COMPLEX_MICRO 0
#endif

#if !defined (LAM_AVX3COMPLEX_FULLVER)
#define LAM_AVX3COMPLEX_FULLVER 1000
#endif

#if !defined (LAM_AVX3COMPLEX_CREATE_DATE)
#define LAM_AVX3COMPLEX_CREATE_DATE "02-09-2017 09:49 +00200 (SAT 02 SEP 2017 GMT+2)"
#endif

#if !defined (LAM_AVX3COMPLEX_BUILD_DATE)
#define LAM_AVX3COMPLEX_BUILD_DATE " "
#endif

#if !defined (LAM_AVX3COMPLEX_AUTHOR)
#define LAM_AVX3COMPLEX_AUTHOR "Programmer: Bernard Gingold e-mail: beniekg@gmail.com"
#endif

#if !defined (LAM_AVX3COMPLEX_DESCRIPT)
#define LAM_AVX3COMPLEX_DESCRIPT "AVX3(512) manual vectorization of complex-valued arrays."
#endif

//
// Warning:
//				Include these files if and only if you have 
//				CPU and/or Accelarator i.e Xeon Phi which supports AVX3 ISA,
//				otherwise remove these files from compilation.
//

#include "../LAM_stdh.h"
#include <complex>

namespace lam{
	namespace math{

		class AVX512VComplex1D{



			public:

			//
			//	Default Constructor surpressed i.e. 'delete'
			//
			AVX512VComplex1D() = delete;

			//
			// explicit one-arg Constructor which performs default
			// object initialization by allocating member arrays and
			// initialize then by NaN value. This has no mathematical
			// sense, but it mimmicks default initialization.
			// 
			explicit AVX512VComplex1D(_In_ const uint64_t);

			//
			// Main class Constructor which constructor an object
			// by copying the content of Re and Im array components. 
			//
			AVX512VComplex1D(_In_ const uint64_t, 
							 _In_ const double* __restrict,
							 _In_ const double* __restrict);

			//
			// Copy-Constructor implements deep copy semantics.
			//
			AVX512VComplex1D(_In_ const AVX512VComplex1D &);

			//
			// Move-Constructor implements shallow copy semantics
			//
			AVX512VComplex1D(_In_ AVX512VComplex1D &&);

			//
			// Class Destructor.
			//
			~AVX512VComplex1D();

			//
			// ***Class member and friend operators***
			//

			//
			// Copy-assignment implements deep-copy semantics
			//
			AVX512VComplex1D & operator=(_In_ const AVX512VComplex1D &);

			//
			// Copy-assignment implements shallow-copy semantics
			//
			AVX512VComplex1D & operator=(_In_ AVX512VComplex1D &&);

			//
			// Complex addition i.e. *this += x
			//
			AVX512VComplex1D & operator+=(_In_ const AVX512VComplex1D &);

			//
			// Complex addition by array of double scalar values.
			// Size of array of scalars must be equal to this->m_Re
			//
			AVX512VComplex1D & operator+=(_In_ const double* __restrict) noexcept(false);

			//
			// Complex subtraction i.e. *this -= x
			//
			AVX512VComplex1D & operator-=(_In_ const AVX512VComplex1D &) noexcept(false);

			//
			// Complex subtraction by array of double scalar values.
			// Size of array of scalars must be equal to this->m_Re
			//
			AVX512VComplex1D & operator-=(_In_ const double* __restrict) noexcept(false);

			//
			// Complex multiplication i.e. *this *= x
			//
			AVX512VComplex1D & operator*=(_In_ const AVX512VComplex1D &) noexcept(false);

			//
			// AVX512VComplex1D multiplication by array of double
			// scalar values.
			//
			AVX512VComplex1D & operator*=(_In_ const double* __restrict) noexcept(false);

			//
			//	Complex division i.e. *this /= x
			//
			AVX512VComplex1D & operator/=(_In_ const AVX512VComplex1D &) noexcept(false);

			//
			//	Complex division by array of double scalar values.
			//
			AVX512VComplex1D & operator/=(_In_ const double* __restrict) noexcept(false);

			//
			//	Complex equality i.e. *this == x
			//
			std::pair<double*, double*> operator==(_In_ const AVX512VComplex1D &);

			//
			//	Complex inequality i.e. *this != x
			//
			std::pair<double*, double*> operator!=(_In_ const AVX512VComplex1D &);

			//
			// Overloaded operator<< i.e iostream
			//
			friend std::ostream & operator<<(_In_ std::ostream &, _In_ const AVX512VComplex1D &);

			//
			//	Class member computational methods.
			//

			//
			// Normalize *this in place.
			//
			AVX512VComplex1D & vcnormalize(_In_ const AVX512VComplex1D &) noexcept(false);

			//
			// Arithmetic mean of complex-valued vectors
			//
			std::complex<double> vcmean(_In_ const AVX512VComplex1D &) noexcept(false);

			//
			// Magnitude of complex-valued vector (*this)
			//
			void vcmag(_In_ double* __restrict, _In_ const uint64_t) noexcept(false);

			//
			// Calculation of argument in degree.
			// Operating on (*this)
			//
			void vcdeg(_In_ double* __restrict, _In_ const uint64_t) noexcept(false);

			//
			// Calculation of argument in radians.
			// Operating on (*this)
			//
			void vcrad(_In_ double* __restrict, _In_ const uint64_t) noexcept(false);

			//
			// Calculation of power of complex valued vector
			// Operating on (*this)
			//
			void vcpow(_In_ double* __restrict, _In_ const uint64_t) noexcept(false);

			//
			// ***Class getters***
			//

			uint64_t get_nsize() const;

			 double * getRe() const;

			 double * getIm() const;

			bool  get_isbuilt() const;
			

			private:

			// Complex component-wise field size
			uint64_t    m_nsize;

			// Real array
_Field_size_(m_nsize)   double* __restrict m_Re;

			// Imaginary array
_Field_size_(m_nsize)   double* __restrict m_Im;

			// Valid status(build) indicator
			bool         m_isbuilt;

		};

#include "LAM_avx3complex.inl"
	}
}



#endif /*__LAM_AVX3COMPLEX_H__*/
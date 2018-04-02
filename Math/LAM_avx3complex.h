
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
#define LAM_AVX3COMPLEX_DESCRIPT "AVX3(512-bit) manual vectorization of complex-valued arrays."
#endif

//
// Warning:
//				Include these files if and only if you have 
//				CPU and/or Accelarator i.e Xeon Phi which supports AVX3 ISA,
//				otherwise remove these files from compilation.
//

//#include "../LAM_stdh.h"
#include <complex>
#include <cstdint>

namespace lam{
	namespace math{



		struct __declspec(align(64)) AVX512VComplex1D{



			public:

			//
			//	Default Constructor.
			//
			AVX512VComplex1D();

			//
			// explicit one-arg Constructor which performs default
			// object initialization by allocating member arrays and
			// initialize then by NaN value. This has no mathematical
			// sense, but it mimmicks default initialization.
			// 
			explicit AVX512VComplex1D(_In_ const std::uint64_t);

		    
			//
			// Copy-Constructor implements deep copy semantics.
			//
			AVX512VComplex1D(_In_ const AVX512VComplex1D &);

			//
			// Move-Constructor implements shallow copy semantics
			//
			AVX512VComplex1D(_In_ AVX512VComplex1D &&) noexcept;

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
			AVX512VComplex1D & operator=(_In_ AVX512VComplex1D &&) noexcept(true);

			//
			// Complex addition i.e. *this += x
			//
			AVX512VComplex1D & operator+=(_In_ const AVX512VComplex1D &) noexcept(true);
			
			//
			// Complex addition by array of double scalar values.
			// Size of array of scalars must be equal to this->m_Re
			//
			AVX512VComplex1D & operator+=(_In_ const double* __restrict) noexcept(true);

			//
			// Complex subtraction i.e. *this -= x
			//
			AVX512VComplex1D & operator-=(_In_ const AVX512VComplex1D &) noexcept(true);

			//
			// Complex subtraction by array of double scalar values.
			// Size of array of scalars must be equal to this->m_Re
			//
			AVX512VComplex1D & operator-=(_In_ const double* __restrict) noexcept(true);

			//
			// Complex multiplication i.e. *this *= x
			//
			AVX512VComplex1D & operator*=(_In_ const AVX512VComplex1D &) noexcept(true);

			//
			// AVX512VComplex1D multiplication by array of double
			// scalar values.
			//
			AVX512VComplex1D & operator*=(_In_ const double* __restrict) noexcept(true);

			//
			//	Complex division i.e. *this /= x
			//
			AVX512VComplex1D & operator/=(_In_ const AVX512VComplex1D &) noexcept(true);

			//
			//	Complex division by array of double scalar values.
			//
			AVX512VComplex1D & operator/=(_In_ const double* __restrict) noexcept(true);

			//
			//	Complex equality i.e. *this == x
			//
			std::pair< double*, double*> operator==(_In_ const AVX512VComplex1D &);

			//
			//	Complex inequality i.e. *this != x
			//
			std::pair< double*,  double*> operator!=(_In_ const AVX512VComplex1D &);

			//
			// Overloaded operator<< i.e iostream
			//
			friend std::ostream & operator<<(_In_ std::ostream &, _In_ const AVX512VComplex1D &);

			// Complex component-wise field size
			std::uint64_t    m_nsize;

			// Real array
			_Field_size_(m_nsize)   double* __restrict m_Re;

			// Imaginary array
			_Field_size_(m_nsize)   double* __restrict m_Im;


		};	

		

			

			

			
			
			

		

			
		
		

		
		
		
		// 
		// 
	    // Normalization of vector AVX512VComplex1D product.
		// All three arguments must have the same size.
		// No error checking is made on the inputs.
		//
		void v512cnormalize_product(_Inout_ AVX512VComplex1D &, 
									_In_ const AVX512VComplex1D &,
									_In_ const AVX512VComplex1D &) noexcept(true);
		//
		//  Arithmetic mean product of complex-valued vectors
		//  Two AVX512VComplex1D arguments must have the same length.
		//  No error checking is made on the inputs.
		// 
		void v512cmean_product(_Inout_ std::complex<double> &, 
							   _In_ const AVX512VComplex1D  &,
							   _In_ const AVX512VComplex1D  & ) noexcept(true);

	    //
		// Mean complex quotient of AVX512VComplex1D
		// Two AVX512VComplex1D arguments must have the same length.
		// No error checking is made on the inputs.
		// 
		void v512cmean_quotient(_Inout_ std::complex<double> &,
								 _In_ const AVX512VComplex1D &,
								 _In_ const AVX512VComplex1D &) noexcept(true);

		//
		// Conjugate product of AVX512VComplex1D 
		// Three AVX512VComplex1D arguments must have the same length.
		// No error checking is made on the inputs.
		//
		void v512cconj_product(_Inout_ AVX512VComplex1D    &,
							   _In_ const AVX512VComplex1D &,
							   _In_ const AVX512VComplex1D &) noexcept(true);

		//
		// Normalized conjugate product of AVX512VComplex1D 
		// Three AVX512VComplex1D arguments must have the same length.
		// No error checking is made on the inputs.
		//
		void v512cnorm_conjprod(_Inout_ AVX512VComplex1D &,
								 _In_ const AVX512VComplex1D &,
								 _In_ const AVX512VComplex1D &) noexcept(true);

		//
		//	Mean conjugate product of AVX512VComplex1D
		//  Two AVX512VComplex1D arguments must have the sane length.
		//	No error checking is made on the inputs.
		//
		void v512cmean_conjprod(_Inout_ std::complex<double> &,
							    _In_ const AVX512VComplex1D &,
								_In_ const AVX512VComplex1D &) noexcept(true);

		//
		//	Artithmetic mean of complex series (AVX512VComplex1D vectors). 
		//  No error checking is made on the inputs.
		//	Bear in mind that AVX3 reduction will probably
		//  incur some penalty on code execution because
		//  of horizontal addition.
		//
		void v512c_arithmean(_Inout_ std::complex<double> &,
							 _In_ const AVX512VComplex1D &) noexcept(true);

		//
		//	Normalize complex vector
		//	In this case a temporary argument, which
		//  is an exact copy of argument being normalized
		//  is passed to this procedure.
		//  This is done in order to trigger HW prefetcher.
		//  An exact copy should be constructed by calling
		//  class Move Constructor.
		//	All vectors must have the same length.
		//
		void v512c_normalize(_Inout_ AVX512VComplex1D    &,
							 _In_ const AVX512VComplex1D &,
							 _In_ const AVX512VComplex1D &) noexcept(true);

		//
		//	Complex vector magnitude.
		//	In this case a temporary argument, which
		//  is an exact copy of argument being normalized
		//  is passed to this procedure.
		//  This is done in order to trigger HW prefetcher.
		//  An exact copy should be constructed by calling
		//  class Move Constructor.
		//	All 2 vectors and array (double) must have the same length.
		//
		void v512c_magnitude(_Inout_ double * __restrict,
							 _In_ const AVX512VComplex1D &,
							 _In_ const AVX512VComplex1D &) noexcept(true);
	}
}



#endif /*__LAM_AVX3COMPLEX_H__*/

#ifndef __LAM_AVXCOMPLEX_H__
#define __LAM_AVXCOMPLEX_H__

#if !defined (LAM_AVXCOMPLEX_MAJOR)
#define LAM_AVXCOMPLEX_MAJOR 1
#endif

#if !defined (LAM_AVXCOMPLEX_MINOR)
#define LAM_AVXCOMPLEX_MINOR 0
#endif

#if !defined (LAM_AVXCOMPLEX_MICRO)
#define LAM_AVXCOMPLEX_MICRO 0
#endif

#if !defined (LAM_AVXCOMPLEX_FULLVER)
#define LAM_AVXCOMPLEX_FULLVER 1000
#endif

#if !defined (LAM_AVXCOMPLEX_CREATE_DATE)
#define LAM_AVXCOMPLEX_CREATE_DATE "27-08-2017 10:58 +00200 (SUN 27 AUG 2017 GMT+2)"
#endif

/*
	Set this value to latest build date/time
*/
#if !defined (LAM_AVXCOMPLEX_BUILD_DATE)
#define LAM_AVXCOMPLEX_BUILD_DATE ""
#endif

#if !defined (LAM_AVXCOMPLEX_AUTHOR)
#define LAM_AVXCOMPLEX_AUTHOR "Programmer: Bernard Gingold e-mail: beniekg@gmail.com"
#endif

#if !defined (LAM_AVXCOMPLEX_DESCRIPT)
#define LAM_AVXCOMPLEX_DESCRIPT "AVX manual vectorization of complex-valued arrays."
#endif

/*
	Bernard Gingold copyright notice:
	This file is a part of LibAtmosModelCPP library
	Copyright(C) 2017 Bernard Gingold
	License : GNU General Public License version 3 or later,
	for additional information check file LICENSE.txt in
	project directory.
*/



#include <cstdint>
#include <complex>

namespace lam{
	namespace math{

		__declspec(align(64))struct  AVXVComplex1D{

			
			

				/*
					Default Constructor 
				*/
				AVXVComplex1D();

				/*
					Single argument default explicit Constructor
					Initialization of array members to default values i.e. (NaN)
				*/
				explicit AVXVComplex1D(_In_ const uint64_t);

				
				/*
					Copy-Constructor implements deep-copy semantics.
				*/
				AVXVComplex1D(_In_ const AVXVComplex1D &);

				/*
					Move-Constructor implements shallow-copy semantics.
				*/
				AVXVComplex1D(_In_ AVXVComplex1D &&) noexcept(true);

				/*
					Class Destructor
				*/
				~AVXVComplex1D() noexcept(true);

				/*
				    Class member operators
				*/

				/*
				    Copy-assignment operator
				    (deep-copy semantics)
				*/
				AVXVComplex1D & operator=(_In_ const AVXVComplex1D &);

				/*
					Move-assignment operator
					(shallow-copy semantics)
				*/
				AVXVComplex1D & operator=(_In_ AVXVComplex1D &&);

				/*
					Complex addition i.e.
					AVXVComplex1D + AVXVComplex1D
				*/
				AVXVComplex1D & operator+=(_In_ const AVXVComplex1D &);

				/*
					Complex addition by array of double scalar values.
					Size of array of scalars must be equal to this->m_Re
				*/
				AVXVComplex1D & operator+=(_In_ const double* __restrict);

				/*
					Complex subtraction i.e.
					AVXVComplex1D - AVXVComplex1D
				*/
				AVXVComplex1D & operator-=(_In_ const AVXVComplex1D &);

				/*
					Complex subtraction by array of double scalar values.
					Size of array of scalars must be equal to this->m_Re
				*/
				AVXVComplex1D & operator-=(_In_ const double* __restrict);

				/*
					Complex multiplication i.e.
					AVXVComplex1D * AVXVComplex1D
				*/
				AVXVComplex1D & operator*=(_In_ const AVXVComplex1D &);

				/*
					AVXVComplex1D multiplication by array of double
				    scalar values.

				*/
				AVXVComplex1D & operator*=(_In_ const double* __restrict);

				/*
					Complex division i.e.
					AVXVComplex1D / AVXVComplex1D
				*/
				AVXVComplex1D & operator/=(_In_ const AVXVComplex1D &);

				/*
					Complex division by array of double scalar values.

				*/
				AVXVComplex1D & operator/=(_In_ const double* __restrict);


				/*
					Complex equality i.e.
					AVXVComplex1D == AVXVComplex1D
				*/
			    std::pair<double*,double*> operator==(_In_ const AVXVComplex1D &);

				/*
					Complex inequality i.e.
					AVXVComplex1D != AVXVComplex1D
				*/
			    std::pair<double*,double*> operator!=(_In_ const AVXVComplex1D &);

				/*
					Overloaded operator<< i.e iostream
				*/
				friend std::ostream & operator<<(_In_ std::ostream &, 
												  _In_ const AVXVComplex1D &);
				// Complex component-wise field size
				uint64_t m_nsize;

				// Real array
				_Field_size_(m_nsize) double* __restrict m_Re;
				// Imaginary array
				_Field_size_(m_nsize) double* __restrict m_Im;



		};
			

			




			

		

		//
		// Normalization of vecto AVXVComplex1D.
		// Third argument is exact copy of second one
		// 
		// This is needed to trigger HW prefetcher.
		// Both AVXVComplex1D arguments must contain the same data
		// and must no overlap in the memory.
		// All three arguments must have the same size.
		// No error checking is made on the inputs.
		//
		void vcnormalize(_Inout_ AVXVComplex1D &vout, _In_ const AVXVComplex1D &vin, 
						 _In_ const AVXVComplex1D &tmp) noexcept(true);
		//
		// Arithmetic mean of complex-valued vectors
		// Two temporary arrays are needed because
		// one of the AVXVComplex1D arguments will be modified
		// in-place and that means no HW prefetching for this one vector.
		//
		
		void vcmean(_Inout_ std::complex<double> &, _In_ const AVXVComplex1D &v1,
					_In_ const AVXVComplex1D &v2, _Inout_ double * __restrict ,
					_Inout_ double * __restrict, _In_ const uint64_t) noexcept(true);

	   //
	   //	Magnitude of complex valued vector AVXVComplex1D.
	   //	Second and third arguments must be the same
	   //   and must not overlap in the memory.
	   //   This is needed in order to trigger HW Prefetcher
	   //   Both of the argumens (AVXVComplex1D) and out array
	   //   of type double must have the same size (length)
	   //   No error checking is being made on the input
		void vcmag(_Inout_ double * __restrict, _In_ const AVXVComplex1D &,
				   _In_  const AVXVComplex1D &)  noexcept(true);

	   //
	   //  Calculate (convert) complex argument to degree.
	   //  Size of output array must be the same
	   //  as the size of argument (AVXVComplex1D)
	   //  No error checking is performed on inputs.
	   //
		void vcdeg(_Inout_ double * __restrict, _In_ const AVXVComplex1D &) noexcept(true);

	  //
	  //  Calculate (convert) argument to radian
	  //  Size of output array must be the same
	  //  as the size of argument (AVXVComplex1D)
	  //  No error checking is performed on inputs.
	  //
		void vcrad(_Inout_ double * __restrict, _In_ const AVXVComplex1D &) noexcept(true);

	  //
	  //  Calculation of AVXVComplex1D power (power of complex valued vector)
	  //  Size of output array must be the same
	  //  as the size of arguments (AVXVComplex1D)
	  //  Second and third arguments must be the same
	  //  and must not overlap in the memory.
	  //  No error checking is performed on inputs.
	  //
		void vcpow(_Inout_ double * __restrict, _In_ const AVXVComplex1D &,
				   _In_ const AVXVComplex1D &tmp) noexcept(true);
	}
}



#endif /*__LAM_AVXCOMPLEX_H__*/
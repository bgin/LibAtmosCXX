
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

#include "../LAM_config.h"
#include "../LAM_simd_defs.h"
#include "../LAM_stdh.h"
#include <complex>

namespace lam{
	namespace math{

		class AVXVComplex1D{

			
			public:

				/*
					Default Constructor surpressed (delete).
				*/
				AVXVComplex1D() = delete;

				/*
					Single argument default explicit Constructor
					Initialization of array members to default values i.e. (NaN)
				*/
				explicit AVXVComplex1D(_In_ const uint64_t);

				/*
					Main class Constructor.
				*/
				AVXVComplex1D(_In_ const uint64_t, 
							  _In_ const double* __restrict ,
							  _In_ const double* __restrict);

				/*
					Copy-Constructor implements deep-copy semantics.
				*/
				AVXVComplex1D(_In_ const AVXVComplex1D &);

				/*
					Move-Constructor implements shallow-copy semantics.
				*/
				AVXVComplex1D(_In_ AVXVComplex1D &&);

				/*
					Class Destructor
				*/
				~AVXVComplex1D();

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

				/*
					Class member methods
				*/

				//
				// Normalize *this.
				// Normalization is performed in-place
				//
				AVXVComplex1D & vcnormalize(_In_ const AVXVComplex1D &) noexcept(false);

				//
				// Arithmetic mean of complex-valued vectors
				//
				std::complex<double> vcmean(_In_ const AVXVComplex1D &) noexcept(false);

				

				//
				// Magnitude of complex-valued vector (*this)
				//
				void  vcmag(_Inout_ double* __restrict, _In_ const uint64_t) noexcept(false);

				//
				// Calculation of argument in degree.
				// Operating on (*this)
				//
				void vcdeg(_Inout_ double* __restrict, _In_ const uint64_t) noexcept(false);

				//
				// Calculation of argument in radians.
				// Operating on (*this)
				//
				void vcrad(_Inout_ double* __restrict, _In_ const uint64_t) noexcept(false);

				//
				// Calculation of power of complex valued vector
				// Operating on (*this)
				//
				void vcpow(_Inout_ double* __restrict, _In_ const uint64_t) noexcept(false);

				//
				//	Class getters
				//
				uint64_t get_nsize() const;

				double* getRe() const;

				double* getIm() const;

				bool get_isbuilt() const;



			private:

			// Complex component-wise field size
			uint64_t m_nsize;

			// Real array
_Field_size_(m_nsize) double* __restrict m_Re;
			// Imaginary array
_Field_size_(m_nsize) double* __restrict m_Im;

			 // built status
			 bool m_isbuilt;

		};

#include "LAM_avxcomplex.inl"
		
	}
}



#endif /*__LAM_AVXCOMPLEX_H__*/
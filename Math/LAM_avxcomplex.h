
#ifndef __LAM_AVXCOMPLEX_H__
#define __LAM_AVXCOMPLEX_H__

namespace file_info{

#include "../LAM_version.h"

const unsigned int gLAM_AVXCOMPLEX_MAJOR = lam::common::gVersionInfo.m_VersionMajor;

const unsigned int gLAM_AVXCOMPLEX_MINOR = lam::common::gVersionInfo.m_VersionMinor;

const unsigned int gLAM_AVXCOMPLEX_MICRO = lam::common::gVersionInfo.m_VersionMicro;

const unsigned int gLAM_AVXCOMPLEX_FULLVER = 
	1000U*gLAM_AVXCOMPLEX_MAJOR + 100U*gLAM_AVXCOMPLEX_MINOR + 10U*gLAM_AVXCOMPLEX_MICRO;

const char * const pgLAM_AVXCOMPLEX_CREATE_DATE = "27-08-2017 10:58 +00200 (SUN 27 AUG 2017 GMT+2)";

/*
Set this value to latest build date/time
*/
const char * const pgLAM_AVXCOMPLEX_BUILD_DATE =  "00-00-0000 00:00";

const char * const pgLAM_AVXCOMPLEX_AUTHOR  = "Programmer: Bernard Gingold e-mail: beniekg@gmail.com";

const char * const pgLAM_AVXCOMPLEX_DESCRIPT = "AVX manual vectorization of complex-valued arrays.";

}


/*
	Bernard Gingold copyright notice:
	This file is a part of LibAtmosModelCPP library
	Copyright(C) 2017 Bernard Gingold
	License : GNU General Public License version 3 or later,
	for additional information check file LICENSE.txt in
	project directory.
*/



#include <cstdint>

#include "../LAM_config.h"

// Enable non-temporal stores for this class only( used with free-standing operators)
// defaulted to 0.
#if !defined (USE_AVXCOMPLEX_NT_STORES)
#define USE_AVXCOMPLEX_NT_STORES 0
#endif

namespace lam{
	namespace math{

		
		struct AVXVCData{
			
			// Real array
			_Field_size_(m_nsize) __declspec(align(8)) double* __restrict m_Re;
			// Imaginary array
			_Field_size_(m_nsize) __declspec(align(8)) double* __restrict m_Im;

			int32_t				  __declspec(align(4)) m_nsize;

#if (USE_STRUCT_PADDING) == 1
			PAD_TO_ALIGNED(4,0,4)
#endif
#if (USE_STRUCT_PADDING) == 1
		   PAD_TO_ALIGNED(8,1,8)
#endif
		};

		__declspec(align(64)) 
				struct  AVXVComplex1D{ // Start of this struct at 64-byte offset.

			
					__declspec(align(64)) AVXVCData data;

				/*
					Default Constructor 
				*/
				AVXVComplex1D();

				/*
					Single argument default explicit Constructor
					Initialization of array members to default values i.e. (NaN)
				*/
				explicit AVXVComplex1D(_In_ const int32_t);

				AVXVComplex1D(_In_ const double * __restrict,
							  _In_ const double * __restrict,
							  _In_ const int32_t);


				
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

			
		};		


		std::ostream &
		operator<<(_In_ std::ostream &,
				   _In_ const AVXVComplex1D &);
		
		AVXVComplex1D
		operator+(_In_ const AVXVComplex1D &,
				  _In_ const AVXVComplex1D &);

		AVXVComplex1D
		operator+(_In_ const AVXVComplex1D &,
				  _In_ const double * __restrict);

	    AVXVComplex1D
		operator-(_In_ const AVXVComplex1D &,
				  _In_ const AVXVComplex1D &);

		AVXVComplex1D
		operator-(_In_ const AVXVComplex1D &,
				  _In_ const double * __restrict);
			
		AVXVComplex1D
		operator*(_In_ const AVXVComplex1D &,
				  _In_ const AVXVComplex1D &);

		AVXVComplex1D
		operator*(_In_ const AVXVComplex1D &,
				  _In_ const double * __restrict);

		AVXVComplex1D
		operator/(_In_ const AVXVComplex1D &,
				  _In_ const AVXVComplex1D &);

		AVXVComplex1D
		operator/(_In_ const AVXVComplex1D &,
				  _In_ const double * __restrict);

		AVXVComplex1D
		operator==(_In_ const AVXVComplex1D &,
				   _In_ const AVXVComplex1D &);

		AVXVComplex1D
		operator!=(_In_ const AVXVComplex1D &,
				   _In_ const AVXVComplex1D &);

		
		void v256cnormalize_product( _Inout_ AVXVComplex1D &, 
									 _In_ const AVXVComplex1D &, 
									 _In_ const AVXVComplex1D &,
									 _In_ const bool) noexcept(true);
		
		
		void v256cmean_product(_Inout_ std::complex<double> &,
							  _In_ const AVXVComplex1D &v1,
					          _In_ const AVXVComplex1D &v2) noexcept(true);

	  
		void v256cmean_quotient(_Inout_ std::complex<double> &,
						        _In_ const AVXVComplex1D &,
								_In_ const AVXVComplex1D);

	  
		void v256cconj_product(_Inout_ AVXVComplex1D &,
							   _In_ const AVXVComplex1D &,
							   _In_ const AVXVComplex1D &,
							   _In_ const bool);

		void v256cnorm_conjprod(_Inout_ AVXVComplex1D &,
							    _In_ const AVXVComplex1D &,
								_In_ const AVXVComplex1D &,
								_In_ const bool);

		void v256cmean_conjprod(_Inout_ std::complex<double> &,
							    _In_ const AVXVComplex1D &,
								_In_ const AVXVComplex1D &);

		void v256c_arithmean(_Inout_ std::complex<double> &,
							 _In_ const AVXVComplex1D &);

		void v256c_normalize(_Inout_ AVXVComplex1D &,
							 _In_ const AVXVComplex1D &,
							 _In_ const AVXVComplex1D &,
							 _In_ const bool);

		void v256c_magnitude(_Inout_ double * __restrict,
							 _In_ const AVXVComplex1D &,
							 _In_ const AVXVComplex1D &);

	}
}



#endif /*__LAM_AVXCOMPLEX_H__*/
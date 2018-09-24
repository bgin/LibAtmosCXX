
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

		//
		// Normalization of vector AVXVComplex1D.
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
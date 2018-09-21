
#ifndef __LAM_AVX3VCPROCEDURES_H__
#define __LAM_AVX3VCPROCEDURES_H__

namespace file_info {
#include "../LAM_version.h"

	const unsigned int gLAM_AVX3PROCEDURES_MAJOR = lam::common::gVersionInfo.m_VersionMajor;

	const unsigned int gLAM_AVX3PROCEDURES_MINOR = lam::common::gVersionInfo.m_VersionMinor;

	const unsigned int gLAM_AVX3PROCEDURES_MICRO = lam::common::gVersionInfo.m_VersionMicro;

	const unsigned int gLAM_AVX3PROCEDURES_FULLVER = 
		1000U*gLAM_AVX3COMPLEX_MAJOR+100U*gLAM_AVX3COMPLEX_MINOR+10U*gLAM_AVX3COMPLEX_MICRO;

	const char * const pgLAM_AVX3PROCEDURES_CREATE_DATE = "02-04-2018 10:39 +00200 (MON 02 APR 2018 GMT+2)";

	const char * const pgLAM_AVX3PROCEDURES_BUILD_DATE = "00-00-0000 00:00";

	const char * const pgLAM_AVX3PROCEDURES_AUTHOR = "Programmer: Bernard Gingold, contact: beniekg@gmail.com";

	const char * const pgLAM_AVX3PROCEDURES_SYNOPSIS = "Global (namespace) operator-like procedures.";
}


namespace lam {
	namespace math {

class AVX512VComplex1D;
			
		

		
		void
		avx3vcomplex_add(_Inout_ AVX512VComplex1D    &,
						 _In_ const AVX512VComplex1D &,
						 _In_ const AVX512VComplex1D &,
						 _In_ const bool ) noexcept(true);

		
		void
		avx3vcomplex_add(_Inout_ AVX512VComplex1D &,
						 _In_ const AVX512VComplex1D &,
						 _In_ const double * __restrict,
						 _In_ const bool) noexcept(true);

		
		void
		avx3vcomplex_sub(_Inout_ AVX512VComplex1D &,
						 _In_ const AVX512VComplex1D &,
						 _In_ const AVX512VComplex1D &,
						 _In_ const bool) noexcept(true);

	
		void
		avx3vcomplex_sub(_Inout_ AVX512VComplex1D &,
						 _In_ const AVX512VComplex1D &,
						 _In_ const double * __restrict,
						 _In_ const bool) noexcept(true);

	
		void
		avx3vcomplex_mul(_Inout_ AVX512VComplex1D &,
						 _In_ const AVX512VComplex1D &,
						 _In_ const AVX512VComplex1D &,
						 _In_ const bool) noexcept(true);

	
		void
		avx3vcomplex_mul(_Inout_ AVX512VComplex1D &,
						 _In_ const AVX512VComplex1D &,
						 _In_ const double * __restrict,
						 _In_ const bool) noexcept(true);

		void
		avx3vcomplex_div(_Inout_ AVX512VComplex1D	 &, 
						 _In_ const AVX512VComplex1D &,
						 _In_ const AVX512VComplex1D &,
						 _In_ const bool);
						

		
		void
		avx3vcomplex_div(_Inout_ AVX512VComplex1D    &, 
						 _In_ const AVX512VComplex1D &,
						 _In_ const double * __restrict,
						 _In_ const bool) noexcept(true);

	  //
	  //	*********** Procedures which compute equality/inequality of complex series implemented in LAM_avxvcprocedures.cpp ************
	  //
	}
}



#endif /*__LAM_AVX3VCPROCEDURES_H__*/
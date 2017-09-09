
#ifndef __LAM_AVX3VCOPERATORS_H__
#define __LAM_AVX3VCOPERATORS_H__

#if !defined (LAM_AVX3VCOPERATORS_MAJOR)
#define LAM_AVX3VCOPERATORS_MAJOR 1
#endif

#if !defined (LAM_AVX3VCOPERATORS_MINOR)
#define LAM_AVX3VCOPERATORS_MINOR 0
#endif

#if !defined (LAM_AVX3VCOPERATORS_MICRO)
#define LAM_AVX3VCOPERATORS_MICRO 0
#endif

#if !defined (LAM_AVX3VCOPERATORS_FULLVER)
#define LAM_AVX3VCOPERATORS_FULLVER 1000
#endif

#if !defined (LAM_AVX3VCOPERATORS_CREATE_DATE)
#define LAM_AVX3VCOPERATORS_CREATE_DATE "09-09-2017 09:51 +00200 (SAT 09 SEP 2017 GMT+2)"
#endif
//
//	Set this value after successful build date/time.
//
#if !defined (LAM_AVX3VCOPERATORS_BUILD_DATE)
#define LAM_AVX3VCOPERATORS_BUILD_DATE " "
#endif

#if !defined (LAM_AVX3VCOPERATORS_AUTHOR)
#define LAM_AVX3VCOPERATORS_AUTHOR "Programmer: Bernard Gingold e-mail: beniekg@gmail.com"
#endif

#if !defined (LAM_AVX3VCOPERATORS_DESCRIPT)
#define LAM_AVX3VCOPERATORS_DESCRIPT "Global operators acting on AVX512VComplex1D object type."
#endif

//class AVX512VComplex1D;
#include "LAM_avx3complex.h"

namespace lam {
	namespace math {


		/*
		*  Collection of global operators acting on
		*  objects of type AVX512VComplex1D
		*/

		/*
			@Purpose:
						 C = A+B
						 where A is of type: AVX512VComplex1D
						 and   B is of type: AVX512VComplex1D
		*/
		AVX512VComplex1D operator+( const AVX512VComplex1D &, 
								    const AVX512VComplex1D &) noexcept(false);

		/*
			@Purpose:
						C = A+B
						where A is of type: AVX512Complex1D
					    and B is of type: double * __restrict
		    @Remark:
		                Size of double * argument must be
		                equal to size of AVX512Complex1D.m_Re
		*/
		AVX512VComplex1D operator+( const AVX512VComplex1D &,
									const double* __restrict) noexcept(false);

		/*
			@Purpose:
						C = A+B
						where A is of type: double * __restrict
						and B is of type:   AVX512Complex1D
			@Remark:
						Size of double * argument must be
						equal to size of AVX512Complex1D.m_Re
		*/
		AVX512VComplex1D operator+( const double* __restrict,
									const AVX512VComplex1D &) noexcept(false);

		/*
			@Purpose:
						C = A-B
						where A is of type: VComplex1D
						and B is of type:   VComplex1D
		*/
		AVX512VComplex1D operator-( const AVX512VComplex1D &,
									const AVX512VComplex1D &) noexcept(false);

		/*
			@Purpose:
						C = A-B
						where A is of type: AVX512VComplex1D
						and B is of type: double * __restrict
			@Remark:
						Size of double * argument must be
						equal to size of AVX512VComplex1D.m_Re
		*/
		AVX512VComplex1D operator-( const AVX512VComplex1D &,
									const double* __restrict) noexcept(false);

		/*
			@Purpose:
						C = A-B
						where A is of type: double * __restrict
						and B is of type:   AVX512Complex1D
			@Remark:
						Size of double * argument must be
						equal to size of AVX512VComplex1D.m_Re
		*/
		AVX512VComplex1D operator-( const double* __restrict,
									const AVX512VComplex1D &) noexcept(false);

		/*
			@Purpose:
						C = A*B
						where A is of type: AVX512VComplex1D
						and   B is of type: AVX512VComplex1D
		*/
		AVX512VComplex1D operator*( const AVX512VComplex1D &,
									const AVX512VComplex1D &) noexcept(false);

		/*
			@Purpose:
						C = A*B
						where A is of type: AVX512VComplex1D
						and B is of type: double* __restrict
			@Remark:
						Size of double * argument must be
						equal to size of AVX512VComplex1D.m_Re
		*/
		AVX512VComplex1D operator*( const AVX512VComplex1D &,
									const double* __restrict) noexcept(false);

		/*
			@Purpose:
						C = A*B
						where A is of type: double * __restrict
						and B is of type:   AVX512VComplex1D
			@Remark:
						Size of double * argument must be
						equal to size of AVX512VComplex1D.m_Re
		*/
		AVX512VComplex1D operator*( const double* __restrict, 
									const AVX512VComplex1D &) noexcept(false);

		/*
			@Purpose:
						C = A/B
						where A is of type: AVX512VComplex1D
						and B is of type: double * __restrict
			@Remark:
						Size of double * argument must be
						equal to size of AVXVComplex1D.m_Re
		*/
		AVX512VComplex1D operator/( const AVX512VComplex1D &,
									const AVX512VComplex1D &) noexcept(false);

		/*
			@Purpose:
						C = A/B
						where A is of type: double * __restrict
						and B is of type:   AVX512VComplex1D
			@Remark:
						Size of double * argument must be
						equal to size of AVX512VComplex1D.m_Re
		*/
		AVX512VComplex1D operator/( const double* __restrict,
									const AVX512VComplex1D &) noexcept(false);

		/*
			@Purpose:
						C = A==B
						where C is of type: double *
						A is of type: AVX512VComplex1D
						B is of type: AVX512VComplex1D
		*/
		double * operator==( const AVX512VComplex1D &,
							 const AVX512VComplex1D &) noexcept(false);

		/*
			@Purpose:
						C = A!=B
						where C is of type: double *
						A is of type: AVX512VComplex1D
						B is of type: AVX512VComplex1D
		*/
		double * operator!=( const AVX512VComplex1D &,
							 const AVX512VComplex1D &) noexcept(false);



	}
}





#endif /*__LAM_AVX3VCOPERATORS_H__*/
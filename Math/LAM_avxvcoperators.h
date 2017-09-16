
#ifndef __LAM_AVXVCOPERATORS_H__
#define __LAM_AVXVCOPERATORS_H__

#if !defined (LAM_AVXVCOPERATORS_MAJOR)
#define LAM_AVXVCOPERATORS_MAJOR 1
#endif

#if !defined (LAM_AVXVCOPERATORS_MINOR)
#define LAM_AVXVCOPERATORS_MINOR 0
#endif

#if !defined (LAM_AVXVCOPERATORS_MICRO)
#define LAM_AVXVCOPERATORS_MICRO 0
#endif

#if !defined (LAM_AVXVCOPERATORS_FULLVER)
#define LAM_AVXVCOPERATORS_FULLVER 1000
#endif

#if !defined (LAM_AVXVCOPERATORS_CREATE_DATE)
#define LAM_AVXVCOPERATORS_CREATE_DATE "14-09-2017 11:03 +00200 (THR 13 SEP 2017 GMT+2)"
#endif

//
//	Set this value to last successful build date/time.
//
#if !defined (LAM_AVXVCOPERATORS_BUILD_DATE)
#define LAM_AVXVCOPERATORS_BUILD_DATE " "
#endif

#if !defined (LAM_AVXVCOPERATORS_AUTHOR)
#define LAM_AVXVCOPERATORS_AUTHOR "Programmer: Bernard Gingold e-mail: beniekg@gmail.com"
#endif

#if !defined (LAM_AVXVCOPERATORS_DESCRIPT)
#define LAM_AVXVCOPERATORS_DESCRIPT "Global operators acting on object of type AVXVComplex1D."
#endif

#include "LAM_avxcomplex.h"

namespace lam {
	namespace math {

		/*
		 *  Collection of global operators acting on
		 *  objects of type AVXVComplex1D.
		 */

		/*
			@Purpose:
						C = A+B
						where A is of type: AVXVComplex1D
						and   B is of type: AVXVComplex1D
		*/
		AVXVComplex1D operator+(_In_ const AVXVComplex1D &,
								_In_ const AVXVComplex1D &) noexcept(false);

		/*
			@Purpose:
						C = A+B
						where A is of type: AVXVComplex1D
						and B is of type: double * __restrict
			@Remark:
						Size of double * argument must be
						equal to size of AVXVComplex1D.m_Re
		*/
		AVXVComplex1D operator+(_In_ const AVXVComplex1D &,
								_In_ const double* __restrict) noexcept(false);

		/*
			@Purpose:
						C = A+B
						where A is of type: double * __restrict
						and B is of type:   AVXVComplex1D
			@Remark:
						Size of double * argument must be
						equal to size of AVXVComplex1D.m_Re
		*/
		AVXVComplex1D operator+(_In_ const double* __restrict,
								_In_ const AVXVComplex1D &) noexcept(false);

		/*
			@Purpose:
						C = A-B
						where A is of type: AVXVComplex1D
						and B is of type:   AVXVComplex1D
		*/
		AVXVComplex1D operator-(_In_ const AVXVComplex1D &,
								_In_ const AVXVComplex1D &) noexcept(false);

		/*
			@Purpose:
						C = A-B
						where A is of type: AVXVComplex1D
						and B is of type: double * __restrict
			@Remark:
						Size of double * argument must be
						equal to size of AVX512VComplex1D.m_Re
		*/
		AVXVComplex1D operator-(_In_ const AVXVComplex1D &,
								_In_ const double* __restrict) noexcept(false);

		/*
			@Purpose:
						C = A-B
						where A is of type: double * __restrict
						and B is of type:   AVXVComplex1D
			@Remark:
						Size of double * argument must be
						equal to size of AVXVComplex1D.m_Re
		*/
		AVXVComplex1D operator-(_In_ const double* __restrict,
								_In_ const AVXVComplex1D &) noexcept(false);

		/*
			@Purpose:
						C = A*B
						where A is of type: AVX512VComplex1D
						and   B is of type: AVX512VComplex1D
		*/
		AVXVComplex1D operator*(_In_ const AVXVComplex1D &,
								_In_ const AVXVComplex1D &) noexcept(false);

		/*
			@Purpose:
						C = A*B
						where A is of type: AVXVComplex1D
						and B is of type: double* __restrict
			@Remark:
						Size of double * argument must be
						equal to size of AVXVComplex1D.m_Re
		*/
		AVXVComplex1D operator*(_In_ const AVXVComplex1D &,
								_In_ const double* __restrict) noexcept(false);

		/*
			@Purpose:
						C = A*B
						where A is of type: double * __restrict
						and B is of type:   AVXVComplex1D
			@Remark:
						Size of double * argument must be
						equal to size of AVXVComplex1D.m_Re
		*/
		AVXVComplex1D operator*(_In_ const double* __restrict,
								_In_ const AVXVComplex1D &) noexcept(false);

		/*
			@Purpose:
						C = A/B
						where A is of type: AVXVComplex1D
						and B is of type: double * __restrict
			@Remark:
						Size of double * argument must be
						equal to size of AVXVComplex1D.m_Re
		*/
		AVXVComplex1D operator/(_In_ const AVXVComplex1D &,
								_In_ const AVXVComplex1D &) noexcept(false);

		/*
			@Purpose:
						C = A/B
						where A is of type: double * __restrict
						and B is of type:   AVXVComplex1D
			@Remark:
						Size of double * argument must be
						equal to size of AVXVComplex1D.m_Re
		*/
		AVXVComplex1D operator/(_In_ const double* __restrict,
								_In_ const AVXVComplex1D &) noexcept(false);

		/*
			@Purpose:
						C = A==B
						where C is of type: std::pair<double*,double*>
						A is of type: AVXVComplex1D
						B is of type: AVXVComplex1D
		*/
		std::pair<double*, double*> operator==(_In_ const AVXVComplex1D &,
											   _In_ const AVXVComplex1D &) noexcept(false);

		/*
			@Purpose:
						C = A!=B
						where C is of type: std::pair<double*,double*>
						A is of type: AVX512VComplex1D
						B is of type: AVX512VComplex1D
		*/
		std::pair<double*, double*> operator!=(_In_ const AVXVComplex1D &,
											   _In_ const AVXVComplex1D &) noexcept(false);
	}
}

#endif /*__LAM_AVXVCOPERATORS_H__*/
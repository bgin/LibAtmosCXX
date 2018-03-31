
#ifndef __LAM_AVXVCPROCEDURES_H__
#define __LAM_AVXVCPROCEDURES_H__

#if !defined (LAM_AVXVCPROCEDURES_MAJOR)
#define LAM_AVXVCPROCEDURES_MAJOR 1
#endif

#if !defined (LAM_AVXVCPROCEDURES_MINOR)
#define LAM_AVXVCPROCEDURES_MINOR 0
#endif

#if !defined (LAM_AVXVCPROCEDURES_MICRO)
#define LAM_AVXVCPROCEDURES_MICRO 0
#endif

#if !defined (LAM_AVXVCPROCEDURES_FULLVER)
#define LAM_AVXVCPROCEDURES_FULLVER 1000
#endif

#if !defined (LAM_AVXVCPROCEDURES_CREATE_DATE)
#define LAM_AVXVCPROCEDURES_CREATE_DATE "25-03-2018 12:06 +00200 (SUN 25 MAR 2018 GMT+2)"
#endif

//
//	Set this value after successful build date/time
//
#if !defined (LAM_AVXVCPROCEDURES_BUILD_DATE)
#define LAM_AVXVCPROCEDURES_BUILD_DATE " "
#endif

#if !defined (LAM_AVXVCPROCEDURES_AUTHOR)
#define LAM_AVXVCPROCEDURES_AUTHOR "Programmer: Bernard Gingold, e-mail: beniekg@gmail.com"
#endif

#if !defined (LAM_AVXVCPROCEDURES_DESCRIPT)
#define LAM_AVXVCPROCEDURES_DESCRIPT "Global operator-like procedures."
#endif

#include "LAM_avxcomplex.h"


namespace lam{
	namespace math {

		//
		//	Collection of optimized void procedures operating on
		//  objects of type AVXVComplex1D.
		//

		/*
		@Purpose:
					Mimicks this operation -- C = A+B (vectors size obviously must be equal to each other).
					where A is of type: AVXVComplex1D
					and   B is of type: AVXVComplex1D
		@Warning:	
					In order to speed up computation and
					diminish branch predicition misses
					no error checking is implemented.
		*/
		void
		avxvcomplex_add(_Inout_ AVXVComplex1D &, _In_ const AVXVComplex1D & , 
		                _In_ const AVXVComplex1D & )      noexcept(true);

		/*
		@Purpose:
					Mimicks this operation -- C = A+B (vectors size obviously must be equal to each other).
					where A is of type: AVXVComplex1D
					and B is of type: double * __restrict
		@Remark:
					Size of double * argument must be
					equal to size of AVXVComplex1D.m_Re
		@Warning:
					In order to speed up computation and
					diminish branch predicition misses
					no error checking is implemented (usage of conditional if statements)
		*/
		void
		avxvcomplex_add(_Inout_ AVXVComplex1D &, _In_ const AVXVComplex1D &, 
			            _In_ const double * __restrict)    noexcept(true);

		/*
		@Purpose:
					Mimicks this operation -- C = A-B (vectors size obviously must be equal to each other).
					where A is of type: AVXVComplex1D
					and B is of type:   AVXVComplex1D

		@Warning:
					In order to speed up computation and
					diminish branch predicition misses
					no error checking is implemented (usage of conditional if statements)
		*/
		void
		avxvcomplex_sub(_Inout_ AVXVComplex1D &, _In_ const AVXVComplex1D &, 
						_In_  const AVXVComplex1D &)  noexcept(true);

		/*
		@Purpose:
					Mimicks this operation -- C = A-B (vectors size obviously must be equal to each other).
					where A is of type: AVXVComplex1D
					and B is of type: double * __restrict
		@Remark:
					Size of double * argument must be
					equal to size of AVXVComplex1D.m_Re

		@Warning:
					In order to speed up computation and
					diminish branch predicition misses
					no error checking is implemented (usage of conditional if statements)
		*/
		void
		avxvcomplex_sub(_Inout_ AVXVComplex1D &, _In_ const AVXVComplex1D &, 
					   _In_ const double * __restrict)   noexcept(true);

		/*
		@Purpose:
					Mimicks this operation -- C = A*B (vectors size obviously must be equal to each other).
					where A is of type: AVXVComplex1D
					and   B is of type: AVXVComplex1D

		@Warning:
					In order to speed up computation and
					diminish branch predicition misses
					no error checking is implemented (usage of conditional if statements)
		*/
		void avxvcomplex_mul(_Inout_ AVXVComplex1D &, _In_ const AVXVComplex1D &,
							 _In_ const AVXVComplex1D &)  noexcept(true);

		/*
		@Purpose:
					Mimicks this operation -- C = A*B (vectors size obviously must be equal to each other).
					where A is of type: AVXVComplex1D
					and B is of type: double* __restrict
		@Remark:
					Size of double * argument must be
					equal to size of AVXVComplex1D.m_Re

		@Warning:
					In order to speed up computation and
					diminish branch predicition misses
					no error checking is implemented (usage of conditional if statements)
		*/
		void avxvcomplex_mul(_Inout_ AVXVComplex1D &, _In_ const AVXVComplex1D &,
						    _In_ const double * __restrict)   noexcept(true);

		/*
		@Purpose:
					Mimicks this operation -- C = A/B (vectors size obviously must be equal to each other).
					where A is of type: AVXVComplex1D
					and   B is of type: AVXVComplex1D
		@Remark:
					In order to enable HW prefetching additional
					argument of type AVXVComplex1D (copy of third argument)
					is passed.

		@Warning:
					In order to speed up computation and
					diminish branch predicition misses
					no error checking is implemented (usage of conditional if statements)
		*/
		void avxcomplex_div(_Inout_ AVXVComplex1D &, _In_ const AVXVComplex1D &, 
						    _In_ const AVXVComplex1D &, _In_ const AVXVComplex1D &) noexcept(true);

		/*
		@Purpose:
					Mimicks this operation -- C = A/B (vectors size obviously must be equal to each other).
					where A is of type: double * __restrict
					and B is of type:   AVXVComplex1D
		@Remark:
					Size of double * argument must be
					equal to size of AVXVComplex1D.m_Re

		@Warning:
					In order to speed up computation and
					diminish branch predicition misses
					no error checking is implemented (usage of conditional if statements)
		*/
		void avxvcomplex_div(_Inout_ AVXVComplex1D &, _In_ const AVXVComplex1D &,
						     _In_ const double * __restrict) noexcept(true);

		/*
		@Purpose:
					C = A==B (vectors size obviously must be equal to each other).
					where C is represented as two arrays Re[n] == Re[n] , Im[n] == Im[n]
					A is of type: AVXVComplex1D
					B is of type: AVXVComplex1D
		
		@Warning:
					In order to speed up computation and
					diminish branch predicition misses
					no error checking is implemented (usage of conditional if statements)
		*/
		void avxvcomplex_eq(_Inout_ double * __restrict, _Inout_ double * __restrict,
							_In_ const AVXVComplex1D &, _In_ const AVXVComplex1D &) noexcept(true);

		/*
		@Purpose:
					C = A==B (vectors size obviously must be equal to each other).
					where C is represented as two arrays Re[n] != Re[n] , Im[n] != Im[n]
					A is of type: AVXVComplex1D
					B is of type: AVXVComplex1D

		@Warning:
					In order to speed up computation and
					diminish branch predicition misses
					no error checking is implemented (usage of conditional if statements)
		*/
		void avxvcomplex_neq(_Inout_ double * __restrict, _Inout_ double * __restrict,
							 _In_ const AVXVComplex1D &, _In_ const AVXVComplex1D &) noexcept(true);
	}
}

#endif /*__LAM_AVXVCPROCEDURES_H__*/
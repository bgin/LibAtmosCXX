
#ifndef __LAM_AVX3VCPROCEDURES_H__
#define __LAM_AVX3VCPROCEDURES_H__

#if !defined (LAM_AVX3VCPROCEDURES_MAJOR)
#define LAM_AVX3VCPROCEDURES_MAJOR 1
#endif

#if !defined (LAM_AVX3VCPROCEDURES_MINOR)
#define LAM_AVX3VCPROCEDURES_MINOR 0
#endif

#if !defined (LAM_AVX3VCPROCEDURES_MICRO)
#define LAM_AVX3VCPROCEDURES_MICRO 0
#endif

#if !defined (LAM_AVX3VCPROCEDURES_FULLVER)
#define LAM_AVX3VCPROCEDURES_FULLVER 1000
#endif

#if !defined (LAM_AVX3VCPROCEDURES_CREATE_DATE)
#define LAM_AVX3VCPROCEDURES_CREATE_DATE "02-04-2018 10:39 +00200 (MON 02 APR 2018 GMT+2)"
#endif
//
//	Set this value after successful build date/time
//
#if !defined (LAM_AVX3VCPROCEDURES_BUILD_DATE)
#define LAM_AVX3VCPROCEDURES_BUILD_DATE " "
#endif

#if !defined (LAM_AVX3VCPROCEDURES_AUTHOR)
#define LAM_AVX3VCPROCEDURES_AUTHOR "Programmer: Bernard Gingold, e-mail: beniekg@gmail.com"
#endif

#if !defined (LAM_AVX3VCPROCEDURES_DESCRIPT)
#define LAM_AVX3VCPROCEDURES_DESCRIPT "Global (namespace) operator-like procedures."
#endif

#include "LAM_avx3complex.h"

namespace lam {
	namespace math {

			
		//
		//	Collection of optimized void procedures operating on
		//  objects of type AVX512VComplex1D.
		//

//=============================================================================================================//

		/*
		@Purpose:
					Mimicks this operation -- C = A+B (vectors size obviously must be equal to each other).
												  where A is of type: AVX512VComplex1D,
												        B is of type: AVX512VComplex1D,
														C is of type: AVX512VComplex1D (output)
		@Warning:
					In order to speed up computation and
					diminish branch predicition misses
					no error checking is implemented.
		*/
		void
		avx3vcomplex_add(_Inout_ AVX512VComplex1D    &,
						 _In_ const AVX512VComplex1D &,
						 _In_ const AVX512VComplex1D &) noexcept(true);

		/*
		@Purpose:
					Mimicks this operation -- C = A+B (vectors size obviously must be equal to each other).
												  where A is of type: AVX512VComplex1D
												  B is of type: double * __restrict
												  C is of type: AVX512VComplex1D (output)
		
		@Warning:
					In order to speed up computation and
					diminish branch predicition misses
					no error checking is implemented (usage of conditional if statements)
		*/
		void
		avx3vcomplex_add(_Inout_ AVX512VComplex1D &,
						 _In_ const AVX512VComplex1D &,
						 _In_ const double * __restrict) noexcept(true);

		/*
		@Purpose:
					Mimicks this operation -- C = A-B (vectors size obviously must be equal to each other).
												  where A is of type: AVX512VComplex1D
												  B is of type:   AVX512VComplex1D
												  C is of type:   AVX512VComplex1D (output)
		@Warning:
					In order to speed up computation and
					diminish branch predicition misses
					no error checking is implemented (usage of conditional if statements)
		*/
		void
		avx3vcomplex_sub(_Inout_ AVX512VComplex1D &,
						 _In_ const AVX512VComplex1D &,
						 _In_ const AVX512VComplex1D &) noexcept(true);

		/*
		@Purpose:
				 Mimicks this operation -- C = A-B (vectors size obviously must be equal to each other).
											  where A is of type: AVX512VComplex1D
											  B is of type: double * __restrict
											  C is of type: AVX512VComplex1D (output)
		@Remark:
				Size of double * argument must be
				equal to size of AVX512VComplex1D.m_Re

		@Warning:
				In order to speed up computation and
				diminish branch predicition misses
				no error checking is implemented (usage of conditional if statements)
		*/
		void
		avx3vcomplex_sub(_Inout_ AVX512VComplex1D &,
						 _In_ const AVX512VComplex1D &,
						 _In_ const double * __restrict) noexcept(true);

		/*
		@Purpose:
				Mimicks this operation -- C = A*B (vectors size obviously must be equal to each other).
											  where A is of type: AVX512VComplex1D
										      B is of type: AVX512VComplex1D
											  C is of type: AVX512VComplex1D (output)
		@Warning:
				In order to speed up computation and
				diminish branch predicition misses
				no error checking is implemented (usage of conditional if statements)
		*/
		void
		avx3vcomplex_mul(_Inout_ AVX512VComplex1D &,
						 _In_ const AVX512VComplex1D &,
						 _In_ const AVX512VComplex1D &) noexcept(true);

		/*
		@Purpose:
				Mimicks this operation -- C = A*B (vectors size obviously must be equal to each other).
										      where A is of type: AVX512VComplex1D
											  and B is of type: double* __restrict
											  C is of type: AVX512VComplex1D (output)
		@Remark:


		@Warning:
				In order to speed up computation and
				diminish branch predicition misses
				no error checking is implemented (usage of conditional if statements)
		*/
		void
		avx3vcomplex_mul(_Inout_ AVX512VComplex1D &,
						 _In_ const AVX512VComplex1D &,
						 _In_ const double * __restrict) noexcept(true);

		/*
		@Purpose:
				Mimicks this operation -- C = A/B (vectors size obviously must be equal to each other).
												where A is of type: AVX512VComplex1D
												      B is of type: AVX512VComplex1D
													  C is of type: AVX512VComplex1D (output)
		@Remark:
				In order to enable HW prefetching additional
				argument of type AVXVComplex1D (copy of third argument)
				is passed.

		@Warning:
				In order to speed up computation and
				diminish branch predicition misses
				no error checking is implemented (usage of conditional if statements)
		*/
		void
		avx3vcomplex_div(_Inout_ AVX512VComplex1D	 &, 
						 _In_ const AVX512VComplex1D &,
						 _In_ const AVX512VComplex1D &,
						 _In_ const AVX512VComplex1D &);

		/*
		@Purpose:
					Mimicks this operation -- C = A/B (vectors size obviously must be equal to each other).
												  where A is of type: double * __restrict
												  and B is of type:   AVX512VComplex1D
		@Remark:
					Size of double * argument must be
					equal to size of AVX512VComplex1D.m_Re

		@Warning:
					In order to speed up computation and
					diminish branch predicition misses
					no error checking is implemented (usage of conditional if statements)
		*/
		void
		avx3vcomplex_div(_Inout_ AVX512VComplex1D    &, 
						 _In_ const AVX512VComplex1D &,
						 _In_ const double * __restrict) noexcept(true);

	  //
	  //	*********** Procedures which compute equality/inequality of complex series implemented in LAM_avxvcprocedures.cpp ************
	  //
	}
}



#endif /*__LAM_AVX3VCPROCEDURES_H__*/
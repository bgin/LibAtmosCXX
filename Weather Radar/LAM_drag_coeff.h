
#ifndef __LAM_DRAG_COEFF_H__
#define __LAM_DRAG_COEFF_H__

#if !defined (LAM_DRAG_COEFF_MAJOR)
#define LAM_DRAG_COEFF_MAJOR 1
#endif

#if !defined (LAM_DRAG_COEFF_MINOR)
#define LAM_DRAG_COEFF_MINOR 0
#endif

#if !defined (LAM_DRAG_COEFF_MICRO)
#define LAM_DRAG_COEFF_MICRO 0
#endif

#if !defined (LAM_DRAG_COEFF_FULLVER)
#define LAM_DRAG_COEFF_FULLVER 1000
#endif

#if !defined (LAM_DRAG_COEFF_CREATION_DATE)
#define LAM_DRAG_COEFF_CREATION_DATE " 12-08-2018 15:27 +00200 (SUN 12 AUG 2018 GMT+2) "
#endif
//
//  Set this value after successful build date/time
//
#if !defined (LAM_DRAG_COEFF_BUILD_DATE)
#define LAM_DRAG_COEFF_BUILD_DATE " "
#endif

#if !defined (LAM_DRAG_COEFF_AUTHOR)
#define LAM_DRAG_COEFF_AUTHOR "Programmer: Bernard Gingold, contact: beniekg@gmail.com"
#endif

#if !defined (LAM_DRAG_COEFF_DESCRIPT)
#define LAM_DRAG_COEFF_DESCRIPT " Modeling of Drag coefficient."
#endif

	/*
			 This code is based on Fortran 2003 version developed by Bernard Gingold
		     References:
					
							  "Fall Velocities of Hydrometeors in the Atmosphere:
                              Refinements to a Continuous Analytical Power Law "
 
                              VITALY I. KHVOROSTYANOV
                                                  Central Aerological Observatory, Dolgoprudny, Moscow, Russia
                              JUDITH A. CURRY
                                                  School of Earth and Atmospheric Sciences, Georgia Institute of Technology, Atlanta, Georgia 
	*/

#include <cstdint>

namespace lam {
	namespace wsr88d {

		/*
				Computes drag coefficients per single body (hydrometeor)
		        Cd = C0(1 + delta0/Re^0.5)^2
		*/
		void compute_drag_coeff(_Out_  double * __restrict ,
							    _In_   const int32_t,
								_In_   const double * __restrict,
								_In_   const double,
								_In_   const double * __restrict );


		/*
				Calcualtion of Reynolds number (Re)
		*/
		void compute_reynolds_number(_Out_ double * __restrict, 
									 _In_  const int32_t,
									 _In_  const double * __restrict,
									 _In_  const double,
									 _In_  const double * __restrict,
									 _In_  const double * __restrict,
									 _In_  const int32_t,
									 _In_  const int32_t,
									 _In_  const int32_t );

		/*
				  Calculation of Davies (Best) number X
		*/
		void compute_davies_number(_Out_ double * __restrict,
								   _In_  const int32_t,
								   _In_  const double,
								   _In_  const double,
								   _In_  const double * __restrict,
								   _In_  const int32_t,
								   _In_  const int32_t,
								   _In_  const int32_t,
								   _In_  const double,
								   _In_  const double,
								   _In_  const double * __restrict );

		/*
				Calculation of analytical function of X known as a 'aRe'	
		*/
		void compute_aRe(_Out_ double * __restrict ,
						 _In_  double * __restrict,
						 _In_   double * __restrict,
						 _In_  const int32_t,
						 _In_  const double,
						 _In_  const double * __restrict);

		/*
				Calculation of analytical function of X known as a 'bRe'
		*/
		void compute_bRe(_Out_ double * __restrict,
						 _In_  const int32_t,
						 _In_  const double * __restrict,
						 _In_  const double * __restrict);

		/*
			      Calculation of turbulence correction for Re ~ 10.0^3.0
			      Psi - interpolation function implementated as a subroutine.
		*/
		void psi_interpolation(_Out_ double *       __restrict,
							   _In_  const double * __restrict,
							   _In_  const double * __restrict,
							   _In_  const int32_t,
							   _In_  const double,
							   _In_  const double * __restrict);

		/*
				  Calculation of bRe - turbulent correction of (delta bRe)
		*/
		void compute_delta_bRe(_Out_ double * __restrict,
							   _In_  const int32_t,
							   _In_  const double * __restrict,
							   _In_  const double * __restrict,
							   _In_  const double * __restrict,
							   _In_  const double );
	}
}

#endif /*__LAM_DRAG_COEFF_H__*/
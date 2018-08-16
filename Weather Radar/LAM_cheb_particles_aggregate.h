
#ifndef __LAM_CHEB_PARTICLES_AGGREGATE_H__
#define __LAM_CHEB_PARTICLES_AGGREGATE_H__

#if !defined (LAM_CHEB_PARTICLES_AGGREGATE_MAJOR)
#define LAM_CHEB_PARTICLES_AGGREGATE_MAJOR 1
#endif

#if !defined (LAM_CHEB_PARTICLES_AGGREGATE_MINOR)
#define LAM_CHEB_PARTICLES_AGGREGATE_MINOR 0
#endif

#if !defined (LAM_CHEB_PARTICLES_AGGREGATE_MICRO)
#define LAM_CHEB_PARTICLES_AGGREGATE_MICRO 0
#endif

#if !defined (LAM_CHEB_PARTICLES_AGGREGATE_FULLVER)
#define LAM_CHEB_PARTICLES_AGGREGATE_FULLVER 1000
#endif

#if !defined (LAM_CHEB_PARTICLES_AGGREGATE_CREATE_DATE)
#define LAM_CHEB_PARTICLES_AGGREGATE_CREATE_DATE " 13-08-2018 15:33 +00200 (MON 13 AUG 2018 GMT+2) "
#endif

#if !defined (LAM_CHEB_PARTICLES_AGGREGATE_BUILD_DATE)
#define LAM_CHEB_PARTICLES_AGGREGATE_BUILD_DATE " "
#endif

#if !defined (LAM_CHEB_PARTICLES_AGGREGATE_AUTHOR)
#define LAM_CHEB_PARTICLES_AGGREGATE_AUTHOR "Programmer: Bernard Gingold, contact: beniekg@gmail.com"
#endif

#if !defined (LAM_CHEB_PARTICLES_AGGREGATE_DESCRIPT)
#define LAM_CHEB_PARTICLES_AGGREGATE_DESCRIPT " Modeling chebyshev particles as an aggregated ensemble."
#endif

#include <cstdint>

namespace lam {
	namespace wsr88d {
			
		/*
				This code is based on Fortran 2003 version developed by Bernard Gingold
				References:
								'Scattering of Radiation by Moderately Non-Spherical Particles'
								 By A. Mugnai and W.J. Wiscombe (1986)
		*/

		enum class EnsembleShapes : uint32_t {

			 Cylindrical,
			 Spheroidal,
			 Chebyshev

		};



		__declspec(align(64)) struct Chebyshev_paggregate_t {

			/*
				Low-level computational code -- data members are public
			*/

				//  Number of particles  in aggregated emsemble
				int32_t   m_np;

				//  Particles aggregate ID number
				uint32_t  m_ID;

				// Time evolution steps.
				int32_t   m_nt;

				//  maximum number of parametric equation (x-parameter) points.
				int32_t   m_maxx;

				//  maximum number of parametric equation (y-parameter) points.
				int32_t   m_maxy;

				//  maximum number of parametric equation (z-parameter) points.
				int32_t   m_maxz;

				//  maximum number of values per ensemble shape
				int32_t   m_msval;

				//    Hydrometeor type
				uint32_t  m_htype;

				//  Total volume of particles per ensemble
				double    m_tpv;
				
				//   Total particles surface area per ensemble
				double    m_tps;
				
				//    Total particles mass per ensemble
				double    m_tpm;

				//       ! Chebyshev particles shape in aggregated assembly ( (r = r0[1+eTn(cos(theta))])
				//       ![r, np], where r = parametric shape(cross - section), np = n - th particle
				_Field_size_(m_np*m_msval)   double * __restrict  m_pcs;

				//		 Chebyshev particles radii in aggregate ensemble
				_Field_size_(m_np)	         double * __restrict  m_pradii;

				//		 Trajectory of Chebyshev particles ensemble, radial distance component (spherical coordinate system)
				//		 [r, np]
				//	     Computed by simulation code.
				_Field_size_(m_np*m_nt)      double * __restrict  m_prdist;

				//       Trajectory of Chebyshev particles ensemble, theta angle component (spherical coordinate system)
				//       [theta, np]
				//	     Computed by simulation code.
				_Field_size_(m_np*m_nt)      double * __restrict  m_ptheta;

				//       Trajectory of Chebyshev particles ensemble, phi angle component (spherical coordinate system)
				//       [phi, np]
				//	     Computed by simulation code.
				_Field_size_(m_np*m_nt)      double * __restrict  m_pphi;

				//       Chebyshev particles aggregate shape approximated by 3D parametric equations.
				//       Components form location of the particle in the ensemble.
				//	     [3, np], where first dimension represents coordinate components
				//	     second dimension represent number of particles.
				_Field_size_(3*m_np)		 double * __restrict m_pes;

				//	     Chebyshev particles ensemble( per each particle) parametric equation in x - dimension (non-dimensional)
				//		 [paramx, np]
				_Field_size_(m_np*m_maxx)    double * __restrict m_ppx;

				//		  Chebyshev particles ensemble (per each particle)  parametric equation in y  - dimension (non-dimensional)
				//
				_Field_size_(m_np*m_maxy)    double * __restrict m_ppy;

				//        Chebyshev particles ensemble (per each particle)  parametric equation in z  - dimension (non-dimensional)
				//  
				_Field_size_(m_np*m_maxz)    double * __restrict m_ppz;

				//		  Chebyshev particles ensemble fall speed 
				//		  [nt]
				_Field_size_(m_nt)		     double * __restrict m_pfv;

				//
				//	Construction and Destruction
				//

				// Default Constructor, does not have a physical meaning, yet
				// default constructor must be present in order to facilitate
				// an usage of constructs like a std::vector or dynamic allocation.
				Chebyshev_paggregate_t();

				// Main class Constructor -- initialization and allocation
				// of scalar and pointer members.
				// Initialization by default values.
				// Part of computations are performed by member functions.
				Chebyshev_paggregate_t(_In_ const int32_t,
									   _In_ const uint32_t,
									   _In_ const int32_t,
									   _In_ const int32_t,
									   _In_ const int32_t,
									   _In_ const int32_t,
									   _In_ const int32_t,
									   _In_ const uint32_t );

				Chebyshev_paggregate_t(_In_ const Chebyshev_paggregate_t &);

				Chebyshev_paggregate_t(_In_ Chebyshev_paggregate_t &&) noexcept(true);

				~Chebyshev_paggregate_t() noexcept(true);

				Chebyshev_paggregate_t & operator=(_In_ const Chebyshev_paggregate_t &);

				Chebyshev_paggregate_t & operator=(_In_ Chebyshev_paggregate_t &&) noexcept(true);

				void print_object_state() const;

				//
				//				Computational procedures
				//

				/*
						 Compute particles shape as a cross-section
						 This code relies on compuation of radial distance as function of un-perturbed
						 sphere radius, deformity coefficient and T(n) curve.
				*/
				bool compute_cross_section(_In_ const double * __restrict,
										   _In_ const double * __restrict,
										   _In_ const double * __restrict,
										   _In_ const int32_t,
										   _In_ const double,
										   _In_ const double,
										   _In_ const bool,
										   _In_ const bool );

				/*
						  Computation of ensemble shape.
					      As for now only 3 shapes are supported:
					      1) Cylindrical
					      2) Pure spherical
					      3) Chebyshev particle like
				*/
				bool compute_ensemble_shape(_In_ const double, 
											_In_ const double,
											_In_ const EnsembleShapes,
											_In_ const double,
											_In_ const double,
											_In_ const double,
											_In_ const double,
											_In_ const double,
											_In_ const double,
											_In_ const double,
											_In_ const double,
											_In_ const bool,
											_In_ const bool  );

				/*
						  Chebyshev Particles parametric equation in parameter 'x'
					      x = r0[1+- eTn(cos(theta))]sin(theta) cos(phi)
				*/
				bool compute_x_param(_In_ const double * __restrict,
									 _In_ const double * __restrict,
									 _In_ const double * __restrict,
									 _In_ const int32_t,
									 _In_ const double,
									 _In_ const double,
									 _In_ const double,
									 _In_ const double,
									 _In_ const bool,
									 _In_ const bool );

				/*	
						   Chebyshev Particles parametric equation in parameter 'y'
					       y = r0[1+- eTn(cos(theta))]sin(theta) sin(phi)
				*/
				bool compute_y_param(_In_ const double * __restrict,
									 _In_ const double * __restrict,
									 _In_ const double * __restrict,
									 _In_ const int32_t,
									 _In_ const double,
									 _In_ const double,
									 _In_ const double,
									 _In_ const double,
									 _In_ const bool,
									 _In_ const bool );

				/*
					        Chebyshev Particles parametric equation in parameter 'z'
					        z = r0[1+- eTn(cos(theta))]sin(theta)
				*/
				void compute_z_param(_In_ const double * __restrict,
									 _In_ const double * __restrict,
									 _In_ const double * __restrict,
									 _In_ const int32_t,
									 _In_ const double,
									 _In_ const double,
									
									 _In_ const bool );

				/*
							 Computing Chebyshev ensemble particles volume.
							 No argument verification is performed on array arguments like:
							 sphrad,chebn and cdeform (these argument are verified by compute
                                         cross_section subroutine)
				*/
				void compute_ensemble_vol(_In_ const double * __restrict,
										  _In_ const double * __restrict,
										  _In_ const double * __restrict,
										  _In_ const int32_t );

				/*
							  Computes Chebyshev particles surface area (total per ensemble)  
							  No argument verification is performed on array arguments like:
							  sphrad,chebn and cdeform (these argument are verified by compute
                                         cross_section subroutine)
				*/
				void compute_ensemble_surf(_In_ const double * __restrict,
										   _In_ const double * __restrict,
										   _In_ const double * __restrict,
										   _In_ const int32_t );

				/*
							   Vertical falling speed computation based on
							  "Fall Velocities of Hydrometeors in the Atmosphere: 
							   Refinements to Continous Analytical Power Law    "
							    by Vitaliy I. Khvorostyanov and Judith A. Curry
          
							 Adding as an option turbulence correction coefficients.
				*/
				void compute_vertical_fall(_In_ const double * __restrict,
										   _In_ const double * __restrict,
										   _In_ const int32_t,
										   _In_ const double,
										   _In_ const double * __restrict,
										   _In_ const int32_t,
										   _In_ const int32_t,
										   _In_ const int32_t,
										   _In_ const double,
										   _In_ const double,
										   _In_ const double * __restrict,
										   _In_ const double,
										   _In_ const double,
										   _In_ const double * __restrict,
										   _In_ const double * __restrict);
		};
	}
}


#endif /*__LAM_CHEB_PARTICLES_AGGREGATE_H__*/
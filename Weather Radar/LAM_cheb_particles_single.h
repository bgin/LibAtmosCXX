

#ifndef __LAM_CHEB_PARTICLES_SINGLE_H__
#define __LAM_CHEB_PARTICLES_SINGLE_H__

#if !defined (LAM_CHEB_PARTICLES_SINGLE_MAJOR)
#define LAM_CHEB_PARTICLES_SINGLE_MAJOR 1
#endif

#if !defined (LAM_CHEB_PARTICLES_SINGLE_MINOR)
#define LAM_CHEB_PARTICLES_SINGLE_MINOR 0
#endif

#if !defined (LAM_CHEB_PARTICLES_SINGLE_MICRO)
#define LAM_CHEB_PARTICLES_SINGLE_MICRO 0
#endif

#if !defined (LAM_CHEB_PARTICLES_SINGLE_FULLVER)
#define LAM_CHEB_PARTICLES_SINGLE_FULLVER 1000
#endif

#if !defined (LAM_CHEB_PARTICLES_SINGLE_CREATE_DATE)
#define LAM_CHEB_PARTICLES_SINGLE_CREATE_DATE " 09-08-2018 11:07 +00200 (THR 09 AUG 2018 GMT+2) "
#endif

#if !defined (LAM_CHEB_PARTICLES_SINGLE_BUILD_DATE)
#define LAM_CHEB_PARTICLES_SINGLE_BUILD_DATE " "
#endif

#if !defined (LAM_CHEB_PARTICLES_SINGLE_AUTHOR)
#define LAM_CHEB_PARTICLES_SINGLE_AUTHOR "Programmer: Bernard Gingold, contact: beniekg@gmail.com"
#endif

#if !defined (LAM_CHEB_PARTICLES_SINGLE_DESCRIPT)
#define LAM_CHEB_PARTICLES_SINGLE_DESCRIPT "Modeling of Chebyshev particles as  single entities. "
#endif

/*
	  This code is based on Fortran 2003 version developed by Bernard Gingold
	  References:
					         'Scattering of Radiation by Moderately Non-Spherical Particles' 
                              By A. Mugnai and W.J. Wiscombe (1986)
*/


#include <cstdint>

namespace lam {
	namespace wsr88d {

		/*
			Chebyshev particles model (single scattering entities).
		*/

		__declspec(align(64)) struct Chebyshev_psingle_t {



			/*
				Low-level computational code -- data member are public
			*/

			  int32_t  m_np;	  // maximum number of particles per scanning domain

			  int32_t  m_nt;      // number of time steps.

			  int32_t  m_maxx;    // maximum number of parametric equation (x-parameter) points.

			  int32_t  m_maxy;    // maximum number of parametric equation (y-parameter) points.

			  int32_t  m_maxz;    // maximum number of parametric equation (z-parameter) points.

			  int32_t  m_maxsp;   // maximum number of cross-sectional points

			  // Public array member fields in order to eliminate unnecessary copy operations

			  // Particles type   (0 == dust-like,1 == grail,2 == snow,3 == hail, 4 == rain,initialization value == -1)
			  _Field_size_(m_np)         int64_t* __restrict   m_ptypes;  

			  // Chebyshev particles shape (cross-sectional)  i.e.  (r = r0[1+-eTn(cos(theta))])
			  _Field_size_(m_np*m_maxsp) double * __restrict   m_xsect;

			  // Chebyshev particles radii i.e (unperturbed sphere radii)
			  _Field_size_(m_np)		 double * __restrict   m_pradii;

			  //  Trajectory of Chebyshev particles (as a single entities) radial distance time evolution 
			  //  (spherical coordinate system) per scanning domain, [time evolution points, number of particles]
			  // Will be computed by simulation code.
			  _Field_size_(m_np*m_nt)    double * __restrict   m_prdist;

			  // Trajectory of Chebyshev particles(as a single entities) theta spherical coordinate per scanning domain
			  // [time evolution points, number of particles]
			  // Will be computed by simulation code.
			  _Field_size_(m_np*m_nt)    double * __restrict   m_ptheta;


			  //  Trajectory of Chebyshev particles(as a single entities) phi spherical coordinate per scanning domain
			  //  [time evolution points, number of particles]
			  // Will be computed by simulation code. 
			  _Field_size_(m_np*m_nt)    double * __restrict   m_pphi;

			  // Chebyshev particles (single entities) volume.
			  _Field_size_(m_np)		 double * __restrict   m_pvol;

			  // Chebyshev particles(single entities) surface area.
			  _Field_size_(m_np)         double * __restrict   m_psarea;

			  // Chebyshev particles (single enities) parametric equation : parameter 'x'.
			  _Field_size_(m_np*m_maxx)  double * __restrict   m_ppx;

			  // Chebyshev particles (single enities) parametric equation : parameter 'y'.
			  _Field_size_(m_np*m_maxy)  double * __restrict   m_ppy;
			  
			 // Chebyshev particles (single enities) parametric equation : parameter 'z'.
			  _Field_size_(m_np*m_maxz)  double * __restrict   m_ppz;

			 // Chebyshev particles (single entities) vertical falling speed per scanning domain.
			 // [number of evaluation time steps, number of particles per domain]
			  _Field_size_(m_np*m_nt)    double * __restrict   m_pvf;

			 // Chebyshev particles(single entities) surface temperature(time - invariant) (units of Celsius)
			 //	per scanning domain.
			 // Will be computed by simulation code.
			  _Field_size_(m_np)		 double * __restrict   m_ptmp;

			 // Chebyshev particles(single entities) mass(time invariant) (units of miligram).
			 // Will be computed by simulation code.
			  _Field_size_(m_np)		 double * __restrict   m_pmass;

			  //
			  //	Construction and Destruction
			  //

			  // Default Constructor, does not have a physical meaning, yet
			  // default constructor must be present in order to facilitate
			  // an usage of constructs like a std::vector.
			  Chebyshev_psingle_t();

			  // Main class Constructor -- initialization and allocation
			  // of scalar and pointer members.
			  // Initialization by default values.
			  // Part of computations are performed by member functions.
			  Chebyshev_psingle_t(_In_ const int32_t,  
								  _In_ const int32_t,
								  _In_ const int32_t,
								  _In_ const int32_t,
								  _In_ const int32_t,
								  _In_ const int32_t );

			  Chebyshev_psingle_t(_In_ const Chebyshev_psingle_t &);

			  Chebyshev_psingle_t(_In_ Chebyshev_psingle_t &&) noexcept(true);

			  ~Chebyshev_psingle_t() noexcept(true);

			  Chebyshev_psingle_t & operator=(_In_ const Chebyshev_psingle_t &);

			  Chebyshev_psingle_t & operator=(_In_ Chebyshev_psingle_t &&) noexcept(true);

			  void set_ptypes(_In_ const int64_t * __restrict, 
							  _In_ const int32_t );

			  void print_object_state() const;

			  //
			  //	Computational procedures
			  //

			  /*
				  Compute particles shape as a cross-section
				  This code relies on compuation of radial distance as function of un-perturbed
				  sphere radius, deformity coefficient and T(n) curve.
				  The last argument stands for curve type equation
				  1) True for additive i.e. 1 + deform_coeff * cos(T(n) * theta)
				  2) False for subtractive i.e. 1 - deform_coeff * cos(T(n) * theta)
			  */
			  bool  compute_cross_section(_In_ const double * __restrict,   
										  _In_ const double * __restrict,
										  _In_ const double * __restrict,
										  _In_ const int32_t, 
										  _In_ const double,
										  _In_ const double,
										  _In_ const bool,
										  _In_ const bool			);

			  /*
				 Computing Chebyshev particles volume per scanning domain.
                 No argument verification is performed on array arguments like:
                 sphrad,chebn and cdeform (these argument are verified by compute
                                         cross_section subroutine)
			  */
			  void compute_volume(_In_ const double * __restrict,
									        _In_ const double * __restrict,
											_In_ const double * __restrict,
											_In_ const int32_t);

			  /*
				      Computes Chebyshev particles surface area   
                      No argument verification is performed on array arguments like:
                      sphrad,chebn and cdeform (these argument are verified by compute
                                        cross_section subroutine)
			  */
			  void compute_surface_area(_In_ const double * __restrict,
										_In_ const double * __restrict,
										_In_ const double * __restrict,
										_In_ const int32_t );

			  /*
					     Chebyshev Particles parametric equation in parameter 'x'
					     x = r0[1+- eTn(cos(theta))]sin(theta) cos(phi)
						 The last argument stands for curve type equation
						 1) True for additive i.e. x = r0[1 + eTn(cos(theta))]sin(theta) cos(phi)
						 2) False for subtractive i.e. x = r0[1 - eTn(cos(theta))]sin(theta) cos(phi)
			  */
			  bool compute_x_param(_In_ const double * __restrict , 
								   _In_ const double * __restrict ,
								   _In_ const double * __restrict ,
								   _In_ const int32_t,
								   _In_ const double,
								   _In_ const double,
								   _In_ const double,
								   _In_ const double,
								   _In_ const bool,
								   _In_ const bool   );

			  /*	
					 Chebyshev Particles parametric equation in parameter 'y'
				     x = r0[1+- eTn(cos(theta))]sin(theta) sin(phi)
					 The last argument stands for curve type equation
					 1) True for additive i.e. y = r0[1 + eTn(cos(theta))]sin(theta) sin(phi)
					 2) False for subtractive i.e. y = r0[1 - eTn(cos(theta))]sin(theta) sin(phi)
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
					 The last argument stands for curve type equation
					 1) True for additive i.e. y = r0[1 + eTn(cos(theta))]sin(theta) 
					 2) False for subtractive i.e. y = r0[1 - eTn(cos(theta))]sin(theta) 
			  */
			  bool compute_z_param(_In_ const double * __restrict,
								   _In_ const double * __restrict,
								   _In_ const double * __restrict,
								   _In_ const int32_t,
								   _In_ const double,
								   _In_ const double,
								   _In_ const bool,
								   _In_ const bool );

			  /*
					  Vertical falling speed computation based on
					  "Fall Velocities of Hydrometeors in the Atmosphere: 
					   Refinements to Continous Analytical Power Law    "
					   by Vitaliy I. Khvorostyanov and Judith A. Curry
          
                       Adding as an option turbulence correction coefficients.
			  */
			  void compute_vfall(_In_ const double * __restrict ,
								 _In_ const double * __restrict,
								 _In_ const double * __restrict,
								 _In_ const double * __restrict,
								 _In_ const int32_t,
								 _In_ const int32_t,
								 _In_ const int32_t,
								 _In_ const int32_t,
								 _In_ const int32_t,
								 _In_ const double * __restrict,
								 _In_ const double * __restrict,
								 _In_ const double * __restrict,
								 _In_ const double,
								 _In_ const double * __restrict,
								 _In_ const double * __restrict,
								 _In_ const double * __restrict);




		};
	}
}


#endif /*__LAM_CHEB_PARTICLES_SINGLE_H__*/
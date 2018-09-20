
#ifndef __LAM_TMATRIX_MPS_WRAPPER_H__
#define __LAM_TMATRIX_MPS_WRAPPER_H__

namespace file_info {
#include "../LAM_version.h"
	
	const unsigned int gLAM_TMATRIX_MPS_WRAPPER_MAJOR = 1U;

	const unsigned int gLAM_TMATRIX_MPS_WRAPPER_MINOR = 0U;

	const unsigned int gLAM_TMATRIX_MPS_WRAPPER_MICRO = 0U;

	const unsigned int gLAM_TMATRIX_MPS_WRAPPER_FULLVER = 
		1000U*gLAM_TMATRIX_MPS_WRAPPER_MAJOR+100U*gLAM_TMATRIX_MPS_WRAPPER_MINOR+10*gLAM_TMATRIX_MPS_WRAPPER_MICRO;

	const char * const pgLAM_TMATRIX_MPS_WRAPPER_CREATE_DATE = "20-09-2018 09:08 +00200 (THR 20 SEP 2018 GMT+2)"; 

	const char * const pgLAM_TMATRIX_MPS_WRAPPER_BUILD_DATE = "00-00-0000 00:00";

	const char * const pgLAM_TMATRIX_MPS_WRAPPER_AUTHOR = "Programmer: Bernard Gingold, contact: beniekg@gmail.com";

	const char * const pgLAM_TMATRIX_MPS_WRAPPER_SYNOPSIS = "C++ wrapper around Fortran driver: TMATRIX_MPS_DRIVER";

}

#include <cstdint>
#include "../LAM_common.h"
//#include "../LAM_config.h"
#include "LAM_tmatrix_ensemble_iface.h"


namespace lam {
	namespace wsr88d {

		template<int32_t N,
		int32_t NLP> 
		struct __declspec(align(64)) TMatrixMPSParams {
				
			/*
			     Paramter arrays used in looped calls to
				 tmatrix_mps_driver.
			*/
			/*
				idshp(i) - to specify particle shape 
					     0 for a sphere, -1 for a spheroid, -2 for a finite cylinder, ... 
						 idshp>0 for Chebyshev particles, which is the degree
	                     of the Chebyshev polynomial
			*/
			__declspec(align(64)) static int32_t  n_idshp[N][NLP]; 
			/*
				  shp(1) -- to specify the aspect ratio of a nonspherical
!C                particle (the parameter EPS in Mishchenko's 
!C               "ampld.new.f" code), 
!C                for a spheroid, it is the ratio of the horizontal to 
!C                    rotational axises 
!C                for a finite circular cylinder, it is the 
!C                    diameter-to-length ratio
!C                for Chebyshev particles, it is the deformation 
!C                    parameter
!C                for spheres, it is ineffective and can be set to 0
!C             shp(2) and shp(3) -- the azimuth and zenith angles of the 
!C                axis of rotational symmetry of a nonspherical particle
!C                to specify its orientation, i.e., the Euler angles of 
!C                alpha and beta to rotate the coordinate system so that 
!C                the z axis after rotation is along the axis of 
!C                rotational symmetry of the particle
!C                for spheres, simply put shp(2)=shp(3)=0 
			*/
			__declspec(align(64)) static double   n_shp[N][3*NLP];

			/*
				  x,y,z -- the Cartesian coordinates of a particle-center
!C             r -- equivalent-sphere radius to specify particle size, 
!C                for spherical particles, it is the real sphere radius 
!C             Re(m), Im(m) -- the real and imaginary parts of the 
!C               refractive index of a particle 
!C                (for a core-mantle sphere, these refer to the mantle)
!C             rc, Rec(m), Imc(m) -- effective for a core-mantle sphere 
!C                only, which are the radius, real and imaginary parts
!C                of the refractive index of the core of a core-mantle  
!C                sphere; for all other types of particles these three 
!C                parameters are ineffective and can simply be set to 0	
			*/
			__declspec(align(64)) static double   n_r0[N][9*NLP];

		};

		template<int32_t NLP> 
	    struct __declspec(align(64)) TMatrixMPS {

			  static constexpr int32_t NANGMAX = 1801;

			__declspec(align(4))  int32_t   pad;

			__declspec(align(4))  int32_t   m_nlp;

			__declspec(align(8))  double    m_cext;

			__declspec(align(8))  double    m_cabs;

			__declspec(align(8))  double    m_csca;

			__declspec(align(8))  double    m_assym;

			__declspec(align(8))  double    m_cextv;

			__declspec(align(8))  double    m_cabsv;

			__declspec(align(8))  double    m_cscav;

			__declspec(align(8))  double    m_cbakv;

			__declspec(align(8))  double    m_cprv;

			__declspec(align(8))  double    m_cexts;

			__declspec(align(8))  double    m_cabss;

			__declspec(align(8))  double    m_cscas;

			__declspec(align(8))  double    m_cbaks;

			__declspec(align(8))  double    m_cprs;

			__declspec(align(64)) double    m_dang[NANGMAX];

			__declspec(align(64)) double    m_inat[NANGMAX];

			__declspec(align(64)) double    m_pol[NANGMAX];

			__declspec(align(64)) double    m_i11[NANGMAX];

			__declspec(align(64)) double    m_i21[NANGMAX];

			__declspec(align(64)) double    m_i12[NANGMAX];

			__declspec(align(64)) double    m_i22[NANGMAX];

			__declspec(align(64)) double    m_cexti[NLP];

			__declspec(align(64)) double    m_cabsi[NLP];

			__declspec(align(64)) double    m_cscai[NLP];

			__declspec(align(64)) double    m_assymi[NLP];

			__declspec(align(64)) double    m_cpri[NLP];

			__declspec(align(64)) double    m_mue[4*4*NANGMAX];

			TMatrixMPS() noexcept(true) {

				using namespace lam::common;
				m_nlp   = NLP;
				m_cext  = 0.0;
				m_cabs  = 0.0;
				m_csca  = 0.0;
				m_assym = 0.0;
				m_cextv = 0.0;
				m_cabsv = 0.0;
				m_cscav = 0.0;
				m_cbakv = 0.0;
				m_cprv  = 0.0;
				m_cexts = 0.0;
				m_cabss = 0.0;
				m_cscas = 0.0;
				m_cbaks = 0.0;
				m_cprs  = 0.0;
				// Memory first touch.
				avx256_init_unroll2x(&m_dang[0],NANGMAX,0.0);
				avx256_init_unroll2x(&m_inat[0],NANGMAX,0.0);
				avx256_init_unroll2x(&m_pol[0],NANGMAX,0.0);
				avx256_init_unroll2x(&m_i11[0],NANGMAX,0.0);
				avx256_init_unroll2x(&m_i21[0],NANGMAX,0.0);
				avx256_init_unroll2x(&m_i12[0],NANGMAX,0.0);
				avx256_init_unroll2x(&m_i22[0],NANGMAX,0.0);
				avx256_init_unroll2x(&m_cexti[0],m_nlp,0.0);
				avx256_init_unroll2x(&m_cabsi[0],m_nlp,0.0);
				avx256_init_unroll2x(&m_cscai[0],m_nlp,0.0);
				avx256_init_unroll2x(&m_assymi[0],m_nlp,0.0);
				avx256_init_unroll2x(&m_cpri[0],m_nlp,0.0);
				avx256_init_unroll2x(&m_mue[0], (4*4*NANGMAX),0.0);
			}
			
			TMatrixMPS(_In_ const TMatrixMPS &x) {
				using namespace lam::common;
				m_nlp   = x.m_nlp;
				m_cext  = x.m_cext;
				m_cabs  = x.m_cabs;
				m_csca  = x.m_csca;
				m_assym = x.m_assym;
				m_cextv = x.m_cextv;
				m_cabsv = x.m_cabsv;
				m_cscav = x.m_cscav;
				m_cbakv = x.m_cbakv;
				m_cprv  = x.m_cprv;
				m_cexts = x.m_cexts;
				m_cabss = x.m_cabss;
				m_cscas = x.m_cscas;
				m_cbaks = x.m_cbaks;
				m_cprs  = x.m_cprs;
				// Memory first touch.
				avx256_init_unroll2x(&m_dang[0], NANGMAX, 0.0);
				avx256_init_unroll2x(&m_inat[0], NANGMAX, 0.0);
				avx256_init_unroll2x(&m_pol[0], NANGMAX, 0.0);
				avx256_init_unroll2x(&m_i11[0], NANGMAX, 0.0);
				avx256_init_unroll2x(&m_i21[0], NANGMAX, 0.0);
				avx256_init_unroll2x(&m_i12[0], NANGMAX, 0.0);
				avx256_init_unroll2x(&m_i22[0], NANGMAX, 0.0);
				avx256_init_unroll2x(&m_cexti[0], m_nlp, 0.0);
				avx256_init_unroll2x(&m_cabsi[0], m_nlp, 0.0);
				avx256_init_unroll2x(&m_cscai[0], m_nlp, 0.0);
				avx256_init_unroll2x(&m_assymi[0], m_nlp, 0.0);
				avx256_init_unroll2x(&m_cpri[0], m_nlp, 0.0);
				avx256_init_unroll2x(&m_mue[0], (4 * 4 * NANGMAX), 0.0);
				// Copy
				avx256_memcpy2x(&m_dang[0], &x.m_dang[0], NANGMAX);
				avx256_memcpy2x(&m_inat[0], &x.m_inat[0], NANGMAX);
				avx256_memcpy2x(&m_pol[0], &x.m_pol[0], NANGMAX);
				avx256_memcpy2x(&m_i11[0], &x.m_i11[0], NANGMAX);
				avx256_memcpy2x(&m_i21[0], &x.m_i21[0], NANGMAX);
				avx256_memcpy2x(&m_i12[0], &x.m_i12[0], NANGMAX);
				avx256_memcpy2x(&m_i22[0], &x.m_i22[0], NANGMAX);
				avx256_memcpy2x(&m_cexti[0], &x.m_cexti[0],m_nlp);
				avx256_memcpy2x(&m_cabsi[0], &x.m_cabsi[0],m_nlp);
				avx256_memcpy2x(&m_cscai[0], &x.m_cscai[0],m_nlp);
				avx256_memcpy2x(&m_assymi[0], &x.m_assymi[0],m_nlp);
				avx256_memcpy2x(&m_cpri[0], &x.m_cpri[0],m_nlp);
				avx256_memcpy2x(&m_mue[0], &x.m_mue[0], (4*4*NANGMAX));
			}
			
			~TMatrixMPS() noexcept(true) = default;

			TMatrixMPS & operator=(_In_ const TMatrixMPS &x) {
				if (this == &x || m_nlp != x.m_nlp) { return (*this); }
				// Copy over destructively.
				  m_nlp = x.m_nlp;     m_cext = x.m_cext;
				  m_cabs = x.m_cabs;   m_csca = x.m_csca;
				  m_assym = x.m_assym; m_cextv = x.m_cextv;
				  m_cabsv = x.m_cabsv; m_cscav = x.m_cscav;
				  m_cbakv = x.m_cbakv; m_cprv = x.m_cprv;
				  m_cexts = x.m_cexts; m_cabss = x.m_cabss;
				  m_cscas = x.m_cscas; m_cbaks = x.m_cbaks;
				  m_cprs = x.m_cprs;
				  avx256_memcpy2x(&m_dang[0],   &x.m_dang[0], NANGMAX);
				  avx256_memcpy2x(&m_inat[0],   &x.m_inat[0], NANGMAX);
				  avx256_memcpy2x(&m_pol[0],    &x.m_pol[0], NANGMAX);
				  avx256_memcpy2x(&m_i11[0],    &x.m_i11[0], NANGMAX);
				  avx256_memcpy2x(&m_i21[0],    &x.m_i21[0], NANGMAX);
				  avx256_memcpy2x(&m_i12[0],    &x.m_i12[0], NANGMAX);
				  avx256_memcpy2x(&m_i22[0],    &x.m_i22[0], NANGMAX);
				  avx256_memcpy2x(&m_cexti[0],  &x.m_cexti[0], m_nlp);
				  avx256_memcpy2x(&m_cabsi[0],  &x.m_cabsi[0], m_nlp);
				  avx256_memcpy2x(&m_cscai[0],  &x.m_cscai[0], m_nlp);
				  avx256_memcpy2x(&m_assymi[0], &x.m_assymi[0], m_nlp);
				  avx256_memcpy2x(&m_cpri[0],   &x.m_cpri[0], m_nlp);
				  avx256_memcpy2x(&m_mue[0],    &x.m_mue[0], (4 * 4 * NANGMAX));
				  return (*this);
			}	
				
			// Call Fortran tmatrix_mps_driver	
				
			void call_f77_tmatrix_mps_driver(_In_ int32_t np,   _In_ int32_t idMie,
										     _In_ double small, _In_ int32_t MXINT,
										     _In_ int32_t NADD, _In_ int32_t idscmt,
										     _In_ double sang,  _In_ double w,
										     _In_ int32_t irat,  _In_ int32_t nL,
										     _In_ int32_t idshp[NLP],
											 _In_ double shp[3 * NLP],
											 _In_ double r0[9 * NLP]) {
				// Call huge T-Matrix process
				MOD_TMATRIX_MPS_mp_TMATRIX_MPS_DRIVER(&m_nlp,&np,&idMie,&small,&MXINT,&NADD,
													  &idscmt, &sang, &w, &irat, &nL, &idshp[0],
													  &shp[0], &r0[0],&m_cext,&m_cabs,&m_csca,
													  &m_assym,&m_cextv,&m_cabsv,&m_cscav,&m_cbakv,
													  &m_cprv,&m_cexts,&m_cabss,&m_cscas,&m_cbaks,
													  &m_cprs, &m_dang[0], &m_inat[0], &m_pol[0],
													  &m_i11[0], &m_i21[0], &m_i12[0], &m_i22[0],
													  &m_cexti[0], &m_cabsi[0], &m_cscai[0],
													  &m_assymi[0], &m_cpri[0], &m_mue[0]);


			}
				
			
			

		};
	}
}






#endif /*__LAM_TMATRIX_MPS_WRAPPER_H__*/
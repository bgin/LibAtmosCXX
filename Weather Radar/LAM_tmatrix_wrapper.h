
#ifndef __LAM_TMATRIX_WRAPPER_H__
#define __LAM_TMATRIX_WRAPPER_H__

namespace file_info {

#include "../LAM_version.h"

	const unsigned int gLAM_TMATRIX_WRAPPER_MAJOR = 1U;

	const unsigned int gLAM_TMATRIX_WRAPPER_MINOR = 0U;

	const unsigned int gLAM_TMATRIX_WRAPPER_MICRO = 0U;

	const unsigned int gLAM_TMATRIX_WRAPPER_FULLVER = 
		1000U*gLAM_TMATRIX_WRAPPER_MAJOR+100U*gLAM_TMATRIX_WRAPPER_MINOR+10U*gLAM_TMATRIX_WRAPPER_MICRO;

	const char * const  pgLAM_TMATRIX_WRAPPER_CREATE_DATE = "20-09-2018 15:08 +00200 (THR 20 SEP 2018 GMT+2)";

	const char * const pgLAM_TMATRIX_WRAPPER_BUILD_DATE = "00-00-0000 00:00";

	const char * const pgLAM_TMATRIX_WRAPPER_AUTHOR = "Programmer: Bernard Gingold, contact: beniekg@gmail.com";

	const char * const pgLAM_TMATRIX_WRAPPER_SYNOPSIS = "C++ wrapper around Fortran TMATRIX_Driver subroutine.";

}

#include <cstdint>

#include "../LAM_common.h"
#include "LAM_tmatrix_ensemble_iface.h"


namespace lam {
	namespace wsr88d {

		template<int32_t N>
		struct __declspec(align(64)) TMatrixParams {
			/*
				This struct is designed to be used
				from looped construct.
			*/
			__declspec(align(64)) static double   nRAT[N];
			__declspec(align(64)) static int32_t  nNDISTR[N];
			__declspec(align(64)) static double   nAXMAX[N];
			__declspec(align(64)) static int32_t  nNPNAX[N];
			__declspec(align(64)) static double   nB[N];
			__declspec(align(64)) static double   nGAM[N];
			__declspec(align(64)) static int32_t  nNKMAX[N];
			__declspec(align(64)) static double   nEPS[N];
			__declspec(align(64)) static int32_t  nNP[N];
			__declspec(align(64)) static double   nLAM[N];
			__declspec(align(64)) static double   nMRR[N];
			__declspec(align(64)) static double   nMRI[N];
			__declspec(align(64)) static double   nDDELT[N];
			__declspec(align(64)) static int32_t  nNDGS[N];

		};
		
		template<int32_t NPNA>
		struct  __declspec(align(64))  TMatrix {
			
			static int32_t constexpr NPL = 201;

			__declspec(align(4)) int32_t m_npna;

			__declspec(align(4)) char pad0[4];

			__declspec(align(8)) char pad1[8];

			__declspec(align(8)) double m_cext;

			__declspec(align(8)) double m_csca;

			__declspec(align(8)) double m_w;

			__declspec(align(8)) double m_cosph;

			__declspec(align(8)) double m_reff;

			__declspec(align(8)) double m_veff;

			__declspec(align(64)) double m_scatmat[6*NPNA];

			TMatrix() {
				
				using namespace lam::common;
				m_npna = NPNA;
				m_cext = 0.0;
				m_csca = 0.0;
				m_w    = 0.0;
				m_cosph = 0.0;
				m_reff  = 0.0;
				m_veff  = 0.0;
				// Memory first touch.
				avx256_init_unroll2x(&m_scatmat[0], (6*NPNA), 0.0);
			}

			TMatrix(_In_ const TMatrix &x) {
				using namespace lam::common;
				m_npna = x.m_npna;
				m_cext = x.m_cext;
				m_csca = x.m_csca;
				m_w    = x.m_w;
				m_cosph = x.m_cosph;
				m_reff  = x.m_reff;
				m_veff  = x.m_veff;
				// Memory first touch.
				avx256_init_unroll2x(&m_scatmat[0], (6*NPNA),0.0);
				avx256_memcpy2x(&m_scatmat[0], &x.m_scatmat[0], (6*NPNA));
			}

			~TMatrix() noexcept(true) = default;

			TMatrix & operator=(_In_ const TMatrix &x) {
				using namespace lam::common;
				if (this == &x || x.m_npna != m_npna) { return (*this); }
				   m_npna = x.m_npna;
				   m_cext = x.m_cext;
				   m_csca = x.m_csca;
				   m_w = x.m_w;
				   m_cosph = x.m_cosph;
				   m_reff = x.m_reff;
				   m_veff = x.m_veff;
				   avx256_memcpy2x(&m_scatmat[0], &x.m_scatmat[0], (6*NPNA));
				 return (*this);
			}

			void call_f77_tmatrix_driver(_In_ double  RAT, _In_ int32_t NDISTR,
									  	 _In_ double AXMAX, _In_ int32_t NPNAX,
									     _In_ double B, _In_ double GAM,
									     _In_ int32_t NKMAX, _In_ double EPS,
										 _In_ int32_t NP, _In_ double LAM,
									     _In_ double MRR, _In_ double MRI,
									     _In_ double DDELT, _In_ int32_t NDGS,
										 _In_ double ALPHA1[NPL], _In_ double ALPHA2[NPL],
										 _In_ double ALPHA3[NPL], _In_ double ALPHA4[NPL],
										 _In_ double BETA1[NPL], _In_ double BETA2[NPL]) {
					
				MOD_TMATRIX_mp_TMATRIX_Driver(&RAT,&NDISTR,&AXMAX,&NPNAX,&B,&GAM,
											  &NKMAX,&EPS,&NP,&LAM,&MRR,&MRI,&DDELT,
											  &m_npna,&NDGS,&m_cext,&m_csca,&m_w,
											  &m_cosph, &m_reff, &m_veff, &ALPHA1[0],
											  &ALPHA2[0], &ALPHA3[0], &ALPHA4[0],
											  &BETA1[0], &BETA2[0], &m_scatmat[0]);


			}

		};
	}
}



#endif /*__LAM_TMATRIX_WRAPPER_H__*/
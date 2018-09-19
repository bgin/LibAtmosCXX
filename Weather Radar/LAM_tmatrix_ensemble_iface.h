
#ifndef __LAM_TMATRIX_ENSEMBLE_IFACE_H__
#define __LAM_TMATRIX_ENSEMBLE_IFACE_H__

namespace file_info {
#include "../LAM_version.h"

	const unsigned int gLAM_TMATRIX_ENSEMBLE_IFACE_MAJOR = 1U;

	const unsigned int gLAM_TMATRIX_ENSEMBLE_IFACE_MINOR = 0U;

	const unsigned int gLAM_TMATRIX_ENSEMBLE_IFACE_MICRO = 0U;

	const unsigned int gLAM_TMATRIX_ENSEMBLE_IFACE_FULLVER = 
		1000U*gLAM_TMATRIX_ENSEMBLE_IFACE_MAJOR+100U*gLAM_TMATRIX_ENSEMBLE_IFACE_MINOR+10U*gLAM_TMATRIX_ENSEMBLE_IFACE_MICRO;

	const char * const pgLAM_TMATRIX_ENSEMBLE_IFACE_CREATE_DATE = "19-09-2018 16:24 +00200 (WED 19 SEP 2018 GMT+2)";

	const char * const pgLAM_TMATRIX_EMSEMBLE_IFACE_BUILD_DATE = "00-00-0000 00:00";

	const char * const pgLAM_TMATRIX_ENSEMBLE_IFACE_AUTHOR = "Programmer: Bernard Gingold, contact: beniekg@gmail.com";

	const char * const pgLAM_TMATRIX_ENSEMBLE_IFACE_SYNOPSIS = "C interface to Fortran 77 T-Matrix models.";
}

#include "../LAM_config.h"

#if (LAM_DEFAULT_CXX_VERSION) == 199711L || (LAM_DEFAULT_CXX_VERSION) == 201103L

extern "C" {

	void MOD_TMATRIX_MPS_mp_TMATRIX_MPS_DRIVER(int *,
										       int *,
											   int *,
											   double *,
											   int *,
											   int *,
											   int *,
											   double *,
											   double *,
											   int *,
											   int *,
											   int * __restrict,
											   double * __restrict,
											   double * __restrict,
											   double *, double *,
											   double *, double *,
											   double *, double *,
											   double *, double *,
											   double *, double *,
											   double *, double *,
											   double *, double *,
											   double * __restrict,
											   double * __restrict,
											   double * __restrict,
											   double * __restrict,
											   double * __restrict,
											   double * __restrict,
											   double * __restrict,
											   double * __restrict,
											   double * __restrict,
											   double * __restrict,
											   double * __restrict,
											   double * __restrict,
											   double * __restrict);


	void MOD_TMATRIX_mp_TMATRIX_Driver(double * ,
									   int *,
									   double *,
									   int *,
									   double *,
									   double *,
									   int *,
									   double *,
									   int *,
									   double *,
									   double *,
									   double *,
									   double *,
									   int *,
									   int *,
									   double *,
									   double *,
									   double *,
									   double *,
									   double *,
									   double *,
									   double * __restrict,
									   double * __restrict,
									   double * __restrict,
									   double * __restrict,
									   double * __restrict,
									   double * __restrict,
									   double * __restrict);


}

#endif



#endif /*__LAM_TMATRIX_ENSEMBLE_IFACE__*/
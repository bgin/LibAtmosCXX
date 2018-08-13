

#include "LAM_drag_coeff.h"
#include "../LAM_indices.h"
#include <math.h>

void
lam::wsr88d
::compute_drag_coeff(_Out_  double * __restrict Cd,
					 _In_   const int32_t nt,
					 _In_   const double * __restrict C0,
                     _In_	const double delta0,
					 _In_   const double * __restrict Re) {
	
	for (int32_t i = 0; i != nt; ++i) {
		Cd[i] = C0[i] * (1.0 + delta0 / pow(Re[i],0.5)) * 
			            (1.0 + delta0 / pow(Re[i],0.5));
	}
}

void
lam::wsr88d
::compute_reynolds_number(_Out_ double * __restrict Re,
						  _In_  const int32_t nt,
						  _In_  const double * __restrict Vt,
						  _In_  const double D,
						  _In_  const double * __restrict rho_f,
						  _In_  const double * __restrict d_visc,
						  _In_  const int32_t  nx,
						  _In_  const int32_t  ny,
						  _In_  const int32_t  nz) {
	
	for (int32_t i = 0; i != nt; ++i) {
		 
		for (int32_t ix = 0; ix != nx; ++ix) {
			for (int32_t iy = 0; iy != ny; ++iy) {
				for (int32_t iz = 0; iz != nz; ++iz) {
					Re[i] = (Vt[i] * D * rho_f[Ix3D(ix, nx, iy, ny, iz)]) / d_visc[Ix2D(ix,nx,iy)];
				}
			}
		}
	}
}

void
lam::wsr88d
::compute_davies_number(_Out_ double * __restrict X,
					    _In_  const int32_t nt,
						_In_  const double vb,
						_In_  const double rho_b,
						_In_  const double * __restrict rho_f,
						_In_  const int32_t nx,
						_In_  const int32_t ny,
						_In_  const int32_t nz,
						_In_  const double D,
						_In_  const double A,
						_In_  const double * __restrict k_visc) {

	double term1{}, term2{};
	for (int32_t i = 0; i != nt; ++i) {
		 
		for (int32_t ix = 0; ix != nx; ++ix) {
			for (int32_t iy = 0; iy != ny; ++iy) {
				for (int32_t iz = 0; iz != nz; ++iz) {
					term1 = 2.0 * vb * abs(rho_b - rho_f[Ix3D(ix,nx,iy,ny,iz)]) * 9.81 * D * D;
					term2 = A * rho_f[Ix3D(ix, nx, iy, ny, iz)] * k_visc[Ix3D(ix,nx,iy,ny,iz)] * 
							k_visc[Ix3D(ix,nx,iy,ny,iz)];
					X[i] = term1/term2;
				}
			}
		}
	}
}

void
lam::wsr88d
::compute_aRe(_Out_ double * __restrict aRe,
			  _In_   double * __restrict bRe,
			  _In_   double * __restrict X,
			  _In_  const int32_t nt,
			  _In_  const double delta0,
			  _In_  const double * __restrict C1) {

	double term1{}, term2{};
	for (int32_t i = 0; i != nt; ++i) {
		 term1 = delta0 * delta0 * 0.25;
		 term2 = pow(pow(1.0 + C1[i] * pow(X[i], 0.5), 0.5) - 1.0, 2.0) / (pow(X[i], bRe[i]));
		 aRe[i] = term1 * term2;
	}
	
}

void
lam::wsr88d
::compute_bRe(_Out_ double * __restrict bRe,
			  _In_  const int32_t nt,
			  _In_  const double * __restrict C1,
			  _In_  const double * __restrict X) {

	double term1{}, term2{}, term3{};
	for (int32_t i = 0; i != nt; ++i) {
		term1 = C1[i] * pow(X[i],0.5);
		term2 = 2.0 * pow(1.0 + C1[i] * pow(X[i],0.5),0.5) - 1.0;
		term3 = pow(1.0 + C1[i] * pow(X[i],0.5),0.5);
		bRe[i] = term1 / (term2 * term3);
	}
}

void
lam::wsr88d
::psi_interpolation(_Out_ double *  __restrict psi,
					_In_  const double * __restrict X,
					_In_  const double * __restrict X0,
					_In_  const int32_t nt,
					_In_  const double k,
					_In_  const double * __restrict Ct) {

	double term1{}, term2{};

	for (int32_t i = 0; i != nt; ++i) {

		if (X[i] < X0[i]) {
			psi[i] = 1.0;
		}
		else if (X[i] > X0[i]) {
			psi[i] = 1.0 / Ct[i];
		}
		else {
			term1 = 1.0 + pow(X[i] / X0[i],k);
			term2 = 1.0 + Ct[i] * pow(X[i] / X0[i],k);
			psi[i] = term1 / term2;
		}
		   
	}
}

void
lam::wsr88d
::compute_delta_bRe(_Out_ double * __restrict dbRe,
					_In_  const int32_t nt,
					_In_  const double * __restrict X,
					_In_  const double * __restrict X0,
					_In_  const double * __restrict Ct,
					_In_  const double k) {

	double term1{}, term2{}, term3{}, z{};
	for (int32_t i = 0; i != nt; ++i) {
		z = pow(X[i] / X0[i], k);
		term1 = k * Ct[i] - 1.0 * z;
		term2 = 2.0 * 1.0 + z;
		term3 = 1.0 + Ct[i] * z;
		dbRe[i] = term1 / (term2 * term3);
	}
}
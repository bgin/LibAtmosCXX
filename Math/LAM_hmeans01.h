
#ifndef __LAM_HMEANS01_H__
#define __LAM_HMEANS01_H__

#if !defined (LAM_HMEANS01_MAJOR)
#define LAM_HMEANS01_MAJOR 1
#endif

#if !defined (LAM_HMEANS01_MINOR)
#define LAM_HMEANS01_MINOR 0
#endif

#if !defined (LAM_HMEANS01_MICRO)
#define LAM_HMEANS01_MICRO 0
#endif

#if !defined (LAM_HMEANS01_FULLVER)
#define LAM_HMEANS01_FULLVER 1000
#endif

#if !defined (LAM_HMEANS01_CREATE_DATE)
#define LAM_HMEANS01_CREATE_DATE "06-04-2017 10:33 +00200 (FRI 06 APR 2017 GMT+2)"
#endif

#if !defined (LAM_HMEANS01_BUILD_DATE)
#define LAM_HMEANS01_BUILD_DATE ""
#endif

#if !defined (LAM_HMEANS01_AUTHOR)
#define LAM_HMEANS01_AUTHOR "Programmer: Bernard Gingold, e-mail: beniekg@gmail.com"
#endif

#if !defined (LAM_HMEANS01_DESCRIPT)
#define LAM_HMEANS01_DESCRIPT "High-level wrapper to Fortran 90 hmeans_01 subroutine"
#endif

#include <cstdint>


namespace lam {
	namespace math {
		namespace stat {

		
			__declspec(align(64))struct HMEANS01 {

				int32_t  m_cluster_num;

				int32_t  m_dim_num;

				int32_t  m_samples_num; // radar signal samples as a bivariate vector real,or imaginary part.

				int32_t  m_iter_max;

				int32_t  m_iter_num;

				int32_t  m_seed;
				/*	
						CLUSTER(samples_num) -- Input/Output.  On input, the user 
						may specify an initial cluster for each point, or leave all entrie of
						CLUSTER set to 0.  On output, CLUSTER contains the index of the
						cluster to which each data point belongs.
				*/
				_Field_size_(m_samples_num) int32_t * __restrict m_cluster;

				/*
					    CLUSTER_CENTER(dim_num,cluster_num) -- Input/Output, the 
				        centers associated with the minimal energy clustering.
				*/
				_Field_size_(m_dim_num*m_cluster_num) double * __restrict m_cluster_center;

				/*
						CLUSTER_POPULATION(cluster_num) -- Output ,
					    the populuation of each cluster
				*/
				_Field_size_(m_cluster_num) int32_t * __restrict m_cluster_population;
				
				/*
						CLUSTER_ENERGY(cluster_num) -- Output the energy
				        associated with each cluster.
				*/
				_Field_size_(m_cluster_num) double * __restrict m_cluster_energy;

				//
				//	Construction, destruction.
				//
				
				//
				//	Default Constructio -- no real mathematical(statistical) meaning
				//                         used only for default initialzation.
				//
				HMEANS01();

				//
				//	Main class Constuctor -- initialzation/allocation of member variables 
				//							 scalar and arrays.
				//
				HMEANS01(_In_ const int32_t, _In_ const int32_t,
						 _In_ const int32_t, _In_ const int32_t,
						 _In_ const int32_t );

				//
				// Copy Constructor -- deep copy semantics.
				//
				HMEANS01(_In_ const HMEANS01 &);

				//
				// Move Constructor -- shallow copy semantics
				//
				HMEANS01(_In_ HMEANS01 &&) noexcept(true);

				//
				//	Destructor
				//
				~HMEANS01() noexcept(true);

				/*
					Mmeber operators
				*/

				HMEANS01 & operator=(_In_ const HMEANS01 &);

				HMEANS01 & operator=(_In_ HMEANS01 &&) noexcept(true);
			};

			//
			//	Run computation of H-MEANS01
			//  Second argument it is radar samples signal whose number of domain is always 2
			//  and it contains real and imaginary part of signal sample.
			//  Signal samples:
			/*		Re			Im
					0.532095    0.894141
					0.189043    0.613426
					0.550977    0.415724
					0.003973    0.605760
					0.894230    0.666812
					0.073072    0.740658
					0.640180    0.926186
					0.389914    0.553149
					0.046918    0.172275
					0.820327    0.578957
			*/
			//  Third argument is storage for variance computation and must be zero-filled.
			//
			//  Warning:
			//             second argument (from left) must have size of (dim_num*samples_num)
			//			   third argument (from left) must have size of cluster_num
			//				
			//  
			void compute_hmeans01(_Inout_ HMEANS01 &, 
								   _In_  double * __restrict,
								  _Inout_ double * __restrict);
			
		}
		
	}
}




#endif /*__LAM_HMEANS01_H__*/
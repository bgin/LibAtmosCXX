
#ifndef __LAM_KMEANS_H__
#define __LAM_KMEANS_H__

#if !defined (LAM_KMEANS_MAJOR)
#define LAM_KMEANS_MAJOR 1
#endif

#if !defined (LAM_KMEANS_MINOR)
#define LAM_KMEANS_MINOR 0
#endif

#if !defined (LAM_KMEANS_MICRO)
#define LAM_KMEANS_MICRO 0
#endif

#if !defined (LAM_KMEANS_FULLVER)
#define LAM_KMEANS_FULLVER 1000
#endif

#if !defined (LAM_KMEANS_CREATE_DATE)
#define LAM_KMEANS_CREATE_DATE " 07-04-2017 16:08 +00200 (SAT 07 APR 2017 GMT+2)"
#endif

#if !defined (LAM_KMEANS_BUILD_DATE)
#define LAM_KMEANS_BUILD_DATE " "
#endif

#if !defined (LAM_KMEANS_AUTHOR)
#define LAM_KMEANS_AUTHOR "Programmer: Bernard Gingold, e-mail: beniekg@gmail.com"
#endif

#if !defined (LAM_KMEANS_DESCRIPT)
#define LAM_KMEAS_DESCRIPT "High-level wrappers for Fortran 90 KMEANS library."
#endif

#include <cstdint>

namespace lam {
	namespace math {
		namespace stat {

			__declspec(align(64)) struct KMEANS {

				// the number of spatial dimensions.
				int32_t m_dim_num;
				// the number of signal samples (re,im) components
				int32_t m_samples_num;
				// the number of clusters.
				int32_t m_cluster_num;
				// the maximum number of iterations.
				int32_t m_iter_max;
				// the number of iterations taken.
				int32_t m_iter_num;
				// a seed for the random number generator.
				int32_t m_seed;
				/*
				On input, the user
				may specify an initial cluster for each point, or leave all entrie of
				CLUSTER set to 0.  On output, CLUSTER contains the index of the
				cluster to which each data point belongs.
				*/
				_Field_size_(m_samples_num) int32_t * __restrict m_cluster;
				/*
				the coordinates of the cluster centers.
				*/

				_Field_size_(m_dim_num*m_cluster_num) double * __restrict m_cluster_center;
				/*
				the number of
				points assigned to each cluster.
				*/

				_Field_size_(m_cluster_num) int32_t * __restrict m_cluster_population;
				/*
				the energy of
				the clusters.
				*/

				_Field_size_(m_cluster_num) double * __restrict m_cluster_energy;

				//
				//	Default Constructor implemented, although it does not have
				//  any statistical meaning.
				//
				KMEANS();

				//
				//  Main class Constructor - responsible for scalar member initialization and
				//	allocation and zero-initialzation of array members.
				// 
				KMEANS(	_In_ const int32_t, _In_ const int32_t,
						_In_ const int32_t, _In_ const int32_t,
						_In_ const int32_t);

				//
				// Copy Constructor -- deep copy semantics
				//
				KMEANS(_In_ const KMEANS &);

				//
				// Move Constructor -- shallow copy semantics
				//
				KMEANS(_In_ KMEANS &&) noexcept(true);

				~KMEANS() noexcept(true);

				KMEANS & operator=(_In_ const KMEANS &);

				KMEANS & operator=(_In_ KMEANS &&) noexcept(true);



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
			void compute_hmeans01(_Inout_ KMEANS &,
								  _In_  double * __restrict,
								  _Inout_ double * __restrict,
								  _Inout_ std::int32_t[6]);

			//
			//	Run computation of H-MEANS02
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

			void compute_hmeans02(_Inout_ KMEANS &, 
								  _In_ double * __restrict,
								  _Inout_ double * __restrict,
								  _Inout_ std::int32_t[6]);

			//
			//	Run subroutine K-MEANS01
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

			void compute_kmeans01(_Inout_ KMEANS &, 
								  _In_ double * __restrict,
								  _Inout_ double * __restrict ,
								  _Inout_ std::int32_t[6]);

			//
			//	Run subroutine K-MEANS02
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

			void compute_kmeans02(_Inout_ KMEANS &,
								  _In_ double * __restrict,
								  _Inout_ double * __restrict,
								  _Inout_ std::int32_t[6]);

			/*
			//
			//	Run subroutine K-MEANS03
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
	        
			void compute_kmeans03(_Inout_ KMEANS &,
								  _In_ double * __restrict,
								  _Inout_ double * __restrict,
								  _Inout_ std::int32_t[6]);

			
			/*
			//
			//	Run subroutines H-MEANS01 and K-MEANS01
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
			
			void compute_hmeans01_and_kmeans01(_Inout_ KMEANS &,
										   _In_ double * __restrict,
										   _Inout_ double * __restrict,
										   _Inout_ std::int32_t[6]);

			/*
			//
			//	Run subroutines H-MEANS01 and K-MEANS02
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

			void compute_hmeans01_and_kmeans02(_Inout_ KMEANS &,
											   _In_ double * __restrict,
											   _Inout_ double * __restrict,
											   _Inout_ std::int32_t[6]);

			/*
			//
			//	Run subroutines H-MEANS01 and K-MEANS03
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

			void compute_hmeans01_and_kmeans03(_Inout_ KMEANS &,
											   _In_ double * __restrict,
											   _Inout_ double * __restrict,
											   _Inout_ std::int32_t[6]);

			/*
			//
			//	Run subroutines HMEANS_W_01 
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
			//			   fourth argument (from left) must have size of (samples_num)
			//  

			void compute_hmeans_w_01(_Inout_ KMEANS &,
									 _In_ double * __restrict,
									 _Inout_ double * __restrict,
									 _In_ double * __restrict,
									 _Inout_ std::int32_t[6]);

			/*
			//
			//	Run subroutines HMEANS_W_02
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
			//			   fourth argument (from left) must have size of (samples_num)
			//  

			void compute_hmeans_w_02(_Inout_ KMEANS &,
									 _In_ double * __restrict,
									 _Inout_ double * __restrict,
									 _In_ double * __restrict,
									 _Inout_ std::int32_t[6]);

			/*
			//
			//	Run subroutines KMEANS_W_01
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
			//			   fourth argument (from left) must have size of (samples_num)
			//  

			void compute_kmeans_w_01(_Inout_ KMEANS &,
									 _In_ double * __restrict,
									 _Inout_ double * __restrict,
									 _In_ double * __restrict,
									 _Inout_ std::int32_t[6]);

		


		}
	}
}



#endif /*__LAM_KMEANS_H__*/
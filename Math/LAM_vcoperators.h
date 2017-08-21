
#ifndef __LAM_VCOPERATORS_H__
#define __LAM_VCOPERATORS_H__

/*
	Global VComplex1D operators
	File granularity information
*/

#if !defined (LAM_VCOPERATORS_MAJOR)
#define  LAM_VCOPERATORS_MAJOR 1
#endif

#if !defined (LAM_VCOPERATORS_MINOR)
#define LAM_VCOPERATORS_MINOR 0
#endif

#if !defined (LAM_VCOPERATORS_MICRO)
#define LAM_VCOPERATORS_MICRO 0
#endif

#if !defined (LAM_VCOPERATORS_FULLVER)
#define LAM_VCOPERATORS_FULLVER 1000
#endif

#if !defined (LAM_VCOPERATORS_CREATE_DATE)
#define LAM_VCOPERATORS_CREATE_DATE "21-08-2017 10:08 +00200 (MON 21 AUG 2017 GMT+2)"
#endif

/*
	Set this value to latest build date/time
*/
#if !defined (LAM_VCOPERATORS_BUILD_DATE)
#define LAM_VCOPERATORS_BUILD_DATE " "
#endif

#if !defined (LAM_VCOPERATORS_AUTHOR)
#define LAM_VCOPERATORS_AUTHOR "Programmer: Bernard Gingold e-mail: beniekg@gmail.com"
#endif

#if !defined (LAM_VCOPERATORS_DESCRIPT)
#define LAM_VCOPERATORS_DESCRIPT "VComplex1D global complex arithemtic operators."
#endif

#include "LAM_complex.h"

namespace lam {
	namespace math {
		
		/*
		 *  Collection of global operators acting on 
		 *  objects of type VComplex1D<Real_t>
		 */

		/*
		  @Purpose:
		             C = A+B
					 where A is of type: VComplex1D
					 and B is of type:   VComplex1D
		*/
		template<typename Real_t> 
		VComplex1D<Real_t> 
		operator+(_In_ const VComplex1D<Real_t>& ,
			      _In_ const VComplex1D<Real_t>& )noexcept(false);


		/*
		  @Purpose:
		            C = A+B
		            where A is of type: VComplex1D
		            and B is of type: Real_t * __restrict
		  @Remark:
		            Size of Real_t * argument must be
					equal to size of VComplex1D.m_Re
		*/
		template<typename Real_t>
		VComplex1D<Real_t>
	    operator+(_In_ const VComplex1D<Real_t> &,
		          _In_ const Real_t* __restrict)noexcept(false);
				 

    
		/*
		  @Purpose:
		              C = A+B
		              where A is of type: Real_t * __restrict
		              and B is of type:   VComplex1D
		  @Remark:
		              Size of Real_t * argument must be
		              equal to size of VComplex1D.m_Re
		*/
		template<typename Real_t>
		VComplex1D<Real_t>
		operator+(_In_ const Real_t* __restrict,
			      _In_ const VComplex1D<Real_t> &);

		/*
		  @Purpose:
		             C = A-B
		             where A is of type: VComplex1D
		             and B is of type:   VComplex1D
		*/
		template<typename Real_t>
		VComplex1D<Real_t>
	    operator-(_In_ const VComplex1D<Real_t> &,
			      _In_ const VComplex1D<Real_t> &)noexcept(false);


		/*
		  @Purpose:
		            C = A-B
		            where A is of type: VComplex1D
		            and B is of type: Real_t * __restrict
		 @Remark:
		            Size of Real_t * argument must be
		            equal to size of VComplex1D.m_Re
		*/
		template<typename Real_t>
		VComplex1D<Real_t>
		operator-(_In_ const VComplex1D<Real_t> &,
			      _In_ const Real_t* __restrict)noexcept(false);


		/*
		  @Purpose:
		             C = A-B
		             where A is of type: Real_t * __restrict
		             and B is of type:   Vcomplex1D
		  @Remark:
		             Size of Real_t * argument must be
		             equal to size of VComplex1D.m_Re
		*/
		template<typename Real_t>
        VComplex1D<Real_t>
	    operator-(_In_ const Real_t* __restrict,
	              _In_ const VComplex1D<Real_t> &)noexcept(false);


		/*
		  @Purpose:
		              C = A*B
		              where A is of type: VComplex1D
		              and B is of type:   VComplex1D
		*/
		template<typename Real_t>
		VComplex1D<Real_t>
	    operator*(_In_ const VComplex1D<Real_t> &,
				  _In_ const VComplex1D<Real_t> &)noexcept(false);


		/*
		  @Purpose:
				     C = A*B
					 where A is of type: VComplex1D
				     and B is of type: Real_t * __restrict
		  @Remark:
		             Size of Real_t * argument must be
		             equal to size of VComplex1D.m_Re
		*/
		template<typename Real_t>
		VComplex1D<Real_t>
		operator*(_In_ const VComplex1D<Real_t> &,
				  _In_ const Real_t* __restrict)noexcept(false);


		/*
		  @Purpose:
		             C = A*B
		             where A is of type: Real_t * __restrict
		             and B is of type:   Vcomplex1D
		 @Remark:
		             Size of Real_t * argument must be
		             equal to size of VComplex1D.m_Re
		*/
		template<typename Real_t>
		VComplex1D<Real_t>
		operator*(_In_ const Real_t* __restrict,
			      _In_ const VComplex1D<Real_t> &)noexcept(false);


		/*
		  @Purpose:
		             C = A/B
		             where A is of type: VComplex1D
		             and B is of type:   VComplex1D
		*/
		template<typename Real_t>
		VComplex1D<Real_t>
		operator/(_In_ const VComplex1D<Real_t> &,
			      _In_ const VComplex1D<Real_t> &)noexcept(false);


		/*
		  @Purpose:
		              C = A/B
		              where A is of type: VComplex1D
		              and B is of type: Real_t * __restrict
		  @Remark:
		              Size of Real_t * argument must be
		              equal to size of VComplex1D.m_Re
		*/
		template<typename Real_t>
		VComplex1D<Real_t>
		operator/(_In_ const VComplex1D<Real_t> &,
			      _In_ const Real_t* __restrict)noexcept(false);

		
		/*
		  @Purpose:
		              C = A*B
		              where A is of type: Real_t * __restrict
		              and B is of type:   Vcomplex1D
		  @Remark:
		              Size of Real_t * argument must be
		              equal to size of VComplex1D.m_Re
		*/
		template<typename Real_t>
		VComplex1D<Real_t>
		operator/(_In_ const Real_t* __restrict,
				  _In_ const VComplex1D<Real_t> &)noexcept(false);


		/*
		  @Purpose:
					C = A==B
					where C is of type: vector<bool>
		                  A is of type: VComplex1D
		                  B is of type: VComplex1D
		*/
		template<typename Real_t>
		std::vector<bool>
		operator==(_In_ const VComplex1D<Real_t> &,
				   _In_ const VComplex1D<Real_t> &)noexcept(false);


		/*
		  @Purpose:
		             C = A==B
		             where C is of type: vector<bool>
		                   A is of type: VComplex1D
		                   B is of type: const Real_t*
		  @Remark:
		              Size of Real_t * argument must be
		              equal to size of VComplex1D.m_Re
					  
		*/
		template<typename Real_t>
		std::vector<bool>
		operator==(_In_ const VComplex1D<Real_t> &,
				   _In_ const Real_t* __restrict)noexcept(false);


		/*
		  @Purpose:
		             C = A==B
		             where C is of type: vector<bool>
		                   A is of type: const Real_t*
		                   B is of type: VComplex1D
		  @Remark:
		             Size of Real_t * argument must be
		             equal to size of VComplex1D.m_Re
					 
		*/
		template<typename Real_t>
		std::vector<bool>
		operator==(_In_ const Real_t* __restrict,
				   _In_ const VComplex1D<Real_t> &)noexcept(false);


		/*
		  @Purpose:
		             C = A!=B
		             where C is of type: vector<bool>
		                   A is of type: VComplex1D
		                   B is of type: VComplex1D
		*/
		template<typename Real_t>
		std::vector<bool>
		operator!=(_In_ const VComplex1D<Real_t> &,
				   _In_ const VComplex1D<Real_t> &)noexcept(false);


		/*
		  @Purpose:
					  C = A!=B
					  where C is of type: vector<bool>
		                    A is of type: VComplex1D
		                    B is of type: const Real_t*
		 @Remark:
		              Size of Real_t * argument must be
		              equal to size of VComplex1D.m_Re

		*/
		template<typename Real_t>
		std::vector<bool>
		operator!=(_In_ const VComplex1D<Real_t> &,
				   _In_ const Real_t* __restrict)noexcept(false);


		/*
		  @Purpose:
		             C = A!=B
		             where C is of type: vector<bool>
		                   A is of type: const Real_t*
		                   B is of type: VComplex1D
		  @Remark:
		             Size of Real_t * argument must be
		             equal to size of VComplex1D.m_Re

		*/
		template<typename Real_t>
		std::vector<bool>
		operator!=(_In_ const Real_t* __restrict,
				   _In_ const VComplex1D<Real_t> &)noexcept(false);



#include "LAM_vcoperators.inl"
	}
}



#endif /*__LAM_VCOPERATORS_H__*/
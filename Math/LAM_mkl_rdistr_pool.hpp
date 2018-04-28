
#ifndef __LAM_MKL_RDISTR_POOL_HPP__
#define __LAM_MKL_RDISTR_POOL_HPP__


#if !defined (LAM_MKL_RDISTR_POOL_MAJOR)
#define LAM_MKL_RDISTR_POOL_MAJOR 1
#endif

#if !defined (LAM_MKL_RDISTR_POOL_MINOR)
#define LAM_MKL_RDISTR_POOL_MINOR 0
#endif

#if !defined (LAM_MKL_RDISTR_POOL_MICRO)
#define LAM_MKL_RDISTR_POOL_MICRO 0
#endif

#if !defined (LAM_MKL_RDISTR_POOL_FULLVER)
#define LAM_MKL_RDISTR_POOL_FULLVER 1000
#endif

#if !defined (LAM_MKL_RDISTR_POOL_CREATE_DATE)
#define LAM_MKL_RDISTR_POOL_CREATE_DATE "28-04-2018 09:57 +00200 (SAT 28 APR 2018 GMT+2)"
#endif

#if !defined (LAM_MKL_RDISTR_POOL_BUILD_DATE)
#define LAM_MKL_RDISTR_POOL_BUILD_DATE " "
#endif

#if !defined (LAM_MKL_RDISTR_POOL_AUTHOR)
#define LAM_MKL_RDISTR_POOL_AUTHOR "Programmer: Bernard Gingold, e-mail: beniekg@gmail.com"
#endif

#if !defined (LAM_MKL_RDISTR_POOL_DESCRIPT)
#define LAM_MKL_RDISTR_POOL_DESCRIPT "Templated pool of random distribution objects."
#endif

#include <cstdint>
#include <utility>
#include <memory>

#include "../LAM_config.h"
#if (USE_MKL) == 1
#include <mkl_vsl.h>
#endif
#include "../LAM_common.h"
#include "../LAM_malloc.h"


namespace lam{
	namespace math {
		namespace stat {
				
				template<class Container,
					     class MKLDistribution,
						 typename  = std::enable_if<std::is_class<Container>::value && 
						 std::is_class<MKLDistribution>::value>::type> struct MKLRDistrPool {

						 size_t  m_nelems;

						
						 
						Container m_rdpool;

						MKLRDistrPool()
							:
							m_nelems{},
							m_rdpool{} {}
							

						MKLRDistrPool(_In_ const size_t nelems,
									  _In_ const MKL_INT  * __restrict nvalues,
									  _In_ const MKL_UINT * __restrict brngs,
									  _In_ const MKL_INT  * __restrict seeds,
									  _In_ const double   * __restrict vals1,
									  _In_ const double   * __restrict vals2)
									  :
									  m_nelems{nelems},
									 {
										 for (size_t i = 0ULL; i != m_nelems; ++i) {
											 m_rdpool.operator[](i) =
												 std::unique_ptr<MKLDistribution>{new MKLDistribution{ m_nvalues[i],
												 m_brngs[i],
												 m_seeds[i],
												 m_vals1[i],
												 m_vals2[i] }};
									 }
							 }
									 
						  MKLRDistrPool(_In_ const MKLRDistrPool &x)
										  :
										  m_nelems{ x.m_nelems },
										  m_rdpool{ x.m_rdpool } {}


						  MKLRDistrPool(_In_ MKLRDistrPool &&x)
							  :
							  m_nelems{ std::move(x.m_nelems) },
							  m_rdpool{ std::move(x.m_rdpool) } {}

						  ~MKLRDistrPool() {}

						  MKLRDistrPool & operator=(_In_ const MKLRDistrPool &x) {
							  if (this == &x) return (*this);
							  m_nelems = x.m_nelems;
							  m_rdpool.operator=(x.m_rdpool);
							  return (*this);
						  }

						  MKLRDistrPool & operator=(_In_ MKLRDistrPool &&x) {
							  if (this == &x) return (*this);
							  m_nelems = std::move(x.m_nelems);
							  m_rdpool.operator=(std::move(x.m_rdpool));
							  return (*this);
						  }
						

						  void distribute_randomly(_In_ const MKL_INT * __restrict methods) {

							  for (size_t i = 0ULL; i != m_nelems; ++i){
								  m_rdpool.operator[](i).operator->()->compute_rand_distribution(methods[i]);
							  }
						  }

						
								
								  
				};
		}
	}
}



#endif /*__LAM_MKL_RDISTR_POOL_HPP__*/
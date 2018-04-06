
#include <malloc.h>
#include "LAM_hmeans01.h"
#include "LAM_kmeans_wrapper.h"
#include "../LAM_config.h"
#include "../LAM_error_macros.h"
#if (PRINT_CALLSTACK_ON_ERROR) == 1
#include "../System/StackWalker.h"
#endif
#include "../LAM_indices.h"


//
//	Implementation
//

lam::math::stat
::HMEANS01::HMEANS01()
:
m_cluster_num{},
m_dim_num{},
m_samples_num{},
m_iter_max{},
m_iter_num{},
m_seed{},
m_cluster{ NULL },
m_cluster_center{ NULL },
m_cluster_population{ NULL },
m_cluster_energy{ NULL } {}

lam::math::stat
::HMEANS01::HMEANS01(_In_ const int32_t cluster_num,
					 _In_ const int32_t dim_num,
					 _In_ const int32_t samples_num,
					 _In_ const int32_t iter_max,
					 _In_ const int32_t seed)
:
m_cluster_num{ cluster_num },
m_dim_num{ dim_num },
m_samples_num{ samples_num },
m_iter_max{ iter_max },
m_iter_num{},
m_seed{seed},
m_cluster(reinterpret_cast<int32_t*>(_mm_malloc(m_samples_num*sizeof(int32_t),align64B))),
m_cluster_center(reinterpret_cast<double*>(_mm_malloc((m_dim_num*m_cluster_num)*sizeof(double),align64B))),
m_cluster_population(reinterpret_cast<int32_t*>(_mm_malloc(m_cluster_num*sizeof(int32_t),align64B))),
m_cluster_energy(reinterpret_cast<double*>(_mm_malloc(m_cluster_num*sizeof(double), align64B))) {
	if (NULL == m_cluster ||
		NULL == m_cluster_energy ||
		NULL == m_cluster_population ||
		NULL == m_cluster_energy) {
#if (PRINT_CALLSTACK_ON_ERROR) == 1
	 DUMP_CALLSTACK_ON_ERROR
#endif		
	ABORT_ON_ERROR("HMEANS01::HMEANS01(int32_t,int32_t,int32_t,int32_t,int32_t) -- !!! Memory Allocatio  Failure !!!", MALLOC_FAILED)
	}
	for (int32_t i = 0; i != m_samples_num; ++i)
		m_cluster[i] = 0;

	for (int32_t i = 0; i != m_dim_num; ++i)
	    for (int32_t j = 0; j != m_cluster_num; ++j)
			m_cluster_center[Ix2D(i,m_dim_num,j)] = 0.0;

		for (int32_t i = 0; i != m_cluster_num; ++i) {
			m_cluster_population[i] = 0;
			m_cluster_energy[i] = 0.0;
		}
}

lam::math::stat
::HMEANS01::HMEANS01(_In_ const HMEANS01 &x)
:
m_cluster_num{ x.m_cluster_num },
m_dim_num{ x.m_dim_num },
m_samples_num{ x.m_samples_num },
m_iter_max{ x.m_iter_max },
m_iter_num{ x.m_iter_num },
m_seed{x.m_seed},
m_cluster(reinterpret_cast<int32_t*>(_mm_malloc(m_samples_num*sizeof(int32_t), align64B))),
m_cluster_center(reinterpret_cast<double*>(_mm_malloc((m_dim_num*m_cluster_num)*sizeof(double), align64B))),
m_cluster_population(reinterpret_cast<int32_t*>(_mm_malloc(m_cluster_num*sizeof(int32_t), align64B))),
m_cluster_energy(reinterpret_cast<double*>(_mm_malloc(m_cluster_num*sizeof(double), align64B))) {
	if (NULL == m_cluster ||
		NULL == m_cluster_energy ||
		NULL == m_cluster_population ||
		NULL == m_cluster_energy) {
#if (PRINT_CALLSTACK_ON_ERROR) == 1
		DUMP_CALLSTACK_ON_ERROR
#endif		
	   ABORT_ON_ERROR("HMEANS01::HMEANS01(HMEANS01 &) -- !!! Memory Allocatio  Failure !!!", MALLOC_FAILED)
	}
	for (int32_t i = 0; i != m_samples_num; ++i)
		m_cluster[i] = x.m_cluster[i];

	for (int32_t i = 0; i != m_dim_num; ++i)
	    for (int32_t j = 0; j != m_cluster_num; ++j)
		     m_cluster_center[Ix2D(i, m_dim_num, j)] = x.m_cluster_center[Ix2D(i,m_dim_num,j)];

	for (int32_t i = 0; i != m_cluster_num; ++i) {
		m_cluster_population[i] = x.m_cluster_population[i];
		m_cluster_energy[i] = x.m_cluster_energy[i];
	}
}

lam::math::stat
::HMEANS01::HMEANS01(_In_ HMEANS01 &&x)
:
m_cluster_num{ x.m_cluster_num },
m_dim_num{ x.m_dim_num },
m_samples_num{ x.m_samples_num },
m_iter_max{ x.m_iter_max },
m_iter_num{ x.m_iter_num },
m_seed{ x.m_seed },
m_cluster(NULL),
m_cluster_center(NULL),
m_cluster_population(NULL),
m_cluster_energy(NULL) {
	m_cluster = &x.m_cluster[0];
	m_cluster_center = &x.m_cluster_center[0];
	m_cluster_population = &x.m_cluster_population[0];
	m_cluster_energy = &x.m_cluster_energy[0];

	x.m_cluster_num = 0;
	x.m_dim_num = 0;
	x.m_samples_num = 0;
	x.m_iter_max = 0;
	x.m_iter_num = 0;
	x.m_seed = 0;
	x.m_cluster = NULL;
	x.m_cluster_center = NULL;
	x.m_cluster_population = NULL;
	x.m_cluster_energy = NULL;
}

lam::math::stat
::HMEANS01::~HMEANS01() {
	if (NULL != m_cluster_energy) {
		_mm_free(m_cluster_energy);
		m_cluster_energy = NULL;
	}
	if (NULL != m_cluster_population) {
		_mm_free(m_cluster_population);
		m_cluster_population = NULL;
	}
	if (NULL != m_cluster_center) {
		_mm_free(m_cluster_center);
		m_cluster_center = NULL;
	}
	if (NULL != m_cluster) {
		_mm_free(m_cluster);
		m_cluster = NULL;
	}
}

lam::math::stat::HMEANS01 &
lam::math::stat::HMEANS01::operator=(_In_ const HMEANS01 &x) {
	if (this == &x) return (*this);
	m_cluster_num = x.m_cluster_num;
	m_dim_num = x.m_dim_num;
	m_samples_num = x.m_samples_num;
	m_iter_max = x.m_iter_max;
	m_iter_num = x.m_iter_num;
	m_seed = x.m_seed;
	_mm_free(m_cluster_energy);
	_mm_free(m_cluster_population);
	_mm_free(m_cluster_center);
	_mm_free(m_cluster);
	int32_t * __restrict cluster = 
		reinterpret_cast<int32_t*>(_mm_malloc(m_samples_num*sizeof(int32_t),align64B));
	double * __restrict cluster_center = 
		reinterpret_cast<double*>(_mm_malloc((m_dim_num*m_cluster_num)*sizeof(double),align64B));
	int32_t * __restrict cluster_population = 
		reinterpret_cast<int32_t*>(_mm_malloc(m_cluster_num*sizeof(int32_t),align64B));
	double * __restrict cluster_energy = 
		reinterpret_cast<double*>(_mm_malloc(m_cluster_num*sizeof(double),align64B));
	if (NULL == cluster ||
		NULL == cluster_center ||
		NULL == cluster_population ||
		NULL == cluster_energy) {
#if (PRINT_CALLSTACK_ON_ERROR) == 1
		DUMP_CALLSTACK_ON_ERROR
#endif
			ABORT_ON_ERROR("HMEANS01::operator=(HMEANS01 &) -- !!! Memory Allocation Failure !!! ", MALLOC_FAILED)
	}
	for (int32_t i = 0; i != x.m_samples_num; ++i)
		cluster[i] = x.m_cluster[i];
	for (int32_t i = 0; i != x.m_dim_num; ++i)
	    for (int32_t j = 0; j != x.m_cluster_num; ++j)
			cluster_center[Ix2D(i, x.m_dim_num, j)] = x.m_cluster_center[Ix2D(i,x.m_dim_num,j)];
    for (int32_t i = 0; i != x.m_cluster_num; ++i) {
		cluster_population[i] = x.m_cluster_population[i];
		cluster_energy[i] = x.m_cluster_energy[i];
	}
	m_cluster = cluster;
	m_cluster_center = cluster_center;
	m_cluster_population = cluster_population;
	m_cluster_energy = cluster_energy;
	return (*this);
}

lam::math::stat::HMEANS01 &
lam::math::stat::HMEANS01::operator=(_In_ HMEANS01 &&x) {
	if (this == &x) return (*this);
	m_cluster_num = x.m_cluster_num;
	m_dim_num = x.m_dim_num;
	m_samples_num = x.m_samples_num;
	m_iter_max = x.m_iter_max;
	m_iter_num = x.m_iter_num;
	m_seed = x.m_seed;
	_mm_free(m_cluster_energy);
	_mm_free(m_cluster_population);
	_mm_free(m_cluster_center);
	_mm_free(m_cluster);
	m_cluster = x.m_cluster;
	m_cluster_center = x.m_cluster_center;
	m_cluster_population = x.m_cluster_population;
	m_cluster_energy = x.m_cluster_energy;

	x.m_cluster_num = 0;
	x.m_dim_num = 0;
	x.m_samples_num = 0;
	x.m_iter_max = 0;
	x.m_iter_num = 0;
	x.m_seed = 0;
	x.m_cluster = NULL;
	x.m_cluster_center = NULL;
	x.m_cluster_population = NULL;
	x.m_cluster_energy = NULL;
	return (*this);
}

void
lam::math::stat::
compute_hmeans01(_Inout_ HMEANS01 &hm01, 
				  _In_ double * __restrict sig_samples,
				 _Inout_ double * __restrict cluster_variance) {
	
	cluster_initialize_5(&hm01.m_dim_num,&hm01.m_samples_num,&hm01.m_cluster_num,
					     &sig_samples[0],&hm01.m_seed,&hm01.m_cluster_center[0]);
	
	hmeans_01(&hm01.m_dim_num,&hm01.m_samples_num,&hm01.m_cluster_num,&hm01.m_iter_max,
		&hm01.m_iter_num, &sig_samples[0], &hm01.m_cluster[0], &hm01.m_cluster_center[0],
		&hm01.m_cluster_population[0], &hm01.m_cluster_energy[0]);

	cluster_variance_compute(&hm01.m_dim_num,&hm01.m_samples_num,&hm01.m_cluster_num,
		&sig_samples[0], &hm01.m_cluster[0], &hm01.m_cluster_center[0], &cluster_variance[0]);

	cluster_print_summary(&hm01.m_samples_num, &hm01.m_cluster_num, &hm01.m_cluster_population[0],
		&hm01.m_cluster_energy[0], &cluster_variance[0]);
}

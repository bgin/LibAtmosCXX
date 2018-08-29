
#ifndef __LAM_PERF_COLLECTOR_RDTSCP_H__
#define __LAM_PERF_COLLECTOR_RDTSCP_H__


#if !defined (LAM_PERF_COLLECTOR_RDTSCP_MAJOR)
#define LAM_PERF_COLLECTOR_RDTSCP_MAJOR 1
#endif

#if !defined (LAM_PERF_COLLECTOR_RDTSCP_MINOR)
#define LAM_PERF_COLLECTOR_RDTSCP_MINOR 0
#endif

#if !defined (LAM_PERF_COLLECTOR_RDTSCP_MICRO)
#define LAM_PERF_COLLECTOR_RDTSCP_MICRO 0
#endif

#if !defined (LAM_PERF_COLLECTOR_RDTSCP_FULLVER)
#define LAM_PERF_COLLECTOR_RDTSCP_FULLVER 1000
#endif

#if !defined (LAM_PERF_COLLECTOR_RDTSCP_CREATE_DATE)
#define LAM_PERF_COLLECTOR_RDTSCP_CREATE_DATE "21-08-2018 16:51 +00200 (TUE 21 AUG 2018 GMT+2)"
#endif

#if !defined (LAM_PERF_COLLECTOR_RDTSCP_BUILD_DATE)
#define LAM_PERF_COLLECTOR_RDTSCP_BUILD_DATE " "
#endif

#if !defined (LAM_PERF_COLLECTOR_RDTSCP_AUTHOR)
#define LAM_PERF_COLLECTOR_RDTSCP_AUTHOR "Programmer: Bernard Gingold, contact: beniekg@gmail.com"
#endif

#if !defined (LAM_PERF_COLLECTOR_RDTSCP_DESCRIPT)
#define LAM_PERF_COLLECTOR_RDTSCP_DESCRIPT "Code section performance collector class based on RDTSCP machine-code instruction. "
#endif

#include <vector>
#include <string>
#include <cstdint>
#include "../LAM_config.h"
#if (USE_MKL) == 1 && defined (LAM_COMPILED_BY_ICC)
#include <mkl_dfti.h>
#endif
#if (USE_ACCURATE_IEEE754_2008_FP) == 1
#include <bfp754.h>
#endif

void rdft(int, int, double *, int *, double *);

namespace  lam {
	namespace system {

		struct  PerfCollectorRDTSCP {
				
				bool         m_Iscleared; 

				std::size_t  m_nsamples;

				std::string  m_func_name;

				std::string  m_file_name;

				std::string  m_date;

				std::string  m_time;
				// this member describe successful computation of delta value (success == true, otherwise false)
				std::vector<bool>  m_nvalid_values;
				// profiling samples  start  values
				std::vector<uint64_t>  m_start_values;
				// profiling samples, stop values
				std::vector<uint64_t>  m_stop_values;
				// Time samples delta
				std::vector<uint64_t>  m_delta_values;
				// Output of TSC_AUX MSR (core mapping)
				std::vector<uint32_t>  m_tscaux_start;
				// Same as above (stop measurements)
				std::vector<uint32_t>  m_tscaux_stop;

				constexpr static size_t lo_bound = 3Ui64;

				constexpr static size_t lowest = 1Ui64;

				constexpr static size_t zero = 0Ui64;

				PerfCollectorRDTSCP();

				PerfCollectorRDTSCP(_In_ const PerfCollectorRDTSCP &);

				PerfCollectorRDTSCP(_In_ PerfCollectorRDTSCP &&) noexcept(true);

				~PerfCollectorRDTSCP() noexcept(true) = default;

				PerfCollectorRDTSCP & operator=(_In_ const PerfCollectorRDTSCP &);

				PerfCollectorRDTSCP & operator=(_In_ PerfCollectorRDTSCP &&) noexcept(true);

				void start() noexcept(false);

				void stop()  noexcept(false);

				void clear_all();

				bool compute_delta() noexcept(false);

#if   (USE_ACCURATE_IEEE754_2008_FP) == 1
				// This version relies on Intel libbfp754 and that means
				// probably slower execution speed (not confirmed yet).
				bool compute_stats(_Out_ double &,
								   _Out_ double &,
								   _Out_ double &,
								   _Out_ double &,
								   _Out_ double &);
#else
				bool compute_stats(_Out_ double &,
								   _Out_ double &,
								   _Out_ double &,
								   _Out_ double &,
								   _Out_ double &);
#endif
				/*
					If using MKL for FFT pass null pointers to 
					correlation_set (those pointers are used to
					                 call Ouru FFT rdft function)
					Usage of MKL DFTI is set as a default.
				*/
				static bool correlation_set(_In_ PerfCollectorRDTSCP &,
										    _In_ PerfCollectorRDTSCP &,
											_Out_ double * __restrict,
											_In_  int32_t * __restrict,
											_In_  double * __restrict,
											_In_  const int32_t );

				void print() const;

				bool check_data_size();

#if (USE_ACCURATE_IEEE754_2008_FP) == 1
				// This version relies on Intel libbfp754 and that means
				// probably slower execution speed (not confirmed yet).
				bool cvrt_to_double(_Out_ double * __restrict,
								    _In_ const std::size_t) noexcept(true);
#else
				bool cvrt_to_double(_Out_ double * __restrict,
					_In_ const std::size_t) noexcept(true);
#endif

		};
	}
}




#endif /*__LAM_PERF_COLLECTOR_RDTSCP_H__*/
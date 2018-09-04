
#ifndef __LAM_PERF_COLLECTOR_RDTSCP_H__
#define __LAM_PERF_COLLECTOR_RDTSCP_H__

// File version global constans

const unsigned int gLAM_PERF_COLLECTOR_RDTSCP_MAJOR = 1U;

const unsigned int gLAM_PERF_COLLECTOR_RDTSCP_MINOR = 0U;

const unsigned int gLAM_PERF_COLLECTOR_RDTSCP_MICRO = 0U;

const unsigned int gLAM_PERF_COLLECTOR_RDTSCP_FULLVER = 
	1000U*gLAM_PERF_COLLECTOR_RDTSCP_MAJOR + 100U*gLAM_PERF_COLLECTOR_RDTSCP_MINOR + 10U*gLAM_PERF_COLLECTOR_RDTSCP_MICRO;

const char * const pgLAM_PERF_COLLECTOR_RDTSCP_CREATE_DATE = "21-08-2018 16:51 +00200 (TUE 21 AUG 2018 GMT+2)";

const char * const pgLAM_PERF_COLLECTOR_RDTSCP_BUILD_DATE = "00-00-0000 00:00";

const char * const pgLAM_PERF_COLLECTOR_RDTSCP_AUTHOR = "Programmer: Bernard Gingold, contact: beniekg@gmail.com";

const char * const pgLAM_PERF_COLLECTOR_RDTSCP_SYNOPSIS = "Code section performance collector class based on RDTSCP machine-code instruction.";



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

				bool  delta_values_eq(_Out_ std::vector<bool> &,
									  _In_ const PerfCollectorRDTSCP &,
									  _In_ const PerfCollectorRDTSCP &);

				bool   delta_values_ineq(_Out_ std::vector<bool> &,
										 _In_ const PerfCollectorRDTSCP &,
										 _In_ const PerfCollectorRDTSCP &);

				bool   delta_values_gt(_Out_ std::vector<bool> &,
									   _In_ const PerfCollectorRDTSCP &,
									   _In_ const PerfCollectorRDTSCP &);

				bool   delta_values_lt(_Out_ std::vector<bool> &,
									   _In_ const PerfCollectorRDTSCP &,
									   _In_ const PerfCollectorRDTSCP &);

		};
	}
}




#endif /*__LAM_PERF_COLLECTOR_RDTSCP_H__*/
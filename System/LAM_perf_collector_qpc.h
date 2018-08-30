
#ifndef __LAM_PERF_COLLECTOR_QPC_H__
#define __LAM_PERF_COLLECTOR_QPC_H__

#if !defined (LAM_PERF_COLLECTOR_QPC_MAJOR)
#define LAM_PERF_COLLECTOR_QPC_MAJOR 1
#endif

#if !defined (LAM_PERF_COLLECTOR_QPC_MINOR)
#define LAM_PERF_COLLECTOR_QPC_MINOR 0
#endif

#if !defined (LAM_PERF_COLLECTOR_QPC_MICRO)
#define LAM_PERF_COLLECTOR_QPC_MICRO 0
#endif

#if !defined (LAM_PERF_COLLECTOR_QPC_FULLVER)
#define LAM_PERF_COLLECTOR_QPC_FULLVER 1000
#endif

#if !defined (LAM_PERF_COLLECTOR_QPC_CREATE_DATE)
#define LAM_PERF_COLLECTOR_QPC_CREATE_DATE "29-08-2018 15:28 +00200 (WED 29 AUG 2018 GMT+2)"
#endif

#if !defined (LAM_PERF_COLLECTOR_QPC_BUILD_DATE)
#define LAM_PERF_COLLECTOR_QPC_BUILD_DATE " "
#endif

#if !defined (LAM_PERF_COLLECTOR_QPC_AUTHOR)
#define LAM_PERF_COLLECTOR_QPC_AUTHOR "Programmer: Bernard Gingold, contact: beniekg@gmail.com"
#endif

#if !defined (LAM_PERF_COLLECTOR_QPC_DESCRIPT)
#define LAM_PERF_COLLECTOR_QPC_DESCRIPT "Code section performance collector class based on QueryPerformanceCounter."
#endif

#include <vector>
#include <string>
#include <cstdint>
#include <Windows.h>
#include "../LAM_config.h"
#if (USE_MKL) == 1 && defined (LAM_COMPILED_BY_ICC)
#include <mkl_dfti.h>
#endif
#if (USE_ACCURATE_IEEE754_2008_FP) == 1
#include <bfp754.h>
#endif

void rdft(int, int, double *, int *, double *);

namespace lam {
	namespace system {

		struct PerfCollectorQPC {
				
				bool		 m_Iscleared;

				std::size_t  m_nsamples; // Counter of valid measurements.

				std::string  m_func_name;

				std::string  m_file_name;

				std::string  m_date;

				std::string  m_time;

				// this member describe successful computation of delta value (success == true, otherwise false)
				std::vector<bool>          m_nvalid_values;
				// profiling samples  start  values
				std::vector<LARGE_INTEGER> m_start_values;
				// profiling samples, stop values
				std::vector<LARGE_INTEGER> m_stop_values;
				// Time samples delta
				std::vector<double>        m_delta_values;
				//  Performance Counter values themselves (
				std::vector<LARGE_INTEGER> m_pc_values;

				constexpr static size_t lo_bound = 3Ui64;

				constexpr static size_t lowest = 1Ui64;

				constexpr static size_t zero = 0Ui64;

				PerfCollectorQPC();

				PerfCollectorQPC(_In_ const PerfCollectorQPC &);

				PerfCollectorQPC(_In_ PerfCollectorQPC &&) noexcept(true);

				~PerfCollectorQPC() noexcept(true) = default;

				PerfCollectorQPC &  operator=(_In_ const PerfCollectorQPC &);

				PerfCollectorQPC &  operator=(_In_ PerfCollectorQPC &&) noexcept(true);

				bool start() noexcept(false);

				bool stop()  noexcept(false);

				void clear_all();

				bool compute_delta() noexcept(false);

#if (USE_ACCURATE_IEEE754_2008_FP) == 1
				
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
				static bool correlation_set(_In_ PerfCollectorQPC &,
											_In_ PerfCollectorQPC &,
											_Out_ double * __restrict,
											_In_ int32_t * __restrict,
											_In_ double * __restrict,
											_In_ const int32_t );

				void print() const;

				bool check_data_size()const noexcept(true);



		};
	}
}




#endif /*__LAM_PERF_COLLECTOR_QPC_H__*/
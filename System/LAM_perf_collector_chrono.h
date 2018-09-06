
#ifndef __LAM_PERF_COLLECTOR_CHRONO_H__
#define __LAM_PERF_COLLECTOR_CHRONO_H__

// File version info

const unsigned int gLAM_PERF_COLLECTOR_CHRONO_MAJOR = 1U;

const unsigned int gLAM_PERF_COLLECTOR_CHRONO_MINOR = 0U;

const unsigned int gLAM_PERF_COLLECTOR_CHRONO_MICRO = 0U;

const unsigned int gLAM_PERF_COLLECTOR_CHRONO_FULLVER = 
	1000U*gLAM_PERF_COLLECTOR_CHRONO_MAJOR+100U*gLAM_PERF_COLLECTOR_CHRONO_MINOR+10U*gLAM_PERF_COLLECTOR_CHRONO_MICRO;

const char * const pgLAM_PERF_COLLECTOR_CHRONO_CREATE_DATE = "06-09-2018 11:32 +00200 (THR 06 SEP 2018 GMT+2)";

const char * const pgLAM_PERF_COLLECTOR_CHRONO_BUILD_DATE = "00-00-0000 00:00";

const char * const pgLAM_PERF_COLLECTOR_CHRONO_AUTHOR = "Programmer: Bernard Gingold, contact: beniekg@gmail.com";

const char * const pgLAM_PERF_COLLECTOR_CHRONO_SYNOPSIS = "Code section performance collector class based on C++ std library chrono header file.";

#include <vector>
#include <string>
#include <cstdint>
#include <chrono>
#include "../LAM_config.h"
#if (USE_MKL) && defined (LAM_COMPILED_BY_ICC)
#include <mkl_dfti.h>
#endif
#if (USE_ACCURATE_IEEE754_2008_FP) == 1
#include <bfp754.h>
#endif

void rdft(int, int, double *, int *, double *);

namespace lam {
	namespace system {

		struct PerfCollectorChrono{

			    using PERIOD = std::chrono::duration<double>;

			    using TIME_VAL = std::chrono::time_point<std::chrono::high_resolution_clock>; // <--- STD Lib OOP bullshit
				
				bool		  m_Iscleared;

				std::size_t   m_nsamples;

				std::string   m_funcname;

				std::string   m_filename;

				std::string   m_date;

				std::string   m_time;

				std::vector<bool> m_nvalid_values;

				std::vector<TIME_VAL> m_start_values;

				std::vector<TIME_VAL> m_stop_values;

				std::vector<double> m_delta_values;

				constexpr static size_t  lo_bound = 3Ui64;

				constexpr static size_t  lowest = 1Ui64;

				constexpr static size_t  zero = 0Ui64;

				PerfCollectorChrono();

				PerfCollectorChrono(_In_ const PerfCollectorChrono &);

				PerfCollectorChrono(_In_ PerfCollectorChrono &&) noexcept(true);

				~PerfCollectorChrono() noexcept(true);

				PerfCollectorChrono & operator=(_In_ const PerfCollectorChrono &);

				PerfCollectorChrono & operator=(_In_ PerfCollectorChrono &&) noexcept(true);

				void start() noexcept(false);

				void stop() noexcept(false);

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
				static bool correlation_set(_In_ PerfCollectorChrono &,
										    _In_ PerfCollectorChrono &,
											_In_ double * __restrict,
											_In_ int32_t * __restrict,
											_In_ double * __restrict,
											_In_ const int32_t);

				void print() const;

				bool check_data_size() const noexcept(true);

		};
	}
}



#endif /*__LAM_PERF_COLLECTOR_CHRONO_H__*/
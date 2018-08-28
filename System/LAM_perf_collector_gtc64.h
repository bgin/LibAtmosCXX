
#ifndef __LAM_PERF_COLLECTOR_GTC64_H__
#define __LAM_PERF_COLLECTOR_GTC64_H__

#if !defined (LAM_PERF_COLLECTOR_GTC64_MAJOR)
#define LAM_PERF_COLLECTOR_GTC64_MAJOR 1
#endif

#if !defined (LAM_PERF_COLLECTOR_GTC64_MINOR)
#define LAM_PERF_COLLECTOR_GTC64_MINOR 0
#endif

#if !defined (LAM_PERF_COLLECTOR_GTC64_MICRO)
#define LAM_PERF_COLLECTOR_GTC64_MICRO 0
#endif

#if !defined (LAM_PERF_COLLECTOR_GTC64_FULLVER)
#define LAM_PERF_COLLECTOR_GTC64_FULLVER 1000
#endif

#if !defined (LAM_PERF_COLLECTOR_GTC64_CREATE_DATE)
#define LAM_PERF_COLLECTOR_GTC64_CREATE_DATE "26-08-2018 16:07 +00200 (SUN 26 AUG 2018 GMT+2) "
#endif

#if !defined (LAM_PERF_COLLECTOR_GTC64_BUILD_DATE)
#define LAM_PERF_COLLECTOR_GTC64_BUILD_DATE " "
#endif

#if !defined (LAM_PERF_COLLECTOR_GTC64_AUTHOR)
#define LAM_PERF_COLLECTOR_GTC64_AUTHOR "Programmer: Bernard Gingold, contact: beniekg@gmail.com"
#endif

#if !defined (LAM_PERF_COLLECTOR_GTC64_DESCRIPT)
#define LAM_PERF_COLLECTOR_GTC64_DESCRIPT "Code section performance collector class based on Win API GetTickCount64 function."
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
	namespace system  {



		struct PerfCollectorGTC64 {

				bool  m_Iscleared;

				std::size_t  m_nsamples;

				std::string  m_funcname;

				std::string  m_filename;

				std::string  m_date;

				std::string  m_time;

				std::vector<bool>  m_nsuccess; // this member describe successful computation of delta value (success == true, otherwise false)

				std::vector<ULONGLONG>  m_start_values;

				std::vector<ULONGLONG>  m_stop_values;

				std::vector<ULONGLONG>  m_delta_values;

				constexpr static size_t  lo_bound = 3Ui64;

				constexpr static size_t  lowest = 1Ui64;

				constexpr static size_t  zero = 0Ui64;

				PerfCollectorGTC64();

				PerfCollectorGTC64(_In_ const PerfCollectorGTC64 &);

				PerfCollectorGTC64(_In_ PerfCollectorGTC64 &&) noexcept(true);

				~PerfCollectorGTC64() noexcept(true) = default;

				PerfCollectorGTC64 & operator=(_In_ const PerfCollectorGTC64 &);

				PerfCollectorGTC64 & operator=(_In_ PerfCollectorGTC64 &&) noexcept(true);

				void start() noexcept(false);

				void stop()  noexcept(false);

				void clear_all();

				bool compute_delta() noexcept(false);

#if (USE_ACCURATE_IEEE754_2008_FP) == 1
                // This version relies on Intel libbfp754 and that means
				// probably slower execution speed (not confirmed yet).
				bool  compute_stats(_Out_ double &,
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
				static bool correlation_set(_In_ PerfCollectorGTC64 &,
										    _In_ PerfCollectorGTC64 &,
											_Out_ double * __restrict,
											_In_ int32_t * __restrict,
											_In_ double * __restrict,
											_In_ const int32_t);

				void print() const;

		        bool check_data_size() noexcept(true);

		        bool cvrt_to_double(_Out_ double * __restrict,
								     _In_ const std::size_t) noexcept(true);

		};
	}
}




#endif /*__LAM_PERF_COLLECTOR_GTC64_H__*/

#ifndef __LAM_QPC_TIMER_H__
#define __LAM_QPC_TIMER_H__

// File info
const unsigned int gLAM_QPC_TIMER_MAJOR = 1U;

const unsigned int gLAM_QPC_TIMER_MINOR = 0U;

const unsigned int gLAM_QPC_TIMER_MICRO = 0U;

const unsigned int gLAM_QPC_TIMER_FULLVER  = 
	1000U*gLAM_QPC_TIMER_MAJOR + 100U*gLAM_QPC_TIMER_MINOR + 10U*gLAM_QPC_TIMER_MICRO;

const char * const pgLAM_QPC_TIMER_CREATE_DATE = "01-09-2018 12:52 +00200 (SAT 01 SEP 2018 GMT+2)";
// File build date (should be set after successful build of this translation unit.
const char * const pgLAM_QPC_TIMER_BUILD_DATE = "00-00-0000 00:00";

const char * const pgLAM_QPC_TIMER_AUTHOR = "Programmer: Bernard Gingold, contact: beniekg@gmail.com";

const char * const pgLAM_QPC_TIMER_SYNOPSIS = "QueryPerfromanceCounter based performance measurement class.";

#include <vector>
#include <string>
#include <cstdint>
#include <Windows.h>
#include "../LAM_config.h"
#if (USE_ACCURATE_IEEE754_2008_FP) == 1
#include <bfp754.h>
#endif

namespace lam {
	namespace system {

			struct QPCTimer {

				using fptr = void(*)(void);

				std::size_t  m_nruns;

				std::size_t  m_datum_size;

				fptr         m_ptfunc;

				fptr         m_ptwrap;

				std::string  m_func_name;

				std::string  m_file_name;

				std::vector<LARGE_INTEGER> m_timing_values;

				std::vector<LARGE_INTEGER> m_overhead_values;

				std::vector<LARGE_INTEGER> m_pc_values;

				std::vector<double>    m_delta_values;

				static constexpr uint64_t lo_bound = 3Ui64;

				static constexpr uint64_t zero = 0Ui64;

				QPCTimer() = default;

				QPCTimer(_In_ const std::size_t,
						 _In_ const std::size_t,
						 _In_ const fptr,
						 _In_ const fptr,
						 _In_ const char *,
						 _In_ const char * );

				QPCTimer(_In_ const QPCTimer &);

				QPCTimer(_In_ QPCTimer &&) noexcept(true);

				inline ~QPCTimer() noexcept(true);

				QPCTimer & operator=(_In_ const QPCTimer &);

				QPCTimer & operator=(_In_ QPCTimer &&) noexcept(true);

				inline std::size_t get_datum_size() const noexcept(true) { return (m_nruns * m_datum_size); }

				bool run_benchmark() noexcept(false);

#if (USE_ACCURATE_IEEE754_2008_FP) == 1

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
				
				void  print() const noexcept(true);

		};
	}
}

#endif /*__LAM_QPC_TIMER_H__*/
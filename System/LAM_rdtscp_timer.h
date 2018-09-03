
#ifndef __LAM_RDTSCP_TIMER_H__
#define __LAM_RDTSCP_TIMER_H__

// File major version
const unsigned int gLAM_RDTSCP_TIMER_MAJOR = 1U;

// File minor version
const unsigned int gLAM_RDTSCP_TIMER_MINOR = 0U;

// File micro version
const unsigned int gLAM_RDTSCP_TIMER_MICRO = 0U;

// File full version
const unsigned int gLAM_RDTSCP_TIMER_FULLVER = 
		1000U*gLAM_RDTSCP_TIMER_MAJOR + 100U*gLAM_RDTSCP_TIMER_MINOR + 10U*gLAM_RDTSCP_TIMER_MICRO;

// File creation date
const  char * const gpLAM_RDTSCP_TIMER_CREATE_DATE = "31-08-2018 14:57 +00200 (FRI 31 AUG 2018 GMT+2)";

// File build date (should be set after successful build of this translation unit.
const char * const gpLAM_RDTSCP_TIMER_BUILD_DATE = "00-00-0000 00:00";

// File author
const char * const gpLAM_RDTSCP_TIMER_AUTHOR = "Programmer: Bernard Gingold, contact: beniekg@gmail.com";

// File short description
const char * const gpLAM_RDTSCP_TIMER_SYNOPSIS = "RDTSCP based performance measurement class.";

#include <vector>
#include <string>
#include <cstdint>
#include "../LAM_config.h"
#if (USE_ACCURATE_IEEE754_2008_FP) == 1
#include <bfp754.h>   // IEEE754_2008 accurate floating-point aruthmetics.
#endif

namespace lam {
	namespace system {

		struct RDTSCPTimer {

				using fptr = void(*)(void);

				std::size_t  m_nruns;

				std::size_t  m_datum_size;

				fptr         m_ptfunc; // Timed function called by the wrapper

				fptr         m_ptwrap; // Empty wrapper body (expect prolog and epilog overhead)

				std::string  m_func_name;

				std::string  m_file_name;

				std::vector<uint64_t> m_timing_values;

				std::vector<uint64_t> m_overhead_values;

				std::vector<uint64_t> m_delta_values; // Delta between timing values and wrapper overhead calls.

				std::vector<std::pair<uint32_t,uint32_t>> m_tscaux_values; // Executing core values (collected only for timing calls)

				static constexpr uint64_t lo_bound = 3Ui64;

				static constexpr uint64_t zero = 0Ui64;

				RDTSCPTimer() = default;

				RDTSCPTimer(_In_ const std::size_t,
							_In_ const std::size_t,
							_In_ const fptr,
							_In_ const fptr,
							_In_ const char *,
							_In_ const char *);

				RDTSCPTimer(_In_ const RDTSCPTimer &);

				RDTSCPTimer(_In_ RDTSCPTimer &&) noexcept(true);

				inline ~RDTSCPTimer() noexcept(true);

				RDTSCPTimer & operator=(_In_ const RDTSCPTimer &);

				RDTSCPTimer & operator=(_In_ RDTSCPTimer &&);

				inline std::size_t get_datum_size() const { return (m_nruns*m_datum_size); }

				void run_benchmark() noexcept(false);

#if (USE_ACCURATE_IEEE754_2008_FP) == 1

				bool  compute_stats(_Out_ double &,
								    _Out_ double &,
									_Out_ double &,
									_Out_ double &,
									_Out_ double & );
#else

				bool  compute_stats(_Out_ double &,
									_Out_ double &,
									_Out_ double &,
									_Out_ double &,
									_Out_ double &);

#endif
				void print() const noexcept(true);

				static bool  delta_values_eq(_Out_ std::vector<bool> &,
											 _In_  const RDTSCPTimer &,
											 _In_  const RDTSCPTimer &);

				static bool  delta_values_ineq(_Out_ std::vector<bool> &,
											   _In_ const RDTSCPTimer &,
											   _In_ const RDTSCPTimer &);

				static bool  delta_values_gt(_Out_ std::vector<bool> &,
											 _In_ const RDTSCPTimer &,
											 _In_ const RDTSCPTimer &);

				static bool  delta_values_lt(_Out_ std::vector<bool> &,
											 _In_ const RDTSCPTimer &,
											 _In_ const RDTSCPTimer &);

		};
	}
}


#endif /*__LAM_RDTSCP_TIMER_H__*/
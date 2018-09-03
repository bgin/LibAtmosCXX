
#ifndef __LAM_CHRONO_TIMER_H__
#define __LAM_CHRONO_TIMER_H__

// Timer based on std::chrono libarary, class -- high_performance_clock
// File version global constants

const unsigned int gLAM_CHRONO_TIMER_MAJOR = 1U;

const unsigned int gLAM_CHRONO_TIMER_MINOR = 0U;

const unsigned int gLAM_CHRONO_TIMER_MICRO = 0U;

const unsigned int gLAM_CHRONO_TIMER_FULLVER = 
		1000U*gLAM_CHRONO_TIMER_MAJOR + 100U*gLAM_CHRONO_TIMER_MINOR + 10U*gLAM_CHRONO_TIMER_MICRO;

const char * const pgLAM_CHRONO_TIMER_CREATE_DATE = "02-09-2018 11:25 +00200 (SUN 02 SEP 2018 GMT+2)";
// File build date (should be set after successful build of this translation unit.
const char * const pgLAM_CHRONO_TIMER_BUILD_DATE = "00-00-0000 00:00";

const char * const pgLAM_CHRONO_TIMER_AUTHOR = "Programmer: Bernard Gingold, contact: beniekg@gmail.com.";

const char * const pgLAM_CHRONO_TIMER_SYNOPSIS = "std::chrono library based performance measurement class.";

#include <chrono>
#include <vector>
#include <string>
#include "../LAM_config.h"
#if (USE_ACCURATE_IEEE754_2008_FP) == 1
#include <bfp754.h>
#endif

namespace lam {
	namespace system {

		struct HRCTimer {

			    using fptr = void(*)(void);

				using PERIOD = std::chrono::duration<double>;

				using TIME_VAL = std::chrono::time_point<std::chrono::high_resolution_clock>; // <--- STD Lib OOP bullshit

				std::size_t  m_nruns;

				std::size_t  m_datum_size;

				fptr         m_ptfunc;

				fptr         m_ptwrap;

				std::string  m_func_name;

				std::string  m_file_name;

				std::vector<double> m_timing_values;

				std::vector<double> m_overhead_values;

				std::vector<double> m_delta_values;

				static constexpr uint64_t lo_bound = 3Ui64;

				static constexpr uint64_t zero = 0Ui64;

				HRCTimer() = default;

				HRCTimer(_In_ const std::size_t,
						 _In_ const std::size_t,
						 _In_ const fptr,
						 _In_ const fptr,
						 _In_ const char *,
						 _In_ const char *);

				HRCTimer(_In_ const HRCTimer &);

				HRCTimer(_In_ HRCTimer &&) noexcept(true);

				inline ~HRCTimer() noexcept(true);

				HRCTimer & operator=(_In_ const HRCTimer &);

				HRCTimer & operator=(_In_ HRCTimer &&) noexcept(true);

				inline std::size_t get_datum_size() const noexcept(true) { return (m_nruns * m_datum_size); }

				void run_benchmark(_In_ const double) noexcept(false);

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
				void print() const;

				static bool delta_values_eq(_Out_ std::vector<bool> &,
											_In_ const HRCTimer &,
										    _In_ const HRCTimer & ,
											_In_ const double);

				static bool delta_values_ineq(_Out_ std::vector<bool> &,
											  _In_ const HRCTimer &,
											  _In_ const HRCTimer &,
											  _In_ const double	);

				static bool delta_values_lt( _Out_ std::vector<bool> &,
											 _In_ const HRCTimer &,
											 _In_ const HRCTimer &,
											 _In_ const double);

				static bool delta_values_gt( _Out_ std::vector<bool> &,
											 _In_ const HRCTimer &,
											 _In_ const HRCTimer &,
											 _In_ const double );
				
		};
	}
}

#endif /*__LAM_CHRONO_TIMER_H__*/

#ifndef __LAM_GTC64_TIMER_H__
#define __LAM_GTC64_TIMER_H__

#if !defined (LAM_GTC64_TIMER_MAJOR)
#define LAM_GTC64_TIMER_MAJOR 1
#endif

#if !defined (LAM_GTC64_TIMER_MINOR)
#define LAM_GTC64_TIMER_MINOR 0
#endif

#if !defined (LAM_GTC64_TIMER_MICRO)
#define LAM_GTC64_TIMER_MICRO 0
#endif

#if !defined (LAM_GTC64_TIMER_FULLVER)
#define LAM_GTC64_TIMER_FULLVER 1000
#endif

#if !defined (LAM_GTC64_TIMER_CREATE_DATE)
#define LAM_GTC64_TIMER_CREATE_DATE "26-08-2018 11:07 +00200 (SUN 26 AUG 2018 GMT+2) "
#endif

#if !defined (LAM_GTC64_TIMER_BUILD_DATE)
#define LAM_GTC64_TIMER_BUILD_DATE " "
#endif

#if !defined (LAM_GTC64_TIMER_AUTHOR)
#define LAM_GTC64_TIMER_AUTHOR "Programmer: Bernard Gingold, contact: beniekg@gmail.com"
#endif

#if !defined (LAM_GTC64_TIMER_DESCRIPT)
#define LAM_GTC64_TIMER_DESCRIPT " GetTickCount64 - timer based class."
#endif


#include <vector>
#include <string>
#include <functional>
#include <Windows.h>


namespace lam {
	namespace system {

			struct GTC64Timer {
				
				using fptr = void(*)();
				using timed_func = std::function<void(void)>;

				std::size_t  m_nruns;

				std::size_t  m_datum_size;

				timed_func   m_tfunc;

				std::string  m_func_name;

				std::string  m_file_name;

				std::vector<bool> m_nsuccess;

				std::vector<ULONGLONG> m_timing_values;

				static constexpr ULONGLONG lo_bound = 3Ui64;

				static constexpr ULONGLONG zero = 0Ui64;

				GTC64Timer() = default;

				GTC64Timer(_In_ const std::size_t,
						   _In_ const std::size_t,
						   _In_ const fptr tf,
						   _In_ const char *,
						   _In_ const char *);

				GTC64Timer(_In_ const GTC64Timer &);

				GTC64Timer(_In_ GTC64Timer &&) noexcept(true);

				~GTC64Timer() noexcept(true) = default;

				GTC64Timer & operator=(_In_ const GTC64Timer &);

				GTC64Timer & operator=(_In_ GTC64Timer &&) noexcept(true);

				inline std::size_t get_datum_size() const { return (m_nruns * m_datum_size); }

				void run_benchmark();

				bool compute_stats(_Out_ double &,
								   _Out_ double &,
								   _Out_ double &,
								   _Out_ double &,
								   _Out_ double &);

				void print() const;


		};
	}
}


#endif /*__LAM_GTC64_TIMER_H__*/

#ifndef __LAM_RDTSCP_TIMER_HPP__
#define __LAM_RDTSCP_TIMER_HPP__

#if !defined (LAM_RDTSCP_TIMER_MAJOR)
#define LAM_RDTSCP_TIMER_MAJOR 1
#endif

#if !defined (LAM_RDTSCP_TIMER_MINOR)
#define LAM_RDTSCP_TIMER_MINOR 0
#endif

#if !defined (LAM_RDTSCP_TIMER_MICRO)
#define LAM_RDTSCP_TIMER_MICRO 0
#endif

#if !defined (LAM_RDTSCP_TIMER_FULLVER)
#define LAM_RTDSCP_TIMER_FULLVER 1000
#endif

#if !defined (LAM_RDTSCP_TIMER_CREATE_DATE)
#define LAM_RDTSCP_TIMER_CREATE_DATE " 25-08-2018 12:11 +00200 (SAT 25 AUG 2018 GMT+2)"
#endif

#if !defined (LAM_RDTSCP_TIMER_BUILD_DATE)
#define LAM_RDTSCP_TIMER_BUILD_DATE " "
#endif

#if !defined (LAM_RDTSCP_TIMER_AUTHOR)
#define LAM_RDTSCP_TIMER_AUTHOR "Programmer: Bernard Gingold, contact: beniekg@gmail.com"
#endif

#include <cstdint>
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include "../Math/LAM_constants.h"
#include "../LAM_indices.h"

namespace lam {
	namespace system {

		template<class _Functor>  struct RdtscpTimer {

			
			std::size_t m_nruns;

			std::size_t m_datum_size;

			_Functor  m_functor;

			std::string m_func_name;

			std::string m_file_name;

			std::vector<bool> m_nsuccess;

			std::vector<uint64_t> m_timing_values;

			std::vector<uint32_t> m_tscaux_start;

			std::vector<uint32_t> m_tscaux_stop;

			static constexpr size_t zero = 0Ui64;

			RdtscpTimer() = default;

			RdtscpTimer(_In_ const size_t nruns,
					    _In_ const size_t datum_size,
						_In_ _Functor & functor,
						_In_ const char * pfuname,
						_In_ const char * pfilename) noexcept(false)
			:
			m_nruns{ nruns },
			m_datum_size{datum_size},
			m_functor(functor),
			m_func_name{ pfuname },
			m_file_name{ pfilename},
			m_nsuccess(m_nruns     * m_datum_size),
			m_timing_values(m_runs * m_datum_size),
			m_tscaux_start(m_runs  * m_datum_size),
			m_tscaux_stop(m_runs   * m_datum_size)
			{}

			RdtscpTimer(_In_ const RdtscpTimer &x) noexcept(false)
				:
				m_nruns{ x.m_nruns },
				m_datum_size{ x.m_datum_size },
				m_functor{ x.m_functor },
				m_func_name{ x.m_func_name },
				m_file_name{ x.m_file_name },
				m_nsuccess{ x.m_nsuccess },
				m_timing_values{ x.m_timing_values },
				m_tscaux_start{ x.m_tscaux_start },
				m_tscaux_stop{ x.m_tscaux_stop }
			{}

			RdtscpTimer(_In_ RdtscpTimer &&x) noexcept(true)
				:
				m_nruns{ std::move(x.m_nruns) },
				m_datum_size{ std::move(x.m_datum_size) },
				m_functor{ std::move(x.m_functor) },
				m_func_name{ std::move(x.m_func_name) },
				m_file_name{ std::move(x.m_file_name) },
				m_nsuccess{ std::move(x.m_nsuccess) },
				m_timing_values{ std::move(x.m_timing_values) },
				m_tscaux_start{ std::move(x.m_tscaux_start) },
				m_tscaux_stop{ std::move(x.m_tscaux_stop) }
			{}

			~RdtscpTimer() noexcept(true) = default;

			RdtscpTimer & operator=(_In_ const RdtscpTimer &x) noexcept(false) {
				   if (this == &x) return (*this);
				       m_nruns = x.m_nruns;
				       m_datum_size = x.m_datum_size;
				       m_functor = x.m_functor;
				       m_func_name.operator=(x.m_func_name);
				       m_file_name.operator=(x.m_file_name);
				       m_nsuccess.operator=(x.m_nsuccess);
				       m_timing_values.operator=(x.m_timing_values);
				       m_tscaux_start.operator=(x.m_tscaux_start);
				       m_tscaux_stop.operator=(x.m_tscaux_stop);
				    return (*this);
			}

			RdtscpTimer & operator=(_In_ RdtscpTimer &&x) noexcept(true) {
				   if (this == &x) return (*this);
				       m_nruns = std::move(x.m_nruns);
					   m_datum_size = std::move(x.m_datum_size);
					   m_functor = std::move(x.m_functor);
					   m_func_name.operator=(std::move(x.m_func_name));
					   m_file_name.operator=(std::move(x.m_file_name));
					   m_nsuccess.operator=(std::move(x.m_nsuccess));
					   m_timing_values.operator=(std::move(x.m_timing_values));
					   m_tscaux_start.operator=(std::move(x.m_tscaux_start));
					   m_tscaux_stop.operator=(std::move(x.m_tscaux_stop));
				   return (*this);
			}

			
			void  run_benchmark() {
				  
				
				  volatile uint64_t TSC_START{}, TSC_STOP{};
				  uint32_t tscaux_start{ 9999 }, tscaux_stop{ 9999 };
				  volatile int32_t warmup{};
				  int32_t dummy1{}; // memory aliasing at dummy2[-1];
				  int32_t dummy2[4] = {};
				  
				  for (size_t i = 0Ui64; i != m_nruns; ++i) {
					  for (size_t j = 0Ui64; j != m_datum_size; ++j) {

						   warmup = 1;
						   __cpuid(&dummy2[0],dummy1);
						   TSC_START = __rdtscp(&tscaux_start);
						   m_functor();
						   TSC_STOP = __rdtscp(&tscaux_stop);
						   __cpuid(&dummy2[0],dummy1);

						   if ((TSC_STOP - TSC_START) <= 0Ui64) {
							   std::printf("Fatal Error -- invalid timing read out at: i:%llu,j:%llu, TSC_START=%llu, TSC_STOP=%llu, DELTA=%llu\n",
								   i, j, TSC_START, TSC_STOP, (TSC_STOP-TSC_START));
							   m_timing_values.operator[](Ix2D(i,m_datum_size,j) = 0Ui64;
							   m_tscaux_start.operator[](Ix2D(i,m_datum_size,j)) = tscaux_start;
							   m_tscaux_stop.operator[](Ix2D(i,m_datum_size))    = tscaux_stop;
						   }
						   else {
							   m_timing_values.operator[](Ix2D(i,m_datum_size,j)) = TSC_STOP - TSC_START;
							   m_tscaux_start.operator[](Ix2D(i,m_datum_size,j)) = tscaux_start;
							   m_tscaux_stop.operator[](Ix2D(i,m_datum_size,j))  = tscaux_stop;
						   }
					  }
				  }

			}

			bool compute_stats(_Out_ double &mean,
							   _Out_ double &adev,
							   _Out_ double &sdev,
							   _Out_ double &skew,
							   _Out_ double &kurt) {
				using namespace lam::math::constants;
				uint64_t s{}, prev{};
				__declspec(align(64)) struct{
					double len{}, sum{}, var{}, t{}, t2{}, t3{},
					t4{}, t5{}, isdev{}, fracp{}, ct2{}, tmp{};
				} r8_loc;
				

				r8_loc.len = static_cast<double>(m_timing_values.size());
				//   Compute mean (guard against an overflow)
				for (size_t i = 0Ui64; i != m_timing_values.size(); ++i) {
					if (s < prev) return (false);
					prev = s;
					s += m_timing_values.operator[](i);
				}
				r8_loc.sum = static_cast<double>(s);
				mean = r8_loc.sum / r8_loc.len;
				//  Compute average deviation and variance
				for (size_t i = 0Ui64; i != m_timing_values.size(); ++i) {
					if (zero != m_timing_values.operator[](i)) {
						tmp = static_cast<double>(m_timing_values[i]);
						r8_loc.t = std::abs(static_cast<double>(tmp - mean);
						adev += r8_loc.t; // potential overflow?
						r8_loc.t2 = (tmp - mean) * (tmp - mean);
						r8_loc.ct2 = r8_loc.t2;
						r8_loc.fracp = r8_loc.ct2 - static_cast<uint64_t>(r8_loc.ct2);
						if (r8_loc.fracp <= DEPS) std::printf("compute_stats: Losing a significant digits, result may not accurrate\n");
						r8_loc.var += r8_loc.t2; // potential overflow?
					}
				}
				adev /= r8_loc.len;
				if (r8_loc.var <= 0.0) {
					std::printf(" compute_stats: Invalid variance: %.15f\n", r8_loc.var);
					return (false);
				}
				r8_loc.var /= r8_loc.len;
				sdev = std::sqrt(r8_loc.var);
				r8_loc.isdev = 1.0 / sdev;
				r8_loc.fracp = -1.0;
				tmp = 0Ui64;
				for (size_t i = 0Ui64; i != m_timing_values.size(); ++i) {
					if (zero != m_timing_values.operator[](i)) {
						tmp = static_cast<double>(m_timing_values[i]);
						r8_loc.t3 = (tmp - mean) * r8_loc.isdev;
						r8_loc.ct2 = r8_loc.t3;
						r8_loc.fracp = r8_loc.t3 - static_cast<int64_t>(r8_loc.ct2);
						if (r8_loc.fracp <= DEPS) {
							std::printf(" compute_stats: Losing a significant digits, result may not accurrate\n");
						}
						// potential overflows?
						r8_loc.t4 = r8_loc.t3*r8_loc.t3*r8_loc.t3;
						skew += r8_loc.t4;
						r8_loc.t5 = r8_loc.t4 * r8_loc.t3;
						kurt += r8_loc.t5;
					}
				}
				skew /= r8_loc.len;
				kurt /= r8_loc.len - 3.0;
				if (kurt < 1.0) {
					std::printf(" compute_stats: Invalid kurtosis: %.15f\n", kurt);
					return (false);
				}
				return (true);
			}

			void print() const {

				std::cout << "   Dumping state of " << typeid(*this).raw_name() << "\n";
				std::cout << "=======================================================\n";
				std::cout << " Number of test runs:  " << m_nruns << "\n"
					      << " Data size:            " << m_datum_size << "\n"
						  << " Tested function name: " << m_func_name.data() << "\n"
						  << " Located in file name: " << m_file_name.data() << "\n";
				std::cout << "================= Printing data set =====================\n";
				
				for (size_t i = 0Ui64; i != m_nruns; ++i) {
					 std::cout << "Data validity :  Sample  :   TSC_AUX(start)  :   TSC_AUX(stop) \n";
					 for (size_t j = 0Ui64; i != m_datum_size; ++j) {
						 std::cout << std::setw(4) << m_nsuccess[Ix2D(i,m_datum_size,j)] <<
							 std::setw(8) << m_timing_values[Ix2D(i,m_datum_size,j)] <<
							 std::setw(12) << m_tscaux_start[Ix2D(i,m_datum_size,j)] <<
							 std::setw(16) << m_tscaux_stop[Ix2D(i, m_datum_size, j)] << "\n";
					 }
					 std::cout << "\n";
				}
				std::cout << "===============================================================\n";
			}
			
		};
	}
}



#endif /*__LAM_RDTSCP_TIMER_HPP__*/
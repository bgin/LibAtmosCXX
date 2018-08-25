
#ifndef __LAM_PERF_COLLECTORS_HPP__
#define __LAM_PERF_COLLECTORS_HPP__

#if !defined (LAM_PERF_COLLECTORS_MAJOR)
#define LAM_PERF_COLLECTORS_MAJOR 1
#endif

#if !defined (LAM_PERF_COLLECTORS_MINOR)
#define LAM_PERF_COLLECTORS_MINOR 0
#endif

#if !defined (LAM_PERF_COLLECTORS_MICRO)
#define LAM_PERF_COLLECTORS_MICRO 0
#endif

#if !defined (LAM_PERF_COLLECTORS_FULLVER)
#define LAM_PERF_COLLECTORS_FULLVER 1000
#endif

#if !defined (LAM_PERF_COLLECTORS_CREATE_DATE)
#define LAM_PERF_COLLECTORS_CREATE_DATE " 21-08-2018 16:51 +00200 (TUE 21 AUG 2018 GMT+2)"
#endif

#if !defined (LAM_PERF_COLLECTORS_BUILD_DATE)
#define LAM_PERF_COLLECTORS_BUILD_DATE " "
#endif

#if !defined (LAM_PERF_COLLECTORS_AUTHOR)
#define LAM_PERF_COLLECTORS_AUTHOR "Programmer: Bernard Gingold, contact: beniekg@gmail.com
#endif

#if !defined (LAM_PERF_COLLECTORS_DESCRIPT)
#define LAM_PERF_COLLECTORS_DESCRIPT " Code section performance collector class."
#endif

#include <vector>
#include <string>
#include <cstdint>
#include <iostream>
#include <iomanip>
#include "../Math/LAM_constants.h"
#include "../LAM_malloc.h"
#include "../LAM_config.h"

void rdft(int , int , double *, int *, double *);

namespace lam {
	namespace system {







		     struct PerfCollector {
				
				

				bool    m_Iscleared; // number of valid RDTSC measurements (stop - start)

				size_t m_nsamples;

				std::string m_funcname;  // function name

				std::string m_filename;  // file name

				std::string m_date;

				std::string m_time;

				std::vector<bool>    m_success; // this member describe successful computation of delta value (success == true, otherwise false)

				

				std::vector<uint64_t> m_start_values; // profiling samples  start  values

				std::vector<uint64_t> m_stop_values;  // profiling samples, stop values

				std::vector<uint64_t>  m_delta_values;  // measurement deltas

				std::vector<uint32_t> m_tscaux_start; // Output of TSC_AUX MSR (core mapping)

				std::vector<uint32_t> m_tscaux_stop; // Same as above (stop measurements)

				constexpr static size_t lo_bound = 3Ui64;

				constexpr static size_t lowest = 1Ui64;

				constexpr static size_t zero  = 0Ui64;

				PerfCollector() 
				:
				
				m_Iscleared{},
				m_nsamples{},
				m_funcname{},
				m_filename{},
				m_date{},
				m_time{},
				m_success(),
				
				m_start_values(),
				m_stop_values(),
				m_delta_values(),
				m_tscaux_start(),
				m_tscaux_stop()
				{}

				

				PerfCollector(_In_ const PerfCollector &x) noexcept(false)
					:
					
					m_Iscleared{},
					m_nsamples{ x.m_nsamples },
					m_funcname{ x.m_funcname },
					m_filename{ x.m_filename },
					m_date{ x.m_date },
					m_time{ x.m_time },
					m_success{x.m_success},
					
					m_start_values{ x.m_start_values },
					m_stop_values{ x.m_stop_values },
					m_tscaux_start{ x.m_tscaux_start },
					m_tscaux_stop{ x.m_tscaux_stop}
					
				{}

				PerfCollector(_In_ PerfCollector &&x) noexcept(true)
					:
					
					m_Iscleared{ std::move(x.m_Iscleared) },
					m_nsamples{ std::move(x.m_nsamples) },
					m_funcname{ std::move(x.m_funcname) },
					m_filename{ std::move(x.m_filename) },
					m_date{ std::move(x.m_date) },
					m_time{ std::move(x.m_time) },
					m_success{ std::move(x.m_success) },
				
					m_start_values{ std::move(x.m_start_values) },
					m_stop_values{ std::move(x.m_stop_values) },
					m_delta_values{ std::move(x.m_delta_values) },
					m_tscaux_start{ std::move(x.m_tscaux_stop) },
					m_tscaux_stop{ std::move(x.m_tscaux_stop) }

				{}

				~PerfCollector() noexcept(true) = default;

				PerfCollector & operator=(_In_ const PerfCollector &x) {
					if (this == &x) return (*this);
						 m_Iscleared = x.m_Iscleared;
					     m_nsamples  = x.m_nsamples;
					     m_funcname.operator=(x.m_funcname);
					     m_filename.operator=(x.m_filename);
					     m_date.operator=(x.m_date);
					     m_time.operator=(x.m_time);
					     m_success.operator=(x.m_success);
					     m_start_values.operator=(x.m_start_values);
					     m_stop_values.operator=(x.m_stop_values);
					     m_delta_values.operator=(x.m_delta_values);
					     m_tscaux_start.operator=(x.m_tscaux_start);
					     m_tscaux_stop.operator=(x.m_tscaux_stop);
					return (*this);
				}

				PerfCollector & operator=(_In_ PerfCollector &&x) {
					if (this == &x) return (*this);
					    m_Iscleared = std::move(x.m_Iscleared);
				     	m_nsamples = std::move(x.m_nsamples);
					    m_funcname.operator=(std::move(x.m_funcname));
					    m_filename.operator=(std::move(x.m_filename));
					    m_date.operator=(std::move(x.m_date));
					    m_time.operator=(std::move(x.m_time));
					    m_success.operator=(std::move(x.m_success));
					    m_start_values.operator=(std::move(x.m_start_values));
					    m_stop_values.operator=(std::move(x.m_stop_values));
					    m_delta_values.operator=(std::move(x.m_delta_values));
					    m_tscaux_start.operator=(std::move(x.m_tscaux_start));
					    m_tscaux_stop.operator=(std::move(x.m_tscaux_stop));
					return (*this);
				}

				
			

				void    start() noexcept(false) {
					int32_t dummy1[4] = {}, dummy2{};
					uint32_t tscaux{9999};
					__cpuid(&dummy1[0],dummy2);
					m_start_values.push_back(__rdtscp(&tscaux));
					m_tscaux_start.push_back(tscaux);

				}

				

				void stop() noexcept(false) {
					int32_t dummy1[4] = {}, dummy2{};
					uint32_t tscaux{9999};
					m_stop_values.push_back(__rdtscp(&tscaux));
					__cpuid(&dummy1[0],dummy2);
					m_tscaux_stop.push_back(tscaux);

				}

				void clear_all() {
					
					using namespace lam::math::constants;
					if (!m_Iscleared){
					    if (m_start_values.size() >= lowest) { // Upon throwing an exception (push_back) size() will not incremented
						    for (size_t i = 0ULL; i != m_start_values.size(); ++i) { // so different std::vector members has misaligned size.
							     m_start_values.operator[](i) = zero;
						     }
					     }
					    if (m_stop_values.size() >= lowest) {
						    for (size_t i = 0ULL; i != m_stop_values.size(); ++i) {
							    m_stop_values.operator[](i) = zero;
						    }
					    }
					    if (m_delta_values.size() >= lowest) {
						    for (size_t i = 0ULL; i != m_delta_values.size(); ++i) {
							     m_delta_values.operator[](i) = dinf;
						   }
					    }
					    if (m_tscaux_start.size() >= lowest) {
						    for (size_t i = 0ULL; i != m_tscaux_start.size(); ++i) {
							     m_tscaux_start.operator[](i) = 9999;
						     }
					     }
						if (m_tscaux_stop.size() >= lowest) {
							for (size_t i = 0ULL; i != m_tscaux_stop.size(); ++i) {
								m_tscaux_stop.operator[](i) = 9999;
							}
						}
						m_Iscleared = true;
					}
				}
					
				bool compute_delta() {

					if (check_data_size() == false) {
						return (false);
					}
					uint64_t res{};
					for (size_t i = 0ULL; i != m_start_values.size(); ++i) {
						if ((res = m_stop_values.operator[](i) - m_start_values.operator[](i)) > zero) {
							 m_delta_values.push_back(res);
							 m_success.push_back(true);
							 ++m_nsamples;
						}
						else {
							m_delta_values.push_back(zero);
							m_success.push_back(false);
						}
					}
					return (true);
				}

				bool compute_stats(_Inout_ double &mean,
								   _Inout_ double &adev,
					               _Inout_ double &sdev,
					               _Inout_ double &skew,
					               _Inout_ double &kurt){
								  
								
					using namespace lam::math::constants;
					if (m_Iscleared == true || m_delta_values.size() < lo_bound) {
						mean = dinf,adev = dinf,
						sdev = dinf,skew = dinf,
						kurt = dinf;
						return (false);
					}
				
					__declspec(align(64)) struct{
						double len{}, sum{}, var{}, t{}, t2{}, t3{}, tmp{},
						t4{}, t5{}, isdev{}, fracp{}, ct2{};
					} r8_loc;
					r8_loc.len = static_cast<double>(m_delta_values.size());
				
				
					//   Compute mean
					for (size_t i = 0ULL; i != m_delta_values.size(); ++i) {
						r8_loc.sum += static_cast<double>(m_delta_values[i]);
					}		
					mean = r8_loc.sum / r8_loc.len;
					//  Compute average deviation and variance
					for (size_t i = 0Ui64; i != m_delta_values.size(); ++i) {
						if (m_delta_values.operator[](i) != zero) {
							r8_loc.tmp = static_cast<double>(m_delta_values[i]);
							r8_loc.t = std::abs(r8_loc.tmp - mean);
							adev += r8_loc.t;
							r8_loc.t2 = (r8_loc.tmp - mean) * (r8_loc.tmp - mean);
							r8_loc.ct2 = r8_loc.t2; // Checks if catastrophic cancellation has occurred
							r8_loc.fracp = r8_loc.ct2 - static_cast<int64_t>(r8_loc.ct2); // Warning: not robust method. CADNA should be used
							if (r8_loc.fracp <= DEPS) {
								std::printf(" compute_stats: Losing a significant digits, result may not accurrate\n");
								
							}
							r8_loc.var += r8_loc.t2;
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
					r8_loc.tmp = 0.0;
					for (size_t i = 0Ui64; i != m_delta_values.size(); ++i) {
						if (m_delta_values.operator[](i) != zero) {
							r8_loc.tmp = static_cast<double>(m_delta_values[i]);
							r8_loc.t3 = (r8_loc.tmp - mean) * r8_loc.isdev;
							r8_loc.ct2 = r8_loc.t3;
							r8_loc.fracp = r8_loc.t3 - static_cast<int64_t>(r8_loc.ct2);
							if (r8_loc.fracp <= DEPS) {
								std::printf(" compute_stats: Losing a significant digits, result may not accurrate\n");
							}
							// Potential overflow?
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


				bool static correlation_set(_In_   PerfCollector &set1,
										    _In_   PerfCollector &set2,
										    _Out_  double * __restrict correlated_set,
										    _In_   int32_t * __restrict ip,
										    _In_   double * __restrict w,
										    _In_   const int32_t n) {
					if (set1.m_delta_values.size() != set2.m_delta_values.size() || 
					    static_cast<size_t>(n) != set1.m_delta_values.size() ) {
						return (false);
					}
					double t{}, invals{};
					int32_t snvals{};
					auto set_size = set1.m_delta_values.size();
					typedef double * __restrict __declspec(align_value(64)) aligned_ptr8;
					aligned_ptr8 dataset1 = lam::common::lam_edmalloca(set_size,align64B);
					aligned_ptr8 dataset2 = lam::common::lam_edmalloca(set_size, align64B);
					set1.cvrt_to_double(&dataset1[0], set_size);
					set2.cvrt_to_double(&dataset2[0], set_size);
					snvals = n << 1;
					invals = 1.0 / static_cast<double>(snvals);
					ip[0] = 0;
					rdft(n, 1, &dataset1[0], &ip[0], &w[0]);
					rdft(n, 1, &dataset2[0], &ip[0], &w[0]);
					for (int32_t i = 1; i != n - 1; i += 2) {
						t = dataset1[i];
						dataset1[i] = (dataset1[i] * dataset2[i] + dataset1[i + 1] * dataset2[i+1]) * invals;
						dataset1[i + 1] = (dataset1[i + 1] * dataset2[i] - t * dataset2[i+1]) * invals;
					}
					dataset1[0] = dataset1[0] * dataset2[0] * invals;
					dataset1[1] = dataset1[1] * dataset2[1] * invals;
					rdft(n, -1, &dataset1[0], &ip[0], &w[0]);
					memcpy(&correlated_set[0], &dataset1[0], set_size);
					if (dataset1) _mm_free(dataset1);

					if (dataset2) _mm_free(dataset2);
					return (true);
				}




				void print() const {

					std::cout << " Dumping state of: " << typeid(*this).raw_name() << "\n";
					std::cout << "======================================================================================\n";
					std::cout << " Reset state of collector: " << std::boolalpha << m_Iscleared << "\n" 
						<< "       Number of valid samples:  " << m_nsamples << "\n"
						<< "       Collected at function:    " << m_funcname.data() << "\n"
						<< "       Collected in file:        " << m_filename.data() << "\n"
						<< "       Collected at date:        " << m_date.data() << "\n"
						<< "       Collected at time:        " << m_time.data() << "\n"
						<< "       ======================================================================================\n";
					std::cout << " Invalid :   start  :    stop   :    delta    :   TSC_AUX(start)  :   TSC_AUX(stop) \n"
						      << " ========================================================================================\n";
					for (size_t i = 0Ui64; i != m_delta_values.size(); ++i) {
						std::cout << std::setw(4) << m_success[i] << std::setw(8) <<
							m_start_values[i] << std::setw(12) << m_stop_values[i] <<
							std::setw(16) << m_delta_values[i] << std::setw(18) << 
							m_tscaux_start[i] << std::setw(22) << m_tscaux_stop[i] << "\n";
					}
					std::cout << "========================================================================================\n";
					std::cout << "==============================  End of dump =============================================\n";
				}
				

				private: bool check_data_size() noexcept(true) {
								
							 if (m_Iscleared == false) {
								 if (m_start_values.size() == m_stop_values.size() &&
									 m_tscaux_start.size() == m_tscaux_stop.size()) {
									 return (true);
								 }
								 else {
									 return (false);
								 }
							 }
							 else return (false);
				}

				private:  bool cvrt_to_double(_Out_ double * __restrict data,
					                         size_t data_len) noexcept(true) {
							  if (m_delta_values.size() != data_len) return (false);
							  // Begin non vectorized conversion.
							  for (size_t i = 0Ui64; i != data_len; ++i) {
								  data[i] = static_cast<double>(m_delta_values[i]);
							  }
							  return (true);
				}

				
		};

		
	}
}


#endif /*__LAM_PERF_COLLECTORS_HPP_*/
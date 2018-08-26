
#include <iostream>
#include <iomanip>
#include <cstdint>
#include "LAM_gtc64_timer.h"
#include "../LAM_indices.h"
#include "../Math/LAM_constants.h"


lam::system
::GTC64Timer
::GTC64Timer(_In_ const std::size_t nruns,
			 _In_ const std::size_t datum_size,
			 _In_ const fptr tfunc,
			 _In_ const char * pfuname,
			 _In_ const char * pfilename)
:
m_nruns{ nruns },
m_datum_size{ datum_size },
m_tfunc{ tfunc },
m_func_name{ pfuname },
m_file_name{pfilename},
m_nsuccess(false,m_nruns * m_datum_size),
m_timing_values(0ULL, m_nruns * m_datum_size)
{}

lam::system
::GTC64Timer
::GTC64Timer(_In_ const GTC64Timer &x)
:
m_nruns{ x.m_nruns },
m_datum_size{ x.m_datum_size },
m_tfunc{ x.m_tfunc },
m_func_name{ x.m_func_name },
m_file_name{ x.m_file_name },
m_nsuccess{ x.m_nsuccess },
m_timing_values{ x.m_timing_values }
{}

lam::system
::GTC64Timer
::GTC64Timer(_In_ GTC64Timer &&x)
:
m_nruns{ std::move(x.m_nruns) },
m_datum_size{ std::move(x.m_datum_size )},
m_tfunc{ std::move(x.m_tfunc) },
m_func_name{ std::move(x.m_func_name) },
m_file_name{ std::move(x.m_file_name) },
m_nsuccess{ std::move(x.m_nsuccess) },
m_timing_values{ std::move(x.m_timing_values) }
{}

lam::system::GTC64Timer &
lam::system::GTC64Timer
::operator=(_In_ const GTC64Timer &x) {
	if (this == &x) return (*this);
	    m_nruns = x.m_nruns,
	    m_datum_size = x.m_datum_size,
	    m_tfunc.operator=( x.m_tfunc),
	    m_func_name.operator=(x.m_func_name),
	    m_file_name.operator=(x.m_file_name),
	    m_nsuccess.operator=(x.m_nsuccess),
	    m_timing_values.operator=(x.m_timing_values);
	return (*this);
}

lam::system::GTC64Timer &
lam::system::GTC64Timer
::operator=(_In_ GTC64Timer &&x) {
	if (this == &x) return (*this);
		m_nruns = std::move(x.m_nruns),
		m_datum_size = std::move(x.m_datum_size),
		m_tfunc.operator=(std::move(x.m_tfunc)),
		m_func_name.operator=(std::move(x.m_func_name)),
		m_file_name.operator=(std::move(x.m_file_name)),
		m_nsuccess.operator=(std::move(x.m_nsuccess)),
		m_timing_values.operator=(std::move(x.m_timing_values));
	return (*this);
}

void 
lam::system::GTC64Timer::run_benchmark() {

	volatile ULONGLONG START{}, STOP{};
	volatile int32_t warmup{}, val{1};
	constexpr int32_t niters = 1000;
	for (int32_t i = 0; i != niters; ++i) { // Small warm up loop
		warmup = val;
	}
	for (std::size_t i = 0Ui64; i != m_nruns; ++i) {
		for (std::size_t j = 0Ui64; j != m_datum_size; ++j) {

		   
			 START = ::GetTickCount64();
			 m_tfunc.operator()(); // Overhead of std::function<void(void)>::operator()
			 STOP = ::GetTickCount64();
			
			 if ((STOP - START) <= 0Ui64) {
				 std::printf("Fatal Error -- invalid timing read out at: i:%llu,j:%llu, START=%llu, STOP=%llu, DELTA=%llu\n",
					 i, j, START, STOP, (STOP-START));
				 m_timing_values.operator[](Ix2D(i,m_datum_size,j)) = 0Ui64;
				 m_nsuccess.operator[](Ix2D(i,m_datum_size,j)) = false;
			 }
			 else {
				 m_timing_values.operator[](Ix2D(i,m_datum_size,j)) = STOP - START;
				 m_nsuccess.operator[](Ix2D(i,m_datum_size,j)) = true;
			 }
		}
	}
}

bool
lam::system::GTC64Timer
::compute_stats(_Out_ double &mean,
				_Out_ double &adev,
				_Out_ double &sdev,
				_Out_ double &skew,
				_Out_ double &kurt) {

	using namespace lam::math::constants;
	if (m_timing_values.size() <= lo_bound) {
		mean = dinf, adev = dinf,
		sdev = dinf, skew = dinf,
		kurt = dinf;
		return (false);
	}
	ULONGLONG s{}, prev{};
	__declspec(align(64)) struct {
		double len{}, sum{}, var{}, t{},
		t2{}, t3{}, t4{}, t5{}, isdev{},
		fracp{}, ct2{}, tmp{};
	} r8_loc;
	r8_loc.len = static_cast<double>(m_timing_values.size());
	// Compute mean (guard against an overflow)
	for (size_t i = 0Ui64; i != m_timing_values.size(); ++i) {
		if (s < prev) return (false);
		prev = s;
		s += m_timing_values.operator[](i);
	}
	r8_loc.sum = static_cast<double>(s);
	mean = r8_loc.sum / r8_loc.len;
	//  Compute average deviation and variance
	for (size_t i = 0Ui64; i != m_timing_values.size(); ++i) {
		if (zero != m_timing_values[i]) {
			r8_loc.tmp = static_cast<double>(m_timing_values[i]);
			r8_loc.t = std::abs(r8_loc.tmp - mean);
			adev += r8_loc.t; //Potential overflow?
			r8_loc.t2 = (r8_loc.tmp - mean) * (r8_loc.tmp - mean);
			r8_loc.ct2 = r8_loc.t2;
			r8_loc.fracp = r8_loc.ct2 - static_cast<ULONGLONG>(r8_loc.ct2);
			if (r8_loc.fracp <= DEPS) {
			   std::printf(" GTC64Timer::compute_stats: Losing a significant digits: %.16f, result may not be an accurate\n", r8_loc.fracp);
			}
			r8_loc.var += r8_loc.t2; // potential overflow?
		}
	}
	adev /= r8_loc.len;
	if (r8_loc.var <= 0.0) {
		std::printf(" GTC64Timer::compute_stats: Invalid variance: %.15f\n", r8_loc.var);
		return (false);
	}
	r8_loc.var /= r8_loc.len;
	sdev = std::sqrt(r8_loc.var);
	r8_loc.isdev = 1.0 / sdev;
	r8_loc.fracp = -1.0;
	r8_loc.tmp = 0Ui64;
	for (size_t i = 0Ui64; i != m_timing_values.size(); ++i) {
		if (zero != m_timing_values.operator[](i)) {
			r8_loc.tmp = static_cast<double>(m_timing_values[i]);
			r8_loc.t3 = (r8_loc.tmp - mean) * r8_loc.isdev;
			r8_loc.ct2 = r8_loc.t3;
			r8_loc.fracp = r8_loc.t3 - static_cast<ULONGLONG>(r8_loc.ct2);
			if (r8_loc.fracp <= DEPS) {
				std::printf(" GTC64Timer::compute_stats: Losing a significant digits: %.16f, result may not be an accurrate\n", r8_loc.fracp);
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
		std::printf(" GTC64Timer::compute_stats: Invalid kurtosis: %.15f\n", kurt);
		return (false);
	}
	return (true);
}

void
lam::system::
GTC64Timer
::print() const {
	
	std::cout << "	Dumping state of  " << typeid(*this).raw_name() << "\n";
	std::cout << "============================================================\n";
	std::cout << " Number of test runs:   " << m_nruns << "\n"
		      << " Datum size per run:    " << m_datum_size << "\n"
			  << " Tested function name:  " << m_func_name.data() << "\n"
			  << " Located in file name:  " << m_file_name.data() << "\n";
	std::cout << "======================= Printing data set =========================\n";
	for (size_t i = 0Ui64; i != m_nruns; ++i) {
		std::cout << " Data validity   :     Sample value        \n";
		for (size_t j = 0Ui64; j != m_datum_size; ++j) {
		     	std::cout << std::setw(4) << m_nsuccess[Ix2D(i,m_datum_size,j)] <<
			              	 std::setw(8) << m_timing_values[Ix2D(i, m_datum_size, j)] << "\n";
		}
		std::cout << "\n";
	}
}
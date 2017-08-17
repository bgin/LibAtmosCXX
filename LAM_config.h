
#ifndef __LAM_CONFIG_H__
#define __LAM_CONFIG_H__

#if !defined(LAM_CONFIG_MAJOR)
#define LAM_CONFIG_MAJOR 1
#endif

#if !defined(LAM_CONFIG_MINOR)
#define LAM_CONFIG_MINOR 0
#endif

#if !defined(LAM_CONFIG_MICRO)
#define LAM_CONFIG_MICRO 0
#endif

#if !defined(LAM_CONFIG_FULLVER)
#define LAM_CONFIG_FULLVER 1000
#endif

#if !defined(LAM_CONFIG_CREATE_DATE)
#define LAM_CONFIG_CREATE_DATE "17-08-2017 10:03 +00200 (THR 17 AUG 2017 GMT+2)"
#endif
/*
Set this value to latest build date/time
*/
#if !defined(LAM_CONFIG_BUILD_DATE)
#define LAM_CONFIG_BUILD_DATE " "
#endif

#if !defined(LAM_CONFIG_AUTHOR)
#define LAM_CONFIG_AUTHOR  "Programmer: Bernard Gingold, e-mail: beniekg@gmail.com"
#endif

#if !defined(LAM_CONFIG_DESCRIPT)
#define LAM_CONFIG_DESCRIPT "LAM configuration global settings."
#endif



/* Start of Compiler specific declarations.* /

/* Compiler supported CPP version
as reported by reading __cplusplus macro def.*/
#if defined (__cplusplus)
#define LAM_CXX_98 199711L
#define LAM_CXX_11 201103L
#define LAM_CXX_14 201420L
#endif

/* Deteremine current version supported by ICC.*/
#if defined (__cplusplus) && !defined (__INTEL_CXX11_MODE__)
#if LAM_CXX_98 < LAM_CXX_11
#define LAM_DEFAULT_CXX_VERSION 199711L
#else
#define LAM_DEFAULT_CXX_VERSION 201103L
#endif
#endif

// Is Intel Compiler choosen as default
// library compiler?

#if defined __INTEL_COMPILER
#define LAM_COMPILED_BY_ICC 1
#else
#define LAM_COMPILED_BY_ICC 0
#define LAM_COMPILED_BY_MSVC 1
#endif

/* Is 64bit mode current? */

#if (defined (_M_AMD64) || defined (_M_X64_) || defined (__amd64) ) \
	&& !defined (__x86_64__)
#define __x86_64__ 1
#endif

/* Determine architectural support for full set
of GP registers*/
#if __x86_64__ == 1
#define LAM_HAS_FULL_GPR_SET 16
#elif __x86_64__ == 0
#define LAM_HAS_FULL_GPR_SET 8
#else
#error "COMPILE_TIME_ERROR: Cannot determine 32bit or 64bit mode!"
#endif

/* Determine architectural support for full set
of SIMD registers*/
#if __x86_64__ == 1
#define LAM_HAS_FULL_SIMD_REGSET 32
#elif __x86_64__ == 0
#define LAM_HAS_FULL_SIMD_REGSET 16
#else
#error "COMPILE_TIME_ERROR: Cannot determine 32bit or 64bit mode!"
#endif

/*
Compiler optimization settings.
*/
#if defined LAM_COMPILED_BY_ICC
#define LAM_NO_OPTIMIZATION 0
#define LAM_OPTIMIZATION_O1 1
#define LAM_OPTIMIZATION_O2 2
#define LAM_OPTIMIZATION_O3 3
#endif

/*
   CPU user-friemdly name:
*/
#if !defined (MACHINE_CPU_NAME)
#define MACHINE_CPU_NAME "Intel Core i7 4770 HQ"
#endif

/*
Using OpenMP.
*/
#if !defined(USE_OPENMP)
#define USE_OPENMP 1
#endif

#if USE_OPENMP == 1 && defined (LAM_COMPILED_BY_ICC)
#include <omp.h>
#elif defined (LAM_COMPILED_BY_MSVC)
#include <omp.h>
#else
#error "COMPILE_TIME_ERROR: Unsupported Compiler version!"
#endif

#if USE_OPENMP == 1 && __INTEL_COMPILER >= 1500
#define OMP_VER 40
#elif __INTEL_COMPILER < 1500
#define OMP_VER 10
#else
#error "COMPILE_TIME_ERROR: Unsupported Compiler version!"
#endif

/*
Intel MKL support.
Include all headers - master header file.
*/
#if !defined(USE_MKL)
#define USE_MKL 1
#endif

#if USE_MKL == 1 && defined (LAM_COMPILED_BY_ICC)
#include <mkl.h>
#else
#error "COMPILE_TIME_ERROR: Cannot include MKL: headers!"
#endif

// Debug mode.
#if defined (_DEBUG)
#define LAM_DEBUG_ON 1
#endif

/*
Compiler software prefetching.
*/
#if LAM_COMPILED_BY_ICC == 1
#define ICC_PREFETCH_L1 1
#define ICC_PREFETCH_L2 2
#define ICC_PREFETCH_L3 3
#define ICC_PREFETCH_NTA 4
#endif

#if defined (ICC_PREFETCH_L1)
constexpr unsigned int L1_PREF_SHORT{ 4 };
constexpr unsigned int L2_PREF_LONG{ 8 };
#endif

// Highly CPU dependend
#if defined MACHINE_CPU_NAME  // Later should be encoded as ASCII integral type
#if defined (ICC_PREFETCH_L1)
constexpr unsigned int L1_MAX_FLOATS{ 8000 };
constexpr unsigned int L1_MAX_DOUBLES{ 4000 };
#endif
// Highly CPU dependend
#if defined ICC_PREFETCH_L2
constexpr unsigned int L2_MAX_FLOATS{ 8 * L1_MAX_FLOATS };
constexpr unsigned int L2_MAX_DOUBLES{ 8 * L1_MAX_DOUBLES };
#endif
// Highly CPU dependend
#if defined ICC_PREFETCH_L3
constexpr unsigned int L3_MAX_FLOATS{ 1572864 };
constexpr unsigned int L3_MAX_DOUBLES{786432};
#endif
#else
#error "COMPILE_TIME_ERROR: Please define your CPU type!!"
#endif
/*
	Performance measurement
*/
#if !defined(PRECISE_PERF_TIMING)
#define PRECISE_PERF_TIMING 1
#endif

#if PRECISE_PERF_TIMING == 0
#define CRUDE_PERF_TIMING 1
#endif

#if !defined (LAM_MANUAL_UNROLL)
#define LAM_MANUAL_UNROLL  1
#endif

#if LAM_MANUAL_UNROLL == 1
#define UNROLL_2X 2
#define UNROLL_4X 4
#define UNROLL_8X 8
#if __x86_64__ == 1
#define UNROLL_16X 16
#define UNROLL_32X 32
#endif
#endif

#if LAM_COMPILED_BY_ICC == 1
#ifndef _MM_MALLOC_ALIGNED_
#define _MM_MALLOC_ALIGNED_ 1
#endif
#endif

#if _MM_MALLOC_ALIGNED_ == 1
constexpr int align16B{ 16 };
constexpr int align32B{ 32 };
#endif


/* Fixing problem of defined in WinDef macros:
1) min.
2) max.
*/

#if defined _MSC_VER
#if defined (_WINDEF_) && defined (min) && defined (max)
#undef min
#undef max
#endif
#if !defined NOMINMAX
#define NOMINMAX
#endif
#endif



#endif /*_LAM_CONFIG_H__*/
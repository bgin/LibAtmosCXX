
#ifndef __LAM_SIMD_DEFS_H__
#define __LAM_SIMD_DEFS_H__

#if !defined (LAM_SIMD_DEFS_MAJOR)
#define LAM_SIMD_DEFS_MAJOR 1
#endif

#if !defined (LAM_SIMD_DEFS_MINOR)
#define LAM_SIMD_DEFS_MINOR 0
#endif

#if !defined (LAM_SIMD_DEFS_MICRO)
#define LAM_SIMD_DEFS_MICRO 0
#endif

#if !defined (LAM_SIMD_DEFS_FULLVER)
#define LAM_SIMD_DEFS_FULLVER 1000
#endif

#if !defined (LAM_SIMD_DEFS_CREATE_DATE)
#define LAM_SIMD_DEFS_CREATE_DATE "17-08-2017 11:44 +00200 (THR 17 AUG 2017 GMT+2)"
#endif
/*
Set this value to latest build date/time
*/
#if !defined (LAM_SIMD_DEFS_BUILD_DATE)
#define LAM_SIMD_DEFS_BUILD_DATE " "
#endif

#if !defined (LAM_SIMD_DEFS_AUTHOR)
#define LAM_SIMD_DEFS_AUTHOR "Programmer: Bernard Gingold, e-mail: beniekg@gmail.com"
#endif

#if !defined (LAM_SIMD_DEFS_DESCRIPT)
#define LAM_SIMD_DEFS_DESCRIPT "SIMD definitions header file."
#endif

/* Determine SIMD architecture ISA set
and its corresponding intrinsic sets.
*/

#if !defined SIMDISA
#if defined (__AVX512__) || defined (__AVX512CD__) || defined (__AVX512DQ__) \
	|| defined (__AVX512ER__) || defined (__AVX512F__) || defined (__AVXPF__)
#defined SIMDISA 9
#elif defined (__AVX2__)
#define SIMDISA 8
#elif defined (__AVX__)
#define SIMDISA 7
#elif defined (__SSE4_2__)
#define SIMDISA 6
#elif defined (__SSE4__)
#define SIMDISA 5
#elif defined (__SSSE3__)
#define SIMDISA 4
#elif defined (__SSE3__)
define SIMDISA 3
#elif defined (__SSE2__)
#define SIMDISA 2
#elif defined (__SSE__)
#define SIMDISA 1
#elif defined (_M_IX86_FP)
#define SIMDISA _M_IX86_FP
#else
#define SIMDISA 0
#endif
#endif

#if defined __INTEL_COMPILER
#if SIMDISA > 8
#include <zmmintrin.h>
#elif SIMDISA == 8
#include <immintrin.h>
#elif SIMDISA == 7
#include <immintrin.h>
#elif SIMDISA == 6
#include <nmmintrin.h>
#elif SIMDISA == 5
#include <smmintrin.h>
#elif SIMDISA == 4
#include <tmmintrin.h>
#elif SIMDISA == 3
#include <emmintrin.h>
#elif SIMDISA == 2
#include <xmmintrin.h>
#elif defined _MSC_VER
#include <intrin.h>
#else
#error "Unsuported compiler detected."
#endif
#endif


#endif /*__LAM_SIMD_DEFS_H__*/

#ifndef __LAM_AVXBITSETS_H__
#define __LAM_AVXBITSETS_H__

#if !defined (LAM_AVXBITSETS_MAJOR)
#define LAM_AVXBITSETS_MAJOR 1
#endif

#if !defined (LAM_AVXBITSETS_MINOR)
#define LAM_AVXBITSETS_MINOR 0
#endif

#if !defined (LAM_AVXBITSETS_MICRO)
#define LAM_AVXBITSETS_MICRO 0
#endif

#if !defined (LAM_AVXBITSETS_FULLVER)
#define LAM_AVXBITSETS_FULLVER 1000
#endif

#if !defined (LAM_AVXBITSETS_CREATE_DATE)
#define LAM_AVXBITSETS_CREATE_DATE "13-10-2017 11:00 +00200 (FRI 13 OCT 2017 GMT+2)"
#endif

//
// Set this value after succesful compilation.
//
#if !defined (LAM_AVXBITSETS_BUILD_DATE)
#define LAM_AVXBITSETS_BUILD_DATE " "
#endif

#if !defined (LAM_AVXBITSETS_AUTHOR)
#define LAM_AVXBITSETS_AUTHOR "Programmer: Bernard Gingold (adapted from Joerg Arndt 'FXT' Library), e-mail: beniekg@gmail.com"
#endif

#if !defined (LAM_AVXBITSETS_DESCRIPT)
#define LAM_AVXBITSETS_DESCRIPT "AVX version of FXT Library bit twiddling algorithms."
#endif

/*
	Original author copyright notice:
	// This file is part of the FXT library.
	// Copyright (C) 2010, 2012 Joerg Arndt
	// License: GNU General Public License version 3 or later,
	// see the file COPYING.txt in the main directory.

	Bernard Gingold copyright notice:
	This file is a part of LibAtmosModelCPP library
	Copyright (C) 2017 Bernard Gingold
	License: GNU General Public Locense version 3 or later,
	for additional information check file LICENSE.txt in 
	project directory.
*/

#include "../LAM_simd_defs.h"
#include <cstdint>
#include <bitset>
#include <iostream>


namespace lam{
	namespace math {
	   namespace {

		static const __m256i ZERO = _mm256_set1_epi64x(0ULL);

		static const __m256i ONE = _mm256_set1_epi64x(1ULL);

		static const __m256i TWO = _mm256_set1_epi64x(2ULL);

		static const __m256i THREE = _mm256_set1_epi64x(3ULL);

		static const __m256i MASK = _mm256_set1_epi64x(0xFFFFFFFFFFFFFFFF);

		static const __m256i MASK_CNT2BITS = _mm256_set1_epi32(0x55555555UL);

		static const __m256i MASK_CNT4BITS = _mm256_set1_epi32(0x33333333UL);

		static const __m256i MASK_CNT8BITS = _mm256_set1_epi32(0x0f0f0f0fUL);

		static const __m256i MASK_SHL16 = _mm256_set1_epi64x(0x0000ffff0000ffffUL);

		static const __m256i MASK_SHL8 = _mm256_set1_epi64x(0x00ff00ff00ff00ffUL);

		static const __m256i MASK_SHL4 = _mm256_set1_epi64x(0x0f0f0f0f0f0f0f0fUL);

		static const __m256i MASK_SHL2 = _mm256_set1_epi64x(0x3333333333333333UL);

		static const __m256i MASK_SHL1 = _mm256_set1_epi64x(0x5555555555555555UL);

		static const __m256i MASK_RADIX4 = _m256_set1_epi64x(0xccccccccccccccccUL);

		static const __m256i MASK_ALTONES = _mm256_set1_epi32(0x01010101UL);

		static const __m256i MASK_ONES = _mm256_set1_epi32(0x11111111);

		static const __m256i BITS_PER_LONG_64 = _mm256_set1_epi32(64);
	}

		class SIMD_BitSets {

			public:

			// Helpers
			static inline __m256i simd_unary_minus(_In_ const __m256i &x) {
				return (_mm256_sub_epi64(ZERO,x));
			   }

			static inline __m256i simd_dec(_In_ const __m256i &x) {
				return (_mm256_sub_epi64(x,ONE));
			}

			static inline __m256i simd_inc(_In_ const __m256i &x) {
				return (_mm256_add_epi64(x,ONE));
			}

			static inline __m256i simd_not(_In_ const __m256i &x) {
				return (_mm256_xor_si256(x,MASK));
			}

			// 4 uint64_t scalars
			static void bitset64_print(_In_ const __m256i &x) {
				constexpr uint32_t nelems{4U};
				std::bitset<64Ui64> barray[nelems] = {};
				for (uint32_t i = 0U; i != nelems; ++i)
					barray[i] = std::bitset<64Ui64>{static_cast<uint64_t>(_mm256_extract_epi64(x,i))};
				std::cout << " 64-bit X  component: " << barray[0] << "\n"
						  << " 64-bit Y  component: " << barray[1] << "\n"
						  << " 64-bit Z  component: " << barray[2] << "\n"
						  << " 64-bit W  component: " << barray[3] << "\n";
			}
			
			// 8 uint32_t scalars
			static void bitset32_print(_In_ const __m256i &x) {
				constexpr uint32_t nelems{8U};
				std::bitset<32U> barray[nelems] = {};
				for (uint32_t i = 0U; i != nelems; ++i) 
					barray[i] = std::bitset<32U>{static_cast<uint32_t>(_mm256_extract_epi32(x,i))};
				std::cout << " 32-bit x0...x7 components \n";
				for (uint32_t i = 0U; i != nelems; ++i)
					std::cout << "{" << barray[i] << "}" << "\n";
			}
			
		   // End of Helpers

			 static	inline __m256i simd_average(_In_ const __m256i &x,
										        _In_ const __m256i &y) {
					__m256i ymm0,ymm1;
					ymm0 = _mm256_and_si256(x,y);
					ymm1 = _mm256_srli_epi64(_mm256_xor_si256(x,y),1);
					return (_mm256_add_epi64(ymm0,ymm1));
				}	

			 static inline __m256i simd_ceil_average(_In_ const __m256i &x,
												     _In_ const __m256i &y) {
					__m256i ymm0,ymm1;
					ymm0 = _mm256_or_si256(x,y);
					ymm1 = _mm256_srli_epi64(_mm256_xor_si256(x,y),1);
					return (_mm256_sub_epi64(ymm0,ymm1));
			 }

			 static inline void simd_bin2naf(_In_ const __m256i &x,
											 _In_       __m256i &np,
											 _In_       __m256i &nm) {
				//// Compute (nonadjacent form, NAF) signed binary representation of x:
				// the unique representation of x as
				//   x=\sum_{k}{d_k*2^k} where d_j \in {-1,0,+1}
				//   and no two adjacent digits d_j, d_{j+1} are both nonzero.
				// np has bits j set where d_j==+1
				// nm has bits j set where d_j==-1
				// We have:  x = np - nm

					__m256i ymm0,ymm1,ymm2;
					ymm0 = _mm256_srli_epi64(x,1);
					ymm1 = _mm256_add_epi64(x,ymm0);
					ymm2 = _mm256_xor_si256(ymm0,ymm1);
					np = _mm256_and_si256(ymm1,ymm2);
					nm = _mm256_and_si256(ymm0,ymm2);
			 }

			 static inline __m256i simd_naf2bin(_In_ const __m256i &np,
											    _In_ const __m256i &nm) {
				 // Inverse of bin2naf()
				 // Works also for signed-binary pairs np, nm
				 // that are not nonadjacent forms.
				 return (_mm256_sub_epi64(np,nm));
			 }

			 static inline void simd_bin2sbin(_In_ const __m256i &x,
											  _Inout_    __m256i &np,
											  _Inout_	 __m256i &nm) {
				 // Compute a signed binary representation of x:
				 // a representation of x as
				 //   x=\sum_{k}{d_k*2^k} where d_j \in {-1,0,+1}
				 // Inverse function is simd_naf2bin().
				 __m256i ymm0,ymm1;
				 ymm0 = _mm256_srli_epi64(x,1);
				 ymm1 = _mm256_xor_si256(x,ymm0);
				 np = _mm256_and_si256(ymm1,ymm0);
				 nm = _mm256_and_si256(ymm1,x);
			 }

			 static inline __m256i simd_bin_to_sl_gray(_In_  __m256i &k,
													   _In_  __m256i &ldn){
				 // Unranking for binary SL-Gray:
				 // Convert binary number to corresponding word in SL-Gray order.
				 // Successive transitions are adjacent (one-close) or three-close.
				 // See Joerg Arndt, Subset-lex: did we miss an order?, (2014)
				 //   http://arxiv.org/abs/1405.6503
				 
				 if (_mm256_testz_si256(ldn, ZERO))
					 return (ZERO);
				 
				 __m256i ymm0 = _mm256_slli_epi64(_mm256_sub_epi64(ldn, ONE),1); // b
				 __m256i ymm1 = _mm256_sub_epi64(_mm256_slli_epi64(ymm0, 1), ONE); // m
				 __m256i ymm3 = ymm0; // z
				 k = _mm256_sub_epi64(k, ONE);
				 while (!(_mm256_testz_si256(ymm0,ZERO))) {
					 const __m256i ymm4 = _mm256_and_si256(ymm0,k); // h
					 ymm3 = _mm256_xor_si256(ymm3,ymm4);
					 if (_mm256_testz_si256(ymm4,ZERO))
						 k = _mm256_xor_si256(k,ymm1);
					 k = _mm256_add_epi64(k,ONE);
					 ymm0 = _mm256_srli_epi64(ymm0,1);
					 ymm1 = _mm256_srli_epi64(ymm1,1);
				 }
				 return (ymm3);
			 }
			
			 static inline __m256i simd_sl_gray_to_bin(_In_ __m256i &k,
												       _In_ __m256i &ldn) {
				 // Ranking for binary SL-Gray:
				 // Convert binary word in SL-Gray order to binary number.
				 // See Joerg Arndt, Subset-lex: did we miss an order?, (2014)
				 //   http://arxiv.org/abs/1405.6503
				 if (_mm256_testz_si256(k,ZERO))
					 return (_mm256_set1_epi64x(0ULL));
				 __m256i ymm0 = _mm256_slli_epi64(_mm256_sub_epi64(ldn,ONE),1); //b
				 __m256i ymm1 = _mm256_and_si256(k,ymm0); // h
				 k = _mm256_xor_si256(k,ymm1);
				 __m256i ymm2 = simd_sl_gray_to_bin(k, _mm256_sub_epi64(ldn,ONE)); //z
				 if (_mm256_testz_si256(ymm1,ZERO))
					 return (_mm256_sub_epi64(_mm256_slli_epi64(ymm0,1),ymm2));
				 else
					 return (_mm256_add_epi64(ONE,ymm2));
			 }

			 static inline __m256i simd_inv2adic(_In_ const __m256i &x) {
			     // WARNING this function works with unsigned int i.e
				 // 32bit size.
				 // Return inverse modulo 2**BITS_PER_LONG
				 // x must be odd
				 // The number of correct bits is doubled with each step
				 // ==> loop is executed prop. log_2(BITS_PER_LONG) times
				 // precision is 3, 6, 12, 24, 48, 96, ... bits (or better)
				 if (_mm256_testz_si256(ZERO, _mm256_and_si256(x,ONE))) 
					 return (_mm256_set1_epi32(0ULL));
				 __m256i ymm0 = x; //i
				 __m256i ymm1; // p
				 do {

					 ymm1 = _mm256_mul_epu32(ymm0,x);
					 ymm0 = _mm256_mul_epu32(ymm0, _mm256_sub_epi32(_mm256_set1_epi32(2),ymm1));
				 }
				 while (_mm256_cmpneq_epu32_mask(ymm1,ONE));
				 return (ymm0);
			 }

			 static inline __m256i simd_invsqrt2adic(_In_ const __m256i &d) {
				 // WARNING this function works with unsigned int i.e
				 // 32bit size.
				 // Return inverse square root modulo 2**BITS_PER_LONG
				 // Must have:  d==1 mod 8
				 // The number of correct bits is doubled with each step
				 // ==> loop is executed prop. log_2(BITS_PER_LONG) times
				 // precision is 4, 8, 16, 32, 64, ... bits (or better)
				 if (_mm256_cmpneq_epu32_mask(ONE, 
				           _mm256_add_epi32(d, _mm256_set1_epi32(7))))
					 return (_mm256_set1_epi32(0));
				 __m256i ymm0 = _mm256_or_si256(_mm256_srli_epi32(d,1),ONE); //x
				 __m256i ymm1,ymm2; // p,y
				 do {

					ymm2 = ymm0;
					__m256i t = _mm256_mul_epu32(d, _mm256_mul_epu32(ymm2,ymm2));
					ymm1 = _mm256_sub_epi32(_mm256_set1_epi32(3),t);
					ymm0 = _mm256_srli_epi32(_mm256_mul_epu32(ymm2,ymm1),1);
				 }
				 while (_mm256_cmpneq_epu32_mask(ymm0,ymm2));
				 return (ymm0);
			 }

			 static inline __m256i simd_sqrt2adic(_In_  __m256i &d) {
				 // Return square root modulo 2**BITS_PER_LONG
				 // Must have: d==1 mod 8  or  d==4 mod 32,  d==16 mod 128
				 //   ... d==4**k mod 4**(k+3)
				 // Result undefined if condition does not hold
				 if (_mm256_testz_si256(ZERO,d))
					 return (_mm256_set1_epi32(0));
				 __m256i ymm0 = _mm256_set1_epi32(0);
				 while (_mm256_testz_si256(ZERO, 
				              _mm256_and_si256(d, ONE))) {
					 d = _mm256_srli_epi32(d,1);
					 ymm0 = _mm256_add_epi32(ymm0,ONE);
				 }
				 d = _mm256_mul_epi32(d, simd_invsqrt2adic(d));
				 __m256i t = _mm256_srli_epi32(ymm0,1);
				 d = _mm256_sllv_epi32(d,t);
				 return (d);
			 }

			 static inline __m256i simd_butterfly_16(_In_ __m256i &x) {
				 // Swap the two central blocks of 16 bits.
				 const __m256i m = _mm256_set1_epi64x(0x0000ffffffff0000UL);
				 __m256i ymm0 = _mm256_and_si256(x,m); //c
				 ymm0 = _mm256_xor_si256(_mm256_slli_epi64(ymm0, 16), 
				                         _mm256_srli_epi64(ymm0,16));
				 ymm0 = _mm256_and_si256(ymm0,m);
				 return (_mm256_xor_si256(x,ymm0));
			}
			 
			 static inline __m256i simd_butterfly_8(_In_ __m256i &x) {
				 // Swap in each block of 32 bits the two central blocks of 8 bits.
				 const __m256i ymm0 = _mm256_set1_epi64x(0x00ff000000ff0000UL); //ml
				 const __m256i ymm1 = _mm256_set1_epi64x(8UL); // s
				 const __m256i ymm2 = _mm256_sllv_epi64(ymm0,ymm1); // mr
				 __m256i t1 = _mm256_srlv_epi64(_mm256_and_si256(x,ymm0),ymm1);
				 __m256i t2 = _mm256_sllv_epi64(_mm256_and_si256(x,ymm2),ymm1);
				 const __m256i ymm3 = _mm256_or_si256(t1,t2); // t
				 __m256i t3 = _mm256_or_si256(ymm0,ymm2);
				 t3 = _mm256_xor_si256(t3,MASK);
				 x = _mm256_or_si256(_mm256_and_si256(x,t3),ymm3);
				 return (x);
			 }

			 static inline __m256i simd_butterfly_4(_In_ __m256i &x) {
				 // Swap in each block of 16 bits the two central blocks of 4 bits.
				 const __m256i ymm0 = _mm256_set1_epi64x(0x0f000f000f000f00); //ml
				 const __m256i ymm1 = _mm256_set1_epi64x(4UL); // s
				 const __m256i ymm2 = _mm256_sllv_epi64(ymm0, ymm1); // mr
				 __m256i t1 = _mm256_srlv_epi64(_mm256_and_si256(x, ymm0), ymm1);
				 __m256i t2 = _mm256_sllv_epi64(_mm256_and_si256(x, ymm2), ymm1);
				 const __m256i ymm3 = _mm256_or_si256(t1, t2); // t
				 __m256i t3 = _mm256_or_si256(ymm0, ymm2);
				 t3 = _mm256_xor_si256(t3, MASK);
				 x = _mm256_or_si256(_mm256_and_si256(x, t3), ymm3);
				 return (x);
			 }

			 static inline __m256i simd_butterfly_2(_In_ __m256i &x) {
				 // Swap in each block of 8 bits the two central blocks of 2 bits.
				 const __m256i ymm0 = _mm256_set1_epi64x(0x3030303030303030); //ml
				 const __m256i ymm1 = _mm256_set1_epi64x(2UL); // s
				 const __m256i ymm2 = _mm256_sllv_epi64(ymm0, ymm1); // mr
				 __m256i t1 = _mm256_srlv_epi64(_mm256_and_si256(x, ymm0), ymm1);
				 __m256i t2 = _mm256_sllv_epi64(_mm256_and_si256(x, ymm2), ymm1);
				 const __m256i ymm3 = _mm256_or_si256(t1, t2); // t
				 __m256i t3 = _mm256_or_si256(ymm0, ymm2);
				 t3 = _mm256_xor_si256(t3, MASK);
				 x = _mm256_or_si256(_mm256_and_si256(x, t3), ymm3);
				 return (x);
			 }

			 static inline __m256i simd_butterfly_1(_In_ __m256i &x) {
				 // Swap in each block of 4 bits the two central bits.
				 const __m256i ymm0 = _mm256_set1_epi64x(0x4444444444444444); //ml
				 const __m256i ymm1 = _mm256_set1_epi64x(1UL); // s
				 const __m256i ymm2 = _mm256_sllv_epi64(ymm0, ymm1); // mr
				 __m256i t1 = _mm256_srlv_epi64(_mm256_and_si256(x, ymm0), ymm1);
				 __m256i t2 = _mm256_sllv_epi64(_mm256_and_si256(x, ymm2), ymm1);
				 const __m256i ymm3 = _mm256_or_si256(t1, t2); // t
				 __m256i t3 = _mm256_or_si256(ymm0, ymm2);
				 t3 = _mm256_xor_si256(t3, MASK);
				 x = _mm256_or_si256(_mm256_and_si256(x, t3), ymm3);
				 return (x);
			 }

			 static inline __m256i simd_first_comb(_In_ const __m256i &k) {
				 // Return the first combination of (i.e. smallest word with) k bits,
				 // i.e.  00..001111..1 (k low bits set)
				 // Must have:  0 <= k <= BITS_PER_LONG
				 if (_mm256_testz_si256(k,ZERO))
					 return (_mm256_set1_epi64x(0ULL));
				 __m256i ymm0 = _mm256_set1_epi64x(0ULL);
				 ymm0 = _mm256_xor_si256(ymm0,MASK);
				 return (_mm256_srlv_epi64(ymm0, 
							 _mm256_sub_epi64(BITS_PER_LONG_64,k)));
			 }

			 static inline __m256i simd_last_comb(_In_ const __m256i &k) {
				 // Return the last combination of (biggest n-bit word with) k bits
				 // i.e.  1111..100..00 (k high bits set)
				 // Must have:  0 <= k <= n <= BITS_PER_LONG
				 return (_mm256_sllv_epi64(simd_first_comb(k), 
									_mm256_sub_epi64(BITS_PER_LONG_64,k)));
			 }

			 static inline __m256i simd_next_colex_comb(_In_ __m256i &x) {
				 // Return smallest integer greater than x with the same number of bits set.
				 //
				 // colex order (5 over 3):
				 //   set        word    set reversed (sorted!)
				 //  0  1  2    ..111    2  1  0
				 //  0  1  3    .1.11    3  1  0
				 //  0  2  3    .11.1    3  2  0
				 //  1  2  3    .111.    3  2  1
				 //  0  1  4    1..11    4  1  0
				 //  0  2  4    1.1.1    4  2  0
				 //  1  2  4    1.11.    4  2  1
				 //  0  3  4    11..1    4  3  0
				 //  1  3  4    11.1.    4  3  1
				 //  2  3  4    111..    4  3  2
				 //
				 //  Examples:
				 //    000001 -> 000010 -> 000100 -> 001000 -> 010000 -> 100000
				 //    000011 -> 000101 -> 000110 -> 001001 -> 001010 -> 001100 -> 010001 -> ...
				 //    000111 -> 001011 -> 001101 -> 001110 -> 010011 -> 010101 -> 010110 -> ...
				 //
				 //  Special cases:
				 //    0 -> 0
				 //    all bits on the high side (i.e. last combination) -> 0
				 //.
				 // based on code by Doug Moore / Glenn Rhoads
				 // note: might want to use bitscan near end
				
				 __m256i ymm0 = _mm256_and_si256(x, simd_unary_minus(x)); //r , lowest set bit
				 x = _mm256_add_epi64(x,ymm0); //replace lowest block by a one left to it
				 if (_mm256_testz_si256(ZERO,x))
					 return (_mm256_set1_epi64x(0ULL));
				 __m256i ymm1 = _mm256_and_si256(x, simd_unary_minus(x)); // z first zero beyond lowest block
				 ymm1 = _mm256_sub_epi64(ymm1,ymm0); // lowest block  (cf. lowest_block())
				 while (_mm256_testz_si256(ZERO,
					   _mm256_and_si256(ymm1, ONE))) {
					 ymm1 = _mm256_srli_epi64(ymm1,1);
				 }
				 return (_mm256_or_si256(x,_mm256_srli_epi64(ymm1,1)));
			 }

			 static inline __m256i simd_prev_colex_comb(_In_ __m256i &x) {
				 // Inverse of simd_next_colex_comb()
#if 1
				 x = simd_next_colex_comb(simd_unary_minus(x));
				 if(!_mm256_testz_si256(ZERO,x)) {
					 x = simd_unary_minus(x);
					 return (x);
				 }
#else
				 if(_mm256_testz_si256(ZERO,
								_mm256_and_si256(x,ONE))) {
					 __m256i ymm0 = _mm256_and_si256(x, simd_unary_minus(x)); //b
					 x = _mm256_sub_epi64(x,_mm256_srli_epi64(ymm0,1));
				 }
				 else {
					 __m256i ymm1 = simd_unary_minus(x); // k
					 ymm1 = _mm256_and_si256(ymm1,simd_unary_minus(ymm1)); // low block set of bits
					 ymm1 = simd_dec(ymm1); 
					 x = _mm256_xor_si256(x,ymm1); // remove low block
					 if(_mm256_testz_si256(ZERO,x)) // last combination (i.e. first in colex order)
						 return (_mm256_set1_epi64x(0ULL));
					 __m256i ymm2 = _mm256_and_si256(x,simd_unary_minus(x)); //b
					 x = _mm256_sub_epi64(x,_mm256_srli_epi64(ymm2,1)); // move right
					 do {
						 ymm1 = _mm256_slli_epi64(ymm1,1);
				    }
					while(_mm256_testz_si256(ZERO,_mm256_and_si256(ymm1,x)));
					x = _mm256_xor_si256(x,_mm256_srli_epi64(ymm1,1));
			    }
				 return (x);
#endif   
			 }

			 static inline __m256i simd_copy_bit(_Inout_ __m256i &a,
											     _In_ __m256i &isrc,
												 _In_ __m256i &idst) {
				 // Copy bit at [isrc] to position [idst].
				 // Return the modified word.
#if 1 // Branch free
				 __m256i t1 = _mm256_srlv_epi64(a,isrc);
				 __m256i t2 = _mm256_srlv_epi64(a,idst);
				 __m256i ymm0 = _mm256_and_si256(_mm256_xor_si256(t1,t2),ONE); //x one if bits differ
				 a = _mm256_xor_si256(a, _mm256_sllv_epi64(ymm0,idst)); // change if bits differ
				 return (a);
#else
				 __m256i ymm0 = _mm256_and_si256(a,_mm256_sllv_epi64(ONE,isrc)); // v
				 __m256i ymm1 = _mm256_sllv_epi64(ONE,idst); // b
				 if(_mm256_testz_si256(ymm0,ZERO)) 
					 a = _mm256_and_si256(a,simd_unary_minus(ymm1));
				 else
					 a = _mm256_or_si256(a,ymm1);
				 return (a);
#endif
			 }

			 static inline __m256i simd_mask_copy_bit(_In_ __m256i &a,
													  _In_ const __m256i &msrc,
													  _In_ const __m256i &mdst) {
				 // Copy bit according at src-mask (msrc)
				 //  to the bit according to the dest-mask (mdst).
				 // Both msrc and mdst must have exactly one bit set.
				 // Return the modified word.
				 __m256i ymm0 = _mm256_and_si256(a,msrc); // v
				 __m256i ymm1 = mdst; // b
				 if (_mm256_testz_si256(ymm0,ZERO))
					 a = _mm256_and_si256(a,simd_not(ymm1));
				 else
					 a = _mm256_or_si256(a,ymm1);
				 return (a);
			}
	
			 static inline __m256i simd_mask_or_bit(_In_ __m256i &a,
												    _In_ const __m256i &msrc,
												    _In_       __m256i &mdst) {
				 // Or bit according to src-mask (msrc)
				 //  to the bit according to the dest-mask (mdst).
				 // Both msrc and mdst must have exactly one bit set.
				 // If the mdst-position is known to be zero this function
				 //  is equivalent to mask_copy_bit().
				 // Return the modified word.
#if 1 // Branch free
				 if(!_mm256_testz_si256(
							_mm256_and_si256(msrc,a),ZERO))
				    mdst = _mm256_set1_epi64x(0ULL);
				 a = _mm256_or_si256(a,mdst);
				 return (a);
#else
				 if(!_mm256_testz_si256(
							_mm256_and_si256(a,msrc),ZERO))
				    a = _mm256_or_si256(a,mdst);
				 return (a);
#endif
			 }

			 static inline __m256i simd_bit_count(_In_ __m256i &x) {
				 // Return number of set bits.
				 // The sequence of values returned for x = 0, 1, 2, 3, ... is
				 // 0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4, 1, ...
				 // (OEIS sequence A000120).
				 // Implemented only for 32-bit integral values.
				 __m256i t1 = _mm256_and_si256(_mm256_srli_epi32(x,1),MASK_CNT2BITS);
				 x = _mm256_sub_epi32(x,t1);
				 __m256i t2 = _mm256_and_si256(_mm256_srli_epi32(x,2),MASK_CNT4BITS);
				 x = _mm256_add_epi32(t2, _mm256_and_si256(x,MASK_CNT4BITS));
				 __m256i t3 = _mm256_add_epi32(_mm256_srli_epi32(x,4),x);
				 x = _mm256_and_si256(t3,MASK_CNT8BITS);
				 x = _mm256_mul_epu32(x,MASK_ALTONES);
				 return (_mm256_srli_epi32(x,24));
			 }

			 static inline __m256i simd_bit_count_15(_In_ __m256i &x) {
				 // Return number of set bits, must have at most 15 set bits.
				 __m256i t1 = _mm256_and_si256(_mm256_srli_epi32(x,1),MASK_CNT2BITS);
				 x = _mm256_sub_epi32(x,t1);
				 __m256i t2 = _mm256_and_si256(_mm256_srli_epi32(x, 2), MASK_CNT4BITS);
				 x = _mm256_add_epi32(t2, _mm256_and_si256(x, MASK_CNT4BITS));
				 x = _mm256_mul_epu32(x,MASK_ONES);
				 return (_mm256_srli_epi32(x,28));
			 }

			 static inline __m256i simd_bit_count_3(_In_ __m256i &x) {
				 // Return number of set bits, must have at most 3 set bits.
				 __m256i t1 = _mm256_and_si256(_mm256_srli_epi32(x,1),MASK_CNT2BITS);
				 x = _mm256_sub_epi32(x,t1);
				 x = _mm256_mul_epu32(x,MASK_CNT2BITS);
				 return (_mm256_srli_epi32(x,30));
			 }

			 static inline __m256i simd_bit_count_cmp(_In_ __m256i &x,
													  _In_ __m256i &y) {
				// Compare bit counts in x and y.
				 __m256i ymm0 = simd_bit_count(x);
				 __m256i ymm1 = simd_bit_count(y);
				 if (_mm256_cmpeq_epu32_mask(ymm0,ymm1))
					 return (_mm256_set1_epi32(0));
				 else if (_mm256_cmpgt_epu32_mask(ymm0,ymm1))
					 return (_mm256_set1_epi32(+1));
				 else
					 return (_mm256_set1_epi32(-1));
			 }

			 static inline __m256i simd_bit_block_count(_In_ const __m256i &x) {
				 // Return number of bit blocks.
				 // E.g.:
				 // ..1..11111...111.  -> 3
				 // ...1..11111...111  -> 3
				 // ......1.....1.1..  -> 3
				 // .........111.1111  -> 2
				 __m256i t1 = _mm256_and_si256(x,ONE);
				 __m256i t2 = _mm256_xor_si256(x, _mm256_srli_epi32(x,1));
				 return (_mm256_add_epi32(t1, 
						 _mm256_div_epi32(simd_bit_count(t2), _mm256_set1_epi32(2))));
			 }

			 static inline __m256i simd_bit_block_ge2_count(_In_ const __m256i &x) {
				 // Return number of bit blocks with at least 2 bits.
				 // E.g.:
				 // ..1..11111...111.  -> 2
				 // ...1..11111...111  -> 2
				 // ......1.....1.1..  -> 0
				 // .........111.1111  -> 2
				 __m256i t1 = _mm256_and_si256(_mm256_slli_epi32(x, 1), _mm256_srli_epi32(x,1));
				 return (simd_bit_block_count(_mm256_and_si256(x,t1)));
			 }

			 static inline __m256i simd_bit_rotate_left(_In_ const __m256i &x,
														_In_ const __m256i &r) {
				 // Return word rotated r bits to the left
				 // (i.e. toward the most significant bit)
				 //.
				 return (_mm256_or_si256(_mm256_sllv_epi64(x,r),
				         _mm256_srlv_epi64(x,_mm256_sub_epi64(BITS_PER_LONG_64,r))));
			 }

			 static inline __m256i simd_bit_rotate_right(_In_ const __m256i &x,
													     _In_ const __m256i &r) {
				 // Return word rotated r bits to the right
				 // (i.e. toward the least significant bit)
				 //
				 return (_mm256_or_si256(_mm256_srlv_epi64(x, r),
					 _mm256_sllv_epi64(x, _mm256_sub_epi64(BITS_PER_LONG_64, r))));
			 }

			 static inline __m256i simd_bit_rotate_left(_In_  __m256i &x,
													    _In_ const __m256i &r,
													    _In_ const __m256i &n) {
				 // Return n-bit word rotated r bits to the left
				 // (i.e. toward the most significant bit)
				 // Must have  0 <= r <= n
				 __m256i ymm0 = _mm256_srlv_epi64(simd_not(ZERO), 
								       _mm256_sub_epi64(BITS_PER_LONG_64,n)); // m
				 x = _mm256_and_si256(x,ymm0);
				 x = _mm256_or_si256(_mm256_sllv_epi64(x, r), 
					 _mm256_srlv_epi64(x, _mm256_sub_epi64(n,r)));
				 x = _mm256_and_si256(x,ymm0);
				 return (x);
			 }

			 static inline __m256i simd_bit_rotate_right(_In_ __m256i &x,
														 _In_ const __m256i &r,
													     _In_ const __m256i &n) {
				 // Return n-bit word rotated r bits to the right
				 // (i.e. toward the least significant bit)
				 // Must have  0 <= r <= n
				 __m256i ymm0 = _mm256_srlv_epi64(simd_not(ZERO),
					 _mm256_sub_epi64(BITS_PER_LONG_64, n)); // m
				 x = _mm256_and_si256(x, ymm0);
				 x = _mm256_or_si256(_mm256_srlv_epi64(x, r),
					 _mm256_sllv_epi64(x, _mm256_sub_epi64(n, r)));
				 x = _mm256_and_si256(x, ymm0);
			 }

			 static inline __m256i simd_bit_cyclic_dist(_In_ const __m256i &a,
												        _In_ const __m256i &b) {
				 // Return minimal bitcount of (t ^ b)
				 // where t runs through the cyclic rotations of a.
				 __m256i ymm0 = simd_not(ZERO); // d
				 __m256i ymm1 = a; //t
				 do {
					 __m256i ymm2 = _mm256_xor_si256(ymm1,b);
					 __m256i ymm3 = simd_bit_count(ymm2);
					 if (_mm256_cmplt_epi64_mask(ymm3,ymm0))
						 ymm0 = ymm3;
					 ymm1 = simd_bit_rotate_right(ymm1,ONE);
				 }
				 while (_mm256_cmpneq_epu64_mask(ymm1,a));
				 return (ymm0);
			 }

			 static inline __m256i simd_bit_cyclic_dist(_In_ __m256i &a,
														_In_ __m256i &b,
														_In_ const __m256i &n) {
				 // Return minimal bitcount of (t ^ b)
				 // where t runs through the cyclic rotations of a.
				 // Using n-bit words.
				 __m256i ymm0 = simd_not(ZERO); //d
				 const __m256i ymm1 = _mm256_srlv_epi64(simd_not(ZERO), 
									  _mm256_sub_epi64(BITS_PER_LONG_64,n)); // m
				 b = _mm256_and_si256(b,ymm1);
				 a = _mm256_and_si256(a,ymm1);
				 __m256i ymm2 = a;
				 do {
					 __m256i ymm3 = _mm256_xor_si256(ymm2,b);
					 __m256i ymm4 = simd_bit_count(ymm3);
					 if (_mm256_cmplt_epi64_mask(ymm4,ymm0))
						 ymm0 = ymm4;
					 ymm2 = simd_bit_rotate_left(ymm2,ONE,n);
				 }
				 while (_mm256_cmpneq_epu64_mask(ymm2,a));
				 return (ymm0);
			 }

			 static inline __m256i simd_is_pow_of_2(_In_ const __m256i &x) {
				 // Return whether x == 0(!) or x == 2**k
				 return (_mm256_cmpeq_epi64(
						 _mm256_and_si256(x,simd_unary_minus(x)),x));
			 }

			 static inline __m256i simd_one_bit_q(_In_ const __m256i &x) {
				 // Return whether x \in {1,2,4,8,16,...}
				 __m256i ymm0 = _mm256_sub_epi64(x,ONE);
				 return (_mm256_cmpeq_epi64(
					     _mm256_srli_epi64(_mm256_xor_si256(x,ymm0),1),ymm0));
			 }

			 static inline __m256i simd_next_pow_of_2(_In_ __m256i &x) {
				 // Return x if x=2**k
				 // else return 2**ceil(log_2(x))
				 // Exception: returns 0 for x==0
				 __m256i ymm0 = simd_is_pow_of_2(x);
				 if (_mm256_testc_si256(ymm0,ONE))
					 return (x);
				 x = _mm256_or_si256(x, _mm256_srli_epi64(x,1));
				 x = _mm256_or_si256(x, _mm256_srli_epi64(x,2));
				 x = _mm256_or_si256(x, _mm256_srli_epi64(x,4));
				 x = _mm256_or_si256(x, _mm256_srli_epi64(x,8));
				 x = _mm256_or_si256(x, _mm256_srli_epi64(x,16));
				 x = _mm256_or_si256(x, _mm256_srli_epi64(x,32));
				 return (simd_inc(x));
			 }

			 static inline __m256i simd_bit_cyclic_match(_In_ const __m256i &x,
														 _In_ __m256i &y) {
				 // Return  r if x==rotate_right(y, r) else return ~0UL.
				 // In other words: return
				 //   how often the right arg must be rotated right (to match the left)
				 // or, equivalently:
				 //   how often the left arg must be rotated left (to match the right)
				 __m256i ymm0 = _mm256_set1_epi64x(0ULL); // r
				 do {
					 if (_mm256_cmpeq_epi64_mask(x,y))
						 return (ymm0);
					 y = simd_bit_rotate_right(y,ONE);
				 }
				 while (_mm256_cmplt_epi64_mask(simd_inc(ymm0),BITS_PER_LONG_64));
				 return (simd_not(ZERO));
			 }

			 static inline __m256i simd_bit_cyclic_match(_In_ const __m256i &x,
														 _In_  __m256i &y,
														 _In_ const __m256i &n) {
				 // Return  r if x==rotate_right(y, r, n) else return ~0UL
				 //  (using n-bit words)
				 __m256i ymm0 = _mm256_set1_epi64x(0ULL); //r
				 do {
					 if (_mm256_cmpeq_epi64_mask(x,y))
						 return (ymm0);
					 y = simd_bit_rotate_right(y,ONE,n);
				 }
				 while (_mm256_cmplt_epi64_mask(simd_inc(ymm0),n));
				 return (simd_not(ZERO));
			 }

			 static inline __m256i simd_bit_cyclic_dist1_match(_In_ const __m256i &x,
															   _In_  __m256i &y) {
				 // Return  the minimal r so that
				 //   c = (x ^ rotate_right(y, r, n)) is a one-bit word.
				 // Return ~0UL if there is no such r.
				 __m256i ymm0 = _mm256_set1_epi64x(0ULL); //r
				 do {
					 __m256i ymm1 = _mm256_xor_si256(x,y);
					 if (_mm256_cmpgt_epu64_mask(simd_one_bit_q(ymm1),ZERO))
						 return (ymm0);
					 y = simd_bit_rotate_right(y,ONE);
				 }
				 while (_mm256_cmplt_epi64_mask(simd_inc(ymm0),BITS_PER_LONG_64));
				 return (simd_not(ZERO));
			 }

			 static inline __m256i simd_bit_cyclic_dist1_match(_In_ const __m256i &x,
															   _In_ __m256i &y,
															   _In_ const __m256i &n) {
				 // Return  the minimal r so that
				 //   c = (x ^ rotate_right(y, r, n)) is a one-bit word.
				 // Return ~0UL if there is no such r.
				 //  (using n-bit words)
				 __m256i ymm0 = _mm256_set1_epi64x(0ULL);
				 do {
					 __m256i ymm1 = _mm256_xor_si256(x,y);
					 if (_mm256_cmpgt_epu64_mask(simd_one_bit_q(ymm1),ZERO))
						 return (ymm0);
					 y = simd_bit_rotate_right(y,ONE,n);
				 }
				 while (_mm256_cmplt_epi64_mask(simd_inc(ymm0),n));
				 return (simd_not(ZERO));
			 }

			 static inline __m256i simd_bit_cyclic_min(_In_ __m256i &x) {
				 // Return minimum of all rotations of x
				 __m256i ymm0 = _mm256_set1_epi64x(1ULL); // r
				 __m256i ymm1 = x; //m
				 do {
					 x = simd_bit_rotate_right(x,ONE);
					 if (_mm256_cmplt_epi64_mask(x,ymm1))
					     ymm1 = x;
				 }
				 while (_mm256_cmplt_epi64_mask(simd_inc(ymm0),BITS_PER_LONG_64));
				 return (ymm1);
			 }

			 static inline __m256i simd_bit_cyclic_min(_In_ __m256i &x,
												       _In_ const __m256i &n) {
				 // Return minimum of all rotations of x using n-bit words
				 __m256i ymm0 = _mm256_set1_epi64x(1ULL);
				 __m256i ymm1 = x;
				 do {
					 x = simd_bit_rotate_right(x,ONE,n);
					 if (_mm256_cmplt_epu64_mask(x,ymm1));
						 ymm1 = x;
				}	 
				while (_mm256_cmplt_epu64_mask(simd_inc(ymm0),n));
				return (ymm1);
			 }

			 static inline __m256i simd_bit_cyclic_max(_In_ __m256i &x) {
				 // Return maximum of all rotations of x
				 __m256i ymm0 = _mm256_set1_epi64x(1ULL);
				 __m256i ymm1 = x;
				 do {
					 x = simd_bit_rotate_right(x, ONE);
					 if (_mm256_cmpgt_epu64_mask(x, ymm1));
					 ymm1 = x;
				 } while (_mm256_cmplt_epu64_mask(simd_inc(ymm0), BITS_PER_LONG_64));
				 return (ymm1);
			 }

			 static inline __m256i simd_bit_cyclic_max(_In_ __m256i &x,
													   _In_ const __m256i &n) {
				 // Return maximum of all rotations of x using n-bit words
				 __m256i ymm0 = _mm256_set1_epi64x(1ULL);
				 __m256i ymm1 = x; // m
				 do {
					 x = simd_bit_rotate_right(x, ONE, n);
					 if (_mm256_cmpgt_epu64_mask(x, ymm1));
					 ymm1 = x;
				 } while (_mm256_cmplt_epu64_mask(simd_inc(ymm0), n));
				 return (ymm1);
			 }

			 static inline __m256i simd_is_bit_cyclic_min(_In_  __m256i &x) {
			    // Return whether x is the minimum of all rotations of x
				 return (_mm256_cmpeq_epi64(x, simd_bit_cyclic_min(x)));
			 }

			 static inline __m256i simd_is_bit_cyclic_min(_In_ __m256i &x,
														  _In_ __m256i &n) {
				 // Return whether x is the minimum of all rotations of x as n-bit word
				 return (_mm256_cmpeq_epi64(x, simd_bit_cyclic_min(x,n)));
			 }

			 static inline __m256i simd_is_bit_cyclic_max(_In_ __m256i &x) {
				 //  Return whether x is the maximum of all rotations of x
				 return (_mm256_cmpeq_epi64(x, simd_bit_cyclic_max(x)));
			 }

			 static inline __m256i simd_is_bit_cyclic_max(_In_ __m256i &x,
													      _In_ __m256i &n) {
				 // Return whether x is the maximum of all rotations of x as n-bit word
				 return (_mm256_cmpeq_epi64(x, simd_bit_cyclic_max(x,n)));
			 }

			 static inline __m256i simd_bit_cyclic_rxor(_In_ __m256i &x) {
				 // Similar to Gray code, but the bit shifted
				 // out at the right is moved to the highest bit.
				 // The returned word has an even number of bits set.
				 return (_mm256_xor_si256(x,simd_bit_rotate_right(x,ONE)));
			 }

			 static inline __m256i simd_bit_cyclic_rxor(_In_ __m256i &x,
													   _In_ const __m256i &n) {
				 // Version for n-bit words
				 return (_mm256_xor_si256(x, simd_bit_rotate_right(x,ONE,n)));
			 }

			 static inline __mmask8 simd_bit_dragon3_turn(_In_ __m256i &x) {
				 // Increment the radix-3 word x and return (tr)
				 //   whether the number of ones in x is decreased.
				 // tr determines whether to turn left or right (by 120 degrees)
				 //   with the terdragon fractal.
				 //
				 // Starting with x==0:
				 //  x (binary) tr   x (ternary)
				 //  ........   0    0 0 0
				 //  .......1   0    0 0 1
				 //  ......1.   1    0 0 2
				 //  .....1..   0    0 1 0
				 //  .....1.1   0    0 1 1
				 //  .....11.   1    0 1 2
				 //  ....1...   1    0 2 0
				 //  ....1..1   0    0 2 1
				 //  ....1.1.   1    0 2 2
				 //  ...1....   0    1 0 0
				 // The sequence tr (for x>=1) is entry A080846 in the OEIS,
				 // the fixed point of the morphism  0 |--> 010,  1 |--> 011.
				 // See also A060236 (== 1,2,1,1,2,2,1,2,1,1,2,1,1,2,2,1,2,2,1,2, ...).
				 // Also fixed point of morphism (for k>0, identify + with 0 and - with 1)
				 // F |--> F+F-F,  + |--> +,  - |--> -
				 __m256i ymm0 = _mm256_set1_epi64x(0ULL); //s
				 while (_mm256_cmpeq_epu64_mask(_mm256_and_si256(x, THREE),TWO)) {
					 x = _mm256_srli_epi64(x,2);
					 simd_inc(ymm0);
				}		
				 __mmask8 tr = (_mm256_cmpneq_epu64_mask(_mm256_and_si256(x,THREE),ZERO));
				 simd_inc(x);
				 x = _mm256_sllv_epi64(x, _mm256_slli_epi64(ymm0,1));
				 return tr;
			 }

			 static inline __m256i simd_highest_one_01edge(_In_ __m256i &x) {
				 // Return word where all bits from (including) the
				 //   highest set bit to bit 0 are set.
				 // Return 0 if no bit is set.
				 //
				 // Feed the result into bit_count() to get
				 //   the index of the highest bit set.
				 x = _mm256_or_si256(x, _mm256_srli_epi64(x,1));
				 x = _mm256_or_si256(x, _mm256_srli_epi64(x,2));
				 x = _mm256_or_si256(x, _mm256_srli_epi64(x,4));
				 x = _mm256_or_si256(x, _mm256_srli_epi64(x,8));
				 x = _mm256_or_si256(x, _mm256_srli_epi64(x,16));
				 x = _mm256_or_si256(x, _mm256_srli_epi64(x,32));
				 return (x);
			 }

			 static inline __m256i simd_highest_one_10edge(_In_ __m256i &x) {
				 // Return word where all bits from  (including) the
				 //   highest set bit to most significant bit are set.
				 // Return 0 if no bit is set.
				 if (_mm256_cmpeq_epi64_mask(x,ZERO))
					 return (_mm256_set1_epi64x(0ULL));
				 x = simd_highest_one_01edge(x);
				 return (simd_not(_mm256_srli_epi64(x,1)));
			 }

			 static inline __m256i simd_highest_one(_In_ __m256i &x) {
				 // Return word where only the highest bit in x is set.
				 // Return 0 if no bit is set.
				 x = simd_highest_one_01edge(x);
				 return (_mm256_xor_si256(x, _mm256_srli_epi64(x,1)));
			 }

			 static inline __m256i simd_highest_zero(_In_ __m256i &x) {
				 // Return word where only the highest unset bit in x is set.
				 // Return 0 if all bits are set.
				 return (simd_highest_one(simd_not(x)));
			 }

			 static inline __m256i simd_set_highest_zero(_In_ __m256i &x) {
				 // Return word where the highest unset bit in x is set.
				 // Return ~0 for input == ~0.
				 return (_mm256_or_si256(x, simd_highest_one(simd_not(x))));
			 }

			 static inline __mmask8 simd_ld_eq(_In_ const __m256i &x,
											  _In_ const __m256i &y) {
				 // Return whether floor(log2(x))==floor(log2(y)).
				 // For arguments 0 and 1 (either order)
				 // ld_eq(x,y) correctly returns false
				 // whereas ld(x) == ld(y) gives true
				 // (because ld(x) returns 0 for both x==1 and x==0)
				 return (_mm256_cmple_epu64_mask(_mm256_xor_si256(x, y), 
												 _mm256_and_si256(x,y)));
			 }

			 static inline __mmask8 simd_ld_neq(_In_ const __m256i &x,
											    _In_ const __m256i &y) {
				 // Return whether floor(log2(x))!=floor(log2(y))
				 return (_mm256_cmpgt_epu64_mask(_mm256_xor_si256(x,y),
											     _mm256_and_si256(x,y)));
			 }

			 static inline __m256i simd_bit_gather(_In_  const __m256i &w,
												   _In_		   __m256i &m) {
				 // Return  word with bits of w collected as indicated by m:
				 // Example:
				 //  w = 00A0BC00
				 //  m = 00101100
				 //  ==> 00000ABC
				 // This is the inverse of bit_scatter()
				 __m256i ymm0 = _mm256_set1_epi64x(0ULL); // z
				 __m256i ymm1 = _mm256_set1_epi64x(1ULL); // b
				 while (_mm256_cmpneq_epu64_mask(m, ZERO)) {
					__m256i ymm2 = _mm256_and_si256(m, simd_unary_minus(m)); // i
					m = _mm256_xor_si256(m,ymm2);
					if (_mm256_cmpneq_epu64_mask(_mm256_and_si256(ymm2,w),ZERO))
						ymm0 = _mm256_add_epi64(ymm0,ymm1);
					else
						ymm0 = _mm256_add_epi64(ymm0,ZERO);
					ymm1 = _mm256_slli_epi64(ymm1,1);
				 }
				 return (ymm0);
			 }

			 static inline __m256i simd_bit_scatter(_In_ const __m256i &w,
												    _In_ __m256i &m) {
				 // Return  word with bits of w distributed as indicated by m:
				 // Example:
				 //  w = 00000ABC
				 //  m = 00101100
				 //  ==> 00A0BC00
				 // This is the inverse of bit_gather()
				 __m256i ymm0 = _mm256_set1_epi64x(0ULL); // z
				 __m256i ymm1 = _mm256_set1_epi64x(1ULL); // b
				 while (_mm256_cmpneq_epu64_mask(m, ZERO)) {
					 __m256i ymm2 = _mm256_and_si256(m, simd_unary_minus(m)); // i
					 m = _mm256_xor_si256(m, ymm2);
					 if (_mm256_cmpneq_epu64_mask(_mm256_and_si256(ymm2, w), ZERO))
						 ymm0 = _mm256_add_epi64(ymm0, ymm2);
					 else
						 ymm0 = _mm256_add_epi64(ymm0, ZERO);
					 ymm1 = _mm256_slli_epi64(ymm1, 1);
				 }
				 return (ymm0);
			 }

			 static inline __m256i simd_left_swap_16(_In_ __m256i &x) {
				 // Return 64-bit word with two leftmost quarters swapped.
				 const __m256i ymm0 = _mm256_set1_epi64x(0x0000ffff00000000UL); // mr
				 const __m256i ymm1 = _mm256_set1_epi64x(16ULL); // s
				 const __m256i ymm2 = _mm256_sllv_epi64(ymm0,ymm1); // ml
				 const __m256i ymm3 = _mm256_or_si256(_mm256_srlv_epi64(_mm256_and_si256(x,ymm2),ymm1), 
									  _mm256_sllv_epi64(_mm256_and_si256(x,ymm0),ymm1)); // t
				 __m256i t1 = simd_not(_mm256_or_si256(ymm2,ymm0));
				 x = _mm256_or_si256(_mm256_and_si256(x,t1),ymm3);
				 return (x);
			 }

			 static inline __m256i simd_left_swap_8(_In_ __m256i &x) {
				 // Return word with two leftmost quarters of each 32-bit block swapped.
				 const __m256i ymm0 = _mm256_set1_epi64x(0x00ff000000ff0000UL); // mr
				 const __m256i ymm1 = _mm256_set1_epi64x(8ULL); // s
				 const __m256i ymm2 = _mm256_sllv_epi64(ymm0, ymm1); // ml
				 const __m256i ymm3 = _mm256_or_si256(_mm256_srlv_epi64(_mm256_and_si256(x, ymm2), ymm1),
					 _mm256_sllv_epi64(_mm256_and_si256(x, ymm0), ymm1)); // t
				 __m256i t1 = simd_not(_mm256_or_si256(ymm2, ymm0));
				 x = _mm256_or_si256(_mm256_and_si256(x, t1), ymm3);
				 return (x);
			 }

			 static inline __m256i simd_left_swap_4(_In_ __m256i &x) {
				 // Return word with two leftmost quarters of each 16-bit block swapped.
				 const __m256i ymm0 = _mm256_set1_epi64x(0x0f000f000f000f00UL); // mr
				 const __m256i ymm1 = _mm256_set1_epi64x(4ULL); // s
				 const __m256i ymm2 = _mm256_sllv_epi64(ymm0, ymm1); // ml
				 const __m256i ymm3 = _mm256_or_si256(_mm256_srlv_epi64(_mm256_and_si256(x, ymm2), ymm1),
					 _mm256_sllv_epi64(_mm256_and_si256(x, ymm0), ymm1)); // t
				 __m256i t1 = simd_not(_mm256_or_si256(ymm2, ymm0));
				 x = _mm256_or_si256(_mm256_and_si256(x, t1), ymm3);
				 return (x);
			 }

			 static inline __m256i simd_left_swap_2(_In_ __m256i &x) {
				 // Return word with two leftmost quarters of each 8-bit block swapped.
				 const __m256i ymm0 = _mm256_set1_epi64x(0x3030303030303030UL); // mr
				 const __m256i ymm1 = _mm256_set1_epi64x(2ULL); // s
				 const __m256i ymm2 = _mm256_sllv_epi64(ymm0, ymm1); // ml
				 const __m256i ymm3 = _mm256_or_si256(_mm256_srlv_epi64(_mm256_and_si256(x, ymm2), ymm1),
					 _mm256_sllv_epi64(_mm256_and_si256(x, ymm0), ymm1)); // t
				 __m256i t1 = simd_not(_mm256_or_si256(ymm2, ymm0));
				 x = _mm256_or_si256(_mm256_and_si256(x, t1), ymm3);
				 return (x);
			 }

			 static inline __m256i simd_left_swap_1(_In_ __m256i &x) {
				 // Return word with two leftmost bits of each 4-bit block swapped.
				 const __m256i ymm0 = _mm256_set1_epi64x(0x4444444444444444UL); // mr
				 const __m256i ymm1 = _mm256_set1_epi64x(1ULL); // s
				 const __m256i ymm2 = _mm256_sllv_epi64(ymm0, ymm1); // ml
				 const __m256i ymm3 = _mm256_or_si256(_mm256_srlv_epi64(_mm256_and_si256(x, ymm2), ymm1),
					 _mm256_sllv_epi64(_mm256_and_si256(x, ymm0), ymm1)); // t
				 __m256i t1 = simd_not(_mm256_or_si256(ymm2, ymm0));
				 x = _mm256_or_si256(_mm256_and_si256(x, t1), ymm3);
				 return (x);
			 }

			 static inline __m256i simd_bit_gray_permute(_In_ __m256i &x) {
				 // Return word with gray-permuted bits.
				 x = simd_left_swap_1(x);
				 x = simd_left_swap_2(x);
				 x = simd_left_swap_4(x);
				 x = simd_left_swap_8(x);
				 x = simd_left_swap_16(x);
				 return (x);
			 }

			 static inline __m256i simd_bit_inverse_gray_permute(_In_ __m256i &x) {
				 // Inverse of bit_gray_permute()
				 x = simd_left_swap_16(x);
				 x = simd_left_swap_8(x);
				 x = simd_left_swap_4(x);
				 x = simd_left_swap_2(x);
				 x = simd_left_swap_1(x);
				 return (x);
			 }

			 static inline __m256i simd_blue_xcode(_In_ __m256i &a,
												   _In_ __m256i &x) {
				 x = _mm256_and_si256(x,_mm256_sub_epi64(BITS_PER_LONG_64,ONE));
				 __m256i ymm0 = _mm256_srli_epi64(BITS_PER_LONG_64,1); // s
				 __m256i ymm1 = _mm256_sllv_epi64(simd_not(ZERO),ymm0); // m
				 while (_mm256_cmpneq_epi64_mask(ymm0, ZERO)) {
					 if (_mm256_cmpneq_epi64_mask(_mm256_and_si256(x,ONE),ZERO))
						 a = _mm256_xor_si256(a, _mm256_srlv_epi64(_mm256_and_si256(a,ymm1),ymm0));
					 x = _mm256_srli_epi64(x,1);
					 ymm0 = _mm256_srli_epi64(ymm0,1);
					 ymm1 = _mm256_xor_si256(ymm1, _mm256_srlv_epi64(ymm1,ymm0));
				 }
				 return (a);
			 }

			 static inline __m256i simd_yellow_xcode(_In_ __m256i &a,
												     _In_ __m256i &x) {
				 x = _mm256_and_si256(x, _mm256_sub_epi64(BITS_PER_LONG_64, ONE));
				 __m256i ymm0 = _mm256_srli_epi64(BITS_PER_LONG_64, 1); // s
				 __m256i ymm1 = _mm256_srlv_epi64(simd_not(ZERO), ymm0); // m
				 while (_mm256_cmpneq_epi64_mask(ymm0, ZERO)) {
					 if (_mm256_cmpneq_epi64_mask(_mm256_and_si256(x, ONE), ZERO))
						 a = _mm256_xor_si256(a, _mm256_sllv_epi64(_mm256_and_si256(a, ymm1), ymm0));
					 x = _mm256_srli_epi64(x, 1);
					 ymm0 = _mm256_srli_epi64(ymm0, 1);
					 ymm1 = _mm256_xor_si256(ymm1, _mm256_sllv_epi64(ymm1, ymm0));
				 }
				 return (a);
			 }

			 static inline __m256i simd_test_bit(_In_ const __m256i &a,
												 _In_ const __m256i &i) {
				 // Return zero if bit[i] is zero, (vector form)
				 //  else return one-bit word with bit[i] set.
				 return (_mm256_and_si256(a,_mm256_sllv_epi64(ONE,i)));
			 }

			 static inline __m256i simd_set_bit(_In_ const __m256i &a,
												_In_ const __m256i &i) {
				 // Return a with bit[i] set (vector form)
				 return (_mm256_xor_si256(a, _mm256_sllv_epi64(ONE,i)));
			 }

			 static inline __m256i simd_clear_bit(_In_ const __m256i &a,
											      _In_ const __m256i &i) {
				 // Return a with bit[i] cleared (vector form).
				 return (_mm256_and_si256(a, simd_not(_mm256_sllv_epi64(ONE,i))));
			 }

			 static inline __m256i simd_change_bit(_In_ const __m256i &a,
												   _In_ const __m256i &i) {
				 // Return a with bit[i] changed.
				 return (_mm256_xor_si256(a, _mm256_sllv_epi64(ONE,i)));
			 }

			 static inline __m256i simd_single_ones(_In_ const __m256i &x) {
				 // Return word with only the isolated ones of x set.
				 // Assume outside values are 0.
				 return (_mm256_and_si256(x,simd_not(_mm256_or_si256(
						 _mm256_slli_epi64(x, 1), _mm256_srli_epi64(x,1)))));
			 }

			 static inline __m256i simd_single_ones_xi(_In_ const __m256i &x) {
				 // Return word with only the isolated ones of x set.
				 // Ignore outside values.
				 return (simd_single_ones(x));
			 }

			 static inline __m256i simd_single_zeroes(_In_ const __m256i &x) {
				 // Return word with only the isolated zeros of x set.
				 // Assume outside values are 0.
				 return (_mm256_and_si256(simd_not(x), 
						_mm256_and_si256(_mm256_slli_epi64(x, 1), _mm256_srli_epi64(x,1))));
			 }

			 static inline __m256i simd_single_zeroes_xi(_In_ const __m256i &x) {
				 // Return word with only the isolated zeros of x set.
				 // Ignore outside values.
				 return (simd_single_ones(simd_not(x)));
			 }

			 static inline __m256i simd_single_values(_In_ const __m256i &x) {
				 // Return word where only the isolated ones and zeros of x are set.
				 // Assume outside values are 0.
				 __m256i ymm0 = _mm256_xor_si256(x,_mm256_slli_epi64(x,1));
				 __m256i ymm1 = _mm256_xor_si256(x,_mm256_srli_epi64(x,1));
				 return (_mm256_and_si256(ymm0,ymm1));
			 }

			 static inline __m256i simd_single_values_xi(_In_ const __m256i &x) {
				 // Return word where only the isolated ones and zeros of x are set.
				 // Ignore outside values.
				 return (_mm256_xor_si256(simd_single_ones_xi(x), simd_single_zeroes_xi(x)));
			 }

			 static inline __m256i simd_single_border_ones(_In_ const __m256i &x) {
				 // Return word where only those ones of x are set that lie next to a zero.
				 return (_mm256_and_si256(x, simd_not(_mm256_and_si256(
					 _mm256_slli_epi64(x, 1), _mm256_srli_epi64(x, 1)))));
			 }

			 static inline __m256i simd_border_values(_In_ const __m256i &x) {
				 // Return word where those bits of x are set that lie on a transition.
				 // Assume outside values are 0.
				 __m256i ymm0 = _mm256_xor_si256(x, _mm256_slli_epi64(x,1));
				 __m256i ymm1 = _mm256_xor_si256(x, _mm256_srli_epi64(x,1));
				 return (_mm256_or_si256(ymm0,ymm1));
			 }

			 static inline __m256i simd_high_border_ones(_In_ const __m256i &x) {
				 // Return word where only those ones of x are set
				 //   that lie right to (i.e. in the next lower bin of) a zero.
				 return (_mm256_and_si256(x, _mm256_xor_si256(x, _mm256_srli_epi64(x,1))));
			 }

			 static inline __m256i simd_low_border_ones(_In_ const __m256i &x) {
				 // Return word where only those ones of x are set
				 //   that lie left to (i.e. in the next higher bin of) a zero.
				 return (_mm256_and_si256(x, _mm256_xor_si256(x, _mm256_slli_epi64(x, 1))));
			 }

			 static inline __m256i simd_block_border_ones(_In_ const __m256i &x) {
				 // Return word where only those ones of x are set
				 //   that are at the border of a block of at least 2 ones.
				 return (_mm256_and_si256(x, _mm256_xor_si256(_mm256_slli_epi64(x,1),
					 _mm256_srli_epi64(x,1))));
			 }

			 static inline __m256i simd_low_block_border_ones(_In_ const __m256i &x) {
				 // Return word where only those ones of x are set
				 //   that are at right of a border of a block of at least 2 ones.
				 __m256i ymm0 = _mm256_and_si256(x, _mm256_xor_si256(_mm256_slli_epi64(x, 1),
					 _mm256_srli_epi64(x, 1)));
				 return (_mm256_and_si256(ymm0, _mm256_srli_si256(x,1)));
			 }

			 static inline __m256i simd_block_ones(_In_ const __m256i &x) {
				 // Return word where only those ones of x are set
				 //   that are part of a block of at least 2 ones.
				 return (_mm256_and_si256(x, _mm256_or_si256(_mm256_slli_epi64(x, 1),
					 _mm256_srli_epi64(x, 1))));
			 }

			 static inline __m256i simd_block_values(_In_ const __m256i &x) {
				 // Return word where only those bits of x are set
				 // that do not lie next to an opposite value.
				 return (simd_not(simd_single_values(x)));
			 }

			 static inline __m256i simd_interior_ones(_In_ const __m256i &x) {
				 // Return word where only those ones of x are set
				 //   that do not have a zero to their left or right.
				 return (_mm256_and_si256(x, _mm256_and_si256(_mm256_slli_epi64(x, 1),
					 _mm256_srli_epi64(x, 1))));
			 }

			 static inline __m256i simd_interior_values(_In_ const __m256i &x) {
				 return (simd_not(simd_border_values(x)));
			 }

			 static inline __m256i simd_next_lexrev(_In_ __m256i &x) {
				 // Return next word in subset-lexrev order.
				 // Start with a one-bit word at position n-1 to
				 // generate 2**n subsets of length n.
				 // E.g., for n==4 the subsets are
				 //     word   subset of {0,1,2,3}
				 //     1...   {0}
				 //     11..   {0, 1}
				 //     111.   {0, 1, 2}
				 //     1111   {0, 1, 2, 3}
				 //     11.1   {0, 1, 3}
				 //     1.1.   {0, 2}
				 //     1.11   {0, 2, 3}
				 //     1..1   {0, 3}
				 //     .1..   {1}
				 //     .11.   {1, 2}
				 //     .111   {1, 2, 3}
				 //     .1.1   {1, 3}
				 //     ..1.   {2}
				 //     ..11   {2, 3}
				 //     ...1   {3}
				 //     ....   {}
				 // Note (1): the first element of the subset corresponds
				 // to the highest set bit.  When interpreting the binary
				 // words via "bit(n)==element n" (as usual), the order
				 // would be:
				 //     1...           { 3 }
				 //     11..        { 2, 3 }
				 //     111.     { 1, 2, 3 }
				 //     1111  { 0, 1, 2, 3 }
				 //     11.1     { 0, 2, 3 }
				 //     1.1.        { 1, 3 }
				 //     1.11     { 0, 1, 3 }
				 //     1..1        { 0, 3 }
				 //     .1..           { 2 }
				 //     .11.        { 1, 2 }
				 //     .111     { 0, 1, 2 }
				 //     .1.1        { 0, 2 }
				 //     ..1.           { 1 }
				 //     ..11        { 0, 1 }
				 //     ...1           { 0 }
				 // Note (2): the lex order for the delta sets would simply
				 // be the counting order (of the words or reversed words
				 // depending on the interpretation as explained above).
				 __m256i ymm0 = _mm256_and_si256(x, simd_unary_minus(x)); // x0
				 if (_mm256_cmpneq_epi64_mask(ymm0, ONE)) {
					 ymm0 = _mm256_srli_epi64(ymm0,1);
					 x = _mm256_xor_si256(x,ymm0);
					 return (x);
				 }
				 else {
					 x = _mm256_xor_si256(x,ONE);
					 ymm0 = _mm256_and_si256(x, simd_unary_minus(x));
					 ymm0 = _mm256_srli_epi64(ymm0,1);
					 x = _mm256_sub_epi64(x,ymm0);
					 return (x);
				 }
			 }

			 static inline __m256i simd_prev_lexrev(_In_ __m256i &x) {
				 // Return previous word in subset-lexrev order.
				 // Start with zero and use 2**n calls
				 // generate 2**n subsets of length n.
				 // E.g., for n==4:
				 //  ....  =  0
				 //  ...1  =  1
				 //  ..11  =  3
				 //  ..1.  =  2
				 //  .1.1  =  5
				 //  .111  =  7
				 //  .11.  =  6
				 //  .1..  =  4
				 //  1..1  =  9
				 //  1.11  = 11
				 //  1.1.  = 10
				 //  11.1  = 13
				 //  1111  = 15
				 //  111.  = 14
				 //  11..  = 12
				 //  1...  =  8
				 //
				 __m256i ymm0 = _mm256_and_si256(x, simd_unary_minus(x));
				 if (_mm256_cmpneq_epi64_mask(_mm256_and_si256(x, 
										_mm256_slli_epi64(ymm0, 1)),ZERO)) {
					 x = _mm256_xor_si256(x,ymm0);
					 return (x);
				 }
				 else {
					 x = _mm256_add_epi64(x,ymm0);
					 x = _mm256_or_si256(x,ONE);
					 return (x);
				 }
			 }

			 static inline __m256i simd_negidx2lexrev(_In_  __m256i &k) {
				 //
				 //   k:  negidx2lexrev(k)
				 //   0:  .....
				 //   1:  ....1
				 //   2:  ...11
				 //   3:  ...1.
				 //   4:  ..1.1
				 //   5:  ..111
				 //   6:  ..11.
				 //   7:  ..1..
				 //   8:  .1..1
				 //   9:  .1.11
				 //  10:  .1.1.
				 //  11:  .11.1
				 //  12:  .1111
				 //  13:  .111.
				 //  14:  .11..
				 //  15:  .1...
				 //  16:  1...1
				 //
				 __m256i ymm0 = _mm256_set1_epi64x(0ULL); // z
				 __m256i ymm1 = simd_highest_one(k); // h
				 while (_mm256_cmpneq_epi64_mask(k, ZERO)) {
					 while (_mm256_cmpeq_epi64_mask(ZERO, _mm256_and_si256(ymm1,k)))
						 ymm1 = _mm256_srli_epi64(ymm1,1);
					 ymm0 = _mm256_xor_si256(ymm0,ymm1);
					 k = simd_inc(k);
					 k = _mm256_and_si256(k,_mm256_sub_epi64(ymm1,ONE));
				 }
				 return (ymm0);
			 }

			 static inline __m256i simd_lexrev2negidx(_In_ __m256i &x) {
				 // inverse of negidx2lexrev()
				 if (_mm256_cmpeq_epi64_mask(x,ZERO))
					 return (_mm256_set1_epi64x(0ULL));
				 __m256i ymm0 = _mm256_and_si256(x, simd_not(x)); //h
				 __m256i ymm1 = _mm256_sub_epi64(ymm0,ONE); // r
				 while (_mm256_cmpneq_epi64_mask(x = _mm256_xor_si256(x, ymm0), ZERO)) {
					 ymm1 = _mm256_add_epi64(ymm1, _mm256_sub_epi64(ymm0,ONE));
					 ymm0 = _mm256_and_si256(ymm0, simd_unary_minus(x));
				 }
				 ymm1 = _mm256_add_epi64(ymm1,ymm0);
				 return (ymm1);
			 }

			 static inline __m256i simd_lowest_one_idx(_In_ __m256i &x) {
				 // Return index of lowest bit set.
				 // Bit index ranges from zero to BITS_PER_LONG-1.
				 // Examples:
				 //    ***1 --> 0
				 //    **10 --> 1
				 //    *100 --> 2
				 // Return 0 (also) if no bit is set.
				 __m256i ymm0 = _mm256_set1_epi64x(0ULL); // r
				 x = _mm256_and_si256(x, simd_unary_minus(x)); // 
				 const __m256i mask1 = _mm256_and_si256(x, _mm256_set1_epi64x(0xffffffff00000000UL));
				 const __m256i mask2 = _mm256_and_si256(x, _mm256_set1_epi64x(0xffff0000ffff0000UL));
				 const __m256i mask3 = _mm256_and_si256(x, _mm256_set1_epi64x(0xff00ff00ff00ff00UL));
				 const __m256i mask4 = _mm256_and_si256(x, _mm256_set1_epi64x(0xf0f0f0f0f0f0f0f0UL));
				 const __m256i mask5 = _mm256_and_si256(x, _mm256_set1_epi64x(0xccccccccccccccccUL));
				 const __m256i mask6 = _mm256_and_si256(x, _mm256_set1_epi64x(0xaaaaaaaaaaaaaaaaUL));
				 ymm0 = _mm256_or_si256(ymm0,_mm256_cmpgt_epi64(mask1,ZERO));
				 ymm0 = _mm256_slli_epi64(ymm0,1);
				 ymm0 = _mm256_or_si256(ymm0, _mm256_cmpgt_epi64(mask2, ZERO));
				 ymm0 = _mm256_slli_epi64(ymm0, 1);
				 ymm0 = _mm256_or_si256(ymm0, _mm256_cmpgt_epi64(mask3, ZERO));
				 ymm0 = _mm256_slli_epi64(ymm0, 1);
				 ymm0 = _mm256_or_si256(ymm0, _mm256_cmpgt_epi64(mask4, ZERO));
				 ymm0 = _mm256_slli_epi64(ymm0, 1);
				 ymm0 = _mm256_or_si256(ymm0, _mm256_cmpgt_epi64(mask5, ZERO));
				 ymm0 = _mm256_slli_epi64(ymm0, 1);
				 ymm0 = _mm256_or_si256(ymm0, _mm256_cmpgt_epi64(mask6, ZERO));
				 ymm0 = _mm256_slli_epi64(ymm0, 1);
				 return (ymm0);
			 }

			 static inline __m256i simd_lowest_one_idx_parity(_In_ __m256i &x) {
				 // Return the parity of the index of the lowest set bit.
				 // Return zero with x=0.
				 // Sequence for x>=0 (OEIS sequence A096268):
				 // 0,0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,...
				 x = _mm256_and_si256(x, simd_unary_minus(x));
				 return (_mm256_cmpgt_epi64(ZERO, _mm256_and_si256(x,
						 _mm256_set1_epi64x(0xaaaaaaaaaaaaaaaaUL))));
			 }

			 static inline __m256i simd_lowest_one(_In_ const __m256i &x) {
				 // Return word where only the lowest set bit in x is set.
				 // Return 0 if no bit is set.
				 return (_mm256_and_si256(x, simd_unary_minus(x)));
			 }

			 static inline __m256i simd_lowest_zero(_In_ __m256i &x) {
				// Return word where only the lowest unset bit in x is set.
				// Return 0 if all bits are set.
				 x = simd_not(x);
				 return (simd_lowest_one(x));
			 }

			 static inline __m256i simd_lowest_block(_In_ __m256i &x) {
				 // Isolate lowest block of ones.
				 __m256i ymm0 = simd_lowest_one(x); // l
				 __m256i ymm1 = _mm256_and_si256(_mm256_add_epi64(ymm0,x),x);
				 return (_mm256_xor_si256(ymm1,x));
			 }

			 static inline __m256i simd_clear_lowest_one(_In_ const __m256i &x) {
				 // Return word where the lowest bit set in x is cleared.
				 // Return 0 for input == 0.
				 return (_mm256_and_si256(x, _mm256_sub_epi64(x,ONE)));
			 }

			 static inline __m256i simd_set_lowest_zero(_In_ __m256i &x) {
				 // Return word where the lowest unset bit in x is set.
				 // Return ~0 for input == ~0.
				 return (_mm256_or_si256(x, _mm256_add_epi64(x,ONE)));
			 }

			 static inline __m256i simd_low_ones(_In_ __m256i &x) {
				 // Return word where all the (low end) ones are set.
				 // Example:  01011011 --> 00000011
				 // Return 0 if lowest bit is zero:
				 //       10110110 --> 0
				 x = simd_not(x);
				 x = _mm256_and_si256(x, simd_unary_minus(x));
				 x = simd_dec(x);
				 return (x);
			 }

			 static inline __m256i simd_low_zeroes(_In_ __m256i &x) {
				 // Return word where all the (low end) zeros are set.
				 // Example:  01011000 --> 00000111
				 // Return 0 if all bits are set.
				 x = _mm256_and_si256(x, simd_unary_minus(x));
				 x = simd_dec(x);
				 return (x);
			 }

			 static inline __m256i simd_low_match(_In_ __m256i &x,
												  _In_ const __m256i &y) {
				 // Return word that contains all bits at the low end where x and y match.
				 // If x = *0W and y = *1W, then 00W is returned.
				 x = _mm256_xor_si256(x,y); // bit-wise difference
				 x = _mm256_and_si256(x, simd_unary_minus(x)); // lowest bit that differs in both words
				 x = simd_dec(x); // mask that covers equal bits at low end
				 x = _mm256_and_si256(x,y); // isolate matching bits
				 return (x);
			 }

			 static inline __m256i simd_bit_separate(_In_ __m256i &w,
												     _In_ __m256i &m,
												     _In_ __m256i &s = _mm256_div_epu64(BITS_PER_LONG_64, TWO)){
				 // Return  word with bits of w separated as indicated by m.
				 // Bits at positions where m is 0/1 are moved to the low/high end.
				 // Examples:
				 //  w = ABCDEFGH
				 //  m = 00111100
				 //  ==> CDEFABGH
				 //
				 //  w = ABCDEFGH
				 //  m = 01010101
				 //  ==> BDFHACEG
				 //
				 // s must contain the number of ones set in m.
				 // For the default s exactly half of the bits must be set in m
				 __m256i ymm0 = simd_bit_gather(w, simd_not(m));
				 __m256i ymm1 = simd_bit_gather(w,m);
				 return (_mm256_xor_si256(ymm0, _mm256_sllv_epi64(ymm1,s)));
			 }

			 static inline __m256i simd_bit_separate_subwords(_In_ __m256i &w,
															  _In_ __m256i &m,
															  _In_ __m256i &s) {
				 // Bit-separate all length-s subwords of w.
				 // s>=2 must divide BITS_PER_LONG.
				 // The mask must be such that exactly half of the bits
				 //   in each subword are set.
				 // Examples:
				 //  s = 4
				 //  w = ABCD EFGH
				 //  m = 0011 1010
				 //  ==> CDAB EGFH
				 //
				 //  s = 2
				 //  w = AB CD EF GH
				 //  m = 01 10 01 10
				 //  ==> BA CD FE GH
				 //
				 // For s==BITS_PER_LONG the result is as with bit_separate(w, m)
				 //  if half of the bits of m are set.
				 __m256i ymm0 = _mm256_srlv_epi32(simd_not(ZERO), _mm256_sub_epi64(BITS_PER_LONG_64,s)); // sub word mask
				 ymm0 = _mm256_sllv_epi64(ymm0, _mm256_sub_epi64(BITS_PER_LONG_64,s)); // at high end
				 __m256i ymm1 = _mm256_div_epu64(s,TWO); // h
				 __m256i ymm2 = _mm256_set1_epi64x(0ULL); // a
				 do {
					 ymm2 = _mm256_sllv_epi64(ymm2,s);
					 __m256i ymm3 = _mm256_and_si256(m,ymm0);
					 __m256i ymm4 = _mm256_xor_si256(ymm3,ymm0);
					 __m256i ymm5 = simd_bit_gather(w,ymm4);
					 __m256i ymm6 = simd_bit_gather(w,ymm3);
					 ymm2 = _mm256_or_si256(ymm2, _mm256_xor_si256(ymm5, _mm256_sllv_epi64(ymm6,ymm1)));
					 ymm0 = _mm256_srlv_epi64(ymm0,s);
				 }
				 while (_mm256_cmpgt_epi64_mask(ymm0,ZERO));
				 return (ymm2);
			 }

			 static inline __m256i simd_next(_In_ __m256i &u,
											 _In_ const __m256i &v) {
				 u = _mm256_and_si256(_mm256_sub_epi64(u,v),v);
				 return (u);
			 }

			 static inline __m256i simd_prev(_In_ __m256i &u,
											 _In_ const __m256i &v) {
				 u = _mm256_and_si256(simd_dec(u),v);
				 return (u);
			 }

			 static inline __m256i simd_compliment(_In_  __m256i &u,
												   _In_ const __m256i &v) {
				 u = _mm256_xor_si256(u,v);
				 return (u);
			 }

			 static inline void simd_zorder_next(_Inout_ __m256i &x,
												 _Inout_ __m256i &y) {
				 __m256i ymm0 = _mm256_set1_epi64x(1ULL); //b
				 do {
					 x = _mm256_xor_si256(x,ymm0);
					 ymm0 = _mm256_and_si256(ymm0, simd_not(x));
					 y = _mm256_xor_si256(y,ymm0);
					 ymm0 = _mm256_and_si256(ymm0, simd_not(y));
					 ymm0 = _mm256_slli_epi64(ymm0,1);
				 }
				 while (_mm256_cmpneq_epu64_mask(ymm0,ZERO));
			 }

			 static inline void simd_zorder_prev(_Inout_ __m256i &x,
												 _Inout_ __m256i &y) {
				 __m256i ymm0 = _mm256_set1_epi64x(1ULL);
				 do {
				      x = _mm256_xor_si256(x, ymm0);
				      ymm0 = _mm256_and_si256(ymm0, x);
				      y = _mm256_xor_si256(y, ymm0);
				      ymm0 = _mm256_and_si256(ymm0, y);
				      ymm0 = _mm256_slli_epi64(ymm0, 1);
				}
				while (_mm256_cmpneq_epu64_mask(ymm0,ZERO));
			 }

			 static inline void simd_zorder3_next(_Inout_ __m256i &x,
												  _Inout_ __m256i &y,
												  _Inout_ __m256i &z) {
				 __m256i ymm0 = _mm256_set1_epi64x(1ULL);
				 do {
					 x = _mm256_xor_si256(x,ymm0);
					 ymm0 = _mm256_and_si256(ymm0, simd_not(x));
					 y = _mm256_xor_si256(y,ymm0);
					 ymm0 = _mm256_and_si256(ymm0, simd_not(y));
					 z = _mm256_xor_si256(z,ymm0);
					 ymm0 = _mm256_and_si256(ymm0, simd_not(z));
					 ymm0 = _mm256_slli_epi64(ymm0,1);
				 }
				 while (_mm256_cmpneq_epu64_mask(ymm0,ZERO));
			 }

			 static inline void simd_zorder3_prev(_Inout_ __m256i &x,
												  _Inout_ __m256i &y,
												  _Inout_ __m256i &z) {
				 __m256i ymm0 = _mm256_set1_epi64x(1ULL);
				 do {
					 x = _mm256_xor_si256(x, ymm0);
					 ymm0 = _mm256_and_si256(ymm0, x);
					 y = _mm256_xor_si256(y, ymm0);
					 ymm0 = _mm256_and_si256(ymm0,y);
					 z = _mm256_xor_si256(z, ymm0);
					 ymm0 = _mm256_and_si256(ymm0,z);
					 ymm0 = _mm256_slli_epi64(ymm0, 1);
				 } while (_mm256_cmpneq_epu64_mask(ymm0, ZERO));
			 }
			
			 static inline __m256i simd_bit_zip(_In_ __m256i &x) {
				 // Return word with lower half bits in even indices
				 //  and upper half bits in odd indices.
				 x = simd_butterfly_16(x);
				 x = simd_butterfly_8(x);
				 x = simd_butterfly_4(x);
				 x = simd_butterfly_2(x);
				 x = simd_butterfly_1(x);
				 return (x);
				 }
			 
			 static inline __m256i simd_bit_unzip(_In_ __m256i &x) {
				 // Return word with even indexed bits in lower half
				 //  and odd indexed bits in upper half.
				 // Inverse of bit_zip()
				 x = simd_butterfly_1(x);
				 x = simd_butterfly_2(x);
				 x = simd_butterfly_4(x);
				 x = simd_butterfly_8(x);
				 x = simd_butterfly_16(x);
				 return (x);
			 }

			 static inline __m256i simd_bit_zip0(_In_ __m256i &x) {
				 // Return word with lower half bits in even indices.
				 // upper half must be zero.
				 // Same effect as bit_zip() but faster.
				 // 0000abcd --> 0a0b0c0d (a,b,c,d are bits).
				 x = _mm256_and_si256(_mm256_or_si256(x, _mm256_slli_epi64(x,16)),MASK_SHL16);
				 x = _mm256_and_si256(_mm256_or_si256(x, _mm256_slli_epi64(x, 8)),MASK_SHL8);
				 x = _mm256_and_si256(_mm256_or_si256(x, _mm256_slli_epi64(x, 4)),MASK_SHL4);
				 x = _mm256_and_si256(_mm256_or_si256(x, _mm256_slli_epi64(x, 2)),MASK_SHL2);
				 x = _mm256_and_si256(_mm256_or_si256(x, _mm256_slli_epi64(x, 1)),MASK_SHL1);
				 return (x);
			 }

			 static inline __m256i simd_bit_unzip0(_In_ __m256i &x) {
				 // Gather bits in even positions into lower half.
				 // Inverse of bit_zip0().
				 // Bits at odd positions must be zero.
				 // 0a0b0c0d --> 0000abcd (a,b,c,d are bits).
				 x = _mm256_and_si256(_mm256_or_si256(x, _mm256_slli_epi64(x, 1)), MASK_SHL1);
				 x = _mm256_and_si256(_mm256_or_si256(x, _mm256_slli_epi64(x, 2)), MASK_SHL2);
				 x = _mm256_and_si256(_mm256_or_si256(x, _mm256_slli_epi64(x, 4)), MASK_SHL4);
				 x = _mm256_and_si256(_mm256_or_si256(x, _mm256_slli_epi64(x, 8)), MASK_SHL8);
				 x = _mm256_and_si256(_mm256_or_si256(x, _mm256_slli_epi64(x, 16)), MASK_SHL16);
				 return (x);
			 }

			 static inline void simd_bit_zip2(_In_ __m256i &x, 
											  _Inout_ __m256i &lo,
											  _Inout_ __m256i &hi) {
				 // Bits of lower half word spread out into even positions of lo,
				 // bits of upper half word spread out into even positions of hi.
				 x = simd_bit_zip(x);
				 lo = _mm256_and_si256(x, _mm256_set1_epi64x(0x5555555555555555UL));
				 hi = _mm256_and_si256(_mm256_srli_epi64(x, 1), _mm256_set1_epi64x(0x5555555555555555UL));
			 }

			 static inline __m256i simd_bit_unzip2(_In_ __m256i &lo,
												   _In_ __m256i &hi) {
				 return (simd_bit_zip(_mm256_or_si256(_mm256_slli_epi64(hi,1),lo)));
			 }

			 static inline __m256i simd_contains_zero_byte(_In_ __m256i &x) {
				 // Determine if any sub-byte of x is zero:
				 // Return zero when x contains no zero-byte and nonzero when it does.
				 //
				 // To scan for other values than zero (e.g. 0xa5) use:
				 //  contains_zero_byte( x ^ 0xa5a5a5a5UL )
				 const __m256i mask1 = _mm256_set1_epi64x(0x8080808080808080UL);
				 const __m256i mask2 = _mm256_set1_epi64x(0x0101010101010101UL);
				 return (_mm256_and_si256(mask1, _mm256_and_si256(_mm256_sub_epi64(x, mask2), simd_not(x))));
			 }

			 static inline __m256i simd_gray_code(_In_ const __m256i &x) {
				 // Return the Gray code of x
				 // ('bit-wise derivative modulo 2')
				 return (_mm256_xor_si256(x, _mm256_srli_epi64(x,1)));
			 }

			 static inline __m256i simd_inverse_gray_code(_In_ __m256i &x) {
				 // inverse of gray_code()
				 // note: the returned value contains at each bit position
				 // the parity of all bits of the input left from it (incl. itself)
				 //
				 x = _mm256_xor_si256(x, _mm256_srli_epi64(x,1));
				 x = _mm256_xor_si256(x, _mm256_srli_epi64(x,2));
				 x = _mm256_xor_si256(x, _mm256_srli_epi64(x,4));
				 x = _mm256_xor_si256(x, _mm256_srli_epi64(x,8));
				 x = _mm256_xor_si256(x, _mm256_srli_epi64(x,16));
				 x = _mm256_xor_si256(x, _mm256_srli_epi64(x,32));
			 }

			 static inline __m256i simd_byte_gray_code(_In_ const __m256i &x) {
				 // Return the Gray code of bytes in parallel
				 const __m256i mask = _mm256_set1_epi64x(0xfefefefefefefefeUL);
				 return (_mm256_xor_si256(x, _mm256_srli_epi64(_mm256_and_si256(x,mask),1)));
			 }

			 static inline __m256i simd_byte_inverse_gray_code(_In_ __m256i &x) {
				 // Return the inverse Gray code of bytes in parallel
				 const __m256i mask1 = _mm256_set1_epi64x(0xfefefefefefefefeUL);
				 const __m256i mask2 = _mm256_set1_epi64x(0xfcfcfcfcfcfcfcfcUL);
				 const __m256i mask3 = _mm256_set1_epi64x(0xf0f0f0f0f0f0f0f0UL);
				 x = _mm256_xor_si256(x,_mm256_srli_epi64(_mm256_and_si256(x,mask1),1));
				 x = _mm256_xor_si256(x, _mm256_srli_epi64(_mm256_and_si256(x,mask2),2));
				 x = _mm256_xor_si256(x, _mm256_srli_epi64(_mm256_and_si256(x,mask3),3));
				 return (x);
			 }

			 static inline __m256i simd_bin_to_radm4(_In_ __m256i &x) {
				 // binary --> radix(-4)
				 x = _mm256_add_epi64(x,MASK_RADIX4);
				 x = _mm256_and_si256(x,MASK_RADIX4);
				 return (x);
			 }

			 static inline __m256i simd_radm4_to_bin(_In_ __m256i &x) {
				 // radix(-4) --> binary
				 // inverse of bin_to_radm4()
				 x = _mm256_xor_si256(x,MASK_RADIX4);
				 x = _mm256_sub_epi64(x,MASK_RADIX4);
				 return (x);
			 }

			 static inline __m256i simd_next_radm4(_In_ __m256i &x) {
				 // With x the radix(-4) representation of n
				 // return radix(-4) representation of n+1.
				 x = _mm256_xor_si256(x,MASK_RADIX4);
				 x = simd_inc(x);
				 x = _mm256_xor_si256(x,MASK_RADIX4);
				 return (x);
			 }

			 static inline __m256i simd_prev_radm4(_In_ __m256i &x) {
				 // With x the radix(-4) representation of n
				 // return radix(-4) representation of n-1.
				 x = _mm256_xor_si256(x,MASK_RADIX4);
				 x = simd_dec(x);
				 x = _mm256_xor_si256(x,MASK_RADIX4);
				 return (x);
			 }

			 static inline __m256i simd_radm_add(_In_ __m256i &a,
											     _In_ __m256i &b) {
				 return (_mm256_add_epi64(simd_radm4_to_bin(a), simd_radm4_to_bin(b)));
			 }

		};
		
	}
}

#endif /*__LAM_AVXBITSETS_H__*/
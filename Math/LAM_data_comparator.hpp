
#ifndef __LAM_DATA_COMPARATOR_HPP__
#define __LAM_DATA_COMPARATOR_HPP__

// File version global constants

const unsigned int gLAM_DATA_COMPARATOR_MAJOR = 1U;

const unsigned int gLAM_DATA_COMPARATOR_MINOR = 0U;

const unsigned int gLAM_DATA_COMPARATOR_MICRO = 0U;

const unsigned int gLAM_DATA_COMPARATOR_FULLVER = 
	1000U*gLAM_DATA_COMPARATOR_MAJOR + 100U*gLAM_DATA_COMPARATOR_MINOR + 10U * gLAM_DATA_COMPARATOR_MICRO;

const char * const pgLAM_DATA_COMPARATOR_CREATE_DATE = "03-09-2018 15:07 +00200 (MON 03 SEP 2018 GMT+2)";

const char * const pgLAM_DATA_COMPARATOR_BUILD_DATE = "00-00-0000 00:00";

const char * const pgLAM_DATA_COMPARATOR_AUTHOR = "Programmer: Bernard Gingold, contact: beniekg@gmail.com";

const char * const pgLAM_DATA_COMPARATOR_SYNOPSIS = " Primitive types comparator classes.";

#include <type_traits>
#include <memory>
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cstdint>
#include "../LAM_indices.h"

namespace lam {
	namespace math {

#if !defined (LAM_DATA_COMPARATOR_TEST_FAIL)
#define LAM_DATA_COMPARATOR_TEST_FAIL(msg1,msg2)													    \
	std::cout << m_msg << "\n"																			\
			  << msg1  << "\n"																			\
			  << msg2 << "\n";																			\
    std::cout << "m_x: " << m_x << "!=" << "m_y: " << m_y << "\n"										\
	          << "at:  " << m_filename << ":" << m_loc << "(" << "0x"<< m_funaddr.c_str()<< ")" << "\n";
#endif

#if !defined (VEC1D_ACCESSOR1D)
#define VEC1D_ACCESSOR1D(vec,indx) \
	(vec).operator->()->operator[]((indx))
#endif
	
#if !defined (VEC1D_MAKE_RESULT)
#define VEC1D_MAKE_RESULT(vec1,vec2,indx)		     \
	std::make_pair((vec1).operator->()->operator[]((indx)),  \
				   (vec2).operator->()->operator[]((indx))); 
#endif	

#if !defined (VEC2D_ACCESSOR2D)
#define VEC2D_ACCESSOR2D(vec,i,nj,j) \
		(vec).operator->()->operator[]((i)*(nj)+(j))
#endif

#if !defined (VEC2D_MAKE_RESULT)
#define VEC2D_MAKE_RESULT(vec1,vec2,i,nj,j)               \
	std::make_pair((vec1).operator->()->operator[]((i)*(nj)+(j)), \
				   (vec2).operator->()->operator[]((i)+(nj)+(j)));
#endif

#if !defined (FPCOMPARE_CTOR_BLOCK)
#define FPCOMPARE_CTOR_BLOCK         \
	        m_loc{ loc },            \
		    m_x{ x },			     \
			m_y{ y },			     \
			m_fuzz32{ fuzz32 },      \
			m_fuzz64{ fuzz64 },      \
			m_eps{ eps },            \
			m_msg{ pmsg },           \
			m_funcaddr{ pfuncaddr }, \
			m_filename{ pfilename }
#endif

#if !defined (FPCOMPVEC1D_CTOR_BLOCK)
#define FPCOMPVEC1D_CTOR_BLOCK                                               \
	        m_loc{ loc },											         \
		    m_vlen{ vlen },												     \
			m_eps{ eps },												     \
			m_dist{ dist },										             \
			m_fuzz32{ fuzz32 },											     \
			m_fuzz64{ fuzz64 },											     \
			m_msg{ pmsg },												     \
			m_funcaddr{ pfuncaddr },									     \
			m_filename{ pfilename },									     \
			m_vx(new std::vector<Real_t>(vx)),							     \
			m_vy(new std::vector<Real_t>(vy)),							     \
			m_vabser(new std::vector<std::pair<Real_t, Real_t>>(m_vlen)),    \
			m_vreler(new std::vector<std::pair<Real_t, Real_t>>(m_vlen)),    \
			m_vfuzz32er(new std::vector<std::pair<Real_t, Real_t>>(m_vlen)), \
			m_vfuzz64er(new std::vector<std::pair<Real_t, Real_t>>(m_vlen))
#endif	

#if !defined (FPCOMPVEC2D_CTOR_BLOCK)
#define FPCOMPVEC2D_CTOR_BLOCK														\
			m_loc{ loc },														    \
			m_vleni{ vleni },													    \
			m_vlenj{ vlenj },														\
			m_fuzz32{ fuzz32 },												        \
			m_fuzz64{ fuzz64 },														\
			m_dist{ dist },															\
			m_eps{ eps },															\
			m_msg{ pmsg },														    \
			m_funcaddr{ pfuncadr },												    \
			m_filename{ pfilename },												\
			m_vx(new std::vector<Real_t>(vx)),										\
			m_vy(new std::vector<Real_t>(vy)),										\
			m_vabser(new std::vector<std::pair<Real_t, Real_t>>(m_vleni*m_vlenj)),	\
			m_vreler(new std::vector<std::pair<Real_t, Real_t>>(m_vleni*m_vlenj)),	\
			m_vfuzz32(new std::vector<std::pair<Real_t, Real_t>>(m_vleni*m_vlenj)),	\
			m_vfuzz64(new std::vector<std::pair<Real_t, Real_t>>(m_vleni*m_vlenj))
#endif


		

		/***************************************************
			Helper class for computing ulp differrence.
		*****************************************************/
		template<typename Real_t> struct UlpDiff {

				

			static Real_t ulp_diff(_In_ const Real_t value,
								   _In_ Real_t reference) {
				if (value == reference || std::isnan(value) && std::isnan(reference)){
					return (static_cast<Real_t>(0));
				}
				if (reference == Real_t(0)) {
					return (static_cast<Real_t>(static_cast<Real_t>(1.0) + ulp_diff(std::abs(value),
						std::numeric_limits<Real_t>::min())));
				}
				if (value == Real_t(0)) {
					return (static_cast<Real_t>(static_cast<Real_t>(1.0) + ulp_diff(
						std::numeric_limits<Real_t>::min(), std::abs(reference))));
				}
				int exponent;
				frexp(reference,&exponent);
				return static_cast<Real_t>(ldexp(std::abs(reference-value), std::numeric_limits<Real_t>::digits-exponent));
			}

			static Real_t ulp_diff_signed(_In_ const Real_t value,
										  _In_ const Real_t reference) {
				return (static_cast<Real_t>(ulp_diff(value, reference) * (value - reference < static_cast<Real_t>(0) ? -1 : 1)));
			}
		};

		// Helpers


		/*
			@Purpose:
						Scalar integral comparator object.
		*/

		template<typename T1,
				 typename T2,
				 typename =  std::enable_if<std::is_integral<T1>::value &&
					         std::is_integral<T2>::value &&
							 std::is_same<T1, T2>::value>::type>  struct IntCompare {
				
				using Pmf = bool(IntCompare::*)();

				
				
				T1            m_x;

				T2            m_y;

				int32_t       m_loc;

				std::string   m_msg;

				std::wstring  m_funaddr;

				std::string   m_filename;

				

				IntCompare() = default;

				IntCompare(_In_ const T1 x,
					_In_ const T2 y,
					_In_ const int32_t loc,
					_In_ const std::string  & msg,
					_In_ const std::wstring & funaddr,
					_In_ const std::string  & filename)
					:
					m_x{ x },
					m_y{ y },
					m_loc{ loc },
					m_msg{ msg },
					m_funaddr{ funaddr },
					m_filename{ filename }
				{}

				~IntCompare() = default;

				// No copy && no move
				IntCompare(_In_ const IntCompare &) = delete;

				IntCompare(_In_ IntCompare &&) = delete;

				IntCompare & operator=(_In_ const IntCompare &) = delete;

				IntCompare & operator=(_In_ IntCompare &&) = delete;

				// Must not be const because of pointer to member func call.
				bool  compare_equality() {
					using namespace std;
					if (m_x != m_y) {
						LAM_DATA_COMPARATOR_TEST_FAIL("FAIL: Equality test!!", "Values are not equal.")
						return (true);
					}
					else {
						return (false);
					}
				}

				//	Must not be const because of pointer to member func call.
				bool compare_inequality() {
					using namespace std;
					if (m_x == m_y) {
						LAM_DATA_COMPARATOR_TEST_FAIL("Fail: Inequality test!!", "Values are equal.")
						return (true);
					}
					else {
						return (false);
					}
				}

				// Must not be const because of pointer to member func call.
				bool compare_lt() {
					using namespace std;
					if (m_x > m_y) {
						LAM_DATA_COMPARATOR_TEST_FAIL("FAIL: Less than test!!", "x value is greater.")
							return (true);
					}
					else {
						return (false);
					}
				}

				// Must not be const because of pointer to member func call.
				bool compare_gt() {
					 using namespace std;
					if (m_x < m_y) {
						LAM_DATA_COMPARATOR_TEST_FAIL("FAIL: Greater than test!!", "x value is smaller.")
							return (true);
					}
					else {
						return (false);
					}
				}

				const std::string obj_type() const { return (std::string{ typeid(*this).name() }); }

		};

		/*
			 @Purpose:
					     Array1D integral comparator object.
	    */
		template<typename Datum_t,
			    typename = std::enable_if<std::is_integral<Datum_t>
									   	::value>::type> struct IntCompVec1D {
					
					using SPDatum   = std::unique_ptr<std::vector<Datum_t>>;
					using SPResults = std::unique_ptr<std::vector<std::pair<Datum_t, Datum_t>>>;
					using Pmf	    = void(IntCompVec1D::*)(void);

					int32_t           m_loc;

					std::size_t       m_lenx;

					std::size_t       m_leny;

					SPDatum           m_vx;

					SPDatum           m_vy;

					SPResults	      m_veq;

					SPResults		  m_vineq;

					SPResults	      m_vgt;

					SPResults		  m_vlt;

					std::string       m_msg;

					std::wstring      m_funaddr;

					std::string       m_filename;

					IntCompVec1D() noexcept(false)
					 :
					 m_loc{},
					 m_lenx{},
					 m_leny{},
					 m_vx{ nullptr },
					 m_vy{ nullptr },
					 m_veq{ nullptr },
					 m_vineq{ nullptr },
					 m_vgt{ nullptr },
					 m_vlt{ nullptr },
					 m_msg{},
					 m_funaddr{},
					 m_filename
					{}

					IntCompVec1D(_In_ const int32_t loc,
						
						_In_  std::vector<Datum_t> &vdatax,
						_In_  std::vector<Datum_t> &vdatay,
						_In_ const char * msg,
						_In_ const char * funaddr,
						_In_ const char * filename) noexcept(false)
						:
						m_loc{ loc },
						m_lenx{ vdatax.size() },
						m_leny{ vdatay.size() },
						m_vx{ new std::vector<Datum_t>(vdatax) },
						m_vy{ new std::vector<Datum_t>(vdatay) },
						m_veq{ new std::vector<std::pair<Datum_t, Datum_t>>(m_lenx) },
						m_vineq{ new std::vector<std::pair<Datum_t, Datum_t>>(m_lenx) },
						m_vgt{ new std::vector<std::pair<Datum_t, Datum_t>>(m_lenx) },
						m_vlt{ new std::vector<std::pair<Datum_t, Datum_t>>(m_lenx) },
						m_msg{ msg },
						m_funaddr{ funaddr },
						m_filename{ filename }
					{
						_ASSERT(m_lenx == m_leny); // Break in debugger on failure
					}

					IntCompVec1D(_In_ const IntComVec1D &) = delete;

					IntCompVec1D(_In_ IntCompVec1D &&) = delete;

					IntCompVec1D & operator=(_In_ const IntCompVec1D &) = delete;

					IntCompVec1D & operator=(_In_ IntCompVec1D &&) = delete;

					// m_vx is a copy of actual array
					// m_vy is a copy of expected array.
					void  compare_equality() {
						using namespace std;
						for (std::size_t i = 0Ui64; i != m_lenx; ++i) {
							if (VEC1D_ACCESSOR1D(m_vx,i) !=
								VEC1D_ACCESSOR1D(m_vy,i)) {
								std::cout << m_msg.data()            <<  "\n"
									      << "FAIL: Equality test!!" <<  "\n" 
										  << "Values are not equal." <<  "\n"
										  << "at index: " << i << "\n"
										  << "at " << m_filename << ":" << m_loc << "(" << "0x" << m_funaddr.data() << ")" << "\n";
								VEC1D_ACCESSOR1D(m_veq, i) = VEC1D_MAKE_RESULT(m_vx, m_vy, i)
								 // load inequal value pairs
								
							}
							else {
								INTCOMP_VEC1D_ACCESSOR1D(m_veq, i) = INTCOMP_VEC1D_MAKE_RESULT(m_vx,m_vy,i)
							}
						}
					}

					// m_vx is a copy of actual array
					// m_vy is a copy of expected array.
					void compare_inequality() {
						using namespace std;
						for (std::size_t i = 0Ui64; i != m_lenx; ++i) {
							if (VEC1D_ACCESSOR1D(m_vx, i) ==
								VEC1D_ACCESSOR1D(m_vy, i)) {
								std::cout << m_msg.data()                     << "\n"
									      << "Fail: Inequality test!!"        << "\n"
										  << "Values are equal." << "\n"
										  << "at index: " << i << "\n"
										  << "at " << m_filename << ":" << m_loc << "(" << "0x" << m_funaddr.data() << ")" << "\n";
								VEC1D_ACCESSOR1D(m_vineq, i) = VEC1D_MAKE_RESULT(m_vx,m_vy,i)
							}
							else {
								VEC1D_ACCESSOR1D(m_vineq, i) = VEC1D_MAKE_RESULT(m_vx,m_vy,i)
							}
						}
					}

					// m_vx is a copy of actual array
					// m_vy is a copy of expected array.
					void compare_lt() {
						using namespace std;
						for (std::size_t i = 0Ui64; i != m_lenx; ++i) {
							if (VEC1D_ACCESSOR1D(m_vx, i) >
								VEC1D_ACCESSOR1D(m_vy, i)) {
								std::cout << m_msg.data() << "\n"
									      << "Fail: Less than test!!" << "\n"
									      << "m_vx contained value is greater." << "\n"
									      << "at index: " << i << "\n"
									      << "at " << m_filename << ":" << m_loc << "(" << "0x" << m_funaddr.data() << ")" << "\n";
								VEC1D_ACCESSOR1D(m_vlt, i) = VEC1D_MAKE_RESULT(m_vx,m_vy,i)
							}
							else {
								VEC1D_ACCESSOR1D(m_vlt, i) = VEC1D_MAKE_RESULT(m_vx,m_vy,i)
							}
						}
					}

					// m_vx is a copy of actual array
					// m_vy is a copy of expected array.
					void compare_gt() {
						using namespace std;
						for (std::size_t i = 0Ui64; i != m_lenx; ++i) {
							if (VEC1D_ACCESSOR1D(m_vx, i) <
								VEC1D_ACCESSOR1D(m_vy, i)) {
								std::cout << m_msg.data() << "\n"
									      << "Fail: Less than test!!" << "\n"
									      << "m_vx contained value is smaller." << "\n"
									      << "at index: " << i << "\n"
									      << "at " << m_filename << ":" << m_loc << "(" << "0x" << m_funaddr.data() << ")" << "\n";
								VEC1D_ACCESSOR1D(m_vgt, i) = VEC1D_MAKE_RESULT(m_vx,m_vy,i)
							}
							else {
								VEC1D_ACCESSOR1D(m_vgt, i) = VEC1D_MAKE_RESULT(m_vx,m_vy,i)
							}
						}
					}

		};

		/********************************************
		Array2D integral comparison object.
		*********************************************/
		template<typename Datum_t,
			 typename = std::enable_if<
					std::is_integral<Datum_t>::value>::type> struct IntCompVec2D {

					using SPDatum2D   = std::unique_ptr<std::vector<Datum_t>>;
					using SPResults2D = std::unique_ptr<std::vector<std::pair<Datum_t,Datum_t>>>;
					using Pmf		  = void(IntCompVec2D::*)(void);

					int32_t     m_loc;

					std::size_t m_lenx;

					std::size_t m_leny;

					std::string m_msg;

					std::wstring m_funaddr;

					std::string  m_filename;

					SPDatum2D    m_vx;

					SPDatum2D    m_vy;

					SPResults2D  m_veq;

					SPResults2D  m_vineq;

					SPResults2D  m_vlt;

					SPResults2D  m_vgt;

					IntCompVec2D() noexcept(false)
						:
						m_loc{},
						m_lenx{},
						m_leny{},
						m_msg{},
						m_funaddr{},
						m_filename{},
						m_vx(nullptr),
						m_vy(nullptr),
						m_veq(nullptr),
						m_vineq(nullptr),
						m_vlt(nullptr),
						m_vgt(nullptr)
					{}

					IntCompVec2D(_In_ const int32_t loc,
								 _In_ const std::size_t lenx,
								 _In_ const std::size_t leny,
								 _In_ const char * pmsg,
								 _In_ const char * pfunaddr,
								 _In_ const char * pfilename,
								 _In_ const std::vector<Datum_t> &vx,
								 _In_ const std::vector<Datum_t> &vy) noexcept(false)
						:
						m_loc{ loc },
						m_lenx{ lenx },
						m_leny{ leny },
						m_msg{ pmsg },
						m_funaddr{ pfunaddr },
						m_filename{pfilename},
						m_vx(   new std::vector<Datum_t>(vx)), // size of data must be lenx*leny
						m_vy(   new std::vector<Datum_t>(vy)), // size of data must be lenx*leny
						m_veq(  new std::vector<std::pair<Datum_t, Datum_t>>(m_lenx*m_leny)),
						m_vineq(new std::vector<std::pair<Datum_t, Datum_t>>(m_lenx*m_leny)),
						m_vlt(  new std::vector<std::pair<Datum_t, Datum_t>>(m_lenx*m_leny)),
						m_vgt(  new std::vector<std::pair<Datum_t, Datum_t>>(m_lenx*m_leny))
					{}

					IntCompVec2D(_In_ const IntCompVec2D &) = delete;

					IntCompVec2D(_In_ IntCompVec2D &&) = delete;

					IntCompVec2D & operator=(_In_ const IntCompVec2D &) = delete;

					IntCompVec2D & operator=(_In_ IntCompVec2D &&) = delete;

					// m_vx is a copy of actual array
					// m_vy is a copy of expected array.
					void compare_equality() {
						using namespace std;
						for (std::size_t i = 0Ui64; i != m_lenx; ++i) {
							for (std::size_t j = 0Ui64; j != m_leny; ++j) {
								if (VEC2D_ACCESSOR2D(m_vx, i, m_leny, j) !=
									VEC2D_ACCESSOR2D(m_vy, i, m_leny, j)) {
									std::cout << m_msg.data() << "\n"
											  << "FAIL: Equality test!!" << "\n"
										      << "Values are not equal." << "\n"
										      << "at index: " << i * m_leny + j << "\n"
										      << "at " << m_filename << ":" << m_loc << "(" << "0x" << m_funaddr.data() << ")" << "\n";
									VEC2D_ACCESSOR2D(m_veq, i, m_leny, j) = VEC2D_MAKE_RESULT(m_vx,m_vy,i,m_leny,j)
								}
								else {
									VEC2D_ACCESSOR2D(m_veq, i, m_leny, j) = VEC2D_MAKE_RESULT(m_vx,m_vy,i,m_leny,j)
								}
							}
						}
					}

					// m_vx is a copy of actual array
					// m_vy is a copy of expected array.
					void compare_inequality() {
						using namespace std;
						for (std::size_t i = 0Ui64; i != m_lenx; ++i) {
							for (std::size_t j = 0Ui64; j != m_leny; ++j) {
								if (VEC2D_ACCESSOR2D(m_vx, i, m_leny, j) ==
									VEC2D_ACCESSOR2D(m_vy, i, m_leny, j)) {
									std::cout << m_msg.data() << "\n"
										      << "FAIL: Inequality test!!" << "\n"
										      << "Values are  equal." << "\n"
										      << "at index: " << i * m_leny + j << "\n"
										      << "at " << m_filename << ":" << m_loc << "(" << "0x" << m_funaddr.data() << ")" << "\n";
									VEC2D_ACCESSOR2D(m_vineq, i, m_leny, j) = VEC2D_MAKE_RESULT(m_vx,m_vy,i,m_leny,j)
								}
								else {
									VEC2D_ACCESSOR2D(m_vineq, i, m_leny, j) = VEC2D_MAKE_RESULT(m_vx, m_vy, i, m_leny, j)
								}
							}
						}
					}

					// m_vx is a copy of actual array
					// m_vy is a copy of expected array.
					void compare_lt() {
						using namespace std;
						for (std::size_t i = 0Ui64; i != m_lenx; ++i) {
							for (std::size_t j = 0Ui64; j != m_leny; ++j) {
								if (VEC2D_ACCESSOR2D(m_vx, i, m_leny, j) >
									VEC2D_ACCESSOR2D(m_vy, i, m_leny, j)) {
									std::cout << m_msg.data() << "\n"
											  << "FAIL: Less than test!!" << "\n"
										      << "m_vx values are  greater." << "\n"
										      << "at index: " << i * m_leny + j << "\n"
										      << "at " << m_filename << ":" << m_loc << "(" << "0x" << m_funaddr.data() << ")" << "\n";
									VEC2D_ACCESSOR2D(m_vlt, i, m_leny, j) = VEC2D_MAKE_RESULT(m_vx,m_vy,i,m_leny,j)
								}
								else {
									VEC2D_ACCESSOR2D(m_vlt, i, m_leny, j) = VEC2D_MAKE_RESULT(m_vx, m_vy, i, m_leny, j)
								}
							}
						}
					}

					// m_vx is a copy of actual array
					// m_vy is a copy of expected array.
					void compare_gt() {
						using namespace std;
						for (std::size_t i = 0Ui64; i != m_lenx; ++i) {
							for (std::size_t j = 0Ui64; j != m_leny; ++j) {
								if (VEC2D_ACCESSOR2D(m_vx, i, m_leny, j) <
									VEC2D_ACCESSOR2D(m_vy, i, m_leny, j)) {
									std::cout << m_msg.data() << "\n"
											  << "FAIL: Grater than test!!" << "\n"
										      << "m_vx values are smaller." << "\n"
										      << "at index: " << i * m_leny + j << "\n"
										      << "at " << m_filename << ":" << m_loc << "(" << "0x" << m_funaddr.data() << ")" << "\n";
									VEC2D_ACCESSOR2D(m_vgt, i, m_leny, j) = VEC2D_MAKE_RESULT(m_vx,m_vy,i,m_leny,j)
								}
								else {
									VEC2D_ACCESSOR2D(m_vgt, i, m_leny, j) = VEC2D_MAKE_RESULT(m_vx, m_vy, i, m_leny, j)
								}
							}
						}
					}

			};

			// Floating-point scalar comparison
			
			template<typename Real_t,
					 typename = std::enable_if<std::
						   is_floating_point<Real_t>::value>::type>  struct FPCompare{

						   int32_t m_loc;
							
						   Real_t  m_x;

						   Real_t  m_y;

						   float   m_fuzz32;

						   double  m_fuzz64;

						   Real_t  m_eps;

						   Real_t  m_distance;

						   std::string m_msg;

						   std::wstring m_funcaddr;

						   std::string  m_filename;

						   FPCompare() = default;

						   FPCompare(_In_ const int32_t loc,
									 _In_ const Real_t x,
							         _In_ const Real_t y,
							         _In_ const float fuzz32,
							         _In_ const double fuzz64,
							         _In_ const Real_t eps,
							         _In_ const char * pmsg,
							         _In_ const char * pfuncaddr,
							         _In_ const char * pfilename)
							   :
							  FPCOMPARE_CTOR_BLOCK
						   {}

						   ~FPCompare() = default;

						   FPCompare(_In_ const FPCompare &) = delete;

						   FPCompare(_In_ FPCompare &&) = delete;

						   FPCompare & operator=(_In_ const FPCompare &) = delete;

						   FPCompare & operator=(_In_ FPCompare &&) = delete;

						   bool compare_abs_err() const {
							   using namespace std;
							   if (static_cast<Real_t>(std::fabs(m_x - m_y)) > m_eps) {
								   std::cout << m_msg << "\n"
										     << "FAIL: Abs error test!! \n"
											 << "x=" << m_x << " - " << "y=" << m_y << " > " << m_eps << "\n"
											 << "at " << m_filename << ":" << m_loc << "(" << "0x" << m_funcaddr.data() << ")" << "\n"; 
								   return (true);
							   }
							   else {
								   return (false);
							   }
						   }

						   bool compare_rel_err() const {
							   using namespace std;
							   Real_t delta{ static_cast<Real_t>(std::fabs(m_x - m_y)) };
							   m_x = std::fabs(m_x);
							   m_y = std::fabs(m_y);
							   Real_t bigger{ (m_y > m_x) ? m_y : m_x};
							   if (delta >= (bigger * m_eps)) {
								   std::cout << m_msg                         << "\n"
											 << "FAIL: Relative error test!!" << "\n"
											 << "delta = " << delta << " >= " << "(" << bigger * m_eps << ")" << "\n"
											 << "at " << m_filename << ":" << m_loc << "(" << "0x" << m_funcaddr.data() << ")" << "\n";
								   return (true);
							   }
							   else {
								   return (false);
							   }
						   }

						   bool fuzzy_compare32() const {
							  
							   UlpDiff<Real_t> ud;
							   return (ud.ulp_diff(m_x,m_y) <= m_fuzz32);
						   }

						   bool fuzzy_compare64() const {
							   UlpDiff<Real_t> ud;
							   return (ud.ulp_diff(m_x,m_y) <= m_fuzz64);
						   }

			};

			/*****************************************
			     Array1D floating-point comparison
				 object.
			******************************************/
			
			template<typename Real_t,
					 typename = std::enable_if<
					      std::is_floating_point<Real_t>::value>::type> struct FPCompVec1D {

						  using SPData = std::unique_ptr<std::vector<Real_t>>;
						  using SPResult = std::unique_ptr<std::vector<std::pair<Real_t,Real_t>>>;
						  using Pmf = void(FPCompVec1D::*)(void);

						
						  
						

						  int32_t      m_loc;

						  std::size_t  m_vlen;

						

						  Real_t       m_eps;

						  Real_t       m_dist;

						  float        m_fuzz32;

						  double       m_fuzz64;

						  std::string  m_msg;

						  std::wstring m_funcaddr;

						  std::string  m_filename;

						  SPData       m_vx;

						  SPData       m_vy;

						  SPResult     m_vabser;

						  SPResult     m_vreler;

						  SPResult     m_vfuzz32er;

						  SPResult     m_vfuzz64er;

						  FPCompVec1D() 
							  :
							  m_loc{},
							  m_vlen{},
							  m_eps{},
							  m_dist{},
							  m_fuzz32{},
							  m_fuzz64{},
							  m_msg{},
							  m_funcaddr{},
							  m_filename{},
							  m_vx{ nullptr },
							  m_vy{ nullptr },
							  m_vabser{ nullptr },
							  m_vreler{ nullptr },
							  m_vfuzz32er{ nullptr },
							  m_vfuzz64er{ nullptr }
							 
						  {}

						  FPCompVec1D(
									  _In_ const int32_t loc,
									  _In_ const std::size_t vlen,
									  _In_ const Real_t eps,
									  _In_ const Real_t dist,
									  _In_ const float fuzz32,
									  _In_ const double fuzz64,
									  _In_ const char * pmsg,
									  _In_ const char * pfuncaddr,
									  _In_ const char * pfilename,
									  _In_ const std::vector<Real_t> &vx,
									  _In_ const std::vector<Real_t> &vy) noexcept(false)
								:
								FPCOMPVEC1D_CTOR_BLOCK
						  {}

						  ~FPCompVec1D() = default;

						  FPCompVec1D(_In_ const FPCompVec1D &) = delete;

						  FPCompVec1D(_In_ FPCompVec1D &&) = delete;

						  FPCompVec1D & operator=(_In_ const FPCompVec1D &) = delete;

						  FPCompVec1D & operator=(_In_ FPCompVec1D &&) = delete;

						  // m_vx is a copy of expected array
						  // m_vy is a copy of actual array.
						  void  comp_abserr() {
							  using namespace std;
							  for (std::size_t i = 0Ui64; i != m_vlen; ++i) {
								  if ((static_cast<Real_t>(std::fabs(VEC1D_ACCESSOR1D(m_vx, i)-
														   VEC1D_ACCESSOR1D(m_vy, i)))) > m_eps) {
									  cout << m_msg << "\n"
										  << "FAIL: Abs error test!! " << "\n"
										  << "expected:    actual:      abs diff:    eps:     " << "\n"
										  << "----------------------------------------------------" << "\n"
										  << fixed << setprecision(16) << 
										  VEC1D_ACCESSOR1D(m_vx, i) << VEC1D_ACCESSOR1D(m_vy,i) <<
										  std::fabs(VEC1D_ACCESSOR1D(m_vx, i), VEC1D_ACCESSOR1D(m_vy,i)) <<
										  m_eps << "\n";
									  VEC1D_ACCESSOR1D(m_vabser, i) = VEC1D_MAKE_RESULT(m_vx,m_vy,i)
								  }
								  else {
									  VEC1D_ACCESSOR1D(m_vabser, i) = VEC1D_MAKE_RESULT(m_vx,m_vy,i)
								  }
							  }
						  }

						  // m_vx is a copy of expected array
						  // m_vy is a copy of actual array.
						  void comp_relerr() {
							  using namespace std;
							  for (std::size_t i = 0Ui64; i != vlen; ++i) {
								  Real_t delta{ static_cast<Real_t>(std::fabs(VEC1D_ACCESSOR1D(m_vx,i) - 
								  VEC1D_ACCESSOR1D(m_vy,i))) };
								  VEC1D_ACCESSOR1D(m_vx, i) = std::fabs(VEC1D_ACCESSOR1D(m_vx,i));
								  VEC1D_ACCESSOR1D(m_vy, i) = std::fabs(VEC1D_ACCESSOR1D(m_vy, i));
								  Real_t bigger{ (VEC1D_ACCESSOR1D(m_vy, i) - VEC1D_ACCESSOR1D(m_vx,i)) ? 
								  VEC1D_ACCESSOR1D(m_vy, i) : VEC1D_ACCESSOR1D(m_vx,i) };
								  if (delta > bigger * m_eps) {
									  cout << m_msg << "\n"
										  << "FAIL: Realtive error test!! " << "\n"
										  << "expected:    actual:     rel diff:    eps:     " << "\n"
										  << "----------------------------------------------------" << "\n"
										  << fixed << setprecision(16) << 
										  VEC1D_ACCESSOR1D(m_vx, i) << "," << VEC1D_ACCESSOR1D(m_vy,i) <<
										  delta << "," << m_eps << "\n";
									  cout << "at " << m_filename << ":" << m_loc << "(" << "0x" << m_funcaddr.data() << ")" << "\n";
									  VEC1D_ACCESSOR1D(m_vreler, i) = VEC1D_MAKE_RESULT(m_vx,m_vy,i)
								  }
								  else {
									  VEC1D_ACCESSOR1D(m_vreler, i) = VEC1D_MAKE_RESULT(m_vx, m_vy, i)
								  }
							  }
						  }

						  // m_vx is a copy of expected array
						  // m_vy is a copy of actual array.
						  void fuzzy_comp32() {
							  using namespace std;
							 
							  for (std::size_t i = 0Ui64; i != vlen; ++i) {
								  if (m_dist = UlpDiff<Real_t>::ulp_diff(VEC1D_ACCESSOR1D(m_vx, i),
									  VEC1D_ACCESSOR1D(m_vy, i)) > static_cast<Real_t>(m_fuzz32)) {
									  cout << m_msg << "\n"
										   << "FAIL: Last Unit in Place test!!" << "\n"
										   << "expected:      actual:      ulp diff:     fuzz32:  " << "\n"
										   << "----------------------------------------\n" << "\n"
										   << fixed << setprecision(16) <<
										   VEC1D_ACCESSOR1D(m_vx, i) << "," << VEC1D_ACCESSOR1D(m_vy, i) <<
										   m_dist << "," << m_fuzz32 << "\n";
									  cout << "at " << m_filename << ":" << m_loc << "(" << "0x" << m_funcaddr.data() << ")" << "\n"; 
									  VEC1D_ACCESSOR1D(m_vfuzz32er, i) = VEC1D_MAKE_RESULT(m_vx,m_vy,i)
								  }
								  else {
									  VEC1D_ACCESSOR1D(m_vfuzz32er, i) = VEC1D_MAKE_RESULT(m_vx, m_vy, i)
								  }
							  }
						  }

						  // m_vx is a copy of expected array
						  // m_vy is a copy of actual array.
						  void fuzz_comp64() {
							  using namespace std;
							 
							  for (std::size_t i = 0Ui64; i != vlen; ++i) {
								  if (m_dist = UlpDiff<Real_t>::ulp_diff(VEC1D_ACCESSOR1D(m_vx, i),
									  VEC1D_ACCESSOR1D(m_vy, i)) > static_cast<Real_t>(m_fuzz64)) {
									  cout << m_msg << "\n"
										  << "FAIL: Last Unit in Place test!!" << "\n"
										  << "expected:      actual:      ulp diff:     fuzz64:  " << "\n"
										  << "----------------------------------------\n" << "\n"
										  << fixed << setprecision(16) <<
										  VEC1D_ACCESSOR1D(m_vx, i) << "," << VEC1D_ACCESSOR1D(m_vy, i) <<
										  m_dist << "," << m_fuzz64 << "\n";
									  cout << "at " << m_filename << ":" << m_loc << "(" << "0x" << m_funcaddr.data() << ")" << "\n";
									  VEC1D_ACCESSOR1D(m_vfuzz64er, i) = VEC1D_MAKE_RESULT(m_vx, m_vy, i)
								  }
								  else {
									  VEC1D_ACCESSOR1D(m_vfuzz64er, i) = VEC1D_MAKE_RESULT(m_vx, m_vy, i)
								  }
							  }
						  }

			};

			/******************************************
			Array2D floating-point comparison object.
			*******************************************/
			template<typename Real_t,
					 typename = std::enable_if<
					 std::is_floating_point<Real_t>::value>::type> struct FPCompVec2D {

					 using SPData2D   = std::unique_ptr<std::vector<Real_t>>;
					 using SPResult2D = std::unique_ptr<std::vector<std::pair<Real_t,Real_t>>>;
					 using Pmf        = void(FPCompVec2D::*)(void);

					 int32_t		 m_loc;

					 std::size_t     m_vleni;

					 std::size_t     m_vlenj;

					 float           m_fuzz32;

					 double          m_fuzz64;

					 Real_t          m_dist;

					 Real_t          m_eps;

					 std::string     m_msg;

					 std::wstring    m_funcaddr;

					 std::string     m_filename;

					 SPData2D		 m_vx;

					 SPData2D		 m_vy;

					 SPResult2D      m_vabser;

					 SPResult2D      m_vreler;

					 SPResult2D		 m_vfuzz32;

					 SPResult2D		 m_vfuzz64;

					 FPCompVec2D() 
						 :
					 m_loc{},
					 m_vleni{},
					 m_vlenj{},
					 m_fuzz32{},
					 m_fuzz64{},
					 m_dist{},
					 m_eps{},
					 m_msg{},
					 m_funcaddr{},
					 m_filename{},
					 m_vx(nullptr),
					 m_vy(nullptr),
					 m_vabser(nullptr),
					 m_vreler(nullptr),
					 m_vfuzz32(nullptr),
					 m_vfuzz64(nullptr)
					 {}

					 FPCompVec2D(_In_ const int32_t loc,
								 _In_ const std::size_t vleni,
								 _In_ const std::size_t vlenj,
								 _In_ const float fuzz32,
								 _In_ const double fuzz64,
								 _In_ const Real_t dist,
								 _In_ const Real_t eps,
								 _In_ const char * pmsg,
								 _In_ const char * pfuncadr,
								 _In_ const char * pfilename,
								 _In_ const std::vector<Real_t> &vx,
								 _In_ const std::vector<Real_t> &vy)
						:
						FPCOMPVEC2D_CTOR_BLOCK
					 {}

					 ~FPCompVec2D() = default;

					 FPCompVec2D(_In_ const FPCompVec2D &) = delete;

					 FPCompVec2D(_In_ FPCompVec2D &&) = delete;

					 FPCompVec2D & operator=(_In_ const FPCompVec2D &) = delete;

					 FPCompVec2D & operator=(_In_ FPCompVec2D &&) = delete;

					 // m_vx is a copy of expected array
					 // m_vy is a copy of actual array.
					 void comp_abserr() {
						 using namespace std;
						 for (std::size_t i = 0Ui64; i != m_vleni; ++i) {
							 for (std::size_t j = 0Ui64; j != m_vlenj; ++j) {
								 if (static_cast<Real_t>(std::fabs(VEC2D_ACCESSOR2D(m_vx, i, m_vlenj, j) -
															 VEC2D_ACCESSOR2D(m_vy, i, m_vlenj, j)) > m_eps)) {
									 cout << m_msg << "\n"
										  << "FAIL: Abs error test!! \n"
									      << "expected:      actual:    abs diff:      eps:  \n"
									      << "----------------------------------------------------\n"
									      << fixed << setprecision(16) <<
											  VEC2D_ACCESSOR2D(m_vx, i, m_vlenj, j) << "," VEC2D_ACCESSOR2D(m_vy,i,m_vlenj,j) <<
											  std::fabs(VEC2D_ACCESSOR2D(m_vx, i, m_vlenj, j) - VEC2D_ACCESSOR2D(m_vy,i,m_vlenj,j)) <<
											  m_eps << "\n";
									 cout << "at " << m_filename << ":" << m_loc << "(" << "0x" << m_funcaddr.data() << ")" << "\n";"
									VEC2D_ACCESSOR2D(m_vabser, i, m_vlenj, j) = VEC2D_MAKE_RESULT(m_vx,m_vj,i,m_vlenj,j)
								 }
								 else {
									 VEC2D_ACCESSOR2D(m_vabser, i, m_vlenj, j) = VEC2D_MAKE_RESULT(m_vx, m_vj, i, m_vlenj, j)
								 }
							 }
						 }
					 }


					 // m_vx is a copy of expected array
					 // m_vy is a copy of actual array.
					 void comp_relerr() {
						 using namespace std;
						 for (std::size_t i = 0Ui64; i != vleni; ++i) {
							 for (std::size_t j = 0Ui64; j != vlenj; ++j) {
								 Real_t delta{ static_cast<Real_t>(std::fabs(VEC2D_ACCESSOR2D(m_vx,i,m_vlenj,j)- 
																	 VEC2D_ACCESSOR2D(m_vy,i,m_vlenj,j))) };
								 VEC2D_ACCESSOR2D(m_vx, i, m_vlenj, j) = std::fabs(VEC2D_ACCESSOR2D(m_vy,i,m_vlenj,j))
								 VEC2D_ACCESSOR2D(m_vy, i, m_vlenj, j) = std::fabs(VEC2D_ACCESSOR2D(m_vy, i, m_vlenj, j))
								 Real_t bigger{ (VEC2D_ACCESSOR2D(m_vy, i, m_vlenj, j)>VEC2D_ACCESSOR2D(m_vx,i,m_vlenj,j)) ? 
								 VEC2D_ACCESSOR2D(m_vy, i, m_vlenj, j) : VEC2D_ACCESSOR2D(m_vx,i,m_vlenj,j) };
								 if (delta > bigger * m_eps) {
									 cout << "FAIL: Abs error test!! \n"
										 << "expected:      actual:    abs diff:      eps:  \n"
										 << "----------------------------------------------------\n"
										 << fixed << setprecision(16) <<
										 VEC2D_ACCESSOR2D(m_vx, i, m_vlenj, j) << "," << VEC2D_ACCESSOR2D(m_vy,i,m_vlenj,j) <<
										 delta << "," << m_eps << "\n";
									 cout << "at " << m_filename << ":" << m_loc << "(" << "0x" << m_funcaddr.data() << ")" << "\n";
									 VEC2D_ACCESSOR2D(m_vabser, i, m_vlenj, j) = VEC2D_MAKE_RESULT(m_vx,i,m_vlenj,j)
								 }
								 else {
									 VEC2D_ACCESSOR2D(m_vabser, i, m_vlenj, j) = VEC2D_MAKE_RESULT(m_vx, i, m_vlenj, j)
								 }

							 }
						 }
					 }

					 // m_vx is a copy of expected array
					 // m_vy is a copy of actual array.
					 void comp_fuzz32() {
						 using namespace std;
						
						 for (std::size_t i = 0Ui64; i != m_vleni; ++i) {
							 for (std::size_t j = 0Ui64; j != m_vlenj; ++j) {
								 if (m_dist = UlpDiff<Real_t>::ulp_diff(VEC2D_ACCESSOR2D(m_vx, i, m_vlenj, j),
									 VEC2D_ACCESSOR2D(m_vy, i, m_vlenj, j)) > static_cast<Real_t>(m_fuzz32)) {
									 cout << m_msg << "\n"
										  << "FAIL: Last Unit in Place 32-bit fuzz test!!\n"
									      << "expected:   actual:  ulp diff:   fuzz32:   \n"
									      << "----------------------------------------\n"
										  << fixed << setprecision(16) <<
										  VEC2D_ACCESSOR2D(m_vx, i, m_vlenj, j) << "," VEC2D_ACCESSOR2D(m_vy,i,m_vlenj,j) <<
										  m_dist << "," << m_eps << "\n";
									 cout << "at " << m_filename << ":" << m_loc << "(" << "0x" << m_funcaddr.data() << ")" << "\n";
									 VEC2D_ACCESSOR2D(m_vfuzz32, i, m_vlenj, j) = VEC2D_MAKE_RESULT(m_vx,m_vy,i,m_vlenj,j)
								 }
								 else {
									 VEC2D_ACCESSOR2D(m_vfuzz32, i, m_vlenj, j) = VEC2D_MAKE_RESULT(m_vx, m_vy, i, m_vlenj, j)
								 }
							 }
						 }
					 }

					 // m_vx is a copy of expected array
					 // m_vy is a copy of actual array.
					 void comp_fuzz64() {
						 using namespace std;
						 for (std::size_t i = 0Ui64; i != m_vleni; ++i) {
							 for (std::size_t j = 0Ui64; j != m_vlenj; ++j) {
								 if (m_dist = UlpDiff<Real_t>::ulp_diff(VEC2D_ACCESSOR2D(m_vx, i, m_vlenj, j),
									 VEC2D_ACCESSOR2D(m_vy, i, m_vlenj, j)) > static_cast<Real_t>(m_fuzz64)) {
									 cout << m_msg << "\n"
										 << "FAIL: Last Unit in Place 64-bit fuzz test!!\n"
										 << "expected:   actual:  ulp diff:   fuzz64:   \n"
										 << "----------------------------------------\n"
										 << fixed << setprecision(16) <<
										 VEC2D_ACCESSOR2D(m_vx, i, m_vlenj, j) << "," VEC2D_ACCESSOR2D(m_vy, i, m_vlenj, j) <<
										 m_dist << "," << m_eps << "\n";
									 cout << "at " << m_filename << ":" << m_loc << "(" << "0x" << m_funcaddr.data() << ")" << "\n";
									 VEC2D_ACCESSOR2D(m_vfuzz64, i, m_vlenj, j) = VEC2D_MAKE_RESULT(m_vx, m_vy, i, m_vlenj, j)
								 }
								 else {
									 VEC2D_ACCESSOR2D(m_vfuzz64, i, m_vlenj, j) = VEC2D_MAKE_RESULT(m_vx, m_vy, i, m_vlenj, j)
								 }
							 }
						 }
					 }
		 };
	}
}


#endif /*__LAM_DATA_COMPARATOR_HPP__*/
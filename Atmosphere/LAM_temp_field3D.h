#ifndef __LAM_TEMP_FIELD3D_H__
#define __LAM_TEMP_FIELD3D_H__

#if !defined (LAM_TEMP_FIELD3D_MAJOR)
#define LAM_TEMP_FIELD3D_MAJOR 1
#endif

#if !defined (LAM_TEMP_FIELD3D_MINOR)
#define LAM_TEMP_FIELD3D_MINOR 0
#endif

#if !defined (LAM_TEMP_FIELD3D_MICRO)
#define LAM_TEMP_FIELD3D_MICRO 0
#endif

#if !defined (LAM_TEMP_FIELD3D_FULLVER)
#define LAM_TEMP_FIELD3D_FULLVER 1000
#endif

#if !defined (LAM_TEMP_FIELD3D_CREATE_DATE)
#define LAM_TEMP_FIELD3D_CREATE_DATE "16-09-2017 12:33 +00200 (SAT 16 SEP 2017 GMT+2)"
#endif
//
//	Set this value to last successful build date/time.
//
#if !defined (LAM_TEMP_FIELD3D_BUILD_DATE)
#define LAM_TEMP_FIELD3D_BUILD_DATE " "
#endif

#if !defined (LAM_TEMP_FIELD3D_AUTHOR)
#define LAM_TEMP_FIELD3D_AUTHOR "Programmer: Bernard Gingold , e-mail: beniekg@gmail.com"
#endif

#if !defined (LAM_TEMP_FIELD3D_DESCRIPT)
#define LAM_TEMP_FIELD3D_DESCRIPT "Scalar temperature field 3D."
#endif

#include <cstdint>

namespace lam {
	namespace atmosphere {

		struct TempField3D {

			//
			// Default Constructor surpressed.
			//
			TempField3D() = delete;

			//
			// Explicit one-arg Constructor.
			// Should be used to pointer member
			// allocation and default initialization.
			explicit TempField3D(_In_ const uint64_t indices[18]) noexcept(false);
								

			//
			// Constructor object by copying state from
			// user passed array.
			//
			TempField3D(_In_ const uint64_t indices[18],
						_In_ const double* __restrict) noexcept(false);

			//
			// Copy-Constructor implements deep copy-semantics
			//
			TempField3D(_In_ const TempField3D &) noexcept(false);

			//
			// Move-Constructor implements shallow copy-semantics
			//
			TempField3D(_In_ TempField3D &&) noexcept(true);

			//
			// Class destructor
			//
			~TempField3D();

			//
			// Class member and friend operators
			//

			
			
			// Copy-assignment (deep-copy semantics)
			TempField3D & operator=(_In_ const TempField3D &);

			// Move-assignment (shallow-copy semantics)
			TempField3D & operator=(_In_ TempField3D &&);

			// Fields-addition
			TempField3D & operator+=(_In_ const TempField3D &) noexcept(false);

			// Fields-subtraction
			TempField3D & operator-=(_In_ const TempField3D &) noexcept(false);

			// Fields-multiplication
			TempField3D & operator*=(_In_ const TempField3D &) noexcept(false);

			// Filed multiplied by scalar.
			TempField3D & operator*=(_In_ const double) noexcept(true);

			// Fields-division
			TempField3D & operator/=(_In_ const TempField3D &) noexcept(false);

			// Field division by scalar
			TempField3D & operator/=(_In_ const double) noexcept(false);

			// Fields inequality (inequality of scalars i.e. temperature values in (K))
			 double * operator!=(_In_ const TempField3D &) noexcept(false);

			// Fields equality (equality of scalars i.e. temperature values in (K))
			 double * operator==(_In_ const TempField3D &) noexcept(false);

			// Fields greater-then
			 double * operator>(_In_ const TempField3D &) noexcept(false);

			// Fields lesser-than
			 double * operator<(_In_ const TempField3D &) noexcept(false);

			

			// Overloaded operator <<
			friend std::ostream & operator<<(_In_ std::ostream &, _In_ const TempField3D &);

			//
			//	Scalar field differential operators
			//

			// scalar field gradient
			// On error set ioerr parameter   == -1
			// On success set ioerr parameter == 0
			void gradient(_Inout_ double* __restrict,
						  _In_ const uint64_t,
						  _In_ const uint64_t,
						  _In_ const uint64_t,
						  _In_ int&) const noexcept(true);
						  

			// scalar field laplacian - in-place
			// On error set ioerr parameter   == -1
			// On success set ioerr parameter == 0
			void laplacian(_Inout_ double* __restrict,
						   _In_ const uint64_t,
						   _In_ const uint64_t,
						   _In_ const uint64_t,
						   _Inout_ int&) const noexcept(true);

			// scalar field laplacian - returned in user passed array.
			// On error set ioerr parameter   == -1
			// On success set ioerr parameter == 0
			void laplacian(_In_ double* __restrict,
						   _Inout_ double* __restrict,
						   _In_ const uint64_t,
						   _In_ const uint64_t,
						   _In_ const uint64_t,
						   _Inout_ int&) const;


			//
			// Members
			//
			// Indices (conformance to WRF model)
			/*

          kts+n -       - its+n
           ...  -      - ...
		  kts+3	-     - its+3
		  kts+2	-    - its+2
		  kts+1	-	- its+1
				jts+1,jts+2,jts+3 .... jts+n
			*/
			uint64_t m_ims,m_ime,m_kms,m_kme,m_jms,m_jme,
					 m_ids,m_ide,m_kds,m_kde,m_jds,m_jde,
					 m_its,m_ite,m_kts,m_kte,m_jts,m_jte;
			
			// Pointer to temperature field
			double* __restrict m_t3d;

			// Allocation indicator.
			bool m_isalloc;
		};
	}
}

#endif /*__LAM_TEMP_FIELD3D_H__*/
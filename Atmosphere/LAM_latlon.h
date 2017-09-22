
#ifndef __LAM_LATLON_H__
#define __LAT_LONLON_H__

#if !defined (LAM_LATLON_MAJOR)
#define LAM_LATLON_MAJOR 1
#endif

#if !defined (LAM_LATLON_MINOR)
#define LAM_LATLON_MINOR 0
#endif

#if !defined (LAM_LATLON_MICRO)
#define LAM_LATLON_MINOR 0
#endif

#if !defined (LAM_LATLON_FULLVER)
#define LAM_LATLON_FULLVER 1000
#endif

#if !defined (LAM_LATLON_CREATE_DATE)
#define LAM_LATLON_CREATE_DATE "22-09-2017 12:09 +00200 (FRI 22 SEP 2017 GMT+2)"
#endif
//
//	Set this value to last successful build date/time.
//
#if !defined (LAM_LATLON_BUILD_DATE)
#define LAM_LATLON_BUILD_DATE " "
#endif

#if !defined (LAM_LATLON_AUTHOR)
#define LAM_LATLON_AUTHOR "Programmer: Bernard Gingold e-mail: beniekg@gmail.com"
#endif

#if !defined (LAM_LATLON_DESCRIPT)
#define LAM_LATLON_DESCRIPT "Latitude-Longtitude representation (deg)"
#endif

#include <cstdint>
#include <utility>

namespace lam {
	namespace atmosphere {

		struct LatLon{


			//
			// Default Constructor - surpressed
			//
			LatLon() = delete;

			//
			// Explicit one-arg Constructor.
			// Should be used to pointer member
			// allocation and default initialization to invalid state.
			// Caller should later set appropriate geo-coordinate data.
			LatLon(_In_ const uint64_t indices[12]) noexcept(false);

			//
			// Constructor creates an object by copying state from
			// user passed array.
			// @Warning:
			//		     Caller is responsible for allocating the same
			//			 amount of memory for  its array arguments
			// i.e sizeof(lat) == sizeof(m_lat)
			//     sizeof(lon) == sizeof(m_long)
			LatLon(_In_ const uint64_t indices[12], 
				   _In_ const double* __restrict,
				   _In_ const double* __restrict) noexcept(false);
				  

			// Copy-Constructor implememts deep-copy semantics
			LatLon(_In_ const LatLon &) noexcept(false);

			// Move-Constructor implements shallow copy semantics
			LatLon(_In_ LatLon &&) noexcept(true);

			// Class Destructor
			~LatLon();

			//
			// Class member and friend operators
			//

			LatLon & operator=(_In_ const LatLon &);

			LatLon & operator=(_In_ LatLon &&);

			std::pair<double*, double*> 
				operator==(_In_ const LatLon &) noexcept(false);

			std::pair<double*, double*>
				operator!=(_In_ const LatLon &) noexcept(false);

			std::pair<double*,double*>
				operator>(_In_ const LatLon &) noexcept(false);

			std::pair<double*,double*>
				operator<(_In_ const LatLon &) noexcept(false);

			friend std::ostream & operator<<(_In_ std::ostream &,
											 _In_ const LatLon &);


			
			// Indexing members in conformance to WRF model
			// 
			uint64_t m_ims,m_ime,m_jms,m_jme,
					 m_ids,m_ide,m_jds,m_jde,
					 m_its,m_ite,m_jts,m_jte;

			// Latitude data in degrees.
			double* __restrict m_lat;

			// Longtitude data in degrees.
			double* __restrict m_long;

			// Built indicator
			bool m_isalloc;


		};
	}
}

#endif /*__LAM_LATLON_H__*/
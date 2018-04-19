
#ifndef __LAM_WSR88D_VCS_H__
#define __LAM_WSR88D_VCS_H__

#if !defined (LAM_WSR88D_VCS_MAJOR)
#define LAM_WSR88D_VCS_MAJOR 1
#endif

#if !defined (LAM_WSR88D_VCS_MINOR)
#define LAM_WSR88D_VCS_MINOR 0
#endif

#if !defined (LAM_WSR88D_VCS_MICRO)
#define LAM_WSR88D_VCS_MICRO 0
#endif

#if !defined (LAM_WSR88D_VCS_FULLVER)
#define LAM_WSR88D_VCS_FULLVER 1000
#endif

#if !defined (LAM_WSR88D_VCS_CREATE_DATE)
#define LAM_WSR88D_VCS_CREATE_DATE "16-04-2018 14:17 +00200 (MON 16 APR 2018 GMT+2) "
#endif

#if !defined (LAM_WSR88D_VCS_BUILD_DATE)
#define LAM_WSR88D_VCS_BUILD_DATE " "
#endif

#if !defined (LAM_WSR88D_VCS_AUTHOR)
#define LAM_WSR88D_VCS_AUTHOR "Programmer: Bernard Gingold, e-mail: beniekg@gmail.com"
#endif

#if !defined (LAM_WSR88D_VCS_DESCRIPT)
#define LAM_WSR88D_VCS_DESCRIPT "WSR-88D Velocity Cross Section product."
#endif

#include <iostream>
#include <cstdint>

namespace lam {
	namespace wsr88d {

		// WSR-88D Velocity Cross Section product.

		__declspec(align(64))struct VCS_t {

			// number of measurements
			int32_t m_nsize;

			_Field_size_(m_nsize) double * __restrict m_Azimuth; // Azimuth, deg, 0-359, 1

			_Field_size_(m_nsize) double * __restrict m_Range; //   Range, nmi, 0.0-124.0, 1.0

			_Field_size_(m_nsize) double * __restrict m_MaxV; //    Max Velocity, Kts, 0.0-245.0, 1.0

			_Field_size_(m_nsize) double * __restrict m_HMaxV; //   Height of Max Velocity, Kft, 0.0-70.0, 1.0

			_Field_size_(m_nsize) double * __restrict m_MinV;  //   Min Velocity, Kts, -247.0-0.0, 1.0

			_Field_size_(m_nsize) double * __restrict m_HMinV; //   Height of Min Velocity, Kft, 0.0-70.0, 1.0

			// Construction and Destruction

			VCS_t();

			explicit VCS_t(_In_ const int32_t);

			VCS_t(_In_ const VCS_t &);

			VCS_t(_In_ VCS_t &&) noexcept(true);

			~VCS_t()noexcept(true);

			VCS_t & operator=(_In_ const VCS_t &);

			VCS_t & operator=(_In_ VCS_t &&) noexcept(true);

		};

		// operator << (ostream)
		std::ostream &
		operator<<(_In_ std::ostream &, _In_ const VCS_t &);


	}
}

#endif /*__LAM_WSR88D_VCS_H__*/
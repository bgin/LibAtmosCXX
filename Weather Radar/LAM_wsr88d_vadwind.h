
#ifndef __LAM_WSR88D_VADWIND_H__
#define __LAM_WSR88D_VADWIND_H__

#if !defined (LAM_WSR88D_VADWIND_MAJOR)
#define LAM_WSR88D_VADWIND_MAJOR 1
#endif

#if !defined (LAM_WSR88D_VADWIND_MINOR)
#define LAM_WSR88D_VADWIND_MINOR 0
#endif

#if !defined (LAM_WSR88D_VADWIND_MICRO)
#define LAM_WSR88D_VADWIND_MICRO 0
#endif

#if !defined (LAM_WSR88D_VADWIND_FULLVER)
#define LAM_WSR88D_VADWIND_FULLVER 1000
#endif

#if !defined (LAM_WSR88D_VADWIND_CREATE_DATE)
#define LAM_WSR88D_VADWIND_CREATE_DATE "17-04-2018 09:11 +00200 (TUE 17 APR 2018 GMT+2) "
#endif

#if !defined (LAM_WSR88D_VADWIND_BUILD_DATE)
#define LAM_WSR88D_VADWIND_BUILD_DATE " "
#endif

#if !defined (LAM_WSR88D_VADWIND_AUTHOR)
#define LAM_WSR88D_VADWIND_AUTHOR "Programmer: Bernard Gingold, e-mail: beniekg@gmail.com"
#endif

#if !defined (LAM_WSR88D_VADWIND_DESCRIPT)
#define LAM_WSR88D_VADWIND_DESCRIPT "WSR-88D VAD Wind profile product."
#endif

#include <iostream>
#include <cstdint>

namespace lam {
	namespace wsr88d {

		//
		//	WSR-88D VAD Wind profile product
		//

		__declspec(align(64))struct VADWind_t {

			// number of observations
			int32_t m_nsize;
			// Indexing variables of wind fields conform to WRF memory indexing
			// i.e.ims:ime, kms : kme, jms : jme
			int64_t m_ims;
			int64_t m_ime;
			int64_t	m_kms;
			int64_t m_kme;
			int64_t m_jms;
			int64_t m_jme;

			// Public array member fields in order to eliminate unnecessary copy operations

			_Field_size_(m_nsize) double * __restrict m_Alt; // Altitude,  100ft,  0.0-700.0,        1.0

			_Field_size_(m_nsize) double * __restrict m_Dir; // Direction      deg,     0-360,       1

			_Field_size_(m_nsize) double * __restrict m_Spd; // Speed       knots,   0-999,          1

			_Field_size_(m_nsize) double * __restrict m_Rms; //  RMS of speed  knots,   0-30.0,      0.1

			_Field_size_(m_nsize) double * __restrict m_Srng; // SRNG    nm,      0-124.0,           0.01  

			_Field_size_(m_nsize) double * __restrict m_Elev; // Antenna elevation deg,      -1.0-45.0,   0.1

			_Field_size_(m_ime*m_kme*m_jme) double * __restrict m_U; // U-wind    m/s,      -127.0-126.0,  0.1

			_Field_size_(m_ime*m_kme*m_jme) double * __restrict m_V; // V-wind    m/s,      -127.0-126.0,  0.1

			_Field_size_(m_ime*m_kme*m_jme) double * __restrict m_W; // W-component  cm/s   -999.9-9999.9, 0.1    
			
			//
			//	Construction and destruction
			// 

			VADWind_t();

			VADWind_t(_In_ const int64_t,
					  _In_ const int64_t,
					  _In_ const int64_t,
					  _In_ const int64_t,
					  _In_ const int64_t,
					  _In_ const int64_t,
					  _In_ const int64_t);

			VADWind_t(_In_ const VADWind_t &);

			VADWind_t(_In_ VADWind_t &&) noexcept(true);

			~VADWind_t() noexcept(true);

			VADWind_t & operator=(_In_ const VADWind_t &);

			VADWind_t & operator=(_In_ VADWind_t &&) noexcept(true);

		};

		
	}
}


#endif /*__LAM_WSR88D_VADWIND_H__*/
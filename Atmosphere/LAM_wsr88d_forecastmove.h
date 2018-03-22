
#ifndef __LAM_WSR88D_FORECASRMOVE_H__
#define __LAM_WSR88D_FORECASTMOVE_H__

// License info

#if !defined (LAM_WSR88D_FORECASTMOVE_MAJOR)
#define LAM_WSR88D_FORECASTMOVE_MAJOR 1
#endif

#if !defined (LAM_WSR88D_FORECASTMOVE_MINOR)
#define LAM_WSR88D_FORECASTMOVE_MINOR 0
#endif

#if !defined (LAM_WSR88D_FORECASTMOVE_MICRO)
#define LAM_WSR88D_FORECASTMOVE_MICRO 0
#endif

#if !defined (LAM_WSR88D_FORECASTMOVE_FULLVER)
#define LAM_WSR88D_FORECASTMOVE_FULLVER 1000
#endif

#if !defined (LAM_WSR88D_FORECASTMOVE_CREATE_DATE)
#define LAM_WSR88D_FORECASTMOVE_CREATE_DATE "21-03-2018 18:45 +00200 (WED 21 MAR 2018 GMT+2)"
#endif

//
//	Set this value after successful build date/time
//
#if !defined (LAM_WSR88D_FORECASTMOVE_BUILD_DATE)
#define LAM_WSR88D_FORECASTMOVE_BUILD_DATE " "
#endif

#if !defined (LAM_WSR88D_FORECASTMOVE_AUTHOR)
#define LAM_WSR88D_FORECASTMOVE_AUTHOR "Programmer: Bernard Gingold, e-mail: beniekg@gmail.com"
#endif

#if !defined (LAM_WSR88D_FORECASTMOVE_DESCRIPT)
#define LAM_WSR88D_FORECASTMOVE_DESCRIPT "WSR-88D Forecast movement product."
#endif

#include <cstdint>
#include <iostream>

namespace lam {
	namespace wsr88d {

		// WSR-88D Forecast movement product.

		struct ForecastMove_t {

			// Construction and destruction

			// No need for default constructor
			// so it will be 'deleted'
			ForecastMove_t() = delete;

			// Main class Constructor
			explicit ForecastMove_t(_In_ const int32_t);

			// Copy-Constructor
			ForecastMove_t(_In_ const ForecastMove_t &);

			// Move-Constructor
			ForecastMove_t(_In_ ForecastMove_t &&) noexcept(true);

			// Class destructor
			~ForecastMove_t() noexcept(true);

			// Member operators

			ForecastMove_t & operator=(_In_ const ForecastMove_t &);

			ForecastMove_t & operator=(_In_ ForecastMove_t &&) noexcept(true);
			

			// Number of measurement taken
			int32_t m_nsize;

	_Field_size_(m_nsize) double * __restrict m_StormSpeed; // Storm Speed, Kts, 0.0-999.0, 1.0

	_Field_size_(m_nsize) double * __restrict m_StormDir;    // Storm Direction, deg, 0.0-359.0, 1.0
		};

		std::ostream & operator<<(_In_ std::ostream &, _In_ const ForecastMove_t &);

	}
}



#endif /*__LAM_WSR88D_FORECASTMOVE_H__*/
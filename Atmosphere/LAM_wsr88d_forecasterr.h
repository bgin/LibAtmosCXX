
#ifndef __LAM_WSR88D_FORECASTERR_H__
#define __LAM_WSR88D_FORECASTERR_H__

#if !defined (LAM_WSR88D_FORECASTERR_MAJOR)
#define LAM_WSR88D_FORECASTERR_MAJOR 1
#endif

#if !defined (LAM_WSR88D_FORECASTERR_MINOR)
#define LAM_WSR88D_FORECASTERR_MINOR 0
#endif

#if !defined (LAM_WSR88D_FORECASTERR_MICRO)
#define LAM_WSR88D_FORECASTERR_MICRO 0
#endif

#if !defined (LAM_WSR88D_FORECASTERR_FULLVER)
#define LAM_WSR88D_FORECASTERR_FULLVER 1000
#endif

#if !defined (LAM_WSR88D_FORECASTERR_CREATE_DATE)
#define LAM_WSR88D_FORECASTERR_CREATE_DATE "15-03-2018 17:05 +00200 (THR 15 MAR 2018 GMT+2)"
#endif
//
//	Set this value after successful build date/time
//
#if !defined (LAM_WSR88D_FORECASTERR_BUILD_DATE)
#define LAM_WSR88D_FORECASTERR_BUILD_DATE " "
#endif

#if !defined (LAM_WSR88D_FORECASTERR_AUTHOR)
#define LAM_WSR88D_FORECASTERR_AUTHOR "Programmer: Bernard Gingold, e-mail: beniekg@gmail.com"
#endif

#if !defined (LAM_WSR88D_FORECASTERR_DESCRIPT)
#define LAM_WSR88D_FORECASTERR_DESCRIPT "WSR-88D Forecast Error product."
#endif

#include <cstdint>
#include <iostream>

namespace lam{
	namespace wsr88d{
		
		// WSR-88D Forecast Error product.

		struct ForecastErr_t  {
			
			
			 // There is no need for default Constructor
			 // so it will be 'deleted'
			ForecastErr_t() = delete;

			// Main class Constructor - memory allocation 
			// and initialization.
			ForecastErr_t(const int32_t);

			// Copy-Constructor
			ForecastErr_t(const ForecastErr_t &);

			// Move-Constructor
			ForecastErr_t(ForecastErr_t &&) noexcept(true);

			// Class Destructor
			~ForecastErr_t() noexcept(true);

			// Member operators

			ForecastErr_t & operator=(_In_ const ForecastErr_t &);

			ForecastErr_t & operator=(_In_ ForecastErr_t &&) noexcept(true);



			// Number of taken measurements (size of arrays 1D)
								int32_t  m_nsize;
			
		_Field_size_(m_nsize)	double * __restrict m_Err; // Error component --  nmi, 0.0-99.0, 0.1 

		_Field_size_(m_nsize)	double * __restrict m_Mean; // Mean component --  nmi  0.0-99.0, 0.1
		};
			
		// operator << (ostream)
		std::ostream & operator<<(_In_ std::ostream &, _In_ const ForecastErr_t & );
					
	}
}



#endif /*__LAM_WSR88D_FORECASTERR_H__*/

#ifndef __LAM_QUATERNION_H__
#define __LAM_QUATERNION_H__

#if !defined (LAM_QUATERNION_MAJOR)
#define LAM_QUATERNION_MAJOR 1
#endif

#if !defined (LAM_QUATERNION_MINOR)
#define LAM_QUATERNION_MINOR 0
#endif

#if !defined (LAM_QUATERNION_MICRO)
#define LAM_QUATERNION_MICRO 0
#endif

#if !defined (LAM_QUATERNION_FULLVER)
#define LAM_QUATERNION_FULLVER 1000
#endif

#if !defined (LAM_QUATERNION_CREATE_DATE)
#define LAM_QUATERNION_CREATE_DATE "06-12-2017 08:13 +00200 (WED 06 DEC 2017 GMT+2)"
#endif
//
//	Set this value to last compilation date/time
//
#if !defined (LAM_QUATERNION_BUILD_DATE)
#define LAM_QUATERNION_BUILD_DATE " "
#endif

#if !defined (LAM_QUATERNION_AUTHOR)
#define LAM_QUATERNION_AUTHOR "Programmer: Bernard Gingold e-mail: beniekg@gmail.com"
#endif

#if !defined (LAM_QUATERNION_DESCRIPT)
#define LAM_QUATERNION_DESCRIPT "Implementation of Quaternion class."
#endif

#include <iosfwd>
#include <iomanip>
#include <cstdint>
#include <complex>
  
namespace lam {
	namespace math {

	using C64 = std::complex<double>;
#if !defined (CHECK_QUATERNION_LEPS)
#define CHECK_QUATERNION_LEPS(value) \
	do {							 \
	     if ((value) < std::numeric_limits<double>::epsilon()) \
				(value) += std::numeric_limits<double>::epsilon();  \
	} while(0); 
#endif

#if !defined (LAM_QUATERNION_ACCESSORS)
#define LAM_QUATERNION_ACCESSORS    \
									\
	inline	double get_x() const {	\
		return (this->m_x);			\
	}								\
									\
	inline double get_y() const {	\
		return (this->m_y);			\
	}								\
									\
	inline double get_z() const {	\
		return (this->m_z);			\
	}								\
									\
	inline double get_w() const {	\
		return (this->m_w);			\
	}								\
									\
	inline double real()  const {	\
		return (this->get_x());		\
	}								\
									\
	inline Quaternion unreal() const { \
		return (Quaternion{ 0.0,		\
		this->m_y, this->m_z, this->m_w }); \
	}								\
									\
	inline C64 get_c1() const {		\
		return (C64{ m_x, m_y });	\
	}								\
									\
	inline C64 get_c2() const {		\
		return (C64{ m_z, m_w });	\
	}



#endif

#if !defined (LAM_QUATERNION_CTORS_DECLARATIONS)
#define LAM_QUATERNION_CTORS_DECLARATIONS    \
											 \
	Quaternion();							 \
											 \
											 \
	explicit Quaternion(_In_ const double);  \
											 \
											 \
	Quaternion(_In_ const double,			 \
		_In_ const double,					 \
		_In_ const double);					 \
											 \
	Quaternion(_In_ const double,			 \
		_In_ const double,					 \
		_In_ const double,					 \
		_In_ const double);					 \
											 \
											 \
	Quaternion(_In_ const C64 &,			 \
			  _In_ const C64 &);			 \
											 \
										     \
	Quaternion(_In_ const Quaternion &);     \
											
#endif

		class Quaternion {

			
			public:

			LAM_QUATERNION_CTORS_DECLARATIONS
			//
			// Destructor - default
			//
			~Quaternion() = default;

			//
			// Member operators
			//
			Quaternion & operator=(_In_ const Quaternion &);

			Quaternion & operator=(_In_ const double );

			Quaternion & operator=(_In_ const C64 &);

			friend std::ostream & operator<<(_In_ std::ostream &,
										     _In_ const Quaternion &);

			const double operator[](_In_ const uint32_t) const;

			//
			// Getters
			//
			LAM_QUATERNION_ACCESSORS

			private:

			// Quaternion 4-tuple components.

			double m_x;

			double m_y;

			double m_z;

			double m_w;
		};

#if !defined (Q_x)
#define Q_x(obj) obj.get_x()
#endif

#if !defined (Q_y)
#define Q_y(obj) obj.get_y()
#endif

#if !defined (Q_z)
#define Q_z(obj) obj.get_z()
#endif

#if !defined (Q_w)
#define Q_w(obj) obj.get_w()
#endif

#if !defined (Q_SQR)
#define Q_SQR(x) ((x) * (x))
#endif



		//
		//	Global operators
		//

		static inline Quaternion operator+(_In_ const Quaternion &,
										   _In_ const Quaternion &);

		static inline Quaternion operator+(_In_ const Quaternion &,
										   _In_ const std::complex<double> &);

		static inline Quaternion operator+(_In_ const Quaternion &,
										   _In_ const double);

		static inline Quaternion operator+(_In_ const std::complex<double> &,
										   _In_ const Quaternion &);

		static inline Quaternion operator+(_In_ const double,
										   _In_ const Quaternion &);

		static inline Quaternion operator+=(_In_ Quaternion &,
											_In_ const Quaternion &);

		static inline Quaternion operator+=(_In_ Quaternion &,
											_In_ const std::complex<double> &);

		static inline Quaternion operator+=(_In_ const C64 &,
										    _In_ Quaternion &);

		static inline Quaternion operator+=(_In_ Quaternion &,
											_In_ const double);

		static inline Quaternion operator+=(_In_ const double,
										    _In_ Quaternion &);

		static inline Quaternion operator-(_In_ const Quaternion &,
										   _In_ const Quaternion &);

		static inline Quaternion operator-(_In_ const Quaternion &,
										   _In_ const std::complex<double> &);

		static inline Quaternion operator-(_In_ const Quaternion &,
										   _In_ const double);

		static inline Quaternion operator-(_In_ const std::complex<double> &,
										   _In_ const Quaternion &);

		static inline Quaternion operator-(_In_ const double,
										   _In_ const Quaternion &);

		static inline Quaternion operator-=(_In_ Quaternion &,
										    _In_ const Quaternion &);

		static inline Quaternion operator-=(_In_ Quaternion &,
										    _In_ const std::complex<double> &);

		static inline Quaternion operator-=(_In_ const C64 &,
											_In_ Quaternion &);

		static inline Quaternion operator-=(_In_ Quaternion &,
										    _In_ const double);

		static inline Quaternion operator-=(_In_ const double,
									        _In_ Quaternion &);

		static inline Quaternion operator*(_In_ const Quaternion &,
										   _In_ const Quaternion &);

		static inline Quaternion operator*(_In_ const Quaternion &,
										   _In_ const std::complex<double> &);

		static inline Quaternion operator*(_In_ const Quaternion &,
										   _In_ const double);
		
		static inline Quaternion operator*(_In_ const std::complex<double> &,
										   _In_ const Quaternion &);

		static inline Quaternion operator*(_In_ const double,
										   _In_ const Quaternion &);

		static inline Quaternion operator*=(_In_ Quaternion &,
										    _In_ const Quaternion &);

		static inline Quaternion operator*=(_In_ Quaternion &,
										    _In_ const std::complex<double> &);

		static inline Quaternion operator*=(_In_ const C64 &,
									        _In_ Quaternion &);

		static inline Quaternion operator*=(_In_ Quaternion &,
										    _In_ const double );

		static inline Quaternion operator*=(_In_ const double,
										    _In_ Quaternion &);

		static inline Quaternion operator/(_In_ const Quaternion &,
										   _In_ const Quaternion &);

		static inline Quaternion operator/(_In_ const Quaternion &,
										   _In_ const std::complex<double> &);

		static inline Quaternion operator/(_In_ const Quaternion &,
										   _In_ const double);

		static inline Quaternion operator/(_In_ const std::complex<double> &,
										   _In_ const Quaternion &);

		static inline Quaternion operator/(_In_ const double,
										   _In_ const Quaternion &);

		static inline Quaternion operator/=(_In_ Quaternion &,
											_In_ const Quaternion &);

		static inline Quaternion operator/=(_In_ Quaternion &,
										    _In_ const std::complex<double> &);

		static inline Quaternion operator/=(_In_ const C64 &,
									        _In_ Quaternion &);

		static inline Quaternion operator/=(_In_ Quaternion &,
										    _In_ const double);

		static inline Quaternion operator/=(_In_ const double,
										    _In_ Quaternion &);

		static inline bool       operator==(_In_ const Quaternion &,
										    _In_ const Quaternion &);

		static inline bool       operator==(_In_ const Quaternion &,
											_In_ const std::complex<double> &);

		static inline bool       operator==(_In_ const Quaternion &,
											_In_ const double);

		static inline bool       operator==(_In_ const std::complex<double> &,
										    _In_ const Quaternion &);

		static inline bool       operator==(_In_ const double,
											_In_ const Quaternion &);

		static inline bool       operator!=(_In_ const Quaternion &,
										    _In_ const Quaternion &);

		static inline bool       operator!=(_In_ const Quaternion &,
										    _In_ const std::complex<double> &);

		static inline bool       operator!=(_In_ const Quaternion &,
										    _In_ const double);

		static inline bool       operator!=(_In_ const std::complex<double> &,
										    _In_ const Quaternion &);

		static inline bool       operator!=(_In_ const double,
											_In_ const Quaternion &);

		static inline bool       operator>(_In_ const Quaternion &,
									       _In_ const Quaternion &);

		static inline bool       operator>=(_In_ const Quaternion &,
										    _In_ const Quaternion &);

		static inline bool       operator<(_In_ const Quaternion &,
										   _In_ const Quaternion &);

		static inline bool       operator<=(_In_ const Quaternion &,
										    _In_ const Quaternion &);

		//
		// Free-standing functions operating on
		// various Quaternion-related characteristics like:
		// Norm, Vector part norm, conjugate,distance ...etc
		//

		static inline Quaternion conjugate(_In_ const Quaternion &);

		static inline double norm(_In_ const Quaternion &);

		static inline double vnorm(_In_ const Quaternion &);

		static inline double distance(_In_ const Quaternion &,
								      _In_ const Quaternion &);

		static inline Quaternion unit(_In_ const Quaternion &);

		static inline Quaternion polar_decomp(_In_ const Quaternion &);

		static inline Quaternion reciprocal(_In_ const Quaternion &);

		static inline void mat4x4(_In_ const Quaternion &,
						          _Out_ double (&m4x4)[4][4],
								  _In_ const int32_t );

		static inline Quaternion exp(_In_ const Quaternion &);

		static inline Quaternion ln(_In_ const Quaternion &);

		//
		// Based on  boost::quaternion
		//
		static inline Quaternion spherical(_In_ const double,
								    _In_ const double,
									_In_ const double,
									_In_ const double);

		static inline Quaternion semipolar(_In_ const double,
								    _In_ const double,
									_In_ const double,
									_In_ const double);

		static inline Quaternion multipolar(_In_ const double,
									 _In_ const double,
									 _In_ const double,
									 _In_ const double);

		static inline Quaternion cylindrospherical(_In_ const double,
										    _In_ const double,
											_In_ const double,
											_In_ const double);

		static inline Quaternion cylindrical(_In_ const double,
									  _In_ const double,
									  _In_ const double,
									  _In_ const double);

		

#include "LAM_quaternion.inl"
	}
}

#endif /*__LAM_QUATERNION_H__*/
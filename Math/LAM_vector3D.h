
#ifndef __LAM_VECTOR3D_H__
#define __LAM_VECTOR3D_H__

#if !defined (LAM_VECTOR3D_MAJOR)
#define LAM_VECTOR3D_MAJOR 1
#endif

#if !defined (LAM_VECTOR3D_MINOR)
#define LAM_VECTOR3D_MINOR 0
#endif

#if !defined (LAM_VECTOR3D_MICRO)
#define LAM_VECTOR3D_MICRO 0
#endif

#if !defined (LAM_VECTOR3D_FULLVER)
#define LAM_VECTOR3D_FULLVER 1000
#endif

#if !defined (LAM_VECTOR3D_CREATE_DATE)
#define LAM_VECTOR3D_CREATE_DATE "16-12-2017 09:41 +00200 (SAT 16 DEC 2017 GMT+2)"
#endif
//
// Set this value after successful compilation.
//
#if !defined (LAM_VECTOR3D_BUILD_DATE)
#define LAM_VECTOR3D_BUILD_DATE " "
#endif

#if !defined (LAM_VECTOR3D_AUTHOR)
#define LAM_VECTOR3D_AUTHOR "Programmer: Bernard Gingold e-mail: beniekg@gmail.com"
#endif

#if !defined (LAM_VECTOR3D_DESCRIPT)
#define LAM_VECTOR3D_DESCRIPT "Implementation of Vector 3D."
#endif

#include <iosfwd>
#include <iomanip>
#include <cstdint>

namespace lam {
	namespace math{

#if !defined (CHECK_VECTOR3D_LEPS)
#define CHECK_VECTOR3D_LEPS(value)  \
		do {						\
		    if ((value) <= std::numeric_limits<double>::epsilon()) \
		             (value) += std::numeric_limits<double>::epsilon();    \
		} while (0);
#endif

#if !defined (CHECK_VECTOR3D_NAN)
#define CHECK_VECTOR3D_NAN(x,y,z,bres) \
		do {					  \
		   if ((x) == std::isnan((x)) || { \
		       (y) == std::isnan((y)) ||  \
		       (z) == std::isnan((z))) {   \
			    std::cerr << "Detected: NAN at line: " << \
				 __LINE__ << " at virtual address:" << std::hex << \
				 "0x" << __FUNCTIONW__ << " in file: " << __FILE__ << "\n"; \
				 std::cerr << "x= " << (x) << \
				              "y= " << (y) << \
							  "z= " << (z) << "\n"; \
			} \
		} while (0);
#endif

#if !defined (LAM_VECTOR3D_ACCESSOR_GENERATOR)
#define LAM_VECTOR3D_ACCESSOR_GENERATOR     \
	inline double get_x() const {			\
	    return (m_x);						  \
	}										  \
	inline double get_y() const {			 \
	    return (m_y);					    \
	}										\
	inline double get_z() const {			\
		return (m_z);						\
	}										\
	inline const double * get_ptr()	 const  { \
		const double * ptr = reinterpret_cast<const double*>(&this->m_x); \
		return (ptr);														\
	}							
#endif

#if !defined (LAM_VECTOR3D_CTORS_GENERATOR)
#define LAM_VECTOR3D_CTORS_GENERATOR      \
										  \
		Vector3D();				          \
										  \
		Vector3D(_In_ const double,       \
				 _In_ const double,       \
				 _In_ const double);      \
										  \
	explicit Vector3D(_In_ const double); \
										  \
	 Vector3D(_In_ const Vector3D &);     
#endif


	class Vector3D {

			
			public:

			LAM_VECTOR3D_CTORS_GENERATOR
		    
			~Vector3D() = default;

			LAM_VECTOR3D_ACCESSOR_GENERATOR

			// Member operators

			Vector3D & operator=(_In_ const Vector3D &);

			const double operator[](_In_ const uint32_t) const;

			friend	std::ostream & operator<<(_In_ std::ostream &,
											  _In_ const Vector3D &);
			private:

			// Vector components
			double m_x;

			double m_y;

			double m_z;
		};

// Getters macro

#if !defined (V3D_X)
#define V3D_X(obj) obj.get_x()
#endif

#if !defined (V3D_Y)
#define V3D_Y(obj) obj.get_y()
#endif

#if !defined (V3D_Z)
#define V3D_Z(obj) obj.get_z()
#endif

	// Global operators

	static inline Vector3D operator+(_In_ const Vector3D &,
									 _In_ const Vector3D &);

	static inline Vector3D operator+(_In_ const Vector3D &,
									 _In_ const double);

	static inline Vector3D operator+(_In_ const double,
									 _In_ const Vector3D &);

	static inline Vector3D operator+=(_In_ Vector3D &,
								      _In_ const Vector3D &);

	static inline Vector3D operator+=(_In_ Vector3D &,
									  _In_ const double);

	static inline Vector3D operator+=(_In_ const double,
								      _In_ Vector3D &);

	static inline Vector3D operator-(_In_ const Vector3D &,
								     _In_ const Vector3D &);

	static inline Vector3D operator-(_In_ const Vector3D &,
									 _In_ const double);

	static inline Vector3D operator-(_In_ const double,
									 _In_ const Vector3D &);

	static inline Vector3D operator-=(_In_ Vector3D &,
									  _In_ const Vector3D &);

	static inline Vector3D operator-=(_In_ Vector3D &,
									  _In_ const double);

	static inline Vector3D operator-=(_In_ const double,
									  _In_ Vector3D &);

	static inline Vector3D operator*(_In_ const Vector3D &,
									 _In_ const Vector3D &);

	static inline Vector3D operator*(_In_ const Vector3D &,
									 _In_ const double);

	static inline Vector3D operator*(_In_ const double,
									 _In_ const Vector3D &);

	static inline Vector3D operator*=(_In_ Vector3D &,
								      _In_ const Vector3D &);

	static inline Vector3D operator*=(_In_ Vector3D &,
								      _In_ const double);

	static inline Vector3D operator*=(_In_ const double,
									  _In_ Vector3D &);

	static inline Vector3D operator/(_In_ const Vector3D &,
									 _In_ const Vector3D &);

	static inline Vector3D operator/(_In_ const Vector3D &,
									 _In_ const double);

	static inline Vector3D operator/(_In_ const double,
									 _In_ const Vector3D &);

	static inline Vector3D operator/=(_In_ Vector3D &,
									  _In_ const Vector3D &);

	static inline Vector3D operator/=(_In_ Vector3D &,
									  _In_ const double);

	static inline Vector3D operator/=(_In_ const double,
									  _In_ Vector3D &);

	static inline bool operator==(_In_ const Vector3D &,
								  _In_ const Vector3D &);

	static inline bool operator==(_In_ const Vector3D &,
							      _In_ const double);

	static inline bool operator==(_In_ const double,
								  _In_ const Vector3D &);

	static inline bool operator!=(_In_ const Vector3D &,
								  _In_ const Vector3D &);

	static inline bool operator!=(_In_ const Vector3D &,
								  _In_ const double);

	static inline bool operator!=(_In_ const double,
								  _In_ const Vector3D &);

	static inline bool operator>(_In_ const Vector3D &,
							     _In_ const Vector3D &);

	static inline bool operator>(_In_ const Vector3D &,
								 _In_ const double);

	static inline bool operator>(_In_ const double,
								 _In_ const Vector3D &);

	static inline bool operator<(_In_ const Vector3D &,
								 _In_ const Vector3D &);

	static inline bool operator<(_In_ const Vector3D &,
								 _In_ const double);

	static inline bool operator<(_In_ const double,
								 _In_ const Vector3D &);

	static inline bool operator>=(_In_ const Vector3D &,
								  _In_ const Vector3D &);

	static inline bool operator>=(_In_ const Vector3D &,
								  _In_ const double);

	static inline bool operator>=(_In_ const double,
								  _In_ const Vector3D &);

	static inline bool operator<=(_In_ const Vector3D &,
								  _In_ const Vector3D &);

	static inline bool operator<=(_In_ const Vector3D &,
								  _In_ const double);

	static inline bool operator<=(_In_ const double,
								  _In_ const Vector3D &);

	static inline double dot(_In_ const Vector3D &,
						     _In_ const Vector3D &);

	static inline double abs_dot(_In_ const Vector3D &,
								 _In_ const Vector3D &);

	static inline Vector3D cross(_In_ const Vector3D &,
								 _In_ const Vector3D &);

	static inline double tri_prod(_In_ const Vector3D &,
								    _In_ const Vector3D &,
									_In_ const Vector3D &);

	static inline Vector3D dir_cos(_In_ const Vector3D &);

	static inline double norm(_In_ const Vector3D &);

	static inline Vector3D normalize(_In_ const Vector3D &);



#include "LAM_vector3D.inl"
	}
}

#endif /*__LAM_VECTOR3D_H__*/

//
//	Implementation
//

lam::math::
Quaternion::Quaternion()
:
m_x{0.0E+00},
m_y{0.0E+00},
m_z{0.0e+00},
m_w{0.0E+00} {}

lam::math::
Quaternion::Quaternion(_In_ const double a)
:
m_x{ a },
m_y{ 0.0E+00 },
m_z{ 0.0E+00 },
m_w{ 0.0E+00 } {}

lam::math::
Quaternion::Quaternion(_In_ const double b,
					   _In_ const double c,
					   _In_ const double d)
:
m_x{ 0.0E+00 },
m_y{ b },
m_z{ c },
m_w{ d } {}

lam::math::
Quaternion::Quaternion(_In_ const double x,
					   _In_ const double y,
					   _In_ const double z,
					   _In_ const double w)
:
m_x{ x },
m_y{ y },
m_z{ z },
m_w{ w }  {}

lam::math::
Quaternion::Quaternion(_In_ const std::complex<double> &c1,
					   _In_ const std::complex<double> &c2)
:
m_x{ c1.real() },
m_y{ c1.imag() },
m_z{ c2.real() },
m_w{ c2.imag() } {}

lam::math::
Quaternion::Quaternion(_In_ const Quaternion &q)
:
m_x{ q.m_x },
m_y{ q.m_y },
m_z{ q.m_z },
m_w{ q.m_w }  {}

lam::math::Quaternion &
lam::math::Quaternion::operator=(_In_ const Quaternion &q) {
	if (this == &q) return (*this);
	m_x = q.m_x;
	m_y = q.m_y;
	m_z = q.m_z;
	m_w = q.m_w;
	return (*this);
}

lam::math::Quaternion &
lam::math::Quaternion::operator=(_In_ const double s) {
	m_x = s;
	m_y = 0.0E+00;
	m_z = 0.0E+00;
	m_w = 0.0E+00;
	return (*this);
}

lam::math::Quaternion &
lam::math::Quaternion::operator=(_In_ const C64 &c) {
	m_x = c.real();
	m_y = c.imag();
	m_z = 0.0E+00;
	m_w = 0.0E+00;
	return (*this);
}

std::ostream &
lam::math::operator<<(_In_ std::ostream &os,
					  _In_ const Quaternion &q) {
	os << std::fixed << std::setprecision(15) <<
		"x = " << "{" << q.get_x() << "}" <<
		"y = " << "{" << q.get_y() << "}" <<
		"z = " << "{" << q.get_z() << "}" <<
		"w = " << "{" << q.get_w() << "}" << "\n";
	return (os);
}

const double
lam::math::Quaternion::operator[](_In_ const uint32_t idx) const {
	_ASSERT(idx > 0 && idx <= 3);
	return (reinterpret_cast<const double*>(this)[idx]);
}

lam::math::Quaternion
lam::math::operator+(_In_ const Quaternion &q1,
				     _In_ const Quaternion &q2) {
	return (Quaternion{ Q_x(q1) + Q_x(q2),
						Q_y(q1) + Q_y(q2),
						Q_z(q1) + Q_z(q2),
						Q_w(q1) + Q_w(q2) });
}

lam::math::Quaternion
lam::math::operator+(_In_ const Quaternion &q,
_In_ const std::complex<double> &c) {
	return (Quaternion{ Q_x(q) + c.real(),
						Q_y(q) + c.imag(),
						Q_z(q) + c.real(),
						Q_w(q) + c.imag() });
}

lam::math::Quaternion
lam::math::operator+(_In_ const Quaternion &q,
					 _In_ const double s) {
	return (Quaternion{ Q_x(q) + s,
						Q_y(q) + s,
						Q_z(q) + s,
						Q_w(q) + s });
}

lam::math::Quaternion
lam::math::operator+(_In_ const std::complex<double> &c,
					 _In_ const Quaternion &q) {
	return (Quaternion{ c.real() + Q_x(q),
						c.imag() + Q_y(q),
						c.real() + Q_z(q),
						c.imag() + Q_w(q) });
}

lam::math::Quaternion
lam::math::operator+(_In_ const double s,
					 _In_ const Quaternion &q) {
	return (Quaternion{ s + Q_x(q),
					    s + Q_y(q),
						s + Q_z(q),
						s + Q_w(q) });
}

lam::math::Quaternion
lam::math::operator+=(_In_ Quaternion &q1,
					  _In_ const Quaternion &q2) {
	q1 = q1 + q2;
	return (q1);
}

lam::math::Quaternion
lam::math::operator+=(_In_ Quaternion &q,
					  _In_ const std::complex<double> &c) {
	q = q + c;
	return (q);
}

lam::math::Quaternion
lam::math::operator+=(_In_ const C64 &c,
					  _In_ Quaternion &q) {
	q = c / q;
	return (q);
}

lam::math::Quaternion
lam::math::operator+=(_In_ Quaternion &q,
					  _In_ const double s) {
	q = q + s;
	return (q);
}

lam::math::Quaternion
lam::math::operator+=(_In_ const double s,
					  _In_ Quaternion &q) {
	q = s / q;
	return (q);
}

lam::math::Quaternion
lam::math::operator-(_In_ const Quaternion &q1,
					 _In_ const Quaternion &q2) {
	return (Quaternion{ Q_x(q1) - Q_x(q2),
					    Q_y(q1) - Q_y(q2),
						Q_z(q1) - Q_z(q2),
						Q_w(q1) - Q_w(q2) });
}

lam::math::Quaternion
lam::math::operator-(_In_ const Quaternion &q,
					 _In_ const C64 &c) {
	return (Quaternion{ Q_x(q) - c.real(),
						Q_y(q) - c.imag(),
						Q_z(q) - c.real(),
						Q_w(q) - c.imag() });
}

lam::math::Quaternion
lam::math::operator-(_In_ const Quaternion &q,
					 _In_ const double s) {
	return (Quaternion{ Q_x(q)-s,
						Q_y(q) - s,
						Q_z(q) - s,
						Q_w(q) - s });
}

lam::math::Quaternion
lam::math::operator-(_In_ const C64 &c,
					 _In_ const Quaternion &q) {
	return (Quaternion{ c.real() - Q_x(q),
						c.imag() - Q_y(q),
						c.real() - Q_z(q),
						c.imag() - Q_w(q) });
}

lam::math::Quaternion
lam::math::operator-(_In_ const double s,
					 _In_ const Quaternion &q) {
	return (Quaternion{ s - Q_x(q),
						s - Q_y(q),
						s - Q_z(q),
						s - Q_w(q) });
}

lam::math::Quaternion
lam::math::operator-=(_In_ Quaternion &q1,
					  _In_ const Quaternion &q2) {
	q1 = q1 - q2;
	return (q1);
}

lam::math::Quaternion
lam::math::operator-=(_In_ Quaternion &q,
					  _In_ const C64 &c) {
	q = q - c;
	return (q);
}

lam::math::Quaternion
lam::math::operator-=(_In_ const C64 &c,
				      _In_ Quaternion &q) {
	q = c - q;
	return (q);
}

lam::math::Quaternion
lam::math::operator-=(_In_ Quaternion &q,
					  _In_ const double s) {
	q = q - s;
	return (q);
}

lam::math::Quaternion
lam::math::operator-=(_In_ const double s,
					  _In_ Quaternion &q) {
	q = s - q;
	return (q);
}

lam::math::Quaternion
lam::math::operator*(_In_ const Quaternion &q1,
					 _In_ const Quaternion &q2) {
	const double x = Q_x(q1)*Q_x(q2) - Q_y(q1)*Q_y(q2) - 
					 Q_z(q1)*Q_z(q2) - Q_w(q1)*Q_w(q2);
	const double y = Q_x(q1)*Q_y(q2) + Q_y(q1)*Q_x(q2) +
					 Q_z(q1)*Q_w(q2) - Q_w(q1)*Q_w(q2);
	const double z = Q_x(q1)*Q_z(q2) - Q_y(q1)*Q_w(q2) +
					 Q_z(q1)*Q_x(q2) + Q_w(q1)*Q_y(q2);
	const double w = Q_x(q1)*Q_z(q2) + Q_y(q1)*Q_z(q2) - 
					 Q_z(q1)*Q_y(q2) + Q_z(q1)*Q_x(q2);
	return (Quaternion{x,y,z,w});
}

lam::math::Quaternion
lam::math::operator*(_In_ const Quaternion &q,
					 _In_ const C64 &c) {
	const double x = Q_x(q)*c.real() - Q_y(q)*c.imag();
	const double y = Q_x(q)*c.imag() + Q_y(q)*c.real();
	const double z = Q_z(q)*c.real() + Q_w(q)*c.imag();
	const double w = -Q_z(q)*c.imag() + Q_w(q)*c.real();
	return (Quaternion{x,y,z,w});
}

lam::math::Quaternion
lam::math::operator*(_In_ const Quaternion &q,
					 _In_ const double s) {
	return (Quaternion{ Q_x(q)*s,
						Q_y(q)*s,
						Q_z(q)*s,
						Q_w(q)*s });
}

lam::math::Quaternion
lam::math::operator*(_In_ const C64 &c,
					 _In_ const Quaternion &q) {
	const double x = c.real()*Q_x(q) - c.imag()*Q_y(q);
	const double y = c.imag()*Q_x(q) + c.real()*Q_y(q);
	const double z = c.real()*Q_z(q) + c.imag()*Q_w(q);
	const double w = c.imag()*(-Q_z(q)) + c.real()*Q_w(q);
	return (Quaternion{x,y,z,w});
}

lam::math::Quaternion
lam::math::operator*(_In_ const double s,
					 _In_ const Quaternion &q) {
	return (Quaternion{ s*Q_x(q),
						s*Q_y(q),
						s*Q_z(q),
						s*Q_w(q) });
}

lam::math::Quaternion
lam::math::operator*=(_In_ Quaternion &q1,
					  _In_ const Quaternion &q2) {
	q1 = q1 * q2;
	return (q1);
}

lam::math::Quaternion
lam::math::operator*=(_In_ Quaternion &q,
					  _In_ const C64 &c) {
	q = q * c;
	return (q);
}

lam::math::Quaternion
lam::math::operator*=(_In_ const C64 &c,
					  _In_ Quaternion &q) {
	q = c * q;
	return (q);
}

lam::math::Quaternion
lam::math::operator*=(_In_ Quaternion &q,
					  _In_ const double s) {
	q = q * s;
	return (q);
}

lam::math::Quaternion
lam::math::operator*=(_In_ const double s,
					  _In_ Quaternion &q) {
	q = s * q;
	return (q);
}

lam::math::Quaternion
lam::math::operator/(_In_ const Quaternion &q1,
					 _In_ const Quaternion &q2) {
	const double denom = Q_x(q2)*Q_x(q2) + Q_y(q2)*Q_y(q2) + 
						 Q_z(q2)*Q_z(q2) + Q_w(q2)*Q_w(q2);
	const double x = (Q_x(q1)*Q_x(q1) + Q_y(q1)*Q_y(q2)+
				      Q_z(q1)*Q_z(q2) + Q_w(q1)*Q_w(q2)) / denom;
	const double y = (-Q_x(q1)*Q_y(q2) + Q_y(q1)*Q_x(q2)-
					  Q_z(q1)*Q_w(q2) + Q_w(q1)*Q_z(q2)) / denom;
	const double z = (-Q_x(q1)*Q_z(q2) + Q_y(q1)*Q_w(q2)+
					  Q_z(q1)*Q_x(q2) - Q_w(q1)*Q_y(q2)) / denom;
	const double w = (-Q_x(q1)*Q_w(q2) - Q_y(q1)*Q_z(q2)+
					  Q_z(q1)*Q_y(q2) + Q_w(q1)*Q_x(q2)) / denom;
	return (Quaternion{x,y,z,w});
}

lam::math::Quaternion
lam::math::operator/(_In_ const Quaternion &q,
					 _In_ const C64 &c) {
	const double denom = c.real()*c.real() + 
						 c.imag()*c.imag();
	const double x = (Q_x(q)*c.real() + Q_y(q)*c.imag())/denom;
	const double y = (-Q_x(q)*c.imag() + Q_y(q)*c.real())/denom;
	const double z = (Q_z(q)*c.real() - Q_w(q)*c.imag())/denom;
	const double w = (Q_z(q)*c.imag() + Q_w(q)*c.real()) / denom;
	return (Quaternion{x,y,z,w});
}

lam::math::Quaternion
lam::math::operator/(_In_ const Quaternion &q,
					 _In_ const double s) {
	return (Quaternion{ Q_x(q) / s,
						Q_y(q) / s,
						Q_z(q) / s,
						Q_w(q) / s });
}

lam::math::Quaternion
lam::math::operator/(_In_ const C64 &c,
					 _In_ const Quaternion &q) {
	const double denom = c.real()*c.real() +
						 c.imag()*c.imag();
	const double x = (c.real()*Q_x(q) + Q_y(q)*c.imag())/denom;
	const double y = (c.imag()*(-Q_x(q)) + Q_y(q)*c.real())/denom;
	const double z = (c.real()*Q_z(q) - c.imag()*Q_w(q))/denom;
	const double w = (c.imag()*Q_z(q) + c.real()*Q_w(q)) / denom;
	return (Quaternion{x,y,z,w});
}

lam::math::Quaternion
lam::math::operator/(_In_ const double s,
					 _In_ const Quaternion &q) {
	return (Quaternion{ s / Q_x(q),
						s / Q_y(q),
						s / Q_z(q),
						s / Q_w(q) });
}

lam::math::Quaternion
lam::math::operator/=(_In_ Quaternion &q1,
					  _In_ const Quaternion &q2) {
	q1 = q1 / q2;
	return (q1);
}

lam::math::Quaternion
lam::math::operator/=(_In_ Quaternion &q,
					  _In_ const C64 &c) {
	q = q / c;
	return (q);
}

lam::math::Quaternion
lam::math::operator/=(_In_ const C64 &c,
					  _In_ Quaternion &q) {
	q = c / q;
	return (q);
}

lam::math::Quaternion
lam::math::operator/=(_In_ Quaternion &q,
					  _In_ const double s) {
	q = q / s;
	return (q);
}

lam::math::Quaternion
lam::math::operator/=(_In_ const double s,
					  _In_ Quaternion &q) {
	q = s / q;
	return (q);
}

bool
lam::math::operator==(_In_ const Quaternion &q1,
					  _In_ const Quaternion &q2) {
	return (Q_x(q1) == Q_x(q2)     &&
		    Q_y(q1) == Q_y(q2)     &&
		    Q_z(q1) == Q_z(q2)     &&
		    Q_w(q1) == Q_w(q2));
}

bool
lam::math::operator==(_In_ const Quaternion &q,
					  _In_ const C64 &c) {
	return (Q_x(q) == c.real()     &&
			Q_y(q) == c.imag()     &&
		    Q_z(q) == 0.0          &&
		    Q_w(q) == 0.0);
}

bool
lam::math::operator==(_In_ const Quaternion &q,
					  _In_ const double s) {
	return (Q_x(q) == s      &&
		    Q_y(q) == 0.0    &&
		    Q_z(q) == 0.0    &&
		    Q_w(q) == 0.0);
}

bool
lam::math::operator==(_In_ const C64 &c,
					  _In_ const Quaternion &q) {
	return (c.real() == Q_x(q) &&
		    c.imag() == Q_y(q) &&
		    0.0 == Q_z(q)      &&
		    0.0 == Q_w(q));
}

bool
lam::math::operator==(_In_ const double s,
					  _In_ const Quaternion &q) {
	return (s == Q_x(q) &&
		    0.0 == Q_y(q) &&
		    0.0 == Q_z(q) &&
		    0.0 == Q_w(q));
}

bool
lam::math::operator!=(_In_ const Quaternion &q1,
					  _In_ const Quaternion &q2) {
	return (!(q1 == q2));
}

bool
lam::math::operator!=(_In_ const Quaternion &q1,
					  _In_ const C64 &c) {
	return (!(q1 == c));
}

bool
lam::math::operator!=(_In_ const Quaternion &q1,
					  _In_ const double s) {
	return(!(q1 == s));
}

bool
lam::math::operator!=(_In_ const C64 &c,
					  _In_ const Quaternion &q) {
	return (!(c == q));
}

bool
lam::math::operator!=(_In_ const double s,
					  _In_ const Quaternion &q) {
	return (!(s == q));
}

bool
lam::math::operator>(_In_ const Quaternion &q1,
					 _In_ const Quaternion &q2) {
	return (Q_x(q1) > Q_x(q2) &&
			Q_y(q1) > Q_y(q2) &&
			Q_z(q1) > Q_z(q2) &&
			Q_w(q1) > Q_w(q2));
}

bool
lam::math::operator<(_In_ const Quaternion &q1,
					 _In_ const Quaternion &q2) {
	return (Q_x(q1) < Q_x(q2) &&
			Q_y(q1) < Q_y(q2) &&
			Q_z(q1) < Q_z(q2) &&
			Q_w(q1) < Q_w(q2));
}

bool
lam::math::operator>=(_In_ const Quaternion &q1,
					  _In_ const Quaternion &q2) {
	return (Q_x(q1) >= Q_y(q2) &&
			Q_y(q1) >= Q_y(q2)    &&
			Q_z(q1) >= Q_z(q2)   &&
			Q_w(q1) >= Q_w(q2) );
}

bool
lam::math::operator<=(_In_ const Quaternion &q1,
					  _In_ const Quaternion &q2) {
	return (Q_x(q1) <= Q_y(q2) &&
		    Q_y(q1) <= Q_y(q2) &&
		    Q_z(q1) <= Q_z(q2) &&
		    Q_w(q1) <= Q_w(q2));
}

lam::math::Quaternion
lam::math::conjugate(_In_ const Quaternion &q) {
	return (Quaternion{ Q_x(q), -Q_y(q),
					   -Q_z(q), -Q_w(q) });
}

double
lam::math::norm(_In_ const Quaternion &q) {
	return (std::sqrt(Q_SQR(Q_x(q))+
					  Q_SQR(Q_y(q))+
					  Q_SQR(Q_z(q))+
					  Q_SQR(Q_w(q))));
}

double
lam::math::vnorm(_In_ const Quaternion &q) {
	return (std::sqrt(Q_SQR(Q_y(q))+
					  Q_SQR(Q_z(q))+
					  Q_SQR(Q_w(q))));
}

double
lam::math::distance(_In_ const Quaternion &q1,
					_In_ const Quaternion &q2) {
	double dx = (Q_x(q1) - Q_x(q2)) * (Q_x(q1) - Q_x(q2));
	double dy = (Q_y(q1) - Q_y(q2)) * (Q_y(q1) - Q_y(q2));
	double dz = (Q_z(q1) - Q_z(q2)) * (Q_z(q1) - Q_z(q2));
	double dw = (Q_w(q1) - Q_w(q2)) * (Q_w(q1) - Q_w(q2));
	return (std::sqrt(dx+dy+dz+dw));
}

lam::math::Quaternion
lam::math::unit(_In_ const Quaternion &q) {
	double t = norm(q);
	if (t < std::numeric_limits<double>::epsilon())
		t = std::numeric_limits<double>::epsilon();
	return (q / t);
}

lam::math::Quaternion
lam::math::polar_decomp(_In_ const Quaternion &q) {
	Quaternion tq = unit(q);
	double t = norm(q);
	return (tq * t);
}

lam::math::Quaternion
lam::math::reciprocal(_In_ const Quaternion &q) {
	Quaternion tq = conjugate(q);
	double t = norm(q);
	return (tq / (t*t));
}

void
lam::math::mat4x4(_In_ const Quaternion &q,
				  _Out_ double(&m4x4)[4][4],
				  _In_ const int32_t mtype) {
	
	if (mtype == 0) {
		m4x4[0][0] =  Q_x(q);
		m4x4[0][1] = -Q_y(q);
		m4x4[0][2] = -Q_z(q);
		m4x4[0][3] = -Q_w(q);
		m4x4[1][0] =  Q_y(q);
		m4x4[1][1] =  Q_x(q);
		m4x4[1][2] = -Q_w(q);
		m4x4[1][3] =  Q_z(q);
		m4x4[2][0] =  Q_z(q);
		m4x4[2][1] =  Q_w(q);
		m4x4[2][2] =  Q_x(q);
		m4x4[2][3] = -Q_y(q);
		m4x4[3][0] =  Q_w(q);
		m4x4[3][1] = -Q_z(q);
		m4x4[3][2] =  Q_y(q);
		m4x4[3][3] =  Q_x(q);
	}
	else if (mtype == 1) {
		m4x4[0][0] =  Q_x(q);
		m4x4[0][1] =  Q_y(q);
		m4x4[0][2] =  Q_z(q);
		m4x4[0][3] =  Q_w(q);
		m4x4[1][0] = -Q_y(q);
		m4x4[1][1] =  Q_x(q);
		m4x4[1][2] = -Q_w(q);
		m4x4[1][3] =  Q_z(q);
		m4x4[2][0] = -Q_z(q);
		m4x4[2][1] =  Q_w(q);
		m4x4[2][2] =  Q_x(q);
		m4x4[2][3] = -Q_y(q);
		m4x4[3][0] = -Q_w(q);
		m4x4[3][1] = -Q_z(q);
		m4x4[3][2] =  Q_y(q);
		m4x4[3][3] =  Q_x(q);
	}
}

lam::math::Quaternion
lam::math::exp(_In_ const Quaternion &q) {
	double t1 = std::exp(q.real());
	double t2 = vnorm(q);
	CHECK_QUATERNION_LEPS(t2)
	double s1 = q.get_y();
	double s2 = q.get_z();
	double s3 = q.get_w();
	s1 = s1 / t2 * std::sin(t2);
	s2 = s2 / t2 * std::sin(t2);
	s3 = s3 / t2 * std::sin(t2);
	return (Quaternion{ t1*std::cos(t2),
					    t1*s1,
						t1*s2,
						t1*s3 });
}

lam::math::Quaternion
lam::math::ln(_In_ const Quaternion &q) {
	double t1 = std::log(norm(q));
	CHECK_QUATERNION_LEPS(t1)
	double t2 = vnorm(q);
	double s1 = Q_y(q);
	double s2 = Q_z(q);
	double s3 = Q_w(q);
	s1 = s1 / t2 * std::acos(Q_x(q)/t2);
	s2 = s2 / t2 * std::acos(Q_x(q)/t2);
	s3 = s3 / t2 * std::acos(Q_x(q) / t2);
	return (Quaternion{t1, s1,s2,s3});
}

lam::math::Quaternion
lam::math::spherical(_In_ const double rho,
					 _In_ const double theta,
					 _In_ const double phi1,
					 _In_ const double phi2) {
	
	double ONE = 1.0;
	const double w = std::sin(phi2);
	ONE *= std::cos(phi2);
	double z = std::sin(phi1) * ONE;
	ONE *= std::cos(phi1);
	return (Quaternion{ std::cos(theta)*ONE,
						std::sin(theta)*ONE,
						z,w });
}

lam::math::Quaternion
lam::math::semipolar(_In_ const double rho,
					 _In_ const double alpha,
					 _In_ const double theta1,
				     _In_ const double theta2) {
	
	const double x = std::cos(alpha)*std::cos(theta1);
	const double y = std::cos(alpha)*std::sin(theta1);
	const double z = std::sin(alpha)*std::cos(theta2);
	const double w = std::sin(alpha)*std::sin(theta2);
	return (rho*Quaternion{x,y,z,w});
}

lam::math::Quaternion
lam::math::multipolar(_In_ const double rho1,
					  _In_ const double theta1,
					  _In_ const double rho2,
					  _In_ const double theta2) {
	
	const double x = rho1*std::cos(theta1);
	const double y = rho1*std::sin(theta1);
	const double z = rho2*std::cos(theta2);
	const double w = rho2*std::sin(theta2);
	return (Quaternion{x,y,z,w});
}

lam::math::Quaternion
lam::math::cylindrospherical(_In_ const double t,
							 _In_ const double rad,
							 _In_ const double lat,
							 _In_ const double lon) {
	
	const double y = rad*std::cos(lon)*std::cos(lat);
	const double z = rad*std::sin(lon)*std::cos(lat);
	const double w = rad*std::sin(lat);
	return (Quaternion{t,y,z,w});
}

lam::math::Quaternion
lam::math::cylindrical(_In_ const double r,
					   _In_ const double angle,
					   _In_ const double h1,
					   _In_ const double h2) {
	
	const double x = r*std::cos(angle);
	const double y = r*std::sin(angle);
	return (Quaternion{x,y,h1,h2});
}



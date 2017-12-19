
//
//	Implementation
//

lam::math::
Vector3D::Vector3D()
:
m_x{},
m_y{},
m_z{} {}

lam::math::
Vector3D::Vector3D(_In_ const double x,
				   _In_ const double y,
				   _In_ const double z)
:
m_x{ x },
m_y{ y },
m_z{ z }   {}

lam::math::
Vector3D::Vector3D(_In_ const double x)
:
m_x{ x },
m_y{},
m_z{} {}

lam::math::
Vector3D::Vector3D(_In_ const Vector3D &v)
:
m_x{ v.m_x },
m_y{ v.m_y },
m_z{ v.m_z } {}

lam::math::Vector3D &
lam::math::Vector3D::operator=(_In_ const Vector3D &v) {
	if (this == &v) return (*this);
	m_x = v.m_x;
	m_y = v.m_y;
	m_z = v.m_z;
	return (*this);
}

const double
lam::math::Vector3D::operator[](_In_ const uint32_t idx) const {
	_ASSERT(idx >= 0 && idx <= 2);
	return (reinterpret_cast<const double*>(&this->m_x)[idx]);
}

std::ostream &
lam::math::operator<<(_In_ std::ostream &os,
					  _In_ const Vector3D &v) {
	os << std::fixed << std::scientific <<
		  std::setprecision(15) <<
		  "Component x= " << V3D_X(v) <<
		  "Component y= " << V3D_Y(v) <<
		  "Component z= " << V3D_Z(v) << "\n";
	return (os);
}

lam::math::Vector3D
lam::math::operator+(_In_ const Vector3D &v1,
					 _In_ const Vector3D &v2) {
	return (Vector3D{ V3D_X(v1) + V3D_X(v2),
					  V3D_Y(v1) + V3D_Y(v2),
					  V3D_Z(v1) + V3D_Z(v2)});
}

lam::math::Vector3D
lam::math::operator+(_In_ const Vector3D &v,
					 _In_ const double s) {
	return (Vector3D{ V3D_X(v) + s,
					  V3D_Y(v) + s,
					  V3D_Z(v) + s });
}

lam::math::Vector3D
lam::math::operator+(_In_ const double s,
					 _In_ const Vector3D &v) {
	return (Vector3D{ s + V3D_X(v),
		              s + V3D_Y(v),
		              s + V3D_Z(v) });
}

lam::math::Vector3D
lam::math::operator+=(_In_ Vector3D &v1,
					  _In_ const Vector3D &v2) {
	v1 = v1 + v2;
	return (v1);
}

lam::math::Vector3D
lam::math::operator+=(_In_ Vector3D &v,
					  _In_ const double s) {
	v = v + s;
	return (v);
}

lam::math::Vector3D
lam::math::operator+=(_In_ const double s,
					  _In_ Vector3D &v) {
	v = s + v;
	return (v);
}

lam::math::Vector3D
lam::math::operator-(_In_ const Vector3D &v1,
					 _In_ const Vector3D &v2) {
	return (Vector3D{ V3D_X(v1) - V3D_X(v2),
					  V3D_Y(v1) - V3D_Y(v2),
					  V3D_Z(v1) - V3D_Z(v2) });
}

lam::math::Vector3D
lam::math::operator-(_In_ const Vector3D &v,
					 _In_ const double s) {
	return (Vector3D{ V3D_X(v) - s,
		              V3D_Y(v) - s ,
		              V3D_Z(v) - s});
}

lam::math::Vector3D
lam::math::operator-(_In_ const double s,
					 _In_ const Vector3D &v) {
	return (Vector3D{ s - V3D_X(v),
					  s - V3D_Y(v),
					  s - V3D_Z(v) });
}

lam::math::Vector3D
lam::math::operator-=(_In_ Vector3D &v1,
					  _In_ const Vector3D &v2) {
	v1 = v1 - v2;
	return (v1);
}

lam::math::Vector3D
lam::math::operator-=(_In_ Vector3D &v1,
					  _In_ const double s) {
	v1 = v1 - s;
	return (v1);
}

lam::math::Vector3D
lam::math::operator-=(_In_ const double s,
					  _In_ Vector3D &v) {
	v = s - v;
	return (v);
}

lam::math::Vector3D
lam::math::operator*(_In_ const Vector3D &v1,
					 _In_ const Vector3D &v2) {
	return (Vector3D{ V3D_X(v1) * V3D_X(v2),
					  V3D_Y(v1) * V3D_Y(v2),
					  V3D_Z(v1) * V3D_Z(v2) });
}

lam::math::Vector3D
lam::math::operator*(_In_ const Vector3D &v,
					 _In_ const double s) {
	return (Vector3D{ V3D_X(v) * s,
					  V3D_Y(v) * s,
					  V3D_Z(v) * s });
}

lam::math::Vector3D
lam::math::operator*(_In_ const double s,
					 _In_ const Vector3D &v) {
	return (Vector3D{ s * V3D_X(v),
					  s * V3D_Y(v),
					  s * V3D_Z(v) });
}

lam::math::Vector3D
lam::math::operator*=(_In_  Vector3D &v1,
					  _In_ const Vector3D &v2) {
	v1 = v1 * v2;
	return (v1);
}

lam::math::Vector3D
lam::math::operator*=(_In_ Vector3D &v,
					  _In_ const double s) {
	v = v * s;
	return (v);
}

lam::math::Vector3D
lam::math::operator*=(_In_ const double s,
					  _In_ Vector3D &v) {
	v = s * v;
	return (v);
}

lam::math::Vector3D
lam::math::operator/(_In_ const Vector3D &v1,
					 _In_ const Vector3D &v2) {
	return (Vector3D{V3D_X(v1) / V3D_X(v2),
					 V3D_Y(v1) / V3D_Y(v2),
					 V3D_Z(v1) / V3D_Z(v2)});
}

lam::math::Vector3D
lam::math::operator/(_In_ const Vector3D &v,
					 _In_ const double s) {
	return (Vector3D{V3D_X(v) / s,
					 V3D_Y(v) / s,
					 V3D_Z(v) / s});
}

lam::math::Vector3D
lam::math::operator/(_In_ const double s,
					 _In_ const Vector3D &v) {
	return (Vector3D{ s / V3D_X(v),
					  s / V3D_Y(v),
					  s / V3D_Z(v) });
}

lam::math::Vector3D
lam::math::operator/=(_In_  Vector3D &v1,
					  _In_ const Vector3D &v2) {
	v1 = v1 / v2;
	return (v1);
}

lam::math::Vector3D
lam::math::operator/=(_In_ Vector3D &v,
					  _In_ const double s) {
	v = v / s;
	return (v);
}

lam::math::Vector3D
lam::math::operator/=(_In_ const double s,
					   _In_ Vector3D &v) {
	v = s / v;
	return (v);
}

bool
lam::math::operator==(_In_ const Vector3D &v1,
					  _In_ const Vector3D &v2) {
	return (V3D_X(v1) == V3D_X(v2) &&
			V3D_Y(v1) == V3D_Y(v2) &&
			V3D_Z(v1) == V3D_Z(v2));
}

bool
lam::math::operator==(_In_ const Vector3D &v,
					  _In_ const double s) {
	return (V3D_X(v) == s &&
			V3D_Y(v) == 0.0E+00 &&
			V3D_Z(v) == 0.0E+00);
}

bool
lam::math::operator==(_In_ const double s,
					  _In_ const Vector3D &v) {
	return (s == V3D_X(v) &&
		0.0E+00 == V3D_Y(v) &&
		0.0E+00 == V3D_Z(v));
}

bool
lam::math::operator!=(_In_ const Vector3D &v1,
					  _In_ const Vector3D &v2) {
	
	return (!(v1 == v2));
}

bool
lam::math::operator!=(_In_ const Vector3D &v,
					  _In_ const double s) {
	return (!(v == s));
}

bool
lam::math::operator!=(_In_ const double s,
					  _In_ const Vector3D &v) {
	return (!(s == v));
}

bool
lam::math::operator>(_In_ const Vector3D &v1,
					 _In_ const Vector3D &v2) {
	return (V3D_X(v1) > V3D_X(v2) &&
			V3D_Y(v1) > V3D_Y(v2) &&
			V3D_Z(v1) > V3D_Z(v2));
}

bool
lam::math::operator>(_In_ const Vector3D &v1,
				     _In_ const double s) {
	return (V3D_X(v1) > s &&
			V3D_Y(v1) > 0.0E+00 &&
			V3D_Z(v1) > 0.0E+00);
}

bool
lam::math::operator>(_In_ const double s,
					 _In_ const Vector3D &v) {
	return (s > V3D_X(v) &&
			0.0E+00 > V3D_Y(v) &&
			0.0E+00 > V3D_Z(v));
}

bool
lam::math::operator<(_In_ const Vector3D &v1,
					 _In_ const Vector3D &v2) {
	return (V3D_X(v1) < V3D_X(v2) &&
			V3D_Y(v1) < V3D_Y(v2) &&
			V3D_Z(v1) < V3D_Z(v2));
}

bool
lam::math::operator<(_In_ const Vector3D &v,
					 _In_ const double s) {
	return (V3D_X(v) < s &&
			V3D_Y(v) < 0.0E+00 &&
			V3D_Z(v) < 0.0E+00);
}

bool
lam::math::operator<(_In_ const double s,
				     _In_ const Vector3D &v) {
	return (s < V3D_X(v)		&&
			0.0E+00 < V3D_Y(v)  &&
			0.0E+00 < V3D_Z(v));
}

bool
lam::math::operator>=(_In_ const Vector3D &v1,
					  _In_ const Vector3D &v2) {
	return (V3D_X(v1) >= V3D_X(v2) &&
			V3D_Y(v1) >= V3D_Y(v2) &&
			V3D_Z(v1) >= V3D_Z(v2));
}

bool
lam::math::operator>=(_In_ const Vector3D &v,
					 _In_ const double s) {
	return (V3D_X(v) >= s &&
		    V3D_Y(v) >= 0.0E+00 &&
		    V3D_Z(v) >= 0.0E+00);
}

bool
lam::math::operator>=(_In_ const double s,
					  _In_ const Vector3D &v) {
	return (s >= V3D_X(v) &&
			0.0E+00 >= V3D_Y(v) &&
			0.0E+00 >= V3D_Z(v));
}

bool
lam::math::operator<=(_In_ const Vector3D &v1,
					  _In_ const Vector3D &v2) {
	return (V3D_X(v1) <= V3D_X(v2) &&
			V3D_Y(v1) <= V3D_Y(v2) &&
			V3D_Z(v1) <= V3D_Z(v2));
}

bool
lam::math::operator<=(_In_ const Vector3D &v,
					 _In_ const double s) {
	return (V3D_X(v) <= s &&
			V3D_Y(v) <= 0.0E+00 &&
			V3D_Z(v) <= 0.0E+00);
}

bool
lam::math::operator<=(_In_ const double s,
					 _In_ const Vector3D &v) {
	return (s <= V3D_X(v) &&
		0.0E+00 <= V3D_Y(v) &&
		0.0E+00 <= V3D_Z(v));
}

double
lam::math::dot(_In_ const Vector3D &v1,
			   _In_ const Vector3D &v2) {
	return (V3D_X(v1)*V3D_X(v2) + 
		    V3D_Y(v1)*V3D_Y(v2) + 
		    V3D_Z(v1)*V3D_Z(v2));
}

double
lam::math::abs_dot(_In_ const Vector3D &v1,
				   _In_ const Vector3D &v2) {
	return (std::fabs(dot(v1,v2)));
}

lam::math::Vector3D
lam::math::cross(_In_ const Vector3D &v1,
				 _In_ const Vector3D &v2) {
	const double s0 = V3D_Y(v1)*V3D_Z(v2) - 
			          V3D_Z(v1)*V3D_Y(v2);
	const double s1 = V3D_Z(v1)*V3D_X(v2) - 
					  V3D_X(v1)*V3D_Z(v2);
	const double s2 = V3D_X(v1)*V3D_Y(v2) - 
					  V3D_Y(v1)*V3D_X(v2);
	return (Vector3D{s0,s1,s2});
}

double
lam::math::tri_prod(_In_ const Vector3D &v1,
					_In_ const Vector3D &v2,
					_In_ const Vector3D &v3) {
	const double s0 = V3D_X(v1)*(V3D_Y(v2)*V3D_Z(v3) - 
					             V3D_Z(v2)*V3D_Y(v3));
	const double s1 = V3D_Y(v1)*(V3D_Z(v2)*V3D_X(v3) -
								 V3D_X(v1)*V3D_Z(v3));
	const double s2 = V3D_Z(v2)*(V3D_X(v2)*V3D_Y(v3) - 
								 V3D_Y(v2)*V3D_X(v3));
	return (s0+s1+s2);
}

lam::math::Vector3D
lam::math::dir_cos(_In_ const Vector3D &v) {
	double n = norm(v);
	return (Vector3D{ V3D_X(v)/n,
					  V3D_Y(v) / n,
					  V3D_Z(v)/n });
}

double
lam::math::norm(_In_ const Vector3D &v) {
	return (std::sqrt(V3D_X(v)*V3D_X(v) + 
					  V3D_Y(v)*V3D_Y(v) + 
					  V3D_Z(v)*V3D_Z(v)));
}

lam::math::Vector3D
lam::math::normalize(_In_ const Vector3D &v) {
	double n = norm(v);
	return (Vector3D{ V3D_X(v) / n,
		V3D_Y(v) / n,
		V3D_Z(v) / n });
}

// Copyright 2015 J.-M. Chesneaux, P. Eberhart, F. Jezequel, J.-L. Lamotte

// This file is part of CADNA.

// CADNA is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// CADNA is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.

// You should have received a copy of the GNU Lesser General Public License
// along with CADNA.  If not, see <http://www.gnu.org/licenses/>.


#include "cadna_private.h"

/////////////////////////////////////////////////////////////////////////




std::complex<double_st> operator*(const double& a,std::complex<double_st> const& b){
  std::complex<double_st> res;
  res=(double_st)a*b;
  return res;
}
std::complex<float_st> operator*(const float& a,std::complex<float_st> const& b){
  std::complex<float_st> res;
  res=(float_st)a*b;
  return res;
}




std::complex<double_st> operator*(std::complex<double_st> const& a, double const& b){
  std::complex<double_st> res;
  res=a*(double_st)b;
  return res;
}
std::complex<float_st> operator*(std::complex<float_st> const& a, float const& b){
  std::complex<float_st> res;
  res=a*(float_st)b;
  return res;
}

/////////////////////////////////////////////////////////////////////////




std::complex<double_st> operator/(const double& a,std::complex<double_st> const& b){
  std::complex<double_st> res;
  res=(double_st)a/b;
  return res;
}
std::complex<float_st> operator/(const float& a,std::complex<float_st> const& b){
  std::complex<float_st> res;
  res=(float_st)a/b;
  return res;
}




std::complex<double_st> operator/(std::complex<double_st> const& a, double const& b){
  std::complex<double_st> res;
  res=a/(double_st)b;
  return res;
}
std::complex<float_st> operator/(std::complex<float_st> const& a, float const& b){
  std::complex<float_st> res;
  res=a/(float_st)b;
  return res;
}

/////////////////////////////////////////////////////////////////////////



std::complex<double_st> operator+(const double& a,std::complex<double_st> const& b){
  std::complex<double_st> res;
  res=(double_st)a+b;
  return res;
}
std::complex<float_st> operator+(const float& a,std::complex<float_st> const& b){
  std::complex<float_st> res;
  res=(float_st)a+b;
  return res;
}




std::complex<double_st> operator+(std::complex<double_st> const& a, double const& b){
  std::complex<double_st> res;
  res=a+(double_st)b;
  return res;
}
std::complex<float_st> operator+(std::complex<float_st> const& a, float const& b){
  std::complex<float_st> res;
  res=a+(float_st)b;
  return res;
}

/////////////////////////////////////////////////////////////////////////



std::complex<double_st> operator-(const double& a,std::complex<double_st> const& b){
  std::complex<double_st> res;
  res=(double_st)a-b;
  return res;
}
std::complex<float_st> operator-(const float& a,std::complex<float_st> const& b){
  std::complex<float_st> res;
  res=(float_st)a-b;
  return res;
}




std::complex<double_st> operator-(std::complex<double_st> const& a, double const& b){
  std::complex<double_st> res;
  res=a-(double_st)b;
  return res;
}
std::complex<float_st> operator-(std::complex<float_st> const& a, float const& b){
  std::complex<float_st> res;
  res=a-(float_st)b;
  return res;
}

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

///////////////////////////////////////////////////
//****m* cadna_ne/operator!=
//    NAME
//      operator!=
//    SYNOPSIS
//      res = a != b
//    FUNCTION
//      Define all the functions involving at least one argument
//      of stochastic type which overload the "/=" operator.
//
//    INPUTS
//      a           - an integer, a float, a double or a stochastic number
//      b           - an integer, a float, a double or a stochastic number
//      At least one argument must be of stochastic type.
//    RESULT
//      res         - an integer value
//
//*****
//   You can use this space for remarks that should not be included
//   in the documentation.
//    EXAMPLE
//
//
//    NOTES
//      The return value takes into account the stochastic definition of
//      the "!=" operator (see the documentation).
//
//    BUGS
//
//
//    SEE ALSO
//
//
//  /





inline int operator!=(const double& a, const double_st& b){
  double_st res;
  unsigned int random;
  double tmp;

  res.accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  res.x = tmp;
  tmp = b.x;
  DOUBLE_BIT_FLIP(tmp, random);
  res.x -= tmp;
  DOUBLE_BIT_FLIP(res.x, random);

  random = RANDOM;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  res.y = tmp;
  tmp = b.y;
  DOUBLE_BIT_FLIP(tmp, random);
  res.y -= tmp;
  DOUBLE_BIT_FLIP(res.y, random);

  random = 1^random;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  res.z = tmp;
  tmp = b.z;
  DOUBLE_BIT_FLIP(tmp, random);
  res.z -= tmp;
  DOUBLE_BIT_FLIP(res.z, random);

  return ~res.computedzero();
}
inline int operator!=(const float& a, const double_st& b){
  double_st res;
  unsigned int random;
  double tmp;

  res.accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  res.x = tmp;
  tmp = b.x;
  DOUBLE_BIT_FLIP(tmp, random);
  res.x -= tmp;
  DOUBLE_BIT_FLIP(res.x, random);

  random = RANDOM;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  res.y = tmp;
  tmp = b.y;
  DOUBLE_BIT_FLIP(tmp, random);
  res.y -= tmp;
  DOUBLE_BIT_FLIP(res.y, random);

  random = 1^random;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  res.z = tmp;
  tmp = b.z;
  DOUBLE_BIT_FLIP(tmp, random);
  res.z -= tmp;
  DOUBLE_BIT_FLIP(res.z, random);

  return ~res.computedzero();
}
inline int operator!=(const unsigned long long& a, const double_st& b){
  double_st res;
  unsigned int random;
  double tmp;

  res.accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  res.x = tmp;
  tmp = b.x;
  DOUBLE_BIT_FLIP(tmp, random);
  res.x -= tmp;
  DOUBLE_BIT_FLIP(res.x, random);

  random = RANDOM;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  res.y = tmp;
  tmp = b.y;
  DOUBLE_BIT_FLIP(tmp, random);
  res.y -= tmp;
  DOUBLE_BIT_FLIP(res.y, random);

  random = 1^random;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  res.z = tmp;
  tmp = b.z;
  DOUBLE_BIT_FLIP(tmp, random);
  res.z -= tmp;
  DOUBLE_BIT_FLIP(res.z, random);

  return ~res.computedzero();
}
inline int operator!=(const long long& a, const double_st& b){
  double_st res;
  unsigned int random;
  double tmp;

  res.accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  res.x = tmp;
  tmp = b.x;
  DOUBLE_BIT_FLIP(tmp, random);
  res.x -= tmp;
  DOUBLE_BIT_FLIP(res.x, random);

  random = RANDOM;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  res.y = tmp;
  tmp = b.y;
  DOUBLE_BIT_FLIP(tmp, random);
  res.y -= tmp;
  DOUBLE_BIT_FLIP(res.y, random);

  random = 1^random;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  res.z = tmp;
  tmp = b.z;
  DOUBLE_BIT_FLIP(tmp, random);
  res.z -= tmp;
  DOUBLE_BIT_FLIP(res.z, random);

  return ~res.computedzero();
}
inline int operator!=(const unsigned long& a, const double_st& b){
  double_st res;
  unsigned int random;
  double tmp;

  res.accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  res.x = tmp;
  tmp = b.x;
  DOUBLE_BIT_FLIP(tmp, random);
  res.x -= tmp;
  DOUBLE_BIT_FLIP(res.x, random);

  random = RANDOM;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  res.y = tmp;
  tmp = b.y;
  DOUBLE_BIT_FLIP(tmp, random);
  res.y -= tmp;
  DOUBLE_BIT_FLIP(res.y, random);

  random = 1^random;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  res.z = tmp;
  tmp = b.z;
  DOUBLE_BIT_FLIP(tmp, random);
  res.z -= tmp;
  DOUBLE_BIT_FLIP(res.z, random);

  return ~res.computedzero();
}
inline int operator!=(const long& a, const double_st& b){
  double_st res;
  unsigned int random;
  double tmp;

  res.accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  res.x = tmp;
  tmp = b.x;
  DOUBLE_BIT_FLIP(tmp, random);
  res.x -= tmp;
  DOUBLE_BIT_FLIP(res.x, random);

  random = RANDOM;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  res.y = tmp;
  tmp = b.y;
  DOUBLE_BIT_FLIP(tmp, random);
  res.y -= tmp;
  DOUBLE_BIT_FLIP(res.y, random);

  random = 1^random;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  res.z = tmp;
  tmp = b.z;
  DOUBLE_BIT_FLIP(tmp, random);
  res.z -= tmp;
  DOUBLE_BIT_FLIP(res.z, random);

  return ~res.computedzero();
}
inline int operator!=(const unsigned int & a, const double_st& b){
  double_st res;
  unsigned int random;
  double tmp;

  res.accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  res.x = tmp;
  tmp = b.x;
  DOUBLE_BIT_FLIP(tmp, random);
  res.x -= tmp;
  DOUBLE_BIT_FLIP(res.x, random);

  random = RANDOM;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  res.y = tmp;
  tmp = b.y;
  DOUBLE_BIT_FLIP(tmp, random);
  res.y -= tmp;
  DOUBLE_BIT_FLIP(res.y, random);

  random = 1^random;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  res.z = tmp;
  tmp = b.z;
  DOUBLE_BIT_FLIP(tmp, random);
  res.z -= tmp;
  DOUBLE_BIT_FLIP(res.z, random);

  return ~res.computedzero();
}
inline int operator!=(const int & a, const double_st& b){
  double_st res;
  unsigned int random;
  double tmp;

  res.accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  res.x = tmp;
  tmp = b.x;
  DOUBLE_BIT_FLIP(tmp, random);
  res.x -= tmp;
  DOUBLE_BIT_FLIP(res.x, random);

  random = RANDOM;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  res.y = tmp;
  tmp = b.y;
  DOUBLE_BIT_FLIP(tmp, random);
  res.y -= tmp;
  DOUBLE_BIT_FLIP(res.y, random);

  random = 1^random;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  res.z = tmp;
  tmp = b.z;
  DOUBLE_BIT_FLIP(tmp, random);
  res.z -= tmp;
  DOUBLE_BIT_FLIP(res.z, random);

  return ~res.computedzero();
}
inline int operator!=(const unsigned short& a, const double_st& b){
  double_st res;
  unsigned int random;
  double tmp;

  res.accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  res.x = tmp;
  tmp = b.x;
  DOUBLE_BIT_FLIP(tmp, random);
  res.x -= tmp;
  DOUBLE_BIT_FLIP(res.x, random);

  random = RANDOM;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  res.y = tmp;
  tmp = b.y;
  DOUBLE_BIT_FLIP(tmp, random);
  res.y -= tmp;
  DOUBLE_BIT_FLIP(res.y, random);

  random = 1^random;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  res.z = tmp;
  tmp = b.z;
  DOUBLE_BIT_FLIP(tmp, random);
  res.z -= tmp;
  DOUBLE_BIT_FLIP(res.z, random);

  return ~res.computedzero();
}
inline int operator!=(const short& a, const double_st& b){
  double_st res;
  unsigned int random;
  double tmp;

  res.accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  res.x = tmp;
  tmp = b.x;
  DOUBLE_BIT_FLIP(tmp, random);
  res.x -= tmp;
  DOUBLE_BIT_FLIP(res.x, random);

  random = RANDOM;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  res.y = tmp;
  tmp = b.y;
  DOUBLE_BIT_FLIP(tmp, random);
  res.y -= tmp;
  DOUBLE_BIT_FLIP(res.y, random);

  random = 1^random;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  res.z = tmp;
  tmp = b.z;
  DOUBLE_BIT_FLIP(tmp, random);
  res.z -= tmp;
  DOUBLE_BIT_FLIP(res.z, random);

  return ~res.computedzero();
}
inline int operator!=(const unsigned char& a, const double_st& b){
  double_st res;
  unsigned int random;
  double tmp;

  res.accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  res.x = tmp;
  tmp = b.x;
  DOUBLE_BIT_FLIP(tmp, random);
  res.x -= tmp;
  DOUBLE_BIT_FLIP(res.x, random);

  random = RANDOM;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  res.y = tmp;
  tmp = b.y;
  DOUBLE_BIT_FLIP(tmp, random);
  res.y -= tmp;
  DOUBLE_BIT_FLIP(res.y, random);

  random = 1^random;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  res.z = tmp;
  tmp = b.z;
  DOUBLE_BIT_FLIP(tmp, random);
  res.z -= tmp;
  DOUBLE_BIT_FLIP(res.z, random);

  return ~res.computedzero();
}
inline int operator!=(const char& a, const double_st& b){
  double_st res;
  unsigned int random;
  double tmp;

  res.accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  res.x = tmp;
  tmp = b.x;
  DOUBLE_BIT_FLIP(tmp, random);
  res.x -= tmp;
  DOUBLE_BIT_FLIP(res.x, random);

  random = RANDOM;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  res.y = tmp;
  tmp = b.y;
  DOUBLE_BIT_FLIP(tmp, random);
  res.y -= tmp;
  DOUBLE_BIT_FLIP(res.y, random);

  random = 1^random;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  res.z = tmp;
  tmp = b.z;
  DOUBLE_BIT_FLIP(tmp, random);
  res.z -= tmp;
  DOUBLE_BIT_FLIP(res.z, random);

  return ~res.computedzero();
}

inline int operator!=(const double& a, const float_st& b){
  float_st res;
  unsigned int random;
  float tmp;

  res.accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  res.x = tmp;
  tmp = b.x;
  FLOAT_BIT_FLIP(tmp, random);
  res.x -= tmp;
  FLOAT_BIT_FLIP(res.x, random);

  random = RANDOM;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  res.y = tmp;
  tmp = b.y;
  FLOAT_BIT_FLIP(tmp, random);
  res.y -= tmp;
  FLOAT_BIT_FLIP(res.y, random);

  random = 1^random;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  res.z = tmp;
  tmp = b.z;
  FLOAT_BIT_FLIP(tmp, random);
  res.z -= tmp;
  FLOAT_BIT_FLIP(res.z, random);

  return ~res.computedzero();
}
inline int operator!=(const float& a, const float_st& b){
  float_st res;
  unsigned int random;
  float tmp;

  res.accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  res.x = tmp;
  tmp = b.x;
  FLOAT_BIT_FLIP(tmp, random);
  res.x -= tmp;
  FLOAT_BIT_FLIP(res.x, random);

  random = RANDOM;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  res.y = tmp;
  tmp = b.y;
  FLOAT_BIT_FLIP(tmp, random);
  res.y -= tmp;
  FLOAT_BIT_FLIP(res.y, random);

  random = 1^random;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  res.z = tmp;
  tmp = b.z;
  FLOAT_BIT_FLIP(tmp, random);
  res.z -= tmp;
  FLOAT_BIT_FLIP(res.z, random);

  return ~res.computedzero();
}
inline int operator!=(const unsigned long long& a, const float_st& b){
  float_st res;
  unsigned int random;
  float tmp;

  res.accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  res.x = tmp;
  tmp = b.x;
  FLOAT_BIT_FLIP(tmp, random);
  res.x -= tmp;
  FLOAT_BIT_FLIP(res.x, random);

  random = RANDOM;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  res.y = tmp;
  tmp = b.y;
  FLOAT_BIT_FLIP(tmp, random);
  res.y -= tmp;
  FLOAT_BIT_FLIP(res.y, random);

  random = 1^random;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  res.z = tmp;
  tmp = b.z;
  FLOAT_BIT_FLIP(tmp, random);
  res.z -= tmp;
  FLOAT_BIT_FLIP(res.z, random);

  return ~res.computedzero();
}
inline int operator!=(const long long& a, const float_st& b){
  float_st res;
  unsigned int random;
  float tmp;

  res.accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  res.x = tmp;
  tmp = b.x;
  FLOAT_BIT_FLIP(tmp, random);
  res.x -= tmp;
  FLOAT_BIT_FLIP(res.x, random);

  random = RANDOM;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  res.y = tmp;
  tmp = b.y;
  FLOAT_BIT_FLIP(tmp, random);
  res.y -= tmp;
  FLOAT_BIT_FLIP(res.y, random);

  random = 1^random;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  res.z = tmp;
  tmp = b.z;
  FLOAT_BIT_FLIP(tmp, random);
  res.z -= tmp;
  FLOAT_BIT_FLIP(res.z, random);

  return ~res.computedzero();
}
inline int operator!=(const unsigned long& a, const float_st& b){
  float_st res;
  unsigned int random;
  float tmp;

  res.accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  res.x = tmp;
  tmp = b.x;
  FLOAT_BIT_FLIP(tmp, random);
  res.x -= tmp;
  FLOAT_BIT_FLIP(res.x, random);

  random = RANDOM;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  res.y = tmp;
  tmp = b.y;
  FLOAT_BIT_FLIP(tmp, random);
  res.y -= tmp;
  FLOAT_BIT_FLIP(res.y, random);

  random = 1^random;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  res.z = tmp;
  tmp = b.z;
  FLOAT_BIT_FLIP(tmp, random);
  res.z -= tmp;
  FLOAT_BIT_FLIP(res.z, random);

  return ~res.computedzero();
}
inline int operator!=(const long& a, const float_st& b){
  float_st res;
  unsigned int random;
  float tmp;

  res.accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  res.x = tmp;
  tmp = b.x;
  FLOAT_BIT_FLIP(tmp, random);
  res.x -= tmp;
  FLOAT_BIT_FLIP(res.x, random);

  random = RANDOM;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  res.y = tmp;
  tmp = b.y;
  FLOAT_BIT_FLIP(tmp, random);
  res.y -= tmp;
  FLOAT_BIT_FLIP(res.y, random);

  random = 1^random;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  res.z = tmp;
  tmp = b.z;
  FLOAT_BIT_FLIP(tmp, random);
  res.z -= tmp;
  FLOAT_BIT_FLIP(res.z, random);

  return ~res.computedzero();
}
inline int operator!=(const unsigned int & a, const float_st& b){
  float_st res;
  unsigned int random;
  float tmp;

  res.accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  res.x = tmp;
  tmp = b.x;
  FLOAT_BIT_FLIP(tmp, random);
  res.x -= tmp;
  FLOAT_BIT_FLIP(res.x, random);

  random = RANDOM;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  res.y = tmp;
  tmp = b.y;
  FLOAT_BIT_FLIP(tmp, random);
  res.y -= tmp;
  FLOAT_BIT_FLIP(res.y, random);

  random = 1^random;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  res.z = tmp;
  tmp = b.z;
  FLOAT_BIT_FLIP(tmp, random);
  res.z -= tmp;
  FLOAT_BIT_FLIP(res.z, random);

  return ~res.computedzero();
}
inline int operator!=(const int & a, const float_st& b){
  float_st res;
  unsigned int random;
  float tmp;

  res.accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  res.x = tmp;
  tmp = b.x;
  FLOAT_BIT_FLIP(tmp, random);
  res.x -= tmp;
  FLOAT_BIT_FLIP(res.x, random);

  random = RANDOM;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  res.y = tmp;
  tmp = b.y;
  FLOAT_BIT_FLIP(tmp, random);
  res.y -= tmp;
  FLOAT_BIT_FLIP(res.y, random);

  random = 1^random;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  res.z = tmp;
  tmp = b.z;
  FLOAT_BIT_FLIP(tmp, random);
  res.z -= tmp;
  FLOAT_BIT_FLIP(res.z, random);

  return ~res.computedzero();
}
inline int operator!=(const unsigned short& a, const float_st& b){
  float_st res;
  unsigned int random;
  float tmp;

  res.accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  res.x = tmp;
  tmp = b.x;
  FLOAT_BIT_FLIP(tmp, random);
  res.x -= tmp;
  FLOAT_BIT_FLIP(res.x, random);

  random = RANDOM;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  res.y = tmp;
  tmp = b.y;
  FLOAT_BIT_FLIP(tmp, random);
  res.y -= tmp;
  FLOAT_BIT_FLIP(res.y, random);

  random = 1^random;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  res.z = tmp;
  tmp = b.z;
  FLOAT_BIT_FLIP(tmp, random);
  res.z -= tmp;
  FLOAT_BIT_FLIP(res.z, random);

  return ~res.computedzero();
}
inline int operator!=(const short& a, const float_st& b){
  float_st res;
  unsigned int random;
  float tmp;

  res.accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  res.x = tmp;
  tmp = b.x;
  FLOAT_BIT_FLIP(tmp, random);
  res.x -= tmp;
  FLOAT_BIT_FLIP(res.x, random);

  random = RANDOM;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  res.y = tmp;
  tmp = b.y;
  FLOAT_BIT_FLIP(tmp, random);
  res.y -= tmp;
  FLOAT_BIT_FLIP(res.y, random);

  random = 1^random;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  res.z = tmp;
  tmp = b.z;
  FLOAT_BIT_FLIP(tmp, random);
  res.z -= tmp;
  FLOAT_BIT_FLIP(res.z, random);

  return ~res.computedzero();
}
inline int operator!=(const unsigned char& a, const float_st& b){
  float_st res;
  unsigned int random;
  float tmp;

  res.accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  res.x = tmp;
  tmp = b.x;
  FLOAT_BIT_FLIP(tmp, random);
  res.x -= tmp;
  FLOAT_BIT_FLIP(res.x, random);

  random = RANDOM;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  res.y = tmp;
  tmp = b.y;
  FLOAT_BIT_FLIP(tmp, random);
  res.y -= tmp;
  FLOAT_BIT_FLIP(res.y, random);

  random = 1^random;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  res.z = tmp;
  tmp = b.z;
  FLOAT_BIT_FLIP(tmp, random);
  res.z -= tmp;
  FLOAT_BIT_FLIP(res.z, random);

  return ~res.computedzero();
}
inline int operator!=(const char& a, const float_st& b){
  float_st res;
  unsigned int random;
  float tmp;

  res.accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  res.x = tmp;
  tmp = b.x;
  FLOAT_BIT_FLIP(tmp, random);
  res.x -= tmp;
  FLOAT_BIT_FLIP(res.x, random);

  random = RANDOM;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  res.y = tmp;
  tmp = b.y;
  FLOAT_BIT_FLIP(tmp, random);
  res.y -= tmp;
  FLOAT_BIT_FLIP(res.y, random);

  random = 1^random;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  res.z = tmp;
  tmp = b.z;
  FLOAT_BIT_FLIP(tmp, random);
  res.z -= tmp;
  FLOAT_BIT_FLIP(res.z, random);

  return ~res.computedzero();
}


///////////////////////////////////////////////////


inline int operator!=(const double_st& a, const double& b){
  double_st res;

  unsigned int random;
  double tmp;

  res.accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = a.x;
  DOUBLE_BIT_FLIP(tmp, random);
  res.x = tmp;
  tmp = b;
  DOUBLE_BIT_FLIP(tmp, random);
  res.x -= tmp;
  DOUBLE_BIT_FLIP(res.x, random);

  random = RANDOM;
  tmp = a.y;
  DOUBLE_BIT_FLIP(tmp, random);
  res.y = tmp;
  tmp = b;
  DOUBLE_BIT_FLIP(tmp, random);
  res.y -= tmp;
  DOUBLE_BIT_FLIP(res.y, random);

  random = 1^random;
  tmp = a.z;
  DOUBLE_BIT_FLIP(tmp, random);
  res.z = tmp;
  tmp = b;
  DOUBLE_BIT_FLIP(tmp, random);
  res.z -= tmp;
  DOUBLE_BIT_FLIP(res.z, random);

  return !(res.computedzero());
}
inline int operator!=(const double_st& a, const float& b){
  double_st res;

  unsigned int random;
  double tmp;

  res.accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = a.x;
  DOUBLE_BIT_FLIP(tmp, random);
  res.x = tmp;
  tmp = b;
  DOUBLE_BIT_FLIP(tmp, random);
  res.x -= tmp;
  DOUBLE_BIT_FLIP(res.x, random);

  random = RANDOM;
  tmp = a.y;
  DOUBLE_BIT_FLIP(tmp, random);
  res.y = tmp;
  tmp = b;
  DOUBLE_BIT_FLIP(tmp, random);
  res.y -= tmp;
  DOUBLE_BIT_FLIP(res.y, random);

  random = 1^random;
  tmp = a.z;
  DOUBLE_BIT_FLIP(tmp, random);
  res.z = tmp;
  tmp = b;
  DOUBLE_BIT_FLIP(tmp, random);
  res.z -= tmp;
  DOUBLE_BIT_FLIP(res.z, random);

  return !(res.computedzero());
}
inline int operator!=(const double_st& a, const unsigned long long& b){
  double_st res;

  unsigned int random;
  double tmp;

  res.accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = a.x;
  DOUBLE_BIT_FLIP(tmp, random);
  res.x = tmp;
  tmp = b;
  DOUBLE_BIT_FLIP(tmp, random);
  res.x -= tmp;
  DOUBLE_BIT_FLIP(res.x, random);

  random = RANDOM;
  tmp = a.y;
  DOUBLE_BIT_FLIP(tmp, random);
  res.y = tmp;
  tmp = b;
  DOUBLE_BIT_FLIP(tmp, random);
  res.y -= tmp;
  DOUBLE_BIT_FLIP(res.y, random);

  random = 1^random;
  tmp = a.z;
  DOUBLE_BIT_FLIP(tmp, random);
  res.z = tmp;
  tmp = b;
  DOUBLE_BIT_FLIP(tmp, random);
  res.z -= tmp;
  DOUBLE_BIT_FLIP(res.z, random);

  return !(res.computedzero());
}
inline int operator!=(const double_st& a, const long long& b){
  double_st res;

  unsigned int random;
  double tmp;

  res.accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = a.x;
  DOUBLE_BIT_FLIP(tmp, random);
  res.x = tmp;
  tmp = b;
  DOUBLE_BIT_FLIP(tmp, random);
  res.x -= tmp;
  DOUBLE_BIT_FLIP(res.x, random);

  random = RANDOM;
  tmp = a.y;
  DOUBLE_BIT_FLIP(tmp, random);
  res.y = tmp;
  tmp = b;
  DOUBLE_BIT_FLIP(tmp, random);
  res.y -= tmp;
  DOUBLE_BIT_FLIP(res.y, random);

  random = 1^random;
  tmp = a.z;
  DOUBLE_BIT_FLIP(tmp, random);
  res.z = tmp;
  tmp = b;
  DOUBLE_BIT_FLIP(tmp, random);
  res.z -= tmp;
  DOUBLE_BIT_FLIP(res.z, random);

  return !(res.computedzero());
}
inline int operator!=(const double_st& a, const unsigned long& b){
  double_st res;

  unsigned int random;
  double tmp;

  res.accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = a.x;
  DOUBLE_BIT_FLIP(tmp, random);
  res.x = tmp;
  tmp = b;
  DOUBLE_BIT_FLIP(tmp, random);
  res.x -= tmp;
  DOUBLE_BIT_FLIP(res.x, random);

  random = RANDOM;
  tmp = a.y;
  DOUBLE_BIT_FLIP(tmp, random);
  res.y = tmp;
  tmp = b;
  DOUBLE_BIT_FLIP(tmp, random);
  res.y -= tmp;
  DOUBLE_BIT_FLIP(res.y, random);

  random = 1^random;
  tmp = a.z;
  DOUBLE_BIT_FLIP(tmp, random);
  res.z = tmp;
  tmp = b;
  DOUBLE_BIT_FLIP(tmp, random);
  res.z -= tmp;
  DOUBLE_BIT_FLIP(res.z, random);

  return !(res.computedzero());
}
inline int operator!=(const double_st& a, const long& b){
  double_st res;

  unsigned int random;
  double tmp;

  res.accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = a.x;
  DOUBLE_BIT_FLIP(tmp, random);
  res.x = tmp;
  tmp = b;
  DOUBLE_BIT_FLIP(tmp, random);
  res.x -= tmp;
  DOUBLE_BIT_FLIP(res.x, random);

  random = RANDOM;
  tmp = a.y;
  DOUBLE_BIT_FLIP(tmp, random);
  res.y = tmp;
  tmp = b;
  DOUBLE_BIT_FLIP(tmp, random);
  res.y -= tmp;
  DOUBLE_BIT_FLIP(res.y, random);

  random = 1^random;
  tmp = a.z;
  DOUBLE_BIT_FLIP(tmp, random);
  res.z = tmp;
  tmp = b;
  DOUBLE_BIT_FLIP(tmp, random);
  res.z -= tmp;
  DOUBLE_BIT_FLIP(res.z, random);

  return !(res.computedzero());
}
inline int operator!=(const double_st& a, const unsigned int & b){
  double_st res;

  unsigned int random;
  double tmp;

  res.accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = a.x;
  DOUBLE_BIT_FLIP(tmp, random);
  res.x = tmp;
  tmp = b;
  DOUBLE_BIT_FLIP(tmp, random);
  res.x -= tmp;
  DOUBLE_BIT_FLIP(res.x, random);

  random = RANDOM;
  tmp = a.y;
  DOUBLE_BIT_FLIP(tmp, random);
  res.y = tmp;
  tmp = b;
  DOUBLE_BIT_FLIP(tmp, random);
  res.y -= tmp;
  DOUBLE_BIT_FLIP(res.y, random);

  random = 1^random;
  tmp = a.z;
  DOUBLE_BIT_FLIP(tmp, random);
  res.z = tmp;
  tmp = b;
  DOUBLE_BIT_FLIP(tmp, random);
  res.z -= tmp;
  DOUBLE_BIT_FLIP(res.z, random);

  return !(res.computedzero());
}
inline int operator!=(const double_st& a, const int & b){
  double_st res;

  unsigned int random;
  double tmp;

  res.accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = a.x;
  DOUBLE_BIT_FLIP(tmp, random);
  res.x = tmp;
  tmp = b;
  DOUBLE_BIT_FLIP(tmp, random);
  res.x -= tmp;
  DOUBLE_BIT_FLIP(res.x, random);

  random = RANDOM;
  tmp = a.y;
  DOUBLE_BIT_FLIP(tmp, random);
  res.y = tmp;
  tmp = b;
  DOUBLE_BIT_FLIP(tmp, random);
  res.y -= tmp;
  DOUBLE_BIT_FLIP(res.y, random);

  random = 1^random;
  tmp = a.z;
  DOUBLE_BIT_FLIP(tmp, random);
  res.z = tmp;
  tmp = b;
  DOUBLE_BIT_FLIP(tmp, random);
  res.z -= tmp;
  DOUBLE_BIT_FLIP(res.z, random);

  return !(res.computedzero());
}
inline int operator!=(const double_st& a, const unsigned short& b){
  double_st res;

  unsigned int random;
  double tmp;

  res.accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = a.x;
  DOUBLE_BIT_FLIP(tmp, random);
  res.x = tmp;
  tmp = b;
  DOUBLE_BIT_FLIP(tmp, random);
  res.x -= tmp;
  DOUBLE_BIT_FLIP(res.x, random);

  random = RANDOM;
  tmp = a.y;
  DOUBLE_BIT_FLIP(tmp, random);
  res.y = tmp;
  tmp = b;
  DOUBLE_BIT_FLIP(tmp, random);
  res.y -= tmp;
  DOUBLE_BIT_FLIP(res.y, random);

  random = 1^random;
  tmp = a.z;
  DOUBLE_BIT_FLIP(tmp, random);
  res.z = tmp;
  tmp = b;
  DOUBLE_BIT_FLIP(tmp, random);
  res.z -= tmp;
  DOUBLE_BIT_FLIP(res.z, random);

  return !(res.computedzero());
}
inline int operator!=(const double_st& a, const short& b){
  double_st res;

  unsigned int random;
  double tmp;

  res.accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = a.x;
  DOUBLE_BIT_FLIP(tmp, random);
  res.x = tmp;
  tmp = b;
  DOUBLE_BIT_FLIP(tmp, random);
  res.x -= tmp;
  DOUBLE_BIT_FLIP(res.x, random);

  random = RANDOM;
  tmp = a.y;
  DOUBLE_BIT_FLIP(tmp, random);
  res.y = tmp;
  tmp = b;
  DOUBLE_BIT_FLIP(tmp, random);
  res.y -= tmp;
  DOUBLE_BIT_FLIP(res.y, random);

  random = 1^random;
  tmp = a.z;
  DOUBLE_BIT_FLIP(tmp, random);
  res.z = tmp;
  tmp = b;
  DOUBLE_BIT_FLIP(tmp, random);
  res.z -= tmp;
  DOUBLE_BIT_FLIP(res.z, random);

  return !(res.computedzero());
}
inline int operator!=(const double_st& a, const unsigned char& b){
  double_st res;

  unsigned int random;
  double tmp;

  res.accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = a.x;
  DOUBLE_BIT_FLIP(tmp, random);
  res.x = tmp;
  tmp = b;
  DOUBLE_BIT_FLIP(tmp, random);
  res.x -= tmp;
  DOUBLE_BIT_FLIP(res.x, random);

  random = RANDOM;
  tmp = a.y;
  DOUBLE_BIT_FLIP(tmp, random);
  res.y = tmp;
  tmp = b;
  DOUBLE_BIT_FLIP(tmp, random);
  res.y -= tmp;
  DOUBLE_BIT_FLIP(res.y, random);

  random = 1^random;
  tmp = a.z;
  DOUBLE_BIT_FLIP(tmp, random);
  res.z = tmp;
  tmp = b;
  DOUBLE_BIT_FLIP(tmp, random);
  res.z -= tmp;
  DOUBLE_BIT_FLIP(res.z, random);

  return !(res.computedzero());
}
inline int operator!=(const double_st& a, const char& b){
  double_st res;

  unsigned int random;
  double tmp;

  res.accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = a.x;
  DOUBLE_BIT_FLIP(tmp, random);
  res.x = tmp;
  tmp = b;
  DOUBLE_BIT_FLIP(tmp, random);
  res.x -= tmp;
  DOUBLE_BIT_FLIP(res.x, random);

  random = RANDOM;
  tmp = a.y;
  DOUBLE_BIT_FLIP(tmp, random);
  res.y = tmp;
  tmp = b;
  DOUBLE_BIT_FLIP(tmp, random);
  res.y -= tmp;
  DOUBLE_BIT_FLIP(res.y, random);

  random = 1^random;
  tmp = a.z;
  DOUBLE_BIT_FLIP(tmp, random);
  res.z = tmp;
  tmp = b;
  DOUBLE_BIT_FLIP(tmp, random);
  res.z -= tmp;
  DOUBLE_BIT_FLIP(res.z, random);

  return !(res.computedzero());
}

inline int operator!=(const float_st& a, const double& b){
  float_st res;

  unsigned int random;
  float tmp;

  res.accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = a.x;
  FLOAT_BIT_FLIP(tmp, random);
  res.x = tmp;
  tmp = b;
  FLOAT_BIT_FLIP(tmp, random);
  res.x -= tmp;
  FLOAT_BIT_FLIP(res.x, random);

  random = RANDOM;
  tmp = a.y;
  FLOAT_BIT_FLIP(tmp, random);
  res.y = tmp;
  tmp = b;
  FLOAT_BIT_FLIP(tmp, random);
  res.y -= tmp;
  FLOAT_BIT_FLIP(res.y, random);

  random = 1^random;
  tmp = a.z;
  FLOAT_BIT_FLIP(tmp, random);
  res.z = tmp;
  tmp = b;
  FLOAT_BIT_FLIP(tmp, random);
  res.z -= tmp;
  FLOAT_BIT_FLIP(res.z, random);

  return !(res.computedzero());
}
inline int operator!=(const float_st& a, const float& b){
  float_st res;

  unsigned int random;
  float tmp;

  res.accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = a.x;
  FLOAT_BIT_FLIP(tmp, random);
  res.x = tmp;
  tmp = b;
  FLOAT_BIT_FLIP(tmp, random);
  res.x -= tmp;
  FLOAT_BIT_FLIP(res.x, random);

  random = RANDOM;
  tmp = a.y;
  FLOAT_BIT_FLIP(tmp, random);
  res.y = tmp;
  tmp = b;
  FLOAT_BIT_FLIP(tmp, random);
  res.y -= tmp;
  FLOAT_BIT_FLIP(res.y, random);

  random = 1^random;
  tmp = a.z;
  FLOAT_BIT_FLIP(tmp, random);
  res.z = tmp;
  tmp = b;
  FLOAT_BIT_FLIP(tmp, random);
  res.z -= tmp;
  FLOAT_BIT_FLIP(res.z, random);

  return !(res.computedzero());
}
inline int operator!=(const float_st& a, const unsigned long long& b){
  float_st res;

  unsigned int random;
  float tmp;

  res.accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = a.x;
  FLOAT_BIT_FLIP(tmp, random);
  res.x = tmp;
  tmp = b;
  FLOAT_BIT_FLIP(tmp, random);
  res.x -= tmp;
  FLOAT_BIT_FLIP(res.x, random);

  random = RANDOM;
  tmp = a.y;
  FLOAT_BIT_FLIP(tmp, random);
  res.y = tmp;
  tmp = b;
  FLOAT_BIT_FLIP(tmp, random);
  res.y -= tmp;
  FLOAT_BIT_FLIP(res.y, random);

  random = 1^random;
  tmp = a.z;
  FLOAT_BIT_FLIP(tmp, random);
  res.z = tmp;
  tmp = b;
  FLOAT_BIT_FLIP(tmp, random);
  res.z -= tmp;
  FLOAT_BIT_FLIP(res.z, random);

  return !(res.computedzero());
}
inline int operator!=(const float_st& a, const long long& b){
  float_st res;

  unsigned int random;
  float tmp;

  res.accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = a.x;
  FLOAT_BIT_FLIP(tmp, random);
  res.x = tmp;
  tmp = b;
  FLOAT_BIT_FLIP(tmp, random);
  res.x -= tmp;
  FLOAT_BIT_FLIP(res.x, random);

  random = RANDOM;
  tmp = a.y;
  FLOAT_BIT_FLIP(tmp, random);
  res.y = tmp;
  tmp = b;
  FLOAT_BIT_FLIP(tmp, random);
  res.y -= tmp;
  FLOAT_BIT_FLIP(res.y, random);

  random = 1^random;
  tmp = a.z;
  FLOAT_BIT_FLIP(tmp, random);
  res.z = tmp;
  tmp = b;
  FLOAT_BIT_FLIP(tmp, random);
  res.z -= tmp;
  FLOAT_BIT_FLIP(res.z, random);

  return !(res.computedzero());
}
inline int operator!=(const float_st& a, const unsigned long& b){
  float_st res;

  unsigned int random;
  float tmp;

  res.accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = a.x;
  FLOAT_BIT_FLIP(tmp, random);
  res.x = tmp;
  tmp = b;
  FLOAT_BIT_FLIP(tmp, random);
  res.x -= tmp;
  FLOAT_BIT_FLIP(res.x, random);

  random = RANDOM;
  tmp = a.y;
  FLOAT_BIT_FLIP(tmp, random);
  res.y = tmp;
  tmp = b;
  FLOAT_BIT_FLIP(tmp, random);
  res.y -= tmp;
  FLOAT_BIT_FLIP(res.y, random);

  random = 1^random;
  tmp = a.z;
  FLOAT_BIT_FLIP(tmp, random);
  res.z = tmp;
  tmp = b;
  FLOAT_BIT_FLIP(tmp, random);
  res.z -= tmp;
  FLOAT_BIT_FLIP(res.z, random);

  return !(res.computedzero());
}
inline int operator!=(const float_st& a, const long& b){
  float_st res;

  unsigned int random;
  float tmp;

  res.accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = a.x;
  FLOAT_BIT_FLIP(tmp, random);
  res.x = tmp;
  tmp = b;
  FLOAT_BIT_FLIP(tmp, random);
  res.x -= tmp;
  FLOAT_BIT_FLIP(res.x, random);

  random = RANDOM;
  tmp = a.y;
  FLOAT_BIT_FLIP(tmp, random);
  res.y = tmp;
  tmp = b;
  FLOAT_BIT_FLIP(tmp, random);
  res.y -= tmp;
  FLOAT_BIT_FLIP(res.y, random);

  random = 1^random;
  tmp = a.z;
  FLOAT_BIT_FLIP(tmp, random);
  res.z = tmp;
  tmp = b;
  FLOAT_BIT_FLIP(tmp, random);
  res.z -= tmp;
  FLOAT_BIT_FLIP(res.z, random);

  return !(res.computedzero());
}
inline int operator!=(const float_st& a, const unsigned int & b){
  float_st res;

  unsigned int random;
  float tmp;

  res.accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = a.x;
  FLOAT_BIT_FLIP(tmp, random);
  res.x = tmp;
  tmp = b;
  FLOAT_BIT_FLIP(tmp, random);
  res.x -= tmp;
  FLOAT_BIT_FLIP(res.x, random);

  random = RANDOM;
  tmp = a.y;
  FLOAT_BIT_FLIP(tmp, random);
  res.y = tmp;
  tmp = b;
  FLOAT_BIT_FLIP(tmp, random);
  res.y -= tmp;
  FLOAT_BIT_FLIP(res.y, random);

  random = 1^random;
  tmp = a.z;
  FLOAT_BIT_FLIP(tmp, random);
  res.z = tmp;
  tmp = b;
  FLOAT_BIT_FLIP(tmp, random);
  res.z -= tmp;
  FLOAT_BIT_FLIP(res.z, random);

  return !(res.computedzero());
}
inline int operator!=(const float_st& a, const int & b){
  float_st res;

  unsigned int random;
  float tmp;

  res.accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = a.x;
  FLOAT_BIT_FLIP(tmp, random);
  res.x = tmp;
  tmp = b;
  FLOAT_BIT_FLIP(tmp, random);
  res.x -= tmp;
  FLOAT_BIT_FLIP(res.x, random);

  random = RANDOM;
  tmp = a.y;
  FLOAT_BIT_FLIP(tmp, random);
  res.y = tmp;
  tmp = b;
  FLOAT_BIT_FLIP(tmp, random);
  res.y -= tmp;
  FLOAT_BIT_FLIP(res.y, random);

  random = 1^random;
  tmp = a.z;
  FLOAT_BIT_FLIP(tmp, random);
  res.z = tmp;
  tmp = b;
  FLOAT_BIT_FLIP(tmp, random);
  res.z -= tmp;
  FLOAT_BIT_FLIP(res.z, random);

  return !(res.computedzero());
}
inline int operator!=(const float_st& a, const unsigned short& b){
  float_st res;

  unsigned int random;
  float tmp;

  res.accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = a.x;
  FLOAT_BIT_FLIP(tmp, random);
  res.x = tmp;
  tmp = b;
  FLOAT_BIT_FLIP(tmp, random);
  res.x -= tmp;
  FLOAT_BIT_FLIP(res.x, random);

  random = RANDOM;
  tmp = a.y;
  FLOAT_BIT_FLIP(tmp, random);
  res.y = tmp;
  tmp = b;
  FLOAT_BIT_FLIP(tmp, random);
  res.y -= tmp;
  FLOAT_BIT_FLIP(res.y, random);

  random = 1^random;
  tmp = a.z;
  FLOAT_BIT_FLIP(tmp, random);
  res.z = tmp;
  tmp = b;
  FLOAT_BIT_FLIP(tmp, random);
  res.z -= tmp;
  FLOAT_BIT_FLIP(res.z, random);

  return !(res.computedzero());
}
inline int operator!=(const float_st& a, const short& b){
  float_st res;

  unsigned int random;
  float tmp;

  res.accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = a.x;
  FLOAT_BIT_FLIP(tmp, random);
  res.x = tmp;
  tmp = b;
  FLOAT_BIT_FLIP(tmp, random);
  res.x -= tmp;
  FLOAT_BIT_FLIP(res.x, random);

  random = RANDOM;
  tmp = a.y;
  FLOAT_BIT_FLIP(tmp, random);
  res.y = tmp;
  tmp = b;
  FLOAT_BIT_FLIP(tmp, random);
  res.y -= tmp;
  FLOAT_BIT_FLIP(res.y, random);

  random = 1^random;
  tmp = a.z;
  FLOAT_BIT_FLIP(tmp, random);
  res.z = tmp;
  tmp = b;
  FLOAT_BIT_FLIP(tmp, random);
  res.z -= tmp;
  FLOAT_BIT_FLIP(res.z, random);

  return !(res.computedzero());
}
inline int operator!=(const float_st& a, const unsigned char& b){
  float_st res;

  unsigned int random;
  float tmp;

  res.accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = a.x;
  FLOAT_BIT_FLIP(tmp, random);
  res.x = tmp;
  tmp = b;
  FLOAT_BIT_FLIP(tmp, random);
  res.x -= tmp;
  FLOAT_BIT_FLIP(res.x, random);

  random = RANDOM;
  tmp = a.y;
  FLOAT_BIT_FLIP(tmp, random);
  res.y = tmp;
  tmp = b;
  FLOAT_BIT_FLIP(tmp, random);
  res.y -= tmp;
  FLOAT_BIT_FLIP(res.y, random);

  random = 1^random;
  tmp = a.z;
  FLOAT_BIT_FLIP(tmp, random);
  res.z = tmp;
  tmp = b;
  FLOAT_BIT_FLIP(tmp, random);
  res.z -= tmp;
  FLOAT_BIT_FLIP(res.z, random);

  return !(res.computedzero());
}
inline int operator!=(const float_st& a, const char& b){
  float_st res;

  unsigned int random;
  float tmp;

  res.accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = a.x;
  FLOAT_BIT_FLIP(tmp, random);
  res.x = tmp;
  tmp = b;
  FLOAT_BIT_FLIP(tmp, random);
  res.x -= tmp;
  FLOAT_BIT_FLIP(res.x, random);

  random = RANDOM;
  tmp = a.y;
  FLOAT_BIT_FLIP(tmp, random);
  res.y = tmp;
  tmp = b;
  FLOAT_BIT_FLIP(tmp, random);
  res.y -= tmp;
  FLOAT_BIT_FLIP(res.y, random);

  random = 1^random;
  tmp = a.z;
  FLOAT_BIT_FLIP(tmp, random);
  res.z = tmp;
  tmp = b;
  FLOAT_BIT_FLIP(tmp, random);
  res.z -= tmp;
  FLOAT_BIT_FLIP(res.z, random);

  return !(res.computedzero());
}




inline int operator!=(const double_st& a, const double_st& b){
  double_st res;

  unsigned int random;
  double tmp;

  res.accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = a.x;
  DOUBLE_BIT_FLIP(tmp, random);
  res.x = tmp;
  tmp = b.x;
  DOUBLE_BIT_FLIP(tmp, random);
  res.x -= tmp;
  DOUBLE_BIT_FLIP(res.x, random);

  random = RANDOM;
  tmp = a.y;
  DOUBLE_BIT_FLIP(tmp, random);
  res.y = tmp;
  tmp = b.y;
  DOUBLE_BIT_FLIP(tmp, random);
  res.y -= tmp;
  DOUBLE_BIT_FLIP(res.y, random);

  random = 1^random;
  tmp = a.z;
  DOUBLE_BIT_FLIP(tmp, random);
  res.z = tmp;
  tmp = b.z;
  DOUBLE_BIT_FLIP(tmp, random);
  res.z -= tmp;
  DOUBLE_BIT_FLIP(res.z, random);

  return !res.computedzero();
}
inline int operator!=(const double_st& a, const float_st& b){
  double_st res;

  unsigned int random;
  double tmp;

  res.accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = a.x;
  DOUBLE_BIT_FLIP(tmp, random);
  res.x = tmp;
  tmp = b.x;
  DOUBLE_BIT_FLIP(tmp, random);
  res.x -= tmp;
  DOUBLE_BIT_FLIP(res.x, random);

  random = RANDOM;
  tmp = a.y;
  DOUBLE_BIT_FLIP(tmp, random);
  res.y = tmp;
  tmp = b.y;
  DOUBLE_BIT_FLIP(tmp, random);
  res.y -= tmp;
  DOUBLE_BIT_FLIP(res.y, random);

  random = 1^random;
  tmp = a.z;
  DOUBLE_BIT_FLIP(tmp, random);
  res.z = tmp;
  tmp = b.z;
  DOUBLE_BIT_FLIP(tmp, random);
  res.z -= tmp;
  DOUBLE_BIT_FLIP(res.z, random);

  return !res.computedzero();
}
inline int operator!=(const float_st& a, const double_st& b){
  float_st res;

  unsigned int random;
  float tmp;

  res.accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = a.x;
  FLOAT_BIT_FLIP(tmp, random);
  res.x = tmp;
  tmp = b.x;
  FLOAT_BIT_FLIP(tmp, random);
  res.x -= tmp;
  FLOAT_BIT_FLIP(res.x, random);

  random = RANDOM;
  tmp = a.y;
  FLOAT_BIT_FLIP(tmp, random);
  res.y = tmp;
  tmp = b.y;
  FLOAT_BIT_FLIP(tmp, random);
  res.y -= tmp;
  FLOAT_BIT_FLIP(res.y, random);

  random = 1^random;
  tmp = a.z;
  FLOAT_BIT_FLIP(tmp, random);
  res.z = tmp;
  tmp = b.z;
  FLOAT_BIT_FLIP(tmp, random);
  res.z -= tmp;
  FLOAT_BIT_FLIP(res.z, random);

  return !res.computedzero();
}
inline int operator!=(const float_st& a, const float_st& b){
  float_st res;

  unsigned int random;
  float tmp;

  res.accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = a.x;
  FLOAT_BIT_FLIP(tmp, random);
  res.x = tmp;
  tmp = b.x;
  FLOAT_BIT_FLIP(tmp, random);
  res.x -= tmp;
  FLOAT_BIT_FLIP(res.x, random);

  random = RANDOM;
  tmp = a.y;
  FLOAT_BIT_FLIP(tmp, random);
  res.y = tmp;
  tmp = b.y;
  FLOAT_BIT_FLIP(tmp, random);
  res.y -= tmp;
  FLOAT_BIT_FLIP(res.y, random);

  random = 1^random;
  tmp = a.z;
  FLOAT_BIT_FLIP(tmp, random);
  res.z = tmp;
  tmp = b.z;
  FLOAT_BIT_FLIP(tmp, random);
  res.z -= tmp;
  FLOAT_BIT_FLIP(res.z, random);

  return !res.computedzero();
}

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
//****m* cadna_sub/operator-
//    NAME
//      operator-
//    SYNOPSIS
//      res = a - b
//    FUNCTION
//      Define all the functions involving at least one argument
//      of stochastic type which overload the "-" operator
//      in a statement such as "a-b".
//    INPUTS
//      a           - an integer, a float, a double or a stochastic number
//      b           - an integer, a float, a double or a stochastic number
//      At least one argument must be of stochastic type.
//    RESULT
//      res         - a stochastic number
//
//*****
//   You can use this space for remarks that should not be included
//   in the documentation.
//    EXAMPLE
//
//
//    NOTES
//
//
//    BUGS
//
//
//    SEE ALSO
//
//
//  /





inline float_st float_st::operator-() const{
  float_st res;
  res.x=-x;
  res.y=-y;
  res.z=-z;
  return res;
}
inline double_st double_st::operator-() const{
  double_st res;
  res.x=-x;
  res.y=-y;
  res.z=-z;
  return res;
}

/////////////////////////////////////////////////////////////////////////



inline float_st float_st::operator--(){
  float_st initial=*this;

  unsigned int random;
  float tmp;

  accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = x;
  FLOAT_BIT_FLIP(tmp, random);
  x = tmp;
  tmp = 1;
  FLOAT_BIT_FLIP(tmp, random);
  x -= tmp;
  FLOAT_BIT_FLIP(x, random);

  random = RANDOM;
  tmp = y;
  FLOAT_BIT_FLIP(tmp, random);
  y = tmp;
  tmp = 1;
  FLOAT_BIT_FLIP(tmp, random);
  y -= tmp;
  FLOAT_BIT_FLIP(y, random);

  random = 1^random;
  tmp = z;
  FLOAT_BIT_FLIP(tmp, random);
  z = tmp;
  tmp = 1;
  FLOAT_BIT_FLIP(tmp, random);
  z -= tmp;
  FLOAT_BIT_FLIP(z, random);

  if (_cadna_cancel_tag){
    if (initial.accuracy==DIGIT_NOT_COMPUTED || initial.accuracy==RELIABLE_RESULT)
      initial.nb_significant_digit();
    if (initial.accuracy >=  this->nb_significant_digit()+_cadna_cancel_value)
      instability(&_cadna_cancel_count);
  }
  return *this;
};
inline double_st double_st::operator--(){
  double_st initial=*this;

  unsigned int random;
  double tmp;

  accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = x;
  DOUBLE_BIT_FLIP(tmp, random);
  x = tmp;
  tmp = 1;
  DOUBLE_BIT_FLIP(tmp, random);
  x -= tmp;
  DOUBLE_BIT_FLIP(x, random);

  random = RANDOM;
  tmp = y;
  DOUBLE_BIT_FLIP(tmp, random);
  y = tmp;
  tmp = 1;
  DOUBLE_BIT_FLIP(tmp, random);
  y -= tmp;
  DOUBLE_BIT_FLIP(y, random);

  random = 1^random;
  tmp = z;
  DOUBLE_BIT_FLIP(tmp, random);
  z = tmp;
  tmp = 1;
  DOUBLE_BIT_FLIP(tmp, random);
  z -= tmp;
  DOUBLE_BIT_FLIP(z, random);

  if (_cadna_cancel_tag){
    if (initial.accuracy==DIGIT_NOT_COMPUTED || initial.accuracy==RELIABLE_RESULT)
      initial.nb_significant_digit();
    if (initial.accuracy >=  this->nb_significant_digit()+_cadna_cancel_value)
      instability(&_cadna_cancel_count);
  }
  return *this;
};

/////////////////////////////////////////////////////////////////////////



inline float_st float_st::operator--(int){
  float_st initial=*this;

  unsigned int random;
  float tmp;

  accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = x;
  FLOAT_BIT_FLIP(tmp, random);
  x = tmp;
  tmp = 1;
  FLOAT_BIT_FLIP(tmp, random);
  x -= tmp;
  FLOAT_BIT_FLIP(x, random);

  random = RANDOM;
  tmp = y;
  FLOAT_BIT_FLIP(tmp, random);
  y = tmp;
  tmp = 1;
  FLOAT_BIT_FLIP(tmp, random);
  y -= tmp;
  FLOAT_BIT_FLIP(y, random);

  random = 1^random;
  tmp = z;
  FLOAT_BIT_FLIP(tmp, random);
  z = tmp;
  tmp = 1;
  FLOAT_BIT_FLIP(tmp, random);
  z -= tmp;
  FLOAT_BIT_FLIP(z, random);

  if (_cadna_cancel_tag){
    if (initial.accuracy==DIGIT_NOT_COMPUTED || initial.accuracy==RELIABLE_RESULT)
      initial.nb_significant_digit();
    if (initial.accuracy >=  this->nb_significant_digit()+_cadna_cancel_value)
      instability(&_cadna_cancel_count);
  }
  return initial;
};
inline double_st double_st::operator--(int){
  double_st initial=*this;

  unsigned int random;
  double tmp;

  accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = x;
  DOUBLE_BIT_FLIP(tmp, random);
  x = tmp;
  tmp = 1;
  DOUBLE_BIT_FLIP(tmp, random);
  x -= tmp;
  DOUBLE_BIT_FLIP(x, random);

  random = RANDOM;
  tmp = y;
  DOUBLE_BIT_FLIP(tmp, random);
  y = tmp;
  tmp = 1;
  DOUBLE_BIT_FLIP(tmp, random);
  y -= tmp;
  DOUBLE_BIT_FLIP(y, random);

  random = 1^random;
  tmp = z;
  DOUBLE_BIT_FLIP(tmp, random);
  z = tmp;
  tmp = 1;
  DOUBLE_BIT_FLIP(tmp, random);
  z -= tmp;
  DOUBLE_BIT_FLIP(z, random);

  if (_cadna_cancel_tag){
    if (initial.accuracy==DIGIT_NOT_COMPUTED || initial.accuracy==RELIABLE_RESULT)
      initial.nb_significant_digit();
    if (initial.accuracy >=  this->nb_significant_digit()+_cadna_cancel_value)
      instability(&_cadna_cancel_count);
  }
  return initial;
};

/////////////////////////////////////////////////////////////////////////



inline double_st& double_st::operator-=(const double& a){
  double_st initial=*this;

  unsigned int random;
  double tmp;

  accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = x;
  DOUBLE_BIT_FLIP(tmp, random);
  x = tmp;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  x -= tmp;
  DOUBLE_BIT_FLIP(x, random);

  random = RANDOM;
  tmp = y;
  DOUBLE_BIT_FLIP(tmp, random);
  y = tmp;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  y -= tmp;
  DOUBLE_BIT_FLIP(y, random);

  random = 1^random;
  tmp = z;
  DOUBLE_BIT_FLIP(tmp, random);
  z = tmp;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  z -= tmp;
  DOUBLE_BIT_FLIP(z, random);

  if (_cadna_cancel_tag){
    if (initial.accuracy==DIGIT_NOT_COMPUTED || initial.accuracy==RELIABLE_RESULT)
      initial.nb_significant_digit();
    if (initial.accuracy >=  this->nb_significant_digit()+_cadna_cancel_value)
      instability(&_cadna_cancel_count);
  }
  return *this;
}
inline double_st& double_st::operator-=(const float& a){
  double_st initial=*this;

  unsigned int random;
  double tmp;

  accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = x;
  DOUBLE_BIT_FLIP(tmp, random);
  x = tmp;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  x -= tmp;
  DOUBLE_BIT_FLIP(x, random);

  random = RANDOM;
  tmp = y;
  DOUBLE_BIT_FLIP(tmp, random);
  y = tmp;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  y -= tmp;
  DOUBLE_BIT_FLIP(y, random);

  random = 1^random;
  tmp = z;
  DOUBLE_BIT_FLIP(tmp, random);
  z = tmp;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  z -= tmp;
  DOUBLE_BIT_FLIP(z, random);

  if (_cadna_cancel_tag){
    if (initial.accuracy==DIGIT_NOT_COMPUTED || initial.accuracy==RELIABLE_RESULT)
      initial.nb_significant_digit();
    if (initial.accuracy >=  this->nb_significant_digit()+_cadna_cancel_value)
      instability(&_cadna_cancel_count);
  }
  return *this;
}
inline double_st& double_st::operator-=(const unsigned long long& a){
  double_st initial=*this;

  unsigned int random;
  double tmp;

  accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = x;
  DOUBLE_BIT_FLIP(tmp, random);
  x = tmp;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  x -= tmp;
  DOUBLE_BIT_FLIP(x, random);

  random = RANDOM;
  tmp = y;
  DOUBLE_BIT_FLIP(tmp, random);
  y = tmp;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  y -= tmp;
  DOUBLE_BIT_FLIP(y, random);

  random = 1^random;
  tmp = z;
  DOUBLE_BIT_FLIP(tmp, random);
  z = tmp;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  z -= tmp;
  DOUBLE_BIT_FLIP(z, random);

  if (_cadna_cancel_tag){
    if (initial.accuracy==DIGIT_NOT_COMPUTED || initial.accuracy==RELIABLE_RESULT)
      initial.nb_significant_digit();
    if (initial.accuracy >=  this->nb_significant_digit()+_cadna_cancel_value)
      instability(&_cadna_cancel_count);
  }
  return *this;
}
inline double_st& double_st::operator-=(const long long& a){
  double_st initial=*this;

  unsigned int random;
  double tmp;

  accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = x;
  DOUBLE_BIT_FLIP(tmp, random);
  x = tmp;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  x -= tmp;
  DOUBLE_BIT_FLIP(x, random);

  random = RANDOM;
  tmp = y;
  DOUBLE_BIT_FLIP(tmp, random);
  y = tmp;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  y -= tmp;
  DOUBLE_BIT_FLIP(y, random);

  random = 1^random;
  tmp = z;
  DOUBLE_BIT_FLIP(tmp, random);
  z = tmp;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  z -= tmp;
  DOUBLE_BIT_FLIP(z, random);

  if (_cadna_cancel_tag){
    if (initial.accuracy==DIGIT_NOT_COMPUTED || initial.accuracy==RELIABLE_RESULT)
      initial.nb_significant_digit();
    if (initial.accuracy >=  this->nb_significant_digit()+_cadna_cancel_value)
      instability(&_cadna_cancel_count);
  }
  return *this;
}
inline double_st& double_st::operator-=(const unsigned long& a){
  double_st initial=*this;

  unsigned int random;
  double tmp;

  accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = x;
  DOUBLE_BIT_FLIP(tmp, random);
  x = tmp;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  x -= tmp;
  DOUBLE_BIT_FLIP(x, random);

  random = RANDOM;
  tmp = y;
  DOUBLE_BIT_FLIP(tmp, random);
  y = tmp;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  y -= tmp;
  DOUBLE_BIT_FLIP(y, random);

  random = 1^random;
  tmp = z;
  DOUBLE_BIT_FLIP(tmp, random);
  z = tmp;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  z -= tmp;
  DOUBLE_BIT_FLIP(z, random);

  if (_cadna_cancel_tag){
    if (initial.accuracy==DIGIT_NOT_COMPUTED || initial.accuracy==RELIABLE_RESULT)
      initial.nb_significant_digit();
    if (initial.accuracy >=  this->nb_significant_digit()+_cadna_cancel_value)
      instability(&_cadna_cancel_count);
  }
  return *this;
}
inline double_st& double_st::operator-=(const long& a){
  double_st initial=*this;

  unsigned int random;
  double tmp;

  accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = x;
  DOUBLE_BIT_FLIP(tmp, random);
  x = tmp;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  x -= tmp;
  DOUBLE_BIT_FLIP(x, random);

  random = RANDOM;
  tmp = y;
  DOUBLE_BIT_FLIP(tmp, random);
  y = tmp;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  y -= tmp;
  DOUBLE_BIT_FLIP(y, random);

  random = 1^random;
  tmp = z;
  DOUBLE_BIT_FLIP(tmp, random);
  z = tmp;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  z -= tmp;
  DOUBLE_BIT_FLIP(z, random);

  if (_cadna_cancel_tag){
    if (initial.accuracy==DIGIT_NOT_COMPUTED || initial.accuracy==RELIABLE_RESULT)
      initial.nb_significant_digit();
    if (initial.accuracy >=  this->nb_significant_digit()+_cadna_cancel_value)
      instability(&_cadna_cancel_count);
  }
  return *this;
}
inline double_st& double_st::operator-=(const unsigned int& a){
  double_st initial=*this;

  unsigned int random;
  double tmp;

  accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = x;
  DOUBLE_BIT_FLIP(tmp, random);
  x = tmp;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  x -= tmp;
  DOUBLE_BIT_FLIP(x, random);

  random = RANDOM;
  tmp = y;
  DOUBLE_BIT_FLIP(tmp, random);
  y = tmp;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  y -= tmp;
  DOUBLE_BIT_FLIP(y, random);

  random = 1^random;
  tmp = z;
  DOUBLE_BIT_FLIP(tmp, random);
  z = tmp;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  z -= tmp;
  DOUBLE_BIT_FLIP(z, random);

  if (_cadna_cancel_tag){
    if (initial.accuracy==DIGIT_NOT_COMPUTED || initial.accuracy==RELIABLE_RESULT)
      initial.nb_significant_digit();
    if (initial.accuracy >=  this->nb_significant_digit()+_cadna_cancel_value)
      instability(&_cadna_cancel_count);
  }
  return *this;
}
inline double_st& double_st::operator-=(const int& a){
  double_st initial=*this;

  unsigned int random;
  double tmp;

  accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = x;
  DOUBLE_BIT_FLIP(tmp, random);
  x = tmp;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  x -= tmp;
  DOUBLE_BIT_FLIP(x, random);

  random = RANDOM;
  tmp = y;
  DOUBLE_BIT_FLIP(tmp, random);
  y = tmp;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  y -= tmp;
  DOUBLE_BIT_FLIP(y, random);

  random = 1^random;
  tmp = z;
  DOUBLE_BIT_FLIP(tmp, random);
  z = tmp;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  z -= tmp;
  DOUBLE_BIT_FLIP(z, random);

  if (_cadna_cancel_tag){
    if (initial.accuracy==DIGIT_NOT_COMPUTED || initial.accuracy==RELIABLE_RESULT)
      initial.nb_significant_digit();
    if (initial.accuracy >=  this->nb_significant_digit()+_cadna_cancel_value)
      instability(&_cadna_cancel_count);
  }
  return *this;
}
inline double_st& double_st::operator-=(const unsigned short& a){
  double_st initial=*this;

  unsigned int random;
  double tmp;

  accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = x;
  DOUBLE_BIT_FLIP(tmp, random);
  x = tmp;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  x -= tmp;
  DOUBLE_BIT_FLIP(x, random);

  random = RANDOM;
  tmp = y;
  DOUBLE_BIT_FLIP(tmp, random);
  y = tmp;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  y -= tmp;
  DOUBLE_BIT_FLIP(y, random);

  random = 1^random;
  tmp = z;
  DOUBLE_BIT_FLIP(tmp, random);
  z = tmp;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  z -= tmp;
  DOUBLE_BIT_FLIP(z, random);

  if (_cadna_cancel_tag){
    if (initial.accuracy==DIGIT_NOT_COMPUTED || initial.accuracy==RELIABLE_RESULT)
      initial.nb_significant_digit();
    if (initial.accuracy >=  this->nb_significant_digit()+_cadna_cancel_value)
      instability(&_cadna_cancel_count);
  }
  return *this;
}
inline double_st& double_st::operator-=(const short& a){
  double_st initial=*this;

  unsigned int random;
  double tmp;

  accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = x;
  DOUBLE_BIT_FLIP(tmp, random);
  x = tmp;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  x -= tmp;
  DOUBLE_BIT_FLIP(x, random);

  random = RANDOM;
  tmp = y;
  DOUBLE_BIT_FLIP(tmp, random);
  y = tmp;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  y -= tmp;
  DOUBLE_BIT_FLIP(y, random);

  random = 1^random;
  tmp = z;
  DOUBLE_BIT_FLIP(tmp, random);
  z = tmp;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  z -= tmp;
  DOUBLE_BIT_FLIP(z, random);

  if (_cadna_cancel_tag){
    if (initial.accuracy==DIGIT_NOT_COMPUTED || initial.accuracy==RELIABLE_RESULT)
      initial.nb_significant_digit();
    if (initial.accuracy >=  this->nb_significant_digit()+_cadna_cancel_value)
      instability(&_cadna_cancel_count);
  }
  return *this;
}
inline double_st& double_st::operator-=(const unsigned char& a){
  double_st initial=*this;

  unsigned int random;
  double tmp;

  accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = x;
  DOUBLE_BIT_FLIP(tmp, random);
  x = tmp;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  x -= tmp;
  DOUBLE_BIT_FLIP(x, random);

  random = RANDOM;
  tmp = y;
  DOUBLE_BIT_FLIP(tmp, random);
  y = tmp;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  y -= tmp;
  DOUBLE_BIT_FLIP(y, random);

  random = 1^random;
  tmp = z;
  DOUBLE_BIT_FLIP(tmp, random);
  z = tmp;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  z -= tmp;
  DOUBLE_BIT_FLIP(z, random);

  if (_cadna_cancel_tag){
    if (initial.accuracy==DIGIT_NOT_COMPUTED || initial.accuracy==RELIABLE_RESULT)
      initial.nb_significant_digit();
    if (initial.accuracy >=  this->nb_significant_digit()+_cadna_cancel_value)
      instability(&_cadna_cancel_count);
  }
  return *this;
}
inline double_st& double_st::operator-=(const char& a){
  double_st initial=*this;

  unsigned int random;
  double tmp;

  accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = x;
  DOUBLE_BIT_FLIP(tmp, random);
  x = tmp;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  x -= tmp;
  DOUBLE_BIT_FLIP(x, random);

  random = RANDOM;
  tmp = y;
  DOUBLE_BIT_FLIP(tmp, random);
  y = tmp;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  y -= tmp;
  DOUBLE_BIT_FLIP(y, random);

  random = 1^random;
  tmp = z;
  DOUBLE_BIT_FLIP(tmp, random);
  z = tmp;
  tmp = a;
  DOUBLE_BIT_FLIP(tmp, random);
  z -= tmp;
  DOUBLE_BIT_FLIP(z, random);

  if (_cadna_cancel_tag){
    if (initial.accuracy==DIGIT_NOT_COMPUTED || initial.accuracy==RELIABLE_RESULT)
      initial.nb_significant_digit();
    if (initial.accuracy >=  this->nb_significant_digit()+_cadna_cancel_value)
      instability(&_cadna_cancel_count);
  }
  return *this;
}

inline float_st& float_st::operator-=(const double& a){
  float_st initial=*this;

  unsigned int random;
  float tmp;

  accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = x;
  FLOAT_BIT_FLIP(tmp, random);
  x = tmp;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  x -= tmp;
  FLOAT_BIT_FLIP(x, random);

  random = RANDOM;
  tmp = y;
  FLOAT_BIT_FLIP(tmp, random);
  y = tmp;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  y -= tmp;
  FLOAT_BIT_FLIP(y, random);

  random = 1^random;
  tmp = z;
  FLOAT_BIT_FLIP(tmp, random);
  z = tmp;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  z -= tmp;
  FLOAT_BIT_FLIP(z, random);

  if (_cadna_cancel_tag){
    if (initial.accuracy==DIGIT_NOT_COMPUTED || initial.accuracy==RELIABLE_RESULT)
      initial.nb_significant_digit();
    if (initial.accuracy >=  this->nb_significant_digit()+_cadna_cancel_value)
      instability(&_cadna_cancel_count);
  }
  return *this;
}
inline float_st& float_st::operator-=(const float& a){
  float_st initial=*this;

  unsigned int random;
  float tmp;

  accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = x;
  FLOAT_BIT_FLIP(tmp, random);
  x = tmp;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  x -= tmp;
  FLOAT_BIT_FLIP(x, random);

  random = RANDOM;
  tmp = y;
  FLOAT_BIT_FLIP(tmp, random);
  y = tmp;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  y -= tmp;
  FLOAT_BIT_FLIP(y, random);

  random = 1^random;
  tmp = z;
  FLOAT_BIT_FLIP(tmp, random);
  z = tmp;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  z -= tmp;
  FLOAT_BIT_FLIP(z, random);

  if (_cadna_cancel_tag){
    if (initial.accuracy==DIGIT_NOT_COMPUTED || initial.accuracy==RELIABLE_RESULT)
      initial.nb_significant_digit();
    if (initial.accuracy >=  this->nb_significant_digit()+_cadna_cancel_value)
      instability(&_cadna_cancel_count);
  }
  return *this;
}
inline float_st& float_st::operator-=(const unsigned long long& a){
  float_st initial=*this;

  unsigned int random;
  float tmp;

  accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = x;
  FLOAT_BIT_FLIP(tmp, random);
  x = tmp;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  x -= tmp;
  FLOAT_BIT_FLIP(x, random);

  random = RANDOM;
  tmp = y;
  FLOAT_BIT_FLIP(tmp, random);
  y = tmp;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  y -= tmp;
  FLOAT_BIT_FLIP(y, random);

  random = 1^random;
  tmp = z;
  FLOAT_BIT_FLIP(tmp, random);
  z = tmp;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  z -= tmp;
  FLOAT_BIT_FLIP(z, random);

  if (_cadna_cancel_tag){
    if (initial.accuracy==DIGIT_NOT_COMPUTED || initial.accuracy==RELIABLE_RESULT)
      initial.nb_significant_digit();
    if (initial.accuracy >=  this->nb_significant_digit()+_cadna_cancel_value)
      instability(&_cadna_cancel_count);
  }
  return *this;
}
inline float_st& float_st::operator-=(const long long& a){
  float_st initial=*this;

  unsigned int random;
  float tmp;

  accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = x;
  FLOAT_BIT_FLIP(tmp, random);
  x = tmp;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  x -= tmp;
  FLOAT_BIT_FLIP(x, random);

  random = RANDOM;
  tmp = y;
  FLOAT_BIT_FLIP(tmp, random);
  y = tmp;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  y -= tmp;
  FLOAT_BIT_FLIP(y, random);

  random = 1^random;
  tmp = z;
  FLOAT_BIT_FLIP(tmp, random);
  z = tmp;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  z -= tmp;
  FLOAT_BIT_FLIP(z, random);

  if (_cadna_cancel_tag){
    if (initial.accuracy==DIGIT_NOT_COMPUTED || initial.accuracy==RELIABLE_RESULT)
      initial.nb_significant_digit();
    if (initial.accuracy >=  this->nb_significant_digit()+_cadna_cancel_value)
      instability(&_cadna_cancel_count);
  }
  return *this;
}
inline float_st& float_st::operator-=(const unsigned long& a){
  float_st initial=*this;

  unsigned int random;
  float tmp;

  accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = x;
  FLOAT_BIT_FLIP(tmp, random);
  x = tmp;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  x -= tmp;
  FLOAT_BIT_FLIP(x, random);

  random = RANDOM;
  tmp = y;
  FLOAT_BIT_FLIP(tmp, random);
  y = tmp;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  y -= tmp;
  FLOAT_BIT_FLIP(y, random);

  random = 1^random;
  tmp = z;
  FLOAT_BIT_FLIP(tmp, random);
  z = tmp;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  z -= tmp;
  FLOAT_BIT_FLIP(z, random);

  if (_cadna_cancel_tag){
    if (initial.accuracy==DIGIT_NOT_COMPUTED || initial.accuracy==RELIABLE_RESULT)
      initial.nb_significant_digit();
    if (initial.accuracy >=  this->nb_significant_digit()+_cadna_cancel_value)
      instability(&_cadna_cancel_count);
  }
  return *this;
}
inline float_st& float_st::operator-=(const long& a){
  float_st initial=*this;

  unsigned int random;
  float tmp;

  accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = x;
  FLOAT_BIT_FLIP(tmp, random);
  x = tmp;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  x -= tmp;
  FLOAT_BIT_FLIP(x, random);

  random = RANDOM;
  tmp = y;
  FLOAT_BIT_FLIP(tmp, random);
  y = tmp;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  y -= tmp;
  FLOAT_BIT_FLIP(y, random);

  random = 1^random;
  tmp = z;
  FLOAT_BIT_FLIP(tmp, random);
  z = tmp;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  z -= tmp;
  FLOAT_BIT_FLIP(z, random);

  if (_cadna_cancel_tag){
    if (initial.accuracy==DIGIT_NOT_COMPUTED || initial.accuracy==RELIABLE_RESULT)
      initial.nb_significant_digit();
    if (initial.accuracy >=  this->nb_significant_digit()+_cadna_cancel_value)
      instability(&_cadna_cancel_count);
  }
  return *this;
}
inline float_st& float_st::operator-=(const unsigned int& a){
  float_st initial=*this;

  unsigned int random;
  float tmp;

  accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = x;
  FLOAT_BIT_FLIP(tmp, random);
  x = tmp;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  x -= tmp;
  FLOAT_BIT_FLIP(x, random);

  random = RANDOM;
  tmp = y;
  FLOAT_BIT_FLIP(tmp, random);
  y = tmp;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  y -= tmp;
  FLOAT_BIT_FLIP(y, random);

  random = 1^random;
  tmp = z;
  FLOAT_BIT_FLIP(tmp, random);
  z = tmp;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  z -= tmp;
  FLOAT_BIT_FLIP(z, random);

  if (_cadna_cancel_tag){
    if (initial.accuracy==DIGIT_NOT_COMPUTED || initial.accuracy==RELIABLE_RESULT)
      initial.nb_significant_digit();
    if (initial.accuracy >=  this->nb_significant_digit()+_cadna_cancel_value)
      instability(&_cadna_cancel_count);
  }
  return *this;
}
inline float_st& float_st::operator-=(const int& a){
  float_st initial=*this;

  unsigned int random;
  float tmp;

  accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = x;
  FLOAT_BIT_FLIP(tmp, random);
  x = tmp;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  x -= tmp;
  FLOAT_BIT_FLIP(x, random);

  random = RANDOM;
  tmp = y;
  FLOAT_BIT_FLIP(tmp, random);
  y = tmp;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  y -= tmp;
  FLOAT_BIT_FLIP(y, random);

  random = 1^random;
  tmp = z;
  FLOAT_BIT_FLIP(tmp, random);
  z = tmp;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  z -= tmp;
  FLOAT_BIT_FLIP(z, random);

  if (_cadna_cancel_tag){
    if (initial.accuracy==DIGIT_NOT_COMPUTED || initial.accuracy==RELIABLE_RESULT)
      initial.nb_significant_digit();
    if (initial.accuracy >=  this->nb_significant_digit()+_cadna_cancel_value)
      instability(&_cadna_cancel_count);
  }
  return *this;
}
inline float_st& float_st::operator-=(const unsigned short& a){
  float_st initial=*this;

  unsigned int random;
  float tmp;

  accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = x;
  FLOAT_BIT_FLIP(tmp, random);
  x = tmp;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  x -= tmp;
  FLOAT_BIT_FLIP(x, random);

  random = RANDOM;
  tmp = y;
  FLOAT_BIT_FLIP(tmp, random);
  y = tmp;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  y -= tmp;
  FLOAT_BIT_FLIP(y, random);

  random = 1^random;
  tmp = z;
  FLOAT_BIT_FLIP(tmp, random);
  z = tmp;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  z -= tmp;
  FLOAT_BIT_FLIP(z, random);

  if (_cadna_cancel_tag){
    if (initial.accuracy==DIGIT_NOT_COMPUTED || initial.accuracy==RELIABLE_RESULT)
      initial.nb_significant_digit();
    if (initial.accuracy >=  this->nb_significant_digit()+_cadna_cancel_value)
      instability(&_cadna_cancel_count);
  }
  return *this;
}
inline float_st& float_st::operator-=(const short& a){
  float_st initial=*this;

  unsigned int random;
  float tmp;

  accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = x;
  FLOAT_BIT_FLIP(tmp, random);
  x = tmp;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  x -= tmp;
  FLOAT_BIT_FLIP(x, random);

  random = RANDOM;
  tmp = y;
  FLOAT_BIT_FLIP(tmp, random);
  y = tmp;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  y -= tmp;
  FLOAT_BIT_FLIP(y, random);

  random = 1^random;
  tmp = z;
  FLOAT_BIT_FLIP(tmp, random);
  z = tmp;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  z -= tmp;
  FLOAT_BIT_FLIP(z, random);

  if (_cadna_cancel_tag){
    if (initial.accuracy==DIGIT_NOT_COMPUTED || initial.accuracy==RELIABLE_RESULT)
      initial.nb_significant_digit();
    if (initial.accuracy >=  this->nb_significant_digit()+_cadna_cancel_value)
      instability(&_cadna_cancel_count);
  }
  return *this;
}
inline float_st& float_st::operator-=(const unsigned char& a){
  float_st initial=*this;

  unsigned int random;
  float tmp;

  accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = x;
  FLOAT_BIT_FLIP(tmp, random);
  x = tmp;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  x -= tmp;
  FLOAT_BIT_FLIP(x, random);

  random = RANDOM;
  tmp = y;
  FLOAT_BIT_FLIP(tmp, random);
  y = tmp;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  y -= tmp;
  FLOAT_BIT_FLIP(y, random);

  random = 1^random;
  tmp = z;
  FLOAT_BIT_FLIP(tmp, random);
  z = tmp;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  z -= tmp;
  FLOAT_BIT_FLIP(z, random);

  if (_cadna_cancel_tag){
    if (initial.accuracy==DIGIT_NOT_COMPUTED || initial.accuracy==RELIABLE_RESULT)
      initial.nb_significant_digit();
    if (initial.accuracy >=  this->nb_significant_digit()+_cadna_cancel_value)
      instability(&_cadna_cancel_count);
  }
  return *this;
}
inline float_st& float_st::operator-=(const char& a){
  float_st initial=*this;

  unsigned int random;
  float tmp;

  accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = x;
  FLOAT_BIT_FLIP(tmp, random);
  x = tmp;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  x -= tmp;
  FLOAT_BIT_FLIP(x, random);

  random = RANDOM;
  tmp = y;
  FLOAT_BIT_FLIP(tmp, random);
  y = tmp;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  y -= tmp;
  FLOAT_BIT_FLIP(y, random);

  random = 1^random;
  tmp = z;
  FLOAT_BIT_FLIP(tmp, random);
  z = tmp;
  tmp = a;
  FLOAT_BIT_FLIP(tmp, random);
  z -= tmp;
  FLOAT_BIT_FLIP(z, random);

  if (_cadna_cancel_tag){
    if (initial.accuracy==DIGIT_NOT_COMPUTED || initial.accuracy==RELIABLE_RESULT)
      initial.nb_significant_digit();
    if (initial.accuracy >=  this->nb_significant_digit()+_cadna_cancel_value)
      instability(&_cadna_cancel_count);
  }
  return *this;
}



/////////////////////////////////////////////////////////////////////////



inline double_st& double_st::operator-=(const double_st& a){
  double_st initial=*this;

  unsigned int random;
  double tmp;

  accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = x;
  DOUBLE_BIT_FLIP(tmp, random);
  x = tmp;
  tmp = a.x;
  DOUBLE_BIT_FLIP(tmp, random);
  x -= tmp;
  DOUBLE_BIT_FLIP(x, random);

  random = RANDOM;
  tmp = y;
  DOUBLE_BIT_FLIP(tmp, random);
  y = tmp;
  tmp = a.y;
  DOUBLE_BIT_FLIP(tmp, random);
  y -= tmp;
  DOUBLE_BIT_FLIP(y, random);

  random = 1^random;
  tmp = z;
  DOUBLE_BIT_FLIP(tmp, random);
  z = tmp;
  tmp = a.z;
  DOUBLE_BIT_FLIP(tmp, random);
  z -= tmp;
  DOUBLE_BIT_FLIP(z, random);

  if (_cadna_cancel_tag){
    if (initial.accuracy==DIGIT_NOT_COMPUTED || initial.accuracy==RELIABLE_RESULT) initial.nb_significant_digit();
    if (a.accuracy==DIGIT_NOT_COMPUTED || a.accuracy==RELIABLE_RESULT) a.nb_significant_digit();
    if ((initial.accuracy < a.accuracy ? initial.accuracy : a.accuracy) >=
         nb_significant_digit()+_cadna_cancel_value)
      instability(&_cadna_cancel_count);
  }
  return *this;
}
inline double_st& double_st::operator-=(const float_st& a){
  double_st initial=*this;

  unsigned int random;
  double tmp;

  accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = x;
  DOUBLE_BIT_FLIP(tmp, random);
  x = tmp;
  tmp = a.x;
  DOUBLE_BIT_FLIP(tmp, random);
  x -= tmp;
  DOUBLE_BIT_FLIP(x, random);

  random = RANDOM;
  tmp = y;
  DOUBLE_BIT_FLIP(tmp, random);
  y = tmp;
  tmp = a.y;
  DOUBLE_BIT_FLIP(tmp, random);
  y -= tmp;
  DOUBLE_BIT_FLIP(y, random);

  random = 1^random;
  tmp = z;
  DOUBLE_BIT_FLIP(tmp, random);
  z = tmp;
  tmp = a.z;
  DOUBLE_BIT_FLIP(tmp, random);
  z -= tmp;
  DOUBLE_BIT_FLIP(z, random);

  if (_cadna_cancel_tag){
    if (initial.accuracy==DIGIT_NOT_COMPUTED || initial.accuracy==RELIABLE_RESULT) initial.nb_significant_digit();
    if (a.accuracy==DIGIT_NOT_COMPUTED || a.accuracy==RELIABLE_RESULT) a.nb_significant_digit();
    if ((initial.accuracy < a.accuracy ? initial.accuracy : a.accuracy) >=
         nb_significant_digit()+_cadna_cancel_value)
      instability(&_cadna_cancel_count);
  }
  return *this;
}
inline float_st& float_st::operator-=(const double_st& a){
  float_st initial=*this;

  unsigned int random;
  float tmp;

  accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = x;
  FLOAT_BIT_FLIP(tmp, random);
  x = tmp;
  tmp = a.x;
  FLOAT_BIT_FLIP(tmp, random);
  x -= tmp;
  FLOAT_BIT_FLIP(x, random);

  random = RANDOM;
  tmp = y;
  FLOAT_BIT_FLIP(tmp, random);
  y = tmp;
  tmp = a.y;
  FLOAT_BIT_FLIP(tmp, random);
  y -= tmp;
  FLOAT_BIT_FLIP(y, random);

  random = 1^random;
  tmp = z;
  FLOAT_BIT_FLIP(tmp, random);
  z = tmp;
  tmp = a.z;
  FLOAT_BIT_FLIP(tmp, random);
  z -= tmp;
  FLOAT_BIT_FLIP(z, random);

  if (_cadna_cancel_tag){
    if (initial.accuracy==DIGIT_NOT_COMPUTED || initial.accuracy==RELIABLE_RESULT) initial.nb_significant_digit();
    if (a.accuracy==DIGIT_NOT_COMPUTED || a.accuracy==RELIABLE_RESULT) a.nb_significant_digit();
    if ((initial.accuracy < a.accuracy ? initial.accuracy : a.accuracy) >=
         nb_significant_digit()+_cadna_cancel_value)
      instability(&_cadna_cancel_count);
  }
  return *this;
}
inline float_st& float_st::operator-=(const float_st& a){
  float_st initial=*this;

  unsigned int random;
  float tmp;

  accuracy=DIGIT_NOT_COMPUTED;

  random = RANDOM;
  tmp = x;
  FLOAT_BIT_FLIP(tmp, random);
  x = tmp;
  tmp = a.x;
  FLOAT_BIT_FLIP(tmp, random);
  x -= tmp;
  FLOAT_BIT_FLIP(x, random);

  random = RANDOM;
  tmp = y;
  FLOAT_BIT_FLIP(tmp, random);
  y = tmp;
  tmp = a.y;
  FLOAT_BIT_FLIP(tmp, random);
  y -= tmp;
  FLOAT_BIT_FLIP(y, random);

  random = 1^random;
  tmp = z;
  FLOAT_BIT_FLIP(tmp, random);
  z = tmp;
  tmp = a.z;
  FLOAT_BIT_FLIP(tmp, random);
  z -= tmp;
  FLOAT_BIT_FLIP(z, random);

  if (_cadna_cancel_tag){
    if (initial.accuracy==DIGIT_NOT_COMPUTED || initial.accuracy==RELIABLE_RESULT) initial.nb_significant_digit();
    if (a.accuracy==DIGIT_NOT_COMPUTED || a.accuracy==RELIABLE_RESULT) a.nb_significant_digit();
    if ((initial.accuracy < a.accuracy ? initial.accuracy : a.accuracy) >=
         nb_significant_digit()+_cadna_cancel_value)
      instability(&_cadna_cancel_count);
  }
  return *this;
}

/////////////////////////////////////////////////////////////////////////



inline double_st operator-(const double& a, const double_st& b){
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

  if (_cadna_cancel_tag){
    if (b.accuracy==DIGIT_NOT_COMPUTED || b.accuracy==RELIABLE_RESULT)
	b.nb_significant_digit();
    if (b.accuracy >= 	res.nb_significant_digit()+_cadna_cancel_value)
	instability(&_cadna_cancel_count);
  }
  return res;
}
inline double_st operator-(const float& a, const double_st& b){
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

  if (_cadna_cancel_tag){
    if (b.accuracy==DIGIT_NOT_COMPUTED || b.accuracy==RELIABLE_RESULT)
	b.nb_significant_digit();
    if (b.accuracy >= 	res.nb_significant_digit()+_cadna_cancel_value)
	instability(&_cadna_cancel_count);
  }
  return res;
}
inline double_st operator-(const unsigned long long& a, const double_st& b){
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

  if (_cadna_cancel_tag){
    if (b.accuracy==DIGIT_NOT_COMPUTED || b.accuracy==RELIABLE_RESULT)
	b.nb_significant_digit();
    if (b.accuracy >= 	res.nb_significant_digit()+_cadna_cancel_value)
	instability(&_cadna_cancel_count);
  }
  return res;
}
inline double_st operator-(const long long& a, const double_st& b){
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

  if (_cadna_cancel_tag){
    if (b.accuracy==DIGIT_NOT_COMPUTED || b.accuracy==RELIABLE_RESULT)
	b.nb_significant_digit();
    if (b.accuracy >= 	res.nb_significant_digit()+_cadna_cancel_value)
	instability(&_cadna_cancel_count);
  }
  return res;
}
inline double_st operator-(const unsigned long& a, const double_st& b){
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

  if (_cadna_cancel_tag){
    if (b.accuracy==DIGIT_NOT_COMPUTED || b.accuracy==RELIABLE_RESULT)
	b.nb_significant_digit();
    if (b.accuracy >= 	res.nb_significant_digit()+_cadna_cancel_value)
	instability(&_cadna_cancel_count);
  }
  return res;
}
inline double_st operator-(const long& a, const double_st& b){
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

  if (_cadna_cancel_tag){
    if (b.accuracy==DIGIT_NOT_COMPUTED || b.accuracy==RELIABLE_RESULT)
	b.nb_significant_digit();
    if (b.accuracy >= 	res.nb_significant_digit()+_cadna_cancel_value)
	instability(&_cadna_cancel_count);
  }
  return res;
}
inline double_st operator-(const unsigned int & a, const double_st& b){
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

  if (_cadna_cancel_tag){
    if (b.accuracy==DIGIT_NOT_COMPUTED || b.accuracy==RELIABLE_RESULT)
	b.nb_significant_digit();
    if (b.accuracy >= 	res.nb_significant_digit()+_cadna_cancel_value)
	instability(&_cadna_cancel_count);
  }
  return res;
}
inline double_st operator-(const int & a, const double_st& b){
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

  if (_cadna_cancel_tag){
    if (b.accuracy==DIGIT_NOT_COMPUTED || b.accuracy==RELIABLE_RESULT)
	b.nb_significant_digit();
    if (b.accuracy >= 	res.nb_significant_digit()+_cadna_cancel_value)
	instability(&_cadna_cancel_count);
  }
  return res;
}
inline double_st operator-(const unsigned short& a, const double_st& b){
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

  if (_cadna_cancel_tag){
    if (b.accuracy==DIGIT_NOT_COMPUTED || b.accuracy==RELIABLE_RESULT)
	b.nb_significant_digit();
    if (b.accuracy >= 	res.nb_significant_digit()+_cadna_cancel_value)
	instability(&_cadna_cancel_count);
  }
  return res;
}
inline double_st operator-(const short& a, const double_st& b){
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

  if (_cadna_cancel_tag){
    if (b.accuracy==DIGIT_NOT_COMPUTED || b.accuracy==RELIABLE_RESULT)
	b.nb_significant_digit();
    if (b.accuracy >= 	res.nb_significant_digit()+_cadna_cancel_value)
	instability(&_cadna_cancel_count);
  }
  return res;
}
inline double_st operator-(const unsigned char& a, const double_st& b){
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

  if (_cadna_cancel_tag){
    if (b.accuracy==DIGIT_NOT_COMPUTED || b.accuracy==RELIABLE_RESULT)
	b.nb_significant_digit();
    if (b.accuracy >= 	res.nb_significant_digit()+_cadna_cancel_value)
	instability(&_cadna_cancel_count);
  }
  return res;
}
inline double_st operator-(const char& a, const double_st& b){
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

  if (_cadna_cancel_tag){
    if (b.accuracy==DIGIT_NOT_COMPUTED || b.accuracy==RELIABLE_RESULT)
	b.nb_significant_digit();
    if (b.accuracy >= 	res.nb_significant_digit()+_cadna_cancel_value)
	instability(&_cadna_cancel_count);
  }
  return res;
}

inline float_st operator-(const double& a, const float_st& b){
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

  if (_cadna_cancel_tag){
    if (b.accuracy==DIGIT_NOT_COMPUTED || b.accuracy==RELIABLE_RESULT)
	b.nb_significant_digit();
    if (b.accuracy >= 	res.nb_significant_digit()+_cadna_cancel_value)
	instability(&_cadna_cancel_count);
  }
  return res;
}
inline float_st operator-(const float& a, const float_st& b){
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

  if (_cadna_cancel_tag){
    if (b.accuracy==DIGIT_NOT_COMPUTED || b.accuracy==RELIABLE_RESULT)
	b.nb_significant_digit();
    if (b.accuracy >= 	res.nb_significant_digit()+_cadna_cancel_value)
	instability(&_cadna_cancel_count);
  }
  return res;
}
inline float_st operator-(const unsigned long long& a, const float_st& b){
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

  if (_cadna_cancel_tag){
    if (b.accuracy==DIGIT_NOT_COMPUTED || b.accuracy==RELIABLE_RESULT)
	b.nb_significant_digit();
    if (b.accuracy >= 	res.nb_significant_digit()+_cadna_cancel_value)
	instability(&_cadna_cancel_count);
  }
  return res;
}
inline float_st operator-(const long long& a, const float_st& b){
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

  if (_cadna_cancel_tag){
    if (b.accuracy==DIGIT_NOT_COMPUTED || b.accuracy==RELIABLE_RESULT)
	b.nb_significant_digit();
    if (b.accuracy >= 	res.nb_significant_digit()+_cadna_cancel_value)
	instability(&_cadna_cancel_count);
  }
  return res;
}
inline float_st operator-(const unsigned long& a, const float_st& b){
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

  if (_cadna_cancel_tag){
    if (b.accuracy==DIGIT_NOT_COMPUTED || b.accuracy==RELIABLE_RESULT)
	b.nb_significant_digit();
    if (b.accuracy >= 	res.nb_significant_digit()+_cadna_cancel_value)
	instability(&_cadna_cancel_count);
  }
  return res;
}
inline float_st operator-(const long& a, const float_st& b){
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

  if (_cadna_cancel_tag){
    if (b.accuracy==DIGIT_NOT_COMPUTED || b.accuracy==RELIABLE_RESULT)
	b.nb_significant_digit();
    if (b.accuracy >= 	res.nb_significant_digit()+_cadna_cancel_value)
	instability(&_cadna_cancel_count);
  }
  return res;
}
inline float_st operator-(const unsigned int & a, const float_st& b){
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

  if (_cadna_cancel_tag){
    if (b.accuracy==DIGIT_NOT_COMPUTED || b.accuracy==RELIABLE_RESULT)
	b.nb_significant_digit();
    if (b.accuracy >= 	res.nb_significant_digit()+_cadna_cancel_value)
	instability(&_cadna_cancel_count);
  }
  return res;
}
inline float_st operator-(const int & a, const float_st& b){
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

  if (_cadna_cancel_tag){
    if (b.accuracy==DIGIT_NOT_COMPUTED || b.accuracy==RELIABLE_RESULT)
	b.nb_significant_digit();
    if (b.accuracy >= 	res.nb_significant_digit()+_cadna_cancel_value)
	instability(&_cadna_cancel_count);
  }
  return res;
}
inline float_st operator-(const unsigned short& a, const float_st& b){
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

  if (_cadna_cancel_tag){
    if (b.accuracy==DIGIT_NOT_COMPUTED || b.accuracy==RELIABLE_RESULT)
	b.nb_significant_digit();
    if (b.accuracy >= 	res.nb_significant_digit()+_cadna_cancel_value)
	instability(&_cadna_cancel_count);
  }
  return res;
}
inline float_st operator-(const short& a, const float_st& b){
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

  if (_cadna_cancel_tag){
    if (b.accuracy==DIGIT_NOT_COMPUTED || b.accuracy==RELIABLE_RESULT)
	b.nb_significant_digit();
    if (b.accuracy >= 	res.nb_significant_digit()+_cadna_cancel_value)
	instability(&_cadna_cancel_count);
  }
  return res;
}
inline float_st operator-(const unsigned char& a, const float_st& b){
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

  if (_cadna_cancel_tag){
    if (b.accuracy==DIGIT_NOT_COMPUTED || b.accuracy==RELIABLE_RESULT)
	b.nb_significant_digit();
    if (b.accuracy >= 	res.nb_significant_digit()+_cadna_cancel_value)
	instability(&_cadna_cancel_count);
  }
  return res;
}
inline float_st operator-(const char& a, const float_st& b){
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

  if (_cadna_cancel_tag){
    if (b.accuracy==DIGIT_NOT_COMPUTED || b.accuracy==RELIABLE_RESULT)
	b.nb_significant_digit();
    if (b.accuracy >= 	res.nb_significant_digit()+_cadna_cancel_value)
	instability(&_cadna_cancel_count);
  }
  return res;
}

/////////////////////////////////////////////////////////////////////////



inline double_st operator-(const double_st& a, const double& b){
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

  if (_cadna_cancel_tag){
    if (a.accuracy==DIGIT_NOT_COMPUTED || a.accuracy==RELIABLE_RESULT)
	a.nb_significant_digit();
    if (a.accuracy >= 	res.nb_significant_digit()+_cadna_cancel_value)
	instability(&_cadna_cancel_count);
  }
  return res;
}
inline double_st operator-(const double_st& a, const float& b){
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

  if (_cadna_cancel_tag){
    if (a.accuracy==DIGIT_NOT_COMPUTED || a.accuracy==RELIABLE_RESULT)
	a.nb_significant_digit();
    if (a.accuracy >= 	res.nb_significant_digit()+_cadna_cancel_value)
	instability(&_cadna_cancel_count);
  }
  return res;
}
inline double_st operator-(const double_st& a, const unsigned long long& b){
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

  if (_cadna_cancel_tag){
    if (a.accuracy==DIGIT_NOT_COMPUTED || a.accuracy==RELIABLE_RESULT)
	a.nb_significant_digit();
    if (a.accuracy >= 	res.nb_significant_digit()+_cadna_cancel_value)
	instability(&_cadna_cancel_count);
  }
  return res;
}
inline double_st operator-(const double_st& a, const long long& b){
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

  if (_cadna_cancel_tag){
    if (a.accuracy==DIGIT_NOT_COMPUTED || a.accuracy==RELIABLE_RESULT)
	a.nb_significant_digit();
    if (a.accuracy >= 	res.nb_significant_digit()+_cadna_cancel_value)
	instability(&_cadna_cancel_count);
  }
  return res;
}
inline double_st operator-(const double_st& a, const unsigned long& b){
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

  if (_cadna_cancel_tag){
    if (a.accuracy==DIGIT_NOT_COMPUTED || a.accuracy==RELIABLE_RESULT)
	a.nb_significant_digit();
    if (a.accuracy >= 	res.nb_significant_digit()+_cadna_cancel_value)
	instability(&_cadna_cancel_count);
  }
  return res;
}
inline double_st operator-(const double_st& a, const long& b){
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

  if (_cadna_cancel_tag){
    if (a.accuracy==DIGIT_NOT_COMPUTED || a.accuracy==RELIABLE_RESULT)
	a.nb_significant_digit();
    if (a.accuracy >= 	res.nb_significant_digit()+_cadna_cancel_value)
	instability(&_cadna_cancel_count);
  }
  return res;
}
inline double_st operator-(const double_st& a, const unsigned int & b){
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

  if (_cadna_cancel_tag){
    if (a.accuracy==DIGIT_NOT_COMPUTED || a.accuracy==RELIABLE_RESULT)
	a.nb_significant_digit();
    if (a.accuracy >= 	res.nb_significant_digit()+_cadna_cancel_value)
	instability(&_cadna_cancel_count);
  }
  return res;
}
inline double_st operator-(const double_st& a, const int & b){
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

  if (_cadna_cancel_tag){
    if (a.accuracy==DIGIT_NOT_COMPUTED || a.accuracy==RELIABLE_RESULT)
	a.nb_significant_digit();
    if (a.accuracy >= 	res.nb_significant_digit()+_cadna_cancel_value)
	instability(&_cadna_cancel_count);
  }
  return res;
}
inline double_st operator-(const double_st& a, const unsigned short& b){
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

  if (_cadna_cancel_tag){
    if (a.accuracy==DIGIT_NOT_COMPUTED || a.accuracy==RELIABLE_RESULT)
	a.nb_significant_digit();
    if (a.accuracy >= 	res.nb_significant_digit()+_cadna_cancel_value)
	instability(&_cadna_cancel_count);
  }
  return res;
}
inline double_st operator-(const double_st& a, const short& b){
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

  if (_cadna_cancel_tag){
    if (a.accuracy==DIGIT_NOT_COMPUTED || a.accuracy==RELIABLE_RESULT)
	a.nb_significant_digit();
    if (a.accuracy >= 	res.nb_significant_digit()+_cadna_cancel_value)
	instability(&_cadna_cancel_count);
  }
  return res;
}
inline double_st operator-(const double_st& a, const unsigned char& b){
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

  if (_cadna_cancel_tag){
    if (a.accuracy==DIGIT_NOT_COMPUTED || a.accuracy==RELIABLE_RESULT)
	a.nb_significant_digit();
    if (a.accuracy >= 	res.nb_significant_digit()+_cadna_cancel_value)
	instability(&_cadna_cancel_count);
  }
  return res;
}
inline double_st operator-(const double_st& a, const char& b){
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

  if (_cadna_cancel_tag){
    if (a.accuracy==DIGIT_NOT_COMPUTED || a.accuracy==RELIABLE_RESULT)
	a.nb_significant_digit();
    if (a.accuracy >= 	res.nb_significant_digit()+_cadna_cancel_value)
	instability(&_cadna_cancel_count);
  }
  return res;
}

inline float_st operator-(const float_st& a, const double& b){
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

  if (_cadna_cancel_tag){
    if (a.accuracy==DIGIT_NOT_COMPUTED || a.accuracy==RELIABLE_RESULT)
	a.nb_significant_digit();
    if (a.accuracy >= 	res.nb_significant_digit()+_cadna_cancel_value)
	instability(&_cadna_cancel_count);
  }
  return res;
}
inline float_st operator-(const float_st& a, const float& b){
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

  if (_cadna_cancel_tag){
    if (a.accuracy==DIGIT_NOT_COMPUTED || a.accuracy==RELIABLE_RESULT)
	a.nb_significant_digit();
    if (a.accuracy >= 	res.nb_significant_digit()+_cadna_cancel_value)
	instability(&_cadna_cancel_count);
  }
  return res;
}
inline float_st operator-(const float_st& a, const unsigned long long& b){
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

  if (_cadna_cancel_tag){
    if (a.accuracy==DIGIT_NOT_COMPUTED || a.accuracy==RELIABLE_RESULT)
	a.nb_significant_digit();
    if (a.accuracy >= 	res.nb_significant_digit()+_cadna_cancel_value)
	instability(&_cadna_cancel_count);
  }
  return res;
}
inline float_st operator-(const float_st& a, const long long& b){
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

  if (_cadna_cancel_tag){
    if (a.accuracy==DIGIT_NOT_COMPUTED || a.accuracy==RELIABLE_RESULT)
	a.nb_significant_digit();
    if (a.accuracy >= 	res.nb_significant_digit()+_cadna_cancel_value)
	instability(&_cadna_cancel_count);
  }
  return res;
}
inline float_st operator-(const float_st& a, const unsigned long& b){
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

  if (_cadna_cancel_tag){
    if (a.accuracy==DIGIT_NOT_COMPUTED || a.accuracy==RELIABLE_RESULT)
	a.nb_significant_digit();
    if (a.accuracy >= 	res.nb_significant_digit()+_cadna_cancel_value)
	instability(&_cadna_cancel_count);
  }
  return res;
}
inline float_st operator-(const float_st& a, const long& b){
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

  if (_cadna_cancel_tag){
    if (a.accuracy==DIGIT_NOT_COMPUTED || a.accuracy==RELIABLE_RESULT)
	a.nb_significant_digit();
    if (a.accuracy >= 	res.nb_significant_digit()+_cadna_cancel_value)
	instability(&_cadna_cancel_count);
  }
  return res;
}
inline float_st operator-(const float_st& a, const unsigned int & b){
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

  if (_cadna_cancel_tag){
    if (a.accuracy==DIGIT_NOT_COMPUTED || a.accuracy==RELIABLE_RESULT)
	a.nb_significant_digit();
    if (a.accuracy >= 	res.nb_significant_digit()+_cadna_cancel_value)
	instability(&_cadna_cancel_count);
  }
  return res;
}
inline float_st operator-(const float_st& a, const int & b){
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

  if (_cadna_cancel_tag){
    if (a.accuracy==DIGIT_NOT_COMPUTED || a.accuracy==RELIABLE_RESULT)
	a.nb_significant_digit();
    if (a.accuracy >= 	res.nb_significant_digit()+_cadna_cancel_value)
	instability(&_cadna_cancel_count);
  }
  return res;
}
inline float_st operator-(const float_st& a, const unsigned short& b){
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

  if (_cadna_cancel_tag){
    if (a.accuracy==DIGIT_NOT_COMPUTED || a.accuracy==RELIABLE_RESULT)
	a.nb_significant_digit();
    if (a.accuracy >= 	res.nb_significant_digit()+_cadna_cancel_value)
	instability(&_cadna_cancel_count);
  }
  return res;
}
inline float_st operator-(const float_st& a, const short& b){
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

  if (_cadna_cancel_tag){
    if (a.accuracy==DIGIT_NOT_COMPUTED || a.accuracy==RELIABLE_RESULT)
	a.nb_significant_digit();
    if (a.accuracy >= 	res.nb_significant_digit()+_cadna_cancel_value)
	instability(&_cadna_cancel_count);
  }
  return res;
}
inline float_st operator-(const float_st& a, const unsigned char& b){
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

  if (_cadna_cancel_tag){
    if (a.accuracy==DIGIT_NOT_COMPUTED || a.accuracy==RELIABLE_RESULT)
	a.nb_significant_digit();
    if (a.accuracy >= 	res.nb_significant_digit()+_cadna_cancel_value)
	instability(&_cadna_cancel_count);
  }
  return res;
}
inline float_st operator-(const float_st& a, const char& b){
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

  if (_cadna_cancel_tag){
    if (a.accuracy==DIGIT_NOT_COMPUTED || a.accuracy==RELIABLE_RESULT)
	a.nb_significant_digit();
    if (a.accuracy >= 	res.nb_significant_digit()+_cadna_cancel_value)
	instability(&_cadna_cancel_count);
  }
  return res;
}

/////////////////////////////////////////////////////////////////////////



inline double_st operator-(const double_st& a, const double_st& b){
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

  if (_cadna_cancel_tag){
    if (a.accuracy==DIGIT_NOT_COMPUTED || a.accuracy==RELIABLE_RESULT)
	a.nb_significant_digit();
    if (b.accuracy==DIGIT_NOT_COMPUTED || b.accuracy==RELIABLE_RESULT)
	b.nb_significant_digit();
    if ((a.accuracy < b.accuracy ? a.accuracy: b.accuracy) >=
	  res.nb_significant_digit()+_cadna_cancel_value)
	instability(&_cadna_cancel_count);
  }
  return res;
}
inline double_st operator-(const double_st& a, const float_st& b){
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

  if (_cadna_cancel_tag){
    if (a.accuracy==DIGIT_NOT_COMPUTED || a.accuracy==RELIABLE_RESULT)
	a.nb_significant_digit();
    if (b.accuracy==DIGIT_NOT_COMPUTED || b.accuracy==RELIABLE_RESULT)
	b.nb_significant_digit();
    if ((a.accuracy < b.accuracy ? a.accuracy: b.accuracy) >=
	  res.nb_significant_digit()+_cadna_cancel_value)
	instability(&_cadna_cancel_count);
  }
  return res;
}
inline double_st operator-(const float_st& a, const double_st& b){
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

  if (_cadna_cancel_tag){
    if (a.accuracy==DIGIT_NOT_COMPUTED || a.accuracy==RELIABLE_RESULT)
	a.nb_significant_digit();
    if (b.accuracy==DIGIT_NOT_COMPUTED || b.accuracy==RELIABLE_RESULT)
	b.nb_significant_digit();
    if ((a.accuracy < b.accuracy ? a.accuracy: b.accuracy) >=
	  res.nb_significant_digit()+_cadna_cancel_value)
	instability(&_cadna_cancel_count);
  }
  return res;
}
inline float_st operator-(const float_st& a, const float_st& b){
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

  if (_cadna_cancel_tag){
    if (a.accuracy==DIGIT_NOT_COMPUTED || a.accuracy==RELIABLE_RESULT)
	a.nb_significant_digit();
    if (b.accuracy==DIGIT_NOT_COMPUTED || b.accuracy==RELIABLE_RESULT)
	b.nb_significant_digit();
    if ((a.accuracy < b.accuracy ? a.accuracy: b.accuracy) >=
	  res.nb_significant_digit()+_cadna_cancel_value)
	instability(&_cadna_cancel_count);
  }
  return res;
}

/////////////////////////////////////////////////////////////////////////

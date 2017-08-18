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
#include <math.h>




//****f* cadna_math/pow
//    NAME
//      pow
//    SYNOPSIS
//      res = pow(x,y)
//    FUNCTION
//      The pow() functions compute x raised to the power y.
//
//
//    INPUTS
//      a           - double_st
//      b           - double_st
//    RESULT
//      res         - double_st
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

//****f* cadna_math/powf
//    NAME
//      powf
//    SYNOPSIS
//      res = powf(x,y)
//    FUNCTION
//      The powf() functions compute x raised to the power y.
//
//
//    INPUTS
//      a           - float_st
//      b           - float_st
//    RESULT
//      res         - float_st
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






double_st pow(const double& a, const double_st& b){
    double_st res;

    if(_cadna_power_tag!=0){
      if (b.accuracy==DIGIT_NOT_COMPUTED) b.approx_digit();
      if (b.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=pow((double)a,(double)b.x);
    res.y=pow((double)a,(double)b.y);
    res.z=pow((double)a,(double)b.z);
    fesetround(FE_UPWARD);

    return res;
  }
double_st pow(const float& a, const double_st& b){
    double_st res;

    if(_cadna_power_tag!=0){
      if (b.accuracy==DIGIT_NOT_COMPUTED) b.approx_digit();
      if (b.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=pow((double)a,(double)b.x);
    res.y=pow((double)a,(double)b.y);
    res.z=pow((double)a,(double)b.z);
    fesetround(FE_UPWARD);

    return res;
  }
double_st pow(const unsigned long long& a, const double_st& b){
    double_st res;

    if(_cadna_power_tag!=0){
      if (b.accuracy==DIGIT_NOT_COMPUTED) b.approx_digit();
      if (b.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=pow((double)a,(double)b.x);
    res.y=pow((double)a,(double)b.y);
    res.z=pow((double)a,(double)b.z);
    fesetround(FE_UPWARD);

    return res;
  }
double_st pow(const long long& a, const double_st& b){
    double_st res;

    if(_cadna_power_tag!=0){
      if (b.accuracy==DIGIT_NOT_COMPUTED) b.approx_digit();
      if (b.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=pow((double)a,(double)b.x);
    res.y=pow((double)a,(double)b.y);
    res.z=pow((double)a,(double)b.z);
    fesetround(FE_UPWARD);

    return res;
  }
double_st pow(const unsigned long& a, const double_st& b){
    double_st res;

    if(_cadna_power_tag!=0){
      if (b.accuracy==DIGIT_NOT_COMPUTED) b.approx_digit();
      if (b.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=pow((double)a,(double)b.x);
    res.y=pow((double)a,(double)b.y);
    res.z=pow((double)a,(double)b.z);
    fesetround(FE_UPWARD);

    return res;
  }
double_st pow(const long& a, const double_st& b){
    double_st res;

    if(_cadna_power_tag!=0){
      if (b.accuracy==DIGIT_NOT_COMPUTED) b.approx_digit();
      if (b.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=pow((double)a,(double)b.x);
    res.y=pow((double)a,(double)b.y);
    res.z=pow((double)a,(double)b.z);
    fesetround(FE_UPWARD);

    return res;
  }
double_st pow(const unsigned int& a, const double_st& b){
    double_st res;

    if(_cadna_power_tag!=0){
      if (b.accuracy==DIGIT_NOT_COMPUTED) b.approx_digit();
      if (b.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=pow((double)a,(double)b.x);
    res.y=pow((double)a,(double)b.y);
    res.z=pow((double)a,(double)b.z);
    fesetround(FE_UPWARD);

    return res;
  }
double_st pow(const int& a, const double_st& b){
    double_st res;

    if(_cadna_power_tag!=0){
      if (b.accuracy==DIGIT_NOT_COMPUTED) b.approx_digit();
      if (b.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=pow((double)a,(double)b.x);
    res.y=pow((double)a,(double)b.y);
    res.z=pow((double)a,(double)b.z);
    fesetround(FE_UPWARD);

    return res;
  }
double_st pow(const unsigned short& a, const double_st& b){
    double_st res;

    if(_cadna_power_tag!=0){
      if (b.accuracy==DIGIT_NOT_COMPUTED) b.approx_digit();
      if (b.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=pow((double)a,(double)b.x);
    res.y=pow((double)a,(double)b.y);
    res.z=pow((double)a,(double)b.z);
    fesetround(FE_UPWARD);

    return res;
  }
double_st pow(const short& a, const double_st& b){
    double_st res;

    if(_cadna_power_tag!=0){
      if (b.accuracy==DIGIT_NOT_COMPUTED) b.approx_digit();
      if (b.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=pow((double)a,(double)b.x);
    res.y=pow((double)a,(double)b.y);
    res.z=pow((double)a,(double)b.z);
    fesetround(FE_UPWARD);

    return res;
  }
double_st pow(const unsigned char& a, const double_st& b){
    double_st res;

    if(_cadna_power_tag!=0){
      if (b.accuracy==DIGIT_NOT_COMPUTED) b.approx_digit();
      if (b.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=pow((double)a,(double)b.x);
    res.y=pow((double)a,(double)b.y);
    res.z=pow((double)a,(double)b.z);
    fesetround(FE_UPWARD);

    return res;
  }
double_st pow(const char& a, const double_st& b){
    double_st res;

    if(_cadna_power_tag!=0){
      if (b.accuracy==DIGIT_NOT_COMPUTED) b.approx_digit();
      if (b.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=pow((double)a,(double)b.x);
    res.y=pow((double)a,(double)b.y);
    res.z=pow((double)a,(double)b.z);
    fesetround(FE_UPWARD);

    return res;
  }

float_st powf(const double& a, const float_st& b){
    float_st res;

    if(_cadna_power_tag!=0){
      if (b.accuracy==DIGIT_NOT_COMPUTED) b.approx_digit();
      if (b.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=powf((float)a,(float)b.x);
    res.y=powf((float)a,(float)b.y);
    res.z=powf((float)a,(float)b.z);
    fesetround(FE_UPWARD);

    return res;
  }
float_st powf(const float& a, const float_st& b){
    float_st res;

    if(_cadna_power_tag!=0){
      if (b.accuracy==DIGIT_NOT_COMPUTED) b.approx_digit();
      if (b.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=powf((float)a,(float)b.x);
    res.y=powf((float)a,(float)b.y);
    res.z=powf((float)a,(float)b.z);
    fesetround(FE_UPWARD);

    return res;
  }
float_st powf(const unsigned long long& a, const float_st& b){
    float_st res;

    if(_cadna_power_tag!=0){
      if (b.accuracy==DIGIT_NOT_COMPUTED) b.approx_digit();
      if (b.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=powf((float)a,(float)b.x);
    res.y=powf((float)a,(float)b.y);
    res.z=powf((float)a,(float)b.z);
    fesetround(FE_UPWARD);

    return res;
  }
float_st powf(const long long& a, const float_st& b){
    float_st res;

    if(_cadna_power_tag!=0){
      if (b.accuracy==DIGIT_NOT_COMPUTED) b.approx_digit();
      if (b.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=powf((float)a,(float)b.x);
    res.y=powf((float)a,(float)b.y);
    res.z=powf((float)a,(float)b.z);
    fesetround(FE_UPWARD);

    return res;
  }
float_st powf(const unsigned long& a, const float_st& b){
    float_st res;

    if(_cadna_power_tag!=0){
      if (b.accuracy==DIGIT_NOT_COMPUTED) b.approx_digit();
      if (b.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=powf((float)a,(float)b.x);
    res.y=powf((float)a,(float)b.y);
    res.z=powf((float)a,(float)b.z);
    fesetround(FE_UPWARD);

    return res;
  }
float_st powf(const long& a, const float_st& b){
    float_st res;

    if(_cadna_power_tag!=0){
      if (b.accuracy==DIGIT_NOT_COMPUTED) b.approx_digit();
      if (b.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=powf((float)a,(float)b.x);
    res.y=powf((float)a,(float)b.y);
    res.z=powf((float)a,(float)b.z);
    fesetround(FE_UPWARD);

    return res;
  }
float_st powf(const unsigned int & a, const float_st& b){
    float_st res;

    if(_cadna_power_tag!=0){
      if (b.accuracy==DIGIT_NOT_COMPUTED) b.approx_digit();
      if (b.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=powf((float)a,(float)b.x);
    res.y=powf((float)a,(float)b.y);
    res.z=powf((float)a,(float)b.z);
    fesetround(FE_UPWARD);

    return res;
  }
float_st powf(const int& a, const float_st& b){
    float_st res;

    if(_cadna_power_tag!=0){
      if (b.accuracy==DIGIT_NOT_COMPUTED) b.approx_digit();
      if (b.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=powf((float)a,(float)b.x);
    res.y=powf((float)a,(float)b.y);
    res.z=powf((float)a,(float)b.z);
    fesetround(FE_UPWARD);

    return res;
  }
float_st powf(const unsigned short& a, const float_st& b){
    float_st res;

    if(_cadna_power_tag!=0){
      if (b.accuracy==DIGIT_NOT_COMPUTED) b.approx_digit();
      if (b.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=powf((float)a,(float)b.x);
    res.y=powf((float)a,(float)b.y);
    res.z=powf((float)a,(float)b.z);
    fesetround(FE_UPWARD);

    return res;
  }
float_st powf(const short& a, const float_st& b){
    float_st res;

    if(_cadna_power_tag!=0){
      if (b.accuracy==DIGIT_NOT_COMPUTED) b.approx_digit();
      if (b.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=powf((float)a,(float)b.x);
    res.y=powf((float)a,(float)b.y);
    res.z=powf((float)a,(float)b.z);
    fesetround(FE_UPWARD);

    return res;
  }
float_st powf(const unsigned char& a, const float_st& b){
    float_st res;

    if(_cadna_power_tag!=0){
      if (b.accuracy==DIGIT_NOT_COMPUTED) b.approx_digit();
      if (b.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=powf((float)a,(float)b.x);
    res.y=powf((float)a,(float)b.y);
    res.z=powf((float)a,(float)b.z);
    fesetround(FE_UPWARD);

    return res;
  }
float_st powf(const char& a, const float_st& b){
    float_st res;

    if(_cadna_power_tag!=0){
      if (b.accuracy==DIGIT_NOT_COMPUTED) b.approx_digit();
      if (b.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=powf((float)a,(float)b.x);
    res.y=powf((float)a,(float)b.y);
    res.z=powf((float)a,(float)b.z);
    fesetround(FE_UPWARD);

    return res;
  }

float_st pow(const double& a, const float_st& b){
    float_st res;

    if(_cadna_power_tag!=0){
      if (b.accuracy==DIGIT_NOT_COMPUTED) b.approx_digit();
      if (b.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=pow((double)a,(double)b.x);
    res.y=pow((double)a,(double)b.y);
    res.z=pow((double)a,(double)b.z);
    fesetround(FE_UPWARD);

    return res;
  }
float_st pow(const float& a, const float_st& b){
    float_st res;

    if(_cadna_power_tag!=0){
      if (b.accuracy==DIGIT_NOT_COMPUTED) b.approx_digit();
      if (b.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=pow((double)a,(double)b.x);
    res.y=pow((double)a,(double)b.y);
    res.z=pow((double)a,(double)b.z);
    fesetround(FE_UPWARD);

    return res;
  }
float_st pow(const unsigned long long& a, const float_st& b){
    float_st res;

    if(_cadna_power_tag!=0){
      if (b.accuracy==DIGIT_NOT_COMPUTED) b.approx_digit();
      if (b.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=pow((double)a,(double)b.x);
    res.y=pow((double)a,(double)b.y);
    res.z=pow((double)a,(double)b.z);
    fesetround(FE_UPWARD);

    return res;
  }
float_st pow(const long long& a, const float_st& b){
    float_st res;

    if(_cadna_power_tag!=0){
      if (b.accuracy==DIGIT_NOT_COMPUTED) b.approx_digit();
      if (b.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=pow((double)a,(double)b.x);
    res.y=pow((double)a,(double)b.y);
    res.z=pow((double)a,(double)b.z);
    fesetround(FE_UPWARD);

    return res;
  }
float_st pow(const unsigned long& a, const float_st& b){
    float_st res;

    if(_cadna_power_tag!=0){
      if (b.accuracy==DIGIT_NOT_COMPUTED) b.approx_digit();
      if (b.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=pow((double)a,(double)b.x);
    res.y=pow((double)a,(double)b.y);
    res.z=pow((double)a,(double)b.z);
    fesetround(FE_UPWARD);

    return res;
  }
float_st pow(const long& a, const float_st& b){
    float_st res;

    if(_cadna_power_tag!=0){
      if (b.accuracy==DIGIT_NOT_COMPUTED) b.approx_digit();
      if (b.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=pow((double)a,(double)b.x);
    res.y=pow((double)a,(double)b.y);
    res.z=pow((double)a,(double)b.z);
    fesetround(FE_UPWARD);

    return res;
  }
float_st pow(const unsigned int & a, const float_st& b){
    float_st res;

    if(_cadna_power_tag!=0){
      if (b.accuracy==DIGIT_NOT_COMPUTED) b.approx_digit();
      if (b.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=pow((double)a,(double)b.x);
    res.y=pow((double)a,(double)b.y);
    res.z=pow((double)a,(double)b.z);
    fesetround(FE_UPWARD);

    return res;
  }
float_st pow(const int& a, const float_st& b){
    float_st res;

    if(_cadna_power_tag!=0){
      if (b.accuracy==DIGIT_NOT_COMPUTED) b.approx_digit();
      if (b.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=pow((double)a,(double)b.x);
    res.y=pow((double)a,(double)b.y);
    res.z=pow((double)a,(double)b.z);
    fesetround(FE_UPWARD);

    return res;
  }
float_st pow(const unsigned short& a, const float_st& b){
    float_st res;

    if(_cadna_power_tag!=0){
      if (b.accuracy==DIGIT_NOT_COMPUTED) b.approx_digit();
      if (b.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=pow((double)a,(double)b.x);
    res.y=pow((double)a,(double)b.y);
    res.z=pow((double)a,(double)b.z);
    fesetround(FE_UPWARD);

    return res;
  }
float_st pow(const short& a, const float_st& b){
    float_st res;

    if(_cadna_power_tag!=0){
      if (b.accuracy==DIGIT_NOT_COMPUTED) b.approx_digit();
      if (b.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=pow((double)a,(double)b.x);
    res.y=pow((double)a,(double)b.y);
    res.z=pow((double)a,(double)b.z);
    fesetround(FE_UPWARD);

    return res;
  }
float_st pow(const unsigned char& a, const float_st& b){
    float_st res;

    if(_cadna_power_tag!=0){
      if (b.accuracy==DIGIT_NOT_COMPUTED) b.approx_digit();
      if (b.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=pow((double)a,(double)b.x);
    res.y=pow((double)a,(double)b.y);
    res.z=pow((double)a,(double)b.z);
    fesetround(FE_UPWARD);

    return res;
  }
float_st pow(const char& a, const float_st& b){
    float_st res;

    if(_cadna_power_tag!=0){
      if (b.accuracy==DIGIT_NOT_COMPUTED) b.approx_digit();
      if (b.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=pow((double)a,(double)b.x);
    res.y=pow((double)a,(double)b.y);
    res.z=pow((double)a,(double)b.z);
    fesetround(FE_UPWARD);

    return res;
  }







double_st pow(const double_st& a, const double& b)
  {
    double_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    fesetround(FE_TONEAREST);
    res.accuracy=DIGIT_NOT_COMPUTED;
    res.x=pow((double)a.x, (double)b);
    res.y=pow((double)a.y, (double)b);
    res.z=pow((double)a.z, (double)b);
    fesetround(FE_UPWARD);

    return res;
  }
double_st pow(const double_st& a, const float& b)
  {
    double_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    fesetround(FE_TONEAREST);
    res.accuracy=DIGIT_NOT_COMPUTED;
    res.x=pow((double)a.x, (double)b);
    res.y=pow((double)a.y, (double)b);
    res.z=pow((double)a.z, (double)b);
    fesetround(FE_UPWARD);

    return res;
  }
double_st pow(const double_st& a, const unsigned long long& b)
  {
    double_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    fesetround(FE_TONEAREST);
    res.accuracy=DIGIT_NOT_COMPUTED;
    res.x=pow((double)a.x, (double)b);
    res.y=pow((double)a.y, (double)b);
    res.z=pow((double)a.z, (double)b);
    fesetround(FE_UPWARD);

    return res;
  }
double_st pow(const double_st& a, const long long& b)
  {
    double_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    fesetround(FE_TONEAREST);
    res.accuracy=DIGIT_NOT_COMPUTED;
    res.x=pow((double)a.x, (double)b);
    res.y=pow((double)a.y, (double)b);
    res.z=pow((double)a.z, (double)b);
    fesetround(FE_UPWARD);

    return res;
  }
double_st pow(const double_st& a, const unsigned long& b)
  {
    double_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    fesetround(FE_TONEAREST);
    res.accuracy=DIGIT_NOT_COMPUTED;
    res.x=pow((double)a.x, (double)b);
    res.y=pow((double)a.y, (double)b);
    res.z=pow((double)a.z, (double)b);
    fesetround(FE_UPWARD);

    return res;
  }
double_st pow(const double_st& a, const long& b)
  {
    double_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    fesetround(FE_TONEAREST);
    res.accuracy=DIGIT_NOT_COMPUTED;
    res.x=pow((double)a.x, (double)b);
    res.y=pow((double)a.y, (double)b);
    res.z=pow((double)a.z, (double)b);
    fesetround(FE_UPWARD);

    return res;
  }
double_st pow(const double_st& a, const unsigned int & b)
  {
    double_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    fesetround(FE_TONEAREST);
    res.accuracy=DIGIT_NOT_COMPUTED;
    res.x=pow((double)a.x, (double)b);
    res.y=pow((double)a.y, (double)b);
    res.z=pow((double)a.z, (double)b);
    fesetround(FE_UPWARD);

    return res;
  }
double_st pow(const double_st& a, const int & b)
  {
    double_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    fesetround(FE_TONEAREST);
    res.accuracy=DIGIT_NOT_COMPUTED;
    res.x=pow((double)a.x, (double)b);
    res.y=pow((double)a.y, (double)b);
    res.z=pow((double)a.z, (double)b);
    fesetround(FE_UPWARD);

    return res;
  }
double_st pow(const double_st& a, const unsigned short& b)
  {
    double_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    fesetround(FE_TONEAREST);
    res.accuracy=DIGIT_NOT_COMPUTED;
    res.x=pow((double)a.x, (double)b);
    res.y=pow((double)a.y, (double)b);
    res.z=pow((double)a.z, (double)b);
    fesetround(FE_UPWARD);

    return res;
  }
double_st pow(const double_st& a, const short& b)
  {
    double_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    fesetround(FE_TONEAREST);
    res.accuracy=DIGIT_NOT_COMPUTED;
    res.x=pow((double)a.x, (double)b);
    res.y=pow((double)a.y, (double)b);
    res.z=pow((double)a.z, (double)b);
    fesetround(FE_UPWARD);

    return res;
  }
double_st pow(const double_st& a, const unsigned char& b)
  {
    double_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    fesetround(FE_TONEAREST);
    res.accuracy=DIGIT_NOT_COMPUTED;
    res.x=pow((double)a.x, (double)b);
    res.y=pow((double)a.y, (double)b);
    res.z=pow((double)a.z, (double)b);
    fesetround(FE_UPWARD);

    return res;
  }
double_st pow(const double_st& a, const char& b)
  {
    double_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    fesetround(FE_TONEAREST);
    res.accuracy=DIGIT_NOT_COMPUTED;
    res.x=pow((double)a.x, (double)b);
    res.y=pow((double)a.y, (double)b);
    res.z=pow((double)a.z, (double)b);
    fesetround(FE_UPWARD);

    return res;
  }

float_st powf(const float_st& a, const double& b)
  {
    float_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    fesetround(FE_TONEAREST);
    res.accuracy=DIGIT_NOT_COMPUTED;
    res.x=powf((float)a.x, (float)b);
    res.y=powf((float)a.y, (float)b);
    res.z=powf((float)a.z, (float)b);
    fesetround(FE_UPWARD);

    return res;
  }
float_st powf(const float_st& a, const float& b)
  {
    float_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    fesetround(FE_TONEAREST);
    res.accuracy=DIGIT_NOT_COMPUTED;
    res.x=powf((float)a.x, (float)b);
    res.y=powf((float)a.y, (float)b);
    res.z=powf((float)a.z, (float)b);
    fesetround(FE_UPWARD);

    return res;
  }
float_st powf(const float_st& a, const unsigned long long& b)
  {
    float_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    fesetround(FE_TONEAREST);
    res.accuracy=DIGIT_NOT_COMPUTED;
    res.x=powf((float)a.x, (float)b);
    res.y=powf((float)a.y, (float)b);
    res.z=powf((float)a.z, (float)b);
    fesetround(FE_UPWARD);

    return res;
  }
float_st powf(const float_st& a, const long long& b)
  {
    float_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    fesetround(FE_TONEAREST);
    res.accuracy=DIGIT_NOT_COMPUTED;
    res.x=powf((float)a.x, (float)b);
    res.y=powf((float)a.y, (float)b);
    res.z=powf((float)a.z, (float)b);
    fesetround(FE_UPWARD);

    return res;
  }
float_st powf(const float_st& a, const unsigned long& b)
  {
    float_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    fesetround(FE_TONEAREST);
    res.accuracy=DIGIT_NOT_COMPUTED;
    res.x=powf((float)a.x, (float)b);
    res.y=powf((float)a.y, (float)b);
    res.z=powf((float)a.z, (float)b);
    fesetround(FE_UPWARD);

    return res;
  }
float_st powf(const float_st& a, const long& b)
  {
    float_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    fesetround(FE_TONEAREST);
    res.accuracy=DIGIT_NOT_COMPUTED;
    res.x=powf((float)a.x, (float)b);
    res.y=powf((float)a.y, (float)b);
    res.z=powf((float)a.z, (float)b);
    fesetround(FE_UPWARD);

    return res;
  }
float_st powf(const float_st& a, const unsigned int & b)
  {
    float_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    fesetround(FE_TONEAREST);
    res.accuracy=DIGIT_NOT_COMPUTED;
    res.x=powf((float)a.x, (float)b);
    res.y=powf((float)a.y, (float)b);
    res.z=powf((float)a.z, (float)b);
    fesetround(FE_UPWARD);

    return res;
  }
float_st powf(const float_st& a, const int & b)
  {
    float_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    fesetround(FE_TONEAREST);
    res.accuracy=DIGIT_NOT_COMPUTED;
    res.x=powf((float)a.x, (float)b);
    res.y=powf((float)a.y, (float)b);
    res.z=powf((float)a.z, (float)b);
    fesetround(FE_UPWARD);

    return res;
  }
float_st powf(const float_st& a, const unsigned short& b)
  {
    float_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    fesetround(FE_TONEAREST);
    res.accuracy=DIGIT_NOT_COMPUTED;
    res.x=powf((float)a.x, (float)b);
    res.y=powf((float)a.y, (float)b);
    res.z=powf((float)a.z, (float)b);
    fesetround(FE_UPWARD);

    return res;
  }
float_st powf(const float_st& a, const short& b)
  {
    float_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    fesetround(FE_TONEAREST);
    res.accuracy=DIGIT_NOT_COMPUTED;
    res.x=powf((float)a.x, (float)b);
    res.y=powf((float)a.y, (float)b);
    res.z=powf((float)a.z, (float)b);
    fesetround(FE_UPWARD);

    return res;
  }
float_st powf(const float_st& a, const unsigned char& b)
  {
    float_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    fesetround(FE_TONEAREST);
    res.accuracy=DIGIT_NOT_COMPUTED;
    res.x=powf((float)a.x, (float)b);
    res.y=powf((float)a.y, (float)b);
    res.z=powf((float)a.z, (float)b);
    fesetround(FE_UPWARD);

    return res;
  }
float_st powf(const float_st& a, const char& b)
  {
    float_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    fesetround(FE_TONEAREST);
    res.accuracy=DIGIT_NOT_COMPUTED;
    res.x=powf((float)a.x, (float)b);
    res.y=powf((float)a.y, (float)b);
    res.z=powf((float)a.z, (float)b);
    fesetround(FE_UPWARD);

    return res;
  }

float_st pow(const float_st& a, const double& b)
  {
    float_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    fesetround(FE_TONEAREST);
    res.accuracy=DIGIT_NOT_COMPUTED;
    res.x=pow((double)a.x, (double)b);
    res.y=pow((double)a.y, (double)b);
    res.z=pow((double)a.z, (double)b);
    fesetround(FE_UPWARD);

    return res;
  }
float_st pow(const float_st& a, const float& b)
  {
    float_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    fesetround(FE_TONEAREST);
    res.accuracy=DIGIT_NOT_COMPUTED;
    res.x=pow((double)a.x, (double)b);
    res.y=pow((double)a.y, (double)b);
    res.z=pow((double)a.z, (double)b);
    fesetround(FE_UPWARD);

    return res;
  }
float_st pow(const float_st& a, const unsigned long long& b)
  {
    float_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    fesetround(FE_TONEAREST);
    res.accuracy=DIGIT_NOT_COMPUTED;
    res.x=pow((double)a.x, (double)b);
    res.y=pow((double)a.y, (double)b);
    res.z=pow((double)a.z, (double)b);
    fesetround(FE_UPWARD);

    return res;
  }
float_st pow(const float_st& a, const long long& b)
  {
    float_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    fesetround(FE_TONEAREST);
    res.accuracy=DIGIT_NOT_COMPUTED;
    res.x=pow((double)a.x, (double)b);
    res.y=pow((double)a.y, (double)b);
    res.z=pow((double)a.z, (double)b);
    fesetround(FE_UPWARD);

    return res;
  }
float_st pow(const float_st& a, const unsigned long& b)
  {
    float_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    fesetround(FE_TONEAREST);
    res.accuracy=DIGIT_NOT_COMPUTED;
    res.x=pow((double)a.x, (double)b);
    res.y=pow((double)a.y, (double)b);
    res.z=pow((double)a.z, (double)b);
    fesetround(FE_UPWARD);

    return res;
  }
float_st pow(const float_st& a, const long& b)
  {
    float_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    fesetround(FE_TONEAREST);
    res.accuracy=DIGIT_NOT_COMPUTED;
    res.x=pow((double)a.x, (double)b);
    res.y=pow((double)a.y, (double)b);
    res.z=pow((double)a.z, (double)b);
    fesetround(FE_UPWARD);

    return res;
  }
float_st pow(const float_st& a, const unsigned int & b)
  {
    float_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    fesetround(FE_TONEAREST);
    res.accuracy=DIGIT_NOT_COMPUTED;
    res.x=pow((double)a.x, (double)b);
    res.y=pow((double)a.y, (double)b);
    res.z=pow((double)a.z, (double)b);
    fesetround(FE_UPWARD);

    return res;
  }
float_st pow(const float_st& a, const int & b)
  {
    float_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    fesetround(FE_TONEAREST);
    res.accuracy=DIGIT_NOT_COMPUTED;
    res.x=pow((double)a.x, (double)b);
    res.y=pow((double)a.y, (double)b);
    res.z=pow((double)a.z, (double)b);
    fesetround(FE_UPWARD);

    return res;
  }
float_st pow(const float_st& a, const unsigned short& b)
  {
    float_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    fesetround(FE_TONEAREST);
    res.accuracy=DIGIT_NOT_COMPUTED;
    res.x=pow((double)a.x, (double)b);
    res.y=pow((double)a.y, (double)b);
    res.z=pow((double)a.z, (double)b);
    fesetround(FE_UPWARD);

    return res;
  }
float_st pow(const float_st& a, const short& b)
  {
    float_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    fesetround(FE_TONEAREST);
    res.accuracy=DIGIT_NOT_COMPUTED;
    res.x=pow((double)a.x, (double)b);
    res.y=pow((double)a.y, (double)b);
    res.z=pow((double)a.z, (double)b);
    fesetround(FE_UPWARD);

    return res;
  }
float_st pow(const float_st& a, const unsigned char& b)
  {
    float_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    fesetround(FE_TONEAREST);
    res.accuracy=DIGIT_NOT_COMPUTED;
    res.x=pow((double)a.x, (double)b);
    res.y=pow((double)a.y, (double)b);
    res.z=pow((double)a.z, (double)b);
    fesetround(FE_UPWARD);

    return res;
  }
float_st pow(const float_st& a, const char& b)
  {
    float_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    fesetround(FE_TONEAREST);
    res.accuracy=DIGIT_NOT_COMPUTED;
    res.x=pow((double)a.x, (double)b);
    res.y=pow((double)a.y, (double)b);
    res.z=pow((double)a.z, (double)b);
    fesetround(FE_UPWARD);

    return res;
  }


/////////////////////////////////////////////////////////////////////////





double_st pow(const double_st& a, const double_st& b)
  {
    double_st res;
    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (b.accuracy==DIGIT_NOT_COMPUTED) b.approx_digit();
      if (a.accuracy==0 || b.accuracy==0) instability(&_cadna_power_count);
    }
    fesetround(FE_TONEAREST);
    res.accuracy=DIGIT_NOT_COMPUTED;
    res.x=pow((double)a.x, (double)b.x);
    res.y=pow((double)a.y, (double)b.y);
    res.z=pow((double)a.z, (double)b.z);
    fesetround(FE_UPWARD);

    return res;
  }
double_st pow(const double_st& a, const float_st& b)
  {
    double_st res;
    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (b.accuracy==DIGIT_NOT_COMPUTED) b.approx_digit();
      if (a.accuracy==0 || b.accuracy==0) instability(&_cadna_power_count);
    }
    fesetround(FE_TONEAREST);
    res.accuracy=DIGIT_NOT_COMPUTED;
    res.x=pow((double)a.x, (double)b.x);
    res.y=pow((double)a.y, (double)b.y);
    res.z=pow((double)a.z, (double)b.z);
    fesetround(FE_UPWARD);

    return res;
  }
double_st pow(const float_st& a, const double_st& b)
  {
    double_st res;
    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (b.accuracy==DIGIT_NOT_COMPUTED) b.approx_digit();
      if (a.accuracy==0 || b.accuracy==0) instability(&_cadna_power_count);
    }
    fesetround(FE_TONEAREST);
    res.accuracy=DIGIT_NOT_COMPUTED;
    res.x=pow((double)a.x, (double)b.x);
    res.y=pow((double)a.y, (double)b.y);
    res.z=pow((double)a.z, (double)b.z);
    fesetround(FE_UPWARD);

    return res;
  }
float_st powf(const float_st& a, const float_st& b)
  {
    float_st res;
    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (b.accuracy==DIGIT_NOT_COMPUTED) b.approx_digit();
      if (a.accuracy==0 || b.accuracy==0) instability(&_cadna_power_count);
    }
    fesetround(FE_TONEAREST);
    res.accuracy=DIGIT_NOT_COMPUTED;
    res.x=powf((float)a.x, (float)b.x);
    res.y=powf((float)a.y, (float)b.y);
    res.z=powf((float)a.z, (float)b.z);
    fesetround(FE_UPWARD);

    return res;
  }
float_st pow(const float_st& a, const float_st& b)
  {
    float_st res;
    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (b.accuracy==DIGIT_NOT_COMPUTED) b.approx_digit();
      if (a.accuracy==0 || b.accuracy==0) instability(&_cadna_power_count);
    }
    fesetround(FE_TONEAREST);
    res.accuracy=DIGIT_NOT_COMPUTED;
    res.x=pow((double)a.x, (double)b.x);
    res.y=pow((double)a.y, (double)b.y);
    res.z=pow((double)a.z, (double)b.z);
    fesetround(FE_UPWARD);

    return res;
  }
//****f* cadna_math/log
//    NAME
//      log
//
//    SYNOPSIS
//      res = log(x)
//
//    FUNCTION
//       The log() function computes the value of the natural
//       logarithm of argument x.
//
//    INPUTS
//      x           - double_st
//    RESULT
//      res         - double_st
//    SEE ALSO
//      log2() , log10() , log1p(), exp(3), exp2(3), expm1(3), pow(3)
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

//****f* cadna_math/log
//    NAME
//      log
//
//    SYNOPSIS
//      res = log(x)
//
//    FUNCTION
//       The log() function computes the value of the natural
//       logarithm of argument x.
//
//    INPUTS
//      x           - float_st
//    RESULT
//      res         - float_st
//    SEE ALSO
//      log2() , log10() , log1p(), exp(3), exp2(3), expm1(3), pow(3)
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


//****f* cadna_math/log
//    NAME
//      log
//
//    SYNOPSIS
//      res = log(x)
//
//    FUNCTION
//       The log() function computes the value of the natural
//       logarithm of argument x.
//
//    INPUTS
//      x           - float_st
//    RESULT
//      res         - float_st
//    SEE ALSO
//      log2() , log10() , log1p(), exp(3), exp2(3), expm1(3), pow(3)
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






double_st log(const double_st& a)
  {
    double_st res;

    if(_cadna_math_tag!=0 ){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=log((double)a.x);
    res.y=log((double)a.y);
    res.z=log((double)a.z);
    fesetround(FE_UPWARD);

    return res;
  };
float_st log(const float_st& a)
  {
    float_st res;

    if(_cadna_math_tag!=0 ){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=log((float)a.x);
    res.y=log((float)a.y);
    res.z=log((float)a.z);
    fesetround(FE_UPWARD);

    return res;
  };
float_st logf(const float_st& a)
  {
    float_st res;

    if(_cadna_math_tag!=0 ){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=logf((float)a.x);
    res.y=logf((float)a.y);
    res.z=logf((float)a.z);
    fesetround(FE_UPWARD);

    return res;
  };



//****f* cadna_math/log2
//    NAME
//      log2
//
//    SYNOPSIS
//      res = log2(x)
//
//    FUNCTION
//       The log() function computes the value of argument x to base 2.
//
//    INPUTS
//      x           - double_st
//    RESULT
//      res         - double_st
//    SEE ALSO
//      log2() , log10() , log1p(), exp(3), exp2(3), expm1(3), pow(3)
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

//****f* cadna_math/log2
//    NAME
//      log2
//
//    SYNOPSIS
//      res = log2(x)
//
//    FUNCTION
//       The log() function computes the value of argument x to base 2.
//
//    INPUTS
//      x           - float_st
//    RESULT
//      res         - float_st
//    SEE ALSO
//      log2() , log10() , log1p(), exp(3), exp2(3), expm1(3), pow(3)
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


//****f* cadna_math/log2
//    NAME
//      log2
//
//    SYNOPSIS
//      res = log2(x)
//
//    FUNCTION
//       The log() function computes the value of argument x to base 2.
//
//    INPUTS
//      x           - float_st
//    RESULT
//      res         - float_st
//    SEE ALSO
//      log2() , log10() , log1p(), exp(3), exp2(3), expm1(3), pow(3)
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






double_st log2(const double_st& a)
  {
    double_st res;

    if(_cadna_math_tag!=0 ){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=log2((double)a.x);
    res.y=log2((double)a.y);
    res.z=log2((double)a.z);
    fesetround(FE_UPWARD);

    return res;
  };
float_st log2(const float_st& a)
  {
    float_st res;

    if(_cadna_math_tag!=0 ){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=log2((float)a.x);
    res.y=log2((float)a.y);
    res.z=log2((float)a.z);
    fesetround(FE_UPWARD);

    return res;
  };
float_st log2f(const float_st& a)
  {
    float_st res;

    if(_cadna_math_tag!=0 ){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=log2f((float)a.x);
    res.y=log2f((float)a.y);
    res.z=log2f((float)a.z);
    fesetround(FE_UPWARD);

    return res;
  };



//****f* cadna_math/log10
//    NAME
//      log10
//
//    SYNOPSIS
//      res = log10(x)
//
//    FUNCTION
//       The log10() function computes the value of argument x to base 10.
//
//    INPUTS
//      x           - double_st
//    RESULT
//      res         - double_st
//    SEE ALSO
//      log2() , log10() , log1p(), exp(3), exp2(3), expm1(3), pow(3)
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

//****f* cadna_math/log10
//    NAME
//      log10
//
//    SYNOPSIS
//      res = log10(x)
//
//    FUNCTION
//       The log10() function computes the value of argument x to base 10.
//
//    INPUTS
//      x           - float_st
//    RESULT
//      res         - float_st
//    SEE ALSO
//      log2() , log10() , log1p(), exp(3), exp2(3), expm1(3), pow(3)
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


//****f* cadna_math/log10f
//    NAME
//      log10f
//
//    SYNOPSIS
//      res = log10f(x)
//
//    FUNCTION
//       The log10f() function computes the value of argument x to base 10.
//
//    INPUTS
//      x           - float_st
//    RESULT
//      res         - float_st
//    SEE ALSO
//      log2() , log10() , log1p(), exp(3), exp2(3), expm1(3), pow(3)
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






double_st log10(const double_st& a)
  {
    double_st res;

    if(_cadna_math_tag!=0 ){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=log10((double)a.x);
    res.y=log10((double)a.y);
    res.z=log10((double)a.z);
    fesetround(FE_UPWARD);

    return res;
  };
float_st log10(const float_st& a)
  {
    float_st res;

    if(_cadna_math_tag!=0 ){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=log10((float)a.x);
    res.y=log10((float)a.y);
    res.z=log10((float)a.z);
    fesetround(FE_UPWARD);

    return res;
  };
float_st log10f(const float_st& a)
  {
    float_st res;

    if(_cadna_math_tag!=0 ){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=log10f((float)a.x);
    res.y=log10f((float)a.y);
    res.z=log10f((float)a.z);
    fesetround(FE_UPWARD);

    return res;
  };





//****f* cadna_math/log1p
//    NAME
//      log1p
//
//    SYNOPSIS
//      res = log1p(x)
//
//    FUNCTION
//      The log1p() function computes the value of log(1+x) accurately
//      even for very small values of x.
//
//    INPUTS
//      x           - double_st
//    RESULT
//      res         - double_st
//    SEE ALSO
//      log2() , log10() , log1p(), exp(3), exp2(3), expm1(3), pow(3)
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

//****f* cadna_math/log1p
//    NAME
//      log1p
//
//    SYNOPSIS
//      res = log1p(x)
//
//    FUNCTION
//      The log1p() function computes the value of log(1+x) accurately
//      even for very small values of x.
//
//    INPUTS
//      x           - float_st
//    RESULT
//      res         - float_st
//    SEE ALSO
//      log2() , log10() , log1p(), exp(3), exp2(3), expm1(3), pow(3)
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


//****f* cadna_math/log1pf
//    NAME
//      log1pf
//
//    SYNOPSIS
//      res = log1pf(x)
//
//    FUNCTION
//      The log1pf() function computes the value of log(1+x) accurately
//      even for very small values of x.
//
//    INPUTS
//      x           - float_st
//    RESULT
//      res         - float_st
//    SEE ALSO
//      log2() , log10() , log1p(), exp(3), exp2(3), expm1(3), pow(3)
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






double_st log1p(const double_st& a)
  {
    double_st res;

    if(_cadna_math_tag!=0 ){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=log1p((double)a.x);
    res.y=log1p((double)a.y);
    res.z=log1p((double)a.z);
    fesetround(FE_UPWARD);

    return res;
  };
float_st log1p(const float_st& a)
  {
    float_st res;

    if(_cadna_math_tag!=0 ){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=log1p((float)a.x);
    res.y=log1p((float)a.y);
    res.z=log1p((float)a.z);
    fesetround(FE_UPWARD);

    return res;
  };
float_st log1pf(const float_st& a)
  {
    float_st res;

    if(_cadna_math_tag!=0 ){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=log1pf((float)a.x);
    res.y=log1pf((float)a.y);
    res.z=log1pf((float)a.z);
    fesetround(FE_UPWARD);

    return res;
  };



//****f* cadna_math/logb
//    NAME
//      logb
//
//    SYNOPSIS
//      res = logb(x)
//
//    FUNCTION
//      The logb() functions return the exponent of x, represented as
//      a floating-point number.
//
//    INPUTS
//      x           - double_st
//    RESULT
//      res         - double_st
//    SEE ALSO
//      log2() , log10() , log1p(), exp(3), exp2(3), expm1(3), pow(3)
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

//****f* cadna_math/logb
//    NAME
//      logb
//
//    SYNOPSIS
//      res = logb(x)
//
//    FUNCTION
//      The logb() functions return the exponent of x, represented as
//      a floating-point number.
//
//    INPUTS
//      x           - float_st
//    RESULT
//      res         - float_st
//    SEE ALSO
//      log2() , log10() , log1p(), exp(3), exp2(3), expm1(3), pow(3)
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


//****f* cadna_math/logbf
//    NAME
//      logbf
//
//    SYNOPSIS
//      res = logbf(x)
//
//    FUNCTION
//      The logbf() functions return the exponent of x, represented as
//      a floating-point number.
//
//    INPUTS
//      x           - float_st
//    RESULT
//      res         - float_st
//    SEE ALSO
//      log2() , log10() , log1p(), exp(3), exp2(3), expm1(3), pow(3)
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






double_st logb(const double_st& a){
    double_st res;

    if(_cadna_math_tag!=0 ){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=logb((double)a.x);
    res.y=logb((double)a.y);
    res.z=logb((double)a.z);
    fesetround(FE_UPWARD);

    return res;
  };
float_st logb(const float_st& a){
    float_st res;

    if(_cadna_math_tag!=0 ){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=logb((float)a.x);
    res.y=logb((float)a.y);
    res.z=logb((float)a.z);
    fesetround(FE_UPWARD);

    return res;
  };
float_st logbf(const float_st& a){
    float_st res;

    if(_cadna_math_tag!=0 ){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=logbf((float)a.x);
    res.y=logbf((float)a.y);
    res.z=logbf((float)a.z);
    fesetround(FE_UPWARD);

    return res;
  };



//****f* cadna_math/exp
//    NAME
//      exp
//
//    SYNOPSIS
//      res = exp(x)
//
//    FUNCTION
//      The exp() function computes e**x, the base-e exponential of x.
//
//    INPUTS
//      x           - double_st
//    RESULT
//      res         - double_st
//    SEE ALSO
//      log2() , log10() , log1p(), exp(3), exp2(3), expm1(3), pow(3)
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

//****f* cadna_math/exp
//    NAME
//      exp
//
//    SYNOPSIS
//      res = exp(x)
//
//    FUNCTION
//      The exp() function computes e**x, the base-e exponential of x.
//
//    INPUTS
//      x           - float_st
//    RESULT
//      res         - float_st
//    SEE ALSO
//      log2() , log10() , log1p(), exp(3), exp2(3), expm1(3), pow(3)
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


//****f* cadna_math/expf
//    NAME
//      expf
//
//    SYNOPSIS
//      res = expf(x)
//
//    FUNCTION
//      The expf() function computes e**x, the base-e exponential of x.
//
//    INPUTS
//      x           - float_st
//    RESULT
//      res         - float_st
//    SEE ALSO
//      log2() , log10() , log1p(), exp(3), exp2(3), expm1(3), pow(3)
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






double_st exp(const double_st& a){
    double_st res;

    if(_cadna_math_tag!=0 ){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=exp((double)a.x);
    res.y=exp((double)a.y);
    res.z=exp((double)a.z);
    fesetround(FE_UPWARD);

    return res;
  };
float_st exp(const float_st& a){
    float_st res;

    if(_cadna_math_tag!=0 ){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=exp((float)a.x);
    res.y=exp((float)a.y);
    res.z=exp((float)a.z);
    fesetround(FE_UPWARD);

    return res;
  };
float_st expf(const float_st& a){
    float_st res;

    if(_cadna_math_tag!=0 ){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=expf((float)a.x);
    res.y=expf((float)a.y);
    res.z=expf((float)a.z);
    fesetround(FE_UPWARD);

    return res;
  };



//****f* cadna_math/exp2
//    NAME
//      exp2
//
//    SYNOPSIS
//      res = exp2(x)
//
//    FUNCTION
//      The exp() function computes 2**x, the base-e exponential of x.
//
//    INPUTS
//      x           - double_st
//    RESULT
//      res         - double_st
//    SEE ALSO
//      log2() , log10() , log1p(), exp(3), exp2(3), expm1(3), pow(3)
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

//****f* cadna_math/exp2
//    NAME
//      exp2
//
//    SYNOPSIS
//      res = exp2(x)
//
//    FUNCTION
//      The exp() function computes 2**x, the base-e exponential of x.
//
//    INPUTS
//      x           - float_st
//    RESULT
//      res         - float_st
//    SEE ALSO
//      log2() , log10() , log1p(), exp(3), exp2(3), expm1(3), pow(3)
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


//****f* cadna_math/exp2f
//    NAME
//      exp2f
//
//    SYNOPSIS
//      res = exp2f(x)
//
//    FUNCTION
//      The expf() function computes 2**x, the base-e exponential of x.
//
//    INPUTS
//      x           - float_st
//    RESULT
//      res         - float_st
//    SEE ALSO
//      log2() , log10() , log1p(), exp(3), exp2(3), expm1(3), pow(3)
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






double_st exp2(const double_st& a){
    double_st res;

    if(_cadna_math_tag!=0 ){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=exp2((double)a.x);
    res.y=exp2((double)a.y);
    res.z=exp2((double)a.z);
    fesetround(FE_UPWARD);

    return res;
  };
float_st exp2(const float_st& a){
    float_st res;

    if(_cadna_math_tag!=0 ){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=exp2((float)a.x);
    res.y=exp2((float)a.y);
    res.z=exp2((float)a.z);
    fesetround(FE_UPWARD);

    return res;
  };
float_st exp2f(const float_st& a){
    float_st res;

    if(_cadna_math_tag!=0 ){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=exp2f((float)a.x);
    res.y=exp2f((float)a.y);
    res.z=exp2f((float)a.z);
    fesetround(FE_UPWARD);

    return res;
  };



//****f* cadna_math/expm1
//    NAME
//      expm1
//
//    SYNOPSIS
//      res = expm1(x)
//
//    FUNCTION
//      The expm1() function computes the base-e exponential of x ,
//      minus 1 accurately even for very small values of x.
//
//    INPUTS
//      x           - double_st
//    RESULT
//      res         - double_st
//    SEE ALSO
//      log2() , log10() , log1p(), exp(3), exp2(3), expm1(3), pow(3)
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

//****f* cadna_math/expm1
//    NAME
//      expm1
//
//    SYNOPSIS
//      res = expm1(x)
//
//    FUNCTION
//      The expm1() function computes the base-e exponential of x ,
//      minus 1 accurately even for very small values of x.
//
//    INPUTS
//      x           - float_st
//    RESULT
//      res         - float_st
//    SEE ALSO
//      log2() , log10() , log1p(), exp(3), exp2(3), expm1(3), pow(3)
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


//****f* cadna_math/expm1f
//    NAME
//      expm1f
//
//    SYNOPSIS
//      res = expm1f(x)
//
//    FUNCTION
//      The expm1() function computes the base-e exponential of x ,
//      minus 1 accurately even for very small values of x.
//
//    INPUTS
//      x           - float_st
//    RESULT
//      res         - float_st
//    SEE ALSO
//      log2() , log10() , log1p(), exp(3), exp2(3), expm1(3), pow(3)
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






double_st expm1(const double_st& a)
  {
    double_st res;

    if(_cadna_math_tag!=0 ){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=expm1((double)a.x);
    res.y=expm1((double)a.y);
    res.z=expm1((double)a.z);
    fesetround(FE_UPWARD);

    return res;
  };
float_st expm1(const float_st& a)
  {
    float_st res;

    if(_cadna_math_tag!=0 ){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=expm1((float)a.x);
    res.y=expm1((float)a.y);
    res.z=expm1((float)a.z);
    fesetround(FE_UPWARD);

    return res;
  };
float_st expm1f(const float_st& a)
  {
    float_st res;

    if(_cadna_math_tag!=0 ){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=expm1f((float)a.x);
    res.y=expm1f((float)a.y);
    res.z=expm1f((float)a.z);
    fesetround(FE_UPWARD);

    return res;
  };



//****f* cadna_math/sqrt
//    NAME
//      sqrt
//
//    SYNOPSIS
//      res = sqrt(x)
//
//    FUNCTION
//      The sqrt() function compute the non-negative square root of x.
//
//    INPUTS
//      x           - double_st
//    RESULT
//      res         - double_st
//    SEE ALSO
//      cbrt()
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

//****f* cadna_math/sqrt
//    NAME
//      sqrt
//
//    SYNOPSIS
//      res = sqrt(x)
//
//    FUNCTION
//      The sqrt() function compute the non-negative square root of x.
//
//    INPUTS
//      x           - float_st
//    RESULT
//      res         - float_st
//    SEE ALSO
//      cbrt()
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


//****f* cadna_math/sqrtf
//    NAME
//      sqrtf
//
//    SYNOPSIS
//      res = sqrtf(x)
//
//    FUNCTION
//      The sqrt() function compute the non-negative square root of x.
//
//    INPUTS
//      x           - float_st
//    RESULT
//      res         - float_st
//    SEE ALSO
//      cbrt()
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






double_st sqrt(const double_st& a){
    double_st res;

    if(_cadna_math_tag!=0 ){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=sqrt((double)a.x);
    res.y=sqrt((double)a.y);
    res.z=sqrt((double)a.z);
    fesetround(FE_UPWARD);

    return res;
  };
float_st sqrt(const float_st& a){
    float_st res;

    if(_cadna_math_tag!=0 ){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=sqrt((float)a.x);
    res.y=sqrt((float)a.y);
    res.z=sqrt((float)a.z);
    fesetround(FE_UPWARD);

    return res;
  };
float_st sqrtf(const float_st& a){
    float_st res;

    if(_cadna_math_tag!=0 ){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=sqrtf((float)a.x);
    res.y=sqrtf((float)a.y);
    res.z=sqrtf((float)a.z);
    fesetround(FE_UPWARD);

    return res;
  };




//****f* cadna_math/cbrt
//    NAME
//      cbrt
//
//    SYNOPSIS
//      res = cbrt(x)
//
//    FUNCTION
//      The cbrt() function computes the cube root of x.
//
//    INPUTS
//      x           - double_st
//    RESULT
//      res         - double_st
//    SEE ALSO
//      sqrt(3)
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

//****f* cadna_math/cbrt
//    NAME
//      cbrt
//
//    SYNOPSIS
//      res = cbrt(x)
//
//    FUNCTION
//      The cbrt() function computes the cube root of x.
//
//    INPUTS
//      x           - float_st
//    RESULT
//      res         - float_st
//    SEE ALSO
//      sqrt(3)
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


//****f* cadna_math/cbrtf
//    NAME
//      cbrtf
//
//    SYNOPSIS
//      res = cbrtf(x)
//
//    FUNCTION
//      The cbrt() function computes the cube root of x.
//
//    INPUTS
//      x           - float_st
//    RESULT
//      res         - float_st
//    SEE ALSO
//    	sqrt(3)
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






double_st cbrt(const double_st& a){
    double_st res;

    if(_cadna_math_tag!=0 ){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=cbrt((double)a.x);
    res.y=cbrt((double)a.y);
    res.z=cbrt((double)a.z);
    fesetround(FE_UPWARD);

    return res;
  };
float_st cbrt(const float_st& a){
    float_st res;

    if(_cadna_math_tag!=0 ){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=cbrt((float)a.x);
    res.y=cbrt((float)a.y);
    res.z=cbrt((float)a.z);
    fesetround(FE_UPWARD);

    return res;
  };
float_st cbrtf(const float_st& a){
    float_st res;

    if(_cadna_math_tag!=0 ){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=cbrtf((float)a.x);
    res.y=cbrtf((float)a.y);
    res.z=cbrtf((float)a.z);
    fesetround(FE_UPWARD);

    return res;
  };



//****f* cadna_math/sin
//    NAME
//      sin
//    SYNOPSIS
//      res = sin(x)
//    FUNCTION
//      The sin() function computes the sine of x (measured in radians).
//
//
//    INPUTS
//      x           - double_st
//    RESULT
//      res         - double_st
//    SEE ALSO
//      asin(3), asin(3), atan(3), atan2(3), sin(3), sinh(3), sinh(3),
//      tan(3), tanh(3)
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
//      asin(3), asin(3), atan(3), atan2(3), sin(3), sinh(3), sinh(3),
//      tan(3), tanh(3)
//
//  /



//****f* cadna_math/sinf
//    NAME
//      sin
//    SYNOPSIS
//      res = sin(x)
//    FUNCTION
//      The sin() function computes the sine of x (measured in radians).
//
//
//    INPUTS
//      x           - float_st
//    RESULT
//      res         - float_st
//    SEE ALSO
//      asinf(3), asinf(3), atanf(3), atan2f(3), sinf(3), sinhf(3),
//      sinhf(3), tanf(3), tanhf(3)
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



//****f* cadna_math/sinf
//    NAME
//      sinf
//    SYNOPSIS
//      res = sinf(x)
//    FUNCTION
//      The sin() function computes the sine of x (measured in radians).
//
//
//    INPUTS
//      x           - float_st
//    RESULT
//      res         - float_st
//    SEE ALSO
//      asinf(3), asinf(3), atanf(3), atan2f(3), sinf(3), sinhf(3),
//      sinhf(3), tanf(3), tanhf(3)
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




double_st sin(const double_st& a){
    double_st res;

    if(_cadna_math_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=sin((double)a.x);
    res.y=sin((double)a.y);
    res.z=sin((double)a.z);
    fesetround(FE_UPWARD);

    return res;
  };
float_st sin(const float_st& a){
    float_st res;

    if(_cadna_math_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=sin((float)a.x);
    res.y=sin((float)a.y);
    res.z=sin((float)a.z);
    fesetround(FE_UPWARD);

    return res;
  };
float_st sinf(const float_st& a){
    float_st res;

    if(_cadna_math_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=sinf((float)a.x);
    res.y=sinf((float)a.y);
    res.z=sinf((float)a.z);
    fesetround(FE_UPWARD);

    return res;
  };



//****f* cadna_math/cos
//    NAME
//      cos
//    SYNOPSIS
//      res = cos(x)
//    FUNCTION
//      The cos() function computes the cosine of x (measured in radians).
//
//
//    INPUTS
//      x           - double_st
//    RESULT
//      res         - double_st
//    SEE ALSO
//      acos(3), asin(3), atan(3), atan2(3), cos(3), cosh(3), sinh(3),
//      tan(3), tanh(3)
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
//      acos(3), asin(3), atan(3), atan2(3), cos(3), cosh(3), sinh(3),
//      tan(3), tanh(3)
//
//  /



//****f* cadna_math/cos
//    NAME
//      cos
//    SYNOPSIS
//      res = cos(x)
//    FUNCTION
//      The cosf() function computes the cosine of x (measured in radians).
//
//
//    INPUTS
//      x           - float_st
//    RESULT
//      res         - float_st
//    SEE ALSO
//      acosf(3), asinf(3), atanf(3), atan2f(3), cosf(3), coshf(3),
//      sinhf(3), tanf(3), tanhf(3)
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



//****f* cadna_math/cosf
//    NAME
//      cosf
//    SYNOPSIS
//      res = cosf(x)
//    FUNCTION
//      The cos() function computes the cosine of x (measured in radians).
//
//
//    INPUTS
//      x           - float_st
//    RESULT
//      res         - float_st
//    SEE ALSO
//      acosf(3), asinf(3), atanf(3), atan2f(3), cosf(3), coshf(3),
//      sinhf(3), tanf(3), tanhf(3)
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




double_st cos(const double_st& a)
  {
    double_st res;

    if(_cadna_math_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=cos((double)a.x);
    res.y=cos((double)a.y);
    res.z=cos((double)a.z);
    fesetround(FE_UPWARD);

    return res;
  };
float_st cos(const float_st& a)
  {
    float_st res;

    if(_cadna_math_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=cos((float)a.x);
    res.y=cos((float)a.y);
    res.z=cos((float)a.z);
    fesetround(FE_UPWARD);

    return res;
  };
float_st cosf(const float_st& a)
  {
    float_st res;

    if(_cadna_math_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=cosf((float)a.x);
    res.y=cosf((float)a.y);
    res.z=cosf((float)a.z);
    fesetround(FE_UPWARD);

    return res;
  };



//****f* cadna_math/tan
//    NAME
//      tan
//    SYNOPSIS
//      res = tan(x)
//    FUNCTION
//      The tan() function computes the tangent of x (measured in radians).
//
//
//    INPUTS
//      x           - double_st
//    RESULT
//      res         - double_st
//    SEE ALSO
//      atan(3), atan(3), atan(3), atan2(3), tan(3), tanh(3), tanh(3),
//      tan(3), tanh(3)
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
//      atan(3), atan(3), atan(3), atan2(3), tan(3), tanh(3), tanh(3),
//      tan(3), tanh(3)
//
//  /



//****f* cadna_math/tanf
//    NAME
//      tan
//    SYNOPSIS
//      res = tan(x)
//    FUNCTION
//      The tan() function computes the tangent of x (measured in radians).
//
//    INPUTS
//      x           - float_st
//    RESULT
//      res         - float_st
//    SEE ALSO
//      atanf(3), atanf(3), atanf(3), atan2f(3), tanf(3), tanhf(3),
//      tanhf(3), tanf(3), tanhf(3)
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



//****f* cadna_math/tanf
//    NAME
//      tanf
//    SYNOPSIS
//      res = tanf(x)
//    FUNCTION
//      The tan() function computes the tangent of x (measured in radians).
//
//
//    INPUTS
//      x           - float_st
//    RESULT
//      res         - float_st
//    SEE ALSO
//      atanf(3), atanf(3), atanf(3), atan2f(3), tanf(3), tanhf(3),
//      tanhf(3), tanf(3), tanhf(3)
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




double_st tan(const double_st& a)
  {
    double_st res;

    if(_cadna_math_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=tan((double)a.x);
    res.y=tan((double)a.y);
    res.z=tan((double)a.z);
    fesetround(FE_UPWARD);

    return res;
  };
float_st tan(const float_st& a)
  {
    float_st res;

    if(_cadna_math_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=tan((float)a.x);
    res.y=tan((float)a.y);
    res.z=tan((float)a.z);
    fesetround(FE_UPWARD);

    return res;
  };
float_st tanf(const float_st& a)
  {
    float_st res;

    if(_cadna_math_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=tanf((float)a.x);
    res.y=tanf((float)a.y);
    res.z=tanf((float)a.z);
    fesetround(FE_UPWARD);

    return res;
  };



//****f* cadna_math/asin
//    NAME
//      asin
//    SYNOPSIS
//      res = asin(x)
//    FUNCTION
//      The asin() function computes the principal value of the arc
//      sine of x.  The result is in the range [-pi/2, +pi/2].
//

//
//    INPUTS
//      x           - double_st
//    RESULT
//      res         - double_st
//    SEE ALSO
//      acos(3), asin(3), atan(3), atan2(3), cos(3), cosh(3), sinh(3),
//      tan(3), tanh(3)
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
//      acos(3), asin(3), atan(3), atan2(3), cos(3), cosh(3), sinh(3),
//      tan(3), tanh(3)
//
//  /



//****f* cadna_math/asinf
//    NAME
//      asin
//    SYNOPSIS
//      res = asin(x)
//    FUNCTION
//      The asin() function computes the principal value of the arc
//      sine of x.  The result is in the range [-pi/2, +pi/2].
//
//
//
//    INPUTS
//      x           - float_st
//    RESULT
//      res         - float_st
//    SEE ALSO
//      acosf(3), asinf(3), atanf(3), atan2f(3), cosf(3), coshf(3),
//      sinhf(3), tanf(3), tanhf(3)
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



//****f* cadna_math/asinf
//    NAME
//      asinf
//    SYNOPSIS
//      res = asinf(x)
//    FUNCTION
//      The asin() function computes the principal value of the arc
//      sine of x.  The result is in the range [-pi/2, +pi/2].
//
//
//    INPUTS
//      x           - float_st
//    RESULT
//      res         - float_st
//    SEE ALSO
//      acosf(3), asinf(3), atanf(3), atan2f(3), cosf(3), coshf(3),
//      sinhf(3), tanf(3), tanhf(3)
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




double_st asin(const double_st& a){
    double_st res;

    if(_cadna_math_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=asin((double)a.x);
    res.y=asin((double)a.y);
    res.z=asin((double)a.z);
    fesetround(FE_UPWARD);

    return res;
  };
float_st asin(const float_st& a){
    float_st res;

    if(_cadna_math_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=asin((float)a.x);
    res.y=asin((float)a.y);
    res.z=asin((float)a.z);
    fesetround(FE_UPWARD);

    return res;
  };
float_st asinf(const float_st& a){
    float_st res;

    if(_cadna_math_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=asinf((float)a.x);
    res.y=asinf((float)a.y);
    res.z=asinf((float)a.z);
    fesetround(FE_UPWARD);

    return res;
  };



//****f* cadna_math/acos
//    NAME
//      acos
//    SYNOPSIS
//      res = acos(x)
//    FUNCTION
//      The acos() function computes the principal value of the arc
//      cosine of x.  The result is in the range [-pi/2, +pi/2].
//

//
//    INPUTS
//      x           - double_st
//    RESULT
//      res         - double_st
//    SEE ALSO
//      acos(3), asin(3), atan(3), atan2(3), cos(3), cosh(3), sinh(3),
//      tan(3), tanh(3)
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
//      acos(3), acos(3), atan(3), atan2(3), cos(3), cosh(3), sinh(3),
//      tan(3), tanh(3)
//
//  /



//****f* cadna_math/acosf
//    NAME
//      acos
//    SYNOPSIS
//      res = acos(x)
//    FUNCTION
//      The acos() function computes the principal value of the arc
//      cosine of x.  The result is in the range [-pi/2, +pi/2].
//
//
//
//    INPUTS
//      x           - float_st
//    RESULT
//      res         - float_st
//    SEE ALSO
//      acosf(3), asinf(3), atanf(3), atan2f(3), cosf(3), coshf(3),
//      sinhf(3), tanf(3), tanhf(3)
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



//****f* cadna_math/acosf
//    NAME
//      acosf
//    SYNOPSIS
//      res = acosf(x)
//    FUNCTION
//      The acos() function computes the principal value of the arc
//      cosine of x.  The result is in the range [-pi/2, +pi/2].
//
//
//    INPUTS
//      x           - float_st
//    RESULT
//      res         - float_st
//    SEE ALSO
//      acosf(3), asinf(3), atanf(3), atan2f(3), cosf(3), coshf(3),
//      sinhf(3), tanf(3), tanhf(3)
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




double_st acos(const double_st& a){
    double_st res;

    if(_cadna_math_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=acos((double)a.x);
    res.y=acos((double)a.y);
    res.z=acos((double)a.z);
    fesetround(FE_UPWARD);

    return res;
  };
float_st acos(const float_st& a){
    float_st res;

    if(_cadna_math_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=acos((float)a.x);
    res.y=acos((float)a.y);
    res.z=acos((float)a.z);
    fesetround(FE_UPWARD);

    return res;
  };
float_st acosf(const float_st& a){
    float_st res;

    if(_cadna_math_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=acosf((float)a.x);
    res.y=acosf((float)a.y);
    res.z=acosf((float)a.z);
    fesetround(FE_UPWARD);

    return res;
  };



//****f* cadna_math/atan
//    NAME
//      atan
//    SYNOPSIS
//      res = atan(x)
//    FUNCTION
//      The atan() function computes the principal value of the arc
//      tangent of x.  The result is in the range [-pi/2, +pi/2].
//

//
//    INPUTS
//      x           - double_st
//    RESULT
//      res         - double_st
//    SEE ALSO
//      acos(3), asin(3), atan(3), atan2(3), cos(3), cosh(3), sinh(3),
//      tan(3), tanh(3)
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
//      acos(3), atan(3), atan(3), atan2(3), cos(3), cosh(3), sinh(3),
//      tan(3), tanh(3)
//
//  /



//****f* cadna_math/atanf
//    NAME
//      atan
//    SYNOPSIS
//      res = atan(x)
//    FUNCTION
//      The atan() function computes the principal value of the arc
//      sine of x.  The result is in the range [-pi/2, +pi/2].
//
//
//
//    INPUTS
//      x           - float_st
//    RESULT
//      res         - float_st
//    SEE ALSO
//      acosf(3), asinf(3), atanf(3), atan2f(3), cosf(3), coshf(3),
//      sinhf(3), tanf(3), tanhf(3)
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



//****f* cadna_math/atanf
//    NAME
//      atanf
//    SYNOPSIS
//      res = atanf(x)
//    FUNCTION
//      The atan() function computes the principal value of the arc
//      sine of x.  The result is in the range [-pi/2, +pi/2].
//
//
//    INPUTS
//      x           - float_st
//    RESULT
//      res         - float_st
//    SEE ALSO
//      acosf(3), asinf(3), atanf(3), atan2f(3), cosf(3), coshf(3),
//      sinhf(3), tanf(3), tanhf(3)
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




double_st atan(const double_st& a){
    double_st res;

    if(_cadna_math_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=atan((double)a.x);
    res.y=atan((double)a.y);
    res.z=atan((double)a.z);
    fesetround(FE_UPWARD);

    return res;
  };
float_st atan(const float_st& a){
    float_st res;

    if(_cadna_math_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=atan((float)a.x);
    res.y=atan((float)a.y);
    res.z=atan((float)a.z);
    fesetround(FE_UPWARD);

    return res;
  };
float_st atanf(const float_st& a){
    float_st res;

    if(_cadna_math_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=atanf((float)a.x);
    res.y=atanf((float)a.y);
    res.z=atanf((float)a.z);
    fesetround(FE_UPWARD);

    return res;
  };



//****f* cadna_math/atan2
//    NAME
//      atan2
//    SYNOPSIS
//      res = atan2(x,y)
//    FUNCTION
//      The atan2() function computes the principal value of the arc
//      tangent of y/x, using the signs of both arguments to determine
//      the quadrant of the return value.
//
//
//    INPUTS
//      x           - double_st
//      y           - double_st
//    RESULT
//      res         - double_st
//    SEE ALSO
//      xcos(3), asin(3), atan(3), atan2(3), cos(3), cosh(3), sinh(3),
//      tan(3), tanh(3)
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
//  / ****f* cadna_math/atan2f
//      NAME
//        atan2f
//      SYNOPSIS
//        res = atan2f(x,y)
//      FUNCTION The atan2() function computes the principal value of
//      the arc tangent of y/x, using the signs of both arguments to
//      determine the quadrant of the return value.
//
//    INPUTS
//      x           - float_st
//      b           - float_st
//    RESULT
//      res         - float_st
//    SEE ALSO
//      acosf(3), asinf(3), atanf(3), atan2f(3), cosf(3), coshf(3),
//      sinhf(3), tanf(3), tanhf(3)
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




double_st atan2(const double_st& a, const double_st& b){
    double_st res;
    fesetround(FE_TONEAREST);
    res.accuracy=DIGIT_NOT_COMPUTED;
    res.x=atan2((double)a.x,(double)b.x);
    res.y=atan2((double)a.y,(double)b.y);
    res.z=atan2((double)a.z,(double)b.z);
    fesetround(FE_UPWARD);

    return res;
  }
double_st atan2(const double_st& a, const float_st& b){
    double_st res;
    fesetround(FE_TONEAREST);
    res.accuracy=DIGIT_NOT_COMPUTED;
    res.x=atan2((double)a.x,(double)b.x);
    res.y=atan2((double)a.y,(double)b.y);
    res.z=atan2((double)a.z,(double)b.z);
    fesetround(FE_UPWARD);

    return res;
  }
double_st atan2(const float_st& a, const double_st& b){
    double_st res;
    fesetround(FE_TONEAREST);
    res.accuracy=DIGIT_NOT_COMPUTED;
    res.x=atan2((double)a.x,(double)b.x);
    res.y=atan2((double)a.y,(double)b.y);
    res.z=atan2((double)a.z,(double)b.z);
    fesetround(FE_UPWARD);

    return res;
  }
float_st atan2f(const float_st& a, const float_st& b){
    float_st res;
    fesetround(FE_TONEAREST);
    res.accuracy=DIGIT_NOT_COMPUTED;
    res.x=atan2f((float)a.x,(float)b.x);
    res.y=atan2f((float)a.y,(float)b.y);
    res.z=atan2f((float)a.z,(float)b.z);
    fesetround(FE_UPWARD);

    return res;
  }
float_st atan2(const float_st& a, const float_st& b){
    float_st res;
    fesetround(FE_TONEAREST);
    res.accuracy=DIGIT_NOT_COMPUTED;
    res.x=atan2((float)a.x,(float)b.x);
    res.y=atan2((float)a.y,(float)b.y);
    res.z=atan2((float)a.z,(float)b.z);
    fesetround(FE_UPWARD);

    return res;
  }
//****f* cadna_math/sinh
//    NAME
//      sinh
//    SYNOPSIS
//      res = sinh(x)
//    FUNCTION
//      The sinh() function computes the hyperbolic sine of x.
//
//
//    INPUTS
//      x           - double_st
//    RESULT
//      res         - double_st
//    SEE ALSO
//      acos(3), asin(3), atan(3), atan2(3), cos(3), cosh(3), sinh(3),
//      tan(3), tanh(3)
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
//      acos(3), sinh(3), atan(3), atan2(3), cos(3), cosh(3), sinh(3),
//      tan(3), tanh(3)
//
//  /



//****f* cadna_math/sinhf
//    NAME
//      sinh
//    SYNOPSIS
//      res = sinh(x)
//    FUNCTION
//      The sinh() function computes the hyperbolic sine of x.
//
//
//
//    INPUTS
//      x           - float_st
//    RESULT
//      res         - float_st
//    SEE ALSO
//      acosf(3), asinf(3), atanf(3), atan2f(3), cosf(3), coshf(3),
//      sinhf(3), tanf(3), tanhf(3)
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



//****f* cadna_math/sinhf
//    NAME
//      sinhf
//    SYNOPSIS
//      res = sinhf(x)
//    FUNCTION
//      The sinhf() function computes the hyperbolic sine of x.
//
//
//    INPUTS
//      x           - float_st
//    RESULT
//      res         - float_st
//    SEE ALSO
//      acosf(3), asinf(3), atanf(3), atan2f(3), cosf(3), coshf(3),
//      sinhf(3), tanf(3), tanhf(3)
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




double_st sinh(const double_st& a){
    double_st res;

    if(_cadna_math_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=sinh((double)a.x);
    res.y=sinh((double)a.y);
    res.z=sinh((double)a.z);
    fesetround(FE_UPWARD);

    return res;
  };
float_st sinh(const float_st& a){
    float_st res;

    if(_cadna_math_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=sinh((float)a.x);
    res.y=sinh((float)a.y);
    res.z=sinh((float)a.z);
    fesetround(FE_UPWARD);

    return res;
  };
float_st sinhf(const float_st& a){
    float_st res;

    if(_cadna_math_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=sinhf((float)a.x);
    res.y=sinhf((float)a.y);
    res.z=sinhf((float)a.z);
    fesetround(FE_UPWARD);

    return res;
  };



//****f* cadna_math/cosh
//    NAME
//      cosh
//    SYNOPSIS
//      res = cosh(x)
//    FUNCTION
//      The cosh() function computes the hyperbolic cosine of x.
//
//
//    INPUTS
//      x           - double_st
//    RESULT
//      res         - double_st
//    SEE ALSO
//      acos(3), asin(3), atan(3), atan2(3), cos(3), cosh(3), sinh(3),
//      tan(3), tanh(3)
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
//      acos(3), sinh(3), atan(3), atan2(3), cos(3), cosh(3), sinh(3),
//      tan(3), tanh(3)
//
//  /



//****f* cadna_math/coshf
//    NAME
//      cosh
//    SYNOPSIS
//      res = cosh(x)
//    FUNCTION
//      The cosh() function computes the hyperbolic cosine of x.
//
//
//
//    INPUTS
//      x           - float_st
//    RESULT
//      res         - float_st
//    SEE ALSO
//      acosf(3), asinf(3), atanf(3), atan2f(3), cosf(3), coshf(3),
//      sinhf(3), tanf(3), tanhf(3)
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



//****f* cadna_math/coshf
//    NAME
//      coshf
//    SYNOPSIS
//      res = coshf(x)
//    FUNCTION
//      The coshf() function computes the hyperbolic cosine of x.
//
//
//    INPUTS
//      x           - float_st
//    RESULT
//      res         - float_st
//    SEE ALSO
//      acosf(3), asinf(3), atanf(3), atan2f(3), cosf(3), coshf(3),
//      sinhf(3), tanf(3), tanhf(3)
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




double_st cosh(const double_st& a){
    double_st res;

    if(_cadna_math_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=cosh((double)a.x);
    res.y=cosh((double)a.y);
    res.z=cosh((double)a.z);
    fesetround(FE_UPWARD);

    return res;
  };
float_st cosh(const float_st& a){
    float_st res;

    if(_cadna_math_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=cosh((float)a.x);
    res.y=cosh((float)a.y);
    res.z=cosh((float)a.z);
    fesetround(FE_UPWARD);

    return res;
  };
float_st coshf(const float_st& a){
    float_st res;

    if(_cadna_math_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=coshf((float)a.x);
    res.y=coshf((float)a.y);
    res.z=coshf((float)a.z);
    fesetround(FE_UPWARD);

    return res;
  };



//****f* cadna_math/tanh
//    NAME
//      tanh
//    SYNOPSIS
//      res = tanh(x)
//    FUNCTION
//      The tanh() function computes the hyperbolic tangent of x.
//
//
//    INPUTS
//      x           - double_st
//    RESULT
//      res         - double_st
//    SEE ALSO
//      acos(3), asin(3), atan(3), atan2(3), cos(3), cosh(3), sinh(3),
//      tan(3), tanh(3)
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
//      acos(3), sinh(3), atan(3), atan2(3), cos(3), cosh(3), sinh(3),
//      tan(3), tanh(3)
//
//  /



//****f* cadna_math/tanhf
//    NAME
//      tanh
//    SYNOPSIS
//      res = tanh(x)
//    FUNCTION
//      The tanh() function computes the hyperbolic tangent of x.
//
//
//
//    INPUTS
//      x           - float_st
//    RESULT
//      res         - float_st
//    SEE ALSO
//      acosf(3), asinf(3), atanf(3), atan2f(3), cosf(3), coshf(3),
//      sinhf(3), tanf(3), tanhf(3)
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



//****f* cadna_math/tanhf
//    NAME
//      tanhf
//    SYNOPSIS
//      res = tanhf(x)
//    FUNCTION
//      The tanhf() function computes the hyperbolic tangent of x.
//
//
//    INPUTS
//      x           - float_st
//    RESULT
//      res         - float_st
//    SEE ALSO
//      acosf(3), asinf(3), atanf(3), atan2f(3), cosf(3), coshf(3),
//      sinhf(3), tanf(3), tanhf(3)
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




double_st tanh(const double_st& a){
    double_st res;

    if(_cadna_math_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=tanh((double)a.x);
    res.y=tanh((double)a.y);
    res.z=tanh((double)a.z);
    fesetround(FE_UPWARD);

    return res;
  };
float_st tanh(const float_st& a){
    float_st res;

    if(_cadna_math_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=tanh((float)a.x);
    res.y=tanh((float)a.y);
    res.z=tanh((float)a.z);
    fesetround(FE_UPWARD);

    return res;
  };
float_st tanhf(const float_st& a){
    float_st res;

    if(_cadna_math_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=tanhf((float)a.x);
    res.y=tanhf((float)a.y);
    res.z=tanhf((float)a.z);
    fesetround(FE_UPWARD);

    return res;
  };



//****f* cadna_math/asinh
//    NAME
//      asinh
//    SYNOPSIS
//      res = asinh(x)
//    FUNCTION
//      The asinh() function computes the inverse hyperbolic sine of
//      the double_st argument
//
//
//    INPUTS
//      x           - double_st
//    RESULT
//      res         - double_st
//    SEE ALSO
//      acos(3), asin(3), atan(3), atan2(3), cos(3), cosh(3), sinh(3),
//      tan(3), tanh(3)
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
//      acos(3), sinh(3), atan(3), atan2(3), cos(3), cosh(3), sinh(3),
//      tan(3), tanh(3)
//
//  /



//****f* cadna_math/asinhf
//    NAME
//      asinh
//    SYNOPSIS
//      res = asinh(x)
//    FUNCTION
//      The asinh() function computes the inverse hyperbolic sine of
//      the float_st argument
//
//    INPUTS
//      x           - float_st
//    RESULT
//      res         - float_st
//    SEE ALSO
//      acosf(3), asinf(3), atanf(3), atan2f(3), cosf(3), coshf(3),
//      sinhf(3), tanf(3), tanhf(3)
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



//****f* cadna_math/asinhf
//    NAME
//      asinhf
//    SYNOPSIS
//      res = asinhf(x)
//    FUNCTION
//      The asinhf() function computes the inverse hyperbolic sine of
//      the float_st argument
//
//    INPUTS
//      x           - float_st
//    RESULT
//      res         - float_st
//    SEE ALSO
//      acosf(3), asinf(3), atanf(3), atan2f(3), cosf(3), coshf(3),
//      sinhf(3), tanf(3), tanhf(3)
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




double_st asinh(const double_st& a){
    double_st res;

    if(_cadna_math_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=asinh((double)a.x);
    res.y=asinh((double)a.y);
    res.z=asinh((double)a.z);
    fesetround(FE_UPWARD);

    return res;
  };
float_st asinh(const float_st& a){
    float_st res;

    if(_cadna_math_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=asinh((float)a.x);
    res.y=asinh((float)a.y);
    res.z=asinh((float)a.z);
    fesetround(FE_UPWARD);

    return res;
  };
float_st asinhf(const float_st& a){
    float_st res;

    if(_cadna_math_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=asinhf((float)a.x);
    res.y=asinhf((float)a.y);
    res.z=asinhf((float)a.z);
    fesetround(FE_UPWARD);

    return res;
  };



//****f* cadna_math/acosh
//    NAME
//      acosh
//    SYNOPSIS
//      res = acosh(x)
//    FUNCTION
//      The acosh() function computes the inverse hyperbolic cosine of
//      the double_st argument
//
//
//    INPUTS
//      x           - double_st
//    RESULT
//      res         - double_st
//    SEE ALSO
//      acos(3), asin(3), atan(3), atan2(3), cos(3), cosh(3), sinh(3),
//      tan(3), tanh(3)
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
//      acos(3), sinh(3), atan(3), atan2(3), cos(3), cosh(3), sinh(3),
//      tan(3), tanh(3)
//
//  /



//****f* cadna_math/acoshf
//    NAME
//      acosh
//    SYNOPSIS
//      res = acosh(x)
//    FUNCTION
//      The acosh() function computes the inverse hyperbolic cose of
//      the float_st argument
//
//    INPUTS
//      x           - float_st
//    RESULT
//      res         - float_st
//    SEE ALSO
//      acosf(3), asinf(3), atanf(3), atan2f(3), cosf(3), coshf(3),
//      sinhf(3), tanf(3), tanhf(3)
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



//****f* cadna_math/acoshf
//    NAME
//      acoshf
//    SYNOPSIS
//      res = acoshf(x)
//    FUNCTION
//      The acoshf() function computes the inverse hyperbolic cose of
//      the float_st argument
//
//    INPUTS
//      x           - float_st
//    RESULT
//      res         - float_st
//    SEE ALSO
//      acosf(3), asinf(3), atanf(3), atan2f(3), cosf(3), coshf(3),
//      sinhf(3), tanf(3), tanhf(3)
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




double_st acosh(const double_st& a){
    double_st res;

    if(_cadna_math_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=acosh((double)a.x);
    res.y=acosh((double)a.y);
    res.z=acosh((double)a.z);
    fesetround(FE_UPWARD);

    return res;
  };
float_st acosh(const float_st& a){
    float_st res;

    if(_cadna_math_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=acosh((float)a.x);
    res.y=acosh((float)a.y);
    res.z=acosh((float)a.z);
    fesetround(FE_UPWARD);

    return res;
  };
float_st acoshf(const float_st& a){
    float_st res;

    if(_cadna_math_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=acoshf((float)a.x);
    res.y=acoshf((float)a.y);
    res.z=acoshf((float)a.z);
    fesetround(FE_UPWARD);

    return res;
  };



//****f* cadna_math/atanh
//    NAME
//      atanh
//    SYNOPSIS
//      res = atanh(x)
//    FUNCTION
//      The atanh() function computes the inverse hyperbolic tangent of
//      the double_st argument
//
//
//    INPUTS
//      x           - double_st
//    RESULT
//      res         - double_st
//    SEE ALSO
//      acos(3), asin(3), atan(3), atan2(3), cos(3), cosh(3), sinh(3),
//      tan(3), tanh(3)
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
//      acos(3), sinh(3), atan(3), atan2(3), cos(3), cosh(3), sinh(3),
//      tan(3), tanh(3)
//
//  /



//****f* cadna_math/atanhf
//    NAME
//      atanh
//    SYNOPSIS
//      res = atanh(x)
//    FUNCTION
//      The atanh() function computes the inverse hyperbolic tangent of
//      the float_st argument
//
//    INPUTS
//      x           - float_st
//    RESULT
//      res         - float_st
//    SEE ALSO
//      acosf(3), asinf(3), atanf(3), atan2f(3), cosf(3), coshf(3),
//      sinhf(3), tanf(3), tanhf(3)
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



//****f* cadna_math/atanhf
//    NAME
//      atanhf
//    SYNOPSIS
//      res = atanhf(x)
//    FUNCTION
//      The atanhf() function computes the inverse hyperbolic tangent of
//      the float_st argument
//
//    INPUTS
//      x           - float_st
//    RESULT
//      res         - float_st
//    SEE ALSO
//      acosf(3), asinf(3), atanf(3), atan2f(3), cosf(3), coshf(3),
//      sinhf(3), tanf(3), tanhf(3)
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




double_st atanh(const double_st& a){
    double_st res;

    if(_cadna_math_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=atanh((double)a.x);
    res.y=atanh((double)a.y);
    res.z=atanh((double)a.z);
    fesetround(FE_UPWARD);

    return res;
  };
float_st atanh(const float_st& a){
    float_st res;

    if(_cadna_math_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=atanh((float)a.x);
    res.y=atanh((float)a.y);
    res.z=atanh((float)a.z);
    fesetround(FE_UPWARD);

    return res;
  };
float_st atanhf(const float_st& a){
    float_st res;

    if(_cadna_math_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=atanhf((float)a.x);
    res.y=atanhf((float)a.y);
    res.z=atanhf((float)a.z);
    fesetround(FE_UPWARD);

    return res;
  };



//////////////////////////////////////////////////////////////////////////////
//****f* cadna_math/hypot
//    NAME
//      hypot
//    SYNOPSIS
//      res = hypot(x,y)
//    FUNCTION
//      The hypot() function computes the sqrt(x*x+y*y) without undue
//      overflow or underflow.
//
//
//    INPUTS
//      a           - double_st
//      b           - double_st
//    RESULT
//      res         - double_st
//    SEE ALSO
//      sqrtf(3)
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


//****f* cadna_math/hypotf
//    NAME
//      hypotf
//
//    SYNOPSIS
//      res = hypotf(x,y)
//
//    FUNCTION
//      The hypotf() function computes the sqrt(x*x+y*y) without undue
//    overflow or underflow.
//
//    SEE ALSO
//       sqrtf(3)
//
//
//    INPUTS
//      x           - float_st
//      b           - float_st
//    RESULT
//      res         - float_st
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

//
//  /





double_st hypot(const double_st& a, const double_st& b){
    double_st res;
    fesetround(FE_TONEAREST);
    res.accuracy=DIGIT_NOT_COMPUTED;
    res.x=hypot(a.x,b.x);
    res.y=hypot(a.y,b.y);
    res.z=hypot(a.z,b.z);
    fesetround(FE_UPWARD);
    return res;
  }
double_st hypot(const double_st& a, const float_st& b){
    double_st res;
    fesetround(FE_TONEAREST);
    res.accuracy=DIGIT_NOT_COMPUTED;
    res.x=hypot(a.x,b.x);
    res.y=hypot(a.y,b.y);
    res.z=hypot(a.z,b.z);
    fesetround(FE_UPWARD);
    return res;
  }
double_st hypot(const float_st& a, const double_st& b){
    double_st res;
    fesetround(FE_TONEAREST);
    res.accuracy=DIGIT_NOT_COMPUTED;
    res.x=hypot(a.x,b.x);
    res.y=hypot(a.y,b.y);
    res.z=hypot(a.z,b.z);
    fesetround(FE_UPWARD);
    return res;
  }
float_st hypotf(const float_st& a, const float_st& b){
    float_st res;
    fesetround(FE_TONEAREST);
    res.accuracy=DIGIT_NOT_COMPUTED;
    res.x=hypotf(a.x,b.x);
    res.y=hypotf(a.y,b.y);
    res.z=hypotf(a.z,b.z);
    fesetround(FE_UPWARD);
    return res;
  }
float_st hypot(const float_st& a, const float_st& b){
    float_st res;
    fesetround(FE_TONEAREST);
    res.accuracy=DIGIT_NOT_COMPUTED;
    res.x=hypot(a.x,b.x);
    res.y=hypot(a.y,b.y);
    res.z=hypot(a.z,b.z);
    fesetround(FE_UPWARD);
    return res;
  }

//****f* cadna_math/finite
//    NAME
//      finite
//    SYNOPSIS
//      res = finite(a)
//    FUNCTION
//      The finite() functions return a nonzero value if x is neither infinite
//      nor a "not-a-number"  (NaN)  value,  and  0 otherwise.
//
//
//    INPUTS
//      a           - double_st
//    RESULT
//      res         - int
//    SEE ALSO
//      isinf(3), isnan(3)
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



//****f* cadna_math/finite
//    NAME
//      finite
//    SYNOPSIS
//      res = finite(a)
//    FUNCTION
//      The finite() functions return a nonzero value if x is neither infinite
//      nor a "not-a-number"  (NaN)  value,  and  0 otherwise.
//
//
//    INPUTS
//      a           - float_st
//    RESULT
//      res         - int
//    SEE ALSO
//      isinf(3), isnan(3)
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





int finite(const double_st& a){
  int res;

  res=finite(a.x);

  if(res != finite(a.y) || res != finite(a.z) ){
    instability(&_cadna_math_count);
  }

  return res;
};
int finite(const float_st& a){
  int res;

  res=finite(a.x);

  if(res != finite(a.y) || res != finite(a.z) ){
    instability(&_cadna_math_count);
  }

  return res;
};




//****f* cadna_math/ldexp
//    NAME
//      ldexp
//    SYNOPSIS
//      res = ldexp(x,n)
//    FUNCTION
//      The ldexp() function returns the result of multiplying
//      the floating-point number x by 2 raised to the power exp.
//
//
//    INPUTS
//      x           - double_st
//      n           - int
//    RESULT
//      res         - double_st
//    SEE ALSO
//      frexp(3), modf(3), scalbln(3)
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
//


//****f* cadna_math/ldexp
//    NAME
//      ldexp
//    SYNOPSIS
//      res = ldexp(x,n)
//    FUNCTION
//      The ldexp() function returns the result of multiplying
//      the floating-point number x by 2 raised to the power exp.
//
//
//    INPUTS
//      x           - float_st
//      n           - int
//    RESULT
//      res         - float_st
//    SEE ALSO
//      frexp(3), modf(3), scalbln(3)
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
//



//****f* cadna_math/ldexpf
//    NAME
//      ldexpf
//    SYNOPSIS
//      res = ldexpf(x,n)
//    FUNCTION
//      The ldexpf() function returns the result of multiplying
//      the floating-point number x by 2 raised to the power exp.
//
//
//    INPUTS
//      x           - float_st
//      n           - int
//    RESULT
//      res         - float_st
//    SEE ALSO
//      frexpf(3), modf(3), scalbln(3)
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
//





double_st ldexp(const double_st& a, int b){
    double_st res;

    if(_cadna_math_tag!=0 ){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=ldexp((double)a.x, b);
    res.y=ldexp((double)a.y, b);
    res.z=ldexp((double)a.z, b);
    fesetround(FE_UPWARD);

    return res;
  };
float_st ldexp(const float_st& a, int b){
    float_st res;

    if(_cadna_math_tag!=0 ){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=ldexp((float)a.x, b);
    res.y=ldexp((float)a.y, b);
    res.z=ldexp((float)a.z, b);
    fesetround(FE_UPWARD);

    return res;
  };
float_st ldexpf(const float_st& a, int b){
    float_st res;

    if(_cadna_math_tag!=0 ){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=ldexpf((float)a.x, b);
    res.y=ldexpf((float)a.y, b);
    res.z=ldexpf((float)a.z, b);
    fesetround(FE_UPWARD);

    return res;
  };



//****f* cadna_math/fmod
//    NAME
//      fmod
//    SYNOPSIS
//      res = fmod(a,b)
//    FUNCTION
//      The  fmod()  function  computes  the  floating-point remainder of dividing x by y.
//      The return value is x - n * y, where n is the quotient of x / y, rounded toward
//      zero to an integer.
//
//
//    INPUTS
//      a           - double_st
//      b           - double_st
//    RESULT
//      res         - double_st
//    SEE ALSO
//      remainder(3)
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


//****f* cadna_math/fmod
//    NAME
//      fmod
//    SYNOPSIS
//      res = fmod(a,b)
//    FUNCTION
//      The  fmod()  function  computes  the  floating-point remainder of dividing x by y.
//      The return value is x - n * y, where n is the quotient of x / y, rounded toward
//      zero to an integer.
//
//
//    INPUTS
//      a           - float_st
//      b           - float_st
//    RESULT
//      res         - float_st
//    SEE ALSO
//      remainder(3)
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


//****f* cadna_math/fmodf
//    NAME
//      fmodf
//    SYNOPSIS
//      res = fmodf(a,b)
//    FUNCTION
//      The  fmodf()  function  computes  the  floating-point remainder of dividing x by y.
//      The return value is x - n * y, where n is the quotient of x / y, rounded toward
//      zero to an integer.
//
//
//    INPUTS
//      a           - float_st
//      b           - float_st
//    RESULT
//      res         - float_st
//    SEE ALSO
//      remainder(3)
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






double_st fmod(const double_st& a, const double_st& b){
    double_st res;

    if(_cadna_math_tag!=0 ){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
      if (b.accuracy==DIGIT_NOT_COMPUTED) b.approx_digit();
      if (b.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=fmod((double)a.x, (double)b.x);
    res.y=fmod((double)a.y, (double)b.y);
    res.z=fmod((double)a.z, (double)b.z);
    fesetround(FE_UPWARD);

    return res;
  };
float_st fmod(const float_st& a, const float_st& b){
    float_st res;

    if(_cadna_math_tag!=0 ){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
      if (b.accuracy==DIGIT_NOT_COMPUTED) b.approx_digit();
      if (b.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=fmod((float)a.x, (float)b.x);
    res.y=fmod((float)a.y, (float)b.y);
    res.z=fmod((float)a.z, (float)b.z);
    fesetround(FE_UPWARD);

    return res;
  };
float_st fmodf(const float_st& a, const float_st& b){
    float_st res;

    if(_cadna_math_tag!=0 ){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
      if (b.accuracy==DIGIT_NOT_COMPUTED) b.approx_digit();
      if (b.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=fmodf((float)a.x, (float)b.x);
    res.y=fmodf((float)a.y, (float)b.y);
    res.z=fmodf((float)a.z, (float)b.z);
    fesetround(FE_UPWARD);

    return res;
  };



//****f* cadna_math/frexp
//    NAME
//      frexp
//    SYNOPSIS
//      res = frexp(x,n)
//    FUNCTION
//      The  frexp()  function is used to split the number x
//      into a normalized fraction and an exponent which is stored in
//      exp.
//
//
//    INPUTS
//      x           - double_st
//      n           - int*
//    RESULT
//      res         - double_st
//    SEE ALSO
//      ldexp(3)
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

//****f* cadna_math/frexp
//    NAME
//      frexp
//    SYNOPSIS
//      res = frexpf(x,n)
//    FUNCTION
//      The  frexp()  function is used to split the number x
//      into a normalized fraction and an exponent which is stored in
//      exp.
//
//
//    INPUTS
//      x           - float_st
//      n           - int*
//    RESULT
//      res         - float_st
//    SEE ALSO
//      ldexp(3)
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


//****f* cadna_math/frexpf
//    NAME
//      frexpf
//    SYNOPSIS
//      res = frexpf(x,n)
//    FUNCTION
//      The  frexpf()  function is used to split the number x
//      into a normalized fraction and an exponent which is stored in
//      exp.
//
//
//    INPUTS
//      x           - float_st
//      n           - int*
//    RESULT
//      res         - float_st
//    SEE ALSO
//      ldexpf(3)
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



double_st frexp(const double_st& a, int *b){
    double_st res;
    int b2, b3;

    if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
    if (a.accuracy==0) instability(&_cadna_math_count);
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=frexp((double)a.x, b);
    res.y=frexp((double)a.y, &b2);
    res.z=frexp((double)a.z, &b3);

    if(*b != b2 || b2 != b3){
      std::cerr << "CADNA : problem in function frexp with the  integral power of 2 parameter" << std::endl;
    }

    fesetround(FE_UPWARD);

    return res;
};
float_st frexp(const float_st& a, int *b){
    float_st res;
    int b2, b3;

    if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
    if (a.accuracy==0) instability(&_cadna_math_count);
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=frexp((float)a.x, b);
    res.y=frexp((float)a.y, &b2);
    res.z=frexp((float)a.z, &b3);

    if(*b != b2 || b2 != b3){
      std::cerr << "CADNA : problem in function frexp with the  integral power of 2 parameter" << std::endl;
    }

    fesetround(FE_UPWARD);

    return res;
};
float_st frexpf(const float_st& a, int *b){
    float_st res;
    int b2, b3;

    if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
    if (a.accuracy==0) instability(&_cadna_math_count);
    res.accuracy=DIGIT_NOT_COMPUTED;
    fesetround(FE_TONEAREST);
    res.x=frexpf((float)a.x, b);
    res.y=frexpf((float)a.y, &b2);
    res.z=frexpf((float)a.z, &b3);

    if(*b != b2 || b2 != b3){
      std::cerr << "CADNA : problem in function frexp with the  integral power of 2 parameter" << std::endl;
    }

    fesetround(FE_UPWARD);

    return res;
};


//****f* cadna_math/modf
//    NAME
//      modf
//    SYNOPSIS
//      res = modf(x,iptr)
//    FUNCTION
//      The  modf()  function break value into integral and fractional parts
//
//
//    INPUTS
//      x           - double_st
//      iptr           - double_st *
//    RESULT
//      res         - double_st
//    SEE ALSO
//      frexp(3), ldexp(3), math(3)
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

//****f* cadna_math/modf
//    NAME
//      modf
//    SYNOPSIS
//      res = modff(x,iptr)
//    FUNCTION
//      The  modf()  function break value into integral and fractional parts
//
//
//    INPUTS
//      x           - float_st
//      iptr        - float_st*
//    RESULT
//      res         - float_st
//    SEE ALSO
//       frexp(3), ldexp(3), math(3)
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


//****f* cadna_math/modff
//    NAME
//      modff
//    SYNOPSIS
//      res = modff(x,iptr)
//    FUNCTION
//      The  modf()  function break value into integral and fractional parts
//
//
//    INPUTS
//      x           - float_st
//      iptr        - float_st*
//    RESULT
//      res         - float_st
//    SEE ALSO
//       frexp(3), ldexp(3), math(3)
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



double_st modf(const double_st& a, double_st*b){
  double_st res;

  if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
  if (a.accuracy==0) instability(&_cadna_math_count);
  res.accuracy=DIGIT_NOT_COMPUTED;
  b->accuracy=DIGIT_NOT_COMPUTED;
  fesetround(FE_TONEAREST);
  res.x=modf((double)a.x, &b->x);
  res.y=modf((double)a.y, &b->y);
  res.z=modf((double)a.z, &b->z);

  if(b->x != b->y || b->x != b->z){
    std::cerr << "CADNA : problem in function modf "<< std::endl;
  }

  fesetround(FE_UPWARD);

  return res;
};
float_st modff(const float_st& a, float_st*b){
  float_st res;

  if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
  if (a.accuracy==0) instability(&_cadna_math_count);
  res.accuracy=DIGIT_NOT_COMPUTED;
  b->accuracy=DIGIT_NOT_COMPUTED;
  fesetround(FE_TONEAREST);
  res.x=modff((float)a.x, &b->x);
  res.y=modff((float)a.y, &b->y);
  res.z=modff((float)a.z, &b->z);

  if(b->x != b->y || b->x != b->z){
    std::cerr << "CADNA : problem in function modf "<< std::endl;
  }

  fesetround(FE_UPWARD);

  return res;
};







//****f* cadna_math/isfinite
//    NAME
//      isfinite
//    SYNOPSIS
//      res = isfinite(a)
//    FUNCTION
//      The finite() functions return a nonzero value if x is neither infinite
//      nor a "not-a-number"  (NaN)  value,  and  0 otherwise.
//
//
//    INPUTS
//      a           - double_st
//    RESULT
//      res         - int
//    SEE ALSO
//      isinf(3), isnan(3)
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



//****f* cadna_math/isfinite
//    NAME
//      isfinite
//    SYNOPSIS
//      res = isfinitef(a)
//    FUNCTION
//      The finite() functions return a nonzero value if x is neither infinite
//      nor a "not-a-number"  (NaN)  value,  and  0 otherwise.
//
//
//    INPUTS
//      a           - float_st
//    RESULT
//      res         - int
//    SEE ALSO
//      isinf(3), isnan(3)
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





int isfinite(const double_st& a){
    int res;

    res=isfinite(a.x);

    if(res != isfinite(a.y) || res != isfinite(a.z) ){
      instability(&_cadna_math_count);
    }

    return res;
  };
int isfinitef(const float_st& a){
    int res;

    res=isfinitef(a.x);

    if(res != isfinitef(a.y) || res != isfinitef(a.z) ){
      instability(&_cadna_math_count);
    }

    return res;
  };




//****f* cadna_math/isinf
//    NAME
//      isinf
//    SYNOPSIS
//      res = isinf(a)
//    FUNCTION
//    The isinf() functions return 1 if x is positive infinity, -1 if x is negative infinity, and 0 otherwise.
//
//
//    INPUTS
//      a           - double_st
//    RESULT
//      res         - int
//    SEE ALSO
//      finite(3), isinf(3)
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



//****f* cadna_math/isinf
//    NAME
//      isinf
//    SYNOPSIS
//      res = isinf(a)
//    FUNCTION
//     The isinf() functions return 1 if x is positive infinity, -1 if x is negative infinity, and 0 otherwise.
//
//
//    INPUTS
//      a           - float_st
//    RESULT
//      res         - int
//    SEE ALSO
//      finite(3), isinf(3)
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





int isinf(const double_st& a){
  int res;

  res=isinf(a.x);

  if(res != isinf(a.y) || res != isinf(a.z) ){
    instability(&_cadna_math_count);
  }

  return res;
};
int isinf(const float_st& a){
  int res;

  res=isinf(a.x);

  if(res != isinf(a.y) || res != isinf(a.z) ){
    instability(&_cadna_math_count);
  }

  return res;
};




//****f* cadna_math/isnan
//    NAME
//      isnan
//    SYNOPSIS
//      res = isnan(a)
//    FUNCTION
//      The isnanf() functions return a nonzero value if x is a NaN value, and 0 otherwise.
//
//
//    INPUTS
//      a           - double_st
//    RESULT
//      res         - int
//    SEE ALSO
//      finite(3), isinf(3)
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




//****f* cadna_math/isnan
//    NAME
//      isnan
//    SYNOPSIS
//      res = isnan(a)
//    FUNCTION
//      The isnan() functions return a nonzero value if x is
//
//
//    INPUTS
//      a           - float_st
//    RESULT
//      res         - int
//    SEE ALSO
//      finite(3), isinf(3)
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





int isnan(const double_st& a){
    int res;

    res=isnan(a.x);

    if(res != isnan(a.y) || res != isnan(a.z) ){
      instability(&_cadna_math_count);
    }

  return res;
};
int isnan(const float_st& a){
    int res;

    res=isnan(a.x);

    if(res != isnan(a.y) || res != isnan(a.z) ){
      instability(&_cadna_math_count);
    }

  return res;
};




//****f* cadna_math/fmax
//    NAME
//      fmax
//    SYNOPSIS
//      res = fmax(x,y)
//    FUNCTION
//      The fmax() functions return x or y, whichever is larger.
//
//
//    INPUTS
//      a           - double_st
//      b           - double_st
//    RESULT
//      res         - double_st
//    SEE ALSO
//      fmin(3)
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

//
//  /
//****f* cadna_math/fmaxf
//    NAME
//      fmaxf
//    SYNOPSIS
//      res = fmaxf(x,y)
//    FUNCTION
//      The fmaxf() functions return x or y, whichever is larger.
//
//
//    INPUTS
//      x           - float_st
//      b           - float_st
//    RESULT
//      res         - float_st
//    SEE ALSO
//      fminf(3)
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



double_st fmax(const double& a, const double_st& b){
    double_st res;
    unsigned int random;
    double tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);
    if (r){
      res=double_st(a);
    }
    else {
      if ( 3*a  > ( b.x + b.y + b.z ))
	res=double_st(a);
      else
	res=b;
    }
    return res;
  }
double_st fmax(const float& a, const double_st& b){
    double_st res;
    unsigned int random;
    double tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);
    if (r){
      res=double_st(a);
    }
    else {
      if ( 3*a  > ( b.x + b.y + b.z ))
	res=double_st(a);
      else
	res=b;
    }
    return res;
  }
double_st fmax(const unsigned long long& a, const double_st& b){
    double_st res;
    unsigned int random;
    double tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);
    if (r){
      res=double_st(a);
    }
    else {
      if ( 3*a  > ( b.x + b.y + b.z ))
	res=double_st(a);
      else
	res=b;
    }
    return res;
  }
double_st fmax(const long long& a, const double_st& b){
    double_st res;
    unsigned int random;
    double tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);
    if (r){
      res=double_st(a);
    }
    else {
      if ( 3*a  > ( b.x + b.y + b.z ))
	res=double_st(a);
      else
	res=b;
    }
    return res;
  }
double_st fmax(const unsigned long& a, const double_st& b){
    double_st res;
    unsigned int random;
    double tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);
    if (r){
      res=double_st(a);
    }
    else {
      if ( 3*a  > ( b.x + b.y + b.z ))
	res=double_st(a);
      else
	res=b;
    }
    return res;
  }
double_st fmax(const long& a, const double_st& b){
    double_st res;
    unsigned int random;
    double tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);
    if (r){
      res=double_st(a);
    }
    else {
      if ( 3*a  > ( b.x + b.y + b.z ))
	res=double_st(a);
      else
	res=b;
    }
    return res;
  }
double_st fmax(const unsigned int & a, const double_st& b){
    double_st res;
    unsigned int random;
    double tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);
    if (r){
      res=double_st(a);
    }
    else {
      if ( 3*a  > ( b.x + b.y + b.z ))
	res=double_st(a);
      else
	res=b;
    }
    return res;
  }
double_st fmax(const int & a, const double_st& b){
    double_st res;
    unsigned int random;
    double tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);
    if (r){
      res=double_st(a);
    }
    else {
      if ( 3*a  > ( b.x + b.y + b.z ))
	res=double_st(a);
      else
	res=b;
    }
    return res;
  }
double_st fmax(const unsigned short& a, const double_st& b){
    double_st res;
    unsigned int random;
    double tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);
    if (r){
      res=double_st(a);
    }
    else {
      if ( 3*a  > ( b.x + b.y + b.z ))
	res=double_st(a);
      else
	res=b;
    }
    return res;
  }
double_st fmax(const short& a, const double_st& b){
    double_st res;
    unsigned int random;
    double tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);
    if (r){
      res=double_st(a);
    }
    else {
      if ( 3*a  > ( b.x + b.y + b.z ))
	res=double_st(a);
      else
	res=b;
    }
    return res;
  }
double_st fmax(const unsigned char& a, const double_st& b){
    double_st res;
    unsigned int random;
    double tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);
    if (r){
      res=double_st(a);
    }
    else {
      if ( 3*a  > ( b.x + b.y + b.z ))
	res=double_st(a);
      else
	res=b;
    }
    return res;
  }
double_st fmax(const char& a, const double_st& b){
    double_st res;
    unsigned int random;
    double tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);
    if (r){
      res=double_st(a);
    }
    else {
      if ( 3*a  > ( b.x + b.y + b.z ))
	res=double_st(a);
      else
	res=b;
    }
    return res;
  }

float_st fmaxf(const double& a, const float_st& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);
    if (r){
      res=float_st(a);
    }
    else {
      if ( 3*a  > ( b.x + b.y + b.z ))
	res=float_st(a);
      else
	res=b;
    }
    return res;
  }
float_st fmaxf(const float& a, const float_st& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);
    if (r){
      res=float_st(a);
    }
    else {
      if ( 3*a  > ( b.x + b.y + b.z ))
	res=float_st(a);
      else
	res=b;
    }
    return res;
  }
float_st fmaxf(const unsigned long long& a, const float_st& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);
    if (r){
      res=float_st(a);
    }
    else {
      if ( 3*a  > ( b.x + b.y + b.z ))
	res=float_st(a);
      else
	res=b;
    }
    return res;
  }
float_st fmaxf(const long long& a, const float_st& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);
    if (r){
      res=float_st(a);
    }
    else {
      if ( 3*a  > ( b.x + b.y + b.z ))
	res=float_st(a);
      else
	res=b;
    }
    return res;
  }
float_st fmaxf(const unsigned long& a, const float_st& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);
    if (r){
      res=float_st(a);
    }
    else {
      if ( 3*a  > ( b.x + b.y + b.z ))
	res=float_st(a);
      else
	res=b;
    }
    return res;
  }
float_st fmaxf(const long& a, const float_st& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);
    if (r){
      res=float_st(a);
    }
    else {
      if ( 3*a  > ( b.x + b.y + b.z ))
	res=float_st(a);
      else
	res=b;
    }
    return res;
  }
float_st fmaxf(const unsigned int & a, const float_st& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);
    if (r){
      res=float_st(a);
    }
    else {
      if ( 3*a  > ( b.x + b.y + b.z ))
	res=float_st(a);
      else
	res=b;
    }
    return res;
  }
float_st fmaxf(const int & a, const float_st& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);
    if (r){
      res=float_st(a);
    }
    else {
      if ( 3*a  > ( b.x + b.y + b.z ))
	res=float_st(a);
      else
	res=b;
    }
    return res;
  }
float_st fmaxf(const unsigned short& a, const float_st& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);
    if (r){
      res=float_st(a);
    }
    else {
      if ( 3*a  > ( b.x + b.y + b.z ))
	res=float_st(a);
      else
	res=b;
    }
    return res;
  }
float_st fmaxf(const short& a, const float_st& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);
    if (r){
      res=float_st(a);
    }
    else {
      if ( 3*a  > ( b.x + b.y + b.z ))
	res=float_st(a);
      else
	res=b;
    }
    return res;
  }
float_st fmaxf(const unsigned char& a, const float_st& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);
    if (r){
      res=float_st(a);
    }
    else {
      if ( 3*a  > ( b.x + b.y + b.z ))
	res=float_st(a);
      else
	res=b;
    }
    return res;
  }
float_st fmaxf(const char& a, const float_st& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);
    if (r){
      res=float_st(a);
    }
    else {
      if ( 3*a  > ( b.x + b.y + b.z ))
	res=float_st(a);
      else
	res=b;
    }
    return res;
  }

float_st fmax(const double& a, const float_st& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);
    if (r){
      res=float_st(a);
    }
    else {
      if ( 3*a  > ( b.x + b.y + b.z ))
	res=float_st(a);
      else
	res=b;
    }
    return res;
  }
float_st fmax(const float& a, const float_st& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);
    if (r){
      res=float_st(a);
    }
    else {
      if ( 3*a  > ( b.x + b.y + b.z ))
	res=float_st(a);
      else
	res=b;
    }
    return res;
  }
float_st fmax(const unsigned long long& a, const float_st& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);
    if (r){
      res=float_st(a);
    }
    else {
      if ( 3*a  > ( b.x + b.y + b.z ))
	res=float_st(a);
      else
	res=b;
    }
    return res;
  }
float_st fmax(const long long& a, const float_st& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);
    if (r){
      res=float_st(a);
    }
    else {
      if ( 3*a  > ( b.x + b.y + b.z ))
	res=float_st(a);
      else
	res=b;
    }
    return res;
  }
float_st fmax(const unsigned long& a, const float_st& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);
    if (r){
      res=float_st(a);
    }
    else {
      if ( 3*a  > ( b.x + b.y + b.z ))
	res=float_st(a);
      else
	res=b;
    }
    return res;
  }
float_st fmax(const long& a, const float_st& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);
    if (r){
      res=float_st(a);
    }
    else {
      if ( 3*a  > ( b.x + b.y + b.z ))
	res=float_st(a);
      else
	res=b;
    }
    return res;
  }
float_st fmax(const unsigned int & a, const float_st& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);
    if (r){
      res=float_st(a);
    }
    else {
      if ( 3*a  > ( b.x + b.y + b.z ))
	res=float_st(a);
      else
	res=b;
    }
    return res;
  }
float_st fmax(const int & a, const float_st& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);
    if (r){
      res=float_st(a);
    }
    else {
      if ( 3*a  > ( b.x + b.y + b.z ))
	res=float_st(a);
      else
	res=b;
    }
    return res;
  }
float_st fmax(const unsigned short& a, const float_st& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);
    if (r){
      res=float_st(a);
    }
    else {
      if ( 3*a  > ( b.x + b.y + b.z ))
	res=float_st(a);
      else
	res=b;
    }
    return res;
  }
float_st fmax(const short& a, const float_st& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);
    if (r){
      res=float_st(a);
    }
    else {
      if ( 3*a  > ( b.x + b.y + b.z ))
	res=float_st(a);
      else
	res=b;
    }
    return res;
  }
float_st fmax(const unsigned char& a, const float_st& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);
    if (r){
      res=float_st(a);
    }
    else {
      if ( 3*a  > ( b.x + b.y + b.z ))
	res=float_st(a);
      else
	res=b;
    }
    return res;
  }
float_st fmax(const char& a, const float_st& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);
    if (r){
      res=float_st(a);
    }
    else {
      if ( 3*a  > ( b.x + b.y + b.z ))
	res=float_st(a);
      else
	res=b;
    }
    return res;
  }




double_st fmax(const double_st& a, const double& b){
    double_st res;
    unsigned int random;
    double tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=double_st(b);
    else {
      if ( ( a.x + a.y + a.z ) > 3.*b)
	res=a;
      else
	res=double_st(b);
    }
    return res;
  }
double_st fmax(const double_st& a, const float& b){
    double_st res;
    unsigned int random;
    double tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=double_st(b);
    else {
      if ( ( a.x + a.y + a.z ) > 3.*b)
	res=a;
      else
	res=double_st(b);
    }
    return res;
  }
double_st fmax(const double_st& a, const unsigned long long& b){
    double_st res;
    unsigned int random;
    double tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=double_st(b);
    else {
      if ( ( a.x + a.y + a.z ) > 3.*b)
	res=a;
      else
	res=double_st(b);
    }
    return res;
  }
double_st fmax(const double_st& a, const long long& b){
    double_st res;
    unsigned int random;
    double tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=double_st(b);
    else {
      if ( ( a.x + a.y + a.z ) > 3.*b)
	res=a;
      else
	res=double_st(b);
    }
    return res;
  }
double_st fmax(const double_st& a, const unsigned long& b){
    double_st res;
    unsigned int random;
    double tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=double_st(b);
    else {
      if ( ( a.x + a.y + a.z ) > 3.*b)
	res=a;
      else
	res=double_st(b);
    }
    return res;
  }
double_st fmax(const double_st& a, const long& b){
    double_st res;
    unsigned int random;
    double tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=double_st(b);
    else {
      if ( ( a.x + a.y + a.z ) > 3.*b)
	res=a;
      else
	res=double_st(b);
    }
    return res;
  }
double_st fmax(const double_st& a, const unsigned int & b){
    double_st res;
    unsigned int random;
    double tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=double_st(b);
    else {
      if ( ( a.x + a.y + a.z ) > 3.*b)
	res=a;
      else
	res=double_st(b);
    }
    return res;
  }
double_st fmax(const double_st& a, const int & b){
    double_st res;
    unsigned int random;
    double tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=double_st(b);
    else {
      if ( ( a.x + a.y + a.z ) > 3.*b)
	res=a;
      else
	res=double_st(b);
    }
    return res;
  }
double_st fmax(const double_st& a, const unsigned short& b){
    double_st res;
    unsigned int random;
    double tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=double_st(b);
    else {
      if ( ( a.x + a.y + a.z ) > 3.*b)
	res=a;
      else
	res=double_st(b);
    }
    return res;
  }
double_st fmax(const double_st& a, const short& b){
    double_st res;
    unsigned int random;
    double tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=double_st(b);
    else {
      if ( ( a.x + a.y + a.z ) > 3.*b)
	res=a;
      else
	res=double_st(b);
    }
    return res;
  }
double_st fmax(const double_st& a, const unsigned char& b){
    double_st res;
    unsigned int random;
    double tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=double_st(b);
    else {
      if ( ( a.x + a.y + a.z ) > 3.*b)
	res=a;
      else
	res=double_st(b);
    }
    return res;
  }
double_st fmax(const double_st& a, const char& b){
    double_st res;
    unsigned int random;
    double tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=double_st(b);
    else {
      if ( ( a.x + a.y + a.z ) > 3.*b)
	res=a;
      else
	res=double_st(b);
    }
    return res;
  }

float_st fmaxf(const float_st& a, const double& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(b);
    else {
      if ( ( a.x + a.y + a.z ) > 3.*b)
	res=a;
      else
	res=float_st(b);
    }
    return res;
  }
float_st fmaxf(const float_st& a, const float& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(b);
    else {
      if ( ( a.x + a.y + a.z ) > 3.*b)
	res=a;
      else
	res=float_st(b);
    }
    return res;
  }
float_st fmaxf(const float_st& a, const unsigned long long& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(b);
    else {
      if ( ( a.x + a.y + a.z ) > 3.*b)
	res=a;
      else
	res=float_st(b);
    }
    return res;
  }
float_st fmaxf(const float_st& a, const long long& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(b);
    else {
      if ( ( a.x + a.y + a.z ) > 3.*b)
	res=a;
      else
	res=float_st(b);
    }
    return res;
  }
float_st fmaxf(const float_st& a, const unsigned long& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(b);
    else {
      if ( ( a.x + a.y + a.z ) > 3.*b)
	res=a;
      else
	res=float_st(b);
    }
    return res;
  }
float_st fmaxf(const float_st& a, const long& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(b);
    else {
      if ( ( a.x + a.y + a.z ) > 3.*b)
	res=a;
      else
	res=float_st(b);
    }
    return res;
  }
float_st fmaxf(const float_st& a, const unsigned int & b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(b);
    else {
      if ( ( a.x + a.y + a.z ) > 3.*b)
	res=a;
      else
	res=float_st(b);
    }
    return res;
  }
float_st fmaxf(const float_st& a, const int & b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(b);
    else {
      if ( ( a.x + a.y + a.z ) > 3.*b)
	res=a;
      else
	res=float_st(b);
    }
    return res;
  }
float_st fmaxf(const float_st& a, const unsigned short& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(b);
    else {
      if ( ( a.x + a.y + a.z ) > 3.*b)
	res=a;
      else
	res=float_st(b);
    }
    return res;
  }
float_st fmaxf(const float_st& a, const short& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(b);
    else {
      if ( ( a.x + a.y + a.z ) > 3.*b)
	res=a;
      else
	res=float_st(b);
    }
    return res;
  }
float_st fmaxf(const float_st& a, const unsigned char& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(b);
    else {
      if ( ( a.x + a.y + a.z ) > 3.*b)
	res=a;
      else
	res=float_st(b);
    }
    return res;
  }
float_st fmaxf(const float_st& a, const char& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(b);
    else {
      if ( ( a.x + a.y + a.z ) > 3.*b)
	res=a;
      else
	res=float_st(b);
    }
    return res;
  }

float_st fmax(const float_st& a, const double& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(b);
    else {
      if ( ( a.x + a.y + a.z ) > 3.*b)
	res=a;
      else
	res=float_st(b);
    }
    return res;
  }
float_st fmax(const float_st& a, const float& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(b);
    else {
      if ( ( a.x + a.y + a.z ) > 3.*b)
	res=a;
      else
	res=float_st(b);
    }
    return res;
  }
float_st fmax(const float_st& a, const unsigned long long& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(b);
    else {
      if ( ( a.x + a.y + a.z ) > 3.*b)
	res=a;
      else
	res=float_st(b);
    }
    return res;
  }
float_st fmax(const float_st& a, const long long& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(b);
    else {
      if ( ( a.x + a.y + a.z ) > 3.*b)
	res=a;
      else
	res=float_st(b);
    }
    return res;
  }
float_st fmax(const float_st& a, const unsigned long& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(b);
    else {
      if ( ( a.x + a.y + a.z ) > 3.*b)
	res=a;
      else
	res=float_st(b);
    }
    return res;
  }
float_st fmax(const float_st& a, const long& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(b);
    else {
      if ( ( a.x + a.y + a.z ) > 3.*b)
	res=a;
      else
	res=float_st(b);
    }
    return res;
  }
float_st fmax(const float_st& a, const unsigned int & b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(b);
    else {
      if ( ( a.x + a.y + a.z ) > 3.*b)
	res=a;
      else
	res=float_st(b);
    }
    return res;
  }
float_st fmax(const float_st& a, const int & b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(b);
    else {
      if ( ( a.x + a.y + a.z ) > 3.*b)
	res=a;
      else
	res=float_st(b);
    }
    return res;
  }
float_st fmax(const float_st& a, const unsigned short& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(b);
    else {
      if ( ( a.x + a.y + a.z ) > 3.*b)
	res=a;
      else
	res=float_st(b);
    }
    return res;
  }
float_st fmax(const float_st& a, const short& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(b);
    else {
      if ( ( a.x + a.y + a.z ) > 3.*b)
	res=a;
      else
	res=float_st(b);
    }
    return res;
  }
float_st fmax(const float_st& a, const unsigned char& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(b);
    else {
      if ( ( a.x + a.y + a.z ) > 3.*b)
	res=a;
      else
	res=float_st(b);
    }
    return res;
  }
float_st fmax(const float_st& a, const char& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(b);
    else {
      if ( ( a.x + a.y + a.z ) > 3.*b)
	res=a;
      else
	res=float_st(b);
    }
    return res;
  }





double_st fmax(const double_st& a, const double_st& b){
  double_st res;
  unsigned int random;
  double tmp;

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

  int r=res.numericalnoise();

  if (_cadna_branching_tag && r)
    instability(&_cadna_branching_count);

  if (r){
    if (a.accuracy==DIGIT_NOT_COMPUTED || a.accuracy==RELIABLE_RESULT)
      a.nb_significant_digit();
    if (b.accuracy==DIGIT_NOT_COMPUTED || b.accuracy==RELIABLE_RESULT)
      b.nb_significant_digit();
    if (a.accuracy > b.accuracy )
	res=a;
	if (a.approx_digit()>b.approx_digit())
	  res=a;
	else
	  res=b;
	}
    else {
      if ( ( a.x + a.y + a.z ) >	( b.x + b.y + b.z ))
	res=a;
      else
	res=b;
    }
    return res;
  }
double_st fmax(const double_st& a, const float_st& b){
  double_st res;
  unsigned int random;
  double tmp;

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

  int r=res.numericalnoise();

  if (_cadna_branching_tag && r)
    instability(&_cadna_branching_count);

  if (r){
    if (a.accuracy==DIGIT_NOT_COMPUTED || a.accuracy==RELIABLE_RESULT)
      a.nb_significant_digit();
    if (b.accuracy==DIGIT_NOT_COMPUTED || b.accuracy==RELIABLE_RESULT)
      b.nb_significant_digit();
    if (a.accuracy > b.accuracy )
	res=a;
	if (a.approx_digit()>b.approx_digit())
	  res=a;
	else
	  res=b;
	}
    else {
      if ( ( a.x + a.y + a.z ) >	( b.x + b.y + b.z ))
	res=a;
      else
	res=b;
    }
    return res;
  }
double_st fmax(const float_st& a, const double_st& b){
  double_st res;
  unsigned int random;
  double tmp;

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

  int r=res.numericalnoise();

  if (_cadna_branching_tag && r)
    instability(&_cadna_branching_count);

  if (r){
    if (a.accuracy==DIGIT_NOT_COMPUTED || a.accuracy==RELIABLE_RESULT)
      a.nb_significant_digit();
    if (b.accuracy==DIGIT_NOT_COMPUTED || b.accuracy==RELIABLE_RESULT)
      b.nb_significant_digit();
    if (a.accuracy > b.accuracy )
	res=a;
	if (a.approx_digit()>b.approx_digit())
	  res=a;
	else
	  res=b;
	}
    else {
      if ( ( a.x + a.y + a.z ) >	( b.x + b.y + b.z ))
	res=a;
      else
	res=b;
    }
    return res;
  }
float_st fmaxf(const float_st& a, const float_st& b){
  float_st res;
  unsigned int random;
  float tmp;

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

  int r=res.numericalnoise();

  if (_cadna_branching_tag && r)
    instability(&_cadna_branching_count);

  if (r){
    if (a.accuracy==DIGIT_NOT_COMPUTED || a.accuracy==RELIABLE_RESULT)
      a.nb_significant_digit();
    if (b.accuracy==DIGIT_NOT_COMPUTED || b.accuracy==RELIABLE_RESULT)
      b.nb_significant_digit();
    if (a.accuracy > b.accuracy )
	res=a;
	if (a.approx_digit()>b.approx_digit())
	  res=a;
	else
	  res=b;
	}
    else {
      if ( ( a.x + a.y + a.z ) >	( b.x + b.y + b.z ))
	res=a;
      else
	res=b;
    }
    return res;
  }
float_st fmax(const float_st& a, const float_st& b){
  float_st res;
  unsigned int random;
  float tmp;

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

  int r=res.numericalnoise();

  if (_cadna_branching_tag && r)
    instability(&_cadna_branching_count);

  if (r){
    if (a.accuracy==DIGIT_NOT_COMPUTED || a.accuracy==RELIABLE_RESULT)
      a.nb_significant_digit();
    if (b.accuracy==DIGIT_NOT_COMPUTED || b.accuracy==RELIABLE_RESULT)
      b.nb_significant_digit();
    if (a.accuracy > b.accuracy )
	res=a;
	if (a.approx_digit()>b.approx_digit())
	  res=a;
	else
	  res=b;
	}
    else {
      if ( ( a.x + a.y + a.z ) >	( b.x + b.y + b.z ))
	res=a;
      else
	res=b;
    }
    return res;
  }

//****f* cadna_math/fmin
//    NAME
//      fmin
//    SYNOPSIS
//      res = fmin(x,y)
//    FUNCTION
//      The fmin() functions return x or y, whichever is smaller.
//
//
//    INPUTS
//      a           - double_st
//      b           - double_st
//    RESULT
//      res         - double_st
//    SEE ALSO
//      fmax(3)
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
//****f* cadna_math/fminf
//    NAME
//      fminf
//    SYNOPSIS
//      res = fminf(x,y)
//    FUNCTION
//      The fminf() functions return x or y, whichever is smaller.

//
//
//    INPUTS
//      x           - float_st
//      b           - float_st
//    RESULT
//      res         - float_st
//    SEE ALSO
//      fmaxf(3)
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





double_st fmin(const double& a, const double_st& b){
    double_st res;

    unsigned int random;
    double tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=double_st(a);
    else {
      if ( 3*a < ( b.x + b.y + b.z ))
	res=double_st(a);
      else
	res=b;
    }
    return res;
  }
double_st fmin(const float& a, const double_st& b){
    double_st res;

    unsigned int random;
    double tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=double_st(a);
    else {
      if ( 3*a < ( b.x + b.y + b.z ))
	res=double_st(a);
      else
	res=b;
    }
    return res;
  }
double_st fmin(const unsigned long long& a, const double_st& b){
    double_st res;

    unsigned int random;
    double tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=double_st(a);
    else {
      if ( 3*a < ( b.x + b.y + b.z ))
	res=double_st(a);
      else
	res=b;
    }
    return res;
  }
double_st fmin(const long long& a, const double_st& b){
    double_st res;

    unsigned int random;
    double tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=double_st(a);
    else {
      if ( 3*a < ( b.x + b.y + b.z ))
	res=double_st(a);
      else
	res=b;
    }
    return res;
  }
double_st fmin(const unsigned long& a, const double_st& b){
    double_st res;

    unsigned int random;
    double tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=double_st(a);
    else {
      if ( 3*a < ( b.x + b.y + b.z ))
	res=double_st(a);
      else
	res=b;
    }
    return res;
  }
double_st fmin(const long& a, const double_st& b){
    double_st res;

    unsigned int random;
    double tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=double_st(a);
    else {
      if ( 3*a < ( b.x + b.y + b.z ))
	res=double_st(a);
      else
	res=b;
    }
    return res;
  }
double_st fmin(const unsigned int & a, const double_st& b){
    double_st res;

    unsigned int random;
    double tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=double_st(a);
    else {
      if ( 3*a < ( b.x + b.y + b.z ))
	res=double_st(a);
      else
	res=b;
    }
    return res;
  }
double_st fmin(const int & a, const double_st& b){
    double_st res;

    unsigned int random;
    double tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=double_st(a);
    else {
      if ( 3*a < ( b.x + b.y + b.z ))
	res=double_st(a);
      else
	res=b;
    }
    return res;
  }
double_st fmin(const unsigned short& a, const double_st& b){
    double_st res;

    unsigned int random;
    double tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=double_st(a);
    else {
      if ( 3*a < ( b.x + b.y + b.z ))
	res=double_st(a);
      else
	res=b;
    }
    return res;
  }
double_st fmin(const short& a, const double_st& b){
    double_st res;

    unsigned int random;
    double tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=double_st(a);
    else {
      if ( 3*a < ( b.x + b.y + b.z ))
	res=double_st(a);
      else
	res=b;
    }
    return res;
  }
double_st fmin(const unsigned char& a, const double_st& b){
    double_st res;

    unsigned int random;
    double tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=double_st(a);
    else {
      if ( 3*a < ( b.x + b.y + b.z ))
	res=double_st(a);
      else
	res=b;
    }
    return res;
  }
double_st fmin(const char& a, const double_st& b){
    double_st res;

    unsigned int random;
    double tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=double_st(a);
    else {
      if ( 3*a < ( b.x + b.y + b.z ))
	res=double_st(a);
      else
	res=b;
    }
    return res;
  }

float_st fminf(const double& a, const float_st& b){
    float_st res;

    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(a);
    else {
      if ( 3*a < ( b.x + b.y + b.z ))
	res=float_st(a);
      else
	res=b;
    }
    return res;
  }
float_st fminf(const float& a, const float_st& b){
    float_st res;

    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(a);
    else {
      if ( 3*a < ( b.x + b.y + b.z ))
	res=float_st(a);
      else
	res=b;
    }
    return res;
  }
float_st fminf(const unsigned long long& a, const float_st& b){
    float_st res;

    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(a);
    else {
      if ( 3*a < ( b.x + b.y + b.z ))
	res=float_st(a);
      else
	res=b;
    }
    return res;
  }
float_st fminf(const long long& a, const float_st& b){
    float_st res;

    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(a);
    else {
      if ( 3*a < ( b.x + b.y + b.z ))
	res=float_st(a);
      else
	res=b;
    }
    return res;
  }
float_st fminf(const unsigned long& a, const float_st& b){
    float_st res;

    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(a);
    else {
      if ( 3*a < ( b.x + b.y + b.z ))
	res=float_st(a);
      else
	res=b;
    }
    return res;
  }
float_st fminf(const long& a, const float_st& b){
    float_st res;

    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(a);
    else {
      if ( 3*a < ( b.x + b.y + b.z ))
	res=float_st(a);
      else
	res=b;
    }
    return res;
  }
float_st fminf(const unsigned int & a, const float_st& b){
    float_st res;

    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(a);
    else {
      if ( 3*a < ( b.x + b.y + b.z ))
	res=float_st(a);
      else
	res=b;
    }
    return res;
  }
float_st fminf(const int & a, const float_st& b){
    float_st res;

    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(a);
    else {
      if ( 3*a < ( b.x + b.y + b.z ))
	res=float_st(a);
      else
	res=b;
    }
    return res;
  }
float_st fminf(const unsigned short& a, const float_st& b){
    float_st res;

    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(a);
    else {
      if ( 3*a < ( b.x + b.y + b.z ))
	res=float_st(a);
      else
	res=b;
    }
    return res;
  }
float_st fminf(const short& a, const float_st& b){
    float_st res;

    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(a);
    else {
      if ( 3*a < ( b.x + b.y + b.z ))
	res=float_st(a);
      else
	res=b;
    }
    return res;
  }
float_st fminf(const unsigned char& a, const float_st& b){
    float_st res;

    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(a);
    else {
      if ( 3*a < ( b.x + b.y + b.z ))
	res=float_st(a);
      else
	res=b;
    }
    return res;
  }
float_st fminf(const char& a, const float_st& b){
    float_st res;

    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(a);
    else {
      if ( 3*a < ( b.x + b.y + b.z ))
	res=float_st(a);
      else
	res=b;
    }
    return res;
  }

float_st fmin(const double& a, const float_st& b){
    float_st res;

    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(a);
    else {
      if ( 3*a < ( b.x + b.y + b.z ))
	res=float_st(a);
      else
	res=b;
    }
    return res;
  }
float_st fmin(const float& a, const float_st& b){
    float_st res;

    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(a);
    else {
      if ( 3*a < ( b.x + b.y + b.z ))
	res=float_st(a);
      else
	res=b;
    }
    return res;
  }
float_st fmin(const unsigned long long& a, const float_st& b){
    float_st res;

    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(a);
    else {
      if ( 3*a < ( b.x + b.y + b.z ))
	res=float_st(a);
      else
	res=b;
    }
    return res;
  }
float_st fmin(const long long& a, const float_st& b){
    float_st res;

    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(a);
    else {
      if ( 3*a < ( b.x + b.y + b.z ))
	res=float_st(a);
      else
	res=b;
    }
    return res;
  }
float_st fmin(const unsigned long& a, const float_st& b){
    float_st res;

    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(a);
    else {
      if ( 3*a < ( b.x + b.y + b.z ))
	res=float_st(a);
      else
	res=b;
    }
    return res;
  }
float_st fmin(const long& a, const float_st& b){
    float_st res;

    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(a);
    else {
      if ( 3*a < ( b.x + b.y + b.z ))
	res=float_st(a);
      else
	res=b;
    }
    return res;
  }
float_st fmin(const unsigned int & a, const float_st& b){
    float_st res;

    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(a);
    else {
      if ( 3*a < ( b.x + b.y + b.z ))
	res=float_st(a);
      else
	res=b;
    }
    return res;
  }
float_st fmin(const int & a, const float_st& b){
    float_st res;

    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(a);
    else {
      if ( 3*a < ( b.x + b.y + b.z ))
	res=float_st(a);
      else
	res=b;
    }
    return res;
  }
float_st fmin(const unsigned short& a, const float_st& b){
    float_st res;

    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(a);
    else {
      if ( 3*a < ( b.x + b.y + b.z ))
	res=float_st(a);
      else
	res=b;
    }
    return res;
  }
float_st fmin(const short& a, const float_st& b){
    float_st res;

    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(a);
    else {
      if ( 3*a < ( b.x + b.y + b.z ))
	res=float_st(a);
      else
	res=b;
    }
    return res;
  }
float_st fmin(const unsigned char& a, const float_st& b){
    float_st res;

    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(a);
    else {
      if ( 3*a < ( b.x + b.y + b.z ))
	res=float_st(a);
      else
	res=b;
    }
    return res;
  }
float_st fmin(const char& a, const float_st& b){
    float_st res;

    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(a);
    else {
      if ( 3*a < ( b.x + b.y + b.z ))
	res=float_st(a);
      else
	res=b;
    }
    return res;
  }




double_st fmin(const double_st& a, const double& b){
    double_st res;
    unsigned int random;
    double tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=double_st(b);
    else {
      if ( ( a.x + a.y + a.z ) < 3*b )
	res=a;
      else
	res=double_st(b);
    }
    return res;
  }
double_st fmin(const double_st& a, const float& b){
    double_st res;
    unsigned int random;
    double tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=double_st(b);
    else {
      if ( ( a.x + a.y + a.z ) < 3*b )
	res=a;
      else
	res=double_st(b);
    }
    return res;
  }
double_st fmin(const double_st& a, const unsigned long long& b){
    double_st res;
    unsigned int random;
    double tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=double_st(b);
    else {
      if ( ( a.x + a.y + a.z ) < 3*b )
	res=a;
      else
	res=double_st(b);
    }
    return res;
  }
double_st fmin(const double_st& a, const long long& b){
    double_st res;
    unsigned int random;
    double tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=double_st(b);
    else {
      if ( ( a.x + a.y + a.z ) < 3*b )
	res=a;
      else
	res=double_st(b);
    }
    return res;
  }
double_st fmin(const double_st& a, const unsigned long& b){
    double_st res;
    unsigned int random;
    double tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=double_st(b);
    else {
      if ( ( a.x + a.y + a.z ) < 3*b )
	res=a;
      else
	res=double_st(b);
    }
    return res;
  }
double_st fmin(const double_st& a, const long& b){
    double_st res;
    unsigned int random;
    double tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=double_st(b);
    else {
      if ( ( a.x + a.y + a.z ) < 3*b )
	res=a;
      else
	res=double_st(b);
    }
    return res;
  }
double_st fmin(const double_st& a, const unsigned int & b){
    double_st res;
    unsigned int random;
    double tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=double_st(b);
    else {
      if ( ( a.x + a.y + a.z ) < 3*b )
	res=a;
      else
	res=double_st(b);
    }
    return res;
  }
double_st fmin(const double_st& a, const int & b){
    double_st res;
    unsigned int random;
    double tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=double_st(b);
    else {
      if ( ( a.x + a.y + a.z ) < 3*b )
	res=a;
      else
	res=double_st(b);
    }
    return res;
  }
double_st fmin(const double_st& a, const unsigned short& b){
    double_st res;
    unsigned int random;
    double tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=double_st(b);
    else {
      if ( ( a.x + a.y + a.z ) < 3*b )
	res=a;
      else
	res=double_st(b);
    }
    return res;
  }
double_st fmin(const double_st& a, const short& b){
    double_st res;
    unsigned int random;
    double tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=double_st(b);
    else {
      if ( ( a.x + a.y + a.z ) < 3*b )
	res=a;
      else
	res=double_st(b);
    }
    return res;
  }
double_st fmin(const double_st& a, const unsigned char& b){
    double_st res;
    unsigned int random;
    double tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=double_st(b);
    else {
      if ( ( a.x + a.y + a.z ) < 3*b )
	res=a;
      else
	res=double_st(b);
    }
    return res;
  }
double_st fmin(const double_st& a, const char& b){
    double_st res;
    unsigned int random;
    double tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=double_st(b);
    else {
      if ( ( a.x + a.y + a.z ) < 3*b )
	res=a;
      else
	res=double_st(b);
    }
    return res;
  }

float_st fminf(const float_st& a, const double& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(b);
    else {
      if ( ( a.x + a.y + a.z ) < 3*b )
	res=a;
      else
	res=float_st(b);
    }
    return res;
  }
float_st fminf(const float_st& a, const float& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(b);
    else {
      if ( ( a.x + a.y + a.z ) < 3*b )
	res=a;
      else
	res=float_st(b);
    }
    return res;
  }
float_st fminf(const float_st& a, const unsigned long long& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(b);
    else {
      if ( ( a.x + a.y + a.z ) < 3*b )
	res=a;
      else
	res=float_st(b);
    }
    return res;
  }
float_st fminf(const float_st& a, const long long& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(b);
    else {
      if ( ( a.x + a.y + a.z ) < 3*b )
	res=a;
      else
	res=float_st(b);
    }
    return res;
  }
float_st fminf(const float_st& a, const unsigned long& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(b);
    else {
      if ( ( a.x + a.y + a.z ) < 3*b )
	res=a;
      else
	res=float_st(b);
    }
    return res;
  }
float_st fminf(const float_st& a, const long& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(b);
    else {
      if ( ( a.x + a.y + a.z ) < 3*b )
	res=a;
      else
	res=float_st(b);
    }
    return res;
  }
float_st fminf(const float_st& a, const unsigned int & b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(b);
    else {
      if ( ( a.x + a.y + a.z ) < 3*b )
	res=a;
      else
	res=float_st(b);
    }
    return res;
  }
float_st fminf(const float_st& a, const int & b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(b);
    else {
      if ( ( a.x + a.y + a.z ) < 3*b )
	res=a;
      else
	res=float_st(b);
    }
    return res;
  }
float_st fminf(const float_st& a, const unsigned short& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(b);
    else {
      if ( ( a.x + a.y + a.z ) < 3*b )
	res=a;
      else
	res=float_st(b);
    }
    return res;
  }
float_st fminf(const float_st& a, const short& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(b);
    else {
      if ( ( a.x + a.y + a.z ) < 3*b )
	res=a;
      else
	res=float_st(b);
    }
    return res;
  }
float_st fminf(const float_st& a, const unsigned char& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(b);
    else {
      if ( ( a.x + a.y + a.z ) < 3*b )
	res=a;
      else
	res=float_st(b);
    }
    return res;
  }
float_st fminf(const float_st& a, const char& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(b);
    else {
      if ( ( a.x + a.y + a.z ) < 3*b )
	res=a;
      else
	res=float_st(b);
    }
    return res;
  }

float_st fmin(const float_st& a, const double& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(b);
    else {
      if ( ( a.x + a.y + a.z ) < 3*b )
	res=a;
      else
	res=float_st(b);
    }
    return res;
  }
float_st fmin(const float_st& a, const float& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(b);
    else {
      if ( ( a.x + a.y + a.z ) < 3*b )
	res=a;
      else
	res=float_st(b);
    }
    return res;
  }
float_st fmin(const float_st& a, const unsigned long long& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(b);
    else {
      if ( ( a.x + a.y + a.z ) < 3*b )
	res=a;
      else
	res=float_st(b);
    }
    return res;
  }
float_st fmin(const float_st& a, const long long& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(b);
    else {
      if ( ( a.x + a.y + a.z ) < 3*b )
	res=a;
      else
	res=float_st(b);
    }
    return res;
  }
float_st fmin(const float_st& a, const unsigned long& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(b);
    else {
      if ( ( a.x + a.y + a.z ) < 3*b )
	res=a;
      else
	res=float_st(b);
    }
    return res;
  }
float_st fmin(const float_st& a, const long& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(b);
    else {
      if ( ( a.x + a.y + a.z ) < 3*b )
	res=a;
      else
	res=float_st(b);
    }
    return res;
  }
float_st fmin(const float_st& a, const unsigned int & b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(b);
    else {
      if ( ( a.x + a.y + a.z ) < 3*b )
	res=a;
      else
	res=float_st(b);
    }
    return res;
  }
float_st fmin(const float_st& a, const int & b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(b);
    else {
      if ( ( a.x + a.y + a.z ) < 3*b )
	res=a;
      else
	res=float_st(b);
    }
    return res;
  }
float_st fmin(const float_st& a, const unsigned short& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(b);
    else {
      if ( ( a.x + a.y + a.z ) < 3*b )
	res=a;
      else
	res=float_st(b);
    }
    return res;
  }
float_st fmin(const float_st& a, const short& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(b);
    else {
      if ( ( a.x + a.y + a.z ) < 3*b )
	res=a;
      else
	res=float_st(b);
    }
    return res;
  }
float_st fmin(const float_st& a, const unsigned char& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(b);
    else {
      if ( ( a.x + a.y + a.z ) < 3*b )
	res=a;
      else
	res=float_st(b);
    }
    return res;
  }
float_st fmin(const float_st& a, const char& b){
    float_st res;
    unsigned int random;
    float tmp;

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

    int r=res.numericalnoise();

    if (_cadna_branching_tag && r)
      instability(&_cadna_branching_count);

    if (r) res=float_st(b);
    else {
      if ( ( a.x + a.y + a.z ) < 3*b )
	res=a;
      else
	res=float_st(b);
    }
    return res;
  }




double_st fmin(const double_st& a, const double_st& b){
  double_st res;
  unsigned int random;
  double tmp;

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

  int r=res.numericalnoise();

  if (_cadna_branching_tag && r)
    instability(&_cadna_branching_count);

  if (r){
    if (a.accuracy==DIGIT_NOT_COMPUTED || a.accuracy==RELIABLE_RESULT)
      a.nb_significant_digit();
    if (b.accuracy==DIGIT_NOT_COMPUTED || b.accuracy==RELIABLE_RESULT)
      b.nb_significant_digit();
    if (a.accuracy > b.accuracy )
	res=a;
	else
	  res=b;
	}
    else {
      if ( ( a.x + a.y + a.z ) <	( b.x + b.y + b.z ))
	res=a;
      else
	res=b;
    }
    return res;
  }
double_st fmin(const double_st& a, const float_st& b){
  double_st res;
  unsigned int random;
  double tmp;

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

  int r=res.numericalnoise();

  if (_cadna_branching_tag && r)
    instability(&_cadna_branching_count);

  if (r){
    if (a.accuracy==DIGIT_NOT_COMPUTED || a.accuracy==RELIABLE_RESULT)
      a.nb_significant_digit();
    if (b.accuracy==DIGIT_NOT_COMPUTED || b.accuracy==RELIABLE_RESULT)
      b.nb_significant_digit();
    if (a.accuracy > b.accuracy )
	res=a;
	else
	  res=b;
	}
    else {
      if ( ( a.x + a.y + a.z ) <	( b.x + b.y + b.z ))
	res=a;
      else
	res=b;
    }
    return res;
  }
double_st fmin(const float_st& a, const double_st& b){
  double_st res;
  unsigned int random;
  double tmp;

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

  int r=res.numericalnoise();

  if (_cadna_branching_tag && r)
    instability(&_cadna_branching_count);

  if (r){
    if (a.accuracy==DIGIT_NOT_COMPUTED || a.accuracy==RELIABLE_RESULT)
      a.nb_significant_digit();
    if (b.accuracy==DIGIT_NOT_COMPUTED || b.accuracy==RELIABLE_RESULT)
      b.nb_significant_digit();
    if (a.accuracy > b.accuracy )
	res=a;
	else
	  res=b;
	}
    else {
      if ( ( a.x + a.y + a.z ) <	( b.x + b.y + b.z ))
	res=a;
      else
	res=b;
    }
    return res;
  }
float_st fminf(const float_st& a, const float_st& b){
  float_st res;
  unsigned int random;
  float tmp;

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

  int r=res.numericalnoise();

  if (_cadna_branching_tag && r)
    instability(&_cadna_branching_count);

  if (r){
    if (a.accuracy==DIGIT_NOT_COMPUTED || a.accuracy==RELIABLE_RESULT)
      a.nb_significant_digit();
    if (b.accuracy==DIGIT_NOT_COMPUTED || b.accuracy==RELIABLE_RESULT)
      b.nb_significant_digit();
    if (a.accuracy > b.accuracy )
	res=a;
	else
	  res=b;
	}
    else {
      if ( ( a.x + a.y + a.z ) <	( b.x + b.y + b.z ))
	res=a;
      else
	res=b;
    }
    return res;
  }
float_st fmin(const float_st& a, const float_st& b){
  float_st res;
  unsigned int random;
  float tmp;

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

  int r=res.numericalnoise();

  if (_cadna_branching_tag && r)
    instability(&_cadna_branching_count);

  if (r){
    if (a.accuracy==DIGIT_NOT_COMPUTED || a.accuracy==RELIABLE_RESULT)
      a.nb_significant_digit();
    if (b.accuracy==DIGIT_NOT_COMPUTED || b.accuracy==RELIABLE_RESULT)
      b.nb_significant_digit();
    if (a.accuracy > b.accuracy )
	res=a;
	else
	  res=b;
	}
    else {
      if ( ( a.x + a.y + a.z ) <	( b.x + b.y + b.z ))
	res=a;
      else
	res=b;
    }
    return res;
  }

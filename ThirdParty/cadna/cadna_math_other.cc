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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==pow((double)a,(double)b.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==pow((double)a,(double)b.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==pow((double)a,(double)b.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==pow((double)a,(double)b.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==pow((double)a,(double)b.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==pow((double)a,(double)b.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==pow((double)a,(double)b.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==pow((double)a,(double)b.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==pow((double)a,(double)b.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==pow((double)a,(double)b.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==pow((double)a,(double)b.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==pow((double)a,(double)b.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==pow((double)a,(double)b.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==pow((double)a,(double)b.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==pow((double)a,(double)b.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==pow((double)a,(double)b.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==pow((double)a,(double)b.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==pow((double)a,(double)b.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==pow((double)a,(double)b.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==pow((double)a,(double)b.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==pow((double)a,(double)b.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==pow((double)a,(double)b.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==pow((double)a,(double)b.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==pow((double)a,(double)b.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==pow((double)a,(double)b.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==pow((double)a,(double)b.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==pow((double)a,(double)b.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==pow((double)a,(double)b.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==pow((double)a,(double)b.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==pow((double)a,(double)b.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==pow((double)a,(double)b.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==pow((double)a,(double)b.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==pow((double)a,(double)b.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==pow((double)a,(double)b.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==pow((double)a,(double)b.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==pow((double)a,(double)b.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==powf((float)a,(float)b.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==powf((float)a,(float)b.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==powf((float)a,(float)b.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==powf((float)a,(float)b.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==powf((float)a,(float)b.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==powf((float)a,(float)b.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==powf((float)a,(float)b.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==powf((float)a,(float)b.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==powf((float)a,(float)b.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==powf((float)a,(float)b.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==powf((float)a,(float)b.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==powf((float)a,(float)b.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==powf((float)a,(float)b.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==powf((float)a,(float)b.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==powf((float)a,(float)b.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==powf((float)a,(float)b.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==powf((float)a,(float)b.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==powf((float)a,(float)b.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==powf((float)a,(float)b.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==powf((float)a,(float)b.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==powf((float)a,(float)b.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==powf((float)a,(float)b.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==powf((float)a,(float)b.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==powf((float)a,(float)b.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==powf((float)a,(float)b.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==powf((float)a,(float)b.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==powf((float)a,(float)b.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==powf((float)a,(float)b.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==powf((float)a,(float)b.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==powf((float)a,(float)b.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==powf((float)a,(float)b.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==powf((float)a,(float)b.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==powf((float)a,(float)b.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==powf((float)a,(float)b.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==powf((float)a,(float)b.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==powf((float)a,(float)b.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==pow((double)a,(double)b.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==pow((double)a,(double)b.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==pow((double)a,(double)b.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==pow((double)a,(double)b.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==pow((double)a,(double)b.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==pow((double)a,(double)b.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==pow((double)a,(double)b.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==pow((double)a,(double)b.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==pow((double)a,(double)b.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==pow((double)a,(double)b.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==pow((double)a,(double)b.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==pow((double)a,(double)b.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==pow((double)a,(double)b.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==pow((double)a,(double)b.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==pow((double)a,(double)b.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==pow((double)a,(double)b.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==pow((double)a,(double)b.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==pow((double)a,(double)b.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==pow((double)a,(double)b.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==pow((double)a,(double)b.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==pow((double)a,(double)b.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==pow((double)a,(double)b.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==pow((double)a,(double)b.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==pow((double)a,(double)b.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==pow((double)a,(double)b.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==pow((double)a,(double)b.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==pow((double)a,(double)b.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==pow((double)a,(double)b.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==pow((double)a,(double)b.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==pow((double)a,(double)b.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==pow((double)a,(double)b.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==pow((double)a,(double)b.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==pow((double)a,(double)b.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==pow((double)a,(double)b.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==pow((double)a,(double)b.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==pow((double)a,(double)b.z);
fesetround(FE_UPWARD);

    return res;
  }







double_st pow(const double_st& a, const double& b){
    double_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==pow((double)a.x, (double)b);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==pow((double)a.y, (double)b);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==pow((double)a.z, (double)b);
fesetround(FE_UPWARD);

    return res;
  }
double_st pow(const double_st& a, const float& b){
    double_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==pow((double)a.x, (double)b);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==pow((double)a.y, (double)b);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==pow((double)a.z, (double)b);
fesetround(FE_UPWARD);

    return res;
  }
double_st pow(const double_st& a, const unsigned long long& b){
    double_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==pow((double)a.x, (double)b);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==pow((double)a.y, (double)b);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==pow((double)a.z, (double)b);
fesetround(FE_UPWARD);

    return res;
  }
double_st pow(const double_st& a, const long long& b){
    double_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==pow((double)a.x, (double)b);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==pow((double)a.y, (double)b);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==pow((double)a.z, (double)b);
fesetround(FE_UPWARD);

    return res;
  }
double_st pow(const double_st& a, const unsigned long& b){
    double_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==pow((double)a.x, (double)b);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==pow((double)a.y, (double)b);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==pow((double)a.z, (double)b);
fesetround(FE_UPWARD);

    return res;
  }
double_st pow(const double_st& a, const long& b){
    double_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==pow((double)a.x, (double)b);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==pow((double)a.y, (double)b);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==pow((double)a.z, (double)b);
fesetround(FE_UPWARD);

    return res;
  }
double_st pow(const double_st& a, const unsigned int & b){
    double_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==pow((double)a.x, (double)b);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==pow((double)a.y, (double)b);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==pow((double)a.z, (double)b);
fesetround(FE_UPWARD);

    return res;
  }
double_st pow(const double_st& a, const int & b){
    double_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==pow((double)a.x, (double)b);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==pow((double)a.y, (double)b);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==pow((double)a.z, (double)b);
fesetround(FE_UPWARD);

    return res;
  }
double_st pow(const double_st& a, const unsigned short& b){
    double_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==pow((double)a.x, (double)b);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==pow((double)a.y, (double)b);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==pow((double)a.z, (double)b);
fesetround(FE_UPWARD);

    return res;
  }
double_st pow(const double_st& a, const short& b){
    double_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==pow((double)a.x, (double)b);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==pow((double)a.y, (double)b);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==pow((double)a.z, (double)b);
fesetround(FE_UPWARD);

    return res;
  }
double_st pow(const double_st& a, const unsigned char& b){
    double_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==pow((double)a.x, (double)b);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==pow((double)a.y, (double)b);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==pow((double)a.z, (double)b);
fesetround(FE_UPWARD);

    return res;
  }
double_st pow(const double_st& a, const char& b){
    double_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==pow((double)a.x, (double)b);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==pow((double)a.y, (double)b);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==pow((double)a.z, (double)b);
fesetround(FE_UPWARD);

    return res;
  }

float_st powf(const float_st& a, const double& b){
    float_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==powf((float)a.x, (float)b);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==powf((float)a.y, (float)b);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==powf((float)a.z, (float)b);
fesetround(FE_UPWARD);

    return res;
  }
float_st powf(const float_st& a, const float& b){
    float_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==powf((float)a.x, (float)b);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==powf((float)a.y, (float)b);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==powf((float)a.z, (float)b);
fesetround(FE_UPWARD);

    return res;
  }
float_st powf(const float_st& a, const unsigned long long& b){
    float_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==powf((float)a.x, (float)b);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==powf((float)a.y, (float)b);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==powf((float)a.z, (float)b);
fesetround(FE_UPWARD);

    return res;
  }
float_st powf(const float_st& a, const long long& b){
    float_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==powf((float)a.x, (float)b);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==powf((float)a.y, (float)b);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==powf((float)a.z, (float)b);
fesetround(FE_UPWARD);

    return res;
  }
float_st powf(const float_st& a, const unsigned long& b){
    float_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==powf((float)a.x, (float)b);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==powf((float)a.y, (float)b);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==powf((float)a.z, (float)b);
fesetround(FE_UPWARD);

    return res;
  }
float_st powf(const float_st& a, const long& b){
    float_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==powf((float)a.x, (float)b);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==powf((float)a.y, (float)b);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==powf((float)a.z, (float)b);
fesetround(FE_UPWARD);

    return res;
  }
float_st powf(const float_st& a, const unsigned int & b){
    float_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==powf((float)a.x, (float)b);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==powf((float)a.y, (float)b);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==powf((float)a.z, (float)b);
fesetround(FE_UPWARD);

    return res;
  }
float_st powf(const float_st& a, const int & b){
    float_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==powf((float)a.x, (float)b);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==powf((float)a.y, (float)b);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==powf((float)a.z, (float)b);
fesetround(FE_UPWARD);

    return res;
  }
float_st powf(const float_st& a, const unsigned short& b){
    float_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==powf((float)a.x, (float)b);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==powf((float)a.y, (float)b);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==powf((float)a.z, (float)b);
fesetround(FE_UPWARD);

    return res;
  }
float_st powf(const float_st& a, const short& b){
    float_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==powf((float)a.x, (float)b);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==powf((float)a.y, (float)b);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==powf((float)a.z, (float)b);
fesetround(FE_UPWARD);

    return res;
  }
float_st powf(const float_st& a, const unsigned char& b){
    float_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==powf((float)a.x, (float)b);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==powf((float)a.y, (float)b);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==powf((float)a.z, (float)b);
fesetround(FE_UPWARD);

    return res;
  }
float_st powf(const float_st& a, const char& b){
    float_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==powf((float)a.x, (float)b);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==powf((float)a.y, (float)b);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==powf((float)a.z, (float)b);
fesetround(FE_UPWARD);

    return res;
  }


float_st pow(const float_st& a, const double& b){
    float_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==pow((double)a.x, (double)b);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==pow((double)a.y, (double)b);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==pow((double)a.z, (double)b);
fesetround(FE_UPWARD);

    return res;
  }
float_st pow(const float_st& a, const float& b){
    float_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==pow((double)a.x, (double)b);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==pow((double)a.y, (double)b);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==pow((double)a.z, (double)b);
fesetround(FE_UPWARD);

    return res;
  }
float_st pow(const float_st& a, const unsigned long long& b){
    float_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==pow((double)a.x, (double)b);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==pow((double)a.y, (double)b);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==pow((double)a.z, (double)b);
fesetround(FE_UPWARD);

    return res;
  }
float_st pow(const float_st& a, const long long& b){
    float_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==pow((double)a.x, (double)b);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==pow((double)a.y, (double)b);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==pow((double)a.z, (double)b);
fesetround(FE_UPWARD);

    return res;
  }
float_st pow(const float_st& a, const unsigned long& b){
    float_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==pow((double)a.x, (double)b);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==pow((double)a.y, (double)b);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==pow((double)a.z, (double)b);
fesetround(FE_UPWARD);

    return res;
  }
float_st pow(const float_st& a, const long& b){
    float_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==pow((double)a.x, (double)b);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==pow((double)a.y, (double)b);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==pow((double)a.z, (double)b);
fesetround(FE_UPWARD);

    return res;
  }
float_st pow(const float_st& a, const unsigned int & b){
    float_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==pow((double)a.x, (double)b);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==pow((double)a.y, (double)b);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==pow((double)a.z, (double)b);
fesetround(FE_UPWARD);

    return res;
  }
float_st pow(const float_st& a, const int & b){
    float_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==pow((double)a.x, (double)b);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==pow((double)a.y, (double)b);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==pow((double)a.z, (double)b);
fesetround(FE_UPWARD);

    return res;
  }
float_st pow(const float_st& a, const unsigned short& b){
    float_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==pow((double)a.x, (double)b);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==pow((double)a.y, (double)b);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==pow((double)a.z, (double)b);
fesetround(FE_UPWARD);

    return res;
  }
float_st pow(const float_st& a, const short& b){
    float_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==pow((double)a.x, (double)b);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==pow((double)a.y, (double)b);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==pow((double)a.z, (double)b);
fesetround(FE_UPWARD);

    return res;
  }
float_st pow(const float_st& a, const unsigned char& b){
    float_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==pow((double)a.x, (double)b);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==pow((double)a.y, (double)b);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==pow((double)a.z, (double)b);
fesetround(FE_UPWARD);

    return res;
  }
float_st pow(const float_st& a, const char& b){
    float_st res;

    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==pow((double)a.x, (double)b);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==pow((double)a.y, (double)b);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==pow((double)a.z, (double)b);
fesetround(FE_UPWARD);

    return res;
  }


/////////////////////////////////////////////////////////////////////////





double_st pow(const double_st& a, const double_st& b){
    double_st res;
    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (b.accuracy==DIGIT_NOT_COMPUTED) b.approx_digit();
      if (a.accuracy==0 || b.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==pow((double)a.x, (double)b.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==pow((double)a.y, (double)b.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==pow((double)a.z, (double)b.z);
fesetround(FE_UPWARD);

    return res;
  }
double_st pow(const double_st& a, const float_st& b){
    double_st res;
    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (b.accuracy==DIGIT_NOT_COMPUTED) b.approx_digit();
      if (a.accuracy==0 || b.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==pow((double)a.x, (double)b.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==pow((double)a.y, (double)b.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==pow((double)a.z, (double)b.z);
fesetround(FE_UPWARD);

    return res;
  }
double_st pow(const float_st& a, const double_st& b){
    double_st res;
    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (b.accuracy==DIGIT_NOT_COMPUTED) b.approx_digit();
      if (a.accuracy==0 || b.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==pow((double)a.x, (double)b.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==pow((double)a.y, (double)b.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==pow((double)a.z, (double)b.z);
fesetround(FE_UPWARD);

    return res;
  }
float_st powf(const float_st& a, const float_st& b){
    float_st res;
    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (b.accuracy==DIGIT_NOT_COMPUTED) b.approx_digit();
      if (a.accuracy==0 || b.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==powf((float)a.x, (float)b.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==powf((float)a.y, (float)b.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==powf((float)a.z, (float)b.z);
fesetround(FE_UPWARD);

    return res;
  }
float_st pow(const float_st& a, const float_st& b){
    float_st res;
    if(_cadna_power_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (b.accuracy==DIGIT_NOT_COMPUTED) b.approx_digit();
      if (a.accuracy==0 || b.accuracy==0) instability(&_cadna_power_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==pow((double)a.x, (double)b.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==pow((double)a.y, (double)b.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==pow((double)a.z, (double)b.z);
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






double_st log(const double_st& a){
    double_st res;

    if(_cadna_math_tag!=0 ){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==log((double_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==log((double_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==log((double_st::TYPEBASE)a.z);
fesetround(FE_UPWARD);

    return res;
  };
float_st log(const float_st& a){
    float_st res;

    if(_cadna_math_tag!=0 ){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==log((float_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==log((float_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==log((float_st::TYPEBASE)a.z);
fesetround(FE_UPWARD);

    return res;
  };
float_st logf(const float_st& a){
    float_st res;

    if(_cadna_math_tag!=0 ){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==logf((float_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==logf((float_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==logf((float_st::TYPEBASE)a.z);
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






double_st log2(const double_st& a){
    double_st res;

    if(_cadna_math_tag!=0 ){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==log2((double_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==log2((double_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==log2((double_st::TYPEBASE)a.z);
fesetround(FE_UPWARD);

    return res;
  };
float_st log2(const float_st& a){
    float_st res;

    if(_cadna_math_tag!=0 ){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==log2((float_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==log2((float_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==log2((float_st::TYPEBASE)a.z);
fesetround(FE_UPWARD);

    return res;
  };
float_st log2f(const float_st& a){
    float_st res;

    if(_cadna_math_tag!=0 ){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==log2f((float_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==log2f((float_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==log2f((float_st::TYPEBASE)a.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==log10((double_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==log10((double_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==log10((double_st::TYPEBASE)a.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==log10((float_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==log10((float_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==log10((float_st::TYPEBASE)a.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==log10f((float_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==log10f((float_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==log10f((float_st::TYPEBASE)a.z);
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






double_st log1p(const double_st& a){
    double_st res;

    if(_cadna_math_tag!=0 ){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==log1p((double_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==log1p((double_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==log1p((double_st::TYPEBASE)a.z);
fesetround(FE_UPWARD);

    return res;
  };
float_st log1p(const float_st& a){
    float_st res;

    if(_cadna_math_tag!=0 ){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==log1p((float_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==log1p((float_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==log1p((float_st::TYPEBASE)a.z);
fesetround(FE_UPWARD);

    return res;
  };
float_st log1pf(const float_st& a){
    float_st res;

    if(_cadna_math_tag!=0 ){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==log1pf((float_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==log1pf((float_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==log1pf((float_st::TYPEBASE)a.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==logb((double_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==logb((double_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==logb((double_st::TYPEBASE)a.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==logb((float_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==logb((float_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==logb((float_st::TYPEBASE)a.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==logbf((float_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==logbf((float_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==logbf((float_st::TYPEBASE)a.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==exp((double_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==exp((double_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==exp((double_st::TYPEBASE)a.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==exp((float_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==exp((float_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==exp((float_st::TYPEBASE)a.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==expf((float_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==expf((float_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==expf((float_st::TYPEBASE)a.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==exp2((double_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==exp2((double_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==exp2((double_st::TYPEBASE)a.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==exp2((float_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==exp2((float_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==exp2((float_st::TYPEBASE)a.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==exp2f((float_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==exp2f((float_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==exp2f((float_st::TYPEBASE)a.z);
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






double_st expm1(const double_st& a){
    double_st res;

    if(_cadna_math_tag!=0 ){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==expm1((double_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==expm1((double_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==expm1((double_st::TYPEBASE)a.z);
fesetround(FE_UPWARD);

    return res;
  };
float_st expm1(const float_st& a){
    float_st res;

    if(_cadna_math_tag!=0 ){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==expm1((float_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==expm1((float_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==expm1((float_st::TYPEBASE)a.z);
fesetround(FE_UPWARD);

    return res;
  };
float_st expm1f(const float_st& a){
    float_st res;

    if(_cadna_math_tag!=0 ){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==expm1f((float_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==expm1f((float_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==expm1f((float_st::TYPEBASE)a.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==sqrt((double_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==sqrt((double_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==sqrt((double_st::TYPEBASE)a.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==sqrt((float_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==sqrt((float_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==sqrt((float_st::TYPEBASE)a.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==sqrtf((float_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==sqrtf((float_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==sqrtf((float_st::TYPEBASE)a.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==cbrt((double_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==cbrt((double_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==cbrt((double_st::TYPEBASE)a.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==cbrt((float_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==cbrt((float_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==cbrt((float_st::TYPEBASE)a.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==cbrtf((float_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==cbrtf((float_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==cbrtf((float_st::TYPEBASE)a.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==sin((double_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==sin((double_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==sin((double_st::TYPEBASE)a.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==sin((float_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==sin((float_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==sin((float_st::TYPEBASE)a.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==sinf((float_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==sinf((float_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==sinf((float_st::TYPEBASE)a.z);
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




double_st cos(const double_st& a){
    double_st res;

    if(_cadna_math_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==cos((double_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==cos((double_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==cos((double_st::TYPEBASE)a.z);
fesetround(FE_UPWARD);

    return res;
  };
float_st cos(const float_st& a){
    float_st res;

    if(_cadna_math_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==cos((float_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==cos((float_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==cos((float_st::TYPEBASE)a.z);
fesetround(FE_UPWARD);

    return res;
  };
float_st cosf(const float_st& a){
    float_st res;

    if(_cadna_math_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==cosf((float_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==cosf((float_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==cosf((float_st::TYPEBASE)a.z);
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




double_st tan(const double_st& a){
    double_st res;

    if(_cadna_math_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==tan((double_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==tan((double_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==tan((double_st::TYPEBASE)a.z);
fesetround(FE_UPWARD);

    return res;
  };
float_st tan(const float_st& a){
    float_st res;

    if(_cadna_math_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==tan((float_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==tan((float_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==tan((float_st::TYPEBASE)a.z);
fesetround(FE_UPWARD);

    return res;
  };
float_st tanf(const float_st& a){
    float_st res;

    if(_cadna_math_tag!=0){
      if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
      if (a.accuracy==0) instability(&_cadna_math_count);
    }
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==tanf((float_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==tanf((float_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==tanf((float_st::TYPEBASE)a.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==asin((double_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==asin((double_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==asin((double_st::TYPEBASE)a.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==asin((float_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==asin((float_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==asin((float_st::TYPEBASE)a.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==asinf((float_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==asinf((float_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==asinf((float_st::TYPEBASE)a.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==acos((double_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==acos((double_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==acos((double_st::TYPEBASE)a.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==acos((float_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==acos((float_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==acos((float_st::TYPEBASE)a.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==acosf((float_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==acosf((float_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==acosf((float_st::TYPEBASE)a.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==atan((double_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==atan((double_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==atan((double_st::TYPEBASE)a.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==atan((float_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==atan((float_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==atan((float_st::TYPEBASE)a.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==atanf((float_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==atanf((float_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==atanf((float_st::TYPEBASE)a.z);
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
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==atan2((double_st::TYPEBASE)a.x,(double_st::TYPEBASE)b.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==atan2((double_st::TYPEBASE)a.y,(double_st::TYPEBASE)b.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==atan2((double_st::TYPEBASE)a.z,(double_st::TYPEBASE)b.z);
fesetround(FE_UPWARD);

    return res;
  }
double_st atan2(const double_st& a, const float_st& b){
    double_st res;
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==atan2((double_st::TYPEBASE)a.x,(double_st::TYPEBASE)b.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==atan2((double_st::TYPEBASE)a.y,(double_st::TYPEBASE)b.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==atan2((double_st::TYPEBASE)a.z,(double_st::TYPEBASE)b.z);
fesetround(FE_UPWARD);

    return res;
  }
double_st atan2(const float_st& a, const double_st& b){
    double_st res;
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==atan2((double_st::TYPEBASE)a.x,(double_st::TYPEBASE)b.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==atan2((double_st::TYPEBASE)a.y,(double_st::TYPEBASE)b.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==atan2((double_st::TYPEBASE)a.z,(double_st::TYPEBASE)b.z);
fesetround(FE_UPWARD);

    return res;
  }
float_st atan2f(const float_st& a, const float_st& b){
    float_st res;
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==atan2f((float_st::TYPEBASE)a.x,(float_st::TYPEBASE)b.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==atan2f((float_st::TYPEBASE)a.y,(float_st::TYPEBASE)b.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==atan2f((float_st::TYPEBASE)a.z,(float_st::TYPEBASE)b.z);
fesetround(FE_UPWARD);

    return res;
  }
float_st atan2(const float_st& a, const float_st& b){
    float_st res;
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==atan2((float_st::TYPEBASE)a.x,(float_st::TYPEBASE)b.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==atan2((float_st::TYPEBASE)a.y,(float_st::TYPEBASE)b.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==atan2((float_st::TYPEBASE)a.z,(float_st::TYPEBASE)b.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==sinh((double_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==sinh((double_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==sinh((double_st::TYPEBASE)a.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==sinh((float_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==sinh((float_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==sinh((float_st::TYPEBASE)a.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==sinhf((float_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==sinhf((float_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==sinhf((float_st::TYPEBASE)a.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==cosh((double_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==cosh((double_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==cosh((double_st::TYPEBASE)a.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==cosh((float_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==cosh((float_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==cosh((float_st::TYPEBASE)a.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==coshf((float_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==coshf((float_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==coshf((float_st::TYPEBASE)a.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==tanh((double_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==tanh((double_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==tanh((double_st::TYPEBASE)a.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==tanh((float_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==tanh((float_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==tanh((float_st::TYPEBASE)a.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==tanhf((float_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==tanhf((float_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==tanhf((float_st::TYPEBASE)a.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==asinh((double_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==asinh((double_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==asinh((double_st::TYPEBASE)a.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==asinh((float_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==asinh((float_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==asinh((float_st::TYPEBASE)a.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==asinhf((float_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==asinhf((float_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==asinhf((float_st::TYPEBASE)a.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==acosh((double_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==acosh((double_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==acosh((double_st::TYPEBASE)a.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==acosh((float_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==acosh((float_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==acosh((float_st::TYPEBASE)a.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==acoshf((float_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==acoshf((float_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==acoshf((float_st::TYPEBASE)a.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==atanh((double_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==atanh((double_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==atanh((double_st::TYPEBASE)a.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==atanh((float_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==atanh((float_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==atanh((float_st::TYPEBASE)a.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==atanhf((float_st::TYPEBASE)a.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==atanhf((float_st::TYPEBASE)a.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==atanhf((float_st::TYPEBASE)a.z);
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
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==hypot(a.x,b.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==hypot(a.y,b.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==hypot(a.z,b.z);
fesetround(FE_UPWARD);
    return res;
  }
double_st hypot(const double_st& a, const float_st& b){
    double_st res;
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==hypot(a.x,b.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==hypot(a.y,b.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==hypot(a.z,b.z);
fesetround(FE_UPWARD);
    return res;
  }
double_st hypot(const float_st& a, const double_st& b){
    double_st res;
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==hypot(a.x,b.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==hypot(a.y,b.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==hypot(a.z,b.z);
fesetround(FE_UPWARD);
    return res;
  }
float_st hypotf(const float_st& a, const float_st& b){
    float_st res;
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==hypotf(a.x,b.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==hypotf(a.y,b.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==hypotf(a.z,b.z);
fesetround(FE_UPWARD);
    return res;
  }
float_st hypot(const float_st& a, const float_st& b){
    float_st res;
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==hypot(a.x,b.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==hypot(a.y,b.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==hypot(a.z,b.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==ldexp((double_st::TYPEBASE)a.x, b);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==ldexp((double_st::TYPEBASE)a.y, b);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==ldexp((double_st::TYPEBASE)a.z, b);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==ldexp((float_st::TYPEBASE)a.x, b);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==ldexp((float_st::TYPEBASE)a.y, b);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==ldexp((float_st::TYPEBASE)a.z, b);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==ldexpf((float_st::TYPEBASE)a.x, b);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==ldexpf((float_st::TYPEBASE)a.y, b);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==ldexpf((float_st::TYPEBASE)a.z, b);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==fmod((double_st::TYPEBASE)a.x, (double_st::TYPEBASE)b.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==fmod((double_st::TYPEBASE)a.y, (double_st::TYPEBASE)b.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==fmod((double_st::TYPEBASE)a.z, (double_st::TYPEBASE)b.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==fmod((float_st::TYPEBASE)a.x, (float_st::TYPEBASE)b.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==fmod((float_st::TYPEBASE)a.y, (float_st::TYPEBASE)b.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==fmod((float_st::TYPEBASE)a.z, (float_st::TYPEBASE)b.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==fmodf((float_st::TYPEBASE)a.x, (float_st::TYPEBASE)b.x);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==fmodf((float_st::TYPEBASE)a.y, (float_st::TYPEBASE)b.y);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==fmodf((float_st::TYPEBASE)a.z, (float_st::TYPEBASE)b.z);
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
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==frexp((double_st::TYPEBASE)a.x, b);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==frexp((double_st::TYPEBASE)a.y, &b2);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==frexp((double_st::TYPEBASE)a.z, &b3);
fesetround(FE_UPWARD);

    if(*b != b2 || b2 != b3){
      std::cerr << "CADNA : problem in function frexp with the  integral power of 2 parameter" << std::endl;
    }


    return res;
};
float_st frexp(const float_st& a, int *b){
    float_st res;
    int b2, b3;

    if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
    if (a.accuracy==0) instability(&_cadna_math_count);
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==frexp((float_st::TYPEBASE)a.x, b);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==frexp((float_st::TYPEBASE)a.y, &b2);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==frexp((float_st::TYPEBASE)a.z, &b3);
fesetround(FE_UPWARD);

    if(*b != b2 || b2 != b3){
      std::cerr << "CADNA : problem in function frexp with the  integral power of 2 parameter" << std::endl;
    }


    return res;
};
float_st frexpf(const float_st& a, int *b){
    float_st res;
    int b2, b3;

    if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
    if (a.accuracy==0) instability(&_cadna_math_count);
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.x==frexpf((float_st::TYPEBASE)a.x, b);
    if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
  res.y==frexpf((float_st::TYPEBASE)a.y, &b2);
    fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z==frexpf((float_st::TYPEBASE)a.z, &b3);
fesetround(FE_UPWARD);

    if(*b != b2 || b2 != b3){
      std::cerr << "CADNA : problem in function frexp with the  integral power of 2 parameter" << std::endl;
    }


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
  int b2, b3;

  if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
  if (a.accuracy==0) instability(&_cadna_math_count);
  res.accuracy=DIGIT_NOT_COMPUTED;
  b->accuracy=DIGIT_NOT_COMPUTED;

  if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.x=modf((double_st::TYPEBASE)a.x, &b->x);
  if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.y=modf((double_st::TYPEBASE)a.y, &b->y);
  fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z=modf((double_st::TYPEBASE)a.z, &b->z);
fesetround(FE_UPWARD);

  if(b->x != b->y || b->x != b->z){
    std::cerr << "CADNA : problem in function modf "<< std::endl;
  }

  return res;
};
float_st modff(const float_st& a, float_st*b){
    float_st res;
  int b2, b3;

  if (a.accuracy==DIGIT_NOT_COMPUTED) a.approx_digit();
  if (a.accuracy==0) instability(&_cadna_math_count);
  res.accuracy=DIGIT_NOT_COMPUTED;
  b->accuracy=DIGIT_NOT_COMPUTED;

  if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.x=modff((float_st::TYPEBASE)a.x, &b->x);
  if (RANDOM) fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.y=modff((float_st::TYPEBASE)a.y, &b->y);
  fesetround(fegetround() ^ (FE_UPWARD ^ FE_DOWNWARD));
 res.z=modff((float_st::TYPEBASE)a.z, &b->z);
fesetround(FE_UPWARD);

  if(b->x != b->y || b->x != b->z){
    std::cerr << "CADNA : problem in function modf "<< std::endl;
  }

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



double_st fmax(const double& a, const double_st& b)
  {
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
double_st fmax(const float& a, const double_st& b)
  {
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
double_st fmax(const unsigned long long& a, const double_st& b)
  {
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
double_st fmax(const long long& a, const double_st& b)
  {
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
double_st fmax(const unsigned long& a, const double_st& b)
  {
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
double_st fmax(const long& a, const double_st& b)
  {
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
double_st fmax(const unsigned int & a, const double_st& b)
  {
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
double_st fmax(const int & a, const double_st& b)
  {
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
double_st fmax(const unsigned short& a, const double_st& b)
  {
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
double_st fmax(const short& a, const double_st& b)
  {
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
double_st fmax(const unsigned char& a, const double_st& b)
  {
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
double_st fmax(const char& a, const double_st& b)
  {
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

float_st fmaxf(const double& a, const float_st& b)
  {
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
float_st fmaxf(const float& a, const float_st& b)
  {
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
float_st fmaxf(const unsigned long long& a, const float_st& b)
  {
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
float_st fmaxf(const long long& a, const float_st& b)
  {
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
float_st fmaxf(const unsigned long& a, const float_st& b)
  {
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
float_st fmaxf(const long& a, const float_st& b)
  {
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
float_st fmaxf(const unsigned int & a, const float_st& b)
  {
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
float_st fmaxf(const int & a, const float_st& b)
  {
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
float_st fmaxf(const unsigned short& a, const float_st& b)
  {
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
float_st fmaxf(const short& a, const float_st& b)
  {
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
float_st fmaxf(const unsigned char& a, const float_st& b)
  {
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
float_st fmaxf(const char& a, const float_st& b)
  {
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

float_st fmax(const double& a, const float_st& b)
  {
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
float_st fmax(const float& a, const float_st& b)
  {
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
float_st fmax(const unsigned long long& a, const float_st& b)
  {
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
float_st fmax(const long long& a, const float_st& b)
  {
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
float_st fmax(const unsigned long& a, const float_st& b)
  {
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
float_st fmax(const long& a, const float_st& b)
  {
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
float_st fmax(const unsigned int & a, const float_st& b)
  {
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
float_st fmax(const int & a, const float_st& b)
  {
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
float_st fmax(const unsigned short& a, const float_st& b)
  {
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
float_st fmax(const short& a, const float_st& b)
  {
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
float_st fmax(const unsigned char& a, const float_st& b)
  {
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
float_st fmax(const char& a, const float_st& b)
  {
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

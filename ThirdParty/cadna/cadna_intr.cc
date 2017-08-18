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


#include <math.h>
#include "cadna_private.h"



////////////////////////////////////


//****f* cadna_intr/fabs
//    NAME
//      fabs
//
//    SYNOPSIS
//      res = fabs(x)
//
//    FUNCTION
//       The fabs() functions compute the absolute value of a
//       stochastic number x.
//
//    INPUTS
//      a           - double_st
//    RESULT
//      res         - double_st
//    SEE ALSO
//      abs(3), ceil(3), floor(3), rint(3)
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
//
//  /

//****f* cadna_intr/fabsf
//    NAME
//      fabsf
//
//    SYNOPSIS
//      res = fabsf(x)
//
//    FUNCTION
//       The fabsf() functions compute the absolute value of a
//       stochastic number x.
//
//    INPUTS
//      a           - float_st
//    RESULT
//      res         - float_st
//    SEE ALSO
//      ceilf(3), floorf(3), rintf(3)
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
//
//  /


double_st fabs(const double_st& a){
   double_st res;
   if(a.x >= 0){
     res.x = a.x;
     if (_cadna_intrinsic_tag)
       if ((a.y<0) || (a.z<0))  instability(&_cadna_intrinsic_count);
   }
   else{
     res.x = -a.x;
     if (_cadna_intrinsic_tag)
       if ((a.y>0) || (a.z>0))  instability(&_cadna_intrinsic_count);
   }
   if(a.y >= 0)
     res.y = a.y;
   else
     res.y = -a.y;
   if(a.z >= 0)
     res.z = a.z;
   else
     res.z = -a.z;
   res.accuracy=DIGIT_NOT_COMPUTED;
   return(res);
}
float_st fabs(const float_st& a){
   float_st res;
   if(a.x >= 0){
     res.x = a.x;
     if (_cadna_intrinsic_tag)
       if ((a.y<0) || (a.z<0))  instability(&_cadna_intrinsic_count);
   }
   else{
     res.x = -a.x;
     if (_cadna_intrinsic_tag)
       if ((a.y>0) || (a.z>0))  instability(&_cadna_intrinsic_count);
   }
   if(a.y >= 0)
     res.y = a.y;
   else
     res.y = -a.y;
   if(a.z >= 0)
     res.z = a.z;
   else
     res.z = -a.z;
   res.accuracy=DIGIT_NOT_COMPUTED;
   return(res);
}
float_st fabsf(const float_st& a){
   float_st res;
   if(a.x >= 0){
     res.x = a.x;
     if (_cadna_intrinsic_tag)
       if ((a.y<0) || (a.z<0))  instability(&_cadna_intrinsic_count);
   }
   else{
     res.x = -a.x;
     if (_cadna_intrinsic_tag)
       if ((a.y>0) || (a.z>0))  instability(&_cadna_intrinsic_count);
   }
   if(a.y >= 0)
     res.y = a.y;
   else
     res.y = -a.y;
   if(a.z >= 0)
     res.z = a.z;
   else
     res.z = -a.z;
   res.accuracy=DIGIT_NOT_COMPUTED;
   return(res);
}
double_st abs(const double_st& a){
   double_st res;
   if(a.x >= 0){
     res.x = a.x;
     if (_cadna_intrinsic_tag)
       if ((a.y<0) || (a.z<0))  instability(&_cadna_intrinsic_count);
   }
   else{
     res.x = -a.x;
     if (_cadna_intrinsic_tag)
       if ((a.y>0) || (a.z>0))  instability(&_cadna_intrinsic_count);
   }
   if(a.y >= 0)
     res.y = a.y;
   else
     res.y = -a.y;
   if(a.z >= 0)
     res.z = a.z;
   else
     res.z = -a.z;
   res.accuracy=DIGIT_NOT_COMPUTED;
   return(res);
}
float_st abs(const float_st& a){
   float_st res;
   if(a.x >= 0){
     res.x = a.x;
     if (_cadna_intrinsic_tag)
       if ((a.y<0) || (a.z<0))  instability(&_cadna_intrinsic_count);
   }
   else{
     res.x = -a.x;
     if (_cadna_intrinsic_tag)
       if ((a.y>0) || (a.z>0))  instability(&_cadna_intrinsic_count);
   }
   if(a.y >= 0)
     res.y = a.y;
   else
     res.y = -a.y;
   if(a.z >= 0)
     res.z = a.z;
   else
     res.z = -a.z;
   res.accuracy=DIGIT_NOT_COMPUTED;
   return(res);
}

////////////////////////////////////////////////////////////////////////

//****f* cadna_intr/floor
//    NAME
//      floor
//
//    SYNOPSIS
//      res = floor(x)
//
//    FUNCTION
//       The floor() functions return the largest integral value less
//       than or equal to x.
//
//    INPUTS
//      a           - double_st
//    RESULT
//      res         - double_st
//    SEE ALSO
//      abs(3), ceil(3), floor(3), rint(3)
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
//
//  /


//****f* cadna_intr/floorf
//    NAME
//      floorf
//
//    SYNOPSIS
//      res = floorf(x)
//
//    FUNCTION
//       The floorf() functions return the largest integral value less
//       than or equal to x.
//
//    INPUTS
//      a           - float_st
//    RESULT
//      res         - float_st
//    SEE ALSO
//      absf(3), ceilf(3), floorf(3), rintf(3)
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
//
//  /






double_st floor(const double_st& a){
    double_st res;
    res.x = floor(a.x);
    res.y = floor(a.y);
    res.z = floor(a.z);
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (_cadna_intrinsic_tag)
      if (res.x != res.y || res.y!=res.z)
	instability(&_cadna_intrinsic_count);
    return(res);
}
float_st floorf(const float_st& a){
    float_st res;
    res.x = floor(a.x);
    res.y = floor(a.y);
    res.z = floor(a.z);
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (_cadna_intrinsic_tag)
      if (res.x != res.y || res.y!=res.z)
	instability(&_cadna_intrinsic_count);
    return(res);
}
float_st floor(const float_st& a){
    float_st res;
    res.x = floor(a.x);
    res.y = floor(a.y);
    res.z = floor(a.z);
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (_cadna_intrinsic_tag)
      if (res.x != res.y || res.y!=res.z)
	instability(&_cadna_intrinsic_count);
    return(res);
}
////////////////////////////////////////////////////////////////////////


//****f* cadna_intr/ceil
//    NAME
//      ceil
//
//    SYNOPSIS
//      res = ceil(x)
//
//    FUNCTION
//       The ceil() functions return the smallest integral value
//       greater than or equal to x.
//
//    INPUTS
//      a           - double_st
//    RESULT
//      res         - double_st
//    SEE ALSO
//      abs(3), ceil(3), floor(3), rint(3)
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
//
//  /


//****f* cadna_intr/ceilf
//    NAME
//      ceilf
//
//    SYNOPSIS
//      res = ceilf(x)
//
//    FUNCTION
//       The ceilf() functions return the smallest integral value
//       greater than or equal to x.
//
//    INPUTS
//      a           - float_st
//    RESULT
//      res         - float_st
//    SEE ALSO
//      absf(3), ceilf(3), floorf(3), rintf(3)
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
//
//  /



double_st ceil(const double_st& a){
    double_st res;
    res.x = ceil(a.x);
    res.y = ceil(a.y);
    res.z = ceil(a.z);
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (_cadna_intrinsic_tag)
      if (res.x != res.y || res.y!=res.z)
	instability(&_cadna_intrinsic_count);
    return(res);
}
float_st ceilf(const float_st& a){
    float_st res;
    res.x = ceil(a.x);
    res.y = ceil(a.y);
    res.z = ceil(a.z);
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (_cadna_intrinsic_tag)
      if (res.x != res.y || res.y!=res.z)
	instability(&_cadna_intrinsic_count);
    return(res);
}
float_st ceil(const float_st& a){
    float_st res;
    res.x = ceil(a.x);
    res.y = ceil(a.y);
    res.z = ceil(a.z);
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (_cadna_intrinsic_tag)
      if (res.x != res.y || res.y!=res.z)
	instability(&_cadna_intrinsic_count);
    return(res);
}

////////////////////////////////////////////////////////////////////////


//****f* cadna_intr/trunc
//    NAME
//      trunc
//
//    SYNOPSIS
//      res = trunc(x)
//
//    FUNCTION
//       The trunc() functions return the integral value nearest to
//       but no larger in magnitude than x.
//
//    INPUTS
//      a           - double_st
//    RESULT
//      res         - double_st
//    SEE ALSO
//      abs(3), ceil(3), floor(3), rint(3)
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
//
//  /


//****f* cadna_intr/truncf
//    NAME
//      truncf
//
//    SYNOPSIS
//      res = truncf(x)
//
//    FUNCTION
//       The truncf() functions return the integral value nearest to
//       but no larger in magnitude than x.
//
//    INPUTS
//      a           - float_st
//    RESULT
//      res         - float_st
//    SEE ALSO
//      absf(3), ceilf(3), floorf(3), rintf(3)
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
//
//  /




double_st trunc(const double_st& a){
    double_st res;
    res.x = trunc(a.x);
    res.y = trunc(a.y);
    res.z = trunc(a.z);
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (_cadna_intrinsic_tag)
      if (res.x != res.y || res.y!=res.z)
	instability(&_cadna_intrinsic_count);

    return(res);
}
float_st truncf(const float_st& a){
    float_st res;
    res.x = trunc(a.x);
    res.y = trunc(a.y);
    res.z = trunc(a.z);
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (_cadna_intrinsic_tag)
      if (res.x != res.y || res.y!=res.z)
	instability(&_cadna_intrinsic_count);

    return(res);
}
float_st trunc(const float_st& a){
    float_st res;
    res.x = trunc(a.x);
    res.y = trunc(a.y);
    res.z = trunc(a.z);
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (_cadna_intrinsic_tag)
      if (res.x != res.y || res.y!=res.z)
	instability(&_cadna_intrinsic_count);

    return(res);
}
////////////////////////////////////////////////////////////////////////

//****f* cadna_intr/nearbyint
//    NAME
//      nearbyint
//
//    SYNOPSIS
//      res = nearbyint(x)
//
//    FUNCTION
//      The nearbyint() functions return the integral value
//      (represented as a double precision number) nearest to x
//      according to the prevailing rounding mode.
//
//    INPUTS
//      a           - double_st
//    RESULT
//      res         - double_st
//    SEE ALSO
//      abs(3), ceil(3), floor(3), rint(3)
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
//
//  /


//****f* cadna_intr/nearbyintf
//    NAME
//      nearbyintf
//
//    SYNOPSIS
//      res = nearbyintf(x)
//
//    FUNCTION
//      The nearbyintf() functions return the integral value
//      (represented as a double precision number) nearest to x
//      according to the prevailing rounding mode.
//
//    INPUTS
//      a           - float_st
//    RESULT
//      res         - float_st
//    SEE ALSO
//      absf(3), ceilf(3), floorf(3), rintf(3)
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
//
//  /



double_st nearbyint(const double_st& a){
    double_st res;
    std::cerr << "CADNA WARNING: the nearbyint function is not CADNA compatible" << std::endl;
    res.x = nearbyint(a.x);
    res.y = nearbyint(a.y);
    res.z = nearbyint(a.z);
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (_cadna_intrinsic_tag)
      if (res.x != res.y || res.y!=res.z)
	instability(&_cadna_intrinsic_count);

    return(res);
}
float_st nearbyintf(const float_st& a){
    float_st res;
    std::cerr << "CADNA WARNING: the nearbyint function is not CADNA compatible" << std::endl;
    res.x = nearbyint(a.x);
    res.y = nearbyint(a.y);
    res.z = nearbyint(a.z);
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (_cadna_intrinsic_tag)
      if (res.x != res.y || res.y!=res.z)
	instability(&_cadna_intrinsic_count);

    return(res);
}
float_st nearbyint(const float_st& a){
    float_st res;
    std::cerr << "CADNA WARNING: the nearbyint function is not CADNA compatible" << std::endl;
    res.x = nearbyint(a.x);
    res.y = nearbyint(a.y);
    res.z = nearbyint(a.z);
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (_cadna_intrinsic_tag)
      if (res.x != res.y || res.y!=res.z)
	instability(&_cadna_intrinsic_count);

    return(res);
}

////////////////////////////////////////////////////////////////////////

//****f* cadna_intr/rint
//    NAME
//      rint
//
//    SYNOPSIS
//      res = rint(x)
//
//    FUNCTION
//       The rint() functions return the integral value nearest to x
//       (according to the prevailing rounding mode) in floating-point
//       format.
//
//    INPUTS
//      a           - double_st
//    RESULT
//      res         - double_st
//    SEE ALSO
//      abs(3), ceil(3), floor(3), rint(3)
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
//
//  /


//****f* cadna_intr/rintf
//    NAME
//      rintf
//
//    SYNOPSIS
//      res = rintf(x)
//
//    FUNCTION
//       The rintf() functions return the integral value nearest to x
//       (according to the prevailing rounding mode) in floating-point
//       format.
//
//    INPUTS
//      a           - float_st
//    RESULT
//      res         - float_st
//    SEE ALSO
//      absf(3), ceilf(3), floorf(3), rintf(3)
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
//
//  /




double_st rint(const double_st& a){
    double_st res;
    std::cerr << "CADNA WARNING: the rint function is not CADNA compatible" << std::endl;
    res.x = rint(a.x);
    res.y = rint(a.y);
    res.z = rint(a.z);
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (_cadna_intrinsic_tag)
      if (res.x != res.y || res.y!=res.z)
	instability(&_cadna_intrinsic_count);

    return(res);
}
float_st rintf(const float_st& a){
    float_st res;
    std::cerr << "CADNA WARNING: the rint function is not CADNA compatible" << std::endl;
    res.x = rint(a.x);
    res.y = rint(a.y);
    res.z = rint(a.z);
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (_cadna_intrinsic_tag)
      if (res.x != res.y || res.y!=res.z)
	instability(&_cadna_intrinsic_count);

    return(res);
}
float_st rint(const float_st& a){
    float_st res;
    std::cerr << "CADNA WARNING: the rint function is not CADNA compatible" << std::endl;
    res.x = rint(a.x);
    res.y = rint(a.y);
    res.z = rint(a.z);
    res.accuracy=DIGIT_NOT_COMPUTED;
    if (_cadna_intrinsic_tag)
      if (res.x != res.y || res.y!=res.z)
	instability(&_cadna_intrinsic_count);

    return(res);
}
////////////////////////////////////////////////////////////////////////


//****f* cadna_intr/lrint
//    NAME
//      lrint
//
//    SYNOPSIS
//      res = lrint(x)
//
//    FUNCTION
//      The lrint() functions return the integral value nearest to x
//      (according to the prevailing rounding mode) in the return
//      formats specified.  If the rounded value is outside the range
//      of the return type, the numeric result is unspecified and the
//      "invalid" floating-point exception is raised. A range error
//      may occur if the magnitude of x is too large.

//
//    INPUTS
//      a           - double_st
//    RESULT
//      res         - long int
//    SEE ALSO
//      abs(3), ceil(3), floor(3), rint(3)
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
//
//  /


//****f* cadna_intr/lrintf
//    NAME
//      lrintf
//
//    SYNOPSIS
//      res = lrintf(x)
//
//    FUNCTION
//      The lrintf() functions return the integral value nearest to x
//      (according to the prevailing rounding mode) in the return
//      formats specified.  If the rounded value is outside the range
//      of the return type, the numeric result is unspecified and the
//      "invalid" floating-point exception is raised. A range error
//      may occur if the magnitude of x is too large.
//
//
//    INPUTS
//      a           - float_st
//    RESULT
//      res         - long int
//    SEE ALSO
//      absf(3), ceilf(3), floorf(3), rintf(3)
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
//
//  /



long int lrint(const double_st& a){
  long int res1, res2,res3;
  std::cerr << "CADNA WARNING: the rint function is not CADNA compatible" << std::endl;
  res1 = lrint(a.x);
  res2 = lrint(a.y);
  res3 = lrint(a.z);
  if (_cadna_intrinsic_tag)
    if (res1 != res2 || res2!=res3)
       instability(&_cadna_intrinsic_count);

  return(res1);
}
long int lrintf(const float_st& a){
  long int res1, res2,res3;
  std::cerr << "CADNA WARNING: the rint function is not CADNA compatible" << std::endl;
  res1 = lrint(a.x);
  res2 = lrint(a.y);
  res3 = lrint(a.z);
  if (_cadna_intrinsic_tag)
    if (res1 != res2 || res2!=res3)
       instability(&_cadna_intrinsic_count);

  return(res1);
}
long int lrint(const float_st& a){
  long int res1, res2,res3;
  std::cerr << "CADNA WARNING: the rint function is not CADNA compatible" << std::endl;
  res1 = lrint(a.x);
  res2 = lrint(a.y);
  res3 = lrint(a.z);
  if (_cadna_intrinsic_tag)
    if (res1 != res2 || res2!=res3)
       instability(&_cadna_intrinsic_count);

  return(res1);
}
////////////////////////////////////////////////////////////////////////

//****f* cadna_intr/llrint
//    NAME
//      llrint
//
//    SYNOPSIS
//      res = llrint(x)
//
//    FUNCTION
//
//      The llrint() functions return the integral value nearest to x
//      (according to the prevailing rounding mode) in the return
//      formats specified.  If the rounded value is outside the range
//      of the return type, the numeric result is unspecified and the
//      "invalid" floating-point exception is raised. A range error
//      may occur if the magnitude of x is too large.
//
//
//    INPUTS
//      a           - double_st
//    RESULT
//      res         - long long int
//    SEE ALSO
//      abs(3), ceil(3), floor(3), rint(3)
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
//
//  /


//****f* cadna_intr/llrintf
//    NAME
//      llrintf
//
//    SYNOPSIS
//      res = llrintf(x)
//
//    FUNCTION
//      The llrintf() functions return the integral value nearest to x
//      (according to the prevailing rounding mode) in the return
//      formats specified.  If the rounded value is outside the range
//      of the return type, the numeric result is unspecified and the
//      "invalid" floating-point exception is raised. A range error
//      may occur if the magnitude of x is too large.
//
//    INPUTS
//      a           - float_st
//    RESULT
//      res         - long long int
//    SEE ALSO
//      absf(3), ceilf(3), floorf(3), rintf(3)
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
//
//  /




long long int llrint(const double_st& a){
  long long int res1, res2,res3;
  std::cerr << "CADNA WARNING: the rint function is not CADNA compatible" << std::endl;
    res1 = llrint(a.x);
    res2 = llrint(a.y);
    res3 = llrint(a.z);
    if (_cadna_intrinsic_tag)
      if (res1 != res2 || res2!=res3)
	instability(&_cadna_intrinsic_count);

    return(res1);
}
long long int llrintf(const float_st& a){
  long long int res1, res2,res3;
  std::cerr << "CADNA WARNING: the rint function is not CADNA compatible" << std::endl;
    res1 = llrint(a.x);
    res2 = llrint(a.y);
    res3 = llrint(a.z);
    if (_cadna_intrinsic_tag)
      if (res1 != res2 || res2!=res3)
	instability(&_cadna_intrinsic_count);

    return(res1);
}
long long int llrint(const float_st& a){
  long long int res1, res2,res3;
  std::cerr << "CADNA WARNING: the rint function is not CADNA compatible" << std::endl;
    res1 = llrint(a.x);
    res2 = llrint(a.y);
    res3 = llrint(a.z);
    if (_cadna_intrinsic_tag)
      if (res1 != res2 || res2!=res3)
	instability(&_cadna_intrinsic_count);

    return(res1);
}
////////////////////////////////////

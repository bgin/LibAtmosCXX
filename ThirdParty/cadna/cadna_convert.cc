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
#include <stdlib.h>

////////////////////////////////////////////////////////////////

// error_type=0  -> relative error
// error_type=1  -> absolute error


//****m* cadna_convert/data_st
//    NAME
//      data_st
//    SYNOPSIS
//      res = data_st()
//      res = data_st(x,y)
//    FUNCTION
//      the data_st(x,y) method allows to take into account data
//      uncertainty at the initialization of stochastic variables.
//      if y != 0, x is an absolute error
//      else x is a relative error
//
//      the data_st() method perturbs the last bit.
//
//    INPUTS
//      x           - a double
//      y           - an integer
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



void double_st::data_st(const double& e, const int& error_type){
  if (error_type){
    fesetround(FE_UPWARD);
    x = x +(e*rand()/(double)RAND_MAX);
    fesetround(FE_DOWNWARD);
    y = y -(e*rand()/(double)RAND_MAX);
  }
  else {
    fesetround(FE_UPWARD);
    x = x*((double)1.0+(e*rand()/(double)RAND_MAX)) ;
    fesetround(FE_DOWNWARD);
    y = y*((double)1.0-(e*rand()/(double)RAND_MAX)) ;
  }
  fesetround(FE_UPWARD);
  accuracy=DIGIT_NOT_COMPUTED;
}
void float_st::data_st(const double& e, const int& error_type){
  if (error_type){
    fesetround(FE_UPWARD);
    x = x +(e*rand()/(double)RAND_MAX);
    fesetround(FE_DOWNWARD);
    y = y -(e*rand()/(double)RAND_MAX);
  }
  else {
    fesetround(FE_UPWARD);
    x = x*((double)1.0+(e*rand()/(double)RAND_MAX)) ;
    fesetround(FE_DOWNWARD);
    y = y*((double)1.0-(e*rand()/(double)RAND_MAX)) ;
  }
  fesetround(FE_UPWARD);
  accuracy=DIGIT_NOT_COMPUTED;
}

////////////////////////////////////////////////////////////////


void double_st::data_st(){
  double aux=1.0;
  if (x==y){
    fesetround(FE_UPWARD);   x = x*(aux + 1.e-20);
    fesetround(FE_DOWNWARD); y = y*(aux - 1.e-20);
  }
  fesetround(FE_UPWARD);
  accuracy=DIGIT_NOT_COMPUTED;
}
void float_st::data_st(){
  double aux=1.0;
  if (x==y){
    fesetround(FE_UPWARD);   x = x*(aux + 1.e-20);
    fesetround(FE_DOWNWARD); y = y*(aux - 1.e-20);
  }
  fesetround(FE_UPWARD);
  accuracy=DIGIT_NOT_COMPUTED;
}



//****m* cadna_convert/unsigned char
//    NAME
//       unsigned char
//    SYNOPSIS
//      res = (unsigned char)x
//    FUNCTION
//
//
//    INPUTS
//      x           - a stochastic
//    RESULT
//      res         - an unsigned char
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


//****m* cadna_convert/char
//    NAME
//       char
//    SYNOPSIS
//      res = (char)x
//    FUNCTION
//
//
//    INPUTS
//      x           - a stochastic
//    RESULT
//      res         - a char
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


//****m* cadna_convert/int
//    NAME
//       int
//    SYNOPSIS
//      res = (int)x
//    FUNCTION
//
//
//    INPUTS
//      x           - a stochastic
//    RESULT
//      res         - an int
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

//****m* cadna_convert/unsigned int
//    NAME
//       unsigned int
//    SYNOPSIS
//      res = (unsigned int)x
//    FUNCTION
//
//
//    INPUTS
//      x           - a stochastic
//    RESULT
//      res         - an unsigned int
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



//****m* cadna_convert/short
//    NAME
//       short
//    SYNOPSIS
//      res = (short)x
//    FUNCTION
//
//
//    INPUTS
//      x           - a stochastic
//    RESULT
//      res         - a short
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


//****m* cadna_convert/unsigned short
//    NAME
//       unsigned short
//    SYNOPSIS
//      res = (unsigned short )x
//    FUNCTION
//
//
//    INPUTS
//      x           - a stochastic
//    RESULT
//      res         - an unsigned short
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


 //****m* cadna_convert/long
//    NAME
//       long
//    SYNOPSIS
//      res = (long)x
//    FUNCTION
//
//
//    INPUTS
//      x           - a stochastic
//    RESULT
//      res         - a long
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

 //****m* cadna_convert/unsigned long
//    NAME
//       unsigned long
//    SYNOPSIS
//      res = (unsigned long)x
//    FUNCTION
//
//
//    INPUTS
//      x           - a stochastic
//    RESULT
//      res         - an unsigned long
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



//****m* cadna_convert/long long
//    NAME
//       long long
//    SYNOPSIS
//      res = (long long)x
//    FUNCTION
//
//
//    INPUTS
//      x           - a stochastic
//    RESULT
//      res         - a long long
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

//****m* cadna_convert/unsigned long long
//    NAME
//       unsigned long long
//    SYNOPSIS
//      res = (unsigned long long)x
//    FUNCTION
//
//
//    INPUTS
//      x           - a stochastic
//    RESULT
//      res         - an unsigned long long
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


//****m* cadna_convert/float
//    NAME
//       float
//    SYNOPSIS
//      res = (float)x
//    FUNCTION
//
//
//    INPUTS
//      x           - a stochastic
//    RESULT
//      res         - a float
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



//****m* cadna_convert/double
//    NAME
//       double
//    SYNOPSIS
//      res = (double)x
//    FUNCTION
//
//
//    INPUTS
//      x           - a stochastic
//    RESULT
//      res         - a double
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
// /




float_st::operator double_st(){
  double_st res;
  res.x=x;
  res.y=y;
  res.z=z;
  return(res);
}





double_st::operator double(){
  return ( (double)( ( x+y+z ) / 3.));
}
double_st::operator float(){
  return ( (float)( ( x+y+z ) / 3.));
}
double_st::operator unsigned long long(){
  unsigned long long a;
  if (_cadna_intrinsic_tag){
    a=(unsigned long long)x;
    if ((unsigned long long)y!=a || (unsigned long long)z!=a)
      instability(&_cadna_intrinsic_count);
  }
  return ((unsigned long long)(x+y+z)/3.);
}
double_st::operator long long(){
  long long a;
  if (_cadna_intrinsic_tag){
    a=(long long)x;
    if ((long long)y!=a || (long long)z!=a)
      instability(&_cadna_intrinsic_count);
  }
  return ((long long)(x+y+z)/3.);
}
double_st::operator unsigned long(){
  unsigned long a;
  if (_cadna_intrinsic_tag){
    a=(unsigned long)x;
    if ((unsigned long)y!=a || (unsigned long)z!=a)
      instability(&_cadna_intrinsic_count);
  }
  return ((unsigned long)(x+y+z)/3.);
}
double_st::operator long(){
  long a;
  if (_cadna_intrinsic_tag){
    a=(long)x;
    if ((long)y!=a || (long)z!=a)
      instability(&_cadna_intrinsic_count);
  }
  return ((long)(x+y+z)/3.);
}
double_st::operator unsigned int(){
  unsigned int a;
  if (_cadna_intrinsic_tag){
    a=(unsigned int)x;
    if ((unsigned int)y!=a || (unsigned int)z!=a)
      instability(&_cadna_intrinsic_count);
  }
  return ((unsigned int)(x+y+z)/3.);
}
double_st::operator int(){
  int a;
  if (_cadna_intrinsic_tag){
    a=(int)x;
    if ((int)y!=a || (int)z!=a)
      instability(&_cadna_intrinsic_count);
  }
  return ((int)(x+y+z)/3.);
}
double_st::operator unsigned short(){
  unsigned short a;
  if (_cadna_intrinsic_tag){
    a=(unsigned short)x;
    if ((unsigned short)y!=a || (unsigned short)z!=a)
      instability(&_cadna_intrinsic_count);
  }
  return ((unsigned short)(x+y+z)/3.);
}
double_st::operator short(){
  short a;
  if (_cadna_intrinsic_tag){
    a=(short)x;
    if ((short)y!=a || (short)z!=a)
      instability(&_cadna_intrinsic_count);
  }
  return ((short)(x+y+z)/3.);
}
double_st::operator unsigned char(){
  unsigned char a;
  if (_cadna_intrinsic_tag){
    a=(unsigned char)x;
    if ((unsigned char)y!=a || (unsigned char)z!=a)
      instability(&_cadna_intrinsic_count);
  }
  return ((unsigned char)(x+y+z)/3.);
}
double_st::operator char(){
  char a;
  if (_cadna_intrinsic_tag){
    a=(char)x;
    if ((char)y!=a || (char)z!=a)
      instability(&_cadna_intrinsic_count);
  }
  return ((char)(x+y+z)/3.);
}

float_st::operator double(){
  return ( (double)( ( x+y+z ) / 3.));
}
float_st::operator float(){
  return ( (float)( ( x+y+z ) / 3.));
}
float_st::operator unsigned long long(){
  unsigned long long a;
  if (_cadna_intrinsic_tag){
    a=(unsigned long long)x;
    if ((unsigned long long)y!=a || (unsigned long long)z!=a)
      instability(&_cadna_intrinsic_count);
  }
  return ((unsigned long long)(x+y+z)/3.);
}
float_st::operator long long(){
  long long a;
  if (_cadna_intrinsic_tag){
    a=(long long)x;
    if ((long long)y!=a || (long long)z!=a)
      instability(&_cadna_intrinsic_count);
  }
  return ((long long)(x+y+z)/3.);
}
float_st::operator unsigned long(){
  unsigned long a;
  if (_cadna_intrinsic_tag){
    a=(unsigned long)x;
    if ((unsigned long)y!=a || (unsigned long)z!=a)
      instability(&_cadna_intrinsic_count);
  }
  return ((unsigned long)(x+y+z)/3.);
}
float_st::operator long(){
  long a;
  if (_cadna_intrinsic_tag){
    a=(long)x;
    if ((long)y!=a || (long)z!=a)
      instability(&_cadna_intrinsic_count);
  }
  return ((long)(x+y+z)/3.);
}
float_st::operator unsigned int(){
  unsigned int a;
  if (_cadna_intrinsic_tag){
    a=(unsigned int)x;
    if ((unsigned int)y!=a || (unsigned int)z!=a)
      instability(&_cadna_intrinsic_count);
  }
  return ((unsigned int)(x+y+z)/3.);
}
float_st::operator int(){
  int a;
  if (_cadna_intrinsic_tag){
    a=(int)x;
    if ((int)y!=a || (int)z!=a)
      instability(&_cadna_intrinsic_count);
  }
  return ((int)(x+y+z)/3.);
}
float_st::operator unsigned short(){
  unsigned short a;
  if (_cadna_intrinsic_tag){
    a=(unsigned short)x;
    if ((unsigned short)y!=a || (unsigned short)z!=a)
      instability(&_cadna_intrinsic_count);
  }
  return ((unsigned short)(x+y+z)/3.);
}
float_st::operator short(){
  short a;
  if (_cadna_intrinsic_tag){
    a=(short)x;
    if ((short)y!=a || (short)z!=a)
      instability(&_cadna_intrinsic_count);
  }
  return ((short)(x+y+z)/3.);
}
float_st::operator unsigned char(){
  unsigned char a;
  if (_cadna_intrinsic_tag){
    a=(unsigned char)x;
    if ((unsigned char)y!=a || (unsigned char)z!=a)
      instability(&_cadna_intrinsic_count);
  }
  return ((unsigned char)(x+y+z)/3.);
}
float_st::operator char(){
  char a;
  if (_cadna_intrinsic_tag){
    a=(char)x;
    if ((char)y!=a || (char)z!=a)
      instability(&_cadna_intrinsic_count);
  }
  return ((char)(x+y+z)/3.);
}





float_st::operator double_st() const{
  double_st res;
  res.x=x;
  res.y=y;
  res.z=z;
  return(res);
}






double_st::operator double() const{
  return ( (double)( ( x+y+z ) / 3.));
}
double_st::operator float() const{
  return ( (float)( ( x+y+z ) / 3.));
}
double_st::operator unsigned long long() const{
  unsigned long long a;
  if (_cadna_intrinsic_tag){
    a=(unsigned long long)x;
    if ((unsigned long long)y!=a || (unsigned long long)z!=a)
      instability(&_cadna_intrinsic_count);
  }
  return ((unsigned long long)(x+y+z)/3.);
}
double_st::operator long long() const{
  long long a;
  if (_cadna_intrinsic_tag){
    a=(long long)x;
    if ((long long)y!=a || (long long)z!=a)
      instability(&_cadna_intrinsic_count);
  }
  return ((long long)(x+y+z)/3.);
}
double_st::operator unsigned long() const{
  unsigned long a;
  if (_cadna_intrinsic_tag){
    a=(unsigned long)x;
    if ((unsigned long)y!=a || (unsigned long)z!=a)
      instability(&_cadna_intrinsic_count);
  }
  return ((unsigned long)(x+y+z)/3.);
}
double_st::operator long() const{
  long a;
  if (_cadna_intrinsic_tag){
    a=(long)x;
    if ((long)y!=a || (long)z!=a)
      instability(&_cadna_intrinsic_count);
  }
  return ((long)(x+y+z)/3.);
}
double_st::operator unsigned int() const{
  unsigned int a;
  if (_cadna_intrinsic_tag){
    a=(unsigned int)x;
    if ((unsigned int)y!=a || (unsigned int)z!=a)
      instability(&_cadna_intrinsic_count);
  }
  return ((unsigned int)(x+y+z)/3.);
}
double_st::operator int() const{
  int a;
  if (_cadna_intrinsic_tag){
    a=(int)x;
    if ((int)y!=a || (int)z!=a)
      instability(&_cadna_intrinsic_count);
  }
  return ((int)(x+y+z)/3.);
}
double_st::operator unsigned short() const{
  unsigned short a;
  if (_cadna_intrinsic_tag){
    a=(unsigned short)x;
    if ((unsigned short)y!=a || (unsigned short)z!=a)
      instability(&_cadna_intrinsic_count);
  }
  return ((unsigned short)(x+y+z)/3.);
}
double_st::operator short() const{
  short a;
  if (_cadna_intrinsic_tag){
    a=(short)x;
    if ((short)y!=a || (short)z!=a)
      instability(&_cadna_intrinsic_count);
  }
  return ((short)(x+y+z)/3.);
}
double_st::operator unsigned char() const{
  unsigned char a;
  if (_cadna_intrinsic_tag){
    a=(unsigned char)x;
    if ((unsigned char)y!=a || (unsigned char)z!=a)
      instability(&_cadna_intrinsic_count);
  }
  return ((unsigned char)(x+y+z)/3.);
}
double_st::operator char() const{
  char a;
  if (_cadna_intrinsic_tag){
    a=(char)x;
    if ((char)y!=a || (char)z!=a)
      instability(&_cadna_intrinsic_count);
  }
  return ((char)(x+y+z)/3.);
}

float_st::operator double() const{
  return ( (double)( ( x+y+z ) / 3.));
}
float_st::operator float() const{
  return ( (float)( ( x+y+z ) / 3.));
}
float_st::operator unsigned long long() const{
  unsigned long long a;
  if (_cadna_intrinsic_tag){
    a=(unsigned long long)x;
    if ((unsigned long long)y!=a || (unsigned long long)z!=a)
      instability(&_cadna_intrinsic_count);
  }
  return ((unsigned long long)(x+y+z)/3.);
}
float_st::operator long long() const{
  long long a;
  if (_cadna_intrinsic_tag){
    a=(long long)x;
    if ((long long)y!=a || (long long)z!=a)
      instability(&_cadna_intrinsic_count);
  }
  return ((long long)(x+y+z)/3.);
}
float_st::operator unsigned long() const{
  unsigned long a;
  if (_cadna_intrinsic_tag){
    a=(unsigned long)x;
    if ((unsigned long)y!=a || (unsigned long)z!=a)
      instability(&_cadna_intrinsic_count);
  }
  return ((unsigned long)(x+y+z)/3.);
}
float_st::operator long() const{
  long a;
  if (_cadna_intrinsic_tag){
    a=(long)x;
    if ((long)y!=a || (long)z!=a)
      instability(&_cadna_intrinsic_count);
  }
  return ((long)(x+y+z)/3.);
}
float_st::operator unsigned int() const{
  unsigned int a;
  if (_cadna_intrinsic_tag){
    a=(unsigned int)x;
    if ((unsigned int)y!=a || (unsigned int)z!=a)
      instability(&_cadna_intrinsic_count);
  }
  return ((unsigned int)(x+y+z)/3.);
}
float_st::operator int() const{
  int a;
  if (_cadna_intrinsic_tag){
    a=(int)x;
    if ((int)y!=a || (int)z!=a)
      instability(&_cadna_intrinsic_count);
  }
  return ((int)(x+y+z)/3.);
}
float_st::operator unsigned short() const{
  unsigned short a;
  if (_cadna_intrinsic_tag){
    a=(unsigned short)x;
    if ((unsigned short)y!=a || (unsigned short)z!=a)
      instability(&_cadna_intrinsic_count);
  }
  return ((unsigned short)(x+y+z)/3.);
}
float_st::operator short() const{
  short a;
  if (_cadna_intrinsic_tag){
    a=(short)x;
    if ((short)y!=a || (short)z!=a)
      instability(&_cadna_intrinsic_count);
  }
  return ((short)(x+y+z)/3.);
}
float_st::operator unsigned char() const{
  unsigned char a;
  if (_cadna_intrinsic_tag){
    a=(unsigned char)x;
    if ((unsigned char)y!=a || (unsigned char)z!=a)
      instability(&_cadna_intrinsic_count);
  }
  return ((unsigned char)(x+y+z)/3.);
}
float_st::operator char() const{
  char a;
  if (_cadna_intrinsic_tag){
    a=(char)x;
    if ((char)y!=a || (char)z!=a)
      instability(&_cadna_intrinsic_count);
  }
  return ((char)(x+y+z)/3.);
}

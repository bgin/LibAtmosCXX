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



// saves the rounding mode to perform computation
// always with the same rounding mode


//****m* cadna_numericalnoise/numericalnoise
//    NAME
//      numericalnoise
//    SYNOPSIS
//      res = numericalnoise(x)
//    FUNCTION
//      The numericalnoise() function returns 1 if x is a numerical noise,
//      O otherwise.
//
//
//    INPUTS
//      x           - a stochastic number
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
//
//
//    BUGS
//
//
//    SEE ALSO
//
//
//  /




inline int double_st::numericalnoise() const{
  int res;
  double x0,x1,x2,xx;

  xx=3./(x+y+z);
  x0=x*xx-1.;
  x1=y*xx-1;
  x2=z*xx-1;
  res=x0*x0+x1*x1+x2*x2 > 3.241001342318910E-02 ;

  return res;
};
inline int float_st::numericalnoise() const{
  int res;
  double x0,x1,x2,xx;

  xx=3./(x+y+z);
  x0=x*xx-1.;
  x1=y*xx-1;
  x2=z*xx-1;
  res=x0*x0+x1*x1+x2*x2 > 3.241001342318910E-02 ;

  return res;
};

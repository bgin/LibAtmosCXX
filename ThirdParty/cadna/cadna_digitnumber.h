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


// ----------------------------------------


// save the rounding mode to compute the number of significant digits
// always with the same rounding mode


//****f* cadna_digitnumber/nb_significant_digit
//    NAME
//      nb_significant_digit
//    SYNOPSIS
//      res = x.nb_significant_digit()
//    FUNCTION
//      The nb_significant_digit() function returns the number of
//      exact significant digits of a stochastic x
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





inline int double_st::nb_significant_digit() const{
  double x0,x1,x2,xx;

  xx=x+y+z;

  accuracy=0;
  if (xx==0.0){
    if ((x==y) &&(x==z) ) accuracy=15;
  } else {
    xx=(double)3./xx;
    x0=x*xx-(double)1.;
    x1=y*xx-(double)1.;
    x2=z*xx-(double)1.;
    double yy=(x0*x0+x1*x1+x2*x2)*3.085466170416667;

    if (yy<=1.e-30)  accuracy=15;
    else {
      long exp=((doublebf *)&yy)->bf;
      exp&=0x7FF0000000000000UL;
      exp>>=52;
      exp-=1023;
      yy= -exp*0.301029995663981195;
      if (yy>=0.) accuracy=(int)((yy+(double)1.)*(double)0.5);
    }
  }

  return accuracy;
};
inline int float_st::nb_significant_digit() const{
  double x0,x1,x2,xx;

  xx=x+y+z;

  accuracy=0;
  if (xx==0.0){
    if ((x==y) &&(x==z) ) accuracy=7;
  } else {
    xx=(double)3./xx;
    x0=x*xx-(double)1.;
    x1=y*xx-(double)1.;
    x2=z*xx-(double)1.;
    double yy=(x0*x0+x1*x1+x2*x2)*3.085466170416667;

    if (yy<=1.e-14)  accuracy=7;
    else {
      long exp=((doublebf *)&yy)->bf;
      exp&=0x7FF0000000000000UL;
      exp>>=52;
      exp-=1023;
      yy= -exp*0.301029995663981195;
      if (yy>=0.) accuracy=(int)((yy+(double)1.)*(double)0.5);
    }
  }

  return accuracy;
};

//****f* cadna_digitnumber/approx_digit
//    NAME
//      approx_digit
//    SYNOPSIS
//      res = x.approx_digit()
//    FUNCTION
//      The approx_digit() function returns 0 if a stochastic
//	number is non significant and RELIABLE_RESULT otherwise.
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





inline int double_st::approx_digit() const{
  double x0,x1,x2,xx;

  accuracy=RELIABLE_RESULT;
  xx=x+y+z;

  if (xx==(double)0.0) {
    if ((x != y ) || (x != z)) accuracy=0;
  }
  else {
    xx=(double)3./xx;
    x0=x*xx-(double)1.;
    x1=y*xx-(double)1.;
    x2=z*xx-(double)1.;
    if ((x0*x0+x1*x1+x2*x2) > 3.241001342318910E-02 )
      accuracy=0;
  }

  return accuracy;
};
inline int float_st::approx_digit() const{
  double x0,x1,x2,xx;

  accuracy=RELIABLE_RESULT;
  xx=x+y+z;

  if (xx==(double)0.0) {
    if ((x != y ) || (x != z)) accuracy=0;
  }
  else {
    xx=(double)3./xx;
    x0=x*xx-(double)1.;
    x1=y*xx-(double)1.;
    x2=z*xx-(double)1.;
    if ((x0*x0+x1*x1+x2*x2) > 3.241001342318910E-02 )
      accuracy=0;
  }

  return accuracy;
};

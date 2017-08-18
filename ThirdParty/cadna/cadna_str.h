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

#include <fenv.h>
#define MAXCHAINE 256
static char chstr[MAXCHAINE][64];
static int numstr=0; 
#ifdef _OPENMP
#pragma omp threadprivate(chstr, numstr)
#endif //_OPENMP

//////////////////////////////////////////////////////////
//****m* cadna_str/display
//    NAME
//      display
//
//    SYNOPSIS
//      display()
//      display(char *)
//
//    FUNCTION
//      The display method prints the triplet associated with 
//      a stochastic variable.
//    INPUTS
//   
//    RESULT
//      void
//    SEE ALSO
//      str(3)
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

inline void double_st::display() const 
{ 
    printf(" %+.16e -- %+.16e -- %+.16e \n",x,y,z);
}


inline void float_st::display() const 
{ 
    printf(" %+.8e -- %+.8e -- %+.8e \n",x,y,z);
}

//////////////////////////////////////////////////////////
inline void double_st::display(const char *s) const 
{ 
    printf(" %s %+.16e -- %+.16e -- %+.16e ",s,x,y,z);
}

inline void float_st::display(const char *s) const 
{ 
    printf(" %s %+.8e -- %+.8e -- %+.8e ",s,x,y,z);
}

//////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////
//****m* cadna_str/operator<<
//    NAME
//     operator<<
//
//    SYNOPSIS
//      ostream& operator <<(ostream&, const double_st &) 
//      ostream& operator <<(ostream&, const float_st &) 
//    FUNCTION
//      << operator for stochastic variables
//    INPUTS
//   
//    RESULT
//      void
//    SEE ALSO
//      str(3)
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


inline std::ostream& operator <<(std::ostream& s, const double_st &a) 
{
  char ch[25];
  return s << a.str(ch);
}

inline std::ostream& operator <<(std::ostream& s, const float_st &a) 
{
  char ch[25];
  return s << a.str(ch);
}

//////////////////////////////////////////////////////////
//****m* cadna_str/operator>>
//    NAME
//     operator>>
//
//    SYNOPSIS
//      ostream& operator >>(ostream&, const double_st &) 
//      ostream& operator >>(ostream&, const float_st &) 
//    FUNCTION
//      >> operator for stochastic variables
//    INPUTS
//   
//    RESULT
//      void
//    SEE ALSO
//      str(3)
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

inline std::istream& operator >>(std::istream& s, double_st& a)
{
  double d;
  s >> d;
  a.x = d;
  a.y = d;
  a.z = d;
  a.accuracy=DIGIT_NOT_COMPUTED;
  return s;
}

inline std::istream& operator >>(std::istream& s, float_st& a)
{
  float d;
  s >> d;
  a.x = d;
  a.y = d;
  a.z = d;
  a.accuracy=DIGIT_NOT_COMPUTED;
  return s;
}

//////////////////////////////////////////////////////////

//****f* cadna_str/str
//    NAME
//     str
//
//    SYNOPSIS
//      char* double_st::str(char *s) const 
//      char* float_st::str(char *s) const 

//      char* str(char *, double_st&)
//      char* str(char *, float_st&)
//    FUNCTION
//      The output string contains the scientific notation of the 
//      stochastic argument; only the exact significant digits appear 
//      in the string. 
//    INPUTS
//      The str function has a string argument and a stochastic argument.
//    RESULT
//      It returns a pointer to the first argument.
//    SEE ALSO
//      str(3)
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


inline char* double_st::str(char *s) const 
{
  int nn,  nres, naux;
  double fract_res, res;
  int tmp;
  char *t;

  // compute the number of exact significant digits always
  // with the same rounding mode
  fesetround(FE_TONEAREST);
  
  if (accuracy==DIGIT_NOT_COMPUTED || accuracy==RELIABLE_RESULT)
    this->nb_significant_digit();
  
  //        12345678901234567890123
  strcpy(s,"                       ");
  if (accuracy==0) {
    strncpy(s," @.0",4);
  }
  else {
    accuracy=(accuracy<15) ? accuracy : 15;
    res=( (x) +(y) +(z) )/(double)(3);
    if (res<0.0) strncpy(s,"-0.",3);
    else strncpy(s," 0.",3);
    res=fabs(res);
    
    if (res==0.0) {
      nn=0;
      fract_res=0.0;
    }
    else{
      if (res>=1.0) nn=(int)log10(res)+1;
      else  nn= (int)log10(res);
      fract_res=res*pow(10.,-nn);
      if (fract_res<0.1) fract_res=0.1;
      if (fract_res>=1.0) {
	fract_res=0.1;
	nn=nn+1;
      }
    }
    naux=accuracy+3;
    t=s+3;
    for(int i=4;i<naux;i++){
      nres=(int)(fract_res*10.);
      *t++=48+nres;
      fract_res=10.0*fract_res-nres;
    }
    tmp = (int)(fract_res*10.0);
    nres = tmp < 9 ? tmp : 9 ;
    *t++=48+nres;
    *t++='E';
    if(nn<0) *t++='-';
    else *t++='+';
    nn=abs(nn);
    *t++=48+(nn/100);
    nn=nn%100;        
    *t++=48+(nn/10);
    *t++=48+(nn%10);
    *t='\0';
  }
  fesetround(FE_UPWARD);
  return(s);
}



inline char* float_st::str(char *s) const 
{
  int nn, nres, naux;
  float fract_res, res;
  int tmp;
  char *t;

  // compute the number of significant digits always
  // with the same rounding mode
  fesetround(FE_TONEAREST);
  
  if (accuracy==DIGIT_NOT_COMPUTED || accuracy==RELIABLE_RESULT)
    this->nb_significant_digit();
  
  //        12345678901234567890123
  strcpy(s,"                       ");
  if (accuracy==0) {
    strncpy(s," @.0",4);
  }
  else {
    accuracy=(accuracy<7) ? accuracy : 7;
    res=( (x) +(y) +(z) )/(float)(3);
    if (res<0.0) strncpy(s,"-0.",3);
    else strncpy(s," 0.",3);
    res=fabs(res);
    
    if (res==0.0) {
      nn=0;
      fract_res=0.0;
    }
    else{
      if (res>=1.0) nn=(int)log10(res)+1;
      else  nn= (int)log10(res);
      fract_res=res*pow(10.,-nn);
      if (fract_res<0.1) fract_res=0.1;
      if (fract_res>=1.0) {
	fract_res=0.1;
	nn=nn+1;
      }
    }
    naux=accuracy+3;
    t=s+3;
    for(int i=4;i<naux;i++){
      nres=(int)(fract_res*10.);
      *t++=48+nres;
      fract_res=10.0*fract_res-nres;
    }
    tmp = (int)(fract_res*10.0);
    nres = tmp < 9 ? tmp : 9 ;
    *t++=48+nres;
    *t++='E';
    if(nn<0) *t++='-';
    else *t++='+';
    nn=abs(nn);
    *t++=48+(nn/100);
    nn=nn%100;        
    *t++=48+(nn/10);
    *t++=48+(nn%10);
    *t='\0';
  }
  fesetround(FE_UPWARD);
  return(s);
}



inline char* str(char *s, const double_st& a)
{
  return(a.str(s));
}

inline char* str(char *s, const float_st& a)
{
  return(a.str(s));
}

//////////////////////////////////////////////////////////



//****f* cadna_str/strp
//    NAME
//     strp
//
//    SYNOPSIS
//      char* strp(double_st&)
//      char* strp(float_st&)
//    FUNCTION
//      The output string contains the scientific notation of the 
//      stochastic argument; only the exact significant digits appear 
//      in the string. The strp function must be used only with
//      the family of printf functions. The only restriction is that
//      it is not possible to have more than 256 calls to the strp
//      function in one call to the printf function.
//    INPUTS
//      The strp function has a stochastic argument.  
//    RESULT
//      It returns a string.
//    SEE ALSO
//      str(3)
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

inline char* strp(const double_st& a)
{
  char *s;

  s=chstr[numstr];
  if ((++numstr) == MAXCHAINE)  numstr=0; 
  return a.str(s);
}

inline char* strp(const float_st& a)
{
  char *s;
  
  s=chstr[numstr];
  if ((++numstr) == MAXCHAINE)  numstr=0; 
  return a.str(s);
}

//////////////////////////////////////////////////////////



  

//////////////////////////////////////////:

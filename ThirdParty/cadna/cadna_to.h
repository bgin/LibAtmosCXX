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


//****m* cadna_to/operator=
//    NAME
//      operator=
//    SYNOPSIS
//      res = a
//    FUNCTION
//      Define all the functions involving at least one argument
//      of stochastic type which overload the assignment statement "=".
//
//    INPUTS
//      a           - an integer, a float, a double, float_st or double_st
//
//    RESULT
//      res         - float_st or double_st
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



inline double_st& double_st::operator=(const double_st &a){
    x=a.x;
    y=a.y;
    z=a.z;
    accuracy=a.accuracy;
    return *this ;
}
inline float_st& float_st::operator=(const float_st &a){
    x=a.x;
    y=a.y;
    z=a.z;
    accuracy=a.accuracy;
    return *this ;
}

// if a double_st variable is assigned from a float,
// it is perturbed with the relative error 1.E-7.
double_st& double_st::operator=(const float &a)
{
    x=a;
    x = x*((double)1.0+(1.E-7*rand()/(double)RAND_MAX)) ;
    y=a;
    y = y*((double)1.0-(1.E-7*rand()/(double)RAND_MAX)) ;
    z=a;
    accuracy=DIGIT_NOT_COMPUTED;
    return *this ;
}





inline double_st& double_st::operator=(const double &a){
    x=a;
    y=a;
    z=a;
    accuracy=15;
    return *this ;
}
inline double_st& double_st::operator=(const unsigned long long &a){
    x=a;
    y=a;
    z=a;
    accuracy=15;
    return *this ;
}
inline double_st& double_st::operator=(const long long &a){
    x=a;
    y=a;
    z=a;
    accuracy=15;
    return *this ;
}
inline double_st& double_st::operator=(const unsigned long &a){
    x=a;
    y=a;
    z=a;
    accuracy=15;
    return *this ;
}
inline double_st& double_st::operator=(const long &a){
    x=a;
    y=a;
    z=a;
    accuracy=15;
    return *this ;
}
inline double_st& double_st::operator=(const unsigned int &a){
    x=a;
    y=a;
    z=a;
    accuracy=15;
    return *this ;
}
inline double_st& double_st::operator=(const int &a){
    x=a;
    y=a;
    z=a;
    accuracy=15;
    return *this ;
}
inline double_st& double_st::operator=(const unsigned short &a){
    x=a;
    y=a;
    z=a;
    accuracy=15;
    return *this ;
}
inline double_st& double_st::operator=(const short &a){
    x=a;
    y=a;
    z=a;
    accuracy=15;
    return *this ;
}
inline double_st& double_st::operator=(const unsigned char &a){
    x=a;
    y=a;
    z=a;
    accuracy=15;
    return *this ;
}
inline double_st& double_st::operator=(const char &a){
    x=a;
    y=a;
    z=a;
    accuracy=15;
    return *this ;
}



inline float_st& float_st::operator=(const double &a){
    x=a;
    y=a;
    z=a;
    accuracy=7;
    return *this ;
}
inline float_st& float_st::operator=(const float &a){
    x=a;
    y=a;
    z=a;
    accuracy=7;
    return *this ;
}
inline float_st& float_st::operator=(const unsigned long long &a){
    x=a;
    y=a;
    z=a;
    accuracy=7;
    return *this ;
}
inline float_st& float_st::operator=(const long long &a){
    x=a;
    y=a;
    z=a;
    accuracy=7;
    return *this ;
}
inline float_st& float_st::operator=(const unsigned long &a){
    x=a;
    y=a;
    z=a;
    accuracy=7;
    return *this ;
}
inline float_st& float_st::operator=(const long &a){
    x=a;
    y=a;
    z=a;
    accuracy=7;
    return *this ;
}
inline float_st& float_st::operator=(const unsigned int &a){
    x=a;
    y=a;
    z=a;
    accuracy=7;
    return *this ;
}
inline float_st& float_st::operator=(const int &a){
    x=a;
    y=a;
    z=a;
    accuracy=7;
    return *this ;
}
inline float_st& float_st::operator=(const unsigned short &a){
    x=a;
    y=a;
    z=a;
    accuracy=7;
    return *this ;
}
inline float_st& float_st::operator=(const short &a){
    x=a;
    y=a;
    z=a;
    accuracy=7;
    return *this ;
}
inline float_st& float_st::operator=(const unsigned char &a){
    x=a;
    y=a;
    z=a;
    accuracy=7;
    return *this ;
}
inline float_st& float_st::operator=(const char &a){
    x=a;
    y=a;
    z=a;
    accuracy=7;
    return *this ;
}





inline double_st& double_st::operator=(const float_st &a){
    x=(double)a.x;
    y=(double)a.y;
    z=(double)a.z;
    accuracy=DIGIT_NOT_COMPUTED;
    return *this ;
}
inline float_st& float_st::operator=(const double_st &a){
    x=(float)a.x;
    y=(float)a.y;
    z=(float)a.z;
    accuracy=(a.accuracy>8?7:a.accuracy);
    return *this ;
}

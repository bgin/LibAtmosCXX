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


#ifndef __CADNA__
#define __CADNA__


#include <iostream>
#include <cmath>
#include <complex>
#include <cstdlib>
#include <cstdio>
#include <cstring>

#define CADNA_DIV       0x1
#define CADNA_MUL       0x2
#define CADNA_POWER     0x4
#define CADNA_MATH      0x8
#define CADNA_BRANCHING 0x10
#define CADNA_INTRINSIC 0x20
#define CADNA_CANCEL    0x40
#define CADNA_ALL       0xFFFFFFFF

class float_st;

class double_st 
{  
  friend class float_st;

protected:
  double x,y,z;
  
  typedef double TYPEBASE;
  
private:
  mutable int accuracy;
  int pad;

public:

  inline double_st(void) :x(0),y(0),z(0),accuracy(15) {};
  inline double_st(double a, double b, double c):x(a),y(b),z(c),accuracy(-1) {};
  inline double_st(const double &a): x(a),y(a),z(a),accuracy(15) {};

  inline double_st (const float_st&);

  double getx() {return(this->x);}
  double gety() {return(this->y);}
  double getz() {return(this->z);}
  int getaccuracy() {return(this->accuracy);}

  //complex
//1)mulplication
  friend std::complex<double_st> operator*(double const&,std::complex<double_st> const&);
  friend std::complex<double_st> operator*(std::complex<double_st> const&,double const&);
  friend std::complex<float_st> operator*( float const&,std::complex<float_st> const&);
  friend std::complex<float_st> operator*( std::complex<float_st> const&,float const&);
//2)division
  friend std::complex<double_st> operator/(double const&,std::complex<double_st> const&);
  friend std::complex<double_st> operator/(std::complex<double_st> const&,double const&);
  friend std::complex<float_st> operator/( float const&,std::complex<float_st> const&);
  friend std::complex<float_st> operator/( std::complex<float_st> const&,float const&);
//3)addition
  friend std::complex<double_st> operator+(double const&,std::complex<double_st> const&);
  friend std::complex<double_st> operator+(std::complex<double_st> const&,double const&);
  friend std::complex<float_st> operator+( float const&,std::complex<float_st> const&);
  friend std::complex<float_st> operator+( std::complex<float_st> const&,float const&);
//4)SUBTRACTION
  friend std::complex<double_st> operator-(double const&,std::complex<double_st> const&);
  friend std::complex<double_st> operator-(std::complex<double_st> const&,double const&);
  friend std::complex<float_st> operator-( float const&,std::complex<float_st> const&);
  friend std::complex<float_st> operator-( std::complex<float_st> const&,float const&);

  // ASSIGNMENT
  inline double_st& operator=(const double_st&)__attribute__((always_inline));
  inline double_st& operator=(const double&)__attribute__((always_inline));
  inline double_st& operator=(const float&)__attribute__((always_inline));
  inline double_st& operator=(const unsigned long long&)__attribute__((always_inline));
  inline double_st& operator=(const long long&)__attribute__((always_inline));
  inline double_st& operator=(const unsigned long&)__attribute__((always_inline));
  inline double_st& operator=(const long&)__attribute__((always_inline));
  inline double_st& operator=(const unsigned int&)__attribute__((always_inline));
  inline double_st& operator=(const int&)__attribute__((always_inline));
  inline double_st& operator=(const unsigned short&)__attribute__((always_inline));
  inline double_st& operator=(const short&)__attribute__((always_inline));
  inline double_st& operator=(const unsigned char&)__attribute__((always_inline));
  inline double_st& operator=(const char&)__attribute__((always_inline));

  inline double_st& operator=(const float_st&)__attribute__((always_inline));


  // ADDITION
  inline double_st operator++()__attribute__((always_inline));
  inline double_st operator++(int)__attribute__((always_inline));
  inline double_st operator+() const __attribute__((always_inline));

  inline double_st& operator+=(const double_st&)__attribute__((always_inline));
  inline double_st& operator+=(const float_st&)__attribute__((always_inline));
  inline double_st& operator+=(const double&)__attribute__((always_inline));
  inline double_st& operator+=(const float&)__attribute__((always_inline));
  inline double_st& operator+=(const unsigned long long&)__attribute__((always_inline));
  inline double_st& operator+=(const long long&)__attribute__((always_inline));
  inline double_st& operator+=(const unsigned long&)__attribute__((always_inline));
  inline double_st& operator+=(const long&)__attribute__((always_inline));
  inline double_st& operator+=(const unsigned int&)__attribute__((always_inline));
  inline double_st& operator+=(const int&)__attribute__((always_inline));
  inline double_st& operator+=(const unsigned short&)__attribute__((always_inline));
  inline double_st& operator+=(const short&)__attribute__((always_inline));
  inline double_st& operator+=(const unsigned char&)__attribute__((always_inline));
  inline double_st& operator+=(const char&)__attribute__((always_inline));


  inline friend double_st operator+(const double_st&, const double_st&)__attribute__((always_inline)); 
  inline friend double_st operator+(const double_st&, const float_st&)__attribute__((always_inline));
  inline friend double_st operator+(const float_st&,  const double_st&)__attribute__((always_inline));
  
  inline friend double_st operator+(const double_st&, const double&)__attribute__((always_inline));
  inline friend double_st operator+(const double_st&, const float&)__attribute__((always_inline));
  inline friend double_st operator+(const double_st&, const unsigned long long&)__attribute__((always_inline));
  inline friend double_st operator+(const double_st&, const long long&)__attribute__((always_inline));
  inline friend double_st operator+(const double_st&, const unsigned long&)__attribute__((always_inline));
  inline friend double_st operator+(const double_st&, const long&)__attribute__((always_inline));
  inline friend double_st operator+(const double_st&, const unsigned int&)__attribute__((always_inline));
  inline friend double_st operator+(const double_st&, const int&)__attribute__((always_inline));
  inline friend double_st operator+(const double_st&, const unsigned short&)__attribute__((always_inline));
  inline friend double_st operator+(const double_st&, const short&)__attribute__((always_inline));
  inline friend double_st operator+(const double_st&, const unsigned char&)__attribute__((always_inline));
  inline friend double_st operator+(const double_st&, const char&)__attribute__((always_inline));

  inline friend double_st operator+(const double&, const double_st&)__attribute__((always_inline));
  inline friend double_st operator+(const float&, const double_st&)__attribute__((always_inline));
  inline friend double_st operator+(const unsigned long long&, const double_st&)__attribute__((always_inline));
  inline friend double_st operator+(const long long&, const double_st&)__attribute__((always_inline));
  inline friend double_st operator+(const unsigned long&, const double_st&)__attribute__((always_inline));
  inline friend double_st operator+(const long&, const double_st&)__attribute__((always_inline));
  inline friend double_st operator+(const unsigned int&, const double_st&)__attribute__((always_inline));
  inline friend double_st operator+(const int&, const double_st&)__attribute__((always_inline));
  inline friend double_st operator+(const unsigned short&, const double_st&)__attribute__((always_inline));
  inline friend double_st operator+(const short&, const double_st&)__attribute__((always_inline));
  inline friend double_st operator+(const unsigned char&, const double_st&)__attribute__((always_inline));
  inline friend double_st operator+(const char&, const double_st&)__attribute__((always_inline));


      
  // SUBTRACTION
  inline double_st operator--()__attribute__((always_inline));
  inline double_st operator--(int)__attribute__((always_inline));
  inline double_st operator-() const __attribute__((always_inline));

  inline double_st& operator-=(const double_st&)__attribute__((always_inline));
  inline double_st& operator-=(const float_st&)__attribute__((always_inline));
  inline double_st& operator-=(const double&)__attribute__((always_inline));
  inline double_st& operator-=(const float&)__attribute__((always_inline));
  inline double_st& operator-=(const unsigned long long&)__attribute__((always_inline));
  inline double_st& operator-=(const long long&)__attribute__((always_inline));
  inline double_st& operator-=(const unsigned long&)__attribute__((always_inline));
  inline double_st& operator-=(const long&)__attribute__((always_inline));
  inline double_st& operator-=(const unsigned int&)__attribute__((always_inline));
  inline double_st& operator-=(const int&)__attribute__((always_inline));
  inline double_st& operator-=(const unsigned short&)__attribute__((always_inline));
  inline double_st& operator-=(const short&)__attribute__((always_inline));
  inline double_st& operator-=(const unsigned char&)__attribute__((always_inline));
  inline double_st& operator-=(const char&)__attribute__((always_inline));


  inline friend double_st operator-(const double_st&, const double_st&)__attribute__((always_inline)); 
  inline friend double_st operator-(const double_st&, const float_st&)__attribute__((always_inline));
  inline friend double_st operator-(const float_st&, const double_st&)__attribute__((always_inline));
  inline friend double_st operator-(const double_st&, const double&)__attribute__((always_inline));
  inline friend double_st operator-(const double_st&, const float&)__attribute__((always_inline));
  inline friend double_st operator-(const double_st&, const unsigned long long&)__attribute__((always_inline));
  inline friend double_st operator-(const double_st&, const long long&)__attribute__((always_inline));
  inline friend double_st operator-(const double_st&, const unsigned long&)__attribute__((always_inline));
  inline friend double_st operator-(const double_st&, const long&)__attribute__((always_inline));
  inline friend double_st operator-(const double_st&, const unsigned int&)__attribute__((always_inline));
  inline friend double_st operator-(const double_st&, const int&)__attribute__((always_inline));
  inline friend double_st operator-(const double_st&, const unsigned short&)__attribute__((always_inline));
  inline friend double_st operator-(const double_st&, const short&)__attribute__((always_inline));
  inline friend double_st operator-(const double_st&, const unsigned char&)__attribute__((always_inline));
  inline friend double_st operator-(const double_st&, const char&)__attribute__((always_inline));

  inline friend double_st operator-(const double&, const double_st&)__attribute__((always_inline));
  inline friend double_st operator-(const float&, const double_st&)__attribute__((always_inline));
  inline friend double_st operator-(const unsigned long long&, const double_st&)__attribute__((always_inline));
  inline friend double_st operator-(const long long&, const double_st&)__attribute__((always_inline));
  inline friend double_st operator-(const unsigned long&, const double_st&)__attribute__((always_inline));
  inline friend double_st operator-(const long&, const double_st&)__attribute__((always_inline));
  inline friend double_st operator-(const unsigned int&, const double_st&)__attribute__((always_inline));
  inline friend double_st operator-(const int&, const double_st&)__attribute__((always_inline));
  inline friend double_st operator-(const unsigned short&, const double_st&)__attribute__((always_inline));
  inline friend double_st operator-(const short&, const double_st&)__attribute__((always_inline));
  inline friend double_st operator-(const unsigned char&, const double_st&)__attribute__((always_inline));
  inline friend double_st operator-(const char&, const double_st&)__attribute__((always_inline));

  // MULTIPLICATION

  inline double_st& operator*=(const double_st&)__attribute__((always_inline));
  inline double_st& operator*=(const float_st&)__attribute__((always_inline));
  inline double_st& operator*=(const double&)__attribute__((always_inline));
  inline double_st& operator*=(const float&)__attribute__((always_inline));
  inline double_st& operator*=(const unsigned long long&)__attribute__((always_inline));
  inline double_st& operator*=(const long long&)__attribute__((always_inline));
  inline double_st& operator*=(const unsigned long&)__attribute__((always_inline));
  inline double_st& operator*=(const long&)__attribute__((always_inline));
  inline double_st& operator*=(const unsigned int&)__attribute__((always_inline));
  inline double_st& operator*=(const int&)__attribute__((always_inline));
  inline double_st& operator*=(const unsigned short&)__attribute__((always_inline));
  inline double_st& operator*=(const short&)__attribute__((always_inline));
  inline double_st& operator*=(const unsigned char&)__attribute__((always_inline));
  inline double_st& operator*=(const char&)__attribute__((always_inline));


  inline friend double_st operator*(const double_st&, const double_st&)__attribute__((always_inline)); 
  inline friend double_st operator*(const double_st&, const float_st&)__attribute__((always_inline));
  inline friend double_st operator*(const float_st&, const double_st&)__attribute__((always_inline));

  inline friend double_st operator*(const double_st&, const double&)__attribute__((always_inline));
  inline friend double_st operator*(const double_st&, const float&)__attribute__((always_inline));
  inline friend double_st operator*(const double_st&, const unsigned long long&)__attribute__((always_inline));
  inline friend double_st operator*(const double_st&, const long long&)__attribute__((always_inline));
  inline friend double_st operator*(const double_st&, const unsigned long&)__attribute__((always_inline));
  inline friend double_st operator*(const double_st&, const long&)__attribute__((always_inline));
  inline friend double_st operator*(const double_st&, const unsigned int&)__attribute__((always_inline));
  inline friend double_st operator*(const double_st&, const int&)__attribute__((always_inline));
  inline friend double_st operator*(const double_st&, const unsigned short&)__attribute__((always_inline));
  inline friend double_st operator*(const double_st&, const short&)__attribute__((always_inline));
  inline friend double_st operator*(const double_st&, const unsigned char&)__attribute__((always_inline));
  inline friend double_st operator*(const double_st&, const char&)__attribute__((always_inline));

  inline friend double_st operator*(const double&, const double_st&)__attribute__((always_inline));
  inline friend double_st operator*(const float&, const double_st&)__attribute__((always_inline));
  inline friend double_st operator*(const unsigned long long&, const double_st&)__attribute__((always_inline));
  inline friend double_st operator*(const long long&, const double_st&)__attribute__((always_inline));
  inline friend double_st operator*(const unsigned long&, const double_st&)__attribute__((always_inline));
  inline friend double_st operator*(const long&, const double_st&)__attribute__((always_inline));
  inline friend double_st operator*(const unsigned int&, const double_st&)__attribute__((always_inline));
  inline friend double_st operator*(const int&, const double_st&)__attribute__((always_inline));
  inline friend double_st operator*(const unsigned short&, const double_st&)__attribute__((always_inline));
  inline friend double_st operator*(const short&, const double_st&)__attribute__((always_inline));
  inline friend double_st operator*(const unsigned char&, const double_st&)__attribute__((always_inline));
  inline friend double_st operator*(const char&, const double_st&)__attribute__((always_inline));

  // DIVISION

  inline double_st& operator/=(const double_st&)__attribute__((always_inline));
  inline double_st& operator/=(const float_st&)__attribute__((always_inline));
  inline double_st& operator/=(const double&)__attribute__((always_inline));
  inline double_st& operator/=(const float&)__attribute__((always_inline));
  inline double_st& operator/=(const unsigned long long&)__attribute__((always_inline));
  inline double_st& operator/=(const long long&)__attribute__((always_inline));
  inline double_st& operator/=(const unsigned long&)__attribute__((always_inline));
  inline double_st& operator/=(const long&)__attribute__((always_inline));
  inline double_st& operator/=(const unsigned int&)__attribute__((always_inline));
  inline double_st& operator/=(const int&)__attribute__((always_inline));
  inline double_st& operator/=(const unsigned short&)__attribute__((always_inline));
  inline double_st& operator/=(const short&)__attribute__((always_inline));
  inline double_st& operator/=(const unsigned char&)__attribute__((always_inline));
  inline double_st& operator/=(const char&)__attribute__((always_inline));


  inline friend double_st operator/(const double_st&, const double_st&)__attribute__((always_inline)); 
  inline friend double_st operator/(const double_st&, const float_st&)__attribute__((always_inline));
  inline friend double_st operator/(const float_st&, const double_st&)__attribute__((always_inline));
  inline friend double_st operator/(const double_st&, const double&)__attribute__((always_inline));
  inline friend double_st operator/(const double_st&, const float&)__attribute__((always_inline));
  inline friend double_st operator/(const double_st&, const unsigned long long&)__attribute__((always_inline));
  inline friend double_st operator/(const double_st&, const long long&)__attribute__((always_inline));
  inline friend double_st operator/(const double_st&, const unsigned long&)__attribute__((always_inline));
  inline friend double_st operator/(const double_st&, const long&)__attribute__((always_inline));
  inline friend double_st operator/(const double_st&, const unsigned int&)__attribute__((always_inline));
  inline friend double_st operator/(const double_st&, const int&)__attribute__((always_inline));
  inline friend double_st operator/(const double_st&, const unsigned short&)__attribute__((always_inline));
  inline friend double_st operator/(const double_st&, const short&)__attribute__((always_inline));
  inline friend double_st operator/(const double_st&, const unsigned char&)__attribute__((always_inline));
  inline friend double_st operator/(const double_st&, const char&)__attribute__((always_inline));

  inline friend double_st operator/(const double&, const double_st&)__attribute__((always_inline));
  inline friend double_st operator/(const float&, const double_st&)__attribute__((always_inline));
  inline friend double_st operator/(const unsigned long long&, const double_st&)__attribute__((always_inline));
  inline friend double_st operator/(const long long&, const double_st&)__attribute__((always_inline));
  inline friend double_st operator/(const unsigned long&, const double_st&)__attribute__((always_inline));
  inline friend double_st operator/(const long&, const double_st&)__attribute__((always_inline));
  inline friend double_st operator/(const unsigned int&, const double_st&)__attribute__((always_inline));
  inline friend double_st operator/(const int&, const double_st&)__attribute__((always_inline));
  inline friend double_st operator/(const unsigned short&, const double_st&)__attribute__((always_inline));
  inline friend double_st operator/(const short&, const double_st&)__attribute__((always_inline));
  inline friend double_st operator/(const unsigned char&, const double_st&)__attribute__((always_inline));
  inline friend double_st operator/(const char&, const double_st&)__attribute__((always_inline));
  
  
  // RELATIONAL OPERATORS

  inline friend int operator==(const double_st&, const double_st&)__attribute__((always_inline));
  inline friend int operator==(const double_st&, const float_st&)__attribute__((always_inline));
  inline friend int operator==(const float_st&, const double_st&)__attribute__((always_inline));

  inline friend int operator==(const double_st&, const double&)__attribute__((always_inline));
  inline friend int operator==(const double_st&, const float&)__attribute__((always_inline));
  inline friend int operator==(const double_st&, const unsigned long long&)__attribute__((always_inline));
  inline friend int operator==(const double_st&, const long long&)__attribute__((always_inline));
  inline friend int operator==(const double_st&, const unsigned long&)__attribute__((always_inline));
  inline friend int operator==(const double_st&, const long&)__attribute__((always_inline));
  inline friend int operator==(const double_st&, const unsigned int&)__attribute__((always_inline));
  inline friend int operator==(const double_st&, const int&)__attribute__((always_inline));
  inline friend int operator==(const double_st&, const unsigned short&)__attribute__((always_inline));
  inline friend int operator==(const double_st&, const short&)__attribute__((always_inline));
  inline friend int operator==(const double_st&, const unsigned char&)__attribute__((always_inline));
  inline friend int operator==(const double_st&, const char&)__attribute__((always_inline));

  inline friend int operator==(const double&, const double_st&)__attribute__((always_inline));
  inline friend int operator==(const float&, const double_st&)__attribute__((always_inline));
  inline friend int operator==(const unsigned long long&, const double_st&)__attribute__((always_inline));
  inline friend int operator==(const long long&, const double_st&)__attribute__((always_inline));
  inline friend int operator==(const unsigned long&, const double_st&)__attribute__((always_inline));
  inline friend int operator==(const long&, const double_st&)__attribute__((always_inline));
  inline friend int operator==(const unsigned int&, const double_st&)__attribute__((always_inline));
  inline friend int operator==(const int&, const double_st&)__attribute__((always_inline));
  inline friend int operator==(const unsigned short&, const double_st&)__attribute__((always_inline));
  inline friend int operator==(const short&, const double_st&)__attribute__((always_inline));
  inline friend int operator==(const unsigned char&, const double_st&)__attribute__((always_inline));
  inline friend int operator==(const char&, const double_st&)__attribute__((always_inline));
  


  inline friend int operator!=(const double_st&, const double_st&)__attribute__((always_inline));
  inline friend int operator!=(const double_st&, const float_st&)__attribute__((always_inline));
  inline friend int operator!=(const float_st&, const double_st&)__attribute__((always_inline));

  inline friend int operator!=(const double_st&, const double&)__attribute__((always_inline));
  inline friend int operator!=(const double_st&, const float&)__attribute__((always_inline));
  inline friend int operator!=(const double_st&, const unsigned long long&)__attribute__((always_inline));
  inline friend int operator!=(const double_st&, const long long&)__attribute__((always_inline));
  inline friend int operator!=(const double_st&, const unsigned long&)__attribute__((always_inline));
  inline friend int operator!=(const double_st&, const long&)__attribute__((always_inline));
  inline friend int operator!=(const double_st&, const unsigned int&)__attribute__((always_inline));
  inline friend int operator!=(const double_st&, const int&)__attribute__((always_inline));
  inline friend int operator!=(const double_st&, const unsigned short&)__attribute__((always_inline));
  inline friend int operator!=(const double_st&, const short&)__attribute__((always_inline));
  inline friend int operator!=(const double_st&, const unsigned char&)__attribute__((always_inline));
  inline friend int operator!=(const double_st&, const char&)__attribute__((always_inline));

  inline friend int operator!=(const double&, const double_st&)__attribute__((always_inline));
  inline friend int operator!=(const float&, const double_st&)__attribute__((always_inline));
  inline friend int operator!=(const unsigned long long&, const double_st&)__attribute__((always_inline));
  inline friend int operator!=(const long long&, const double_st&)__attribute__((always_inline));
  inline friend int operator!=(const unsigned long&, const double_st&)__attribute__((always_inline));
  inline friend int operator!=(const long&, const double_st&)__attribute__((always_inline));
  inline friend int operator!=(const unsigned int&, const double_st&)__attribute__((always_inline));
  inline friend int operator!=(const int&, const double_st&)__attribute__((always_inline));
  inline friend int operator!=(const unsigned short&, const double_st&)__attribute__((always_inline));
  inline friend int operator!=(const short&, const double_st&)__attribute__((always_inline));
  inline friend int operator!=(const unsigned char&, const double_st&)__attribute__((always_inline));
  inline friend int operator!=(const char&, const double_st&)__attribute__((always_inline));

  inline friend int operator>=(const double_st&, const double_st&)__attribute__((always_inline));
  inline friend int operator>=(const double_st&, const float_st&)__attribute__((always_inline));
  inline friend int operator>=(const float_st&, const double_st&)__attribute__((always_inline));

  inline friend int operator>=(const double_st&, const double&)__attribute__((always_inline));
  inline friend int operator>=(const double_st&, const float&)__attribute__((always_inline));
  inline friend int operator>=(const double_st&, const unsigned long long&)__attribute__((always_inline));
  inline friend int operator>=(const double_st&, const long long&)__attribute__((always_inline));
  inline friend int operator>=(const double_st&, const unsigned long&)__attribute__((always_inline));
  inline friend int operator>=(const double_st&, const long&)__attribute__((always_inline));
  inline friend int operator>=(const double_st&, const unsigned int&)__attribute__((always_inline));
  inline friend int operator>=(const double_st&, const int&)__attribute__((always_inline));
  inline friend int operator>=(const double_st&, const unsigned short&)__attribute__((always_inline));
  inline friend int operator>=(const double_st&, const short&)__attribute__((always_inline));
  inline friend int operator>=(const double_st&, const unsigned char&)__attribute__((always_inline));
  inline friend int operator>=(const double_st&, const char&)__attribute__((always_inline));

  inline friend int operator>=(const double&, const double_st&)__attribute__((always_inline));
  inline friend int operator>=(const float&, const double_st&)__attribute__((always_inline));
  inline friend int operator>=(const unsigned long long&, const double_st&)__attribute__((always_inline));
  inline friend int operator>=(const long long&, const double_st&)__attribute__((always_inline));
  inline friend int operator>=(const unsigned long&, const double_st&)__attribute__((always_inline));
  inline friend int operator>=(const long&, const double_st&)__attribute__((always_inline));
  inline friend int operator>=(const unsigned int&, const double_st&)__attribute__((always_inline));
  inline friend int operator>=(const int&, const double_st&)__attribute__((always_inline));
  inline friend int operator>=(const unsigned short&, const double_st&)__attribute__((always_inline));
  inline friend int operator>=(const short&, const double_st&)__attribute__((always_inline));
  inline friend int operator>=(const unsigned char&, const double_st&)__attribute__((always_inline));
  inline friend int operator>=(const char&, const double_st&)__attribute__((always_inline));

  inline friend int operator>(const double_st&, const double_st&)__attribute__((always_inline));
  inline friend int operator>(const double_st&, const float_st&)__attribute__((always_inline));
  inline friend int operator>(const float_st&, const double_st&)__attribute__((always_inline));

  inline friend int operator>(const double_st&, const double&)__attribute__((always_inline));
  inline friend int operator>(const double_st&, const float&)__attribute__((always_inline));
  inline friend int operator>(const double_st&, const unsigned long long&)__attribute__((always_inline));
  inline friend int operator>(const double_st&, const long long&)__attribute__((always_inline));
  inline friend int operator>(const double_st&, const unsigned long&)__attribute__((always_inline));
  inline friend int operator>(const double_st&, const long&)__attribute__((always_inline));
  inline friend int operator>(const double_st&, const unsigned int&)__attribute__((always_inline));
  inline friend int operator>(const double_st&, const int&)__attribute__((always_inline));
  inline friend int operator>(const double_st&, const unsigned short&)__attribute__((always_inline));
  inline friend int operator>(const double_st&, const short&)__attribute__((always_inline));
  inline friend int operator>(const double_st&, const unsigned char&)__attribute__((always_inline));
  inline friend int operator>(const double_st&, const char&)__attribute__((always_inline));

  inline friend int operator>(const double&, const double_st&)__attribute__((always_inline));
  inline friend int operator>(const float&, const double_st&)__attribute__((always_inline));
  inline friend int operator>(const unsigned long long&, const double_st&)__attribute__((always_inline));
  inline friend int operator>(const long long&, const double_st&)__attribute__((always_inline));
  inline friend int operator>(const unsigned long&, const double_st&)__attribute__((always_inline));
  inline friend int operator>(const long&, const double_st&)__attribute__((always_inline));
  inline friend int operator>(const unsigned int&, const double_st&)__attribute__((always_inline));
  inline friend int operator>(const int&, const double_st&)__attribute__((always_inline));
  inline friend int operator>(const unsigned short&, const double_st&)__attribute__((always_inline));
  inline friend int operator>(const short&, const double_st&)__attribute__((always_inline));
  inline friend int operator>(const unsigned char&, const double_st&)__attribute__((always_inline));
  inline friend int operator>(const char&, const double_st&)__attribute__((always_inline));

  inline friend int operator<=(const double_st&, const double_st&)__attribute__((always_inline));
  inline friend int operator<=(const double_st&, const float_st&)__attribute__((always_inline));
  inline friend int operator<=(const float_st&, const double_st&)__attribute__((always_inline));

  inline friend int operator<=(const double_st&, const double&)__attribute__((always_inline));
  inline friend int operator<=(const double_st&, const float&)__attribute__((always_inline));
  inline friend int operator<=(const double_st&, const unsigned long long&)__attribute__((always_inline));
  inline friend int operator<=(const double_st&, const long long&)__attribute__((always_inline));
  inline friend int operator<=(const double_st&, const unsigned long&)__attribute__((always_inline));
  inline friend int operator<=(const double_st&, const long&)__attribute__((always_inline));
  inline friend int operator<=(const double_st&, const unsigned int&)__attribute__((always_inline));
  inline friend int operator<=(const double_st&, const int&)__attribute__((always_inline));
  inline friend int operator<=(const double_st&, const unsigned short&)__attribute__((always_inline));
  inline friend int operator<=(const double_st&, const short&)__attribute__((always_inline));
  inline friend int operator<=(const double_st&, const unsigned char&)__attribute__((always_inline));
  inline friend int operator<=(const double_st&, const char&)__attribute__((always_inline));

  inline friend int operator<=(const double&, const double_st&)__attribute__((always_inline));
  inline friend int operator<=(const float&, const double_st&)__attribute__((always_inline));
  inline friend int operator<=(const unsigned long long&, const double_st&)__attribute__((always_inline));
  inline friend int operator<=(const long long&, const double_st&)__attribute__((always_inline));
  inline friend int operator<=(const unsigned long&, const double_st&)__attribute__((always_inline));
  inline friend int operator<=(const long&, const double_st&)__attribute__((always_inline));
  inline friend int operator<=(const unsigned int&, const double_st&)__attribute__((always_inline));
  inline friend int operator<=(const int&, const double_st&)__attribute__((always_inline));
  inline friend int operator<=(const unsigned short&, const double_st&)__attribute__((always_inline));
  inline friend int operator<=(const short&, const double_st&)__attribute__((always_inline));
  inline friend int operator<=(const unsigned char&, const double_st&)__attribute__((always_inline));
  inline friend int operator<=(const char&, const double_st&)__attribute__((always_inline));

  inline friend int operator<(const double_st&, const double_st&)__attribute__((always_inline));
  inline friend int operator<(const double_st&, const float_st&)__attribute__((always_inline));
  inline friend int operator<(const float_st&, const double_st&)__attribute__((always_inline));

  inline friend int operator<(const double_st&, const double&)__attribute__((always_inline));
  inline friend int operator<(const double_st&, const float&)__attribute__((always_inline));
  inline friend int operator<(const double_st&, const unsigned long long&)__attribute__((always_inline));
  inline friend int operator<(const double_st&, const long long&)__attribute__((always_inline));
  inline friend int operator<(const double_st&, const unsigned long&)__attribute__((always_inline));
  inline friend int operator<(const double_st&, const long&)__attribute__((always_inline));
  inline friend int operator<(const double_st&, const unsigned int&)__attribute__((always_inline));
  inline friend int operator<(const double_st&, const int&)__attribute__((always_inline));
  inline friend int operator<(const double_st&, const unsigned short&)__attribute__((always_inline));
  inline friend int operator<(const double_st&, const short&)__attribute__((always_inline));
  inline friend int operator<(const double_st&, const unsigned char&)__attribute__((always_inline));
  inline friend int operator<(const double_st&, const char&)__attribute__((always_inline));

  inline friend int operator<(const double&, const double_st&)__attribute__((always_inline));
  inline friend int operator<(const float&, const double_st&)__attribute__((always_inline));
  inline friend int operator<(const unsigned long long&, const double_st&)__attribute__((always_inline));
  inline friend int operator<(const long long&, const double_st&)__attribute__((always_inline));
  inline friend int operator<(const unsigned long&, const double_st&)__attribute__((always_inline));
  inline friend int operator<(const long&, const double_st&)__attribute__((always_inline));
  inline friend int operator<(const unsigned int&, const double_st&)__attribute__((always_inline));
  inline friend int operator<(const int&, const double_st&)__attribute__((always_inline));
  inline friend int operator<(const unsigned short&, const double_st&)__attribute__((always_inline));
  inline friend int operator<(const short&, const double_st&)__attribute__((always_inline));
  inline friend int operator<(const unsigned char&, const double_st&)__attribute__((always_inline));
  inline friend int operator<(const char&, const double_st&)__attribute__((always_inline));


  // MATHEMATICAL FUNCTIONS 

  friend double_st  log(const double_st&);
  friend double_st  log2(const double_st&);
  friend double_st  log10(const double_st&);
  friend double_st  log1p(const double_st&);
  friend double_st  logb(const double_st&);
  friend double_st  exp(const double_st&); 
  friend double_st  exp2(const double_st&); 
  friend double_st  expm1(const double_st&); 
  friend double_st  sqrt(const double_st&);
  friend double_st  cbrt(const double_st&);
  friend double_st  sin(const double_st&);
  friend double_st  cos(const double_st&);
  friend double_st  tan(const double_st&);
  friend double_st  asin(const double_st&);
  friend double_st  acos(const double_st&);
  friend double_st  atan(const double_st&);
  friend double_st  atan2(const double_st&, const double_st&);
  friend double_st  atan2(const double_st&, const float_st&);
  friend double_st  atan2(const float_st&, const double_st&);
  friend double_st  sinh(const double_st&);
  friend double_st  cosh(const double_st&);
  friend double_st  tanh(const double_st&);
  friend double_st  asinh(const double_st&);
  friend double_st  acosh(const double_st&);
  friend double_st  atanh(const double_st&);
  friend double_st  hypot(const double_st&, const double_st&);
  friend double_st  hypot(const double_st&, const float_st&);
  friend double_st  hypot(const float_st&, const double_st&);

  friend double_st pow(const double_st&, const double_st&);  
  friend double_st pow(const double_st&, const float_st&);  
  friend double_st pow(const float_st&, const double_st&);  
  friend double_st pow(const double_st&, const double&);
  friend double_st pow(const double_st&, const float&);
  friend double_st pow(const double_st&, const unsigned long long&);
  friend double_st pow(const double_st&, const long long&);
  friend double_st pow(const double_st&, const unsigned long&);
  friend double_st pow(const double_st&, const long&);
  friend double_st pow(const double_st&, const unsigned int&);
  friend double_st pow(const double_st&, const int&);
  friend double_st pow(const double_st&, const unsigned short&);
  friend double_st pow(const double_st&, const short&);
  friend double_st pow(const double_st&, const unsigned char&);
  friend double_st pow(const double_st&, const char&);

  friend double_st pow(const double&, const double_st&);
  friend double_st pow(const float&, const double_st&);
  friend double_st pow(const unsigned long long&, const double_st&);
  friend double_st pow(const long long&, const double_st&);
  friend double_st pow(const unsigned long&, const double_st&);
  friend double_st pow(const long&, const double_st&);
  friend double_st pow(const unsigned int&, const double_st&);
  friend double_st pow(const int&, const double_st&);
  friend double_st pow(const unsigned short&, const double_st&);
  friend double_st pow(const short&, const double_st&);
  friend double_st pow(const unsigned char&, const double_st&);
  friend double_st pow(const char&, const double_st&);


  friend double_st fmax(const double_st&, const double_st&);  
  friend double_st fmax(const double_st&, const float_st&);  
  friend double_st fmax(const float_st&, const double_st&);  
  friend double_st fmax(const double_st&, const double&);
  friend double_st fmax(const double_st&, const float&);
  friend double_st fmax(const double_st&, const unsigned long long&);
  friend double_st fmax(const double_st&, const long long&);
  friend double_st fmax(const double_st&, const unsigned long&);
  friend double_st fmax(const double_st&, const long&);
  friend double_st fmax(const double_st&, const unsigned int&);
  friend double_st fmax(const double_st&, const int&);
  friend double_st fmax(const double_st&, const unsigned short&);
  friend double_st fmax(const double_st&, const short&);
  friend double_st fmax(const double_st&, const unsigned char&);
  friend double_st fmax(const double_st&, const char&);

  friend double_st fmax(const double&, const double_st&);
  friend double_st fmax(const float&, const double_st&);
  friend double_st fmax(const unsigned long long&, const double_st&);
  friend double_st fmax(const long long&, const double_st&);
  friend double_st fmax(const unsigned long&, const double_st&);
  friend double_st fmax(const long&, const double_st&);
  friend double_st fmax(const unsigned int&, const double_st&);
  friend double_st fmax(const int&, const double_st&);
  friend double_st fmax(const unsigned short&, const double_st&);
  friend double_st fmax(const short&, const double_st&);
  friend double_st fmax(const unsigned char&, const double_st&);
  friend double_st fmax(const char&, const double_st&);


  friend double_st fmin(const double_st&, const double_st&);  
  friend double_st fmin(const double_st&, const float_st&);  
  friend double_st fmin(const float_st&, const double_st&);  
  
  friend double_st fmin(const double_st&, const double&);
  friend double_st fmin(const double_st&, const float&);
  friend double_st fmin(const double_st&, const unsigned long long&);
  friend double_st fmin(const double_st&, const long long&);
  friend double_st fmin(const double_st&, const unsigned long&);
  friend double_st fmin(const double_st&, const long&);
  friend double_st fmin(const double_st&, const unsigned int&);
  friend double_st fmin(const double_st&, const int&);
  friend double_st fmin(const double_st&, const unsigned short&);
  friend double_st fmin(const double_st&, const short&);
  friend double_st fmin(const double_st&, const unsigned char&);
  friend double_st fmin(const double_st&, const char&);

  friend double_st fmin(const double&, const double_st&);
  friend double_st fmin(const float&, const double_st&);
  friend double_st fmin(const unsigned long long&, const double_st&);
  friend double_st fmin(const long long&, const double_st&);
  friend double_st fmin(const unsigned long&, const double_st&);
  friend double_st fmin(const long&, const double_st&);
  friend double_st fmin(const unsigned int&, const double_st&);
  friend double_st fmin(const int&, const double_st&);
  friend double_st fmin(const unsigned short&, const double_st&);
  friend double_st fmin(const short&, const double_st&);
  friend double_st fmin(const unsigned char&, const double_st&);
  friend double_st fmin(const char&, const double_st&);

  friend double_st frexp(const double_st&, int* );
  friend double_st modf(const  double_st&,  double_st*);
  friend double_st ldexp(const double_st&, const int);
  friend double_st fmod(const double_st&, const double_st&);

  // INTRINSIC FUNCTIONS
  
  friend double_st fabs(const double_st&);
  friend double_st abs(const double_st&);
  friend double_st floor(const double_st&);
  friend double_st ceil(const double_st&);
  friend double_st trunc(const double_st&);
  friend double_st nearbyint(const double_st&);
  friend double_st rint(const double_st&);
  friend long int  lrint(const double_st&);
  friend long long int llrint(const double_st&);

  friend int finite(const double_st&);
  friend int isfinite(const double_st&);
  friend int isnan(const double_st&);
  friend int isinf(const double_st&);


  // Conversion
  operator char();  
  operator unsigned char();  
  operator short();  
  operator unsigned short();  
  operator int();  
  operator unsigned int();  
  operator long();  
  operator unsigned long();  
  operator long long();  
  operator unsigned long long();  
  operator float();
  operator double();

  operator float_st() const;
  operator char() const;  
  operator unsigned char() const;  
  operator short() const;  
  operator unsigned short() const;  
  operator int() const;  
  operator unsigned int() const;  
  operator long() const;  
  operator unsigned long() const;  
  operator long long() const;  
  operator unsigned long long() const;  
  operator float() const;
  operator double() const;
  
  inline int nb_significant_digit() const __attribute__((always_inline));
  inline int approx_digit() const __attribute__((always_inline));
  inline int computedzero() const __attribute__((always_inline));
  inline int numericalnoise() const __attribute__((always_inline));
  void display() const ; 
  void display(const char *) const ; 
  char* str( char *)  const ;
  
  friend char* strp(const double_st&);
  friend char* str( char *, const double_st&);
  
  friend std::istream& operator >>(std::istream& s, double_st& );  
  
  void data_st();
  void data_st(const double&, const int&);
  
};

std::ostream& operator<<(std::ostream&, const double_st&);
std::istream& operator >>(std::istream&, double_st& );

///////////////////////////////
///////////////////////////////
///////////////////////////////

class float_st {
  friend class double_st;

protected:
  float x,y,z;
  
  typedef float TYPEBASE;
  
private:
  mutable int accuracy;
  
public:

  inline float_st(void) :x(0),y(0),z(0),accuracy(7) {};
  inline float_st(const double &a, const double &b, const double &c):x(a),y(b),z(c),accuracy(-1) {};

  inline float_st(const double &a): x(a),y(a),z(a),accuracy(7) {};
  inline float_st (const double_st&a) : x(a.x),y(a.y),z(a.z),accuracy(a.accuracy>8?7:a.accuracy) {};

  float getx() {return(this->x);}
  float gety() {return(this->y);}
  float getz() {return(this->z);}
  int getaccuracy() {return(this->accuracy);}


  // ASSIGNMENT

  inline float_st& operator=(const float_st&)__attribute__((always_inline)); 
  inline float_st& operator=(const double&)__attribute__((always_inline));
  inline float_st& operator=(const float&)__attribute__((always_inline));
  inline float_st& operator=(const unsigned long long&)__attribute__((always_inline));
  inline float_st& operator=(const long long&)__attribute__((always_inline));
  inline float_st& operator=(const unsigned long&)__attribute__((always_inline));
  inline float_st& operator=(const long&)__attribute__((always_inline));
  inline float_st& operator=(const unsigned int&)__attribute__((always_inline));
  inline float_st& operator=(const int&)__attribute__((always_inline));
  inline float_st& operator=(const unsigned short&)__attribute__((always_inline));
  inline float_st& operator=(const short&)__attribute__((always_inline));
  inline float_st& operator=(const unsigned char&)__attribute__((always_inline));
  inline float_st& operator=(const char&)__attribute__((always_inline));
  
  inline float_st& operator=(const double_st&)__attribute__((always_inline));


  // ADDITION
  inline float_st operator++()__attribute__((always_inline));
  inline float_st operator++(int)__attribute__((always_inline));
  inline float_st operator+() const __attribute__((always_inline)); 

  inline float_st& operator+=(const double_st&)__attribute__((always_inline));
  inline float_st& operator+=(const float_st&)__attribute__((always_inline));
  inline float_st& operator+=(const double&)__attribute__((always_inline));
  inline float_st& operator+=(const float&)__attribute__((always_inline));
  inline float_st& operator+=(const unsigned long long&)__attribute__((always_inline));
  inline float_st& operator+=(const long long&)__attribute__((always_inline));
  inline float_st& operator+=(const unsigned long&)__attribute__((always_inline));
  inline float_st& operator+=(const long&)__attribute__((always_inline));
  inline float_st& operator+=(const unsigned int&)__attribute__((always_inline));
  inline float_st& operator+=(const int&)__attribute__((always_inline));
  inline float_st& operator+=(const unsigned short&)__attribute__((always_inline));
  inline float_st& operator+=(const short&)__attribute__((always_inline));
  inline float_st& operator+=(const unsigned char&)__attribute__((always_inline));
  inline float_st& operator+=(const char&)__attribute__((always_inline));

  inline friend double_st operator+(const double_st&, const float_st&)__attribute__((always_inline));  
  inline friend double_st operator+(const float_st&,  const double_st&)__attribute__((always_inline));  
  inline friend float_st operator+(const float_st&, const float_st&)__attribute__((always_inline));  

  inline friend float_st operator+(const float_st&, const double&)__attribute__((always_inline));
  inline friend float_st operator+(const float_st&, const float&)__attribute__((always_inline));
  inline friend float_st operator+(const float_st&, const unsigned long long&)__attribute__((always_inline));
  inline friend float_st operator+(const float_st&, const long long&)__attribute__((always_inline));
  inline friend float_st operator+(const float_st&, const unsigned long&)__attribute__((always_inline));
  inline friend float_st operator+(const float_st&, const long&)__attribute__((always_inline));
  inline friend float_st operator+(const float_st&, const unsigned int&)__attribute__((always_inline));
  inline friend float_st operator+(const float_st&, const int&)__attribute__((always_inline));
  inline friend float_st operator+(const float_st&, const unsigned short&)__attribute__((always_inline));
  inline friend float_st operator+(const float_st&, const short&)__attribute__((always_inline));
  inline friend float_st operator+(const float_st&, const unsigned char&)__attribute__((always_inline));
  inline friend float_st operator+(const float_st&, const char&)__attribute__((always_inline));

  inline friend float_st operator+(const double&, const float_st&)__attribute__((always_inline));
  inline friend float_st operator+(const float&, const float_st&)__attribute__((always_inline));
  inline friend float_st operator+(const unsigned long long&, const float_st&)__attribute__((always_inline));
  inline friend float_st operator+(const long long&, const float_st&)__attribute__((always_inline));
  inline friend float_st operator+(const unsigned long&, const float_st&)__attribute__((always_inline));
  inline friend float_st operator+(const long&, const float_st&)__attribute__((always_inline));
  inline friend float_st operator+(const unsigned int&, const float_st&)__attribute__((always_inline));
  inline friend float_st operator+(const int&, const float_st&)__attribute__((always_inline));
  inline friend float_st operator+(const unsigned short&, const float_st&)__attribute__((always_inline));
  inline friend float_st operator+(const short&, const float_st&)__attribute__((always_inline));
  inline friend float_st operator+(const unsigned char&, const float_st&)__attribute__((always_inline));
  inline friend float_st operator+(const char&, const float_st&)__attribute__((always_inline));

      
  // SUBTRACTION

  inline float_st operator--()__attribute__((always_inline));
  inline float_st operator--(int)__attribute__((always_inline));
  inline float_st operator-() const __attribute__((always_inline)); 

  inline float_st& operator-=(const double_st&)__attribute__((always_inline));
  inline float_st& operator-=(const float_st&)__attribute__((always_inline));
  inline float_st& operator-=(const double&)__attribute__((always_inline));
  inline float_st& operator-=(const float&)__attribute__((always_inline));
  inline float_st& operator-=(const unsigned long long&)__attribute__((always_inline));
  inline float_st& operator-=(const long long&)__attribute__((always_inline));
  inline float_st& operator-=(const unsigned long&)__attribute__((always_inline));
  inline float_st& operator-=(const long&)__attribute__((always_inline));
  inline float_st& operator-=(const unsigned int&)__attribute__((always_inline));
  inline float_st& operator-=(const int&)__attribute__((always_inline));
  inline float_st& operator-=(const unsigned short&)__attribute__((always_inline));
  inline float_st& operator-=(const short&)__attribute__((always_inline));
  inline float_st& operator-=(const unsigned char&)__attribute__((always_inline));
  inline float_st& operator-=(const char&)__attribute__((always_inline));

  inline friend double_st operator-(const double_st&, const float_st&)__attribute__((always_inline));  
  inline friend double_st operator-(const float_st&, const double_st&)__attribute__((always_inline));  
  inline friend float_st operator-(const float_st&, const float_st&)__attribute__((always_inline));  

  inline friend float_st operator-(const float_st&, const double&)__attribute__((always_inline));
  inline friend float_st operator-(const float_st&, const float&)__attribute__((always_inline));
  inline friend float_st operator-(const float_st&, const unsigned long long&)__attribute__((always_inline));
  inline friend float_st operator-(const float_st&, const long long&)__attribute__((always_inline));
  inline friend float_st operator-(const float_st&, const unsigned long&)__attribute__((always_inline));
  inline friend float_st operator-(const float_st&, const long&)__attribute__((always_inline));
  inline friend float_st operator-(const float_st&, const unsigned int&)__attribute__((always_inline));
  inline friend float_st operator-(const float_st&, const int&)__attribute__((always_inline));
  inline friend float_st operator-(const float_st&, const unsigned short&)__attribute__((always_inline));
  inline friend float_st operator-(const float_st&, const short&)__attribute__((always_inline));
  inline friend float_st operator-(const float_st&, const unsigned char&)__attribute__((always_inline));
  inline friend float_st operator-(const float_st&, const char&)__attribute__((always_inline));

  inline friend float_st operator-(const double&, const float_st&)__attribute__((always_inline));
  inline friend float_st operator-(const float&, const float_st&)__attribute__((always_inline));
  inline friend float_st operator-(const unsigned long long&, const float_st&)__attribute__((always_inline));
  inline friend float_st operator-(const long long&, const float_st&)__attribute__((always_inline));
  inline friend float_st operator-(const unsigned long&, const float_st&)__attribute__((always_inline));
  inline friend float_st operator-(const long&, const float_st&)__attribute__((always_inline));
  inline friend float_st operator-(const unsigned int&, const float_st&)__attribute__((always_inline));
  inline friend float_st operator-(const int&, const float_st&)__attribute__((always_inline));
  inline friend float_st operator-(const unsigned short&, const float_st&)__attribute__((always_inline));
  inline friend float_st operator-(const short&, const float_st&)__attribute__((always_inline));
  inline friend float_st operator-(const unsigned char&, const float_st&)__attribute__((always_inline));
  inline friend float_st operator-(const char&, const float_st&)__attribute__((always_inline));
    
  // PRODUCT

  inline float_st& operator*=(const double_st&)__attribute__((always_inline));
  inline float_st& operator*=(const float_st&)__attribute__((always_inline));
  inline float_st& operator*=(const double&)__attribute__((always_inline));
  inline float_st& operator*=(const float&)__attribute__((always_inline));
  inline float_st& operator*=(const unsigned long long&)__attribute__((always_inline));
  inline float_st& operator*=(const long long&)__attribute__((always_inline));
  inline float_st& operator*=(const unsigned long&)__attribute__((always_inline));
  inline float_st& operator*=(const long&)__attribute__((always_inline));
  inline float_st& operator*=(const unsigned int&)__attribute__((always_inline));
  inline float_st& operator*=(const int&)__attribute__((always_inline));
  inline float_st& operator*=(const unsigned short&)__attribute__((always_inline));
  inline float_st& operator*=(const short&)__attribute__((always_inline));
  inline float_st& operator*=(const unsigned char&)__attribute__((always_inline));
  inline float_st& operator*=(const char&)__attribute__((always_inline));

  inline friend double_st operator*(const double_st&, const float_st&)__attribute__((always_inline));  
  inline friend double_st operator*(const float_st&, const double_st&)__attribute__((always_inline));  
  inline friend float_st operator*(const float_st&, const float_st&)__attribute__((always_inline));  

  inline friend float_st operator*(const float_st&, const double&)__attribute__((always_inline));
  inline friend float_st operator*(const float_st&, const float&)__attribute__((always_inline));
  inline friend float_st operator*(const float_st&, const unsigned long long&)__attribute__((always_inline));
  inline friend float_st operator*(const float_st&, const long long&)__attribute__((always_inline));
  inline friend float_st operator*(const float_st&, const unsigned long&)__attribute__((always_inline));
  inline friend float_st operator*(const float_st&, const long&)__attribute__((always_inline));
  inline friend float_st operator*(const float_st&, const unsigned int&)__attribute__((always_inline));
  inline friend float_st operator*(const float_st&, const int&)__attribute__((always_inline));
  inline friend float_st operator*(const float_st&, const unsigned short&)__attribute__((always_inline));
  inline friend float_st operator*(const float_st&, const short&)__attribute__((always_inline));
  inline friend float_st operator*(const float_st&, const unsigned char&)__attribute__((always_inline));
  inline friend float_st operator*(const float_st&, const char&)__attribute__((always_inline));

  inline friend float_st operator*(const double&, const float_st&)__attribute__((always_inline));
  inline friend float_st operator*(const float&, const float_st&)__attribute__((always_inline));
  inline friend float_st operator*(const unsigned long long&, const float_st&)__attribute__((always_inline));
  inline friend float_st operator*(const long long&, const float_st&)__attribute__((always_inline));
  inline friend float_st operator*(const unsigned long&, const float_st&)__attribute__((always_inline));
  inline friend float_st operator*(const long&, const float_st&)__attribute__((always_inline));
  inline friend float_st operator*(const unsigned int&, const float_st&)__attribute__((always_inline));
  inline friend float_st operator*(const int&, const float_st&)__attribute__((always_inline));
  inline friend float_st operator*(const unsigned short&, const float_st&)__attribute__((always_inline));
  inline friend float_st operator*(const short&, const float_st&)__attribute__((always_inline));
  inline friend float_st operator*(const unsigned char&, const float_st&)__attribute__((always_inline));
  inline friend float_st operator*(const char&, const float_st&)__attribute__((always_inline));

  // DIVISION
  
  inline float_st& operator/=(const double_st&)__attribute__((always_inline));
  inline float_st& operator/=(const float_st&)__attribute__((always_inline));
  inline float_st& operator/=(const double&)__attribute__((always_inline));
  inline float_st& operator/=(const float&)__attribute__((always_inline));
  inline float_st& operator/=(const unsigned long long&)__attribute__((always_inline));
  inline float_st& operator/=(const long long&)__attribute__((always_inline));
  inline float_st& operator/=(const unsigned long&)__attribute__((always_inline));
  inline float_st& operator/=(const long&)__attribute__((always_inline));
  inline float_st& operator/=(const unsigned int&)__attribute__((always_inline));
  inline float_st& operator/=(const int&)__attribute__((always_inline));
  inline float_st& operator/=(const unsigned short&)__attribute__((always_inline));
  inline float_st& operator/=(const short&)__attribute__((always_inline));
  inline float_st& operator/=(const unsigned char&)__attribute__((always_inline));
  inline float_st& operator/=(const char&)__attribute__((always_inline));

  inline friend double_st operator/(const double_st&, const float_st&)__attribute__((always_inline));  
  inline friend double_st operator/(const float_st&, const double_st&)__attribute__((always_inline));  
  inline friend float_st operator/(const float_st&, const float_st&)__attribute__((always_inline));  

  inline friend float_st operator/(const float_st&, const double&)__attribute__((always_inline));
  inline friend float_st operator/(const float_st&, const float&)__attribute__((always_inline));
  inline friend float_st operator/(const float_st&, const unsigned long long&)__attribute__((always_inline));
  inline friend float_st operator/(const float_st&, const long long&)__attribute__((always_inline));
  inline friend float_st operator/(const float_st&, const unsigned long&)__attribute__((always_inline));
  inline friend float_st operator/(const float_st&, const long&)__attribute__((always_inline));
  inline friend float_st operator/(const float_st&, const unsigned int&)__attribute__((always_inline));
  inline friend float_st operator/(const float_st&, const int&)__attribute__((always_inline));
  inline friend float_st operator/(const float_st&, const unsigned short&)__attribute__((always_inline));
  inline friend float_st operator/(const float_st&, const short&)__attribute__((always_inline));
  inline friend float_st operator/(const float_st&, const unsigned char&)__attribute__((always_inline));
  inline friend float_st operator/(const float_st&, const char&)__attribute__((always_inline));

  inline friend float_st operator/(const double&, const float_st&)__attribute__((always_inline));
  inline friend float_st operator/(const float&, const float_st&)__attribute__((always_inline));
  inline friend float_st operator/(const unsigned long long&, const float_st&)__attribute__((always_inline));
  inline friend float_st operator/(const long long&, const float_st&)__attribute__((always_inline));
  inline friend float_st operator/(const unsigned long&, const float_st&)__attribute__((always_inline));
  inline friend float_st operator/(const long&, const float_st&)__attribute__((always_inline));
  inline friend float_st operator/(const unsigned int&, const float_st&)__attribute__((always_inline));
  inline friend float_st operator/(const int&, const float_st&)__attribute__((always_inline));
  inline friend float_st operator/(const unsigned short&, const float_st&)__attribute__((always_inline));
  inline friend float_st operator/(const short&, const float_st&)__attribute__((always_inline));
  inline friend float_st operator/(const unsigned char&, const float_st&)__attribute__((always_inline));
  inline friend float_st operator/(const char&, const float_st&)__attribute__((always_inline));


  // RELATIONAL OPERATORS

  inline friend int operator==(const double_st&, const float_st&)__attribute__((always_inline));  
  inline friend int operator==(const float_st&, const double_st&)__attribute__((always_inline));  
  inline friend int operator==(const float_st&, const float_st&)__attribute__((always_inline));  

  inline friend int operator==(const float_st&, const double&)__attribute__((always_inline));
  inline friend int operator==(const float_st&, const float&)__attribute__((always_inline));
  inline friend int operator==(const float_st&, const unsigned long long&)__attribute__((always_inline));
  inline friend int operator==(const float_st&, const long long&)__attribute__((always_inline));
  inline friend int operator==(const float_st&, const unsigned long&)__attribute__((always_inline));
  inline friend int operator==(const float_st&, const long&)__attribute__((always_inline));
  inline friend int operator==(const float_st&, const unsigned int&)__attribute__((always_inline));
  inline friend int operator==(const float_st&, const int&)__attribute__((always_inline));
  inline friend int operator==(const float_st&, const unsigned short&)__attribute__((always_inline));
  inline friend int operator==(const float_st&, const short&)__attribute__((always_inline));
  inline friend int operator==(const float_st&, const unsigned char&)__attribute__((always_inline));
  inline friend int operator==(const float_st&, const char&)__attribute__((always_inline));

  inline friend int operator==(const double&, const float_st&)__attribute__((always_inline));
  inline friend int operator==(const float&, const float_st&)__attribute__((always_inline));
  inline friend int operator==(const unsigned long long&, const float_st&)__attribute__((always_inline));
  inline friend int operator==(const long long&, const float_st&)__attribute__((always_inline));
  inline friend int operator==(const unsigned long&, const float_st&)__attribute__((always_inline));
  inline friend int operator==(const long&, const float_st&)__attribute__((always_inline));
  inline friend int operator==(const unsigned int&, const float_st&)__attribute__((always_inline));
  inline friend int operator==(const int&, const float_st&)__attribute__((always_inline));
  inline friend int operator==(const unsigned short&, const float_st&)__attribute__((always_inline));
  inline friend int operator==(const short&, const float_st&)__attribute__((always_inline));
  inline friend int operator==(const unsigned char&, const float_st&)__attribute__((always_inline));
  inline friend int operator==(const char&, const float_st&)__attribute__((always_inline));
  
  inline friend int operator!=(const double_st&, const float_st&)__attribute__((always_inline));  
  inline friend int operator!=(const float_st&, const double_st&)__attribute__((always_inline));  
  inline friend int operator!=(const float_st&, const float_st&)__attribute__((always_inline));  

  inline friend int operator!=(const float_st&, const double&)__attribute__((always_inline));
  inline friend int operator!=(const float_st&, const float&)__attribute__((always_inline));
  inline friend int operator!=(const float_st&, const unsigned long long&)__attribute__((always_inline));
  inline friend int operator!=(const float_st&, const long long&)__attribute__((always_inline));
  inline friend int operator!=(const float_st&, const unsigned long&)__attribute__((always_inline));
  inline friend int operator!=(const float_st&, const long&)__attribute__((always_inline));
  inline friend int operator!=(const float_st&, const unsigned int&)__attribute__((always_inline));
  inline friend int operator!=(const float_st&, const int&)__attribute__((always_inline));
  inline friend int operator!=(const float_st&, const unsigned short&)__attribute__((always_inline));
  inline friend int operator!=(const float_st&, const short&)__attribute__((always_inline));
  inline friend int operator!=(const float_st&, const unsigned char&)__attribute__((always_inline));
  inline friend int operator!=(const float_st&, const char&)__attribute__((always_inline));

  inline friend int operator!=(const double&, const float_st&)__attribute__((always_inline));
  inline friend int operator!=(const float&, const float_st&)__attribute__((always_inline));
  inline friend int operator!=(const unsigned long long&, const float_st&)__attribute__((always_inline));
  inline friend int operator!=(const long long&, const float_st&)__attribute__((always_inline));
  inline friend int operator!=(const unsigned long&, const float_st&)__attribute__((always_inline));
  inline friend int operator!=(const long&, const float_st&)__attribute__((always_inline));
  inline friend int operator!=(const unsigned int&, const float_st&)__attribute__((always_inline));
  inline friend int operator!=(const int&, const float_st&)__attribute__((always_inline));
  inline friend int operator!=(const unsigned short&, const float_st&)__attribute__((always_inline));
  inline friend int operator!=(const short&, const float_st&)__attribute__((always_inline));
  inline friend int operator!=(const unsigned char&, const float_st&)__attribute__((always_inline));
  inline friend int operator!=(const char&, const float_st&)__attribute__((always_inline));

  inline friend int operator>=(const double_st&, const float_st&)__attribute__((always_inline));  
  inline friend int operator>=(const float_st&, const double_st&)__attribute__((always_inline));  
  inline friend int operator>=(const float_st&, const float_st&)__attribute__((always_inline));  

  inline friend int operator>=(const float_st&, const double&)__attribute__((always_inline));
  inline friend int operator>=(const float_st&, const float&)__attribute__((always_inline));
  inline friend int operator>=(const float_st&, const unsigned long long&)__attribute__((always_inline));
  inline friend int operator>=(const float_st&, const long long&)__attribute__((always_inline));
  inline friend int operator>=(const float_st&, const unsigned long&)__attribute__((always_inline));
  inline friend int operator>=(const float_st&, const long&)__attribute__((always_inline));
  inline friend int operator>=(const float_st&, const unsigned int&)__attribute__((always_inline));
  inline friend int operator>=(const float_st&, const int&)__attribute__((always_inline));
  inline friend int operator>=(const float_st&, const unsigned short&)__attribute__((always_inline));
  inline friend int operator>=(const float_st&, const short&)__attribute__((always_inline));
  inline friend int operator>=(const float_st&, const unsigned char&)__attribute__((always_inline));
  inline friend int operator>=(const float_st&, const char&)__attribute__((always_inline));

  inline friend int operator>=(const double&, const float_st&)__attribute__((always_inline));
  inline friend int operator>=(const float&, const float_st&)__attribute__((always_inline));
  inline friend int operator>=(const unsigned long long&, const float_st&)__attribute__((always_inline));
  inline friend int operator>=(const long long&, const float_st&)__attribute__((always_inline));
  inline friend int operator>=(const unsigned long&, const float_st&)__attribute__((always_inline));
  inline friend int operator>=(const long&, const float_st&)__attribute__((always_inline));
  inline friend int operator>=(const unsigned int&, const float_st&)__attribute__((always_inline));
  inline friend int operator>=(const int&, const float_st&)__attribute__((always_inline));
  inline friend int operator>=(const unsigned short&, const float_st&)__attribute__((always_inline));
  inline friend int operator>=(const short&, const float_st&)__attribute__((always_inline));
  inline friend int operator>=(const unsigned char&, const float_st&)__attribute__((always_inline));
  inline friend int operator>=(const char&, const float_st&)__attribute__((always_inline));

  inline friend int operator>(const double_st&, const float_st&)__attribute__((always_inline));  
  inline friend int operator>(const float_st&, const double_st&)__attribute__((always_inline));  
  inline friend int operator>(const float_st&, const float_st&)__attribute__((always_inline));
  
  inline friend int operator>(const float_st&, const double&)__attribute__((always_inline));
  inline friend int operator>(const float_st&, const float&)__attribute__((always_inline));
  inline friend int operator>(const float_st&, const unsigned long long&)__attribute__((always_inline));
  inline friend int operator>(const float_st&, const long long&)__attribute__((always_inline));
  inline friend int operator>(const float_st&, const unsigned long&)__attribute__((always_inline));
  inline friend int operator>(const float_st&, const long&)__attribute__((always_inline));
  inline friend int operator>(const float_st&, const unsigned int&)__attribute__((always_inline));
  inline friend int operator>(const float_st&, const int&)__attribute__((always_inline));
  inline friend int operator>(const float_st&, const unsigned short&)__attribute__((always_inline));
  inline friend int operator>(const float_st&, const short&)__attribute__((always_inline));
  inline friend int operator>(const float_st&, const unsigned char&)__attribute__((always_inline));
  inline friend int operator>(const float_st&, const char&)__attribute__((always_inline));

  inline friend int operator>(const double&, const float_st&)__attribute__((always_inline));
  inline friend int operator>(const float&, const float_st&)__attribute__((always_inline));
  inline friend int operator>(const unsigned long long&, const float_st&)__attribute__((always_inline));
  inline friend int operator>(const long long&, const float_st&)__attribute__((always_inline));
  inline friend int operator>(const unsigned long&, const float_st&)__attribute__((always_inline));
  inline friend int operator>(const long&, const float_st&)__attribute__((always_inline));
  inline friend int operator>(const unsigned int&, const float_st&)__attribute__((always_inline));
  inline friend int operator>(const int&, const float_st&)__attribute__((always_inline));
  inline friend int operator>(const unsigned short&, const float_st&)__attribute__((always_inline));
  inline friend int operator>(const short&, const float_st&)__attribute__((always_inline));
  inline friend int operator>(const unsigned char&, const float_st&)__attribute__((always_inline));
  inline friend int operator>(const char&, const float_st&)__attribute__((always_inline));

  inline friend int operator<=(const double_st&, const float_st&)__attribute__((always_inline));  
  inline friend int operator<=(const float_st&, const double_st&)__attribute__((always_inline));  
  inline friend int operator<=(const float_st&, const float_st&)__attribute__((always_inline));  

  inline friend int operator<=(const float_st&, const double&)__attribute__((always_inline));
  inline friend int operator<=(const float_st&, const float&)__attribute__((always_inline));
  inline friend int operator<=(const float_st&, const unsigned long long&)__attribute__((always_inline));
  inline friend int operator<=(const float_st&, const long long&)__attribute__((always_inline));
  inline friend int operator<=(const float_st&, const unsigned long&)__attribute__((always_inline));
  inline friend int operator<=(const float_st&, const long&)__attribute__((always_inline));
  inline friend int operator<=(const float_st&, const unsigned int&)__attribute__((always_inline));
  inline friend int operator<=(const float_st&, const int&)__attribute__((always_inline));
  inline friend int operator<=(const float_st&, const unsigned short&)__attribute__((always_inline));
  inline friend int operator<=(const float_st&, const short&)__attribute__((always_inline));
  inline friend int operator<=(const float_st&, const unsigned char&)__attribute__((always_inline));
  inline friend int operator<=(const float_st&, const char&)__attribute__((always_inline));

  inline friend int operator<=(const double&, const float_st&)__attribute__((always_inline));
  inline friend int operator<=(const float&, const float_st&)__attribute__((always_inline));
  inline friend int operator<=(const unsigned long long&, const float_st&)__attribute__((always_inline));
  inline friend int operator<=(const long long&, const float_st&)__attribute__((always_inline));
  inline friend int operator<=(const unsigned long&, const float_st&)__attribute__((always_inline));
  inline friend int operator<=(const long&, const float_st&)__attribute__((always_inline));
  inline friend int operator<=(const unsigned int&, const float_st&)__attribute__((always_inline));
  inline friend int operator<=(const int&, const float_st&)__attribute__((always_inline));
  inline friend int operator<=(const unsigned short&, const float_st&)__attribute__((always_inline));
  inline friend int operator<=(const short&, const float_st&)__attribute__((always_inline));
  inline friend int operator<=(const unsigned char&, const float_st&)__attribute__((always_inline));
  inline friend int operator<=(const char&, const float_st&)__attribute__((always_inline));

  inline friend int operator<(const double_st&, const float_st&)__attribute__((always_inline));  
  inline friend int operator<(const float_st&, const double_st&)__attribute__((always_inline));  
  inline friend int operator<(const float_st&, const float_st&)__attribute__((always_inline));
  
  inline friend int operator<(const float_st&, const double&)__attribute__((always_inline));
  inline friend int operator<(const float_st&, const float&)__attribute__((always_inline));
  inline friend int operator<(const float_st&, const unsigned long long&)__attribute__((always_inline));
  inline friend int operator<(const float_st&, const long long&)__attribute__((always_inline));
  inline friend int operator<(const float_st&, const unsigned long&)__attribute__((always_inline));
  inline friend int operator<(const float_st&, const long&)__attribute__((always_inline));
  inline friend int operator<(const float_st&, const unsigned int&)__attribute__((always_inline));
  inline friend int operator<(const float_st&, const int&)__attribute__((always_inline));
  inline friend int operator<(const float_st&, const unsigned short&)__attribute__((always_inline));
  inline friend int operator<(const float_st&, const short&)__attribute__((always_inline));
  inline friend int operator<(const float_st&, const unsigned char&)__attribute__((always_inline));
  inline friend int operator<(const float_st&, const char&)__attribute__((always_inline));

  inline friend int operator<(const double&, const float_st&)__attribute__((always_inline));
  inline friend int operator<(const float&, const float_st&)__attribute__((always_inline));
  inline friend int operator<(const unsigned long long&, const float_st&)__attribute__((always_inline));
  inline friend int operator<(const long long&, const float_st&)__attribute__((always_inline));
  inline friend int operator<(const unsigned long&, const float_st&)__attribute__((always_inline));
  inline friend int operator<(const long&, const float_st&)__attribute__((always_inline));
  inline friend int operator<(const unsigned int&, const float_st&)__attribute__((always_inline));
  inline friend int operator<(const int&, const float_st&)__attribute__((always_inline));
  inline friend int operator<(const unsigned short&, const float_st&)__attribute__((always_inline));
  inline friend int operator<(const short&, const float_st&)__attribute__((always_inline));
  inline friend int operator<(const unsigned char&, const float_st&)__attribute__((always_inline));
  inline friend int operator<(const char&, const float_st&)__attribute__((always_inline));


  // MATHEMATICAL FUNCTIONS 

  friend float_st  logf(const float_st&);
  friend float_st  log2f(const float_st&);
  friend float_st  log10f(const float_st&);
  friend float_st  log1pf(const float_st&);
  friend float_st  logbf(const float_st&);
  friend float_st  expf(const float_st&); 
  friend float_st  exp2f(const float_st&); 
  friend float_st  expm1f(const float_st&); 
  friend float_st  sqrtf(const float_st&);
  friend float_st  cbrtf(const float_st&);
  friend float_st  sinf(const float_st&);
  friend float_st  cosf(const float_st&);
  friend float_st  tanf(const float_st&);
  friend float_st  asinf(const float_st&);
  friend float_st  acosf(const float_st&);
  friend float_st  atanf(const float_st&);
  friend double_st atan2f(const double_st&, const float_st&);
  friend double_st atan2f(const float_st&, const double_st&);
  friend float_st  atan2f(const float_st&, const float_st&);
  friend float_st  sinhf(const float_st&);
  friend float_st  coshf(const float_st&);
  friend float_st  tanhf(const float_st&);
  friend float_st  asinhf(const float_st&);
  friend float_st  acoshf(const float_st&);
  friend float_st  atanhf(const float_st&);
  friend double_st  hypot(const double_st&, const float_st&);
  friend double_st  hypot(const float_st&, const double_st&);  
  friend float_st  hypotf(const float_st&, const float_st&);

  friend float_st  log(const float_st&);
  friend float_st  log2(const float_st&);
  friend float_st  log10(const float_st&);
  friend float_st  log1p(const float_st&);
  friend float_st  logb(const float_st&);
  friend float_st  exp(const float_st&); 
  friend float_st  exp2(const float_st&); 
  friend float_st  expm1(const float_st&); 
  friend float_st  sqrt(const float_st&);
  friend float_st  cbrt(const float_st&);
  friend float_st  sin(const float_st&);
  friend float_st  cos(const float_st&);
  friend float_st  tan(const float_st&);
  friend float_st  asin(const float_st&);
  friend float_st  acos(const float_st&);
  friend float_st  atan(const float_st&);
  friend double_st atan2(const double_st&, const float_st&);
  friend double_st atan2(const float_st&, const double_st&);
  friend float_st  atan2(const float_st&, const float_st&);
  friend float_st  sinh(const float_st&);
  friend float_st  cosh(const float_st&);
  friend float_st  tanh(const float_st&);
  friend float_st  asinh(const float_st&);
  friend float_st  acosh(const float_st&);
  friend float_st  atanh(const float_st&);
  // friend double_st  hypot(const double_st&, const float_st&);
  // friend double_st  hypot(const float_st&, const double_st&);  
  friend float_st  hypot(const float_st&, const float_st&);



  friend double_st pow(const double_st&, const float_st&);
  friend double_st pow(const float_st&, const double_st&);
  friend float_st powf(const float_st&, const float_st&);
  friend float_st pow(const float_st&, const float_st&);
  
  friend float_st powf(const float_st&, const double&);
  friend float_st powf(const float_st&, const float&);
  friend float_st powf(const float_st&, const unsigned long long&);
  friend float_st powf(const float_st&, const long long&);
  friend float_st powf(const float_st&, const unsigned long&);
  friend float_st powf(const float_st&, const long&);
  friend float_st powf(const float_st&, const unsigned int&);
  friend float_st powf(const float_st&, const int&);
  friend float_st powf(const float_st&, const unsigned short&);
  friend float_st powf(const float_st&, const short&);
  friend float_st powf(const float_st&, const unsigned char&);
  friend float_st powf(const float_st&, const char&);

  friend float_st pow(const float_st&, const double&);
  friend float_st pow(const float_st&, const float&);
  friend float_st pow(const float_st&, const unsigned long long&);
  friend float_st pow(const float_st&, const long long&);
  friend float_st pow(const float_st&, const unsigned long&);
  friend float_st pow(const float_st&, const long&);
  friend float_st pow(const float_st&, const unsigned int&);
  friend float_st pow(const float_st&, const int&);
  friend float_st pow(const float_st&, const unsigned short&);
  friend float_st pow(const float_st&, const short&);
  friend float_st pow(const float_st&, const unsigned char&);
  friend float_st pow(const float_st&, const char&);



  friend float_st powf(const double&, const float_st&);
  friend float_st powf(const float&, const float_st&);
  friend float_st powf(const unsigned long long&, const float_st&);
  friend float_st powf(const long long&, const float_st&);
  friend float_st powf(const unsigned long&, const float_st&);
  friend float_st powf(const long&, const float_st&);
  friend float_st powf(const unsigned int&, const float_st&);
  friend float_st powf(const int&, const float_st&);
  friend float_st powf(const unsigned short&, const float_st&);
  friend float_st powf(const short&, const float_st&);
  friend float_st powf(const unsigned char&, const float_st&);
  friend float_st powf(const char&, const float_st&);

  friend float_st pow(const double&, const float_st&);
  friend float_st pow(const float&, const float_st&);
  friend float_st pow(const unsigned long long&, const float_st&);
  friend float_st pow(const long long&, const float_st&);
  friend float_st pow(const unsigned long&, const float_st&);
  friend float_st pow(const long&, const float_st&);
  friend float_st pow(const unsigned int&, const float_st&);
  friend float_st pow(const int&, const float_st&);
  friend float_st pow(const unsigned short&, const float_st&);
  friend float_st pow(const short&, const float_st&);
  friend float_st pow(const unsigned char&, const float_st&);
  friend float_st pow(const char&, const float_st&);


  friend float_st fmaxf(const float_st&, const float_st&);  
  friend double_st fmax(const double_st&, const float_st&);  
  friend double_st fmax(const float_st&, const double_st&);  

  friend float_st fmax(const float_st&, const float_st&);  

  friend float_st fmaxf(const float_st&, const double&);
  friend float_st fmaxf(const float_st&, const float&);
  friend float_st fmaxf(const float_st&, const unsigned long long&);
  friend float_st fmaxf(const float_st&, const long long&);
  friend float_st fmaxf(const float_st&, const unsigned long&);
  friend float_st fmaxf(const float_st&, const long&);
  friend float_st fmaxf(const float_st&, const unsigned int&);
  friend float_st fmaxf(const float_st&, const int&);
  friend float_st fmaxf(const float_st&, const unsigned short&);
  friend float_st fmaxf(const float_st&, const short&);
  friend float_st fmaxf(const float_st&, const unsigned char&);
  friend float_st fmaxf(const float_st&, const char&);

  friend float_st fmax(const float_st&, const double&);
  friend float_st fmax(const float_st&, const float&);
  friend float_st fmax(const float_st&, const unsigned long long&);
  friend float_st fmax(const float_st&, const long long&);
  friend float_st fmax(const float_st&, const unsigned long&);
  friend float_st fmax(const float_st&, const long&);
  friend float_st fmax(const float_st&, const unsigned int&);
  friend float_st fmax(const float_st&, const int&);
  friend float_st fmax(const float_st&, const unsigned short&);
  friend float_st fmax(const float_st&, const short&);
  friend float_st fmax(const float_st&, const unsigned char&);
  friend float_st fmax(const float_st&, const char&);


  friend float_st fmaxf(const double&, const float_st&);
  friend float_st fmaxf(const float&, const float_st&);
  friend float_st fmaxf(const unsigned long long&, const float_st&);
  friend float_st fmaxf(const long long&, const float_st&);
  friend float_st fmaxf(const unsigned long&, const float_st&);
  friend float_st fmaxf(const long&, const float_st&);
  friend float_st fmaxf(const unsigned int&, const float_st&);
  friend float_st fmaxf(const int&, const float_st&);
  friend float_st fmaxf(const unsigned short&, const float_st&);
  friend float_st fmaxf(const short&, const float_st&);
  friend float_st fmaxf(const unsigned char&, const float_st&);
  friend float_st fmaxf(const char&, const float_st&);

  friend float_st fmax(const double&, const float_st&);
  friend float_st fmax(const float&, const float_st&);
  friend float_st fmax(const unsigned long long&, const float_st&);
  friend float_st fmax(const long long&, const float_st&);
  friend float_st fmax(const unsigned long&, const float_st&);
  friend float_st fmax(const long&, const float_st&);
  friend float_st fmax(const unsigned int&, const float_st&);
  friend float_st fmax(const int&, const float_st&);
  friend float_st fmax(const unsigned short&, const float_st&);
  friend float_st fmax(const short&, const float_st&);
  friend float_st fmax(const unsigned char&, const float_st&);
  friend float_st fmax(const char&, const float_st&);


  friend float_st fminf(const float_st&, const float_st&);  
  friend float_st fmin(const float_st&, const float_st&);  
  friend double_st fmin(const double_st&, const float_st&);  
  friend double_st fmin(const float_st&, const double_st&);  

  friend float_st fminf(const float_st&, const double&);
  friend float_st fminf(const float_st&, const float&);
  friend float_st fminf(const float_st&, const unsigned long long&);
  friend float_st fminf(const float_st&, const long long&);
  friend float_st fminf(const float_st&, const unsigned long&);
  friend float_st fminf(const float_st&, const long&);
  friend float_st fminf(const float_st&, const unsigned int&);
  friend float_st fminf(const float_st&, const int&);
  friend float_st fminf(const float_st&, const unsigned short&);
  friend float_st fminf(const float_st&, const short&);
  friend float_st fminf(const float_st&, const unsigned char&);
  friend float_st fminf(const float_st&, const char&);

  friend float_st fmin(const float_st&, const double&);
  friend float_st fmin(const float_st&, const float&);
  friend float_st fmin(const float_st&, const unsigned long long&);
  friend float_st fmin(const float_st&, const long long&);
  friend float_st fmin(const float_st&, const unsigned long&);
  friend float_st fmin(const float_st&, const long&);
  friend float_st fmin(const float_st&, const unsigned int&);
  friend float_st fmin(const float_st&, const int&);
  friend float_st fmin(const float_st&, const unsigned short&);
  friend float_st fmin(const float_st&, const short&);
  friend float_st fmin(const float_st&, const unsigned char&);
  friend float_st fmin(const float_st&, const char&);


  friend float_st fminf(const double&, const float_st&);
  friend float_st fminf(const float&, const float_st&);
  friend float_st fminf(const unsigned long long&, const float_st&);
  friend float_st fminf(const long long&, const float_st&);
  friend float_st fminf(const unsigned long&, const float_st&);
  friend float_st fminf(const long&, const float_st&);
  friend float_st fminf(const unsigned int&, const float_st&);
  friend float_st fminf(const int&, const float_st&);
  friend float_st fminf(const unsigned short&, const float_st&);
  friend float_st fminf(const short&, const float_st&);
  friend float_st fminf(const unsigned char&, const float_st&);
  friend float_st fminf(const char&, const float_st&);

  friend float_st fmin(const double&, const float_st&);
  friend float_st fmin(const float&, const float_st&);
  friend float_st fmin(const unsigned long long&, const float_st&);
  friend float_st fmin(const long long&, const float_st&);
  friend float_st fmin(const unsigned long&, const float_st&);
  friend float_st fmin(const long&, const float_st&);
  friend float_st fmin(const unsigned int&, const float_st&);
  friend float_st fmin(const int&, const float_st&);
  friend float_st fmin(const unsigned short&, const float_st&);
  friend float_st fmin(const short&, const float_st&);
  friend float_st fmin(const unsigned char&, const float_st&);
  friend float_st fmin(const char&, const float_st&);

  // INTRINSIC FUNCTIONS
 
  friend float_st fabsf(const float_st&);
  friend float_st floorf(const float_st&);
  friend float_st ceilf(const float_st&);
  friend float_st truncf(const float_st&);
  friend float_st nearbyintf(const float_st&);
  friend float_st rintf(const float_st&);
  friend long int  lrintf(const float_st&);
  friend long long int  llrintf(const float_st&);

  friend float_st frexp(const float_st&, int*);
  /* friend float_st modf(const  float_st&,  float_st*); */
  friend float_st ldexp(const float_st&, const int);
  friend float_st fmod(const float_st&, const float_st&);


  friend float_st frexpf(const float_st&, int*);
  friend float_st modff(const  float_st&,  float_st*);
  friend float_st ldexpf(const float_st&, const int);
  friend float_st fmodf(const float_st&, const float_st&);


  friend float_st fabs(const float_st&);
  friend float_st abs(const float_st&);
  friend float_st floor(const float_st&);
  friend float_st ceil(const float_st&);
  friend float_st trunc(const float_st&);
  friend float_st nearbyint(const float_st&);
  friend float_st rint(const float_st&);
  friend long int  lrint(const float_st&);
  friend long long int  llrint(const float_st&);

  friend int finite(const float_st&);
  friend int isfinitef(const float_st&);
  friend int isnan(const float_st&);
  friend int isinf(const float_st&);


  // Conversion
  operator char();  
  operator unsigned char();  
  operator short();  
  operator unsigned short();  
  operator int();  
  operator unsigned();  
  operator long();  
  operator unsigned long();  
  operator long long();  
  operator unsigned long long();  
  operator float();
  operator double();
  operator double_st();
  
  operator char() const;  
  operator unsigned char() const;  
  operator short() const;  
  operator unsigned short() const;  
  operator int() const;  
  operator unsigned() const;  
  operator long() const;  
  operator unsigned long() const;  
  operator long long() const;  
  operator unsigned long long() const;  
  operator float() const;
  operator double() const;
  operator double_st() const;



  
  inline int nb_significant_digit() const __attribute__((always_inline));  
  inline int approx_digit() const __attribute__((always_inline));
  inline int computedzero() const __attribute__((always_inline));
  inline int numericalnoise() const __attribute__((always_inline));
  void display() const ; 
  void display(const char *) const ; 
  char* str( char *)  const ;
  
  friend char* strp(const float_st&);
  friend char* str( char *, const float_st&);
  
  friend std::istream& operator >>(std::istream& s, float_st& );  
  
  void data_st();
  void data_st(const double&, const int &);
  
};

std::ostream& operator<<(std::ostream&, const float_st&);
std::istream& operator >>(std::istream&, float_st& );



inline double_st::double_st (const float_st&a) : x(a.x),y(a.y),z(a.z),accuracy(a.accuracy) {};


void  cadna_init(int, unsigned int, unsigned int, unsigned int);
void  cadna_init(int, unsigned int);
void  cadna_init(int);
void  cadna_end();

void cadna_enable(unsigned int);
void cadna_disable(unsigned int);

inline void  instability(unsigned long*) __attribute__((always_inline));


// INSTABILITIES MANAGEMENT

extern unsigned long _cadna_div_count;
extern unsigned long _cadna_mul_count;  
extern unsigned long _cadna_power_count;  
extern unsigned long _cadna_branching_count; 
extern unsigned long _cadna_cancel_count;  
extern unsigned long _cadna_intrinsic_count;  
extern unsigned long _cadna_math_count; 

extern unsigned int _cadna_div_tag;
extern unsigned int _cadna_mul_tag;  
extern unsigned int _cadna_power_tag;  
extern unsigned int _cadna_branching_tag;
extern unsigned int _cadna_cancel_tag;
extern unsigned int _cadna_intrinsic_tag; 
extern unsigned int _cadna_math_tag; 

extern unsigned int _cadna_div_change; 
extern unsigned int _cadna_mul_change;  
extern unsigned int _cadna_power_change;  
extern unsigned int _cadna_branching_change;
extern unsigned int _cadna_cancel_change; 
extern unsigned int _cadna_intrinsic_change; 
extern unsigned int _cadna_math_change; 

extern int _cadna_cancel_value;

extern int nbre_trace_cadna;
extern int nbre_stability_count;

extern int  _cadna_max_instability;
extern int  _cadna_instability_detected;

// The RANDOM BIT GENERATOR
extern unsigned int _cadna_random;
extern int _cadna_random_counter;
extern unsigned int _cadna_recurrence;

#define RANDOM _cadna_random_function()


#define DIGIT_NOT_COMPUTED -1
#define RELIABLE_RESULT  255

typedef union u_floatbf {
  float fl;
  unsigned int bf;
} floatbf;

typedef union u_doublebf {
  double fl;
  unsigned long bf;
} doublebf;

#ifdef _OPENMP
#pragma omp threadprivate (_cadna_random, _cadna_random_counter, _cadna_recurrence)
#endif //_OPENMP

#ifdef _OPENMP
#pragma omp declare reduction(+:float_st : omp_out=omp_in+omp_out)	\
  initializer(omp_priv=float_st(0.f))
#pragma omp declare reduction(+:double_st: omp_out=omp_in+omp_out)	\
  initializer(omp_priv=double_st(0.))
#pragma omp declare reduction(-:float_st : omp_out=omp_in+omp_out)	\
  initializer(omp_priv=float_st(0.f))
#pragma omp declare reduction(-:double_st: omp_out=omp_in+omp_out)	\
  initializer(omp_priv=double_st(0.))
#pragma omp declare reduction(*:float_st : omp_out=omp_in*omp_out)	\
  initializer(omp_priv=float_st(1.f))
#pragma omp declare reduction(*:double_st: omp_out=omp_in*omp_out)	\
  initializer(omp_priv=double_st(1.))
#endif //_OPENMP

#define FLOAT_BIT_FLIP(f, b) ((floatbf*)&f)->bf^=((unsigned int)b)<<31;
#define DOUBLE_BIT_FLIP(d, b) ((doublebf*)&d)->bf^=((unsigned long)b)<<63;

#include <cadna_unstab.h>
#include <cadna_random.h>
#include <cadna_digitnumber.h>
#include <cadna_computedzero.h>
#include <cadna_numericalnoise.h>
#include <cadna_to.h>
#include <cadna_add.h>
#include <cadna_sub.h>
#include <cadna_mul.h>
#include <cadna_div.h>
#ifndef __CADNA_LIB__

#include <cadna_eq.h>
#include <cadna_ne.h>
#include <cadna_ge.h>
#include <cadna_gt.h>
#include <cadna_le.h>
#include <cadna_lt.h>
#include <cadna_str.h>

#endif /* __CADNA_LIB */

#endif












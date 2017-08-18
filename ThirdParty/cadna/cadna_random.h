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


inline unsigned int _cadna_TauswortheStep(unsigned int,
					  unsigned int,
					  unsigned int,
					  unsigned int) __attribute__((always_inline));
inline unsigned int _cadna_TauswortheStep(unsigned int s1,
					  unsigned int s2,
					  unsigned int s3,
					  unsigned int m){
  unsigned int b = (((_cadna_recurrence << s1) ^ _cadna_recurrence) >> s2);
  return _cadna_recurrence = (((_cadna_recurrence & m) << s3) ^ b);
}

inline unsigned int _cadna_LCGStep(unsigned int,
				   unsigned int) __attribute__((always_inline));
inline unsigned int _cadna_LCGStep(unsigned int a,
				   unsigned int c){
  return _cadna_recurrence = (a * _cadna_recurrence + c);
}


//****if* cadna_random/_cadna_random_function
//    NAME
//     _cadna_random_function
//
//    SYNOPSIS
//      unsigned int _cadna_random_function()
//
//    FUNCTION
//        internal random generator of the CADNA library.
//      
//    INPUTS
//   
//    RESULT

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

inline unsigned int _cadna_random_function() __attribute__((always_inline));

inline unsigned int _cadna_random_function(){
  static const unsigned int Taus1S1 = 13;
  static const unsigned int Taus1S2 = 19;
  static const unsigned int Taus1S3 = 12;
  static const unsigned int Taus1M  = 429496729U;
  static const unsigned int Taus2S1 = 2;
  static const unsigned int Taus2S2 = 25;
  static const unsigned int Taus2S3 = 4;
  static const unsigned int Taus2M  = 4294967288U;
  static const unsigned int Taus3S1 = 3;
  static const unsigned int Taus3S2 = 11;
  static const unsigned int Taus3S3 = 17;
  static const unsigned int Taus3M  = 429496280U;
  static const unsigned int LCGa    = 1664525;
  static const unsigned int LCGc    = 1013904223U;

  unsigned int z1, z2, z3, z4;

  if((_cadna_random_counter&0x1F)==0){
    z1 = _cadna_TauswortheStep(Taus1S1, Taus1S2, Taus1S3, Taus1M);
    z2 = _cadna_TauswortheStep(Taus2S1, Taus2S2, Taus2S3, Taus2M);
    z3 = _cadna_TauswortheStep(Taus3S1, Taus3S2, Taus3S3, Taus3M);
    z4 = _cadna_LCGStep(LCGa, LCGc);
    _cadna_recurrence = (z1 ^ z2 ^ z3 ^ z4);
    _cadna_random = _cadna_recurrence;
  }
  else{
    _cadna_random>>=1;
  }

  _cadna_random_counter++;

  return _cadna_random&1;
}



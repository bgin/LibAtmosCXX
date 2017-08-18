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

#include "cadna.h"

  
//
//
//=====================================================
//	"INSTABILITY" function
//=====================================================
//
//


//****f* cadna_unstab/instability
//    NAME
//     instability
//
//    SYNOPSIS
//      void  instability(unsigned long *unstab)
//    FUNCTION
//      It is an internal subroutine of the CADNA library. It manages 
//      the different kinds of instabilities detected by CADNA.
//    INPUTS
//      An unsigned long integer which indicates the kind of instability 
//      that has been detected.
//    RESULT
//    
//    SEE ALSO
//*****
//   You can use this space for remarks that should not be included
//   in the documentation.
//    EXAMPLE
//      
//  
//    NOTES
//      This function is called exclusively when an instability has been 
//      detected. Therefore, under a symbolic debugger like gdb, one has
//      only to put a breakoint at this function to stop the run each
//      time an instability occurs. 
//  
//    BUGS
//  
//  
//      
//      
//  /


void instability(unsigned long *unstab)
{
#ifdef _OPENMP
#pragma omp atomic
#endif //_OPENMP
  (*unstab)++;
#ifdef _OPENMP
#pragma omp atomic
#endif //_OPENMP
  _cadna_instability_detected++;
  if (_cadna_max_instability<0) return;    
  if (_cadna_instability_detected==_cadna_max_instability) {

    _cadna_div_tag=0; 
    _cadna_mul_tag=0;  
    _cadna_power_tag=0;  
    _cadna_math_tag=0; 
    _cadna_intrinsic_tag=0; 
    _cadna_cancel_tag=0; 
    _cadna_branching_tag=0;

    _cadna_div_change=1; 
    _cadna_mul_change=1;  
    _cadna_power_change=1;  
    _cadna_branching_change=1;
    _cadna_cancel_change=1; 
    _cadna_intrinsic_change=1; 
    _cadna_math_change=1;

    _cadna_max_instability=-2;
  }
} 

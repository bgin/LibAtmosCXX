
#ifndef __LAM_STDH_H__
#define __LAM_STDH_H__

#if !defined (LAM_STDH_MAJOR)
#define LAM_STDH_MAJOR 1
#endif

#if !defined (LAM_STDH_MINOR)
#define LAM_STDH_MINOR 0
#endif

#if !defined (LAM_STDH_MICRO)
#define LAM_STDH_MICRO 0
#endif

#if !defined (LAM_STDH_FULLVER)
#define LAM_STDH_FULLVER 1000
#endif

#if !defined (LAM_STDH_CREATE_DATE)
#define LAM_STDH_CREATE_DATE "19-08-2017 11:21 +00200 (SAT 19 AUG 2017 GMT+2)"
#endif

/*
	Set this value after successful compilation of this file
*/
#if !defined (LAM_STDH_BUILD_DATE)
#define LAM_STDH_BUILD_DATE " "
#endif

#if !defined (LAM_STDH_AUTHOR)
#define LAM_STDH_AUTHOR "Programmer: Bernard Gingold e-mail: beniekg@gmail.com"
#endif

#if !defined (LAM_STDH_DESCRIPT)
#define LAM_STDH_DESCRIPT "Inclusion of std lib headers."
#endif

#include <iostream>
#include <iomanip>
#include <complex>
#include <string>
#include <vector>
#include <memory>


#endif /*__LAM_STDH_H__*/
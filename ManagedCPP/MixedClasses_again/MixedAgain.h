#ifndef MIXEDAGAIN_H
#define MIXEDAGAIN_H
/////////////////////////////////////////////////////////////////////
// MixedAgain.h  -  Demonstrates use of managed and unmanaged      //
//                  C++ classes holding references to each other   //
//                                                                 //
// Jim Fawcett, CSE775 - Distributed Objects, Spring 2003          //
/////////////////////////////////////////////////////////////////////
// Built with Empty Managed C++ Project wizard                     //
/////////////////////////////////////////////////////////////////////

using namespace System;
using namespace System::Text;

#include <iostream>
#include <string>
#include <vcclr.h>
using namespace std;

/////////////////////////////////////////////////////////////////////
// simple native C++ class

class N1
{
public:
  void say();
};

/////////////////////////////////////////////////////////////////////
// managed reference type holding native pointer to native class

ref class R1
{
public:
  R1();
  ~R1();
  void say();
private:
  N1* pN;
};

/////////////////////////////////////////////////////////////////////
// simple managed reference type

ref class R2
{
public:
  void say();
};

/////////////////////////////////////////////////////////////////////
// native C++ type holding managed pointer to managed class

class N2
{
public:
  N2();
  ~N2();
  void say();
private:
  gcroot<R2^> rR;
};

#endif

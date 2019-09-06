#ifndef MARSHALINGLIB_H
#define MARSHALINGLIB_H
/////////////////////////////////////////////////////////////////////
// MarshalingLib.H - Demonstrates use of marshaling and PInvoke    //
//                                                                 //
// Jim Fawcett, CSE775 - Distributed Objects, Spring 2003          //
/////////////////////////////////////////////////////////////////////
// Built with Win32 Project wizard                                 //
/////////////////////////////////////////////////////////////////////

#include <iostream>
#include "IMarshalingLib.h"

#ifdef MARSHALINGLIB_EXPORTS
#define MARSHALINGLIB_API __declspec(dllexport)
#else
#define MARSHALINGLIB_API __declspec(dllimport)
#endif

class MARSHALINGLIB_API CMarshalingLib : public IMarshalingLib
{
public:
  void demoTransfer(const char* str)
  {
    std::cout << "\n  in demoTransfer: " << str;
  }
};

extern "C" MARSHALINGLIB_API void CreateMLobj(IMarshalingLib*& pObj)
{
  std::cout << "\n  creating instance of CMarshalingLib";
  pObj = new CMarshalingLib();
}

extern "C" MARSHALINGLIB_API void DeleteMLobj(IMarshalingLib* pObj)
{
  std::cout << "\n  destroying instance of CMarshalingLib";
  delete pObj;
}

#endif

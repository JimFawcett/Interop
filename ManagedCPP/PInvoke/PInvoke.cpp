/////////////////////////////////////////////////////////////////////
// PInvoke.cpp - Demonstrates use of Platform Invoke access to     //
//               Win32 API                                         //
//                                                                 //
// Jim Fawcett, CSE775 - Distributed Objects, Spring 2003          //
/////////////////////////////////////////////////////////////////////
// Built with Empty Managed C++ Project wizard                     //
/////////////////////////////////////////////////////////////////////

//#using <mscorlib.dll>
using namespace System;
using namespace System::Runtime::InteropServices;

#include <iostream>
using namespace std;

///////////////////////////////////////////////////////////////
// Note:
//   Signature specified in documentation is:
//   BOOL Beep(DWORD,DWORD);
//
[DllImport("kernel32.dll")]
extern "C" bool Beep(Int32,Int32);

int main()
{
  cout << "\n  Demonstrating Platfrom Invoke"
       << "\n ===============================\n";

  Beep(2000,500);
  Beep(1500,400);
  Beep(2000,500);
  Beep(1500,400);
  Beep(2000,500);
  Beep(1500,400);
  Beep(2000,500);

  cout << "\n\n";
}

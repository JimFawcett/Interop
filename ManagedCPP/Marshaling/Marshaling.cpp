/////////////////////////////////////////////////////////////////////
// Marshaling.cpp - Demonstrates use of marshaling and PInvoke     //
//                                                                 //
// Jim Fawcett, CSE775 - Distributed Objects, Spring 2003          //
/////////////////////////////////////////////////////////////////////
// Built with Win32 Project wizard                                 //
//   - place MarshalingLib.dll in project and debug directories    //
/////////////////////////////////////////////////////////////////////

//#using <mscorlib.dll>
//#using "c:/su/CSE775/code/managedCPP/MarshalingLib/Debug/MarshalingLib.dll"
using namespace System;
using namespace System::Runtime::InteropServices;

#include <iostream>
#include <string>
#include "IMarshalingLib.h"

using namespace std;

[ DllImport(
    "MarshalingLib.dll", CharSet=CharSet::Ansi,
    EntryPoint="?demoTransfer@CMarshalingLib@@QAEXPBD@Z"
  )
]
extern "C" void CallDemoTransfer([MarshalAs(UnmanagedType::LPStr)] String^ pMsg);

[ DllImport("MarshalingLib.dll")]
extern "C" void CreateMLobj(IMarshalingLib*& pObj);

[ DllImport("MarshalingLib.dll")]
extern "C" void DeleteMLobj(IMarshalingLib* pObj);

int main()
{
  cout << "\n  Demonstrate PInvoke with Specified Marshaling "
       << "\n ===============================================\n";
  cout.flush();

  IMarshalingLib* pMLobj;
  CreateMLobj(pMLobj);
  String^ pMsg = gcnew String("Hello from Managed World");
  CallDemoTransfer(pMsg);
  pMLobj->demoTransfer("Hello again");
  DeleteMLobj(pMLobj);
  cout << "\n\n";
}

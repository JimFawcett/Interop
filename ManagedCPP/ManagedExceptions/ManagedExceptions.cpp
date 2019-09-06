/////////////////////////////////////////////////////////////////////
// ManagedExceptions.cpp - Demonstrates use of managed exceptions  //
//                                                                 //
// Jim Fawcett, CSE775 - Distributed Objects, Spring 2003          //
/////////////////////////////////////////////////////////////////////
// Built with Empty Managed C++ Project wizard                     //
/////////////////////////////////////////////////////////////////////

#using <mscorlib.dll>
using namespace System;
using namespace System::Text;

#include <iostream>
#include <string>
using namespace std;

///////////////////////////////////////////////////////////////
// managed class holding reference to a StringBuilder object
//
public ref class managed : public ApplicationException
{
public:
  managed(String^ pStr) : ApplicationException(pStr) {}
};

//----< test exceptions >--------------------------------------

int main()
{
  try
  {
    throw gcnew managed("from main");
  }
  catch(managed^ pMan)
  {
    Console::Write("\n  Message:    {0}",pMan->Message);
    Console::Write("\n  TargetSite: {0}",pMan->TargetSite);
    Console::Write("\n  StackTrace:\n  {0}",pMan->StackTrace);
  }
  __finally
  {
    Console::Write("\n  in __finally\n\n");
  }
}

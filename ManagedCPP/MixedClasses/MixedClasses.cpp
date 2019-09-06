/////////////////////////////////////////////////////////////////////
// MixedClasses.cpp - Demonstrates use of managed and unmanaged    //
//                    C++ classes                                  //
//                                                                 //
// Jim Fawcett, CSE775 - Distributed Objects, Spring 2003          //
/////////////////////////////////////////////////////////////////////
// Built with Empty Managed C++ Project wizard                     //
/////////////////////////////////////////////////////////////////////

using namespace System;
using namespace System::Text;

#include <iostream>
#include <string>
using namespace std;

//---< convert from System::Text::StringBuilder* to std::wstring* >--
//
//  user must eventually call delete on returned pointer
//
std::wstring* convert_SysStrBldToStdStr(System::Text::StringBuilder^ str)
{
  std::wstring* stdStr = new std::wstring();
  for(int i=0; i<str->Length; ++i)
    stdStr->append(1,str[i]);
  return stdStr;
}
//---< convert from std::wstring* to System::Text::StringBuilder* >--
//
//  return pointer is managed so should not be deleted
//
System::Text::StringBuilder^ convert_StdStrToSysStrBld(std::wstring* str)
{
  System::Text::StringBuilder^ sysStr = gcnew StringBuilder();
  for(size_t i=0; i<str->size(); ++i)
    sysStr->Append((*str)[i]);
  return sysStr;
}

///////////////////////////////////////////////////////////////
// unmanaged class holding std::wstring object
//
class UnManaged
{
public:
  UnManaged(const std::wstring& str) : _str(str) {}
  std::wstring& value() { return _str; }
private:
  std::wstring _str;
};

//
///////////////////////////////////////////////////////////////
// managed class holding pointer to a StringBuilder object
// 
ref class Managed
{
public:
  Managed(StringBuilder^ pStr) : _pStr(pStr) {}
  StringBuilder^ value() { return _pStr; }
  StringBuilder^ callUnManaged(UnManaged* pUnMan);
private:
  StringBuilder^ _pStr;
};

StringBuilder^ Managed::callUnManaged(UnManaged* pUnMan)
{ 
  std::wstring temp = pUnMan->value();
  return convert_StdStrToSysStrBld(&temp);
}

//----< display a message on console >-------------------------------

void msg(const std::string& s)
{
  cout << "\n  " << s;
  std::string underline(s.size()+2,'-');
  cout << "\n " << underline << endl;
}

//----< test mixed classes >-----------------------------------------

int main()
{
  msg("Creating Managed Class");
  Managed^ pMan 
    = gcnew Managed(gcnew StringBuilder("Hello World from Managed"));
  Console::Write("\n  {0}\n",pMan->value());

  msg("Creating UnManaged Class");
  UnManaged UnMan(L"Hello from UnManaged");
  wcout << L"\n  " << UnMan.value() << endl;

  msg("Calling UnManaged from Managed");
  Console::Write("\n  {0}\n\n",(pMan->callUnManaged(&UnMan))->ToString());
}

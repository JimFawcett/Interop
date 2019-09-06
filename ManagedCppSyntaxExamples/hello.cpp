///////////////////////////////////////////////////////////////
// hello.cpp - first managed C++ program                     //
//                                                           //
// Jim Fawcett, CSE687 - Object Oriented Design, Spring 2005 //
///////////////////////////////////////////////////////////////

#using <mscorlib.dll>
#include <iostream>
#include <string>
using namespace System;
using namespace System::Text;

namespace myApp
{
  /////////////////////////////////////////////////////
  // managed class

  public ref class firstClass
  {
  private:
    String^ m_pString;  // must be pointer or reference
                        // created on managed heap
  public:
    firstClass(String^ pOutStr) : m_pString(pOutStr) {}
    void speak() 
    {
      StringBuilder^ temp = gcnew StringBuilder("\n  ");
      temp->Append(m_pString);
      Console::WriteLine(temp);
    }
  };

  /////////////////////////////////////////////////////
  // unmanaged class

  class secondClass
  {
  private:
    std::string m_String;  // created in stack frame

  public:
    secondClass(const std::string& str) : m_String(str) {};
    void say()
    {
      std::string temp = "\n  ";
      temp.append(m_String);
      std::cout << temp.c_str();
      std::cout.flush();
    }
  };
}

//
using namespace myApp;

void main(int argc, char* argv[])
{
  Console::Write("\n  Demonstrating Managed and UnManaged C++");
  Console::Write("\n =========================================\n");

  std::cout << "\n  Command line arguments are:";
  for(int i=0; i<argc; ++i)
    std::cout << "\n  " << argv[i];
  std::cout << std::endl;

  Console::Write("\n  Creating managed Object");

  // Create instance of user defined managed class.
  // Note that firstClass constructor will accept a literal string.

  firstClass^ myFirstClass = gcnew firstClass(gcnew String("first class here!"));
  myFirstClass->speak();

  Console::Write("\n  Creating unmanaged Object");

  // Create instance of user defined unmanaged class.

  secondClass mySecondClass("second class here!");
  mySecondClass.say();

  Console::Write("\n\n");
}


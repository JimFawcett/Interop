///////////////////////////////////////////////////////////////
// demoProps.cpp - Properties work this way
//
// Jim Fawcett, CSE687 - Object Oriented Design, Spring 2005 
///////////////////////////////////////////////////////////////

//#using <mscorlib.dll>
using namespace System;

namespace Properties
{
  ref class demoProps
  {
  public:
    property String^ name { 
      String^ get() { return _name; }
      void set(String^ value) { _name = value; }
    }
    property String^ othername;

  private:
    String^ _name;
  };
}

void main()
{
  Console::Write("\n  Demonstrating Properties in Managed C++");
  Console::Write("\n =========================================\n");

  Properties::demoProps^ dp = gcnew Properties::demoProps();
  dp->name = "Bartholomew";
  Console::Write("\n  name property: {0}\n",dp->name);
  dp->othername = "Albert";
  Console::Write("\n  othername property: {0}\n\n",dp->othername);
}

#ifndef MANAGEDCLASSES_H
#define MANAGEDCLASSES_H
/////////////////////////////////////////////////////////////////////
// ManagedClasses.cpp - Demonstrates use of managed C++ classes    //
//                                                                 //
// Jim Fawcett, CSE775 - Distributed Objects, Spring 2003          //
/////////////////////////////////////////////////////////////////////
// Built with Empty Managed C++ Project wizard                     //
/////////////////////////////////////////////////////////////////////

using namespace System;
using namespace System::Text;

///////////////////////////////////////////////////////////////
// managed class holding handle to a StringBuilder object
//
public ref class Managed
{
public:
  Managed(StringBuilder^ rStr) : _rStr(rStr) {}
  StringBuilder^ value() { return _rStr; }
  void value(StringBuilder^ rStr) { _rStr = rStr; }
private:
  StringBuilder^ _rStr;
};

///////////////////////////////////////////////////////////////
// managed class with StringBuilder property
//
public ref class NewManaged
{
public:
  NewManaged() : Str(gcnew StringBuilder("")) {}
   property StringBuilder^ str
   {
      StringBuilder^ get()
      {
         return Str;
      }
      void set(StringBuilder^ value)
      {
         Str = value;
      }
   }
private:
  StringBuilder^ Str;
};

///////////////////////////////////////////////////////////////
// managed class returning reference to StringBuilder object
// in value() function
//
public ref class NewerManaged
{
public:
  NewerManaged() : _rStr(gcnew StringBuilder()) { }
  System::Text::StringBuilder% value() { return *_rStr; }
private:
  System::Text::StringBuilder^ _rStr;
};

#endif

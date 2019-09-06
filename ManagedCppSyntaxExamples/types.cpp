///////////////////////////////////////////////////////////////
// types.cs - Getting type information at run-time           //
//                                                           //
// Jim Fawcett, CSE687 - Object Oriented Design, Spring 2005 //
///////////////////////////////////////////////////////////////

#using <mscorlib.dll>
using namespace System; 

namespace types
{
  ref class CApp
  {
  public:
    static bool IsInteger( Object^ obj )
    { 
      bool isInt = obj->GetType()->Equals(Int32::typeid);
      bool isLong = obj->GetType()->Equals(Int64::typeid);

      if( isInt || isLong )
        return true; 
      else 
        return false;
    }
    static void DisplayTypeInfo( Object^ obj ) 
    { 
      Console::Write( "\n  Type name = {0}", obj->GetType()->Name );
      Console::Write( "\n  full name = {0}", obj->GetType()->FullName ); 
      Console::Write( "\n  namesapce = {0}", obj->GetType()->Namespace ); 
      Console::Write( "\n  module    = {0}", obj->GetType()->Module ); 
    }
  }; 
}

using namespace types;

void main()
{ 
  Console::Write("\n  Demonstrating Type Queries in Managed C++");
  Console::Write("\n ===========================================\n");

  String^ s = gcnew String("fred"); 
  Object% sRef = *s;
  long i = 10; 
  Object^ iPtr = i;  // implicit boxing

  CApp^ pCa = gcnew CApp;
  Console::Write(
    "\n  {0} is {1}an integer", 
    s, 
    (pCa->IsInteger(s) ? gcnew String("") : gcnew String("not "))
  ); 
  Console::Write(
    "\n  {0} is {1}an integer", 
    iPtr, 
    (pCa->IsInteger(iPtr) ? gcnew String("") : gcnew String("not "))
  ); 

  Object^ app = gcnew CApp();
  CApp::DisplayTypeInfo(app);
  array<String^>^ animals = { "ardvvark", "tiger", "vulture", "jackel", "mule" };
  CApp::DisplayTypeInfo(animals);
  CApp::DisplayTypeInfo(iPtr);

  Console::Write("\n\n");
}

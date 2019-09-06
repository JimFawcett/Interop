/////////////////////////////////////////////////////////////
// types.cs - Getting type information at run-time         //
//                                                         //
// Jim Fawcett, CSE775 - Distributed Objects, Spring 2005  //
/////////////////////////////////////////////////////////////
// Modified from an example by Andy McMullen               //
/////////////////////////////////////////////////////////////

using System; 

namespace types
{
  class CApp
  {
    static bool IsInteger( object obj )
    { 
      if( obj is int || obj is long )
        return true; 
      else 
        return false;
    }
    static void DisplayTypeInfo( object obj ) 
    { 
      Console.WriteLine( "Type name = {0}",obj.GetType().Name );
      Console.WriteLine( "full name = {0}", obj.GetType().FullName ); 
      Console.WriteLine( "namesapce = {0}", obj.GetType().Namespace ); 
      Console.WriteLine( "module    = {0}", obj.GetType().Module ); 
    }
    public static void Main()
    { 
      string s = "fred"; 
      long i = 10; 

      Console.WriteLine("{0} is {1}an integer", s, (IsInteger(s) ? "" : "not ")); 
      Console.WriteLine("{0} is {1}an integer", i, (IsInteger(i) ? "" : "not ")); 

      CApp app = new CApp();
      DisplayTypeInfo(app);
      string[] animals = { "ardvvark", "tiger", "vulture", "jackel", "mule" };
      DisplayTypeInfo(animals);
      DisplayTypeInfo(i);
    }
  } 
}
/////////////////////////////////////////////////////////////
// hello C# - first CSharp program                         //
//                                                         //
// Jim Fawcett, CSE775 - Distributed Objects, Spring 2005  //
/////////////////////////////////////////////////////////////

using System;

namespace myApp
{
  public class firstClass
  {
    private string m_string;
    public firstClass(string outStr) 
    {
      m_string = outStr;
    }
    public void speak() 
    {
      string temp = "\n  " + m_string;
      Console.WriteLine(temp);
    }
  }
  class Hello
  {
    static void Main(string[] args)
    {
      Console.WriteLine("\n  hello CSE791 - Distributed Objects class\n");
      Console.WriteLine("\n  Creating firstClass Object");

      // create instance of user defined class

      firstClass myFirstClass = new firstClass("first class here!");
      myFirstClass.speak();

      Console.Write("\n\n");
    }
  }
}

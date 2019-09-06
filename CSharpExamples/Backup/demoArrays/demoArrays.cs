///////////////////////////////////////////////////////////////
// demoArrays.cs - Arrays work this way
//
// Jim Fawcett, CSE775 - Distributed Objects, Spring 2003
///////////////////////////////////////////////////////////////

using System;

namespace demoArrays
{
  class demoArrays
  {
    public void display(double[,] arr)
    {
      for(int i=0; i<arr.GetLength(0); ++i)
      {
        Console.Write("\n  ");
        for(int j=0; j<arr.GetLength(1); ++j)
        {
          Console.Write("{0,5} ",arr[i,j]);
        }
      }
      Console.Write("\n\n");
    }
    [STAThread]
    static void Main(string[] args)
    {
      string[] animals = { "ardvvark", "tiger", "vulture", "jackel", "mule" };
      foreach(string animal in animals)
        Console.Write("\n  {0}",animal);
      Console.Write("\n\n");

      double[,] matrix = new double[3,2];
      for(int i=0; i<3; ++i)
        for(int j=0; j<2; ++j)
          matrix[i,j] = i+j-0.5;
      demoArrays da = new demoArrays();
      da.display(matrix);
    }
  }
}

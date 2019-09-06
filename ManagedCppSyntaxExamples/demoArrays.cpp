///////////////////////////////////////////////////////////////
// demoArrays.cpp - Managed arrays work this way             //
//                                                           //
// Jim Fawcett, CSE687 - Object Oriented Design, Spring 2005 //
///////////////////////////////////////////////////////////////

using namespace System;

namespace Arrays
{
  ref class demoArrays
  {
  public:
    void display(array<Double,2>^ arr)
    {
      for(int i=0; i<arr->GetLength(0); ++i)
      {
        Console::Write("\n  ");
        for(int j=0; j<arr->GetLength(1); ++j)
        {
          Console::Write("{0,5} ",arr[i,j]);
        }
      }
      Console::Write("\n\n");
    }
  };
}

using namespace Arrays;

void main()
{
  Console::Write("\n  Demonstrating Arrays in Managed C++");
  Console::Write("\n =====================================\n");

  array<String^>^ animals = { "ardvvark", "tiger", "vulture", "jackel", "mule" };
  for(int i=0; i<5; ++i)
    Console::Write("\n  {0}",animals[i]);
  Console::Write("\n\n");

  array<Double,2>^ matrix = gcnew array<Double,2>(3,2);
  for(int i=0; i<3; ++i)
    for(int j=0; j<2; ++j)
      matrix[i,j] = i+j-0.5;
  demoArrays^ da = gcnew demoArrays();
  da->display(matrix);
}

/////////////////////////////////////////////////////////////////////
// RIAA.cpp - Demonstrates simulated stack semantics with scope    //
//            based destruction                                    //
//                                                                 //
// Jim Fawcett, CSE775 - Distributed Objects, Spring 2006          //
/////////////////////////////////////////////////////////////////////

using namespace System;
using namespace System::Text;
#include <iostream>

/////////////////////////////////////////////////////////////////////
// a reference type lives on the managed heap, but can simulate
// stack-based semantics, as shown here

public ref class refType
{
public:
  refType(String^ s) : str(s)
  {
    std::cout << "\n  constructing refType instance";
  }
  ~refType()
  {
    std::cout << "\n  destroying refType instance";
  }
  String^ value() { return str; }
private:
  String^ str;
};

/////////////////////////////////////////////////////////////////////
// a user-defined value type must be bit-wise copyable.
// - no virtual functions
// - no constructors or destructor

public value class valueType
{
public:
  void say() { std::cout << "\n  value type here"; }
};

/////////////////////////////////////////////////////////////////////
// this struct simply emits two newlines after execution l
struct cosmetic
{
  ~cosmetic() { std::cout << "\n\n"; std::cout.flush(); }
} aGlobal;

//
void main()
{
  std::cout << "\n  Demonstrating RAII with Managed Class";
  std::cout << "\n =======================================\n";

  // managed class that simulates living on the stack
  // - Appears to live on the stack, but in fact is
  //   instantiated on the managed heap (without calling
  //   gcnew).
  // - Destuctor is called when thread of execution
  //   leaves declaration scope.
  // - That calls Dispose() so all unmanaged resources
  //   are deallocated at that time.
  // - Memory of the object is still collected by the
  //   garbage collector, e.g., non-deterministically.
  {
    refType rt("refType here");
    System::Console::Write("\n  {0}", rt.value());
    valueType vt;
    vt.say();
  }
  std::cout << "\n\n  out of anonymous scope\n\n";
}

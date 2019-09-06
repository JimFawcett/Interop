///////////////////////////////////////////////////////////////
// demoDelegate.cpp - Delegates work this way
//
// Jim Fawcett, CSE687 - Object Oriented Design, Spring 2005
///////////////////////////////////////////////////////////////

using namespace System;

namespace Delegates
{
  ref class demoDelegates
  {
  public:
    delegate void DelType(String^ str);
    DelType^ demoDel;

    void EventHandler(String ^str)
    {
      Console::Write("\n  myDel invoked with string {0}", str);
    }

    void publishEvent()
    {
      if(demoDel != nullptr)
        demoDel->Invoke("Hi there");
    }
  };
}

using namespace Delegates;

void main()
{
  Console::Write("\n  Demonstrating Delegates in Managed C++");
  Console::Write("\n ========================================\n");

  demoDelegates^ demo = gcnew demoDelegates();
  demo->demoDel = gcnew demoDelegates::DelType(demo, &demoDelegates::EventHandler);
  demo->publishEvent();
  Console::Write("\n\n");
}

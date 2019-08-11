///////////////////////////////////////////////////////////////
// Bridge.cpp - Supports Interop between C# and native C++   //
//                                                           //
// Jim Fawcett, CSE687 - Object Oriented Design, Spring 2014 //
///////////////////////////////////////////////////////////////

#include "ITask.h"
#include "Task.h"

ref class Bridge : public ITask
{
public:
  Bridge() : pTask(new Task(this)) {}
  ~Bridge() { delete pTask; }

  virtual void run(System::Windows::Threading::Dispatcher^ disp) override
  {
    //::MessageBox(0, L"in Bridge::run", L"debug", MB_OK);
    dispatcher_ = disp;
    pTask->makeSoundAndSleep(5000);
  }
  virtual void doCallBack(int i) override
  {
    //::MessageBox(0, L"in Bridge::doCallBack", L"debug", MB_OK);
    if (callback != nullptr)
    {
      array<Object^>^ arr = gcnew array<Object^>(1);
      arr[0] = i+1;
      dispatcher_->Invoke(callback, arr);
    }
  }
private:
  Task* pTask;
  System::Windows::Threading::Dispatcher^ dispatcher_;
};

ITask^ ITask::Create()
{
  return gcnew Bridge();
}
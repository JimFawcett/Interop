///////////////////////////////////////////////////////////////
// Task.cpp - Implementation of long running Task            //
//                                                           //
// Jim Fawcett, CSE687 - Object Oriented Design, Spring 2014 //
///////////////////////////////////////////////////////////////

#include "Task.h"
#include "ITask.h"

void Task::makeSoundAndSleep(int millisec)
{
  int imax = millisec / 1000;
  for (int i = 0; i < imax; ++i)
  {
    if (static_cast<ITask^>(hBridge_) != nullptr)  // did Bridge register itself?
      hBridge_->doCallBack(i);
    System::Media::SystemSounds::Asterisk->Play();
    System::Threading::Thread::Sleep(500 * imax);
  }
}

int main()
{
  Task t;
  t.makeSoundAndSleep(5000);
}
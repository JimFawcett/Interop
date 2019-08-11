#ifndef TASK_H
#define TASK_H
///////////////////////////////////////////////////////////////
// Task.h - Public interface of long running Task            //
//                                                           //
// Jim Fawcett, CSE687 - Object Oriented Design, Spring 2014 //
///////////////////////////////////////////////////////////////

#include "ITask.h"
#include <vcclr.h>

class Task
{
public:
  // constructor accepts reference to Bridge as an ITask

  Task(ITask^ hBridge = nullptr) : hBridge_(hBridge) {}
  
  // Long task

  void makeSoundAndSleep(int millisec);

private:
  gcroot<ITask^> hBridge_; // reference to C++\CLI Bridge
};

#endif

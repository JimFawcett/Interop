#ifndef ITASK_H
#define ITASK_H
///////////////////////////////////////////////////////////////
// ITask.cpp - Abstract Interface for long task              //
//                                                           //
// Jim Fawcett, CSE687 - Object Oriented Design, Spring 2014 //
///////////////////////////////////////////////////////////////

public ref class ITask abstract
{
public:
  delegate void EventCallBack(int);  // callback status to MainWindow
  EventCallBack^ callback = nullptr;
  
  // UI thread sends its dispatcher to Bridge for callback

  virtual void run(System::Windows::Threading::Dispatcher^ disp) = 0;

  // callback for native task to return progress count to Bridge

  virtual void doCallBack(int i) = 0;

  static ITask^ Create();  // factory function
};

#endif

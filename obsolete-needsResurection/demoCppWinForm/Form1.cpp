/////////////////////////////////////////////////////////////////////
// Form1.cpp - Implements form displaying files and directories    //
//             in a list box.  Provides a browse control written   //
//             in C# that allows users to select a path to search, //
//             using a treeView control.                           //
//                                                                 //
// Jim Fawcett, CSE687 - Object Oriented Design, Spring 2004       //
/////////////////////////////////////////////////////////////////////
// Notes:                                                          //
//   This project demonstrates how to communicate between two      //
//   forms.  The same techniques work for any two classes that     //
//   are defined in seperate modules.                              //
/////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Form1.h"
#include <windows.h>

using namespace demoWinForm;

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
  System::Threading::Thread::CurrentThread->ApartmentState 
    = System::Threading::ApartmentState::STA;
  Application::Run(new Form1());
  return 0;
}

/////////////////////////////////////////////////////////////////////////////
// WPF-ConsoleApplication.cpp - C++\CLI implementation of WPF Application  //
//                                                                         //
// Jim Fawcett, CSE687 - Object Oriented Design, Spring 2014               //
/////////////////////////////////////////////////////////////////////////////
/*
 * To run as Console application:
 * - Set Project Properties > Linker > System > Subsystem to Console
 * - uncomment Console statements in makeSoundAndSleep function
 * - uncomment Console statement in main, below
 * - uncomment main, below
 * - comment WinMain, below
 *
 * To run as Windows application:
 * - Set Project Properties > Linker > System > Subsystem to Windows
 * - comment Console statements in makeSoundAndSleep function
 * - comment Console statement in main, below
 * - comment main, below
 * - uncomment WinMain, below
 */
#include "WPF-ConsoleApplication.h"

using namespace WPF_ConsoleApplication;

[STAThread]
int main(array<System::String^>^ args)
//int _stdcall WinMain()
{
  Application^ app = gcnew Application();
  app->Run(gcnew WPFDemo());
  Console::WriteLine(L"\n\n");
  return 0;
}

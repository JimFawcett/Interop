#ifndef CPPBRIDGE_H
#define CPPBRIDGE_H
/////////////////////////////////////////////////////////////////////
//  CppBridge.h  - Defines a C++\CLI ref class interface for       //
//                 a C# Form to extract tokens from a file         //
//  ver 1.0                                                        //
//  Language:      Visual C++ 2008, SP1                            //
//  Platform:      Dell Precision T7400, Win 7, Pro                //
//  Application:   Prototype for CSE687 Pr4, Sp10                  //
//  Author:        Jim Fawcett, CST 4-187, Syracuse University     //
//                 (315) 443-3948, jfawcett@twcny.rr.com           //
/////////////////////////////////////////////////////////////////////
/*
  Module Operations: 
  ==================
  Provides a tokenizing interface, in managed C++\CLI ref class Bridge,
  intended for use by a C# form.

  Public Interface (as seen by C# code):
  ======================================
  Bridge br;
  if(br.fileToTokenize(String^ fileHandle))
  {
    String^ str = getTok();
  }

  Also provides the utility functions:
    std::string manStrConv(String^ str);
    String^ stdStrConv(const std::string& str);

  Build Process:
  ==============
  Required files
    - Form1.cs, Program.cs, CppBridge.h, CppBridge.cpp, 
      tokenizer.h, tokenizer.cpp
  Build commands
    - devenv FormsInterop.sln

  Maintenance History:
  ====================
  ver 1.0 : 21 Apr 10
  - first release

*/

#include <string>
using namespace System;

public ref class Bridge
{
public:
  ~Bridge() { delete pToker; }
  bool fileToTokenize(String^ fileHandle);
  String^ getTok();
  std::string manStrConv(String^ str);
  String^ stdStrConv(const std::string& str);
private:
  Toker* pToker;
};
#endif

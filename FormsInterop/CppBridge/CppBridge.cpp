/////////////////////////////////////////////////////////////////////
//  CppBridge.cpp - Defines a C++\CLI ref class interface for      //
//                  a C# Form to extract tokens from a file        //
//  ver 1.0                                                        //
//  Language:      Visual C++ 2008, SP1                            //
//  Platform:      Dell Precision T7400, Win 7, Pro                //
//  Application:   Prototype for CSE687 Pr4, Sp10                  //
//  Author:        Jim Fawcett, CST 4-187, Syracuse University     //
//                 (315) 443-3948, jfawcett@twcny.rr.com           //
/////////////////////////////////////////////////////////////////////

#include "../tokenizer/tokenizer.h"
#include "CppBridge.h"

std::string Bridge::manStrConv(String^ str)
{
  std::string temp;
  for(int i=0; i<str->Length; ++i)
    temp += static_cast<char>(str[i]);
  return temp;
}

String^ Bridge::stdStrConv(const std::string& str)
{
  String^ temp;
  for(size_t i=0; i<str.size(); ++i)
    temp += static_cast<wchar_t>(str[i]);
  return temp;
}
bool Bridge::fileToTokenize(String^ fileHandle)
{
  pToker = new Toker;
  std::string file = manStrConv(fileHandle);
  if(!pToker->attach(file))
  {
    std::cout << "\n  could not attach to file " << file << "\n\n";
    pToker = 0;
    return false;
  }
  return true;
}

String^ Bridge::getTok()
{
  std::string tok = pToker->getTok();
  return stdStrConv(tok);
}
using namespace System;

int main(array<System::String ^> ^args)
{
  Bridge br;
  br.fileToTokenize("../Tokenizer/Tokenizer.h");
  while(true)
  {
    String^ tok = br.getTok();
    if(tok == nullptr || tok->Equals(""))
      break;
    if(tok != L"\n")
      Console::Write("\n  {0}",tok);
  }
  return 0;
}

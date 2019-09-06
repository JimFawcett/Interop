/////////////////////////////////////////////////////////////////////////
// CppBridge.cpp - C++/CLI bridge between C# client and C++ tokenizer  //
//                                                                     //
// Jim Fawcett, CSE775 - Distributed Objects, Spring 2012              //
/////////////////////////////////////////////////////////////////////////

#include <string>
#include "Tokenizer.h"
#include "IBridge.h"

using namespace System;

ref class Bridge : public IBridge
{
public:
  Bridge();
  virtual bool attachStream(String^ filename) override;
  virtual String^ getTok() override;
private:
  Toker* pToker;
};

IBridge^ IBridge::createBridge()
{
  return gcnew Bridge();
}

Bridge::Bridge()
{
  pToker = new Toker;
}

bool Bridge::attachStream(String^ filename)
{
  std::string temp;
  for(int i=0; i<filename->Length; ++i)
    temp += (char)filename[i];
  return pToker->attach(temp);
}

String^ Bridge::getTok()
{
  System::Text::StringBuilder^ temp = gcnew System::Text::StringBuilder();
  std::string tok = pToker->getTok();
  for(size_t i=0; i<tok.size(); ++i)
    temp->Append((wchar_t)tok[i]);
  return temp->ToString();
}

int main(array<System::String ^> ^args)
{
    Console::Write(L"\n  Demonstrating InterOperation");
    Console::Write(L"\n ==============================\n");
    
    if(args->Length == 0)
    {
      Console::Write(L"\n  Please enter name of file to tokenize on command line\n\n");
      return 1;
    }
    IBridge^ bridge = IBridge::createBridge();

    if(bridge->attachStream(args[0]))
    {
      String^ tok;
      do
      {
        tok = bridge->getTok();
        if(tok != "\n")
          Console::Write("\n  {0}",tok);
      } while(tok->Length > 0);
    }
    else
    {
      Console::Write("\n  Can't open file {0}\n\n",args[0]);
      return 1;
    }
    return 0;
}

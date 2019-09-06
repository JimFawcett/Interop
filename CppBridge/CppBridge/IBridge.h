#ifndef IBRIDGE_H
#define IBRIDGE_H
/////////////////////////////////////////////////////////////////////////
// IBridge.I - abstract base for C++/CLI bridge for C++ tokenizer      //
//                                                                     //
// Jim Fawcett, CSE775 - Distributed Objects, Spring 2012              //
/////////////////////////////////////////////////////////////////////////

using namespace System;

public ref class IBridge abstract
{
public:
  static IBridge^ createBridge();
  virtual bool attachStream(String^ filename)=0;
  virtual String^ getTok()=0;
};

#endif

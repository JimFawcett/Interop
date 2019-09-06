#ifndef IMARSHALINGLIB_H
#define IMARSHALINGLIB_H
/////////////////////////////////////////////////////////////////////
// MarshalingLib.H - Demonstrates use of marshaling and PInvoke    //
//                                                                 //
// Jim Fawcett, CSE775 - Distributed Objects, Spring 2003          //
/////////////////////////////////////////////////////////////////////

class IMarshalingLib
{
public:
  virtual void demoTransfer(const char* s) = 0;
};

#endif

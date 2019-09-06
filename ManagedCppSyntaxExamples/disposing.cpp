///////////////////////////////////////////////////////////////
// disposing.cpp - returning resources                       //
//                                                           //
// Jim Fawcett, CSE687 - Object Oriented Design, Spring 2005 //
///////////////////////////////////////////////////////////////

#using <mscorlib.dll>
using namespace System;
using namespace System::IO;
using namespace System::Text;

void main()
{
  try
  {
    StreamWriter^ StrmWr = gcnew StreamWriter("Test.txt");
    StringBuilder^ sb = gcnew StringBuilder();
    sb->Append("  a line of text");
    StringWriter^ StrgWr = gcnew StringWriter(sb);

    StrmWr->WriteLine(sb->ToString());
    Console::WriteLine("  Disposing of {0}",StrmWr->GetType()); 
    StrmWr->Dispose();

    StrgWr->Write(sb->ToString());
    Console::WriteLine(sb->ToString());
    Console::WriteLine("  Disposing of {0}",StrgWr->GetType());
    StrgWr->Dispose();
  }
  catch(...)
  {
//    StrmWr->Dispose(true);
//    StrgWr->Dispose(true);
  }
}
/*
  Console::WriteLine();
  sb->Remove(0,sb.Length);
  sb->Append("  another line of text");
  StrmWr = new StreamWriter("Test.txt");
  StrgWr = new StringWriter(sb);
      
  using( StrgWr )
  using( StrmWr )
  {
    StrmWr->WriteLine(sb.ToString());
    Console::WriteLine("  Disposing of {0}",StrmWr.GetType());  
    StrgWr->Write(sb.ToString());
    Console::WriteLine(sb.ToString());
    Console->WriteLine("  Disposing of {0}",StrgWr.GetType());  
  }
}
*/
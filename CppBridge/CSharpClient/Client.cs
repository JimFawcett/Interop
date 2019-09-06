///////////////////////////////////////////////////////////////////////
// Client.cs - C# console application that calls a C++ tokenizer     //
//                                                                   //
// Jim Fawcett, CSE775 - Distributed Objects, Spring 2012            //
///////////////////////////////////////////////////////////////////////
/*
 *   This client uses a C++/CLI Bridge class to use a C++ tokenizer
 *   designed as a native application.
 */

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CSharpClient
{
  class Client
  {
    static void Main(string[] args)
    {
      Console.Write("\n  Demonstrating C# to C++ Interoperation");
      Console.Write("\n ========================================\n");

      if (args.Length == 0)
      {
        Console.Write("\n  Please enter name of file to process on command line\n\n");
        return;
      }
      IBridge Bridge = IBridge.createBridge();
      if (Bridge.attachStream(args[0]))
      {
        string tok = "aTok";
        while (tok.Length > 0)
        {
          tok = Bridge.getTok();
          if(tok != "\n")
            Console.Write("\n  {0}", tok);
        }
      }
      else
      {
        Console.Write("\n  Can't open file {0}\n\n", args[0]);
        return;
      }
    }
  }
}

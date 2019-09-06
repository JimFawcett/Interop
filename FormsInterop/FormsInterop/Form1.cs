/////////////////////////////////////////////////////////////////////
//  Form1.cs   -  C# Form displays tokens extracted with           //
//                   native C++ tokenizer                          //
//  ver 1.1                                                        //
//  Language:      Visual C++ 2008, SP1                            //
//  Platform:      Dell Precision T7400, Win 7, Pro                //
//  Application:   Prototype for CSE687 Pr4, Sp10                  //
//  Author:        Jim Fawcett, CST 4-187, Syracuse University     //
//                 (315) 443-3948, jfawcett@twcny.rr.com           //
/////////////////////////////////////////////////////////////////////
/*
  Module Operations: 
  ==================
  Displays tokens in listbox, extracted by native C++ tokenizer embedded
  in C++\CLI project.  This project uses a C++\CLI Bridge ref class
  to make calls into the tokenizer.

  Build Process:
  ==============
  Required files
    - Form1.cs, Program.cs, CppBridge.h, CppBridge.cpp, 
      tokenizer.h, tokenizer.cpp
  Build commands
    - devenv FormsInterop.sln
  Note:
    - If you run on a 64 bit machine you will need to set the property
      Build\Platform Target to x86

  Maintenance History:
  ====================
  ver 1.1 : 25 Apr 10
  - Set Build\Platform Target to x86, added note, above.
  ver 1.0 : 21 Apr 10
  - first release

*/
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace FormsInterop
{
  public partial class Form1 : Form
  {
    public Form1()
    {
      InitializeComponent();
    }

    private void button1_Click(object sender, EventArgs e)
    {
      Bridge br = new Bridge();
      if (!br.fileToTokenize("../../../Tokenizer/Tokenizer.h"))
      {
        listBox1.Items.Add("Can't open file");
        return;
      }
      while(true)
      {
        String tok = br.getTok();
        if(tok == null || tok.Equals(""))
          break;
        if(tok != "\n")
          listBox1.Items.Add(tok);
      }
    }

    private void Form1_Load(object sender, EventArgs e)
    {
      Text = "Forms Interop Demo";
    }
  }
}

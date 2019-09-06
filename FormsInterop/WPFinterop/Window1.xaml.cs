/////////////////////////////////////////////////////////////////////
//  Window1.Xaml.cs - WPF Window displays tokens extracted with    //
//                    native C++ tokenizer                         //
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
  Displays tokens in listbox, extracted by native C++ tokenizer embedded
  in C++\CLI project.  This project uses a C++\CLI Bridge ref class
  to make calls into the tokenizer.

  Build Process:
  ==============
  Required files
    - Window1.Xaml.cs, Window1.Xaml, App.Xaml.cs, App.Xaml,
      CppBridge.h, CppBridge.cpp, tokenizer.h, tokenizer.cpp
  Build commands
    - devenv FormsInterop.sln

  Maintenance History:
  ====================
  ver 1.0 : 21 Apr 10
  - first release

*/
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace WPFinterop
{
  /// <summary>
  /// Interaction logic for Window1.xaml
  /// </summary>
  public partial class Window1 : Window
  {
    public Window1()
    {
      InitializeComponent();
    }

    private void button1_Click(object sender, RoutedEventArgs e)
    {
      Bridge br = new Bridge();
      if (!br.fileToTokenize("../../../Tokenizer/Tokenizer.h"))
      {
        listBox1.Items.Add("Can't open file");
        return;
      }
      while (true)
      {
        String tok = br.getTok();
        if (tok == null || tok.Equals(""))
          break;
        if (tok != "\n")
          listBox1.Items.Add(tok);
      }
    }

    private void Window_Loaded(object sender, RoutedEventArgs e)
    {
      this.Title = "WPF Interop Demo";
    }
  }
}

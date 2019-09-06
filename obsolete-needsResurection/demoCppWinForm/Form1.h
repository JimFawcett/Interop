#pragma once
/////////////////////////////////////////////////////////////////////
// Form1.h  -  Declares a form displaying files and directories    //
//             in a list box.  Provides a browse control written   //
//             in C# that allows users to select a path to search, //
//             using a treeView control.                           //
//                                                                 //
// Jim Fawcett, CSE687 - Object Oriented Design, Spring 2004       //
/////////////////////////////////////////////////////////////////////
// Notes:                                                          //
//   This project demonstrates how to communicate between two      //
//   forms.  The same techniques work for any two classes that     //
//   are defined in seperate modules.                              //
/////////////////////////////////////////////////////////////////////

#using <mscorlib.dll>
#include "BrowseForm.h"

namespace demoWinForm
{
  using namespace System;
  using namespace System::ComponentModel;
  using namespace System::Collections;
  using namespace System::Windows::Forms;
  using namespace System::Data;
  using namespace System::Drawing;
  using namespace System::IO;
  using namespace System::Text;

  /// <summary> 
  /// Summary for Form1
  ///
  /// WARNING: If you change the name of this class, you will need to change the 
  ///          'Resource File Name' property for the managed resource compiler tool 
  ///          associated with all .resx files this class depends on.  Otherwise,
  ///          the designers will not be able to interact properly with localized
  ///          resources associated with this form.
  /// </summary>
  public __gc class Form1 : public System::Windows::Forms::Form
  { 
  public:
    Form1(void)
    {
      InitializeComponent();
    }
  
//
  protected:
    void Dispose(Boolean disposing)
    {
      if (disposing && components)
      {
        components->Dispose();
      }
      __super::Dispose(disposing);
    }
  private: System::Windows::Forms::ListBox *  listBox1;
  private: System::Windows::Forms::TextBox *  textBox1;
  private: System::Windows::Forms::Button *  button1;
  private: System::Windows::Forms::StatusBar *  statusBar1;
  private: System::Windows::Forms::Button *  button2;

  private: bool _showFiles, _showDirs;
  private: System::Windows::Forms::Button *  button3;

  private:
    System::ComponentModel::Container * components;
    void InitializeComponent(void)
    {
      this->listBox1 = new System::Windows::Forms::ListBox();
      this->textBox1 = new System::Windows::Forms::TextBox();
      this->button1 = new System::Windows::Forms::Button();
      this->statusBar1 = new System::Windows::Forms::StatusBar();
      this->button2 = new System::Windows::Forms::Button();
      this->button3 = new System::Windows::Forms::Button();
      this->SuspendLayout();
      // 
      // listBox1
      // 
      this->listBox1->Anchor = (System::Windows::Forms::AnchorStyles)(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
        | System::Windows::Forms::AnchorStyles::Left) 
        | System::Windows::Forms::AnchorStyles::Right);
      this->listBox1->Font = new System::Drawing::Font(S"Tahoma", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)0);
      this->listBox1->ItemHeight = 16;
      this->listBox1->Location = System::Drawing::Point(16, 80);
      this->listBox1->Name = S"listBox1";
      this->listBox1->Size = System::Drawing::Size(464, 372);
      this->listBox1->TabIndex = 0;
      this->listBox1->DoubleClick += new System::EventHandler(this, listBox1_DoubleClick);
      // 
      // textBox1
      // 
      this->textBox1->AcceptsReturn = true;
      this->textBox1->Anchor = (System::Windows::Forms::AnchorStyles)((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
        | System::Windows::Forms::AnchorStyles::Right);
      this->textBox1->Font = new System::Drawing::Font(S"Tahoma", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)0);
      this->textBox1->Location = System::Drawing::Point(16, 16);
      this->textBox1->Name = S"textBox1";
      this->textBox1->Size = System::Drawing::Size(464, 23);
      this->textBox1->TabIndex = 1;
      this->textBox1->Text = S"";
      this->textBox1->TextChanged += new System::EventHandler(this, textBox1_TextChanged);
      // 
      // button1
      // 
      this->button1->Anchor = System::Windows::Forms::AnchorStyles::Top;
      this->button1->Font = new System::Drawing::Font(S"Tahoma", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)0);
      this->button1->Location = System::Drawing::Point(16, 48);
      this->button1->Name = S"button1";
      this->button1->Size = System::Drawing::Size(128, 23);
      this->button1->TabIndex = 2;
      this->button1->Text = S"ShowFiles";
      this->button1->Click += new System::EventHandler(this, button1_Click);
      // 
      // statusBar1
      // 
      this->statusBar1->Location = System::Drawing::Point(0, 476);
      this->statusBar1->Name = S"statusBar1";
      this->statusBar1->Size = System::Drawing::Size(496, 22);
      this->statusBar1->TabIndex = 3;
      this->statusBar1->Text = S"statusBar1";
      this->statusBar1->PanelClick += new System::Windows::Forms::StatusBarPanelClickEventHandler(this, statusBar1_PanelClick);
      // 
      // button2
      // 
      this->button2->Anchor = System::Windows::Forms::AnchorStyles::Top;
      this->button2->Font = new System::Drawing::Font(S"Tahoma", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)0);
      this->button2->Location = System::Drawing::Point(352, 48);
      this->button2->Name = S"button2";
      this->button2->Size = System::Drawing::Size(128, 23);
      this->button2->TabIndex = 2;
      this->button2->Text = S"ShowDirs";
      this->button2->Click += new System::EventHandler(this, button2_Click);
      // 
      // button3
      // 
      this->button3->Anchor = System::Windows::Forms::AnchorStyles::Top;
      this->button3->Font = new System::Drawing::Font(S"Tahoma", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, (System::Byte)0);
      this->button3->Location = System::Drawing::Point(184, 48);
      this->button3->Name = S"button3";
      this->button3->Size = System::Drawing::Size(128, 23);
      this->button3->TabIndex = 2;
      this->button3->Text = S"Browse";
      this->button3->Click += new System::EventHandler(this, button3_Click);
      // 
      // Form1
      // 
      this->AutoScaleBaseSize = System::Drawing::Size(5, 13);
      this->ClientSize = System::Drawing::Size(496, 498);
      this->Controls->Add(this->statusBar1);
      this->Controls->Add(this->button1);
      this->Controls->Add(this->textBox1);
      this->Controls->Add(this->listBox1);
      this->Controls->Add(this->button2);
      this->Controls->Add(this->button3);
      this->Name = S"Form1";
      this->Text = S"Form1";
      this->Load += new System::EventHandler(this, Form1_Load);
      this->ResumeLayout(false);

    } 
  
//
  //----< called after form completes loading >----------------------

  private: 
    System::Void Form1_Load(
      System::Object *  sender, System::EventArgs *  e)
    {
      this->Text = "C++ Form Demo";
      listBox1->Items->Clear();
      statusBar1->Text = "Please Enter Desired Path";
      textBox1->Text = "c:\\SU";
      button1->Text = "Don't Show Files";
      button2->Text = "Don't Show Dirs";
      _showFiles = true;
      _showDirs = true;
      textBox1_TextChanged(this,0);
    }
  //----< handler for textBox text change >--------------------------
  
  private: 
    System::Void textBox1_TextChanged(
      System::Object *  sender, System::EventArgs *  e)
    {
      StringBuilder* path = new StringBuilder(textBox1->Text);
      try
      {
        // strip spaces from path

        int len = path->Length;
        for(int i=len-1; i>=0; --i)
          if(path->Chars[i] == ' ')
            path->Remove(i,1);
        
        // Attempt to set current directory to this path.
        // FCL ensures that user's path will be reset
        // at end of program.

        Directory::SetCurrentDirectory(path->ToString());
        listBox1->Items->Clear();
        if(_showDirs)
        {
          String* dirs[] = Directory::GetDirectories(path->ToString(),"*.*");
          for(int i=0; i<dirs->Length; ++i)
          {
            listBox1->Items->Add(dirs[i]);
          }
        }
        if(_showFiles)
        {
          String* files[] = Directory::GetFiles(path->ToString(),"*.*");
          for(int i=0; i<files->Length; ++i)
          {
            String* file = Path::GetFileName(files[i]);
            listBox1->Items->Add(file);
          }
        }
        statusBar1->Text = "";
      }
      catch(Exception* )
      {
        statusBar1->Text = "invalid path";
      }
    }
//
  //----< handler for Show Files button >----------------------------

  private: 
    System::Void button1_Click(
      System::Object *  sender, System::EventArgs *  e)
    {
      if(!_showFiles)
      {
        _showFiles = true;
        button1->Text = "Don't Show Files";
      }
      else
      {
        _showFiles = false;
        button1->Text = "Show Files";
      }
      textBox1_TextChanged(this,0);
    }
  //----< handler for Show Dirs button >-----------------------------

  private: 
    System::Void button2_Click(
      System::Object *  sender, System::EventArgs *  e)
    {
      if(!_showDirs)
      {
        _showDirs = true;
        button2->Text = "Don't Show Dirs";
      }
      else
      {
        _showDirs = false;
        button2->Text = "Show Dirs";
      }
      textBox1_TextChanged(this,0);
    }
  //----< handler for Browse button >--------------------------------

  private: 
    System::Void button3_Click(
      System::Object *  sender, System::EventArgs *  e)
    {
      BrowseForm* bf = new BrowseForm();
      bf->setBaseForm(this);  // allows BrowseForm to call back
      bf->setPathEvent += new BrowseForm::setPathDelegate(this,setPath);
      bf->Show();
      bf->Update();
    }
//
  //----< handler for statusbar clicked >----------------------------

  private: 
    System::Void statusBar1_PanelClick(
      System::Object *  sender, 
      System::Windows::Forms::StatusBarPanelClickEventArgs *  e)
    {
      // not used
    }

  //---< provides way for another class to pass path to this form >--

  public:
    void setPath(String* path)
    {
      textBox1->Text = path;
      textBox1_TextChanged(this,0);
    }

  //----< handler for listBox1 selection >---------------------------
  private: 
    System::Void listBox1_DoubleClick(
      System::Object *  sender, System::EventArgs *  e)
    {
      StringBuilder* msg = new StringBuilder("Do something with ");
      int index = listBox1->SelectedIndex;
      String* selected = static_cast<String*>(listBox1->Items->Item[index]);
      msg->Append(selected);
      MessageBox::Show(msg->ToString());
    }

};
}

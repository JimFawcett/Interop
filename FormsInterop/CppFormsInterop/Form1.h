#pragma once
/////////////////////////////////////////////////////////////////////
//  Form1.h    -   C++\CLI Form displays tokens extracted with     //
//                   native C++ tokenizer                          //
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
    - Form1.h, CppFormsInterop.cpp, CppBridge.h, CppBridge.cpp, 
      tokenizer.h, tokenizer.cpp
  Build commands
    - devenv FormsInterop.sln
  Note:
    - If you run on a 64 bit machine you will need to set the property:
      Linker\Advanced\Target to MachineX86

  Maintenance History:
  ====================
  ver 1.0 : 24 Apr 10
  - first release

*/

#using <.\debug\CppBridge.dll>

namespace CppFormsInterop {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
      this->Text = "C++ Form Interop Demo";
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
  private: System::Windows::Forms::Button^  button1;
  protected: 
  private: System::Windows::Forms::ListBox^  listBox1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
      this->button1 = (gcnew System::Windows::Forms::Button());
      this->listBox1 = (gcnew System::Windows::Forms::ListBox());
      this->SuspendLayout();
      // 
      // button1
      // 
      this->button1->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
      this->button1->Location = System::Drawing::Point(106, 287);
      this->button1->Name = L"button1";
      this->button1->Size = System::Drawing::Size(75, 23);
      this->button1->TabIndex = 0;
      this->button1->Text = L"Start";
      this->button1->UseVisualStyleBackColor = true;
      this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
      // 
      // listBox1
      // 
      this->listBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
        | System::Windows::Forms::AnchorStyles::Left) 
        | System::Windows::Forms::AnchorStyles::Right));
      this->listBox1->FormattingEnabled = true;
      this->listBox1->ItemHeight = 16;
      this->listBox1->Location = System::Drawing::Point(13, 13);
      this->listBox1->Name = L"listBox1";
      this->listBox1->Size = System::Drawing::Size(257, 260);
      this->listBox1->TabIndex = 1;
      // 
      // Form1
      // 
      this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
      this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
      this->ClientSize = System::Drawing::Size(282, 322);
      this->Controls->Add(this->listBox1);
      this->Controls->Add(this->button1);
      this->Name = L"Form1";
      this->Text = L"Form1";
      this->ResumeLayout(false);

    }
#pragma endregion
  private:
    System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
    {
      Bridge^ br = gcnew Bridge();
      if (!br->fileToTokenize("../Tokenizer/Tokenizer.h"))
      {
        listBox1->Items->Add("Can't open file");
        return;
      }
      while(true)
      {
        String^ tok = br->getTok();
        if(tok == nullptr || tok->Equals(""))
          break;
        if(tok != "\n")
          listBox1->Items->Add(tok);
      }
    }
  };
}


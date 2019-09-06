#pragma once
/////////////////////////////////////////////////////////////////////
// BrowseForm.h - declares browse form, used to send selected      //
//                paths back to parent form                        //
//                                                                 //
// Jim Fawcett, CSE687 - Object Oriented Design, Spring 2004       //
/////////////////////////////////////////////////////////////////////
// Notes:                                                          //
//   This form hosts a .Net control, tvPlus, written in C#.        //
//   Amazingly, you just pull the control from the toolbox         //
//   (you have to add the control to the toolbox first) onto       //
//   the form and use it!  Everything just works due to the        //
//   effective interoperability mechanisms built into .Net.        //
/////////////////////////////////////////////////////////////////////

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Threading;

namespace demoWinForm
{
  /// <summary> 
  /// Summary for BrowseForm
  ///
  /// WARNING: If you change the name of this class, you will need to change the 
  ///          'Resource File Name' property for the managed resource compiler tool 
  ///          associated with all .resx files this class depends on.  Otherwise,
  ///          the designers will not be able to interact properly with localized
  ///          resources associated with this form.
  /// </summary>

  public __gc class BrowseForm : public System::Windows::Forms::Form
  {
  public: 
    BrowseForm(void)
      : _baseForm(NULL), _first(true)
    {
      InitializeComponent();
    }
        
  protected: 
    void Dispose(Boolean disposing)
    {
      if (disposing && components)
      {
        components->Dispose();
      }
      __super::Dispose(disposing);
    }

  private: TreeViewPlus::TVPlus *  tvPlus1;
  private: System::ComponentModel::IContainer^ components;

//
  private:

    void InitializeComponent(void)
    {
      this->components = (gcnew System::ComponentModel::Container());
      this->tvPlus1 = (gcnew TreeViewPlus::TVPlus());
      this->SuspendLayout();
      // 
      // tvPlus1
      // 
      this->tvPlus1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
        | System::Windows::Forms::AnchorStyles::Left)
        | System::Windows::Forms::AnchorStyles::Right));
      this->tvPlus1->ImageIndex = 0;
      this->tvPlus1->Location = System::Drawing::Point(13, 12);
      this->tvPlus1->Name = L"tvPlus1";
      this->tvPlus1->SelectedImageIndex = 0;
      this->tvPlus1->showFiles = false;
      this->tvPlus1->Size = System::Drawing::Size(260, 452);
      this->tvPlus1->TabIndex = 0;
      this->tvPlus1->AfterSelect += gcnew System::Windows::Forms::TreeViewEventHandler(this, &BrowseForm::tvPlus1_AfterSelect);
      // 
      // BrowseForm
      // 
      this->AutoScaleBaseSize = System::Drawing::Size(8, 19);
      this->ClientSize = System::Drawing::Size(292, 490);
      this->Controls->Add(this->tvPlus1);
      this->Name = L"BrowseForm";
      this->Text = L"BrowseForm";
      this->Load += gcnew System::EventHandler(this, &BrowseForm::BrowseForm_Load);
      this->ResumeLayout(false);

    }
  
    //----< handle treeView selection event >------------------------
  private: 
    System::Void tvPlus1_AfterSelect(
      System::Object *  sender, System::Windows::Forms::TreeViewEventArgs *  e);

    //----< build tree after form loads >----------------------------
  private: 
    System::Void BrowseForm_Load(
      System::Object *  sender, System::EventArgs *  e)
    {
      tvPlus1->buildTree();
    }
    //----< enables parent to send me its reference >----------------

  public:
    void setBaseForm(Form* baseForm);
    __delegate void setPathDelegate(String* path);
    __event setPathDelegate* setPathEvent;

  private:
    Form* _baseForm;
    bool _first;
  };
}
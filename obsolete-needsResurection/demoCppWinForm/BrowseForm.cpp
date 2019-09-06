/////////////////////////////////////////////////////////////////////
// BrowseForm.cpp - implements Browser members using parent form   //
//                                                                 //
// Jim Fawcett, CSE687 - Object Oriented Design, Spring 2004       //
/////////////////////////////////////////////////////////////////////
// Notes:                                                          //
//   The member functions implemented here can't be inlined in     //
//   BrowseForm.h.  That would required including the Form1.h      //
//   header in BrowseForm.h.  But Form1.h already includes the     //
//   BrowseForm.h file, and mutual includes between header files   //
//   don't work.                                                   //
/////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "BrowseForm.h"
#include "Form1.h"
using namespace demoWinForm;

//----< called by parent form to provide its reference >-------------

void BrowseForm::setBaseForm(Form* baseForm)
{
  _baseForm = baseForm;
}

//----< event handler that sends selected path back to parent >------

System::Void BrowseForm::tvPlus1_AfterSelect(
  System::Object *  sender, System::Windows::Forms::TreeViewEventArgs *  e)
{
  if(!_first)  // don't call back if this is first selection
  {
    String* path = e->get_Node()->FullPath;
    Form1* pForm = static_cast<Form1*>(_baseForm);

  ///////////////////////////////////////////////////////
  // statement below is simple way to communicate with
  // parent form, but not as flexible as delegate-based
  // method used here
  //   pForm->setPath(path);

  // set up delegate argument

    String* argArray[] = new String*[1];
    argArray[0] = path;

  // invoke delegate to callback on parent form's setPathEvent handler
  // in way that is safe even if called from a thread that did not create 
  // form

    if(pForm->InvokeRequired)
      pForm->BeginInvoke(setPathEvent, argArray);  // called by worker thread
    else
      setPathEvent(path);                          // called by UI thread
    return;
  }
  _first = false;
}

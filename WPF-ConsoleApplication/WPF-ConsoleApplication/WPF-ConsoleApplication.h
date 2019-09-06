///////////////////////////////////////////////////////////////////////////
// WPF-ConsoleApplication.h - C++\CLI implementation of WPF Application  //
//                                                                       //
// Jim Fawcett, CSE687 - Object Oriented Design, Spring 2014             //
///////////////////////////////////////////////////////////////////////////
/*
 * Right - click project > Add > References
 *   add references to :
 *     System.Windows
 *     WindowsBase
 *     PresentatioCore
 *     PresentationFramework
 */

using namespace System;
using namespace System::Windows;
using namespace System::Windows::Input;
using namespace System::Windows::Markup;
using namespace System::Windows::Media;
using namespace System::Windows::Controls;
using namespace System::Threading;
using namespace System::Threading::Tasks;
using namespace System::Windows::Threading;

namespace WPF_ConsoleApplication
{
  ref class WPFDemo : Window
  {
    Button^ hSynchButton = gcnew Button();
    Button^ hAsyncButton = gcnew Button();
    TextBlock^ hTextBlock = gcnew TextBlock();
    StackPanel^ hStackPanel = gcnew StackPanel();
    Grid^ hGrid = gcnew Grid();
    Windows::Threading::Dispatcher^ hDispatcher;
    delegate void Tasker(int);
    Tasker^ doTask;
    IAsyncResult^ hResult;

  public:

    WPFDemo()
    {
      doTask = gcnew Tasker(this, &WPFDemo::makeSoundAndSleep);
      this->Title = "WPF Demo";
      this->Width = 600;
      this->Height = 300;

      // provide access to UI thead dispatcher

      hDispatcher = Windows::Threading::Dispatcher::CurrentDispatcher;

      // set window layout with Grid

      this->Content = hGrid;
      hGrid->Margin = Thickness(20);
      RowDefinition^ hRow1Def = gcnew RowDefinition();
      hRow1Def->Height = GridLength(100);
      hGrid->RowDefinitions->Add(hRow1Def);
      RowDefinition^ hRow2Def = gcnew RowDefinition();
      hRow1Def->Height = GridLength(100);
      hGrid->RowDefinitions->Add(hRow2Def);

      // textBlock

      hTextBlock->Text = "Click button to start long task";
      hTextBlock->FontSize = 24;
      hTextBlock->FontFamily = gcnew Windows::Media::FontFamily("Tahoma");
      hTextBlock->FontWeight = FontWeights::Bold;
      hTextBlock->TextAlignment = TextAlignment::Center;
      hTextBlock->VerticalAlignment = Windows::VerticalAlignment::Center;
      Border^ hBorder = gcnew Border();
      hBorder->BorderThickness = Thickness(3);
      hBorder->Width = 400;
      hBorder->BorderBrush = Brushes::Black;
      hBorder->Child = hTextBlock;
      hGrid->Children->Add(hBorder);
      hGrid->SetRow(hTextBlock, 0);

      // SynchButton

      hSynchButton->Height = 40;
      hSynchButton->Width = 180;
      hSynchButton->Margin = Thickness(10);
      hSynchButton->VerticalAlignment = Windows::VerticalAlignment::Center;
      hSynchButton->HorizontalAlignment = Windows::HorizontalAlignment::Center;
      hSynchButton->Content = "Run Synchronous Task";
      hSynchButton->Click += gcnew RoutedEventHandler(this, &WPFDemo::OnSynchClick);

      // AyncButton

      hAsyncButton->Height = 40;
      hAsyncButton->Width = 180;
      hAsyncButton->Margin = Thickness(10);
      hAsyncButton->VerticalAlignment = Windows::VerticalAlignment::Center;
      hAsyncButton->HorizontalAlignment = Windows::HorizontalAlignment::Center;
      hAsyncButton->Content = "Run Asynchronous Task";
      hAsyncButton->Click += gcnew RoutedEventHandler(this, &WPFDemo::OnAsyncClick);

      // StackPanel

      hStackPanel->Orientation = Orientation::Horizontal;
      hStackPanel->HorizontalAlignment = Windows::HorizontalAlignment::Center;
      hStackPanel->Children->Add(hSynchButton);
      hStackPanel->Children->Add(hAsyncButton);

      hGrid->Children->Add(hStackPanel);
      hGrid->SetRow(hStackPanel, 1);
    }
    //----< will be called on main thread from delegate >----------------

    void enableButtons()
    {
      hSynchButton->IsEnabled = true;
      hAsyncButton->IsEnabled = true;
      hTextBlock->Text = "Finished long task";
    }
    //----< long task >--------------------------------------------------

    void makeSoundAndSleep(int millisec)
    {
      Console::Clear();
      int imax = millisec / 1000;
      for (int i = 0; i < imax; ++i)
      {
        System::Media::SystemSounds::Asterisk->Play();
        Console::Write("\n  looping in long task");
        Thread::Sleep(500 * imax);
      }
      if (hDispatcher->Thread->Equals(Thread::CurrentThread))  // running on UI thread
      {
        enableButtons();
      }
      else  // running on delegate dispatched thread
      {
        System::Action^ act1 = gcnew Action(this, &WPFDemo::enableButtons);
        Dispatcher->Invoke(act1);
      }
    }
    //----< Force window to refresh >------------------------------------

    void renderWindow()
    {
      WPFDemo::UpdateLayout();
      DispatcherPriority::Send;
    }
    //----< Run long task on UI Thread >---------------------------------

    void OnSynchClick(Object^ sender, RoutedEventArgs^ e)
    {
      hSynchButton->IsEnabled = false;
      hAsyncButton->IsEnabled = false;
      hTextBlock->Text = "Running long task";

      // Force window to render before starting long task

      System::Action^ act = gcnew Action(this, &WPFDemo::renderWindow);
      Dispatcher->Invoke(act, DispatcherPriority::Render);
      
      // long task

      makeSoundAndSleep(5000);
    }
    //----< Run long task on delegate spawned child thread >-------------

    void OnAsyncClick(System::Object^ sender, System::Windows::RoutedEventArgs^ e)
    {
      if (hResult != nullptr)
        doTask->EndInvoke(hResult);
      hSynchButton->IsEnabled = false;
      hAsyncButton->IsEnabled = false;
      hTextBlock->Text = "Running long task";
      
      /////////////////////////////////////////////////////////
      // The next two lines are declared at top of this file
      // delegate void Tasker(int);
      // Tasker^ doTask = gcnew Tasker(this, &WPFDemo::makeSoundAndSleep);

      hResult = doTask->BeginInvoke(5000, nullptr, gcnew Object());
    }
  };
}


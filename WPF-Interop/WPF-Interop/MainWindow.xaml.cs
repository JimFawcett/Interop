///////////////////////////////////////////////////////////////
// MainWindow.xaml.cs - Code behind for Demo Window          //
//                                                           //
// Jim Fawcett, CSE687 - Object Oriented Design, Spring 2014 //
///////////////////////////////////////////////////////////////
/*
 *  C# Program started with WPF wizard
 *  - provides buttons to run a long task synchronously and asynchronously
 *  - uses callbacks to notify user of progress on status bar
 */
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace WPF_Interop
{
  public partial class MainWindow : Window
  {
    public MainWindow()
    {
      InitializeComponent();
    }
    //----< set display to running state >-------------------------------

    void disableButtons()
    {
      textBlock.Text = "Running long task";
      SynchButton.IsEnabled = false;
      AsynchButton.IsEnabled = false;
    }
    //----< reset display to ready state >-------------------------------

    void enableButtons()
    {
      textBlock.Text = "Finished long task";
      SynchButton.IsEnabled = true;
      AsynchButton.IsEnabled = true;
      statusBlock.Text = "  Ready";
    }
    //----< Run long task synchronously on UI thread >-------------------

    private void SynchButton_Click(object sender, RoutedEventArgs e)
    {
      disableButtons();

      // Force UI to update.  Without this buttons stay enabled.

      Dispatcher.Invoke(() => InvalidateVisual(), System.Windows.Threading.DispatcherPriority.Render);

      // create native task instance

      ITask rTask = ITask.Create();
      
      // no point in sending callbacks - UI thread isn't listening
      // rTask.callback = new ITask.EventCallBack(this.updateStatus);

      rTask.run(Dispatcher);

      // Refresh UI

      enableButtons();
    }
    //----< wrapper runs long task asynchronously >----------------------

    Task longTaskWrapper()
    {
      // create instance of native task

      ITask rTask = ITask.Create();
      
      // hook up callback if not done already

      if (rTask.callback == null)
        rTask.callback = new ITask.EventCallBack(this.updateStatus);
  
      // run task asynchronously

      Task task = Task.Run(() => rTask.run(Dispatcher));
      return task;
    }
    //----< start long task asynchronously on threadpool thread >--------

    private async void AsynchButton_Click(object sender, RoutedEventArgs e)
    {
      disableButtons();      
      await longTaskWrapper();  // return immediately while running task on threadpool thread

      // statement below runs in continuation on UI thread
      
      enableButtons();
    }
    //----< callback for status bar >------------------------------------

    void updateStatus(int i)
    {
      statusBlock.Text = "  long task loop count " + i.ToString() + " of 5";
    }
  }
}

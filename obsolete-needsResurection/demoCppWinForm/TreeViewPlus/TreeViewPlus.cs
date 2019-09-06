/////////////////////////////////////////////////////////////////////////
///  TreeViewPlus.cs                                                  ///
///                - Navigates a Directory Subtree, providing events  ///
///  ver 1.0         for found new file and entered new directory.    ///
///                                                                   ///
///  Language:     Visual C#                                          ///
///  Platform:     Dell Dimension 8100, Windows Pro 2000, SP2         ///
///  Application:  CSE681 Example                                     ///
///  Author:       Jim Fawcett, CST 2-187, Syracuse Univ.             ///
///                (315) 443-3948, jfawcett@twcny.rr.com              ///
/////////////////////////////////////////////////////////////////////////
///
///  Client form must call buildTree() in its Form_Load event.
///  
using System;
using System.Collections;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Windows.Forms;
using System.IO;

namespace TreeViewPlus
{
  public class TVPlus : System.Windows.Forms.TreeView
  {
    private ImageList imgLst = null;

    public TVPlus()
    {
      this.ImageIndex = -1;
      this.SelectedImageIndex = -1;
      this.BeforeExpand += new System.Windows.Forms.TreeViewCancelEventHandler(this_BeforeExpand);

      imgLst = new ImageList();
      imgLst.Images.Add(new Bitmap(GetType(), "35FLOPPY.BMP"));
      imgLst.Images.Add(new Bitmap(GetType(), "CLSDFOLD.BMP"));
      imgLst.Images.Add(new Bitmap(GetType(), "OPENFOLD.BMP"));
      imgLst.Images.Add(new Bitmap(GetType(), "DOC.BMP"));
      imgLst.Images.Add(new Bitmap(GetType(), "EXE.BMP"));
      imgLst.Images.Add(new Bitmap(GetType(), "TXT.BMP"));
      this.ImageList = imgLst;
    }
    //
  //----< add directories and files to tree control view >-----------

    public void buildTree()
    {
      RefreshTree();

      // expand current path

      string path = Directory.GetCurrentDirectory();
      string [] subDirs = path.Split('\\');
      TreeNodeCollection nodes = this.Nodes;
      foreach(string subDir in subDirs)
      {
        string lcSubDir = subDir.ToLower();
        foreach(TreeNode node in nodes)
        {
          string t = node.Text;
          t = t.ToLower();
          if(t == lcSubDir | t == lcSubDir + '\\')
          {
            SelectedNode = node;
            node.Expand();
            nodes = node.Nodes;
            break;
          }
        }
      }
    }
    //----< rebuild tree from scratch >------------------------------

    public void RefreshTree()
    {
      this.BeginUpdate();
      this.Nodes.Clear();

      string [] drives = Directory.GetLogicalDrives();
      foreach(string drive in drives)
      {
        TreeNode folder;
        folder = new TreeNode(drive,0,0);
        this.Nodes.Add(folder);
        AddDirectories(folder);

        if(drive == "C:\\")
          this.SelectedNode = folder;
      }
      this.EndUpdate();
    }
    //
    //----< add directories to treeView control >--------------------

    void AddDirectories(TreeNode folder)
    {
      folder.Nodes.Clear();

      string fp = folder.FullPath;
      DirectoryInfo di = new DirectoryInfo(fp);
      DirectoryInfo [] dis;
      FileInfo [] fis;
      try
      {
        dis = di.GetDirectories();
        fis = di.GetFiles();
      }
      catch
      {
        return;
      }

      foreach(DirectoryInfo info in dis)
      {
        TreeNode node = new TreeNode(info.Name, 1, 2);
        folder.Nodes.Add(node);
      }
      if(!_showFiles)
        return;
      foreach(FileInfo info in fis)
      {
        int index = 5;
        if(info.Extension.ToLower() == ".exe")
          index = 4;
        if(info.Extension.ToLower() == ".doc")
          index = 3;
        TreeNode node = new TreeNode(info.Name, index, index);
        folder.Nodes.Add(node);
      }
    }
    //----< look down to next level to get dir and file info >-------

    private void this_BeforeExpand(
      Object sender, System.Windows.Forms.TreeViewCancelEventArgs e)
    {
      this.BeginUpdate();
      foreach(TreeNode node in e.Node.Nodes)
        AddDirectories(node);
      this.EndUpdate();
    }
    //
    //----< property: to showFiles or not to showFiles >-------------
    //                That is the question

    public bool showFiles
    {
      get
      {
        return _showFiles;
      }
      set
      {
        _showFiles = value;
      }
    }

    private bool _showFiles = false;
  }
}


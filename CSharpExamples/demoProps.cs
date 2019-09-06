///////////////////////////////////////////////////////////////
// demoProps.cs - Properties work this way
//
// Jim Fawcett, CSE775 - Distributed Objects, Spring 2003
///////////////////////////////////////////////////////////////

using System;

namespace Properties
{
	class demoProps
	{
    public string name
    {
      get { return _name; }
      set { _name = value; }
    }

    private string _name;

    [STAThread]
    static void Main(string[] args)
    {
      demoProps dp = new demoProps();
      dp.name = "Jim";
      Console.Write("\n  name property: {0}\n\n",dp.name);
    }
  }
}

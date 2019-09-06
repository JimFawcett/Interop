///////////////////////////////////////////////////////////////
// demoIndexers.cs - Indexers work this way
//
// Jim Fawcett, CSE687 - Object Oriented Design, Spring 2005
///////////////////////////////////////////////////////////////

#using <mscorlib.dll>
using namespace System;

namespace Indexers
{
  ref class demoIndexers
  {
  private:
    static String^ _falcon        = "falcon"; 
    static String^ _falconType    = "bird";
    static String^ _arrdvark      = "arrdvark"; 
    static String^ _arrdvarkType  = "mammal";
    static String^ _armadillo     = "armadillo"; 
    static String^ _armadilloType = "mammal";
    static String^ _kangaroo      = "kangaroo"; 
    static String^ _kangarooType  = "marsupial";

  public:

    property String^ default[String^]
    {
      String^ get(String^ creature)
      {
        if(creature->CompareTo(_falcon)    == 0) return _falconType;
        if(creature->CompareTo(_arrdvark)  == 0) return _arrdvarkType;
        if(creature->CompareTo(_armadillo) == 0) return _armadilloType;
        if(creature->CompareTo(_kangaroo)  == 0) return _kangarooType;
        return "unknown";
      }

      void set(String^ creature, String^ value)
      {
        if(creature->CompareTo(_falcon)   == 0) _falconType    = value;
        if(creature->CompareTo(_arrdvark) == 0) _arrdvarkType  = value;
        if(creature->CompareTo(_armadillo)== 0) _armadilloType = value;
        if(creature->CompareTo(_kangaroo) == 0) _kangarooType  = value;
      }
    }
  };
}

using namespace Indexers;

void main()
{
  Console::Write("\n  Demonstrating Indexers in Managed C++");
  Console::Write("\n =======================================\n");

  demoIndexers^ creatures = gcnew demoIndexers();
  Console::Write(
    "\n  creature[\"falcon\"] is {0}",
    creatures["falcon"]
  );
  creatures["falcon"] = "bird of prey";
  Console::Write(
    "\n  creature[\"falcon\"] is {0}\n\n",
    creatures["falcon"]
  );
}

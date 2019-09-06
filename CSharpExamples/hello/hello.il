/////////////////////////////////////////////////////////////
// hello il - first IL program                             //
//                                                         //
// Jim Fawcett, CSE775 - Distributed Objects, Spring 2005  //
/////////////////////////////////////////////////////////////

    .assembly MyAssembly {}
    .class MyApp {
      .method static void Main() {
        .entrypoint
        ldstr  "Hello, IL!"
        call   void [mscorlib]System.Console::WriteLine(class System.Object)
        ret
      }
    }

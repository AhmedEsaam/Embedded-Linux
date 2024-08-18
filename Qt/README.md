# Qt6 - QML with C++

* It is a across-platform application framework.

## Qt Framework

1. **Modules**: header files (classes written in C++) : Every module is implemented in one or more library.
   1. **Qt Core** --> for **Non-GUI** applications
   2. **Qt Widgets** --> for Desktop **GUI** applications
   3. **Qt Quick** --> for **GUI** applications that responds to touch gestures.

2. **Libraries**: binary code

   * **To build**: Qt applications are built using **qmake**:
     * In `file.pro`

       >```sh
       >Qt = Core   # Module used  
       >```

     * Then the **Makefile** is generated and links the application with the used modules.

3. **Tools**:
   1. **moc**: Meta-Object Compiler.
   2. **rcc**: Qt Resource Compiler.


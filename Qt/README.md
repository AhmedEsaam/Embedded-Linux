# Qt6 - QML with C++

* It is a across-platform application framework.

## Qt Framework

1. **Modules**: header files (classes written in C++) : Every module is implemented in one or more library.
   1. **Qt Core** --> for **Non-GUI** applications (it is also the core of the next two)
   2. **Qt Widgets** --> for Desktop **GUI** applications
   3. **Qt Quick** --> for **GUI** applications that responds to touch gestures.

2. **Libraries**: binary code

   * **To build**: Qt applications are built using **qmake** build system or **cmake**:
     * In `file.pro`

       >```sh
       >Qt = Core   # Module used  
       >```

     * Then the **Makefile** is generated and links the application with the used modules.

3. **Tools**
   1. **moc** : Meta-Object Compiler.
   2. **rcc** : Qt Resource Compiler.

## Syntax

```cpp
#include <QCoreApplication>
#include <iostream>
#include <QDebug>
#include <QString>

qInfo("hello");
```

## Signals and Solts

* There are events --> **Signals**
  * A signal is not a function --> it is a prototype.
* And, even handlers --> **solts**.

* A signal can be connected to one or more slots

```CPP
connect(Object1, signal1, Object2, slot1);
connect(Object1, signal1, Object2, slot2);
```

* Create your class and enable the signal and slot capability.
  * And that's be making your class inherit from the class `QOject` which contains signals and slots.
  * Put `Q_OBJECT` macro in the private section of your class.

---

## QML (Qt Modeling Language)

* Is a declarative language that describes the GUI of the application (But not the functionality.)
* You can say it's the front-end of the application.
* The C++ code will be the back-end of your application.
* The **QML** and **C++** are communicating using **signals** and **slots**.

* **QML** uses **quick** Module.

* Classes are **types** in **QML**.

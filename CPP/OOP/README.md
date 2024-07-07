# OOP

* Applications are consisted of **source** files and **header** files.

## Classes

* **Classes** are essentially templates for entities that have:

  1. Function
  2. Attributes

---

## Objects

* **Objects** are instances of the class blueprint.

---

## Example

```cpp
class Dio
{
    struct register Dio;
    set_pin_dir();
    set_pin_mode();
    set_pin_val();
};

DIO ARM();    # create an instance of the DIO class for the ARM architecture
```

---

## OOP Concepts

### Encapsulation

* Glopal vars contradicts the concept of encapsulation as it shares resources in the code.

* **Encapsulation** means that you put your variables and function inside one entity.

### Inheritance

* **Inheritance** allows you to extend the functionality of already provided blueprint.

```cpp
class DIO_ARM : public DIO
{
    # add functionality for ARM
}
```

### Polymorphism

#### Static Polymorphism

* **In compile time**, compiler handles calling functions with the same name but different signatures.

```cpp
int add(int, int);
float add(float, float);
```

#### Dynamic Polymorphism

* **In run time**, you can call dynamically allocated functions that are assigned to certain addresses during run time.

---

## OOP Principles

### Modularity

* Allows you to **debug** and facilitates **maintainance**.

### Abstraction

* The principle of the black box; where you just concerned with **inputs** and **outputs** of the module.

---

## Constructor

### Implicit Default Constructor

* The **compiler** generates a default constrctor implicitly to initialise the **attributes** with zeros (compiler dependent).

```cpp
class DIO
{
    struct register DIO;
    int x;                  // stored in .bss
    int y;                  // stored in .bss

    Dio  set_pin_dir();     // stored in .text
    ...
}

DIO avr;                    // create object
```

### Explicit Default Constructor

* The **programmer** creates a constructor to initialize attributes with specific values.

```cpp
class DIO
{
    DIO()
    {
        x = 3;
        x = 4;
    }
};
```

### Parametarised Constructor

* The **programmer** creates a constructor

```cpp
struct DIO * register;

DIO(struct DIO * reg)
{
    register = reg;
}
```

### Default Values

Default Values are set even if you put all constructors.

```cpp
class DIO
{
    // default values
    int x = 4;
    int y = 5;

    DIO(int var1, int var2)
    {
        x = var1;
        y = var2
    } 

    DIO()
    {
        x = 3;
        y = 4;
    }

    Dio  set_pin_dir();     // stored in .text
    ...
};

DIO avr;
```


### Notes

* **Note:** The compiler will **NOT** create a default constructor if you create a parametarised constructor and not a default constructor. (It will lead to a compilation error if you craeted an object of this class)

* **Note:** You **can** access the class function using a pointer refers to its location in memory.

* **Note:** When you craete multiple instances from the same class, every **function** will be **stored just once in memory** but they will ofcourse have different attributes.

---

## Destructor

You use it to:

1. Prevent Memory leaks
2. Close files
3. Close connections

* If you initialise dynamically allocated memeory inside the class when the **object goes out of scope**.

```cpp
lass DIO
{
    // default values
    int x = 4;
    int y = 5;
    int * z = (int*)malloc(1 * 4); 

    DIO(int var1, int var2)
    {
        x = var1;
        y = var2
    } 

    DIO()
    {
        x = 3;
        y = 4;
    }

    Dio  set_pin_dir();     // stored in .text

    ~DIO()
    {
        free z;             // deallocte
    }
}

int main()
{
    DIO avr;               // allocates memory
    return 0;
}
```

* The **delete** keyword automoatically calls the class destructor.

```cpp
delete avr;         // DIO destructor is called
```

## Member Initialisation in Class

* The compiler creates an assemply to automatically initialise these attributes.

1. It allows initialising const variables.
2. Avoids ambiguous initialization.

```cpp
class Dio
{
    const int x;
    int y;

    // 1. It allows initialising const variables:

    /*
    // Normal Initialisation
    Dio()
    {
        x = 3;  // Error: can't initialise const vars. 
        y = 2;
    }
    */

    // Member Initialisation
    Dio() : x(3), y(0)  // x is initialised by the compiler using assemply automatically
    {

    }

    // -------------------------------------

    // 2. Avoids ambiguous initialization

    /*
    // Normal Initialisation
    Dio(int x, int y)
    {
        x = x;  // Error: which x is the member var and which is the arg 
        y = y;
    }
    */

    Dio(intx, int y) : x(x), y(y)
    {

    }

}
```

* **Note:** The first defined variable is initialised first in the members initialisation. You can check that:

```cpp
class Dio 
{
    int x;      // defined first
    int y;
    Dio(int x, int y) : x(cout << x), y(cout << y) {}
}
``` 

### Delegate Constructor

* Calling constructor from a constructor.

```cpp
class Dio 
{
    intx, y;

    Dio() : x(0), y(0) {}

    // Delegate Constructor
    Dio(int x, int y) : Dio() {}
}
```

* It may leed to **infinite loop** if not used properly.

```cpp
class Dio 
{
    int x, y;

    // Explicit Default Constructor
    Dio() : Dio(3, 5) {}

    // Delegate Constructor
    Dio(int x, int y) : Dio() {}
}
```

* The **correct** way to use it:

```cpp
class Dio 
{
    int x, y;

    // Explicit Default Constructor
    Dio() : Dio(3, 5) {}

    // Delegate Constructor
    Dio(int x, int y) : x(x), y(y) {}
}
```

---

## Copy Constructor

The Copy constructor performs **shollow copy** where it copies attributes from the source object to the target object.

* The compiler can generate a copy constructor implicitly if not existed.

* It may lead to **dangling pointers** if you use dynamically allocated memory:
  * As the two objects will have pointers point to the sme memory.
  * So, when one of them goes out of scopt, the destructor deallocates the memory, hence the other object's pointer will be dangling.

* So, you need to allocate new memory for the new pointer when copying:

```cpp
class Dio 
{
    int x, y;
    int * ptr;

    // Default Constructor
    Dio() 
    {
        ptr = (int*)malloc(1*4);
    }

    // Copy Constructor
    Dio(const Dio &copy_object) : Dio()
    {
        // using 'const' prevent changing original object
        x = copy_object.x;
        y = copy_object.y;
        *ptr = *copy_object.ptr;
    }
}

Dio avr32;              // calls default constructor

Dio avr16 = avr32;      // class copy constructor

Dio avr16(avr32);       // calls copy constructor
```

* **Note:** Default and Copy constructors are called **Special Member Functions**.

---

## Static Variables in Class

Static Variables are special class member attribute **shared across all objects**, so they are all see the same value.

* They are stored in **.data** section in memory.

* Static Variables will be allocated memory before any object is created. So, you can read them even if no objects are created.

* Initialising the class static var inside the class means you need every object to have a copy of it with this value and that contradicts that is one shared memory between all objects.
* **Normal and Special Member functions** (default and copy constructors) can access static variables.

* **Static Member Functions** reside in `.data` section in memory. Which means they can access **class static variables** and **any data in the `.data`** section. **But**, They can't access class member variables and functions as they reside in `.stack` section in memory.

```cpp
class Dio
{
    static int mystatic;    // you can't initialize here

    void increment()        // member function can access static vars 
    {
        mystatic++;
    }

    static memberFunction()
    {
        // Can access static variables
        mystatic = 0;
        // And any data in .data secton in memory
        // But, can't access class member variables and member functions as they reside .stack memory.
    }
}

Dio::mystatic = 2;            // Initialisation for static variables outside the class

int main()
{
    int x = Dio::getStatic();

    return 0;
}
```

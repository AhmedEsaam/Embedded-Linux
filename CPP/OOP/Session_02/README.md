# OOP - Session 02

## Temporary Object

```cpp
class Example
{};

func(Example());    // A temporary object is passed
```

* `RVO` **Return Value Optimization**: is compiler optimization technique used in C++ to eliminate unnecessary copying of objects returned from functions.

```cpp
MyObject createObject() {
    MyObject obj;

    return obj;  // a temporary object is traditionally created here which is copied from obj
}
```

* **RVO** concept means that the compiler will directly use the created object without copying it for the return statement.

```cpp
func1(int x);

func2(int& x);

func3(const int& x);

int main(void)
{
    func1(5);       // Ok
    func2(5);       // Not Ok, func2() expects an l-value but an r-value is passed
    func3(5);       // Ok, func3() accepts l-values and r-values

    return 0;
}
```

---

## Friend Class

```cpp
class Example 
{
    private:
    int x;

    friend class MyClass;

    friend void function(Example e);
};

void function(Example e)      // function() is friend to the Example class, so, it can access its private members
{
    std::cout << e.x << std::endl;
}

class MyClass
{
private:
    Example obj;                // MyClass has access to obj private members

public:
    int getX()
    {
        return obj.x;
    }
};
```

---

## Member Initialization

* When using `{}` on initializing an object, The **member initialization periority** goes as follows:

    1. initializer list.
    2. parametarized constructor.
    3. substitute normally same as structure.

```cpp
class A
{
    int x, y;
};

class B
{
    int x, y;

    B(int x, int y) : x(x), y(y) {};
};

class C
{
    int x, y;
    
    C(int x, int y) : x(x), y(y) {};

    C(const std::initializer_list& arr)
    {

    }
};



int main(void)
{
    A a{1, 3};      // Ok

    A a(1, 3);      // Not Ok. No constructor

    B b{1, 3};      // calls the parametarized constructor

    C c(3, 7);      // calls parametarized constructor with int x , int y

    C c{3, 7};      // calls parametarized constructor with initializer list

    return 0;
}
```

---

## `delete` and `const`

* You can use `delete` to eliminate any type of constructor.

```cpp
class Example
{
 private:
    int x;

    mutable int y;

 public:
    Example() = delete;     // The default constructor is prohibited to be called explicitly or implicitly
    int showValue() const   // 'const' cannot edit any member attributes
    {
        std::cout << x;
        x++;                // Error
        y++;                // Ok, y is mutable
    }
};

int main(void)
{
    Example obj;            // Error, no default constructor

    return 0;
}
```

---

## Inheritance

### 1. Single Inheritance

A class inherits one single class.

```cpp
class A
{

};

class B : public A
{

};
```

### 2. Hierarchical Inheritance

One class is a base to more than one derived class.

```cpp
class RCC
{
protected:
    int x, y;
};

class GPIO : public RCC     // code of RCC is stored only once, while RCC data members are created for every new object.
{
    int x;

    int getRCC_x()
    {
        return RCC::x;
    }
};

class UART : public RCC
{
    int y;

    int getRCC_x()
    {
        return RCC::y;
    }
}
```

### 3. Multiple Inheritance

A derived class inherits more than one base class.

```cpp
class Base1
{};

class Base2
{};

class Derived : public Base1, public Base2  // constructor of Base1 is called before constructor of Base2
{};
```

### 4. Multi-level Inheritance

A class is base to another class which in turn is a base to another third class and so on.

```cpp
class Base1
{};

class Derived1, public Base1
{};

class Derived : public Base2
{};
```

### 5. Hybrid Inheritance

Diamond shape inheritance. **NOT RECOMMENDED**

It is a compination between **Hierarchical Inheritance** and **Multiple Inheritance**.

```cpp
class Base
{};

class Derived1 : public Base
{};

class Derived2 : public Base
{};

class child : public Derived1, public Derived2
{};
```

---

## Common and Unique

Always think of what is a **common** and what is a **unique** between entities.

You can put common properties in a **Base** class, and unique properties in **Derived** classes.

### **Inheritance:** `is a` relationship

```cpp
class DIO
{
    setOinValue();
    getPinValue();
};

class ARM_DIO : public DIO
{
};
```

* **ARM_DIO** `is a` **DIO**.

### **Composition:** `has a` relationship

```cpp
class RCC
{

};

class GPIO
{
    RCC obj;
};
```

* **GPIO** `has an` **RCC** object.

### **Aggregaion**

```cpp
class Employee
{

};

class Company
{
    Employee* emp;

public:
    Company(Employee* e)
    {
        emp->x = e->x;
    }
};
```

### **Association**

```cpp

```

---

## Types of Inheritance

* The Derived class can only restrict accessibility for itself for the Base class members.

| public | protected | private |
| :----- | :----- | :----- |
| Every access specifier in the **Perent** class retains its accessibility in the **Derived** class | `protected` and `public` members in **Base** are `protected` in the **Derived** class | All **Base** class members are `private` for the **Derived** class |

---

## Base Constructors

```cpp
class Example
{
private:
    int x;

public:
    Example(int var)
    {
        x = var
    }

    // Example() = {}           // x = garbage value
    
    Example() = default;        // 'default' signals the compiler to create a default constructor and puts x = 0
};

class Derived : private Example
{
  int z;

public:
    // Derived(int x) : Example(x) 
    // {}

    using Example::Example; // Used to copy the constructors from Base class to the Derived class
    // This is another way of the above constructor 
    // (if passed an int --> it calls the Example(int) constructor)
    // But it has low priority if you implemented the Derived constructor
};

int main(void)
{
    Derived(5);

    return 0;
}
```

---

## Function Overriding

```cpp
class Base
{
public:
    void display();
};

class Derived : public Base
{
    void display();         // overrides the Base::display()
};

int main(void)
{
    Derived obj;

    obj.display();          // Derived::display() is called

    obj.Base::display();    // To call the Base::display()

    return 0;
}
```

## Dynamic Polymorphism

```cpp
class Base
{
    int x, y;
public:
    void display();

    virtual void func() const;
    // the compiler implicitly creates a pointer vfptr* that holds the addresses of the overrided functions of this virtual function in the virtual table of this class.
};

class Derived : public Base
{
    int z;
public:
    void display();

    void func() const override;   // overrided virtual function
    // use 'override' to indicate that this function is overrided (which leads to checking the function signature if it matches one of the parent class functions in compile-time.)

    // And it makes the code more self-documented.

};

int main(void)
{
    Derived obj;

    Base* pBObj = &obj;     // the Base object pointer only points to Base members in the Derived class object

    pBObj->display();       // calls the Base::display()

    // If we want to call the override func() in the Derived class:

    pBObj->func();      // calls Derived::func() which is an overrided virtual function 
                        // The pointer calls the function which address is in the virtual table of the Base class

    return 0;
}
```

### Base Class Virtual Table

* The base class which contains a virtual function contains a `vfptr*` pointer which points to the **Virtual Function Table** which in turn holds pointers to the addresses of the overrided functions of the Base class virtual function.

* When the virtual function is called through a Base pointer or refernce, the `vfptr*` determines which **table** to use (here, the Base class virtual table), and then which function to call from that **table**.
* 
| | Pointers' Values : Addresses of the Overrided Virtual Functions in the Derived Classes |
| :---: | :---: |
| Derived1::func | 0x545465 |
| Derived2::func | 0x276334 |
| Derived3::func | 0x879466 |
| ... | ... |

```cpp
pBObj->func();  // The pBobj `vfptr*` --> points to the base class virtual table --> gets the desired function implementation address.
```

---

## Abstract Class

Is a class which has atleast one pure virtual function.

You Cannot create an object of the abstract class.

```cpp
class A
{
    virtual void display() = 0;
};

class B : public A
{
    void display();
};

int main(void)
{
    A a;            // Error: you can't create an object of an abstract class.

    B b;

    A* p = &b;      // Ok

    return 0;
}
```
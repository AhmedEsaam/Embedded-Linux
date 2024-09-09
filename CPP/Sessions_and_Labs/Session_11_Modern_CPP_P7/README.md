# C++ - Session 11 Notes - Modern C++ - P7

* Raw Pointers Disadvantages:
    1. Dangling Pointers
    2. Un-Authorized Access
    3. Memory Leakage
    4. Double Deletion

## Smart Pointers

* Are objects that store memory location (like raw pointers) with **Automatic Memory Management**
* It applies **RAI** (Resource Aquisition Initialization).

* Smart Pointers Types:
    1. `unique_ptr<>` : **The object has one pointer**.
    1. `shared_ptr<>` : **The object has more than one pointer (with their count stored)**.
    1. `weak_ptr<>` : **The object has more than one pointer (with weak pointer not counted)**.

### 1. Unique Pointer

* Has unique ownership : no other pointer shares rthe same location.
  * But we can transfer the control over the refered object to anotherr pointer using **move semantics**.

```cpp
#include <memory>

std::unique_ptr<int> uPtr(new int(100));    // in-place initializing the unique pointer 
// ptr = uPtr;     // Not allowed

// Recommended - more effiecient
std::unique_ptr<MyClass> uPtr2 = std::make_unique<MyClass>(100);


// The unique pointer must not share the address with other pointer (it must move the ownership)
// std::unique_ptr<int> uPtr = new int(100);

// to move ownership
std::unique_ptr<C> ptr1 = std::move(ptr2);

// to dereference
MyClass obj = *ptr;

// to get address
ptr.get();

// to release ownership
MyClass *p = ptr.release();
```

### 2. Shared Pointer

* There are more than one pointer refer to the same object.
  * Keep reference count.
    * Once that count equals zero --> delete the allocated object.

```cpp
#include <memory>

std::shared_ptr<int> sPtr(new int(100));

// Recommended - more effiecient
std::shared_ptr<MyClass> uPtr2 = std::make_shared<MyClass>(100);

sPtr.use_count();
```

### 3. Shared Pointer

* There are more than one pointer refer to the same object.
  * don't get counted in the reference count.
    * So, it will not delete the refered object.

* Advantage:
  * Used to break **Circular Reference Problem**.

```cpp
#include <memory>

std::shared_ptr<int> sPtr(new int(100));
std::weak_ptr<int> wPtr = sPtr;     // Note: cannot = a unique pointer
```

---

## Rules in C++

* Are **Guidelines** to:
  * Manage resources (specially if you use dynamically allocated memory [raw pointers])
    * To solve the problem of shallow copy.
  * And object lifecycles

* if you define/delete one method -->
  * You must delete all the remaining.

* Rule Types
  1. **Rule of Zero** : (Do not define anyhting)
  2. **Rule of Three** : Define all or nothing of:
     1. `Destructor`
     2. `Copy Constructor` or `Assignment operator overloading`
  3. **Rule of Five** : Define all or nothing of:
     1. `Destructor`
     2. `Copy Constructor` or `Assignment operator overloading`
     3. `Move Constructor` or `Move with assignment operator`

---

## Move Constructor

* Moves the ownership of the object

```cpp
// Move constructor
A& Operator= (const A&&);
```

---

## Generated Functions

* The compiler generates some funtions by default for every class (it differs from one standard to another)
  1. **Default constructor** (if you have not provided any constructor of any type)
  2. **Default Destructor**
  3. **Copy constructor**

---

* Read about the **Boast Framework**.
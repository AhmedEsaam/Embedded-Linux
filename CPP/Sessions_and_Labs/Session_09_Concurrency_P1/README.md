# Session 09 - Concurrency P1

## Multi-Threading

1. **Sequential Execution**

2. **Parallelism**
   * Multi-core and multi-processor
   * Depends on **Parallel Distribution**

3. **Concurrency** - Seemingly parallel (limited hardware : assume 1 core or Number of **tasks** > number of **cores**)
   * Priority based
   * Round Robin
   * FCFS
   * EDF

---

### Process and Thread

#### Process

* An executable file is called a **passive entity**.
* As soon as it runs, it is called an **active entity**.
* Every process has a Process Control Block **(PCB)**, which holds the process task, PID, and other information.

#### Thread

| H/W Thread | S/W Thread |
|:--|:--|
|**SMT** (Simultaneous Multithreading) or Hyper Threading: every core runs two threads | Instructions to be executed (functions) |
| **Limited**: You can check if your machine supports hyper threading using the command `lscpu` which will show the number of cores and the number of threads per core. | **Also limited**: as it is limited by memory. |

#### Process and Thread Comparison

| Process | Thread |
| :-- | :-- |
| - Hard to create & manage | - Easier to manage |
| - Process don't share same address | - Threads share the same address space **(subset of process)** |
| - hard to share data | - Easier to share data |
| - More context switching time | - Less context switching time |

---

### Syntax

```cpp
std::thread obj(func, arg ...);

// you cannot pass an argument by reference directly (as every thread has its own address space)
// You must do
std::thread obj(func, std::ref(arg) ...);
```

---

### Example

```cpp
#include <iostream>
#include <thread>

void myFunction(int id)
{
    for (int i = 0; i < 20; i++)
    {
        std::cout << "Hello from my function(id=" << id << ")" << std::endl;
    }
}

int main() // Main Thread
{
    // std::thread --> class
    std::thread obj{myFunction, 1};
    std::thread obj2{myFunction, 2};
    // Created SW Tgread --> An, d it started running

    obj.join(); // Block the current thread until the specified thread finishes.
    // If main() finishes ... wait for this thread to finish (you can instead put a while(1))
    // main() CANNOT terminate before this thread.

    obj2.detach(); // running in the background even after the main() terminates

    std::this_thread::sleep_for(std::chrono::seconds(1)); // sleep for 1 seconds

    // A thread that call join() in its destructor
    std::jthread obj3{myFunction, 3};

    std::cout << std::thread::hardware_concurrency() << std::endl;

    return 0;
}

/*
    * In Sequential Execution --> Main Thread

    * Multi-Threaded --> Main Thread + Threads

*/
```

* To make a daemon thread (running in the background)

```cpp
thread_obj.detach();
```

---

### Jthread

Is a thread that call join() in it's destructor, so it spares the main from joining all threads to wait until they all finish.

---

### Thread Safe

* A thread safe function is a function that vcan be called by multiple thrteads without any problems.

* if it is used by one thread and another thread used it, it stops its execution, performs the new thread call and return back which wll cause a **data race**.

* `std::cout <<` is not thread safe.

---

### How to make a function safe on a shared resource

To guarantee using multiple threads on the same resource does not cause problems:

* We can use the **Mutex** class
* Or, use atomic operations. (In the next session)

---

### Dead lock

* Deadlock happens when two threads waits for the release of the resource owned by the other which leads to a **circular wait**. to solve it:
  1. Aquire at the same time.
  2. Release in the reverse order of aquiring if not all needed resources are available.

* Or, when one thread is holding a resource infinitly while another thread is waiting for its release. To solve it:
  1. Use a timeout on the resource.
  2. Preempt task.

#### Deadlock Conditions

* Using **Mutex** to hold resoutces.
* Hold and wait.
* No Preemption. (No high-priority task can interrupt a running lower-priority task).
* Circular wait.

#### How to avoid the deadlock

1. Using the **RAII** function (locking).
2. Avoid **hold and wait**.
3. Using **Preemption**.
4. Use the Resource Allocation Graph **(RAG)** to design the system avoiding deadlocks.

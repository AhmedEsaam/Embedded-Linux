# Session 10 - Concurrency P2

## Atomic operation

* A way to achieve a thread safe functions (or a reentrant function).
* It's a **Synchronization Mechanism** to prevent data race.
* Use it with **Primitive Data Types**.
* With Non-Primitive Data Types, use Mutex.

### Synyax

```cpp
// atomic is a template class
std::atomic<T> obj;
```

---

## Mutex (Mutual Exclusion)

* Is a synchronized mechanism --> that provide unique lock for a resource.

### Syntax

```cpp
std::mutex muMutex;
```

* The mutex uses these functions

  * `lock()` : if locked ... continue execution, if not ... goes to blocked state
  * `unlock()` : release mutex
  * `try_lock()` : tries to lock the mutex (used with timed-mutex)

* But you must make sure you unlock the mutex.

## RAII Functions/Classes - Resource Aquisition Initialization

* They handle **releasing resources automatically** when destructing (ex. dynamically allocated memory that is being freed automatically by **Smart Pointers**)
* When releasing resources, it releases with the reverse order it has aquired with.

* Functions
  * `std::lock_guard l(mtx)` : lock the mutex and automatically handles unlocking the mutex.
  * `std::unique_lock l(mtx, std::defer_lock)` : just like lock guard, but the mutex is not locked yet, but as soon as it locked, it will be guarded. (it often used with condition variables)
  * `std::scoped_lock l(mtxR1, mtxR2, mtxR3, mtxR4)` : lock and guard multiple resources at the same time.

## Mutex Types

* `std::mutex` : regular mutex
* `std::timed_mutex` : mutex is released after a time period.
* `std::recursive_mutex` : the mutex can be locked multiple times by the same thread.
* `std::shared_mutex` : multiple threads can read the resource, but onlu one thread can write.

## Condition Variable

* Used with mutex.
* It checks if the mutex is unlocked **and** the condition is met.
* **Ex.:** A thread locks the mutex and adds to a queue. Another thread waits for ...
  * (the mutex to be released)
  * **And** (the queue is updated with the new value) to print or use the queue data

* The first thread sends a `notify_all` signal to all other threads that waits for this condition to make their check. And that is passed by a `condition_variable`.
* Normally those other threads often do the their check regardless, but this notification forces them to do their checks.

---

* Read about Future & Promise.

---

## Semaphores

* 

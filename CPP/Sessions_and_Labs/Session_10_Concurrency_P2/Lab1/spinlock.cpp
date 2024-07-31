#include <iostream>
#include <atomic>
#include <thread>

class Spinlock
{
private:
    std::atomic_flag flag;

public:
    // Constructor initiate the atmic flag with initial value
    Spinlock() : flag(ATOMIC_FLAG_INIT) {}

    // Lock the spinlock
    void lock()
    {
        while (flag.test_and_set(std::memory_order_acquire))
        {
            // Spin until the lock is acquired
        }
    }

    void unlock()
    {
        // Release the lock
        flag.clear(std::memory_order_release);
    }
};

void multiply(int &num, Spinlock &spLock)
{
    // spin till aquiring the lock
    spLock.lock();

    // multiply till num = 20
    while (num < 20)
    {
        num *= 2;
    }

    // release the lock
    spLock.unlock();
}

void divide(int &num, Spinlock &spLock)
{
    // spin till aquiring the lock
    spLock.lock();

    // divide till num = 1
    while (num > 1)
    {
        num /= 2;
    }

    // release the lock
    spLock.unlock();
}

int main()
{
    Spinlock spLock;

    int x = 1;

    multiply(x, spLock);

    {
        std::jthread mul_Th{multiply, std::ref(x), std::ref(spLock)};
        std::jthread div_Th{divide, std::ref(x), std::ref(spLock)};
    }

    std::cout << "x = " << x << std::endl;

    return 0;
}
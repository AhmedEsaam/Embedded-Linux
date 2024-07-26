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
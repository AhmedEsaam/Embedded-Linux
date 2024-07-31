#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::recursive_mutex result_mutex;
std::mutex fib_mutex;
std::mutex print_mutex;

std::condition_variable results_ready;

void fibonacci_recursive(int count, int &result, int current = 1, int prev = 0)
{
    if (count <= 1)
    {
        return;
    }
    std::unique_lock<std::recursive_mutex> lock(result_mutex);
    result = current + prev;
    prev = current;
    current = result;

    // std::this_thread::sleep_for(std::chrono::milliseconds(10));
    fibonacci_recursive(count - 1, result, current, prev);
}

void print_fibonacci(int count, int &result)
{
    // lock the mutex for fibonacci waiting the result
    std::unique_lock<std::mutex> fib_lock(fib_mutex);
    results_ready.wait(fib_lock, [result]
                       { return result != 0; });

    // Lock the mutex for printing
    std::lock_guard<std::mutex> print_lock(print_mutex);
    std::cout << "Fibonacci(" << count << ") = " << result << std::endl;
}

int main()
{
    int result = 0, count;

    std::cout << "Please enter number: ";
    std::cin >> count;

    std::jthread fib_thread([&result, count]()
                            {
                            std::lock_guard<std::mutex> lock(fib_mutex);
                            fibonacci_recursive(count, std::ref(result));
                            results_ready.notify_all(); });

    std::jthread thread_print(print_fibonacci, count, std::ref(result));

    return 0;
}
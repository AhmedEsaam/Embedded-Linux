#include <iostream>
#include <thread>

void beep(std::chrono::seconds delay)
{
    while (1)
    {
        std::cout << "\a";
        std::cout.flush();
        std::this_thread::sleep_for(delay);
    }
}

void beepStop()
{
    std::cout << "(Press 'Enter' to stop)" << std::endl;

    std::cin.get();

    exit(0);
}

int main()
{
    std::jthread beepTh{beep, std::chrono::seconds(3)};
    std::jthread beepStopTh(beepStop);

    return 0;
}

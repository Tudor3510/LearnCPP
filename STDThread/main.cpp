#include <iostream>
#include <vector>
#include <thread>
#include <Windows.h>

class PauseScheduler
{
private:
    static std::vector <std::thread*> scheduler;


public:
    void operator()(int id) {
        std::cout << "Thread " << id << " is running." << std::endl;
    }

    static void SchedulePause()
    {
        PauseScheduler* pauseScheduler = new PauseScheduler();

        for (int i=0; i <= 50; i++)
        {
            std::thread *threadPtr = new std::thread(*pauseScheduler, i);
            delete threadPtr;
        }
    }

};

std::vector<std::thread*> PauseScheduler::scheduler;

int main()
{
    std::cout << "Hello World" << '\n';

    PauseScheduler::SchedulePause();

    Sleep(1000);8

    return 0;
}
#include <iostream>
#include <unistd.h>
#include "tsq.hpp"

class testobj
{
public:
    std::string name;
    unsigned size;
};

void processQueue(threadSafeQueue<testobj> &tsq)
{
    testobj t;
    while (true)
    {
        tsq.wait_available();
        while (tsq.try_pop(t))
        {
            std::cout << t.name << std::endl;
            std::cout << t.size << std::endl;
        }
    }
}

int main(int argc, char *argv[])
{
    testobj t;
    threadSafeQueue<testobj> tsq;

    t.name = "test";
    t.size = 1234567;
    std::thread t1(processQueue, std::ref(tsq));
    sleep(1);
    tsq.push(t);
    while (1)
    {
        tsq.push(t);
        usleep(30);
    }
    sleep(2);
    exit(0);
}
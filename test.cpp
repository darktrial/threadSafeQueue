#include <iostream>
#include <unistd.h>
#include "tsq.hpp"

class testobj
{
public:
    std::string name;
};

void processQueue(threadSafeQueue<testobj> &tsq)
{
    testobj t;
    while (true)
    {
        std::cout<<"wait and pop"<<std::endl;
        tsq.wait_and_pop(t);
        std::cout << t.name << std::endl;
        while (tsq.try_pop(t))
        {
            std::cout<<"has data"<<std::endl;
            std::cout << t.name << std::endl;
        }
    }
}

int main(int argc, char *argv[])
{
    testobj t;
    threadSafeQueue<testobj> tsq;

    t.name = "test";
    std::thread t1(processQueue, std::ref(tsq));
    sleep(1);
    tsq.push(t);
    sleep(3);
}
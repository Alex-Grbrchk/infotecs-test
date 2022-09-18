#include <thread>
#include "ThreadOne.h"
#include "ThreadTwo.h"



int main(){
    Buffer buffer;

    ThreadOne threadOne(buffer);
    ThreadTwo threadTwo(buffer);

    std::thread thread1(threadOne);
    std::thread thread2(threadTwo);

    thread1.join();
    thread2.join();

    return 0;
}
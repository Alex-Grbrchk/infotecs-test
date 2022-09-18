

#ifndef UNTITLED2_THREADTWO_H
#define UNTITLED2_THREADTWO_H
#include <iostream>
#include <thread>
#include "Buffer.h"
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 8080

class ThreadTwo {
private:
    Buffer& buffer;
public:
    ThreadTwo(Buffer& buffer);

    [[noreturn]] void operator()();
};


#endif //UNTITLED2_THREADTWO_H

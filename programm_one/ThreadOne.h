#ifndef UNTITLED2_THREADONE_H
#define UNTITLED2_THREADONE_H
#include <iostream>
#include <algorithm> 
#include "Buffer.h"

class ThreadOne {
private:

    Buffer& buffer;

    bool check_buffer();
    std::string sort_buffer();
    std::string replace_chars_in_buffer();
public:
    ThreadOne(Buffer &buffer);

    [[noreturn]] void operator()();
};


#endif //UNTITLED2_THREADONE_H

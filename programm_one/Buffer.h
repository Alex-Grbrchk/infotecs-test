#ifndef UNTITLED2_BUFFER_H
#define UNTITLED2_BUFFER_H
#include <mutex>
#include <condition_variable>
#include <iostream>

class Buffer {
private:
    std::string buffer;
    bool _is_filled;
public:
    Buffer();
    std::condition_variable cv;
    std::mutex m;

    void input_buffer();
    bool is_filled() const;
    void to_empty();
    void fill_buffer();

    Buffer& operator= (std::string value);
    std::string get_buffer();
};


#endif //UNTITLED2_BUFFER_H

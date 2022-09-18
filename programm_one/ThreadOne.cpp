#include <thread>
#include "ThreadOne.h"

bool ThreadOne::check_buffer(){
    if(buffer.get_buffer().length() > 64) return false;
    std::string buffer_ = buffer.get_buffer();
    return std::all_of(buffer_.begin(), buffer_.end(), [](char i){return i >= '0' && i <= '9';});
}

std::string ThreadOne::sort_buffer(){
    std::string buffer_sort = buffer.get_buffer();
    /*bool comp(char l, char r){
    	return l>r;
    }	*/
    sort(buffer_sort.begin(), buffer_sort.end(), std::greater<>()/*[](char l, char r){return l < r;}*/);

    return buffer_sort;
}

// ???
std::string ThreadOne::replace_chars_in_buffer(){
    std::string buffer_replace;
    for(char i : buffer.get_buffer()){
        if(i % 2 == 0) buffer_replace += "KB";
        else buffer_replace += i;
    }

    return buffer_replace;

}

ThreadOne::ThreadOne(Buffer& buffer): buffer(buffer) {
}

[[noreturn]] void ThreadOne::operator()() {
    while (true) {
        buffer.input_buffer();

        std::cout << "Checking buffer\n";
        if (check_buffer()) {
            std::cout << "Sorting buffer\n";
            buffer = sort_buffer();
            std::cout << "Replacing chars\n";
            buffer = replace_chars_in_buffer();
            std::cout << "Fill buffer\n";
            buffer.fill_buffer();
        } else {
            std::cout << "Buffer is invalid. Buffer: " << buffer.get_buffer() << std::endl;
            buffer.to_empty();
        }
    }
}



#include "Buffer.h"

void Buffer::input_buffer() {
    std::cin >> buffer;
}

bool Buffer::is_filled() const {
    return _is_filled;
}

void Buffer::to_empty() {
    buffer = "";
    _is_filled = false;
}

void Buffer::fill_buffer(){
    std::unique_lock<std::mutex> lk(m);
    _is_filled = true;

    cv.notify_all();
}

Buffer& Buffer::operator=(std::string value) {
    this->buffer = value;
    return *this;
}

std::string Buffer::get_buffer() {
    return buffer;
}

Buffer::Buffer() {
    _is_filled = false;
}





#include "ThreadTwo.h"

ThreadTwo::ThreadTwo(Buffer &buffer): buffer(buffer) {

}

void send_sum(int sum){
    int sock = 0, client_fd;
    sockaddr_in serv_addr{};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std::cout << "Socket creation error \n";
    }
    else  std::cout << "Socket created\n";

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if ((client_fd
                 = connect(sock, (struct sockaddr*)&serv_addr,
                           sizeof(serv_addr)))
        < 0) {
        std::cout << "Connection Faile \n";
    }
    else  std::cout << "Connected\n";

    char data[124];
    strcpy(data, std::to_string(sum).c_str());
    send(sock, data, strlen(data), 0);
}

[[noreturn]] void ThreadTwo::operator()() {
    while(true) {
        std::unique_lock<std::mutex> lk(buffer.m);

        buffer.cv.wait(lk, [=](){return buffer.is_filled();});

        std::cout << "Start thread 2\n";
        int sum = 0;
        for (char i: buffer.get_buffer()) {
            if (i >= '0' && i <= '9') {
                sum += i - '0';
            }
        }

        std::cout << buffer.get_buffer() << ": " << sum << std::endl;
        send_sum(sum);
        buffer.to_empty();
    }
}

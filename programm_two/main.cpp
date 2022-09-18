#include <iostream>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 8080


int main() {
    int server_fd, new_socket;
    sockaddr_in address{};
    int addr_len = sizeof(address);
    char buffer[1024] = { 0 };

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0))
        == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr*)&address,
             sizeof(address))
        < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while(true) {
        if ((new_socket
                     = accept(server_fd, (struct sockaddr *) &address,
                              (socklen_t *) &addr_len)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        size_t val_read = read(new_socket, buffer, 1024);
        int sum = std::stoi(buffer);
        if (strlen(buffer)>2 && sum%32 == 0){
        	std::cout<<"\nData have been recieved"<<std::endl;
        }
        else
        	std::cout<<"Error!"<<std::endl;
        	
      	printf("%s\n", buffer);
	

        // closing the connected socket
        close(new_socket);
        // closing the listening socket
       // shutdown(server_fd, SHUT_RDWR);
    }
    return 0;
}

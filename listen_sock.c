#include "common.h"

int main(int argc, char *argv[]) {

    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUF_SIZE] = {0};

    EXIT_IF_NOT_EQ(argc, 2);
    EXIT_IF_ERROR(server_fd = socket(AF_INET, SOCK_STREAM, 0));

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(atoi(argv[1]));

    EXIT_IF_ERROR(bind(server_fd, (struct sockaddr *)&address, sizeof(address)));
    EXIT_IF_ERROR(listen(server_fd, 3));
    EXIT_IF_ERROR(new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen));

    printf("Client connected!\n");

    while ((valread = read(new_socket, buffer, BUF_SIZE)) > 0) {
        printf("%s", buffer);
        memset(buffer, 0, sizeof(buffer));
    }

    return 0;
}

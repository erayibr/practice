#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>

#define BUF_SIZE 1024

#define EXIT_IF_NOT_EQ(arg,x) do { \
    if ((arg) != x) { \
        fprintf(stderr, "%s:%d:%s\n", __FILE__, __LINE__, #arg); \
        exit(EXIT_FAILURE); \
    } \
} while (0)

#define EXIT_IF_ERROR(call) do { \
    if ((call) < 0) { \
        fprintf(stderr, "%s:%d:%s\n", __FILE__, __LINE__, #call); \
        perror("Error"); \
        exit(EXIT_FAILURE); \
    } \
} while (0)

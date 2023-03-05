#include "common.h"

int main(int argc, char *argv[]) {

	struct addrinfo hints, *result, *tmp;
	char ip_address[INET6_ADDRSTRLEN];
	
    EXIT_IF_NOT_EQ(argc, 2);

    memset(&hints, 0, sizeof hints);
 
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    EXIT_IF_ERROR(getaddrinfo(argv[1], NULL, &hints, &result));

    tmp = result;

    while (tmp != NULL) {
        
        if (tmp->ai_family == AF_INET) { // IPv4
            struct sockaddr_in * v = (struct sockaddr_in *) tmp->ai_addr;
            inet_ntop(tmp->ai_family, &v->sin_addr, ip_address, sizeof ip_address);
            printf("IPV4 address: %s\n", ip_address);
        } else {
            struct sockaddr_in6 * v = (struct sockaddr_in6 *) tmp->ai_addr;
            inet_ntop(tmp->ai_family, &v->sin6_addr, ip_address, sizeof ip_address);
            printf("IPV6 address: %s\n", ip_address);
        }

        tmp = tmp->ai_next;
    }

    freeaddrinfo(result);
	return 0;
}
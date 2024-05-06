#include <stdio.h>

#include "../inc/socket.h"

int main(int argc, char *argv[]) {
    printf("[TEST : PCB_GENERATOR : SOCKET]\n");

    socket_t a, b;

    assign_connections(&a, "ABC");
    assign_connections(&b, "ABC");

    printf(" - [TEST 1] ");

    if (!can_connect_sockets(&a, &b)) {
        printf("PASSED\n");
    } else {
        printf("FAILED\n");
    }

    assign_connections(&b, "CBA");

    printf(" - [TEST 2] ");

    if (can_connect_sockets(&a, &b)) {
        printf("PASSED\n");
    } else {
        printf("FAILED\n");
    }

    return 0;
}


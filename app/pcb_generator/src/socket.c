#include "../inc/socket.h"

int can_connect_sockets(socket_t *socket_a, socket_t *socket_b) {
    int i;

    for (i = 0; i < NUM_CONNS; i++) {
        if (socket_a->conns[i] != socket_b->conns[NUM_CONNS - 1 - i]) {
            return 0;
        }
    }

    return 1;
}


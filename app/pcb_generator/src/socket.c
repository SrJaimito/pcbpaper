#include "../inc/socket.h"

#include <string.h>

void assign_connections(socket_t *socket, const char *connections) {
    strncpy(socket->connections, connections, NUM_CONNECTIONS);
}

int can_connect_sockets(const socket_t *socket_a, const socket_t *socket_b) {
    for (int i = 0; i < NUM_CONNECTIONS; i++) {
        if (socket_a->connections[i] !=
                socket_b->connections[NUM_CONNECTIONS - 1 - i]) {

            return 0;
        }
    }

    return 1;
}

void copy_socket(socket_t *destiny, socket_t *source) {
    memcpy(destiny, source, NUM_CONNECTIONS);
}


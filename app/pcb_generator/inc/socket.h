#ifndef __PCBPAPER_PCBGEN_SOCKET_H__
#define __PCBPAPER_PCBGEN_SOCKET_H__

#define NUM_CONNECTIONS 3

typedef struct {
    char connections[NUM_CONNECTIONS];
} socket_t;

void assign_connections(socket_t *socket, const char *connections);
int can_connect_sockets(const socket_t *, const socket_t *);

void copy_socket(socket_t *destiny, socket_t *source);

#endif


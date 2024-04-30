#ifndef __PCBPAPER_PCBGEN_SOCKET_H__
#define __PCBPAPER_PCBGEN_SOCKET_H__

#define NUM_CONNS 3

typedef char connection_t;

typedef struct {
    connection_t conns[NUM_CONNS];
} socket_t;

int can_connect_sockets(socket_t *, socket_t *);

#endif


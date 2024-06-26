#ifndef __PCBPAPER_PCBGEN_COMPONENT_H__
#define __PCBPAPER_PCBGEN_COMPONENT_H__

#include <stdint.h>

#include "socket.h"

#define NUM_COMPONENT_TYPES 19
#define NUM_ROTATIONS       4
#define NUM_SOCKETS         4

typedef enum {
    ROT_0 = 0,
    ROT_90,
    ROT_180,
    ROT_270
} component_rotation_e;

typedef enum {
    UP = 0,
    RIGHT,
    DOWN,
    LEFT
} socket_position_e;

typedef struct {
    int type;
    component_rotation_e rotation;
    socket_t sockets[NUM_SOCKETS];
} component_t;

void create_component(component_t *component, int type, component_rotation_e rotation);
void copy_component(component_t *destiny, component_t *source);

socket_t *get_socket(component_t *component, socket_position_e position);

int can_connect_components(component_t *comp_a, socket_position_e pos_a,
        component_t *comp_b, socket_position_e pos_b);

#endif


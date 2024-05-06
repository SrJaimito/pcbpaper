#include "../inc/component.h"

void create_component(component_t *component, int type, component_rotation_e rotation) {
    component->type = type;
    component->rotation = rotation;

    switch (type) {
        case 0:
            assign_connections(component->sockets + UP, "AAA");
            assign_connections(component->sockets + RIGHT, "AAA");
            assign_connections(component->sockets + DOWN, "AAA");
            assign_connections(component->sockets + LEFT, "AAA");

            break;

        case 1:
            assign_connections(component->sockets + UP, "AAA");
            assign_connections(component->sockets + RIGHT, "ABB");
            assign_connections(component->sockets + DOWN, "BBB");
            assign_connections(component->sockets + LEFT, "BBA");

            break;

        case 2:
            assign_connections(component->sockets + UP, "AAA");
            assign_connections(component->sockets + RIGHT, "ABB");
            assign_connections(component->sockets + DOWN, "BBB");
            assign_connections(component->sockets + LEFT, "BBA");

            break;

        case 3:
            assign_connections(component->sockets + UP, "AAA");
            assign_connections(component->sockets + RIGHT, "ABB");
            assign_connections(component->sockets + DOWN, "BBB");
            assign_connections(component->sockets + LEFT, "BBA");

            break;

        case 4:
            assign_connections(component->sockets + UP, "ABB");
            assign_connections(component->sockets + RIGHT, "BBB");
            assign_connections(component->sockets + DOWN, "BBB");
            assign_connections(component->sockets + LEFT, "BBA");

            break;

        case 5:
            assign_connections(component->sockets + UP, "ABB");
            assign_connections(component->sockets + RIGHT, "BCB");
            assign_connections(component->sockets + DOWN, "BCB");
            assign_connections(component->sockets + LEFT, "BBA");

            break;

        case 6:
            assign_connections(component->sockets + UP, "BCB");
            assign_connections(component->sockets + RIGHT, "BBB");
            assign_connections(component->sockets + DOWN, "BCB");
            assign_connections(component->sockets + LEFT, "BBB");

            break;

        case 7:
            assign_connections(component->sockets + UP, "BCB");
            assign_connections(component->sockets + RIGHT, "BBB");
            assign_connections(component->sockets + DOWN, "BCB");
            assign_connections(component->sockets + LEFT, "BCB");

            break;

        case 8:
            assign_connections(component->sockets + UP, "BBC");
            assign_connections(component->sockets + RIGHT, "CBB");
            assign_connections(component->sockets + DOWN, "BCB");
            assign_connections(component->sockets + LEFT, "BCB");

            break;

        case 9:
            assign_connections(component->sockets + UP, "BCB");
            assign_connections(component->sockets + RIGHT, "BBC");
            assign_connections(component->sockets + DOWN, "CBC");
            assign_connections(component->sockets + LEFT, "CBB");

            break;

        case 10:
            assign_connections(component->sockets + UP, "BCB");
            assign_connections(component->sockets + RIGHT, "BBB");
            assign_connections(component->sockets + DOWN, "BBB");
            assign_connections(component->sockets + LEFT, "BBB");

            break;

        case 11:
            assign_connections(component->sockets + UP, "BBC");
            assign_connections(component->sockets + RIGHT, "CBB");
            assign_connections(component->sockets + DOWN, "BBB");
            assign_connections(component->sockets + LEFT, "BBB");

            break;

        case 12:
            assign_connections(component->sockets + UP, "BBB");
            assign_connections(component->sockets + RIGHT, "BBB");
            assign_connections(component->sockets + DOWN, "BBB");
            assign_connections(component->sockets + LEFT, "BBB");

            break;

        case 13:
            assign_connections(component->sockets + UP, "BCB");
            assign_connections(component->sockets + RIGHT, "BBB");
            assign_connections(component->sockets + DOWN, "BBB");
            assign_connections(component->sockets + LEFT, "BCB");

            break;

        case 14:
            assign_connections(component->sockets + UP, "BCB");
            assign_connections(component->sockets + RIGHT, "BBB");
            assign_connections(component->sockets + DOWN, "BBC");
            assign_connections(component->sockets + LEFT, "CBB");

            break;

        case 15:
            assign_connections(component->sockets + UP, "BBC");
            assign_connections(component->sockets + RIGHT, "CBB");
            assign_connections(component->sockets + DOWN, "BBC");
            assign_connections(component->sockets + LEFT, "CBB");

            break;

        case 16:
            assign_connections(component->sockets + UP, "AAA");
            assign_connections(component->sockets + RIGHT, "ABB");
            assign_connections(component->sockets + DOWN, "BBC");
            assign_connections(component->sockets + LEFT, "CBA");

            break;

        case 17:
            assign_connections(component->sockets + UP, "AAA");
            assign_connections(component->sockets + RIGHT, "ABC");
            assign_connections(component->sockets + DOWN, "CBB");
            assign_connections(component->sockets + LEFT, "BBA");

            break;

        case 18:
            assign_connections(component->sockets + UP, "BCB");
            assign_connections(component->sockets + RIGHT, "BBC");
            assign_connections(component->sockets + DOWN, "CBB");
            assign_connections(component->sockets + LEFT, "BBB");
    }
}

socket_t *get_socket(component_t *component, socket_position_e position) {
    int socket_index = (component->rotation + position) % NUM_SOCKETS;

    return component->sockets + socket_index;
}

int can_connect_components(component_t *comp_a, socket_position_e pos_a,
        component_t *comp_b, socket_position_e pos_b) {

    socket_t *from_socket = get_socket(comp_a, pos_a);
    socket_t *to_socket = get_socket(comp_b, pos_b);

    return can_connect_sockets(from_socket, to_socket);
}

void copy_component(component_t *destiny, component_t *source) {
    destiny->type = source->type;
    destiny->rotation = source->rotation;

    for (int i = 0; i < NUM_SOCKETS; i++) {
        copy_socket(destiny->sockets + i, source->sockets + i);
    }
}


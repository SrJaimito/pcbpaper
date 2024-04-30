#include "../inc/component.h"

component_t create_component(int type) {
    component_t component;
    component.type = type;
    component.rotation = ROT_0;

    switch (type) {
        case 0:
            component.sockets[UP].conns[0] = 'A';
            component.sockets[UP].conns[1] = 'A';
            component.sockets[UP].conns[2] = 'A';

            component.sockets[RIGHT].conns[0] = 'A';
            component.sockets[RIGHT].conns[1] = 'A';
            component.sockets[RIGHT].conns[2] = 'A';

            component.sockets[DOWN].conns[0] = 'A';
            component.sockets[DOWN].conns[1] = 'A';
            component.sockets[DOWN].conns[2] = 'A';

            component.sockets[LEFT].conns[0] = 'A';
            component.sockets[LEFT].conns[1] = 'A';
            component.sockets[LEFT].conns[2] = 'A';

            break;

        case 1:
            component.sockets[UP].conns[0] = 'A';
            component.sockets[UP].conns[1] = 'A';
            component.sockets[UP].conns[2] = 'A';

            component.sockets[RIGHT].conns[0] = 'A';
            component.sockets[RIGHT].conns[1] = 'B';
            component.sockets[RIGHT].conns[2] = 'B';

            component.sockets[DOWN].conns[0] = 'B';
            component.sockets[DOWN].conns[1] = 'B';
            component.sockets[DOWN].conns[2] = 'B';

            component.sockets[LEFT].conns[0] = 'B';
            component.sockets[LEFT].conns[1] = 'B';
            component.sockets[LEFT].conns[2] = 'A';

            break;

        case 2:
            component.sockets[UP].conns[0] = 'A';
            component.sockets[UP].conns[1] = 'A';
            component.sockets[UP].conns[2] = 'A';

            component.sockets[RIGHT].conns[0] = 'A';
            component.sockets[RIGHT].conns[1] = 'B';
            component.sockets[RIGHT].conns[2] = 'B';

            component.sockets[DOWN].conns[0] = 'B';
            component.sockets[DOWN].conns[1] = 'B';
            component.sockets[DOWN].conns[2] = 'B';

            component.sockets[LEFT].conns[0] = 'B';
            component.sockets[LEFT].conns[1] = 'B';
            component.sockets[LEFT].conns[2] = 'A';

            break;

        case 3:
            component.sockets[UP].conns[0] = 'A';
            component.sockets[UP].conns[1] = 'A';
            component.sockets[UP].conns[2] = 'A';

            component.sockets[RIGHT].conns[0] = 'A';
            component.sockets[RIGHT].conns[1] = 'B';
            component.sockets[RIGHT].conns[2] = 'B';

            component.sockets[DOWN].conns[0] = 'B';
            component.sockets[DOWN].conns[1] = 'B';
            component.sockets[DOWN].conns[2] = 'B';

            component.sockets[LEFT].conns[0] = 'B';
            component.sockets[LEFT].conns[1] = 'B';
            component.sockets[LEFT].conns[2] = 'A';

            break;

        case 4:
            component.sockets[UP].conns[0] = 'A';
            component.sockets[UP].conns[1] = 'B';
            component.sockets[UP].conns[2] = 'B';

            component.sockets[RIGHT].conns[0] = 'B';
            component.sockets[RIGHT].conns[1] = 'B';
            component.sockets[RIGHT].conns[2] = 'B';

            component.sockets[DOWN].conns[0] = 'B';
            component.sockets[DOWN].conns[1] = 'B';
            component.sockets[DOWN].conns[2] = 'B';

            component.sockets[LEFT].conns[0] = 'B';
            component.sockets[LEFT].conns[1] = 'B';
            component.sockets[LEFT].conns[2] = 'A';

            break;

        case 5:
            component.sockets[UP].conns[0] = 'A';
            component.sockets[UP].conns[1] = 'B';
            component.sockets[UP].conns[2] = 'B';

            component.sockets[RIGHT].conns[0] = 'B';
            component.sockets[RIGHT].conns[1] = 'C';
            component.sockets[RIGHT].conns[2] = 'B';

            component.sockets[DOWN].conns[0] = 'B';
            component.sockets[DOWN].conns[1] = 'C';
            component.sockets[DOWN].conns[2] = 'B';

            component.sockets[LEFT].conns[0] = 'B';
            component.sockets[LEFT].conns[1] = 'B';
            component.sockets[LEFT].conns[2] = 'A';

            break;

        case 6:
            component.sockets[UP].conns[0] = 'B';
            component.sockets[UP].conns[1] = 'C';
            component.sockets[UP].conns[2] = 'B';

            component.sockets[RIGHT].conns[0] = 'B';
            component.sockets[RIGHT].conns[1] = 'B';
            component.sockets[RIGHT].conns[2] = 'B';

            component.sockets[DOWN].conns[0] = 'B';
            component.sockets[DOWN].conns[1] = 'C';
            component.sockets[DOWN].conns[2] = 'B';

            component.sockets[LEFT].conns[0] = 'B';
            component.sockets[LEFT].conns[1] = 'B';
            component.sockets[LEFT].conns[2] = 'B';

            break;

        case 7:
            component.sockets[UP].conns[0] = 'B';
            component.sockets[UP].conns[1] = 'C';
            component.sockets[UP].conns[2] = 'B';

            component.sockets[RIGHT].conns[0] = 'B';
            component.sockets[RIGHT].conns[1] = 'B';
            component.sockets[RIGHT].conns[2] = 'B';

            component.sockets[DOWN].conns[0] = 'B';
            component.sockets[DOWN].conns[1] = 'C';
            component.sockets[DOWN].conns[2] = 'B';

            component.sockets[LEFT].conns[0] = 'B';
            component.sockets[LEFT].conns[1] = 'C';
            component.sockets[LEFT].conns[2] = 'B';

            break;

        case 8:
            component.sockets[UP].conns[0] = 'B';
            component.sockets[UP].conns[1] = 'B';
            component.sockets[UP].conns[2] = 'C';

            component.sockets[RIGHT].conns[0] = 'C';
            component.sockets[RIGHT].conns[1] = 'B';
            component.sockets[RIGHT].conns[2] = 'B';

            component.sockets[DOWN].conns[0] = 'B';
            component.sockets[DOWN].conns[1] = 'C';
            component.sockets[DOWN].conns[2] = 'B';

            component.sockets[LEFT].conns[0] = 'B';
            component.sockets[LEFT].conns[1] = 'C';
            component.sockets[LEFT].conns[2] = 'B';

            break;

        case 9:
            component.sockets[UP].conns[0] = 'B';
            component.sockets[UP].conns[1] = 'C';
            component.sockets[UP].conns[2] = 'B';

            component.sockets[RIGHT].conns[0] = 'B';
            component.sockets[RIGHT].conns[1] = 'B';
            component.sockets[RIGHT].conns[2] = 'C';

            component.sockets[DOWN].conns[0] = 'C';
            component.sockets[DOWN].conns[1] = 'B';
            component.sockets[DOWN].conns[2] = 'C';

            component.sockets[LEFT].conns[0] = 'C';
            component.sockets[LEFT].conns[1] = 'B';
            component.sockets[LEFT].conns[2] = 'B';

            break;

        case 10:
            component.sockets[UP].conns[0] = 'B';
            component.sockets[UP].conns[1] = 'C';
            component.sockets[UP].conns[2] = 'B';

            component.sockets[RIGHT].conns[0] = 'B';
            component.sockets[RIGHT].conns[1] = 'B';
            component.sockets[RIGHT].conns[2] = 'B';

            component.sockets[DOWN].conns[0] = 'B';
            component.sockets[DOWN].conns[1] = 'B';
            component.sockets[DOWN].conns[2] = 'B';

            component.sockets[LEFT].conns[0] = 'B';
            component.sockets[LEFT].conns[1] = 'B';
            component.sockets[LEFT].conns[2] = 'B';

            break;

        case 11:
            component.sockets[UP].conns[0] = 'B';
            component.sockets[UP].conns[1] = 'B';
            component.sockets[UP].conns[2] = 'C';

            component.sockets[RIGHT].conns[0] = 'C';
            component.sockets[RIGHT].conns[1] = 'B';
            component.sockets[RIGHT].conns[2] = 'B';

            component.sockets[DOWN].conns[0] = 'B';
            component.sockets[DOWN].conns[1] = 'B';
            component.sockets[DOWN].conns[2] = 'B';

            component.sockets[LEFT].conns[0] = 'B';
            component.sockets[LEFT].conns[1] = 'B';
            component.sockets[LEFT].conns[2] = 'B';

            break;

        case 12:
            component.sockets[UP].conns[0] = 'B';
            component.sockets[UP].conns[1] = 'B';
            component.sockets[UP].conns[2] = 'B';

            component.sockets[RIGHT].conns[0] = 'B';
            component.sockets[RIGHT].conns[1] = 'B';
            component.sockets[RIGHT].conns[2] = 'B';

            component.sockets[DOWN].conns[0] = 'B';
            component.sockets[DOWN].conns[1] = 'B';
            component.sockets[DOWN].conns[2] = 'B';

            component.sockets[LEFT].conns[0] = 'B';
            component.sockets[LEFT].conns[1] = 'B';
            component.sockets[LEFT].conns[2] = 'B';

            break;

        case 13:
            component.sockets[UP].conns[0] = 'B';
            component.sockets[UP].conns[1] = 'C';
            component.sockets[UP].conns[2] = 'B';

            component.sockets[RIGHT].conns[0] = 'B';
            component.sockets[RIGHT].conns[1] = 'B';
            component.sockets[RIGHT].conns[2] = 'B';

            component.sockets[DOWN].conns[0] = 'B';
            component.sockets[DOWN].conns[1] = 'B';
            component.sockets[DOWN].conns[2] = 'B';

            component.sockets[LEFT].conns[0] = 'B';
            component.sockets[LEFT].conns[1] = 'C';
            component.sockets[LEFT].conns[2] = 'B';

            break;

        case 14:
            component.sockets[UP].conns[0] = 'B';
            component.sockets[UP].conns[1] = 'C';
            component.sockets[UP].conns[2] = 'B';

            component.sockets[RIGHT].conns[0] = 'B';
            component.sockets[RIGHT].conns[1] = 'B';
            component.sockets[RIGHT].conns[2] = 'B';

            component.sockets[DOWN].conns[0] = 'B';
            component.sockets[DOWN].conns[1] = 'B';
            component.sockets[DOWN].conns[2] = 'C';

            component.sockets[LEFT].conns[0] = 'C';
            component.sockets[LEFT].conns[1] = 'B';
            component.sockets[LEFT].conns[2] = 'B';

            break;

        case 15:
            component.sockets[UP].conns[0] = 'B';
            component.sockets[UP].conns[1] = 'B';
            component.sockets[UP].conns[2] = 'C';

            component.sockets[RIGHT].conns[0] = 'C';
            component.sockets[RIGHT].conns[1] = 'B';
            component.sockets[RIGHT].conns[2] = 'B';

            component.sockets[DOWN].conns[0] = 'B';
            component.sockets[DOWN].conns[1] = 'B';
            component.sockets[DOWN].conns[2] = 'C';

            component.sockets[LEFT].conns[0] = 'C';
            component.sockets[LEFT].conns[1] = 'B';
            component.sockets[LEFT].conns[2] = 'B';

            break;

        case 16:
            component.sockets[UP].conns[0] = 'A';
            component.sockets[UP].conns[1] = 'A';
            component.sockets[UP].conns[2] = 'A';

            component.sockets[RIGHT].conns[0] = 'A';
            component.sockets[RIGHT].conns[1] = 'B';
            component.sockets[RIGHT].conns[2] = 'B';

            component.sockets[DOWN].conns[0] = 'B';
            component.sockets[DOWN].conns[1] = 'B';
            component.sockets[DOWN].conns[2] = 'C';

            component.sockets[LEFT].conns[0] = 'C';
            component.sockets[LEFT].conns[1] = 'B';
            component.sockets[LEFT].conns[2] = 'A';

            break;

        case 17:
            component.sockets[UP].conns[0] = 'A';
            component.sockets[UP].conns[1] = 'A';
            component.sockets[UP].conns[2] = 'A';

            component.sockets[RIGHT].conns[0] = 'A';
            component.sockets[RIGHT].conns[1] = 'B';
            component.sockets[RIGHT].conns[2] = 'C';

            component.sockets[DOWN].conns[0] = 'C';
            component.sockets[DOWN].conns[1] = 'B';
            component.sockets[DOWN].conns[2] = 'B';

            component.sockets[LEFT].conns[0] = 'B';
            component.sockets[LEFT].conns[1] = 'B';
            component.sockets[LEFT].conns[2] = 'A';

            break;

        case 18:
            component.sockets[UP].conns[0] = 'B';
            component.sockets[UP].conns[1] = 'C';
            component.sockets[UP].conns[2] = 'B';

            component.sockets[RIGHT].conns[0] = 'B';
            component.sockets[RIGHT].conns[1] = 'B';
            component.sockets[RIGHT].conns[2] = 'C';

            component.sockets[DOWN].conns[0] = 'C';
            component.sockets[DOWN].conns[1] = 'B';
            component.sockets[DOWN].conns[2] = 'B';

            component.sockets[LEFT].conns[0] = 'B';
            component.sockets[LEFT].conns[1] = 'B';
            component.sockets[LEFT].conns[2] = 'B';
    }

    return component;
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


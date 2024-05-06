#include "../inc/cell.h"

#include <stdlib.h>

static int append_component(cell_t *cell, component_t *component) {
    // Create node for component
    component_list_node_t *node = (component_list_node_t *) malloc(sizeof(component_list_node_t));
    if (node == NULL) {
        return 0;
    }

    copy_component(&node->component, component);
    node->next = NULL;

    // Append new node
    if (cell->possibilities == 0) {
        cell->first = node;
    } else {
        component_list_node_t *last = cell->first;
        while (last->next != NULL) {
            last = last->next;
        }

        last->next = node;
    }

    cell->possibilities++;

    return 1;
}

static component_t *get(cell_t *cell, int index) {
    if (index < 0 || index >= cell->possibilities) {
        return NULL;
    }

    component_list_node_t *node = cell->first;
    for (int i = 0; i < index; i++) {
        node = node->next;
    }

    return &node->component;
}

static void remove_at(cell_t *cell, int index) {
    if (index < 0 || index >= cell->possibilities) {
        return;
    }

    component_list_node_t *target;

    if (index == 0) {
        target = cell->first;
        cell->first = NULL;
    } else {
        component_list_node_t *previous = cell->first;
        for (int i = 0; i < index - 1; i++) {
            previous = previous->next;
        }

        target = previous->next;
        previous->next = target->next;
    }

    free(target);

    cell->possibilities--;
}

int init_cell(cell_t *cell) {
    cell->first = NULL;
    cell->possibilities = 0;

    // Fill cell with all possibilities
    for (int type = 0; type < NUM_COMPONENT_TYPES; type++) {
        for (component_rotation_e rotation = ROT_0; rotation <= ROT_270; rotation++) {
            component_t component;
            create_component(&component, type, rotation);

            if (!append_component(cell, &component)) {
                return 0;
            }
        }
    }

    return 1;
}

component_t *get_component(cell_t *cell) {
    if (cell->possibilities != 1) {
        return NULL;
    }

    return &cell->first->component;
}

void reduce_possibilities(cell_t *target, socket_position_e target_socket,
        cell_t *reference, socket_position_e reference_socket) {

    for (int i = 0; i < target->possibilities; i++) {
        component_t *target_component = get(target, i);

        int can_connect = 1;
        for (int j = 0; j < reference->possibilities; j++) {
            if (!can_connect_components(target_component, target_socket,
                        get(reference, j), reference_socket)) {

                can_connect = 0;
                break;
            }
        }

        if (!can_connect) {
            remove_at(reference, i);
            i--;
        }
    }
}

void collapse(cell_t *cell) {

}

void free_cell(cell_t *cell) {
    while (cell->first != NULL) {
        component_list_node_t *trash = cell->first;
        cell->first = cell->first->next;

        free(trash);
    }

    cell->possibilities = 0;
}


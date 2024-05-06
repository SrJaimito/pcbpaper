#include "../inc/generator.h"

#include <stdlib.h>
#include <string.h>

int init_pcb(pcb_t *pcb, int width, int height) {
    pcb->width = width;
    pcb->height = height;

    pcb->cells = (cell_t **) malloc(height * sizeof(cell_t *));
    if (pcb->cells == NULL) {
        return 0;
    }

    for (int i = 0; i < height; i++) {
        pcb->cells[i] = (cell_t *) malloc(width * sizeof(cell_t));
        if (pcb->cells[i] == NULL) {
            return 0;
        }

        for (int j = 0; j < width; j++) {
            if (!init_cell(&pcb->cells[i][j])) {
                return 0;
            }
        }
    }

    return 1;
}

void search_next_component_to_collapse(pcb_t *pcb, int *x, int *y) {
    int min_possibilities = NUM_COMPONENT_TYPES * 4;

    for (int i = 0; i < pcb->height; i++) {
        for (int j = 0; j < pcb->width; j++) {
            int possibilities = pcb->cells[i][j].possibilities;

            if (possibilities != 1 && possibilities < min_possibilities) {
                min_possibilities = possibilities;
                *x = j;
                *y = i;
            }
        }
    }
}

void collapse_component(pcb_t *pcb, int x, int y) {
    int choice = rand() % pcb->cells[y][x].possibilities;

    if (choice != 0) {
        component_t *first_component = pcb->cells[y][x].possible_components;
        component_t *chosen_component = pcb->cells[y][x].possible_components + choice;

        copy_component(first_component, chosen_component);
    }

    pcb->cells[y][x].possibilities = 1;

    printf("Collapsed at (%d, %d): type %d with rotation %d\n", x, y,
            pcb->cells[y][x].possible_components[0].type, pcb->cells[y][x].possible_components[0].rotation);
}

static void reduce_possibilities(cell_t *cell, socket_position_e cell_socket,
        component_t *reference, socket_position_e reference_socket) {

    int current_possibilities = cell->possibilities;
    int i = 0;

    while (i < current_possibilities) {
        if (!can_connect_components(cell->possible_components + i, cell_socket,
                    reference, reference_socket)) {

            for (int j = i; j < current_possibilities - 1; j++) {
                copy_component(cell->possible_components + j, cell->possible_components + j + 1);
            }

            current_possibilities--;

        } else {
            i++;
        }
    }

    cell->possibilities = current_possibilities;
}

void propagate_from_component(pcb_t *pcb, int x, int y) {
    component_t *reference = pcb->cells[y][x].possible_components;

    // Up
    if (y > 0) {
        cell_t *current_cell = &(pcb->cells[y - 1][x]);

        if (current_cell->possibilities > 1) {
            reduce_possibilities(current_cell, DOWN, reference, UP);
        }
    }

    // Right
    if (x < pcb->width - 1) {
        cell_t *current_cell = &(pcb->cells[y][x + 1]);

        if (current_cell->possibilities > 1) {
            reduce_possibilities(current_cell, LEFT, reference, RIGHT);
        }
    }

    // Down
    if (y < pcb->height - 1) {
        cell_t *current_cell = &(pcb->cells[y + 1][x]);

        if (current_cell->possibilities > 1) {
            reduce_possibilities(current_cell, UP, reference, DOWN);
        }
    }
    
    // Left
    if (x > 0) {
        cell_t *current_cell = &(pcb->cells[y][x - 1]);

        if (current_cell->possibilities > 1) {
            reduce_possibilities(current_cell, RIGHT, reference, LEFT);
        }
    }
}

int pcb_collapsed(pcb_t *pcb) {
    for (int i = 0; i < pcb->height; i++) {
        for (int j = 0; j < pcb->width; j++) {
            if (pcb->cells[i][j].possibilities != 1) {
                return 0;
            }
        }
    }

    return 1;
}

void debug_print_pcb(pcb_t *pcb) {
}


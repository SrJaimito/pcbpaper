#include "../inc/generator.h"

#include <stdlib.h>
#include <string.h>

void reset_possibilities(pcb_cell_t *cell) {
    for (int type = 0; type < NUM_COMPONENT_TYPES; type++) {
        for (int rotation = ROT_0; rotation <= ROT_270; rotation++) {
            cell->possible_components[type * 4 + rotation] = create_component(type);
            cell->possible_components[type * 4 + rotation].rotation = rotation;
        }
    }

    cell->possibilities = NUM_COMPONENT_TYPES * 4;
}

int init_pcb(pcb_t *pcb, int width, int height) {
    pcb->width = width;
    pcb->height = height;

    pcb->cells = (pcb_cell_t **) malloc(height * sizeof(pcb_cell_t *));
    if (pcb->cells == NULL) {
        return 0;
    }

    for (int i = 0; i < height; i++) {
        pcb->cells[i] = (pcb_cell_t *) malloc(width * sizeof(pcb_cell_t));
        if (pcb->cells[i] == NULL) {
            return 0;
        }

        for (int j = 0; j < width; j++) {
            reset_possibilities(pcb->cells[i] + j);
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

        memcpy(first_component, chosen_component, sizeof(component_t));
    }

    pcb->cells[y][x].possibilities = 1;
}

void propagate_from_component(pcb_t *pcb, int x, int y) {
    component_t *reference = pcb->cells[y][x].possible_components;

    // Up
    if (y > 0) {
        int current_possibilities = pcb->cells[y - 1][x].possibilities;

        int i = 0;
        while (i < current_possibilities) {
            component_t *current = pcb->cells[y - 1][x].possible_components + i;

            if (!can_connect_components(current, DOWN, reference, UP)) {
                for (int j = i; j < current_possibilities - 1; j++) {
                    component_t *destiny = pcb->cells[y - 1][x].possible_components + i;
                    component_t *source = pcb->cells[y - 1][x].possible_components + i + 1;

                    memcpy(destiny, source, sizeof(component_t));
                }

                current_possibilities--;
            } else {
                i++;
            }
        }

        pcb->cells[y - 1][x].possibilities = current_possibilities;
    }

    // Right
    if (x < pcb->width - 1) {
        int current_possibilities = pcb->cells[y][x + 1].possibilities;

        int i = 0;
        while (i < current_possibilities) {
            component_t *current = pcb->cells[y][x + 1].possible_components + i;

            if (!can_connect_components(current, LEFT, reference, RIGHT)) {
                for (int j = i; j < current_possibilities - 1; j++) {
                    component_t *destiny = pcb->cells[y][x + 1].possible_components + i;
                    component_t *source = pcb->cells[y][x + 1].possible_components + i + 1;

                    memcpy(destiny, source, sizeof(component_t));
                }

                current_possibilities--;
            } else {
                i++;
            }
        }

        pcb->cells[y][x + 1].possibilities = current_possibilities;
    }

    // Down
    if (y < pcb->height - 1) {
        int current_possibilities = pcb->cells[y + 1][x].possibilities;

        int i = 0;
        while (i < current_possibilities) {
            component_t *current = pcb->cells[y + 1][x].possible_components + i;

            if (!can_connect_components(current, UP, reference, DOWN)) {
                for (int j = i; j < current_possibilities - 1; j++) {
                    component_t *destiny = pcb->cells[y + 1][x].possible_components + i;
                    component_t *source = pcb->cells[y + 1][x].possible_components + i + 1;

                    memcpy(destiny, source, sizeof(component_t));
                }

                current_possibilities--;
            } else {
                i++;
            }
        }

        pcb->cells[y + 1][x].possibilities = current_possibilities;
    }
    
    // Left
    if (x > 0) {
        int current_possibilities = pcb->cells[y][x - 1].possibilities;

        int i = 0;
        while (i < current_possibilities) {
            component_t *current = pcb->cells[y][x - 1].possible_components + i;

            if (!can_connect_components(current, RIGHT, reference, LEFT)) {
                for (int j = i; j < current_possibilities - 1; j++) {
                    component_t *destiny = pcb->cells[y][x - 1].possible_components + i;
                    component_t *source = pcb->cells[y][x - 1].possible_components + i + 1;

                    memcpy(destiny, source, sizeof(component_t));
                }

                current_possibilities--;
            } else {
                i++;
            }
        }

        pcb->cells[y][x - 1].possibilities = current_possibilities;
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
    for (int i = 0; i < pcb->height; i++) {
        // UP
        for (int j = 0; j < pcb->width; j++) {
            component_t *current = pcb->cells[i][j].possible_components;

            current->sockets[UP].c
        }
    }
}


#include "../inc/generator.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static void search_low_entropy_cell(pcb_t *pcb, int *x, int *y) {
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

static void collapse_cell(pcb_t *pcb, int x, int y) {
    collapse(&pcb->cells[y][x]);
}

static void propagate_collapse(pcb_t *pcb, int x, int y) {
    cell_t *reference = &pcb->cells[y][x];

    // Up
    if (y > 0) {
        cell_t *current_cell = &(pcb->cells[y - 1][x]);

        if (current_cell->possibilities > 1) {
            if (reduce_possibilities(current_cell, DOWN, reference, UP)) {
                propagate_collapse(pcb, x, y - 1);
            }
        }
    }

    // Right
    if (x < pcb->width - 1) {
        cell_t *current_cell = &(pcb->cells[y][x + 1]);

        if (current_cell->possibilities > 1) {
            if (reduce_possibilities(current_cell, LEFT, reference, RIGHT)) {
                propagate_collapse(pcb, x + 1, y);
            }
        }
    }

    // Down
    if (y < pcb->height - 1) {
        cell_t *current_cell = &(pcb->cells[y + 1][x]);

        if (current_cell->possibilities > 1) {
            if (reduce_possibilities(current_cell, UP, reference, DOWN)) {
                propagate_collapse(pcb, x, y + 1);
            }
        }
    }
    
    // Left
    if (x > 0) {
        cell_t *current_cell = &(pcb->cells[y][x - 1]);

        if (current_cell->possibilities > 1) {
            if (reduce_possibilities(current_cell, RIGHT, reference, LEFT)) {
                propagate_collapse(pcb, x - 1, y);
            }
        }
    }
}

static int pcb_collapsed(pcb_t *pcb) {
    for (int i = 0; i < pcb->height; i++) {
        for (int j = 0; j < pcb->width; j++) {
            if (pcb->cells[i][j].possibilities != 1) {
                return 0;
            }
        }
    }

    return 1;
}

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

int generate_random_pcb(pcb_t *pcb) {
    int first_x = rand() % pcb->width;
    int first_y = rand() % pcb->height;

    collapse_cell(pcb, first_x, first_y);
    printf("First collapse OK\n");
    propagate_collapse(pcb, first_x, first_y);
    printf("First propagation OK\n");

    int i = 1;

    while (!pcb_collapsed(pcb)) {
        int x, y;

        search_low_entropy_cell(pcb, &x, &y);
        printf("Num. searches: %d\n", i);
        collapse_cell(pcb, x, y);
        printf("Num. collapses: %d\n", i);
        propagate_collapse(pcb, x, y);
        printf("Num. propagations: %d\n", i);

        i++;
    }
    
    return 1;
}

void free_pcb(pcb_t *pcb) {
    for (int i = 0; i < pcb->height; i++) {
        for (int j = 0; j < pcb->width; j++) {
            free_cell(&pcb->cells[i][j]);
        }

        free(pcb->cells[i]);
    }

    free(pcb->cells);
}


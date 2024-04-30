#ifndef __PCBPAPER_PCBGEN_GENERATOR_H__
#define __PCBPAPER_PCBGEN_GENERATOR_H__

#include "component.h"

typedef struct {
    component_t possible_components[NUM_COMPONENT_TYPES * 4];
    int possibilities;
} pcb_cell_t;

void reset_possibilities(pcb_cell_t *cell);

typedef struct {
    pcb_cell_t **cells;
    int width;
    int height;
} pcb_t;

int init_pcb(pcb_t *pcb, int width, int height);
void search_next_component_to_collapse(pcb_t *pcb, int *x, int *y);
void collapse_component(pcb_t *pcb, int x, int y);
void propagate_from_component(pcb_t *pcb, int x, int y);
int pcb_collapsed(pcb_t *pcb);

void debug_print_pcb(pcb_t *pcb);

#endif


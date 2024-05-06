#ifndef __PCBPAPER_PCBGEN_CELL_H__
#define __PCBPAPER_PCBGEN_CELL_H__

#include "component.h"

typedef struct component_list_node {
    component_t component;
    struct component_list_node *next;
} component_list_node_t;

typedef struct {
    component_list_node_t *first;
    int possibilities;
} cell_t;

#ifdef __TEST_CELL__
int append_component(cell_t *, component_t *);
component_t *get(cell_t *, int);
void remove_at(cell_t *, int);
#endif

int init_cell(cell_t *cell);

component_t *get_component(cell_t *cell);
int reduce_possibilities(cell_t *target, socket_position_e target_socket,
        cell_t *reference, socket_position_e reference_socket);
void collapse(cell_t *cell);

void free_cell(cell_t *cell);

#endif


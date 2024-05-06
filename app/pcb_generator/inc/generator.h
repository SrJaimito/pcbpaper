#ifndef __PCBPAPER_PCBGEN_GENERATOR_H__
#define __PCBPAPER_PCBGEN_GENERATOR_H__

#include "cell.h"

typedef struct {
    cell_t **cells;
    int width;
    int height;
} pcb_t;

int init_pcb(pcb_t *pcb, int width, int height);

int generate_random_pcb(pcb_t *pcb);

void free_pcb(pcb_t *pcb);

#endif


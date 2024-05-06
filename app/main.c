#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "pcb_generator/inc/generator.h"

int main(int argc, char *argv[]) {
    pcb_t pcb;

    int width = atoi(argv[1]);
    int height = atoi(argv[2]);

    srand(time(NULL));

    init_pcb(&pcb, width, height);

    int random_x = rand() % width;
    int random_y = rand() % height;

    collapse_component(&pcb, random_x, random_y);
    propagate_from_component(&pcb, random_x, random_y);

    while (!pcb_collapsed(&pcb)) {
        int x, y;

        search_next_component_to_collapse(&pcb, &x, &y);
        collapse_component(&pcb, x, y);
        propagate_from_component(&pcb, x, y);
    }

    debug_print_pcb(&pcb);
}


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "pcb_generator/inc/generator.h"

int main(int argc, char *argv[]) {
    pcb_t pcb;

    int width = atoi(argv[1]);
    int height = atoi(argv[2]);

    srand(time(NULL));

    printf("Init PCB: %s\n", init_pcb(&pcb, width, height) ? "OK" : "FAILED");

    generate_random_pcb(&pcb);

    printf("OK!\n");

    free_pcb(&pcb);

    return 0;
}


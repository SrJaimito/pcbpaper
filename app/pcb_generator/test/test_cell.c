#include <stdio.h>

#include "../inc/cell.h"

int main(int argc, char *argv[]) {
    printf("[TEST : PCB_GENERATOR : CELL]\n");

    component_t c0, c1, c2, c3, c4;
    
    create_component(&c0, 0, ROT_0);
    create_component(&c1, 1, ROT_0);
    create_component(&c2, 2, ROT_0);
    create_component(&c3, 3, ROT_0);
    create_component(&c4, 4, ROT_0);

    cell_t cell;
    cell.first = NULL;
    cell.possibilities = 0;

    append_component(&cell, &c0);
    append_component(&cell, &c1);
    append_component(&cell, &c2);
    append_component(&cell, &c3);
    append_component(&cell, &c4);

    int test_1_ok = 1;
    for (int i = 0; i < cell.possibilities; i++) {
        component_t *current = get(&cell, i);

        if (current->type != i) {
            test_1_ok = 0;
            break;
        }
    }

    printf(" - [TEST 1] %s\n", test_1_ok ? "PASSED" : "FAILED");

    remove_at(&cell, 0);

    component_t *new_first = get(&cell, 0);
    int test_2_ok = (cell.possibilities) == 4 && (new_first->type == 1);

    printf(" - [TEST 2] %s\n", test_2_ok ? "PASSED" : "FAILED");

    remove_at(&cell, 2);

    int test_3_ok = 1;

    test_3_ok = get(&cell, 0)->type == 1;
    test_3_ok = get(&cell, 1)->type == 2;
    test_3_ok = get(&cell, 2)->type == 4;

    printf(" - [TEST 3] %s\n", test_3_ok ? "PASSED" : "FAILED");

    return 0;
}


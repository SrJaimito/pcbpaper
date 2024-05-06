#include <stdio.h>

#include "../inc/component.h"

int main(int argc, char *argv[]) {
    printf("[TEST : PCB_GENERATOR : COMPONENT]\n");

    component_t a, b;

    create_component(&a, 7, ROT_0);
    create_component(&b, 13, ROT_0);

    printf(" - [TEST 1] ");

    a.rotation = ROT_0;
    printf("%s\n", can_connect_components(&a, DOWN, &b, UP) ? "PASSED" : "FAILED");

    printf(" - [TEST 2] ");

    a.rotation = ROT_90;
    printf("%s\n", can_connect_components(&a, DOWN, &b, UP) ? "PASSED" : "FAILED");

    printf(" - [TEST 3] ");

    a.rotation = ROT_180;
    printf("%s\n", can_connect_components(&a, DOWN, &b, UP) ? "PASSED" : "FAILED");

    printf(" - [TEST 4] ");

    a.rotation = ROT_270;
    printf("%s\n", !can_connect_components(&a, DOWN, &b, UP) ? "PASSED" : "FAILED");

    printf(" - [TEST 5] ");

    a.rotation = ROT_0;
    printf("%s\n", !can_connect_components(&a, RIGHT, &b, LEFT) ? "PASSED" : "FAILED");

    printf(" - [TEST 6] ");

    a.rotation = ROT_90;
    printf("%s\n", can_connect_components(&a, RIGHT, &b, LEFT) ? "PASSED" : "FAILED");

    printf(" - [TEST 7] ");

    a.rotation = ROT_180;
    printf("%s\n", can_connect_components(&a, RIGHT, &b, LEFT) ? "PASSED" : "FAILED");

    printf(" - [TEST 8] ");

    a.rotation = ROT_270;
    printf("%s\n", can_connect_components(&a, RIGHT, &b, LEFT) ? "PASSED" : "FAILED");

    printf(" - [TEST 9] ");

    a.rotation = ROT_0;
    printf("%s\n", !can_connect_components(&a, UP, &b, DOWN) ? "PASSED" : "FAILED");

    printf(" - [TEST 10] ");

    a.rotation = ROT_90;
    printf("%s\n", can_connect_components(&a, UP, &b, DOWN) ? "PASSED" : "FAILED");

    printf(" - [TEST 11] ");

    a.rotation = ROT_180;
    printf("%s\n", !can_connect_components(&a, UP, &b, DOWN) ? "PASSED" : "FAILED");

    printf(" - [TEST 12] ");

    a.rotation = ROT_270;
    printf("%s\n", !can_connect_components(&a, UP, &b, DOWN) ? "PASSED" : "FAILED");

    printf(" - [TEST 13] ");

    a.rotation = ROT_0;
    printf("%s\n", !can_connect_components(&a, LEFT, &b, RIGHT) ? "PASSED" : "FAILED");

    printf(" - [TEST 14] ");

    a.rotation = ROT_90;
    printf("%s\n", !can_connect_components(&a, LEFT, &b, RIGHT) ? "PASSED" : "FAILED");

    printf(" - [TEST 15] ");

    a.rotation = ROT_180;
    printf("%s\n", can_connect_components(&a, LEFT, &b, RIGHT) ? "PASSED" : "FAILED");

    printf(" - [TEST 16] ");

    a.rotation = ROT_270;
    printf("%s\n", !can_connect_components(&a, LEFT, &b, RIGHT) ? "PASSED" : "FAILED");

    return 0;
}


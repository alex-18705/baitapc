// math_utils.c
#include<stdio.h>
#include "math_utils.h"

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}
int main() {
    int x = 10, y = 3;
    printf("Add: %d\n", add(x, y));
    printf("Subtract: %d\n", subtract(x, y));
    return 0;
}
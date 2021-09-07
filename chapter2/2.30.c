// Write a function with the following prototype:
// /* Determine whether arguments can be added without overflow */
// int tadd_ok(int x, int y);
// This function should return 1 if arguments x and y can be added without
// causing overflow.

/* Determine whether arguments can be added without overflow */
int tadd_ok(int x, int y);

int tadd_ok(int x, int y)
{
    int s = x + y;
    return !((s >= 0 && x < 0 && y < 0) || (s <= 0 && x > 0 && y > 0));
}

#include <stdio.h>
#include <limits.h>

int main()
{
    printf("1 means OK, 0 means overflow\n");
    printf("Pos-overflow? %d\n", tadd_ok(INT_MAX, 1));
    printf("Neg-overflow? %d\n", tadd_ok(INT_MIN, -1));
    printf("No overflow? %d\n", tadd_ok(114514, 1919810));
}
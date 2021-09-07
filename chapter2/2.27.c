// Write a function with the following prototype:
// /* Determine whether arguments can be added without overflow */
// int uadd_ok(unsigned x, unsigned y);

// This function should return 1 if arguments x and y can be added without
// causing overflow.

/* Determine whether arguments can be added without overflow. Derivation is at page 125  */
int uadd_ok(unsigned x, unsigned y);

int uadd_ok(unsigned x, unsigned y)
{
    unsigned result = x + y;
    return result >= x && result >= y;
    // solution from book
    // return result >= x;
}

// Test
#include <stdio.h>
#include <limits.h>

int main()
{
    printf("Can UMax + 1 be added without overflow? %d\n", uadd_ok(UINT_MAX, 1));
    printf("How about 114514 + 1919810? %d\n", uadd_ok(114514, 1919810));
}
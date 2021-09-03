// Using only bit-level and logical operations, write a C expression that is equivalent
// to x == y. In other words, it will return 1 when x and y are equal and 0 otherwise.

#include <stdio.h>

int equal(int x, int y)
{
    return !(x ^ y) ? 1 : 0;
}

int main()
{
    printf("114514 == 114514 ? %d\n", equal(114514, 114514));
    printf("114514 == 1919810 ? %d\n", equal(114514, 19191810));
}
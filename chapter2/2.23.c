// Consider the following C functions:
int fun1(unsigned word)
{
    return (int)((word << 24) >> 24);
}
int fun2(unsigned word)
{
    return ((int)word << 24) >> 24;
}

// Describe in words the useful computation each of these functions performs.
// Function fun1 extracts a value from the low-order 8 bits of the argument,
// giving an integer ranging between 0 and 255. Function fun2 extracts a value
// from the low-order 8 bits of the argument, but it also performs sign extension.
// The result will be a number between −128 and 127.

// Assume these are executed as a 32-bit program on a machine that uses two’scomplement
// arithmetic. Assume also that right shifts of signed values are performed
// arithmetically, while right shifts of unsigned values are performed logically.

#include <stdio.h>

void PrintResult(int w)
{
    printf("0x%.8x 0x%.8x 0x%.8x\n", w, fun1(w), fun2(w));
}

int main()
{
    printf("%10s %10s %10s\n", "w", "fun1(w)", "fun2(w)");
    PrintResult(0x00000076);
    PrintResult(0x87654321);
    // In Two's Complement, If the most significant bit is 1, it means negative. And >> is arithmetic move.
    // Just remember that hex digits 8 through F have their most significant bits equal to 1.
    PrintResult(0x000000C9);
    PrintResult(0xEDCBA987);
}
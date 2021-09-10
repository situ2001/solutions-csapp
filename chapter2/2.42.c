// Write a function div16 that returns the value x/16 for integer argument x. Your
// function should not use division, modulus, multiplication, any conditionals (if or
// ?:), any comparison operators (e.g., <, >, or ==), or any loops. You may assume
// that data type int is 32 bits long and uses a two’s-complement representation, and
// that right shifts are performed arithmetically.

/* function div16, rounding up if x < 0, rounding down if x >= 0 */
int div16(int x)
{
    int bias = x >> 31 & 0xf; // If x >= 0, bias = 0. Else if x < 0, bias = 15
    return (x + bias) >> 4;
}

// Test
#include <stdio.h>

int main()
{
    int neg_x = -30;
    int pos_x = 30;
    printf("30 / 16 = %d\n", div16(pos_x));
    printf("-30 / 16 = %d (Two's Complement Division, rounding up)\n", div16(neg_x));
    printf("-30 / 16 = %d (Arithmetic Right Shift, rounding down)\n", neg_x >> 4);
}
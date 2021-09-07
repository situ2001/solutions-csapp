// Your coworker gets impatient with your analysis of the overflow conditions for
// two’s-complement addition and presents you with the following implementation
// of tadd_ok:
/* Determine whether arguments can be added without overflow */
/* WARNING: This code is buggy. */
int tadd_ok(int x, int y)
{
    int sum = x + y;
    return (sum - x == y) && (sum - y == x);
}
// You look at the code and laugh. Explain why.

#include <stdio.h>
#include <limits.h>

// You can test in 4-bit presentation.
// For example, consider x = 4, y = 6, x + y = 10 >= 7, so truncated result is 10 - 2^4 = -6
// Let tmp = (-6) -4 = -10, you surprisingly find that -10 is also overflow
// Adding 2^4 to tmp yields 6, which equals to y!

// But in fact...
// Modular addition forms a mathematical structure known as an abelian group
// Two’scomplement addition uses modular addition under the hooks, so forms an abelian group
// Thus, sum = x + y, so (x + y) - x = y => (x - x) + y == y (commutative & associative)
// regradless whether there is an overflow or not, check the paragraph under the problem 2.27

int main()
{
    printf("%d\n", tadd_ok(INT_MAX, 1));
    printf("%d\n", tadd_ok(INT_MIN, -1));
    printf("%d\n", tadd_ok(114514, 1919810));
}

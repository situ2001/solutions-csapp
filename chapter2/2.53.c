// Fill in the following macro definitions to generate the double-precision values+∞,
// −∞, and −0:
// #define POS_INFINITY
// #define NEG_INFINITY
// #define NEG_ZERO
// You cannot use any include files (such as math.h), but you can make use of the
// fact that the largest finite number that can be represented with double precision
// is around 1.8 × 10308.

// Just define a value that is larger than 1.8*10e308
#define POS_INFINITY 1e514
#define NEG_INFINITY (-POS_INFINITY)
#define NEG_ZERO (1 / NEG_INFINITY)

// test
#include <stdio.h>

int main()
{
    printf("%f\n", POS_INFINITY); // inf
    printf("%f\n", NEG_INFINITY); // -inf
    printf("%f\n", NEG_ZERO); // -0.000000
}
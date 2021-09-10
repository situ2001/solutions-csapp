// For the case where data type int has 32 bits, devise a version of tmult_ok (Problem
// 2.35) that uses the 64-bit precision of data type int64_t, without using
// division.

// From proble 2.35
/* Determine whether arguments can be multiplied without overflow */
int tmult_ok(int x, int y)
{
    int p = x * y;
    /* Either x is zero, or dividing p by x gives y */
    return !x || p / x == y;
}

#include <stdio.h>
#include <limits.h>

// impl another version that uses 64-bit preciousion of data
int tmult_ok_i64(__int64_t a, __int64_t b)
{
    __int64_t ans = a * b;
    return ans == (int) ans; // truncate upper 32 bits
}

int main()
{
    printf("Is INT_MAX * INT_MAX ok? %d\n", tmult_ok_i64(INT_MAX, INT_MAX));
    printf("Is 114 * 514 ok? %d\n", tmult_ok_i64(114, 514));
}
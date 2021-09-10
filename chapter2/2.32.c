// You are assigned the task of writing code for a function tsub_ok, with arguments
// x and y, that will return 1 if computing x-y does not cause overflow. Having just
// written the code for Problem 2.30,
int tadd_ok(int x, int y)
{
    int s = x + y;
    return !((s >= 0 && x < 0 && y < 0) || (s <= 0 && x > 0 && y > 0));
}
// you write the following:
/* Determine whether arguments can be subtracted without overflow */
/* WARNING: This code is buggy. */
int tsub_ok(int x, int y)
{
    return tadd_ok(x, -y);
}
// For what values of x and y will this function give incorrect results? Writing a
// correct version of this function is left as an exercise (Problem 2.74).

#include <stdio.h>
#include <limits.h>

int main()
{
    // That's it.
    // Notice that there's no prefect asymmetry in the ranges of [TMin...TMax]
    // Note: TMin = - (TMax + 1)
    // -1 + TMin should be equalvent to -1 - (TMax + 1)
    printf("%d\n", tadd_ok(1, INT_MAX + 1)); // Yields 1
    printf("%d\n", tsub_ok(-1 , INT_MIN)); // Expect 1, but get 0!
}
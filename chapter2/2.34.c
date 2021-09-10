// In the following code, we have omitted the definitions of constants M and N:
#define M 31 /* Mystery number 1 */
#define N 8 /* Mystery number 2 */
int arith(int x, int y)
{
    int result = 0;
    result = x * M + y / N; /* M and N are mystery numbers. */
    return result;
}
// We compiled this code for particular values of M and N. The compiler optimized
// the multiplication and division using the methods we have discussed. The
// following is a translation of the generated machine code back into C:
/* Translation of assembly code for arith */
int optarith(int x, int y)
{
    int t = x;
    x <<= 5;
    x -= t;
    if (y < 0)
        y += 7;
    y >>= 3; /* Arithmetic shift */
    return x + y;
}
// What are the values of M and N ?

// My answer is as follwed

// Well, from the first 3 statements, we can surely write down
// the expr: x = (x << 5) - (x << 0), which means x = x * (2^5 - 2^0), thus M = 31
// And the remaining statements indicate that this is a division on Two's complement
// if y < 0 then y += 7, this statement tells us that the bias is (1<<3) - 1 = 7
// Adding bias to y and then right shift y by 3 bit tells us that N = 8

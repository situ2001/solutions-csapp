#include <stdio.h>
#include <limits.h>

int main()
{
    // 1 1 0 1 1
    printf("%d %d %d %d %d\n",
        -2147483647-1 == 2147483648U,
        -2147483647-1 < 2147483647,
        -2147483647-1U < 2147483647,
        -2147483647-1 < 2147483647,
        -2147483647-1U < -2147483647
    );
}

#include <stdio.h>

int f4(int x, int y, int z)
{
    int t = z - y;
    unsigned tmp = t >> 31;
    t += tmp;
    t >>= 1;
    int sum = t + y;
    if (sum - x == 0)
    {
        return 0;
    }
    if (sum - x > 0)
    {
        return 2 * f4(x, y, sum - 1);
    }
    if (sum - x < 0)
    {
        return 2 * f4(x, sum + 1, z) + 1;
    }
}

int main()
{
    for (int i = 0; i < 10; i++)
    {
        if (f4(i, 0, 14) == 0)
        {
            printf("%d\n", i);
        }
    }
}

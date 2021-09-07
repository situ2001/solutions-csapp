/* WARNING: This is buggy code */
float sum_elements(float a[], unsigned length)
{
    int i;
    float result = 0;

    for (i = 0; i <= length - 1; i++)
        result += a[i];
    return result;
}

// When run with argument length equal to 0, this code should return 0.0.
// Instead, it encounters a memory error. Explain why this happens. Show how this
// code can be corrected.

#include <stdio.h>
typedef unsigned char *byte_pointer;
void show_bytes(byte_pointer start, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%.2x ", start[i]);
    }
    printf("\n");
}

/* Now I fix it! */
float sum_elements_fixed(float a[], unsigned length)
{
    int i;
    float result = 0;
    // Because of the implicit casting between int & unsigned
    // When one of the two operands is int type and another one is unsigned type
    // The int one will be implicitly casted to unsigned
    // 0 - 1 = -1, which represents 0xffffffff, then converts to unsigned comparsion
    // So i <= 0 - 1 means 0x00000000 <= 0xffffffff, which is always true in this loop.
    unsigned ar = length - 1;
    show_bytes((byte_pointer)(&ar), 4); // ff ff ff ff
    // So we fix it by simply adding (int) before length to avoid implicit cast.
    for (i = 0; i <= (int)length - 1; i++)
    // or by changing
    // the test of the for loop to be i < length. (to avoid negative value)
    // for (i = 0; i < length; i++)
        result += a[i];
    return result;
}

int main()
{
    float arr[] = {1, 2, 3, 4, 5};
    printf("%f", sum_elements_fixed(arr, 0));
}

#include <stdio.h>

typedef unsigned char* byte_pointer;
// Q: Why don't we use signed char pointer to visit raw memory?
// A: When you dereference it, you know it. (signed byte ranges from -128 to 127)
// typedef char* byte_pointer;

void show_bytes(byte_pointer start, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf ("%.2x ", start[i]);
    }
    printf("\n");
}

void show_pointer(void* x)
{
    show_bytes((byte_pointer) &x, sizeof(void*));
}

int main()
{
    long i = 1145141919810810L;
    show_bytes((byte_pointer) &i, sizeof(long)); // address of the variable i
    show_pointer(&i); // address of the pointer to i
}
void switch_eg_impl(long x, long n, long *dest)
{
    // extened C
    // the authors of gcc create a new operator && to create a pointer for a code location
    static void *jt[7] = { &&loc_A, &&loc_default, &&loc_B, &&loc_C, &&loc_D, &&loc_default, &&loc_D };
    
    unsigned long index = n - 100;
    long val;
    if (index > 6)
        goto loc_default;

    goto *jt[index];

loc_A:
    val = x * 13;
    goto done;
loc_B:
    x = x + 10;
loc_C:
    val = x + 11;
    goto done;
loc_D:
    val = x * x;
    goto done;
loc_default:
    val = 0;
done:
    *dest = val;
}
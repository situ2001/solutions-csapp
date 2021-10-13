long fact_for_guarded_goto(long n)
{
    long i;
    long result = 1;
    i = 2;
    if (n < i) // guard
    {
        goto done;
    }
loop:
    result *= i;
    i++;
    if (i <= n)
    {
        goto loop;
    }
done:
    return result;
}
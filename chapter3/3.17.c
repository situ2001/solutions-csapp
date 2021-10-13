long lt_cnt = 0;
long ge_cnt = 0;

long gotodiff_se_alt(long x, long y)
{
    long result;
    int t = x < y;
    if (t)
    {
        goto label;
    }
    else
    {
        goto done;
    }
label:
    lt_cnt++;
    return y - x;
done:
    ge_cnt++;
    return x - y;
}
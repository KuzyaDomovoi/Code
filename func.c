double per_sq(double w, double h)
{
    if(w < 0 || h < 0)
        return 0;

    return 2 * (w + h);
}

int abs_int(int x)
{
    return(x < 0) ? -x : x;

}

int sq_to_int(double x)
{
    return(int)(x * x);
}

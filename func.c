double per_sq(double w, double h)
{
    if(w < 0 || h < 0)
        return 0;

    return 2 * (w + h);
}

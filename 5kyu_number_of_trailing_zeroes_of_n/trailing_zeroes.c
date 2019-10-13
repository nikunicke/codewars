int     trailing_zeros(long n) {
    int     i;
    int     zeros;

    i = 5;
    zeros = 0;
    while (i <= n) {
        zeros += n / i;
        i *= 5;
    }
    return (zeros);
}

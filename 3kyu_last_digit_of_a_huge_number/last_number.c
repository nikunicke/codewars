#include <stdio.h>

int     big_mod(int base, int exp, int mod) {
    if (exp == 0)
        return (1 % mod);
    else if (exp == 1)
        return (base % mod);
    else if (exp % 2 == 0)
        return (((big_mod(base, exp / 2, mod) % mod) * (big_mod(base, exp / 2, mod) % mod)) % mod);
    else if (exp % 2 != 0)
        return (((big_mod(base, 1, mod) % mod) * (big_mod(base, exp - 1, mod) % mod)) % mod);
}

int     last_ndec(int n, int mod) {
    if (n < 0)
        n *= -1;
    if (n < mod)
        return (n);
    last_ndec(n % mod, mod);
}

int     ft_pow(int n, int e) {
    if (e < 1)
        return (1);
    else if (n == 0)
        return (0);
    else
        return (n * ft_pow(n, e - 1));
}

int     num_of_digits(int n) {
    int     count;

    if (n < 0)
        n *= -1;
    count = 1;
    while (n > 0) {
        count++;
        n /= 10;
    }
    return (count - 1);
}

int     inverse_mod(int a, int b) {
    int     x;

    if (a > b)
        return (1);
    x = 1;
    while ((a * x) % b != 1)
        x++;
    return (x);
}

int     crt(int base, int exp, int dec) {
    int     mod_a;
    int     mod_b;
    int     x1;
    int     x2;
    int     res;

    if (base == 0 && exp == 0)
        return (1);
    else if (base == 0)
        return (0);
    mod_a = ft_pow(2, dec);
    mod_b = ft_pow(5, dec);
    x1 = big_mod(base, exp, mod_a);
    x2 = big_mod(base, exp, mod_b);
    x1 = x1 * mod_b * inverse_mod(mod_b, mod_a);
    x2 = x2 * mod_a * inverse_mod(mod_a, mod_b);
    res = (x1 + x2) % ft_pow(10, dec);
    if (res == 0)
        res = 100;
    return (res);
}

int     last_digit(const unsigned long int *arr, size_t arr_size) {
    int     i;
    int     last_digit;

    if (arr_size == 0)
        return (1);
    i = arr_size - 1;
    while (arr[i] != 0 && i > 0) {
        i--;
    }
    if (i == 0)
        i = arr_size - 1;
    last_digit = arr[i] % 1000;
    while (i > 0) {
        last_digit = crt(arr[i - 1] % 10, last_digit, 4);
        i--;
    }
    return (last_digit % 10);
}


int     main(void) {
    int     res;
    const unsigned long int     arr[5] = {9, 9, 9, 9, 9};
    size_t  size;

    size = 5;
    res = last_digit(arr, size);
    printf("%d\n", res);


    return (0);
}
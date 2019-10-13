#include <stdio.h>
#include <stdlib.h>

long long     ft_pow(int n, int e) {
    if (e < 1)
        return (1);
    else if (n == 0)
        return (0);
    else
        return (n * ft_pow(n, e - 1));
}

int     last_ndec(long long n, int mod) {
    if (n < 0)
        n *= -1;
    if (n < mod)
        return (n);
    last_ndec(n % mod, mod);
}

int     main(int ac, char **av) {
    long long   result;
    long long   num[2];
    int         pos[4];
    int         i;
    int         j;
    int         x;
    int         k;
    int         exp;
    int         len;

    num[0] = 3;
    num[1] = 1;
    i = 0;

    while (i < 4) {
        pos[i] = last_ndec(ft_pow(last_ndec(num[0], 10), i + 1), 10);
        i++;
    }
    exp = 125;
    len = 4;
    x = 0;
    k = 0;
    j = 0;

    if (exp > 9) {
        x = last_ndec(exp, 10);
        if ((exp / 10) % 2 != 0)
            x += 2;
        else if (x == 0)
            x = 4;
        while (k < x) {
            j = 0;
            while (j < 4) {
                j++;
                k++;
                if (k == x)
                    break;
            }
        }
    }
    else {
        while (k < exp) {
            j = 0;
            while (j < 4) {
                j++;
                k++;
                if (k == exp)
                    break;
            }
        }
    }

    printf("%d\n", pos[j - 1]);


    // k = 1;
    // j = 0;
    // printf("%d\n", x);
    // while (k <= x) {
    //     j = 0;
    //     while (j < 4) {
    //         k++;
    //         if (k == x)
    //             break;
    //         j++;
    //     }
    // }
    // printf("%d\n%d\n", j, pos[j]);

    // i = 0;
    // while (i < 4) {
    //     printf("%d\n", pos[i]);
    //     i++;
    // }


    // x = last_ndec(num[0], 10);
    // printf("%d\n", x);

    // if (ac == 2) {
    //     exp = 10;
    //     while (exp >= 0) {
    //         printf("%lld\n", ft_pow(atoi(av[1]), exp));
    //         if (exp % 10 == 0)
    //             printf("\n");
    //         exp--;
    //     }
    // }
    return (0);
}
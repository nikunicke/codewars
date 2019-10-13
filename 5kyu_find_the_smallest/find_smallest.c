#include <stdio.h>
#include <stdlib.h>

void     split_digits(long long n, long long i, long long *arr) {
    if (n > 9) {
        split_digits(n / 10, i - 1, arr);
        arr[i] = n % 10;
    } else
        arr[i] = n;
}

long long    join_digits(long long *arr, long long len) {
    long long     i;
    long long     result;

    i = 0;
    result = 0;
    while (i < len) {
        result = result * 10 + arr[i];
        i++;
    }
    return (result);
}

long long     num_of_digits(long long n) {
    long long     count;

    if (n < 0)
        n *= -1;
    count = 1;
    while (n > 0) {
        count++;
        n /= 10;
    }
    return (count - 1);
}

// long long     index_of(long long *arr, long long len) {
//     long long     min_i;
//     long long     i;

//     min_i = 0;
//     i = 0;
//     while(i < len) {
//         if (arr[i] <= arr[min_i]) {
//             min_i = i;
//         }
//         i++;
//     }
//     return (min_i);
// }

long long     wtf(long long *arr, long long len) {
    long long     i;
    long long     j;
    long long     k;
    long long     min_i;

    j = 0;
    k = 0;
    min_i = 0;
    while (k == j && j < len) {
        i = j;
        while (i < len) {
            if (arr[i] <= arr[k]) {
                k = i;
            }
            i++;
        }
        min_i = k;
        if (k == j) {
            j++;
            k++;
            if (j == len)
                return (0);
        }
        else
            break;
    }
    return (min_i);
}

void    ft_swap(long long *a, long long *b) {
    long long     tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

long long    *swap_if(long long *arr, long long len, long long min) {
    long long            i;
    long long            min_i;
    long long            tmp_i;
    static long long     result[3];

    i = 0;
    while (i < min) {
        if (arr[i] > arr[min]) {
            min_i = min;
            tmp_i = i + 1;
            while (arr[i] > arr[tmp_i] && arr[tmp_i] == arr[tmp_i + 1] && tmp_i < min)
                tmp_i++;
            if (tmp_i == min) {
                ft_swap(&arr[i], &arr[min]);
                i = tmp_i;
                min = 0;
            }
            else if (min == len - 1 && arr[min] != arr[min - 1]) {
                while (i < min) {
                    ft_swap(&arr[i], &arr[i + 1]);
                    i++;
                }
                min = 0;
            }
            else {
                while (i < min_i) {
                    ft_swap(&arr[min_i], &arr[min_i - 1]);
                    min_i--;
                }
                if (min == len - 1) {
                    while (arr[min] == arr[min - 1] && min > 0)
                        min--;
                    min--;
                }
                if (i == min_i && arr[i] == arr[min_i - 1] && i > 0)
                    i--;
            }
            break;
        }
        i++;
    }
    if (i == min) {
        i = 0;
        min = 0;
    }
    result[0] = join_digits(arr, len);
    result[1] = min;
    result[2] = i;
    return (result);
}

long long* smallest(long long n) {
    long long   *arr;
    long long   *result;
    long long   digits;

    digits = num_of_digits(n);
    if (!(arr = malloc(sizeof(long long) * digits)))
        return (0);
    split_digits(n, digits - 1, arr);
    result = swap_if(arr, digits, wtf(arr, digits));
    return (result);
}

int     main(void) {
    long long   *test;
    int         i;


    test = smallest(1100);
    i = 0;
    while (i < 3) {
        printf("%lld\n", test[i]);
        i++;
    }
    return (0);
}

// 296837
// 261235 OK
// 9223372036854775807
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void    ft_putchar(char c) {
    write(1, &c, 1);
}

typedef struct          s_list
{
    struct s_list       *next;
    char                *data;
}                       t_list;

t_list    *ft_create_elem(char *data) {
    t_list  *node;

    if (!(node = malloc(sizeof(t_list))))
        return (0);
    if (node) {
        node->data = data;
        node->next = NULL;
    }
    return (node);
}

void    ft_push_back(t_list **first, char *data) {
    t_list  *tmp;

    if (*first) {
        tmp = *first;
        while (tmp->next) {
            tmp = tmp->next;
        }
        tmp->next = ft_create_elem(data);
    } else
        *first = ft_create_elem(data);
}

int     ft_strlen(char *str) {
    int     i;
    
    i = 0;
    while (str[i])
        i++;
    return (i);
}

char    *ft_strdup(char *str) {
    char    *dest;
    int     i;

    if (!(dest = malloc(sizeof(char) * (ft_strlen(str) + 1))))
        return (0);
    i = 0;
    while (str[i]) {
        dest[i] = str[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char    *ft_strcat(char *dest, char *src) {
    int     i;
    int     j;

    i = 0;
    while (dest[i])
        i++;
    j = 0;
    while (src[j]) {
        dest[i + j] = src[j];
        j++;
    }
    dest[i + j] = '\0';
    return (dest);
}

void    *split_digits(int n, int i, char *str) {
    if (n < 0) {
        str[i - i] = '-';
        n *= -1;
    }
    if (n > 9) {
        split_digits(n / 10, i - 1, str);
        str[i] = n % 10 + '0';
    } else
        str[i] = n + '0';
}

int     num_of_digits(int n) {
    int     count;

    if (n == 0)
        return (1);
    if (n < 0)
        n *= -1;
    count = 1;
    while (n > 0) {
        count++;
        n /= 10;
    }
    return(count - 1);
}

char    *ft_itoa(int n) {
    char    *res;
    int     int_len;

    int_len = num_of_digits(n);
    if (n < 0)
        int_len++;
    if (!(res = malloc(sizeof(char) * int_len + 1)))
        return (0);
    split_digits(n, int_len - 1, res);
    res[int_len] = '\0';
    return (res);
}

int     minutes(int seconds) {
    return (seconds / 60);
}

int     hours(int seconds) {
    return (seconds / (60 * 60));
}

int     days(int seconds) {
    return (seconds / (60 * 60 * 24));
}

int     years(int seconds) {
    return (seconds / (60 * 60 * 24 * 365));
}

int     *calculated_duration(int sec) {
    int    *time;

    if (!(time = malloc(sizeof(int) * 5)))
        return (0);
    time[0] = years(sec);
    time[1] = days(sec) % 365;
    time[2] = hours(sec) % 24;
    time[3] = minutes(sec) % 60;
    time[4] = sec % 60;
    return (time);
}

int     find_last(int *arr, int len) {
    len--;
    while (arr[len] == 0) {
        len--;
    }
    return (len);
}

char    *format_duration(int *time) {
    char        *result;
    char        **units;
    t_list      *list;
    int         len;
    char         *num;
    int         i;
    int         j;

    if(!(units = malloc(sizeof(char *) * 5 + 1)))
        return (0);
    units[0] = ft_strdup("year");
    units[1] = ft_strdup("day");
    units[2] = ft_strdup("hour");
    units[3] = ft_strdup("minute");
    units[4] = ft_strdup("second");
    units[5] = 0;
    len = 0;
    i = 0;
    list = NULL;
    j = find_last(time, 5);
    while (i < 5) {
        if (time[i] > 0) {
            num = ft_itoa(time[i]);
            ft_push_back(&list, ft_strdup(num));
            ft_push_back(&list, ft_strdup(" "));
            ft_push_back(&list, ft_strdup(units[i]));
            if (time[i] > 1) {
                ft_push_back(&list, ft_strdup("s"));
                len += 1;
            }
            if (i + 1 < j) {
                ft_push_back(&list, ft_strdup(", "));
                len += 2;
            } else if (i + 1 == j) {
                ft_push_back(&list, ft_strdup(" and "));
                len += 5;
            }
            len += 1;
            len += ft_strlen(num);
            len += ft_strlen(units[i]);

        }
        i++;
    }
    if (!(result = malloc(sizeof(char) * len + 1)))
        return (0);
    while (list) {
        result = ft_strcat(result, list->data);
        list = list->next;
    }
    return (result);
}


int     main(void) {
    int     sec;
    int     i;
    int     *asd;
    char    *time;
    char    *result;
    // t_list  *list;

    // time = ft_itoa(31536000);
    // printf("%s\n", time);
    // sec = 3662;
    // time = calculated_duration(sec);
    // printf("HELLO");
    // result = format_duration(time);
    i = 0;
    sec = 167249;
    asd = calculated_duration(sec);
    // while (i < 5) {
    //     printf("%d", asd[i]);
    //     if (i + 1 != 5)
    //         printf(" - ");
    //     i++;
    // }
    // printf("\n");
    result = format_duration(asd);
    printf("%s", result);
    // printf("%d years\n", years(sec));
    // printf("%d days\n", days(sec) % 365);
    // printf("%d hours\n", hours(sec) % 24);
    // printf("%d minutes\n", minutes(sec) % 60);
    // printf("%d seconds\n", sec % 60);
    printf("\n");
    return (0);
}

// 1 year = 31536000
// 1h 1min 2s = 3662
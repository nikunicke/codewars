#include <stdio.h>
#include <stdlib.h>

int     scramble(char *str1, char *str2) {
    int     *alpha;
    int     i;
    int     j;

    if (!(alpha = calloc(sizeof(int), 26)))
        return (0);
    
    i = 0;
    while (str1[i]) {
        alpha[str1[i] - 97] += 1;
        i++;
    }
    j = 0;
    while (str2[j]) {
        if (alpha[str2[j] - 97] < 1)
            return (0);
        else
            alpha[str2[j] - 97] -= 1;
        j++;
    }
    free(alpha);
    return (1);
}

int     main(void) {
    if (scramble("katas", "steak"))
        printf("TRUE\n");
    else
        printf("FALSE\n");
    return (0);
}
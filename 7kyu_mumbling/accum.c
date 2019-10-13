#include <stdlib.h>
#include <stdio.h>

// TEST COMMENT

int	determine_len(const char *str)
{
    int	    i;
    int	    res;

    i = 0;
    res = 0;
    while (str[i])
    {
	res += i + 1;
	i++;
    }
    return (res + i);
}

char	*ft_strcat(char *dest, const char *src, int *pos)
{

    dest[*pos] = *src;
    (*pos)++;
    dest[*pos] = '\0';
    return (dest);
}

void	str_capit(char *str)
{
    int	    i;
    
    if (*str >= 'a' && *str <= 'z')
	*str -= 32;
    i = 1;
    while (str[i])
    {
	if ((str[i] >= 'a' && str[i] <= 'z') && str[i - 1] == '-')
	    str[i] -= 32;
	else if ((str[i] >= 'A' && str[i] <= 'Z') && str[i - 1] != '-')
	    str[i] += 32;
	i++;
    }
}

char	*accum(const char *src)
{
    int	    i;
    int	    j;
    int	    k;
    int	    pos;
    char    *res;

    if (!(res = malloc(sizeof(char) * determine_len(src))))
	return (0);
    i = 0;
    k = 1;
    pos = 0;
    while (src[i])
    {
	j = 0;
	while (j < k)
	{
	    res = ft_strcat(res, &src[i], &pos);
	    j++;
	}
	if (src[i + 1] != '\0')
	    res = ft_strcat(res, "-", &pos);
	k++;
	i++;
    }
    str_capit(res);
    return (res);
}

int	main(int ac, char **av)
{
    if (ac == 2)
    {
	printf("%s", accum(av[1]));
    }
    printf("\n");
    return (0);
}

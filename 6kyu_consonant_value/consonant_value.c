#include <stdio.h>

int	is_consonant(char c)
{
    char    consonants[] = "bcdfghjklmnpqrstvwxyz";
    int	    i;

    i = 0;
    while (consonants[i])
    {
	if (consonants[i] == c)
		return (1);
	i++;
    }
    return (0);
}

int	solve(const char *str)
{
    int	    i;
    int	    tmp;
    int	    max;

    i = 0;
    max = 0;
    while (str[i])
    {
	tmp = 0;
	while (is_consonant(str[i]))
	{
	    tmp = tmp + (str[i] - 96);
	    i++;
	}
	if (tmp > max)
	    max = tmp;
	if (str[i])
	    i++;
    }
    return (max);
}

int	main(int ac, char **av)
{
    if (ac == 2)
    {
	printf("%d", solve(av[1]));
    }
    printf("\n");
    return (0);
}

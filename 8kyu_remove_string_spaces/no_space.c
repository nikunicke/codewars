#include <stdlib.h>
#include <stdio.h>

int 	ft_strlen_no_space(char	*strin)
{
  int i;
  int j;

  i = 0;
  j = 0;
  while (strin[i] != '\0')
    {
      if (strin[i] > 32)
        j++;
      i++;
    }
  return (j);
}

char *no_space(char *strin) {

  int i;
  int j;
  char *no_space;
  int len;

  len =	ft_strlen_no_space(strin);
  if (len == 0)
    return (0);
  printf("%d\n", len);
  no_space = malloc(sizeof(char) * len);
  if (no_space == NULL)
    return (0);
  i = 0;
  j = 0;
  while(strin[i] != '\0')
    {
      if(strin[i] == 32)
        i++;
      else
        {
          no_space[j] = strin[i];
          i++;
          j++;
        }
    }
  no_space[j] = '\0';
  return (no_space);
}

int     main(void) {
    char    *result;
    int     len;

    result = no_space("asd asd");
    printf("%s\n", result);
    free(result);
    return (0);
}
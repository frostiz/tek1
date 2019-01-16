/*
** my_strcat.c for 42sh in /home/Lucas/delivery/PSU/PSU_2016_42sh
**
** Made by Lucas Dumy
** Login   <lucas.dumy@epitech.eu>
**
** Started on  Thu May 18 17:36:27 2017 Lucas Dumy
** Last update Mon May 22 14:54:47 2017 Lucas Dumy
*/

#include	<stdlib.h>
#include	<string.h>
#include	"mysh.h"

int			my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str != NULL && str[i] != '\0')
    i++;
  return (i);
}

char		*my_strcat(char *str1, char *str2)
{
  char		*str3;
  int		i;
  int		j;

  i = 0;
  j = 0;
  if (str2 == NULL)
    return (NULL);
  str3 = malloc(sizeof(char) * (my_strlen(str1) + my_strlen(str2) + 1));
  if (str3 == NULL)
    exit(84);
  while (str1 != NULL && str1[i] != '\0')
    {
      str3[i] = str1[i];
      i++;
    }
  while (str2 != NULL && str2[j] != '\0')
    {
      str3[i + j] = str2[j];
      j++;
    }
  str3[i + j] = '\0';
  return (str3);
}

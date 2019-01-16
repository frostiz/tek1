/*
** strings.c for Navy in /home/thibaut/Repository/PSU_2016_navy/src
** 
** Made by 
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Wed Feb 15 17:36:52 2017 
** Last update Sun Feb 19 18:31:12 2017 
*/

#include "my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

int	is_number(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < '0' || str[i] > '9')
	return (0);
      i++;
    }
  return (1);
}

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] ==  s2[i])
    {
      if (s1[i] == '\0' || s2[i] == '\0')
	return (0);
      i++;
    }
  if (s1[i] < s2[i] && s1 != '\0')
    return (-1);
  else
    return (1);
  return (0);
}

char	*my_strdup(char *str)
{
  int	i;
  char	*tmp;

  i = 0;
  tmp = malloc(sizeof(char) * my_strlen(str) + 1);
  if (tmp == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      tmp[i] = str[i];
      i++;
    }
  tmp[i] = '\0';
  return (tmp);
}

void	swap_char(char *a, char *b)
{
  char	tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
}

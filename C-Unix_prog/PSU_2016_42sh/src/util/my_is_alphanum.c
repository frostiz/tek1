/*
** my_is_alphanum.c for 42sh in /home/Lucas/delivery/PSU/PSU_2016_42sh
**
** Made by Lucas Dumy
** Login   <lucas.dumy@epitech.eu>
**
** Started on  Fri Apr  7 09:50:38 2017 Lucas Dumy
** Last update Mon May 15 10:24:13 2017 Lucas Dumy
*/

#include	"mysh.h"

int		my_is_alphanum(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if ((str[i] < '0' && str[i] != '.') || (str[i] > '9' && str[i] < 'A') ||
	  (str[i] > 'Z' && str[i] < 'a' && str[i] != '_') || str[i] > 'z')
	return (-1);
      i++;
    }
  return (0);
}

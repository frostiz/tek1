/*
** glob_util.c for 42sh in /home/Lucas/delivery/PSU/PSU_2016_42sh
**
** Made by Lucas Dumy
** Login   <lucas.dumy@epitech.eu>
**
** Started on  Sun May 21 14:48:16 2017 Lucas Dumy
** Last update Sun May 21 23:39:07 2017 Thibaut Trouvé
*/

#include	"mysh.h"

int		my_has_slash(char *arg)
{
  int		i;

  i = 0;
  while (arg[i] != '\0')
    {
      if (arg[i] == '/')
	return (1);
      i++;
    }
  return (0);
}

int		my_is_glob(char *str)
{
  int		bracket;
  int		i;

  i = 0;
  bracket = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '[')
	bracket = 1;
      if (str[i] == '*' || str[i] == '?' || (str[i] == ']' && bracket == 1))
	return (0);
      i++;
    }
  return (1);
}

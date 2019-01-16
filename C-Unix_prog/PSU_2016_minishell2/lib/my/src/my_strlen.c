/*
** my_strlen.c for my_strlen.c in /home/thibaut/Repository/PSU_2016_minishell2/lib/my
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Mon Apr  3 21:13:02 2017 Thibaut Trouvé
** Last update Mon Apr  3 21:26:10 2017 Thibaut Trouvé
*/

#include "my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      i++;
    }
  return (i);
}

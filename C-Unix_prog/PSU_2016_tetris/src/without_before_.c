/*
** without_before_.c for  in /home/sahel/rendu/PSU/PSU_2016_tetris
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Thu Mar  2 14:27:13 2017 Sahel
** Last update Thu Mar  2 14:37:03 2017 Sahel
*/

#include <stdlib.h>
#include <unistd.h>
#include "basic.h"

char	*without_before_(char *str, char c)
{
  char	*new;
  int	str_i;
  int	new_i;

  str_i = 0;
  new_i = 0;
  new = malloc(strlen_(str) + 1);
  if (!new)
    return (NULL);
  while (str[str_i] && str[str_i] != c)
    str_i++;
  str_i++;
  while (str[str_i])
    {
      new[new_i] = str[str_i];
      new_i++;
      str_i++;
    }
  new[new_i] = '\0';
  return (new);
}

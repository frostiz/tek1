/*
** get_next_line2.c for  in /home/sahel/rendu/CPE_2016_matchstick
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Sun Feb 26 16:50:35 2017 Sahel
** Last update Sun Feb 26 16:51:31 2017 Sahel
*/

#include <stdlib.h>
#include <unistd.h>
#include "basic.h"

char	*concat_free(char *str1, char *str2)
{
  char	*new;
  int	str_i[2];

  if (str1 && str2)
    new = malloc(strlen_(str1) + strlen_(str2) + 1);
  else
    new = malloc(strlen_((str1) ? (str1) : (str2)) + 1);
  if (!new)
    return (NULL);
  str_i[0] = 0;
  str_i[1] = 0;
  while (str1 && str1[str_i[0]])
    {
      new[str_i[0]] = str1[str_i[0]];
      str_i[0]++;
    }
  while (str2 && str2[str_i[1]])
    {
      new[str_i[0] + str_i[1]] = str2[str_i[1]];
      str_i[1]++;
    }
  new[str_i[0] + str_i[1]] = '\0';
  free_(str1);
  return (new);
}

/*
** my_realloc.c for tetris in /home/thibaut/Repository/PSU_2016_tetris
** 
** Made by 
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Fri Mar 10 17:28:00 2017 
** Last update Fri Mar 10 17:30:47 2017 
*/

#include <stdlib.h>

char	*realloc_(char *str, int size)
{
  int	i;
  char	*tmp;

  tmp = malloc(sizeof(char) * size);
  if (tmp == NULL)
    return (NULL);
  i = 0;
  while (str[i] != '\0')
    {
      tmp[i] = str[i];
      i++;
    }
  tmp[i] = '\0';
  return (tmp);
}

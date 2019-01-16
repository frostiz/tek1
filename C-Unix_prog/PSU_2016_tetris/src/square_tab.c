/*
** square_tab.c for  in /home/sahel/rendu/PSU_2016_tetris
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Sat Mar 18 17:16:20 2017 Sahel
** Last update Sat Mar 18 17:22:22 2017 Sahel
*/

#include <stdlib.h>

char	**malloc_square_tab(int size)
{
  char	**tab;
  int	i;

  i = 0;
  if (!(tab = malloc(sizeof(char *) * (size + 1))))
    return (NULL);
  while (i < size)
    {
      if (!(tab[i] = malloc(size + 1)))
	return (NULL);
      i++;
    }
  tab[i] = NULL;
  return (tab);
}

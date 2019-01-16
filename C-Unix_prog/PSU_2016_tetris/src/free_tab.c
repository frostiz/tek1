/*
** free_tab.c for  in /home/sahel/rendu/PSU_2016_tetris
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Fri Mar 17 13:58:35 2017 Sahel
** Last update Fri Mar 17 14:08:47 2017 Sahel
*/

#include <unistd.h>
#include <stdlib.h>
#include "basic.h"

void	free_tab(char **tab)
{
  int	len;

  len = 0;
  while (tab && tab[len])
    {
      free_(tab[len]);
      len++;
    }
  if (tab)
    free(tab);
}

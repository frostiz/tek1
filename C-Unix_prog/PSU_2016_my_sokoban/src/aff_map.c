/*
** aff_map.c for aff_map.c in /home/frostiz/PSU_2016_my_sokoban
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Fri Dec 16 00:01:32 2016 thibaut trouve
** Last update Tue Dec 20 04:28:13 2016 thibaut trouve
*/

#include "my.h"

void	aff_map(char **map, int row_max, int col_max)
{
  int   i;
  int   j;

  i = 0;
  j = 0;
  if (col_max % 2 != 0)
    j = 1;
  while (map[i] != NULL)
    {
      move(LINES / 2 - row_max / 2 + i, COLS / 2 - col_max / 2 + j);
      printw("%s", map[i]);
      i++;
    }
}

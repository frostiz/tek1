/*
** check_error.c for check_error.c in /home/frostiz/PSU_2016_my_sokoban
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Mon Dec 19 15:35:03 2016 thibaut trouve
** Last update Mon Dec 19 15:54:30 2016 thibaut trouve
*/

#include "my.h"

int	check_map(char **map)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (map[i] != NULL)
    {
      while (map[i][j] != '\0')
	{
	  if (map[i][j] != ' ' && map[i][j] != '\n' &&
	      map[i][j] != 'X' && map[i][j] != 'P' &&
	      map[i][j] != '#' && map[i][j] != 'O')
	    return (1);
	  j++;
	}
      j = 0;
      i++;
    }
  return (0);
}

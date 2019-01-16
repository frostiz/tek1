/*
** check_end.c for check_end.c in /home/frostiz/PSU_2016_my_sokoban
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Fri Dec 16 00:02:22 2016 thibaut trouve
** Last update Mon Dec 19 11:07:32 2016 thibaut trouve
*/

#include "my.h"

int	check_lose(char **map)
{
  int   i;
  int   j;
  int   stuck;
  int   nb_x;

  nb_x = 0;
  stuck = 0;
  i = 0;
  j = 0;
  while (map[i] != NULL)
    {
      while (map[i][j] != '\0')
	{
	  if (map[i][j] == 'X')
	    {
	      nb_x++;
	      check_around(map, i, j, &stuck);
	    }
	  j++;
	}
      i++;
      j = 0;
    }
  return (stuck >= nb_x ? 1 : 0);
}

int	check_win(char **map, char **map_o)
{
  int   nb_o;
  int   i;
  int   j;

  nb_o = count_o(map_o);
  i = 0;
  j = 0;
  while (map[i] != NULL)
    {
      while (map[i][j] != '\0')
	{
	  if (map[i][j] == 'X' && map_o[i][j] == 'O')
	    nb_o--;
	  j++;
	}
      i++;
      j = 0;
    }
  if (nb_o == 0)
    return (1);
  return (0);
}

int	check_nb_o(char **map)
{
  int	i;
  int   j;
  int   nb_o;
  int   nb_x;

  i = 0;
  j = 0;
  nb_o = 0;
  nb_x = 0;
  while (map[i] != NULL)
    {
      while (map[i][j] != '\0')
	{
	  if (map[i][j] == 'X')
	    nb_x++;
	  if (map[i][j] == 'O')
	    nb_o++;
	  j++;
	}
      j = 0;
      i++;
    }
  if (nb_o < nb_x)
    return (1);
  return (0);
}

void	check_around(char **map, int i, int j, int *stuck)
{
  if ((map[i - 1][j] == '#' || map[i - 1][j - 1] == 'X') &&
      (map[i][j - 1] == '#' || map[i][j - 1] == 'X'))
    (*stuck)++;
  else if ((map[i - 1][j] == '#' || map[i - 1][j] == 'X') &&
	   (map[i][j + 1] == '#' || map[i][j + 1] == 'X'))
    (*stuck)++;
  else if ((map[i + 1][j] == '#' || map[i + 1][j] == 'X') &&
	   (map[i][j - 1] == '#' || map[i][j - 1] == 'X'))
    (*stuck)++;
  else if ((map[i + 1][j] == '#' || map[i + 1][j] == 'X') &&
	   (map[i][j + 1] == '#' || map[i][j + 1] == 'X'))
    (*stuck)++;
}

/*
** check_boat_error.c for Navy in /home/thibaut/Repository/PSU_2016_navy/src
** 
** Made by 
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Wed Feb 15 17:45:30 2017 
** Last update Sun Feb 19 18:37:41 2017 
*/

#include "my.h"

int	check_boats_lenght(char **map)
{
  int	i;
  int	j;
  int	lenght[4][2];

  i = 0;
  j = 0;
  while (map[i] != NULL)
    {
      lenght[i][0] = i + 2;
      lenght[i][1] = 0;
      i++;
    }
  i = 0;
  while (map[i] != NULL)
    {
      while (j < 4)
	{
	  if (lenght[j][0] == map[i][0] - 48)
	    lenght[j][1] = 1;
	  j++;
	}
      j = 0;
      i++;
    }
  return (check_lenght(lenght));
}

int	check_boat_coords(char **map)
{
  int	i;

  i = 0;
  while (map[i] != NULL)
    {
      if (map[i][2] != map[i][2 + 3] && map[i][3] != map[i][3 + 3])
	return (1);
      else if (map[i][2] == map[i][2 + 3])
	{
	  if (map[i][2 + 1] > map[i][2 + 3 + 1])
	    swap_char(&map[i][2 + 1], &map[i][2 + 3 + 1]);
	}
      else if (map[i][3] == map[i][3 + 3])
	{
	  swap_char(&map[i][2], &map[i][2 + 1]);
	  swap_char(&map[i][2 + 3], &map[i][2 + 3 + 1]);
	  i = 0;
	}
      i++;
    }
  return (0);
}

int	check_lenght_coherence(char **map)
{
  int	i;
  int	len;

  i = 0;
  len = 0;
  while (map[i] != NULL)
    {
      len = map[i][0] - 48;
      if (map[i][3] + len - 1 != map[i][3 + 3])
	return (1);
      i++;
    }
  return (0);
}

int	check_cross_boat(char **map)
{
  char	**coord_tab;
  int	i;
  int	j;

  coord_tab = get_coords(map);
  i = 0;
  j = 0;
  while (coord_tab[i] != NULL)
    {
      while (coord_tab[j] != NULL)
	{
	  if (j != i)
	    if (my_strcmp(coord_tab[i], coord_tab[j]) == 0)
	      return (1);
	  j++;
	}
      j = 0;
      i++;
    }
  return (0);
}

int	is_valid_coord(char **map)
{
  if (check_boats_lenght(map) == 1)
    {
      my_putstr("Invalid lenght of boat(s)\n");
      return (1);
    }
  if (check_boat_coords(map) == 1)
    {
      my_putstr("Invalid coordinates of boat(s)\n");
      return (1);
    }
  if (check_lenght_coherence(map) == 1)
    {
      my_putstr("Invalid lenght of boat(s)\n");
      return (1);
    }
  return (0);
}

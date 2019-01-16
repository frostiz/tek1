/*
** check_map_error.c for Navy in /home/thibaut/Repository/PSU_2016_navy/src
** 
** Made by 
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Wed Feb 15 17:43:53 2017 
** Last update Sun Feb 19 18:43:22 2017 
*/

#include "my.h"

int	invalid_character(char **map)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (map[i] != NULL)
    {
      while (map[i][j] != '\0')
	{
	  if ((!(map[i][j] >= '2' && map[i][j] <= '5')) && (j == 0))
	    return (1);
	  if (((map[i][j] < '1') || (map[i][j] > '8' && map[i][j] < 'A') ||
	       (map[i][j] > 'H' && map[i][j] < 'a') || (map[i][j] > 'h'))
	      && map[i][j] != ':')
	    return (1);
	  if (map[i][j] >= 'a' && map[i][j] <= 'h')
	    map[i][j] -= 32;
	  j++;
	}
      if (j != 7)
	return (1);
      i++;
      j = 0;
    }
  return (0);
}

int	nb_boat(char **map)
{
  int	i;

  i = 0;
  while (map[i] != NULL)
    i++;
  return (i);
}

void	count_separator(char **map, int i, int *j, int *separator)
{
  if ((map[i][*j] >= '1' && map[i][*j] <= '7') &&
      (map[i][*j + 1] >= 'A' && map[i][*j + 1] <= 'H'))
    swap_char(&map[i][*j], &map[i][*j + 1]);
  if (map[i][*j] == ':')
    (*separator)++;
  (*j)++;
}

int	check_separators(char **map)
{
  int	i;
  int	j;
  int	separator;

  separator = 0;
  i = 0;
  j = 0;
  while (map[i] != NULL)
    {
      if (map[i][1] != ':' && map[i][1 + 3] != ':')
	return (1);
      while (map[i][j] != '\0')
	{
	  count_separator(map, i, &j, &separator);
	}
      if (separator != 2)
	return (1);
      separator = 0;
      j = 0;
      i++;
    }
  return (0);
}

int	check_lenght(int lenght[4][2])
{
  int	i;

  i = 0;
  while (i < 4)
    {
      if (lenght[i][1] == 0)
	return (1);
      i++;
    }
  return (0);
}

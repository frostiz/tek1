/*
** check_input.c for Navy in /home/thibaut/Repository/PSU_2016_navy/src
** 
** Made by 
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Wed Feb 15 17:55:59 2017 
** Last update Sun Feb 19 18:40:57 2017 
*/

#include "my.h"

char	**get_coords(char **map)
{
  int	i;
  int	j;
  int	k;
  char	**coord_tab;

  i = 0;
  j = 0;
  k = 0;
  if ((coord_tab = malloc(sizeof(char *) * 15)) == NULL)
    return (NULL);
  while (map[i] != NULL)
    {
      while (map[i][3] + j <= map[i][3 + 3])
	{
	  if ((coord_tab[k] = malloc(sizeof(char) * 3)) == NULL)
	    return (NULL);
	  coord_tab[k][0] = map[i][3 - 1];
	  coord_tab[k][1] = map[i][3] + j++;
	  coord_tab[k++][2] = '\0';
	}
      j = 0;
      i++;
    }
  coord_tab[k] = NULL;
  return (coord_tab);
}

int	check_error(char **map)
{
  if (nb_boat(map) != 4)
    {
      my_putstr("Invalid map, too much boats\n");
      return (1);
    }
  if (invalid_character(map) == 1 || check_separators(map) == 1)
    {
      my_putstr("Invalid map, invalid character(s) found\n");
      return (1);
    }
  if (is_valid_coord(map) == 1)
    return (1);
  if (check_cross_boat(map) == 1)
    {
      my_putstr("boats are on same positions\n");
      return (1);
    }
  return (0);
}

void	count_k(int *k, int *j)
{
  (*k)++;
  if (*k == *j)
    {
      (*j)++;
      *k = 0;
    }
}

int	check_input_validity(char *input)
{
  char	tmp;

  if (input[0] == '\0')
    return (84);
  if (my_strlen(input) != 2)
    return (84);
  if (input[0] >= 'a' && input[0] <= 'h')
    input[0] -= 32;
  if (input[1] >= 'a' && input[1] <= 'h')
    input[1] -= 32;
  if ((input[1] >= 'A' && input[1] <= 'H') &&
      (input[0] >= '1' && input[0] <= '8'))
    {
      tmp = input[1];
      input[1] = input[0];
      input[0] = tmp;
    }
  if ((input[0] >= 'A' && input[0] <= 'H') &&
      (input[1] >= '1' && input[1] <= '8'))
    return (0);
  my_putstr(input);
  return (84);
}

int	count_x(char **positions, int *nb_hit)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (positions[i] != NULL)
    {
      while (positions[i][j] != '\0')
	{
	  if (positions[i][j] == 'x')
	    (*nb_hit)++;
	  j++;
	}
      j = 0;
      i++;
    }
  return (0);
}

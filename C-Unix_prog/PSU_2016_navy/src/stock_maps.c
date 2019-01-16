/*
** stock_maps.c for Navy in /home/thibaut/Repository/PSU_2016_navy/src
** 
** Made by 
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Wed Feb 15 17:21:31 2017 
** Last update Sun Feb 19 18:39:38 2017 
*/

#include "my.h"
#include "gnl.h"

extern int	nb_sig[3];

char	**get_map()
{
  char	**positions;
  int	i;

  positions = malloc(sizeof(char *) * 9);
  if (positions == NULL)
    return (NULL);
  positions[8] = NULL;
  i = 0;
  while (i < 8)
    {
      positions[i] = my_strdup("........");
      i++;
    }
  return (positions);
}

char	**file_to_wordtab(int fd)
{
  char	*line;
  char	**map;
  int	i;

  map = malloc(sizeof(char *) * 5);
  if (map == NULL)
    return (NULL);
  i = 0;
  while ((line = get_next_line(fd)) != NULL)
    {
      map[i] = my_strdup(line);
      i++;
    }
  map[i] = NULL;
  return (map);
}

char	**stock_map(char **file)
{
  char	**coords;
  char	**map;
  int	i;
  int	j;
  int	k;

  k = 0;
  j = 2;
  coords = get_coords(file);
  map = get_map();
  i = 0;
  while (coords[i] != NULL)
    {
      if (coords[i][0] >= 'A' && coords[i][0] <= 'H')
	{
	  if (coords[i][1] >= '1' && coords[i][1] <= '8')
	    map[coords[i][1] - 48 - 1][coords[i][0] - 65] = file[j - 2][0];
	}
      else
	map[coords[i][0] - 48 - 1][coords[i][1] - 65] = file[j - 2][0];
      i++;
      count_k(&k, &j);
    }
  return (map);
}

char	**get_my_map(int fd)
{
  char	**file;
  char	**map;

  file = file_to_wordtab(fd);
  if (check_error(file) == 1)
    return (NULL);
  map = stock_map(file);
  return (map);
}

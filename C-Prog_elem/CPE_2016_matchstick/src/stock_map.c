/*
** stock_map.c for matchstick in /home/thibaut/Repository/CPE_2016_matchstick
** 
** Made by 
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Sun Feb 26 14:38:13 2017 
** Last update Sun Feb 26 16:49:26 2017 
*/

#include "my.h"

char	**create_stickmap(int nb_line)
{
  int	i;
  int	j;
  int	nb_stick;
  char	**map;

  if ((map = malloc(sizeof(char *) * (nb_line + 1))) == NULL)
    return (NULL);
  nb_stick = 1;
  i = 0;
  while (i < nb_line)
    {
      j = 0;
      if ((map[i] = malloc(sizeof(char) * (nb_stick + 1))) == NULL)
	return (NULL);
      map[i][0] = '\0';
      while (j < nb_stick)
	{
	  my_strcat(map[i], "|");
	  j++;
	}
      i++;
      nb_stick += 2;
    }
  map[i] = NULL;
  return (map);
}

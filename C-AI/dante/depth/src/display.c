/*
** display.c for depth in /home/thibaut/Repository/dante/depth
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Sun May 14 18:55:51 2017 Thibaut Trouvé
** Last update Sun May 14 19:41:30 2017 Thibaut Trouvé
*/

#include <stdlib.h>
#include <unistd.h>
#include "depth.h"

static int	newline(t_maze *data, int *line, int *j)
{
  if (write(1, &data->str[*line * data->width], data->width) == -1)
    return (84);
  if (*line < data->height - 1)
    if (write(1, "\n", 1) == -1)
      return (84);
  (*line)++;
  *j = 0;
  return (0);
}

void	display_lab(t_maze *data)
{
  int	j;
  int	i;
  int	line;

  line = 0;
  i = 0;
  j = 0;
  while (i < data->height * data->width)
    {
      if (data->str[i] & WALL)
	data->str[i] = 'X';
      else if (data->str[i] & VISITED && data->str[i] & PATH)
	data->str[i] = 'o';
      else
	data->str[i] = '*';
      j++;
      if (j == data->width)
	{
	  if (newline(data, &line, &j) == 84)
	    return ;
	}
      i++;
    }
  free(data->str);
  free(data);
}

/*
** check_errors.c for depth in /home/thibaut/Repository/dante/depth
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Sun May 14 18:51:50 2017 Thibaut Trouvé
** Last update Sun May 14 19:41:04 2017 Thibaut Trouvé
*/

#include <stdio.h>
#include "depth.h"

int	check_invalid_char(t_maze *data)
{
  int	i;

  i = 0;
  while (i < data->width * data->height )
    {
      if (data->str[i] != '*' && data->str[i] != 'X')
	{
	  if (data->str[i] == '\0')
	    fprintf(stderr, "Invalid size\n");
	  else
	    fprintf(stderr, "Invalid character\n");
	  return (84);
	}
      i++;
    }
  return (0);
}

int	check_errors(t_maze *data)
{
  if (check_invalid_char(data) == 84)
    return (84);
  if (data->height <= 0 || data->width <= 0)
    return (84);
  return (0);
}

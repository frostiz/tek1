/*
** display.c for generation in /home/thibaut/Repository/dante/generator/src
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Sun May 14 20:10:18 2017 Thibaut Trouvé
** Last update Sun May 14 20:56:25 2017 Thibaut Trouvé
*/

#include <unistd.h>
#include "generator.h"

int	check_write(int *idx_buff, char buff[], int opt)
{
  if (opt == 0)
    {
      if (*idx_buff >= BUFF_SIZE)
	{
	  buff[*idx_buff] = '\0';
	  if (write(1, buff, *idx_buff) == -1)
	    return (-1);
	  *idx_buff = 0;
	}
    }
  else
    {
      if (*idx_buff < BUFF_SIZE)
	{
	  buff[*idx_buff] = '\0';
	  if (write(1, buff, *idx_buff) == -1)
	    return (-1);
	  *idx_buff = 0;
	}
    }
  return (0);
}

int	check_newline(int *i, t_maze *data, int *idx_buff, char buff[])
{
  if (*i != data->height - 1)
    {
      buff[*idx_buff] = '\n';
      (*idx_buff)++;
    }
  if (check_write(idx_buff, buff, 0) == -1)
    return (-1);
  return (0);
}

void	display_lab(t_maze *data)
{
  int	i;
  int	j;
  int	k;
  char	buff[BUFF_SIZE + 1];
  int	idx_buff;

  idx_buff = 0;
  k = 0;
  i = 0;
  while (i < data->height)
    {
      j = 0;
      while (j < data->width)
	{
	  buff[idx_buff++] = data->maze[k++];
	  if (check_write(&idx_buff, buff, 0) == -1)
	    return ;
	  j++;
	}
      if (check_newline(&i, data, &idx_buff, buff) == -1)
	return ;
      i++;
    }
  if (check_write(&idx_buff, buff, 1) == -1)
    return ;
}

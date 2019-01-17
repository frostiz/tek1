/*
** prepare_depth.c for depth in /home/thibaut/Repository/dante/depth
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Sun May 14 18:49:07 2017 Thibaut Trouvé
** Last update Sun May 14 19:36:20 2017 Thibaut Trouvé
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "depth.h"

int	get_size(t_maze *data, char *filename)
{
  FILE		*fd;
  int		i;
  char		*str;
  size_t	len;
  int		size;

  len = 0;
  str = NULL;
  i = 0;
  fd = fopen(filename, "r");
  if (fd == NULL)
    return (0);
  while ((size = getline(&str, &len, fd)) != -1)
    {
      i = i + size;
      data->height++;
      if (i == size)
	data->width = size - 1;
    }
  fclose(fd);
  free(str);
  return (i);
}

int		get_data(char *filename, t_maze *data)
{
  FILE		*fd;
  size_t	len;
  int		size;
  int		size_sum;
  char		*tmp;

  data->str = malloc(sizeof(char) * get_size(data, filename) + 1);
  if (data->str == NULL)
    return (84);
  fd = fopen(filename, "r");
  if (fd == NULL)
    return (84);
  data->str = memset(data->str, '\0', data->height * data->width);
  tmp = NULL;
  len = 0;
  size_sum = 0;
  while ((size = getline(&tmp, &len, fd)) != -1)
    {
      if (tmp[size - 1] == '\n')
	tmp[size - 1] = '\0';
      strcpy(&data->str[size_sum], tmp);
      size_sum += size - 1;
    }
  fclose(fd);
  return (0);
}

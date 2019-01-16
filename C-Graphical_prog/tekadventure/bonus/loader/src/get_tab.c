/*
** get_tab.c for loader in /home/frostiz/repository/tekadventure/bonus/loader
** 
** Made by thibaut trouve
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Sun May 28 18:23:55 2017 thibaut trouve
** Last update Sun May 28 18:41:58 2017 thibaut trouve
*/

#include <unistd.h>
#include <fcntl.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "tekadventure.h"

int	*get_int_tab(int *file, int index)
{
  int	*size;
  int	i;

  size = malloc(sizeof(int) * 4);
  if (size == NULL)
    return (NULL);
  i = 0;
  while (i < 4)
    {
      size[i] = file[index];
      i++;
      index++;
    }
  return (size);
}

int	get_file_size(char *file)
{
  int	fd;
  int	size;
  int	result;
  int	c;

  fd = open(file, O_RDONLY);
  if (fd == -1)
    return (-1);
  size = 1;
  result = 0;
  while (size != 0)
    {
      size = read(fd, &c, 1);
      if (size == -1)
	return (-1);
      result++;
    }
  close(fd);
  return (result);
}

int	*rev_int(int *size)
{
  int	*tmp;
  int	i;
  int	j;

  tmp = malloc(sizeof(int) * 4);
  if (tmp == NULL)
    return (NULL);
  i = 3;
  j = 0;
  while (j < 4)
    {
      tmp[j] = size[i];
      i--;
      j++;
    }
  return (tmp);
}

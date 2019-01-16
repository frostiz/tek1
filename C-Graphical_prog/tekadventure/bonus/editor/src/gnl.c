/*
** gnl.c for  in /home/Zarkkos/Delivery/C_Graphical_Prog/tekadventure/editor
**
** Made by Antoine Duez
** Login   <Zarkkos@epitech.net>
**
** Started on  Thu May 18 23:21:25 2017 Antoine Duez
** Last update Sat May 27 02:57:47 2017 Antoine Duez
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

static char	*my_ralloc(char *str)
{
  int		i;
  int		j;
  char		*new_str;

  i = 0;
  j = my_strlen(str);
  new_str = malloc(sizeof(char) * (j + 1) + 1);
  if (new_str == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      new_str[i] = str[i];
      i++;
    }
  new_str[i] = '\0';
  free(str);
  return (new_str);
}

char		*my_realloc(char *str, int size)
{
  int		i;
  char		*new;

  i = 0;
  new = malloc(sizeof(char) * (size));
  if (new == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      new[i] = str[i];
      i++;
    }
  new[i] = '\0';
  free(str);
  return (new);
}

char		*my_strcat(char *dest, char *str)
{
  int		i;
  int		j;

  i = 0;
  j = my_strlen(dest);
  dest = my_realloc(dest, (j + my_strlen(str) + 1));
  while (str[i] != '\0')
    {
      dest[j + i] = str[i];
      i++;
    }
  dest[i + j] = '\0';
  return (dest);
}

char		*get_next_line(int fd)
{
  char		buffer[2];
  int		readed;
  static char	*str;

  readed = 1;
  str = malloc(sizeof(char) * 1);
  if (str == NULL)
    return (NULL);
  str[0] = '\0';
  if (read(fd, buffer, 1) == 0)
    return (NULL);
  buffer[1] = '\0';
  while (buffer[0] != '\n' && readed != 0)
    {
      str = my_strcat(str, buffer);
      str = my_ralloc(str);
      readed = read(fd, buffer, 1);
      buffer[1] = '\0';
    }
  return (str);
}

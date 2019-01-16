/*
** get_next_line.c for lemin in /home/thibaut/Repository/CPE_2016_Lemin
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Thu Apr 13 19:52:02 2017 Thibaut Trouvé
** Last update Sun Apr 30 19:10:11 2017 Vincent Roye
*/

#include <unistd.h>
#include "my.h"
#include "gnl.h"

char	*my_realloc(char *str, int size)
{
  char	*tmp;
  int	i;

  tmp = malloc(sizeof(char) * (my_strlen(str) + 1 + size));
  if (tmp == NULL)
    return (NULL);
  i = 0;
  while (str[i] != '\0')
    {
      tmp[i] = str[i];
      i++;
    }
  tmp[i] = '\0';
  free(str);
  return (tmp);
}

char	*finished(char *str, int i)
{
  str[i] = '\0';
  return (str);
}

char	*get_next_line(const int fd)
{
  char	buffer[2];
  char	*str;
  int	i;
  int	size;

  i = 0;
  str = malloc(sizeof(char) * 2);
  if (str == NULL)
    return (NULL);
  str[0] = '\0';
  while ((size = read(fd, buffer, 1)) > 0)
    {
      if (buffer[0] == '\n')
	return (finished(str, i));
      buffer[1] = '\0';
      str[i] = buffer[0];
      str[i + 1] = '\0';
      i++;
      str = my_realloc(str, 1);
    }
  str[i] = '\0';
  if (str[0] != '\0')
    return (str);
  free(str);
  return (NULL);
}

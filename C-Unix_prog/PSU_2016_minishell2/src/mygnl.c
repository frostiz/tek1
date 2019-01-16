/*
** mygnl.c for lemin in /home/thibaut/Repository/PSU_2016_minishell2
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Sun Apr 30 18:52:08 2017 Thibaut Trouvé
** Last update Wed May  3 05:50:55 2017 Thibaut Trouvé
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

char	*get_next_line(const int fd)
{
  char	buffer[2];
  char	*str;
  int	size;

  str = malloc(sizeof(char) * 2);
  if (str == NULL)
    return (NULL);
  str[0] = '\0';
  while ((size = read(fd, buffer, 1)) > 0)
    {
      if (buffer[0] == '\n')
	return (str);
      buffer[1] = '\0';
      str = my_realloc(str, (my_strlen(str) + 1 + 2));
      if (str == NULL)
	return (NULL);
      my_strcat(str, buffer);
    }
  if (str[0] != '\0')
    return (str);
  free(str);
  return (NULL);
}

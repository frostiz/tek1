/*
** check_error.c for check_error.c in /home/frostiz/wolf3d/bonus
**
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
**
** Started on  Thu Jan 12 18:24:43 2017 thibaut trouve
** Last update Mon Jan 23 09:17:46 2017 thibaut trouve
*/

#include "my.h"

int	check_error(t_map data, char **argv)
{
  int	i;
  int	fd;
  char	buffer[100000];

  (void)data;
  fd = open(argv[1], O_RDONLY);
  i = 0;
  buffer[read(fd, buffer, 100000)] = '\0';
  while (buffer[i] != '\0')
    {
      if (buffer[i] != '0' && buffer[i] != '1' && buffer[i] != '\n'
	  && buffer[i] != '\0')
	{
	  printf("Invalid  map\n");
	  exit(84);
	}
      i++;
    }
  return (0);
}

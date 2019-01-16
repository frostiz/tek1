/*
** basic_functions.c for basic_functions.c in /home/frostiz/CPE_2016_BSQ
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Wed Dec 14 19:28:35 2016 thibaut trouve
** Last update Wed Dec 14 20:20:04 2016 thibaut trouve
*/

#include "my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_strlen(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

int	lign_lenght(char *str)
{
  int   i;

  i = beginning_of_file(str);
  while (str[i] != '\0')
    {
      if (str[i] == '\n')
	return (i - beginning_of_file(str));
      i++;
    }
  return (0);
}

int	beginning_of_file(char *buffer)
{
  int   i;

  i = 0;
  while (buffer[i] != '\0')
    {
      if (buffer[i] == 'o' || buffer[i] == '.')
	return (i);
      i++;
    }
  return (0);
}

int	beginning(char **argv)
{
  int   i;
  int   fd;
  char  buffer[100000];

  fd = open(argv[1], O_RDONLY);
  read(fd, buffer, 100000);
  i = 0;
  while (buffer[i] != '\0')
    {
      if (buffer[i] == 'o' || buffer[i] == '.')
	return (i);
      i++;
    }
  close(fd);
  return (0);
}

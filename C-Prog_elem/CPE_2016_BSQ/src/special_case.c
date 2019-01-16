/*
** special_case.c for special_case.c in /home/frostiz/CPE_2016_BSQ
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Wed Dec 14 19:35:12 2016 thibaut trouve
** Last update Sun Dec 18 16:56:05 2016 thibaut trouve
*/

#include "my.h"

int	size_one(char *str)
{
  if (str[0] == '.')
    my_putchar('x');
  else
    my_putchar('o');
  my_putchar('\n');
  exit(0);
}

int	map_one_column(char **argv)
{
  int   i;
  int   fd;
  char  buffer[BUF_SIZE];
  int   done;

  done = 0;
  fd = open(argv[1], O_RDONLY);
  i = 0;
  read(fd, buffer, beginning(argv));
  read(fd, buffer, BUF_SIZE);
  while (buffer[i] != '\0')
    {
      if (buffer[i] == '.' && done == 0)
	{
	  my_putchar('x');
	  done = 1;
	}
      else
	my_putchar(buffer[i]);
      i++;
    }
  close(fd);
  exit(0);
}

int	check_filled(char **tab)
{
  int   i;
  int   j;

  i = 0;
  j = 0;
  while (tab[i] != NULL)
    {
      while (tab[i][j] != '\0')
	{
	  if (tab[i][j] != 'o')
	    return (0);
	  j++;
	}
      j = 0;
      i++;
    }
  return (1);
}

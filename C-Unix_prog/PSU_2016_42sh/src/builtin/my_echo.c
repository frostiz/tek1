/*
** my_echo.c for 42sh in /home/Lucas/delivery/PSU/PSU_2016_42sh
**
** Made by Lucas Dumy
** Login   <lucas.dumy@epitech.eu>
**
** Started on  Mon May 15 14:06:35 2017 Lucas Dumy
** Last update Thu May 18 20:48:24 2017 Lucas Dumy
*/

#include	<stdlib.h>
#include	<stdbool.h>
#include	<string.h>
#include	"mysh.h"

void		my_echo(char **tab, __attribute__ ((unused)) char ***env,
			int *return_value, __attribute__ ((unused)) int *fd)
{
  unsigned int	i;
  bool		carriage_return;

  i = 1;
  carriage_return = true;
  if (tab[1] != NULL && strcmp(tab[1], "-n") == 0)
    {
      carriage_return = false;
      i++;
    }
  while (tab[i] != NULL)
    {
      my_putstr(tab[i]);
      i++;
      if (tab[i] != NULL)
	my_putstr(" ");
    }
  if (carriage_return == true)
    my_putstr("\n");
  *return_value = 0;
}

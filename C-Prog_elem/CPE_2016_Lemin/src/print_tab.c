/*
** print_tab.c for print_tab.c in /home/roye_v/delivery/CPE_2016/CPE_2016_Lemin
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Thu Apr 13 20:25:38 2017 Vincent Roye
** Last update Sat Apr 22 21:06:36 2017 Vincent Roye
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

void	print_tab(char **stock)
{
  int	line;

  line = 0;
  while (stock[line] != NULL)
    {
      my_printf("[%d] = %s\n", line, stock[line]);
      line++;
    }
}

void	my_putchar_e(char c)
{
  write(2, &c, 1);
}

void	my_put_error(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar_e(str[i]);
      i++;
    }
}

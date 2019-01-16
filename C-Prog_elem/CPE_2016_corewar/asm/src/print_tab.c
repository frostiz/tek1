/*
** print_tab.c for print_tab.c in /home/roye_v/delivery/CPE_2016/CPE_2016_corewar
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Tue Mar 28 20:19:00 2017 Vincent Roye
** Last update Tue Mar 28 20:20:39 2017 Vincent Roye
*/

#include <stdlib.h>
#include "my.h"

void	print_tab(char **stock)
{
  int	i;

  i = 0;
  while (stock[i] != NULL)
    {
      my_printf("stock[%d] = %s\n", i, stock[i]);
      i++;
    }
}

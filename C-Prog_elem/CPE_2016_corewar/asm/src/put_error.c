/*
** put_error.c for put_error.c in /home/roye_v/delivery/CPE_2016/CPE_2016_corewar
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sun Apr  2 10:36:48 2017 Vincent Roye
** Last update Sun Apr  2 10:39:16 2017 Vincent Roye
*/

#include <unistd.h>
#include <stdlib.h>
#include "asm.h"

void		my_put_err(char c)
{
  write(2, &c, 1);
}

void		my_put_error(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      my_put_err(str[i]);
      i++;
    }
}

void		my_error_exit(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      my_put_err(str[i]);
      i++;
    }
  exit(84);
}

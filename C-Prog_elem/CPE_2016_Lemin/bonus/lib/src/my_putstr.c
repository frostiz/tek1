/*
** my_putstr.c for my_putstr.c in /home/roye_v/delivery/PSU_2016_minishell1
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Fri Jan 13 21:35:05 2017 Vincent Roye
** Last update Sun Apr  9 18:06:27 2017 Vincent Roye
*/

#include "my.h"

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
}

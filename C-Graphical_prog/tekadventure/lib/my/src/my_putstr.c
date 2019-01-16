/*
** my_putstr.c for my_putstr.c in /home/roye_v/delivery
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Thu Oct  6 17:56:39 2016 Vincent Roye
** Last update Sat Feb 11 18:36:46 2017 Vincent Roye
*/

#include <unistd.h>
#include <stdlib.h>
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

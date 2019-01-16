/*
** my_putchar.c for my_putchar.c in /home/roye_v/delivery/my_lib
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sat Feb 11 13:59:14 2017 Vincent Roye
** Last update Sat Feb 11 18:35:41 2017 Vincent Roye
*/

#include <unistd.h>
#include "my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

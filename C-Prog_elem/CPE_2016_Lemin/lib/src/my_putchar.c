/*
** my_putchar.c for my_putchar.c in /home/roye_v/delivery/PSU_2016/PSU_2016_minishell2
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sun Apr  9 17:50:12 2017 Vincent Roye
** Last update Sun Apr  9 18:06:04 2017 Vincent Roye
*/

#include <unistd.h>
#include "my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

/*
** my_strlen.c for my_strlen.c in /home/roye_v/delivery/my_lib
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sat Feb 11 14:00:08 2017 Vincent Roye
** Last update Sat Feb 11 18:37:00 2017 Vincent Roye
*/

#include "my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

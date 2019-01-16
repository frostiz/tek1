/*
** my_strlen.c for my_strlen.c in /home/roye_v/delivery/CPE_2016_n4s
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Fri Jun  2 14:56:51 2017 Vincent Roye
** Last update Fri Jun  2 14:58:38 2017 Vincent Roye
*/

#include	"n4s.h"

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

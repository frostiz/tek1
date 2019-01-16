/*
** my_getnbr.c for get nbr in /home/H3r3zy/rendu/CPool_Day04
** 
** Made by Lucas Sahel
** Login   <H3r3zy@epitech.net>
** 
** Started on  Thu Oct  6 16:20:15 2016 Lucas Sahel
** Last update Fri Feb 17 08:34:31 2017 Sahel
*/

#include "basic.h"

static int	my_nblen(char *str)
{
  int		len;

  len = 0;
  while (str[len] && str[len] >= '0' && str[len] <= '9')
    len++;
  return (len);
}

int	getnbr_(char *str)
{
  int	nbr;
  int	p;
  int	str_i;

  nbr = 0;
  p = 0;
  str_i = 0;
  while (str[str_i] && (str[str_i] == '+' || str[str_i] == '-'))
    {
      if (str[str_i] == '-')
	p++;
      str_i++;
    }
  while (str[str_i] && str[str_i] >= '0' && str[str_i] <= '9')
    {
      nbr += (str[str_i] - 48) * power_(10, my_nblen(&str[str_i]) - 1);
      str_i++;
    }
  if (p % 2 == 1)
    nbr *= -1;
  return (nbr);
}

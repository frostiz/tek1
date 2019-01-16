/*
** my_put_nbr.c for my_put_nbr.c in /home/roye_v/delivery/CPool_Day03
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Tue Oct 11 09:23:33 2016 Vincent Roye
** Last update Sat Feb 11 18:37:19 2017 Vincent Roye
*/

#include <unistd.h>
#include "my.h"

int	my_put_nbr(int nb)
{
  int	j;

  j = 1;
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  if (nb >= 0)
    {
      if (nb >= 10)
	{
	  j = (nb % 10);
	  nb = (nb - j) / 10;
	  my_put_nbr(nb);
	  my_putchar(j + 48);
	}
      else
	my_putchar((nb % 10) + 48);
    }
  return (nb);
}

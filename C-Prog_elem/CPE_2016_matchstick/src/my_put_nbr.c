/*
** my_put_nbr.c for my_put_nbr.c in /home/frostiz/CPool_Day03
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Thu Oct  6 12:34:07 2016 thibaut trouve
** Last update Tue Feb 14 15:01:00 2017 
*/

#include "my.h"

int	my_put_nbr(int nb)
{
  int	rest_nb;

  if (nb < 0)
    {
      nb = nb * (-1);
      my_putchar('-');
    }
  if (nb >= 0)
    {
      if (nb >= 10)
	{
	  rest_nb = nb % 10;
	  nb = (nb - rest_nb) / 10;
	  my_put_nbr(nb);
	  my_putchar(rest_nb + 48);
	}
      else
	my_putchar(48 + nb % 10);
    }
}

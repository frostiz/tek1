/*
** basic_functions.c for basic_functions.c in /home/frostiz/bootstrap_printf
**
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
**
** Started on  Wed Nov  9 10:59:50 2016 thibaut trouve
** Last update Sun Jan 22 19:17:04 2017 thibaut trouve
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
  return (0);
}

int	my_put_nbr_unsigned(unsigned int nb)
{
  int   rest_nb;

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
  return (0);
}

/*
** my_put_unsigned.c for my_put_unsigned.c in /home/roye_v/delivery/PSU_2016_my_printf
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Tue Nov 15 16:28:21 2016 Vincent Roye
** Last update Sat Feb 11 19:32:42 2017 Vincent Roye
*/

#include "my.h"

int	my_put_unsigned(unsigned int nb)
{
  unsigned int	j;

  j = 1;
  if (nb > 0)
    {
      if (nb >= 10)
	{
	  j = (nb % 10);
	  nb = (nb - j) / 10;
	  my_put_nbr(nb);
	  my_putchar(j + '0');
	}
      else
	my_putchar((nb%10) + '0');
    }
  return (nb);
}

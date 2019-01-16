/*
** my_putnbr.c for  in /home/sahel/bin/lib/src
** 
** Made by Sahel
** Login   <sahel.lucas-saoudi@epitech.eu@epitech.net>
** 
** Started on  Fri Feb 17 08:14:40 2017 Sahel
** Last update Fri Feb 17 08:31:57 2017 Sahel
*/

#include "basic.h"

static void	print_number(long int nb)
{
  if (nb >= 1)
    {
      print_number((nb / 10));
      putchar_((nb % 10) + 48);
    }
}

void		putnbr_(int nb)
{
  long int	long_nb;

  long_nb = nb;
  if (long_nb < 0)
    {
      putchar_('-');
      print_number((long_nb * -1));
    }
  else if (long_nb == 0)
    putchar_(long_nb + 48);
  else
    print_number(long_nb);
}

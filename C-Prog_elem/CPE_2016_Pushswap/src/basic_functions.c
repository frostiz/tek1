/*
** my_getnbr.c for my_getnbr.c in /home/frostiz/CPE_2016_Pushswap
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Mon Nov 21 17:17:52 2016 thibaut trouve
** Last update Sun Nov 27 23:07:20 2016 thibaut trouve
*/

#include "my.h"

int	*stock_arguments_in_list(int size, char **argv)
{
  int   *list_a;
  int   i;

  i = 1;
  list_a = malloc(sizeof(int) * size + 1);
  if (list_a == NULL)
    return (NULL);
  while (argv[i] != NULL)
    {
      list_a[i - 1] = my_getnbr(argv[i]);
      i++;
    }
  return (list_a);
}

int	my_getnbr(char *str)
{
  int	nbr;
  int	neg;
  int	i;

  neg = 1;
  i = 0;
  nbr = 0;
  while (str[i] != '\0')
    {
      while ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
	{
	  if (str[i] == '-')
	    neg = neg * (-1);
	  if (str[i] >= '0' && str[i] <= '9')
	      nbr = (str[i] - 48) + (10 * nbr);
	  i++;
	}
      if (str[i] < '0' || str[i] > '9')
	{
	  nbr = nbr * neg;
	  return (nbr);
	}
      i++;
    }
  return (nbr);
}

void	my_putchar(char c)
{
  write (1, &c, 1);
}

void	my_putstr(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
}

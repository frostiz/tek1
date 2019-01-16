/*
** basic_functions.c for basic_functions.c in /home/frostiz/bootstrap_printf
**
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
**
** Started on  Wed Nov  9 10:59:50 2016 thibaut trouve
** Last update Sun Nov 20 22:01:11 2016 thibaut trouve
*/

#include <unistd.h>

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      i++;
    }
  return (i);
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
}

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

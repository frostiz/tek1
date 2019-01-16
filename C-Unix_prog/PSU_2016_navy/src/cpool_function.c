/*
** cpool_function.c for Navy in /home/thibaut/Repository/PSU_2016_navy
** 
** Made by 
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Tue Jan 31 12:35:24 2017 
** Last update Sun Feb 19 18:32:07 2017 
*/

#include "my.h"

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

int	my_put_nbr_calc(int nb, int rest_nb)
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
  return (0);
}

int	my_put_nbr(int nb)
{
  int	rest_nb;

  rest_nb = 0;
  if (nb < 0)
    {
      nb = nb * (-1);
      my_putchar('-');
    }
  if (nb >= 0)
    {
      my_put_nbr_calc(nb, rest_nb);
    }
  return (0);
}

char	*my_revstr(char *str)
{
  int	i;
  int	strlen;
  char	temp;

  i = 0;
  strlen = my_strlen(str) - 1;
  while (strlen > i)
    {
      temp = str[i];
      str[i] = str[strlen];
      str[strlen] = temp;
      i++;
      strlen--;
    }
  return (str);
}

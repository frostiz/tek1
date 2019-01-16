/*
** convert_base.c for convert_base.c in /home/frostiz/travail/convert_base
**
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
**
** Started on  Fri Nov 11 20:20:33 2016 thibaut trouve
** Last update Sun Nov 20 22:01:36 2016 thibaut trouve
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int	my_getnbr_modified(char *str, int j)
{
  int	nbr;
  int	i;
  int	neg;

  neg = 1;
  i = j;
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

char	*convert_dec_to_all(int nb, char *base)
{
  int   j;
  char	*result;

  j = 0;
  result = malloc(sizeof(char) * (nb + my_strlen(base)));
  if (result == NULL)
    return (NULL);
  result[0] = (nb < my_strlen(base)) ? base[nb] : '\0';
  while (nb >= my_strlen(base))
    {
      if (nb / my_strlen(base) > my_strlen(base))
	{
	  result[j] = base[nb % my_strlen(base)];
	  j++;
	}
      else
	{
	  result[j] = base[nb % my_strlen(base)];
	  result[j + 1] = base[nb / my_strlen(base)];
	  j++;
	}
      nb = nb / my_strlen(base);
    }
  my_revstr(result);
  return (result);
}

char	*convert_dec_to_all2(unsigned long int nb, char *base)
{
  int   j;
  char  *result;

  j = 0;
  result = malloc(sizeof(char));
  if (result == NULL)
    return (NULL);
  result[0] = (nb < my_strlen(base)) ? base[nb] : '\0';
  while (nb >= my_strlen(base))
    {
      if (nb / my_strlen(base) > my_strlen(base))
	{
	  result[j] = base[nb % my_strlen(base)];
	  j++;
	}
      else
	{
	  result[j] = base[nb % my_strlen(base)];
	  result[j + 1] = base[nb / my_strlen(base)];
	  j++;
	}
      nb = nb / my_strlen(base);
    }
  my_revstr(result);
  return (result);
}

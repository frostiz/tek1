/*
** my_getnbr.c for my_getnbr.c in /home/frostiz/CPool_Day04
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Fri Oct  7 18:50:53 2016 thibaut trouve
** Last update Mon Feb 13 09:29:33 2017 
*/

#include <stdlib.h>

int	my_getnbr(char *str)
{
  int	i;
  int	result;
  int	neg;

  neg = 1;
  i = 0;
  result = 0;
  if (str == NULL)
    return (0);
  while (str[i] != '\0')
    {
      while (str[i] == '-')
	{
	  neg *= -1;
	  i++;
	}
      if (str[i] >= '0' && str[i] <= '9')
	{
	  while (str[i] >= '0' && str[i] <= '9')
	    result = result * 10 + str[i++] - 48;
	  return (neg * result);
	}
      i++;
    }
  return (neg * result);
}

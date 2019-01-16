/*
** my_put_binary.c for my_put_binary.c in /home/roye_v/delivery/PSU_2016_my_printf
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Tue Nov 15 16:59:56 2016 Vincent Roye
** Last update Mon Mar 20 20:23:53 2017 Vincent Roye
*/

#include <stdlib.h>
#include "my.h"

int	my_putstrb(char *str)
{
  int	i;

  i = 0;
  while (str[0] == '0' && str[1] != '\0')
    {
      while (str[i] != '\0')
	{
	  str[i] = str[i + 1];
	  i++;
	}
    }
  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
  return (0);
}

char		*my_put_binary(unsigned int i)
{
  t_puthexa	hexa;

  hexa.l = 0;
  if ((hexa.m = malloc(sizeof(char *) * i + 1)) == NULL)
    return (NULL);
  if (i == 0)
    my_putchar('0');
  while (i > 0)
    {
      if (i % 2 > 9)
	{
	  hexa.m[hexa.l] = (i % 2 + 55);
	  hexa.l++;
	}
      else
	{
	  hexa.m[hexa.l] = (i % 2 + 48);
	  hexa.l++;
	}
      i = (i / 2);
      hexa.m[hexa.l] = i + 48;
    }
  my_revstr(hexa.m);
  my_putstrb(hexa.m);
  return (hexa.m);
}

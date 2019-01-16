/*
** my_pur_hexa.c for my_put_hexa.c in /home/roye_v/delivery/PSU_2016_my_printf
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sat Nov 12 15:38:17 2016 Vincent Roye
** Last update Thu Nov 17 19:33:49 2016 Vincent Roye
*/

#include <stdlib.h>
#include "my.h"

int	my_putstrn(char *str)
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

char		*my_put_octale(unsigned int i)
{
  t_puthexa	hexa;

  hexa.l = 0;
  hexa.m = malloc(sizeof(char));
  if (i == 0)
    my_putchar('0');
  while (i > 0)
    {
      if (i % 8 > 9)
	{
	  hexa.m[hexa.l] = (i % 8 + 55);
	  hexa.l++;
	}
      else
	{
	  hexa.m[hexa.l] = (i % 8 + 48);
	  hexa.l++;
	}
      i = (i / 8);
      hexa.m[hexa.l] = i + 48;
    }
  my_revstr(hexa.m);
  my_putstrn(hexa.m);
  return (hexa.m);
}

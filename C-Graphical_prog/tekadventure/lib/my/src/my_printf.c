/*
** my_printf.c for my_printf.c in /home/roye_v/delivery/PSU_2021_my_printf_bootstrap
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Wed Nov  9 09:39:51 2016 Vincent Roye
** Last update Sat May 27 03:22:39 2017 Vincent Roye
*/

#include <stdio.h>
#include <stdarg.h>
#include "my.h"

int	check_flag(int i, const char *s, va_list ap)
{
  if (s[i] == 'c')
    my_putchar(va_arg(ap, int));
  if (s[i] == 's')
    my_putstr(va_arg(ap, char*));
  if (s[i] == 'd' || s[i] == 'i')
    my_put_nbr(va_arg(ap, int));
  if (s[i] == 'b')
    my_put_binary(va_arg(ap, int));
  if (s[i] == '%')
    my_putchar('%');
  return (0);
}

int		my_printf(const char *s, ...)
{
  va_list	ap;
  int		i;

  i = 0;
  va_start(ap, 0);
  while (s[i] != '\0')
    {
      if (s[i] == '%')
	{
	  i++;
	  check_flag(i, s, ap);
	}
      else
	my_putchar(s[i]);
      i++;
    }
  va_end(ap);
  return (0);
}

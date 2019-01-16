/*
** my_printf.c for my_printf.c in /home/frostiz/PSU_2016_my_printf
**
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
**
** Started on  Fri Nov 11 19:41:23 2016 thibaut trouve
** Last update Sun Nov 20 21:54:06 2016 thibaut trouve
*/

#include "my.h"

int	my_intlen(int nb)
{
  int	i;

  i = 0;
  if (nb < 0)
    i++;
  if (nb > 0)
    {
      i = 1;
      while (nb >= 10 || nb <= -10)
	{
	  nb /= 10;
	  i++;
	}
    }
  return (i);
}

void	print_next_value(char *format, int i, va_list print, int nb_after_pct)
{
  if (format[i] == 's')
    print_spaces_and_value_s(nb_after_pct, print);
  if ((format[i] == 'd' || format[i] == 'i') ||
      (format[i] == 'l' && format[i + 1] == 'd') ||
      (format[i] == 'h' && format[i + 1] == 'd'))
    print_spaces_and_value_dildhd(nb_after_pct, print);
  if (format[i] == 'c')
    print_spaces_and_value_c(nb_after_pct, print);
  if (format[i] == 'x')
    print_spaces_and_value_x(nb_after_pct, print);
  if (format[i] == 'X')
    print_spaces_and_value_X(nb_after_pct, print);
  if (format[i] == 'o')
    print_spaces_and_value_o(nb_after_pct, print);
  if (format[i] == 'p')
    print_spaces_and_value_p(nb_after_pct, print);
  if (format[i] == '%')
    my_putchar(format[i]);
  if (format[i] == 'u')
    print_spaces_and_value_u(nb_after_pct, print);
  if (format[i] == 'b')
    print_spaces_and_value_b(nb_after_pct, print);
  if (format[i] == 'S')
    print_spaces_and_value_S(nb_after_pct, print);
}

void	percent_found(char *format, int *i, int nb_after_pct, va_list print)
{
  if ((format[*i + 1] == 'l' && format[*i + 2] == 'd') ||
      (format[*i + 1] == 'h' && format[*i + 2] == 'd'))
    *i = *i + 1;
  if ((format[*i + 1] <= '9' && format[*i + 1] >= '0') ||
      (format[*i + 1] == '-'))
    number_after_pct(format, i, nb_after_pct, print);
  else if (format[*i + 1] == '#' && format[*i + 2] == ' ')
    dieze_after_pct(format, i, nb_after_pct, print);
  else if (format[*i + 1] == ' ')
    space_after_pct(format, i, nb_after_pct, print);
  else if (format[*i + 1] == '+')
    plus_after_pct(format, i, nb_after_pct, print);
  else
    print_next_value(format, *i + 1, print, nb_after_pct);
}

void	core_function(va_list print, char *format, int i)
{
  int	number_after_percent;

  number_after_percent = 0;
  i = 0;
  while (format[i] != '\0')
    {
      if (format[i] == '%')
	{
	  percent_found(format, &i, number_after_percent, print);
	  i = i + 1;
	}
      else
	my_putchar(format[i]);
      i = i + 1;
    }
}

int	my_printf(char *format, ...)
{
  va_list print;
  int	i;

  va_start(print, format);
  i = 0;
  core_function(print, format, i);
  va_end(print);
  return (0);
}

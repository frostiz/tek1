/*
** zprint_spaces_and_value3.c for zprint_spaces_and_value3.c in /home/frostiz/PSU_2016_my_printf
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Tue Nov 15 20:03:54 2016 thibaut trouve
** Last update Sun Nov 20 21:53:43 2016 thibaut trouve
*/

#include "my.h"

void	print_spaces_p2(int nb_after_pct, va_list print, char *tmp)
{
  if (nb_after_pct < 0)
    {
      my_putstr("0x");
      my_putstr(tmp);
      while (nb_after_pct + my_strlen(tmp) + 2 < 0)
	{
	  my_putchar(' ');
	  nb_after_pct++;
	}
    }
  else if (nb_after_pct > 0)
    {
      while (nb_after_pct > my_strlen(tmp) + 2)
	{
	  my_putchar(' ');
	  nb_after_pct--;
	}
      my_putstr("0x");
      my_putstr(tmp);
    }
  else
    {
      my_putstr("0x");
      my_putstr(tmp);
    }
}

void	number_after_pct(char *format, int *i, int nb_after_pct, va_list print)
{
      nb_after_pct = my_getnbr_modified(format, *i + 1);
      while ((format[*i + 1] <= '9' && format[*i + 1] >= '0') ||
	     (format[*i + 1] == '-'))
	*i = *i + 1;
      if ((format[*i] == 'l' && format[*i + 1] == 'd') ||
	  (format[*i] == 'h' && format[*i + 1] == 'd'))
	*i = *i + 1;
      print_next_value(format, *i + 1, print, nb_after_pct);
}

void	dieze_after_pct(char *format, int *i, int nb_after_pct, va_list print)
{
  (*i) += 2;
  my_putchar(' ');
  while (format[*i] == ' ')
    (*i)++;
  print_next_value(format, *i, print, nb_after_pct);
  *i = *i - 1;
}

void	space_after_pct(char *format, int *i, int nb_after_pct, va_list print)
{
  (*i)++;
  while (format[*i] == ' ')
    (*i)++;
  nb_after_pct = my_getnbr_modified(format, *i);
  while ((format[*i] <= '9' && format[*i] >= '0') || format[*i] == ' ')
    (*i)++;
  print_next_value(format, *i, print, nb_after_pct);
  (*i)--;
}

void	plus_after_pct(char *format, int *i, int nb_after_pct, va_list print)
{
  int	is_S;
  int	j;

  j = 0;
  is_S = 0;
  while (format[j] != '\0')
    {
      if (format[j] == 'S')
	is_S = 1;
      (j)++;
    }
  if (is_S == 1)
    {
      while (format[*i + 1] != 'S')
	(*i)++;
      print_next_value(format, *i + 1, print, nb_after_pct);
    }
}

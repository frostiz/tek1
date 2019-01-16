/*
** zprint_spaces_and_value2.c for zprint_spaces_and_value2.c in /home/frostiz/PSU_2016_my_printf
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Tue Nov 15 19:13:33 2016 thibaut trouve
** Last update Sun Nov 20 22:02:23 2016 thibaut trouve
*/

#include "my.h"

void	print_spaces_and_value_o(int number_after_percent, va_list print)
{
  char  *tmp;

  tmp = convert_dec_to_all2(va_arg(print, long int), "01234567");
  if (number_after_percent < 0)
    {
      my_putstr(tmp);
      while (number_after_percent + my_strlen(tmp) < 0)
	{
	  my_putchar(' ');
	  number_after_percent++;
	}
    }
  else if (number_after_percent > 0)
    {
      while (number_after_percent > my_strlen(tmp))
	{
	  my_putchar(' ');
	  number_after_percent--;
	}
      my_putstr(tmp);
    }
  else
    my_putstr(tmp);
}

void	print_spaces_and_value_u(int number_after_percent, va_list print)
{
  unsigned int   tmp;

  tmp = va_arg(print, unsigned int);
  if (number_after_percent < 0)
    {
      my_put_nbr_unsigned(tmp);
      while (number_after_percent + my_intlen(tmp) < 0)
	{
	  my_putchar(' ');
	  number_after_percent++;
	}
    }
  else if (number_after_percent > 0)
    {
      while (number_after_percent > my_intlen(tmp))
	{
	  my_putchar(' ');
	  number_after_percent--;
	}
      my_put_nbr_unsigned(tmp);
    }
  else
    my_put_nbr_unsigned(tmp);
}

void	print_spaces_and_value_p(int number_after_percent, va_list print)
{
  char			*tmp;
  unsigned long int	tmp2;

  tmp2 = va_arg(print, unsigned long int);
  tmp = convert_dec_to_all2(tmp2, "0123456789abcdef");
  if (tmp[0] == 0)
    my_putstr("(nil)");
  else
      print_spaces_p2(number_after_percent, print, tmp);
}

void	print_spaces_and_value_b(int number_after_percent, va_list print)
{
  char   *tmp;

  tmp = convert_dec_to_all2(va_arg(print, unsigned int), "01");
  if (number_after_percent < 0)
    {
      my_putstr(tmp);
      while (number_after_percent + my_strlen(tmp) < 0)
	{
	  my_putchar(' ');
	  number_after_percent++;
	}
    }
  else if (number_after_percent > 0)
    {
      while (number_after_percent > my_strlen(tmp))
	{
	  my_putchar(' ');
	  number_after_percent--;
	}
      my_putstr(tmp);
    }
  else
    my_putstr(tmp);
}

void	print_spaces_and_value_S(int number_after_percent, va_list print)
{
  char  *tmp;
  char  *tmp2;
  int   i;

  i = 0;
  tmp = va_arg(print, char *);
  while (tmp[i] != '\0')
    {
      if (tmp[i] >= 32 && tmp[i] < 127)
	my_putchar(tmp[i]);
      else
	{
	  tmp2 = convert_dec_to_all2(tmp[i], "01234567");
	  my_putchar('\\');
	  if (my_strlen(tmp2) == 1)
	    my_putstr("00");
	  else if (my_strlen(tmp2) == 2)
	    my_putchar('0');
	  my_putstr(tmp2);
	}
      i++;
    }
}

/*
** zprint_spaces_and_value.c for zprint_spaces_and_value.c in /home/frostiz/PSU_2016_my_printf
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Tue Nov 15 19:14:09 2016 thibaut trouve
** Last update Sun Nov 20 22:03:15 2016 thibaut trouve
*/

#include "my.h"

void	print_spaces_and_value_dildhd(int number_after_percent, va_list print)
{
  int   tmp;

  tmp = va_arg(print, int);
  if (number_after_percent < 0)
    {
      my_put_nbr(tmp);
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
      my_put_nbr(tmp);
    }
  else
    my_put_nbr(tmp);
}

void	print_spaces_and_value_s(int number_after_percent, va_list print)
{
  char  *tmp;

  tmp = va_arg(print, char*);
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

void	print_spaces_and_value_c(int number_after_percent, va_list print)
{
  char  tmp;

  tmp = va_arg(print, int);
  if (number_after_percent < 0)
    {
      my_putchar(tmp);
      while (number_after_percent + 1 < 0)
	{
	  my_putchar(' ');
	  number_after_percent++;
	}
    }
  else if (number_after_percent > 0)
    {
      while (number_after_percent > 1)
	{
	  my_putchar(' ');
	  number_after_percent--;
	}
      my_putchar(tmp);
    }
  else
    my_putchar(tmp);
}

void	print_spaces_and_value_x(int number_after_percent, va_list print)
{
  char  *tmp;

  tmp = convert_dec_to_all2(va_arg(print, unsigned int), "0123456789abcdef");
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

void	print_spaces_and_value_X(int number_after_percent, va_list print)
{
  char  *tmp;

  tmp = convert_dec_to_all2(va_arg(print, unsigned int), "0123456789ABCDEF");
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

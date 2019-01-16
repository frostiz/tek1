/*
** my.h for my.h in /home/frostiz/PSU_2016_my_printf_bootstrap
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Wed Nov  9 11:32:59 2016 thibaut trouve
** Last update Sun Nov 20 21:56:02 2016 thibaut trouve
*/

#ifndef MY_H_
#define MY_H_

#include <stdarg.h>

void	my_putchar(char);
int	my_strlen(char *);
int	my_put_nbr(int);
void	my_putstr(char *);
char	*convert_dec_to_all(int, char *);
char	*convert_dec_to_all2(unsigned long int, char *);
int	my_put_nbr_unsigned(unsigned int);
int	my_getnbr_modified(char *, int);
void	print_spaces_and_value_dildhd(int, va_list);
void	print_spaces_and_value_c(int, va_list);
void	print_spaces_and_value_s(int, va_list);
void	print_spaces_and_value_x(int, va_list);
void	print_spaces_and_value_X(int, va_list);
void	print_spaces_and_value_o(int, va_list);
void	print_spaces_and_value_b(int, va_list);
void	print_spaces_and_value_S(int, va_list);
void	print_spaces_and_value_u(int, va_list);
void	print_spaces_and_value_p(int, va_list);
void    print_spaces_p2(int, va_list, char *);
int	my_intlen(int);
void	number_after_pct(char *, int *, int, va_list);
void	dieze_after_pct(char *, int *, int, va_list);
void	plus_after_pct(char *, int *, int, va_list);
void	space_after_pct(char *, int *, int, va_list);
void	print_next_value(char *, int, va_list, int);
#endif

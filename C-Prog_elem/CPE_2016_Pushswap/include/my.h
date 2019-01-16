/*
** my.h for my.h in /home/frostiz/PSU_2016_my_printf_bootstrap
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Wed Nov  9 11:32:59 2016 thibaut trouve
** Last update Sat Nov 26 11:02:29 2016 thibaut trouve
*/

#ifndef MY_H_
#define MY_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_lists
{
  int	*list_a;
  int	*list_b;
  int	size_list_a;
  int	size_list_b;
}	t_lists;

int	my_getnbr(char *);
void	rotate_left(int *, int);
void	rotate_right(int *, int);
void    shift_right(int *, int);
void    shift_left(int *, int);
void    push_elem(int *, int *, int *, int *);
t_lists	push_a_to_b(t_lists);
t_lists	push_b_to_a(t_lists);
int     *stock_arguments_in_list(int, char **);
void	my_putchar(char);
void	my_putstr(char *);
int     verif_sorted(int *, int);
int     search_smaller(int *, int, int *);
int     is_sorted(int *, int);
void    core_func(t_lists);
void	pushswap(t_lists , char **);
#endif

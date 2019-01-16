/*
** error_with_coredump.c for minishell2 in /home/thibaut/Repository/PSU_2016_minishell2
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Fri Apr  7 16:55:41 2017 Thibaut Trouvé
** Last update Sat Apr  8 18:55:48 2017 Thibaut Trouvé
*/

#include "my.h"
#include "main.h"

void	ill_with(int *wstatus)
{
  (void)wstatus;
  my_putstr("Illegal instruction (core dumped)\n");
}

void	abort_with(int *wstatus)
{
  (void)wstatus;
  my_putstr("Aborted (core dumped)\n");
}

void	bus_with(int *wstatus)
{
  (void)wstatus;
  my_putstr("Bus error (core dumped)\n");
}

void	float_with(int *wstatus)
{
  (void)wstatus;
  my_putstr("Floating exception (core dumped)\n");
}

void	seg_with(int *wstatus)
{
  (void)wstatus;
  my_putstr("Segmentation fault (core dumped)\n");
}

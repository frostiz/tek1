/*
** error_without_coredump.c for minishell2 in /home/thibaut/Repository/PSU_2016_minishell2
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Fri Apr  7 16:51:40 2017 Thibaut Trouvé
** Last update Sat Apr  8 18:58:14 2017 Thibaut Trouvé
*/

#include "my.h"
#include "main.h"

void	seg_without(int *wstatus)
{
  *wstatus = 139;
  my_putstr("Segmentation fault\n");
}

void	float_without(int *wstatus)
{
  *wstatus = 136;
  my_putstr("Floating exception\n");
}

void	bus_without(int *wstatus)
{
  *wstatus = 135;
  my_putstr("Bus error\n");
}

void	abort_without(int *wstatus)
{
  *wstatus = 134;
  my_putstr("Aborted\n");
}

void	ill_without(int *wstatus)
{
  *wstatus = 132;
  my_putstr("Illegal instruction\n");
}

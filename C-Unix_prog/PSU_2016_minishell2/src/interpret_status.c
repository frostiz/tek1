/*
** interpret_status.c for minishell2 in /home/thibaut/Repository/PSU_2016_minishell2
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Wed Apr  5 22:43:29 2017 Thibaut Trouvé
** Last update Sun Apr  9 18:13:38 2017 thibaut trouve
*/

#include "my.h"
#include "main.h"

void	interpret_status(int *wstatus)
{
  void	(*error[10])(int *);
  int	status[10] = {4, 6, 7, 8, 11, 132, 134, 135, 136, 139};
  int	i;

  error[0] = ill_without;
  error[1] = abort_without;
  error[2] = bus_without;
  error[3] = float_without;
  error[4] = seg_without;
  error[5] = ill_with;
  error[6] = abort_with;
  error[7] = bus_with;
  error[8] = float_with;
  error[9] = seg_with;
  i = 0;
  while (i < 10)
    {
      if (status[i] == *wstatus)
	{
	  error[i](wstatus);
	  return ;
	}
      i++;
    }
}

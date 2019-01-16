/*
** wait_all.c for 42sh in /home/Lucas/delivery/PSU/PSU_2016_42sh
**
** Made by Lucas Dumy
** Login   <lucas.dumy@epitech.eu>
**
** Started on  Tue May 16 23:24:34 2017 Lucas Dumy
** Last update Sun May 21 12:38:45 2017 bastien bedu
*/

#include	<sys/types.h>
#include	<sys/wait.h>
#include	<stdlib.h>
#include	"exec.h"

int		*create_value(int value)
{
  int		*ret;

  ret = malloc(sizeof(int) * 3);
  if (ret == NULL)
    return (NULL);
  ret[0] = 0;
  ret[1] = value;
  ret[2] = -1;
  return (ret);
}

int		value_return(int *list, int i)
{
  int		status;

  status = 1;
  if (list[i] == 1)
    {
      waitpid(list[i + 1], &status, 0);
      return (signal_handle(status, list[i + 2]));
    }
  else if (list[i] == 0)
    return (list[i + 1]);
  return (1);
}

int		*wait_all(int *list)
{
  int		status;
  int		real_ret;
  int		i;

  if (list == NULL)
    return (NULL);
  i = 0;
  while (list[i] != -1)
    i++;
  i -= 2;
  real_ret = 0;
  while (i >= 0)
    {
      status = value_return(list, i);
      if (list[i + 2] != - 1 && status < 0 && real_ret == 0)
	real_ret = status * -1 - 2;
      if (real_ret == 0 && status != 0)
	real_ret = status;
      i -= 2;
    }
  free(list);
  return (create_value(real_ret));
}

/*
** repeat.c for  in /home/bastien/delivery/PSU/PSU_2016_42sh/src
** 
** Made by bastien bedu
** Login   <bastien.bedu@epitech.eu>
** 
** Started on  Sat May 20 17:37:50 2017 bastien bedu
** Last update Sun May 21 10:58:59 2017 bastien bedu
*/

#include	<stdlib.h>
#include	<string.h>
#include	<sys/types.h>
#include	<sys/wait.h>
#include	"exec.h"

void		parse_built(char **args, char ***env, int *return_value, int *fd)
{
  if (args == NULL || args[0] == NULL)
    {
      *return_value = 1;
      my_perror("if: Empty if.\n");
    }
  else if (check_builtin(args, fd, env, return_value) == 0);
  else
    {
      *return_value = execute_command(args, fd, *env, strdup(args[0]));
      if (*return_value > 0)
	{
	  waitpid(*return_value, return_value, 0);
	  *return_value = signal_handle(*return_value, -1);
	}
      else
	*return_value = 1;
    }
}

void		repeat(char **args, char ***env, int *return_value, int *fd)
{
  int		nb;

  if (my_tablen(args) < 3)
    {
      my_perror("repeat: Too few arguments.\n");
      *return_value = 1;
      return ;
    }
  if (is_int(args[1]) == 1)
    nb = atoi(args[1]);
  else
    {
      my_perror("repeat: Badly formed number.\n");
      *return_value = 1;
      return ;
    }
  while (nb > 0)
    {
      parse_built(&args[2], env, return_value, fd);
      nb--;
    }
}

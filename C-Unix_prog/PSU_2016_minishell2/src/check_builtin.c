/*
** check_builtin.c for minishell2.c in /home/thibaut/Repository/PSU_2016_minishell2
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Wed Apr  5 23:00:15 2017 Thibaut Trouvé
** Last update Tue May  2 17:21:40 2017 Thibaut Trouvé
*/

#include <stdlib.h>
#include "main.h"
#include "my.h"

int	check_builtin(char **args)
{
  char	*builtins[6];
  int	i;
  int	found;

  builtins[0] = "env";
  builtins[1] = "setenv";
  builtins[2] = "unsetenv";
  builtins[3] = "cd";
  builtins[4] = "exit";
  builtins[5] = NULL;
  found = 1;
  i = 0;
  while (builtins[i] != NULL)
    {
      found = my_strcmp(args[0], builtins[i]);
      if (found == 0)
	return (i);
      i++;
    }
  return (-1);
}

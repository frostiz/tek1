/*
** interpret_path.c for minishell2 in /home/thibaut/Repository/PSU_2016_minishell2
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Sun Apr  9 16:31:36 2017 Thibaut Trouvé
** Last update Tue May  2 11:18:40 2017 Thibaut Trouvé
*/

#include <stdlib.h>
#include "my.h"
#include "main.h"

int	no_right(char *path)
{
  if (access(path, F_OK) == 0 && access(path, X_OK) == -1)
    return (1);
  return (0);
}

int	interpret_path(char *found_path, t_tab **data, char **arg)
{
  int	builtin;

  if (found_path == NULL)
    {
      builtin = check_builtin(arg);
      if (builtin >= 0)
	{
	  exec_builtin(builtin, arg, data);
	  return (1);
	}
      my_putstr(arg[0]);
      my_putstr(": Command not found.\n");
      (*data)->exit_value = 1;
      return (1);
    }
  if (is_dir(found_path) == 1 || no_right(found_path) == 1)
    {
      my_putstr(found_path);
      my_putstr(": Permission denied.\n");
      (*data)->exit_value = 1;
      return (1);
    }
  return (0);
}

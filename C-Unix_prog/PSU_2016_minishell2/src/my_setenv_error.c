/*
** my_setenv_error.c for minishell2 in /home/frostiz/Backup/minishell2
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Sun Apr  9 17:21:14 2017 thibaut trouve
** Last update Tue May  2 10:22:34 2017 Thibaut Trouvé
*/

#include <stdlib.h>
#include "main.h"
#include "my.h"

static int	count_args(char **args)
{
  int	i;

  i = 0;
  while (args[i] != NULL && is_in(args[i][0], ";<>|") == 0)
    i++;
  return (i - 1);
}

static int	check_name_validity(char **args)
{
  int	i;

  i = 0;
  if ((args[1][0] < 'A' || args[1][0] > 'Z') &&
      (args[1][0] < 'a' || args[1][0] > 'z') && args[1][0] != '_')
    return (-1);
  while (args[1][i] != '\0')
    {
      if (is_alphanum(args[1][i]) == 0 && args[1][i] != '_')
	return (-2);
      i++;
    }
  return (0);
}

static int	interpret_validity(int validity)
{
  if (validity == -1)
    {
      my_putstr("setenv: Variable name must begin with a letter.\n");
      return (-1);
    }
  else if (validity == -2)
    {
      my_putstr("setenv: Variable name must\
 contain alphanumeric characters.\n");
      return (-1);
    }
  return (0);
}

int	check_setenv_errors(char **arg, t_tab **data)
{
  int	validity;
  int	ret;

  validity = count_args(arg);
  if (validity == 0)
    {
      display_env(arg, data);
      return (-2);
    }
  else if (validity >= 3)
    {
      my_putstr("setenv: Too many arguments.\n");
      return (-1);
    }
  validity = check_name_validity(arg);
  ret = interpret_validity(validity);
  if (ret == -1)
    return (-1);
  return (0);
}

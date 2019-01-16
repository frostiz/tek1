/*
** check_syntax_error.c for minishell2 in /home/frostiz/repository/PSU_2016_minishell2
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Tue Apr 25 17:52:42 2017 thibaut trouve
** Last update Wed May  3 05:03:36 2017 Thibaut Trouvé
*/

#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "my.h"

int	check_output(char **args, int i)
{
  while (args[i] != NULL)
    {
      if (args[i] && args[i][0] == '|')
	return (-1);
      i++;
    }
  return (0);
}

int	check_input(char **args, int i)
{
  while (i > 0)
    {
      if (args[i] && args[i][0] == '|')
	return (-1);
      i--;
    }
  return (0);
}

static int	interpret_invalid_ret(int ret, int *exit_value)
{
  if (ret == 1)
    {
      my_putstr("Invalid null command.\n");
      *exit_value = 1;
      return (1);
    }
  else if (ret == 2)
    {
      my_putstr("Missing name for redirect.\n");
      *exit_value = 1;
      return (1);
    }
  return (0);
}

static int	interpret_ambiguous_ret(int ret, int *exit_value)
{
  if (ret == 1)
    {
      my_putstr("Ambiguous input redirect.\n");
      *exit_value = 1;
      return (1);
    }
  else if (ret == 2)
    {
      my_putstr("Ambiguous output redirect.\n");
      *exit_value = 1;
      return (1);
    }
  return (0);
}

int	check_cmd_error(t_cmd *cmd, int *exit_value)
{
  int	ret;

  if (cmd == NULL)
    return (1);
  check_inverted(cmd);
  ret = check_invalid_syntax(cmd);
  ret = interpret_invalid_ret(ret, exit_value);
  if (ret != 0)
    return (ret);
  ret = check_ambiguous(cmd);
  ret = interpret_ambiguous_ret(ret, exit_value);
  if (ret != 0)
    return (ret);
  return (0);
}

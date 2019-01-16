/*
** my_unsetenv.c for minishell2 in /home/thibaut/Repository/PSU_2016_minishell2
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Wed Apr  5 23:39:40 2017 Thibaut Trouvé
** Last update Sun Apr  9 18:17:34 2017 thibaut trouve
*/

#include <stdlib.h>
#include "my.h"
#include "main.h"

void	del_var_from_env(char **env, int idx)
{
  free(env[idx]);
  while (env[idx] != NULL)
    {
      env[idx] = env[idx + 1];
      idx++;
    }
}

void	my_unsetenv(char **arg, t_tab **data)
{
  int	i;
  int	idx_var;

  i = 1;
  if (arg[1] == NULL)
    {
      my_putstr("unsetenv: Too few arguments.\n");
      return ;
    }
  while (arg[i] != NULL)
    {
      idx_var = search_in_env(arg[i], (*data)->my_env);
      if (idx_var != -1)
	del_var_from_env((*data)->my_env, idx_var);
      i++;
    }
}

/*
** main.c for minishell2 in /home/thibaut/Repository/PSU_2016_minishell2
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Mon Apr  3 20:57:38 2017 Thibaut Trouvé
** Last update Sun Apr  9 01:03:31 2017 Thibaut Trouvé
*/

#include <signal.h>
#include <stdlib.h>
#include "my.h"
#include "main.h"

static int	init_struct(t_tab *data, char **env)
{
  data->my_env = my_copy_tab(env);
  if (data->my_env == NULL)
    return (-1);
  data->exit_value = 0;
  return (0);
}

int	minishell2(char **env, t_tab *data)
{
  if (env == NULL)
    return (-1);
  if (init_struct(data, env) == -1)
    return (-1);
  if (mainloop(data) == -1)
    return (-1);
  return (data->exit_value);
}

int	main(int argc, char **argv, char **env)
{
  int	ret;
  t_tab	*data;

  (void)argc;
  (void)argv;
  signal(SIGSEGV, sign_handler);
  data = malloc(sizeof(t_tab));
  if (data == NULL)
    return (0);
  ret = minishell2(env, data);
  if (ret == -1)
    return (0);
  free_tab(data->my_env);
  free(data);
  return (ret);
}

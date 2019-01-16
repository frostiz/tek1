/*
** my_setenv.c for minishell2 in /home/thibaut/Repository/PSU_2016_minishell2
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Wed Apr  5 23:38:44 2017 Thibaut Trouvé
** Last update Tue May  2 10:22:33 2017 Thibaut Trouvé
*/

#include <stdlib.h>
#include "my.h"
#include "main.h"

int	search_in_env(char *name, char **my_env)
{
  int	i;
  int	dist;

  i = 0;
  while (my_env[i] != NULL)
    {
      dist = 0;
      while (my_env[i][dist] != '=' && my_env[i][dist] != '\0')
	dist++;
      if (my_strncmp(my_env[i], name, dist - 1) == 0)
	return (i);
      i++;
    }
  return (-1);
}

void	modify_env(char **args, t_tab *data, int idx_varname)
{
  int	len;

  if (args[2] == NULL)
    len = 0;
  else
    len = my_strlen(args[2]);
  free(data->my_env[idx_varname]);
  data->my_env[idx_varname] = malloc(sizeof(char) *
				     my_strlen(args[1]) + len + 2);
  if (data->my_env[idx_varname] == NULL)
    return ;
  data->my_env[idx_varname][0] = '\0';
  my_strcat(data->my_env[idx_varname], args[1]);
  my_strcat(data->my_env[idx_varname], "=");
  if (args[2] != NULL)
    my_strcat(data->my_env[idx_varname], args[2]);
}

char	**get_env(char **env)
{
  int	i;
  char	**new_env;

  i = 0;
  new_env = malloc(sizeof(char *) * (my_tablen(env) + 1 + 2));
  if (new_env == NULL)
    return (NULL);
  while (env[i] != NULL)
    {
      new_env[i] = my_strdup(env[i]);
      free(env[i]);
      i++;
    }
  new_env[i] = NULL;
  free(env);
  return (new_env);
}

void	add_to_env(char **args, char ***env)
{
  int	len;
  int	tablen;
  char	**new_env;

  if (args[2] == NULL)
    len = 0;
  else
    len = my_strlen(args[2]);
  new_env = get_env(*env);
  tablen = my_tablen(new_env);
  new_env[tablen] = malloc(sizeof(char) * my_strlen(args[1]) + len + 2);
  if (new_env[tablen] == NULL)
    return ;
  my_strcpy(new_env[tablen], args[1]);
  my_strcat(new_env[tablen], "=");
  if (args[2] != NULL)
    my_strcat(new_env[tablen], args[2]);
  new_env[tablen + 1] = NULL;
  *env = get_env(new_env);
}

void	my_setenv(char **arg, t_tab **data)
{
  int	ret;
  int	idx_varname;

  ret = check_setenv_errors(arg, data);
  if (ret == -1)
    {
      (*data)->exit_value = 1;
      return ;
    }
  else if (ret == -2)
    return ;
  idx_varname = search_in_env(arg[1], (*data)->my_env);
  if (idx_varname == -1)
    add_to_env(arg, &(*data)->my_env);
  else
    modify_env(arg, *data, idx_varname);
}

/*
** setenv.c for setenv.c in /home/frostiz/PSU_2016_minishell1/src
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Sun Jan 22 23:10:51 2017 thibaut trouve
** Last update Sun Jan 22 23:38:45 2017 thibaut trouve
*/

#include "my.h"

char	**pop_var_in_env(char **my_env, char *var_name, char *var_value)
{
  char  **new_env;
  int   pos_end;
  int   i;

  i = 0;
  new_env = get_env(my_env);
  while (my_env[i] != NULL)
    {
      free(my_env[i]);
      i++;
    }
  free(my_env);
  pos_end = nb_env_var(new_env);
  new_env[pos_end] = malloc(sizeof(char) * my_strlen(var_name)
			    + my_strlen(var_value) + 2);
  if (new_env[pos_end] == NULL)
    return (NULL);
  my_strcpy(new_env[pos_end], var_name);
  my_strcat(new_env[pos_end], "=");
  my_strcat(new_env[pos_end], var_value);
  new_env[pos_end + 1] = NULL;
  return (new_env);
}

void	modify_var_env(char **my_env, int pos_var, char *var_name,
		       char *var_value)
{
  free(my_env[pos_var]);
  my_env[pos_var] =
    malloc(sizeof(char) * my_strlen(var_name) + my_strlen(var_value) + 2);
  if (my_env[pos_var] == NULL)
    return ;
  my_strcpy(my_env[pos_var], var_name);
  my_strcat(my_env[pos_var], "=");
  my_strcat(my_env[pos_var], var_value);
}

int	check_name_validity(char *name)
{
  int   i;

  i = 0;
  if ((name[0] < 'a' || name[0] > 'z') &&
      (name[0] < 'A' || name[0] > 'Z') &&
      (name[0] != '_'))
    return (2);
  while (name[i] != '\0')
    {
      if (name[i] > 'z')
	return (0);
      if (name[i] < 'a' && name[i] > 'Z' && name[i] != '_')
	return (0);
      if (name[i] < 'A' && name[i] > '9')
	return (0);
      if (name[i] < '0' && name[i] != '.')
	return (0);
      i++;
    }
  return (1);
}

void	my_setenv(char ***my_env, char *var_name, char *var_value)
{
  int   pos_var;

  if (var_name != NULL && var_value == NULL)
    var_value = my_strdup("");
  if (check_name_validity(var_name) == 0)
    {
      my_printf("setenv: Variable name must contain alphanumeric characters.\n"
		);
      return ;
    }
  else if (check_name_validity(var_name) == 2)
    {
      my_printf("setenv: Variable name must begin with a letter.\n");
      return ;
    }
  pos_var = check_env_var(*my_env, var_name);
  if (nb_env_var(*my_env) == pos_var)
    *my_env = pop_var_in_env(*my_env, var_name, var_value);
  else
    modify_var_env(*my_env, pos_var, var_name, var_value);
}

int	is_existing_prog(char *tab, char *path)
{
  if (my_strcmp("cd", tab) != 0 &&
      my_strcmp("setenv", tab) != 0 &&
      my_strcmp("env", tab) != 0 &&
      my_strcmp("unsetenv", tab) != 0 &&
      my_strcmp("exit", tab) != 0 &&
      path == NULL)
    {
      return (0);
    }
  return (1);
}

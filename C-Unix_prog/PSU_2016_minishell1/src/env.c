/*
** env.c for env.c in /home/frostiz/PSU_2016_minishell1/src
** 
** Made by thibaut trouve
** Login   <frostiz@epitech.net>
** 
** Started on  Sun Jan 22 23:08:32 2017 thibaut trouve
** Last update Sun Jan 22 23:32:29 2017 thibaut trouve
*/

#include "my.h"

int	env_command(char **tab, char ***my_env)
{
  if (my_strcmp("env", tab[0]) == 0)
    {
      aff_env(*my_env);
      return (0);
    }
  else if (my_strcmp("setenv", tab[0]) == 0)
    {
      if (tab[1] != NULL && tab[2] != NULL)
	my_setenv(my_env, tab[1], tab[2]);
      else if (tab[1] != NULL && tab[2] == NULL)
	my_setenv(my_env, tab[1], NULL);
      else
	aff_env(*my_env);
      return (0);
    }
  else if (my_strcmp("unsetenv", tab[0]) == 0)
    {
      my_unsetenv(my_env, tab);
      return (0);
    }
  return (1);
}

char	*get_var_env_value(char **my_env, char *var_name)
{
  int   i;
  int   j;
  char  *str;

  j = 0;
  i = 0;
  str = NULL;
  while (my_env[i] != NULL)
    {
      while (my_env[i][j] != '=' && my_env[i][j] != '\0')
	j++;
      if (my_strncmp(var_name, my_env[i], j) == 0)
	{
	  str = malloc(sizeof(char) * my_strlen(my_env[i]) + 1);
	  if (str == NULL)
	    return (NULL);
	  j++;
	  my_strcpy(str, &my_env[i][j]);
	}
      j = 0;
      i++;
    }
  if (str == NULL)
    return (NULL);
  return (str);
}

int	check_env_var(char **my_env, char *var_name)
{
  int   i;
  int   j;

  i = 0;
  j = 0;
  while (my_env[i] != NULL)
    {
      while (my_env[i][j] != '=' && my_env[i][j] != '\0')
	j++;
      if (my_strncmp(my_env[i], var_name, j) == 0)
	return (i);
      j = 0;
      i++;
    }
  return (i);
}

void	aff_env(char **my_env)
{
  int i;

  i = 0;
  while (my_env[i] != NULL)
    {
      my_printf("%s\n", my_env[i]);
      i++;
    }
  return ;
}

int	find_path(char **my_env)
{
  int   i;
  int   pos_path;

  i = 0;
  while (my_env[i] != NULL)
    {
      if (my_strncmp("PATH", my_env[i], 4) == 0)
	return (pos_path = i);
      i++;
    }
  return (-1);
}

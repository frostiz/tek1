/*
** my_unsetenv.c for 42sh in /home/Lucas/delivery/PSU/PSU_2016_42sh
**
** Made by Lucas Dumy
** Login   <lucas.dumy@epitech.eu>
**
** Started on  Fri Apr  7 10:54:36 2017 Lucas Dumy
** Last update Thu May 18 21:13:13 2017 Lucas Dumy
*/

#include	<string.h>
#include	<stdlib.h>
#include	"mysh.h"

static char	**remove_empty_lines(char **env, char **new_env)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (env[i] != NULL)
    {
      if (env[i][0] != '\0')
	{
	  new_env[j] = env[i];
	  j++;
	}
      else
	free(env[i]);
      i++;
    }
  free(env);
  new_env[j] = NULL;
  return (new_env);
}

static char	**new_size(char **env)
{
  char		**new_env;
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (env[i] != NULL)
    {
      if (env[i][0] != '\0')
	j++;
      i++;
    }
  if (i == j)
    return (env);
  new_env = malloc(sizeof(char *) * (j + 1));
  if (new_env == NULL)
    exit(84);
  new_env = remove_empty_lines(env, new_env);
  return (new_env);
}

static char	**delete_env(char **env, char *str)
{
  int		i;

  i = 0;
  while (env[i] != NULL)
    {
      if (strncmp(str, env[i], strlen(str)) == 0 &&
	  env[i][strlen(str)] == '=')
	env[i][0] = '\0';
      i++;
    }
  env = new_size(env);
  return (env);
}

void		my_unsetenv(char **tab, char ***env,
			    int *return_value, int *fd)
{
  int		i;

  i = 1;
  if (tab[i] == NULL)
    {
      my_perror("unsetenv: Too few arguments.\n");
      *return_value = 1;
      return ;
    }
  else if (fd[2] == -1)
    {
      while (tab[i] != NULL)
	{
	  *env = delete_env(*env, tab[i]);
	  i++;
	}
    }
  *return_value = 0;
}

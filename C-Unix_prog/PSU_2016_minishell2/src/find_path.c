/*
** find_path.c for minishell2 in /home/thibaut/Repository/PSU_2016_minishell2
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Tue Apr  4 21:42:43 2017 Thibaut Trouvé
** Last update Wed May  3 05:55:48 2017 Thibaut Trouvé
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"
#include "my.h"

char	*get_var_env_value(char **env, char *name)
{
  int	i;

  i = 0;
  while (env[i] != NULL)
    {
      if (my_strncmp(env[i], name, my_strlen(name) - 1) == 0)
	return (&env[i][my_strlen(name) + 1]);
      i++;
    }
  return (NULL);
}

char	*find_correct_path(char *prog_name, char **paths_tab)
{
  int	i;
  char	*tmp;

  i = 0;
  while (paths_tab[i] != NULL)
    {
      tmp = malloc(sizeof(char) * (my_strlen(prog_name) +
				   my_strlen(paths_tab[i]) + 2));
      if (tmp == NULL)
	return (NULL);
      my_strcpy(tmp, paths_tab[i]);
      if (tmp[my_strlen(tmp) - 1] != '/')
	my_strcat(tmp, "/");
      my_strcat(tmp, prog_name);
      if (access(tmp, X_OK) == 0)
	return (tmp);
      free(tmp);
      i++;
    }
  return (NULL);
}

int	true_path(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '/')
	return (1);
      i++;
    }
  return (0);
}

int	is_dir(char *path)
{
  struct stat   file;

  if (stat(path, &file) == -1)
    return (-1);
  if ((file.st_mode & S_IFMT) == S_IFDIR)
    return (1);
  return (-1);
}

char	*find_path(char **args, char **my_env)
{
  char	*paths;
  char	**paths_tab;
  char	*correct_path;

  if (args[0] == NULL)
    return (NULL);
  if (true_path(args[0]) == 1)
    {
      paths = my_strdup(args[0]);
      paths = interpret_truepath(paths);
      return (paths);
    }
  paths = get_var_env_value(my_env, "PATH");
  if (paths == NULL)
    return (NULL);
  paths_tab = my_str_to_wordtab(paths, ":");
  if (paths_tab == NULL)
    return (NULL);
  correct_path = find_correct_path(args[0], paths_tab);
  free_tab(paths_tab);
  if (correct_path == NULL)
    return (NULL);
  return (correct_path);
}

/*
** strcmp_question_mark.c for 42sh in /home/Lucas/delivery/PSU/PSU_2016_42sh/globbing
**
** Made by Lucas Dumy
** Login   <lucas.dumy@epitech.eu>
**
** Started on  Sat May 20 08:14:21 2017 Lucas Dumy
** Last update Sun May 21 22:35:18 2017 Lucas Dumy
*/

#include	<sys/types.h>
#include	<dirent.h>
#include	<stdlib.h>
#include	<string.h>
#include	"mysh.h"

static char	**realloc_tab(char **args, char *match)
{
  char		**new_args;
  int		i;

  i = 0;
  while (args[i] != NULL)
    i++;
  new_args = malloc(sizeof(char *) * (i + 2));
  if (new_args == NULL)
    return (NULL);
  i = 0;
  while (args[i] != NULL)
    {
      new_args[i] = args[i];
      i++;
    }
  new_args[i] = match;
  new_args[i + 1] = NULL;
  free(args);
  return (new_args);
}

static char	**check_arg(char *arg, char **new_args, int *glob)
{
  struct dirent	*path;
  DIR		*dir;
  int		i;
  int		j;

  if (my_has_slash(arg) == 0)
    {
      dir = opendir(".");
      path = readdir(dir);
      while (path != NULL)
	{
	  i = 0;
	  j = 0;
	  if ((path->d_name[0] == '.' && arg[0] == '.') ||
	      (path->d_name[0] != '.' &&
	       glob_and_cmp(arg, path->d_name, &i, &j) == 0))
	    new_args = realloc_tab(new_args, strdup(path->d_name));
	  path = readdir(dir);
	}
      closedir(dir);
    }
  (*glob)++;
  return (new_args);
}

static char	**check_new_args(char **args, char **new_args, int glob)
{
  free(args);
  if (new_args[1] == NULL && glob != 0)
    {
      my_perror(new_args[0]);
      my_perror(": No match.\n");
      return (NULL);
    }
  return (new_args);
}

char		**globbing(char **args)
{
  char		**new_args;
  int		glob;
  int		i;

  i = 1;
  glob = 0;
  remove_all_quotes(args);
  if (args == NULL || args[0] == NULL || args[1] == NULL)
    return (args);
  new_args = malloc(sizeof(char *) * 2);
  if (new_args == NULL)
    return (NULL);
  new_args[0] = args[0];
  new_args[1] = NULL;
  while (args[i] != NULL)
    {
      if (my_is_glob(args[i]) == 1)
	new_args = realloc_tab(new_args, args[i]);
      else
	new_args = check_arg(args[i], new_args, &glob);
      i++;
    }
  return (check_new_args(args, new_args, glob));
}

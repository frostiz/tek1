/*
** where_access.c for where_access.c in /home/roye_v/delivery/PSU_2016_42sh
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sun May 21 13:38:20 2017 Vincent Roye
** Last update Mon May 22 15:30:45 2017 Vincent Roye
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<string.h>
#include	"exec.h"
#include	"mysh.h"

int		check_where_error(char **env, char **args, int *return_value)
{
  if (array_len(args) == 1)
    {
      *return_value = 1;
      my_perror("where: Too few arguments.\n");
      return (1);
    }
  if (env[0] == NULL)
    return (1);
  return (0);
}

static void	add_new(char **tmp, char **path, char *arg, int i)
{
  tmp[i] = strdup(path[i]);
  tmp[i] = realloc(tmp[i], (strlen(tmp[i]) + strlen(arg) + 3));
  tmp[i] = strcat(tmp[i], "/");
  tmp[i] = strcat(tmp[i], arg);
}

static void	add_access(char **final, char **tmp, int i)
{
  if (*final == NULL)
    *final = strdup(tmp[i]);
  else
    {
      *final = realloc(*final, (strlen(*final) + strlen(tmp[i]) + 3));
      *final = strcat(*final, "\n");
      *final = strcat(*final, tmp[i]);
    }
}

static char	*return_string(char *final)
{
  if (final == NULL)
    return (NULL);
  if (final[strlen(final) - 1] == '\n')
    final[strlen(final) - 1] = '\0';
  return (final);
}

char		*where_access(char *arg, char **path)
{
  char		**tmp;
  char		*final;
  int		i;

  i = 0;
  tmp = malloc(sizeof(char *) * (array_len(path) + 1));
  if (tmp == NULL)
    return (NULL);
  final = malloc(sizeof(char));
  if (final == NULL)
    return (NULL);
  final = NULL;
  if (tmp == NULL)
    return (NULL);
  while (path[i] != NULL)
    {
      add_new(tmp, path, arg, i);
      if (access(tmp[i], X_OK) == 0)
	add_access(&final, tmp, i);
      i++;
    }
  return (return_string(final));
}

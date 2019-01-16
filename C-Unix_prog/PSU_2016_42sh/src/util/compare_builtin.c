/*
** compare_builtin.c for compare_builtin.c in /home/roye_v/delivery/PSU_2016_42sh
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sun May 21 13:15:32 2017 Vincent Roye
** Last update Sun May 21 13:37:02 2017 Vincent Roye
*/

#include	<string.h>
#include	<stdlib.h>
#include	"mysh.h"
#include	"exec.h"

int		compare_builtin(char *str, char **builtin)
{
  int		i;

  i = 0;
  while (builtin[i] != NULL)
    {
      if (strcmp(builtin[i], str) == 0)
	return (1);
      i++;
    }
  return (0);
}

char		**get_path(char **env)
{
  char		**path;
  int		i;
  int		ok;

  i = 0;
  ok = 0;
  path = malloc(sizeof(char *) * (array_len(env) + 1));
  if (path == NULL)
    return (NULL);
  while (env[i] != NULL)
    {
      if (strncmp(env[i], "PATH", 4) == 0)
	ok = i;
      i++;
    }
  path = my_split(env[ok] + 5, ':');
  return (path);
}

int		is_slash(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '/')
	return (1);
      i++;
    }
  return (0);
}

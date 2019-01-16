/*
** my_envdup.c for 42sh in /home/Lucas/delivery/PSU/PSU_2016_42sh
**
** Made by Lucas Dumy
** Login   <lucas.dumy@epitech.eu>
**
** Started on  Thu Apr  6 15:52:48 2017 Lucas Dumy
** Last update Thu May 18 18:38:02 2017 Lucas Dumy
*/

#include	<stdlib.h>
#include	<string.h>
#include	"mysh.h"

char		**my_envdup(char **env, int len, int *return_value)
{
  char		**new_env;
  int		i;

  i = 0;
  *return_value = 1;
  while (env != NULL && env[i] != NULL)
    i++;
  new_env = malloc(sizeof(char *) * (i + 1 + len));
  if (new_env == NULL)
    return (env);
  i = 0;
  while (env[i] != NULL)
    {
      new_env[i] = strdup(env[i]);
      i++;
    }
  new_env[i] = NULL;
  if (len != 0)
    {
      my_free_tab(env);
      new_env[i + len] = NULL;
    }
  *return_value = 0;
  return (new_env);
}

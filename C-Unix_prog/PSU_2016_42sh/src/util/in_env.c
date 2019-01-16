/*
** in_env.c for  in /home/bastien/delivery/PSU/PSU_2016_42sh
** 
** Made by bastien bedu
** Login   <bastien.bedu@epitech.eu>
** 
** Started on  Sat May 20 12:38:10 2017 bastien bedu
** Last update Sat May 20 12:58:14 2017 bastien bedu
*/

#include	<stdlib.h>
#include	<string.h>
#include	"env.h"

int		env_index(char **env, char *str)
{
  int		i;

  if (str == NULL)
    return (- 1);
  i = 0;
  while (env != NULL && env[i] != NULL && my_strcomp(env[i], str) == 0)
    i++;
  if (env != NULL && env[i] != NULL)
    return (i);
  return (-1);
}

char		*value_of(char **env, char *str)
{
  char		*in_env;
  int		i;

  i = env_index(env, str);
  if (i == -1)
    return (NULL);
  in_env = env[i];
  i = 0;
  while (in_env[i] != '\0' && in_env[i] != '=')
    i++;
  if (in_env[i] == '=')
    i++;
  in_env = strdup(&in_env[i]);
  return (in_env);
}

/*
** cat_path.c for  in /home/bastien/delivery/PSU/PSU_2016_42sh
**
** Made by bastien bedu
** Login   <bastien.bedu@epitech.eu>
**
** Started on  Sun May 21 14:43:14 2017 bastien bedu
** Last update Sun May 21 21:56:42 2017 Lucas Dumy
*/

#include	<stdlib.h>
#include	<string.h>
#include	<unistd.h>
#include	"exec.h"

char		*my_str_path(char *str, char *str2)
{
  char		*new;
  int		i;
  int		j;

  i = 0;
  j = 0;
  new = malloc(sizeof(char) * (strlen(str) + strlen(str2) + 2));
  while (new != NULL && str != NULL && str[i] != '\0')
    {
      new[i] = str[i];
      i++;
    }
  if (new != NULL && i > 0 && str[i - 1] != '/')
    {
      new[i] = '/';
      i++;
    }
  while (new != NULL && str2 != NULL && str2[j] != '\0')
    {
      new[i + j] = str2[j];
      j++;
    }
  if (new != NULL)
    new[i + j] = '\0';
  return (new);
}

int		my_strcomp(char *str, char *str2)
{
  int		i;

  i = 0;
  if (str2 == NULL || str == NULL)
    return (0);
  while (str[i] != '\0' && str[i] != '=' && str[i] == str2[i])
    i++;
  if (str[i] == '=' && str2[i] == '\0')
    return (1);
  return (0);
}

char		*my_strcat_path(char **env, char *arg)
{
  char		**paths;
  char		*new;
  int		i;
  int		j;

  i = 0;
  paths = NULL;
  while (env != NULL && env[i] != NULL && my_strcomp(env[i], "PATH") == 0)
    i++;
  new = NULL;
  if (env != NULL && env[i] != NULL)
    paths = my_split(&env[i][5], ':');
  else
    paths = my_split("/bin:/sbin:/usr/bin:/usr/sbin:/usr/heimdal/bin:"
		     "/usr/heimdal/sbin", ':');
  j = 0;
  while (paths != NULL && paths[j] != NULL &&
	 (j == 0 || (new != NULL && my_access(new, X_OK, 0) == -1)))
    {
      free(new);
      new = my_str_path(paths[j], arg);
      j++;
    }
  my_free_tab(paths);
  return (new);
}

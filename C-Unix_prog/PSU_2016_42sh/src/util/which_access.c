/*
** which_access.c for which_access.c in /home/roye_v/delivery/PSU_2016_42sh
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sun May 21 13:23:16 2017 Vincent Roye
** Last update Mon May 22 15:26:09 2017 Vincent Roye
*/

#include	<string.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	"mysh.h"
#include	"exec.h"

static int	too_few_arguments(int *return_value)
{
  *return_value = 1;
  my_perror("which: Too few arguments.\n");
  return (0);
}

int	check_which_error(char **args, char **env, int *return_value)
{
  if (array_len(args) == 1)
    if (too_few_arguments(return_value) == 0)
      return (1);
  if (env[0] == NULL)
    return (1);
  return (0);
}

char	*which_access(char *arg, char **path)
{
  char	**tmp;
  int	i;

  i = 0;
  tmp = malloc(sizeof(char *) * (array_len(path) + 1));
  if (tmp == NULL)
    return (NULL);
  while (path[i] != NULL)
    {
      tmp[i] = strdup(path[i]);
      tmp[i] = realloc(tmp[i], (strlen(tmp[i]) + strlen(arg) + 3));
      tmp[i] = strcat(tmp[i], "/");
      tmp[i] = strcat(tmp[i], arg);
      if (access(tmp[i], X_OK) == 0)
	return (tmp[i]);
      i++;
    }
  return (NULL);
}

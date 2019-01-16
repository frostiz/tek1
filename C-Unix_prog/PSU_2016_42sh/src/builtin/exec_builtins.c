/*
** exec_builtins.c for 42sh in /home/Lucas/delivery/PSU/PSU_2016_42sh
**
** Made by Lucas Dumy
** Login   <lucas.dumy@epitech.eu>
**
** Started on  Thu May 18 11:22:06 2017 Lucas Dumy
** Last update Sun May 21 11:00:01 2017 bastien bedu
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	"mysh.h"

char		**create_builtins_array()
{
  char		**array;

  array = malloc(sizeof(char *) * (11));
  if (array == NULL)
    return (NULL);
  array[0] = strdup("env");
  array[1] = strdup("setenv");
  array[2] = strdup("unsetenv");
  array[3] = strdup("cd");
  array[4] = strdup("exit");
  array[5] = strdup("echo");
  array[6] = strdup("which");
  array[7] = strdup("repeat");
  array[8] = strdup("where");
  array[9] = strdup("if");
  array[10] = NULL;
  return (array);
}

void		set_builtins(void (**builtins)
			     (char **, char ***, int *, int *))
{
  builtins[0] = &my_env;
  builtins[1] = &my_setenv;
  builtins[2] = &my_unsetenv;
  builtins[3] = &my_cd;
  builtins[4] = &my_exit;
  builtins[5] = &my_echo;
  builtins[6] = &my_which;
  builtins[7] = &repeat;
  builtins[8] = &my_where;
  builtins[9] = &my_if;
}

int		check_builtin(char **args, int *fd,
			      char ***env, int *return_value)
{
  void		(*builtins[10])(char **, char ***, int *, int *);
  char		**builtins_array;
  int		i;
  int		fd_save;

  i = 0;
  *return_value = 0;
  builtins_array = create_builtins_array();
  if (builtins_array == NULL)
    return (1);
  set_builtins(builtins);
  while (builtins_array[i] != NULL && strcmp(builtins_array[i], args[0]) != 0)
    i++;
  my_free_tab(builtins_array);
  if (i == 10)
    return (1);
  fd_save = dup(1);
  if (fd_save == -1 || (fd[1] != 1 && dup2(fd[1], 1) == -1))
    *return_value = 1;
  else
    builtins[i](args, env, return_value, fd);
  if (dup2(fd_save, 1) == -1)
    *return_value = 1;
  close(fd_save);
  return (0);
}

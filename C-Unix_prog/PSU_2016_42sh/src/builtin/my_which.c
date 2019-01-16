/*
** which.c for which.c in /home/roye_v/delivery/PSU_2016_42sh
**
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
**
** Started on  Sat May 20 19:15:32 2017 Vincent Roye
** Last update Mon May 22 15:25:47 2017 Vincent Roye
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<unistd.h>
#include	<string.h>
#include	"mysh.h"
#include	"exec.h"

static void	builtin_error(char **args, int i)
{
  my_perror(args[i]);
  my_perror(": shell built-in command.\n");
}

static void	put_good_str(char *good_str)
{
  my_putstr(good_str);
  my_putstr("\n");
}

static void	command_not_found(char **args, int *return_value, int i)
{
  my_putstr(args[i]);
  my_putstr(": Command not found.\n");
  *return_value = 1;
}

void		my_which(char **args, char ***env, int *return_value,
			 __attribute__ ((unused)) int *fd)
{
  int		i;
  char		**path;
  char		**builtin;
  char		*good_str;

  i = 1;
  *return_value = 0;
  builtin = create_builtins_array();
  if (check_which_error(args, *env, return_value) == 1)
    return ;
  path = get_path(*env);
  while (args[i] != NULL)
    {
      good_str = which_access(args[i], path);
      if (access(args[i], X_OK) == 0)
	good_str = strdup(args[i]);
      if (compare_builtin(args[i], builtin) == 1)
	builtin_error(args, i);
      else if (good_str != NULL)
	put_good_str(good_str);
      else
	command_not_found(args, return_value, i);
      i++;
    }
}

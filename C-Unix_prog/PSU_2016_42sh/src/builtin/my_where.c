/*
** my_where.c for my_where.c in /home/roye_v/delivery/PSU_2016_42sh
** 
** Made by Vincent Roye
** Login   <roye_v@epitech.net>
** 
** Started on  Sun May 21 04:05:28 2017 Vincent Roye
** Last update Mon May 22 15:30:50 2017 Vincent Roye
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<unistd.h>
#include	<string.h>
#include	"mysh.h"
#include	"exec.h"

static void	slash_error(int *return_value)
{
  my_putstr("where: / in command makes no sense\n");
  *return_value = 1;
}

static void	error_builtin(char **args, int i)
{
  my_putstr(args[i]);
  my_putstr(" is a shell built-in\n");
}

static void print_good_str(char *good_str)
{
  my_putstr(good_str);
  my_putstr("\n");
}

void		my_where(char **args, char ***env, int *return_value,
			 __attribute__ ((unused)) int *fd)
{
  int		i;
  char		**path;
  char		**builtin;
  char		*good_str;

  i = 1;
  *return_value = 0;
  builtin = create_builtins_array();
  if (check_where_error(*env, args, return_value) == 1)
    return ;
  path = get_path(*env);
  while (args[i] != NULL)
    {
      good_str = where_access(args[i], path);
      if (is_slash(args[i]) == 1)
	slash_error(return_value);
      else if (compare_builtin(args[i], builtin) == 1)
	error_builtin(args, i);
      else if (good_str != NULL)
	print_good_str(good_str);
      else
	*return_value = 1;
      i++;
    }
}

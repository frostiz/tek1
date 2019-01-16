/*
** open_files_redir.c for minishell2 in /home/thibaut/Repository/PSU_2016_minishell2
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Wed May  3 03:33:42 2017 Thibaut Trouvé
** Last update Wed May  3 04:31:47 2017 Thibaut Trouvé
*/

#include <fcntl.h>
#include "main.h"
#include "my.h"

int	get_output(char **args)
{
  int	i;

  i = 0;
  while (args[i] != NULL)
    {
      if (args[i][0] == '>')
	{
	  if (args[i][1] == '>')
	    {
	      return (DOUBLE_RIGHT);
	    }
	  return (SIMPLE_RIGHT);
	}
      i++;
    }
  return (-1);
}

int	get_input(char **args)
{
  int	i;

  i = 0;
  while (args[i] != NULL)
    {
      if (args[i][0] == '<')
	{
	  if (args[i][1] == '<')
	    {
	      return (DOUBLE_LEFT);
	    }
	  return (SIMPLE_LEFT);
	}
      i++;
    }
  return (-1);
}

int	interpret_output(int ret, char **args, int *output_fd, t_tab **data)
{
  char	*file;

  if (ret == -1)
    return (-1);
  else if (ret == SIMPLE_RIGHT)
    {
      file = get_file(args, ">");
      if (file == NULL)
	return (0);
      *output_fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    }
  else if (ret == DOUBLE_RIGHT)
    {
      file = get_file(args, ">>");
      if (file == NULL)
	return (0);
      *output_fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0666);
    }
  if (*output_fd == -1)
    {
      if (open_failure(file, data) == -1)
	return (-1);
    }
  return (0);
}

int	interpret_input(int ret, char **args, int *input_fd, t_tab **data)
{
  char	*file;

  if (ret == -1)
    return (-1);
  else if (ret == SIMPLE_LEFT)
    {
      file = get_file(args, "<");
      if (file == NULL)
	return (0);
      *input_fd = open(file, O_RDONLY);
      if (*input_fd == -1)
	{
	  my_putstr(file);
	  (*data)->exit_value = 1;
	  if (is_dir(file) == 1)
	    {
	      my_putstr(": Is a directory.\n");
	      return (-1);
	    }
	  my_putstr(": No such file or directory.\n");
	  return (-1);
	}
    }
  return (0);
}

int	open_files(int *output_fd, int *input_fd, t_tab **data, char **args)
{
  int	ret;

  ret = 0;
  if (is_right_simple_redir(args) == 1)
    {
      ret = get_output(args);
      if (interpret_output(ret, args, output_fd, data) == -1)
	return (-1);
    }
  if (is_left_simple_redir(args) == 1)
    {
      ret = get_input(args);
      if (interpret_input(ret, args, input_fd, data) == -1)
	return (-1);
    }
  return (0);
}

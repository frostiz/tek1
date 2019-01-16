/*
** exec.c for  in /home/bastien/delivery/PSU/PSU_2016_42sh
**
** Made by bastien bedu
** Login   <bastien.bedu@epitech.eu>
**
** Started on  Mon May 15 19:01:08 2017 bastien bedu
** Last update Sun May 21 22:30:33 2017 Lucas Dumy
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<fcntl.h>
#include	<string.h>
#include	"exec.h"
#include	"env.h"
#include	"mysh.h"

int		puts_error(char *arg, char *str)
{
  struct stat	file_inf;

  if (str == NULL || stat(str, &file_inf) == -1)
    {
      my_perror(arg);
      my_perror(": Command not found.\n");
      free(str);
    }
  else if (S_ISDIR(file_inf.st_mode))
    {
      my_perror(arg);
      my_perror(": Permission denied.\n");
      free(str);
    }
  else
    {
      free(arg);
      return (1);
    }
  return (0);
}

int		my_access(char *command, int type, int write)
{
  struct stat	file_info;

  if (stat(command, &file_info) == - 1)
    {
      if (write == 0)
	return (-1);
      my_perror(command);
      if (type == R_OK)
	my_perror(": No such file or directory.\n");
      else
	my_perror(": Command not found.\n");
    }
  else if (S_ISDIR(file_info.st_mode) || access(command, type) == -1)
    {
      if (write == 0)
	return (-1);
      my_perror(command);
      my_perror(": Permission denied.\n");
    }
  else
    return (0);
  return (-1);
}

int		my_exec(char **arg, int *fd, char **env, char *command)
{
  int		pid;

  pid = fork();
  if (pid < 0)
    return (-1);
  if (pid == 0)
    {
      if (fd[0] != 0 && dup2(fd[0], 0) == -1)
	exit(-1);
      if (fd[1] != 1 && dup2(fd[1], 1) == -1)
	exit(-1);
      my_close(fd[2]);
      if (fd[1] != 1)
	my_close(fd[1]);
      if (fd[0] != 0)
	my_close(fd[0]);
      my_swap(&command, arg);
      execve(command, arg, env);
      my_perror(command);
      my_perror(": Exec format error. Binary file not executable.\n");
      exit(1);
    }
  free(command);
  return (pid);
}

int		execute_command(char **args, int *fd, char **env, char *command)
{
  char		*str;
  int		pid;

  pid = -1;
  if (args != NULL && my_str_in_str("/", args[0]) != NULL)
    {
      if (my_access(args[0], X_OK, 1) == -1)
	return (-1);
      pid = my_exec(args, fd, env, command);
    }
  else if (args != NULL)
    {
      str = my_strcat_path(env, args[0]);
      if (puts_error(args[0], str) == 1)
	{
	  args[0] = str;
	  pid = my_exec(args, fd, env, command);
	}
      else
	return (-1);
      args[0] = str;
    }
  return (pid);
}

int		*parse_to_exec(t_graph *graph, char ***env, int *fd,
			       __attribute__ ((unused)) void **tab)
{
  int		*value;
  char		**args;
  int		return_value;

  value = malloc(sizeof(int) * 3);
  graph->command = backticks(graph->command, env);
  graph->command = get_mod_str(*env, graph->command);
  args = my_split(graph->command, ' ');
  if (value == NULL || args == NULL)
    return (NULL);
  args = globbing(args);
  value[2] = -1;
  if (args == NULL || args[0] == NULL)
    set_value(value, 0, 0);
  else if (check_builtin(args, fd, env, &return_value) == 0)
    set_value(value, 0, return_value);
  else
    {
      value[1] = execute_command(args, fd, *env, strdup(args[0]));
      value[0] = 1;
    }
  if (args == NULL || value[1] == -1)
    set_value(value, 0, 1);
  my_free_tab(args);
  return (value);
}

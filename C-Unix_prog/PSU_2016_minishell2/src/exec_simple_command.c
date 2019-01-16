/*
** exec_simple_command.c for minishell2 in /home/thibaut/Repository/PSU_2016_minishell2
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Wed Apr  5 22:40:55 2017 Thibaut Trouvé
** Last update Sun Apr  9 22:17:23 2017 Thibaut Trouvé
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "main.h"
#include "my.h"

int	exec(char **args, t_tab *data, char *found_path, char **env)
{
  pid_t pid;

  pid = fork();
  if (pid == -1)
    return (-1);
  else if (pid == 0)
    {
      if (execve(found_path, args, env) == -1)
	{
	  my_putstr(args[0]);
	  my_putstr(": Exec format error. Binary file not executable.\n");
	  data->exit_value = 1;
	}
      exit(data->exit_value);
    }
  else
    {
      waitpid(pid, &data->exit_value, 0);
      if (WIFEXITED(data->exit_value))
	data->exit_value = WEXITSTATUS(data->exit_value);
      interpret_status(&data->exit_value);
    }
  return (0);
}

int	exec_simple_command(t_tab **data, char **arg)
{
  char	*found_path;
  int	ret;

  found_path = find_path(arg, (*data)->my_env);
  ret = interpret_path(found_path, data, arg);
  if (ret == 1)
    return (0);
  ret = exec(arg, *data, found_path, (*data)->my_env);
  free(found_path);
  if (ret == -1)
    return (-1);
  return (0);
}

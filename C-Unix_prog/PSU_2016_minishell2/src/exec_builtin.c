/*
** exec_builtin.c for minishell2 in /home/thibaut/Repository/PSU_2016_minishell2
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Wed Apr  5 23:04:50 2017 Thibaut Trouvé
** Last update Wed May  3 05:48:24 2017 Thibaut Trouvé
*/

#include <stdlib.h>
#include <sys/wait.h>
#include "main.h"
#include "my.h"

int	exec_builtin(int idx, char **arg, t_tab **data)
{
  void	(*builtin_tab[6])(char **, t_tab **);

  builtin_tab[0] = display_env;
  builtin_tab[1] = my_setenv;
  builtin_tab[2] = my_unsetenv;
  builtin_tab[3] = my_cd;
  builtin_tab[4] = my_exit;
  builtin_tab[idx](arg, data);
  return (0);
}

void		exec_builtin_middle(t_tab **data,
				    int *save_fd, t_split *split)
{
  pid_t	pid;
  int	pipefd[2];
  int	builtin;

  pipefd[0] = 0;
  pipefd[1] = 0;
  pipe(pipefd);
  pid = fork();
  if (pid == 0)
    {
      dup2(*save_fd, 0);
      dup2(pipefd[1], 1);
      close(pipefd[0]);
      builtin = check_builtin(split->real_cmd);
      exec_builtin(builtin, split->real_cmd, data);
      exit(0);
    }
  else
    {
      waitpid(-1, &(*data)->exit_value, 0);
      if (WIFEXITED((*data)->exit_value))
	(*data)->exit_value = WEXITSTATUS((*data)->exit_value);
      close(pipefd[1]);
      *save_fd = pipefd[0];
    }
}

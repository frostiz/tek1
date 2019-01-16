/*
** exec_simple_left.c for minishell2 in /home/thibaut/Repository/PSU_2016_minishell2
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Wed May  3 03:51:00 2017 Thibaut Trouvé
** Last update Wed May  3 05:45:27 2017 Thibaut Trouvé
*/

#include <sys/wait.h>
#include <stdlib.h>
#include "main.h"
#include "my.h"

int	is_left_simple_redir(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      if (my_strcmp(tab[i], "<") == 0)
	return (1);
      i++;
    }
  return (0);
}

static void	duplicate(int input_fd, int *save_fd,
			  int pipefd[2], t_split *split)
{
  dup2(input_fd, *save_fd);
  dup2(*save_fd, 0);
  if (split->next != NULL)
    dup2(pipefd[1], 1);
  close(pipefd[0]);
}

static void	my_wait(t_tab **data, int pipefd[2], int *save_fd)
{
  waitpid(-1, &(*data)->exit_value, 0);
  if (WIFEXITED((*data)->exit_value))
    (*data)->exit_value = WEXITSTATUS((*data)->exit_value);
  close(pipefd[1]);
  *save_fd = pipefd[0];
}

int		exec_simple_left(t_split *split, int input_fd,
				 int *save_fd, t_tab **data)
{
  pid_t	pid;
  char	*progname;
  int	pipefd[2];

  pipe(pipefd);
  split->real_cmd = extract_cmd(split->real_cmd, 0, '<');
  progname = find_path(split->real_cmd, (*data)->my_env);
  if (progname == NULL)
    {
      my_putstr(split->real_cmd[0]);
      my_putstr(": Command not found.\n");
      (*data)->exit_value = 1;
      return (0);
    }
  pid = fork();
  if (pid == 0)
    {
      duplicate(input_fd, save_fd, pipefd, split);
      execve(progname, split->real_cmd, (*data)->my_env);
      exit(0);
    }
  else
    my_wait(data, pipefd, save_fd);
  return (0);
}

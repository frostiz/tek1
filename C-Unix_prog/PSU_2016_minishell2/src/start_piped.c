/*
** start_piped.c for minishell2 in /home/thibaut/Repository/PSU_2016_minishell2
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Sun Apr  9 16:25:21 2017 Thibaut Trouvé
** Last update Wed May  3 05:49:16 2017 Thibaut Trouvé
*/

#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
#include "my.h"

int	count_pipe(char **args)
{
  int	i;
  int	count;

  count = 0;
  i = 0;
  while (args[i] != NULL)
    {
      if (args[i][0] == '|')
	count++;
      i++;
    }
  return (count);
}

int	**create_pipe(char **args)
{
  int	**pipefd;
  int	count;
  int	i;

  i = 0;
  count = count_pipe(args);
  pipefd = malloc(sizeof(int *) * (10));
  if (pipefd == NULL)
    return (NULL);
  while (count >= 0)
    {
      pipefd[i] = malloc(sizeof(int) * (3));
      if (pipefd[i] == NULL)
	return (NULL);
      pipefd[i][0] = 0;
      pipefd[i][1] = 0;
      pipe(pipefd[i]);
      i++;
      count--;
    }
  return (pipefd);
}

int	init_struct_pipe(t_pipe *pipe, char **args)
{
  pipe->idx_pipe = 0;
  pipe->output_fd = 0;
  pipe->input_fd = 0;
  pipe->save_fd = 0;
  pipe->pid = malloc(sizeof(pid_t) * (count_pipe(args) + 1));
  if (pipe->pid == NULL)
    return (-1);
  pipe->pipe_fdtab = create_pipe(args);
  if (pipe->pipe_fdtab == NULL)
    return (-1);
  pipe->idx_pipe = 0;
  pipe->status = 0;
  return (0);
}

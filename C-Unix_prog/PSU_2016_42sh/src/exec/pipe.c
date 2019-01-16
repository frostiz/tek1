/*
** pipe.c for  in /home/bastien/delivery/PSU/PSU_2016_42sh
** 
** Made by bastien bedu
** Login   <bastien.bedu@epitech.eu>
** 
** Started on  Tue May 16 22:28:01 2017 bastien bedu
** Last update Sat May 20 16:22:49 2017 bastien bedu
*/

#include	<unistd.h>
#include	<fcntl.h>
#include	<stdlib.h>
#include	"mysh.h"

int		*pipe_split(t_graph *graph, char ***env, int *fd, void **tab)
{
  int		*values_l;
  int		*values_r;
  int		pipefd[2];
  int		savefd[2];

  if (pipe(pipefd) == -1)
    return (create_value(1));
  fd_reset(fd, savefd, 0);
  fd[1] = pipefd[1];
  fd[2] = pipefd[0];
  values_l = command_sep(graph->left, env, fd, tab);
  fd_reset(fd, savefd, 1);
  if (values_l == NULL)
    return (NULL);
  fd[0] = pipefd[0];
  fd[2] = pipefd[1];
  values_r = command_sep(graph->right, env, fd, tab);
  fd_reset(fd, savefd, 1);
  fd[2] = -1;
  if (values_r == NULL)
    return (NULL);
  values_r = cat_values(values_l, values_r);
  if (values_r == NULL)
    return (NULL);
  return (values_r);
}

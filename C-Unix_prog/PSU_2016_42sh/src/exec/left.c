/*
** left.c for  in /home/bastien/delivery/PSU/PSU_2016_42sh
**
** Made by bastien bedu
** Login   <bastien.bedu@epitech.eu>
**
** Started on  Wed May 17 01:30:01 2017 bastien bedu
** Last update Sun May 21 13:03:14 2017 bastien bedu
*/

#include	<fcntl.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	"mysh.h"
#include	"exec.h"
#include	"get_next_line.h"

int		*left_redir(t_graph *graph, char ***env, int *fd, void **tab)
{
  if (my_access(graph->right->command, R_OK, 1) == -1)
    return (create_value(1));
  fd[0] = open(graph->right->command, O_RDONLY);
  if (fd[0] == -1)
    return (create_value(1));
  return (command_sep(graph->left, env, fd, tab));
}

int		*d_left(t_graph *graph, char ***env, int *fd, void **tab)
{
  char		*str;
  char		*full;
  char		*tmp;
  int		pipefd[2];

  if (pipe(pipefd) == -1)
    return (create_value(1));
  full = NULL;
  str = get_next_line(0);
  while (str != NULL && strcmp(graph->right->command, str) != 0)
    {
      tmp = my_strcat(full, str);
      free(full);
      full = my_strcat(tmp, "\n");
      free(tmp);
      free(str);
      str = get_next_line(0);
    }
  write(pipefd[1], full, my_strlen(full));
  close(pipefd[1]);
  fd[0] = pipefd[0];
  return (command_sep(graph->left, env, fd, tab));
}

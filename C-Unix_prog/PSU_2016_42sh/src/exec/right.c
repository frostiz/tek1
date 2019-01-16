/*
** right.c for  in /home/bastien/delivery/PSU/PSU_2016_42sh
**
** Made by bastien bedu
** Login   <bastien.bedu@epitech.eu>
**
** Started on  Wed May 17 21:54:10 2017 bastien bedu
** Last update Wed May 17 22:56:08 2017 Lucas Dumy
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	"mysh.h"

#ifndef PERMISSION
# define PERMISSION (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)
#endif /* !PERMISSION */

int		*right_redir(t_graph *graph, char ***env, int *fd, void **tab)
{
  struct stat	buf;
  int		tmp;

  tmp = stat(graph->right->command, &buf);
  if (tmp != -1 && S_ISDIR(buf.st_mode))
    {
      my_perror(graph->right->command);
      my_perror(": Is a directory.\n");
    }
  else if (tmp != -1 && access(graph->right->command, W_OK) != 0)
    {
      my_perror(graph->right->command);
      my_perror(": Permission denied.\n");
    }
  else
    {
      fd[1] = open(graph->right->command, O_WRONLY | O_CREAT | O_TRUNC,
		   PERMISSION);
      if (fd[1] == -1)
	return (create_value(1));
      return (command_sep(graph->left, env, fd, tab));
    }
  return (create_value(1));
}

int		*d_redir(t_graph *graph, char ***env, int *fd, void **tab)
{
  struct stat	buf;
  int		tmp;

  tmp = stat(graph->right->command, &buf);
  if (tmp != -1 && S_ISDIR(buf.st_mode))
    {
      my_perror(graph->right->command);
      my_perror(": Is a directory.\n");
    }
  else if (tmp != -1 && access(graph->right->command, W_OK) != 0)
    {
      my_perror(graph->right->command);
      my_perror(": Permission denied.\n");
    }
  else
    {
      fd[1] = open(graph->right->command, O_WRONLY | O_CREAT | O_APPEND,
		   PERMISSION);
      if (fd[1] == -1)
	return (create_value(1));
      return (command_sep(graph->left, env, fd, tab));
    }
  return (create_value(1));
}

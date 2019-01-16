/*
** binary.c for  in /home/bastien/delivery/PSU/PSU_2016_42sh
** 
** Made by bastien bedu
** Login   <bastien.bedu@epitech.eu>
** 
** Started on  Tue May 16 22:57:04 2017 bastien bedu
** Last update Sun May 21 13:37:33 2017 bastien bedu
*/

#include	<stdlib.h>
#include	"mysh.h"

int		*and_bin(t_graph *graph, char ***env, int *fd, void **tab)
{
  int		*value;
  int		savefd[2];
  int		exit;

  fd_reset(fd, savefd, 0);
  value = command_sep(graph->left, env, fd, tab);
  value = wait_all(value);
  fd_reset(fd, savefd, 1);
  if (value == NULL)
    return (NULL);
  exit = value[1];
  if (value[0] == 0 && value[1] == 0)
    {
      value = command_sep(graph->right, env, fd, tab);
      value = wait_all(value);
      if (value == NULL)
	return (NULL);
      if (exit < 0 && value[1] < 0)
	value[1] *= -1;
      fd_reset(fd, savefd, 1);
    }
  return (value);
}

int		*or_bin(t_graph *graph, char ***env, int *fd, void **tab)
{
  int		*value;
  int		savefd[2];
  int		exit;

  fd_reset(fd, savefd, 0);
  value = command_sep(graph->left, env, fd, tab);
  value = wait_all(value);
  fd_reset(fd, savefd, 1);
  if (value == NULL)
    return (NULL);
  exit = value[1];
  if (value[0] == 0 && value[1] != 0)
    {
      value = command_sep(graph->right, env, fd, tab);
      value = wait_all(value);
      if (value == NULL)
	return (NULL);
      if (exit < 0 && value[1] < 0)
	value[1] *= -1;
      fd_reset(fd, savefd, 1);
    }
  return (value);
}

int		*coma_bin(t_graph *graph, char ***env, int *fd, void **tab)
{
  int		*value;
  int		savefd[2];
  int		exit;

  fd_reset(fd, savefd, 0);
  value = command_sep(graph->left, env, fd, tab);
  value = wait_all(value);
  fd_reset(fd, savefd, 1);
  if (value == NULL)
    return (NULL);
  exit = value[1];
  free(value);
  value = command_sep(graph->right, env, fd, tab);
  value = wait_all(value);
  fd_reset(fd, savefd, 1);
  if (value == NULL)
    return (NULL);
  if (exit < 0 && value[1] < 0)
    value[1] *= -1;
  return (value);
}

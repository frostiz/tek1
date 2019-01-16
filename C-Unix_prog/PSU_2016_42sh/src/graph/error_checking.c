/*
** error_checking.c for 42sh in /home/dubret_v/delivery/semestre2/Unix/PSU_2016_42sh
**
** Made by dubret_v
** Login   <victor.dubret@epitech.eu>
**
** Started on  Mon May 15 11:34:16 2017 dubret_v
** Last update Sun May 21 21:45:13 2017 dubret_v
*/

#include	<string.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	"mysh.h"

static int	checking(t_graph *graph)
{
  int		(*cond[3])(t_graph *);
  int		(*is_wrong[3])(t_graph *);
  int		i;

  i = 0;
  cond[0] = is_pipe;
  cond[1] = is_and;
  cond[2] = is_redir;
  is_wrong[0] = invalid_pipe;
  is_wrong[1] = invalid_and;
  is_wrong[2] = invalid_redir;
  while (i != 3)
    {
      if (cond[i](graph) == 0)
	if (is_wrong[i](graph) == 1)
	  return (1);
      i++;
    }
  return (0);
}

static int	is_mult_redir(int nb_redir[2], int limit, int my_fd[2])
{
  if ((limit == 4 || limit == 6) && (my_fd[0] == 1))
    nb_redir[0] += 50;
  else if ((limit == 5 || limit == 7) && (my_fd[1] == 1))
    nb_redir[1] += 50;
  else if (limit == 3)
    nb_redir[2] += 1;
  if (nb_redir[0] > 1)
    {
      my_perror("Ambiguous output redirect.\n");
      return (1);
    }
  else if (nb_redir[1] > 1)
    {
      my_perror("Ambiguous input redirect.\n");
      return (1);
    }
  return (0);
}

static int	error_parentheses(char *command)
{
  int			i;

  i = 0;
  while (command[i] != '\0')
    {
      if (command[i] == '"' || command[i] == '`')
	i = go_through_quotes(command, i + 1, command[i]);
      if (command[i] == '(')
	{
	  my_perror("Badly placed ()'s.\n");
	  return (1);
	}
      if (command[i] != '\0')
	i++;
    }
  return (0);
}

static int	error_checking(t_graph *graph, int ret,
			       int nb_redir[], int my_fd[])
{
  int		my_fd_tmp[2];

  if (ret == 1)
    return (1);
  count_redir(nb_redir, graph->limit, my_fd);
  set_value(my_fd_tmp, my_fd[0], my_fd[1]);
  ret = checking(graph);
  if (ret == 1)
    return (1);
  ret = is_mult_redir(nb_redir, graph->limit, my_fd);
  if (graph->left != NULL)
    {
      if (graph->limit == 3)
	set_value(my_fd, 1, my_fd_tmp[1]);
      ret = error_checking(graph->left, ret, nb_redir, my_fd);
    }
  if (graph->right != NULL)
    {
      if (graph->limit == 3)
	set_value(my_fd, my_fd_tmp[0], 1);
      ret = error_checking(graph->right, ret, nb_redir, my_fd);
    }
  if (graph->right == NULL && graph->left == NULL)
    ret = error_parentheses(graph->command);
  return (ret);
}

int		for_error_checking(t_graph *graph)
{
  int		nb_redir[3];
  int		my_fd[2];
  int		ret;

  ret = 0;
  nb_redir[0] = 0;
  nb_redir[1] = 0;
  nb_redir[2] = 0;
  my_fd[0] = 0;
  my_fd[1] = 0;
  ret = error_checking(graph, 0, nb_redir, my_fd);
  return (ret);
}

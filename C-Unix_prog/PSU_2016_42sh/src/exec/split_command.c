/*
** split_command.c for 42sh in /home/Lucas/delivery/PSU/PSU_2016_42sh
**
** Made by Lucas Dumy
** Login   <lucas.dumy@epitech.eu>
**
** Started on  Mon May 15 16:45:21 2017 Lucas Dumy
** Last update Sun May 21 20:26:17 2017 bastien bedu
*/

#include	<stdlib.h>
#include	"mysh.h"
#include	"env.h"

void		set_split(int *(**split)(t_graph *, char ***, int *, void **))
{
  split[0] = &coma_bin;
  split[1] = &or_bin;
  split[2] = &and_bin;
  split[3] = &pipe_split;
  split[4] = &d_redir;
  split[5] = &d_left;
  split[6] = &right_redir;
  split[7] = &left_redir;
  split[8] = &parse_to_exec;
}

int		set_command(t_graph *graph, char **env)
{
  if (graph->left != NULL && set_command(graph->left, env) == 0)
    return (0);
  if (graph->right != NULL && set_command(graph->right, env) == 0)
    return (0);
  if (graph->left == NULL && graph->right == NULL)
    {
      graph->command = get_mod_str(env, graph->command);
      if (graph->command == NULL)
	return (0);
    }
  return (1);
}

int		split_command(t_graph *graph, char ***env)
{
  int		*(*split[9])(t_graph *, char ***, int *, void **);
  int		fd[3];
  int		fd_save[3];
  int		*ret_val;

  if (set_command(graph, *env) == 0)
    return (1);
  fd[0] = 0;
  fd[1] = 1;
  fd[2] = -1;
  fd_reset(fd, fd_save, 0);
  set_split(split);
  if (graph == NULL)
    return (1);
  ret_val = split[(int)(graph->limit)](graph, env, fd, (void **)(split));
  ret_val = wait_all(ret_val);
  if (ret_val == NULL)
    return (1);
  fd_reset(fd, fd_save, 1);
  fd[0] = ret_val[1];
  free(ret_val);
  return (fd[0]);
}

int		*command_sep(t_graph *graph, char ***env, int *fd, void **tab)
{
  int		*(**split)(t_graph *, char ***, int *, void **);

  split = (int *(**)(t_graph *, char ***, int *, void **))(tab);
  if (graph == NULL)
    return (NULL);
  return (split[(int)(graph->limit)](graph, env, fd, tab));
}

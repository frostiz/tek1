/*
** exec_compled_command.c for minishell2 in /home/thibaut/Repository/PSU_2016_minishell2
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Mon May  1 16:39:27 2017 Thibaut Trouvé
** Last update Wed May  3 05:23:08 2017 Thibaut Trouvé
*/

#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>
#include "main.h"
#include "my.h"

static int	interpret_prognull(t_split *split, t_tab **data, t_pipe *pipe)
{
  int	builtin;

  builtin = check_builtin(split->real_cmd);
  if (builtin != -1)
    {
      if (split->next == NULL)
	exec_builtin(builtin, split->real_cmd, data);
      else
	exec_builtin_middle(data, &(pipe->save_fd), split);
      return (0);
    }
  my_putstr(split->real_cmd[0]);
  my_putstr(": Command not found.\n");
  (*data)->exit_value = 1;
  return (0);
}

int	exec_normal(t_split *split, t_tab **data, t_pipe *pipe)
{
  pipe->progname = find_path(split->real_cmd, (*data)->my_env);
  if (pipe->progname == NULL)
    {
      interpret_prognull(split, data, pipe);
      return (0);
    }
  pipe->pid[pipe->idx_pipe] = fork();
  if (pipe->pid[pipe->idx_pipe] == 0)
    {
      dup2(pipe->save_fd, 0);
      if (split->next != NULL)
	dup2(pipe->pipe_fdtab[pipe->idx_pipe][1], 1);
      close(pipe->pipe_fdtab[pipe->idx_pipe][0]);
      execve(pipe->progname, split->real_cmd, (*data)->my_env);
      close(pipe->pipe_fdtab[pipe->idx_pipe][1]);
      exit(0);
    }
  else
    {
      pipe->save_fd = pipe->pipe_fdtab[pipe->idx_pipe][0];
      close(pipe->pipe_fdtab[pipe->idx_pipe][1]);
    }
  return (0);
}

int	exec_split_cmd(t_split *split, t_pipe *pipe, t_tab **data)
{
  while (split != NULL)
    {
      if (pipe->idx_pipe == 0)
	{
	  if (is_left_simple_redir(split->real_cmd) == 1)
	    exec_simple_left(split, pipe->input_fd, &(pipe->save_fd), data);
	  else if (is_left_double_redir(split->real_cmd) == 1)
	    return (exec_double_left(split, &(pipe->save_fd), data));
	  else if (is_right_simple_redir(split->real_cmd) == 1)
	    exec_simple_right(split, pipe->output_fd, &(pipe->save_fd), data);
	  else
	    exec_normal(split, data, pipe);
	}
      else
	{
	  if (is_right_simple_redir(split->real_cmd) == 1)
	    exec_simple_right(split, pipe->output_fd, &(pipe->save_fd), data);
	  else
	    exec_normal(split, data, pipe);
	}
      pipe->idx_pipe++;
      split = split->next;
    }
  return (0);
}

void	wait_pipes(t_pipe *pipe, t_tab **data)
{
  int	tmp;
  int	status;

  status = 0;
  tmp = pipe->idx_pipe;
  pipe->idx_pipe--;
  while (pipe->idx_pipe >= 0)
    {
      close(pipe->pipe_fdtab[pipe->idx_pipe][0]);
      close(pipe->pipe_fdtab[pipe->idx_pipe][1]);
      pipe->idx_pipe--;
    }
  waitpid(pipe->pid[tmp - 1], &status, 0);
  while (waitpid(-1, &status, 0) != -1)
    {
      if (WIFEXITED(status))
	(*data)->exit_value = WEXITSTATUS(status);
      else if (WIFSIGNALED(status))
	(*data)->exit_value = WTERMSIG(status) + 128;
    }
}

int	exec_complex_command(t_tab **data, char **args)
{
  t_pipe	*pipe;
  t_split	*split;

  pipe = malloc(sizeof(t_pipe));
  if (pipe == NULL)
    return (0);
  if (init_struct_pipe(pipe, args) == -1)
    return (0);
  if (open_files(&(pipe->output_fd), &(pipe->input_fd), data, args) == -1)
    return (0);
  split = malloc(sizeof(t_split));
  if (split == NULL)
    return (0);
  split = NULL;
  split = split_cmd(split, args);
  if (exec_split_cmd(split, pipe, data) == -1)
    return (0);
  wait_pipes(pipe, data);
  return (0);
}

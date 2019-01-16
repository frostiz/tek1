/*
** exec_simple_right.c for minishell2 in /home/thibaut/Repository/PSU_2016_minishell2
** 
** Made by Thibaut Trouvé
** Login   <thibaut.trouve@epitech.eu>
** 
** Started on  Wed May  3 03:52:38 2017 Thibaut Trouvé
** Last update Wed May  3 05:28:55 2017 Thibaut Trouvé
*/

#include <sys/wait.h>
#include <stdlib.h>
#include "main.h"
#include "my.h"

int	is_right_simple_redir(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      if (my_strcmp(tab[i], ">") == 0 || my_strcmp(tab[i], ">>") == 0)
	return (1);
      i++;
    }
  return (0);
}

static int	write_in(int fd_file, int save_fd)
{
  char	buff[1000];
  int	size;

  if (fd_file == -1)
    return (-1);
  size = 1;
  while (size > 0)
    {
      size = read(save_fd, buff, 1000);
      buff[size] = '\0';
      write(fd_file, buff, size);
    }
  return (0);
}

static int	wait_write(t_tab **data, int pipefd[2],
			   int *save_fd, int output_fd)
{
  waitpid(-1, &(*data)->exit_value, 0);
  if (WIFEXITED((*data)->exit_value))
    (*data)->exit_value = WEXITSTATUS((*data)->exit_value);
  close(pipefd[1]);
  *save_fd = pipefd[0];
  write_in(output_fd, *save_fd);
  return (0);
}

static void	init_values(int pipefd[2], t_split *split,
			    char **progname, t_tab **data)
{
  (void)progname;
  pipefd[0] = 0;
  pipefd[1] = 0;
  pipe(pipefd);
  split->real_cmd = extract_cmd(split->real_cmd, 0, '>');
  *progname = find_path(split->real_cmd, (*data)->my_env);
}

int	exec_simple_right(t_split *split, int output_fd,
			  int *save_fd, t_tab **data)
{
  pid_t	pid;
  char	*progname;
  int	pipefd[2];

  progname = NULL;
  init_values(pipefd, split, &progname, data);
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
      dup2(*save_fd, 0);
      dup2(pipefd[1], 1);
      close(pipefd[0]);
      execve(progname, split->real_cmd, (*data)->my_env);
      exit(0);
    }
  else
    wait_write(data, pipefd, save_fd, output_fd);
  return (0);
}

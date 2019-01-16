/*
** backtick.c for  in /home/bastien/delivery/PSU/PSU_2016_42sh
** 
** Made by bastien bedu
** Login   <bastien.bedu@epitech.eu>
** 
** Started on  Sun May 21 14:53:30 2017 bastien bedu
** Last update Sun May 21 23:26:12 2017 bastien bedu
*/

#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/wait.h>
#include	<unistd.h>
#include	<fcntl.h>
#include	<string.h>
#include	"mysh.h"
#include	"exec.h"

char		*malloc_from_double(char **tab)
{
  char		*str;
  char		*tmp;
  int		i;

  str = NULL;
  i = 0;
  while (tab != NULL && tab[i] != NULL)
    {
      tmp = my_strcat(str, tab[i]);
      free(tab[i]);
      free(str);
      str = tmp;
      i++;
    }
  free(tab);
  return (str);
}

char		*concat_result(int *fdread, t_graph *graph, int pid)
{
  char		*line;
  char		*tmp;
  char		buff[64];
  int		rd;

  line = NULL;
  rd = 63;
  while (rd == 63 || waitpid(pid, &rd, WNOHANG) == 0)
    {
      usleep(10);
      rd = read(fdread[0], buff, 63);
      if (rd < 0)
	buff[0] = '\0';
      else
	buff[rd] = '\0';
      tmp = my_strcat(line, buff);
      free(line);
      line = tmp;
      epur_line(line);
    }
  free_graph(graph);
  close(fdread[0]);
  close(fdread[1]);
  return (line);
}

char		*exec_and_keep(char *command, char ***env)
{
  t_graph	*graph;
  int		pipefd[2];
  int		pid;

  graph = create_graph(command);
  if (graph == NULL)
    return (strdup(""));
  if (pipe2(pipefd, O_NONBLOCK) == -1)
    return (NULL);
  pid = fork();
  if (pid < 0)
    return (NULL);
  else if (pid == 0)
    {
      dup2(pipefd[1], 1);
      close(pipefd[1]);
      close(pipefd[0]);
      split_command(graph, env);
      exit(0);
    }
  return (concat_result(pipefd, graph, pid));
}

char		*sep_tick(char *str, char ***env)
{
  char		**command;
  int		mode;
  int		i;
  int		j;

  command = my_split(str, '`');
  if (command == NULL)
    return (NULL);
  mode = 0;
  i = 0;
  j = 0;
  while (str[i] != '\0' && command[j] != NULL)
    {
      mode = move(str, &i, mode);
      if (mode == 1)
	command[j] = exec_and_keep(command[j], env);
      j++;
    }
  return (malloc_from_double(command));
}

char		*backticks(char *str, char ***env)
{
  int		i;
  int		mode;

  if (str == NULL)
    return (NULL);
  i = 0;
  mode = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '`')
	mode++;
      i++;
    }
  if (mode == 0)
    return (str);
  if (mode % 2 == 1)
    {
      my_perror("Unmatched '`'.\n");
      return (NULL);
    }
  return (sep_tick(str, env));
}

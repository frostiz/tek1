/*
** main.c for 42sh in /home/dubret_v/delivery/semestre2/Unix/PSU_2016_42sh
**
** Made by dubret_v
** Login   <victor.dubret@epitech.eu>
**
** Started on  Sat May 13 15:45:54 2017 dubret_v
** Last update Mon May 29 12:01:40 2017 dubret_v
*/

#include	<string.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<term.h>
#include	<stdio.h>
#include	<signal.h>
#include	"mysh.h"
#include	"read.h"
#include	"get_next_line.h"

int		is_exec(char *str, char ***my_env)
{
  int		ret;
  t_graph	*graph;
  char		*tmp;

  tmp = my_epur_str(str, &ret);
  if (tmp != NULL)
    {
      graph = create_graph(str);
      if (graph != NULL)
	{
	  ret = for_error_checking(graph);
	  if (ret != 1)
	    ret = split_command(graph, my_env);
	  free_graph(graph);
	}
    }
  return (ret);
}

int		my_shell(char ***my_env, t_keys *keys, t_hist *hist, int read)
{
  int		ret;
  char		*str;

  ret = 0;
  str = "OK";
  while (str != NULL && ret >= 0)
    {
      if (isatty(0) == 1 && read == 0)
	{
	  mode(0);
	  write(1, "$> ", strlen("$> "));
	  str = read_command(keys, hist);
	  mode(1);
	}
      else
	{
	  //	  if (read == 1)
	    write(1, "$> ", strlen("$> "));
	  str = get_next_line(0);
	}
      if (str != NULL)
	ret = is_exec(str, my_env);
    }
  if (ret < 0)
    return ((-1 * ret) - 2);
  return (ret);
}

static t_hist	*init_line_editing(t_keys **keys, int *read)
{
  t_hist	*hist;
  int		ret;

  *read = 0;
  *keys = malloc(sizeof(t_keys));
  if ((*keys) == NULL)
    return (NULL);
  hist = malloc(sizeof(t_hist));
  if (hist == NULL)
    return (NULL);
  hist->hist = malloc(sizeof(char *));
  if (hist->hist == NULL)
    return (NULL);
  hist->hist[0] = NULL;
  hist->len = 0;
  hist->idx = 0;
  ret = init_term(*keys);
  if (ret == 84)
    return (NULL);
  else if (ret == 42)
    {
      *read = 1;
      return (NULL);
    }
  return (hist);
}

int		main(__attribute__ ((unused)) int ac,
		     __attribute__ ((unused)) char **av,
		     char **env)
{
  char		**my_env;
  int		ret;
  t_keys	*keys;
  t_hist	*hist;
  int		read;

  signal(SIGINT, my_prompt);
  if (isatty(0) == 1)
    {
      hist = init_line_editing(&keys, &read);
      if (hist == NULL && read == 0)
	return (84);
    }
  my_env = my_envdup(env, 0, &ret);
  ret = my_shell(&my_env, keys, hist, read);
  my_free_tab(my_env);
  if (isatty(0) == 1 && read == 0)
    {
      mode(1);
      my_free_tab(hist->hist);
      free(hist);
      free(keys);
    }
  return (ret);
}
